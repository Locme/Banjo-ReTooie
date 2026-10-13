#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080305C_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080305C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803064: jal         0x80100094
    // 0x80803068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080306C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80803070: lh          $t6, 0x46($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X46);
    // 0x80803074: beql        $t6, $zero, L_80803098
    if (ctx->r14 == 0) {
        // 0x80803078: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80803098;
    }
    goto skip_0;
    // 0x80803078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080307C: jal         0x800F54E4
    // 0x80803080: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80803080: nop

    after_1:
    // 0x80803084: jal         0x800F4B20
    // 0x80803088: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4B20(rdram, ctx);
        goto after_2;
    // 0x80803088: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080308C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80803090: sh          $zero, 0x46($t7)
    MEM_H(0X46, ctx->r15) = 0;
    // 0x80803094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803098:
    // 0x80803098: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080309C: jr          $ra
    // 0x808030A0: nop

    return;
    // 0x808030A0: nop

;}
RECOMP_FUNC void _ncbatarget_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894B0: syscall     782
    recomp_syscall_handler(rdram, ctx, 0x800894B0);
    return;
    // 0x800894B4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _basub_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851B8: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851B8);
    return;
    // 0x800851BC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bashoes_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085018: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085018);
    return;
    // 0x8008501C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800E24_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E24: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80800E28: slti        $v0, $t6, 0x7F
    ctx->r2 = SIGNED(ctx->r14) < 0X7F ? 1 : 0;
    // 0x80800E2C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80800E30: beq         $v0, $zero, L_80800E3C
    if (ctx->r2 == 0) {
        // 0x80800E34: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_80800E3C;
    }
    // 0x80800E34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800E38: slti        $v0, $t6, 0x88
    ctx->r2 = SIGNED(ctx->r14) < 0X88 ? 1 : 0;
L_80800E3C:
    // 0x80800E3C: jr          $ra
    // 0x80800E40: nop

    return;
    // 0x80800E40: nop

;}
RECOMP_FUNC void _ncpodfixpos_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896A8: syscall     786
    recomp_syscall_handler(rdram, ctx, 0x800896A8);
    return;
    // 0x800896AC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800FAA34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAA34: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FAA38: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FAA3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FAA40: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FAA44: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800FAA48: lw          $a2, 0x3898($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3898);
    // 0x800FAA4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FAA50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FAA54: beq         $a2, $zero, L_800FAA64
    if (ctx->r6 == 0) {
        // 0x800FAA58: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800FAA64;
    }
    // 0x800FAA58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800FAA5C: jal         0x8008A5A8
    // 0x800FAA60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _scinfobar_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800FAA60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
L_800FAA64:
    // 0x800FAA64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FAA68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FAA6C: jr          $ra
    // 0x800FAA70: nop

    return;
    // 0x800FAA70: nop

;}
RECOMP_FUNC void func_80800514_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800514: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800518: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080051C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800520: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800524: jal         0x80100094
    // 0x80800528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080052C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800530: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800534: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800538: jal         0x800FE850
    // 0x8080053C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_800FE850(rdram, ctx);
        goto after_1;
    // 0x8080053C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_1:
    // 0x80800540: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800544: lbu         $t0, 0x26($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X26);
    // 0x80800548: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8080054C: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x80800550: beq         $at, $zero, L_808005E8
    if (ctx->r1 == 0) {
        // 0x80800554: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_808005E8;
    }
    // 0x80800554: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800558: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3E48) << 16);
    // 0x8080055C: addu        $at, $at, $t1
    gpr jr_addend_80800564 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80800560: lw          $t1, 0x3E48($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3E48));
    // 0x80800564: jr          $t1
    // 0x80800568: nop

    switch (jr_addend_80800564 >> 2) {
        case 0: goto L_8080056C; break;
        case 1: goto L_80800580; break;
        case 2: goto L_80800594; break;
        case 3: goto L_808005A8; break;
        case 4: goto L_808005BC; break;
        case 5: goto L_808005D0; break;
        default: switch_error(__func__, 0x80800564, 0x80803E48);
    }
    // 0x80800568: nop

L_8080056C:
    // 0x8080056C: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    // 0x80800570: jal         0x80087A58
    // 0x80800574: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800574: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x80800578: b           L_808005EC
    // 0x8080057C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005EC;
    // 0x8080057C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800580:
    // 0x80800580: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    // 0x80800584: jal         0x80087A58
    // 0x80800588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080058C: b           L_808005EC
    // 0x80800590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005EC;
    // 0x80800590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800594:
    // 0x80800594: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    // 0x80800598: jal         0x80087A58
    // 0x8080059C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080059C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x808005A0: b           L_808005EC
    // 0x808005A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005EC;
    // 0x808005A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005A8:
    // 0x808005A8: addiu       $a0, $zero, 0x13B
    ctx->r4 = ADD32(0, 0X13B);
    // 0x808005AC: jal         0x80087A58
    // 0x808005B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808005B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808005B4: b           L_808005EC
    // 0x808005B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005EC;
    // 0x808005B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005BC:
    // 0x808005BC: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    // 0x808005C0: jal         0x80087A58
    // 0x808005C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808005C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808005C8: b           L_808005EC
    // 0x808005CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005EC;
    // 0x808005CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005D0:
    // 0x808005D0: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x808005D4: jal         0x80087A58
    // 0x808005D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808005D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x808005DC: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x808005E0: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x808005E4: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_808005E8:
    // 0x808005E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005EC:
    // 0x808005EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005F4: jr          $ra
    // 0x808005F8: nop

    return;
    // 0x808005F8: nop

;}
RECOMP_FUNC void func_800DABF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DABF0: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x800DABF4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DABF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800DABFC: addiu       $t7, $t7, -0x3880
    ctx->r15 = ADD32(ctx->r15, -0X3880);
    // 0x800DAC00: jr          $ra
    // 0x800DAC04: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    return;
    // 0x800DAC04: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
;}
RECOMP_FUNC void _chlavahand_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087598: syscall     591
    recomp_syscall_handler(rdram, ctx, 0x80087598);
    return;
    // 0x8008759C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802780_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802780: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802788: jal         0x80106790
    // 0x8080278C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080278C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802790: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802794: beql        $t6, $zero, L_808027B0
    if (ctx->r14 == 0) {
        // 0x80802798: lbu         $t0, 0x65($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X65);
            goto L_808027B0;
    }
    goto skip_0;
    // 0x80802798: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
    skip_0:
    // 0x8080279C: lbu         $t8, 0x65($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X65);
    // 0x808027A0: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x808027A4: b           L_808027B8
    // 0x808027A8: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
        goto L_808027B8;
    // 0x808027A8: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
    // 0x808027AC: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
L_808027B0:
    // 0x808027B0: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x808027B4: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
L_808027B8:
    // 0x808027B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808027BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808027C0: jr          $ra
    // 0x808027C4: nop

    return;
    // 0x808027C4: nop

;}
RECOMP_FUNC void mlspline_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800DDC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800DE0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800DE4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800DE8: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x80800DEC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800DF0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800DF4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800DF8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80800DFC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800E00: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800E04: jal         0x800F0D50
    // 0x80800E08: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_800F0D50(rdram, ctx);
        goto after_0;
    // 0x80800E08: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800E0C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800E10: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800E14: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80800E18: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800E1C: nop

    // 0x80800E20: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800E24: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800E28: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80800E2C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80800E30: nop

    // 0x80800E34: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80800E38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800E3C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800E40: bne         $v0, $zero, L_80800F00
    if (ctx->r2 != 0) {
        // 0x80800E44: sub.s       $f20, $f2, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_80800F00;
    }
    // 0x80800E44: sub.s       $f20, $f2, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80800E48: bgtz        $v0, L_80801134
    if (SIGNED(ctx->r2) > 0) {
        // 0x80800E4C: sll         $a0, $a1, 2
        ctx->r4 = S32(ctx->r5 << 2);
            goto L_80801134;
    }
    // 0x80800E4C: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x80800E50: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800E54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800E58: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800E5C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800E60: addu        $v1, $s0, $a0
    ctx->r3 = ADD32(ctx->r16, ctx->r4);
    // 0x80800E64: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
L_80800E68:
    // 0x80800E68: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800E6C: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800E70: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800E74: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800E78: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80800E7C: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80800E80: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800E84: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80800E88: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80800E8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800E90: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800E94: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80800E98: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80800E9C: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800EA0: nop

    // 0x80800EA4: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80800EA8: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80800EAC: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800EB0: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800EB4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80800EB8: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800EBC: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800EC0: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80800EC4: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800EC8: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800ECC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80800ED0: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800ED4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800ED8: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800EDC: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800EE0: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800EE4: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800EE8: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800EEC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80800EF0: bne         $at, $zero, L_80800E68
    if (ctx->r1 != 0) {
        // 0x80800EF4: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80800E68;
    }
    // 0x80800EF4: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800EF8: b           L_80801138
    // 0x80800EFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80801138;
    // 0x80800EFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800F00:
    // 0x80800F00: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80800F04: addiu       $t9, $a1, 0x2
    ctx->r25 = ADD32(ctx->r5, 0X2);
    // 0x80800F08: bne         $a0, $t9, L_80800F28
    if (ctx->r4 != ctx->r25) {
        // 0x80800F0C: sll         $t2, $a1, 2
        ctx->r10 = S32(ctx->r5 << 2);
            goto L_80800F28;
    }
    // 0x80800F0C: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x80800F10: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x80800F14: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800F18: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x80800F1C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800F20: b           L_80801134
    // 0x80800F24: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
        goto L_80801134;
    // 0x80800F24: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
L_80800F28:
    // 0x80800F28: addiu       $t3, $a1, 0x3
    ctx->r11 = ADD32(ctx->r5, 0X3);
    // 0x80800F2C: bne         $a0, $t3, L_80800FE0
    if (ctx->r4 != ctx->r11) {
        // 0x80800F30: addu        $s0, $s0, $t2
        ctx->r16 = ADD32(ctx->r16, ctx->r10);
            goto L_80800FE0;
    }
    // 0x80800F30: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
    // 0x80800F34: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800F38: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800F3C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800F40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800F44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800F48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800F4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800F50: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80800F54: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80800F58: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80800F5C:
    // 0x80800F5C: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800F60: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800F64: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800F68: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800F6C: mul.s       $f8, $f12, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x80800F70: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800F74: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800F78: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800F7C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800F80: sub.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80800F84: mul.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80800F88: sub.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80800F8C: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800F90: add.s       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80800F94: add.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800F98: mul.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80800F9C: add.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80800FA0: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800FA4: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800FA8: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80800FAC: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800FB0: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800FB4: add.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800FB8: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800FBC: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800FC0: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800FC4: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800FC8: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800FCC: add.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80800FD0: bne         $a0, $a1, L_80800F5C
    if (ctx->r4 != ctx->r5) {
        // 0x80800FD4: swc1        $f12, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f12.u32l;
            goto L_80800F5C;
    }
    // 0x80800FD4: swc1        $f12, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f12.u32l;
    // 0x80800FD8: b           L_80801138
    // 0x80800FDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80801138;
    // 0x80800FDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800FE0:
    // 0x80800FE0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800FE4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800FE8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800FEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800FF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800FF4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800FF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800FFC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80801000: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80801004: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80801008: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080100C: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80801010: beq         $a0, $a1, L_808010B0
    if (ctx->r4 == ctx->r5) {
        // 0x80801014: lwc1        $f16, 0xC($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
            goto L_808010B0;
    }
    // 0x80801014: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
L_80801018:
    // 0x80801018: sub.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x8080101C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80801020: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80801024: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80801028: mul.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8080102C: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80801030: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80801034: mul.s       $f2, $f8, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80801038: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080103C: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80801040: sub.s       $f2, $f12, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80801044: mul.s       $f0, $f16, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80801048: add.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8080104C: add.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f6.fl;
    // 0x80801050: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80801054: add.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80801058: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8080105C: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80801060: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80801064: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80801068: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080106C: mul.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80801070: nop

    // 0x80801074: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80801078: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8080107C: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80801080: add.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80801084: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80801088: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080108C: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80801090: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80801094: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80801098: add.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080109C: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x808010A0: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808010A4: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808010A8: bne         $a0, $a1, L_80801018
    if (ctx->r4 != ctx->r5) {
        // 0x808010AC: nop
    
            goto L_80801018;
    }
    // 0x808010AC: nop

L_808010B0:
    // 0x808010B0: sub.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x808010B4: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x808010B8: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808010BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808010C0: mul.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x808010C4: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x808010C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808010CC: mul.s       $f2, $f8, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x808010D0: nop

    // 0x808010D4: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x808010D8: sub.s       $f2, $f12, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x808010DC: mul.s       $f0, $f16, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x808010E0: add.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x808010E4: add.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f6.fl;
    // 0x808010E8: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808010EC: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x808010F0: add.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x808010F4: mul.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x808010F8: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x808010FC: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80801100: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80801104: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80801108: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8080110C: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80801110: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80801114: add.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80801118: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8080111C: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80801120: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80801124: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80801128: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080112C: add.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801130: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80801134:
    // 0x80801134: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801138:
    // 0x80801138: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080113C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80801140: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801144: jr          $ra
    // 0x80801148: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801148: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chpawnbroker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085EE0: syscall     258
    recomp_syscall_handler(rdram, ctx, 0x80085EE0);
    return;
    // 0x80085EE4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chusefeather_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002D4: jal         0x800D3948
    // 0x808002D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x808002D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002DC: bne         $v0, $zero, L_80800304
    if (ctx->r2 != 0) {
        // 0x808002E0: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80800304;
    }
    // 0x808002E0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808002E4: bne         $t6, $zero, L_808002F4
    if (ctx->r14 != 0) {
        // 0x808002E8: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_808002F4;
    }
    // 0x808002E8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808002EC: b           L_808002F8
    // 0x808002F0: addiu       $a2, $zero, 0x26A
    ctx->r6 = ADD32(0, 0X26A);
        goto L_808002F8;
    // 0x808002F0: addiu       $a2, $zero, 0x26A
    ctx->r6 = ADD32(0, 0X26A);
L_808002F4:
    // 0x808002F4: addiu       $a2, $zero, 0x26B
    ctx->r6 = ADD32(0, 0X26B);
L_808002F8:
    // 0x808002F8: addiu       $a0, $a0, 0x5940
    ctx->r4 = ADD32(ctx->r4, 0X5940);
    // 0x808002FC: jal         0x80086D38
    // 0x80800300: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _chbaddiesetup_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800300: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80800304:
    // 0x80800304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080030C: jr          $ra
    // 0x80800310: nop

    return;
    // 0x80800310: nop

;}
RECOMP_FUNC void idwave_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800004: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80800008: lw          $s3, 0x90($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X90);
    // 0x8080000C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80800014: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80800018: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8080001C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80800020: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80800024: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80800028: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8080002C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800030: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800034: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800038: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080003C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800040: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80800044: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80800048: lwc1        $f26, 0x4($s3)
    ctx->f26.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8080004C: lwc1        $f28, 0x8($s3)
    ctx->f28.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80800050: lwc1        $f30, 0x10($s3)
    ctx->f30.u32l = MEM_W(ctx->r19, 0X10);
    // 0x80800054: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x80800058: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8080005C: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x80800060: addu        $s6, $t6, $a1
    ctx->r22 = ADD32(ctx->r14, ctx->r5);
    // 0x80800064: sltu        $at, $a1, $s6
    ctx->r1 = ctx->r5 < ctx->r22 ? 1 : 0;
    // 0x80800068: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x8080006C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800070: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800074: lh          $s4, 0x28($s3)
    ctx->r20 = MEM_H(ctx->r19, 0X28);
    // 0x80800078: beq         $at, $zero, L_80800230
    if (ctx->r1 == 0) {
        // 0x8080007C: lh          $s5, 0x2A($s3)
        ctx->r21 = MEM_H(ctx->r19, 0X2A);
            goto L_80800230;
    }
    // 0x8080007C: lh          $s5, 0x2A($s3)
    ctx->r21 = MEM_H(ctx->r19, 0X2A);
    // 0x80800080: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800084: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800088: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
L_8080008C:
    // 0x8080008C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80800090: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80800094: nop

    // 0x80800098: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080009C: sub.s       $f16, $f10, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f30.fl;
    // 0x808000A0: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x808000A4: jal         0x800136D0
    // 0x808000A8: add.s       $f12, $f18, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f26.fl;
    func_800136D0(rdram, ctx);
        goto after_0;
    // 0x808000A8: add.s       $f12, $f18, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f26.fl;
    after_0:
    // 0x808000AC: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x808000B0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x808000B4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808000B8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808000BC: nop

    // 0x808000C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000C4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808000C8: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x808000CC: jal         0x800136D0
    // 0x808000D0: add.s       $f12, $f16, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f28.fl;
    func_800136D0(rdram, ctx);
        goto after_1;
    // 0x808000D0: add.s       $f12, $f16, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f28.fl;
    after_1:
    // 0x808000D4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808000D8: jal         0x8001395C
    // 0x808000DC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_8001395C(rdram, ctx);
        goto after_2;
    // 0x808000DC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x808000E0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808000E4: jal         0x800138BC
    // 0x808000E8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_800138BC(rdram, ctx);
        goto after_3;
    // 0x808000E8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_3:
    // 0x808000EC: add.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x808000F0: lwc1        $f4, 0x20($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X20);
    // 0x808000F4: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x808000F8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808000FC: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800100: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800104: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x80800108: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8080010C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800110: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80800114: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800118: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080011C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80800120: nop

    // 0x80800124: sh          $t0, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r8;
    // 0x80800128: lwc1        $f16, 0x24($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8080012C: lbu         $t2, -0x4($s1)
    ctx->r10 = MEM_BU(ctx->r17, -0X4);
    // 0x80800130: div.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80800134: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800138: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080013C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800140: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80800144: nop

    // 0x80800148: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080014C: mflo        $t3
    ctx->r11 = lo;
    // 0x80800150: nop

    // 0x80800154: nop

    // 0x80800158: div         $zero, $t3, $s2
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r18)));
    // 0x8080015C: mflo        $t4
    ctx->r12 = lo;
    // 0x80800160: sb          $t4, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r12;
    // 0x80800164: lbu         $t5, -0x3($s1)
    ctx->r13 = MEM_BU(ctx->r17, -0X3);
    // 0x80800168: bne         $s2, $zero, L_80800174
    if (ctx->r18 != 0) {
        // 0x8080016C: nop
    
            goto L_80800174;
    }
    // 0x8080016C: nop

    // 0x80800170: break       7
    do_break(2155872624);
L_80800174:
    // 0x80800174: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800178: bne         $s2, $at, L_8080018C
    if (ctx->r18 != ctx->r1) {
        // 0x8080017C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8080018C;
    }
    // 0x8080017C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800180: bne         $t3, $at, L_8080018C
    if (ctx->r11 != ctx->r1) {
        // 0x80800184: nop
    
            goto L_8080018C;
    }
    // 0x80800184: nop

    // 0x80800188: break       6
    do_break(2155872648);
L_8080018C:
    // 0x8080018C: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800190: mflo        $t6
    ctx->r14 = lo;
    // 0x80800194: nop

    // 0x80800198: nop

    // 0x8080019C: div         $zero, $t6, $s2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r18)));
    // 0x808001A0: mflo        $t7
    ctx->r15 = lo;
    // 0x808001A4: sb          $t7, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r15;
    // 0x808001A8: lbu         $t8, -0x2($s1)
    ctx->r24 = MEM_BU(ctx->r17, -0X2);
    // 0x808001AC: bne         $s2, $zero, L_808001B8
    if (ctx->r18 != 0) {
        // 0x808001B0: nop
    
            goto L_808001B8;
    }
    // 0x808001B0: nop

    // 0x808001B4: break       7
    do_break(2155872692);
L_808001B8:
    // 0x808001B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001BC: bne         $s2, $at, L_808001D0
    if (ctx->r18 != ctx->r1) {
        // 0x808001C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_808001D0;
    }
    // 0x808001C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808001C4: bne         $t6, $at, L_808001D0
    if (ctx->r14 != ctx->r1) {
        // 0x808001C8: nop
    
            goto L_808001D0;
    }
    // 0x808001C8: nop

    // 0x808001CC: break       6
    do_break(2155872716);
L_808001D0:
    // 0x808001D0: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808001D4: mflo        $t9
    ctx->r25 = lo;
    // 0x808001D8: nop

    // 0x808001DC: nop

    // 0x808001E0: div         $zero, $t9, $s2
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r18)));
    // 0x808001E4: mflo        $t0
    ctx->r8 = lo;
    // 0x808001E8: sb          $t0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r8;
    // 0x808001EC: lh          $t1, -0x8($s1)
    ctx->r9 = MEM_H(ctx->r17, -0X8);
    // 0x808001F0: bne         $s2, $zero, L_808001FC
    if (ctx->r18 != 0) {
        // 0x808001F4: nop
    
            goto L_808001FC;
    }
    // 0x808001F4: nop

    // 0x808001F8: break       7
    do_break(2155872760);
L_808001FC:
    // 0x808001FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800200: bne         $s2, $at, L_80800214
    if (ctx->r18 != ctx->r1) {
        // 0x80800204: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800214;
    }
    // 0x80800204: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800208: bne         $t9, $at, L_80800214
    if (ctx->r25 != ctx->r1) {
        // 0x8080020C: nop
    
            goto L_80800214;
    }
    // 0x8080020C: nop

    // 0x80800210: break       6
    do_break(2155872784);
L_80800214:
    // 0x80800214: addu        $t2, $t1, $s4
    ctx->r10 = ADD32(ctx->r9, ctx->r20);
    // 0x80800218: sh          $t2, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r10;
    // 0x8080021C: lh          $t3, -0x6($s1)
    ctx->r11 = MEM_H(ctx->r17, -0X6);
    // 0x80800220: sltu        $at, $s1, $s6
    ctx->r1 = ctx->r17 < ctx->r22 ? 1 : 0;
    // 0x80800224: addu        $t4, $t3, $s5
    ctx->r12 = ADD32(ctx->r11, ctx->r21);
    // 0x80800228: bne         $at, $zero, L_8080008C
    if (ctx->r1 != 0) {
        // 0x8080022C: sh          $t4, -0x6($s0)
        MEM_H(-0X6, ctx->r16) = ctx->r12;
            goto L_8080008C;
    }
    // 0x8080022C: sh          $t4, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r12;
L_80800230:
    // 0x80800230: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80800234: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800238: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8080023C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800240: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800244: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800248: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8080024C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80800250: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80800254: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80800258: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8080025C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80800260: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80800264: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80800268: jr          $ra
    // 0x8080026C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8080026C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void bsbtrot_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808011DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808011E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808011E8: jal         0x8008CABC
    // 0x808011EC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808011EC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x808011F0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808011F4: jal         0x808004B4
    // 0x808011F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x808011F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808011FC: jal         0x8008E3E8
    // 0x80801200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E3E8(rdram, ctx);
        goto after_2;
    // 0x80801200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801204: beql        $v0, $zero, L_80801218
    if (ctx->r2 == 0) {
        // 0x80801208: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801218;
    }
    goto skip_0;
    // 0x80801208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080120C: jal         0x80085078
    // 0x80801210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80801210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801218:
    // 0x80801218: jal         0x80095738
    // 0x8080121C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_4;
    // 0x8080121C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_4:
    // 0x80801220: beq         $v0, $zero, L_80801238
    if (ctx->r2 == 0) {
        // 0x80801224: nop
    
            goto L_80801238;
    }
    // 0x80801224: nop

    // 0x80801228: jal         0x8009B7C0
    // 0x8080122C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_5;
    // 0x8080122C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801230: b           L_80801244
    // 0x80801234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801244;
    // 0x80801234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801238:
    // 0x80801238: jal         0x80800438
    // 0x8080123C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800438_bsbtrot(rdram, ctx);
        goto after_6;
    // 0x8080123C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801244:
    // 0x80801244: jal         0x8009BB24
    // 0x80801248: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_7;
    // 0x80801248: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_7:
    // 0x8080124C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801250: jal         0x80091A30
    // 0x80801254: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_8;
    // 0x80801254: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x80801258: beq         $v0, $zero, L_80801280
    if (ctx->r2 == 0) {
        // 0x8080125C: lwc1        $f6, 0x28($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80801280;
    }
    // 0x8080125C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801260: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801264: nop

    // 0x80801268: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080126C: nop

    // 0x80801270: bc1fl       L_80801284
    if (!c1cs) {
        // 0x80801274: lw          $t6, 0x15C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X15C);
            goto L_80801284;
    }
    goto skip_1;
    // 0x80801274: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    skip_1:
    // 0x80801278: jal         0x8009BC6C
    // 0x8080127C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_9;
    // 0x8080127C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80801280:
    // 0x80801280: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
L_80801284:
    // 0x80801284: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80801288: beq         $at, $zero, L_80801534
    if (ctx->r1 == 0) {
        // 0x8080128C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801534;
    }
    // 0x8080128C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801290: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2E10) << 16);
    // 0x80801294: addu        $at, $at, $t6
    gpr jr_addend_8080129C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801298: lw          $t6, 0x2E10($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(124, 0X2E10));
    // 0x8080129C: jr          $t6
    // 0x808012A0: nop

    switch (jr_addend_8080129C >> 2) {
        case 0: goto L_808012A4; break;
        case 1: goto L_808012E8; break;
        case 2: goto L_80801334; break;
        case 3: goto L_808013D8; break;
        case 4: goto L_80801460; break;
        case 5: goto L_808014E8; break;
        default: switch_error(__func__, 0x8080129C, 0x80802E10);
    }
    // 0x808012A0: nop

L_808012A4:
    // 0x808012A4: jal         0x8008B324
    // 0x808012A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_10;
    // 0x808012A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x808012AC: beq         $v0, $zero, L_80801534
    if (ctx->r2 == 0) {
        // 0x808012B0: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80801534;
    }
    // 0x808012B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808012B4: lui         $a2, 0x3EEE
    ctx->r6 = S32(0X3EEE << 16);
    // 0x808012B8: ori         $a2, $a2, 0x3BCD
    ctx->r6 = ctx->r6 | 0X3BCD;
    // 0x808012BC: jal         0x8008B1D4
    // 0x808012C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_11;
    // 0x808012C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x808012C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808012C8: jal         0x8008B1BC
    // 0x808012CC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_12;
    // 0x808012CC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_12:
    // 0x808012D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808012D4: jal         0x8008B134
    // 0x808012D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_13;
    // 0x808012D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808012DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808012E0: b           L_80801534
    // 0x808012E4: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_80801534;
    // 0x808012E4: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_808012E8:
    // 0x808012E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012EC: jal         0x8008DF8C
    // 0x808012F0: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    func_8008DF8C(rdram, ctx);
        goto after_14;
    // 0x808012F0: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    after_14:
    // 0x808012F4: beq         $v0, $zero, L_80801534
    if (ctx->r2 == 0) {
        // 0x808012F8: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80801534;
    }
    // 0x808012F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808012FC: lui         $a2, 0x3F3B
    ctx->r6 = S32(0X3F3B << 16);
    // 0x80801300: ori         $a2, $a2, 0x98C8
    ctx->r6 = ctx->r6 | 0X98C8;
    // 0x80801304: jal         0x8008B1D4
    // 0x80801308: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_15;
    // 0x80801308: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_15:
    // 0x8080130C: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80801310: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80801314: jal         0x8008B1BC
    // 0x80801318: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_16;
    // 0x80801318: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_16:
    // 0x8080131C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801320: jal         0x8008B134
    // 0x80801324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_17;
    // 0x80801324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80801328: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8080132C: b           L_80801534
    // 0x80801330: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_80801534;
    // 0x80801330: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_80801334:
    // 0x80801334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801338: jal         0x8009D3A8
    // 0x8080133C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_18;
    // 0x8080133C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80801340: jal         0x8008E078
    // 0x80801344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_19;
    // 0x80801344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80801348: beq         $v0, $zero, L_80801534
    if (ctx->r2 == 0) {
        // 0x8080134C: nop
    
            goto L_80801534;
    }
    // 0x8080134C: nop

    // 0x80801350: jal         0x8009FE58
    // 0x80801354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_20;
    // 0x80801354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801358: lui         $a2, 0x3F61
    ctx->r6 = S32(0X3F61 << 16);
    // 0x8080135C: ori         $a2, $a2, 0x3A93
    ctx->r6 = ctx->r6 | 0X3A93;
    // 0x80801360: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801364: jal         0x8008B1D4
    // 0x80801368: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_21;
    // 0x80801368: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_21:
    // 0x8080136C: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80801370: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80801374: jal         0x8008B1BC
    // 0x80801378: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_22;
    // 0x80801378: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_22:
    // 0x8080137C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801380: jal         0x8008B134
    // 0x80801384: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_23;
    // 0x80801384: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80801388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080138C: jal         0x8009D2D8
    // 0x80801390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D2D8(rdram, ctx);
        goto after_24;
    // 0x80801390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80801394: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80801398: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
    // 0x8080139C: jal         0x8009BB00
    // 0x808013A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_25;
    // 0x808013A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808013A4: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x808013A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808013AC: nop

    // 0x808013B0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808013B4: nop

    // 0x808013B8: bc1f        L_808013C8
    if (!c1cs) {
        // 0x808013BC: nop
    
            goto L_808013C8;
    }
    // 0x808013BC: nop

    // 0x808013C0: jal         0x8009D658
    // 0x808013C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_26;
    // 0x808013C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
L_808013C8:
    // 0x808013C8: jal         0x800849D0
    // 0x808013CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_1(rdram, ctx);
        goto after_27;
    // 0x808013CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808013D0: b           L_80801534
    // 0x808013D4: nop

        goto L_80801534;
    // 0x808013D4: nop

L_808013D8:
    // 0x808013D8: jal         0x8009BB00
    // 0x808013DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_28;
    // 0x808013DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808013E0: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x808013E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808013E8: nop

    // 0x808013EC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x808013F0: nop

    // 0x808013F4: bc1fl       L_80801408
    if (!c1cs) {
        // 0x808013F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801408;
    }
    goto skip_2;
    // 0x808013F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808013FC: jal         0x8009D658
    // 0x80801400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_29;
    // 0x80801400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80801404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801408:
    // 0x80801408: jal         0x8009D3A8
    // 0x8080140C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_30;
    // 0x8080140C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80801410: jal         0x8008B324
    // 0x80801414: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_31;
    // 0x80801414: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_31:
    // 0x80801418: beq         $v0, $zero, L_80801450
    if (ctx->r2 == 0) {
        // 0x8080141C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80801450;
    }
    // 0x8080141C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801420: lui         $a2, 0x3F63
    ctx->r6 = S32(0X3F63 << 16);
    // 0x80801424: ori         $a2, $a2, 0xC9EF
    ctx->r6 = ctx->r6 | 0XC9EF;
    // 0x80801428: jal         0x8008B1D4
    // 0x8080142C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_32;
    // 0x8080142C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_32:
    // 0x80801430: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801434: jal         0x8008B1BC
    // 0x80801438: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_33;
    // 0x80801438: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_33:
    // 0x8080143C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801440: jal         0x8008B134
    // 0x80801444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_34;
    // 0x80801444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_34:
    // 0x80801448: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8080144C: sw          $t0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r8;
L_80801450:
    // 0x80801450: jal         0x800849D0
    // 0x80801454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_1(rdram, ctx);
        goto after_35;
    // 0x80801454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80801458: b           L_80801534
    // 0x8080145C: nop

        goto L_80801534;
    // 0x8080145C: nop

L_80801460:
    // 0x80801460: jal         0x8009BB00
    // 0x80801464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_36;
    // 0x80801464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80801468: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x8080146C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801470: nop

    // 0x80801474: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80801478: nop

    // 0x8080147C: bc1fl       L_80801490
    if (!c1cs) {
        // 0x80801480: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801490;
    }
    goto skip_3;
    // 0x80801480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80801484: jal         0x8009D658
    // 0x80801488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_37;
    // 0x80801488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x8080148C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801490:
    // 0x80801490: jal         0x8009D3A8
    // 0x80801494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_38;
    // 0x80801494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_38:
    // 0x80801498: jal         0x8008B324
    // 0x8080149C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_39;
    // 0x8080149C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_39:
    // 0x808014A0: beq         $v0, $zero, L_808014D8
    if (ctx->r2 == 0) {
        // 0x808014A4: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808014D8;
    }
    // 0x808014A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808014A8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808014AC: jal         0x8008B1D4
    // 0x808014B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_40;
    // 0x808014B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_40:
    // 0x808014B4: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x808014B8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808014BC: jal         0x8008B1BC
    // 0x808014C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_41;
    // 0x808014C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_41:
    // 0x808014C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808014C8: jal         0x8008B134
    // 0x808014CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_42;
    // 0x808014CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_42:
    // 0x808014D0: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x808014D4: sw          $t1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r9;
L_808014D8:
    // 0x808014D8: jal         0x800849D0
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_1(rdram, ctx);
        goto after_43;
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x808014E0: b           L_80801534
    // 0x808014E4: nop

        goto L_80801534;
    // 0x808014E4: nop

L_808014E8:
    // 0x808014E8: jal         0x8009BB00
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_44;
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x808014F0: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x808014F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808014F8: nop

    // 0x808014FC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80801500: nop

    // 0x80801504: bc1fl       L_80801518
    if (!c1cs) {
        // 0x80801508: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801518;
    }
    goto skip_4;
    // 0x80801508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x8080150C: jal         0x8009D658
    // 0x80801510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_45;
    // 0x80801510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80801514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801518:
    // 0x80801518: jal         0x8009D3A8
    // 0x8080151C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_46;
    // 0x8080151C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_46:
    // 0x80801520: jal         0x8008B324
    // 0x80801524: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_47;
    // 0x80801524: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_47:
    // 0x80801528: beq         $v0, $zero, L_80801534
    if (ctx->r2 == 0) {
        // 0x8080152C: addiu       $t2, $zero, 0x15
        ctx->r10 = ADD32(0, 0X15);
            goto L_80801534;
    }
    // 0x8080152C: addiu       $t2, $zero, 0x15
    ctx->r10 = ADD32(0, 0X15);
    // 0x80801530: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80801534:
    // 0x80801534: jal         0x80084FE0
    // 0x80801538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_48;
    // 0x80801538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x8080153C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801540: beq         $v0, $at, L_80801550
    if (ctx->r2 == ctx->r1) {
        // 0x80801544: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801550;
    }
    // 0x80801544: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801548: bne         $v0, $at, L_80801578
    if (ctx->r2 != ctx->r1) {
        // 0x8080154C: nop
    
            goto L_80801578;
    }
    // 0x8080154C: nop

L_80801550:
    // 0x80801550: jal         0x80097DF4
    // 0x80801554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097DF4(rdram, ctx);
        goto after_49;
    // 0x80801554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80801558: beq         $v0, $zero, L_80801564
    if (ctx->r2 == 0) {
        // 0x8080155C: addiu       $t3, $zero, 0x10
        ctx->r11 = ADD32(0, 0X10);
            goto L_80801564;
    }
    // 0x8080155C: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80801560: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80801564:
    // 0x80801564: jal         0x80097F08
    // 0x80801568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097F08(rdram, ctx);
        goto after_50;
    // 0x80801568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x8080156C: beq         $v0, $zero, L_80801578
    if (ctx->r2 == 0) {
        // 0x80801570: addiu       $t4, $zero, 0x11
        ctx->r12 = ADD32(0, 0X11);
            goto L_80801578;
    }
    // 0x80801570: addiu       $t4, $zero, 0x11
    ctx->r12 = ADD32(0, 0X11);
    // 0x80801574: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80801578:
    // 0x80801578: jal         0x8008E35C
    // 0x8080157C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_51;
    // 0x8080157C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80801580: beq         $v0, $zero, L_8080158C
    if (ctx->r2 == 0) {
        // 0x80801584: addiu       $t5, $zero, 0x4C
        ctx->r13 = ADD32(0, 0X4C);
            goto L_8080158C;
    }
    // 0x80801584: addiu       $t5, $zero, 0x4C
    ctx->r13 = ADD32(0, 0X4C);
    // 0x80801588: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_8080158C:
    // 0x8080158C: jal         0x8008E078
    // 0x80801590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_52;
    // 0x80801590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80801594: beq         $v0, $zero, L_808015CC
    if (ctx->r2 == 0) {
        // 0x80801598: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015CC;
    }
    // 0x80801598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080159C: jal         0x80091A58
    // 0x808015A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_53;
    // 0x808015A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_53:
    // 0x808015A4: beq         $v0, $zero, L_808015B8
    if (ctx->r2 == 0) {
        // 0x808015A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015B8;
    }
    // 0x808015A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015AC: jal         0x8080075C
    // 0x808015B0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8080075C_bsbtrot(rdram, ctx);
        goto after_54;
    // 0x808015B0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_54:
    // 0x808015B4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_808015B8:
    // 0x808015B8: jal         0x8008DF18
    // 0x808015BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_55;
    // 0x808015BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x808015C0: beq         $v0, $zero, L_808015CC
    if (ctx->r2 == 0) {
        // 0x808015C4: addiu       $t6, $zero, 0x45
        ctx->r14 = ADD32(0, 0X45);
            goto L_808015CC;
    }
    // 0x808015C4: addiu       $t6, $zero, 0x45
    ctx->r14 = ADD32(0, 0X45);
    // 0x808015C8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_808015CC:
    // 0x808015CC: jal         0x8008E260
    // 0x808015D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_56;
    // 0x808015D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x808015D4: beq         $v0, $zero, L_808015E4
    if (ctx->r2 == 0) {
        // 0x808015D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015E4;
    }
    // 0x808015D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015DC: addiu       $t7, $zero, 0x3D
    ctx->r15 = ADD32(0, 0X3D);
    // 0x808015E0: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_808015E4:
    // 0x808015E4: jal         0x8009E5C8
    // 0x808015E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_57;
    // 0x808015E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_57:
    // 0x808015EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808015F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808015F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808015F8: jr          $ra
    // 0x808015FC: nop

    return;
    // 0x808015FC: nop

;}
RECOMP_FUNC void _chstarspinnerplanet_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DE8: syscall     243
    recomp_syscall_handler(rdram, ctx, 0x80085DE8);
    return;
    // 0x80085DEC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chpoolkids_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800F8C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800F90: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800F94: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800F98: jal         0x80106790
    // 0x80800F9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800F9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800FA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FA4: jal         0x80100094
    // 0x80800FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800FAC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800FB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800FB4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800FB8: beq         $v1, $at, L_80800FD4
    if (ctx->r3 == ctx->r1) {
        // 0x80800FBC: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_80800FD4;
    }
    // 0x80800FBC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800FC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800FC4: beq         $v1, $at, L_808010B8
    if (ctx->r3 == ctx->r1) {
        // 0x80800FC8: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_808010B8;
    }
    // 0x80800FC8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80800FCC: b           L_80801198
    // 0x80800FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801198;
    // 0x80800FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FD4:
    // 0x80800FD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800FD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800FDC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800FE0: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80800FE4: addu        $v1, $t7, $s0
    ctx->r3 = ADD32(ctx->r15, ctx->r16);
    // 0x80800FE8: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80800FEC: beq         $at, $zero, L_80801194
    if (ctx->r1 == 0) {
        // 0x80800FF0: sub.s       $f0, $f4, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_80801194;
    }
    // 0x80800FF0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
L_80800FF4:
    // 0x80800FF4: lbu         $t8, 0xF($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XF);
    // 0x80800FF8: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800FFC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801000: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80801004: bgez        $t8, L_80801018
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801008: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80801018;
    }
    // 0x80801008: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080100C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801010: nop

    // 0x80801014: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80801018:
    // 0x80801018: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8080101C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801020: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801024: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80801028: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8080102C: nop

    // 0x80801030: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80801034: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80801038: nop

    // 0x8080103C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80801040: beql        $t0, $zero, L_80801090
    if (ctx->r8 == 0) {
        // 0x80801044: mfc1        $t0, $f4
        ctx->r8 = (int32_t)ctx->f4.u32l;
            goto L_80801090;
    }
    goto skip_0;
    // 0x80801044: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x80801048: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080104C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801050: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80801054: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80801058: nop

    // 0x8080105C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80801060: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80801064: nop

    // 0x80801068: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8080106C: bne         $t0, $zero, L_80801084
    if (ctx->r8 != 0) {
        // 0x80801070: nop
    
            goto L_80801084;
    }
    // 0x80801070: nop

    // 0x80801074: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80801078: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080107C: b           L_8080109C
    // 0x80801080: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8080109C;
    // 0x80801080: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80801084:
    // 0x80801084: b           L_8080109C
    // 0x80801088: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8080109C;
    // 0x80801088: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8080108C: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
L_80801090:
    // 0x80801090: nop

    // 0x80801094: bltz        $t0, L_80801084
    if (SIGNED(ctx->r8) < 0) {
        // 0x80801098: nop
    
            goto L_80801084;
    }
    // 0x80801098: nop

L_8080109C:
    // 0x8080109C: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x808010A0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808010A4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x808010A8: bne         $at, $zero, L_80800FF4
    if (ctx->r1 != 0) {
        // 0x808010AC: sb          $t0, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r8;
            goto L_80800FF4;
    }
    // 0x808010AC: sb          $t0, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r8;
    // 0x808010B0: b           L_80801198
    // 0x808010B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801198;
    // 0x808010B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808010B8:
    // 0x808010B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808010BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808010C0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x808010C4: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808010C8: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x808010CC: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x808010D0: beq         $at, $zero, L_80801194
    if (ctx->r1 == 0) {
        // 0x808010D4: sub.s       $f0, $f6, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
            goto L_80801194;
    }
    // 0x808010D4: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
L_808010D8:
    // 0x808010D8: lbu         $t3, 0xF($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XF);
    // 0x808010DC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x808010E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808010E4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x808010E8: bgez        $t3, L_808010FC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808010EC: cvt.s.w     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
            goto L_808010FC;
    }
    // 0x808010EC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808010F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808010F4: nop

    // 0x808010F8: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_808010FC:
    // 0x808010FC: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80801100: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801104: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801108: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8080110C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80801110: nop

    // 0x80801114: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80801118: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8080111C: nop

    // 0x80801120: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80801124: beql        $t5, $zero, L_80801174
    if (ctx->r13 == 0) {
        // 0x80801128: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_80801174;
    }
    goto skip_1;
    // 0x80801128: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x8080112C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801130: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801134: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801138: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8080113C: nop

    // 0x80801140: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801144: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80801148: nop

    // 0x8080114C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80801150: bne         $t5, $zero, L_80801168
    if (ctx->r13 != 0) {
        // 0x80801154: nop
    
            goto L_80801168;
    }
    // 0x80801154: nop

    // 0x80801158: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8080115C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801160: b           L_80801180
    // 0x80801164: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80801180;
    // 0x80801164: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80801168:
    // 0x80801168: b           L_80801180
    // 0x8080116C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80801180;
    // 0x8080116C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801170: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_80801174:
    // 0x80801174: nop

    // 0x80801178: bltz        $t5, L_80801168
    if (SIGNED(ctx->r13) < 0) {
        // 0x8080117C: nop
    
            goto L_80801168;
    }
    // 0x8080117C: nop

L_80801180:
    // 0x80801180: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80801184: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80801188: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8080118C: bne         $at, $zero, L_808010D8
    if (ctx->r1 != 0) {
        // 0x80801190: sb          $t5, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r13;
            goto L_808010D8;
    }
    // 0x80801190: sb          $t5, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r13;
L_80801194:
    // 0x80801194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801198:
    // 0x80801198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080119C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808011A0: jr          $ra
    // 0x808011A4: nop

    return;
    // 0x808011A4: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C9C: jal         0x80802A4C
    // 0x80802CA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802A4C_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80802CA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802CA4: jal         0x8080061C
    // 0x80802CA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080061C_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802CA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80802CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802CB4: jr          $ra
    // 0x80802CB8: nop

    return;
    // 0x80802CB8: nop

;}
RECOMP_FUNC void glsplinenode_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800030: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800034: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800038: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8080003C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800040: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80800044: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x80800048: jal         0x80105494
    // 0x8080004C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x8080004C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800050: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80800054: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x80800058: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8080005C: andi        $t6, $t1, 0x1
    ctx->r14 = ctx->r9 & 0X1;
    // 0x80800060: beql        $t6, $zero, L_808002F0
    if (ctx->r14 == 0) {
        // 0x80800064: lbu         $t9, 0xA($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0XA);
            goto L_808002F0;
    }
    goto skip_0;
    // 0x80800064: lbu         $t9, 0xA($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XA);
    skip_0:
    // 0x80800068: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8080006C: sll         $t7, $v1, 28
    ctx->r15 = S32(ctx->r3 << 28);
    // 0x80800070: srl         $t8, $t7, 29
    ctx->r24 = S32(U32(ctx->r15) >> 29);
    // 0x80800074: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80800078: beq         $at, $zero, L_8080020C
    if (ctx->r1 == 0) {
        // 0x8080007C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8080020C;
    }
    // 0x8080007C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800080: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2718, 0X970) << 16);
    // 0x80800084: addu        $at, $at, $t8
    gpr jr_addend_8080008C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800088: lw          $t8, 0x970($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2718, 0X970));
    // 0x8080008C: jr          $t8
    // 0x80800090: nop

    switch (jr_addend_8080008C >> 2) {
        case 0: goto L_80800094; break;
        case 1: goto L_8080020C; break;
        case 2: goto L_8080020C; break;
        case 3: goto L_8080020C; break;
        case 4: goto L_8080020C; break;
        case 5: goto L_8080020C; break;
        case 6: goto L_808001F4; break;
        case 7: goto L_808000D8; break;
        default: switch_error(__func__, 0x8080008C, 0x80800970);
    }
    // 0x80800090: nop

L_80800094:
    // 0x80800094: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x80800098: beql        $a0, $zero, L_80800210
    if (ctx->r4 == 0) {
        // 0x8080009C: sll         $v0, $t1, 20
        ctx->r2 = S32(ctx->r9 << 20);
            goto L_80800210;
    }
    goto skip_1;
    // 0x8080009C: sll         $v0, $t1, 20
    ctx->r2 = S32(ctx->r9 << 20);
    skip_1:
    // 0x808000A0: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x808000A4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x808000A8: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x808000AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808000B0: srl         $t2, $v1, 11
    ctx->r10 = S32(U32(ctx->r3) >> 11);
    // 0x808000B4: lwc1        $f4, 0x190($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X190);
    // 0x808000B8: sll         $t3, $t2, 19
    ctx->r11 = S32(ctx->r10 << 19);
    // 0x808000BC: srl         $t4, $t3, 8
    ctx->r12 = S32(U32(ctx->r11) >> 8);
    // 0x808000C0: xor         $t5, $t4, $v1
    ctx->r13 = ctx->r12 ^ ctx->r3;
    // 0x808000C4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x808000C8: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x808000CC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x808000D0: b           L_8080020C
    // 0x808000D4: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
        goto L_8080020C;
    // 0x808000D4: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
L_808000D8:
    // 0x808000D8: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x808000DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808000E0: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x808000E4: sll         $t7, $t6, 28
    ctx->r15 = S32(ctx->r14 << 28);
    // 0x808000E8: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x808000EC: bnel        $a0, $t8, L_808001A4
    if (ctx->r4 != ctx->r24) {
        // 0x808000F0: sll         $t7, $t1, 10
        ctx->r15 = S32(ctx->r9 << 10);
            goto L_808001A4;
    }
    goto skip_2;
    // 0x808000F0: sll         $t7, $t1, 10
    ctx->r15 = S32(ctx->r9 << 10);
    skip_2:
    // 0x808000F4: bne         $v0, $zero, L_80800114
    if (ctx->r2 != 0) {
        // 0x808000F8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800114;
    }
    // 0x808000F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000FC: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80800100: lbu         $t2, 0x79($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X79);
    // 0x80800104: andi        $t3, $t2, 0xFFFC
    ctx->r11 = ctx->r10 & 0XFFFC;
    // 0x80800108: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x8080010C: b           L_8080013C
    // 0x80800110: sb          $t4, 0x79($t9)
    MEM_B(0X79, ctx->r25) = ctx->r12;
        goto L_8080013C;
    // 0x80800110: sb          $t4, 0x79($t9)
    MEM_B(0X79, ctx->r25) = ctx->r12;
L_80800114:
    // 0x80800114: bne         $v0, $at, L_80800124
    if (ctx->r2 != ctx->r1) {
        // 0x80800118: lw          $v1, 0x84($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X84);
            goto L_80800124;
    }
    // 0x80800118: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x8080011C: b           L_80800128
    // 0x80800120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800128;
    // 0x80800120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800124:
    // 0x80800124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800128:
    // 0x80800128: lbu         $t7, 0x79($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X79);
    // 0x8080012C: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80800130: andi        $t8, $t7, 0xFFFC
    ctx->r24 = ctx->r15 & 0XFFFC;
    // 0x80800134: or          $t2, $t6, $t8
    ctx->r10 = ctx->r14 | ctx->r24;
    // 0x80800138: sb          $t2, 0x79($v1)
    MEM_B(0X79, ctx->r3) = ctx->r10;
L_8080013C:
    // 0x8080013C: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x80800140: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80800144: andi        $t3, $v0, 0x7FFF
    ctx->r11 = ctx->r2 & 0X7FFF;
    // 0x80800148: beq         $t3, $zero, L_80800184
    if (ctx->r11 == 0) {
        // 0x8080014C: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80800184;
    }
    // 0x8080014C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80800150: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80800154: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800158: bgez        $t3, L_8080016C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8080015C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8080016C;
    }
    // 0x8080015C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800160: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800164: nop

    // 0x80800168: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8080016C:
    // 0x8080016C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800170: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800174: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x80800178: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8080017C: b           L_80800190
    // 0x80800180: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
        goto L_80800190;
    // 0x80800180: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
L_80800184:
    // 0x80800184: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800188: nop

    // 0x8080018C: swc1        $f6, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f6.u32l;
L_80800190:
    // 0x80800190: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800194: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x80800198: swc1        $f8, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f8.u32l;
    // 0x8080019C: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x808001A0: sll         $t7, $t1, 10
    ctx->r15 = S32(ctx->r9 << 10);
L_808001A4:
    // 0x808001A4: srl         $t6, $t7, 31
    ctx->r14 = S32(U32(ctx->r15) >> 31);
    // 0x808001A8: bne         $a0, $t6, L_8080020C
    if (ctx->r4 != ctx->r14) {
        // 0x808001AC: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_8080020C;
    }
    // 0x808001AC: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x808001B0: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x808001B4: lbu         $a3, 0x7($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X7);
    // 0x808001B8: sll         $a0, $t1, 11
    ctx->r4 = S32(ctx->r9 << 11);
    // 0x808001BC: srl         $t8, $a0, 24
    ctx->r24 = S32(U32(ctx->r4) >> 24);
    // 0x808001C0: lbu         $a2, 0x6($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X6);
    // 0x808001C4: addiu       $t9, $t9, -0x7B10
    ctx->r25 = ADD32(ctx->r25, -0X7B10);
    // 0x808001C8: sll         $t2, $a1, 22
    ctx->r10 = S32(ctx->r5 << 22);
    // 0x808001CC: srl         $t4, $a3, 4
    ctx->r12 = S32(U32(ctx->r7) >> 4);
    // 0x808001D0: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x808001D4: srl         $a1, $t2, 26
    ctx->r5 = S32(U32(ctx->r10) >> 26);
    // 0x808001D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808001DC: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x808001E0: jal         0x800C04C8
    // 0x808001E4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800C04C8(rdram, ctx);
        goto after_1;
    // 0x808001E4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x808001E8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x808001EC: b           L_8080020C
    // 0x808001F0: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
        goto L_8080020C;
    // 0x808001F0: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
L_808001F4:
    // 0x808001F4: lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X4);
    // 0x808001F8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x808001FC: jal         0x800DA3B8
    // 0x80800200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_2;
    // 0x80800200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800204: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80800208: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
L_8080020C:
    // 0x8080020C: sll         $v0, $t1, 20
    ctx->r2 = S32(ctx->r9 << 20);
L_80800210:
    // 0x80800210: srl         $t5, $v0, 21
    ctx->r13 = S32(U32(ctx->r2) >> 21);
    // 0x80800214: beq         $t5, $zero, L_80800958
    if (ctx->r13 == 0) {
        // 0x80800218: or          $a0, $t5, $zero
        ctx->r4 = ctx->r13 | 0;
            goto L_80800958;
    }
    // 0x80800218: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8080021C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80800220: addiu       $t2, $sp, 0x58
    ctx->r10 = ADD32(ctx->r29, 0X58);
    // 0x80800224: addiu       $t3, $sp, 0x54
    ctx->r11 = ADD32(ctx->r29, 0X54);
    // 0x80800228: sll         $t6, $t7, 21
    ctx->r14 = S32(ctx->r15 << 21);
    // 0x8080022C: sra         $t8, $t6, 22
    ctx->r24 = S32(SIGNED(ctx->r14) >> 22);
    // 0x80800230: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800234: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80800238: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8080023C: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x80800240: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80800244: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x80800248: jal         0x80088470
    // 0x8080024C: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    _glsplinefuncs_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080024C: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_3:
    // 0x80800250: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80800254: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80800258: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8080025C: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
    // 0x80800260: lh          $t2, 0x2($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X2);
    // 0x80800264: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80800268: andi        $t8, $t6, 0x7FE
    ctx->r24 = ctx->r14 & 0X7FE;
    // 0x8080026C: andi        $t3, $t2, 0xF801
    ctx->r11 = ctx->r10 & 0XF801;
    // 0x80800270: or          $t4, $t8, $t3
    ctx->r12 = ctx->r24 | ctx->r11;
    // 0x80800274: sh          $t4, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r12;
    // 0x80800278: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8080027C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800280: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80800284: swc1        $f16, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f16.u32l;
    // 0x80800288: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x8080028C: jal         0x800EE7F8
    // 0x80800290: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800290: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x80800294: beq         $s0, $zero, L_80800958
    if (ctx->r16 == 0) {
        // 0x80800298: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2718, 0X990) << 16);
            goto L_80800958;
    }
    // 0x80800298: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2718, 0X990) << 16);
    // 0x8080029C: lwc1        $f0, 0x990($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2718, 0X990));
    // 0x808002A0: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808002A4: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x808002A8: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x808002AC: nop

    // 0x808002B0: bc1tl       L_808002C8
    if (c1cs) {
        // 0x808002B4: lwc1        $f4, 0x54($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
            goto L_808002C8;
    }
    goto skip_3;
    // 0x808002B4: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x808002B8: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x808002BC: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x808002C0: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
    // 0x808002C4: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
L_808002C8:
    // 0x808002C8: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x808002CC: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x808002D0: nop

    // 0x808002D4: bc1tl       L_8080095C
    if (c1cs) {
        // 0x808002D8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080095C;
    }
    goto skip_4;
    // 0x808002D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x808002DC: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x808002E0: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x808002E4: b           L_80800958
    // 0x808002E8: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
        goto L_80800958;
    // 0x808002E8: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
    // 0x808002EC: lbu         $t9, 0xA($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XA);
L_808002F0:
    // 0x808002F0: andi        $t5, $t9, 0x1
    ctx->r13 = ctx->r25 & 0X1;
    // 0x808002F4: beql        $t5, $zero, L_80800368
    if (ctx->r13 == 0) {
        // 0x808002F8: lw          $t4, 0x8($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X8);
            goto L_80800368;
    }
    goto skip_5;
    // 0x808002F8: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    skip_5:
    // 0x808002FC: lb          $t6, 0x13($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X13);
    // 0x80800300: sll         $t8, $t1, 20
    ctx->r24 = S32(ctx->r9 << 20);
    // 0x80800304: sll         $t2, $t1, 20
    ctx->r10 = S32(ctx->r9 << 20);
    // 0x80800308: bgez        $t6, L_80800334
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080030C: srl         $t3, $t8, 21
        ctx->r11 = S32(U32(ctx->r24) >> 21);
            goto L_80800334;
    }
    // 0x8080030C: srl         $t3, $t8, 21
    ctx->r11 = S32(U32(ctx->r24) >> 21);
    // 0x80800310: lbu         $t7, 0x26($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X26);
    // 0x80800314: srl         $t8, $t2, 21
    ctx->r24 = S32(U32(ctx->r10) >> 21);
    // 0x80800318: addiu       $t4, $t8, -0x69
    ctx->r12 = ADD32(ctx->r24, -0X69);
    // 0x8080031C: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x80800320: andi        $t5, $t9, 0x1E
    ctx->r13 = ctx->r25 & 0X1E;
    // 0x80800324: andi        $t6, $t7, 0xFFE1
    ctx->r14 = ctx->r15 & 0XFFE1;
    // 0x80800328: or          $t2, $t5, $t6
    ctx->r10 = ctx->r13 | ctx->r14;
    // 0x8080032C: b           L_80800364
    // 0x80800330: sb          $t2, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r10;
        goto L_80800364;
    // 0x80800330: sb          $t2, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r10;
L_80800334:
    // 0x80800334: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80800338: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080033C: bgez        $t3, L_80800350
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800340: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80800350;
    }
    // 0x80800340: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800344: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800348: nop

    // 0x8080034C: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_80800350:
    // 0x80800350: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800354: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800358: nop

    // 0x8080035C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800360: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
L_80800364:
    // 0x80800364: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
L_80800368:
    // 0x80800368: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x8080036C: sll         $t7, $t4, 21
    ctx->r15 = S32(ctx->r12 << 21);
    // 0x80800370: bgezl       $t7, L_80800468
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800374: lw          $a1, 0x4($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X4);
            goto L_80800468;
    }
    goto skip_6;
    // 0x80800374: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    skip_6:
    // 0x80800378: jal         0x80104248
    // 0x8080037C: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_80104248(rdram, ctx);
        goto after_5;
    // 0x8080037C: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_5:
    // 0x80800380: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800384: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80800388: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8080038C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800390: sll         $t6, $t5, 10
    ctx->r14 = S32(ctx->r13 << 10);
    // 0x80800394: srl         $t2, $t6, 21
    ctx->r10 = S32(U32(ctx->r14) >> 21);
    // 0x80800398: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8080039C: bgez        $t2, L_808003B0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808003A0: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_808003B0;
    }
    // 0x808003A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808003A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003A8: nop

    // 0x808003AC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_808003B0:
    // 0x808003B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808003B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003BC: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x808003C0: swc1        $f18, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f18.u32l;
    // 0x808003C4: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x808003C8: srl         $t8, $a0, 22
    ctx->r24 = S32(U32(ctx->r4) >> 22);
    // 0x808003CC: jal         0x8008A688
    // 0x808003D0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    _seqdat_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x808003D0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_6:
    // 0x808003D4: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x808003D8: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x808003DC: lhu         $t7, 0x24($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X24);
    // 0x808003E0: andi        $t5, $t7, 0x1
    ctx->r13 = ctx->r15 & 0X1;
    // 0x808003E4: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x808003E8: sh          $t6, 0x24($t0)
    MEM_H(0X24, ctx->r8) = ctx->r14;
    // 0x808003EC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x808003F0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x808003F4: bnel        $t2, $zero, L_80800418
    if (ctx->r10 != 0) {
        // 0x808003F8: lw          $a1, 0x24($t0)
        ctx->r5 = MEM_W(ctx->r8, 0X24);
            goto L_80800418;
    }
    goto skip_7;
    // 0x808003F8: lw          $a1, 0x24($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X24);
    skip_7:
    // 0x808003FC: jal         0x801042B8
    // 0x80800400: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_801042B8(rdram, ctx);
        goto after_7;
    // 0x80800400: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_7:
    // 0x80800404: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800408: jal         0x8008AF24
    // 0x8080040C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_8;
    // 0x8080040C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800410: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80800414: lw          $a1, 0x24($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X24);
L_80800418:
    // 0x80800418: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x8080041C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800420: srl         $t8, $a1, 17
    ctx->r24 = S32(U32(ctx->r5) >> 17);
    // 0x80800424: jal         0x8008AED4
    // 0x80800428: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    anctrl_setIndex(rdram, ctx);
        goto after_9;
    // 0x80800428: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_9:
    // 0x8080042C: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80800430: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800434: jal         0x8008B1BC
    // 0x80800438: lw          $a1, 0x1C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X1C);
    anctrl_setDuration(rdram, ctx);
        goto after_10;
    // 0x80800438: lw          $a1, 0x1C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X1C);
    after_10:
    // 0x8080043C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800440: jal         0x8008B188
    // 0x80800444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_11;
    // 0x80800444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800448: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8080044C: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80800450: beq         $t3, $zero, L_80800464
    if (ctx->r11 == 0) {
        // 0x80800454: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_80800464;
    }
    // 0x80800454: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80800458: jal         0x8008B064
    // 0x8080045C: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    anctrl_start(rdram, ctx);
        goto after_12;
    // 0x8080045C: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_12:
    // 0x80800460: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
L_80800464:
    // 0x80800464: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
L_80800468:
    // 0x80800468: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x8080046C: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80800470: sll         $t4, $a1, 25
    ctx->r12 = S32(ctx->r5 << 25);
    // 0x80800474: jal         0x800D7754
    // 0x80800478: srl         $a1, $t4, 29
    ctx->r5 = S32(U32(ctx->r12) >> 29);
    func_800D7754(rdram, ctx);
        goto after_13;
    // 0x80800478: srl         $a1, $t4, 29
    ctx->r5 = S32(U32(ctx->r12) >> 29);
    after_13:
    // 0x8080047C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80800480: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80800484: sll         $t9, $v1, 28
    ctx->r25 = S32(ctx->r3 << 28);
    // 0x80800488: srl         $t5, $t9, 29
    ctx->r13 = S32(U32(ctx->r25) >> 29);
    // 0x8080048C: addiu       $t6, $t5, -0x2
    ctx->r14 = ADD32(ctx->r13, -0X2);
    // 0x80800490: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80800494: beq         $at, $zero, L_808005EC
    if (ctx->r1 == 0) {
        // 0x80800498: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808005EC;
    }
    // 0x80800498: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080049C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2718, 0X994) << 16);
    // 0x808004A0: addu        $at, $at, $t6
    gpr jr_addend_808004A8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808004A4: lw          $t6, 0x994($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2718, 0X994));
    // 0x808004A8: jr          $t6
    // 0x808004AC: nop

    switch (jr_addend_808004A8 >> 2) {
        case 0: goto L_808004B0; break;
        case 1: goto L_808004F8; break;
        case 2: goto L_80800540; break;
        case 3: goto L_8080058C; break;
        case 4: goto L_808005D8; break;
        default: switch_error(__func__, 0x808004A8, 0x80800994);
    }
    // 0x808004AC: nop

L_808004B0:
    // 0x808004B0: lwc1        $f0, 0x14($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X14);
    // 0x808004B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808004B8: lbu         $t2, 0x28($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X28);
    // 0x808004BC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808004C0: andi        $t8, $t2, 0xFFF3
    ctx->r24 = ctx->r10 & 0XFFF3;
    // 0x808004C4: sb          $t8, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r24;
    // 0x808004C8: bc1fl       L_808004E0
    if (!c1cs) {
        // 0x808004CC: swc1        $f0, 0x14($t0)
        MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
            goto L_808004E0;
    }
    goto skip_8;
    // 0x808004CC: swc1        $f0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
    skip_8:
    // 0x808004D0: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x808004D4: b           L_808004E0
    // 0x808004D8: swc1        $f6, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f6.u32l;
        goto L_808004E0;
    // 0x808004D8: swc1        $f6, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f6.u32l;
    // 0x808004DC: swc1        $f0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
L_808004E0:
    // 0x808004E0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x808004E4: jal         0x80101D4C
    // 0x808004E8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_80101D4C(rdram, ctx);
        goto after_14;
    // 0x808004E8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_14:
    // 0x808004EC: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x808004F0: b           L_808005EC
    // 0x808004F4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
        goto L_808005EC;
    // 0x808004F4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
L_808004F8:
    // 0x808004F8: lwc1        $f0, 0x14($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X14);
    // 0x808004FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800500: lbu         $t3, 0x28($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X28);
    // 0x80800504: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800508: andi        $t4, $t3, 0xFFF3
    ctx->r12 = ctx->r11 & 0XFFF3;
    // 0x8080050C: sb          $t4, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r12;
    // 0x80800510: bc1fl       L_80800524
    if (!c1cs) {
        // 0x80800514: neg.s       $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
            goto L_80800524;
    }
    goto skip_9;
    // 0x80800514: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    skip_9:
    // 0x80800518: b           L_80800528
    // 0x8080051C: swc1        $f0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
        goto L_80800528;
    // 0x8080051C: swc1        $f0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
    // 0x80800520: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
L_80800524:
    // 0x80800524: swc1        $f8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f8.u32l;
L_80800528:
    // 0x80800528: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x8080052C: jal         0x80101D4C
    // 0x80800530: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_80101D4C(rdram, ctx);
        goto after_15;
    // 0x80800530: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_15:
    // 0x80800534: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80800538: b           L_808005EC
    // 0x8080053C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
        goto L_808005EC;
    // 0x8080053C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
L_80800540:
    // 0x80800540: lwc1        $f0, 0x14($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80800544: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800548: lbu         $t7, 0x28($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X28);
    // 0x8080054C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800550: andi        $t9, $t7, 0xFFF3
    ctx->r25 = ctx->r15 & 0XFFF3;
    // 0x80800554: ori         $t5, $t9, 0x4
    ctx->r13 = ctx->r25 | 0X4;
    // 0x80800558: sb          $t5, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r13;
    // 0x8080055C: bc1fl       L_80800574
    if (!c1cs) {
        // 0x80800560: swc1        $f0, 0x14($t0)
        MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
            goto L_80800574;
    }
    goto skip_10;
    // 0x80800560: swc1        $f0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
    skip_10:
    // 0x80800564: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x80800568: b           L_80800574
    // 0x8080056C: swc1        $f18, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f18.u32l;
        goto L_80800574;
    // 0x8080056C: swc1        $f18, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f18.u32l;
    // 0x80800570: swc1        $f0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
L_80800574:
    // 0x80800574: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80800578: jal         0x80101D7C
    // 0x8080057C: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_80101D7C(rdram, ctx);
        goto after_16;
    // 0x8080057C: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_16:
    // 0x80800580: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80800584: b           L_808005EC
    // 0x80800588: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
        goto L_808005EC;
    // 0x80800588: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
L_8080058C:
    // 0x8080058C: lwc1        $f0, 0x14($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80800590: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800594: lbu         $t6, 0x28($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X28);
    // 0x80800598: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080059C: andi        $t2, $t6, 0xFFF3
    ctx->r10 = ctx->r14 & 0XFFF3;
    // 0x808005A0: ori         $t8, $t2, 0x4
    ctx->r24 = ctx->r10 | 0X4;
    // 0x808005A4: sb          $t8, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r24;
    // 0x808005A8: bc1fl       L_808005BC
    if (!c1cs) {
        // 0x808005AC: neg.s       $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
            goto L_808005BC;
    }
    goto skip_11;
    // 0x808005AC: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    skip_11:
    // 0x808005B0: b           L_808005C0
    // 0x808005B4: swc1        $f0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
        goto L_808005C0;
    // 0x808005B4: swc1        $f0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
    // 0x808005B8: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
L_808005BC:
    // 0x808005BC: swc1        $f6, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f6.u32l;
L_808005C0:
    // 0x808005C0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x808005C4: jal         0x80101D7C
    // 0x808005C8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_80101D7C(rdram, ctx);
        goto after_17;
    // 0x808005C8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_17:
    // 0x808005CC: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x808005D0: b           L_808005EC
    // 0x808005D4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
        goto L_808005EC;
    // 0x808005D4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
L_808005D8:
    // 0x808005D8: lbu         $t3, 0x28($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X28);
    // 0x808005DC: andi        $t4, $t3, 0xFFF3
    ctx->r12 = ctx->r11 & 0XFFF3;
    // 0x808005E0: ori         $t7, $t4, 0x8
    ctx->r15 = ctx->r12 | 0X8;
    // 0x808005E4: sb          $t7, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r15;
    // 0x808005E8: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
L_808005EC:
    // 0x808005EC: sll         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3 << 12);
    // 0x808005F0: srl         $t9, $v0, 30
    ctx->r25 = S32(U32(ctx->r2) >> 30);
    // 0x808005F4: beq         $t9, $zero, L_8080061C
    if (ctx->r25 == 0) {
        // 0x808005F8: sll         $t5, $t9, 1
        ctx->r13 = S32(ctx->r25 << 1);
            goto L_8080061C;
    }
    // 0x808005F8: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x808005FC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2718, 0X9B0) << 16);
    // 0x80800600: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80800604: lh          $t2, 0x9B0($t6)
    ctx->r10 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(2718, 0X9B0));
    // 0x80800608: lbu         $t4, 0x28($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X28);
    // 0x8080060C: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80800610: andi        $t7, $t4, 0xFF1F
    ctx->r15 = ctx->r12 & 0XFF1F;
    // 0x80800614: or          $t9, $t3, $t7
    ctx->r25 = ctx->r11 | ctx->r15;
    // 0x80800618: sb          $t9, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r25;
L_8080061C:
    // 0x8080061C: lw          $t6, 0x28($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X28);
    // 0x80800620: lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X12);
    // 0x80800624: sll         $t2, $t6, 3
    ctx->r10 = S32(ctx->r14 << 3);
    // 0x80800628: srl         $t8, $t2, 31
    ctx->r24 = S32(U32(ctx->r10) >> 31);
    // 0x8080062C: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80800630: beq         $t5, $t8, L_80800650
    if (ctx->r13 == ctx->r24) {
        // 0x80800634: or          $t4, $t5, $zero
        ctx->r12 = ctx->r13 | 0;
            goto L_80800650;
    }
    // 0x80800634: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x80800638: lbu         $t9, 0x28($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X28);
    // 0x8080063C: sll         $t3, $t4, 4
    ctx->r11 = S32(ctx->r12 << 4);
    // 0x80800640: andi        $t7, $t3, 0x10
    ctx->r15 = ctx->r11 & 0X10;
    // 0x80800644: andi        $t5, $t9, 0xFFEF
    ctx->r13 = ctx->r25 & 0XFFEF;
    // 0x80800648: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x8080064C: sb          $t6, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r14;
L_80800650:
    // 0x80800650: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80800654: sll         $t4, $t2, 22
    ctx->r12 = S32(ctx->r10 << 22);
    // 0x80800658: bgezl       $t4, L_80800690
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080065C: lw          $a1, 0x4($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X4);
            goto L_80800690;
    }
    goto skip_12;
    // 0x8080065C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    skip_12:
    // 0x80800660: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80800664: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80800668: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x8080066C: sll         $t3, $a0, 21
    ctx->r11 = S32(ctx->r4 << 21);
    // 0x80800670: sll         $t7, $a2, 9
    ctx->r15 = S32(ctx->r6 << 9);
    // 0x80800674: srl         $a2, $t7, 21
    ctx->r6 = S32(U32(ctx->r15) >> 21);
    // 0x80800678: sra         $a0, $t3, 22
    ctx->r4 = S32(SIGNED(ctx->r11) >> 22);
    // 0x8080067C: jal         0x800D7708
    // 0x80800680: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_800D7708(rdram, ctx);
        goto after_18;
    // 0x80800680: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_18:
    // 0x80800684: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80800688: swc1        $f0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
    // 0x8080068C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
L_80800690:
    // 0x80800690: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x80800694: srl         $t6, $a1, 21
    ctx->r14 = S32(U32(ctx->r5) >> 21);
    // 0x80800698: beq         $t6, $zero, L_808008B8
    if (ctx->r14 == 0) {
        // 0x8080069C: addiu       $a2, $a3, 0x4
        ctx->r6 = ADD32(ctx->r7, 0X4);
            goto L_808008B8;
    }
    // 0x8080069C: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    // 0x808006A0: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x808006A4: lw          $t4, 0x14($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X14);
    // 0x808006A8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x808006AC: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x808006B0: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x808006B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808006B8: addu        $v0, $t8, $a3
    ctx->r2 = ADD32(ctx->r24, ctx->r7);
    // 0x808006BC: srl         $t3, $t4, 21
    ctx->r11 = S32(U32(ctx->r12) >> 21);
    // 0x808006C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808006C4: beq         $t6, $t3, L_808006F8
    if (ctx->r14 == ctx->r11) {
        // 0x808006C8: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_808006F8;
    }
    // 0x808006C8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808006CC: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x808006D0: beql        $at, $zero, L_808006FC
    if (ctx->r1 == 0) {
        // 0x808006D4: lhu         $t6, 0x4($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X4);
            goto L_808006FC;
    }
    goto skip_13;
    // 0x808006D4: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    skip_13:
    // 0x808006D8: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
L_808006DC:
    // 0x808006DC: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x808006E0: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x808006E4: srl         $t7, $t9, 21
    ctx->r15 = S32(U32(ctx->r25) >> 21);
    // 0x808006E8: beql        $a0, $t7, L_808006FC
    if (ctx->r4 == ctx->r15) {
        // 0x808006EC: lhu         $t6, 0x4($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X4);
            goto L_808006FC;
    }
    goto skip_14;
    // 0x808006EC: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    skip_14:
    // 0x808006F0: bnel        $at, $zero, L_808006DC
    if (ctx->r1 != 0) {
        // 0x808006F4: lw          $t9, 0x24($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X24);
            goto L_808006DC;
    }
    goto skip_15;
    // 0x808006F4: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    skip_15:
L_808006F8:
    // 0x808006F8: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
L_808006FC:
    // 0x808006FC: lbu         $t4, 0x44($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X44);
    // 0x80800700: sll         $t2, $t6, 5
    ctx->r10 = S32(ctx->r14 << 5);
    // 0x80800704: andi        $t8, $t2, 0x60
    ctx->r24 = ctx->r10 & 0X60;
    // 0x80800708: andi        $t3, $t4, 0xFF9F
    ctx->r11 = ctx->r12 & 0XFF9F;
    // 0x8080070C: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x80800710: sb          $t7, 0x44($t0)
    MEM_B(0X44, ctx->r8) = ctx->r15;
    // 0x80800714: andi        $t5, $t7, 0x7F
    ctx->r13 = ctx->r15 & 0X7F;
    // 0x80800718: sb          $t5, 0x44($t0)
    MEM_B(0X44, ctx->r8) = ctx->r13;
    // 0x8080071C: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800720: swc1        $f10, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f10.u32l;
    // 0x80800724: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800728: swc1        $f8, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f8.u32l;
    // 0x8080072C: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x80800730: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80800734: andi        $t2, $t6, 0x1
    ctx->r10 = ctx->r14 & 0X1;
    // 0x80800738: beq         $t2, $zero, L_80800830
    if (ctx->r10 == 0) {
        // 0x8080073C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800830;
    }
    // 0x8080073C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800740: lw          $v0, 0x40($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X40);
    // 0x80800744: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80800748: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x8080074C: srl         $t3, $v0, 14
    ctx->r11 = S32(U32(ctx->r2) >> 14);
    // 0x80800750: srl         $t8, $t4, 23
    ctx->r24 = S32(U32(ctx->r12) >> 23);
    // 0x80800754: xor         $t9, $t8, $t3
    ctx->r25 = ctx->r24 ^ ctx->r11;
    // 0x80800758: sll         $t7, $t9, 23
    ctx->r15 = S32(ctx->r25 << 23);
    // 0x8080075C: srl         $t5, $t7, 9
    ctx->r13 = S32(U32(ctx->r15) >> 9);
    // 0x80800760: xor         $t6, $t5, $v0
    ctx->r14 = ctx->r13 ^ ctx->r2;
    // 0x80800764: sw          $t6, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r14;
    // 0x80800768: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x8080076C: lhu         $t9, 0x40($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X40);
    // 0x80800770: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800774: srl         $t4, $t2, 23
    ctx->r12 = S32(U32(ctx->r10) >> 23);
    // 0x80800778: sll         $t3, $t4, 7
    ctx->r11 = S32(ctx->r12 << 7);
    // 0x8080077C: andi        $t7, $t9, 0x7F
    ctx->r15 = ctx->r25 & 0X7F;
    // 0x80800780: or          $t5, $t3, $t7
    ctx->r13 = ctx->r11 | ctx->r15;
    // 0x80800784: sh          $t5, 0x40($t0)
    MEM_H(0X40, ctx->r8) = ctx->r13;
    // 0x80800788: lhu         $t6, 0x6($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6);
    // 0x8080078C: lhu         $t9, 0x42($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X42);
    // 0x80800790: srl         $t2, $t6, 7
    ctx->r10 = S32(U32(ctx->r14) >> 7);
    // 0x80800794: sll         $t4, $t2, 5
    ctx->r12 = S32(ctx->r10 << 5);
    // 0x80800798: andi        $t8, $t4, 0x3FE0
    ctx->r24 = ctx->r12 & 0X3FE0;
    // 0x8080079C: andi        $t3, $t9, 0xC01F
    ctx->r11 = ctx->r25 & 0XC01F;
    // 0x808007A0: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x808007A4: sh          $t7, 0x42($t0)
    MEM_H(0X42, ctx->r8) = ctx->r15;
    // 0x808007A8: lhu         $t5, 0x6($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X6);
    // 0x808007AC: lw          $t7, 0x40($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X40);
    // 0x808007B0: lhu         $t9, 0x44($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X44);
    // 0x808007B4: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x808007B8: sll         $t2, $t6, 4
    ctx->r10 = S32(ctx->r14 << 4);
    // 0x808007BC: sll         $t5, $t7, 9
    ctx->r13 = S32(ctx->r15 << 9);
    // 0x808007C0: srl         $t6, $t5, 23
    ctx->r14 = S32(U32(ctx->r13) >> 23);
    // 0x808007C4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x808007C8: andi        $t4, $t2, 0x1FF0
    ctx->r12 = ctx->r10 & 0X1FF0;
    // 0x808007CC: andi        $t8, $t9, 0xE00F
    ctx->r24 = ctx->r25 & 0XE00F;
    // 0x808007D0: or          $t3, $t4, $t8
    ctx->r11 = ctx->r12 | ctx->r24;
    // 0x808007D4: sh          $t3, 0x44($t0)
    MEM_H(0X44, ctx->r8) = ctx->r11;
    // 0x808007D8: bgez        $t6, L_808007EC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808007DC: cvt.s.w     $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
            goto L_808007EC;
    }
    // 0x808007DC: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808007E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808007E4: nop

    // 0x808007E8: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_808007EC:
    // 0x808007EC: swc1        $f0, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f0.u32l;
    // 0x808007F0: swc1        $f0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f0.u32l;
    // 0x808007F4: lw          $t2, 0x40($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X40);
    // 0x808007F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808007FC: sll         $t9, $t2, 18
    ctx->r25 = S32(ctx->r10 << 18);
    // 0x80800800: srl         $t4, $t9, 23
    ctx->r12 = S32(U32(ctx->r25) >> 23);
    // 0x80800804: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800808: bgez        $t4, L_8080081C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080080C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080081C;
    }
    // 0x8080080C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800810: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800814: nop

    // 0x80800818: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8080081C:
    // 0x8080081C: swc1        $f0, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
    // 0x80800820: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
    // 0x80800824: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x80800828: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8080082C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80800830:
    // 0x80800830: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x80800834: beql        $t3, $zero, L_808008BC
    if (ctx->r11 == 0) {
        // 0x80800838: lw          $v0, 0x24($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X24);
            goto L_808008BC;
    }
    goto skip_16;
    // 0x80800838: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    skip_16:
    // 0x8080083C: lwc1        $f10, 0x14($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80800840: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80800844: swc1        $f10, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f10.u32l;
    // 0x80800848: sll         $t7, $a0, 21
    ctx->r15 = S32(ctx->r4 << 21);
    // 0x8080084C: sra         $a0, $t7, 22
    ctx->r4 = S32(SIGNED(ctx->r15) >> 22);
    // 0x80800850: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x80800854: jal         0x800D7520
    // 0x80800858: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_800D7520(rdram, ctx);
        goto after_19;
    // 0x80800858: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_19:
    // 0x8080085C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80800860: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800864: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800868: jal         0x800C7AE4
    // 0x8080086C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    func_800C7AE4(rdram, ctx);
        goto after_20;
    // 0x8080086C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_20:
    // 0x80800870: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80800874: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80800878: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080087C: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80800880: sll         $t2, $t6, 9
    ctx->r10 = S32(ctx->r14 << 9);
    // 0x80800884: srl         $t9, $t2, 21
    ctx->r25 = S32(U32(ctx->r10) >> 21);
    // 0x80800888: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8080088C: bgez        $t9, L_808008A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800890: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_808008A0;
    }
    // 0x80800890: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800894: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800898: nop

    // 0x8080089C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_808008A0:
    // 0x808008A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808008A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808008A8: nop

    // 0x808008AC: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x808008B0: div.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808008B4: swc1        $f10, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f10.u32l;
L_808008B8:
    // 0x808008B8: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
L_808008BC:
    // 0x808008BC: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x808008C0: sll         $t8, $v0, 18
    ctx->r24 = S32(ctx->r2 << 18);
    // 0x808008C4: bltzl       $t8, L_8080095C
    if (SIGNED(ctx->r24) < 0) {
        // 0x808008C8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080095C;
    }
    goto skip_17;
    // 0x808008C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_17:
    // 0x808008CC: lw          $t3, 0x28($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X28);
    // 0x808008D0: sll         $t5, $v0, 23
    ctx->r13 = S32(ctx->r2 << 23);
    // 0x808008D4: srl         $t6, $t5, 29
    ctx->r14 = S32(U32(ctx->r13) >> 29);
    // 0x808008D8: andi        $t7, $t3, 0x3F
    ctx->r15 = ctx->r11 & 0X3F;
    // 0x808008DC: bnel        $t7, $zero, L_8080095C
    if (ctx->r15 != 0) {
        // 0x808008E0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080095C;
    }
    goto skip_18;
    // 0x808008E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_18:
    // 0x808008E4: bnel        $t6, $zero, L_8080095C
    if (ctx->r14 != 0) {
        // 0x808008E8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080095C;
    }
    goto skip_19;
    // 0x808008E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_19:
    // 0x808008EC: lh          $t9, 0x26($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X26);
    // 0x808008F0: bgezl       $t9, L_80800928
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808008F4: sll         $t7, $v0, 17
        ctx->r15 = S32(ctx->r2 << 17);
            goto L_80800928;
    }
    goto skip_20;
    // 0x808008F4: sll         $t7, $v0, 17
    ctx->r15 = S32(ctx->r2 << 17);
    skip_20:
    // 0x808008F8: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x808008FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800900: srl         $t8, $t4, 23
    ctx->r24 = S32(U32(ctx->r12) >> 23);
    // 0x80800904: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80800908: bgez        $t8, L_8080091C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080090C: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8080091C;
    }
    // 0x8080090C: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800910: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800914: nop

    // 0x80800918: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_8080091C:
    // 0x8080091C: swc1        $f18, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f18.u32l;
    // 0x80800920: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    // 0x80800924: sll         $t7, $v0, 17
    ctx->r15 = S32(ctx->r2 << 17);
L_80800928:
    // 0x80800928: bgezl       $t7, L_8080095C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8080092C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080095C;
    }
    goto skip_21;
    // 0x8080092C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_21:
    // 0x80800930: lhu         $t5, 0x6($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6);
    // 0x80800934: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800938: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x8080093C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800940: bgez        $t6, L_80800954
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800944: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800954;
    }
    // 0x80800944: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800948: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080094C: nop

    // 0x80800950: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80800954:
    // 0x80800954: swc1        $f6, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f6.u32l;
L_80800958:
    // 0x80800958: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080095C:
    // 0x8080095C: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x80800960: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800964: jr          $ra
    // 0x80800968: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80800968: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8080096C: nop

;}
RECOMP_FUNC void func_80800B40_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B50: jal         0x808005DC
    // 0x80800B54: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    bstrexsmall_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800B54: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800B58: jal         0x808002B8
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002B8_bstrexsmall(rdram, ctx);
        goto after_1;
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B60: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    // 0x80800B64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B6C: beq         $v0, $at, L_80800B84
    if (ctx->r2 == ctx->r1) {
        // 0x80800B70: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800B84;
    }
    // 0x80800B70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B74: beq         $v0, $at, L_80800BA4
    if (ctx->r2 == ctx->r1) {
        // 0x80800B78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BA4;
    }
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: b           L_80800BDC
    // 0x80800B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800BDC;
    // 0x80800B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800B84:
    // 0x80800B84: jal         0x8008DF8C
    // 0x80800B88: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_2;
    // 0x80800B88: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_2:
    // 0x80800B8C: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800B90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD8;
    }
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B94: jal         0x80800A24
    // 0x80800B98: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800A24_bstrexsmall(rdram, ctx);
        goto after_3;
    // 0x80800B98: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800B9C: b           L_80800BDC
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800BDC;
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800BA4:
    // 0x80800BA4: jal         0x8009D3A8
    // 0x80800BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_4;
    // 0x80800BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800BAC: jal         0x8008E078
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_5;
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800BB4: beql        $v0, $zero, L_80800BDC
    if (ctx->r2 == 0) {
        // 0x80800BB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BDC;
    }
    goto skip_0;
    // 0x80800BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800BBC: jal         0x800A2E18
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2E18(rdram, ctx);
        goto after_6;
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC8: jal         0x8009B9B0
    // 0x80800BCC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x80800BCC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x80800BD0: addiu       $t6, $zero, 0x13B
    ctx->r14 = ADD32(0, 0X13B);
    // 0x80800BD4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800BD8:
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800BDC:
    // 0x80800BDC: jal         0x8009E5C8
    // 0x80800BE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80800BE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80800BE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800BF0: jr          $ra
    // 0x80800BF4: nop

    return;
    // 0x80800BF4: nop

;}
RECOMP_FUNC void func_8009650C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009650C: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096510: jr          $ra
    // 0x80096514: lbu         $v0, 0x55($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X55);
    return;
    // 0x80096514: lbu         $v0, 0x55($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X55);
;}
RECOMP_FUNC void func_800A3304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A330C: jal         0x800F8B88
    // 0x800A3310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F8B88(rdram, ctx);
        goto after_0;
    // 0x800A3310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A3314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3318: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800A331C: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800A3320: jr          $ra
    // 0x800A3324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800A3324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801D74_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D74: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801D78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801D80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801D84: jal         0x80103D48
    // 0x80801D88: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    func_80103D48(rdram, ctx);
        goto after_0;
    // 0x80801D88: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801D8C: jal         0x80104248
    // 0x80801D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_1;
    // 0x80801D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801D94: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80801D98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801D9C: beq         $v0, $zero, L_80801DC4
    if (ctx->r2 == 0) {
        // 0x80801DA0: sw          $t6, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r14;
            goto L_80801DC4;
    }
    // 0x80801DA0: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x80801DA4: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x80801DA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801DAC: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80801DB0: bltzl       $t9, L_80801DC8
    if (SIGNED(ctx->r25) < 0) {
        // 0x80801DB4: lw          $t0, 0x50($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X50);
            goto L_80801DC8;
    }
    goto skip_0;
    // 0x80801DB4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x80801DB8: jal         0x8008B304
    // 0x80801DBC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    func_8008B304(rdram, ctx);
        goto after_2;
    // 0x80801DBC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_2:
    // 0x80801DC0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
L_80801DC4:
    // 0x80801DC4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
L_80801DC8:
    // 0x80801DC8: lh          $t1, 0x10($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X10);
    // 0x80801DCC: beq         $t1, $zero, L_80801E38
    if (ctx->r9 == 0) {
        // 0x80801DD0: nop
    
            goto L_80801E38;
    }
    // 0x80801DD0: nop

    // 0x80801DD4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80801DD8: jal         0x800B27E0
    // 0x80801DDC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    func_800B27E0(rdram, ctx);
        goto after_3;
    // 0x80801DDC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_3:
    // 0x80801DE0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80801DE4: beql        $a1, $zero, L_80801E28
    if (ctx->r5 == 0) {
        // 0x80801DE8: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80801E28;
    }
    goto skip_1;
    // 0x80801DE8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    skip_1:
    // 0x80801DEC: beql        $v0, $zero, L_80801E28
    if (ctx->r2 == 0) {
        // 0x80801DF0: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80801E28;
    }
    goto skip_2;
    // 0x80801DF0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    skip_2:
    // 0x80801DF4: lw          $t2, 0x7C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C);
    // 0x80801DF8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80801DFC: sll         $t4, $t2, 19
    ctx->r12 = S32(ctx->r10 << 19);
    // 0x80801E00: bltzl       $t4, L_80801E28
    if (SIGNED(ctx->r12) < 0) {
        // 0x80801E04: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80801E28;
    }
    goto skip_3;
    // 0x80801E04: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    skip_3:
    // 0x80801E08: jal         0x8008AEDC
    // 0x80801E0C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_8008AEDC(rdram, ctx);
        goto after_4;
    // 0x80801E0C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80801E10: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80801E14: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80801E18: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801E1C: jal         0x8008C200
    // 0x80801E20: lh          $a0, 0x10($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X10);
    func_8008C200(rdram, ctx);
        goto after_5;
    // 0x80801E20: lh          $a0, 0x10($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X10);
    after_5:
    // 0x80801E24: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_80801E28:
    // 0x80801E28: jal         0x800AE080
    // 0x80801E2C: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_800AE080(rdram, ctx);
        goto after_6;
    // 0x80801E2C: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_6:
    // 0x80801E30: jal         0x800DF72C
    // 0x80801E34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF72C(rdram, ctx);
        goto after_7;
    // 0x80801E34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
L_80801E38:
    // 0x80801E38: jal         0x80089C90
    // 0x80801E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80801E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801E40: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80801E44: beql        $at, $zero, L_80801E60
    if (ctx->r1 == 0) {
        // 0x80801E48: lhu         $a0, 0x7A($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X7A);
            goto L_80801E60;
    }
    goto skip_4;
    // 0x80801E48: lhu         $a0, 0x7A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X7A);
    skip_4:
    // 0x80801E4C: jal         0x80089C90
    // 0x80801E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80801E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801E54: jal         0x800DF410
    // 0x80801E58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF410(rdram, ctx);
        goto after_10;
    // 0x80801E58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x80801E5C: lhu         $a0, 0x7A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X7A);
L_80801E60:
    // 0x80801E60: srl         $t7, $a0, 14
    ctx->r15 = S32(U32(ctx->r4) >> 14);
    // 0x80801E64: jal         0x800DF830
    // 0x80801E68: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800DF830(rdram, ctx);
        goto after_11;
    // 0x80801E68: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_11:
    // 0x80801E6C: jal         0x8008A0F0
    // 0x80801E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieskeleton_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80801E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801E74: jal         0x800DF738
    // 0x80801E78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF738(rdram, ctx);
        goto after_13;
    // 0x80801E78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80801E7C: lw          $t8, 0x7C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X7C);
    // 0x80801E80: sll         $t0, $t8, 19
    ctx->r8 = S32(ctx->r24 << 19);
    // 0x80801E84: bltzl       $t0, L_80801F94
    if (SIGNED(ctx->r8) < 0) {
        // 0x80801E88: lw          $t7, 0x0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X0);
            goto L_80801F94;
    }
    goto skip_5;
    // 0x80801E88: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x80801E8C: jal         0x800B2840
    // 0x80801E90: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    func_800B2840(rdram, ctx);
        goto after_14;
    // 0x80801E90: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_14:
    // 0x80801E94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801E98: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80801E9C: jal         0x800B237C
    // 0x80801EA0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800B237C(rdram, ctx);
        goto after_15;
    // 0x80801EA0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_15:
    // 0x80801EA4: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80801EA8: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801EAC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80801EB0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80801EB4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801EB8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801EBC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801EC0: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80801EC4: nop

    // 0x80801EC8: sh          $t2, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r10;
    // 0x80801ECC: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801ED0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801ED4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80801ED8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801EDC: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80801EE0: nop

    // 0x80801EE4: sh          $t5, 0x20($t3)
    MEM_H(0X20, ctx->r11) = ctx->r13;
    // 0x80801EE8: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801EEC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801EF0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801EF4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80801EF8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80801EFC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80801F00: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80801F04: sh          $t7, 0x22($t3)
    MEM_H(0X22, ctx->r11) = ctx->r15;
    // 0x80801F08: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801F0C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80801F10: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80801F14: nop

    // 0x80801F18: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80801F1C: beql        $t9, $zero, L_80801F6C
    if (ctx->r25 == 0) {
        // 0x80801F20: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_80801F6C;
    }
    goto skip_6;
    // 0x80801F20: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_6:
    // 0x80801F24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801F28: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80801F2C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801F30: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80801F34: nop

    // 0x80801F38: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801F3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80801F40: nop

    // 0x80801F44: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80801F48: bne         $t9, $zero, L_80801F60
    if (ctx->r25 != 0) {
        // 0x80801F4C: nop
    
            goto L_80801F60;
    }
    // 0x80801F4C: nop

    // 0x80801F50: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80801F54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801F58: b           L_80801F78
    // 0x80801F5C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80801F78;
    // 0x80801F5C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80801F60:
    // 0x80801F60: b           L_80801F78
    // 0x80801F64: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80801F78;
    // 0x80801F64: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80801F68: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_80801F6C:
    // 0x80801F6C: nop

    // 0x80801F70: bltz        $t9, L_80801F60
    if (SIGNED(ctx->r25) < 0) {
        // 0x80801F74: nop
    
            goto L_80801F60;
    }
    // 0x80801F74: nop

L_80801F78:
    // 0x80801F78: lhu         $t4, 0x18($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X18);
    // 0x80801F7C: sll         $t2, $t9, 5
    ctx->r10 = S32(ctx->r25 << 5);
    // 0x80801F80: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80801F84: andi        $t5, $t4, 0x1F
    ctx->r13 = ctx->r12 & 0X1F;
    // 0x80801F88: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x80801F8C: sh          $t6, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r14;
    // 0x80801F90: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_80801F94:
    // 0x80801F94: jal         0x800D731C
    // 0x80801F98: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    func_800D731C(rdram, ctx);
        goto after_16;
    // 0x80801F98: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    after_16:
    // 0x80801F9C: beq         $v0, $zero, L_80801FAC
    if (ctx->r2 == 0) {
        // 0x80801FA0: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_80801FAC;
    }
    // 0x80801FA0: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80801FA4: jal         0x800DF7E8
    // 0x80801FA8: nop

    func_800DF7E8(rdram, ctx);
        goto after_17;
    // 0x80801FA8: nop

    after_17:
L_80801FAC:
    // 0x80801FAC: jal         0x80103D70
    // 0x80801FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103D70(rdram, ctx);
        goto after_18;
    // 0x80801FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80801FB4: lbu         $t9, 0x7E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7E);
    // 0x80801FB8: lbu         $a2, 0x79($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X79);
    // 0x80801FBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801FC0: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80801FC4: srl         $t1, $a2, 4
    ctx->r9 = S32(U32(ctx->r6) >> 4);
    // 0x80801FC8: sb          $t0, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r8;
    // 0x80801FCC: beq         $t1, $zero, L_80801FF4
    if (ctx->r9 == 0) {
        // 0x80801FD0: or          $a2, $t1, $zero
        ctx->r6 = ctx->r9 | 0;
            goto L_80801FF4;
    }
    // 0x80801FD0: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80801FD4: beq         $t1, $at, L_80801FF4
    if (ctx->r9 == ctx->r1) {
        // 0x80801FD8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801FF4;
    }
    // 0x80801FD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801FDC: beq         $t1, $at, L_80801FF4
    if (ctx->r9 == ctx->r1) {
        // 0x80801FE0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80801FF4;
    }
    // 0x80801FE0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801FE4: beq         $t1, $at, L_80802020
    if (ctx->r9 == ctx->r1) {
        // 0x80801FE8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80802020;
    }
    // 0x80801FE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801FEC: b           L_80802060
    // 0x80801FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802060;
    // 0x80801FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801FF4:
    // 0x80801FF4: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80801FF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801FFC: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x80802000: bgez        $t5, L_80802010
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80802004: nop
    
            goto L_80802010;
    }
    // 0x80802004: nop

    // 0x80802008: b           L_80802010
    // 0x8080200C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80802010;
    // 0x8080200C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80802010:
    // 0x80802010: jal         0x800DF744
    // 0x80802014: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    func_800DF744(rdram, ctx);
        goto after_19;
    // 0x80802014: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    after_19:
    // 0x80802018: b           L_80802060
    // 0x8080201C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802060;
    // 0x8080201C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802020:
    // 0x80802020: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802028:
    // 0x80802028: jal         0x80016800
    // 0x8080202C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_80016800(rdram, ctx);
        goto after_20;
    // 0x8080202C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_20:
    // 0x80802030: beq         $v0, $zero, L_80802044
    if (ctx->r2 == 0) {
        // 0x80802034: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_80802044;
    }
    // 0x80802034: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80802038: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080203C: sllv        $t3, $t6, $s0
    ctx->r11 = S32(ctx->r14 << (ctx->r16 & 31));
    // 0x80802040: or          $a1, $a1, $t3
    ctx->r5 = ctx->r5 | ctx->r11;
L_80802044:
    // 0x80802044: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80802048: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080204C: bnel        $s0, $at, L_80802028
    if (ctx->r16 != ctx->r1) {
        // 0x80802050: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802028;
    }
    goto skip_7;
    // 0x80802050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_7:
    // 0x80802054: jal         0x800DF7C4
    // 0x80802058: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF7C4(rdram, ctx);
        goto after_21;
    // 0x80802058: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_21:
    // 0x8080205C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802060:
    // 0x80802060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802064: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80802068: jr          $ra
    // 0x8080206C: nop

    return;
    // 0x8080206C: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803338: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080333C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803340: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x80803344: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80803348: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8080334C: bne         $t7, $zero, L_8080335C
    if (ctx->r15 != 0) {
        // 0x80803350: nop
    
            goto L_8080335C;
    }
    // 0x80803350: nop

    // 0x80803354: bne         $a1, $zero, L_80803364
    if (ctx->r5 != 0) {
        // 0x80803358: addiu       $a2, $sp, 0x1C
        ctx->r6 = ADD32(ctx->r29, 0X1C);
            goto L_80803364;
    }
    // 0x80803358: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
L_8080335C:
    // 0x8080335C: b           L_80803370
    // 0x80803360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803370;
    // 0x80803360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803364:
    // 0x80803364: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80803368: jal         0x80803218
    // 0x8080336C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    gczoombox_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080336C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
L_80803370:
    // 0x80803370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803378: jr          $ra
    // 0x8080337C: nop

    return;
    // 0x8080337C: nop

;}
RECOMP_FUNC void _chcamerawibble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086708: syscall     358
    recomp_syscall_handler(rdram, ctx, 0x80086708);
    return;
    // 0x8008670C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800F50D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F50D0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800F50D4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800F50D8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800F50DC: addiu       $s2, $s2, 0x5490
    ctx->r18 = ADD32(ctx->r18, 0X5490);
    // 0x800F50E0: lbu         $t6, 0x48($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X48);
    // 0x800F50E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800F50E8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800F50EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F50F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F50F4: beq         $t6, $zero, L_800F5168
    if (ctx->r14 == 0) {
        // 0x800F50F8: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800F5168;
    }
    // 0x800F50F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F50FC: jal         0x800A89F8
    // 0x800F5100: nop

    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x800F5100: nop

    after_0:
    // 0x800F5104: jal         0x800A8984
    // 0x800F5108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A8984(rdram, ctx);
        goto after_1;
    // 0x800F5108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800F510C: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x800F5110: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F5114: jal         0x800CA7E4
    // 0x800F5118: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800CA7E4(rdram, ctx);
        goto after_2;
    // 0x800F5118: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800F511C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5120: addiu       $a0, $a0, 0x54B8
    ctx->r4 = ADD32(ctx->r4, 0X54B8);
    // 0x800F5124: lbu         $a1, 0x48($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X48);
    // 0x800F5128: jal         0x800854F0
    // 0x800F512C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _bainvisible_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x800F512C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x800F5130: lbu         $t7, 0x48($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X48);
    // 0x800F5134: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800F5138: addiu       $s1, $s1, 0x5490
    ctx->r17 = ADD32(ctx->r17, 0X5490);
    // 0x800F513C: blez        $t7, L_800F5168
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800F5140: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800F5168;
    }
    // 0x800F5140: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800F5144: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
L_800F5148:
    // 0x800F5148: jal         0x80098BA8
    // 0x800F514C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80098BA8(rdram, ctx);
        goto after_4;
    // 0x800F514C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x800F5150: lbu         $t8, 0x48($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X48);
    // 0x800F5154: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800F5158: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800F515C: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800F5160: bnel        $at, $zero, L_800F5148
    if (ctx->r1 != 0) {
        // 0x800F5164: lw          $a0, 0x28($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X28);
            goto L_800F5148;
    }
    goto skip_0;
    // 0x800F5164: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    skip_0:
L_800F5168:
    // 0x800F5168: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800F516C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F5170: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F5174: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800F5178: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800F517C: jr          $ra
    // 0x800F5180: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800F5180: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_808011E0_sumultiscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808011E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808011EC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808011F0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x808011F4: lbu         $t6, 0x1($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1);
    // 0x808011F8: lb          $t8, 0xA($a1)
    ctx->r24 = MEM_B(ctx->r5, 0XA);
    // 0x808011FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801200: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80801204: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x80801208: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8080120C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801210: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80801214: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80801218: lhu         $t2, 0x2($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X2);
    // 0x8080121C: lb          $t1, 0xB($a1)
    ctx->r9 = MEM_B(ctx->r5, 0XB);
    // 0x80801220: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80801224: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80801228: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x8080122C: bnel        $t4, $at, L_808012B8
    if (ctx->r12 != ctx->r1) {
        // 0x80801230: lbu         $t7, 0x5($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X5);
            goto L_808012B8;
    }
    goto skip_0;
    // 0x80801230: lbu         $t7, 0x5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5);
    skip_0:
    // 0x80801234: lbu         $t5, 0x7($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X7);
    // 0x80801238: beql        $t5, $zero, L_8080125C
    if (ctx->r13 == 0) {
        // 0x8080123C: lbu         $a1, 0x5($s0)
        ctx->r5 = MEM_BU(ctx->r16, 0X5);
            goto L_8080125C;
    }
    goto skip_1;
    // 0x8080123C: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    skip_1:
    // 0x80801240: jal         0x8001210C
    // 0x80801244: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80801244: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80801248: beql        $v0, $zero, L_8080125C
    if (ctx->r2 == 0) {
        // 0x8080124C: lbu         $a1, 0x5($s0)
        ctx->r5 = MEM_BU(ctx->r16, 0X5);
            goto L_8080125C;
    }
    goto skip_2;
    // 0x8080124C: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    skip_2:
    // 0x80801250: b           L_80801264
    // 0x80801254: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
        goto L_80801264;
    // 0x80801254: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80801258: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
L_8080125C:
    // 0x8080125C: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80801260: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_80801264:
    // 0x80801264: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801268: jal         0x800B8C98
    // 0x8080126C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800B8C98(rdram, ctx);
        goto after_1;
    // 0x8080126C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x80801270: jal         0x800B8C8C
    // 0x80801274: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800B8C8C(rdram, ctx);
        goto after_2;
    // 0x80801274: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80801278: jal         0x800B80D0
    // 0x8080127C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800B80D0(rdram, ctx);
        goto after_3;
    // 0x8080127C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_3:
    // 0x80801280: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80801284: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3154, 0X1440) << 16);
    // 0x80801288: addiu       $a1, $a1, 0x1440
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3154, 0X1440));
    // 0x8080128C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801290: jal         0x8002DC20
    // 0x80801294: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x80801294: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_4:
    // 0x80801298: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080129C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808012A0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808012A4: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x808012A8: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x808012AC: jal         0x800B8E28
    // 0x808012B0: addiu       $a2, $a2, -0xC
    ctx->r6 = ADD32(ctx->r6, -0XC);
    func_800B8E28(rdram, ctx);
        goto after_5;
    // 0x808012B0: addiu       $a2, $a2, -0xC
    ctx->r6 = ADD32(ctx->r6, -0XC);
    after_5:
    // 0x808012B4: lbu         $t7, 0x5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5);
L_808012B8:
    // 0x808012B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808012BC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808012C0: bgez        $t7, L_808012D4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808012C4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808012D4;
    }
    // 0x808012C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808012C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808012CC: nop

    // 0x808012D0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808012D4:
    // 0x808012D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3154, 0X1498) << 16);
    // 0x808012D8: lwc1        $f10, 0x1498($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3154, 0X1498));
    // 0x808012DC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808012E0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808012E4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808012E8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808012EC: jal         0x800B8C98
    // 0x808012F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800B8C98(rdram, ctx);
        goto after_6;
    // 0x808012F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_6:
    // 0x808012F4: jal         0x800B8C8C
    // 0x808012F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800B8C8C(rdram, ctx);
        goto after_7;
    // 0x808012F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x808012FC: jal         0x800B80D0
    // 0x80801300: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800B80D0(rdram, ctx);
        goto after_8;
    // 0x80801300: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_8:
    // 0x80801304: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3154, 0X144C) << 16);
    // 0x80801308: addiu       $a1, $a1, 0x144C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3154, 0X144C));
    // 0x8080130C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801310: jal         0x8002DC20
    // 0x80801314: lh          $a2, 0x8($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X8);
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x80801314: lh          $a2, 0x8($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X8);
    after_9:
    // 0x80801318: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8080131C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801320: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801324: jal         0x800B8E28
    // 0x80801328: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_800B8E28(rdram, ctx);
        goto after_10;
    // 0x80801328: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_10:
    // 0x8080132C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801330: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801334: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801338: jr          $ra
    // 0x8080133C: nop

    return;
    // 0x8080133C: nop

;}
RECOMP_FUNC void _bstrexlarge_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084058: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084058);
    return;
    // 0x8008405C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void badust_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC70) << 16);
    // 0x80800388: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8080038C: lwc1        $f4, 0xC70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC70));
    // 0x80800390: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800398: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8080039C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808003A0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808003A4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x808003A8: jal         0x8009C128
    // 0x808003AC: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808003AC: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x808003B0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x808003B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003B8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808003BC: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808003C0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808003C4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808003C8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x808003CC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808003D0: jal         0x800EFCD8
    // 0x808003D4: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    func_800EFCD8(rdram, ctx);
        goto after_1;
    // 0x808003D4: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x808003D8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808003DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC74) << 16);
    // 0x808003E4: lwc1        $f18, 0xC74($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC74));
    // 0x808003E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003F0: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808003F4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808003F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808003FC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800400: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80800404: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80800408: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8080040C: jal         0x80800260
    // 0x80800410: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    badust_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800410: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800418: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080041C: jr          $ra
    // 0x80800420: nop

    return;
    // 0x80800420: nop

;}
RECOMP_FUNC void func_800A4D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4D40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4D48: jal         0x800A4C88
    // 0x800A4D4C: nop

    func_800A4C88(rdram, ctx);
        goto after_0;
    // 0x800A4D4C: nop

    after_0:
    // 0x800A4D50: jal         0x8010FAE4
    // 0x800A4D54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FAE4(rdram, ctx);
        goto after_1;
    // 0x800A4D54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A4D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4D5C: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x800A4D60: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800A4D64: jr          $ra
    // 0x800A4D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800A4D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _ncbaclimb_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089258: syscall     768
    recomp_syscall_handler(rdram, ctx, 0x80089258);
    return;
    // 0x8008925C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800FE0_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800FE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800FE8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800FEC: jal         0x808001E0
    // 0x80800FF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800FF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800FF4: lui         $a2, 0x3EB3
    ctx->r6 = S32(0X3EB3 << 16);
    // 0x80800FF8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801000: jal         0x8008CBB0
    // 0x80801004: addiu       $a1, $zero, 0xBC
    ctx->r5 = ADD32(0, 0XBC);
    baanim_playForDuration_loop(rdram, ctx);
        goto after_1;
    // 0x80801004: addiu       $a1, $zero, 0xBC
    ctx->r5 = ADD32(0, 0XBC);
    after_1:
    // 0x80801008: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8080100C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801014: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801018: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080101C: jal         0x8009FFD8
    // 0x80801020: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801020: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801028: jal         0x80093360
    // 0x8080102C: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    func_80093360(rdram, ctx);
        goto after_3;
    // 0x8080102C: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    after_3:
    // 0x80801030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801034: addiu       $a1, $zero, 0x5A3
    ctx->r5 = ADD32(0, 0X5A3);
    // 0x80801038: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080103C: jal         0x8009DF18
    // 0x80801040: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF18(rdram, ctx);
        goto after_4;
    // 0x80801040: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_4:
    // 0x80801044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801048: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080104C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801050: jr          $ra
    // 0x80801054: nop

    return;
    // 0x80801054: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855D8: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855D8);
    return;
    // 0x800855DC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _chlagoonufoint_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A50: syscall     190
    recomp_syscall_handler(rdram, ctx, 0x80085A50);
    return;
    // 0x80085A54: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080010C_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800114: jal         0x80800060
    // 0x80800118: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80800060_chnastycavemen(rdram, ctx);
        goto after_0;
    // 0x80800118: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080011C: beq         $v0, $zero, L_8080012C
    if (ctx->r2 == 0) {
        // 0x80800120: nop
    
            goto L_8080012C;
    }
    // 0x80800120: nop

    // 0x80800124: jal         0x800900D0
    // 0x80800128: addiu       $a0, $zero, 0x1D9
    ctx->r4 = ADD32(0, 0X1D9);
    func_800900D0(rdram, ctx);
        goto after_1;
    // 0x80800128: addiu       $a0, $zero, 0x1D9
    ctx->r4 = ADD32(0, 0X1D9);
    after_1:
L_8080012C:
    // 0x8080012C: jal         0x8008FD48
    // 0x80800130: nop

    func_8008FD48(rdram, ctx);
        goto after_2;
    // 0x80800130: nop

    after_2:
    // 0x80800134: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800138: beq         $v0, $at, L_80800158
    if (ctx->r2 == ctx->r1) {
        // 0x8080013C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80800158;
    }
    // 0x8080013C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800140: beq         $v0, $at, L_80800158
    if (ctx->r2 == ctx->r1) {
        // 0x80800144: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80800158;
    }
    // 0x80800144: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800148: beq         $v0, $at, L_80800180
    if (ctx->r2 == ctx->r1) {
        // 0x8080014C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80800180;
    }
    // 0x8080014C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800150: b           L_80800168
    // 0x80800154: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
        goto L_80800168;
    // 0x80800154: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
L_80800158:
    // 0x80800158: jal         0x800904C8
    // 0x8080015C: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    func_800904C8(rdram, ctx);
        goto after_3;
    // 0x8080015C: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    after_3:
    // 0x80800160: b           L_80800184
    // 0x80800164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800184;
    // 0x80800164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800168:
    // 0x80800168: lh          $a0, 0x75CA($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X75CA);
    // 0x8080016C: jal         0x808000AC
    // 0x80800170: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_808000AC_chnastycavemen(rdram, ctx);
        goto after_4;
    // 0x80800170: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x80800174: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800178: jal         0x80087A58
    // 0x8080017C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x8080017C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
L_80800180:
    // 0x80800180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800184:
    // 0x80800184: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void freelist_is_element_alive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B31B8: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x800B31BC: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800B31C0: beql        $t6, $zero, L_800B31FC
    if (ctx->r14 == 0) {
        // 0x800B31C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800B31FC;
    }
    goto skip_0;
    // 0x800B31C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800B31C8: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
L_800B31CC:
    // 0x800B31CC: bnel        $a1, $a2, L_800B31E0
    if (ctx->r5 != ctx->r6) {
        // 0x800B31D0: lh          $t7, 0x0($a0)
        ctx->r15 = MEM_H(ctx->r4, 0X0);
            goto L_800B31E0;
    }
    goto skip_1;
    // 0x800B31D0: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    skip_1:
    // 0x800B31D4: jr          $ra
    // 0x800B31D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B31D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B31DC: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
L_800B31E0:
    // 0x800B31E0: multu       $a2, $t7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B31E4: mflo        $t8
    ctx->r24 = lo;
    // 0x800B31E8: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x800B31EC: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x800B31F0: bne         $a2, $zero, L_800B31CC
    if (ctx->r6 != 0) {
        // 0x800B31F4: nop
    
            goto L_800B31CC;
    }
    // 0x800B31F4: nop

    // 0x800B31F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B31FC:
    // 0x800B31FC: jr          $ra
    // 0x800B3200: nop

    return;
    // 0x800B3200: nop

;}
RECOMP_FUNC void func_80801A10_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A10: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801A14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801A18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801A1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801A20: jal         0x80100094
    // 0x80801A24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801A24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801A28: jal         0x800D8FF8
    // 0x80801A2C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801A2C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801A30: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801A34: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801A38: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80801A3C: lh          $t6, 0x90($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X90);
    // 0x80801A40: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80801A44: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80801A48: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80801A4C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80801A50: addu        $a1, $v1, $t7
    ctx->r5 = ADD32(ctx->r3, ctx->r15);
    // 0x80801A54: jal         0x800F18FC
    // 0x80801A58: addiu       $a1, $a1, 0xA4
    ctx->r5 = ADD32(ctx->r5, 0XA4);
    func_800F18FC(rdram, ctx);
        goto after_2;
    // 0x80801A58: addiu       $a1, $a1, 0xA4
    ctx->r5 = ADD32(ctx->r5, 0XA4);
    after_2:
    // 0x80801A5C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801A60: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801A64: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801A68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801A6C: add.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80801A70: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x80801A74: mul.s       $f18, $f2, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80801A78: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801A7C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801A80: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80801A84: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x80801A88: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801A8C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80801A90: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801A94: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x80801A98: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80801A9C: jal         0x800F1FF0
    // 0x80801AA0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_3;
    // 0x80801AA0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80801AA4: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801AA8: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801AAC: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80801AB0: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80801AB4: lwc1        $f14, 0x50($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80801AB8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80801ABC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80801AC0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801AC4: jal         0x800F1FF0
    // 0x80801AC8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_4;
    // 0x80801AC8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80801ACC: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80801AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AD4: jal         0x80102CF4
    // 0x80801AD8: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102CF4(rdram, ctx);
        goto after_5;
    // 0x80801AD8: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_5:
    // 0x80801ADC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801AE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801AE4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801AE8: jr          $ra
    // 0x80801AEC: nop

    return;
    // 0x80801AEC: nop

;}
RECOMP_FUNC void func_800F5470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5470: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5478: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F547C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5480: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5484: jal         0x80098590
    // 0x800F5488: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80098590(rdram, ctx);
        goto after_0;
    // 0x800F5488: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F548C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5494: jr          $ra
    // 0x800F5498: nop

    return;
    // 0x800F5498: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D04: lbu         $t8, 0x1C($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1C);
    // 0x80800D08: andi        $t7, $a1, 0x7
    ctx->r15 = ctx->r5 & 0X7;
    // 0x80800D0C: andi        $t9, $t8, 0xFFF8
    ctx->r25 = ctx->r24 & 0XFFF8;
    // 0x80800D10: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800D14: jr          $ra
    // 0x80800D18: sb          $t0, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r8;
    return;
    // 0x80800D18: sb          $t0, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void _chaliendad_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086608: syscall     347
    recomp_syscall_handler(rdram, ctx, 0x80086608);
    return;
    // 0x8008660C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bstaxi_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E60: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E60);
    return;
    // 0x80083E64: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void _bsledge_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837F0: syscall     74
    recomp_syscall_handler(rdram, ctx, 0x800837F0);
    return;
    // 0x800837F4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _sujiggy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6A8: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6A8);
    return;
    // 0x8008A6AC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808009B4_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808009C0: jal         0x8008E124
    // 0x808009C4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_8008E124(rdram, ctx);
        goto after_0;
    // 0x808009C4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808009C8: bne         $v0, $zero, L_808009D4
    if (ctx->r2 != 0) {
        // 0x808009CC: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808009D4;
    }
    // 0x808009CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808009D0: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
L_808009D4:
    // 0x808009D4: jal         0x8009E5C8
    // 0x808009D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x808009D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808009DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009E4: jr          $ra
    // 0x808009E8: nop

    return;
    // 0x808009E8: nop

;}
RECOMP_FUNC void _chboggy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087180: syscall     526
    recomp_syscall_handler(rdram, ctx, 0x80087180);
    return;
    // 0x80087184: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sukickball_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AD8: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AD8);
    return;
    // 0x80089ADC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800E3BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3BFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3C00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800E3C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3C08: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800E3C0C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3C10: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800E3C14: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3C18: jal         0x800CA5F8
    // 0x800E3C1C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800CA5F8(rdram, ctx);
        goto after_0;
    // 0x800E3C1C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x800E3C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3C28: jr          $ra
    // 0x800E3C2C: nop

    return;
    // 0x800E3C2C: nop

;}
RECOMP_FUNC void func_800F48BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F48BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F48C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F48C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F48C8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F48CC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F48D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F48D4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800F48D8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800F48DC: jal         0x800F4200
    // 0x800F48E0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800F4200(rdram, ctx);
        goto after_0;
    // 0x800F48E0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F48E4: jal         0x800D8FF8
    // 0x800F48E8: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x800F48E8: nop

    after_1:
    // 0x800F48EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F48F0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800F48F4: jal         0x800EFA20
    // 0x800F48F8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800EFA20(rdram, ctx);
        goto after_2;
    // 0x800F48F8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x800F48FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800F4900: jal         0x800EF04C
    // 0x800F4904: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x800F4904: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x800F4908: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F490C: jal         0x800F4648
    // 0x800F4910: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F4648(rdram, ctx);
        goto after_4;
    // 0x800F4910: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x800F4914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4918: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800F491C: jr          $ra
    // 0x800F4920: nop

    return;
    // 0x800F4920: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0F8: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A0F8);
    return;
    // 0x8008A0FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
