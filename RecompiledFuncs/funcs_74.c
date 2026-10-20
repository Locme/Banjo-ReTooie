#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800C75E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C75E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C75EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C75F0: addiu       $v0, $v0, 0x760C
    ctx->r2 = ADD32(ctx->r2, 0X760C);
    // 0x800C75F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C75F8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800C75FC: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800C7600: jal         0x800C77DC
    // 0x800C7604: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C77DC(rdram, ctx);
        goto after_0;
    // 0x800C7604: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C7608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C760C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7610: jr          $ra
    // 0x800C7614: nop

    return;
    // 0x800C7614: nop

;}
RECOMP_FUNC void func_80094864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094864: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80094868: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009486C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80094870: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80094874: jal         0x800F6774
    // 0x80094878: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F6774(rdram, ctx);
        goto after_0;
    // 0x80094878: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x8009487C: beq         $v0, $zero, L_800949A8
    if (ctx->r2 == 0) {
        // 0x80094880: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800949A8;
    }
    // 0x80094880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094884: jal         0x80094348
    // 0x80094888: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80094348(rdram, ctx);
        goto after_1;
    // 0x80094888: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x8009488C: beql        $v0, $zero, L_800948A0
    if (ctx->r2 == 0) {
        // 0x80094890: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800948A0;
    }
    goto skip_0;
    // 0x80094890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80094894: jal         0x80094390
    // 0x80094898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094390(rdram, ctx);
        goto after_2;
    // 0x80094898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8009489C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800948A0:
    // 0x800948A0: jal         0x80094348
    // 0x800948A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80094348(rdram, ctx);
        goto after_3;
    // 0x800948A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x800948A8: beql        $v0, $zero, L_800948E4
    if (ctx->r2 == 0) {
        // 0x800948AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800948E4;
    }
    goto skip_1;
    // 0x800948AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800948B0: jal         0x80094510
    // 0x800948B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094510(rdram, ctx);
        goto after_4;
    // 0x800948B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800948B8: jal         0x800883E0
    // 0x800948BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcegg_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x800948BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800948C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800948C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800948C8: jal         0x80094348
    // 0x800948CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80094348(rdram, ctx);
        goto after_6;
    // 0x800948CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x800948D0: bnel        $v0, $zero, L_800948E4
    if (ctx->r2 != 0) {
        // 0x800948D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800948E4;
    }
    goto skip_2;
    // 0x800948D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x800948D8: jal         0x800D1824
    // 0x800948DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800D1824(rdram, ctx);
        goto after_7;
    // 0x800948DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x800948E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800948E4:
    // 0x800948E4: jal         0x80094348
    // 0x800948E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80094348(rdram, ctx);
        goto after_8;
    // 0x800948E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x800948EC: bnel        $v0, $zero, L_800949AC
    if (ctx->r2 != 0) {
        // 0x800948F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800949AC;
    }
    goto skip_3;
    // 0x800948F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800948F4: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x800948F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800948FC: lbu         $v0, 0x3($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X3);
    // 0x80094900: beq         $v0, $zero, L_80094920
    if (ctx->r2 == 0) {
        // 0x80094904: nop
    
            goto L_80094920;
    }
    // 0x80094904: nop

    // 0x80094908: beq         $v0, $at, L_80094958
    if (ctx->r2 == ctx->r1) {
        // 0x8009490C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80094958;
    }
    // 0x8009490C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80094910: beq         $v0, $at, L_80094988
    if (ctx->r2 == ctx->r1) {
        // 0x80094914: nop
    
            goto L_80094988;
    }
    // 0x80094914: nop

    // 0x80094918: b           L_800949AC
    // 0x8009491C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800949AC;
    // 0x8009491C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80094920:
    // 0x80094920: jal         0x80097C7C
    // 0x80094924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097C7C(rdram, ctx);
        goto after_9;
    // 0x80094924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80094928: beq         $v0, $zero, L_800949A8
    if (ctx->r2 == 0) {
        // 0x8009492C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800949A8;
    }
    // 0x8009492C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80094930: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80094934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094938: jal         0x80094510
    // 0x8009493C: sb          $t7, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r15;
    func_80094510(rdram, ctx);
        goto after_10;
    // 0x8009493C: sb          $t7, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r15;
    after_10:
    // 0x80094940: jal         0x80094E40
    // 0x80094944: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80094E40(rdram, ctx);
        goto after_11;
    // 0x80094944: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80094948: jal         0x80094C88
    // 0x8009494C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094C88(rdram, ctx);
        goto after_12;
    // 0x8009494C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80094950: b           L_800949AC
    // 0x80094954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800949AC;
    // 0x80094954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80094958:
    // 0x80094958: jal         0x80094824
    // 0x8009495C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094824(rdram, ctx);
        goto after_13;
    // 0x8009495C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80094960: jal         0x80094DA8
    // 0x80094964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094DA8(rdram, ctx);
        goto after_14;
    // 0x80094964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80094968: beq         $v0, $zero, L_800949A8
    if (ctx->r2 == 0) {
        // 0x8009496C: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_800949A8;
    }
    // 0x8009496C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80094970: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80094974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094978: jal         0x80094C88
    // 0x8009497C: sb          $t9, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r25;
    func_80094C88(rdram, ctx);
        goto after_15;
    // 0x8009497C: sb          $t9, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r25;
    after_15:
    // 0x80094980: b           L_800949AC
    // 0x80094984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800949AC;
    // 0x80094984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80094988:
    // 0x80094988: jal         0x80094824
    // 0x8009498C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094824(rdram, ctx);
        goto after_16;
    // 0x8009498C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80094990: jal         0x80094DA8
    // 0x80094994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094DA8(rdram, ctx);
        goto after_17;
    // 0x80094994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80094998: bnel        $v0, $zero, L_800949AC
    if (ctx->r2 != 0) {
        // 0x8009499C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800949AC;
    }
    goto skip_4;
    // 0x8009499C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800949A0: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x800949A4: sb          $zero, 0x3($t1)
    MEM_B(0X3, ctx->r9) = 0;
L_800949A8:
    // 0x800949A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800949AC:
    // 0x800949AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800949B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800949B4: jr          $ra
    // 0x800949B8: nop

    return;
    // 0x800949B8: nop

;}
RECOMP_FUNC void func_80090C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090C34: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80090C38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80090C3C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80090C40: lw          $a1, 0x2C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2C);
    // 0x80090C44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80090C48: lbu         $t6, 0x19($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X19);
    // 0x80090C4C: sb          $t6, 0x1A($a1)
    MEM_B(0X1A, ctx->r5) = ctx->r14;
    // 0x80090C50: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x80090C54: jal         0x8008E37C
    // 0x80090C58: sb          $zero, 0x19($t7)
    MEM_B(0X19, ctx->r15) = 0;
    func_8008E37C(rdram, ctx);
        goto after_0;
    // 0x80090C58: sb          $zero, 0x19($t7)
    MEM_B(0X19, ctx->r15) = 0;
    after_0:
    // 0x80090C5C: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80090C60: beq         $a1, $zero, L_80090C6C
    if (ctx->r5 == 0) {
        // 0x80090C64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80090C6C;
    }
    // 0x80090C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80090C68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80090C6C:
    // 0x80090C6C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80090C70: lbu         $t9, 0x18($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X18);
    // 0x80090C74: bnel        $t9, $zero, L_80090CC0
    if (ctx->r25 != 0) {
        // 0x80090C78: lw          $a1, 0x2C($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X2C);
            goto L_80090CC0;
    }
    goto skip_0;
    // 0x80090C78: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    skip_0:
    // 0x80090C7C: jal         0x8008E078
    // 0x80090C80: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    player_isStable(rdram, ctx);
        goto after_1;
    // 0x80090C80: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80090C84: bne         $v0, $zero, L_80090CBC
    if (ctx->r2 != 0) {
        // 0x80090C88: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80090CBC;
    }
    // 0x80090C88: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80090C8C: bnel        $a1, $zero, L_80090CC0
    if (ctx->r5 != 0) {
        // 0x80090C90: lw          $a1, 0x2C($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X2C);
            goto L_80090CC0;
    }
    goto skip_1;
    // 0x80090C90: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    skip_1:
    // 0x80090C94: jal         0x800F3ED0
    // 0x80090C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F3ED0(rdram, ctx);
        goto after_2;
    // 0x80090C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80090C9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80090CA0: beql        $v0, $at, L_80090CC0
    if (ctx->r2 == ctx->r1) {
        // 0x80090CA4: lw          $a1, 0x2C($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X2C);
            goto L_80090CC0;
    }
    goto skip_2;
    // 0x80090CA4: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    skip_2:
    // 0x80090CA8: jal         0x8009E6F8
    // 0x80090CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_3;
    // 0x80090CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80090CB0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80090CB4: bne         $v0, $at, L_80090CCC
    if (ctx->r2 != ctx->r1) {
        // 0x80090CB8: nop
    
            goto L_80090CCC;
    }
    // 0x80090CB8: nop

L_80090CBC:
    // 0x80090CBC: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
L_80090CC0:
    // 0x80090CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80090CC4: jal         0x8009C128
    // 0x80090CC8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_8009C128(rdram, ctx);
        goto after_4;
    // 0x80090CC8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_4:
L_80090CCC:
    // 0x80090CCC: jal         0x800F3ED0
    // 0x80090CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F3ED0(rdram, ctx);
        goto after_5;
    // 0x80090CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80090CD4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80090CD8: bne         $v0, $at, L_80090CF0
    if (ctx->r2 != ctx->r1) {
        // 0x80090CDC: nop
    
            goto L_80090CF0;
    }
    // 0x80090CDC: nop

    // 0x80090CE0: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x80090CE4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80090CE8: b           L_80090E10
    // 0x80090CEC: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
        goto L_80090E10;
    // 0x80090CEC: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
L_80090CF0:
    // 0x80090CF0: jal         0x8008E37C
    // 0x80090CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E37C(rdram, ctx);
        goto after_6;
    // 0x80090CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80090CF8: beq         $v0, $zero, L_80090D0C
    if (ctx->r2 == 0) {
        // 0x80090CFC: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80090D0C;
    }
    // 0x80090CFC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80090D00: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80090D04: b           L_80090D10
    // 0x80090D08: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
        goto L_80090D10;
    // 0x80090D08: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
L_80090D0C:
    // 0x80090D0C: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
L_80090D10:
    // 0x80090D10: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x80090D14: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80090D18: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    // 0x80090D1C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80090D20: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x80090D24: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80090D28: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80090D2C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80090D30: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x80090D34: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80090D38: addiu       $a0, $a1, 0xC
    ctx->r4 = ADD32(ctx->r5, 0XC);
    // 0x80090D3C: jal         0x800CCDF4
    // 0x80090D40: addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    func_800CCDF4(rdram, ctx);
        goto after_7;
    // 0x80090D40: addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    after_7:
    // 0x80090D44: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80090D48: beq         $v1, $zero, L_80090D5C
    if (ctx->r3 == 0) {
        // 0x80090D4C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80090D5C;
    }
    // 0x80090D4C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80090D50: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80090D54: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80090D58: sb          $t9, 0x19($t0)
    MEM_B(0X19, ctx->r8) = ctx->r25;
L_80090D5C:
    // 0x80090D5C: bne         $v1, $zero, L_80090DEC
    if (ctx->r3 != 0) {
        // 0x80090D60: nop
    
            goto L_80090DEC;
    }
    // 0x80090D60: nop

    // 0x80090D64: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x80090D68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80090D6C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80090D70: beq         $t2, $at, L_80090DEC
    if (ctx->r10 == ctx->r1) {
        // 0x80090D74: nop
    
            goto L_80090DEC;
    }
    // 0x80090D74: nop

    // 0x80090D78: jal         0x800A4CA8
    // 0x80090D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_8;
    // 0x80090D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80090D80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090D84: jal         0x801107F0
    // 0x80090D88: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_801107F0(rdram, ctx);
        goto after_9;
    // 0x80090D88: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_9:
    // 0x80090D8C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80090D90: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80090D94: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80090D98: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80090D9C: addiu       $a3, $zero, 0x384
    ctx->r7 = ADD32(0, 0X384);
    // 0x80090DA0: jal         0x800CCDF4
    // 0x80090DA4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800CCDF4(rdram, ctx);
        goto after_10;
    // 0x80090DA4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_10:
    // 0x80090DA8: beq         $v0, $zero, L_80090DEC
    if (ctx->r2 == 0) {
        // 0x80090DAC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80090DEC;
    }
    // 0x80090DAC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80090DB0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80090DB4: jal         0x800CBBC0
    // 0x80090DB8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_800CBBC0(rdram, ctx);
        goto after_11;
    // 0x80090DB8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_11:
    // 0x80090DBC: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x80090DC0: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80090DC4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80090DC8: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
    // 0x80090DCC: beql        $v0, $t4, L_80090DE0
    if (ctx->r2 == ctx->r12) {
        // 0x80090DD0: sw          $t5, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r13;
            goto L_80090DE0;
    }
    goto skip_3;
    // 0x80090DD0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    skip_3:
    // 0x80090DD4: b           L_80090DEC
    // 0x80090DD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80090DEC;
    // 0x80090DD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80090DDC: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_80090DE0:
    // 0x80090DE0: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80090DE4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80090DE8: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
L_80090DEC:
    // 0x80090DEC: beq         $a2, $zero, L_80090E08
    if (ctx->r6 == 0) {
        // 0x80090DF0: lw          $a1, 0x2C($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X2C);
            goto L_80090E08;
    }
    // 0x80090DF0: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x80090DF4: jal         0x800CBBC0
    // 0x80090DF8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_800CBBC0(rdram, ctx);
        goto after_12;
    // 0x80090DF8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_12:
    // 0x80090DFC: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80090E00: b           L_80090E10
    // 0x80090E04: sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
        goto L_80090E10;
    // 0x80090E04: sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
L_80090E08:
    // 0x80090E08: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80090E0C: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
L_80090E10:
    // 0x80090E10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80090E14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80090E18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80090E1C: jr          $ra
    // 0x80090E20: nop

    return;
    // 0x80090E20: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E40: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E40);
    return;
    // 0x80082E44: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void func_8080021C_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_8080021C_ncpoducam");
    // 0x8080021C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800220: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800224: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800228: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
    // 0x8080022C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800230: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80800234: beq         $t6, $zero, L_808002D8
    if (ctx->r14 == 0) {
        // 0x80800238: andi        $t1, $v0, 0x40
        ctx->r9 = ctx->r2 & 0X40;
            goto L_808002D8;
    }
    // 0x80800238: andi        $t1, $v0, 0x40
    ctx->r9 = ctx->r2 & 0X40;
    // 0x8080023C: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    // 0x80800240: jal         0x808001F0
    // 0x80800244: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    func_808001F0_ncpoducam(rdram, ctx);
        goto after_0;
    // 0x80800244: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    after_0:
    // 0x80800248: beq         $v0, $zero, L_808002D0
    if (ctx->r2 == 0) {
        // 0x8080024C: nop
    
            goto L_808002D0;
    }
    // 0x8080024C: nop

    // 0x80800250: jal         0x80106790
    // 0x80800254: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800254: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_1:
    // 0x80800258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080025C: jal         0x80103DFC
    // 0x80800260: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80103DFC(rdram, ctx);
        goto after_2;
    // 0x80800260: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x80800264: lh          $t7, 0x48($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X48);
    // 0x80800268: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8080026C: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x80800270: beq         $t8, $zero, L_808002C0
    if (ctx->r24 == 0) {
        // 0x80800274: nop
    
            goto L_808002C0;
    }
    // 0x80800274: nop

    // 0x80800278: lbu         $t9, 0x63($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X63);
    // 0x8080027C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800280: addiu       $a2, $s0, 0x3C
    ctx->r6 = ADD32(ctx->r16, 0X3C);
    // 0x80800284: beq         $t9, $zero, L_808002C0
    if (ctx->r25 == 0) {
        // 0x80800288: nop
    
            goto L_808002C0;
    }
    // 0x80800288: nop

    // 0x8080028C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800290: jal         0x800EFB24
    // 0x80800294: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x80800294: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800298: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x8080029C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808002A0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808002A4: jal         0x800EF334
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF334(rdram, ctx);
        goto after_4;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808002B0: jal         0x800EF04C
    // 0x808002B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808002B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x808002B8: b           L_80800394
    // 0x808002BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800394;
    // 0x808002BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002C0:
    // 0x808002C0: jal         0x800EE7F8
    // 0x808002C4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x808002C4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_6:
    // 0x808002C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808002CC: sb          $t0, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r8;
L_808002D0:
    // 0x808002D0: b           L_80800394
    // 0x808002D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800394;
    // 0x808002D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002D8:
    // 0x808002D8: beq         $t1, $zero, L_80800384
    if (ctx->r9 == 0) {
        // 0x808002DC: andi        $t6, $v0, 0x80
        ctx->r14 = ctx->r2 & 0X80;
            goto L_80800384;
    }
    // 0x808002DC: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x808002E0: jal         0x800F54E4
    // 0x808002E4: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x808002E4: nop

    after_7:
    // 0x808002E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002EC: jal         0x800F5BC4
    // 0x808002F0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5BC4(rdram, ctx);
        goto after_8;
    // 0x808002F0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_8:
    // 0x808002F4: jal         0x800F54E4
    // 0x808002F8: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x808002F8: nop

    after_9:
    // 0x808002FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800300: jal         0x800F5A00
    // 0x80800304: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800F5A00(rdram, ctx);
        goto after_10;
    // 0x80800304: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_10:
    // 0x80800308: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8080030C: jal         0x800EF04C
    // 0x80800310: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80800310: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_11:
    // 0x80800314: lh          $t2, 0x48($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X48);
    // 0x80800318: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8080031C: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x80800320: andi        $t3, $t2, 0x400
    ctx->r11 = ctx->r10 & 0X400;
    // 0x80800324: beq         $t3, $zero, L_80800374
    if (ctx->r11 == 0) {
        // 0x80800328: addiu       $a1, $sp, 0x54
        ctx->r5 = ADD32(ctx->r29, 0X54);
            goto L_80800374;
    }
    // 0x80800328: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8080032C: lbu         $t4, 0x63($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X63);
    // 0x80800330: addiu       $a2, $s0, 0x3C
    ctx->r6 = ADD32(ctx->r16, 0X3C);
    // 0x80800334: beq         $t4, $zero, L_80800374
    if (ctx->r12 == 0) {
        // 0x80800338: nop
    
            goto L_80800374;
    }
    // 0x80800338: nop

    // 0x8080033C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800340: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800344: jal         0x800EFB24
    // 0x80800348: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800EFB24(rdram, ctx);
        goto after_12;
    // 0x80800348: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_12:
    // 0x8080034C: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x80800350: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800354: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800358: jal         0x800EF334
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF334(rdram, ctx);
        goto after_13;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800360: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800364: jal         0x800EF04C
    // 0x80800368: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_14;
    // 0x80800368: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x8080036C: b           L_80800394
    // 0x80800370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800394;
    // 0x80800370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800374:
    // 0x80800374: jal         0x800EE7F8
    // 0x80800378: sb          $t5, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r13;
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x80800378: sb          $t5, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r13;
    after_15:
    // 0x8080037C: b           L_80800394
    // 0x80800380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800394;
    // 0x80800380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800384:
    // 0x80800384: beq         $t6, $zero, L_80800394
    if (ctx->r14 == 0) {
        // 0x80800388: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800394;
    }
    // 0x80800388: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080038C: b           L_80800394
    // 0x80800390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800394;
    // 0x80800390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800394:
    // 0x80800394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080039C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void func_80800774_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800774: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800778: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080077C: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800780: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800788: bne         $a1, $at, L_80800810
    if (ctx->r5 != ctx->r1) {
        // 0x8080078C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800810;
    }
    // 0x8080078C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800790: jal         0x80088840
    // 0x80800794: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80800794: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_0:
    // 0x80800798: beq         $v0, $zero, L_808007D0
    if (ctx->r2 == 0) {
        // 0x8080079C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808007D0;
    }
    // 0x8080079C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808007A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808007A4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808007A8: jal         0x80085708
    // 0x808007AC: addiu       $a3, $zero, 0x2910
    ctx->r7 = ADD32(0, 0X2910);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808007AC: addiu       $a3, $zero, 0x2910
    ctx->r7 = ADD32(0, 0X2910);
    after_1:
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B4: jal         0x80101FDC
    // 0x808007B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808007B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808007BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1000, 0X8FC) << 16);
    // 0x808007C0: lwc1        $f4, 0x8FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1000, 0X8FC));
    // 0x808007C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808007C8: b           L_80800814
    // 0x808007CC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800814;
    // 0x808007CC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808007D0:
    // 0x808007D0: jal         0x80088840
    // 0x808007D4: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x808007D4: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_3:
    // 0x808007D8: beq         $v0, $zero, L_80800810
    if (ctx->r2 == 0) {
        // 0x808007DC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800810;
    }
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808007E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808007E4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808007E8: jal         0x80085708
    // 0x808007EC: addiu       $a3, $zero, 0x2910
    ctx->r7 = ADD32(0, 0X2910);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x808007EC: addiu       $a3, $zero, 0x2910
    ctx->r7 = ADD32(0, 0X2910);
    after_4:
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F4: jal         0x80101FDC
    // 0x808007F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x808007F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x808007FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1000, 0X900) << 16);
    // 0x80800800: lwc1        $f6, 0x900($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1000, 0X900));
    // 0x80800804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800808: b           L_80800814
    // 0x8080080C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800814;
    // 0x8080080C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800810:
    // 0x80800810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800814:
    // 0x80800814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800818: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080081C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800820: jr          $ra
    // 0x80800824: nop

    return;
    // 0x80800824: nop

;}
RECOMP_FUNC void func_80013B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013B7C: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80013B80: nop

    // 0x80013B84: mul.s       $f0, $f14, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80013B88: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80013B8C: sqrt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = sqrtf(ctx->f0.fl);
    // 0x80013B90: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80013B94: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
    // 0x80013B98: c.eq.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl == ctx->f12.fl;
    // 0x80013B9C: bc1fl       L_80013BC8
    if (!c1cs) {
        // 0x80013BA0: c.eq.s      $f10, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl == ctx->f14.fl;
            goto L_80013BC8;
    }
    goto skip_0;
    // 0x80013BA0: c.eq.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl == ctx->f14.fl;
    skip_0:
    // 0x80013BA4: c.ole.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl <= ctx->f14.fl;
    // 0x80013BA8: bc1t        L_80013BBC
    if (c1cs) {
        // 0x80013BAC: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80013BBC;
    }
    // 0x80013BAC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80013BB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80013BB4: jr          $ra
    // 0x80013BB8: nop

    return;
    // 0x80013BB8: nop

L_80013BBC:
    // 0x80013BBC: jr          $ra
    // 0x80013BC0: mov.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = ctx->f10.fl;
    return;
    // 0x80013BC0: mov.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = ctx->f10.fl;
    // 0x80013BC4: c.eq.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl == ctx->f14.fl;
L_80013BC8:
    // 0x80013BC8: bc1fl       L_80013BFC
    if (!c1cs) {
        // 0x80013BCC: lui         $at, 0x3E34
        ctx->r1 = S32(0X3E34 << 16);
            goto L_80013BFC;
    }
    goto skip_1;
    // 0x80013BCC: lui         $at, 0x3E34
    ctx->r1 = S32(0X3E34 << 16);
    skip_1:
    // 0x80013BD0: c.olt.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80013BD4: bc1t        L_80013BE8
    if (c1cs) {
        // 0x80013BD8: lui         $at, 0x4387
        ctx->r1 = S32(0X4387 << 16);
            goto L_80013BE8;
    }
    // 0x80013BD8: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80013BDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80013BE0: jr          $ra
    // 0x80013BE4: nop

    return;
    // 0x80013BE4: nop

L_80013BE8:
    // 0x80013BE8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80013BEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80013BF0: jr          $ra
    // 0x80013BF4: nop

    return;
    // 0x80013BF4: nop

    // 0x80013BF8: lui         $at, 0x3E34
    ctx->r1 = S32(0X3E34 << 16);
L_80013BFC:
    // 0x80013BFC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80013C00: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
    // 0x80013C04: jal         0x80013ABC
    // 0x80013C08: div.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    func_80013ABC(rdram, ctx);
        goto after_0;
    // 0x80013C08: div.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    after_0:
    // 0x80013C0C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80013C10: or          $ra, $a3, $zero
    ctx->r31 = ctx->r7 | 0;
    // 0x80013C14: bc1f        L_80013C28
    if (!c1cs) {
        // 0x80013C18: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80013C28;
    }
    // 0x80013C18: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80013C1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80013C20: nop

    // 0x80013C24: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
L_80013C28:
    // 0x80013C28: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80013C2C: bc1f        L_80013C40
    if (!c1cs) {
        // 0x80013C30: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80013C40;
    }
    // 0x80013C30: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80013C34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80013C38: jr          $ra
    // 0x80013C3C: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    return;
    // 0x80013C3C: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
L_80013C40:
    // 0x80013C40: jr          $ra
    // 0x80013C44: nop

    return;
    // 0x80013C44: nop

;}
RECOMP_FUNC void _gccollectDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088018: syscall     666
    recomp_syscall_handler(rdram, ctx, 0x80088018);
    return;
    // 0x8008801C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void ncbafixpos_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808000A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B0: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x808000B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B8: lbu         $t7, 0x1A($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1A);
    // 0x808000BC: bnel        $t7, $zero, L_8080016C
    if (ctx->r15 != 0) {
        // 0x808000C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080016C;
    }
    goto skip_0;
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000C4: jal         0x801107F0
    // 0x808000C8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x808000C8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x808000CC: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x808000D0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808000D4: jal         0x800EE7F8
    // 0x808000D8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808000D8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_1:
    // 0x808000DC: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x808000E0: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x808000E4: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x808000E8: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x808000EC: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x808000F0: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x808000F4: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x808000F8: lbu         $t0, 0x18($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X18);
    // 0x808000FC: beq         $t0, $zero, L_80800110
    if (ctx->r8 == 0) {
        // 0x80800100: nop
    
            goto L_80800110;
    }
    // 0x80800100: nop

    // 0x80800104: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800108: b           L_8080011C
    // 0x8080010C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
        goto L_8080011C;
    // 0x8080010C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_80800110:
    // 0x80800110: jal         0x8080003C
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080003C_ncbafixpos(rdram, ctx);
        goto after_2;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800118: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
L_8080011C:
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x80111AE0
    // 0x80800124: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80111AE0(rdram, ctx);
        goto after_3;
    // 0x80800124: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80800128: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x8080012C: lbu         $t2, 0x19($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X19);
    // 0x80800130: beql        $t2, $zero, L_80800144
    if (ctx->r10 == 0) {
        // 0x80800134: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800144;
    }
    goto skip_1;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800138: jal         0x8011329C
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8011329C(rdram, ctx);
        goto after_4;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800144:
    // 0x80800144: jal         0x80112524
    // 0x80800148: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80112524(rdram, ctx);
        goto after_5;
    // 0x80800148: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800154: jal         0x80110A68
    // 0x80800158: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_80110A68(rdram, ctx);
        goto after_6;
    // 0x80800158: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_6:
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: jal         0x80110790
    // 0x80800164: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80110790(rdram, ctx);
        goto after_7;
    // 0x80800164: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080016C:
    // 0x8080016C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800170: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void func_800F1DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1DCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F1DD0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800F1DD4: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F1DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1DDC: jal         0x80013728
    // 0x800F1DE0: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    func_80013728(rdram, ctx);
        goto after_0;
    // 0x800F1DE0: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    after_0:
    // 0x800F1DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F1DEC: jr          $ra
    // 0x800F1DF0: nop

    return;
    // 0x800F1DF0: nop

;}
RECOMP_FUNC void func_80800830_chfactorylight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800830: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800834: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800838: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080083C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800844: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x80800848: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080084C: jal         0x800EE7F8
    // 0x80800850: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800850: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80800854: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800858: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080085C: jal         0x800EF1B8
    // 0x80800860: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800860: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_1:
    // 0x80800864: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800868: jal         0x800EE7F8
    // 0x8080086C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080086C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800870: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800874: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800878: jal         0x800EF1B8
    // 0x8080087C: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x8080087C: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    after_3:
    // 0x80800880: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800884: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800888: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8080088C: jal         0x800BEF00
    // 0x80800890: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_4;
    // 0x80800890: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_4:
    // 0x80800894: beq         $v0, $zero, L_808008D0
    if (ctx->r2 == 0) {
        // 0x80800898: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808008D0;
    }
    // 0x80800898: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080089C: jal         0x800EE7F8
    // 0x808008A0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808008A0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x808008A4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808008A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008AC: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808008B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008B4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808008B8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808008BC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808008C0: jal         0x800EF1B8
    // 0x808008C4: nop

    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x808008C4: nop

    after_6:
    // 0x808008C8: jal         0x80103014
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_7;
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_808008D0:
    // 0x808008D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808008D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808008DC: jr          $ra
    // 0x808008E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808008E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _bstaxi_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DE0: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083DE0);
    return;
    // 0x80083DE4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800DF8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF8C4: jr          $ra
    // 0x800DF8C8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    return;
    // 0x800DF8C8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
;}
RECOMP_FUNC void babee_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080026C: jr          $ra
    // 0x80800270: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800270: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void suquiz_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800658: jal         0x800DA298
    // 0x8080065C: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080065C: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_0:
    // 0x80800660: beq         $v0, $zero, L_80800678
    if (ctx->r2 == 0) {
        // 0x80800664: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800678;
    }
    // 0x80800664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800668: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8080066C: lw          $t6, 0x7614($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7614);
    // 0x80800670: b           L_8080067C
    // 0x80800674: lbu         $v0, 0x25($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X25);
        goto L_8080067C;
    // 0x80800674: lbu         $v0, 0x25($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X25);
L_80800678:
    // 0x80800678: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8080067C:
    // 0x8080067C: jr          $ra
    // 0x80800680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808002B0_chdinoswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002B4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808002B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808002C0: beq         $a1, $at, L_808002E4
    if (ctx->r5 == ctx->r1) {
        // 0x808002C4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_808002E4;
    }
    // 0x808002C4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808002C8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808002CC: beq         $a1, $at, L_80800308
    if (ctx->r5 == ctx->r1) {
        // 0x808002D0: addiu       $at, $zero, 0x99
        ctx->r1 = ADD32(0, 0X99);
            goto L_80800308;
    }
    // 0x808002D0: addiu       $at, $zero, 0x99
    ctx->r1 = ADD32(0, 0X99);
    // 0x808002D4: beq         $a1, $at, L_80800344
    if (ctx->r5 == ctx->r1) {
        // 0x808002D8: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_80800344;
    }
    // 0x808002D8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x808002DC: b           L_808003C4
    // 0x808002E0: nop

        goto L_808003C4;
    // 0x808002E0: nop

L_808002E4:
    // 0x808002E4: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x808002E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808002EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002F0: beq         $t6, $zero, L_808003D4
    if (ctx->r14 == 0) {
        // 0x808002F4: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_808003D4;
    }
    // 0x808002F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x808002F8: jal         0x8010114C
    // 0x808002FC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x808002FC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80800300: b           L_808003D8
    // 0x80800304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003D8;
    // 0x80800304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800308:
    // 0x80800308: lhu         $a2, 0x76($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X76);
    // 0x8080030C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800310: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800314: srl         $t8, $a2, 7
    ctx->r24 = S32(U32(ctx->r6) >> 7);
    // 0x80800318: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8080031C: jal         0x80089C70
    // 0x80800320: addiu       $a1, $zero, 0x364
    ctx->r5 = ADD32(0, 0X364);
    _subaddiefind_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800320: addiu       $a1, $zero, 0x364
    ctx->r5 = ADD32(0, 0X364);
    after_1:
    // 0x80800324: jal         0x80800270
    // 0x80800328: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800270_chdinoswitches(rdram, ctx);
        goto after_2;
    // 0x80800328: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8080032C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800330: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800334: jal         0x80085820
    // 0x80800338: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800338: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8080033C: b           L_808003DC
    // 0x80800340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003DC;
    // 0x80800340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800344:
    // 0x80800344: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80800348: sll         $t1, $t9, 10
    ctx->r9 = S32(ctx->r25 << 10);
    // 0x8080034C: bgez        $t1, L_8080035C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800350: nop
    
            goto L_8080035C;
    }
    // 0x80800350: nop

    // 0x80800354: b           L_80800368
    // 0x80800358: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
        goto L_80800368;
    // 0x80800358: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
L_8080035C:
    // 0x8080035C: jal         0x80800108
    // 0x80800360: nop

    func_80800108_chdinoswitches(rdram, ctx);
        goto after_4;
    // 0x80800360: nop

    after_4:
    // 0x80800364: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800368:
    // 0x80800368: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8080036C: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80800370: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800374: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1048, 0XB28) << 16);
    // 0x80800378: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8080037C: lhu         $v0, 0xB28($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(1048, 0XB28));
    // 0x80800380: addiu       $at, $zero, 0x7B8
    ctx->r1 = ADD32(0, 0X7B8);
    // 0x80800384: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800388: beq         $v0, $at, L_808003A0
    if (ctx->r2 == ctx->r1) {
        // 0x8080038C: addiu       $at, $zero, 0x7B9
        ctx->r1 = ADD32(0, 0X7B9);
            goto L_808003A0;
    }
    // 0x8080038C: addiu       $at, $zero, 0x7B9
    ctx->r1 = ADD32(0, 0X7B9);
    // 0x80800390: beq         $v0, $at, L_808003A0
    if (ctx->r2 == ctx->r1) {
        // 0x80800394: addiu       $at, $zero, 0x942
        ctx->r1 = ADD32(0, 0X942);
            goto L_808003A0;
    }
    // 0x80800394: addiu       $at, $zero, 0x942
    ctx->r1 = ADD32(0, 0X942);
    // 0x80800398: bne         $v0, $at, L_808003B0
    if (ctx->r2 != ctx->r1) {
        // 0x8080039C: nop
    
            goto L_808003B0;
    }
    // 0x8080039C: nop

L_808003A0:
    // 0x808003A0: jal         0x80101074
    // 0x808003A4: addiu       $a0, $a0, -0x5D90
    ctx->r4 = ADD32(ctx->r4, -0X5D90);
    func_80101074(rdram, ctx);
        goto after_5;
    // 0x808003A4: addiu       $a0, $a0, -0x5D90
    ctx->r4 = ADD32(ctx->r4, -0X5D90);
    after_5:
    // 0x808003A8: b           L_808003D8
    // 0x808003AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003D8;
    // 0x808003AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003B0:
    // 0x808003B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x808003B4: jal         0x80101074
    // 0x808003B8: addiu       $a0, $a0, -0x5DB8
    ctx->r4 = ADD32(ctx->r4, -0X5DB8);
    func_80101074(rdram, ctx);
        goto after_6;
    // 0x808003B8: addiu       $a0, $a0, -0x5DB8
    ctx->r4 = ADD32(ctx->r4, -0X5DB8);
    after_6:
    // 0x808003BC: b           L_808003D8
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003D8;
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C4:
    // 0x808003C4: jal         0x80085820
    // 0x808003C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x808003C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_7:
    // 0x808003CC: b           L_808003DC
    // 0x808003D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003DC;
    // 0x808003D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003D4:
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003D8:
    // 0x808003D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003DC:
    // 0x808003DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003E0: jr          $ra
    // 0x808003E4: nop

    return;
    // 0x808003E4: nop

;}
RECOMP_FUNC void func_80108C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108C14: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80108C18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80108C1C: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x80108C20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80108C24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80108C28: jal         0x801067C4
    // 0x80108C2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x80108C2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80108C30: beq         $v0, $zero, L_80108C7C
    if (ctx->r2 == 0) {
        // 0x80108C34: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80108C7C;
    }
    // 0x80108C34: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80108C38:
    // 0x80108C38: jal         0x80100368
    // 0x80108C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100368(rdram, ctx);
        goto after_1;
    // 0x80108C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80108C40: lhu         $t6, 0x20($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X20);
    // 0x80108C44: beq         $t6, $zero, L_80108C6C
    if (ctx->r14 == 0) {
        // 0x80108C48: nop
    
            goto L_80108C6C;
    }
    // 0x80108C48: nop

    // 0x80108C4C: jal         0x800DA298
    // 0x80108C50: andi        $a0, $t6, 0xFFFF
    ctx->r4 = ctx->r14 & 0XFFFF;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80108C50: andi        $a0, $t6, 0xFFFF
    ctx->r4 = ctx->r14 & 0XFFFF;
    after_2:
    // 0x80108C54: beq         $v0, $zero, L_80108C6C
    if (ctx->r2 == 0) {
        // 0x80108C58: nop
    
            goto L_80108C6C;
    }
    // 0x80108C58: nop

    // 0x80108C5C: jal         0x800FFAB0
    // 0x80108C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80108C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80108C64: jal         0x800819B4
    // 0x80108C68: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    func_800819B4(rdram, ctx);
        goto after_4;
    // 0x80108C68: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_4:
L_80108C6C:
    // 0x80108C6C: jal         0x8010682C
    // 0x80108C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010682C(rdram, ctx);
        goto after_5;
    // 0x80108C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80108C74: bne         $v0, $zero, L_80108C38
    if (ctx->r2 != 0) {
        // 0x80108C78: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80108C38;
    }
    // 0x80108C78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80108C7C:
    // 0x80108C7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80108C80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80108C84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80108C88: jr          $ra
    // 0x80108C8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80108C8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80802BC8_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802BC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802BCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4514) << 16);
    // 0x80802BD0: lwc1        $f4, 0x4514($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4514));
    // 0x80802BD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802BD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80802BDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802BE0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80802BE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802BE8: jal         0x80100094
    // 0x80802BEC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802BEC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80802BF0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80802BF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802BF8: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802BFC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80802C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C04: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802C08: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80802C0C: jal         0x80105A9C
    // 0x80802C10: nop

    func_80105A9C(rdram, ctx);
        goto after_1;
    // 0x80802C10: nop

    after_1:
    // 0x80802C14: jal         0x80105834
    // 0x80802C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_2;
    // 0x80802C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802C1C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802C20: jal         0x800F1DCC
    // 0x80802C24: lwc1        $f14, 0x4($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X4);
    func_800F1DCC(rdram, ctx);
        goto after_3;
    // 0x80802C24: lwc1        $f14, 0x4($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X4);
    after_3:
    // 0x80802C28: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802C2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80802C30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802C34: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80802C38: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80802C3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4518) << 16);
    // 0x80802C40: lwc1        $f10, 0x4518($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4518));
    // 0x80802C44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802C48: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80802C4C: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80802C50: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80802C54: swc1        $f16, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f16.u32l;
    // 0x80802C58: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80802C5C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802C60: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x80802C64: lbu         $t6, 0xE($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XE);
    // 0x80802C68: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x80802C6C: bne         $t6, $zero, L_80802C84
    if (ctx->r14 != 0) {
        // 0x80802C70: nop
    
            goto L_80802C84;
    }
    // 0x80802C70: nop

    // 0x80802C74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802C78: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80802C7C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80802C80: sb          $t7, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r15;
L_80802C84:
    // 0x80802C84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X451C) << 16);
    // 0x80802C88: lwc1        $f10, 0x451C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X451C));
    // 0x80802C8C: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80802C90: lwc1        $f14, 0x44($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80802C94: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80802C98: jal         0x800F1DCC
    // 0x80802C9C: nop

    func_800F1DCC(rdram, ctx);
        goto after_4;
    // 0x80802C9C: nop

    after_4:
    // 0x80802CA0: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80802CA4: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80802CA8: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80802CAC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80802CB0: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802CB4: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80802CB8: jal         0x800F1DCC
    // 0x80802CBC: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x80802CBC: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x80802CC0: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80802CC4: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802CC8: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80802CCC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80802CD0: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x80802CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802CD8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80802CDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80802CE0: jr          $ra
    // 0x80802CE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80802CE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808000A4_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808000B0: jal         0x800B5BE4
    // 0x808000B4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x808000B4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_0:
    // 0x808000B8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808000BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808000C0: jal         0x8009C128
    // 0x808000C4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x808000C4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808000C8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808000CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000D0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808000D4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(76, 0XDE8) << 16);
    // 0x808000D8: addiu       $t6, $t6, 0xDE8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(76, 0XDE8));
    // 0x808000DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000E8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808000EC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x808000F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000F4: jal         0x800BABB8
    // 0x808000F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808000F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x808000FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_80800000_chlavaarchgrillswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800004: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800008: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8080000C: jr          $ra
    // 0x80800010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80800BB4_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800BB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BBC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1932, 0X1100) << 16);
    // 0x80800BC0: addiu       $a2, $a2, 0x1100
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1932, 0X1100));
    // 0x80800BC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800BC8: jal         0x8008A1E8
    // 0x80800BCC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800BCC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800BD0: beq         $v0, $zero, L_80800C04
    if (ctx->r2 == 0) {
        // 0x80800BD4: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80800C04;
    }
    // 0x80800BD4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800BD8: addiu       $at, $zero, 0x1208
    ctx->r1 = ADD32(0, 0X1208);
    // 0x80800BDC: beq         $v0, $at, L_80800C04
    if (ctx->r2 == ctx->r1) {
        // 0x80800BE0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800C04;
    }
    // 0x80800BE0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BE4: jal         0x80100094
    // 0x80800BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800BEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BF0: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    // 0x80800BF4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800BF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800BFC: jal         0x8008A2C8
    // 0x80800C00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800C00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
L_80800C04:
    // 0x80800C04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C08: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800C0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C10: jr          $ra
    // 0x80800C14: nop

    return;
    // 0x80800C14: nop

;}
RECOMP_FUNC void ncpod_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D7C: jal         0x800895D0
    // 0x80800D80: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    _ncpoddialog_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800D80: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    after_0:
    // 0x80800D84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D88: jal         0x80089608
    // 0x80800D8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _ncpoddialog_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800D8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D98: jr          $ra
    // 0x80800D9C: nop

    return;
    // 0x80800D9C: nop

;}
RECOMP_FUNC void func_80026100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026100: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80026104: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80026108: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x8002610C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80026110: lbu         $t7, 0x36($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X36);
    // 0x80026114: blez        $t7, L_80026178
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80026118: nop
    
            goto L_80026178;
    }
    // 0x80026118: nop

L_8002611C:
    // 0x8002611C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80026120: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x80026124: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80026128: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8002612C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80026130: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80026134: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80026138: sb          $t8, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r24;
    // 0x8002613C: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80026140: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80026144: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80026148: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8002614C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80026150: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80026154: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80026158: sb          $t3, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r11;
    // 0x8002615C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80026160: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x80026164: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80026168: lbu         $t1, 0x36($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X36);
    // 0x8002616C: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80026170: bne         $at, $zero, L_8002611C
    if (ctx->r1 != 0) {
        // 0x80026174: nop
    
            goto L_8002611C;
    }
    // 0x80026174: nop

L_80026178:
    // 0x80026178: b           L_80026180
    // 0x8002617C: nop

        goto L_80026180;
    // 0x8002617C: nop

L_80026180:
    // 0x80026180: jr          $ra
    // 0x80026184: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80026184: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_808009BC_chfactorycrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009C0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808009C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009C8: bne         $a1, $at, L_80800A00
    if (ctx->r5 != ctx->r1) {
        // 0x808009CC: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80800A00;
    }
    // 0x808009CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808009D0: jal         0x80086B58
    // 0x808009D4: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808009D4: nop

    after_0:
    // 0x808009D8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808009DC: addiu       $t6, $zero, 0xA3
    ctx->r14 = ADD32(0, 0XA3);
    // 0x808009E0: addiu       $a1, $zero, 0x1340
    ctx->r5 = ADD32(0, 0X1340);
    // 0x808009E4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808009E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808009F0: jal         0x8008A208
    // 0x808009F4: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808009F4: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x808009F8: b           L_80800A08
    // 0x808009FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A08;
    // 0x808009FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A00:
    // 0x80800A00: jal         0x80085820
    // 0x80800A04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800A04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
L_80800A08:
    // 0x80800A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A10: jr          $ra
    // 0x80800A14: nop

    return;
    // 0x80800A14: nop

    // 0x80800A18: nop

    // 0x80800A1C: nop

;}
RECOMP_FUNC void func_80800008_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: jal         0x80091A58
    // 0x8080001C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80800020: beq         $v0, $zero, L_80800054
    if (ctx->r2 == 0) {
        // 0x80800024: nop
    
            goto L_80800054;
    }
    // 0x80800024: nop

    // 0x80800028: jal         0x80800C10
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bafpctrl_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800030: beq         $v0, $zero, L_80800054
    if (ctx->r2 == 0) {
        // 0x80800034: nop
    
            goto L_80800054;
    }
    // 0x80800034: nop

    // 0x80800038: lw          $t6, 0x90($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X90);
    // 0x8080003C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800040: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80800044: bne         $t8, $zero, L_80800054
    if (ctx->r24 != 0) {
        // 0x80800048: nop
    
            goto L_80800054;
    }
    // 0x80800048: nop

    // 0x8080004C: b           L_808000C8
    // 0x80800050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C8;
    // 0x80800050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800054:
    // 0x80800054: jal         0x8008E35C
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_2;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080005C: beq         $v0, $zero, L_80800090
    if (ctx->r2 == 0) {
        // 0x80800060: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800090;
    }
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: jal         0x8008FD48
    // 0x80800068: nop

    func_8008FD48(rdram, ctx);
        goto after_3;
    // 0x80800068: nop

    after_3:
    // 0x8080006C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800070: bnel        $v0, $at, L_808000C8
    if (ctx->r2 != ctx->r1) {
        // 0x80800074: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000C8;
    }
    goto skip_0;
    // 0x80800074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800078: jal         0x8008FF94
    // 0x8080007C: nop

    func_8008FF94(rdram, ctx);
        goto after_4;
    // 0x8080007C: nop

    after_4:
    // 0x80800080: bnel        $v0, $zero, L_808000C8
    if (ctx->r2 != 0) {
        // 0x80800084: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000C8;
    }
    goto skip_1;
    // 0x80800084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80800088: b           L_808000C8
    // 0x8080008C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C8;
    // 0x8080008C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800090:
    // 0x80800090: jal         0x8008DF8C
    // 0x80800094: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_8008DF8C(rdram, ctx);
        goto after_5;
    // 0x80800094: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_5:
    // 0x80800098: bnel        $v0, $zero, L_808000C8
    if (ctx->r2 != 0) {
        // 0x8080009C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000C8;
    }
    goto skip_2;
    // 0x8080009C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x808000A0: jal         0x80800BF0
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bafpctrl_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000AC: beq         $v0, $at, L_808000BC
    if (ctx->r2 == ctx->r1) {
        // 0x808000B0: nop
    
            goto L_808000BC;
    }
    // 0x808000B0: nop

    // 0x808000B4: b           L_808000C8
    // 0x808000B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000C8;
    // 0x808000B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000BC:
    // 0x808000BC: b           L_808000C8
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C8;
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000C8:
    // 0x808000C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void func_80800818_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080081C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800820: jal         0x80800000
    // 0x80800824: nop

    func_80800000_bskazpaddle(rdram, ctx);
        goto after_0;
    // 0x80800824: nop

    after_0:
    // 0x80800828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080082C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800830: jr          $ra
    // 0x80800834: nop

    return;
    // 0x80800834: nop

;}
RECOMP_FUNC void func_80800448_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080044C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800450: jal         0x80800000
    // 0x80800454: nop

    func_80800000_bskazpaddle(rdram, ctx);
        goto after_0;
    // 0x80800454: nop

    after_0:
    // 0x80800458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080045C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800460: jr          $ra
    // 0x80800464: nop

    return;
    // 0x80800464: nop

;}
RECOMP_FUNC void func_80802640_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802640: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802648: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080264C: jal         0x80106790
    // 0x80802650: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802650: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802654: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802658: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8080265C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80802660: beql        $a1, $t6, L_808026BC
    if (ctx->r5 == ctx->r14) {
        // 0x80802664: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808026BC;
    }
    goto skip_0;
    // 0x80802664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802668: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x8080266C: beq         $t7, $zero, L_8080268C
    if (ctx->r15 == 0) {
        // 0x80802670: nop
    
            goto L_8080268C;
    }
    // 0x80802670: nop

    // 0x80802674: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80802678: jal         0x80088728
    // 0x8080267C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080267C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802680: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80802684: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802688: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
L_8080268C:
    // 0x8080268C: beq         $a1, $zero, L_808026A8
    if (ctx->r5 == 0) {
        // 0x80802690: sw          $a1, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->r5;
            goto L_808026A8;
    }
    // 0x80802690: sw          $a1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r5;
    // 0x80802694: lw          $a0, 0x30($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X30);
    // 0x80802698: jal         0x80088718
    // 0x8080269C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080269C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x808026A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808026A4: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
L_808026A8:
    // 0x808026A8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808026AC: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x808026B0: jal         0x80087BE0
    // 0x808026B4: lw          $a0, 0x28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X28);
    _gczoombox_entrypoint_32(rdram, ctx);
        goto after_3;
    // 0x808026B4: lw          $a0, 0x28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X28);
    after_3:
    // 0x808026B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808026BC:
    // 0x808026BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808026C0: jr          $ra
    // 0x808026C4: nop

    return;
    // 0x808026C4: nop

;}
RECOMP_FUNC void subaddiefind_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8080014C: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80800150: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800154: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800158: addiu       $s7, $sp, 0x48
    ctx->r23 = ADD32(ctx->r29, 0X48);
    // 0x8080015C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800160: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80800164: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800168: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080016C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800170: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3186, 0X9F0) << 16);
    // 0x80800174: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800178: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8080017C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800180: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800184: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800188: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8080018C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80800190: lwc1        $f20, 0x9F0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3186, 0X9F0));
    // 0x80800194: jal         0x801067C4
    // 0x80800198: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x80800198: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x8080019C: beq         $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x808001A0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8080023C;
    }
    // 0x808001A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001A4: addiu       $s4, $zero, 0x243
    ctx->r20 = ADD32(0, 0X243);
    // 0x808001A8: addiu       $s3, $zero, 0x215
    ctx->r19 = ADD32(0, 0X215);
L_808001AC:
    // 0x808001AC: lw          $v1, 0x6C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6C);
    // 0x808001B0: sll         $t6, $v1, 11
    ctx->r14 = S32(ctx->r3 << 11);
    // 0x808001B4: srl         $v1, $t6, 20
    ctx->r3 = S32(U32(ctx->r14) >> 20);
    // 0x808001B8: beql        $s1, $v1, L_808001CC
    if (ctx->r17 == ctx->r3) {
        // 0x808001BC: lhu         $t8, 0x72($v0)
        ctx->r24 = MEM_HU(ctx->r2, 0X72);
            goto L_808001CC;
    }
    goto skip_0;
    // 0x808001BC: lhu         $t8, 0x72($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X72);
    skip_0:
    // 0x808001C0: bgez        $s1, L_8080022C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x808001C4: nop
    
            goto L_8080022C;
    }
    // 0x808001C4: nop

    // 0x808001C8: lhu         $t8, 0x72($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X72);
L_808001CC:
    // 0x808001CC: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808001D0: beq         $s6, $t9, L_8080022C
    if (ctx->r22 == ctx->r25) {
        // 0x808001D4: nop
    
            goto L_8080022C;
    }
    // 0x808001D4: nop

    // 0x808001D8: beq         $s3, $v1, L_8080022C
    if (ctx->r19 == ctx->r3) {
        // 0x808001DC: nop
    
            goto L_8080022C;
    }
    // 0x808001DC: nop

    // 0x808001E0: beq         $s4, $v1, L_8080022C
    if (ctx->r20 == ctx->r3) {
        // 0x808001E4: nop
    
            goto L_8080022C;
    }
    // 0x808001E4: nop

    // 0x808001E8: lw          $t0, 0x64($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X64);
    // 0x808001EC: sll         $t2, $t0, 14
    ctx->r10 = S32(ctx->r8 << 14);
    // 0x808001F0: bltz        $t2, L_8080022C
    if (SIGNED(ctx->r10) < 0) {
        // 0x808001F4: nop
    
            goto L_8080022C;
    }
    // 0x808001F4: nop

    // 0x808001F8: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x808001FC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80800200: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x80800204: beq         $t3, $t4, L_8080022C
    if (ctx->r11 == ctx->r12) {
        // 0x80800208: nop
    
            goto L_8080022C;
    }
    // 0x80800208: nop

    // 0x8080020C: jal         0x800EEAD4
    // 0x80800210: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EEAD4(rdram, ctx);
        goto after_1;
    // 0x80800210: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800214: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800218: nop

    // 0x8080021C: bc1f        L_8080022C
    if (!c1cs) {
        // 0x80800220: nop
    
            goto L_8080022C;
    }
    // 0x80800220: nop

    // 0x80800224: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800228: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
L_8080022C:
    // 0x8080022C: jal         0x8010682C
    // 0x80800230: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_8010682C(rdram, ctx);
        goto after_2;
    // 0x80800230: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_2:
    // 0x80800234: bne         $v0, $zero, L_808001AC
    if (ctx->r2 != 0) {
        // 0x80800238: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808001AC;
    }
    // 0x80800238: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8080023C:
    // 0x8080023C: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80800240: beql        $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x80800244: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80800250;
    }
    goto skip_1;
    // 0x80800244: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x80800248: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x8080024C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800250:
    // 0x80800250: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80800254: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800258: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8080025C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800260: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800264: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800268: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8080026C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800270: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80800274: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80800278: jr          $ra
    // 0x8080027C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8080027C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800A2C_chlavagargoyle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800A2C_chlavagargoyle");
    // 0x80800A2C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A34: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800A38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A40: beq         $a1, $at, L_80800A68
    if (ctx->r5 == ctx->r1) {
        // 0x80800A44: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80800A68;
    }
    // 0x80800A44: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800A48: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800A4C: beq         $a1, $at, L_80800A9C
    if (ctx->r5 == ctx->r1) {
        // 0x80800A50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A9C;
    }
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A54: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800A58: beql        $a1, $at, L_80800AB4
    if (ctx->r5 == ctx->r1) {
        // 0x80800A5C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800AB4;
    }
    goto skip_0;
    // 0x80800A5C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x80800A60: b           L_80800B78
    // 0x80800A64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B78;
    // 0x80800A64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A68:
    // 0x80800A68: jal         0x800F54E4
    // 0x80800A6C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800A6C: nop

    after_0:
    // 0x80800A70: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x80800A74: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800A78: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800A7C: jal         0x800F5A00
    // 0x80800A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80800A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800A84: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A8C: jal         0x80800B8C
    // 0x80800A90: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80800B8C_chlavagargoyle(rdram, ctx);
        goto after_2;
    // 0x80800A90: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800A94: b           L_80800B78
    // 0x80800A98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B78;
    // 0x80800A98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A9C:
    // 0x80800A9C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800AA0: jal         0x80800B8C
    // 0x80800AA4: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_80800B8C_chlavagargoyle(rdram, ctx);
        goto after_3;
    // 0x80800AA4: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_3:
    // 0x80800AA8: b           L_80800B78
    // 0x80800AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B78;
    // 0x80800AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800AB0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800AB4:
    // 0x80800AB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800AB8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800ABC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800AC0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800AC4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800AC8: jal         0x800DC178
    // 0x80800ACC: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800ACC: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x80800AD0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800AD4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800AD8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800ADC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800AE0: jal         0x800DC178
    // 0x80800AE4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800AE4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_5:
    // 0x80800AE8: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800AEC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800AF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800AF4: jal         0x800EE7F8
    // 0x80800AF8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800AF8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_6:
    // 0x80800AFC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B04: jal         0x80103EAC
    // 0x80800B08: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    func_80103EAC(rdram, ctx);
        goto after_7;
    // 0x80800B08: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_7:
    // 0x80800B0C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800B10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800B1C: jal         0x80103EAC
    // 0x80800B20: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    func_80103EAC(rdram, ctx);
        goto after_8;
    // 0x80800B20: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x80800B24: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800B28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B2C: nop

    // 0x80800B30: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800B34: jal         0x800C8A98
    // 0x80800B38: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    func_800C8A98(rdram, ctx);
        goto after_9;
    // 0x80800B38: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x80800B3C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80800B40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B44: jal         0x800C8F64
    // 0x80800B48: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C8F64(rdram, ctx);
        goto after_10;
    // 0x80800B48: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800B4C: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80800B50: jal         0x800C8D4C
    // 0x80800B54: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800C8D4C(rdram, ctx);
        goto after_11;
    // 0x80800B54: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_11:
    // 0x80800B58: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80800B5C: jal         0x800C8FE0
    // 0x80800B60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_12;
    // 0x80800B60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800B64: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80800B68: jal         0x800C8CB8
    // 0x80800B6C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800C8CB8(rdram, ctx);
        goto after_13;
    // 0x80800B6C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x80800B70: b           L_80800B78
    // 0x80800B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B78;
    // 0x80800B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B78:
    // 0x80800B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800B84: jr          $ra
    // 0x80800B88: nop

    return;
    // 0x80800B88: nop

;}
RECOMP_FUNC void _bawandglow_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853D0: syscall     160
    recomp_syscall_handler(rdram, ctx, 0x800853D0);
    return;
    // 0x800853D4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800548_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800548: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080054C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800550: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800554: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800558: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080055C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80800560: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800564: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800568: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080056C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800570: jal         0x800D1000
    // 0x80800574: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800D1000(rdram, ctx);
        goto after_0;
    // 0x80800574: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800578: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080057C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800580: jal         0x80086670
    // 0x80800584: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800584: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_1:
    // 0x80800588: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1052, 0X7D0) << 16);
    // 0x8080058C: addiu       $t6, $t6, 0x7D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1052, 0X7D0));
    // 0x80800590: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800594: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800598: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808005A4: jal         0x800BBCB8
    // 0x808005A8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x808005A8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_2:
    // 0x808005AC: jal         0x800DA544
    // 0x808005B0: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x808005B0: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_3:
    // 0x808005B4: jal         0x800FFAB0
    // 0x808005B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x808005B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x808005BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005C8: jr          $ra
    // 0x808005CC: nop

    return;
    // 0x808005CC: nop

;}
RECOMP_FUNC void func_80803150_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803150: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803158: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080315C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803160: jal         0x80100094
    // 0x80803164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803168: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080316C: jal         0x8080149C
    // 0x80803170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080149C_chflysaucer(rdram, ctx);
        goto after_1;
    // 0x80803170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80803174: jal         0x80801534
    // 0x80803178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801534_chflysaucer(rdram, ctx);
        goto after_2;
    // 0x80803178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080317C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80803180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803184: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80803188: bltzl       $t8, L_8080319C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080318C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080319C;
    }
    goto skip_0;
    // 0x8080318C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80803190: jal         0x808009DC
    // 0x80803194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808009DC_chflysaucer(rdram, ctx);
        goto after_3;
    // 0x80803194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80803198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080319C:
    // 0x8080319C: jal         0x808012A4
    // 0x808031A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_4;
    // 0x808031A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808031A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808031AC: jal         0x808021C0
    // 0x808031B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_808021C0_chflysaucer(rdram, ctx);
        goto after_5;
    // 0x808031B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x808031B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808031B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808031BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808031C0: jr          $ra
    // 0x808031C4: nop

    return;
    // 0x808031C4: nop

;}
RECOMP_FUNC void bskazshoessuckspline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x80084FE0
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800018: bne         $v0, $at, L_80800088
    if (ctx->r2 != ctx->r1) {
        // 0x8080001C: nop
    
            goto L_80800088;
    }
    // 0x8080001C: nop

    // 0x80800020: jal         0x8009E6EC
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_1;
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800028: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x8080002C: bne         $v0, $at, L_80800088
    if (ctx->r2 != ctx->r1) {
        // 0x80800030: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800088;
    }
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: jal         0x80095738
    // 0x80800038: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x80800038: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_2:
    // 0x8080003C: bne         $v0, $zero, L_80800090
    if (ctx->r2 != 0) {
        // 0x80800040: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800090;
    }
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: jal         0x80099A7C
    // 0x80800048: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80099A7C(rdram, ctx);
        goto after_3;
    // 0x80800048: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: jal         0x800850A8
    // 0x80800054: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _bashoessuck_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800054: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800058: beq         $v0, $zero, L_80800090
    if (ctx->r2 == 0) {
        // 0x8080005C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800090;
    }
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: jal         0x80095760
    // 0x80800064: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    baflag_set(rdram, ctx);
        goto after_5;
    // 0x80800064: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_5:
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: jal         0x8009E5C8
    // 0x80800070: addiu       $a1, $zero, 0x188
    ctx->r5 = ADD32(0, 0X188);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x80800070: addiu       $a1, $zero, 0x188
    ctx->r5 = ADD32(0, 0X188);
    after_6:
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: jal         0x8009E830
    // 0x8080007C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_7;
    // 0x8080007C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800080: b           L_80800094
    // 0x80800084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800094;
    // 0x80800084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800088:
    // 0x80800088: jal         0x80099B94
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_8;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800090:
    // 0x80800090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800094:
    // 0x80800094: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800098: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void _sumultiscore_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089990: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x80089990);
    return;
    // 0x80089994: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80802438_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802438: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x8080243C: jr          $ra
    // 0x80802440: sw          $a1, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r5;
    return;
    // 0x80802440: sw          $a1, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void _idbounce_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C98: syscall     733
    recomp_syscall_handler(rdram, ctx, 0x80088C98);
    return;
    // 0x80088C9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void fxdialog_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800190: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80800194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800198: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080019C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808001A0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808001A4: beq         $t6, $zero, L_808001BC
    if (ctx->r14 == 0) {
        // 0x808001A8: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_808001BC;
    }
    // 0x808001A8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808001AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2858, 0X2A0) << 16);
    // 0x808001B0: lwc1        $f0, 0x2A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2858, 0X2A0));
    // 0x808001B4: b           L_808001C8
    // 0x808001B8: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
        goto L_808001C8;
    // 0x808001B8: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
L_808001BC:
    // 0x808001BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2858, 0X2A0) << 16);
    // 0x808001C0: lwc1        $f0, 0x2A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2858, 0X2A0));
    // 0x808001C4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_808001C8:
    // 0x808001C8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x808001CC: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x808001D0: jal         0x800E2554
    // 0x808001D4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_800E2554(rdram, ctx);
        goto after_0;
    // 0x808001D4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x808001D8: jal         0x800E257C
    // 0x808001DC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800E257C(rdram, ctx);
        goto after_1;
    // 0x808001DC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x808001E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808001E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808001E8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808001EC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2858, 0X290) << 16);
    // 0x808001F0: addiu       $v0, $v0, 0x290
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2858, 0X290));
    // 0x808001F4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808001F8: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x808001FC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800200: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800204: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800208: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x8080020C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800210: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80800214: nop

    // 0x80800218: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8080021C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800220: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80800224: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800228: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8080022C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80800230: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80800234: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80800238: nop

    // 0x8080023C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80800240: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800244: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80800248: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080024C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80800250: jal         0x800D674C
    // 0x80800254: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x80800254: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_2:
    // 0x80800258: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080025C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800260: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800264: jal         0x800E30E0
    // 0x80800268: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_800E30E0(rdram, ctx);
        goto after_3;
    // 0x80800268: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x8080026C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800270: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800274: jr          $ra
    // 0x80800278: nop

    return;
    // 0x80800278: nop

    // 0x8080027C: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C20: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C20);
    return;
    // 0x80082C24: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void subaddieaudioloop_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800094: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80800098: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8080009C: beq         $t6, $zero, L_808000B0
    if (ctx->r14 == 0) {
        // 0x808000A0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808000B0;
    }
    // 0x808000A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A4: jal         0x800C2FDC
    // 0x808000A8: nop

    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x808000A8: nop

    after_0:
    // 0x808000AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_808000B0:
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void func_80800000_chmolehill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800010: jal         0x8010CAC0
    // 0x80800014: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    func_8010CAC0(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    after_0:
    // 0x80800018: beq         $v0, $zero, L_80800028
    if (ctx->r2 == 0) {
        // 0x8080001C: nop
    
            goto L_80800028;
    }
    // 0x8080001C: nop

    // 0x80800020: b           L_80800078
    // 0x80800024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800078;
    // 0x80800024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800028:
    // 0x80800028: jal         0x8010CD28
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010CD28(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800030: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080003C: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80800040: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800044: jal         0x800F1DCC
    // 0x80800048: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x80800048: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_2:
    // 0x8080004C: jal         0x800F2100
    // 0x80800050: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x80800050: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80800054: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800058: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080005C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800060: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800064: nop

    // 0x80800068: bc1f        L_80800078
    if (!c1cs) {
        // 0x8080006C: nop
    
            goto L_80800078;
    }
    // 0x8080006C: nop

    // 0x80800070: b           L_80800078
    // 0x80800074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800078;
    // 0x80800074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800078:
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080007C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void func_80800B40_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B4C: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x80800B50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B54: beq         $v0, $at, L_80800B74
    if (ctx->r2 == ctx->r1) {
        // 0x80800B58: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800B74;
    }
    // 0x80800B58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B5C: beq         $v0, $at, L_80800BB0
    if (ctx->r2 == ctx->r1) {
        // 0x80800B60: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800BB0;
    }
    // 0x80800B60: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800B64: beq         $v0, $at, L_80800BC8
    if (ctx->r2 == ctx->r1) {
        // 0x80800B68: nop
    
            goto L_80800BC8;
    }
    // 0x80800B68: nop

    // 0x80800B6C: b           L_80800BE4
    // 0x80800B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BE4;
    // 0x80800B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B74:
    // 0x80800B74: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x80800B78: beq         $t6, $zero, L_80800B98
    if (ctx->r14 == 0) {
        // 0x80800B7C: nop
    
            goto L_80800B98;
    }
    // 0x80800B7C: nop

    // 0x80800B80: jal         0x800D3EC8
    // 0x80800B84: lhu         $a0, 0x6($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6);
    func_800D3EC8(rdram, ctx);
        goto after_0;
    // 0x80800B84: lhu         $a0, 0x6($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6);
    after_0:
    // 0x80800B88: bnel        $v0, $zero, L_80800BE4
    if (ctx->r2 != 0) {
        // 0x80800B8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800BE4;
    }
    goto skip_0;
    // 0x80800B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800B90: b           L_80800BE4
    // 0x80800B94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BE4;
    // 0x80800B94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B98:
    // 0x80800B98: jal         0x800D3E6C
    // 0x80800B9C: lhu         $a0, 0x6($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6);
    func_800D3E6C(rdram, ctx);
        goto after_1;
    // 0x80800B9C: lhu         $a0, 0x6($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6);
    after_1:
    // 0x80800BA0: bnel        $v0, $zero, L_80800BE4
    if (ctx->r2 != 0) {
        // 0x80800BA4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800BE4;
    }
    goto skip_1;
    // 0x80800BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80800BA8: b           L_80800BE4
    // 0x80800BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BE4;
    // 0x80800BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BB0:
    // 0x80800BB0: jal         0x80088148
    // 0x80800BB4: lhu         $a0, 0x6($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6);
    _gcfrontend_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800BB4: lhu         $a0, 0x6($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6);
    after_2:
    // 0x80800BB8: beql        $v0, $zero, L_80800BE4
    if (ctx->r2 == 0) {
        // 0x80800BBC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800BE4;
    }
    goto skip_2;
    // 0x80800BBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80800BC0: b           L_80800BE4
    // 0x80800BC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BE4;
    // 0x80800BC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BC8:
    // 0x80800BC8: jal         0x800DA298
    // 0x80800BCC: addiu       $a0, $zero, 0xC0C
    ctx->r4 = ADD32(0, 0XC0C);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800BCC: addiu       $a0, $zero, 0xC0C
    ctx->r4 = ADD32(0, 0XC0C);
    after_3:
    // 0x80800BD0: beql        $v0, $zero, L_80800BE4
    if (ctx->r2 == 0) {
        // 0x80800BD4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800BE4;
    }
    goto skip_3;
    // 0x80800BD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80800BD8: b           L_80800BE4
    // 0x80800BDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BE4;
    // 0x80800BDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BE4:
    // 0x80800BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BEC: jr          $ra
    // 0x80800BF0: nop

    return;
    // 0x80800BF0: nop

;}
RECOMP_FUNC void func_808010AC_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808010B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808010B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808010B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808010BC: jal         0x80800694
    // 0x808010C0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    bsbabykaz_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808010C0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808010C4: jal         0x8008E148
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_1;
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808010CC: beq         $v0, $zero, L_808010E0
    if (ctx->r2 == 0) {
        // 0x808010D0: nop
    
            goto L_808010E0;
    }
    // 0x808010D0: nop

    // 0x808010D4: jal         0x800848B0
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_2;
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808010DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808010E0:
    // 0x808010E0: jal         0x8008DD04
    // 0x808010E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_3;
    // 0x808010E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808010E8: beq         $v0, $zero, L_808010F8
    if (ctx->r2 == 0) {
        // 0x808010EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010F8;
    }
    // 0x808010EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010F0: addiu       $t6, $zero, 0x133
    ctx->r14 = ADD32(0, 0X133);
    // 0x808010F4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808010F8:
    // 0x808010F8: jal         0x808001A8
    // 0x808010FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808001A8_bsbabykaz(rdram, ctx);
        goto after_4;
    // 0x808010FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801104: jal         0x8009E5C8
    // 0x80801108: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x80801108: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8080110C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801114: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801118: jr          $ra
    // 0x8080111C: nop

    return;
    // 0x8080111C: nop

;}
RECOMP_FUNC void func_800C517C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C517C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5180: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C5184: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C5188: jr          $ra
    // 0x800C518C: lwc1        $f0, -0x5610($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5610);
    return;
    // 0x800C518C: lwc1        $f0, -0x5610($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5610);
;}
RECOMP_FUNC void suquiz_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800798: jal         0x80800584
    // 0x8080079C: nop

    suquiz_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080079C: nop

    after_0:
    // 0x808007A0: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x808007A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3370, 0XF74) << 16);
    // 0x808007A8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808007AC: jal         0x800DC298
    // 0x808007B0: lwc1        $f12, 0xF74($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3370, 0XF74));
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x808007B0: lwc1        $f12, 0xF74($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3370, 0XF74));
    after_1:
    // 0x808007B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007BC: jr          $ra
    // 0x808007C0: nop

    return;
    // 0x808007C0: nop

;}
RECOMP_FUNC void func_8009B08C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B08C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009B090: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009B094: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009B098: jal         0x800D8FF8
    // 0x8009B09C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8009B09C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8009B0A0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8009B0A4: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B0A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8009B0AC: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    // 0x8009B0B0: jal         0x800EFB24
    // 0x8009B0B4: addiu       $a2, $v0, 0x10
    ctx->r6 = ADD32(ctx->r2, 0X10);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x8009B0B4: addiu       $a2, $v0, 0x10
    ctx->r6 = ADD32(ctx->r2, 0X10);
    after_1:
    // 0x8009B0B8: lw          $t6, 0xC8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B0BC: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8009B0C0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8009B0C4: lwc1        $f4, 0x44($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X44);
    // 0x8009B0C8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009B0CC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8009B0D0: jal         0x800EF334
    // 0x8009B0D4: nop

    func_800EF334(rdram, ctx);
        goto after_2;
    // 0x8009B0D4: nop

    after_2:
    // 0x8009B0D8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009B0DC: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009B0E0: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009B0E4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8009B0E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B0EC: lwc1        $f8, 0x52A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X52A4);
    // 0x8009B0F0: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8009B0F4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8009B0F8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8009B0FC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8009B100: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8009B104: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8009B108: nop

    // 0x8009B10C: bc1fl       L_8009B130
    if (!c1cs) {
        // 0x8009B110: lw          $a0, 0xC8($s0)
        ctx->r4 = MEM_W(ctx->r16, 0XC8);
            goto L_8009B130;
    }
    goto skip_0;
    // 0x8009B110: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    skip_0:
    // 0x8009B114: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B118: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x8009B11C: jal         0x800EE7F8
    // 0x8009B120: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x8009B120: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    after_3:
    // 0x8009B124: b           L_8009B13C
    // 0x8009B128: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B13C;
    // 0x8009B128: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B12C: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
L_8009B130:
    // 0x8009B130: jal         0x800EF04C
    // 0x8009B134: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x8009B134: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_4:
    // 0x8009B138: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B13C:
    // 0x8009B13C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8009B140: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x8009B144: jal         0x800EFA20
    // 0x8009B148: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    func_800EFA20(rdram, ctx);
        goto after_5;
    // 0x8009B148: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    after_5:
    // 0x8009B14C: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B150: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8009B154: jal         0x800EF04C
    // 0x8009B158: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x8009B158: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    after_6:
    // 0x8009B15C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009B164: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8009B168: jr          $ra
    // 0x8009B16C: nop

    return;
    // 0x8009B16C: nop

;}
RECOMP_FUNC void sccustom_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808005D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808005D8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808005DC: jal         0x8008A618
    // 0x808005E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _scinfobar_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x808005E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808005E4: addiu       $at, $zero, 0x3E7
    ctx->r1 = ADD32(0, 0X3E7);
    // 0x808005E8: bne         $v0, $at, L_80800614
    if (ctx->r2 != ctx->r1) {
        // 0x808005EC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800614;
    }
    // 0x808005EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005F0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(3342, 0X920) << 16);
    // 0x808005F4: lw          $t6, 0x920($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(3342, 0X920));
    // 0x808005F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808005FC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800600: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800604: jal         0x80800264
    // 0x80800608: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80800264_sccustom(rdram, ctx);
        goto after_1;
    // 0x80800608: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8080060C: b           L_80800638
    // 0x80800610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800638;
    // 0x80800610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800614:
    // 0x80800614: jal         0x808004C8
    // 0x80800618: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_808004C8_sccustom(rdram, ctx);
        goto after_2;
    // 0x80800618: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8080061C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800620: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800624: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800628: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080062C: jal         0x80800000
    // 0x80800630: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80800000_sccustom(rdram, ctx);
        goto after_3;
    // 0x80800630: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800638:
    // 0x80800638: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080063C: jr          $ra
    // 0x80800640: nop

    return;
    // 0x80800640: nop

;}
RECOMP_FUNC void baeggfire_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080050C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800510: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800514: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080051C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x80800520: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x80800524: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    // 0x80800528: lw          $t8, 0x6C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X6C);
    // 0x8080052C: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
    // 0x80800530: jal         0x80800180
    // 0x80800534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800180_baeggfire(rdram, ctx);
        goto after_0;
    // 0x80800534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800538: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080053C: jal         0x8009E0AC
    // 0x80800540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009E0AC(rdram, ctx);
        goto after_1;
    // 0x80800540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800544: jal         0x80800040
    // 0x80800548: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800040_baeggfire(rdram, ctx);
        goto after_2;
    // 0x80800548: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080054C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800554: jr          $ra
    // 0x80800558: nop

    return;
    // 0x80800558: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808015A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808015AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808015B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808015B4: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x808015B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808015BC: jal         0x80800038
    // 0x808015C0: sb          $a2, 0x218($t7)
    MEM_B(0X218, ctx->r15) = ctx->r6;
    func_80800038_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x808015C0: sb          $a2, 0x218($t7)
    MEM_B(0X218, ctx->r15) = ctx->r6;
    after_0:
    // 0x808015C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808015CC: jal         0x80800000
    // 0x808015D0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_1;
    // 0x808015D0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x808015D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808015D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808015DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015E0: beql        $a2, $at, L_80801618
    if (ctx->r6 == ctx->r1) {
        // 0x808015E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801618;
    }
    goto skip_0;
    // 0x808015E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808015E8: jal         0x80800000
    // 0x808015EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_2;
    // 0x808015EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x808015F0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x808015F4: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x808015F8: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x808015FC: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80801600: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x80801604: beq         $t0, $zero, L_80801614
    if (ctx->r8 == 0) {
        // 0x80801608: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_80801614;
    }
    // 0x80801608: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080160C: jal         0x80087C20
    // 0x80801610: lw          $a0, 0x3C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X3C);
    _gczoombox_entrypoint_40(rdram, ctx);
        goto after_3;
    // 0x80801610: lw          $a0, 0x3C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X3C);
    after_3:
L_80801614:
    // 0x80801614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801618:
    // 0x80801618: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080161C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801620: jr          $ra
    // 0x80801624: nop

    return;
    // 0x80801624: nop

;}
RECOMP_FUNC void func_80801724_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080172C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801730: lbu         $v0, 0x7F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7F);
    // 0x80801734: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801738: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080173C: beq         $v0, $at, L_80801760
    if (ctx->r2 == ctx->r1) {
        // 0x80801740: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801760;
    }
    // 0x80801740: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801744: bnel        $v0, $at, L_80801764
    if (ctx->r2 != ctx->r1) {
        // 0x80801748: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80801764;
    }
    goto skip_0;
    // 0x80801748: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080174C: jal         0x800F54E4
    // 0x80801750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801754: jal         0x800F4CC0
    // 0x80801758: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_1;
    // 0x80801758: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080175C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80801760:
    // 0x80801760: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_80801764:
    // 0x80801764: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801768: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x8080176C: beq         $v0, $at, L_80801794
    if (ctx->r2 == ctx->r1) {
        // 0x80801770: sb          $t6, 0x7F($a2)
        MEM_B(0X7F, ctx->r6) = ctx->r14;
            goto L_80801794;
    }
    // 0x80801770: sb          $t6, 0x7F($a2)
    MEM_B(0X7F, ctx->r6) = ctx->r14;
    // 0x80801774: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801778: bnel        $v0, $at, L_80801798
    if (ctx->r2 != ctx->r1) {
        // 0x8080177C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801798;
    }
    goto skip_1;
    // 0x8080177C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801780: jal         0x800F54E4
    // 0x80801784: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80801784: nop

    after_2:
    // 0x80801788: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080178C: jal         0x800F4CEC
    // 0x80801790: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    func_800F4CEC(rdram, ctx);
        goto after_3;
    // 0x80801790: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    after_3:
L_80801794:
    // 0x80801794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801798:
    // 0x80801798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080179C: jr          $ra
    // 0x808017A0: nop

    return;
    // 0x808017A0: nop

;}
