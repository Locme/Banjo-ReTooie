#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chmineentrygrille_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087098: syscall     507
    recomp_syscall_handler(rdram, ctx, 0x80087098);
    return;
    // 0x8008709C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chblackeye_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DC0: syscall     456
    recomp_syscall_handler(rdram, ctx, 0x80086DC0);
    return;
    // 0x80086DC4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chgameselect_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BD8: syscall     205
    recomp_syscall_handler(rdram, ctx, 0x80085BD8);
    return;
    // 0x80085BDC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808080C0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808080C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808080C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808080C8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808080CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808080D0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x808080D4: jal         0x80100094
    // 0x808080D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808080D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808080DC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808080E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808080E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808080E8: beq         $a2, $zero, L_80808108
    if (ctx->r6 == 0) {
        // 0x808080EC: sh          $a2, 0xA4($v0)
        MEM_H(0XA4, ctx->r2) = ctx->r6;
            goto L_80808108;
    }
    // 0x808080EC: sh          $a2, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = ctx->r6;
    // 0x808080F0: beq         $a2, $at, L_8080814C
    if (ctx->r6 == ctx->r1) {
        // 0x808080F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080814C;
    }
    // 0x808080F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808080F8: beql        $a2, $at, L_80808138
    if (ctx->r6 == ctx->r1) {
        // 0x808080FC: lw          $t7, 0xA8($v0)
        ctx->r15 = MEM_W(ctx->r2, 0XA8);
            goto L_80808138;
    }
    goto skip_0;
    // 0x808080FC: lw          $t7, 0xA8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XA8);
    skip_0:
    // 0x80808100: b           L_80808150
    // 0x80808104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80808150;
    // 0x80808104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80808108:
    // 0x80808108: lw          $t6, 0xA8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA8);
    // 0x8080810C: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x80808110: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80808114: beql        $t6, $zero, L_80808150
    if (ctx->r14 == 0) {
        // 0x80808118: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80808150;
    }
    goto skip_1;
    // 0x80808118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8080811C: lw          $a0, 0xA8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XA8);
    // 0x80808120: jal         0x8010114C
    // 0x80808124: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8010114C(rdram, ctx);
        goto after_1;
    // 0x80808124: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80808128: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080812C: b           L_8080814C
    // 0x80808130: sw          $zero, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = 0;
        goto L_8080814C;
    // 0x80808130: sw          $zero, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = 0;
    // 0x80808134: lw          $t7, 0xA8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XA8);
L_80808138:
    // 0x80808138: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080813C: bnel        $t7, $zero, L_80808150
    if (ctx->r15 != 0) {
        // 0x80808140: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80808150;
    }
    goto skip_2;
    // 0x80808140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80808144: jal         0x80108B04
    // 0x80808148: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x80808148: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
L_8080814C:
    // 0x8080814C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80808150:
    // 0x80808150: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80808154: jr          $ra
    // 0x80808158: nop

    return;
    // 0x80808158: nop

;}
RECOMP_FUNC void func_80804DB8_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804DB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804DBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804DC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80804DC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80804DC8: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80804DCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804DD0: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80804DD4: beq         $t7, $at, L_80804E00
    if (ctx->r15 == ctx->r1) {
        // 0x80804DD8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80804E00;
    }
    // 0x80804DD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804DDC: beq         $t7, $at, L_80804DEC
    if (ctx->r15 == ctx->r1) {
        // 0x80804DE0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80804DEC;
    }
    // 0x80804DE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804DE4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80804DE8: bne         $t7, $at, L_80804E00
    if (ctx->r15 != ctx->r1) {
        // 0x80804DEC: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1852, 0X5A50) << 16);
            goto L_80804E00;
    }
L_80804DEC:
    // 0x80804DEC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1852, 0X5A50) << 16);
    // 0x80804DF0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X5488) << 16);
    // 0x80804DF4: addiu       $a2, $a2, 0x5488
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5488));
    // 0x80804DF8: jal         0x80089D18
    // 0x80804DFC: addiu       $a1, $a1, 0x5A50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1852, 0X5A50));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80804DFC: addiu       $a1, $a1, 0x5A50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1852, 0X5A50));
    after_0:
L_80804E00:
    // 0x80804E00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804E04: jal         0x80101FDC
    // 0x80804E08: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80804E08: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80804E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804E10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804E14: jr          $ra
    // 0x80804E18: nop

    return;
    // 0x80804E18: nop

;}
RECOMP_FUNC void func_80092AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092AB8: jal         0x80092AD8
    // 0x80092ABC: nop

    func_80092AD8(rdram, ctx);
        goto after_0;
    // 0x80092ABC: nop

    after_0:
    // 0x80092AC0: jal         0x800E0ACC
    // 0x80092AC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E0ACC(rdram, ctx);
        goto after_1;
    // 0x80092AC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80092AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092ACC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092AD0: jr          $ra
    // 0x80092AD4: nop

    return;
    // 0x80092AD4: nop

;}
RECOMP_FUNC void func_80801604_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801604: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080160C: jal         0x80100094
    // 0x80801610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801614: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801618: jal         0x8008A2F8
    // 0x8080161C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8080161C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80801620: jal         0x800D284C
    // 0x80801624: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    func_800D284C(rdram, ctx);
        goto after_2;
    // 0x80801624: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    after_2:
    // 0x80801628: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080162C: lbu         $a0, 0xC($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0XC);
    // 0x80801630: beql        $a0, $zero, L_8080164C
    if (ctx->r4 == 0) {
        // 0x80801634: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080164C;
    }
    goto skip_0;
    // 0x80801634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801638: jal         0x800C2FDC
    // 0x8080163C: nop

    func_800C2FDC(rdram, ctx);
        goto after_3;
    // 0x8080163C: nop

    after_3:
    // 0x80801640: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80801644: sb          $zero, 0xC($t7)
    MEM_B(0XC, ctx->r15) = 0;
    // 0x80801648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080164C:
    // 0x8080164C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801650: jr          $ra
    // 0x80801654: nop

    return;
    // 0x80801654: nop

;}
RECOMP_FUNC void func_801099D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801099D0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801099D4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801099D8: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x801099DC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801099E0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x801099E4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x801099E8: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x801099EC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x801099F0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x801099F4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x801099F8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x801099FC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80109A00: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80109A04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80109A08: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80109A0C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80109A10: jal         0x800BE444
    // 0x80109A14: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    func_800BE444(rdram, ctx);
        goto after_0;
    // 0x80109A14: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    after_0:
    // 0x80109A18: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80109A1C: jal         0x800CB854
    // 0x80109A20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_1;
    // 0x80109A20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80109A24: beq         $v0, $zero, L_80109A44
    if (ctx->r2 == 0) {
        // 0x80109A28: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_80109A44;
    }
    // 0x80109A28: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80109A2C: jal         0x800CB854
    // 0x80109A30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_2;
    // 0x80109A30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80109A34: addiu       $t6, $v0, 0x1F
    ctx->r14 = ADD32(ctx->r2, 0X1F);
    // 0x80109A38: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80109A3C: b           L_80109A44
    // 0x80109A40: sllv        $s7, $t7, $t6
    ctx->r23 = S32(ctx->r15 << (ctx->r14 & 31));
        goto L_80109A44;
    // 0x80109A40: sllv        $s7, $t7, $t6
    ctx->r23 = S32(ctx->r15 << (ctx->r14 & 31));
L_80109A44:
    // 0x80109A44: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80109A48: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x80109A4C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x80109A50: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80109A54: lw          $s2, 0x64($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X64);
    // 0x80109A58: beql        $a0, $zero, L_80109BB8
    if (ctx->r4 == 0) {
        // 0x80109A5C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80109BB8;
    }
    goto skip_0;
    // 0x80109A5C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
L_80109A60:
    // 0x80109A60: jal         0x800E9E88
    // 0x80109A64: nop

    func_800E9E88(rdram, ctx);
        goto after_3;
    // 0x80109A64: nop

    after_3:
    // 0x80109A68: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80109A6C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80109A70: jal         0x800E9EB4
    // 0x80109A74: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_4;
    // 0x80109A74: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_4:
    // 0x80109A78: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80109A7C: beq         $at, $zero, L_80109B9C
    if (ctx->r1 == 0) {
        // 0x80109A80: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_80109B9C;
    }
    // 0x80109A80: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80109A84: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_80109A88:
    // 0x80109A88: sll         $t1, $v0, 27
    ctx->r9 = S32(ctx->r2 << 27);
    // 0x80109A8C: bgez        $t1, L_80109B8C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80109A90: andi        $t2, $v0, 0x1
        ctx->r10 = ctx->r2 & 0X1;
            goto L_80109B8C;
    }
    // 0x80109A90: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80109A94: beql        $t2, $zero, L_80109B90
    if (ctx->r10 == 0) {
        // 0x80109A98: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80109B90;
    }
    goto skip_1;
    // 0x80109A98: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_1:
    // 0x80109A9C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80109AA0: beql        $s0, $s2, L_80109B90
    if (ctx->r16 == ctx->r18) {
        // 0x80109AA4: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80109B90;
    }
    goto skip_2;
    // 0x80109AA4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_2:
    // 0x80109AA8: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
    // 0x80109AAC: sll         $t5, $t3, 22
    ctx->r13 = S32(ctx->r11 << 22);
    // 0x80109AB0: bgezl       $t5, L_80109B90
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80109AB4: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80109B90;
    }
    goto skip_3;
    // 0x80109AB4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_3:
    // 0x80109AB8: lhu         $t7, 0x18($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X18);
    // 0x80109ABC: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x80109AC0: beql        $t6, $zero, L_80109B90
    if (ctx->r14 == 0) {
        // 0x80109AC4: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80109B90;
    }
    goto skip_4;
    // 0x80109AC4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_4:
    // 0x80109AC8: lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X14);
    // 0x80109ACC: beql        $v0, $zero, L_80109B90
    if (ctx->r2 == 0) {
        // 0x80109AD0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80109B90;
    }
    goto skip_5;
    // 0x80109AD0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_5:
    // 0x80109AD4: beql        $s6, $v0, L_80109B90
    if (ctx->r22 == ctx->r2) {
        // 0x80109AD8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80109B90;
    }
    goto skip_6;
    // 0x80109AD8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_6:
    // 0x80109ADC: jal         0x80106790
    // 0x80109AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80109AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80109AE4: lw          $t8, 0x64($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X64);
    // 0x80109AE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80109AEC: sll         $t0, $t8, 14
    ctx->r8 = S32(ctx->r24 << 14);
    // 0x80109AF0: bltzl       $t0, L_80109B90
    if (SIGNED(ctx->r8) < 0) {
        // 0x80109AF4: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80109B90;
    }
    goto skip_7;
    // 0x80109AF4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_7:
    // 0x80109AF8: lhu         $t1, 0x66($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X66);
    // 0x80109AFC: and         $t2, $t1, $s7
    ctx->r10 = ctx->r9 & ctx->r23;
    // 0x80109B00: bnel        $t2, $zero, L_80109B90
    if (ctx->r10 != 0) {
        // 0x80109B04: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80109B90;
    }
    goto skip_8;
    // 0x80109B04: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_8:
    // 0x80109B08: beql        $s3, $zero, L_80109B24
    if (ctx->r19 == 0) {
        // 0x80109B0C: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_80109B24;
    }
    goto skip_9;
    // 0x80109B0C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_9:
    // 0x80109B10: jalr        $s3
    // 0x80109B14: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
        goto after_6;
    // 0x80109B14: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_6:
    // 0x80109B18: beql        $v0, $zero, L_80109B90
    if (ctx->r2 == 0) {
        // 0x80109B1C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80109B90;
    }
    goto skip_10;
    // 0x80109B1C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_10:
    // 0x80109B20: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_80109B24:
    // 0x80109B24: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80109B28: jal         0x801098D0
    // 0x80109B2C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_801098D0(rdram, ctx);
        goto after_7;
    // 0x80109B2C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80109B30: beql        $v0, $zero, L_80109B90
    if (ctx->r2 == 0) {
        // 0x80109B34: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80109B90;
    }
    goto skip_11;
    // 0x80109B34: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_11:
    // 0x80109B38: jal         0x800EC3C4
    // 0x80109B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EC3C4(rdram, ctx);
        goto after_8;
    // 0x80109B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80109B40: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x80109B44: beql        $t3, $zero, L_80109B6C
    if (ctx->r11 == 0) {
        // 0x80109B48: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_80109B6C;
    }
    goto skip_12;
    // 0x80109B48: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    skip_12:
    // 0x80109B4C: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x80109B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80109B54: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80109B58: jalr        $t9
    // 0x80109B5C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x80109B5C: nop

    after_9:
    // 0x80109B60: beql        $v0, $zero, L_80109B90
    if (ctx->r2 == 0) {
        // 0x80109B64: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80109B90;
    }
    goto skip_13;
    // 0x80109B64: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_13:
    // 0x80109B68: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_80109B6C:
    // 0x80109B6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80109B70: jal         0x80088610
    // 0x80109B74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _glhittableDll_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80109B74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x80109B78: bne         $v0, $zero, L_80109B8C
    if (ctx->r2 != 0) {
        // 0x80109B7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80109B8C;
    }
    // 0x80109B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80109B80: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80109B84: jal         0x800EB210
    // 0x80109B88: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    func_800EB210(rdram, ctx);
        goto after_11;
    // 0x80109B88: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    after_11:
L_80109B8C:
    // 0x80109B8C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80109B90:
    // 0x80109B90: sltu        $at, $s1, $s4
    ctx->r1 = ctx->r17 < ctx->r20 ? 1 : 0;
    // 0x80109B94: bnel        $at, $zero, L_80109A88
    if (ctx->r1 != 0) {
        // 0x80109B98: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_80109A88;
    }
    goto skip_14;
    // 0x80109B98: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_14:
L_80109B9C:
    // 0x80109B9C: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80109BA0: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80109BA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80109BA8: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80109BAC: bne         $a0, $zero, L_80109A60
    if (ctx->r4 != 0) {
        // 0x80109BB0: nop
    
            goto L_80109A60;
    }
    // 0x80109BB0: nop

    // 0x80109BB4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80109BB8:
    // 0x80109BB8: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x80109BBC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80109BC0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80109BC4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80109BC8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80109BCC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80109BD0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80109BD4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80109BD8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80109BDC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80109BE0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80109BE4: jr          $ra
    // 0x80109BE8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80109BE8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80802004_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802004: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80802008: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8080200C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80802010: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80802014: addiu       $s6, $sp, 0x54
    ctx->r22 = ADD32(ctx->r29, 0X54);
    // 0x80802018: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080201C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80802020: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80802024: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80802028: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080202C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802030: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80802034: jal         0x800EE7F8
    // 0x80802038: addiu       $a1, $s5, 0x4
    ctx->r5 = ADD32(ctx->r21, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80802038: addiu       $a1, $s5, 0x4
    ctx->r5 = ADD32(ctx->r21, 0X4);
    after_0:
    // 0x8080203C: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x80802040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802044: lw          $a1, 0x48($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X48);
    // 0x80802048: jal         0x800EEB9C
    // 0x8080204C: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x8080204C: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_1:
    // 0x80802050: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80802054: jal         0x800EF04C
    // 0x80802058: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80802058: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8080205C: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2484, 0X7314) << 16);
    // 0x80802060: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2484, 0X731C) << 16);
    // 0x80802064: addiu       $s2, $s2, 0x731C
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2484, 0X731C));
    // 0x80802068: addiu       $s3, $s3, 0x7314
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2484, 0X7314));
    // 0x8080206C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80802070: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x80802074: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
L_80802078:
    // 0x80802078: jal         0x800C8A98
    // 0x8080207C: nop

    func_800C8A98(rdram, ctx);
        goto after_3;
    // 0x8080207C: nop

    after_3:
    // 0x80802080: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80802084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802088: jal         0x800C8F64
    // 0x8080208C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_800C8F64(rdram, ctx);
        goto after_4;
    // 0x8080208C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_4:
    // 0x80802090: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80802094: jal         0x800C8E84
    // 0x80802098: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C8E84(rdram, ctx);
        goto after_5;
    // 0x80802098: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x8080209C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808020A0: jal         0x800C8D4C
    // 0x808020A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C8D4C(rdram, ctx);
        goto after_6;
    // 0x808020A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
    // 0x808020A8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808020AC: jal         0x800C8CB8
    // 0x808020B0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_7;
    // 0x808020B0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_7:
    // 0x808020B4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808020B8: jal         0x800C8FE0
    // 0x808020BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_8;
    // 0x808020BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808020C0: jal         0x80103EF4
    // 0x808020C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80103EF4(rdram, ctx);
        goto after_9;
    // 0x808020C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_9:
    // 0x808020C8: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808020CC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808020D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808020D4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808020D8: bne         $s1, $s4, L_80802078
    if (ctx->r17 != ctx->r20) {
        // 0x808020DC: swc1        $f6, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
            goto L_80802078;
    }
    // 0x808020DC: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x808020E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808020E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808020E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808020EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808020F0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808020F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808020F8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808020FC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80802100: jr          $ra
    // 0x80802104: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80802104: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80800D50_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800D5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800D60: jal         0x80100094
    // 0x80800D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D68: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800D6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D70: jal         0x80801B88
    // 0x80800D74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80801B88_chboilerboss(rdram, ctx);
        goto after_1;
    // 0x80800D74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800D78: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800D7C: lhu         $v0, 0x72($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X72);
    // 0x80800D80: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800D84: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80800D88: bne         $at, $zero, L_80800E54
    if (ctx->r1 != 0) {
        // 0x80800D8C: slti        $at, $t6, 0xB
        ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
            goto L_80800E54;
    }
    // 0x80800D8C: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x80800D90: beql        $at, $zero, L_80800E58
    if (ctx->r1 == 0) {
        // 0x80800D94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800E58;
    }
    goto skip_0;
    // 0x80800D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800D98: jal         0x800CB854
    // 0x80800D9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_2;
    // 0x80800D9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800DA0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800DA4: bne         $v0, $at, L_80800DCC
    if (ctx->r2 != ctx->r1) {
        // 0x80800DA8: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800DCC;
    }
    // 0x80800DA8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800DAC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800DB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DB4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DB8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800DBC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80800DC0: jal         0x80109EEC
    // 0x80800DC4: swc1        $f4, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f4.u32l;
    func_80109EEC(rdram, ctx);
        goto after_3;
    // 0x80800DC4: swc1        $f4, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f4.u32l;
    after_3:
    // 0x80800DC8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80800DCC:
    // 0x80800DCC: lhu         $t8, 0x72($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X72);
    // 0x80800DD0: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800DD4: addiu       $t0, $t9, -0x6
    ctx->r8 = ADD32(ctx->r25, -0X6);
    // 0x80800DD8: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x80800DDC: beq         $at, $zero, L_80800DF8
    if (ctx->r1 == 0) {
        // 0x80800DE0: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800DF8;
    }
    // 0x80800DE0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800DE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X29F8) << 16);
    // 0x80800DE8: addu        $at, $at, $t0
    gpr jr_addend_80800DF0 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800DEC: lw          $t0, 0x29F8($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(932, 0X29F8));
    // 0x80800DF0: jr          $t0
    // 0x80800DF4: nop

    switch (jr_addend_80800DF0 >> 2) {
        case 0: goto L_80800E54; break;
        case 1: goto L_80800E54; break;
        case 2: goto L_80800E54; break;
        case 3: goto L_80800E54; break;
        case 4: goto L_80800E54; break;
        default: switch_error(__func__, 0x80800DF0, 0x808029F8);
    }
    // 0x80800DF4: nop

L_80800DF8:
    // 0x80800DF8: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80800DFC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800E00: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800E04: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x80800E08: sll         $t4, $t2, 20
    ctx->r12 = S32(ctx->r10 << 20);
    // 0x80800E0C: bgezl       $t4, L_80800E28
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800E10: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80800E28;
    }
    goto skip_1;
    // 0x80800E10: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_1:
    // 0x80800E14: jal         0x80800F34
    // 0x80800E18: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_4;
    // 0x80800E18: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x80800E1C: b           L_80800E58
    // 0x80800E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800E58;
    // 0x80800E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E24: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80800E28:
    // 0x80800E28: jal         0x800DC298
    // 0x80800E2C: nop

    func_800DC298(rdram, ctx);
        goto after_5;
    // 0x80800E2C: nop

    after_5:
    // 0x80800E30: beq         $v0, $zero, L_80800E44
    if (ctx->r2 == 0) {
        // 0x80800E34: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E44;
    }
    // 0x80800E34: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E38: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(932, 0X2B34) << 16);
    // 0x80800E3C: b           L_80800E4C
    // 0x80800E40: addiu       $a1, $a1, 0x2B34
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(932, 0X2B34));
        goto L_80800E4C;
    // 0x80800E40: addiu       $a1, $a1, 0x2B34
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(932, 0X2B34));
L_80800E44:
    // 0x80800E44: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(932, 0X2B40) << 16);
    // 0x80800E48: addiu       $a1, $a1, 0x2B40
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(932, 0X2B40));
L_80800E4C:
    // 0x80800E4C: jal         0x800C4AF0
    // 0x80800E50: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_800C4AF0(rdram, ctx);
        goto after_6;
    // 0x80800E50: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_6:
L_80800E54:
    // 0x80800E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E58:
    // 0x80800E58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E5C: jr          $ra
    // 0x80800E60: nop

    return;
    // 0x80800E60: nop

;}
RECOMP_FUNC void _bakaztorpedo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D80: syscall     136
    recomp_syscall_handler(rdram, ctx, 0x80084D80);
    return;
    // 0x80084D84: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80802A9C_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A9C: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80802AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802AA4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80802AA8: blez        $t6, L_80802AD0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80802AAC: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_80802AD0;
    }
    // 0x80802AAC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80802AB0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80802AB4: sb          $a1, 0x94($v1)
    MEM_B(0X94, ctx->r3) = ctx->r5;
L_80802AB8:
    // 0x80802AB8: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80802ABC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80802AC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80802AC4: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80802AC8: bnel        $at, $zero, L_80802AB8
    if (ctx->r1 != 0) {
        // 0x80802ACC: sb          $a1, 0x94($v1)
        MEM_B(0X94, ctx->r3) = ctx->r5;
            goto L_80802AB8;
    }
    goto skip_0;
    // 0x80802ACC: sb          $a1, 0x94($v1)
    MEM_B(0X94, ctx->r3) = ctx->r5;
    skip_0:
L_80802AD0:
    // 0x80802AD0: jr          $ra
    // 0x80802AD4: sb          $t8, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r24;
    return;
    // 0x80802AD4: sb          $t8, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void _susplinet_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E30: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E30);
    return;
    // 0x80089E34: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void baduo_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800870: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800878: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080087C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800880: jal         0x8009C128
    // 0x80800884: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800884: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800888: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8080088C: jal         0x800F6224
    // 0x80800890: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    func_800F6224(rdram, ctx);
        goto after_1;
    // 0x80800890: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    after_1:
    // 0x80800894: jal         0x800F53D0
    // 0x80800898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x80800898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080089C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808008A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008A4: jal         0x800F452C
    // 0x808008A8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800F452C(rdram, ctx);
        goto after_3;
    // 0x808008A8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x808008AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008B0: jal         0x8009E5C8
    // 0x808008B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x808008B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808008B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808008C0: jal         0x800F45B0
    // 0x808008C4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800F45B0(rdram, ctx);
        goto after_5;
    // 0x808008C4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_5:
    // 0x808008C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808008D0: jr          $ra
    // 0x808008D4: nop

    return;
    // 0x808008D4: nop

;}
RECOMP_FUNC void func_800A98E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A98E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A98E4: lbu         $v0, 0x7760($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7760);
    // 0x800A98E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A98EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A98F0: beq         $v0, $at, L_800A990C
    if (ctx->r2 == ctx->r1) {
        // 0x800A98F4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800A990C;
    }
    // 0x800A98F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A98F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A98FC: bnel        $v0, $at, L_800A9910
    if (ctx->r2 != ctx->r1) {
        // 0x800A9900: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A9910;
    }
    goto skip_0;
    // 0x800A9900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A9904: jal         0x80088C70
    // 0x800A9908: nop

    _gsattract_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800A9908: nop

    after_0:
L_800A990C:
    // 0x800A990C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9910:
    // 0x800A9910: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A9914: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9918: sb          $t6, 0x7763($at)
    MEM_B(0X7763, ctx->r1) = ctx->r14;
    // 0x800A991C: jr          $ra
    // 0x800A9920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800A9920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void glglobalsettings_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B0: jal         0x800DA298
    // 0x808003B4: addiu       $a0, $zero, 0xBB9
    ctx->r4 = ADD32(0, 0XBB9);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808003B4: addiu       $a0, $zero, 0xBB9
    ctx->r4 = ADD32(0, 0XBB9);
    after_0:
    // 0x808003B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003C0: jr          $ra
    // 0x808003C4: nop

    return;
    // 0x808003C4: nop

;}
RECOMP_FUNC void _badrone_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084848: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084848);
    return;
    // 0x8008484C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800670_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800678: jal         0x808003BC
    // 0x8080067C: nop

    func_808003BC_bsbanswim(rdram, ctx);
        goto after_0;
    // 0x8080067C: nop

    after_0:
    // 0x80800680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800688: jr          $ra
    // 0x8080068C: nop

    return;
    // 0x8080068C: nop

;}
RECOMP_FUNC void func_800D2CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2CC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D2CC8: jr          $ra
    // 0x800D2CCC: sb          $zero, -0x4CDF($at)
    MEM_B(-0X4CDF, ctx->r1) = 0;
    return;
    // 0x800D2CCC: sb          $zero, -0x4CDF($at)
    MEM_B(-0X4CDF, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80800F34_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800F38: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800F3C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80800F40: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80800F44: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800F48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800F4C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800F50: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80800F54: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80800F58: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80800F5C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800F60: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800F64: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800F68: jal         0x801015B0
    // 0x80800F6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_801015B0(rdram, ctx);
        goto after_0;
    // 0x80800F6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800F70: jal         0x8001B798
    // 0x80800F74: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x80800F74: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_1:
    // 0x80800F78: sll         $t6, $s6, 2
    ctx->r14 = S32(ctx->r22 << 2);
    // 0x80800F7C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80800F80: jal         0x8001B798
    // 0x80800F84: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x80800F84: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    after_2:
    // 0x80800F88: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x80800F8C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80800F90: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80800F94: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800F98: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80800F9C: addu        $s2, $t0, $v0
    ctx->r18 = ADD32(ctx->r8, ctx->r2);
    // 0x80800FA0: lbu         $s5, 0x0($s2)
    ctx->r21 = MEM_BU(ctx->r18, 0X0);
    // 0x80800FA4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800FA8: blezl       $s5, L_8080105C
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80800FAC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8080105C;
    }
    goto skip_0;
    // 0x80800FAC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
L_80800FB0:
    // 0x80800FB0: lh          $t1, 0x0($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X0);
    // 0x80800FB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800FB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800FBC: beq         $s1, $t1, L_80800FF4
    if (ctx->r17 == ctx->r9) {
        // 0x80800FC0: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_80800FF4;
    }
    // 0x80800FC0: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
L_80800FC4:
    // 0x80800FC4: bnel        $v0, $zero, L_80800FE4
    if (ctx->r2 != 0) {
        // 0x80800FC8: lh          $t4, 0x2($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X2);
            goto L_80800FE4;
    }
    goto skip_1;
    // 0x80800FC8: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    skip_1:
    // 0x80800FCC: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x80800FD0: lbu         $t3, 0x0($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X0);
    // 0x80800FD4: bnel        $t2, $t3, L_80800FE4
    if (ctx->r10 != ctx->r11) {
        // 0x80800FD8: lh          $t4, 0x2($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X2);
            goto L_80800FE4;
    }
    goto skip_2;
    // 0x80800FD8: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    skip_2:
    // 0x80800FDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800FE0: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
L_80800FE4:
    // 0x80800FE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800FE8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800FEC: bne         $s1, $t4, L_80800FC4
    if (ctx->r17 != ctx->r12) {
        // 0x80800FF0: nop
    
            goto L_80800FC4;
    }
    // 0x80800FF0: nop

L_80800FF4:
    // 0x80800FF4: bne         $v0, $zero, L_8080104C
    if (ctx->r2 != 0) {
        // 0x80800FF8: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_8080104C;
    }
    // 0x80800FF8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800FFC: jal         0x800CC63C
    // 0x80801000: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    func_800CC63C(rdram, ctx);
        goto after_3;
    // 0x80801000: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_3:
    // 0x80801004: lh          $t5, 0xC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XC);
    // 0x80801008: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080100C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80801010: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80801014: nop

    // 0x80801018: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080101C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80801020: jal         0x800F0064
    // 0x80801024: nop

    func_800F0064(rdram, ctx);
        goto after_4;
    // 0x80801024: nop

    after_4:
    // 0x80801028: beql        $v0, $zero, L_80801050
    if (ctx->r2 == 0) {
        // 0x8080102C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80801050;
    }
    goto skip_3;
    // 0x8080102C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_3:
    // 0x80801030: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x80801034: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x80801038: addu        $v1, $s4, $t6
    ctx->r3 = ADD32(ctx->r20, ctx->r14);
    // 0x8080103C: sh          $s1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r17;
    // 0x80801040: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80801044: b           L_8080105C
    // 0x80801048: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
        goto L_8080105C;
    // 0x80801048: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
L_8080104C:
    // 0x8080104C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80801050:
    // 0x80801050: bne         $s3, $s5, L_80800FB0
    if (ctx->r19 != ctx->r21) {
        // 0x80801054: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800FB0;
    }
    // 0x80801054: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80801058: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8080105C:
    // 0x8080105C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801060: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801064: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801068: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080106C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801070: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80801074: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80801078: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8080107C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80801080: jr          $ra
    // 0x80801084: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801084: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80013798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013798: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001379C: lwc1        $f14, 0x16C0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X16C0);
    // 0x800137A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800137A4: b           L_80013818
    // 0x800137A8: lwc1        $f16, 0x16C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X16C4);
    func_80013818(rdram, ctx);
    return;
    // 0x800137A8: lwc1        $f16, 0x16C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X16C4);
;}
RECOMP_FUNC void _babounce_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845B8: syscall     116
    recomp_syscall_handler(rdram, ctx, 0x800845B8);
    return;
    // 0x800845BC: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _chklungophial_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863B0: syscall     317
    recomp_syscall_handler(rdram, ctx, 0x800863B0);
    return;
    // 0x800863B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801CC4_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CC4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80801CC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801CCC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801CD0: jal         0x80101F24
    // 0x80801CD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101F24(rdram, ctx);
        goto after_0;
    // 0x80801CD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801CD8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80801CDC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801CE0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80801CE4: jal         0x800EE7F8
    // 0x80801CE8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80801CE8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80801CEC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80801CF0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2484, 0X7220) << 16);
    // 0x80801CF4: addiu       $at, $zero, 0x596
    ctx->r1 = ADD32(0, 0X596);
    // 0x80801CF8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801CFC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80801D00: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80801D04: lhu         $v0, 0x7220($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7220));
    // 0x80801D08: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80801D0C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801D10: beq         $v0, $at, L_80801D28
    if (ctx->r2 == ctx->r1) {
        // 0x80801D14: addiu       $at, $zero, 0x597
        ctx->r1 = ADD32(0, 0X597);
            goto L_80801D28;
    }
    // 0x80801D14: addiu       $at, $zero, 0x597
    ctx->r1 = ADD32(0, 0X597);
    // 0x80801D18: beq         $v0, $at, L_80801DC0
    if (ctx->r2 == ctx->r1) {
        // 0x80801D1C: nop
    
            goto L_80801DC0;
    }
    // 0x80801D1C: nop

    // 0x80801D20: b           L_80801E60
    // 0x80801D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801E60;
    // 0x80801D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801D28:
    // 0x80801D28: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801D2C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80801D30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801D34: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80801D38: jal         0x800F10B4
    // 0x80801D3C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80801D3C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80801D40: jal         0x800138D0
    // 0x80801D44: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800138D0(rdram, ctx);
        goto after_3;
    // 0x80801D44: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80801D48: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801D4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801D50: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801D54: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801D58: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801D5C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80801D60: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801D64: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801D68: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801D6C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80801D70: jal         0x800EEB9C
    // 0x80801D74: nop

    func_800EEB9C(rdram, ctx);
        goto after_4;
    // 0x80801D74: nop

    after_4:
    // 0x80801D78: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80801D7C: jal         0x800EF04C
    // 0x80801D80: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80801D80: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x80801D84: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801D88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801D8C: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x80801D90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801D94: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80801D98: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80801D9C: lw          $a3, 0x30($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X30);
    // 0x80801DA0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80801DA4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801DA8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801DAC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801DB0: jal         0x800EFA4C
    // 0x80801DB4: nop

    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x80801DB4: nop

    after_6:
    // 0x80801DB8: b           L_80801E60
    // 0x80801DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801E60;
    // 0x80801DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801DC0:
    // 0x80801DC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X65A4) << 16);
    // 0x80801DC4: lwc1        $f16, 0x65A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X65A4));
    // 0x80801DC8: lui         $a2, 0x3F26
    ctx->r6 = S32(0X3F26 << 16);
    // 0x80801DCC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801DD0: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80801DD4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80801DD8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801DDC: bc1fl       L_80801E28
    if (!c1cs) {
        // 0x80801DE0: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80801E28;
    }
    goto skip_0;
    // 0x80801DE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x80801DE4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801DE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801DEC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801DF0: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    // 0x80801DF4: jal         0x800F10B4
    // 0x80801DF8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80801DF8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x80801DFC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801E00: lui         $a2, 0x3F26
    ctx->r6 = S32(0X3F26 << 16);
    // 0x80801E04: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80801E08: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80801E0C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80801E10: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801E14: jal         0x800F10B4
    // 0x80801E18: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80801E18: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_8:
    // 0x80801E1C: b           L_80801E30
    // 0x80801E20: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80801E30;
    // 0x80801E20: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80801E24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80801E28:
    // 0x80801E28: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801E2C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
L_80801E30:
    // 0x80801E30: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80801E34: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x80801E38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801E3C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80801E40: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801E44: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80801E48: lw          $a3, 0x30($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X30);
    // 0x80801E4C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80801E50: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80801E54: jal         0x800EFA4C
    // 0x80801E58: nop

    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80801E58: nop

    after_9:
    // 0x80801E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801E60:
    // 0x80801E60: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80801E64: jal         0x80085770
    // 0x80801E68: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80801E68: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_10:
    // 0x80801E6C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801E70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801E74: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x80801E78: beq         $t9, $at, L_80801FE4
    if (ctx->r25 == ctx->r1) {
        // 0x80801E7C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801FE4;
    }
    // 0x80801E7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801E80: beq         $t9, $at, L_80801E9C
    if (ctx->r25 == ctx->r1) {
        // 0x80801E84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801E9C;
    }
    // 0x80801E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801E8C: beq         $t9, $at, L_80801FDC
    if (ctx->r25 == ctx->r1) {
        // 0x80801E90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801FDC;
    }
    // 0x80801E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E94: b           L_80801FE8
    // 0x80801E98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801FE8;
    // 0x80801E98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801E9C:
    // 0x80801E9C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80801EA0: jal         0x80101E14
    // 0x80801EA4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_11;
    // 0x80801EA4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_11:
    // 0x80801EA8: beq         $v0, $zero, L_80801EC8
    if (ctx->r2 == 0) {
        // 0x80801EAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801EC8;
    }
    // 0x80801EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EB0: addiu       $a0, $zero, 0x528
    ctx->r4 = ADD32(0, 0X528);
    // 0x80801EB4: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x80801EB8: jal         0x80101180
    // 0x80801EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_12;
    // 0x80801EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80801EC0: b           L_80801FA0
    // 0x80801EC4: nop

        goto L_80801FA0;
    // 0x80801EC4: nop

L_80801EC8:
    // 0x80801EC8: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80801ECC: jal         0x80101E14
    // 0x80801ED0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x80801ED0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    after_13:
    // 0x80801ED4: beq         $v0, $zero, L_80801F68
    if (ctx->r2 == 0) {
        // 0x80801ED8: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80801F68;
    }
    // 0x80801ED8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801EDC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2484, 0X723C) << 16);
    // 0x80801EE0: addiu       $t0, $t0, 0x723C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2484, 0X723C));
    // 0x80801EE4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801EE8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801EEC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801EF0: jal         0x800BBCB8
    // 0x80801EF4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_14;
    // 0x80801EF4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_14:
    // 0x80801EF8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801EFC: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2484, 0X7274) << 16);
    // 0x80801F00: addiu       $t2, $t2, 0x7274
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2484, 0X7274));
    // 0x80801F04: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801F08: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801F0C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x80801F10: jal         0x800BBCB8
    // 0x80801F14: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800BBCB8(rdram, ctx);
        goto after_15;
    // 0x80801F14: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_15:
    // 0x80801F18: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80801F1C: jal         0x800C3F48
    // 0x80801F20: ori         $a0, $a0, 0x5E84
    ctx->r4 = ctx->r4 | 0X5E84;
    func_800C3F48(rdram, ctx);
        goto after_16;
    // 0x80801F20: ori         $a0, $a0, 0x5E84
    ctx->r4 = ctx->r4 | 0X5E84;
    after_16:
    // 0x80801F24: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80801F28: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80801F2C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80801F30: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801F34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801F38: jal         0x800187B4
    // 0x80801F3C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800187B4(rdram, ctx);
        goto after_17;
    // 0x80801F3C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_17:
    // 0x80801F40: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80801F44: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801F48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801F4C: jal         0x800E15CC
    // 0x80801F50: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_800E15CC(rdram, ctx);
        goto after_18;
    // 0x80801F50: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_18:
    // 0x80801F54: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80801F58: jal         0x80089D40
    // 0x80801F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x80801F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80801F60: b           L_80801FA0
    // 0x80801F64: nop

        goto L_80801FA0;
    // 0x80801F64: nop

L_80801F68:
    // 0x80801F68: jal         0x80101DDC
    // 0x80801F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_20;
    // 0x80801F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801F70: beq         $v0, $zero, L_80801FA0
    if (ctx->r2 == 0) {
        // 0x80801F74: addiu       $a0, $zero, 0x88
        ctx->r4 = ADD32(0, 0X88);
            goto L_80801FA0;
    }
    // 0x80801F74: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    // 0x80801F78: jal         0x80101238
    // 0x80801F7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80101238(rdram, ctx);
        goto after_21;
    // 0x80801F7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80801F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F84: jal         0x80102424
    // 0x80801F88: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x80801F88: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_22:
    // 0x80801F8C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80801F90: beq         $v0, $zero, L_80801FA0
    if (ctx->r2 == 0) {
        // 0x80801F94: nop
    
            goto L_80801FA0;
    }
    // 0x80801F94: nop

    // 0x80801F98: jal         0x800E1720
    // 0x80801F9C: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    func_800E1720(rdram, ctx);
        goto after_23;
    // 0x80801F9C: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    after_23:
L_80801FA0:
    // 0x80801FA0: jal         0x80101F24
    // 0x80801FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_24;
    // 0x80801FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80801FA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X65A8) << 16);
    // 0x80801FAC: lwc1        $f18, 0x65A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X65A8));
    // 0x80801FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FB4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801FB8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80801FBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801FC0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2484, 0X72BC) << 16);
    // 0x80801FC4: bc1fl       L_80801FE8
    if (!c1cs) {
        // 0x80801FC8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801FE8;
    }
    goto skip_1;
    // 0x80801FC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80801FCC: jal         0x80089D50
    // 0x80801FD0: addiu       $a3, $a3, 0x72BC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2484, 0X72BC));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_25;
    // 0x80801FD0: addiu       $a3, $a3, 0x72BC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2484, 0X72BC));
    after_25:
    // 0x80801FD4: b           L_80801FE8
    // 0x80801FD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801FE8;
    // 0x80801FD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801FDC:
    // 0x80801FDC: jal         0x8010C908
    // 0x80801FE0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_8010C908(rdram, ctx);
        goto after_26;
    // 0x80801FE0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_26:
L_80801FE4:
    // 0x80801FE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801FE8:
    // 0x80801FE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801FEC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80801FF0: jr          $ra
    // 0x80801FF4: nop

    return;
    // 0x80801FF4: nop

;}
RECOMP_FUNC void func_80106A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106A98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80106A9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80106AA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80106AA4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80106AA8: lbu         $v0, 0x7B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7B);
    // 0x80106AAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80106AB0: srl         $t6, $v0, 6
    ctx->r14 = S32(U32(ctx->r2) >> 6);
    // 0x80106AB4: beq         $t6, $zero, L_80106BD0
    if (ctx->r14 == 0) {
        // 0x80106AB8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80106BD0;
    }
    // 0x80106AB8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80106ABC: lh          $t8, 0x96($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X96);
    // 0x80106AC0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80106AC4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80106AC8: bgez        $t8, L_80106AF0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80106ACC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80106AF0;
    }
    // 0x80106ACC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80106AD0: jal         0x800DF660
    // 0x80106AD4: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    func_800DF660(rdram, ctx);
        goto after_0;
    // 0x80106AD4: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    after_0:
    // 0x80106AD8: jal         0x80100AC4
    // 0x80106ADC: lh          $a0, 0x60($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X60);
    func_80100AC4(rdram, ctx);
        goto after_1;
    // 0x80106ADC: lh          $a0, 0x60($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X60);
    after_1:
    // 0x80106AE0: jal         0x800DF720
    // 0x80106AE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_2;
    // 0x80106AE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80106AE8: b           L_80106BF8
    // 0x80106AEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80106BF8;
    // 0x80106AEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80106AF0:
    // 0x80106AF0: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80106AF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80106AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80106AFC: sll         $t1, $t9, 6
    ctx->r9 = S32(ctx->r25 << 6);
    // 0x80106B00: bgez        $t1, L_80106B28
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80106B04: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80106B28;
    }
    // 0x80106B04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80106B08: jal         0x800DF660
    // 0x80106B0C: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    func_800DF660(rdram, ctx);
        goto after_3;
    // 0x80106B0C: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    after_3:
    // 0x80106B10: jal         0x80100AC4
    // 0x80106B14: lh          $a0, 0x60($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X60);
    func_80100AC4(rdram, ctx);
        goto after_4;
    // 0x80106B14: lh          $a0, 0x60($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X60);
    after_4:
    // 0x80106B18: jal         0x800DF720
    // 0x80106B1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_5;
    // 0x80106B1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80106B20: b           L_80106BF8
    // 0x80106B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80106BF8;
    // 0x80106B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80106B28:
    // 0x80106B28: jal         0x80106C4C
    // 0x80106B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106C4C(rdram, ctx);
        goto after_6;
    // 0x80106B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80106B30: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80106B34: jal         0x800B27A0
    // 0x80106B38: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800B27A0(rdram, ctx);
        goto after_7;
    // 0x80106B38: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_7:
    // 0x80106B3C: bne         $v0, $zero, L_80106B60
    if (ctx->r2 != 0) {
        // 0x80106B40: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_80106B60;
    }
    // 0x80106B40: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80106B44: lbu         $t2, 0x7B($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X7B);
    // 0x80106B48: lbu         $t4, 0x77($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X77);
    // 0x80106B4C: andi        $t3, $t2, 0xFF3F
    ctx->r11 = ctx->r10 & 0XFF3F;
    // 0x80106B50: andi        $t5, $t4, 0xFFBF
    ctx->r13 = ctx->r12 & 0XFFBF;
    // 0x80106B54: sb          $t3, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r11;
    // 0x80106B58: b           L_80106BF4
    // 0x80106B5C: sb          $t5, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r13;
        goto L_80106BF4;
    // 0x80106B5C: sb          $t5, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r13;
L_80106B60:
    // 0x80106B60: beq         $a2, $zero, L_80106B80
    if (ctx->r6 == 0) {
        // 0x80106B64: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80106B80;
    }
    // 0x80106B64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80106B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80106B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80106B70: jal         0x800DF660
    // 0x80106B74: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    func_800DF660(rdram, ctx);
        goto after_8;
    // 0x80106B74: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    after_8:
    // 0x80106B78: b           L_80106BB8
    // 0x80106B7C: nop

        goto L_80106BB8;
    // 0x80106B7C: nop

L_80106B80:
    // 0x80106B80: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80106B84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80106B88: sll         $t8, $t6, 25
    ctx->r24 = S32(ctx->r14 << 25);
    // 0x80106B8C: bgezl       $t8, L_80106BA8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80106B90: lbu         $a1, 0x7B($s0)
        ctx->r5 = MEM_BU(ctx->r16, 0X7B);
            goto L_80106BA8;
    }
    goto skip_0;
    // 0x80106B90: lbu         $a1, 0x7B($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7B);
    skip_0:
    // 0x80106B94: lbu         $a1, 0x7B($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7B);
    // 0x80106B98: srl         $t9, $a1, 6
    ctx->r25 = S32(U32(ctx->r5) >> 6);
    // 0x80106B9C: b           L_80106BB0
    // 0x80106BA0: negu        $a1, $t9
    ctx->r5 = SUB32(0, ctx->r25);
        goto L_80106BB0;
    // 0x80106BA0: negu        $a1, $t9
    ctx->r5 = SUB32(0, ctx->r25);
    // 0x80106BA4: lbu         $a1, 0x7B($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7B);
L_80106BA8:
    // 0x80106BA8: srl         $t0, $a1, 6
    ctx->r8 = S32(U32(ctx->r5) >> 6);
    // 0x80106BAC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_80106BB0:
    // 0x80106BB0: jal         0x800DF660
    // 0x80106BB4: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    func_800DF660(rdram, ctx);
        goto after_9;
    // 0x80106BB4: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    after_9:
L_80106BB8:
    // 0x80106BB8: jal         0x80100AC4
    // 0x80106BBC: lh          $a0, 0x60($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X60);
    func_80100AC4(rdram, ctx);
        goto after_10;
    // 0x80106BBC: lh          $a0, 0x60($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X60);
    after_10:
    // 0x80106BC0: jal         0x800DF720
    // 0x80106BC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_11;
    // 0x80106BC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80106BC8: b           L_80106BF8
    // 0x80106BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80106BF8;
    // 0x80106BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80106BD0:
    // 0x80106BD0: lw          $t1, 0x78($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X78);
    // 0x80106BD4: sll         $t3, $t1, 30
    ctx->r11 = S32(ctx->r9 << 30);
    // 0x80106BD8: bgezl       $t3, L_80106BF8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80106BDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80106BF8;
    }
    goto skip_1;
    // 0x80106BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80106BE0: lbu         $a0, 0x98($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X98);
    // 0x80106BE4: lbu         $a1, 0x99($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X99);
    // 0x80106BE8: lbu         $a2, 0x9A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9A);
    // 0x80106BEC: jal         0x800DF5D8
    // 0x80106BF0: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    func_800DF5D8(rdram, ctx);
        goto after_12;
    // 0x80106BF0: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    after_12:
L_80106BF4:
    // 0x80106BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80106BF8:
    // 0x80106BF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80106BFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80106C00: jr          $ra
    // 0x80106C04: nop

    return;
    // 0x80106C04: nop

;}
RECOMP_FUNC void sulights_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800400: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800404: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800408: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080040C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800410: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800414: jal         0x80800000
    // 0x80800418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800000_sulights(rdram, ctx);
        goto after_0;
    // 0x80800418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8080041C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3374, 0X9E0) << 16);
    // 0x80800420: lwc1        $f0, 0x9E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3374, 0X9E0));
    // 0x80800424: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800428: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8080042C: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    // 0x80800430: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800434: nop

    // 0x80800438: bc1fl       L_8080044C
    if (!c1cs) {
        // 0x8080043C: swc1        $f2, 0x38($v0)
        MEM_W(0X38, ctx->r2) = ctx->f2.u32l;
            goto L_8080044C;
    }
    goto skip_0;
    // 0x8080043C: swc1        $f2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f2.u32l;
    skip_0:
    // 0x80800440: b           L_8080044C
    // 0x80800444: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
        goto L_8080044C;
    // 0x80800444: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x80800448: swc1        $f2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f2.u32l;
L_8080044C:
    // 0x8080044C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800450: jal         0x800EE830
    // 0x80800454: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800EE830(rdram, ctx);
        goto after_1;
    // 0x80800454: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800458: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8080045C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800460: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800464: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800468: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_8080046C:
    // 0x8080046C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800470: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80800474: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800478: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080047C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80800480: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800484: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800488: bne         $v0, $a2, L_8080046C
    if (ctx->r2 != ctx->r6) {
        // 0x8080048C: sw          $t8, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r24;
            goto L_8080046C;
    }
    // 0x8080048C: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x80800490: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800494: jal         0x800C8E84
    // 0x80800498: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800C8E84(rdram, ctx);
        goto after_2;
    // 0x80800498: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8080049C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004A4: jr          $ra
    // 0x808004A8: nop

    return;
    // 0x808004A8: nop

;}
RECOMP_FUNC void func_8080000C_chboggyboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800020: jal         0x80100094
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800028: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080002C: jal         0x80085CE0
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chboggykids_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800034: bne         $v0, $zero, L_8080004C
    if (ctx->r2 != 0) {
        // 0x80800038: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_8080004C;
    }
    // 0x80800038: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080003C: jal         0x800FFAB0
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800044: b           L_808000A8
    // 0x80800048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000A8;
    // 0x80800048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080004C:
    // 0x8080004C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800050: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    // 0x80800054: jal         0x800DA298
    // 0x80800058: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800058: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x8080005C: bnel        $v0, $zero, L_80800078
    if (ctx->r2 != 0) {
        // 0x80800060: lbu         $t7, 0x16($s1)
        ctx->r15 = MEM_BU(ctx->r17, 0X16);
            goto L_80800078;
    }
    goto skip_0;
    // 0x80800060: lbu         $t7, 0x16($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X16);
    skip_0:
    // 0x80800064: jal         0x8010A570
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080006C: b           L_80800080
    // 0x80800070: nop

        goto L_80800080;
    // 0x80800070: nop

    // 0x80800074: lbu         $t7, 0x16($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X16);
L_80800078:
    // 0x80800078: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x8080007C: sb          $t8, 0x16($s1)
    MEM_B(0X16, ctx->r17) = ctx->r24;
L_80800080:
    // 0x80800080: jal         0x8008A498
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    // 0x80800090: jal         0x80089F70
    // 0x80800094: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800094: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80800098: sh          $zero, 0x14($s1)
    MEM_H(0X14, ctx->r17) = 0;
    // 0x8080009C: jal         0x8080082C
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080082C_chboggyboy(rdram, ctx);
        goto after_7;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A8:
    // 0x808000A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000B0: jr          $ra
    // 0x808000B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void suexpression_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808005C4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808005C8: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x808005CC: trunc.w.s   $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x808005D0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x808005D4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x808005D8: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x808005DC: jr          $ra
    // 0x808005E0: sh          $t9, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r25;
    return;
    // 0x808005E0: sh          $t9, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_80807D70_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807D70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80807D74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80807D78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807D7C: jal         0x808001D0
    // 0x80807D80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001D0_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80807D80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80807D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807D88: jal         0x80809DA0
    // 0x80807D8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80809DA0_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80807D8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80807D90: jal         0x808067B0
    // 0x80807D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808067B0_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80807D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80807D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807D9C: jal         0x80801B64
    // 0x80807DA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801B64_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80807DA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80807DA4: jal         0x80802ED4
    // 0x80807DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802ED4_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80807DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80807DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807DB0: jal         0x800A34E4
    // 0x80807DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A34E4(rdram, ctx);
        goto after_5;
    // 0x80807DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80807DB8: jal         0x8009BD50
    // 0x80807DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BD50(rdram, ctx);
        goto after_6;
    // 0x80807DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80807DC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80807DC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807DC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80807DCC: jr          $ra
    // 0x80807DD0: nop

    return;
    // 0x80807DD0: nop

;}
RECOMP_FUNC void func_80802434_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802434: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802438: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x8080243C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802440: sltiu       $at, $t7, 0x10
    ctx->r1 = ctx->r15 < 0X10 ? 1 : 0;
    // 0x80802444: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080244C: beq         $at, $zero, L_80802608
    if (ctx->r1 == 0) {
        // 0x80802450: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80802608;
    }
    // 0x80802450: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802454: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80802458: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X65C8) << 16);
    // 0x8080245C: addu        $at, $at, $t7
    gpr jr_addend_80802464 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80802460: lw          $t7, 0x65C8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X65C8));
    // 0x80802464: jr          $t7
    // 0x80802468: nop

    switch (jr_addend_80802464 >> 2) {
        case 0: goto L_8080246C; break;
        case 1: goto L_80802608; break;
        case 2: goto L_80802480; break;
        case 3: goto L_80802494; break;
        case 4: goto L_808024A8; break;
        case 5: goto L_80802608; break;
        case 6: goto L_808024C4; break;
        case 7: goto L_808024D8; break;
        case 8: goto L_80802608; break;
        case 9: goto L_80802500; break;
        case 10: goto L_808024EC; break;
        case 11: goto L_80802514; break;
        case 12: goto L_80802524; break;
        case 13: goto L_80802554; break;
        case 14: goto L_80802568; break;
        case 15: goto L_808025F0; break;
        default: switch_error(__func__, 0x80802464, 0x808065C8);
    }
    // 0x80802468: nop

L_8080246C:
    // 0x8080246C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802470: jal         0x80802108
    // 0x80802474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802108_chquiz(rdram, ctx);
        goto after_0;
    // 0x80802474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80802478: b           L_8080260C
    // 0x8080247C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x8080247C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802480:
    // 0x80802480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802484: jal         0x80802108
    // 0x80802488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802108_chquiz(rdram, ctx);
        goto after_1;
    // 0x80802488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080248C: b           L_8080260C
    // 0x80802490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x80802490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802494:
    // 0x80802494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802498: jal         0x80802108
    // 0x8080249C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802108_chquiz(rdram, ctx);
        goto after_2;
    // 0x8080249C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808024A0: b           L_8080260C
    // 0x808024A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x808024A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808024A8:
    // 0x808024A8: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x808024AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808024B0: srl         $t8, $a0, 7
    ctx->r24 = S32(U32(ctx->r4) >> 7);
    // 0x808024B4: jal         0x80803368
    // 0x808024B8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80803368_chquiz(rdram, ctx);
        goto after_3;
    // 0x808024B8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_3:
    // 0x808024BC: b           L_8080260C
    // 0x808024C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x808024C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808024C4:
    // 0x808024C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024C8: jal         0x80802108
    // 0x808024CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802108_chquiz(rdram, ctx);
        goto after_4;
    // 0x808024CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808024D0: b           L_8080260C
    // 0x808024D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x808024D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808024D8:
    // 0x808024D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024DC: jal         0x80802108
    // 0x808024E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802108_chquiz(rdram, ctx);
        goto after_5;
    // 0x808024E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808024E4: b           L_8080260C
    // 0x808024E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x808024E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808024EC:
    // 0x808024EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024F0: jal         0x80802108
    // 0x808024F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802108_chquiz(rdram, ctx);
        goto after_6;
    // 0x808024F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808024F8: b           L_8080260C
    // 0x808024FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x808024FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802500:
    // 0x80802500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802504: jal         0x80802108
    // 0x80802508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802108_chquiz(rdram, ctx);
        goto after_7;
    // 0x80802508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8080250C: b           L_8080260C
    // 0x80802510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x80802510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802514:
    // 0x80802514: jal         0x8080216C
    // 0x80802518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080216C_chquiz(rdram, ctx);
        goto after_8;
    // 0x80802518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080251C: b           L_8080260C
    // 0x80802520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x80802520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802524:
    // 0x80802524: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80802528: srl         $t9, $a0, 7
    ctx->r25 = S32(U32(ctx->r4) >> 7);
    // 0x8080252C: jal         0x80801C7C
    // 0x80802530: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_80801C7C_chquiz(rdram, ctx);
        goto after_9;
    // 0x80802530: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_9:
    // 0x80802534: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80802538: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x8080253C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802540: srl         $t0, $a0, 7
    ctx->r8 = S32(U32(ctx->r4) >> 7);
    // 0x80802544: jal         0x80803320
    // 0x80802548: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80803320_chquiz(rdram, ctx);
        goto after_10;
    // 0x80802548: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_10:
    // 0x8080254C: b           L_8080260C
    // 0x80802550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x80802550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802554:
    // 0x80802554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802558: jal         0x80802108
    // 0x8080255C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802108_chquiz(rdram, ctx);
        goto after_11;
    // 0x8080255C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80802560: b           L_8080260C
    // 0x80802564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x80802564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802568:
    // 0x80802568: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x8080256C: addiu       $a0, $zero, 0x52B
    ctx->r4 = ADD32(0, 0X52B);
    // 0x80802570: srl         $t1, $a1, 7
    ctx->r9 = S32(U32(ctx->r5) >> 7);
    // 0x80802574: jal         0x80089C78
    // 0x80802578: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    _subaddiefind_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80802578: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_12:
    // 0x8080257C: jal         0x800FFAB0
    // 0x80802580: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x80802580: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80802584: jal         0x800FFAB0
    // 0x80802588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x80802588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080258C: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
    // 0x80802590: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802594: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x80802598: bnel        $t3, $at, L_8080260C
    if (ctx->r11 != ctx->r1) {
        // 0x8080259C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080260C;
    }
    goto skip_0;
    // 0x8080259C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808025A0: jal         0x800D395C
    // 0x808025A4: nop

    func_800D395C(rdram, ctx);
        goto after_15;
    // 0x808025A4: nop

    after_15:
    // 0x808025A8: bnel        $v0, $zero, L_8080260C
    if (ctx->r2 != 0) {
        // 0x808025AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080260C;
    }
    goto skip_1;
    // 0x808025AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808025B0: jal         0x800F54E4
    // 0x808025B4: nop

    func_800F54E4(rdram, ctx);
        goto after_16;
    // 0x808025B4: nop

    after_16:
    // 0x808025B8: jal         0x800F4CC0
    // 0x808025BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_17;
    // 0x808025BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x808025C0: jal         0x800F54E4
    // 0x808025C4: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x808025C4: nop

    after_18:
    // 0x808025C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808025CC: jal         0x800F4CEC
    // 0x808025D0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800F4CEC(rdram, ctx);
        goto after_19;
    // 0x808025D0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_19:
    // 0x808025D4: jal         0x800F54E4
    // 0x808025D8: nop

    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x808025D8: nop

    after_20:
    // 0x808025DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808025E0: jal         0x800F7B9C
    // 0x808025E4: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_800F7B9C(rdram, ctx);
        goto after_21;
    // 0x808025E4: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_21:
    // 0x808025E8: b           L_8080260C
    // 0x808025EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080260C;
    // 0x808025EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808025F0:
    // 0x808025F0: jal         0x800F54E4
    // 0x808025F4: nop

    func_800F54E4(rdram, ctx);
        goto after_22;
    // 0x808025F4: nop

    after_22:
    // 0x808025F8: jal         0x800F4CC0
    // 0x808025FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_23;
    // 0x808025FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x80802600: jal         0x800FFAB0
    // 0x80802604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_24;
    // 0x80802604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
L_80802608:
    // 0x80802608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080260C:
    // 0x8080260C: jal         0x80102424
    // 0x80802610: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80102424(rdram, ctx);
        goto after_25;
    // 0x80802610: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_25:
    // 0x80802614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802618: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080261C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802620: jr          $ra
    // 0x80802624: nop

    return;
    // 0x80802624: nop

;}
RECOMP_FUNC void func_80800380_chhoneycarrier(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800388: jal         0x80101870
    // 0x8080038C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x8080038C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800394: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800398: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x8080039C: bgezl       $t8, L_808003B0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808003A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003B0;
    }
    goto skip_0;
    // 0x808003A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808003A4: jal         0x80103110
    // 0x808003A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808003A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808003AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B0:
    // 0x808003B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void func_80800244_chdinofamilysick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800244: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800248: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080024C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800250: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800254: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800258: jal         0x800CB3E0
    // 0x8080025C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800CB3E0(rdram, ctx);
        goto after_0;
    // 0x8080025C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800260: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800264: beq         $v0, $at, L_80800298
    if (ctx->r2 == ctx->r1) {
        // 0x80800268: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800298;
    }
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800270: beq         $v0, $at, L_808002A8
    if (ctx->r2 == ctx->r1) {
        // 0x80800274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A8;
    }
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080027C: beq         $v0, $at, L_808002BC
    if (ctx->r2 == ctx->r1) {
        // 0x80800280: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_808002BC;
    }
    // 0x80800280: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800284: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800288: beq         $v0, $at, L_808002F0
    if (ctx->r2 == ctx->r1) {
        // 0x8080028C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F0;
    }
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: b           L_808002FC
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002FC;
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800298:
    // 0x80800298: jal         0x80102424
    // 0x8080029C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080029C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808002A0: b           L_808002FC
    // 0x808002A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002FC;
    // 0x808002A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002A8:
    // 0x808002A8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808002AC: jal         0x8008A548
    // 0x808002B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _subaddietaxi_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808002B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x808002B4: b           L_808002FC
    // 0x808002B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002FC;
    // 0x808002B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002BC:
    // 0x808002BC: jal         0x808001FC
    // 0x808002C0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_808001FC_chdinofamilysick(rdram, ctx);
        goto after_3;
    // 0x808002C0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x808002C4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002CC: jal         0x80102424
    // 0x808002D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x808002D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808002DC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x808002E0: jal         0x8008A4F8
    // 0x808002E4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    _subaddietaxi_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808002E4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_5:
    // 0x808002E8: b           L_808002FC
    // 0x808002EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002FC;
    // 0x808002EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002F0:
    // 0x808002F0: jal         0x80102424
    // 0x808002F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808002F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x808002F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002FC:
    // 0x808002FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800300: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800304: jr          $ra
    // 0x80800308: nop

    return;
    // 0x80800308: nop

;}
RECOMP_FUNC void vector_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2D30: jal         0x8001B084
    // 0x800B2D34: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800B2D34: nop

    after_0:
    // 0x800B2D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2D3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2D40: jr          $ra
    // 0x800B2D44: nop

    return;
    // 0x800B2D44: nop

;}
RECOMP_FUNC void _chbanjoctrl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086398: syscall     315
    recomp_syscall_handler(rdram, ctx, 0x80086398);
    return;
    // 0x8008639C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800008_ncbajig(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x80112524
    // 0x80800014: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800014: nop

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
RECOMP_FUNC void _gldialog_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088748: syscall     702
    recomp_syscall_handler(rdram, ctx, 0x80088748);
    return;
    // 0x8008874C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _gzthread_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A970: syscall     881
    recomp_syscall_handler(rdram, ctx, 0x8008A970);
    return;
    // 0x8008A974: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801258_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801258: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080125C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801260: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801264: jal         0x80800ECC
    // 0x80801268: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    bstnt_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801268: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080126C: jal         0x8008CABC
    // 0x80801270: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x80801270: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80801274: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801278: jal         0x8008AF24
    // 0x8080127C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x8080127C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801284: jal         0x8008AED4
    // 0x80801288: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80801288: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    after_3:
    // 0x8080128C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80801290: ori         $a1, $a1, 0xEBEE
    ctx->r5 = ctx->r5 | 0XEBEE;
    // 0x80801294: jal         0x8008B24C
    // 0x80801298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_4;
    // 0x80801298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080129C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808012A0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808012A4: jal         0x8008B1BC
    // 0x808012A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x808012A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808012AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012B0: jal         0x8008B134
    // 0x808012B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x808012B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808012B8: jal         0x8008B064
    // 0x808012BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x808012BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808012C0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x808012C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808012C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808012CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808012D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808012D4: jal         0x8009FFD8
    // 0x808012D8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x808012D8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x808012DC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808012E0: sw          $zero, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = 0;
    // 0x808012E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808012E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808012EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808012F0: jr          $ra
    // 0x808012F4: nop

    return;
    // 0x808012F4: nop

;}
RECOMP_FUNC void bsjump_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005B0: jal         0x800C6E38
    // 0x808005B4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x808005B4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x808005B8: beq         $v0, $zero, L_808005C8
    if (ctx->r2 == 0) {
        // 0x808005BC: nop
    
            goto L_808005C8;
    }
    // 0x808005BC: nop

    // 0x808005C0: jal         0x800C6DA0
    // 0x808005C4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_800C6DA0(rdram, ctx);
        goto after_1;
    // 0x808005C4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_1:
L_808005C8:
    // 0x808005C8: jal         0x8009E704
    // 0x808005CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bs_getNextState(rdram, ctx);
        goto after_2;
    // 0x808005CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808005D0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808005D4: beql        $v0, $at, L_808005E8
    if (ctx->r2 == ctx->r1) {
        // 0x808005D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005E8;
    }
    goto skip_0;
    // 0x808005D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808005DC: jal         0x8009BC6C
    // 0x808005E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_3;
    // 0x808005E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808005E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005E8:
    // 0x808005E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005EC: jr          $ra
    // 0x808005F0: nop

    return;
    // 0x808005F0: nop

;}
RECOMP_FUNC void ncfixposrot_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001CC: jal         0x8011001C
    // 0x808001D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8011001C(rdram, ctx);
        goto after_0;
    // 0x808001D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001D4: lh          $t6, 0x18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X18);
    // 0x808001D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001E0: beql        $t6, $zero, L_808001FC
    if (ctx->r14 == 0) {
        // 0x808001E4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x808001E8: jal         0x800C53EC
    // 0x808001EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800C53EC(rdram, ctx);
        goto after_1;
    // 0x808001EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001F0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F4: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x808001F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808001FC:
    // 0x808001FC: jal         0x8010F9C0
    // 0x80800200: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010F9C0(rdram, ctx);
        goto after_2;
    // 0x80800200: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080020C: jr          $ra
    // 0x80800210: nop

    return;
    // 0x80800210: nop

;}
RECOMP_FUNC void func_80801850_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801850: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801854: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801858: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080185C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801860: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801864: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801868: jal         0x80100094
    // 0x8080186C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080186C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801870: lwc1        $f2, 0x93C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X93C);
    // 0x80801874: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80801878: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080187C: swc1        $f2, 0x91C($v0)
    MEM_W(0X91C, ctx->r2) = ctx->f2.u32l;
    // 0x80801880: lwc1        $f6, 0x24($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X24);
    // 0x80801884: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801888: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4470) << 16);
    // 0x8080188C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801890: nop

    // 0x80801894: bc1f        L_8080193C
    if (!c1cs) {
        // 0x80801898: nop
    
            goto L_8080193C;
    }
    // 0x80801898: nop

    // 0x8080189C: lwc1        $f0, 0x920($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X920);
    // 0x808018A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808018A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808018A8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808018AC: nop

    // 0x808018B0: bc1fl       L_808018D4
    if (!c1cs) {
        // 0x808018B4: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_808018D4;
    }
    goto skip_0;
    // 0x808018B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x808018B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808018BC: lwc1        $f0, 0x920($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X920);
    // 0x808018C0: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x808018C4: swc1        $f10, 0x93C($v0)
    MEM_W(0X93C, ctx->r2) = ctx->f10.u32l;
    // 0x808018C8: b           L_808018F4
    // 0x808018CC: lwc1        $f2, 0x93C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X93C);
        goto L_808018F4;
    // 0x808018CC: lwc1        $f2, 0x93C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X93C);
    // 0x808018D0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_808018D4:
    // 0x808018D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808018D8: bc1fl       L_808018F8
    if (!c1cs) {
        // 0x808018DC: c.lt.s      $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
            goto L_808018F8;
    }
    goto skip_1;
    // 0x808018DC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    skip_1:
    // 0x808018E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808018E4: lwc1        $f0, 0x920($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X920);
    // 0x808018E8: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x808018EC: swc1        $f18, 0x93C($v0)
    MEM_W(0X93C, ctx->r2) = ctx->f18.u32l;
    // 0x808018F0: lwc1        $f2, 0x93C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X93C);
L_808018F4:
    // 0x808018F4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
L_808018F8:
    // 0x808018F8: nop

    // 0x808018FC: bc1fl       L_80801924
    if (!c1cs) {
        // 0x80801900: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80801924;
    }
    goto skip_2;
    // 0x80801900: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_2:
    // 0x80801904: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80801908: nop

    // 0x8080190C: bc1fl       L_80801950
    if (!c1cs) {
        // 0x80801910: lui         $at, 0xC0A0
        ctx->r1 = S32(0XC0A0 << 16);
            goto L_80801950;
    }
    goto skip_3;
    // 0x80801910: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    skip_3:
    // 0x80801914: swc1        $f0, 0x93C($v0)
    MEM_W(0X93C, ctx->r2) = ctx->f0.u32l;
    // 0x80801918: b           L_8080194C
    // 0x8080191C: lwc1        $f2, 0x93C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X93C);
        goto L_8080194C;
    // 0x8080191C: lwc1        $f2, 0x93C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X93C);
    // 0x80801920: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80801924:
    // 0x80801924: nop

    // 0x80801928: bc1fl       L_80801950
    if (!c1cs) {
        // 0x8080192C: lui         $at, 0xC0A0
        ctx->r1 = S32(0XC0A0 << 16);
            goto L_80801950;
    }
    goto skip_4;
    // 0x8080192C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    skip_4:
    // 0x80801930: swc1        $f0, 0x93C($v0)
    MEM_W(0X93C, ctx->r2) = ctx->f0.u32l;
    // 0x80801934: b           L_8080194C
    // 0x80801938: lwc1        $f2, 0x93C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X93C);
        goto L_8080194C;
    // 0x80801938: lwc1        $f2, 0x93C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X93C);
L_8080193C:
    // 0x8080193C: lwc1        $f6, 0x4470($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4470));
    // 0x80801940: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80801944: swc1        $f8, 0x93C($v0)
    MEM_W(0X93C, ctx->r2) = ctx->f8.u32l;
    // 0x80801948: lwc1        $f2, 0x93C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X93C);
L_8080194C:
    // 0x8080194C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
L_80801950:
    // 0x80801950: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801954: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801958: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8080195C: nop

    // 0x80801960: bc1tl       L_80801984
    if (c1cs) {
        // 0x80801964: lbu         $t6, 0x924($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X924);
            goto L_80801984;
    }
    goto skip_5;
    // 0x80801964: lbu         $t6, 0x924($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X924);
    skip_5:
    // 0x80801968: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080196C: nop

    // 0x80801970: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80801974: nop

    // 0x80801978: bc1fl       L_808019A8
    if (!c1cs) {
        // 0x8080197C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808019A8;
    }
    goto skip_6;
    // 0x8080197C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_6:
    // 0x80801980: lbu         $t6, 0x924($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X924);
L_80801984:
    // 0x80801984: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x80801988: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080198C: beql        $t6, $zero, L_808019A8
    if (ctx->r14 == 0) {
        // 0x80801990: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808019A8;
    }
    goto skip_7;
    // 0x80801990: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_7:
    // 0x80801994: lbu         $a0, 0x924($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X924);
    // 0x80801998: jal         0x800C4350
    // 0x8080199C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x8080199C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_1:
    // 0x808019A0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808019A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_808019A8:
    // 0x808019A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808019AC: lwc1        $f18, 0x91C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X91C);
    // 0x808019B0: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x808019B4: nop

    // 0x808019B8: bc1fl       L_80801A2C
    if (!c1cs) {
        // 0x808019BC: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80801A2C;
    }
    goto skip_8;
    // 0x808019BC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    skip_8:
    // 0x808019C0: lwc1        $f4, 0x93C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X93C);
    // 0x808019C4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X46F4) << 16);
    // 0x808019C8: addiu       $a2, $a2, 0x46F4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X46F4));
    // 0x808019CC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808019D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808019D4: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x808019D8: bc1fl       L_80801A2C
    if (!c1cs) {
        // 0x808019DC: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80801A2C;
    }
    goto skip_9;
    // 0x808019DC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    skip_9:
    // 0x808019E0: jal         0x80089D18
    // 0x808019E4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808019E4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_2:
    // 0x808019E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4474) << 16);
    // 0x808019EC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808019F0: lwc1        $f6, 0x4474($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4474));
    // 0x808019F4: jal         0x800DC0C0
    // 0x808019F8: swc1        $f6, 0x934($v1)
    MEM_W(0X934, ctx->r3) = ctx->f6.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_3;
    // 0x808019F8: swc1        $f6, 0x934($v1)
    MEM_W(0X934, ctx->r3) = ctx->f6.u32l;
    after_3:
    // 0x808019FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801A00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801A04: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80801A08: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80801A0C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80801A10: nop

    // 0x80801A14: bc1fl       L_80801A2C
    if (!c1cs) {
        // 0x80801A18: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80801A2C;
    }
    goto skip_10;
    // 0x80801A18: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    skip_10:
    // 0x80801A1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801A20: nop

    // 0x80801A24: swc1        $f10, 0x93C($v1)
    MEM_W(0X93C, ctx->r3) = ctx->f10.u32l;
    // 0x80801A28: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
L_80801A2C:
    // 0x80801A2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801A30: lwc1        $f16, 0x91C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X91C);
    // 0x80801A34: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80801A38: nop

    // 0x80801A3C: bc1f        L_80801AAC
    if (!c1cs) {
        // 0x80801A40: nop
    
            goto L_80801AAC;
    }
    // 0x80801A40: nop

    // 0x80801A44: lwc1        $f18, 0x93C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X93C);
    // 0x80801A48: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X46F4) << 16);
    // 0x80801A4C: addiu       $a2, $a2, 0x46F4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X46F4));
    // 0x80801A50: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80801A54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801A58: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x80801A5C: bc1f        L_80801AAC
    if (!c1cs) {
        // 0x80801A60: nop
    
            goto L_80801AAC;
    }
    // 0x80801A60: nop

    // 0x80801A64: jal         0x80089D18
    // 0x80801A68: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80801A68: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_4:
    // 0x80801A6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4478) << 16);
    // 0x80801A70: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80801A74: lwc1        $f4, 0x4478($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4478));
    // 0x80801A78: jal         0x800DC0C0
    // 0x80801A7C: swc1        $f4, 0x938($v1)
    MEM_W(0X938, ctx->r3) = ctx->f4.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80801A7C: swc1        $f4, 0x938($v1)
    MEM_W(0X938, ctx->r3) = ctx->f4.u32l;
    after_5:
    // 0x80801A80: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801A84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801A88: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80801A8C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801A90: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80801A94: nop

    // 0x80801A98: bc1f        L_80801AAC
    if (!c1cs) {
        // 0x80801A9C: nop
    
            goto L_80801AAC;
    }
    // 0x80801A9C: nop

    // 0x80801AA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801AA4: nop

    // 0x80801AA8: swc1        $f8, 0x93C($v1)
    MEM_W(0X93C, ctx->r3) = ctx->f8.u32l;
L_80801AAC:
    // 0x80801AAC: jal         0x800DC0C0
    // 0x80801AB0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800DC0C0(rdram, ctx);
        goto after_6;
    // 0x80801AB0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_6:
    // 0x80801AB4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X447C) << 16);
    // 0x80801AB8: lwc1        $f10, 0x447C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X447C));
    // 0x80801ABC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801AC0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80801AC4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80801AC8: nop

    // 0x80801ACC: bc1f        L_80801B30
    if (!c1cs) {
        // 0x80801AD0: nop
    
            goto L_80801B30;
    }
    // 0x80801AD0: nop

    // 0x80801AD4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801AD8: lwc1        $f18, 0x24($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X24);
    // 0x80801ADC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80801AE0: nop

    // 0x80801AE4: bc1f        L_80801B30
    if (!c1cs) {
        // 0x80801AE8: nop
    
            goto L_80801B30;
    }
    // 0x80801AE8: nop

    // 0x80801AEC: lwc1        $f0, 0x93C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X93C);
    // 0x80801AF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801AF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801AF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4480) << 16);
    // 0x80801AFC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801B00: nop

    // 0x80801B04: bc1fl       L_80801B1C
    if (!c1cs) {
        // 0x80801B08: c.lt.s      $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
            goto L_80801B1C;
    }
    goto skip_11;
    // 0x80801B08: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    skip_11:
    // 0x80801B0C: lwc1        $f6, 0x4480($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4480));
    // 0x80801B10: lwc1        $f0, 0x93C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X93C);
    // 0x80801B14: swc1        $f6, 0x934($v1)
    MEM_W(0X934, ctx->r3) = ctx->f6.u32l;
    // 0x80801B18: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
L_80801B1C:
    // 0x80801B1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4484) << 16);
    // 0x80801B20: bc1f        L_80801B30
    if (!c1cs) {
        // 0x80801B24: nop
    
            goto L_80801B30;
    }
    // 0x80801B24: nop

    // 0x80801B28: lwc1        $f10, 0x4484($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4484));
    // 0x80801B2C: swc1        $f10, 0x938($v1)
    MEM_W(0X938, ctx->r3) = ctx->f10.u32l;
L_80801B30:
    // 0x80801B30: jal         0x800D8FF8
    // 0x80801B34: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x80801B34: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_7:
    // 0x80801B38: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80801B3C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80801B40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80801B44:
    // 0x80801B44: lwc1        $f0, 0x934($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X934);
    // 0x80801B48: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80801B4C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801B50: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80801B54: nop

    // 0x80801B58: bc1fl       L_80801B78
    if (!c1cs) {
        // 0x80801B5C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801B78;
    }
    goto skip_12;
    // 0x80801B5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_12:
    // 0x80801B60: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80801B64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801B68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801B6C: jal         0x80801638
    // 0x80801B70: swc1        $f4, 0x934($s1)
    MEM_W(0X934, ctx->r17) = ctx->f4.u32l;
    func_80801638_chhandcart(rdram, ctx);
        goto after_8;
    // 0x80801B70: swc1        $f4, 0x934($s1)
    MEM_W(0X934, ctx->r17) = ctx->f4.u32l;
    after_8:
    // 0x80801B74: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801B78:
    // 0x80801B78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801B7C: bne         $s0, $at, L_80801B44
    if (ctx->r16 != ctx->r1) {
        // 0x80801B80: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80801B44;
    }
    // 0x80801B80: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80801B84: jal         0x8080176C
    // 0x80801B88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8080176C_chhandcart(rdram, ctx);
        goto after_9;
    // 0x80801B88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80801B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801B90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801B94: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B98: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801B9C: jr          $ra
    // 0x80801BA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801BA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _gspropprop_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C20: syscall     729
    recomp_syscall_handler(rdram, ctx, 0x80088C20);
    return;
    // 0x80088C24: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800164_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080016C: lhu         $v0, 0x78($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X78);
    // 0x80800170: lbu         $t7, 0x9B($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X9B);
    // 0x80800174: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80800178: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8080017C: beq         $t7, $at, L_80800194
    if (ctx->r15 == ctx->r1) {
        // 0x80800180: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800194;
    }
    // 0x80800180: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800184: lbu         $t8, 0x79($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X79);
    // 0x80800188: andi        $t9, $t8, 0xFFFC
    ctx->r25 = ctx->r24 & 0XFFFC;
    // 0x8080018C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80800190: sb          $t0, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r8;
L_80800194:
    // 0x80800194: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800198: jal         0x80089C08
    // 0x8080019C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddiedraw25d_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080019C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001A4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A8: lbu         $t3, 0x79($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X79);
    // 0x808001AC: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x808001B0: andi        $t4, $t3, 0xFFFC
    ctx->r12 = ctx->r11 & 0XFFFC;
    // 0x808001B4: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808001B8: sb          $t5, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r13;
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void func_80800564_chsquits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080056C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800570: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800574: jal         0x800DC128
    // 0x80800578: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x80800578: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8080057C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800580: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800584: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    // 0x80800588: swc1        $f4, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f4.u32l;
    // 0x8080058C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800594: jr          $ra
    // 0x80800598: nop

    return;
    // 0x80800598: nop

    // 0x8080059C: nop

;}
RECOMP_FUNC void func_80800000_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80100094
    // 0x8080000C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080000C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800010: addiu       $a0, $zero, 0xA34
    ctx->r4 = ADD32(0, 0XA34);
    // 0x80800014: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800018: jal         0x800DA564
    // 0x8080001C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x8080001C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800020: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: sb          $v0, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r2;
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800030: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_80801884_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801884: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801888: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080188C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801890: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801894: jal         0x800D9078
    // 0x80801898: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80801898: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x8080189C: beq         $v0, $zero, L_80801928
    if (ctx->r2 == 0) {
        // 0x808018A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801928;
    }
    // 0x808018A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018A4: jal         0x80100094
    // 0x808018A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808018A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808018AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808018B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018B4: jal         0x80102424
    // 0x808018B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808018B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x808018BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1324, 0X227C) << 16);
    // 0x808018C0: addiu       $a2, $a2, 0x227C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1324, 0X227C));
    // 0x808018C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018C8: jal         0x80089D18
    // 0x808018CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808018CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808018D0: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808018D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808018D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808018DC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x808018E0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x808018E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018E8: jal         0x80089CA0
    // 0x808018EC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808018EC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x808018F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018F4: jal         0x8010A800
    // 0x808018F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_5;
    // 0x808018F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808018FC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80801900: lw          $a0, 0x30($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X30);
    // 0x80801904: beql        $a0, $zero, L_8080192C
    if (ctx->r4 == 0) {
        // 0x80801908: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080192C;
    }
    goto skip_0;
    // 0x80801908: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080190C: jal         0x80106790
    // 0x80801910: nop

    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80801910: nop

    after_6:
    // 0x80801914: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
    // 0x80801918: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080191C: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x80801920: jal         0x8010A590
    // 0x80801924: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
    func_8010A590(rdram, ctx);
        goto after_7;
    // 0x80801924: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
    after_7:
L_80801928:
    // 0x80801928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080192C:
    // 0x8080192C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801930: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801934: jr          $ra
    // 0x80801938: nop

    return;
    // 0x80801938: nop

;}
RECOMP_FUNC void func_80800A80_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800A8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A90: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800A94: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800A98: jal         0x80100094
    // 0x80800A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800AA0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800AA4: lbu         $v1, 0x5F($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5F);
    // 0x80800AA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800AAC: beq         $v1, $zero, L_80800ACC
    if (ctx->r3 == 0) {
        // 0x80800AB0: nop
    
            goto L_80800ACC;
    }
    // 0x80800AB0: nop

    // 0x80800AB4: beq         $v1, $at, L_80800B04
    if (ctx->r3 == ctx->r1) {
        // 0x80800AB8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800B04;
    }
    // 0x80800AB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800ABC: beql        $v1, $at, L_80800AFC
    if (ctx->r3 == ctx->r1) {
        // 0x80800AC0: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80800AFC;
    }
    goto skip_0;
    // 0x80800AC0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800AC4: b           L_80800B28
    // 0x80800AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B28;
    // 0x80800AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800ACC:
    // 0x80800ACC: jal         0x80800438
    // 0x80800AD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800438_chdragonbrothers(rdram, ctx);
        goto after_1;
    // 0x80800AD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800AD4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AD8: jal         0x800F5EF8
    // 0x80800ADC: lw          $a0, 0x20($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20);
    func_800F5EF8(rdram, ctx);
        goto after_2;
    // 0x80800ADC: lw          $a0, 0x20($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20);
    after_2:
    // 0x80800AE0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800AE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AE8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800AEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800AF0: jal         0x80089540
    // 0x80800AF4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    _ncpod_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x80800AF4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_3:
    // 0x80800AF8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_80800AFC:
    // 0x80800AFC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800B00: sb          $t8, 0x5F($t9)
    MEM_B(0X5F, ctx->r25) = ctx->r24;
L_80800B04:
    // 0x80800B04: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B08: jal         0x800F5EF8
    // 0x80800B0C: lw          $a0, 0x20($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X20);
    func_800F5EF8(rdram, ctx);
        goto after_4;
    // 0x80800B0C: lw          $a0, 0x20($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X20);
    after_4:
    // 0x80800B10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B14: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B18: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800B1C: jal         0x80089560
    // 0x80800B20: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _ncpod_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x80800B20: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B28:
    // 0x80800B28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B2C: jr          $ra
    // 0x80800B30: nop

    return;
    // 0x80800B30: nop

;}
RECOMP_FUNC void func_80800030_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800034: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8080003C: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80800040: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80800044: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80800048: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8080004C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800050: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800054: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800058: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8080005C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800060: jal         0x80100094
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800068: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080006C: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    // 0x80800070: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80800074: jal         0x800882C0
    // 0x80800078: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800078: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x8080007C: blez        $v0, L_80800130
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800080: sw          $zero, 0x60($s0)
        MEM_W(0X60, ctx->r16) = 0;
            goto L_80800130;
    }
    // 0x80800080: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x80800084: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800088: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080008C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800090: addiu       $s1, $sp, 0x70
    ctx->r17 = ADD32(ctx->r29, 0X70);
    // 0x80800094: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800098: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080009C: addu        $s6, $t7, $s1
    ctx->r22 = ADD32(ctx->r15, ctx->r17);
    // 0x808000A0: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x808000A4: addiu       $s4, $sp, 0x54
    ctx->r20 = ADD32(ctx->r29, 0X54);
    // 0x808000A8: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x808000AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_808000B0:
    // 0x808000B0: jal         0x800EE88C
    // 0x808000B4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x808000B4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x808000B8: jal         0x800CBC3C
    // 0x808000BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800CBC3C(rdram, ctx);
        goto after_3;
    // 0x808000BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x808000C0: beq         $v0, $s7, L_80800120
    if (ctx->r2 == ctx->r23) {
        // 0x808000C4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800120;
    }
    // 0x808000C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808000C8: lw          $t8, 0x60($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X60);
    // 0x808000CC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808000D0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808000D4: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000D8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x808000DC: mflo        $t9
    ctx->r25 = lo;
    // 0x808000E0: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x808000E4: jal         0x800DC178
    // 0x808000E8: swc1        $f4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f4.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808000E8: swc1        $f4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f4.u32l;
    after_4:
    // 0x808000EC: lw          $t1, 0x60($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X60);
    // 0x808000F0: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000F4: mflo        $t2
    ctx->r10 = lo;
    // 0x808000F8: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x808000FC: swc1        $f0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f0.u32l;
    // 0x80800100: lw          $t4, 0x60($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X60);
    // 0x80800104: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800108: mflo        $t5
    ctx->r13 = lo;
    // 0x8080010C: addu        $t7, $s0, $t5
    ctx->r15 = ADD32(ctx->r16, ctx->r13);
    // 0x80800110: sw          $s2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r18;
    // 0x80800114: lw          $t6, 0x60($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X60);
    // 0x80800118: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8080011C: sw          $t8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r24;
L_80800120:
    // 0x80800120: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800124: sltu        $at, $s1, $s6
    ctx->r1 = ctx->r17 < ctx->r22 ? 1 : 0;
    // 0x80800128: bnel        $at, $zero, L_808000B0
    if (ctx->r1 != 0) {
        // 0x8080012C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_808000B0;
    }
    goto skip_0;
    // 0x8080012C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
L_80800130:
    // 0x80800130: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1264, 0X10C0) << 16);
    // 0x80800134: lwc1        $f6, 0x10C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1264, 0X10C0));
    // 0x80800138: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    // 0x8080013C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800140: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80800144: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80800148: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8080014C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80800150: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800154: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800158: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8080015C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800160: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800164: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800168: jr          $ra
    // 0x8080016C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8080016C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void _idflash_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D38: syscall     737
    recomp_syscall_handler(rdram, ctx, 0x80088D38);
    return;
    // 0x80088D3C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800F1CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1CF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F1CF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1CF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800F1CFC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F1D00: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1D04: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F1D08: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F1D0C: nop

    // 0x800F1D10: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F1D14: jal         0x8002DCA0
    // 0x800F1D18: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F1D18: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800F1D1C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800F1D20: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800F1D24: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F1D28: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F1D2C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F1D30: nop

    // 0x800F1D34: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800F1D38: jal         0x8002DCA0
    // 0x800F1D3C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800F1D3C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x800F1D40: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F1D44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F1D48: lwc1        $f18, 0x5ED4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5ED4);
    // 0x800F1D4C: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800F1D50: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800F1D54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800F1D58: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800F1D5C: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x800F1D60: bc1fl       L_800F1DB8
    if (!c1cs) {
        // 0x800F1D64: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800F1DB8;
    }
    goto skip_0;
    // 0x800F1D64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x800F1D68: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1D6C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F1D70: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F1D74: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F1D78: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800F1D7C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x800F1D80: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800F1D84: sub.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800F1D88: jal         0x800F2100
    // 0x800F1D8C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x800F1D8C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x800F1D90: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F1D94: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F1D98: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800F1D9C: nop

    // 0x800F1DA0: bc1f        L_800F1DAC
    if (!c1cs) {
        // 0x800F1DA4: nop
    
            goto L_800F1DAC;
    }
    // 0x800F1DA4: nop

    // 0x800F1DA8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_800F1DAC:
    // 0x800F1DAC: b           L_800F1DBC
    // 0x800F1DB0: div.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
        goto L_800F1DBC;
    // 0x800F1DB0: div.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800F1DB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800F1DB8:
    // 0x800F1DB8: nop

L_800F1DBC:
    // 0x800F1DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1DC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F1DC4: jr          $ra
    // 0x800F1DC8: nop

    return;
    // 0x800F1DC8: nop

;}
