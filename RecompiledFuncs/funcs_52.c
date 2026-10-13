#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80802588_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080258C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802590: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x80802594: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80802598: beq         $t6, $zero, L_808025B4
    if (ctx->r14 == 0) {
        // 0x8080259C: nop
    
            goto L_808025B4;
    }
    // 0x8080259C: nop

    // 0x808025A0: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x808025A4: jal         0x80088728
    // 0x808025A8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808025A8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808025AC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808025B0: sw          $zero, 0x30($a1)
    MEM_W(0X30, ctx->r5) = 0;
L_808025B4:
    // 0x808025B4: jal         0x80802620
    // 0x808025B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80802620_chgameselect(rdram, ctx);
        goto after_1;
    // 0x808025B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x808025BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808025C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808025C4: jr          $ra
    // 0x808025C8: nop

    return;
    // 0x808025C8: nop

;}
RECOMP_FUNC void func_80800168_chdiggerground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080016C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800170: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800174: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800178: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080017C: jal         0x80100094
    // 0x80800180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800184: bne         $v0, $zero, L_80800194
    if (ctx->r2 != 0) {
        // 0x80800188: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80800194;
    }
    // 0x80800188: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080018C: b           L_808001B8
    // 0x80800190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001B8;
    // 0x80800190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800194:
    // 0x80800194: addiu       $at, $zero, 0xB6
    ctx->r1 = ADD32(0, 0XB6);
    // 0x80800198: bnel        $t6, $at, L_808001AC
    if (ctx->r14 != ctx->r1) {
        // 0x8080019C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808001AC;
    }
    goto skip_0;
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808001A0: jal         0x80800214
    // 0x808001A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800214_chdiggerground(rdram, ctx);
        goto after_1;
    // 0x808001A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808001AC:
    // 0x808001AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808001B0: jal         0x8008A1A0
    // 0x808001B4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _sucoaster_entrypoint_21(rdram, ctx);
        goto after_2;
    // 0x808001B4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
L_808001B8:
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void _chflysaucer_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BF8: syscall     430
    recomp_syscall_handler(rdram, ctx, 0x80086BF8);
    return;
    // 0x80086BFC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800574_idtwinklecolour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800574: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800578: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080057C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800580: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800584: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800588: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080058C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800590: lh          $a1, 0xC($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XC);
    // 0x80800594: jal         0x800DC214
    // 0x80800598: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DC214(rdram, ctx);
        goto after_0;
    // 0x80800598: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8080059C: sh          $v0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r2;
    // 0x808005A0: sh          $zero, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = 0;
    // 0x808005A4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808005A8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808005AC: addiu       $a2, $a2, -0x7138
    ctx->r6 = ADD32(ctx->r6, -0X7138);
    // 0x808005B0: sh          $t6, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r14;
    // 0x808005B4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808005B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808005BC: jal         0x80088670
    // 0x808005C0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808005C0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x808005C4: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    // 0x808005C8: jal         0x800DC214
    // 0x808005CC: lh          $a1, 0x1A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1A);
    func_800DC214(rdram, ctx);
        goto after_2;
    // 0x808005CC: lh          $a1, 0x1A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1A);
    after_2:
    // 0x808005D0: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808005D4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808005D8: addiu       $a2, $a2, -0x7140
    ctx->r6 = ADD32(ctx->r6, -0X7140);
    // 0x808005DC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808005E0: mflo        $t7
    ctx->r15 = lo;
    // 0x808005E4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x808005E8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808005EC: jal         0x80088670
    // 0x808005F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    _glid_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808005F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x808005F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800600: jr          $ra
    // 0x80800604: nop

    return;
    // 0x80800604: nop

;}
RECOMP_FUNC void func_80800CF4_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF4: lw          $v1, 0x164($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X164);
    // 0x80800CF8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800CFC: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x80800D00: bnel        $at, $zero, L_80800D14
    if (ctx->r1 != 0) {
        // 0x80800D04: addu        $t6, $v1, $a3
        ctx->r14 = ADD32(ctx->r3, ctx->r7);
            goto L_80800D14;
    }
    goto skip_0;
    // 0x80800D04: addu        $t6, $v1, $a3
    ctx->r14 = ADD32(ctx->r3, ctx->r7);
    skip_0:
    // 0x80800D08: sw          $zero, 0x164($a0)
    MEM_W(0X164, ctx->r4) = 0;
    // 0x80800D0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800D10: addu        $t6, $v1, $a3
    ctx->r14 = ADD32(ctx->r3, ctx->r7);
L_80800D14:
    // 0x80800D14: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x80800D18: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80800D1C: jr          $ra
    // 0x80800D20: sw          $t7, 0x164($a0)
    MEM_W(0X164, ctx->r4) = ctx->r15;
    return;
    // 0x80800D20: sw          $t7, 0x164($a0)
    MEM_W(0X164, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_808005E0_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808005E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005F0: jal         0x808004D8
    // 0x808005F4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_808004D8_bsledge(rdram, ctx);
        goto after_0;
    // 0x808005F4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x808005F8: jal         0x8008CAEC
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_1;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800600: beq         $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x80800604: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800610;
    }
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800608: addiu       $t6, $zero, 0xA6
    ctx->r14 = ADD32(0, 0XA6);
    // 0x8080060C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_80800610:
    // 0x80800610: lui         $a1, 0x3DFC
    ctx->r5 = S32(0X3DFC << 16);
    // 0x80800614: jal         0x8008CB10
    // 0x80800618: ori         $a1, $a1, 0x84B6
    ctx->r5 = ctx->r5 | 0X84B6;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80800618: ori         $a1, $a1, 0x84B6
    ctx->r5 = ctx->r5 | 0X84B6;
    after_2:
    // 0x8080061C: beq         $v0, $zero, L_80800638
    if (ctx->r2 == 0) {
        // 0x80800620: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800638;
    }
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800624: lui         $a2, 0x3F93
    ctx->r6 = S32(0X3F93 << 16);
    // 0x80800628: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080062C: addiu       $a1, $zero, 0x442C
    ctx->r5 = ADD32(0, 0X442C);
    // 0x80800630: jal         0x8009DF94
    // 0x80800634: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF94(rdram, ctx);
        goto after_3;
    // 0x80800634: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_3:
L_80800638:
    // 0x80800638: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8080063C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800640: jal         0x8008CB10
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800648: beq         $v0, $zero, L_80800664
    if (ctx->r2 == 0) {
        // 0x8080064C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800664;
    }
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80800654: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800658: addiu       $a1, $zero, 0x442C
    ctx->r5 = ADD32(0, 0X442C);
    // 0x8080065C: jal         0x8009DF94
    // 0x80800660: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF94(rdram, ctx);
        goto after_5;
    // 0x80800660: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_5:
L_80800664:
    // 0x80800664: jal         0x8008CAC8
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_6;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080066C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(304, 0X1314) << 16);
    // 0x80800670: lwc1        $f4, 0x1314($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(304, 0X1314));
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080067C: nop

    // 0x80800680: bc1f        L_808006E4
    if (!c1cs) {
        // 0x80800684: nop
    
            goto L_808006E4;
    }
    // 0x80800684: nop

    // 0x80800688: jal         0x80800040
    // 0x8080068C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_80800040_bsledge(rdram, ctx);
        goto after_7;
    // 0x8080068C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_7:
    // 0x80800690: jal         0x800EEF24
    // 0x80800694: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EEF24(rdram, ctx);
        goto after_8;
    // 0x80800694: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_8:
    // 0x80800698: beq         $v0, $zero, L_808006A4
    if (ctx->r2 == 0) {
        // 0x8080069C: addiu       $t7, $zero, 0xA7
        ctx->r15 = ADD32(0, 0XA7);
            goto L_808006A4;
    }
    // 0x8080069C: addiu       $t7, $zero, 0xA7
    ctx->r15 = ADD32(0, 0XA7);
    // 0x808006A0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_808006A4:
    // 0x808006A4: jal         0x808003D0
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003D0_bsledge(rdram, ctx);
        goto after_9;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808006AC: beq         $v0, $zero, L_808006B8
    if (ctx->r2 == 0) {
        // 0x808006B0: addiu       $t8, $zero, 0xAA
        ctx->r24 = ADD32(0, 0XAA);
            goto L_808006B8;
    }
    // 0x808006B0: addiu       $t8, $zero, 0xAA
    ctx->r24 = ADD32(0, 0XAA);
    // 0x808006B4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_808006B8:
    // 0x808006B8: jal         0x80800000
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsledge(rdram, ctx);
        goto after_10;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808006C0: beq         $v0, $zero, L_808006D0
    if (ctx->r2 == 0) {
        // 0x808006C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D0;
    }
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C8: addiu       $t9, $zero, 0xA9
    ctx->r25 = ADD32(0, 0XA9);
    // 0x808006CC: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_808006D0:
    // 0x808006D0: jal         0x80091A58
    // 0x808006D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_11;
    // 0x808006D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808006D8: beq         $v0, $zero, L_808006E4
    if (ctx->r2 == 0) {
        // 0x808006DC: addiu       $t0, $zero, 0x2F
        ctx->r8 = ADD32(0, 0X2F);
            goto L_808006E4;
    }
    // 0x808006DC: addiu       $t0, $zero, 0x2F
    ctx->r8 = ADD32(0, 0X2F);
    // 0x808006E0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_808006E4:
    // 0x808006E4: jal         0x80800410
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800410_bsledge(rdram, ctx);
        goto after_12;
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808006EC: bne         $v0, $zero, L_808006FC
    if (ctx->r2 != 0) {
        // 0x808006F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006FC;
    }
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F4: addiu       $t1, $zero, 0x2F
    ctx->r9 = ADD32(0, 0X2F);
    // 0x808006F8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_808006FC:
    // 0x808006FC: jal         0x8009E5C8
    // 0x80800700: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x80800700: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x80800704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800708: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080070C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800710: jr          $ra
    // 0x80800714: nop

    return;
    // 0x80800714: nop

;}
RECOMP_FUNC void func_808029D8_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808029D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808029DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808029E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808029E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808029E8: jal         0x80106790
    // 0x808029EC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808029EC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808029F0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808029F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808029F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808029FC: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x80802A00: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80802A04: beql        $t9, $at, L_80802A44
    if (ctx->r25 == ctx->r1) {
        // 0x80802A08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802A44;
    }
    goto skip_0;
    // 0x80802A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802A0C: jal         0x808010F8
    // 0x80802A10: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_808010F8_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x80802A10: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802A14: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80802A18: jal         0x80089AF8
    // 0x80802A1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80802A1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80802A20: beq         $v0, $zero, L_80802A40
    if (ctx->r2 == 0) {
        // 0x80802A24: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80802A40;
    }
    // 0x80802A24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802A28: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80802A2C: lui         $a2, 0x427B
    ctx->r6 = S32(0X427B << 16);
    // 0x80802A30: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80802A34: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80802A38: jal         0x80089B00
    // 0x80802A3C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80802A3C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
L_80802A40:
    // 0x80802A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802A44:
    // 0x80802A44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802A48: jr          $ra
    // 0x80802A4C: nop

    return;
    // 0x80802A4C: nop

;}
RECOMP_FUNC void bsledge_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808012B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808012BC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x808012C0: jal         0x800839E0
    // 0x808012C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bsrest_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x808012C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808012C8: beq         $v0, $zero, L_808012D4
    if (ctx->r2 == 0) {
        // 0x808012CC: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_808012D4;
    }
    // 0x808012CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808012D0: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
L_808012D4:
    // 0x808012D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808012D8: jal         0x8009E5C8
    // 0x808012DC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x808012DC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x808012E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808012E8: jr          $ra
    // 0x808012EC: nop

    return;
    // 0x808012EC: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DB0: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DB0);
    return;
    // 0x80082DB4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void sumissilehome_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8080007C: jr          $ra
    // 0x80800080: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
    return;
    // 0x80800080: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_808000F8_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800104: jal         0x80091A58
    // 0x80800108: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80800108: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x8080010C: beq         $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x80800110: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080011C;
    }
    // 0x80800110: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800114: jal         0x800844A8
    // 0x80800118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bababykaz_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_8080011C:
    // 0x8080011C: jal         0x80084488
    // 0x80800120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bababykaz_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080012C: jr          $ra
    // 0x80800130: nop

    return;
    // 0x80800130: nop

;}
RECOMP_FUNC void _gctransitionDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881F0: syscall     674
    recomp_syscall_handler(rdram, ctx, 0x800881F0);
    return;
    // 0x800881F4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800E81D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E81D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E81D4: jr          $ra
    // 0x800E81D8: lw          $v0, -0x2A10($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2A10);
    return;
    // 0x800E81D8: lw          $v0, -0x2A10($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2A10);
    // 0x800E81DC: nop

;}
RECOMP_FUNC void func_80801768_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080176C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80801770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801774: bne         $a1, $at, L_8080178C
    if (ctx->r5 != ctx->r1) {
        // 0x80801778: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080178C;
    }
    // 0x80801778: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080177C: jal         0x80801424
    // 0x80801780: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801424_chfishshootgame(rdram, ctx);
        goto after_0;
    // 0x80801780: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80801784: b           L_80801790
    // 0x80801788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801790;
    // 0x80801788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080178C:
    // 0x8080178C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801790:
    // 0x80801790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801798: jr          $ra
    // 0x8080179C: nop

    return;
    // 0x8080179C: nop

;}
RECOMP_FUNC void func_800931AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800931AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800931B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800931B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800931B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800931BC: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x800931C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800931C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800931C8: lbu         $v1, 0x15($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X15);
    // 0x800931CC: beql        $a1, $v1, L_80093218
    if (ctx->r5 == ctx->r3) {
        // 0x800931D0: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80093218;
    }
    goto skip_0;
    // 0x800931D0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800931D4: beq         $a1, $a0, L_800931E4
    if (ctx->r5 == ctx->r4) {
        // 0x800931D8: nop
    
            goto L_800931E4;
    }
    // 0x800931D8: nop

    // 0x800931DC: bnel        $a0, $v1, L_80093218
    if (ctx->r4 != ctx->r3) {
        // 0x800931E0: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80093218;
    }
    goto skip_1;
    // 0x800931E0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_1:
L_800931E4:
    // 0x800931E4: jal         0x8009C984
    // 0x800931E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_0;
    // 0x800931E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800931EC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800931F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800931F4: jal         0x800136E4
    // 0x800931F8: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x800931F8: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_1:
    // 0x800931FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80093200: jal         0x8009C914
    // 0x80093204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_2;
    // 0x80093204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80093208: jal         0x8009C974
    // 0x8009320C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_3;
    // 0x8009320C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80093210: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80093214: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80093218:
    // 0x80093218: sb          $t7, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r15;
    // 0x8009321C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80093220: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80093224: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80093228: jr          $ra
    // 0x8009322C: nop

    return;
    // 0x8009322C: nop

;}
RECOMP_FUNC void badata_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F90: jal         0x80800388
    // 0x80800F94: nop

    func_80800388_badata(rdram, ctx);
        goto after_0;
    // 0x80800F94: nop

    after_0:
    // 0x80800F98: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80800F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FA0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X1490) << 16);
    // 0x80800FA4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800FA8: lh          $v0, 0x1490($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X1490));
    // 0x80800FAC: jr          $ra
    // 0x80800FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8080126C_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080126C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801270: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801274: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801278: jal         0x808006F0
    // 0x8080127C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080127C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801280: lui         $a2, 0x4046
    ctx->r6 = S32(0X4046 << 16);
    // 0x80801284: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080128C: jal         0x8008CCBC
    // 0x80801290: addiu       $a1, $zero, 0x1D0
    ctx->r5 = ADD32(0, 0X1D0);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80801290: addiu       $a1, $zero, 0x1D0
    ctx->r5 = ADD32(0, 0X1D0);
    after_1:
    // 0x80801294: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801298: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080129C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808012A4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808012A8: jal         0x8009FFD8
    // 0x808012AC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808012AC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x808012B0: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808012B4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808012B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012BC: jal         0x8009C99C
    // 0x808012C0: lui         $a1, 0x425C
    ctx->r5 = S32(0X425C << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x808012C0: lui         $a1, 0x425C
    ctx->r5 = S32(0X425C << 16);
    after_3:
    // 0x808012C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012C8: jal         0x8009B9B0
    // 0x808012CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x808012CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808012D0: jal         0x80801230
    // 0x808012D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801230_bstrexlarge(rdram, ctx);
        goto after_5;
    // 0x808012D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808012D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808012DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808012E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808012E4: jr          $ra
    // 0x808012E8: nop

    return;
    // 0x808012E8: nop

;}
RECOMP_FUNC void func_8010A5B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A5B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A5B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A5B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010A5BC: jal         0x8010A610
    // 0x8010A5C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010A610(rdram, ctx);
        goto after_0;
    // 0x8010A5C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010A5C4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8010A5C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010A5CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010A5D0: beql        $t6, $zero, L_8010A5F0
    if (ctx->r14 == 0) {
        // 0x8010A5D4: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8010A5F0;
    }
    goto skip_0;
    // 0x8010A5D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8010A5D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8010A5DC: lbu         $t8, 0x2A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2A);
    // 0x8010A5E0: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x8010A5E4: b           L_8010A5FC
    // 0x8010A5E8: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
        goto L_8010A5FC;
    // 0x8010A5E8: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    // 0x8010A5EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_8010A5F0:
    // 0x8010A5F0: lbu         $t0, 0x2A($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2A);
    // 0x8010A5F4: andi        $t1, $t0, 0xFFFD
    ctx->r9 = ctx->r8 & 0XFFFD;
    // 0x8010A5F8: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
L_8010A5FC:
    // 0x8010A5FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A604: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8010A608: jr          $ra
    // 0x8010A60C: nop

    return;
    // 0x8010A60C: nop

;}
RECOMP_FUNC void func_80105010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105010: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80105014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80105018: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010501C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80105020: jal         0x80104410
    // 0x80105024: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80104410(rdram, ctx);
        goto after_0;
    // 0x80105024: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80105028: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x8010502C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80105030: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80105034: jal         0x800EE7F8
    // 0x80105038: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80105038: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_1:
    // 0x8010503C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80105040: jal         0x800EE7F8
    // 0x80105044: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80105044: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x80105048: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8010504C: lw          $a1, 0x48($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X48);
    // 0x80105050: jal         0x800EF1B8
    // 0x80105054: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x80105054: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_3:
    // 0x80105058: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8010505C: lw          $a1, 0x48($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X48);
    // 0x80105060: jal         0x800EF1B8
    // 0x80105064: lui         $a2, 0xC2A0
    ctx->r6 = S32(0XC2A0 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x80105064: lui         $a2, 0xC2A0
    ctx->r6 = S32(0XC2A0 << 16);
    after_4:
    // 0x80105068: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8010506C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80105070: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80105074: jal         0x800BEF00
    // 0x80105078: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_5;
    // 0x80105078: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    after_5:
    // 0x8010507C: beq         $v0, $zero, L_8010510C
    if (ctx->r2 == 0) {
        // 0x80105080: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_8010510C;
    }
    // 0x80105080: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80105084: jal         0x80104958
    // 0x80105088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104958(rdram, ctx);
        goto after_6;
    // 0x80105088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8010508C: jal         0x800AAAE0
    // 0x80105090: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800AAAE0(rdram, ctx);
        goto after_7;
    // 0x80105090: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_7:
    // 0x80105094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105098: jal         0x8010486C
    // 0x8010509C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8010486C(rdram, ctx);
        goto after_8;
    // 0x8010509C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x801050A0: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801050A4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801050A8: sb          $t8, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r24;
    // 0x801050AC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801050B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801050B4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x801050B8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801050BC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x801050C0: nop

    // 0x801050C4: sh          $t7, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r15;
    // 0x801050C8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x801050CC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801050D0: jal         0x801049B4
    // 0x801050D4: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    func_801049B4(rdram, ctx);
        goto after_9;
    // 0x801050D4: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    after_9:
    // 0x801050D8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x801050DC: jal         0x80104D80
    // 0x801050E0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_80104D80(rdram, ctx);
        goto after_10;
    // 0x801050E0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_10:
    // 0x801050E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x801050E8: jal         0x80104E24
    // 0x801050EC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80104E24(rdram, ctx);
        goto after_11;
    // 0x801050EC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_11:
    // 0x801050F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801050F4: jal         0x80089CE8
    // 0x801050F8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x801050F8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_12:
    // 0x801050FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80105100: sb          $t1, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r9;
    // 0x80105104: b           L_80105124
    // 0x80105108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80105124;
    // 0x80105108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010510C:
    // 0x8010510C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80105110: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80105114: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80105118: jal         0x80089CF0
    // 0x8010511C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_12(rdram, ctx);
        goto after_13;
    // 0x8010511C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_13:
    // 0x80105120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80105124:
    // 0x80105124: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80105128: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010512C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80105130: jr          $ra
    // 0x80105134: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80105134: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void bsbee_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: jal         0x8009E74C
    // 0x80800014: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800018: bne         $v0, $zero, L_808000A0
    if (ctx->r2 != 0) {
        // 0x8080001C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000A0;
    }
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800024: jal         0x800947EC
    // 0x80800028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_1;
    // 0x80800028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800030: jal         0x8009BF5C
    // 0x80800034: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_2;
    // 0x80800034: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: jal         0x8009C4CC
    // 0x80800040: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_3;
    // 0x80800040: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800044: jal         0x8009EF60
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_4;
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: jal         0x800A0CF4
    // 0x80800054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_5;
    // 0x80800054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: jal         0x800A0CE8
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CE8(rdram, ctx);
        goto after_6;
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: jal         0x80095774
    // 0x8080006C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_clear(rdram, ctx);
        goto after_7;
    // 0x8080006C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: jal         0x80095774
    // 0x80800078: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    baflag_clear(rdram, ctx);
        goto after_8;
    // 0x80800078: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x8080007C: jal         0x8009E474
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_9;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800084: jal         0x80095A40
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_10;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080008C: jal         0x80084558
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babee_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x80092864
    // 0x8080009C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_12;
    // 0x8080009C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_12:
L_808000A0:
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_808006CC_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006DC: jal         0x8008CABC
    // 0x808006E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808006E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808006E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808006E8: jal         0x800852C0
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808006F0: jal         0x800852C8
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808006F8: jal         0x800852D0
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800700: lui         $a1, 0x3F03
    ctx->r5 = S32(0X3F03 << 16);
    // 0x80800704: ori         $a1, $a1, 0x126F
    ctx->r5 = ctx->r5 | 0X126F;
    // 0x80800708: jal         0x8008B348
    // 0x8080070C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x8080070C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800710: beq         $v0, $zero, L_80800728
    if (ctx->r2 == 0) {
        // 0x80800714: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800728;
    }
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800718: jal         0x800852B8
    // 0x8080071C: lui         $a1, 0x43E1
    ctx->r5 = S32(0X43E1 << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x8080071C: lui         $a1, 0x43E1
    ctx->r5 = S32(0X43E1 << 16);
    after_5:
    // 0x80800720: b           L_80800738
    // 0x80800724: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
        goto L_80800738;
    // 0x80800724: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
L_80800728:
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080072C: jal         0x800852B8
    // 0x80800730: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800730: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_6:
    // 0x80800734: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
L_80800738:
    // 0x80800738: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x8080073C: jal         0x8008B348
    // 0x80800740: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x80800740: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80800744: beq         $v0, $zero, L_80800760
    if (ctx->r2 == 0) {
        // 0x80800748: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800760;
    }
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080074C: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x80800750: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800754: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    // 0x80800758: jal         0x8009DF18
    // 0x8080075C: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DF18(rdram, ctx);
        goto after_8;
    // 0x8080075C: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_8:
L_80800760:
    // 0x80800760: lui         $a1, 0x3F2B
    ctx->r5 = S32(0X3F2B << 16);
    // 0x80800764: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80800768: jal         0x8008B348
    // 0x8080076C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x8080076C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x80800770: beq         $v0, $zero, L_8080078C
    if (ctx->r2 == 0) {
        // 0x80800774: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080078C;
    }
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800778: lui         $a2, 0x3FD9
    ctx->r6 = S32(0X3FD9 << 16);
    // 0x8080077C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800780: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    // 0x80800784: jal         0x8009DF18
    // 0x80800788: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DF18(rdram, ctx);
        goto after_10;
    // 0x80800788: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_10:
L_8080078C:
    // 0x8080078C: jal         0x80085280
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800794: beq         $v0, $zero, L_808007C4
    if (ctx->r2 == 0) {
        // 0x80800798: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808007C4;
    }
    // 0x80800798: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080079C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007A0: beq         $v0, $at, L_808007E0
    if (ctx->r2 == ctx->r1) {
        // 0x808007A4: addiu       $t7, $zero, 0x81
        ctx->r15 = ADD32(0, 0X81);
            goto L_808007E0;
    }
    // 0x808007A4: addiu       $t7, $zero, 0x81
    ctx->r15 = ADD32(0, 0X81);
    // 0x808007A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007AC: beq         $v0, $at, L_808007EC
    if (ctx->r2 == ctx->r1) {
        // 0x808007B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808007EC;
    }
    // 0x808007B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808007B4: beq         $v0, $at, L_808007E8
    if (ctx->r2 == ctx->r1) {
        // 0x808007B8: addiu       $t8, $zero, 0x90
        ctx->r24 = ADD32(0, 0X90);
            goto L_808007E8;
    }
    // 0x808007B8: addiu       $t8, $zero, 0x90
    ctx->r24 = ADD32(0, 0X90);
    // 0x808007BC: b           L_808007EC
    // 0x808007C0: nop

        goto L_808007EC;
    // 0x808007C0: nop

L_808007C4:
    // 0x808007C4: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x808007C8: jal         0x8008B348
    // 0x808007CC: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    anctrl_isAt(rdram, ctx);
        goto after_12;
    // 0x808007CC: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    after_12:
    // 0x808007D0: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x808007D4: addiu       $t6, $zero, 0x2B
        ctx->r14 = ADD32(0, 0X2B);
            goto L_808007EC;
    }
    // 0x808007D4: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x808007D8: b           L_808007EC
    // 0x808007DC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_808007EC;
    // 0x808007DC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808007E0:
    // 0x808007E0: b           L_808007EC
    // 0x808007E4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_808007EC;
    // 0x808007E4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808007E8:
    // 0x808007E8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808007EC:
    // 0x808007EC: jal         0x80085278
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808007F4: beq         $v0, $zero, L_80800800
    if (ctx->r2 == 0) {
        // 0x808007F8: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_80800800;
    }
    // 0x808007F8: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x808007FC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800800:
    // 0x80800800: jal         0x8008E35C
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_14;
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800808: bne         $v0, $zero, L_80800818
    if (ctx->r2 != 0) {
        // 0x8080080C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800818;
    }
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800814: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80800818:
    // 0x80800818: jal         0x8009E5C8
    // 0x8080081C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x8080081C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800824: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800828: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080082C: jr          $ra
    // 0x80800830: nop

    return;
    // 0x80800830: nop

;}
RECOMP_FUNC void _badata_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084698: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084698);
    return;
    // 0x8008469C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _badeathmatch_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085508: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x80085508);
    return;
    // 0x8008550C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801928_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801928: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080192C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801930: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801934: jal         0x800A5090
    // 0x80801938: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A5090(rdram, ctx);
        goto after_0;
    // 0x80801938: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080193C: beq         $v0, $zero, L_80801994
    if (ctx->r2 == 0) {
        // 0x80801940: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801994;
    }
    // 0x80801940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801944: lw          $t6, 0x188($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X188);
    // 0x80801948: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8080194C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80801950: jal         0x808015C0
    // 0x80801954: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    func_808015C0_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80801954: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    after_1:
    // 0x80801958: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8080195C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801960: lwc1        $f4, 0x20C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X20C);
    // 0x80801964: jal         0x800A4CA8
    // 0x80801968: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_800A4CA8(rdram, ctx);
        goto after_2;
    // 0x80801968: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8080196C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801970: jal         0x800893F8
    // 0x80801974: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _ncba1p_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80801974: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80801978: jal         0x800A4CA8
    // 0x8080197C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_4;
    // 0x8080197C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801980: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801984: jal         0x80089400
    // 0x80801988: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _ncba1p_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80801988: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x8080198C: jal         0x808019B0
    // 0x80801990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808019B0_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80801990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80801994:
    // 0x80801994: jal         0x808016A0
    // 0x80801998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016A0_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80801998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080199C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808019A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808019A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808019A8: jr          $ra
    // 0x808019AC: nop

    return;
    // 0x808019AC: nop

;}
RECOMP_FUNC void gsworldDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808002B8: lhu         $t7, 0x2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X2);
    // 0x808002BC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x808002C0: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x808002C4: sh          $a1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r5;
    // 0x808002C8: sh          $t7, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r15;
    // 0x808002CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808002D0: jal         0x80088258
    // 0x808002D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _gcsectionDll_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808002D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808002D8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x808002DC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x808002E0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808002E4: sh          $t9, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r25;
    // 0x808002E8: jal         0x800A9EC0
    // 0x808002EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800A9EC0(rdram, ctx);
        goto after_1;
    // 0x808002EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808002F0: jal         0x800D8800
    // 0x808002F4: nop

    func_800D8800(rdram, ctx);
        goto after_2;
    // 0x808002F4: nop

    after_2:
    // 0x808002F8: jal         0x800BC690
    // 0x808002FC: nop

    func_800BC690(rdram, ctx);
        goto after_3;
    // 0x808002FC: nop

    after_3:
    // 0x80800300: jal         0x800E829C
    // 0x80800304: nop

    func_800E829C(rdram, ctx);
        goto after_4;
    // 0x80800304: nop

    after_4:
    // 0x80800308: jal         0x800E8A60
    // 0x8080030C: nop

    func_800E8A60(rdram, ctx);
        goto after_5;
    // 0x8080030C: nop

    after_5:
    // 0x80800310: jal         0x800EA334
    // 0x80800314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800EA334(rdram, ctx);
        goto after_6;
    // 0x80800314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80800318: jal         0x800EA34C
    // 0x8080031C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800EA34C(rdram, ctx);
        goto after_7;
    // 0x8080031C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80800320: jal         0x800D9FFC
    // 0x80800324: nop

    func_800D9FFC(rdram, ctx);
        goto after_8;
    // 0x80800324: nop

    after_8:
    // 0x80800328: jal         0x800A5320
    // 0x8080032C: nop

    func_800A5320(rdram, ctx);
        goto after_9;
    // 0x8080032C: nop

    after_9:
    // 0x80800330: jal         0x800D298C
    // 0x80800334: nop

    func_800D298C(rdram, ctx);
        goto after_10;
    // 0x80800334: nop

    after_10:
    // 0x80800338: jal         0x800A5AB0
    // 0x8080033C: nop

    func_800A5AB0(rdram, ctx);
        goto after_11;
    // 0x8080033C: nop

    after_11:
    // 0x80800340: jal         0x8010052C
    // 0x80800344: nop

    func_8010052C(rdram, ctx);
        goto after_12;
    // 0x80800344: nop

    after_12:
    // 0x80800348: jal         0x80100B3C
    // 0x8080034C: nop

    func_80100B3C(rdram, ctx);
        goto after_13;
    // 0x8080034C: nop

    after_13:
    // 0x80800350: jal         0x800C6A68
    // 0x80800354: nop

    func_800C6A68(rdram, ctx);
        goto after_14;
    // 0x80800354: nop

    after_14:
    // 0x80800358: jal         0x80088F40
    // 0x8080035C: nop

    _idworldmake_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x8080035C: nop

    after_15:
    // 0x80800360: jal         0x800C90AC
    // 0x80800364: nop

    func_800C90AC(rdram, ctx);
        goto after_16;
    // 0x80800364: nop

    after_16:
    // 0x80800368: jal         0x800BF444
    // 0x8080036C: nop

    func_800BF444(rdram, ctx);
        goto after_17;
    // 0x8080036C: nop

    after_17:
    // 0x80800370: jal         0x80087E80
    // 0x80800374: nop

    _gcwater_entrypoint_0(rdram, ctx);
        goto after_18;
    // 0x80800374: nop

    after_18:
    // 0x80800378: jal         0x800C5778
    // 0x8080037C: nop

    func_800C5778(rdram, ctx);
        goto after_19;
    // 0x8080037C: nop

    after_19:
    // 0x80800380: jal         0x80088740
    // 0x80800384: nop

    _gldialog_entrypoint_2(rdram, ctx);
        goto after_20;
    // 0x80800384: nop

    after_20:
    // 0x80800388: jal         0x800D8870
    // 0x8080038C: nop

    func_800D8870(rdram, ctx);
        goto after_21;
    // 0x8080038C: nop

    after_21:
    // 0x80800390: jal         0x800A5C04
    // 0x80800394: nop

    func_800A5C04(rdram, ctx);
        goto after_22;
    // 0x80800394: nop

    after_22:
    // 0x80800398: jal         0x800EBB94
    // 0x8080039C: nop

    func_800EBB94(rdram, ctx);
        goto after_23;
    // 0x8080039C: nop

    after_23:
    // 0x808003A0: jal         0x800E9728
    // 0x808003A4: nop

    func_800E9728(rdram, ctx);
        goto after_24;
    // 0x808003A4: nop

    after_24:
    // 0x808003A8: jal         0x80087AB8
    // 0x808003AC: nop

    _gcgoto_entrypoint_13(rdram, ctx);
        goto after_25;
    // 0x808003AC: nop

    after_25:
    // 0x808003B0: jal         0x800C7A58
    // 0x808003B4: nop

    func_800C7A58(rdram, ctx);
        goto after_26;
    // 0x808003B4: nop

    after_26:
    // 0x808003B8: jal         0x800A55E0
    // 0x808003BC: nop

    func_800A55E0(rdram, ctx);
        goto after_27;
    // 0x808003BC: nop

    after_27:
    // 0x808003C0: jal         0x800B5028
    // 0x808003C4: nop

    func_800B5028(rdram, ctx);
        goto after_28;
    // 0x808003C4: nop

    after_28:
    // 0x808003C8: jal         0x800B5884
    // 0x808003CC: nop

    func_800B5884(rdram, ctx);
        goto after_29;
    // 0x808003CC: nop

    after_29:
    // 0x808003D0: jal         0x800B5B04
    // 0x808003D4: nop

    func_800B5B04(rdram, ctx);
        goto after_30;
    // 0x808003D4: nop

    after_30:
    // 0x808003D8: jal         0x800B7D14
    // 0x808003DC: nop

    func_800B7D14(rdram, ctx);
        goto after_31;
    // 0x808003DC: nop

    after_31:
    // 0x808003E0: jal         0x800BFCBC
    // 0x808003E4: nop

    func_800BFCBC(rdram, ctx);
        goto after_32;
    // 0x808003E4: nop

    after_32:
    // 0x808003E8: jal         0x800BFF4C
    // 0x808003EC: nop

    func_800BFF4C(rdram, ctx);
        goto after_33;
    // 0x808003EC: nop

    after_33:
    // 0x808003F0: jal         0x800AB980
    // 0x808003F4: nop

    func_800AB980(rdram, ctx);
        goto after_34;
    // 0x808003F4: nop

    after_34:
    // 0x808003F8: jal         0x800CB988
    // 0x808003FC: nop

    func_800CB988(rdram, ctx);
        goto after_35;
    // 0x808003FC: nop

    after_35:
    // 0x80800400: jal         0x800BD570
    // 0x80800404: nop

    func_800BD570(rdram, ctx);
        goto after_36;
    // 0x80800404: nop

    after_36:
    // 0x80800408: jal         0x800FA010
    // 0x8080040C: nop

    func_800FA010(rdram, ctx);
        goto after_37;
    // 0x8080040C: nop

    after_37:
    // 0x80800410: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800414: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80800418: beq         $a1, $at, L_80800428
    if (ctx->r5 == ctx->r1) {
        // 0x8080041C: nop
    
            goto L_80800428;
    }
    // 0x8080041C: nop

    // 0x80800420: jal         0x80800000
    // 0x80800424: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    gsworldDll_entrypoint_0(rdram, ctx);
        goto after_38;
    // 0x80800424: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_38:
L_80800428:
    // 0x80800428: jal         0x800BF68C
    // 0x8080042C: nop

    func_800BF68C(rdram, ctx);
        goto after_39;
    // 0x8080042C: nop

    after_39:
    // 0x80800430: jal         0x800D2CD0
    // 0x80800434: nop

    func_800D2CD0(rdram, ctx);
        goto after_40;
    // 0x80800434: nop

    after_40:
    // 0x80800438: jal         0x800D5250
    // 0x8080043C: nop

    func_800D5250(rdram, ctx);
        goto after_41;
    // 0x8080043C: nop

    after_41:
    // 0x80800440: jal         0x800C00BC
    // 0x80800444: nop

    func_800C00BC(rdram, ctx);
        goto after_42;
    // 0x80800444: nop

    after_42:
    // 0x80800448: jal         0x800DA048
    // 0x8080044C: nop

    func_800DA048(rdram, ctx);
        goto after_43;
    // 0x8080044C: nop

    after_43:
    // 0x80800450: jal         0x80088600
    // 0x80800454: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _glintrosyncDll_entrypoint_6(rdram, ctx);
        goto after_44;
    // 0x80800454: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_44:
    // 0x80800458: jal         0x800D7418
    // 0x8080045C: nop

    func_800D7418(rdram, ctx);
        goto after_45;
    // 0x8080045C: nop

    after_45:
    // 0x80800460: jal         0x80088608
    // 0x80800464: nop

    _glhittableDll_entrypoint_0(rdram, ctx);
        goto after_46;
    // 0x80800464: nop

    after_46:
    // 0x80800468: jal         0x8010D790
    // 0x8080046C: nop

    func_8010D790(rdram, ctx);
        goto after_47;
    // 0x8080046C: nop

    after_47:
    // 0x80800470: jal         0x800A5C28
    // 0x80800474: nop

    func_800A5C28(rdram, ctx);
        goto after_48;
    // 0x80800474: nop

    after_48:
    // 0x80800478: jal         0x80088368
    // 0x8080047C: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_49;
    // 0x8080047C: nop

    after_49:
    // 0x80800480: jal         0x800F73C4
    // 0x80800484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F73C4(rdram, ctx);
        goto after_50;
    // 0x80800484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_50:
    // 0x80800488: jal         0x800E1788
    // 0x8080048C: nop

    func_800E1788(rdram, ctx);
        goto after_51;
    // 0x8080048C: nop

    after_51:
    // 0x80800490: jal         0x800FE740
    // 0x80800494: nop

    func_800FE740(rdram, ctx);
        goto after_52;
    // 0x80800494: nop

    after_52:
    // 0x80800498: jal         0x800C73A4
    // 0x8080049C: nop

    func_800C73A4(rdram, ctx);
        goto after_53;
    // 0x8080049C: nop

    after_53:
    // 0x808004A0: jal         0x800858C8
    // 0x808004A4: nop

    _chbounce_entrypoint_0(rdram, ctx);
        goto after_54;
    // 0x808004A4: nop

    after_54:
    // 0x808004A8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x808004AC: jal         0x800A5124
    // 0x808004B0: lh          $a0, 0x8($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X8);
    func_800A5124(rdram, ctx);
        goto after_55;
    // 0x808004B0: lh          $a0, 0x8($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X8);
    after_55:
    // 0x808004B4: jal         0x800B5DFC
    // 0x808004B8: nop

    func_800B5DFC(rdram, ctx);
        goto after_56;
    // 0x808004B8: nop

    after_56:
    // 0x808004BC: jal         0x800A5C94
    // 0x808004C0: nop

    func_800A5C94(rdram, ctx);
        goto after_57;
    // 0x808004C0: nop

    after_57:
    // 0x808004C4: jal         0x800887C8
    // 0x808004C8: nop

    _glcutDll_entrypoint_4(rdram, ctx);
        goto after_58;
    // 0x808004C8: nop

    after_58:
    // 0x808004CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004D4: jr          $ra
    // 0x808004D8: nop

    return;
    // 0x808004D8: nop

;}
RECOMP_FUNC void func_808025C8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808025CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808025D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808025D4: jal         0x800A3280
    // 0x808025D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x808025D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808025DC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x808025E0: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x808025E4: lui         $t7, 0x8081
    ctx->r15 = S32(RELOC_HI16(439, 0XB1B8) << 16);
    // 0x808025E8: addiu       $t7, $t7, -0x4E48
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(439, 0XB1B8));
    // 0x808025EC: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x808025F0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x808025F4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x808025F8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x808025FC: lui         $t0, 0x8081
    ctx->r8 = S32(RELOC_HI16(439, 0XB1E0) << 16);
    // 0x80802600: addiu       $t0, $t0, -0x4E20
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(439, 0XB1E0));
    // 0x80802604: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x80802608: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8080260C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802614: jr          $ra
    // 0x80802618: nop

    return;
    // 0x80802618: nop

;}
RECOMP_FUNC void chbigfoot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1212, 0XC8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1212, 0XC8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1212, 0XC8));
;}
RECOMP_FUNC void _bskazpaddle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083528: syscall     65
    recomp_syscall_handler(rdram, ctx, 0x80083528);
    return;
    // 0x8008352C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008B29C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B29C: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8008B2A0: sll         $t6, $v0, 25
    ctx->r14 = S32(ctx->r2 << 25);
    // 0x8008B2A4: jr          $ra
    // 0x8008B2A8: srl         $v0, $t6, 31
    ctx->r2 = S32(U32(ctx->r14) >> 31);
    return;
    // 0x8008B2A8: srl         $v0, $t6, 31
    ctx->r2 = S32(U32(ctx->r14) >> 31);
;}
RECOMP_FUNC void func_8009DAAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DAAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009DAB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009DAB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DAB8: addiu       $at, $zero, -0x1000
    ctx->r1 = ADD32(0, -0X1000);
    // 0x8009DABC: and         $v1, $v0, $at
    ctx->r3 = ctx->r2 & ctx->r1;
    // 0x8009DAC0: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x8009DAC4: andi        $t6, $v0, 0xFFF
    ctx->r14 = ctx->r2 & 0XFFF;
    // 0x8009DAC8: bne         $v1, $at, L_8009DAF4
    if (ctx->r3 != ctx->r1) {
        // 0x8009DACC: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_8009DAF4;
    }
    // 0x8009DACC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009DAD0: jal         0x8009EA2C
    // 0x8009DAD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8009EA2C(rdram, ctx);
        goto after_0;
    // 0x8009DAD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009DAD8: beq         $v0, $zero, L_8009DAF4
    if (ctx->r2 == 0) {
        // 0x8009DADC: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8009DAF4;
    }
    // 0x8009DADC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DAE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DAE4: lwc1        $f6, 0x538C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X538C);
    // 0x8009DAE8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8009DAEC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009DAF0: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8009DAF4:
    // 0x8009DAF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009DAF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009DAFC: jr          $ra
    // 0x8009DB00: nop

    return;
    // 0x8009DB00: nop

;}
RECOMP_FUNC void func_808000D4_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000E4: jal         0x800F54E4
    // 0x808000E8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808000E8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x808000EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000F0: jal         0x800F7B9C
    // 0x808000F4: addiu       $a1, $zero, 0x7E
    ctx->r5 = ADD32(0, 0X7E);
    func_800F7B9C(rdram, ctx);
        goto after_1;
    // 0x808000F4: addiu       $a1, $zero, 0x7E
    ctx->r5 = ADD32(0, 0X7E);
    after_1:
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: jal         0x80100094
    // 0x80800100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800104: beq         $v0, $zero, L_80800124
    if (ctx->r2 == 0) {
        // 0x80800108: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800124;
    }
    // 0x80800108: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080010C: jal         0x80100094
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800114: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800118: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8080011C: jal         0x800897D8
    // 0x80800120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_80800124:
    // 0x80800124: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800128: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080012C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800130: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80800134: beq         $at, $zero, L_80800300
    if (ctx->r1 == 0) {
        // 0x80800138: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800300;
    }
    // 0x80800138: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8080013C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800140: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1272, 0X840) << 16);
    // 0x80800144: addu        $at, $at, $t7
    gpr jr_addend_8080014C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800148: lw          $t7, 0x840($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1272, 0X840));
    // 0x8080014C: jr          $t7
    // 0x80800150: nop

    switch (jr_addend_8080014C >> 2) {
        case 0: goto L_80800154; break;
        case 1: goto L_808001B0; break;
        case 2: goto L_808001D0; break;
        case 3: goto L_80800230; break;
        case 4: goto L_8080027C; break;
        case 5: goto L_808002EC; break;
        default: switch_error(__func__, 0x8080014C, 0x80800840);
    }
    // 0x80800150: nop

L_80800154:
    // 0x80800154: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800158: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8080015C: jal         0x80800600
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800600_chnicecavemenguard(rdram, ctx);
        goto after_5;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800164: jal         0x800F54E4
    // 0x80800168: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80800168: nop

    after_6:
    // 0x8080016C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800170: jal         0x800F64A4
    // 0x80800174: lui         $a1, 0x6
    ctx->r5 = S32(0X6 << 16);
    func_800F64A4(rdram, ctx);
        goto after_7;
    // 0x80800174: lui         $a1, 0x6
    ctx->r5 = S32(0X6 << 16);
    after_7:
    // 0x80800178: bne         $v0, $zero, L_808001A0
    if (ctx->r2 != 0) {
        // 0x8080017C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001A0;
    }
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1272, 0X968) << 16);
    // 0x80800184: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1272, 0X8C0) << 16);
    // 0x80800188: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8080018C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800190: addiu       $a3, $a3, 0x8C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1272, 0X8C0));
    // 0x80800194: addiu       $a2, $a2, 0x968
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1272, 0X968));
    // 0x80800198: jal         0x8008A1F0
    // 0x8080019C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x8080019C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
L_808001A0:
    // 0x808001A0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808001A4: srl         $t0, $v0, 10
    ctx->r8 = S32(U32(ctx->r2) >> 10);
    // 0x808001A8: b           L_80800300
    // 0x808001AC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80800300;
    // 0x808001AC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_808001B0:
    // 0x808001B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808001B4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x808001B8: jal         0x80800600
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800600_chnicecavemenguard(rdram, ctx);
        goto after_9;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001C0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808001C4: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x808001C8: b           L_80800300
    // 0x808001CC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_80800300;
    // 0x808001CC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_808001D0:
    // 0x808001D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808001D4: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x808001D8: jal         0x80800608
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800608_chnicecavemenguard(rdram, ctx);
        goto after_10;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001E0: jal         0x80101DDC
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_11;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001E8: beql        $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x808001EC: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80800224;
    }
    goto skip_0;
    // 0x808001EC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x808001F0: jal         0x80089D40
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001FC: addiu       $t4, $zero, 0x96
    ctx->r12 = ADD32(0, 0X96);
    // 0x80800200: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800204: addiu       $a1, $zero, 0x17E7
    ctx->r5 = ADD32(0, 0X17E7);
    // 0x80800208: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8080020C: jal         0x8008A208
    // 0x80800210: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80800210: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x80102424
    // 0x8080021C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x8080021C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x80800220: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800224:
    // 0x80800224: srl         $t5, $v0, 10
    ctx->r13 = S32(U32(ctx->r2) >> 10);
    // 0x80800228: b           L_80800300
    // 0x8080022C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80800300;
    // 0x8080022C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80800230:
    // 0x80800230: jal         0x80800730
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800730_chnicecavemenguard(rdram, ctx);
        goto after_15;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800238: jal         0x80101DDC
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_16;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800240: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x80800244: addiu       $a1, $zero, 0x17E8
        ctx->r5 = ADD32(0, 0X17E8);
            goto L_8080026C;
    }
    // 0x80800244: addiu       $a1, $zero, 0x17E8
    ctx->r5 = ADD32(0, 0X17E8);
    // 0x80800248: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080024C: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x80800250: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800254: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800258: jal         0x8008A208
    // 0x8080025C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x8080025C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_17:
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: jal         0x80102424
    // 0x80800268: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x80800268: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_18:
L_8080026C:
    // 0x8080026C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800270: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80800274: b           L_80800300
    // 0x80800278: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80800300;
    // 0x80800278: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8080027C:
    // 0x8080027C: jal         0x8080075C
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080075C_chnicecavemenguard(rdram, ctx);
        goto after_19;
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800284: jal         0x80105854
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105854(rdram, ctx);
        goto after_20;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080028C: jal         0x800F54E4
    // 0x80800290: nop

    func_800F54E4(rdram, ctx);
        goto after_21;
    // 0x80800290: nop

    after_21:
    // 0x80800294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800298: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080029C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x808002A0: jal         0x800F4F34
    // 0x808002A4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    func_800F4F34(rdram, ctx);
        goto after_22;
    // 0x808002A4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_22:
    // 0x808002A8: jal         0x80105A5C
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_23;
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808002B0: beql        $v0, $zero, L_808002E0
    if (ctx->r2 == 0) {
        // 0x808002B4: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_808002E0;
    }
    goto skip_1;
    // 0x808002B4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x808002B8: jal         0x800DA544
    // 0x808002BC: addiu       $a0, $zero, 0x186
    ctx->r4 = ADD32(0, 0X186);
    func_800DA544(rdram, ctx);
        goto after_24;
    // 0x808002BC: addiu       $a0, $zero, 0x186
    ctx->r4 = ADD32(0, 0X186);
    after_24:
    // 0x808002C0: jal         0x80085710
    // 0x808002C4: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_25;
    // 0x808002C4: nop

    after_25:
    // 0x808002C8: jal         0x800F54E4
    // 0x808002CC: nop

    func_800F54E4(rdram, ctx);
        goto after_26;
    // 0x808002CC: nop

    after_26:
    // 0x808002D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D4: jal         0x800F7F98
    // 0x808002D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_27;
    // 0x808002D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x808002DC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808002E0:
    // 0x808002E0: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x808002E4: b           L_80800300
    // 0x808002E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_80800300;
    // 0x808002E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_808002EC:
    // 0x808002EC: jal         0x80800608
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800608_chnicecavemenguard(rdram, ctx);
        goto after_28;
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808002F4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808002F8: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x808002FC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80800300:
    // 0x80800300: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800304: beq         $v0, $at, L_80800334
    if (ctx->r2 == ctx->r1) {
        // 0x80800308: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800334;
    }
    // 0x80800308: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080030C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800310: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x80800314: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80800318: jal         0x80089F18
    // 0x8080031C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_29;
    // 0x8080031C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_29:
    // 0x80800320: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x80800324: beq         $t0, $zero, L_80800334
    if (ctx->r8 == 0) {
        // 0x80800328: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_80800334;
    }
    // 0x80800328: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8080032C: jal         0x80089F38
    // 0x80800330: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _sudeflect_entrypoint_4(rdram, ctx);
        goto after_30;
    // 0x80800330: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_30:
L_80800334:
    // 0x80800334: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80800338: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080033C: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80800340: beq         $t1, $zero, L_80800374
    if (ctx->r9 == 0) {
        // 0x80800344: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1272, 0X978) << 16);
            goto L_80800374;
    }
    // 0x80800344: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1272, 0X978) << 16);
    // 0x80800348: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1272, 0X984) << 16);
    // 0x8080034C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80800350: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800354: addiu       $a3, $a3, 0x984
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1272, 0X984));
    // 0x80800358: jal         0x80089F30
    // 0x8080035C: addiu       $a2, $a2, 0x978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1272, 0X978));
    _sudeflect_entrypoint_3(rdram, ctx);
        goto after_31;
    // 0x8080035C: addiu       $a2, $a2, 0x978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1272, 0X978));
    after_31:
    // 0x80800360: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x80800364: beq         $t3, $zero, L_80800374
    if (ctx->r11 == 0) {
        // 0x80800368: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_80800374;
    }
    // 0x80800368: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8080036C: jal         0x80089F38
    // 0x80800370: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _sudeflect_entrypoint_4(rdram, ctx);
        goto after_32;
    // 0x80800370: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_32:
L_80800374:
    // 0x80800374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800378: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080037C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

;}
RECOMP_FUNC void func_80096500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096500: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096504: jr          $ra
    // 0x80096508: lbu         $v0, 0xA1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA1);
    return;
    // 0x80096508: lbu         $v0, 0xA1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA1);
;}
RECOMP_FUNC void _chbiggafoot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086340: syscall     310
    recomp_syscall_handler(rdram, ctx, 0x80086340);
    return;
    // 0x80086344: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gzreg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A960: syscall     880
    recomp_syscall_handler(rdram, ctx, 0x8008A960);
    return;
    // 0x8008A964: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8010D7EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D7EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010D7F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8010D7F4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8010D7F8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8010D7FC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8010D800: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8010D804: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8010D808: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010D80C: addiu       $s2, $s2, 0x4730
    ctx->r18 = ADD32(ctx->r18, 0X4730);
    // 0x8010D810: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8010D814: addiu       $s4, $zero, 0xD
    ctx->r20 = ADD32(0, 0XD);
L_8010D818:
    // 0x8010D818: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x8010D81C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8010D820: sll         $t7, $s3, 4
    ctx->r15 = S32(ctx->r19 << 4);
    // 0x8010D824: blez        $t6, L_8010D870
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8010D828: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_8010D870;
    }
    // 0x8010D828: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8010D82C: addiu       $t8, $t8, 0x6F90
    ctx->r24 = ADD32(ctx->r24, 0X6F90);
    // 0x8010D830: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x8010D834: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
L_8010D838:
    // 0x8010D838: beql        $a0, $zero, L_8010D85C
    if (ctx->r4 == 0) {
        // 0x8010D83C: lbu         $t9, 0x0($s2)
        ctx->r25 = MEM_BU(ctx->r18, 0X0);
            goto L_8010D85C;
    }
    goto skip_0;
    // 0x8010D83C: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    skip_0:
    // 0x8010D840: jal         0x800C3D78
    // 0x8010D844: nop

    func_800C3D78(rdram, ctx);
        goto after_0;
    // 0x8010D844: nop

    after_0:
    // 0x8010D848: bnel        $v0, $zero, L_8010D85C
    if (ctx->r2 != 0) {
        // 0x8010D84C: lbu         $t9, 0x0($s2)
        ctx->r25 = MEM_BU(ctx->r18, 0X0);
            goto L_8010D85C;
    }
    goto skip_1;
    // 0x8010D84C: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    skip_1:
    // 0x8010D850: jal         0x8010DA30
    // 0x8010D854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010DA30(rdram, ctx);
        goto after_1;
    // 0x8010D854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8010D858: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
L_8010D85C:
    // 0x8010D85C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8010D860: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8010D864: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8010D868: bnel        $at, $zero, L_8010D838
    if (ctx->r1 != 0) {
        // 0x8010D86C: lbu         $a0, 0x0($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X0);
            goto L_8010D838;
    }
    goto skip_2;
    // 0x8010D86C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    skip_2:
L_8010D870:
    // 0x8010D870: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8010D874: bne         $s3, $s4, L_8010D818
    if (ctx->r19 != ctx->r20) {
        // 0x8010D878: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8010D818;
    }
    // 0x8010D878: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8010D87C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8010D880: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010D884: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8010D888: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8010D88C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8010D890: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8010D894: jr          $ra
    // 0x8010D898: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8010D898: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800FE890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE890: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FE894: jr          $ra
    // 0x800FE898: lbu         $v0, 0x59CE($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X59CE);
    return;
    // 0x800FE898: lbu         $v0, 0x59CE($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X59CE);
;}
RECOMP_FUNC void func_80800DD0_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800DD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DD8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800DDC: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800DE0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800DE4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800DE8: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800DEC: beq         $t6, $at, L_80800EC4
    if (ctx->r14 == ctx->r1) {
        // 0x80800DF0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800EC4;
    }
    // 0x80800DF0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800DF4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800DF8: bne         $t6, $at, L_80800E38
    if (ctx->r14 != ctx->r1) {
        // 0x80800DFC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80800E38;
    }
    // 0x80800DFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800E00: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800E04: addiu       $at, $zero, 0x2C2
    ctx->r1 = ADD32(0, 0X2C2);
    // 0x80800E08: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80800E0C: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x80800E10: bne         $t9, $at, L_80800E24
    if (ctx->r25 != ctx->r1) {
        // 0x80800E14: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_80800E24;
    }
    // 0x80800E14: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800E18: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800E1C: b           L_80800E60
    // 0x80800E20: nop

        goto L_80800E60;
    // 0x80800E20: nop

L_80800E24:
    // 0x80800E24: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800E28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800E2C: nop

    // 0x80800E30: b           L_80800E60
    // 0x80800E34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800E60;
    // 0x80800E34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800E38:
    // 0x80800E38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E3C: bne         $v0, $at, L_80800E50
    if (ctx->r2 != ctx->r1) {
        // 0x80800E40: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80800E50;
    }
    // 0x80800E40: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800E44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800E48: b           L_80800E60
    // 0x80800E4C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800E60;
    // 0x80800E4C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800E50:
    // 0x80800E50: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800E54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800E58: nop

    // 0x80800E5C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800E60:
    // 0x80800E60: bne         $v1, $v0, L_80800E78
    if (ctx->r3 != ctx->r2) {
        // 0x80800E64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E78;
    }
    // 0x80800E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E68: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800E6C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800E70: b           L_80800E84
    // 0x80800E74: nop

        goto L_80800E84;
    // 0x80800E74: nop

L_80800E78:
    // 0x80800E78: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800E7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800E80: nop

L_80800E84:
    // 0x80800E84: bne         $v1, $v0, L_80800E9C
    if (ctx->r3 != ctx->r2) {
        // 0x80800E88: addiu       $a1, $s0, 0x18
        ctx->r5 = ADD32(ctx->r16, 0X18);
            goto L_80800E9C;
    }
    // 0x80800E88: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800E8C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800E90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800E94: b           L_80800EAC
    // 0x80800E98: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
        goto L_80800EAC;
    // 0x80800E98: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_80800E9C:
    // 0x80800E9C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800EA0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800EA4: nop

    // 0x80800EA8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_80800EAC:
    // 0x80800EAC: addiu       $a3, $s0, 0x2C
    ctx->r7 = ADD32(ctx->r16, 0X2C);
    // 0x80800EB0: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x80800EB4: jal         0x80800CEC
    // 0x80800EB8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80800CEC_chpiranha(rdram, ctx);
        goto after_0;
    // 0x80800EB8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80800EBC: b           L_80800EEC
    // 0x80800EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800EEC;
    // 0x80800EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800EC4:
    // 0x80800EC4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800EC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800ED4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800ED8: addiu       $a3, $s0, 0x2C
    ctx->r7 = ADD32(ctx->r16, 0X2C);
    // 0x80800EDC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800EE0: jal         0x80800CEC
    // 0x80800EE4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80800CEC_chpiranha(rdram, ctx);
        goto after_1;
    // 0x80800EE4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800EE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800EEC:
    // 0x80800EEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800EF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800EF4: jr          $ra
    // 0x80800EF8: nop

    return;
    // 0x80800EF8: nop

;}
RECOMP_FUNC void _seqdefine_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082668: syscall     4
    recomp_syscall_handler(rdram, ctx, 0x80082668);
    return;
    // 0x8008266C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _basnowball_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850F0: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x800850F0);
    return;
    // 0x800850F4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void mlspline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800194: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800198: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8080019C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808001A0: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x808001A4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001A8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808001AC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808001B0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808001B4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x808001B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001BC: jal         0x800F0D50
    // 0x808001C0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_800F0D50(rdram, ctx);
        goto after_0;
    // 0x808001C0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x808001C4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x808001C8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x808001CC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x808001D0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808001D4: nop

    // 0x808001D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001DC: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808001E0: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x808001E4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x808001E8: nop

    // 0x808001EC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x808001F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808001F4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x808001F8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808001FC: bne         $v0, $zero, L_808002BC
    if (ctx->r2 != 0) {
        // 0x80800200: sub.s       $f20, $f2, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_808002BC;
    }
    // 0x80800200: sub.s       $f20, $f2, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80800204: beq         $at, $zero, L_80800504
    if (ctx->r1 == 0) {
        // 0x80800208: sll         $a0, $a1, 2
        ctx->r4 = S32(ctx->r5 << 2);
            goto L_80800504;
    }
    // 0x80800208: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8080020C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800210: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800214: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800218: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080021C: addu        $v1, $s0, $a0
    ctx->r3 = ADD32(ctx->r16, ctx->r4);
    // 0x80800220: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
L_80800224:
    // 0x80800224: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800228: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8080022C: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800230: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800234: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80800238: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x8080023C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800240: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80800244: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80800248: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080024C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800250: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80800254: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80800258: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8080025C: nop

    // 0x80800260: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80800264: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80800268: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8080026C: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800270: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80800274: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800278: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080027C: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80800280: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800284: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800288: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8080028C: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800290: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800294: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800298: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080029C: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x808002A0: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x808002A4: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808002A8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x808002AC: bne         $at, $zero, L_80800224
    if (ctx->r1 != 0) {
        // 0x808002B0: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80800224;
    }
    // 0x808002B0: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x808002B4: b           L_80800508
    // 0x808002B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800508;
    // 0x808002B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002BC:
    // 0x808002BC: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x808002C0: addiu       $t0, $a1, 0x2
    ctx->r8 = ADD32(ctx->r5, 0X2);
    // 0x808002C4: bne         $v1, $t0, L_808002F0
    if (ctx->r3 != ctx->r8) {
        // 0x808002C8: sll         $t4, $a1, 2
        ctx->r12 = S32(ctx->r5 << 2);
            goto L_808002F0;
    }
    // 0x808002C8: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x808002CC: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x808002D0: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x808002D4: addiu       $t2, $t1, -0x3
    ctx->r10 = ADD32(ctx->r9, -0X3);
    // 0x808002D8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x808002DC: addu        $a1, $s0, $t3
    ctx->r5 = ADD32(ctx->r16, ctx->r11);
    // 0x808002E0: jal         0x800EE7F8
    // 0x808002E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808002E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x808002E8: b           L_80800508
    // 0x808002EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800508;
    // 0x808002EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002F0:
    // 0x808002F0: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x808002F4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x808002F8: addiu       $t6, $a1, 0x3
    ctx->r14 = ADD32(ctx->r5, 0X3);
    // 0x808002FC: bne         $v1, $t6, L_808003B0
    if (ctx->r3 != ctx->r14) {
        // 0x80800300: addu        $s0, $s0, $t5
        ctx->r16 = ADD32(ctx->r16, ctx->r13);
            goto L_808003B0;
    }
    // 0x80800300: addu        $s0, $s0, $t5
    ctx->r16 = ADD32(ctx->r16, ctx->r13);
    // 0x80800304: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800308: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080030C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800310: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800314: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800318: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080031C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800320: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80800324: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80800328: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_8080032C:
    // 0x8080032C: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800330: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800334: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800338: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080033C: mul.s       $f8, $f12, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x80800340: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800344: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800348: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8080034C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800350: sub.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80800354: mul.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80800358: sub.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8080035C: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800360: add.s       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80800364: add.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800368: mul.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8080036C: add.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80800370: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800374: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800378: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8080037C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800380: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800384: add.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800388: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8080038C: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800390: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800394: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800398: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080039C: add.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x808003A0: bne         $a0, $a1, L_8080032C
    if (ctx->r4 != ctx->r5) {
        // 0x808003A4: swc1        $f12, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f12.u32l;
            goto L_8080032C;
    }
    // 0x808003A4: swc1        $f12, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f12.u32l;
    // 0x808003A8: b           L_80800508
    // 0x808003AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800508;
    // 0x808003AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003B0:
    // 0x808003B0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x808003B4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808003B8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808003BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808003C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003CC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x808003D0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x808003D4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x808003D8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808003DC: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808003E0: beq         $a0, $a1, L_80800480
    if (ctx->r4 == ctx->r5) {
        // 0x808003E4: lwc1        $f16, 0x24($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X24);
            goto L_80800480;
    }
    // 0x808003E4: lwc1        $f16, 0x24($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X24);
L_808003E8:
    // 0x808003E8: sub.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x808003EC: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808003F0: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x808003F4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808003F8: mul.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x808003FC: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80800400: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800404: mul.s       $f2, $f8, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80800408: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080040C: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80800410: sub.s       $f2, $f12, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80800414: mul.s       $f0, $f16, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80800418: add.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8080041C: add.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f6.fl;
    // 0x80800420: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80800424: add.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80800428: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8080042C: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800430: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80800434: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80800438: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080043C: mul.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80800440: nop

    // 0x80800444: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800448: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8080044C: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800450: add.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800454: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800458: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080045C: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800460: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800464: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800468: add.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080046C: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80800470: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800474: lwc1        $f16, 0x24($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80800478: bne         $a0, $a1, L_808003E8
    if (ctx->r4 != ctx->r5) {
        // 0x8080047C: nop
    
            goto L_808003E8;
    }
    // 0x8080047C: nop

L_80800480:
    // 0x80800480: sub.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80800484: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800488: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8080048C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800490: mul.s       $f10, $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80800494: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80800498: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080049C: mul.s       $f2, $f8, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x808004A0: nop

    // 0x808004A4: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x808004A8: sub.s       $f2, $f12, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x808004AC: mul.s       $f0, $f16, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x808004B0: add.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x808004B4: add.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f6.fl;
    // 0x808004B8: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808004BC: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x808004C0: add.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x808004C4: mul.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x808004C8: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x808004CC: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808004D0: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x808004D4: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808004D8: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x808004DC: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x808004E0: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808004E4: add.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x808004E8: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x808004EC: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808004F0: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x808004F4: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x808004F8: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808004FC: add.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800500: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80800504:
    // 0x80800504: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800508:
    // 0x80800508: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080050C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800510: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800514: jr          $ra
    // 0x80800518: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800518: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800146D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800146D8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800146DC: lw          $v1, -0x7B74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7B74);
    // 0x800146E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800146E4: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800146E8: bne         $v1, $at, L_80014758
    if (ctx->r3 != ctx->r1) {
        // 0x800146EC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80014758;
    }
    // 0x800146EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800146F0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800146F4: addiu       $v0, $v0, -0x70FC
    ctx->r2 = ADD32(ctx->r2, -0X70FC);
    // 0x800146F8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800146FC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80014700: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80014704: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80014708: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8001470C: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80014710: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80014714: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80014718: lw          $t8, -0x7150($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7150);
    // 0x8001471C: mfhi        $t1
    ctx->r9 = hi;
    // 0x80014720: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80014724: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80014728: addiu       $a0, $a0, -0xC10
    ctx->r4 = ADD32(ctx->r4, -0XC10);
    // 0x8001472C: jal         0x8002F700
    // 0x80014730: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_0;
    // 0x80014730: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80014734: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80014738: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8001473C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014740: sw          $t2, -0x7B6C($at)
    MEM_W(-0X7B6C, ctx->r1) = ctx->r10;
    // 0x80014744: jal         0x80013E34
    // 0x80014748: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80013E34(rdram, ctx);
        goto after_1;
    // 0x80014748: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8001474C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014750: b           L_800148A0
    // 0x80014754: sw          $zero, -0x70EC($at)
    MEM_W(-0X70EC, ctx->r1) = 0;
        goto L_800148A0;
    // 0x80014754: sw          $zero, -0x70EC($at)
    MEM_W(-0X70EC, ctx->r1) = 0;
L_80014758:
    // 0x80014758: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001475C: bne         $v1, $at, L_80014780
    if (ctx->r3 != ctx->r1) {
        // 0x80014760: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_80014780;
    }
    // 0x80014760: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014764: lw          $v0, -0x7B88($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7B88);
    // 0x80014768: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001476C: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80014770: jal         0x8002EAD0
    // 0x80014774: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80014774: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    after_2:
    // 0x80014778: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001477C: lw          $v1, -0x7B74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7B74);
L_80014780:
    // 0x80014780: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80014784: bne         $v1, $at, L_800147CC
    if (ctx->r3 != ctx->r1) {
        // 0x80014788: lui         $t3, 0x8008
        ctx->r11 = S32(0X8008 << 16);
            goto L_800147CC;
    }
    // 0x80014788: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8001478C: lw          $t3, -0x7B6C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7B6C);
    // 0x80014790: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80014794: beql        $t3, $zero, L_800147D0
    if (ctx->r11 == 0) {
        // 0x80014798: addiu       $t5, $zero, 0x10
        ctx->r13 = ADD32(0, 0X10);
            goto L_800147D0;
    }
    goto skip_0;
    // 0x80014798: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    skip_0:
    // 0x8001479C: jal         0x8002F08C
    // 0x800147A0: addiu       $a0, $a0, -0xC10
    ctx->r4 = ADD32(ctx->r4, -0XC10);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_3;
    // 0x800147A0: addiu       $a0, $a0, -0xC10
    ctx->r4 = ADD32(ctx->r4, -0XC10);
    after_3:
    // 0x800147A4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800147A8: jal         0x8002F1F4
    // 0x800147AC: addiu       $a0, $a0, -0xC10
    ctx->r4 = ADD32(ctx->r4, -0XC10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_4;
    // 0x800147AC: addiu       $a0, $a0, -0xC10
    ctx->r4 = ADD32(ctx->r4, -0XC10);
    after_4:
    // 0x800147B0: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x800147B4: lw          $t4, -0x7B70($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7B70);
    // 0x800147B8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800147BC: sw          $t4, -0x7B74($at)
    MEM_W(-0X7B74, ctx->r1) = ctx->r12;
    // 0x800147C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800147C4: b           L_800148A0
    // 0x800147C8: sw          $zero, -0x7B6C($at)
    MEM_W(-0X7B6C, ctx->r1) = 0;
        goto L_800148A0;
    // 0x800147C8: sw          $zero, -0x7B6C($at)
    MEM_W(-0X7B6C, ctx->r1) = 0;
L_800147CC:
    // 0x800147CC: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
L_800147D0:
    // 0x800147D0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800147D4: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800147D8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800147DC: sw          $t5, -0x7B74($at)
    MEM_W(-0X7B74, ctx->r1) = ctx->r13;
    // 0x800147E0: addiu       $t6, $t6, -0x7158
    ctx->r14 = ADD32(ctx->r14, -0X7158);
    // 0x800147E4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800147E8: addiu       $v0, $v0, -0x7154
    ctx->r2 = ADD32(ctx->r2, -0X7154);
    // 0x800147EC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800147F0: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800147F4: beq         $t7, $t8, L_80014848
    if (ctx->r15 == ctx->r24) {
        // 0x800147F8: nop
    
            goto L_80014848;
    }
    // 0x800147F8: nop

    // 0x800147FC: lw          $t9, -0x7B80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7B80);
    // 0x80014800: bne         $t9, $zero, L_80014848
    if (ctx->r25 != 0) {
        // 0x80014804: nop
    
            goto L_80014848;
    }
    // 0x80014804: nop

    // 0x80014808: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8001480C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014810: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80014814: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80014818: jal         0x800140D8
    // 0x8001481C: lw          $a0, -0x71A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X71A8);
    func_800140D8(rdram, ctx);
        goto after_5;
    // 0x8001481C: lw          $a0, -0x71A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X71A8);
    after_5:
    // 0x80014820: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014824: addiu       $v0, $v0, -0x7154
    ctx->r2 = ADD32(ctx->r2, -0X7154);
    // 0x80014828: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8001482C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80014830: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80014834: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80014838: mfhi        $t4
    ctx->r12 = hi;
    // 0x8001483C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80014840: b           L_800148A4
    // 0x80014844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800148A4;
    // 0x80014844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80014848:
    // 0x80014848: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8001484C: lw          $t5, -0x7B84($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7B84);
    // 0x80014850: beq         $t5, $zero, L_800148A0
    if (ctx->r13 == 0) {
        // 0x80014854: lui         $t6, 0x8008
        ctx->r14 = S32(0X8008 << 16);
            goto L_800148A0;
    }
    // 0x80014854: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80014858: lw          $t6, -0x7B7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B7C);
    // 0x8001485C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80014860: bnel        $t6, $at, L_800148A4
    if (ctx->r14 != ctx->r1) {
        // 0x80014864: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800148A4;
    }
    goto skip_1;
    // 0x80014864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80014868: jal         0x8002F240
    // 0x8001486C: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_6;
    // 0x8001486C: nop

    after_6:
    // 0x80014870: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x80014874: bne         $t7, $zero, L_800148A0
    if (ctx->r15 != 0) {
        // 0x80014878: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_800148A0;
    }
    // 0x80014878: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001487C: addiu       $a0, $a0, -0x7BC8
    ctx->r4 = ADD32(ctx->r4, -0X7BC8);
    // 0x80014880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80014884: jal         0x8002EAD0
    // 0x80014888: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80014888: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8001488C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80014890: addiu       $v1, $v1, -0x7B84
    ctx->r3 = ADD32(ctx->r3, -0X7B84);
    // 0x80014894: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80014898: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8001489C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800148A0:
    // 0x800148A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800148A4:
    // 0x800148A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800148A8: jr          $ra
    // 0x800148AC: nop

    return;
    // 0x800148AC: nop

;}
RECOMP_FUNC void func_808021E4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808021E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808021EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808021F0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x808021F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808021F8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x808021FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80802200: jal         0x80087B08
    // 0x80802204: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _gczoombox_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80802204: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80802208: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8080220C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802210: jal         0x80087B78
    // 0x80802214: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    _gczoombox_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80802214: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    after_1:
    // 0x80802218: jal         0x8001ACCC
    // 0x8080221C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x8080221C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_2:
    // 0x80802220: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80802224: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x80802228: jal         0x8001ACCC
    // 0x8080222C: sw          $v0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r2;
    heap_alloc(rdram, ctx);
        goto after_3;
    // 0x8080222C: sw          $v0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r2;
    after_3:
    // 0x80802230: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80802234: sw          $v0, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r2;
    // 0x80802238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080223C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802240: jr          $ra
    // 0x80802244: nop

    return;
    // 0x80802244: nop

;}
RECOMP_FUNC void _bapulse_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F50: syscall     144
    recomp_syscall_handler(rdram, ctx, 0x80084F50);
    return;
    // 0x80084F54: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D0F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0F9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D0FA0: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800D0FA4: or          $t7, $a2, $zero
    ctx->r15 = ctx->r6 | 0;
    // 0x800D0FA8: or          $t8, $a3, $zero
    ctx->r24 = ctx->r7 | 0;
    // 0x800D0FAC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800D0FB0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800D0FB4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800D0FB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D0FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0FC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D0FC4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D0FC8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800D0FCC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D0FD0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800D0FD4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800D0FD8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800D0FDC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800D0FE0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D0FE4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800D0FE8: jal         0x800D0DAC
    // 0x800D0FEC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800D0DAC(rdram, ctx);
        goto after_0;
    // 0x800D0FEC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800D0FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0FF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D0FF8: jr          $ra
    // 0x800D0FFC: nop

    return;
    // 0x800D0FFC: nop

;}
RECOMP_FUNC void func_80800944_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800944: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080094C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800950: jal         0x80100094
    // 0x80800954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800958: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080095C: jal         0x80800B90
    // 0x80800960: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800B90_chquiz(rdram, ctx);
        goto after_1;
    // 0x80800960: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800964: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800968: beq         $v0, $zero, L_80800984
    if (ctx->r2 == 0) {
        // 0x8080096C: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_80800984;
    }
    // 0x8080096C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800970: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800974: beq         $v0, $at, L_808009A8
    if (ctx->r2 == ctx->r1) {
        // 0x80800978: addiu       $v1, $a2, -0x1A00
        ctx->r3 = ADD32(ctx->r6, -0X1A00);
            goto L_808009A8;
    }
    // 0x80800978: addiu       $v1, $a2, -0x1A00
    ctx->r3 = ADD32(ctx->r6, -0X1A00);
    // 0x8080097C: b           L_808009C8
    // 0x80800980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009C8;
    // 0x80800980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800984:
    // 0x80800984: addiu       $v1, $a2, -0x1910
    ctx->r3 = ADD32(ctx->r6, -0X1910);
    // 0x80800988: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8080098C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80800990: lbu         $a0, 0x9C($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X9C);
    // 0x80800994: andi        $t8, $v1, 0x7
    ctx->r24 = ctx->r3 & 0X7;
    // 0x80800998: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080099C: sllv        $t0, $t9, $t8
    ctx->r8 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x808009A0: b           L_808009C8
    // 0x808009A4: and         $v0, $t0, $a0
    ctx->r2 = ctx->r8 & ctx->r4;
        goto L_808009C8;
    // 0x808009A4: and         $v0, $t0, $a0
    ctx->r2 = ctx->r8 & ctx->r4;
L_808009A8:
    // 0x808009A8: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x808009AC: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x808009B0: lbu         $a0, 0xBA($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0XBA);
    // 0x808009B4: andi        $t3, $v1, 0x7
    ctx->r11 = ctx->r3 & 0X7;
    // 0x808009B8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808009BC: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x808009C0: b           L_808009C8
    // 0x808009C4: and         $v0, $t5, $a0
    ctx->r2 = ctx->r13 & ctx->r4;
        goto L_808009C8;
    // 0x808009C4: and         $v0, $t5, $a0
    ctx->r2 = ctx->r13 & ctx->r4;
L_808009C8:
    // 0x808009C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009D0: jr          $ra
    // 0x808009D4: nop

    return;
    // 0x808009D4: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802E08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802E0C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80802E10: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80802E14: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80802E18: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80802E1C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80802E20: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80802E24: jal         0x8001ACCC
    // 0x80802E28: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x80802E28: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    after_0:
    // 0x80802E2C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80802E30: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80802E34: sb          $t7, 0x171($v0)
    MEM_B(0X171, ctx->r2) = ctx->r15;
    // 0x80802E38: sw          $t6, 0x16C($v0)
    MEM_W(0X16C, ctx->r2) = ctx->r14;
    // 0x80802E3C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80802E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802E44: sb          $a1, 0x174($v0)
    MEM_B(0X174, ctx->r2) = ctx->r5;
    // 0x80802E48: sb          $a1, 0x170($v0)
    MEM_B(0X170, ctx->r2) = ctx->r5;
    // 0x80802E4C: sb          $zero, 0x175($v0)
    MEM_B(0X175, ctx->r2) = 0;
    // 0x80802E50: sh          $t8, 0x172($v0)
    MEM_H(0X172, ctx->r2) = ctx->r24;
    // 0x80802E54: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80802E58: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x80802E5C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80802E60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802E64: sb          $t1, 0x177($v0)
    MEM_B(0X177, ctx->r2) = ctx->r9;
    // 0x80802E68: sw          $zero, 0x130($v0)
    MEM_W(0X130, ctx->r2) = 0;
    // 0x80802E6C: sh          $zero, 0x13A($v0)
    MEM_H(0X13A, ctx->r2) = 0;
    // 0x80802E70: sw          $t2, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->r10;
    // 0x80802E74: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80802E78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802E7C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80802E80: sb          $t9, 0x176($v0)
    MEM_B(0X176, ctx->r2) = ctx->r25;
L_80802E84:
    // 0x80802E84: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80802E88: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x80802E8C: sw          $zero, 0x184($v1)
    MEM_W(0X184, ctx->r3) = 0;
    // 0x80802E90: sw          $zero, 0x188($v1)
    MEM_W(0X188, ctx->r3) = 0;
    // 0x80802E94: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80802E98: bne         $a0, $a1, L_80802E84
    if (ctx->r4 != ctx->r5) {
        // 0x80802E9C: sw          $zero, 0x16C($v1)
        MEM_W(0X16C, ctx->r3) = 0;
            goto L_80802E84;
    }
    // 0x80802E9C: sw          $zero, 0x16C($v1)
    MEM_W(0X16C, ctx->r3) = 0;
    // 0x80802EA0: lbu         $t3, 0x1E5($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1E5);
    // 0x80802EA4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80802EA8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80802EAC: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x80802EB0: sb          $zero, 0x19E($v0)
    MEM_B(0X19E, ctx->r2) = 0;
    // 0x80802EB4: sb          $zero, 0x19D($v0)
    MEM_B(0X19D, ctx->r2) = 0;
    // 0x80802EB8: sb          $zero, 0x19C($v0)
    MEM_B(0X19C, ctx->r2) = 0;
    // 0x80802EBC: sb          $t4, 0x1E5($v0)
    MEM_B(0X1E5, ctx->r2) = ctx->r12;
    // 0x80802EC0: sw          $zero, 0x1A0($v0)
    MEM_W(0X1A0, ctx->r2) = 0;
    // 0x80802EC4: sh          $a0, 0x1AC($v0)
    MEM_H(0X1AC, ctx->r2) = ctx->r4;
    // 0x80802EC8: sh          $a0, 0x1BC($v0)
    MEM_H(0X1BC, ctx->r2) = ctx->r4;
    // 0x80802ECC: sb          $v1, 0x1B4($v0)
    MEM_B(0X1B4, ctx->r2) = ctx->r3;
    // 0x80802ED0: sb          $v1, 0x1B5($v0)
    MEM_B(0X1B5, ctx->r2) = ctx->r3;
    // 0x80802ED4: sb          $v1, 0x1B6($v0)
    MEM_B(0X1B6, ctx->r2) = ctx->r3;
    // 0x80802ED8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80802EDC: lbu         $t8, 0x1E4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1E4);
    // 0x80802EE0: lbu         $t2, 0x1E6($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1E6);
    // 0x80802EE4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80802EE8: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80802EEC: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x80802EF0: lbu         $t7, 0x1E7($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1E7);
    // 0x80802EF4: andi        $t5, $t2, 0xFFFD
    ctx->r13 = ctx->r10 & 0XFFFD;
    // 0x80802EF8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80802EFC: sb          $t5, 0x1E6($v0)
    MEM_B(0X1E6, ctx->r2) = ctx->r13;
    // 0x80802F00: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80802F04: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80802F08: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x80802F0C: sb          $t1, 0x1E4($v0)
    MEM_B(0X1E4, ctx->r2) = ctx->r9;
    // 0x80802F10: sb          $zero, 0x179($v0)
    MEM_B(0X179, ctx->r2) = 0;
    // 0x80802F14: sb          $t6, 0x1E6($v0)
    MEM_B(0X1E6, ctx->r2) = ctx->r14;
    // 0x80802F18: sb          $t9, 0x1E7($v0)
    MEM_B(0X1E7, ctx->r2) = ctx->r25;
    // 0x80802F1C: beq         $t2, $zero, L_80802F38
    if (ctx->r10 == 0) {
        // 0x80802F20: swc1        $f2, 0x1E8($v0)
        MEM_W(0X1E8, ctx->r2) = ctx->f2.u32l;
            goto L_80802F38;
    }
    // 0x80802F20: swc1        $f2, 0x1E8($v0)
    MEM_W(0X1E8, ctx->r2) = ctx->f2.u32l;
    // 0x80802F24: addiu       $t3, $zero, 0x104
    ctx->r11 = ADD32(0, 0X104);
    // 0x80802F28: addiu       $t4, $zero, 0x190
    ctx->r12 = ADD32(0, 0X190);
    // 0x80802F2C: sh          $t3, 0x1B2($v0)
    MEM_H(0X1B2, ctx->r2) = ctx->r11;
    // 0x80802F30: b           L_80802F48
    // 0x80802F34: sh          $t4, 0x1AE($v0)
    MEM_H(0X1AE, ctx->r2) = ctx->r12;
        goto L_80802F48;
    // 0x80802F34: sh          $t4, 0x1AE($v0)
    MEM_H(0X1AE, ctx->r2) = ctx->r12;
L_80802F38:
    // 0x80802F38: addiu       $t5, $zero, 0x2C
    ctx->r13 = ADD32(0, 0X2C);
    // 0x80802F3C: addiu       $t6, $zero, -0x60
    ctx->r14 = ADD32(0, -0X60);
    // 0x80802F40: sh          $t5, 0x1B2($v0)
    MEM_H(0X1B2, ctx->r2) = ctx->r13;
    // 0x80802F44: sh          $t6, 0x1AE($v0)
    MEM_H(0X1AE, ctx->r2) = ctx->r14;
L_80802F48:
    // 0x80802F48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802F4C: sll         $t7, $v0, 24
    ctx->r15 = S32(ctx->r2 << 24);
    // 0x80802F50: sra         $t9, $t7, 24
    ctx->r25 = S32(SIGNED(ctx->r15) >> 24);
    // 0x80802F54: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80802F58: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80802F5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802F60: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802F64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802F68: swc1        $f2, 0x1A4($s0)
    MEM_W(0X1A4, ctx->r16) = ctx->f2.u32l;
    // 0x80802F6C: swc1        $f2, 0x1A8($s0)
    MEM_W(0X1A8, ctx->r16) = ctx->f2.u32l;
    // 0x80802F70: sb          $v0, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r2;
    // 0x80802F74: sb          $v0, 0x1D0($s0)
    MEM_B(0X1D0, ctx->r16) = ctx->r2;
    // 0x80802F78: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80802F7C: swc1        $f0, 0x1C4($s0)
    MEM_W(0X1C4, ctx->r16) = ctx->f0.u32l;
    // 0x80802F80: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
    // 0x80802F84: swc1        $f2, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->f2.u32l;
    // 0x80802F88: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80802F8C: swc1        $f2, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = ctx->f2.u32l;
    // 0x80802F90: sh          $t8, 0x1B0($s0)
    MEM_H(0X1B0, ctx->r16) = ctx->r24;
    // 0x80802F94: swc1        $f8, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = ctx->f8.u32l;
    // 0x80802F98: jal         0x800E6A00
    // 0x80802F9C: sb          $t2, 0x1CE($s0)
    MEM_B(0X1CE, ctx->r16) = ctx->r10;
    func_800E6A00(rdram, ctx);
        goto after_1;
    // 0x80802F9C: sb          $t2, 0x1CE($s0)
    MEM_B(0X1CE, ctx->r16) = ctx->r10;
    after_1:
    // 0x80802FA0: lbu         $t6, 0x1E7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E7);
    // 0x80802FA4: lbu         $t9, 0x1E6($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1E6);
    // 0x80802FA8: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x80802FAC: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x80802FB0: andi        $t8, $t6, 0xFFFD
    ctx->r24 = ctx->r14 & 0XFFFD;
    // 0x80802FB4: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x80802FB8: andi        $t5, $t9, 0xFFDF
    ctx->r13 = ctx->r25 & 0XFFDF;
    // 0x80802FBC: sb          $t7, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r15;
    // 0x80802FC0: sb          $t5, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r13;
    // 0x80802FC4: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
    // 0x80802FC8: andi        $t8, $t5, 0xBF
    ctx->r24 = ctx->r13 & 0XBF;
    // 0x80802FCC: sll         $t2, $v1, 18
    ctx->r10 = S32(ctx->r3 << 18);
    // 0x80802FD0: srl         $v1, $t2, 31
    ctx->r3 = S32(U32(ctx->r10) >> 31);
    // 0x80802FD4: sll         $a0, $v1, 6
    ctx->r4 = S32(ctx->r3 << 6);
    // 0x80802FD8: andi        $t6, $a0, 0x40
    ctx->r14 = ctx->r4 & 0X40;
    // 0x80802FDC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80802FE0: or          $t1, $t6, $t8
    ctx->r9 = ctx->r14 | ctx->r24;
    // 0x80802FE4: lbu         $t6, 0x1E5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E5);
    // 0x80802FE8: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x80802FEC: andi        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 & 0X1;
    // 0x80802FF0: andi        $t5, $t6, 0xFFFE
    ctx->r13 = ctx->r14 & 0XFFFE;
    // 0x80802FF4: or          $t9, $t4, $t5
    ctx->r25 = ctx->r12 | ctx->r13;
    // 0x80802FF8: sb          $t1, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r9;
    // 0x80802FFC: sll         $a1, $v1, 7
    ctx->r5 = S32(ctx->r3 << 7);
    // 0x80803000: sll         $a2, $v1, 1
    ctx->r6 = S32(ctx->r3 << 1);
    // 0x80803004: andi        $t7, $a2, 0x2
    ctx->r15 = ctx->r6 & 0X2;
    // 0x80803008: or          $t3, $a1, $t2
    ctx->r11 = ctx->r5 | ctx->r10;
    // 0x8080300C: andi        $t1, $t9, 0xFD
    ctx->r9 = ctx->r25 & 0XFD;
    // 0x80803010: or          $t6, $t7, $t1
    ctx->r14 = ctx->r15 | ctx->r9;
    // 0x80803014: sb          $t3, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r11;
    // 0x80803018: sll         $a3, $v1, 4
    ctx->r7 = S32(ctx->r3 << 4);
    // 0x8080301C: andi        $t3, $a3, 0x10
    ctx->r11 = ctx->r7 & 0X10;
    // 0x80803020: andi        $t4, $t6, 0xEF
    ctx->r12 = ctx->r14 & 0XEF;
    // 0x80803024: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80803028: or          $t7, $t3, $t4
    ctx->r15 = ctx->r11 | ctx->r12;
    // 0x8080302C: sb          $t9, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r25;
    // 0x80803030: sll         $t0, $v1, 5
    ctx->r8 = S32(ctx->r3 << 5);
    // 0x80803034: andi        $t8, $t0, 0x20
    ctx->r24 = ctx->r8 & 0X20;
    // 0x80803038: sb          $t6, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r14;
    // 0x8080303C: andi        $t9, $t7, 0xDF
    ctx->r25 = ctx->r15 & 0XDF;
    // 0x80803040: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x80803044: sb          $t7, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r15;
    // 0x80803048: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x8080304C: lbu         $t7, 0x1E4($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1E4);
    // 0x80803050: andi        $t3, $t2, 0xBF
    ctx->r11 = ctx->r10 & 0XBF;
    // 0x80803054: or          $t4, $a0, $t3
    ctx->r12 = ctx->r4 | ctx->r11;
    // 0x80803058: sb          $t2, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r10;
    // 0x8080305C: sb          $t4, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r12;
    // 0x80803060: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x80803064: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x80803068: andi        $t9, $t7, 0xFFFD
    ctx->r25 = ctx->r15 & 0XFFFD;
    // 0x8080306C: or          $t6, $a2, $t9
    ctx->r14 = ctx->r6 | ctx->r25;
    // 0x80803070: or          $t8, $a1, $t5
    ctx->r24 = ctx->r5 | ctx->r13;
    // 0x80803074: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80803078: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x8080307C: sb          $t8, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r24;
    // 0x80803080: andi        $t4, $t6, 0xFB
    ctx->r12 = ctx->r14 & 0XFB;
    // 0x80803084: or          $t9, $t3, $t4
    ctx->r25 = ctx->r11 | ctx->r12;
    // 0x80803088: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8080308C: andi        $t7, $t8, 0x8
    ctx->r15 = ctx->r24 & 0X8;
    // 0x80803090: andi        $t1, $t9, 0xF7
    ctx->r9 = ctx->r25 & 0XF7;
    // 0x80803094: sb          $t6, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r14;
    // 0x80803098: or          $t6, $t7, $t1
    ctx->r14 = ctx->r15 | ctx->r9;
    // 0x8080309C: andi        $t3, $t6, 0xEF
    ctx->r11 = ctx->r14 & 0XEF;
    // 0x808030A0: or          $t5, $a3, $t3
    ctx->r13 = ctx->r7 | ctx->r11;
    // 0x808030A4: andi        $t8, $t5, 0xDF
    ctx->r24 = ctx->r13 & 0XDF;
    // 0x808030A8: sb          $t9, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r25;
    // 0x808030AC: sb          $t6, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r14;
    // 0x808030B0: or          $t7, $t0, $t8
    ctx->r15 = ctx->r8 | ctx->r24;
    // 0x808030B4: andi        $t1, $t7, 0xBF
    ctx->r9 = ctx->r15 & 0XBF;
    // 0x808030B8: sb          $t5, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r13;
    // 0x808030BC: sb          $t7, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r15;
    // 0x808030C0: lbu         $t5, 0x1E7($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1E7);
    // 0x808030C4: lbu         $t7, 0x1E5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1E5);
    // 0x808030C8: or          $t6, $a0, $t1
    ctx->r14 = ctx->r4 | ctx->r9;
    // 0x808030CC: andi        $t3, $t6, 0x7F
    ctx->r11 = ctx->r14 & 0X7F;
    // 0x808030D0: or          $t4, $a1, $t3
    ctx->r12 = ctx->r5 | ctx->r11;
    // 0x808030D4: sb          $t6, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r14;
    // 0x808030D8: andi        $t8, $t5, 0xFFFE
    ctx->r24 = ctx->r13 & 0XFFFE;
    // 0x808030DC: ori         $t1, $t7, 0x4
    ctx->r9 = ctx->r15 | 0X4;
    // 0x808030E0: sb          $t4, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r12;
    // 0x808030E4: sb          $t8, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r24;
    // 0x808030E8: sb          $t1, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r9;
    // 0x808030EC: lw          $t2, 0x1E4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E4);
    // 0x808030F0: lbu         $t8, 0x1E6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1E6);
    // 0x808030F4: lbu         $t1, 0x1E7($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E7);
    // 0x808030F8: sll         $t6, $t2, 13
    ctx->r14 = S32(ctx->r10 << 13);
    // 0x808030FC: srl         $t3, $t6, 31
    ctx->r11 = S32(U32(ctx->r14) >> 31);
    // 0x80803100: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80803104: andi        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 & 0X8;
    // 0x80803108: andi        $t9, $t8, 0xFFF7
    ctx->r25 = ctx->r24 & 0XFFF7;
    // 0x8080310C: andi        $t6, $t1, 0xFFBF
    ctx->r14 = ctx->r9 & 0XFFBF;
    // 0x80803110: or          $t7, $t5, $t9
    ctx->r15 = ctx->r13 | ctx->r25;
    // 0x80803114: andi        $t4, $t6, 0xDF
    ctx->r12 = ctx->r14 & 0XDF;
    // 0x80803118: sb          $t6, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r14;
    // 0x8080311C: andi        $t5, $t4, 0xEF
    ctx->r13 = ctx->r12 & 0XEF;
    // 0x80803120: sb          $t4, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r12;
    // 0x80803124: sb          $t5, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r13;
    // 0x80803128: andi        $t9, $t5, 0xF7
    ctx->r25 = ctx->r13 & 0XF7;
    // 0x8080312C: sb          $t7, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r15;
    // 0x80803130: sb          $t9, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r25;
    // 0x80803134: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80803138: jal         0x80802B94
    // 0x8080313C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802B94_gczoombox(rdram, ctx);
        goto after_2;
    // 0x8080313C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80803140: lbu         $t1, 0x1E7($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E7);
    // 0x80803144: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803148: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080314C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803150: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x80803154: sb          $t2, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r10;
    // 0x80803158: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3E24) << 16);
    // 0x8080315C: swc1        $f2, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->f2.u32l;
    // 0x80803160: swc1        $f10, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->f10.u32l;
    // 0x80803164: lwc1        $f16, 0x3E24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3E24));
    // 0x80803168: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8080316C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80803170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803174: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x80803178: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8080317C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80803180: jal         0x80803460
    // 0x80803184: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    gczoombox_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80803184: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80803188: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080318C: addiu       $a1, $s0, 0x1B7
    ctx->r5 = ADD32(ctx->r16, 0X1B7);
    // 0x80803190: jal         0x80088420
    // 0x80803194: addiu       $a2, $s0, 0x1B8
    ctx->r6 = ADD32(ctx->r16, 0X1B8);
    _gczoomboxdata_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80803194: addiu       $a2, $s0, 0x1B8
    ctx->r6 = ADD32(ctx->r16, 0X1B8);
    after_4:
    // 0x80803198: sb          $zero, 0x1BA($s0)
    MEM_B(0X1BA, ctx->r16) = 0;
    // 0x8080319C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808031A0: lb          $t6, 0x1BA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1BA);
    // 0x808031A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808031A8: sh          $zero, 0x142($s0)
    MEM_H(0X142, ctx->r16) = 0;
    // 0x808031AC: sb          $t6, 0x1B9($s0)
    MEM_B(0X1B9, ctx->r16) = ctx->r14;
    // 0x808031B0: swc1        $f18, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->f18.u32l;
    // 0x808031B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808031B8: jal         0x80802C80
    // 0x808031BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802C80_gczoombox(rdram, ctx);
        goto after_5;
    // 0x808031BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808031C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031C4: jal         0x808036C4
    // 0x808031C8: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    gczoombox_entrypoint_30(rdram, ctx);
        goto after_6;
    // 0x808031C8: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    after_6:
    // 0x808031CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031D0: jal         0x808001D4
    // 0x808031D4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_808001D4_gczoombox(rdram, ctx);
        goto after_7;
    // 0x808031D4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_7:
    // 0x808031D8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x808031DC: jal         0x808001D4
    // 0x808031E0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_808001D4_gczoombox(rdram, ctx);
        goto after_8;
    // 0x808031E0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_8:
    // 0x808031E4: addiu       $a0, $s0, 0xC0
    ctx->r4 = ADD32(ctx->r16, 0XC0);
    // 0x808031E8: jal         0x808001D4
    // 0x808031EC: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_808001D4_gczoombox(rdram, ctx);
        goto after_9;
    // 0x808031EC: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_9:
    // 0x808031F0: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x808031F4: jal         0x808001D4
    // 0x808031F8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_808001D4_gczoombox(rdram, ctx);
        goto after_10;
    // 0x808031F8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_10:
    // 0x808031FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80803200: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80803204: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80803208: jr          $ra
    // 0x8080320C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080320C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808004BC_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004CC: jal         0x80100094
    // 0x808004D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808004D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004D4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808004D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808004DC: jal         0x800BF744
    // 0x808004E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_1;
    // 0x808004E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808004E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808004E8: jal         0x800BF744
    // 0x808004EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_2;
    // 0x808004EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808004F0: jal         0x800D395C
    // 0x808004F4: nop

    func_800D395C(rdram, ctx);
        goto after_3;
    // 0x808004F4: nop

    after_3:
    // 0x808004F8: beql        $v0, $zero, L_8080050C
    if (ctx->r2 == 0) {
        // 0x808004FC: lhu         $t6, 0x72($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X72);
            goto L_8080050C;
    }
    goto skip_0;
    // 0x808004FC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800500: jal         0x800A16BC
    // 0x80800504: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A16BC(rdram, ctx);
        goto after_4;
    // 0x80800504: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800508: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_8080050C:
    // 0x8080050C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800514: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800518: bne         $t7, $at, L_808005BC
    if (ctx->r15 != ctx->r1) {
        // 0x8080051C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808005BC;
    }
    // 0x8080051C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800520: addiu       $a2, $zero, 0x320
    ctx->r6 = ADD32(0, 0X320);
    // 0x80800524: jal         0x8008A2F0
    // 0x80800528: addiu       $a3, $zero, 0x1AD
    ctx->r7 = ADD32(0, 0X1AD);
    _susubgame_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800528: addiu       $a3, $zero, 0x1AD
    ctx->r7 = ADD32(0, 0X1AD);
    after_5:
    // 0x8080052C: beq         $v0, $zero, L_80800560
    if (ctx->r2 == 0) {
        // 0x80800530: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800560;
    }
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: jal         0x800861A8
    // 0x80800538: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800538: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8080053C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800548: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8080054C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800550: jal         0x8008A2D0
    // 0x80800554: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x80800554: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    after_7:
    // 0x80800558: b           L_808005AC
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808005AC;
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800560:
    // 0x80800560: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800564: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800568: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080056C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800570: jal         0x8008A2C8
    // 0x80800574: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x80800574: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    after_8:
    // 0x80800578: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080057C: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x80800580: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800584: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80800588: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8080058C: jal         0x8008A208
    // 0x80800590: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80800590: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80800594: jal         0x800F54E4
    // 0x80800598: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800598: nop

    after_10:
    // 0x8080059C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005A0: jal         0x800F82D4
    // 0x808005A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_11;
    // 0x808005A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005AC:
    // 0x808005AC: jal         0x80101FDC
    // 0x808005B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x808005B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x808005B4: b           L_80800610
    // 0x808005B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800610;
    // 0x808005B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005BC:
    // 0x808005BC: jal         0x800F54E4
    // 0x808005C0: nop

    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x808005C0: nop

    after_13:
    // 0x808005C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005CC: jal         0x800F8300
    // 0x808005D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F8300(rdram, ctx);
        goto after_14;
    // 0x808005D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x808005D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808005E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808005E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808005E8: jal         0x8008A2C8
    // 0x808005EC: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x808005EC: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    after_15:
    // 0x808005F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808005F4: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
    // 0x808005F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808005FC: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800600: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80800604: jal         0x8008A208
    // 0x80800608: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80800608: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_16:
    // 0x8080060C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800610:
    // 0x80800610: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800614: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800618: jr          $ra
    // 0x8080061C: nop

    return;
    // 0x8080061C: nop

;}
RECOMP_FUNC void seqdat_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: bne         $a1, $zero, L_8080001C
    if (ctx->r5 != 0) {
        // 0x80800004: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080001C;
    }
    // 0x80800004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800008: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3346, 0X30) << 16);
    // 0x80800010: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800014: jr          $ra
    // 0x80800018: lh          $v0, 0x30($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(3346, 0X30));
    return;
    // 0x80800018: lh          $v0, 0x30($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(3346, 0X30));
L_8080001C:
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

    // 0x80800024: nop

    // 0x80800028: nop

    // 0x8080002C: nop

;}
RECOMP_FUNC void chhandcart_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808043B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1632, 0X4E6C) << 16);
    // 0x808043B8: jr          $ra
    // 0x808043BC: addiu       $v0, $v0, 0x4E6C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1632, 0X4E6C));
    return;
    // 0x808043BC: addiu       $v0, $v0, 0x4E6C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1632, 0X4E6C));
;}
RECOMP_FUNC void func_80110818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011081C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80110820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110824: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80110828: jal         0x800EE7F8
    // 0x8011082C: addiu       $a1, $a3, 0x80
    ctx->r5 = ADD32(ctx->r7, 0X80);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8011082C: addiu       $a1, $a3, 0x80
    ctx->r5 = ADD32(ctx->r7, 0X80);
    after_0:
    // 0x80110830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110838: jr          $ra
    // 0x8011083C: nop

    return;
    // 0x8011083C: nop

;}
