#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chfactorymaindoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087560: syscall     588
    recomp_syscall_handler(rdram, ctx, 0x80087560);
    return;
    // 0x80087564: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802314_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802314: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080231C: addiu       $a0, $zero, 0xA4F
    ctx->r4 = ADD32(0, 0XA4F);
    // 0x80802320: jal         0x800DA980
    // 0x80802324: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA980(rdram, ctx);
        goto after_0;
    // 0x80802324: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80802328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080232C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80802330: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    // 0x80802334: jr          $ra
    // 0x80802338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80802338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800CB8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB8BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB8C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB8C4: jal         0x800CB890
    // 0x800CB8C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800CB890(rdram, ctx);
        goto after_0;
    // 0x800CB8C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CB8CC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CB8D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB8D4: lh          $t7, 0x1A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X1A);
    // 0x800CB8D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB8DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CB8E0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800CB8E4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800CB8E8: jr          $ra
    // 0x800CB8EC: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    return;
    // 0x800CB8EC: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
;}
RECOMP_FUNC void bainput_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098140: beql        $a2, $zero, L_80098168
    if (ctx->r6 == 0) {
        // 0x80098144: lw          $v0, 0xA4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XA4);
            goto L_80098168;
    }
    goto skip_0;
    // 0x80098144: lw          $v0, 0xA4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA4);
    skip_0:
    // 0x80098148: lw          $v0, 0xA4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA4);
    // 0x8009814C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80098150: sllv        $t8, $t7, $a1
    ctx->r24 = S32(ctx->r15 << (ctx->r5 & 31));
    // 0x80098154: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80098158: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009815C: jr          $ra
    // 0x80098160: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    return;
    // 0x80098160: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80098164: lw          $v0, 0xA4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA4);
L_80098168:
    // 0x80098168: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009816C: sllv        $t2, $t1, $a1
    ctx->r10 = S32(ctx->r9 << (ctx->r5 & 31));
    // 0x80098170: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80098174: nor         $t3, $t2, $zero
    ctx->r11 = ~(ctx->r10 | 0);
    // 0x80098178: and         $t4, $t0, $t3
    ctx->r12 = ctx->r8 & ctx->r11;
    // 0x8009817C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80098180: jr          $ra
    // 0x80098184: nop

    return;
    // 0x80098184: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084228: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084228);
    return;
    // 0x8008422C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _chmole_maya_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A28: syscall     406
    recomp_syscall_handler(rdram, ctx, 0x80086A28);
    return;
    // 0x80086A2C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808020D8_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808020D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808020DC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808020E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808020E4: beq         $a1, $at, L_80802114
    if (ctx->r5 == ctx->r1) {
        // 0x808020E8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80802114;
    }
    // 0x808020E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808020EC: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x808020F0: beq         $a1, $at, L_8080215C
    if (ctx->r5 == ctx->r1) {
        // 0x808020F4: lh          $t6, 0x22($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X22);
            goto L_8080215C;
    }
    // 0x808020F4: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x808020F8: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808020FC: beq         $a1, $at, L_80802190
    if (ctx->r5 == ctx->r1) {
        // 0x80802100: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80802190;
    }
    // 0x80802100: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80802104: beq         $a1, $at, L_80802178
    if (ctx->r5 == ctx->r1) {
        // 0x80802108: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80802178;
    }
    // 0x80802108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080210C: b           L_808021A0
    // 0x80802110: nop

        goto L_808021A0;
    // 0x80802110: nop

L_80802114:
    // 0x80802114: lh          $v0, 0x20($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X20);
    // 0x80802118: addiu       $at, $zero, 0x13DE
    ctx->r1 = ADD32(0, 0X13DE);
    // 0x8080211C: beq         $v0, $at, L_80802144
    if (ctx->r2 == ctx->r1) {
        // 0x80802120: addiu       $at, $zero, 0x13DF
        ctx->r1 = ADD32(0, 0X13DF);
            goto L_80802144;
    }
    // 0x80802120: addiu       $at, $zero, 0x13DF
    ctx->r1 = ADD32(0, 0X13DF);
    // 0x80802124: beq         $v0, $at, L_80802144
    if (ctx->r2 == ctx->r1) {
        // 0x80802128: addiu       $at, $zero, 0x13ED
        ctx->r1 = ADD32(0, 0X13ED);
            goto L_80802144;
    }
    // 0x80802128: addiu       $at, $zero, 0x13ED
    ctx->r1 = ADD32(0, 0X13ED);
    // 0x8080212C: bne         $v0, $at, L_80802154
    if (ctx->r2 != ctx->r1) {
        // 0x80802130: nop
    
            goto L_80802154;
    }
    // 0x80802130: nop

    // 0x80802134: jal         0x80801EE8
    // 0x80802138: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801EE8_chtrashcangame(rdram, ctx);
        goto after_0;
    // 0x80802138: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x8080213C: b           L_808021A0
    // 0x80802140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808021A0;
    // 0x80802140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802144:
    // 0x80802144: jal         0x80088180
    // 0x80802148: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80802148: nop

    after_1:
    // 0x8080214C: b           L_808021A0
    // 0x80802150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808021A0;
    // 0x80802150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802154:
    // 0x80802154: b           L_808021A0
    // 0x80802158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808021A0;
    // 0x80802158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080215C:
    // 0x8080215C: beql        $t6, $zero, L_80802170
    if (ctx->r14 == 0) {
        // 0x80802160: lw          $v0, 0x20($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X20);
            goto L_80802170;
    }
    goto skip_0;
    // 0x80802160: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    skip_0:
    // 0x80802164: b           L_808021A0
    // 0x80802168: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
        goto L_808021A0;
    // 0x80802168: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x8080216C: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_80802170:
    // 0x80802170: b           L_808021A0
    // 0x80802174: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_808021A0;
    // 0x80802174: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80802178:
    // 0x80802178: jal         0x8008A088
    // 0x8080217C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _subaddiemulti_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080217C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80802180: jal         0x8008A0A8
    // 0x80802184: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _subaddiemulti_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80802184: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80802188: b           L_808021A0
    // 0x8080218C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808021A0;
    // 0x8080218C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802190:
    // 0x80802190: jal         0x808019EC
    // 0x80802194: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_808019EC_chtrashcangame(rdram, ctx);
        goto after_4;
    // 0x80802194: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80802198: b           L_808021A0
    // 0x8080219C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808021A0;
    // 0x8080219C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808021A0:
    // 0x808021A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808021A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808021A8: jr          $ra
    // 0x808021AC: nop

    return;
    // 0x808021AC: nop

;}
RECOMP_FUNC void bsdronexform_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A10: jal         0x800961AC
    // 0x80800A14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_0;
    // 0x80800A14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800A18: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80800A1C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800A20: jal         0x800C59F0
    // 0x80800A24: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800C59F0(rdram, ctx);
        goto after_1;
    // 0x80800A24: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_1:
    // 0x80800A28: jal         0x808002CC
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002CC_bsdronexform(rdram, ctx);
        goto after_2;
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800A30: jal         0x8080069C
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080069C_bsdronexform(rdram, ctx);
        goto after_3;
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A38: jal         0x8009CEE8
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CEE8(rdram, ctx);
        goto after_4;
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: jal         0x80095774
    // 0x80800A48: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    baflag_clear(rdram, ctx);
        goto after_5;
    // 0x80800A48: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_5:
    // 0x80800A4C: jal         0x80084900
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badronemem_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800A54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A60: jr          $ra
    // 0x80800A64: nop

    return;
    // 0x80800A64: nop

;}
RECOMP_FUNC void func_800C42E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C42E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C42E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C42E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C42EC: addiu       $a1, $a2, -0x3E9
    ctx->r5 = ADD32(ctx->r6, -0X3E9);
    // 0x800C42F0: jal         0x800DC548
    // 0x800C42F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DC548(rdram, ctx);
        goto after_0;
    // 0x800C42F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800C42F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C42FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C4300: jr          $ra
    // 0x800C4304: nop

    return;
    // 0x800C4304: nop

;}
RECOMP_FUNC void func_800DF428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF428: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF42C: addiu       $v0, $v0, -0x37D4
    ctx->r2 = ADD32(ctx->r2, -0X37D4);
    // 0x800DF430: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DF434: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x800DF438: jr          $ra
    // 0x800DF43C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800DF43C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80019A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019A10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80019A14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80019A18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80019A1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80019A20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80019A24: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x80019A28: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019A2C: jal         0x80019C84
    // 0x80019A30: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    mlMtxTranslate(rdram, ctx);
        goto after_0;
    // 0x80019A30: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80019A34: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80019A38: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80019A3C: jal         0x80018FE8
    // 0x80019A40: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    mlMtxRotYaw(rdram, ctx);
        goto after_1;
    // 0x80019A40: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x80019A44: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80019A48: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80019A4C: jal         0x80018F50
    // 0x80019A50: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    mlMtxRotPitch(rdram, ctx);
        goto after_2;
    // 0x80019A50: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_2:
    // 0x80019A54: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80019A58: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80019A5C: jal         0x8001907C
    // 0x80019A60: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    mlMtxRotRoll(rdram, ctx);
        goto after_3;
    // 0x80019A60: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_3:
    // 0x80019A64: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80019A68: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80019A6C: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80019A70: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80019A74: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80019A78: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80019A7C: jal         0x80019C84
    // 0x80019A80: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    mlMtxTranslate(rdram, ctx);
        goto after_4;
    // 0x80019A80: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_4:
    // 0x80019A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80019A88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80019A8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80019A90: jr          $ra
    // 0x80019A94: nop

    return;
    // 0x80019A94: nop

;}
RECOMP_FUNC void _chfirefx_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086150: syscall     281
    recomp_syscall_handler(rdram, ctx, 0x80086150);
    return;
    // 0x80086154: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800060_bsmumattack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800068: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(312, 0X6F0) << 16);
    // 0x8080006C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800070: addiu       $a2, $a2, 0x6F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(312, 0X6F0));
    // 0x80800074: jal         0x8009D454
    // 0x80800078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D454(rdram, ctx);
        goto after_0;
    // 0x80800078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080007C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800080: jal         0x800C8A98
    // 0x80800084: sb          $v0, 0x160($t6)
    MEM_B(0X160, ctx->r14) = ctx->r2;
    func_800C8A98(rdram, ctx);
        goto after_1;
    // 0x80800084: sb          $v0, 0x160($t6)
    MEM_B(0X160, ctx->r14) = ctx->r2;
    after_1:
    // 0x80800088: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800094: sw          $v0, 0x164($v1)
    MEM_W(0X164, ctx->r3) = ctx->r2;
    // 0x80800098: swc1        $f4, 0x16C($v1)
    MEM_W(0X16C, ctx->r3) = ctx->f4.u32l;
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void chmole_cuckoo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1848, 0XD0) << 16);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1848, 0XD0));
    return;
    // 0x808000BC: addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1848, 0XD0));
;}
RECOMP_FUNC void func_80800758_chtoxicroomprops(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800758: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080075C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800760: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800764: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800768: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080076C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800770: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800774: beq         $t6, $at, L_8080079C
    if (ctx->r14 == ctx->r1) {
        // 0x80800778: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080079C;
    }
    // 0x80800778: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080077C: beq         $t6, $at, L_808007E0
    if (ctx->r14 == ctx->r1) {
        // 0x80800780: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808007E0;
    }
    // 0x80800780: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800784: beq         $t6, $at, L_8080083C
    if (ctx->r14 == ctx->r1) {
        // 0x80800788: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080083C;
    }
    // 0x80800788: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080078C: beq         $t6, $at, L_808008A8
    if (ctx->r14 == ctx->r1) {
        // 0x80800790: nop
    
            goto L_808008A8;
    }
    // 0x80800790: nop

    // 0x80800794: b           L_80800948
    // 0x80800798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800948;
    // 0x80800798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080079C:
    // 0x8080079C: jal         0x800DA298
    // 0x808007A0: addiu       $a0, $zero, 0xA04
    ctx->r4 = ADD32(0, 0XA04);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808007A0: addiu       $a0, $zero, 0xA04
    ctx->r4 = ADD32(0, 0XA04);
    after_0:
    // 0x808007A4: bnel        $v0, $zero, L_808007BC
    if (ctx->r2 != 0) {
        // 0x808007A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007BC;
    }
    goto skip_0;
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808007AC: jal         0x800DA298
    // 0x808007B0: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808007B0: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_1:
    // 0x808007B4: bne         $v0, $zero, L_808007D4
    if (ctx->r2 != 0) {
        // 0x808007B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007D4;
    }
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007BC:
    // 0x808007BC: jal         0x80101FDC
    // 0x808007C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808007C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808007C4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808007C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007CC: nop

    // 0x808007D0: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
L_808007D4:
    // 0x808007D4: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808007D8: b           L_80800944
    // 0x808007DC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_80800944;
    // 0x808007DC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_808007E0:
    // 0x808007E0: jal         0x800D90A4
    // 0x808007E4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D90A4(rdram, ctx);
        goto after_3;
    // 0x808007E4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_3:
    // 0x808007E8: beq         $v0, $zero, L_808007F8
    if (ctx->r2 == 0) {
        // 0x808007EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007F8;
    }
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: jal         0x80101FDC
    // 0x808007F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808007F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
L_808007F8:
    // 0x808007F8: jal         0x80103EF4
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_5;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800800: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800804: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800808: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2492, 0X98C) << 16);
    // 0x8080080C: lwc1        $f8, 0x98C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2492, 0X98C));
    // 0x80800810: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800814: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800818: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080081C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800820: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800824: jal         0x800F10B4
    // 0x80800828: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800828: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8080082C: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800830: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800834: b           L_80800944
    // 0x80800838: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
        goto L_80800944;
    // 0x80800838: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_8080083C:
    // 0x8080083C: jal         0x800DA298
    // 0x80800840: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800840: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_7:
    // 0x80800844: beq         $v0, $zero, L_80800884
    if (ctx->r2 == 0) {
        // 0x80800848: nop
    
            goto L_80800884;
    }
    // 0x80800848: nop

    // 0x8080084C: jal         0x800DA298
    // 0x80800850: addiu       $a0, $zero, 0xA04
    ctx->r4 = ADD32(0, 0XA04);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800850: addiu       $a0, $zero, 0xA04
    ctx->r4 = ADD32(0, 0XA04);
    after_8:
    // 0x80800854: bne         $v0, $zero, L_80800884
    if (ctx->r2 != 0) {
        // 0x80800858: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800884;
    }
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: jal         0x80101FDC
    // 0x80800860: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x80800860: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80800864: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800868: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080086C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2492, 0XA78) << 16);
    // 0x80800870: addiu       $a2, $a2, 0xA78
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2492, 0XA78));
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800878: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080087C: jal         0x80089D18
    // 0x80800880: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800880: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    after_10:
L_80800884:
    // 0x80800884: jal         0x80103EF4
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_11;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080088C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2492, 0X990) << 16);
    // 0x80800890: lwc1        $f6, 0x990($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2492, 0X990));
    // 0x80800894: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800898: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080089C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808008A0: b           L_80800944
    // 0x808008A4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_80800944;
    // 0x808008A4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_808008A8:
    // 0x808008A8: jal         0x800D90A4
    // 0x808008AC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D90A4(rdram, ctx);
        goto after_12;
    // 0x808008AC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_12:
    // 0x808008B0: beq         $v0, $zero, L_80800900
    if (ctx->r2 == 0) {
        // 0x808008B4: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80800900;
    }
    // 0x808008B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808008B8: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x808008BC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x808008C0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x808008C4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808008C8: jal         0x800E1610
    // 0x808008CC: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    func_800E1610(rdram, ctx);
        goto after_13;
    // 0x808008CC: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    after_13:
    // 0x808008D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008D4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808008D8: jal         0x800E148C
    // 0x808008DC: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    func_800E148C(rdram, ctx);
        goto after_14;
    // 0x808008DC: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    after_14:
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E4: jal         0x80101FDC
    // 0x808008E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_15;
    // 0x808008E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808008EC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2492, 0XA78) << 16);
    // 0x808008F0: addiu       $a2, $a2, 0xA78
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2492, 0XA78));
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F8: jal         0x80089D18
    // 0x808008FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x808008FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_16:
L_80800900:
    // 0x80800900: jal         0x80103EF4
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_17;
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800908: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080090C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800910: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2492, 0X994) << 16);
    // 0x80800914: lwc1        $f18, 0x994($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2492, 0X994));
    // 0x80800918: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080091C: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800920: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800924: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800928: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8080092C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800930: jal         0x800F10B4
    // 0x80800934: nop

    func_800F10B4(rdram, ctx);
        goto after_18;
    // 0x80800934: nop

    after_18:
    // 0x80800938: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8080093C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800940: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_80800944:
    // 0x80800944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800948:
    // 0x80800948: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080094C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800950: jr          $ra
    // 0x80800954: nop

    return;
    // 0x80800954: nop

;}
RECOMP_FUNC void func_80802B1C_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B1C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80802B20: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80802B24: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80802B28: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x80802B2C: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x80802B30: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x80802B34: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x80802B38: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80802B3C: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x80802B40: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80802B44: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80802B48: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80802B4C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80802B50: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80802B54: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80802B58: jal         0x800B53A4
    // 0x80802B5C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80802B5C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80802B60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802B64: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80802B68: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80802B6C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80802B70: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80802B74: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80802B78: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80802B7C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80802B80: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80802B84: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x80802B88: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80802B8C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80802B90: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(1360, 0X4A10) << 16);
    // 0x80802B94: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80802B98: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80802B9C: addiu       $s4, $s4, 0x4A10
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(1360, 0X4A10));
    // 0x80802BA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802BA4: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x80802BA8: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x80802BAC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80802BB0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_80802BB4:
    // 0x80802BB4: jal         0x800DC178
    // 0x80802BB8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80802BB8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_1:
    // 0x80802BBC: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80802BC0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802BC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802BC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802BCC: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80802BD0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80802BD4: jal         0x800EEB9C
    // 0x80802BD8: nop

    func_800EEB9C(rdram, ctx);
        goto after_2;
    // 0x80802BD8: nop

    after_2:
    // 0x80802BDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802BE0: jal         0x800EF04C
    // 0x80802BE4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80802BE4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80802BE8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80802BEC: jal         0x800DC178
    // 0x80802BF0: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80802BF0: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    after_4:
    // 0x80802BF4: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80802BF8: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x80802BFC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80802C00: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80802C04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80802C08: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80802C0C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80802C10: jal         0x800BABB8
    // 0x80802C14: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x80802C14: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80802C18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80802C1C: bnel        $s0, $s5, L_80802BB4
    if (ctx->r16 != ctx->r21) {
        // 0x80802C20: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_80802BB4;
    }
    goto skip_0;
    // 0x80802C20: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_0:
    // 0x80802C24: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X49FC) << 16);
    // 0x80802C28: addiu       $a2, $a2, 0x49FC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X49FC));
    // 0x80802C2C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80802C30: jal         0x80089D18
    // 0x80802C34: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80802C34: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x80802C38: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80802C3C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80802C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802C44: jal         0x800E15CC
    // 0x80802C48: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_7;
    // 0x80802C48: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_7:
    // 0x80802C4C: lui         $a1, 0x3FE6
    ctx->r5 = S32(0X3FE6 << 16);
    // 0x80802C50: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80802C54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802C58: jal         0x80018820
    // 0x80802C5C: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    func_80018820(rdram, ctx);
        goto after_8;
    // 0x80802C5C: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_8:
    // 0x80802C60: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80802C64: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80802C68: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80802C6C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80802C70: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80802C74: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80802C78: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80802C7C: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x80802C80: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80802C84: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80802C88: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80802C8C: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x80802C90: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x80802C94: jr          $ra
    // 0x80802C98: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80802C98: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_801164E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801164E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801164E4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801164E8: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801164EC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801164F0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x801164F4: lwc1        $f12, 0x6634($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6634);
L_801164F8:
    // 0x801164F8: lb          $t0, 0x0($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X0);
    // 0x801164FC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80116500: lb          $t0, 0x1($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X1);
    // 0x80116504: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80116508: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8011650C: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80116510: lb          $t0, 0x2($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X2);
    // 0x80116514: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80116518: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8011651C: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80116520: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80116524: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80116528: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8011652C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80116530: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x80116534: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80116538: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x8011653C: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80116540: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80116544: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80116548: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x8011654C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80116550: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80116554: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80116558: bgtz        $v0, L_801164F8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8011655C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_801164F8;
    }
    // 0x8011655C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80116560: jr          $ra
    // 0x80116564: nop

    return;
    // 0x80116564: nop

;}
RECOMP_FUNC void badrone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void bsclimb_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080075C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800764: jal         0x808001D0
    // 0x80800768: nop

    func_808001D0_bsclimb(rdram, ctx);
        goto after_0;
    // 0x80800768: nop

    after_0:
    // 0x8080076C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800774: jr          $ra
    // 0x80800778: nop

    return;
    // 0x80800778: nop

;}
RECOMP_FUNC void func_80800008_bsbwhirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: jal         0x800BF8E4
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800BF8E4(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080001C: blezl       $v0, L_808000C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800020: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000C8;
    }
    goto skip_0;
    // 0x80800020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800024: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
    // 0x80800028: bnel        $t6, $zero, L_8080006C
    if (ctx->r14 != 0) {
        // 0x8080002C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080006C;
    }
    goto skip_1;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800030: jal         0x800C8A98
    // 0x80800034: nop

    func_800C8A98(rdram, ctx);
        goto after_1;
    // 0x80800034: nop

    after_1:
    // 0x80800038: sw          $v0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r2;
    // 0x8080003C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800040: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800044: jal         0x800C8E54
    // 0x80800048: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    func_800C8E54(rdram, ctx);
        goto after_2;
    // 0x80800048: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    after_2:
    // 0x8080004C: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x80800050: jal         0x800C8F64
    // 0x80800054: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_800C8F64(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
    // 0x80800058: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(128, 0XF50) << 16);
    // 0x8080005C: addiu       $a1, $a1, 0xF50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(128, 0XF50));
    // 0x80800060: jal         0x800C8E84
    // 0x80800064: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x80800064: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    after_4:
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080006C:
    // 0x8080006C: jal         0x80092B8C
    // 0x80800070: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80092B8C(rdram, ctx);
        goto after_5;
    // 0x80800070: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x80800074: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: jal         0x8009C128
    // 0x80800080: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_8009C128(rdram, ctx);
        goto after_6;
    // 0x80800080: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x80800084: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800088: jal         0x800EF04C
    // 0x8080008C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x8080008C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_7:
    // 0x80800090: jal         0x80092BE8
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092BE8(rdram, ctx);
        goto after_8;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800098: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080009C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808000A0: jal         0x800EF1B8
    // 0x808000A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800EF1B8(rdram, ctx);
        goto after_9;
    // 0x808000A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x808000A8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808000AC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808000B0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808000B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000B8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x808000BC: jal         0x800C8CB8
    // 0x808000C0: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    func_800C8CB8(rdram, ctx);
        goto after_10;
    // 0x808000C0: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    after_10:
    // 0x808000C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C8:
    // 0x808000C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808000D0: jr          $ra
    // 0x808000D4: nop

    return;
    // 0x808000D4: nop

;}
RECOMP_FUNC void gcgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D4: jal         0x800FE4E4
    // 0x808000D8: nop

    func_800FE4E4(rdram, ctx);
        goto after_0;
    // 0x808000D8: nop

    after_0:
    // 0x808000DC: jal         0x800CB610
    // 0x808000E0: nop

    func_800CB610(rdram, ctx);
        goto after_1;
    // 0x808000E0: nop

    after_1:
    // 0x808000E4: jal         0x80088028
    // 0x808000E8: nop

    _gccollectDll_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000E8: nop

    after_2:
    // 0x808000EC: jal         0x800D1604
    // 0x808000F0: nop

    func_800D1604(rdram, ctx);
        goto after_3;
    // 0x808000F0: nop

    after_3:
    // 0x808000F4: jal         0x8009E8B4
    // 0x808000F8: nop

    func_8009E8B4(rdram, ctx);
        goto after_4;
    // 0x808000F8: nop

    after_4:
    // 0x808000FC: jal         0x800F8DD8
    // 0x80800100: nop

    func_800F8DD8(rdram, ctx);
        goto after_5;
    // 0x80800100: nop

    after_5:
    // 0x80800104: jal         0x800DA188
    // 0x80800108: nop

    func_800DA188(rdram, ctx);
        goto after_6;
    // 0x80800108: nop

    after_6:
    // 0x8080010C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void func_800A8264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8264: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8268: lbu         $v0, 0x7642($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7642);
    // 0x800A826C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A8270: jr          $ra
    // 0x800A8274: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x800A8274: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_80802CC0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802CC8: jal         0x80106790
    // 0x80802CCC: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802CCC: nop

    after_0:
    // 0x80802CD0: lbu         $t6, 0x65($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X65);
    // 0x80802CD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802CD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802CDC: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80802CE0: jal         0x80100094
    // 0x80802CE4: sb          $t7, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r15;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802CE4: sb          $t7, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r15;
    after_1:
    // 0x80802CE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802CEC: jal         0x80087DC0
    // 0x80802CF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_2;
    // 0x80802CF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80802CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802CF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802CFC: jr          $ra
    // 0x80802D00: nop

    return;
    // 0x80802D00: nop

;}
RECOMP_FUNC void __baanim_oscillateScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C3FC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8008C400: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8008C404: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008C408: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8008C40C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8008C410: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8008C414: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8008C418: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8008C41C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8008C420: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8008C424: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8008C428: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8008C42C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8008C430: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8008C434: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8008C438: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x8008C43C: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x8008C440: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8008C444: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008C448: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8008C44C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008C450: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8008C454: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8008C458:
    // 0x8008C458: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x8008C45C: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    // 0x8008C460: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008C464: div.s       $f0, $f6, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f28.fl);
    // 0x8008C468: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8008C46C: jal         0x800F0F9C
    // 0x8008C470: add.s       $f12, $f8, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f22.fl;
    func_800F0F9C(rdram, ctx);
        goto after_0;
    // 0x8008C470: add.s       $f12, $f8, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f22.fl;
    after_0:
    // 0x8008C474: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8008C478: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008C47C: nop

    // 0x8008C480: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8008C484: jal         0x80013970
    // 0x8008C488: nop

    func_80013970(rdram, ctx);
        goto after_1;
    // 0x8008C488: nop

    after_1:
    // 0x8008C48C: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8008C490: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008C494: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8008C498: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8008C49C: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8008C4A0: add.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f26.fl;
    // 0x8008C4A4: bne         $s0, $s2, L_8008C458
    if (ctx->r16 != ctx->r18) {
        // 0x8008C4A8: swc1        $f6, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f6.u32l;
            goto L_8008C458;
    }
    // 0x8008C4A8: swc1        $f6, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f6.u32l;
    // 0x8008C4AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8008C4B0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8008C4B4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8008C4B8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8008C4BC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8008C4C0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8008C4C4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8008C4C8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8008C4CC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8008C4D0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8008C4D4: jr          $ra
    // 0x8008C4D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8008C4D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void bsbansnooze_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004AC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004B0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(49, 0XA50) << 16);
    // 0x808004B4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808004B8: jr          $ra
    // 0x808004BC: lw          $v0, 0xA50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XA50));
    return;
    // 0x808004BC: lw          $v0, 0xA50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XA50));
;}
RECOMP_FUNC void func_808000FC_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800100: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800104: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800108: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080010C: jal         0x80087CA8
    // 0x80800110: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _gcnewoption_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800110: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800114: jal         0x8001ACCC
    // 0x80800118: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x80800118: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080011C: jal         0x80087CA8
    // 0x80800120: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    _gcnewoption_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800120: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_2:
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x8002D6E0
    // 0x8080012C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bzero(rdram, ctx);
        goto after_3;
    // 0x8080012C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80800130: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800134: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800138: addiu       $a1, $a1, 0x7DB0
    ctx->r5 = ADD32(ctx->r5, 0X7DB0);
    // 0x8080013C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800148: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080014C: jal         0x80087CC0
    // 0x80800150: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _gcnewoption_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800150: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x80800154: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800158: jal         0x80100094
    // 0x8080015C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x8080015C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800160: sw          $s0, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r16;
    // 0x80800164: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6550) << 16);
    // 0x80800168: lwc1        $f4, 0x6550($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6550));
    // 0x8080016C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800170: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8080017C: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80800180: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800184: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800188: jal         0x80087DD8
    // 0x8080018C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_6;
    // 0x8080018C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: jal         0x80087CD8
    // 0x80800198: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80800198: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: jal         0x80087CE0
    // 0x808001A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x808001A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x80087CE8
    // 0x808001B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x808001B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: jal         0x80087D98
    // 0x808001BC: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    _gcnewoption_entrypoint_32(rdram, ctx);
        goto after_10;
    // 0x808001BC: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    after_10:
    // 0x808001C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808001D4: jal         0x80087D08
    // 0x808001D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _gcnewoption_entrypoint_14(rdram, ctx);
        goto after_11;
    // 0x808001D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x808001DC: jal         0x80087D78
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_28(rdram, ctx);
        goto after_12;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x80087D60
    // 0x808001EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_25(rdram, ctx);
        goto after_13;
    // 0x808001EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: jal         0x80087D68
    // 0x808001F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_26(rdram, ctx);
        goto after_14;
    // 0x808001F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x808001FC: jal         0x80087CF0
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800208: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8080020C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800210: jr          $ra
    // 0x80800214: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800214: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80115EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115EA8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80115EAC: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x80115EB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80115EB4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80115EB8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80115EBC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80115EC0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80115EC4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80115EC8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80115ECC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80115ED0: jal         0x800F2100
    // 0x80115ED4: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x80115ED4: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80115ED8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80115EDC: lwc1        $f8, 0x6620($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6620);
    // 0x80115EE0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80115EE4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80115EE8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80115EEC: nop

    // 0x80115EF0: bc1fl       L_80115F74
    if (!c1cs) {
        // 0x80115EF4: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80115F74;
    }
    goto skip_0;
    // 0x80115EF4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x80115EF8: jal         0x800D8FF8
    // 0x80115EFC: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80115EFC: nop

    after_1:
    // 0x80115F00: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80115F04: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80115F08: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80115F0C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80115F10: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80115F14: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80115F18: jal         0x800FF060
    // 0x80115F1C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800FF060(rdram, ctx);
        goto after_2;
    // 0x80115F1C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80115F20: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80115F24: jal         0x800F2100
    // 0x80115F28: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x80115F28: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80115F2C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80115F30: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80115F34: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80115F38: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80115F3C: nop

    // 0x80115F40: bc1fl       L_80115F64
    if (!c1cs) {
        // 0x80115F44: lwc1        $f6, 0x0($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
            goto L_80115F64;
    }
    goto skip_1;
    // 0x80115F44: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80115F48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80115F4C: nop

    // 0x80115F50: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    // 0x80115F54: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80115F58: b           L_80115F84
    // 0x80115F5C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
        goto L_80115F84;
    // 0x80115F5C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80115F60: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
L_80115F64:
    // 0x80115F64: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80115F68: b           L_80115F84
    // 0x80115F6C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
        goto L_80115F84;
    // 0x80115F6C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80115F70: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80115F74:
    // 0x80115F74: nop

    // 0x80115F78: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    // 0x80115F7C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80115F80: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_80115F84:
    // 0x80115F84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80115F88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80115F8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80115F90: jr          $ra
    // 0x80115F94: nop

    return;
    // 0x80115F94: nop

;}
RECOMP_FUNC void func_8080110C_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080110C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801110: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80801114: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80801118: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080111C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80801120: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80801124: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x80801128: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080112C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801130: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80801134: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80801138: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8080113C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801140: addiu       $s1, $zero, 0x168
    ctx->r17 = ADD32(0, 0X168);
    // 0x80801144: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_80801148:
    // 0x80801148: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8080114C: jal         0x800F2094
    // 0x80801150: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F2094(rdram, ctx);
        goto after_0;
    // 0x80801150: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x80801154: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80801158: addiu       $s0, $s0, 0x5A
    ctx->r16 = ADD32(ctx->r16, 0X5A);
    // 0x8080115C: bc1f        L_8080116C
    if (!c1cs) {
        // 0x80801160: nop
    
            goto L_8080116C;
    }
    // 0x80801160: nop

    // 0x80801164: b           L_808011A4
    // 0x80801168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808011A4;
    // 0x80801168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080116C:
    // 0x8080116C: bnel        $s0, $s1, L_80801148
    if (ctx->r16 != ctx->r17) {
        // 0x80801170: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_80801148;
    }
    goto skip_0;
    // 0x80801170: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_0:
    // 0x80801174: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801178: jal         0x800F2094
    // 0x8080117C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800F2094(rdram, ctx);
        goto after_1;
    // 0x8080117C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_1:
    // 0x80801180: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801184: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080118C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80801190: nop

    // 0x80801194: bc1f        L_808011A4
    if (!c1cs) {
        // 0x80801198: nop
    
            goto L_808011A4;
    }
    // 0x80801198: nop

    // 0x8080119C: b           L_808011A4
    // 0x808011A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808011A4;
    // 0x808011A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011A4:
    // 0x808011A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808011A8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808011AC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808011B0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808011B4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808011B8: jr          $ra
    // 0x808011BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808011BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800EC48C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC48C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC494: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
    // 0x800EC498: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800EC49C: beql        $v0, $zero, L_800EC4B0
    if (ctx->r2 == 0) {
        // 0x800EC4A0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800EC4B0;
    }
    goto skip_0;
    // 0x800EC4A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x800EC4A4: bne         $v0, $at, L_800EC4B8
    if (ctx->r2 != ctx->r1) {
        // 0x800EC4A8: nop
    
            goto L_800EC4B8;
    }
    // 0x800EC4A8: nop

    // 0x800EC4AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800EC4B0:
    // 0x800EC4B0: b           L_800EC4F8
    // 0x800EC4B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800EC4F8;
    // 0x800EC4B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EC4B8:
    // 0x800EC4B8: jal         0x800EC3E8
    // 0x800EC4BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EC3E8(rdram, ctx);
        goto after_0;
    // 0x800EC4BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800EC4C0: jal         0x800B0CFC
    // 0x800EC4C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B0CFC(rdram, ctx);
        goto after_1;
    // 0x800EC4C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800EC4C8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800EC4CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800EC4D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EC4D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EC4D8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800EC4DC: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EC4E0: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800EC4E4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800EC4E8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800EC4EC: nop

    // 0x800EC4F0: sh          $t7, 0x20($t8)
    MEM_H(0X20, ctx->r24) = ctx->r15;
    // 0x800EC4F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EC4F8:
    // 0x800EC4F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EC4FC: jr          $ra
    // 0x800EC500: nop

    return;
    // 0x800EC500: nop

;}
RECOMP_FUNC void func_8009BD50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BD50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BD54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BD58: lw          $t6, 0xD4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD4);
    // 0x8009BD5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009BD60: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8009BD64: jal         0x8009BD38
    // 0x8009BD68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009BD38(rdram, ctx);
        goto after_0;
    // 0x8009BD68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009BD6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009BD70: jal         0x80091788
    // 0x8009BD74: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    bastatetimer_clear(rdram, ctx);
        goto after_1;
    // 0x8009BD74: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x8009BD78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BD7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BD80: jr          $ra
    // 0x8009BD84: nop

    return;
    // 0x8009BD84: nop

;}
RECOMP_FUNC void _chfantasytrashcanbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087608: syscall     596
    recomp_syscall_handler(rdram, ctx, 0x80087608);
    return;
    // 0x8008760C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800EB3D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB3D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800EB3D4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800EB3D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EB3DC: addiu       $t7, $t7, 0x2E80
    ctx->r15 = ADD32(ctx->r15, 0X2E80);
    // 0x800EB3E0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800EB3E4: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800EB3E8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800EB3EC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800EB3F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EB3F4: bne         $t8, $zero, L_800EB410
    if (ctx->r24 != 0) {
        // 0x800EB3F8: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_800EB410;
    }
    // 0x800EB3F8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800EB3FC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800EB400: jal         0x800B2D70
    // 0x800EB404: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    vector_new(rdram, ctx);
        goto after_0;
    // 0x800EB404: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EB408: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800EB40C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800EB410:
    // 0x800EB410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB414: jal         0x800B2974
    // 0x800EB418: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    vector_push_back(rdram, ctx);
        goto after_1;
    // 0x800EB418: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_1:
    // 0x800EB41C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800EB420: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800EB424: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800EB428: lh          $t1, 0x0($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X0);
    // 0x800EB42C: lh          $t9, 0x4($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X4);
    // 0x800EB430: lh          $t3, 0x2($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X2);
    // 0x800EB434: lh          $t2, 0x6($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X6);
    // 0x800EB438: subu        $a3, $t9, $t1
    ctx->r7 = SUB32(ctx->r25, ctx->r9);
    // 0x800EB43C: multu       $a3, $a3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EB440: subu        $v1, $t2, $t3
    ctx->r3 = SUB32(ctx->r10, ctx->r11);
    // 0x800EB444: lh          $t5, 0x4($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X4);
    // 0x800EB448: lh          $t4, 0x8($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X8);
    // 0x800EB44C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x800EB450: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    // 0x800EB454: mflo        $t6
    ctx->r14 = lo;
    // 0x800EB458: nop

    // 0x800EB45C: nop

    // 0x800EB460: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EB464: mflo        $t7
    ctx->r15 = lo;
    // 0x800EB468: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800EB46C: nop

    // 0x800EB470: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EB474: mflo        $t9
    ctx->r25 = lo;
    // 0x800EB478: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x800EB47C: jal         0x800B28C4
    // 0x800EB480: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    vector_begin(rdram, ctx);
        goto after_2;
    // 0x800EB480: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_2:
    // 0x800EB484: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800EB488: jal         0x800B296C
    // 0x800EB48C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_3;
    // 0x800EB48C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x800EB490: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800EB494: addiu       $a1, $v0, -0x10
    ctx->r5 = ADD32(ctx->r2, -0X10);
    // 0x800EB498: addiu       $a2, $v0, -0x8
    ctx->r6 = ADD32(ctx->r2, -0X8);
    // 0x800EB49C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800EB4A0: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800EB4A4: bne         $at, $zero, L_800EB4CC
    if (ctx->r1 != 0) {
        // 0x800EB4A8: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_800EB4CC;
    }
    // 0x800EB4A8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800EB4AC: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
L_800EB4B0:
    // 0x800EB4B0: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800EB4B4: bnel        $at, $zero, L_800EB4D0
    if (ctx->r1 != 0) {
        // 0x800EB4B8: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_800EB4D0;
    }
    goto skip_0;
    // 0x800EB4B8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    skip_0:
    // 0x800EB4BC: addiu       $a1, $a1, -0x8
    ctx->r5 = ADD32(ctx->r5, -0X8);
    // 0x800EB4C0: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800EB4C4: beql        $at, $zero, L_800EB4B0
    if (ctx->r1 == 0) {
        // 0x800EB4C8: lw          $t1, 0x4($a1)
        ctx->r9 = MEM_W(ctx->r5, 0X4);
            goto L_800EB4B0;
    }
    goto skip_1;
    // 0x800EB4C8: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    skip_1:
L_800EB4CC:
    // 0x800EB4CC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_800EB4D0:
    // 0x800EB4D0: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x800EB4D4: beq         $at, $zero, L_800EB4FC
    if (ctx->r1 == 0) {
        // 0x800EB4D8: addiu       $a0, $a1, 0x8
        ctx->r4 = ADD32(ctx->r5, 0X8);
            goto L_800EB4FC;
    }
    // 0x800EB4D8: addiu       $a0, $a1, 0x8
    ctx->r4 = ADD32(ctx->r5, 0X8);
    // 0x800EB4DC: subu        $a2, $t0, $a1
    ctx->r6 = SUB32(ctx->r8, ctx->r5);
    // 0x800EB4E0: sra         $t2, $a2, 3
    ctx->r10 = S32(SIGNED(ctx->r6) >> 3);
    // 0x800EB4E4: sll         $a2, $t2, 3
    ctx->r6 = S32(ctx->r10 << 3);
    // 0x800EB4E8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x800EB4EC: jal         0x8001BC68
    // 0x800EB4F0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    aligned4_memmove(rdram, ctx);
        goto after_4;
    // 0x800EB4F0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_4:
    // 0x800EB4F4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800EB4F8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
L_800EB4FC:
    // 0x800EB4FC: sw          $a3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r7;
    // 0x800EB500: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800EB504: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800EB508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EB50C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EB510: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800EB514: jr          $ra
    // 0x800EB518: nop

    return;
    // 0x800EB518: nop

;}
RECOMP_FUNC void func_80801A00_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801A04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801A08: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80801A0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801A10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801A14: beq         $a1, $at, L_80801A8C
    if (ctx->r5 == ctx->r1) {
        // 0x80801A18: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80801A8C;
    }
    // 0x80801A18: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80801A1C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80801A20: beq         $a1, $at, L_80801B2C
    if (ctx->r5 == ctx->r1) {
        // 0x80801A24: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80801B2C;
    }
    // 0x80801A24: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80801A28: beq         $a1, $at, L_80801A60
    if (ctx->r5 == ctx->r1) {
        // 0x80801A2C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80801A60;
    }
    // 0x80801A2C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80801A30: bne         $a1, $at, L_80801B54
    if (ctx->r5 != ctx->r1) {
        // 0x80801A34: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801B54;
    }
    // 0x80801A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801A38: jal         0x80103110
    // 0x80801A3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x80801A3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A44: jal         0x8008A4B8
    // 0x80801A48: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _subaddieDll_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80801A48: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80801A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A50: jal         0x80101FDC
    // 0x80801A54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80801A54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80801A58: b           L_80801B54
    // 0x80801A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801B54;
    // 0x80801A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801A60:
    // 0x80801A60: jal         0x800DA544
    // 0x80801A64: addiu       $a0, $zero, 0x581
    ctx->r4 = ADD32(0, 0X581);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80801A64: addiu       $a0, $zero, 0x581
    ctx->r4 = ADD32(0, 0X581);
    after_3:
    // 0x80801A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A6C: jal         0x80086E20
    // 0x80801A70: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _chskeletonexplode_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80801A70: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80801A74: jal         0x8010A570
    // 0x80801A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x80801A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801A7C: jal         0x8010A624
    // 0x80801A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_6;
    // 0x80801A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801A84: b           L_80801B54
    // 0x80801A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801B54;
    // 0x80801A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801A8C:
    // 0x80801A8C: jal         0x80101080
    // 0x80801A90: nop

    func_80101080(rdram, ctx);
        goto after_7;
    // 0x80801A90: nop

    after_7:
    // 0x80801A94: jal         0x80106790
    // 0x80801A98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_8;
    // 0x80801A98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80801A9C: lui         $a0, 0x5991
    ctx->r4 = S32(0X5991 << 16);
    // 0x80801AA0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801AA4: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801AA8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801AAC: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80801AB0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801AB4: jal         0x800C4140
    // 0x80801AB8: ori         $a0, $a0, 0x9413
    ctx->r4 = ctx->r4 | 0X9413;
    func_800C4140(rdram, ctx);
        goto after_9;
    // 0x80801AB8: ori         $a0, $a0, 0x9413
    ctx->r4 = ctx->r4 | 0X9413;
    after_9:
    // 0x80801ABC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801AC0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2456, 0X1EE4) << 16);
    // 0x80801AC4: addiu       $t6, $t6, 0x1EE4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2456, 0X1EE4));
    // 0x80801AC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801ACC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801AD0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80801AD4: jal         0x800BBCB8
    // 0x80801AD8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800BBCB8(rdram, ctx);
        goto after_10;
    // 0x80801AD8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_10:
    // 0x80801ADC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801AE0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2456, 0X1F1C) << 16);
    // 0x80801AE4: addiu       $t7, $t7, 0x1F1C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2456, 0X1F1C));
    // 0x80801AE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801AEC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801AF0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80801AF4: jal         0x800BBCB8
    // 0x80801AF8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800BBCB8(rdram, ctx);
        goto after_11;
    // 0x80801AF8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_11:
    // 0x80801AFC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801B00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801B04: jal         0x80086E00
    // 0x80801B08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chskeletonexplode_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x80801B08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80801B0C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801B10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801B14: jal         0x80086E00
    // 0x80801B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chskeletonexplode_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x80801B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80801B1C: jal         0x800FFA88
    // 0x80801B20: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_14;
    // 0x80801B20: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_14:
    // 0x80801B24: b           L_80801B54
    // 0x80801B28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801B54;
    // 0x80801B28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B2C:
    // 0x80801B2C: jal         0x801015D0
    // 0x80801B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_15;
    // 0x80801B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801B34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801B38: jal         0x800DF744
    // 0x80801B3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_16;
    // 0x80801B3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80801B40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80801B44: jal         0x800DF744
    // 0x80801B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_17;
    // 0x80801B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80801B4C: b           L_80801B54
    // 0x80801B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801B54;
    // 0x80801B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B54:
    // 0x80801B54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801B58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801B5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801B60: jr          $ra
    // 0x80801B64: nop

    return;
    // 0x80801B64: nop

;}
RECOMP_FUNC void _chminelight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CB8: syscall     443
    recomp_syscall_handler(rdram, ctx, 0x80086CB8);
    return;
    // 0x80086CBC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800C00_subaddietaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C04: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800C08: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(3334, 0XD74) << 16);
    // 0x80800C0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C10: addiu       $t6, $t6, 0xD74
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(3334, 0XD74));
    // 0x80800C14: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800C18: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800C1C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80800C20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C24: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800C28: jal         0x800BBCB8
    // 0x80800C2C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800C2C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x80800C30: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3334, 0XD50) << 16);
    // 0x80800C34: addiu       $a2, $a2, 0xD50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3334, 0XD50));
    // 0x80800C38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800C3C: jal         0x80089D18
    // 0x80800C40: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800C40: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C4C: jr          $ra
    // 0x80800C50: nop

    return;
    // 0x80800C50: nop

;}
RECOMP_FUNC void subaddierouteDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801320: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801324: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801328: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8080132C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80801330: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80801334: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80801338: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080133C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801340: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80801344: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80801348: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8080134C: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x80801350: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80801354: sll         $t7, $v0, 22
    ctx->r15 = S32(ctx->r2 << 22);
    // 0x80801358: srl         $t8, $t7, 26
    ctx->r24 = S32(U32(ctx->r15) >> 26);
    // 0x8080135C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80801360: srl         $s5, $v0, 25
    ctx->r21 = S32(U32(ctx->r2) >> 25);
    // 0x80801364: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80801368: jal         0x801015B0
    // 0x8080136C: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    func_801015B0(rdram, ctx);
        goto after_0;
    // 0x8080136C: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80801370: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801374: jal         0x800CC61C
    // 0x80801378: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800CC61C(rdram, ctx);
        goto after_1;
    // 0x80801378: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8080137C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80801380: blez        $v0, L_808014B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801384: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_808014B0;
    }
    // 0x80801384: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801388: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8080138C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80801390: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80801394:
    // 0x80801394: jal         0x800CC684
    // 0x80801398: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800CC684(rdram, ctx);
        goto after_2;
    // 0x80801398: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x8080139C: lh          $v1, 0xE($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XE);
    // 0x808013A0: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x808013A4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808013A8: negu        $t1, $v1
    ctx->r9 = SUB32(0, ctx->r3);
    // 0x808013AC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x808013B0: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x808013B4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x808013B8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808013BC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x808013C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808013C4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808013C8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x808013CC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808013D0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808013D4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808013D8: jal         0x800F00A4
    // 0x808013DC: nop

    func_800F00A4(rdram, ctx);
        goto after_3;
    // 0x808013DC: nop

    after_3:
    // 0x808013E0: beq         $v0, $zero, L_808014A0
    if (ctx->r2 == 0) {
        // 0x808013E4: andi        $t2, $s0, 0x2
        ctx->r10 = ctx->r16 & 0X2;
            goto L_808014A0;
    }
    // 0x808013E4: andi        $t2, $s0, 0x2
    ctx->r10 = ctx->r16 & 0X2;
    // 0x808013E8: beq         $t2, $zero, L_80801400
    if (ctx->r10 == 0) {
        // 0x808013EC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80801400;
    }
    // 0x808013EC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808013F0: jal         0x800EE7F8
    // 0x808013F4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808013F4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_4:
    // 0x808013F8: b           L_808015E8
    // 0x808013FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015E8;
    // 0x808013FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801400:
    // 0x80801400: lh          $t3, 0xC($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XC);
    // 0x80801404: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80801408: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8080140C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80801410: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801414: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801418: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8080141C: jal         0x8010BFA4
    // 0x80801420: nop

    func_8010BFA4(rdram, ctx);
        goto after_5;
    // 0x80801420: nop

    after_5:
    // 0x80801424: bne         $v0, $zero, L_80801434
    if (ctx->r2 != 0) {
        // 0x80801428: nop
    
            goto L_80801434;
    }
    // 0x80801428: nop

    // 0x8080142C: b           L_808015E8
    // 0x80801430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015E8;
    // 0x80801430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801434:
    // 0x80801434: blez        $s3, L_808014B0
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80801438: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808014B0;
    }
    // 0x80801438: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080143C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80801440:
    // 0x80801440: jal         0x800CC684
    // 0x80801444: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800CC684(rdram, ctx);
        goto after_6;
    // 0x80801444: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80801448: beql        $s0, $s2, L_80801490
    if (ctx->r16 == ctx->r18) {
        // 0x8080144C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801490;
    }
    goto skip_0;
    // 0x8080144C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80801450: lh          $t4, 0xC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XC);
    // 0x80801454: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801458: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8080145C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80801460: nop

    // 0x80801464: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801468: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080146C: jal         0x800F0064
    // 0x80801470: nop

    func_800F0064(rdram, ctx);
        goto after_7;
    // 0x80801470: nop

    after_7:
    // 0x80801474: beq         $v0, $zero, L_8080148C
    if (ctx->r2 == 0) {
        // 0x80801478: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8080148C;
    }
    // 0x80801478: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080147C: jal         0x800EE7F8
    // 0x80801480: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80801480: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_8:
    // 0x80801484: b           L_808015E8
    // 0x80801488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015E8;
    // 0x80801488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080148C:
    // 0x8080148C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801490:
    // 0x80801490: bnel        $s0, $s3, L_80801440
    if (ctx->r16 != ctx->r19) {
        // 0x80801494: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80801440;
    }
    goto skip_1;
    // 0x80801494: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_1:
    // 0x80801498: b           L_808014B4
    // 0x8080149C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
        goto L_808014B4;
    // 0x8080149C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
L_808014A0:
    // 0x808014A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808014A4: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x808014A8: bnel        $at, $zero, L_80801394
    if (ctx->r1 != 0) {
        // 0x808014AC: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80801394;
    }
    goto skip_2;
    // 0x808014AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_2:
L_808014B0:
    // 0x808014B0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
L_808014B4:
    // 0x808014B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808014B8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x808014BC: jal         0x800CC63C
    // 0x808014C0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    func_800CC63C(rdram, ctx);
        goto after_9;
    // 0x808014C0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    after_9:
    // 0x808014C4: lh          $v1, 0xE($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XE);
    // 0x808014C8: lh          $t5, 0xC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XC);
    // 0x808014CC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x808014D0: negu        $t6, $v1
    ctx->r14 = SUB32(0, ctx->r3);
    // 0x808014D4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x808014D8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x808014DC: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x808014E0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808014E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808014E8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808014EC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808014F0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808014F4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808014F8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808014FC: jal         0x800F00A4
    // 0x80801500: nop

    func_800F00A4(rdram, ctx);
        goto after_10;
    // 0x80801500: nop

    after_10:
    // 0x80801504: beq         $v0, $zero, L_80801514
    if (ctx->r2 == 0) {
        // 0x80801508: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80801514;
    }
    // 0x80801508: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8080150C: b           L_808015E8
    // 0x80801510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808015E8;
    // 0x80801510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801514:
    // 0x80801514: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x80801518: jal         0x8001B798
    // 0x8080151C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_8001B798(rdram, ctx);
        goto after_11;
    // 0x8080151C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_11:
    // 0x80801520: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x80801524: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80801528: jal         0x8001B798
    // 0x8080152C: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    func_8001B798(rdram, ctx);
        goto after_12;
    // 0x8080152C: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    after_12:
    // 0x80801530: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80801534: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80801538: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8080153C: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80801540: addu        $s0, $t3, $v0
    ctx->r16 = ADD32(ctx->r11, ctx->r2);
    // 0x80801544: lbu         $s3, 0x0($s0)
    ctx->r19 = MEM_BU(ctx->r16, 0X0);
    // 0x80801548: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080154C: blez        $s3, L_808015D8
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80801550: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_808015D8;
    }
L_80801550:
    // 0x80801550: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80801554: jal         0x800CC63C
    // 0x80801558: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    func_800CC63C(rdram, ctx);
        goto after_13;
    // 0x80801558: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    after_13:
    // 0x8080155C: lh          $v1, 0xE($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XE);
    // 0x80801560: lh          $t4, 0xC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XC);
    // 0x80801564: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80801568: negu        $t5, $v1
    ctx->r13 = SUB32(0, ctx->r3);
    // 0x8080156C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80801570: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80801574: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80801578: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080157C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801580: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801584: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80801588: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080158C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801590: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801594: jal         0x800F00A4
    // 0x80801598: nop

    func_800F00A4(rdram, ctx);
        goto after_14;
    // 0x80801598: nop

    after_14:
    // 0x8080159C: beq         $v0, $zero, L_808015D0
    if (ctx->r2 == 0) {
        // 0x808015A0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_808015D0;
    }
    // 0x808015A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808015A4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x808015A8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x808015AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808015B0: lhu         $t2, 0x72($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X72);
    // 0x808015B4: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x808015B8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x808015BC: andi        $t0, $t9, 0x3F0
    ctx->r8 = ctx->r25 & 0X3F0;
    // 0x808015C0: andi        $t3, $t2, 0xFC0F
    ctx->r11 = ctx->r10 & 0XFC0F;
    // 0x808015C4: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x808015C8: b           L_808015E8
    // 0x808015CC: sh          $t4, 0x72($t1)
    MEM_H(0X72, ctx->r9) = ctx->r12;
        goto L_808015E8;
    // 0x808015CC: sh          $t4, 0x72($t1)
    MEM_H(0X72, ctx->r9) = ctx->r12;
L_808015D0:
    // 0x808015D0: bne         $s2, $s3, L_80801550
    if (ctx->r18 != ctx->r19) {
        // 0x808015D4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801550;
    }
    // 0x808015D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808015D8:
    // 0x808015D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808015DC: jal         0x800EE7F8
    // 0x808015E0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x808015E0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_15:
    // 0x808015E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808015E8:
    // 0x808015E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808015EC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808015F0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808015F4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808015F8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808015FC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80801600: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80801604: jr          $ra
    // 0x80801608: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80801608: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800B5FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5FE4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B5FE8: addiu       $v1, $v1, -0x7E80
    ctx->r3 = ADD32(ctx->r3, -0X7E80);
    // 0x800B5FEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B5FF0: lbu         $t6, 0x1C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1C);
    // 0x800B5FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5FF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B5FFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800B6000: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B6004: bne         $t6, $zero, L_800B6094
    if (ctx->r14 != 0) {
        // 0x800B6008: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_800B6094;
    }
    // 0x800B6008: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800B600C: lbu         $a1, 0x2B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2B);
    // 0x800B6010: lbu         $a0, 0x20($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X20);
    // 0x800B6014: jal         0x800D35D0
    // 0x800B6018: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D35D0(rdram, ctx);
        goto after_0;
    // 0x800B6018: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800B601C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6020: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B6024: addiu       $v1, $v1, -0x7E80
    ctx->r3 = ADD32(ctx->r3, -0X7E80);
    // 0x800B6028: beq         $v0, $at, L_800B6038
    if (ctx->r2 == ctx->r1) {
        // 0x800B602C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800B6038;
    }
    // 0x800B602C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B6030: b           L_800B60B4
    // 0x800B6034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B60B4;
    // 0x800B6034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B6038:
    // 0x800B6038: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B603C: bne         $a1, $at, L_800B6094
    if (ctx->r5 != ctx->r1) {
        // 0x800B6040: nop
    
            goto L_800B6094;
    }
    // 0x800B6040: nop

    // 0x800B6044: lbu         $t7, 0x21($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X21);
    // 0x800B6048: beq         $t7, $zero, L_800B6060
    if (ctx->r15 == 0) {
        // 0x800B604C: nop
    
            goto L_800B6060;
    }
    // 0x800B604C: nop

    // 0x800B6050: jal         0x800D35BC
    // 0x800B6054: lbu         $a0, 0x20($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X20);
    func_800D35BC(rdram, ctx);
        goto after_1;
    // 0x800B6054: lbu         $a0, 0x20($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X20);
    after_1:
    // 0x800B6058: b           L_800B606C
    // 0x800B605C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800B606C;
    // 0x800B605C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B6060:
    // 0x800B6060: jal         0x800D3574
    // 0x800B6064: lbu         $a0, 0x20($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X20);
    func_800D3574(rdram, ctx);
        goto after_2;
    // 0x800B6064: lbu         $a0, 0x20($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X20);
    after_2:
    // 0x800B6068: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B606C:
    // 0x800B606C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800B6070: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800B6074: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6078: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B607C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B6080: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B6084: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B6088: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800B608C: b           L_800B60B0
    // 0x800B6090: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
        goto L_800B60B0;
    // 0x800B6090: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_800B6094:
    // 0x800B6094: jal         0x800B5E74
    // 0x800B6098: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    func_800B5E74(rdram, ctx);
        goto after_3;
    // 0x800B6098: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    after_3:
    // 0x800B609C: beql        $v0, $zero, L_800B60B0
    if (ctx->r2 == 0) {
        // 0x800B60A0: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800B60B0;
    }
    goto skip_0;
    // 0x800B60A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x800B60A4: b           L_800B60B0
    // 0x800B60A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B60B0;
    // 0x800B60A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B60AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B60B0:
    // 0x800B60B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B60B4:
    // 0x800B60B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B60B8: jr          $ra
    // 0x800B60BC: nop

    return;
    // 0x800B60BC: nop

;}
RECOMP_FUNC void _chanim_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859B0: syscall     184
    recomp_syscall_handler(rdram, ctx, 0x800859B0);
    return;
    // 0x800859B4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_808008C4_chdoormake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008CC: jal         0x80100094
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008D4: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x808008D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808008DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808008E0: bnel        $t6, $at, L_808008F4
    if (ctx->r14 != ctx->r1) {
        // 0x808008E4: lw          $t7, 0x0($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X0);
            goto L_808008F4;
    }
    goto skip_0;
    // 0x808008E4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x808008E8: b           L_80800938
    // 0x808008EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800938;
    // 0x808008EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008F0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
L_808008F4:
    // 0x808008F4: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x808008F8: beq         $t8, $zero, L_80800914
    if (ctx->r24 == 0) {
        // 0x808008FC: nop
    
            goto L_80800914;
    }
    // 0x808008FC: nop

    // 0x80800900: jal         0x800DA298
    // 0x80800904: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800904: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    after_1:
    // 0x80800908: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8080090C: b           L_80800938
    // 0x80800910: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80800938;
    // 0x80800910: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80800914:
    // 0x80800914: jal         0x800DA298
    // 0x80800918: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800918: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    after_2:
    // 0x8080091C: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800920: beq         $t0, $zero, L_80800938
    if (ctx->r8 == 0) {
        // 0x80800924: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80800938;
    }
    // 0x80800924: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80800928: jal         0x800DA298
    // 0x8080092C: addiu       $a0, $zero, 0x9CC
    ctx->r4 = ADD32(0, 0X9CC);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080092C: addiu       $a0, $zero, 0x9CC
    ctx->r4 = ADD32(0, 0X9CC);
    after_3:
    // 0x80800930: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800934: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80800938:
    // 0x80800938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080093C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800940: jr          $ra
    // 0x80800944: nop

    return;
    // 0x80800944: nop

;}
RECOMP_FUNC void func_80800A00_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A08: jal         0x80082FF0
    // 0x80800A0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800A0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A10: jal         0x80800000
    // 0x80800A14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bskazglide(rdram, ctx);
        goto after_1;
    // 0x80800A14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A20: jr          $ra
    // 0x80800A24: nop

    return;
    // 0x80800A24: nop

;}
RECOMP_FUNC void chfactorytoxicpools_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1156, 0X9D0) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x9D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1156, 0X9D0));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x9D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1156, 0X9D0));
;}
RECOMP_FUNC void gccubeDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x808
    ctx->r29 = ADD32(ctx->r29, -0X808);
    // 0x80800004: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800008: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800014: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800018: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080001C: addiu       $v0, $sp, 0x34
    ctx->r2 = ADD32(ctx->r29, 0X34);
    // 0x80800020: addiu       $v1, $sp, 0x804
    ctx->r3 = ADD32(ctx->r29, 0X804);
L_80800024:
    // 0x80800024: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80800028: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x8080002C: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x80800030: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80800034: bne         $v0, $v1, L_80800024
    if (ctx->r2 != ctx->r3) {
        // 0x80800038: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_80800024;
    }
    // 0x80800038: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x8080003C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80800040: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x80800044: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80800048: addiu       $s3, $sp, 0x2C
    ctx->r19 = ADD32(ctx->r29, 0X2C);
    // 0x8080004C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800050: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80800054: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x80800058: beq         $at, $zero, L_80800090
    if (ctx->r1 == 0) {
        // 0x8080005C: addiu       $s2, $sp, 0x34
        ctx->r18 = ADD32(ctx->r29, 0X34);
            goto L_80800090;
    }
    // 0x8080005C: addiu       $s2, $sp, 0x34
    ctx->r18 = ADD32(ctx->r29, 0X34);
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800064:
    // 0x80800064: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800068: jal         0x80088B80
    // 0x8080006C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    _gspropsDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080006C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_0:
    // 0x80800070: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x80800074: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80800078: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8080007C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80800080: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80800084: sltu        $at, $s0, $t2
    ctx->r1 = ctx->r16 < ctx->r10 ? 1 : 0;
    // 0x80800088: bnel        $at, $zero, L_80800064
    if (ctx->r1 != 0) {
        // 0x8080008C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800064;
    }
    goto skip_0;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80800090:
    // 0x80800090: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800094: jal         0x80088B88
    // 0x80800098: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _gspropsDll_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800098: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8080009C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000A8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808000AC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808000B0: jr          $ra
    // 0x808000B4: addiu       $sp, $sp, 0x808
    ctx->r29 = ADD32(ctx->r29, 0X808);
    return;
    // 0x808000B4: addiu       $sp, $sp, 0x808
    ctx->r29 = ADD32(ctx->r29, 0X808);
;}
RECOMP_FUNC void func_80801AD8_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801ADC: addiu       $at, $zero, 0x1085
    ctx->r1 = ADD32(0, 0X1085);
    // 0x80801AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801AE4: bne         $a1, $at, L_80801AF4
    if (ctx->r5 != ctx->r1) {
        // 0x80801AE8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801AF4;
    }
    // 0x80801AE8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801AEC: jal         0x80108B04
    // 0x80801AF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_0;
    // 0x80801AF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
L_80801AF4:
    // 0x80801AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AFC: jr          $ra
    // 0x80801B00: nop

    return;
    // 0x80801B00: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F38: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F38);
    return;
    // 0x80087F3C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800D6060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6060: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800D6064: lh          $t2, -0x419E($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X419E);
    // 0x800D6068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D606C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6070: addiu       $a1, $t2, -0x1
    ctx->r5 = ADD32(ctx->r10, -0X1);
    // 0x800D6074: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D6078: bltz        $a1, L_800D6140
    if (SIGNED(ctx->r5) < 0) {
        // 0x800D607C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800D6140;
    }
    // 0x800D607C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6080: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800D6084: addiu       $t1, $t1, -0x4800
    ctx->r9 = ADD32(ctx->r9, -0X4800);
    // 0x800D6088: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x800D608C: addu        $v0, $a1, $a2
    ctx->r2 = ADD32(ctx->r5, ctx->r6);
L_800D6090:
    // 0x800D6090: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800D6094: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6098: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800D609C: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x800D60A0: mflo        $t7
    ctx->r15 = lo;
    // 0x800D60A4: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x800D60A8: lw          $v1, 0x8($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X8);
    // 0x800D60AC: srl         $t9, $v1, 18
    ctx->r25 = S32(U32(ctx->r3) >> 18);
    // 0x800D60B0: slt         $at, $t9, $a0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D60B4: beq         $at, $zero, L_800D60FC
    if (ctx->r1 == 0) {
        // 0x800D60B8: nop
    
            goto L_800D60FC;
    }
    // 0x800D60B8: nop

    // 0x800D60BC: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x800D60C0: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800D60C4: beq         $at, $zero, L_800D60F4
    if (ctx->r1 == 0) {
        // 0x800D60C8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D60F4;
    }
    // 0x800D60C8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D60CC: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D60D0: mflo        $t3
    ctx->r11 = lo;
    // 0x800D60D4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800D60D8: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800D60DC: srl         $t6, $t5, 18
    ctx->r14 = S32(U32(ctx->r13) >> 18);
    // 0x800D60E0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D60E4: beql        $at, $zero, L_800D6138
    if (ctx->r1 == 0) {
        // 0x800D60E8: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800D6138;
    }
    goto skip_0;
    // 0x800D60E8: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x800D60EC: b           L_800D6140
    // 0x800D60F0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_800D6140;
    // 0x800D60F0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800D60F4:
    // 0x800D60F4: b           L_800D6140
    // 0x800D60F8: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
        goto L_800D6140;
    // 0x800D60F8: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
L_800D60FC:
    // 0x800D60FC: bltz        $v0, L_800D612C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D6100: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D612C;
    }
    // 0x800D6100: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D6104: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6108: mflo        $t7
    ctx->r15 = lo;
    // 0x800D610C: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x800D6110: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800D6114: srl         $t3, $t9, 18
    ctx->r11 = S32(U32(ctx->r25) >> 18);
    // 0x800D6118: slt         $at, $t3, $a0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D611C: beql        $at, $zero, L_800D6138
    if (ctx->r1 == 0) {
        // 0x800D6120: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800D6138;
    }
    goto skip_1;
    // 0x800D6120: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    skip_1:
    // 0x800D6124: b           L_800D6140
    // 0x800D6128: nop

        goto L_800D6140;
    // 0x800D6128: nop

L_800D612C:
    // 0x800D612C: b           L_800D6140
    // 0x800D6130: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_800D6140;
    // 0x800D6130: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D6134: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_800D6138:
    // 0x800D6138: beql        $at, $zero, L_800D6090
    if (ctx->r1 == 0) {
        // 0x800D613C: addu        $v0, $a1, $a2
        ctx->r2 = ADD32(ctx->r5, ctx->r6);
            goto L_800D6090;
    }
    goto skip_2;
    // 0x800D613C: addu        $v0, $a1, $a2
    ctx->r2 = ADD32(ctx->r5, ctx->r6);
    skip_2:
L_800D6140:
    // 0x800D6140: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800D6144: addiu       $t1, $t1, -0x4800
    ctx->r9 = ADD32(ctx->r9, -0X4800);
    // 0x800D6148: bgez        $a3, L_800D6158
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800D614C: addiu       $t0, $zero, 0xC
        ctx->r8 = ADD32(0, 0XC);
            goto L_800D6158;
    }
    // 0x800D614C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x800D6150: b           L_800D6168
    // 0x800D6154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_800D6168;
    // 0x800D6154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800D6158:
    // 0x800D6158: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800D615C: beql        $at, $zero, L_800D616C
    if (ctx->r1 == 0) {
        // 0x800D6160: slt         $at, $a3, $t2
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800D616C;
    }
    goto skip_3;
    // 0x800D6160: slt         $at, $a3, $t2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
    skip_3:
    // 0x800D6164: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
L_800D6168:
    // 0x800D6168: slt         $at, $a3, $t2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
L_800D616C:
    // 0x800D616C: beql        $at, $zero, L_800D61A4
    if (ctx->r1 == 0) {
        // 0x800D6170: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D61A4;
    }
    goto skip_4;
    // 0x800D6170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800D6174: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6178: subu        $v0, $t2, $a3
    ctx->r2 = SUB32(ctx->r10, ctx->r7);
    // 0x800D617C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800D6180: mflo        $t4
    ctx->r12 = lo;
    // 0x800D6184: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    // 0x800D6188: addiu       $a0, $a1, 0xC
    ctx->r4 = ADD32(ctx->r5, 0XC);
    // 0x800D618C: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6190: mflo        $a2
    ctx->r6 = lo;
    // 0x800D6194: jal         0x8001BC68
    // 0x800D6198: nop

    aligned4_memmove(rdram, ctx);
        goto after_0;
    // 0x800D6198: nop

    after_0:
    // 0x800D619C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D61A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D61A4:
    // 0x800D61A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D61A8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800D61AC: jr          $ra
    // 0x800D61B0: nop

    return;
    // 0x800D61B0: nop

;}
RECOMP_FUNC void func_808003A4_changlerbossflare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808003A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003B0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808003B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003B8: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808003BC: bgezl       $t8, L_80800458
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808003C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800458;
    }
    goto skip_0;
    // 0x808003C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808003C4: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x808003C8: andi        $t9, $a0, 0x1FF
    ctx->r25 = ctx->r4 & 0X1FF;
    // 0x808003CC: jal         0x800F6438
    // 0x808003D0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x808003D0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x808003D4: beql        $v0, $zero, L_80800458
    if (ctx->r2 == 0) {
        // 0x808003D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800458;
    }
    goto skip_1;
    // 0x808003D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808003DC: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x808003E0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808003E4: andi        $t0, $a0, 0x1FF
    ctx->r8 = ctx->r4 & 0X1FF;
    // 0x808003E8: jal         0x800F5A00
    // 0x808003EC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x808003EC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x808003F0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808003F4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808003F8: jal         0x800EEB40
    // 0x808003FC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EEB40(rdram, ctx);
        goto after_2;
    // 0x808003FC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80800400: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1336, 0X474) << 16);
    // 0x80800404: lwc1        $f4, 0x474($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1336, 0X474));
    // 0x80800408: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080040C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800410: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800414: nop

    // 0x80800418: bc1f        L_80800430
    if (!c1cs) {
        // 0x8080041C: nop
    
            goto L_80800430;
    }
    // 0x8080041C: nop

    // 0x80800420: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800424: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x80800428: b           L_80800454
    // 0x8080042C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_80800454;
    // 0x8080042C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_80800430:
    // 0x80800430: jal         0x800F18FC
    // 0x80800434: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800F18FC(rdram, ctx);
        goto after_3;
    // 0x80800434: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800438: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080043C: jal         0x800EEF94
    // 0x80800440: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800EEF94(rdram, ctx);
        goto after_4;
    // 0x80800440: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_4:
    // 0x80800444: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800448: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080044C: jal         0x800EEBF0
    // 0x80800450: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EEBF0(rdram, ctx);
        goto after_5;
    // 0x80800450: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
L_80800454:
    // 0x80800454: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800458:
    // 0x80800458: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080045C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800460: jr          $ra
    // 0x80800464: nop

    return;
    // 0x80800464: nop

    // 0x80800468: nop

    // 0x8080046C: nop

;}
RECOMP_FUNC void _suexpressmorph_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B40: syscall     803
    recomp_syscall_handler(rdram, ctx, 0x80089B40);
    return;
    // 0x80089B44: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bamovespline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E80: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084E80);
    return;
    // 0x80084E84: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8001A0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A0A8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001A0AC: jr          $ra
    // 0x8001A0B0: lw          $v0, -0x433C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X433C);
    return;
    // 0x8001A0B0: lw          $v0, -0x433C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X433C);
;}
RECOMP_FUNC void _bswalk_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841D0: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x800841D0);
    return;
    // 0x800841D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
