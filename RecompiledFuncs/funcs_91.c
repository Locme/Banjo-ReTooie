#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800C3648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3648: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C364C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C3650: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3654: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C365C: beq         $t6, $zero, L_800C367C
    if (ctx->r14 == 0) {
        // 0x800C3660: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800C367C;
    }
    // 0x800C3660: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C3664: jal         0x800C1414
    // 0x800C3668: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3668: nop

    after_0:
    // 0x800C366C: jal         0x800EA05C
    // 0x800C3670: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x800C3670: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800C3674: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3678: sh          $v0, 0x5E($t7)
    MEM_H(0X5E, ctx->r15) = ctx->r2;
L_800C367C:
    // 0x800C367C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3680: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3684: jr          $ra
    // 0x800C3688: nop

    return;
    // 0x800C3688: nop

;}
RECOMP_FUNC void func_808006C0_chfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C8: jal         0x80089B78
    // 0x808006CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _sufreezy_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808006CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006D0: jal         0x800FFAB0
    // 0x808006D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x808006D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808006D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006E0: jr          $ra
    // 0x808006E4: nop

    return;
    // 0x808006E4: nop

    // 0x808006E8: nop

    // 0x808006EC: nop

;}
RECOMP_FUNC void chfactorymagnet_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EB0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2284, 0X2A04) << 16);
    // 0x80801EB4: jr          $ra
    // 0x80801EB8: addiu       $v0, $v0, 0x2A04
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2284, 0X2A04));
    return;
    // 0x80801EB8: addiu       $v0, $v0, 0x2A04
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2284, 0X2A04));
;}
RECOMP_FUNC void func_80800614_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800614: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800618: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080061C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800620: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800624: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800628: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8080062C: jal         0x800B53A4
    // 0x80800630: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800630: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800634: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1020, 0X1580) << 16);
    // 0x80800638: addiu       $t6, $t6, 0x1580
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1020, 0X1580));
    // 0x8080063C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800640: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800648: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080064C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800650: jal         0x800BABB8
    // 0x80800654: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800654: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80800658: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8080065C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800660: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800664: beq         $v1, $zero, L_80800678
    if (ctx->r3 == 0) {
        // 0x80800668: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_80800678;
    }
    // 0x80800668: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8080066C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80800670: jal         0x800BABB8
    // 0x80800674: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800674: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_2:
L_80800678:
    // 0x80800678: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080067C: jal         0x800BA22C
    // 0x80800680: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800680: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80800684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800688: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080068C: jr          $ra
    // 0x80800690: nop

    return;
    // 0x80800690: nop

;}
RECOMP_FUNC void func_80100670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100678: jal         0x80100610
    // 0x8010067C: nop

    func_80100610(rdram, ctx);
        goto after_0;
    // 0x8010067C: nop

    after_0:
    // 0x80100680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100688: jr          $ra
    // 0x8010068C: nop

    return;
    // 0x8010068C: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808020AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808020B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808020B4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808020B8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808020BC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808020C0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x808020C4: lbu         $t1, 0x77($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X77);
    // 0x808020C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808020CC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x808020D0: blezl       $t1, L_80802170
    if (SIGNED(ctx->r9) <= 0) {
        // 0x808020D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80802170;
    }
    goto skip_0;
    // 0x808020D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808020D8: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
L_808020DC:
    // 0x808020DC: lw          $t7, 0x4C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4C);
    // 0x808020E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808020E4: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808020E8: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x808020EC: bgezl       $t9, L_80802164
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808020F0: addiu       $t0, $t0, 0x58
        ctx->r8 = ADD32(ctx->r8, 0X58);
            goto L_80802164;
    }
    goto skip_1;
    // 0x808020F0: addiu       $t0, $t0, 0x58
    ctx->r8 = ADD32(ctx->r8, 0X58);
    skip_1:
    // 0x808020F4: lhu         $a0, 0x40($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X40);
    // 0x808020F8: jal         0x800D674C
    // 0x808020FC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x808020FC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x80802100: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80802104: jal         0x800B2720
    // 0x80802108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2720(rdram, ctx);
        goto after_1;
    // 0x80802108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080210C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80802110: jal         0x800B2840
    // 0x80802114: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800B2840(rdram, ctx);
        goto after_2;
    // 0x80802114: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x80802118: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8080211C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80802120: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80802124: lw          $t3, 0x68($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X68);
    // 0x80802128: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8080212C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80802130: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80802134: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80802138: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080213C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802140: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80802144: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80802148: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8080214C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80802150: jal         0x800AD2C8
    // 0x80802154: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800AD2C8(rdram, ctx);
        goto after_3;
    // 0x80802154: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80802158: b           L_80802174
    // 0x8080215C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80802174;
    // 0x8080215C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802160: addiu       $t0, $t0, 0x58
    ctx->r8 = ADD32(ctx->r8, 0X58);
L_80802164:
    // 0x80802164: bne         $at, $zero, L_808020DC
    if (ctx->r1 != 0) {
        // 0x80802168: addiu       $v0, $v0, 0x58
        ctx->r2 = ADD32(ctx->r2, 0X58);
            goto L_808020DC;
    }
    // 0x80802168: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x8080216C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802170:
    // 0x80802170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802174:
    // 0x80802174: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802178: jr          $ra
    // 0x8080217C: nop

    return;
    // 0x8080217C: nop

;}
RECOMP_FUNC void func_80800A04_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A0C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800A10: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800A14: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800A18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800A1C: jal         0x80800C0C
    // 0x80800A20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80800C0C_chcheato(rdram, ctx);
        goto after_0;
    // 0x80800A20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800A24: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800A28: blez        $v0, L_80800A98
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800A2C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800A98;
    }
    // 0x80800A2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800A30:
    // 0x80800A30: addiu       $s1, $s0, 0x1
    ctx->r17 = ADD32(ctx->r16, 0X1);
    // 0x80800A34: jal         0x800D3E14
    // 0x80800A38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D3E14(rdram, ctx);
        goto after_1;
    // 0x80800A38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800A3C: beq         $v0, $zero, L_80800A58
    if (ctx->r2 == 0) {
        // 0x80800A40: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800A58;
    }
    // 0x80800A40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A48: jal         0x80087D40
    // 0x80800A4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_21(rdram, ctx);
        goto after_2;
    // 0x80800A4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800A50: b           L_80800A64
    // 0x80800A54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_80800A64;
    // 0x80800A54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800A58:
    // 0x80800A58: jal         0x80087D50
    // 0x80800A5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_23(rdram, ctx);
        goto after_3;
    // 0x80800A5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800A60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800A64:
    // 0x80800A64: jal         0x808008B8
    // 0x80800A68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808008B8_chcheato(rdram, ctx);
        goto after_4;
    // 0x80800A68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800A6C: jal         0x800D3FC0
    // 0x80800A70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D3FC0(rdram, ctx);
        goto after_5;
    // 0x80800A70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80800A74: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80800A78: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80800A7C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80800A80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A84: jal         0x80087D90
    // 0x80800A88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_6;
    // 0x80800A88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80800A8C: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80800A90: bne         $at, $zero, L_80800A30
    if (ctx->r1 != 0) {
        // 0x80800A94: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80800A30;
    }
    // 0x80800A94: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80800A98:
    // 0x80800A98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800A9C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800AA0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800AA4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AA8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800AAC: jr          $ra
    // 0x80800AB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800AB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800F63E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F63E0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F63E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F63E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F63EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F63F0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F63F4: jal         0x8008F854
    // 0x800F63F8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008F854(rdram, ctx);
        goto after_0;
    // 0x800F63F8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F63FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6404: jr          $ra
    // 0x800F6408: nop

    return;
    // 0x800F6408: nop

;}
RECOMP_FUNC void chcredits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080020C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800210: addiu       $v0, $v0, 0x7610
    ctx->r2 = ADD32(ctx->r2, 0X7610);
    // 0x80800214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800218: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8080021C: jal         0x808000E8
    // 0x80800220: sb          $a0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r4;
    func_808000E8_chcredits(rdram, ctx);
        goto after_0;
    // 0x80800220: sb          $a0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r4;
    after_0:
    // 0x80800224: jal         0x800DA544
    // 0x80800228: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800228: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    after_1:
    // 0x8080022C: jal         0x800887A8
    // 0x80800230: nop

    _glcutDll_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800230: nop

    after_2:
    // 0x80800234: jal         0x80800000
    // 0x80800238: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_80800000_chcredits(rdram, ctx);
        goto after_3;
    // 0x80800238: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_3:
    // 0x8080023C: jal         0x800887E0
    // 0x80800240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _glcutDll_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800244: jal         0x80088858
    // 0x80800248: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    _glcutDll_entrypoint_22(rdram, ctx);
        goto after_5;
    // 0x80800248: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_5:
    // 0x8080024C: jal         0x80088828
    // 0x80800250: nop

    _glcutDll_entrypoint_16(rdram, ctx);
        goto after_6;
    // 0x80800250: nop

    after_6:
    // 0x80800254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void _bsdrone_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FF8: syscall     38
    recomp_syscall_handler(rdram, ctx, 0x80082FF8);
    return;
    // 0x80082FFC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _indrv_fx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F90: syscall     752
    recomp_syscall_handler(rdram, ctx, 0x80088F90);
    return;
    // 0x80088F94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bssplitup_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B08: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083B08);
    return;
    // 0x80083B0C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80801568_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801568: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080156C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801570: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801574: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801578: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080157C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80801580: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x80801584: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080158C:
    // 0x8080158C: jal         0x80100094
    // 0x80801590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801594: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801598: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x8080159C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808015A0: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808015A4: beq         $t6, $s2, L_808015DC
    if (ctx->r14 == ctx->r18) {
        // 0x808015A8: nop
    
            goto L_808015DC;
    }
    // 0x808015A8: nop

    // 0x808015AC: bnel        $t6, $at, L_808015E8
    if (ctx->r14 != ctx->r1) {
        // 0x808015B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015E8;
    }
    goto skip_0;
    // 0x808015B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808015B4: jal         0x800F54E4
    // 0x808015B8: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808015B8: nop

    after_1:
    // 0x808015BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808015C0: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x808015C4: jal         0x800F7C0C
    // 0x808015C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F7C0C(rdram, ctx);
        goto after_2;
    // 0x808015C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x808015CC: jal         0x80801534
    // 0x808015D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801534_chflysaucer(rdram, ctx);
        goto after_3;
    // 0x808015D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808015D4: b           L_808015E8
    // 0x808015D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808015E8;
    // 0x808015D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808015DC:
    // 0x808015DC: jal         0x808004B0
    // 0x808015E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B0_chflysaucer(rdram, ctx);
        goto after_4;
    // 0x808015E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808015E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808015E8:
    // 0x808015E8: jal         0x80102424
    // 0x808015EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x808015EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x808015F0: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808015F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808015F8: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x808015FC: beql        $t7, $at, L_80801634
    if (ctx->r15 == ctx->r1) {
        // 0x80801600: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801634;
    }
    goto skip_1;
    // 0x80801600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80801604: beq         $t7, $s2, L_80801674
    if (ctx->r15 == ctx->r18) {
        // 0x80801608: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80801674;
    }
    // 0x80801608: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080160C: beq         $t7, $at, L_80801724
    if (ctx->r15 == ctx->r1) {
        // 0x80801610: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_80801724;
    }
    // 0x80801610: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80801614: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80801618: bnel        $t7, $at, L_808017BC
    if (ctx->r15 != ctx->r1) {
        // 0x8080161C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808017BC;
    }
    goto skip_2;
    // 0x8080161C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80801620: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80801624: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80801628: b           L_808017B8
    // 0x8080162C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
        goto L_808017B8;
    // 0x8080162C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80801630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801634:
    // 0x80801634: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
    // 0x80801638: addiu       $a2, $zero, 0x4020
    ctx->r6 = ADD32(0, 0X4020);
    // 0x8080163C: jal         0x80800424
    // 0x80801640: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800424_chflysaucer(rdram, ctx);
        goto after_6;
    // 0x80801640: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80801644: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3F64) << 16);
    // 0x80801648: lwc1        $f4, 0x3F64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3F64));
    // 0x8080164C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80801650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801658: jal         0x808012A4
    // 0x8080165C: swc1        $f4, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f4.u32l;
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_7;
    // 0x8080165C: swc1        $f4, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f4.u32l;
    after_7:
    // 0x80801660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801664: jal         0x808009DC
    // 0x80801668: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808009DC_chflysaucer(rdram, ctx);
        goto after_8;
    // 0x80801668: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x8080166C: b           L_808017BC
    // 0x80801670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808017BC;
    // 0x80801670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801674:
    // 0x80801674: jal         0x800D395C
    // 0x80801678: nop

    func_800D395C(rdram, ctx);
        goto after_9;
    // 0x80801678: nop

    after_9:
    // 0x8080167C: bne         $v0, $zero, L_808016E8
    if (ctx->r2 != 0) {
        // 0x80801680: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_808016E8;
    }
    // 0x80801680: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80801684: jal         0x800D0A9C
    // 0x80801688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_10;
    // 0x80801688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8080168C: beq         $v0, $zero, L_808016A0
    if (ctx->r2 == 0) {
        // 0x80801690: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_808016A0;
    }
    // 0x80801690: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80801694: jal         0x800D0A9C
    // 0x80801698: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800D0A9C(rdram, ctx);
        goto after_11;
    // 0x80801698: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_11:
    // 0x8080169C: bne         $v0, $zero, L_808016E8
    if (ctx->r2 != 0) {
        // 0x808016A0: addiu       $a0, $zero, 0x417
        ctx->r4 = ADD32(0, 0X417);
            goto L_808016E8;
    }
L_808016A0:
    // 0x808016A0: addiu       $a0, $zero, 0x417
    ctx->r4 = ADD32(0, 0X417);
    // 0x808016A4: jal         0x800DA9E4
    // 0x808016A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_12;
    // 0x808016A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808016AC: bne         $v0, $zero, L_808016D4
    if (ctx->r2 != 0) {
        // 0x808016B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808016D4;
    }
    // 0x808016B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016B8: addiu       $a1, $zero, 0x10C5
    ctx->r5 = ADD32(0, 0X10C5);
    // 0x808016BC: jal         0x8080105C
    // 0x808016C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_13;
    // 0x808016C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x808016C4: jal         0x80088178
    // 0x808016C8: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_14;
    // 0x808016C8: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    after_14:
    // 0x808016CC: b           L_808017BC
    // 0x808016D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808017BC;
    // 0x808016D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808016D4:
    // 0x808016D4: addiu       $a1, $zero, 0x1102
    ctx->r5 = ADD32(0, 0X1102);
    // 0x808016D8: jal         0x8080105C
    // 0x808016DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_15;
    // 0x808016DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x808016E0: b           L_808017BC
    // 0x808016E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808017BC;
    // 0x808016E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808016E8:
    // 0x808016E8: addiu       $a0, $zero, 0x418
    ctx->r4 = ADD32(0, 0X418);
    // 0x808016EC: jal         0x800DA9E4
    // 0x808016F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_16;
    // 0x808016F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808016F4: bne         $v0, $zero, L_80801714
    if (ctx->r2 != 0) {
        // 0x808016F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801714;
    }
    // 0x808016F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801700: addiu       $a1, $zero, 0x10E1
    ctx->r5 = ADD32(0, 0X10E1);
    // 0x80801704: jal         0x8080105C
    // 0x80801708: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_17;
    // 0x80801708: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x8080170C: b           L_808017BC
    // 0x80801710: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808017BC;
    // 0x80801710: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801714:
    // 0x80801714: jal         0x808004F0
    // 0x80801718: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    func_808004F0_chflysaucer(rdram, ctx);
        goto after_18;
    // 0x80801718: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    after_18:
    // 0x8080171C: b           L_8080158C
    // 0x80801720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080158C;
    // 0x80801720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801724:
    // 0x80801724: sh          $zero, 0x2A($t2)
    MEM_H(0X2A, ctx->r10) = 0;
    // 0x80801728: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3F68) << 16);
    // 0x8080172C: lwc1        $f6, 0x3F68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3F68));
    // 0x80801730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801738: jal         0x8008A4B0
    // 0x8080173C: swc1        $f6, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f6.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x8080173C: swc1        $f6, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f6.u32l;
    after_19:
    // 0x80801740: jal         0x8008A490
    // 0x80801744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x80801744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801748: jal         0x800FDC28
    // 0x8080174C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_800FDC28(rdram, ctx);
        goto after_21;
    // 0x8080174C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_21:
    // 0x80801750: jal         0x80800728
    // 0x80801754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800728_chflysaucer(rdram, ctx);
        goto after_22;
    // 0x80801754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80801758: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8080175C: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80801760: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80801764: jal         0x808007C4
    // 0x80801768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007C4_chflysaucer(rdram, ctx);
        goto after_23;
    // 0x80801768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x8080176C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801770: jal         0x808012A4
    // 0x80801774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_24;
    // 0x80801774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80801778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080177C: jal         0x808009DC
    // 0x80801780: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808009DC_chflysaucer(rdram, ctx);
        goto after_25;
    // 0x80801780: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80801784: jal         0x80800C3C
    // 0x80801788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C3C_chflysaucer(rdram, ctx);
        goto after_26;
    // 0x80801788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8080178C: jal         0x800F54E4
    // 0x80801790: nop

    func_800F54E4(rdram, ctx);
        goto after_27;
    // 0x80801790: nop

    after_27:
    // 0x80801794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801798: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x8080179C: jal         0x800F7C0C
    // 0x808017A0: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    func_800F7C0C(rdram, ctx);
        goto after_28;
    // 0x808017A0: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_28:
    // 0x808017A4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808017A8: jal         0x80104268
    // 0x808017AC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    func_80104268(rdram, ctx);
        goto after_29;
    // 0x808017AC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    after_29:
    // 0x808017B0: jal         0x808013B4
    // 0x808017B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808013B4_chflysaucer(rdram, ctx);
        goto after_30;
    // 0x808017B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
L_808017B8:
    // 0x808017B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808017BC:
    // 0x808017BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808017C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808017C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808017C8: jr          $ra
    // 0x808017CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808017CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chklungodoors_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863D0: syscall     319
    recomp_syscall_handler(rdram, ctx, 0x800863D0);
    return;
    // 0x800863D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void capod_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080051C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800520: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800524: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800528: jal         0x8008FFE8
    // 0x8080052C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x8080052C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800530: beq         $v0, $zero, L_80800550
    if (ctx->r2 == 0) {
        // 0x80800534: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800550;
    }
    // 0x80800534: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800538: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080053C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800540: jal         0x800895C0
    // 0x80800544: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    _ncpod_entrypoint_32(rdram, ctx);
        goto after_1;
    // 0x80800544: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800548: b           L_80800558
    // 0x8080054C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800558;
    // 0x8080054C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800550:
    // 0x80800550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800558:
    // 0x80800558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080055C: jr          $ra
    // 0x80800560: nop

    return;
    // 0x80800560: nop

;}
RECOMP_FUNC void _chterryegg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086178: syscall     283
    recomp_syscall_handler(rdram, ctx, 0x80086178);
    return;
    // 0x8008617C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsjump_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083240: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083240);
    return;
    // 0x80083244: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _scinfobar_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A628: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A628);
    return;
    // 0x8008A62C: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_80022060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022060: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80022064: lw          $t6, -0x15C0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X15C0);
    // 0x80022068: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8002206C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80022070: sw          $a0, -0x15C0($at)
    MEM_W(-0X15C0, ctx->r1) = ctx->r4;
    // 0x80022074: jr          $ra
    // 0x80022078: nop

    return;
    // 0x80022078: nop

;}
RECOMP_FUNC void func_808009F0_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009F8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808009FC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800A00: jal         0x8008A1E8
    // 0x80800A04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800A04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A0C: beq         $v0, $zero, L_80800A30
    if (ctx->r2 == 0) {
        // 0x80800A10: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800A30;
    }
    // 0x80800A10: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800A14: addiu       $at, $zero, 0x1208
    ctx->r1 = ADD32(0, 0X1208);
    // 0x80800A18: beq         $v0, $at, L_80800A30
    if (ctx->r2 == ctx->r1) {
        // 0x80800A1C: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80800A30;
    }
    // 0x80800A1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800A24: jal         0x80800C08
    // 0x80800A28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800C08_chbottlesfamily(rdram, ctx);
        goto after_1;
    // 0x80800A28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800A2C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80800A30:
    // 0x80800A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A38: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x80800A3C: jr          $ra
    // 0x80800A40: nop

    return;
    // 0x80800A40: nop

;}
RECOMP_FUNC void bskazflamethrower_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800010: jal         0x8009BFCC
    // 0x80800014: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_8009BFCC(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800018: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8080001C: jal         0x8009C984
    // 0x80800020: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x80800020: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800024: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800028: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080002C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800030: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800034: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800038: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080003C: jal         0x800EEC30
    // 0x80800040: nop

    func_800EEC30(rdram, ctx);
        goto after_2;
    // 0x80800040: nop

    after_2:
    // 0x80800044: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800048: jal         0x8009C128
    // 0x8080004C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x8080004C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800050: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800054: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800058: jal         0x800EFA98
    // 0x8080005C: lui         $a2, 0x4188
    ctx->r6 = S32(0X4188 << 16);
    func_800EFA98(rdram, ctx);
        goto after_4;
    // 0x8080005C: lui         $a2, 0x4188
    ctx->r6 = S32(0X4188 << 16);
    after_4:
    // 0x80800060: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800064: jal         0x800EF04C
    // 0x80800068: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800068: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x8080006C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800070: lui         $at, 0x4264
    ctx->r1 = S32(0X4264 << 16);
    // 0x80800074: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800078: lwc1        $f8, 0x4($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8080007C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800080: swc1        $f16, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f16.u32l;
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800088: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void _chjujubagfx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C80: syscall     439
    recomp_syscall_handler(rdram, ctx, 0x80086C80);
    return;
    // 0x80086C84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801B0C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801B18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801B1C: jal         0x800F424C
    // 0x80801B20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F424C(rdram, ctx);
        goto after_0;
    // 0x80801B20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801B24: beq         $v0, $zero, L_80801B48
    if (ctx->r2 == 0) {
        // 0x80801B28: lw          $t8, 0x1C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1C);
            goto L_80801B48;
    }
    // 0x80801B28: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B2C: jal         0x80097B28
    // 0x80801B30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bainput_func_80097B28(rdram, ctx);
        goto after_1;
    // 0x80801B30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801B34: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B38: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x80801B3C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80801B40: b           L_80801B54
    // 0x80801B44: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
        goto L_80801B54;
    // 0x80801B44: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
L_80801B48:
    // 0x80801B48: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80801B4C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80801B50: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_80801B54:
    // 0x80801B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B5C: jr          $ra
    // 0x80801B60: nop

    return;
    // 0x80801B60: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808004D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808004D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004D8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808004DC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808004E0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808004E4: blez        $a2, L_80800504
    if (SIGNED(ctx->r6) <= 0) {
        // 0x808004E8: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80800504;
    }
    // 0x808004E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_808004EC:
    // 0x808004EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004F0: jal         0x808004A8
    // 0x808004F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gsmaker_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808004F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x808004F8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808004FC: bgtz        $s0, L_808004EC
    if (SIGNED(ctx->r16) > 0) {
        // 0x80800500: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_808004EC;
    }
    // 0x80800500: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_80800504:
    // 0x80800504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800508: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080050C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800510: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800514: jr          $ra
    // 0x80800518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chexploder_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080178C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801790: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801794: jal         0x80100094
    // 0x80801798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080179C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808017A0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808017A4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x808017A8: nop

    // 0x808017AC: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x808017B0: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808017B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808017B8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x808017BC: nop

    // 0x808017C0: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x808017C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808017C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808017CC: jr          $ra
    // 0x808017D0: nop

    return;
    // 0x808017D0: nop

;}
RECOMP_FUNC void idflasha_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
    // 0x80800004: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80800008: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800010: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80800014: beq         $at, $zero, L_80800030
    if (ctx->r1 == 0) {
        // 0x80800018: lh          $v0, 0x0($t6)
        ctx->r2 = MEM_H(ctx->r14, 0X0);
            goto L_80800030;
    }
    // 0x80800018: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
L_8080001C:
    // 0x8080001C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80800020: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80800024: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800028: bne         $at, $zero, L_8080001C
    if (ctx->r1 != 0) {
        // 0x8080002C: sb          $v0, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r2;
            goto L_8080001C;
    }
    // 0x8080002C: sb          $v0, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r2;
L_80800030:
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808021C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808021C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808021CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808021D0: jal         0x80084F80
    // 0x808021D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    _bareact_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808021D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808021D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808021DC: bnel        $v0, $at, L_808021F0
    if (ctx->r2 != ctx->r1) {
        // 0x808021E0: lui         $a1, 0x3E99
        ctx->r5 = S32(0X3E99 << 16);
            goto L_808021F0;
    }
    goto skip_0;
    // 0x808021E0: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    skip_0:
    // 0x808021E4: jal         0x80800438
    // 0x808021E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800438_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x808021E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808021EC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
L_808021F0:
    // 0x808021F0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808021F4: jal         0x8008CB10
    // 0x808021F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x808021F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808021FC: beq         $v0, $zero, L_8080220C
    if (ctx->r2 == 0) {
        // 0x80802200: nop
    
            goto L_8080220C;
    }
    // 0x80802200: nop

    // 0x80802204: jal         0x800951B4
    // 0x80802208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_3;
    // 0x80802208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8080220C:
    // 0x8080220C: jal         0x8008E260
    // 0x80802210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_4;
    // 0x80802210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802214: beq         $v0, $zero, L_80802220
    if (ctx->r2 == 0) {
        // 0x80802218: addiu       $t6, $zero, 0x3D
        ctx->r14 = ADD32(0, 0X3D);
            goto L_80802220;
    }
    // 0x80802218: addiu       $t6, $zero, 0x3D
    ctx->r14 = ADD32(0, 0X3D);
    // 0x8080221C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80802220:
    // 0x80802220: jal         0x8008E078
    // 0x80802224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_5;
    // 0x80802224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802228: beq         $v0, $zero, L_80802244
    if (ctx->r2 == 0) {
        // 0x8080222C: nop
    
            goto L_80802244;
    }
    // 0x8080222C: nop

    // 0x80802230: jal         0x8008CAEC
    // 0x80802234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_6;
    // 0x80802234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802238: beq         $v0, $zero, L_80802244
    if (ctx->r2 == 0) {
        // 0x8080223C: addiu       $t7, $zero, 0x15
        ctx->r15 = ADD32(0, 0X15);
            goto L_80802244;
    }
    // 0x8080223C: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x80802240: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80802244:
    // 0x80802244: jal         0x8008CABC
    // 0x80802248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_7;
    // 0x80802248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080224C: jal         0x8008B324
    // 0x80802250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_8;
    // 0x80802250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80802254: beql        $v0, $zero, L_80802274
    if (ctx->r2 == 0) {
        // 0x80802258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802274;
    }
    goto skip_1;
    // 0x80802258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080225C: jal         0x8008E35C
    // 0x80802260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_9;
    // 0x80802260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80802264: beq         $v0, $zero, L_80802270
    if (ctx->r2 == 0) {
        // 0x80802268: addiu       $t8, $zero, 0x2D
        ctx->r24 = ADD32(0, 0X2D);
            goto L_80802270;
    }
    // 0x80802268: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x8080226C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80802270:
    // 0x80802270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802274:
    // 0x80802274: jal         0x8009E5C8
    // 0x80802278: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x80802278: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x8080227C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802280: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802284: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802288: jr          $ra
    // 0x8080228C: nop

    return;
    // 0x8080228C: nop

;}
RECOMP_FUNC void func_80800190_chghostdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800198: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080019C: jal         0x80085808
    // 0x808001A0: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808001A0: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    after_0:
    // 0x808001A4: jal         0x80085818
    // 0x808001A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808001A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B4: jr          $ra
    // 0x808001B8: nop

    return;
    // 0x808001B8: nop

;}
RECOMP_FUNC void func_80801EA0_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801EA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801EA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801EAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801EB0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80801EB4: jal         0x8008CB10
    // 0x80801EB8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80801EB8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x80801EBC: beq         $v0, $zero, L_80801ECC
    if (ctx->r2 == 0) {
        // 0x80801EC0: nop
    
            goto L_80801ECC;
    }
    // 0x80801EC0: nop

    // 0x80801EC4: jal         0x800951B4
    // 0x80801EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_1;
    // 0x80801EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80801ECC:
    // 0x80801ECC: jal         0x800845C8
    // 0x80801ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80801ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801ED4: beq         $v0, $zero, L_80801EE4
    if (ctx->r2 == 0) {
        // 0x80801ED8: nop
    
            goto L_80801EE4;
    }
    // 0x80801ED8: nop

    // 0x80801EDC: jal         0x80800164
    // 0x80801EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bstnt(rdram, ctx);
        goto after_3;
    // 0x80801EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80801EE4:
    // 0x80801EE4: jal         0x80084600
    // 0x80801EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80801EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801EEC: beq         $v0, $zero, L_80801EF8
    if (ctx->r2 == 0) {
        // 0x80801EF0: addiu       $t6, $zero, 0x10C
        ctx->r14 = ADD32(0, 0X10C);
            goto L_80801EF8;
    }
    // 0x80801EF0: addiu       $t6, $zero, 0x10C
    ctx->r14 = ADD32(0, 0X10C);
    // 0x80801EF4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80801EF8:
    // 0x80801EF8: jal         0x80800F94
    // 0x80801EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstnt_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80801EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F04: jal         0x8009E5C8
    // 0x80801F08: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x80801F08: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80801F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801F10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801F14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801F18: jr          $ra
    // 0x80801F1C: nop

    return;
    // 0x80801F1C: nop

;}
RECOMP_FUNC void chstoneballcontrol_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036A8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1608, 0X5314) << 16);
    // 0x808036AC: jr          $ra
    // 0x808036B0: addiu       $v0, $v0, 0x5314
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1608, 0X5314));
    return;
    // 0x808036B0: addiu       $v0, $v0, 0x5314
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1608, 0X5314));
;}
RECOMP_FUNC void func_80800148_chshockjump(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080014C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800150: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800154: jal         0x80089C90
    // 0x80800158: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800158: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080015C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800164: addiu       $at, $zero, 0x210
    ctx->r1 = ADD32(0, 0X210);
    // 0x80800168: lw          $t7, 0x6C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X6C);
    // 0x8080016C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80800170: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x80800174: srl         $t9, $t8, 20
    ctx->r25 = S32(U32(ctx->r24) >> 20);
    // 0x80800178: bne         $t9, $at, L_80800188
    if (ctx->r25 != ctx->r1) {
        // 0x8080017C: nop
    
            goto L_80800188;
    }
    // 0x8080017C: nop

    // 0x80800180: b           L_80800188
    // 0x80800184: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
        goto L_80800188;
    // 0x80800184: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
L_80800188:
    // 0x80800188: jal         0x800C6E38
    // 0x8080018C: nop

    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x8080018C: nop

    after_1:
    // 0x80800190: beql        $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x80800194: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_808001E0;
    }
    goto skip_0;
    // 0x80800194: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800198: jal         0x800F54E4
    // 0x8080019C: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080019C: nop

    after_2:
    // 0x808001A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001A4: jal         0x800F64A4
    // 0x808001A8: addiu       $a1, $zero, 0x401
    ctx->r5 = ADD32(0, 0X401);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x808001A8: addiu       $a1, $zero, 0x401
    ctx->r5 = ADD32(0, 0X401);
    after_3:
    // 0x808001AC: beq         $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001B0: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_808001DC;
    }
    // 0x808001B0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x808001B4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x808001B8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808001BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001C0: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x808001C4: jal         0x800F15F8
    // 0x808001C8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F15F8(rdram, ctx);
        goto after_4;
    // 0x808001C8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_4:
    // 0x808001CC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808001D0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808001D4: b           L_80800204
    // 0x808001D8: nop

        goto L_80800204;
    // 0x808001D8: nop

L_808001DC:
    // 0x808001DC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
L_808001E0:
    // 0x808001E0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808001E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001E8: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x808001EC: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x808001F0: jal         0x800F15F8
    // 0x808001F4: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_800F15F8(rdram, ctx);
        goto after_5;
    // 0x808001F4: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_5:
    // 0x808001F8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808001FC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800200: nop

L_80800204:
    // 0x80800204: jal         0x80089CD0
    // 0x80800208: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _subaddiefade_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800208: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x8080020C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800210: jal         0x80101870
    // 0x80800214: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101870(rdram, ctx);
        goto after_7;
    // 0x80800214: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080021C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void _bsjump_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083298: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083298);
    return;
    // 0x8008329C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800040_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080004C: jal         0x80100094
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800058: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080005C: jal         0x80089F70
    // 0x80800060: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800064: jal         0x80089F60
    // 0x80800068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void func_80116050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116050: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80116054: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80116058: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8011605C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80116060: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80116064: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    // 0x80116068: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8011606C: swc1        $f6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f6.u32l;
    // 0x80116070: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80116074: jr          $ra
    // 0x80116078: swc1        $f12, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f12.u32l;
    return;
    // 0x80116078: swc1        $f12, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bstimeout_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F18: syscall     98
    recomp_syscall_handler(rdram, ctx, 0x80083F18);
    return;
    // 0x80083F1C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chappearfx_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006F4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808006F8: jal         0x80800710
    // 0x808006FC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    chappearfx_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808006FC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800708: jr          $ra
    // 0x8080070C: nop

    return;
    // 0x8080070C: nop

;}
RECOMP_FUNC void func_80800868_chjigsawbitcont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800868: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1644, 0X994) << 16);
    // 0x8080086C: lwc1        $f4, 0x994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1644, 0X994));
    // 0x80800870: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1644, 0X998) << 16);
    // 0x80800874: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80800878: lwc1        $f6, 0x998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1644, 0X998));
    // 0x8080087C: lui         $at, 0x4452
    ctx->r1 = S32(0X4452 << 16);
    // 0x80800880: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800884: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x80800888: jr          $ra
    // 0x8080088C: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8080088C: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void fxtwinkle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80800020
    // 0x8080000C: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    fxtwinkle_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080000C: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
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
RECOMP_FUNC void func_80800150_chjadesnake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800154: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080015C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800160: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800164: jal         0x800D0B68
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_0;
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080016C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800170: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800174: jal         0x800D0A9C
    // 0x80800178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x80800178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080017C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800180: jal         0x8010D254
    // 0x80800184: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_8010D254(rdram, ctx);
        goto after_2;
    // 0x80800184: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x80800188: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080018C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800190: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800194: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80800198: beq         $at, $zero, L_8080065C
    if (ctx->r1 == 0) {
        // 0x8080019C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8080065C;
    }
    // 0x8080019C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808001A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1868, 0X8E0) << 16);
    // 0x808001A4: addu        $at, $at, $t8
    gpr jr_addend_808001AC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808001A8: lw          $t8, 0x8E0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1868, 0X8E0));
    // 0x808001AC: jr          $t8
    // 0x808001B0: nop

    switch (jr_addend_808001AC >> 2) {
        case 0: goto L_808001B4; break;
        case 1: goto L_808002E0; break;
        case 2: goto L_808003DC; break;
        case 3: goto L_808004BC; break;
        case 4: goto L_8080065C; break;
        case 5: goto L_808003B8; break;
        case 6: goto L_808005F0; break;
        case 7: goto L_8080060C; break;
        default: switch_error(__func__, 0x808001AC, 0x808008E0);
    }
    // 0x808001B0: nop

L_808001B4:
    // 0x808001B4: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x808001B8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x808001BC: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x808001C0: bgez        $t1, L_808001F0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808001C4: nop
    
            goto L_808001F0;
    }
    // 0x808001C4: nop

    // 0x808001C8: bne         $t2, $zero, L_808001F0
    if (ctx->r10 != 0) {
        // 0x808001CC: lw          $t3, 0x4C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X4C);
            goto L_808001F0;
    }
    // 0x808001CC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x808001D0: bne         $t3, $zero, L_808001F0
    if (ctx->r11 != 0) {
        // 0x808001D4: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_808001F0;
    }
    // 0x808001D4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x808001D8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001E0: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x808001E4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808001E8: jal         0x800D1000
    // 0x808001EC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800D1000(rdram, ctx);
        goto after_3;
    // 0x808001EC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
L_808001F0:
    // 0x808001F0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1868, 0X9C0) << 16);
    // 0x808001F4: addiu       $a1, $a1, 0x9C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1868, 0X9C0));
    // 0x808001F8: jal         0x80101E4C
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_4;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800200: beq         $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800204: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_80800234;
    }
    // 0x80800204: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80800208: beq         $t5, $zero, L_80800218
    if (ctx->r13 == 0) {
        // 0x8080020C: addiu       $a0, $zero, 0x5C7
        ctx->r4 = ADD32(0, 0X5C7);
            goto L_80800218;
    }
    // 0x8080020C: addiu       $a0, $zero, 0x5C7
    ctx->r4 = ADD32(0, 0X5C7);
    // 0x80800210: b           L_80800218
    // 0x80800214: addiu       $a0, $zero, 0x5C6
    ctx->r4 = ADD32(0, 0X5C6);
        goto L_80800218;
    // 0x80800214: addiu       $a0, $zero, 0x5C6
    ctx->r4 = ADD32(0, 0X5C6);
L_80800218:
    // 0x80800218: jal         0x800C4B7C
    // 0x8080021C: nop

    func_800C4B7C(rdram, ctx);
        goto after_5;
    // 0x8080021C: nop

    after_5:
    // 0x80800220: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1868, 0X964) << 16);
    // 0x80800224: addiu       $a2, $a2, 0x964
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1868, 0X964));
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: jal         0x80089D18
    // 0x80800230: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800230: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
L_80800234:
    // 0x80800234: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80800238: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8080023C: bnel        $t6, $zero, L_80800660
    if (ctx->r14 != 0) {
        // 0x80800240: lw          $t7, 0x6C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X6C);
            goto L_80800660;
    }
    goto skip_0;
    // 0x80800240: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x80800244: beql        $t7, $zero, L_80800660
    if (ctx->r15 == 0) {
        // 0x80800248: lw          $t7, 0x6C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X6C);
            goto L_80800660;
    }
    goto skip_1;
    // 0x80800248: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    skip_1:
    // 0x8080024C: jal         0x8080009C
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chjadesnake(rdram, ctx);
        goto after_7;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800254: beq         $v0, $zero, L_8080065C
    if (ctx->r2 == 0) {
        // 0x80800258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080065C;
    }
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1868, 0X910) << 16);
    // 0x80800260: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    // 0x80800264: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80800268: addiu       $a2, $a2, 0x910
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1868, 0X910));
    // 0x8080026C: jal         0x80089D18
    // 0x80800270: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800270: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_8:
    // 0x80800274: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800278: jal         0x80090734
    // 0x8080027C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80090734(rdram, ctx);
        goto after_9;
    // 0x8080027C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: jal         0x8010A85C
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_10;
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x80102424
    // 0x80800294: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800294: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80800298: addiu       $a0, $zero, 0x677
    ctx->r4 = ADD32(0, 0X677);
    // 0x8080029C: jal         0x800DA9E4
    // 0x808002A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_12;
    // 0x808002A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808002A4: bne         $v0, $zero, L_808002D0
    if (ctx->r2 != 0) {
        // 0x808002A8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808002D0;
    }
    // 0x808002A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002AC: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808002B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808002B8: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x808002BC: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x808002C0: jal         0x80085708
    // 0x808002C4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_13;
    // 0x808002C4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_13:
    // 0x808002C8: b           L_80800660
    // 0x808002CC: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
        goto L_80800660;
    // 0x808002CC: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_808002D0:
    // 0x808002D0: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x808002D4: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x808002D8: b           L_8080065C
    // 0x808002DC: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_8080065C;
    // 0x808002DC: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_808002E0:
    // 0x808002E0: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: beql        $t4, $zero, L_80800310
    if (ctx->r12 == 0) {
        // 0x808002EC: lui         $a1, 0x3F3A
        ctx->r5 = S32(0X3F3A << 16);
            goto L_80800310;
    }
    goto skip_2;
    // 0x808002EC: lui         $a1, 0x3F3A
    ctx->r5 = S32(0X3F3A << 16);
    skip_2:
    // 0x808002F0: jal         0x8010A85C
    // 0x808002F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A85C(rdram, ctx);
        goto after_14;
    // 0x808002F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002FC: jal         0x80102424
    // 0x80800300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x80800300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800304: jal         0x80090708
    // 0x80800308: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_16;
    // 0x80800308: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8080030C: lui         $a1, 0x3F3A
    ctx->r5 = S32(0X3F3A << 16);
L_80800310:
    // 0x80800310: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80800314: jal         0x80101E14
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_17;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080031C: beq         $v0, $zero, L_80800340
    if (ctx->r2 == 0) {
        // 0x80800320: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80800340;
    }
    // 0x80800320: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800324: jal         0x800D119C
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D119C(rdram, ctx);
        goto after_18;
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x8080032C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1868, 0X92C) << 16);
    // 0x80800330: addiu       $a2, $a2, 0x92C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1868, 0X92C));
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: jal         0x80089D18
    // 0x8080033C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x8080033C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_19:
L_80800340:
    // 0x80800340: jal         0x80101DDC
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_20;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800348: beql        $v0, $zero, L_80800660
    if (ctx->r2 == 0) {
        // 0x8080034C: lw          $t7, 0x6C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X6C);
            goto L_80800660;
    }
    goto skip_3;
    // 0x8080034C: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    skip_3:
    // 0x80800350: jal         0x800DA298
    // 0x80800354: addiu       $a0, $zero, 0x434
    ctx->r4 = ADD32(0, 0X434);
    func_800DA298(rdram, ctx);
        goto after_21;
    // 0x80800354: addiu       $a0, $zero, 0x434
    ctx->r4 = ADD32(0, 0X434);
    after_21:
    // 0x80800358: beq         $v0, $zero, L_8080037C
    if (ctx->r2 == 0) {
        // 0x8080035C: addiu       $a0, $zero, 0x434
        ctx->r4 = ADD32(0, 0X434);
            goto L_8080037C;
    }
    // 0x8080035C: addiu       $a0, $zero, 0x434
    ctx->r4 = ADD32(0, 0X434);
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x80102424
    // 0x80800368: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x80800368: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_22:
    // 0x8080036C: jal         0x80090708
    // 0x80800370: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_23;
    // 0x80800370: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x80800374: b           L_80800660
    // 0x80800378: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
        goto L_80800660;
    // 0x80800378: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_8080037C:
    // 0x8080037C: addiu       $t5, $s0, 0x4
    ctx->r13 = ADD32(ctx->r16, 0X4);
    // 0x80800380: jal         0x800DA544
    // 0x80800384: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    func_800DA544(rdram, ctx);
        goto after_24;
    // 0x80800384: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    after_24:
    // 0x80800388: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080038C: addiu       $t6, $zero, 0x46
    ctx->r14 = ADD32(0, 0X46);
    // 0x80800390: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800394: addiu       $a1, $zero, 0xF3C
    ctx->r5 = ADD32(0, 0XF3C);
    // 0x80800398: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080039C: jal         0x8008A208
    // 0x808003A0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_25;
    // 0x808003A0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_25:
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: jal         0x80102424
    // 0x808003AC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x808003AC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_26:
    // 0x808003B0: b           L_80800660
    // 0x808003B4: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
        goto L_80800660;
    // 0x808003B4: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_808003B8:
    // 0x808003B8: jal         0x80085710
    // 0x808003BC: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_27;
    // 0x808003BC: nop

    after_27:
    // 0x808003C0: jal         0x80090708
    // 0x808003C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_28;
    // 0x808003C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_28:
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: jal         0x80102424
    // 0x808003D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_29;
    // 0x808003D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_29:
    // 0x808003D4: b           L_80800660
    // 0x808003D8: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
        goto L_80800660;
    // 0x808003D8: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_808003DC:
    // 0x808003DC: jal         0x80101F24
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_30;
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808003E4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808003E8: jal         0x8010D254
    // 0x808003EC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_8010D254(rdram, ctx);
        goto after_31;
    // 0x808003EC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_31:
    // 0x808003F0: jal         0x800F54E4
    // 0x808003F4: nop

    func_800F54E4(rdram, ctx);
        goto after_32;
    // 0x808003F4: nop

    after_32:
    // 0x808003F8: jal         0x800F56AC
    // 0x808003FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F56AC(rdram, ctx);
        goto after_33;
    // 0x808003FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_33:
    // 0x80800400: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80800404: beq         $v0, $at, L_80800450
    if (ctx->r2 == ctx->r1) {
        // 0x80800408: lwc1        $f4, 0x3C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_80800450;
    }
    // 0x80800408: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080040C: lui         $at, 0x4491
    ctx->r1 = S32(0X4491 << 16);
    // 0x80800410: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080041C: nop

    // 0x80800420: bc1f        L_80800450
    if (!c1cs) {
        // 0x80800424: nop
    
            goto L_80800450;
    }
    // 0x80800424: nop

    // 0x80800428: jal         0x80102424
    // 0x8080042C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_34;
    // 0x8080042C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_34:
    // 0x80800430: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800438: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080043C: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800440: bgez        $t9, L_80800450
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800444: addiu       $a3, $zero, 0x10
        ctx->r7 = ADD32(0, 0X10);
            goto L_80800450;
    }
    // 0x80800444: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800448: jal         0x80085708
    // 0x8080044C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_35;
    // 0x8080044C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_35:
L_80800450:
    // 0x80800450: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1868, 0X900) << 16);
    // 0x80800454: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800458: lwc1        $f8, 0x900($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1868, 0X900));
    // 0x8080045C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1868, 0X904) << 16);
    // 0x80800460: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800464: nop

    // 0x80800468: bc1f        L_80800498
    if (!c1cs) {
        // 0x8080046C: nop
    
            goto L_80800498;
    }
    // 0x8080046C: nop

    // 0x80800470: lwc1        $f10, 0x904($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1868, 0X904));
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800478: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080047C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800480: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800484: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1868, 0X948) << 16);
    // 0x80800488: bc1f        L_80800498
    if (!c1cs) {
        // 0x8080048C: nop
    
            goto L_80800498;
    }
    // 0x8080048C: nop

    // 0x80800490: jal         0x80089D50
    // 0x80800494: addiu       $a3, $a3, 0x948
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1868, 0X948));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_36;
    // 0x80800494: addiu       $a3, $a3, 0x948
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1868, 0X948));
    after_36:
L_80800498:
    // 0x80800498: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1868, 0X958) << 16);
    // 0x8080049C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1868, 0X9DC) << 16);
    // 0x808004A0: addiu       $a3, $a3, 0x9DC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1868, 0X9DC));
    // 0x808004A4: addiu       $a2, $a2, 0x958
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1868, 0X958));
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: jal         0x80089D28
    // 0x808004B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_37;
    // 0x808004B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_37:
    // 0x808004B4: b           L_80800660
    // 0x808004B8: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
        goto L_80800660;
    // 0x808004B8: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_808004BC:
    // 0x808004BC: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
    // 0x808004C0: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x808004C4: jal         0x80101E14
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_38;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x808004CC: beq         $v0, $zero, L_8080052C
    if (ctx->r2 == 0) {
        // 0x808004D0: lw          $t0, 0x4C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X4C);
            goto L_8080052C;
    }
    // 0x808004D0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x808004D4: bne         $t0, $zero, L_8080052C
    if (ctx->r8 != 0) {
        // 0x808004D8: nop
    
            goto L_8080052C;
    }
    // 0x808004D8: nop

    // 0x808004DC: jal         0x800DA298
    // 0x808004E0: addiu       $a0, $zero, 0x435
    ctx->r4 = ADD32(0, 0X435);
    func_800DA298(rdram, ctx);
        goto after_39;
    // 0x808004E0: addiu       $a0, $zero, 0x435
    ctx->r4 = ADD32(0, 0X435);
    after_39:
    // 0x808004E4: beq         $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004E8: nop
    
            goto L_808004FC;
    }
    // 0x808004E8: nop

    // 0x808004EC: jal         0x80800048
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800048_chjadesnake(rdram, ctx);
        goto after_40;
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x808004F4: b           L_8080052C
    // 0x808004F8: nop

        goto L_8080052C;
    // 0x808004F8: nop

L_808004FC:
    // 0x808004FC: jal         0x800DA544
    // 0x80800500: addiu       $a0, $zero, 0x435
    ctx->r4 = ADD32(0, 0X435);
    func_800DA544(rdram, ctx);
        goto after_41;
    // 0x80800500: addiu       $a0, $zero, 0x435
    ctx->r4 = ADD32(0, 0X435);
    after_41:
    // 0x80800504: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800508: addiu       $t1, $zero, 0x46
    ctx->r9 = ADD32(0, 0X46);
    // 0x8080050C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800510: addiu       $a1, $zero, 0xF3D
    ctx->r5 = ADD32(0, 0XF3D);
    // 0x80800514: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800518: jal         0x8008A208
    // 0x8080051C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_42;
    // 0x8080051C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_42:
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: jal         0x80102424
    // 0x80800528: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_43;
    // 0x80800528: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_43:
L_8080052C:
    // 0x8080052C: jal         0x80101DDC
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_44;
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x80800534: beql        $v0, $zero, L_80800578
    if (ctx->r2 == 0) {
        // 0x80800538: lw          $t2, 0x50($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X50);
            goto L_80800578;
    }
    goto skip_4;
    // 0x80800538: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    skip_4:
    // 0x8080053C: jal         0x800DA298
    // 0x80800540: addiu       $a0, $zero, 0x435
    ctx->r4 = ADD32(0, 0X435);
    func_800DA298(rdram, ctx);
        goto after_45;
    // 0x80800540: addiu       $a0, $zero, 0x435
    ctx->r4 = ADD32(0, 0X435);
    after_45:
    // 0x80800544: bne         $v0, $zero, L_80800560
    if (ctx->r2 != 0) {
        // 0x80800548: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800560;
    }
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: jal         0x80102424
    // 0x80800554: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_46;
    // 0x80800554: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_46:
    // 0x80800558: b           L_80800578
    // 0x8080055C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
        goto L_80800578;
    // 0x8080055C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
L_80800560:
    // 0x80800560: jal         0x8010A85C
    // 0x80800564: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A85C(rdram, ctx);
        goto after_47;
    // 0x80800564: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_47:
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: jal         0x80102424
    // 0x80800570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_48;
    // 0x80800570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_48:
    // 0x80800574: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
L_80800578:
    // 0x80800578: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8080057C: bnel        $t2, $zero, L_80800660
    if (ctx->r10 != 0) {
        // 0x80800580: lw          $t7, 0x6C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X6C);
            goto L_80800660;
    }
    goto skip_5;
    // 0x80800580: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    skip_5:
    // 0x80800584: beql        $t3, $zero, L_80800660
    if (ctx->r11 == 0) {
        // 0x80800588: lw          $t7, 0x6C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X6C);
            goto L_80800660;
    }
    goto skip_6;
    // 0x80800588: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    skip_6:
    // 0x8080058C: jal         0x8080009C
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chjadesnake(rdram, ctx);
        goto after_49;
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80800594: beq         $v0, $zero, L_8080065C
    if (ctx->r2 == 0) {
        // 0x80800598: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080065C;
    }
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080059C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1868, 0X910) << 16);
    // 0x808005A0: addiu       $t4, $s0, 0x4
    ctx->r12 = ADD32(ctx->r16, 0X4);
    // 0x808005A4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x808005A8: addiu       $a2, $a2, 0x910
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1868, 0X910));
    // 0x808005AC: jal         0x80089D18
    // 0x808005B0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_50;
    // 0x808005B0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_50:
    // 0x808005B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808005B8: jal         0x80090734
    // 0x808005BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80090734(rdram, ctx);
        goto after_51;
    // 0x808005BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_51:
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C4: jal         0x8010A85C
    // 0x808005C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_52;
    // 0x808005C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_52:
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: jal         0x80102424
    // 0x808005D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_53;
    // 0x808005D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_53:
    // 0x808005D8: lui         $a1, 0x3F11
    ctx->r5 = S32(0X3F11 << 16);
    // 0x808005DC: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    // 0x808005E0: jal         0x80101EE4
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101EE4(rdram, ctx);
        goto after_54;
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x808005E8: b           L_80800660
    // 0x808005EC: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
        goto L_80800660;
    // 0x808005EC: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_808005F0:
    // 0x808005F0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x808005F4: bnel        $t5, $zero, L_80800660
    if (ctx->r13 != 0) {
        // 0x808005F8: lw          $t7, 0x6C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X6C);
            goto L_80800660;
    }
    goto skip_7;
    // 0x808005F8: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    skip_7:
    // 0x808005FC: jal         0x80800048
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800048_chjadesnake(rdram, ctx);
        goto after_55;
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80800604: b           L_80800660
    // 0x80800608: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
        goto L_80800660;
    // 0x80800608: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_8080060C:
    // 0x8080060C: jal         0x80101DDC
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_56;
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x80800614: beq         $v0, $zero, L_8080065C
    if (ctx->r2 == 0) {
        // 0x80800618: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_8080065C;
    }
    // 0x80800618: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8080061C: beq         $t6, $zero, L_80800640
    if (ctx->r14 == 0) {
        // 0x80800620: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800640;
    }
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800624: jal         0x8010A85C
    // 0x80800628: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A85C(rdram, ctx);
        goto after_57;
    // 0x80800628: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_57:
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: jal         0x80102424
    // 0x80800634: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_58;
    // 0x80800634: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_58:
    // 0x80800638: b           L_80800660
    // 0x8080063C: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
        goto L_80800660;
    // 0x8080063C: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_80800640:
    // 0x80800640: jal         0x80800048
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800048_chjadesnake(rdram, ctx);
        goto after_59;
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x80800648: jal         0x80090708
    // 0x8080064C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_60;
    // 0x8080064C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_60:
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: jal         0x80102424
    // 0x80800658: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_61;
    // 0x80800658: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_61:
L_8080065C:
    // 0x8080065C: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_80800660:
    // 0x80800660: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800664: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80800668: beql        $t8, $zero, L_80800718
    if (ctx->r24 == 0) {
        // 0x8080066C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800718;
    }
    goto skip_8;
    // 0x8080066C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x80800670: jal         0x800D0634
    // 0x80800674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0634(rdram, ctx);
        goto after_62;
    // 0x80800674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_62:
    // 0x80800678: beq         $v0, $zero, L_80800714
    if (ctx->r2 == 0) {
        // 0x8080067C: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80800714;
    }
    // 0x8080067C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800680: jal         0x800D0634
    // 0x80800684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0634(rdram, ctx);
        goto after_63;
    // 0x80800684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_63:
    // 0x80800688: jal         0x80106790
    // 0x8080068C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_64;
    // 0x8080068C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_64:
    // 0x80800690: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800694: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800698: jal         0x800EF04C
    // 0x8080069C: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_65;
    // 0x8080069C: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    after_65:
    // 0x808006A0: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x808006A4: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    // 0x808006A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006AC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x808006B0: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x808006B4: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x808006B8: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808006BC: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
    // 0x808006C0: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x808006C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808006C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1868, 0X920) << 16);
    // 0x808006CC: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x808006D0: bne         $t6, $at, L_808006EC
    if (ctx->r14 != ctx->r1) {
        // 0x808006D4: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808006EC;
    }
    // 0x808006D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808006D8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808006DC: jal         0x80089D18
    // 0x808006E0: addiu       $a2, $a2, 0x920
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1868, 0X920));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_66;
    // 0x808006E0: addiu       $a2, $a2, 0x920
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1868, 0X920));
    after_66:
    // 0x808006E4: b           L_80800718
    // 0x808006E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800718;
    // 0x808006E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006EC:
    // 0x808006EC: bne         $v0, $zero, L_80800714
    if (ctx->r2 != 0) {
        // 0x808006F0: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80800714;
    }
    // 0x808006F0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808006F4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808006F8: jal         0x800EE7F8
    // 0x808006FC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_67;
    // 0x808006FC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_67:
    // 0x80800700: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800704: jal         0x80102FE8
    // 0x80800708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102FE8(rdram, ctx);
        goto after_68;
    // 0x80800708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_68:
    // 0x8080070C: jal         0x80103014
    // 0x80800710: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80103014(rdram, ctx);
        goto after_69;
    // 0x80800710: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_69:
L_80800714:
    // 0x80800714: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800718:
    // 0x80800718: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080071C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800720: jr          $ra
    // 0x80800724: nop

    return;
    // 0x80800724: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C98: jal         0x80090A2C
    // 0x80801C9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090A2C(rdram, ctx);
        goto after_0;
    // 0x80801C9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801CA0: jal         0x808000D4
    // 0x80801CA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstaxi_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801CA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801CB0: jr          $ra
    // 0x80801CB4: nop

    return;
    // 0x80801CB4: nop

;}
RECOMP_FUNC void _dbmorph_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087988: syscall     643
    recomp_syscall_handler(rdram, ctx, 0x80087988);
    return;
    // 0x8008798C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bsbabykaz_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082828: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x80082828);
    return;
    // 0x8008282C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_808003DC_chfactorydrums(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808003E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003E8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808003EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003F0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808003F4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808003F8: beq         $t7, $at, L_8080040C
    if (ctx->r15 == ctx->r1) {
        // 0x808003FC: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_8080040C;
    }
    // 0x808003FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: jal         0x8010C93C
    // 0x80800408: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8010C93C(rdram, ctx);
        goto after_0;
    // 0x80800408: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
L_8080040C:
    // 0x8080040C: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x80800410: sll         $t0, $t8, 29
    ctx->r8 = S32(ctx->r24 << 29);
    // 0x80800414: bltzl       $t0, L_80800C40
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800418: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800C40;
    }
    goto skip_0;
    // 0x80800418: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080041C: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x80800420: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80800424: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80800428: sltiu       $at, $t3, 0x9
    ctx->r1 = ctx->r11 < 0X9 ? 1 : 0;
    // 0x8080042C: beq         $at, $zero, L_80800C3C
    if (ctx->r1 == 0) {
        // 0x80800430: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80800C3C;
    }
    // 0x80800430: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80800434: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2252, 0XF70) << 16);
    // 0x80800438: addu        $at, $at, $t3
    gpr jr_addend_80800440 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8080043C: lw          $t3, 0xF70($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2252, 0XF70));
    // 0x80800440: jr          $t3
    // 0x80800444: nop

    switch (jr_addend_80800440 >> 2) {
        case 0: goto L_80800448; break;
        case 1: goto L_808004D4; break;
        case 2: goto L_80800554; break;
        case 3: goto L_80800874; break;
        case 4: goto L_808008CC; break;
        case 5: goto L_80800A24; break;
        case 6: goto L_80800C3C; break;
        case 7: goto L_80800C3C; break;
        case 8: goto L_80800C3C; break;
        default: switch_error(__func__, 0x80800440, 0x80800F70);
    }
    // 0x80800444: nop

L_80800448:
    // 0x80800448: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x8080044C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80800450: bgez        $t6, L_80800494
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800454: nop
    
            goto L_80800494;
    }
    // 0x80800454: nop

    // 0x80800458: jal         0x80089BC0
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800460: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2252, 0XF94) << 16);
    // 0x80800464: lwc1        $f4, 0xF94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2252, 0XF94));
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80800470: nop

    // 0x80800474: bc1f        L_80800484
    if (!c1cs) {
        // 0x80800478: nop
    
            goto L_80800484;
    }
    // 0x80800478: nop

    // 0x8080047C: jal         0x80800CD0
    // 0x80800480: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_2;
    // 0x80800480: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_80800484:
    // 0x80800484: jal         0x808002B8
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002B8_chfactorydrums(rdram, ctx);
        goto after_3;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080048C: b           L_80800C40
    // 0x80800490: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800C40;
    // 0x80800490: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800494:
    // 0x80800494: jal         0x800D90A4
    // 0x80800498: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x80800498: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_4:
    // 0x8080049C: beql        $v0, $zero, L_80800C40
    if (ctx->r2 == 0) {
        // 0x808004A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800C40;
    }
    goto skip_1;
    // 0x808004A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808004A4: jal         0x8010C500
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_5;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808004AC: beql        $v0, $zero, L_80800C40
    if (ctx->r2 == 0) {
        // 0x808004B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800C40;
    }
    goto skip_2;
    // 0x808004B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808004B4: jal         0x80800130
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800130_chfactorydrums(rdram, ctx);
        goto after_6;
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808004BC: beq         $v0, $zero, L_80800C3C
    if (ctx->r2 == 0) {
        // 0x808004C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C3C;
    }
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: jal         0x80800CD0
    // 0x808004C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_7;
    // 0x808004C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808004CC: b           L_80800C40
    // 0x808004D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800C40;
    // 0x808004D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004D4:
    // 0x808004D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2252, 0X1098) << 16);
    // 0x808004D8: addiu       $a2, $a2, 0x1098
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2252, 0X1098));
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808004E4: jal         0x80089D20
    // 0x808004E8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808004E8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_8:
    // 0x808004EC: jal         0x80101DDC
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_9;
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808004F4: beq         $v0, $zero, L_80800520
    if (ctx->r2 == 0) {
        // 0x808004F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800520;
    }
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: jal         0x80800CD0
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_10;
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800504: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800508: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080050C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800510: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800514: jal         0x800DC178
    // 0x80800518: nop

    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80800518: nop

    after_11:
    // 0x8080051C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800520:
    // 0x80800520: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800524: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800528: bgezl       $t9, L_80800C40
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8080052C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800C40;
    }
    goto skip_3;
    // 0x8080052C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800530: jal         0x80089BC0
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080053C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80800540: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800544: jal         0x80102BAC
    // 0x80800548: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    func_80102BAC(rdram, ctx);
        goto after_13;
    // 0x80800548: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_13:
    // 0x8080054C: b           L_80800C40
    // 0x80800550: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800C40;
    // 0x80800550: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800554:
    // 0x80800554: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2252, 0X108C) << 16);
    // 0x80800558: addiu       $t0, $t0, 0x108C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2252, 0X108C));
    // 0x8080055C: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80800560: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8080056C: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x80800570: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x80800574: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80800578: jal         0x80101E4C
    // 0x8080057C: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    func_80101E4C(rdram, ctx);
        goto after_14;
    // 0x8080057C: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    after_14:
    // 0x80800580: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x80800584: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800654;
    }
    // 0x80800584: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800588: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080058C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2252, 0XF98) << 16);
    // 0x80800590: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    // 0x80800594: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80800598: jal         0x800DC178
    // 0x8080059C: lwc1        $f14, 0xF98($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2252, 0XF98));
    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x8080059C: lwc1        $f14, 0xF98($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2252, 0XF98));
    after_15:
    // 0x808005A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2252, 0XF9C) << 16);
    // 0x808005A4: lwc1        $f6, 0xF9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2252, 0XF9C));
    // 0x808005A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808005AC: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x808005B0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808005B4: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808005B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808005BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808005C0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x808005C4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808005C8: nop

    // 0x808005CC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x808005D0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808005D4: nop

    // 0x808005D8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808005DC: beql        $a0, $zero, L_8080062C
    if (ctx->r4 == 0) {
        // 0x808005E0: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_8080062C;
    }
    goto skip_4;
    // 0x808005E0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x808005E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808005EC: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x808005F0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808005F4: nop

    // 0x808005F8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x808005FC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800600: nop

    // 0x80800604: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800608: bne         $a0, $zero, L_80800620
    if (ctx->r4 != 0) {
        // 0x8080060C: nop
    
            goto L_80800620;
    }
    // 0x8080060C: nop

    // 0x80800610: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80800614: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800618: b           L_80800638
    // 0x8080061C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800638;
    // 0x8080061C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800620:
    // 0x80800620: b           L_80800638
    // 0x80800624: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800638;
    // 0x80800624: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800628: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_8080062C:
    // 0x8080062C: nop

    // 0x80800630: bltz        $a0, L_80800620
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800634: nop
    
            goto L_80800620;
    }
    // 0x80800634: nop

L_80800638:
    // 0x80800638: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
    // 0x8080063C: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80800640: ori         $at, $at, 0xA45A
    ctx->r1 = ctx->r1 | 0XA45A;
    // 0x80800644: sll         $t6, $t5, 21
    ctx->r14 = S32(ctx->r13 << 21);
    // 0x80800648: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8080064C: jal         0x800C4140
    // 0x80800650: addu        $a0, $t6, $at
    ctx->r4 = ADD32(ctx->r14, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_16;
    // 0x80800650: addu        $a0, $t6, $at
    ctx->r4 = ADD32(ctx->r14, ctx->r1);
    after_16:
L_80800654:
    // 0x80800654: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080065C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800660: bgez        $t9, L_808006F4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800664: nop
    
            goto L_808006F4;
    }
    // 0x80800664: nop

    // 0x80800668: jal         0x80089BC0
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800670: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8080067C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800680: jal         0x80102BAC
    // 0x80800684: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    func_80102BAC(rdram, ctx);
        goto after_18;
    // 0x80800684: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_18:
    // 0x80800688: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080068C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800690: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800694: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x80800698: ori         $a1, $a1, 0x1015
    ctx->r5 = ctx->r5 | 0X1015;
    // 0x8080069C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x808006A8: jal         0x8010BA80
    // 0x808006AC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_8010BA80(rdram, ctx);
        goto after_19;
    // 0x808006AC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_19:
    // 0x808006B0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808006B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2252, 0XFA0) << 16);
    // 0x808006BC: lwc1        $f6, 0xFA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2252, 0XFA0));
    // 0x808006C0: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808006C4: lui         $a3, 0x3EEF
    ctx->r7 = S32(0X3EEF << 16);
    // 0x808006C8: ori         $a3, $a3, 0x1AA0
    ctx->r7 = ctx->r7 | 0X1AA0;
    // 0x808006CC: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x808006D0: jal         0x800F1198
    // 0x808006D4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F1198(rdram, ctx);
        goto after_20;
    // 0x808006D4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_20:
    // 0x808006D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808006DC: jal         0x80101CDC
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101CDC(rdram, ctx);
        goto after_21;
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808006E4: jal         0x808002B8
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002B8_chfactorydrums(rdram, ctx);
        goto after_22;
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808006EC: b           L_80800C40
    // 0x808006F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800C40;
    // 0x808006F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006F4:
    // 0x808006F4: jal         0x80100094
    // 0x808006F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_23;
    // 0x808006F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x808006FC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800700: jal         0x80089F78
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_24;
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800708: beq         $v0, $zero, L_8080079C
    if (ctx->r2 == 0) {
        // 0x8080070C: nop
    
            goto L_8080079C;
    }
    // 0x8080070C: nop

    // 0x80800710: jal         0x8010C500
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_25;
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800718: beql        $v0, $zero, L_80800750
    if (ctx->r2 == 0) {
        // 0x8080071C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800750;
    }
    goto skip_5;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80800720: jal         0x80800130
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800130_chfactorydrums(rdram, ctx);
        goto after_26;
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800728: beql        $v0, $zero, L_80800750
    if (ctx->r2 == 0) {
        // 0x8080072C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800750;
    }
    goto skip_6;
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
    // 0x80800730: jal         0x800F54E4
    // 0x80800734: nop

    func_800F54E4(rdram, ctx);
        goto after_27;
    // 0x80800734: nop

    after_27:
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080073C: jal         0x8010CD50
    // 0x80800740: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010CD50(rdram, ctx);
        goto after_28;
    // 0x80800740: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_28:
    // 0x80800744: b           L_80800758
    // 0x80800748: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_80800758;
    // 0x80800748: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800750:
    // 0x80800750: jal         0x80800CD0
    // 0x80800754: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_29;
    // 0x80800754: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_29:
L_80800758:
    // 0x80800758: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080075C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800760: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800764: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80800768: addiu       $t1, $zero, 0x4802
    ctx->r9 = ADD32(0, 0X4802);
    // 0x8080076C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800774: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80800778: jal         0x80089F90
    // 0x8080077C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_30;
    // 0x8080077C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_30:
    // 0x80800780: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80800784: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800788: lhu         $t3, 0x6($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X6);
    // 0x8080078C: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x80800790: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x80800794: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80800798: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
L_8080079C:
    // 0x8080079C: jal         0x800D8FF8
    // 0x808007A0: nop

    func_800D8FF8(rdram, ctx);
        goto after_31;
    // 0x808007A0: nop

    after_31:
    // 0x808007A4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808007A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808007AC: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808007B0: lwc1        $f14, 0x50($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808007B4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808007B8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808007BC: jal         0x800F15F8
    // 0x808007C0: nop

    func_800F15F8(rdram, ctx);
        goto after_32;
    // 0x808007C0: nop

    after_32:
    // 0x808007C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808007CC: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    // 0x808007D0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808007D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007D8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808007DC: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x808007E0: andi        $t8, $a2, 0x1FF
    ctx->r24 = ctx->r6 & 0X1FF;
    // 0x808007E4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x808007E8: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808007EC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x808007F8: jal         0x80089F80
    // 0x808007FC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_33;
    // 0x808007FC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_33:
    // 0x80800800: jal         0x80101F24
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_34;
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800808: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2252, 0X10B0) << 16);
    // 0x8080080C: addiu       $a1, $a1, 0x10B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2252, 0X10B0));
    // 0x80800810: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800814: jal         0x800F3780
    // 0x80800818: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800F3780(rdram, ctx);
        goto after_35;
    // 0x80800818: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_35:
    // 0x8080081C: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x80800820: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800824: ori         $a1, $a1, 0x5425
    ctx->r5 = ctx->r5 | 0X5425;
    // 0x80800828: jal         0x8010C3A8
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C3A8(rdram, ctx);
        goto after_36;
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800830: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2252, 0X10E0) << 16);
    // 0x80800834: addiu       $t9, $t9, 0x10E0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2252, 0X10E0));
    // 0x80800838: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800840: sw          $at, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r1;
    // 0x80800844: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x80800848: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8080084C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800850: lw          $a3, 0x8($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X8);
    // 0x80800854: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80800858: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080085C: jal         0x801026CC
    // 0x80800860: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_801026CC(rdram, ctx);
        goto after_37;
    // 0x80800860: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_37:
    // 0x80800864: jal         0x808002B8
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002B8_chfactorydrums(rdram, ctx);
        goto after_38;
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x8080086C: b           L_80800C40
    // 0x80800870: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800C40;
    // 0x80800870: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800874:
    // 0x80800874: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2252, 0X1098) << 16);
    // 0x80800878: addiu       $a2, $a2, 0x1098
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2252, 0X1098));
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800880: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800884: jal         0x80089D20
    // 0x80800888: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_39;
    // 0x80800888: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_39:
    // 0x8080088C: jal         0x80101DDC
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_40;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80800894: beql        $v0, $zero, L_80800C40
    if (ctx->r2 == 0) {
        // 0x80800898: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800C40;
    }
    goto skip_7;
    // 0x80800898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x8080089C: lw          $t2, 0x78($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X78);
    // 0x808008A0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A8: sll         $t5, $t2, 29
    ctx->r13 = S32(ctx->r10 << 29);
    // 0x808008AC: bltzl       $t5, L_80800C40
    if (SIGNED(ctx->r13) < 0) {
        // 0x808008B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800C40;
    }
    goto skip_8;
    // 0x808008B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x808008B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808008BC: jal         0x80800CD0
    // 0x808008C0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_41;
    // 0x808008C0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_41:
    // 0x808008C4: b           L_80800C40
    // 0x808008C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800C40;
    // 0x808008C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008CC:
    // 0x808008CC: addiu       $t4, $s0, 0x4
    ctx->r12 = ADD32(ctx->r16, 0X4);
    // 0x808008D0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x808008D4: jal         0x80101F24
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_42;
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x808008DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2252, 0XFA4) << 16);
    // 0x808008E0: lwc1        $f10, 0xFA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2252, 0XFA4));
    // 0x808008E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008E8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x808008EC: nop

    // 0x808008F0: bc1f        L_808008FC
    if (!c1cs) {
        // 0x808008F4: nop
    
            goto L_808008FC;
    }
    // 0x808008F4: nop

    // 0x808008F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008FC:
    // 0x808008FC: beq         $v0, $zero, L_8080092C
    if (ctx->r2 == 0) {
        // 0x80800900: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8080092C;
    }
    // 0x80800900: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800904: jal         0x80101F24
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_43;
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x8080090C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800910: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800918: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8080091C: nop

    // 0x80800920: bc1f        L_8080092C
    if (!c1cs) {
        // 0x80800924: nop
    
            goto L_8080092C;
    }
    // 0x80800924: nop

    // 0x80800928: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8080092C:
    // 0x8080092C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2252, 0X1080) << 16);
    // 0x80800930: addiu       $a3, $a3, 0x1080
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2252, 0X1080));
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800938: jal         0x80089D50
    // 0x8080093C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_44;
    // 0x8080093C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_44:
    // 0x80800940: jal         0x80101F24
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_45;
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80800948: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2252, 0XFA8) << 16);
    // 0x8080094C: lwc1        $f14, 0xFA8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2252, 0XFA8));
    // 0x80800950: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800954: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800958: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080095C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800960: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800964: jal         0x800F10B4
    // 0x80800968: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_46;
    // 0x80800968: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_46:
    // 0x8080096C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2252, 0XFAC) << 16);
    // 0x80800970: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800974: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800978: lwc1        $f14, 0xFAC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2252, 0XFAC));
    // 0x8080097C: jal         0x800F1214
    // 0x80800980: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F1214(rdram, ctx);
        goto after_47;
    // 0x80800980: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_47:
    // 0x80800984: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800988: jal         0x80089D30
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_48;
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800994: jal         0x80101E14
    // 0x80800998: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_49;
    // 0x80800998: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_49:
    // 0x8080099C: beq         $v0, $zero, L_808009B4
    if (ctx->r2 == 0) {
        // 0x808009A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009B4;
    }
    // 0x808009A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A4: jal         0x80108B04
    // 0x808009A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_50;
    // 0x808009A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_50:
    // 0x808009AC: b           L_80800C40
    // 0x808009B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800C40;
    // 0x808009B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009B4:
    // 0x808009B4: jal         0x80101DDC
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_51;
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x808009BC: beql        $v0, $zero, L_80800C40
    if (ctx->r2 == 0) {
        // 0x808009C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800C40;
    }
    goto skip_9;
    // 0x808009C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x808009C4: jal         0x80089D40
    // 0x808009C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_52;
    // 0x808009C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x808009CC: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808009D8: bgez        $t8, L_808009F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808009DC: nop
    
            goto L_808009F0;
    }
    // 0x808009DC: nop

    // 0x808009E0: jal         0x80800CD0
    // 0x808009E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_53;
    // 0x808009E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_53:
    // 0x808009E8: b           L_80800C40
    // 0x808009EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800C40;
    // 0x808009EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009F0:
    // 0x808009F0: jal         0x8010C500
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_54;
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x808009F8: beq         $v0, $zero, L_80800A14
    if (ctx->r2 == 0) {
        // 0x808009FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A14;
    }
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A04: jal         0x80800CD0
    // 0x80800A08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_55;
    // 0x80800A08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_55:
    // 0x80800A0C: b           L_80800C40
    // 0x80800A10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800C40;
    // 0x80800A10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A14:
    // 0x80800A14: jal         0x80800CD0
    // 0x80800A18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_56;
    // 0x80800A18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_56:
    // 0x80800A1C: b           L_80800C40
    // 0x80800A20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800C40;
    // 0x80800A20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A24:
    // 0x80800A24: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    // 0x80800A28: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80800A2C: jal         0x800B53A4
    // 0x80800A30: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800B53A4(rdram, ctx);
        goto after_57;
    // 0x80800A30: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_57:
    // 0x80800A34: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800A38: jal         0x800B53A4
    // 0x80800A3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800B53A4(rdram, ctx);
        goto after_58;
    // 0x80800A3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_58:
    // 0x80800A40: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800A44: jal         0x800B53A4
    // 0x80800A48: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B53A4(rdram, ctx);
        goto after_59;
    // 0x80800A48: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_59:
    // 0x80800A4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A50: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2252, 0X117C) << 16);
    // 0x80800A54: addiu       $t9, $t9, 0x117C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2252, 0X117C));
    // 0x80800A58: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800A5C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800A60: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800A64: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800A68: jal         0x800BABB8
    // 0x80800A6C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BABB8(rdram, ctx);
        goto after_60;
    // 0x80800A6C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_60:
    // 0x80800A70: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800A74: jal         0x800BA670
    // 0x80800A78: addiu       $a1, $zero, 0x88C
    ctx->r5 = ADD32(0, 0X88C);
    func_800BA670(rdram, ctx);
        goto after_61;
    // 0x80800A78: addiu       $a1, $zero, 0x88C
    ctx->r5 = ADD32(0, 0X88C);
    after_61:
    // 0x80800A7C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80800A80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A84: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800A88: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800A8C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800A90: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800A94: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800A98: nop

    // 0x80800A9C: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80800AA0: jal         0x800BA4D0
    // 0x80800AA4: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_62;
    // 0x80800AA4: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_62:
    // 0x80800AA8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800AAC: jal         0x800BA22C
    // 0x80800AB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BA22C(rdram, ctx);
        goto after_63;
    // 0x80800AB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_63:
    // 0x80800AB4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AB8: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2252, 0X117C) << 16);
    // 0x80800ABC: addiu       $t5, $t5, 0x117C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2252, 0X117C));
    // 0x80800AC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800AC4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800AC8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800ACC: jal         0x800BABB8
    // 0x80800AD0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BABB8(rdram, ctx);
        goto after_64;
    // 0x80800AD0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_64:
    // 0x80800AD4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800AD8: jal         0x800BA670
    // 0x80800ADC: addiu       $a1, $zero, 0x88D
    ctx->r5 = ADD32(0, 0X88D);
    func_800BA670(rdram, ctx);
        goto after_65;
    // 0x80800ADC: addiu       $a1, $zero, 0x88D
    ctx->r5 = ADD32(0, 0X88D);
    after_65:
    // 0x80800AE0: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80800AE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800AE8: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800AEC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800AF0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800AF4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800AF8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800AFC: nop

    // 0x80800B00: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80800B04: jal         0x800BA4D0
    // 0x80800B08: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_66;
    // 0x80800B08: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_66:
    // 0x80800B0C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800B10: jal         0x800BA22C
    // 0x80800B14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BA22C(rdram, ctx);
        goto after_67;
    // 0x80800B14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_67:
    // 0x80800B18: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B1C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2252, 0X117C) << 16);
    // 0x80800B20: addiu       $t8, $t8, 0x117C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2252, 0X117C));
    // 0x80800B24: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800B28: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800B2C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800B30: jal         0x800BABB8
    // 0x80800B34: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BABB8(rdram, ctx);
        goto after_68;
    // 0x80800B34: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_68:
    // 0x80800B38: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800B3C: jal         0x800BA670
    // 0x80800B40: addiu       $a1, $zero, 0x88B
    ctx->r5 = ADD32(0, 0X88B);
    func_800BA670(rdram, ctx);
        goto after_69;
    // 0x80800B40: addiu       $a1, $zero, 0x88B
    ctx->r5 = ADD32(0, 0X88B);
    after_69:
    // 0x80800B44: lhu         $t1, 0x76($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X76);
    // 0x80800B48: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800B4C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800B50: srl         $t9, $t1, 7
    ctx->r25 = S32(U32(ctx->r9) >> 7);
    // 0x80800B54: beq         $t9, $at, L_80800B68
    if (ctx->r25 == ctx->r1) {
        // 0x80800B58: lui         $a2, 0x8008
        ctx->r6 = S32(0X8008 << 16);
            goto L_80800B68;
    }
    // 0x80800B58: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800B5C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800B60: b           L_80800B6C
    // 0x80800B64: addiu       $a2, $a2, 0x7430
    ctx->r6 = ADD32(ctx->r6, 0X7430);
        goto L_80800B6C;
    // 0x80800B64: addiu       $a2, $a2, 0x7430
    ctx->r6 = ADD32(ctx->r6, 0X7430);
L_80800B68:
    // 0x80800B68: addiu       $a2, $a2, 0x7438
    ctx->r6 = ADD32(ctx->r6, 0X7438);
L_80800B6C:
    // 0x80800B6C: jal         0x800BA544
    // 0x80800B70: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800BA544(rdram, ctx);
        goto after_70;
    // 0x80800B70: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_70:
    // 0x80800B74: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80800B78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800B7C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800B80: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800B84: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800B88: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800B8C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800B90: nop

    // 0x80800B94: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80800B98: jal         0x800BA4D0
    // 0x80800B9C: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_71;
    // 0x80800B9C: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_71:
    // 0x80800BA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800BA4: jal         0x800BA22C
    // 0x80800BA8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800BA22C(rdram, ctx);
        goto after_72;
    // 0x80800BA8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_72:
    // 0x80800BAC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2252, 0X11B8) << 16);
    // 0x80800BB0: addiu       $a2, $a2, 0x11B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2252, 0X11B8));
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB8: jal         0x80089D18
    // 0x80800BBC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_73;
    // 0x80800BBC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_73:
    // 0x80800BC0: lhu         $t5, 0x76($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X76);
    // 0x80800BC4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800BC8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BCC: srl         $t4, $t5, 7
    ctx->r12 = S32(U32(ctx->r13) >> 7);
    // 0x80800BD0: beq         $t4, $at, L_80800C18
    if (ctx->r12 == ctx->r1) {
        // 0x80800BD4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800C18;
    }
    // 0x80800BD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BD8: jal         0x80800000
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chfactorydrums(rdram, ctx);
        goto after_74;
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_74:
    // 0x80800BE0: beq         $v0, $zero, L_80800BF0
    if (ctx->r2 == 0) {
        // 0x80800BE4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BF0;
    }
    // 0x80800BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE8: jal         0x80108B04
    // 0x80800BEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_75;
    // 0x80800BEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_75:
L_80800BF0:
    // 0x80800BF0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2252, 0X1134) << 16);
    // 0x80800BF4: addiu       $t6, $t6, 0x1134
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2252, 0X1134));
    // 0x80800BF8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800BFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C00: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C08: jal         0x800BBCB8
    // 0x80800C0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_76;
    // 0x80800C0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_76:
    // 0x80800C10: b           L_80800C34
    // 0x80800C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800C34;
    // 0x80800C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C18:
    // 0x80800C18: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2252, 0X10EC) << 16);
    // 0x80800C1C: addiu       $t7, $t7, 0x10EC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2252, 0X10EC));
    // 0x80800C20: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800C24: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800C28: jal         0x800BBCB8
    // 0x80800C2C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_77;
    // 0x80800C2C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_77:
    // 0x80800C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C34:
    // 0x80800C34: jal         0x80800CD0
    // 0x80800C38: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_78;
    // 0x80800C38: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_78:
L_80800C3C:
    // 0x80800C3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C40:
    // 0x80800C40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C44: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800C48: jr          $ra
    // 0x80800C4C: nop

    return;
    // 0x80800C4C: nop

;}
RECOMP_FUNC void _baboost_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084598: syscall     115
    recomp_syscall_handler(rdram, ctx, 0x80084598);
    return;
    // 0x8008459C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080853C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080853C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80808540: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80808544: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80808548: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080854C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80808550: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80808554: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80808558: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8080855C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80808560: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80808564: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80808568: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080856C: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80808570: beql        $v0, $a0, L_80808598
    if (ctx->r2 == ctx->r4) {
        // 0x80808574: add.s       $f16, $f18, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f12.fl;
            goto L_80808598;
    }
    goto skip_0;
    // 0x80808574: add.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f12.fl;
    skip_0:
L_80808578:
    // 0x80808578: add.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8080857C: lwc1        $f14, 0x4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80808580: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80808584: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80808588: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8080858C: bne         $v0, $a0, L_80808578
    if (ctx->r2 != ctx->r4) {
        // 0x80808590: swc1        $f16, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
            goto L_80808578;
    }
    // 0x80808590: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80808594: add.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f12.fl;
L_80808598:
    // 0x80808598: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080859C: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x808085A0: jr          $ra
    // 0x808085A4: nop

    return;
    // 0x808085A4: nop

;}
RECOMP_FUNC void func_800D129C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D129C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D12A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D12A4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800D12A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D12AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D12B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D12B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D12B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D12BC: jal         0x800D0820
    // 0x800D12C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D0820(rdram, ctx);
        goto after_0;
    // 0x800D12C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800D12C4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D12C8: jal         0x800D0894
    // 0x800D12CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D0894(rdram, ctx);
        goto after_1;
    // 0x800D12CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800D12D0: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800D12D4: bne         $at, $zero, L_800D1318
    if (ctx->r1 != 0) {
        // 0x800D12D8: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_800D1318;
    }
    // 0x800D12D8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800D12DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D12E0: addiu       $t7, $t7, -0x54C0
    ctx->r15 = ADD32(ctx->r15, -0X54C0);
    // 0x800D12E4: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800D12E8: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800D12EC: lbu         $t8, -0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X2);
L_800D12F0:
    // 0x800D12F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D12F4: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // 0x800D12F8: bne         $s3, $t8, L_800D1304
    if (ctx->r19 != ctx->r24) {
        // 0x800D12FC: nop
    
            goto L_800D1304;
    }
    // 0x800D12FC: nop

    // 0x800D1300: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D1304:
    // 0x800D1304: jal         0x800D0894
    // 0x800D1308: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D0894(rdram, ctx);
        goto after_2;
    // 0x800D1308: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800D130C: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800D1310: beql        $at, $zero, L_800D12F0
    if (ctx->r1 == 0) {
        // 0x800D1314: lbu         $t8, -0x2($s0)
        ctx->r24 = MEM_BU(ctx->r16, -0X2);
            goto L_800D12F0;
    }
    goto skip_0;
    // 0x800D1314: lbu         $t8, -0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X2);
    skip_0:
L_800D1318:
    // 0x800D1318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D131C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800D1320: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1324: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D1328: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D132C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D1330: jr          $ra
    // 0x800D1334: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D1334: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void gcnewoption_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808018E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808018EC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808018F0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808018F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808018F8: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x808018FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801900: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801904: beq         $a2, $zero, L_80801918
    if (ctx->r6 == 0) {
        // 0x80801908: sh          $t6, 0x238($a0)
        MEM_H(0X238, ctx->r4) = ctx->r14;
            goto L_80801918;
    }
    // 0x80801908: sh          $t6, 0x238($a0)
    MEM_H(0X238, ctx->r4) = ctx->r14;
    // 0x8080190C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801910: jal         0x80087B98
    // 0x80801914: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gczoombox_entrypoint_23(rdram, ctx);
        goto after_0;
    // 0x80801914: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
L_80801918:
    // 0x80801918: lh          $t7, 0x2($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X2);
    // 0x8080191C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801920: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80801924: blezl       $t7, L_80801954
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80801928: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801954;
    }
    goto skip_0;
    // 0x80801928: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080192C: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
L_80801930:
    // 0x80801930: jal         0x80087B98
    // 0x80801934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gczoombox_entrypoint_23(rdram, ctx);
        goto after_1;
    // 0x80801934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801938: lh          $t8, 0x2($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X2);
    // 0x8080193C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801940: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80801944: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80801948: bnel        $at, $zero, L_80801930
    if (ctx->r1 != 0) {
        // 0x8080194C: lw          $a0, 0x3C($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X3C);
            goto L_80801930;
    }
    goto skip_1;
    // 0x8080194C: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    skip_1:
    // 0x80801950: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801954:
    // 0x80801954: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801958: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080195C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801960: jr          $ra
    // 0x80801964: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801964: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chstoneballcontrol_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A60: syscall     409
    recomp_syscall_handler(rdram, ctx, 0x80086A60);
    return;
    // 0x80086A64: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chmumboskullfakearchpanellava_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087048: syscall     498
    recomp_syscall_handler(rdram, ctx, 0x80087048);
    return;
    // 0x8008704C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808016E8_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016E8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808016EC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2336, 0X2558) << 16);
    // 0x808016F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016F4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808016F8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x808016FC: addiu       $t6, $t6, 0x2558
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2336, 0X2558));
    // 0x80801700: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80801704: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x80801708: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080170C: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80801710: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80801714: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80801718: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8080171C: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x80801720: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x80801724: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x80801728: lw          $at, 0x10($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X10);
    // 0x8080172C: sw          $at, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r1;
    // 0x80801730: lw          $t9, 0x14($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X14);
    // 0x80801734: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
    // 0x80801738: lw          $at, 0x18($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X18);
    // 0x8080173C: sw          $at, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r1;
    // 0x80801740: lw          $t9, 0x1C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X1C);
    // 0x80801744: sw          $t9, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r25;
    // 0x80801748: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8080174C:
    // 0x8080174C: sll         $t2, $v1, 3
    ctx->r10 = S32(ctx->r3 << 3);
    // 0x80801750: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x80801754: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80801758: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8080175C: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x80801760: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80801764: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80801768: nop

    // 0x8080176C: bc1fl       L_80801780
    if (!c1cs) {
        // 0x80801770: lwc1        $f6, 0x4($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80801780;
    }
    goto skip_0;
    // 0x80801770: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80801774: b           L_80801860
    // 0x80801778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801860;
    // 0x80801778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080177C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
L_80801780:
    // 0x80801780: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80801784: nop

    // 0x80801788: bc1tl       L_808017A0
    if (c1cs) {
        // 0x8080178C: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_808017A0;
    }
    goto skip_1;
    // 0x8080178C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    skip_1:
    // 0x80801790: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80801794: bne         $at, $zero, L_8080174C
    if (ctx->r1 != 0) {
        // 0x80801798: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_8080174C;
    }
    // 0x80801798: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x8080179C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_808017A0:
    // 0x808017A0: bne         $at, $zero, L_808017B0
    if (ctx->r1 != 0) {
        // 0x808017A4: nop
    
            goto L_808017B0;
    }
    // 0x808017A4: nop

    // 0x808017A8: b           L_80801860
    // 0x808017AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801860;
    // 0x808017AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808017B0:
    // 0x808017B0: jal         0x800F1EA4
    // 0x808017B4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800F1EA4(rdram, ctx);
        goto after_0;
    // 0x808017B4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x808017B8: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x808017BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808017C0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808017C4: jal         0x800136E4
    // 0x808017C8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x808017C8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_1:
    // 0x808017CC: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x808017D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808017D4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x808017D8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808017DC: div.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
    // 0x808017E0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808017E4: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x808017E8: nop

    // 0x808017EC: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x808017F0: jal         0x800F13C4
    // 0x808017F4: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    func_800F13C4(rdram, ctx);
        goto after_2;
    // 0x808017F4: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x808017F8: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x808017FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801800: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80801804: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80801808: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080180C: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801810: bc1fl       L_80801824
    if (!c1cs) {
        // 0x80801814: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_80801824;
    }
    goto skip_2;
    // 0x80801814: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_2:
    // 0x80801818: b           L_80801860
    // 0x8080181C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801860;
    // 0x8080181C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801820: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_80801824:
    // 0x80801824: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80801828: div.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8080182C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801830: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80801834: jal         0x800F13C4
    // 0x80801838: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    func_800F13C4(rdram, ctx);
        goto after_3;
    // 0x80801838: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    after_3:
    // 0x8080183C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801840: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801848: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8080184C: nop

    // 0x80801850: bc1f        L_80801860
    if (!c1cs) {
        // 0x80801854: nop
    
            goto L_80801860;
    }
    // 0x80801854: nop

    // 0x80801858: b           L_80801860
    // 0x8080185C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801860;
    // 0x8080185C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801860:
    // 0x80801860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801864: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801868: jr          $ra
    // 0x8080186C: nop

    return;
    // 0x8080186C: nop

;}
