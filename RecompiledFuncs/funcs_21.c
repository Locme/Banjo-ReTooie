#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80105C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105C20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105C28: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80105C2C: jal         0x800B3268
    // 0x80105C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    freelist_new(rdram, ctx);
        goto after_0;
    // 0x80105C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80105C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105C38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80105C3C: sw          $v0, 0x6ED0($at)
    MEM_W(0X6ED0, ctx->r1) = ctx->r2;
    // 0x80105C40: jr          $ra
    // 0x80105C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800E68_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800E70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E74: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80800E78: jal         0x80101808
    // 0x80800E7C: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    func_80101808(rdram, ctx);
        goto after_0;
    // 0x80800E7C: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    after_0:
    // 0x80800E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E88: jr          $ra
    // 0x80800E8C: nop

    return;
    // 0x80800E8C: nop

;}
RECOMP_FUNC void func_808000FC_chstadiumdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800100: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800104: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800108: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080010C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800114: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800118: beq         $t6, $at, L_80800130
    if (ctx->r14 == ctx->r1) {
        // 0x8080011C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800130;
    }
    // 0x8080011C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800120: beq         $t6, $at, L_808001EC
    if (ctx->r14 == ctx->r1) {
        // 0x80800124: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001EC;
    }
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: b           L_80800254
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800254;
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800130:
    // 0x80800130: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x80800134: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80800138: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x8080013C: beq         $t7, $at, L_8080015C
    if (ctx->r15 == ctx->r1) {
        // 0x80800140: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_8080015C;
    }
    // 0x80800140: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80800144: beq         $t7, $at, L_8080018C
    if (ctx->r15 == ctx->r1) {
        // 0x80800148: addiu       $at, $zero, 0x35
        ctx->r1 = ADD32(0, 0X35);
            goto L_8080018C;
    }
    // 0x80800148: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x8080014C: beq         $t7, $at, L_808001BC
    if (ctx->r15 == ctx->r1) {
        // 0x80800150: nop
    
            goto L_808001BC;
    }
    // 0x80800150: nop

    // 0x80800154: b           L_80800254
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800254;
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080015C:
    // 0x8080015C: jal         0x800DA298
    // 0x80800160: addiu       $a0, $zero, 0x576
    ctx->r4 = ADD32(0, 0X576);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800160: addiu       $a0, $zero, 0x576
    ctx->r4 = ADD32(0, 0X576);
    after_0:
    // 0x80800164: beql        $v0, $zero, L_80800254
    if (ctx->r2 == 0) {
        // 0x80800168: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800254;
    }
    goto skip_0;
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080016C: lbu         $t8, 0x72($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X72);
    // 0x80800170: lui         $at, 0xC2AA
    ctx->r1 = S32(0XC2AA << 16);
    // 0x80800174: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800178: andi        $t9, $t8, 0xFF03
    ctx->r25 = ctx->r24 & 0XFF03;
    // 0x8080017C: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x80800180: sb          $t0, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r8;
    // 0x80800184: b           L_80800250
    // 0x80800188: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
        goto L_80800250;
    // 0x80800188: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
L_8080018C:
    // 0x8080018C: jal         0x800DA298
    // 0x80800190: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800190: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    after_1:
    // 0x80800194: beql        $v0, $zero, L_80800254
    if (ctx->r2 == 0) {
        // 0x80800198: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800254;
    }
    goto skip_1;
    // 0x80800198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080019C: lbu         $t1, 0x72($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X72);
    // 0x808001A0: lui         $at, 0xC2AA
    ctx->r1 = S32(0XC2AA << 16);
    // 0x808001A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001A8: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x808001AC: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x808001B0: sb          $t3, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r11;
    // 0x808001B4: b           L_80800250
    // 0x808001B8: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
        goto L_80800250;
    // 0x808001B8: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
L_808001BC:
    // 0x808001BC: jal         0x800DA298
    // 0x808001C0: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808001C0: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_2:
    // 0x808001C4: beql        $v0, $zero, L_80800254
    if (ctx->r2 == 0) {
        // 0x808001C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800254;
    }
    goto skip_2;
    // 0x808001C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808001CC: lbu         $t4, 0x72($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X72);
    // 0x808001D0: lui         $at, 0xC2AA
    ctx->r1 = S32(0XC2AA << 16);
    // 0x808001D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001D8: andi        $t5, $t4, 0xFF03
    ctx->r13 = ctx->r12 & 0XFF03;
    // 0x808001DC: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x808001E0: sb          $t6, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r14;
    // 0x808001E4: b           L_80800250
    // 0x808001E8: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
        goto L_80800250;
    // 0x808001E8: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
L_808001EC:
    // 0x808001EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001F0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1652, 0X270) << 16);
    // 0x808001F4: addiu       $a3, $a3, 0x270
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1652, 0X270));
    // 0x808001F8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808001FC: jal         0x80089D50
    // 0x80800200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x80102CF4
    // 0x8080020C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102CF4(rdram, ctx);
        goto after_4;
    // 0x8080020C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80800210: bne         $v0, $zero, L_8080022C
    if (ctx->r2 != 0) {
        // 0x80800214: lui         $a0, 0x6651
        ctx->r4 = S32(0X6651 << 16);
            goto L_8080022C;
    }
    // 0x80800214: lui         $a0, 0x6651
    ctx->r4 = S32(0X6651 << 16);
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x80102B2C
    // 0x80800220: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102B2C(rdram, ctx);
        goto after_5;
    // 0x80800220: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x80800224: b           L_80800254
    // 0x80800228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800254;
    // 0x80800228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080022C:
    // 0x8080022C: lui         $a2, 0x1388
    ctx->r6 = S32(0X1388 << 16);
    // 0x80800230: ori         $a2, $a2, 0x9C4
    ctx->r6 = ctx->r6 | 0X9C4;
    // 0x80800234: ori         $a0, $a0, 0x94CC
    ctx->r4 = ctx->r4 | 0X94CC;
    // 0x80800238: jal         0x800C4140
    // 0x8080023C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C4140(rdram, ctx);
        goto after_6;
    // 0x8080023C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800240: lbu         $t7, 0x72($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X72);
    // 0x80800244: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x80800248: ori         $t9, $t8, 0xC
    ctx->r25 = ctx->r24 | 0XC;
    // 0x8080024C: sb          $t9, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r25;
L_80800250:
    // 0x80800250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800254:
    // 0x80800254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void func_800FB5F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB5F8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800FB5FC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800FB600: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800FB604: addiu       $a2, $a2, 0x59B0
    ctx->r6 = ADD32(ctx->r6, 0X59B0);
    // 0x800FB608: addiu       $a1, $a1, 0x57D0
    ctx->r5 = ADD32(ctx->r5, 0X57D0);
    // 0x800FB60C: lh          $v0, 0x28($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X28);
L_800FB610:
    // 0x800FB610: bne         $a0, $v0, L_800FB620
    if (ctx->r4 != ctx->r2) {
        // 0x800FB614: nop
    
            goto L_800FB620;
    }
    // 0x800FB614: nop

    // 0x800FB618: jr          $ra
    // 0x800FB61C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800FB61C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800FB620:
    // 0x800FB620: bnel        $v1, $zero, L_800FB638
    if (ctx->r3 != 0) {
        // 0x800FB624: addiu       $a1, $a1, 0x50
        ctx->r5 = ADD32(ctx->r5, 0X50);
            goto L_800FB638;
    }
    goto skip_0;
    // 0x800FB624: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    skip_0:
    // 0x800FB628: bgezl       $v0, L_800FB638
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800FB62C: addiu       $a1, $a1, 0x50
        ctx->r5 = ADD32(ctx->r5, 0X50);
            goto L_800FB638;
    }
    goto skip_1;
    // 0x800FB62C: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    skip_1:
    // 0x800FB630: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800FB634: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
L_800FB638:
    // 0x800FB638: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x800FB63C: bnel        $at, $zero, L_800FB610
    if (ctx->r1 != 0) {
        // 0x800FB640: lh          $v0, 0x28($a1)
        ctx->r2 = MEM_H(ctx->r5, 0X28);
            goto L_800FB610;
    }
    goto skip_2;
    // 0x800FB640: lh          $v0, 0x28($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X28);
    skip_2:
    // 0x800FB644: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800FB648: jr          $ra
    // 0x800FB64C: nop

    return;
    // 0x800FB64C: nop

;}
RECOMP_FUNC void func_800E8D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8D5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E8D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8D64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E8D68: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800E8D6C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800E8D70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800E8D74: jal         0x800E8CB0
    // 0x800E8D78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800E8CB0(rdram, ctx);
        goto after_0;
    // 0x800E8D78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E8D7C: lh          $v1, 0x2A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2A);
    // 0x800E8D80: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800E8D84: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x800E8D88: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x800E8D8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800E8D90: jal         0x8001BBA0
    // 0x800E8D94: sll         $a2, $v1, 3
    ctx->r6 = S32(ctx->r3 << 3);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x800E8D94: sll         $a2, $v1, 3
    ctx->r6 = S32(ctx->r3 << 3);
    after_1:
    // 0x800E8D98: jal         0x800E8E3C
    // 0x800E8D9C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800E8E3C(rdram, ctx);
        goto after_2;
    // 0x800E8D9C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800E8DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8DA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E8DA8: jr          $ra
    // 0x800E8DAC: nop

    return;
    // 0x800E8DAC: nop

;}
RECOMP_FUNC void _gcboundDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EF8: syscall     661
    recomp_syscall_handler(rdram, ctx, 0x80087EF8);
    return;
    // 0x80087EFC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _ncpoducam_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089658: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089658);
    return;
    // 0x8008965C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chbilldrillboulder_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1908, 0X588) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x588
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1908, 0X588));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x588
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1908, 0X588));
;}
RECOMP_FUNC void func_808015C0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808015C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808015C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808015CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808015D0: jal         0x80802484
    // 0x808015D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80802484_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808015D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808015D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808015DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808015E0: jal         0x8009C128
    // 0x808015E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x808015E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808015E8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808015EC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808015F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808015F4: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808015F8: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x808015FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801600: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80801604: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80801608: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x8080160C: jal         0x8009C984
    // 0x80801610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    yaw_get(rdram, ctx);
        goto after_2;
    // 0x80801610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80801614: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80801618: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080161C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80801620: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801624: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80801628: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    // 0x8080162C: swc1        $f18, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f18.u32l;
    // 0x80801630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801638: jr          $ra
    // 0x8080163C: nop

    return;
    // 0x8080163C: nop

;}
RECOMP_FUNC void func_80801FF4_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FF4: jr          $ra
    // 0x80801FF8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80801FF8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800140_chweldarbossdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800148: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080014C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800150: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800154: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800158: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080015C: bne         $t7, $at, L_8080016C
    if (ctx->r15 != ctx->r1) {
        // 0x80800160: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8080016C;
    }
    // 0x80800160: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800164: b           L_80800170
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800170;
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8080016C:
    // 0x8080016C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800170:
    // 0x80800170: jal         0x800DF744
    // 0x80800174: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80800174: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800178: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080017C: jal         0x80101870
    // 0x80800180: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80800180: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void func_80800E28_chglowbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800E2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800E30: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800E34: jal         0x800EA05C
    // 0x80800E38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800E38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800E3C: addiu       $at, $zero, 0x157
    ctx->r1 = ADD32(0, 0X157);
    // 0x80800E40: bnel        $v0, $at, L_80800E5C
    if (ctx->r2 != ctx->r1) {
        // 0x80800E44: lbu         $t9, 0x74($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X74);
            goto L_80800E5C;
    }
    goto skip_0;
    // 0x80800E44: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    skip_0:
    // 0x80800E48: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x80800E4C: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80800E50: b           L_80800E64
    // 0x80800E54: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
        goto L_80800E64;
    // 0x80800E54: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    // 0x80800E58: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
L_80800E5C:
    // 0x80800E5C: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x80800E60: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
L_80800E64:
    // 0x80800E64: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80800E68: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800E6C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80800E70: bgezl       $t3, L_80800E8C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800E74: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800E8C;
    }
    goto skip_1;
    // 0x80800E74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80800E78: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800E7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E80: b           L_80800E94
    // 0x80800E84: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
        goto L_80800E94;
    // 0x80800E84: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x80800E88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800E8C:
    // 0x80800E8C: nop

    // 0x80800E90: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
L_80800E94:
    // 0x80800E94: jal         0x80090010
    // 0x80800E98: nop

    func_80090010(rdram, ctx);
        goto after_1;
    // 0x80800E98: nop

    after_1:
    // 0x80800E9C: lui         $at, 0xC2DC
    ctx->r1 = S32(0XC2DC << 16);
    // 0x80800EA0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800EA4: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80800EA8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800EAC: jal         0x800DC178
    // 0x80800EB0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800EB0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800EB4: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800EB8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800EBC: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800EC0: jal         0x8010D254
    // 0x80800EC4: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    func_8010D254(rdram, ctx);
        goto after_3;
    // 0x80800EC4: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x80800EC8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800ECC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800ED0: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80800ED4: jal         0x800EEB9C
    // 0x80800ED8: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_4;
    // 0x80800ED8: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    after_4:
    // 0x80800EDC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800EE0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800EE4: jal         0x800EF04C
    // 0x80800EE8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800EE8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_5:
    // 0x80800EEC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800EF0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800EF4: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800EF8: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x80800EFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800F00: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800F04: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800F08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800F0C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800F10: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800F14: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800F18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800F1C: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x80800F20: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x80800F24: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80800F28: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X139C) << 16);
    // 0x80800F2C: lwc1        $f16, 0x139C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X139C));
    // 0x80800F30: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80800F34: addiu       $a1, $zero, 0x4DE
    ctx->r5 = ADD32(0, 0X4DE);
    // 0x80800F38: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800F3C: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    // 0x80800F40: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80800F44: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80800F48: jal         0x800C9C70
    // 0x80800F4C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800C9C70(rdram, ctx);
        goto after_6;
    // 0x80800F4C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_6:
    // 0x80800F50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F54: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800F58: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800F5C: jr          $ra
    // 0x80800F60: nop

    return;
    // 0x80800F60: nop

;}
RECOMP_FUNC void func_800A2EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2EEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A2EF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2EF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A2EF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A2EFC: jal         0x8009E6F8
    // 0x800A2F00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800A2F00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A2F04: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A2F08: jal         0x800A2C84
    // 0x800A2F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2C84(rdram, ctx);
        goto after_1;
    // 0x800A2F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A2F10: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800A2F14: lw          $t7, 0x124($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X124);
    // 0x800A2F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2F1C: sb          $t6, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r14;
    // 0x800A2F20: jal         0x8009CBDC
    // 0x800A2F24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009CBDC(rdram, ctx);
        goto after_2;
    // 0x800A2F24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x800A2F28: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A2F2C: beq         $v0, $at, L_800A2F48
    if (ctx->r2 == ctx->r1) {
        // 0x800A2F30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A2F48;
    }
    // 0x800A2F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2F34: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A2F38: jal         0x8009CA70
    // 0x800A2F3C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8009CA70(rdram, ctx);
        goto after_3;
    // 0x800A2F3C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_3:
    // 0x800A2F40: beql        $v0, $zero, L_800A2F6C
    if (ctx->r2 == 0) {
        // 0x800A2F44: lw          $v0, 0x124($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X124);
            goto L_800A2F6C;
    }
    goto skip_0;
    // 0x800A2F44: lw          $v0, 0x124($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X124);
    skip_0:
L_800A2F48:
    // 0x800A2F48: lw          $v0, 0x124($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X124);
    // 0x800A2F4C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800A2F50: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800A2F54: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A2F58: jal         0x80088A38
    // 0x800A2F5C: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    _fxstep_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x800A2F5C: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    after_4:
    // 0x800A2F60: b           L_800A2F80
    // 0x800A2F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A2F80;
    // 0x800A2F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2F68: lw          $v0, 0x124($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X124);
L_800A2F6C:
    // 0x800A2F6C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800A2F70: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A2F74: jal         0x80088A38
    // 0x800A2F78: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    _fxstep_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x800A2F78: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    after_5:
    // 0x800A2F7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A2F80:
    // 0x800A2F80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A2F84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A2F88: jr          $ra
    // 0x800A2F8C: nop

    return;
    // 0x800A2F8C: nop

;}
RECOMP_FUNC void _glid_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088670: syscall     697
    recomp_syscall_handler(rdram, ctx, 0x80088670);
    return;
    // 0x80088674: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _subaddiefade_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CF8: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CF8);
    return;
    // 0x80089CFC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_8080068C_gcfrontend(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080068C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800690: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800694: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800698: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080069C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808006A0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x808006A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808006A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808006AC: jal         0x800D3D1C
    // 0x808006B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800D3D1C(rdram, ctx);
        goto after_0;
    // 0x808006B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x808006B4: bnel        $v0, $zero, L_8080071C
    if (ctx->r2 != 0) {
        // 0x808006B8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080071C;
    }
    goto skip_0;
    // 0x808006B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808006BC: jal         0x800D3D04
    // 0x808006C0: nop

    func_800D3D04(rdram, ctx);
        goto after_1;
    // 0x808006C0: nop

    after_1:
    // 0x808006C4: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2650, 0XDB0) << 16);
    // 0x808006C8: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2650, 0XE30) << 16);
    // 0x808006CC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808006D0: addiu       $s2, $s2, 0xE30
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2650, 0XE30));
    // 0x808006D4: addiu       $s0, $s0, 0xDB0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2650, 0XDB0));
    // 0x808006D8: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
L_808006DC:
    // 0x808006DC: bnel        $s1, $t6, L_80800710
    if (ctx->r17 != ctx->r14) {
        // 0x808006E0: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80800710;
    }
    goto skip_1;
    // 0x808006E0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_1:
    // 0x808006E4: jal         0x800D3A20
    // 0x808006E8: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_800D3A20(rdram, ctx);
        goto after_2;
    // 0x808006E8: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_2:
    // 0x808006EC: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x808006F0: beql        $v0, $zero, L_80800700
    if (ctx->r2 == 0) {
        // 0x808006F4: lh          $v0, 0x6($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X6);
            goto L_80800700;
    }
    goto skip_2;
    // 0x808006F4: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    skip_2:
    // 0x808006F8: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x808006FC: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
L_80800700:
    // 0x80800700: beql        $v0, $zero, L_80800710
    if (ctx->r2 == 0) {
        // 0x80800704: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80800710;
    }
    goto skip_3;
    // 0x80800704: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_3:
    // 0x80800708: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x8080070C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80800710:
    // 0x80800710: bnel        $s0, $s2, L_808006DC
    if (ctx->r16 != ctx->r18) {
        // 0x80800714: lh          $t6, 0x0($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X0);
            goto L_808006DC;
    }
    goto skip_4;
    // 0x80800714: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    skip_4:
    // 0x80800718: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080071C:
    // 0x8080071C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800720: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800724: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800728: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080072C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800730: jr          $ra
    // 0x80800734: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800734: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chskeletonexplode_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E20: syscall     459
    recomp_syscall_handler(rdram, ctx, 0x80086E20);
    return;
    // 0x80086E24: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bafly_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C20: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C20);
    return;
    // 0x80084C24: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_8009B9F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B9F0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009B9F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B9F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B9FC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8009BA00: jal         0x8009B9B0
    // 0x8009BA04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_0;
    // 0x8009BA04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009BA08: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8009BA0C: lw          $v0, 0xC8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC8);
    // 0x8009BA10: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x8009BA14: lw          $a1, 0x40($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X40);
    // 0x8009BA18: jal         0x800EEB9C
    // 0x8009BA1C: lw          $a2, 0x3C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X3C);
    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x8009BA1C: lw          $a2, 0x3C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X3C);
    after_1:
    // 0x8009BA20: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8009BA24: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009BA28: lw          $t6, 0xC8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XC8);
    // 0x8009BA2C: swc1        $f4, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f4.u32l;
    // 0x8009BA30: lw          $v0, 0xC8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC8);
    // 0x8009BA34: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8009BA38: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x8009BA3C: lw          $v0, 0xC8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC8);
    // 0x8009BA40: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8009BA44: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x8009BA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BA4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BA50: jr          $ra
    // 0x8009BA54: nop

    return;
    // 0x8009BA54: nop

;}
RECOMP_FUNC void func_8009B590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B590: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009B594: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009B598: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009B59C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009B5A0: lw          $a1, 0xC8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B5A4: jal         0x8009C128
    // 0x8009B5A8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009B5A8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x8009B5AC: jal         0x800A3048
    // 0x8009B5B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3048(rdram, ctx);
        goto after_1;
    // 0x8009B5B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8009B5B4: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B5B8: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8009B5BC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8009B5C0: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
    // 0x8009B5C4: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B5C8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8009B5CC: sltiu       $at, $t6, 0x14
    ctx->r1 = ctx->r14 < 0X14 ? 1 : 0;
    // 0x8009B5D0: beq         $at, $zero, L_8009B790
    if (ctx->r1 == 0) {
        // 0x8009B5D4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8009B790;
    }
    // 0x8009B5D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009B5D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B5DC: addu        $at, $at, $t6
    gpr jr_addend_8009B5E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8009B5E0: lw          $t6, 0x52AC($at)
    ctx->r14 = ADD32(ctx->r1, 0X52AC);
    // 0x8009B5E4: jr          $t6
    // 0x8009B5E8: nop

    switch (jr_addend_8009B5E4 >> 2) {
        case 0: goto L_8009B790; break;
        case 1: goto L_8009B61C; break;
        case 2: goto L_8009B63C; break;
        case 3: goto L_8009B694; break;
        case 4: goto L_8009B790; break;
        case 5: goto L_8009B660; break;
        case 6: goto L_8009B6B4; break;
        case 7: goto L_8009B790; break;
        case 8: goto L_8009B60C; break;
        case 9: goto L_8009B62C; break;
        case 10: goto L_8009B6F8; break;
        case 11: goto L_8009B5FC; break;
        case 12: goto L_8009B5EC; break;
        case 13: goto L_8009B6A4; break;
        case 14: goto L_8009B740; break;
        case 15: goto L_8009B764; break;
        case 16: goto L_8009B708; break;
        case 17: goto L_8009B728; break;
        case 18: goto L_8009B774; break;
        case 19: goto L_8009B784; break;
        default: switch_error(__func__, 0x8009B5E4, 0x801252AC);
    }
    // 0x8009B5E8: nop

L_8009B5EC:
    // 0x8009B5EC: jal         0x80084E28
    // 0x8009B5F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x8009B5F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8009B5F4: b           L_8009B790
    // 0x8009B5F8: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B5F8: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B5FC:
    // 0x8009B5FC: jal         0x8009B450
    // 0x8009B600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B450(rdram, ctx);
        goto after_3;
    // 0x8009B600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8009B604: b           L_8009B790
    // 0x8009B608: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B608: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B60C:
    // 0x8009B60C: jal         0x8009B3B8
    // 0x8009B610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B3B8(rdram, ctx);
        goto after_4;
    // 0x8009B610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8009B614: b           L_8009B790
    // 0x8009B618: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B618: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B61C:
    // 0x8009B61C: jal         0x8009B170
    // 0x8009B620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B170(rdram, ctx);
        goto after_5;
    // 0x8009B620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8009B624: b           L_8009B790
    // 0x8009B628: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B628: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B62C:
    // 0x8009B62C: jal         0x8009B08C
    // 0x8009B630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B08C(rdram, ctx);
        goto after_6;
    // 0x8009B630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8009B634: b           L_8009B790
    // 0x8009B638: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B638: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B63C:
    // 0x8009B63C: jal         0x8009C990
    // 0x8009B640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_7;
    // 0x8009B640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8009B644: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009B648: jal         0x8009B9C0
    // 0x8009B64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_8;
    // 0x8009B64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8009B650: jal         0x8009AE08
    // 0x8009B654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009AE08(rdram, ctx);
        goto after_9;
    // 0x8009B654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8009B658: b           L_8009B790
    // 0x8009B65C: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B65C: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B660:
    // 0x8009B660: jal         0x8009C990
    // 0x8009B664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_10;
    // 0x8009B664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8009B668: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009B66C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009B670: jal         0x800136E4
    // 0x8009B674: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_11;
    // 0x8009B674: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    after_11:
    // 0x8009B678: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009B67C: jal         0x8009B9C0
    // 0x8009B680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_12;
    // 0x8009B680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8009B684: jal         0x8009AE08
    // 0x8009B688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009AE08(rdram, ctx);
        goto after_13;
    // 0x8009B688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8009B68C: b           L_8009B790
    // 0x8009B690: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B690: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B694:
    // 0x8009B694: jal         0x8009AE08
    // 0x8009B698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009AE08(rdram, ctx);
        goto after_14;
    // 0x8009B698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8009B69C: b           L_8009B790
    // 0x8009B6A0: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B6A0: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B6A4:
    // 0x8009B6A4: jal         0x80084E70
    // 0x8009B6A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamoveledge_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x8009B6A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8009B6AC: b           L_8009B790
    // 0x8009B6B0: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B6B0: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B6B4:
    // 0x8009B6B4: jal         0x8009EF04
    // 0x8009B6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_16;
    // 0x8009B6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8009B6BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009B6C0: nop

    // 0x8009B6C4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8009B6C8: nop

    // 0x8009B6CC: bc1f        L_8009B6E8
    if (!c1cs) {
        // 0x8009B6D0: nop
    
            goto L_8009B6E8;
    }
    // 0x8009B6D0: nop

    // 0x8009B6D4: jal         0x8009EEB8
    // 0x8009B6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_17;
    // 0x8009B6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8009B6DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009B6E0: jal         0x8009B9C0
    // 0x8009B6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_18;
    // 0x8009B6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
L_8009B6E8:
    // 0x8009B6E8: jal         0x8009AE08
    // 0x8009B6EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009AE08(rdram, ctx);
        goto after_19;
    // 0x8009B6EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8009B6F0: b           L_8009B790
    // 0x8009B6F4: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B6F4: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B6F8:
    // 0x8009B6F8: jal         0x8009B27C
    // 0x8009B6FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B27C(rdram, ctx);
        goto after_20;
    // 0x8009B6FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8009B700: b           L_8009B790
    // 0x8009B704: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B704: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B708:
    // 0x8009B708: jal         0x80084360
    // 0x8009B70C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsfirstp_entrypoint_27(rdram, ctx);
        goto after_21;
    // 0x8009B70C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8009B710: jal         0x8009AE08
    // 0x8009B714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009AE08(rdram, ctx);
        goto after_22;
    // 0x8009B714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8009B718: jal         0x8009B414
    // 0x8009B71C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B414(rdram, ctx);
        goto after_23;
    // 0x8009B71C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x8009B720: b           L_8009B790
    // 0x8009B724: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B724: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B728:
    // 0x8009B728: jal         0x80084360
    // 0x8009B72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsfirstp_entrypoint_27(rdram, ctx);
        goto after_24;
    // 0x8009B72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8009B730: jal         0x8009B1FC
    // 0x8009B734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B1FC(rdram, ctx);
        goto after_25;
    // 0x8009B734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8009B738: b           L_8009B790
    // 0x8009B73C: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B73C: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B740:
    // 0x8009B740: jal         0x8009C984
    // 0x8009B744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_26;
    // 0x8009B744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8009B748: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009B74C: jal         0x8009B9C0
    // 0x8009B750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_27;
    // 0x8009B750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8009B754: jal         0x8009AE08
    // 0x8009B758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009AE08(rdram, ctx);
        goto after_28;
    // 0x8009B758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8009B75C: b           L_8009B790
    // 0x8009B760: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B760: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B764:
    // 0x8009B764: jal         0x80084EF8
    // 0x8009B768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovethrust_entrypoint_5(rdram, ctx);
        goto after_29;
    // 0x8009B768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8009B76C: b           L_8009B790
    // 0x8009B770: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B770: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B774:
    // 0x8009B774: jal         0x80084EC8
    // 0x8009B778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovespline_entrypoint_10(rdram, ctx);
        goto after_30;
    // 0x8009B778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8009B77C: b           L_8009B790
    // 0x8009B780: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B790;
    // 0x8009B780: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B784:
    // 0x8009B784: jal         0x80084E40
    // 0x8009B788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovehover_entrypoint_2(rdram, ctx);
        goto after_31;
    // 0x8009B788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x8009B78C: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B790:
    // 0x8009B790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009B794: jal         0x8009C0F8
    // 0x8009B798: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_8009C0F8(rdram, ctx);
        goto after_32;
    // 0x8009B798: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_32:
    // 0x8009B79C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009B7A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009B7A4: lw          $t7, 0xC8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B7A8: swc1        $f16, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f16.u32l;
    // 0x8009B7AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B7B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009B7B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009B7B8: jr          $ra
    // 0x8009B7BC: nop

    return;
    // 0x8009B7BC: nop

;}
RECOMP_FUNC void func_808046EC_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808046EC: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x808046F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808046F4: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x808046F8: beql        $t6, $zero, L_80804728
    if (ctx->r14 == 0) {
        // 0x808046FC: lw          $t7, 0x6C($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X6C);
            goto L_80804728;
    }
    goto skip_0;
    // 0x808046FC: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    skip_0:
    // 0x80804700: beq         $t6, $at, L_80804724
    if (ctx->r14 == ctx->r1) {
        // 0x80804704: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80804724;
    }
    // 0x80804704: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804708: beq         $t6, $at, L_80804724
    if (ctx->r14 == ctx->r1) {
        // 0x8080470C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80804724;
    }
    // 0x8080470C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80804710: beql        $t6, $at, L_80804758
    if (ctx->r14 == ctx->r1) {
        // 0x80804714: lui         $at, 0x4416
        ctx->r1 = S32(0X4416 << 16);
            goto L_80804758;
    }
    goto skip_1;
    // 0x80804714: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    skip_1:
    // 0x80804718: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080471C: b           L_80804764
    // 0x80804720: nop

        goto L_80804764;
    // 0x80804720: nop

L_80804724:
    // 0x80804724: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
L_80804728:
    // 0x80804728: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080472C: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80804730: bnel        $t8, $zero, L_8080474C
    if (ctx->r24 != 0) {
        // 0x80804734: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8080474C;
    }
    goto skip_2;
    // 0x80804734: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x80804738: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8080473C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80804740: jr          $ra
    // 0x80804744: nop

    return;
    // 0x80804744: nop

    // 0x80804748: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8080474C:
    // 0x8080474C: jr          $ra
    // 0x80804750: nop

    return;
    // 0x80804750: nop

    // 0x80804754: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
L_80804758:
    // 0x80804758: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080475C: jr          $ra
    // 0x80804760: nop

    return;
    // 0x80804760: nop

L_80804764:
    // 0x80804764: jr          $ra
    // 0x80804768: nop

    return;
    // 0x80804768: nop

;}
RECOMP_FUNC void _vpglow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089060: syscall     758
    recomp_syscall_handler(rdram, ctx, 0x80089060);
    return;
    // 0x80089064: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _glsavegame_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088548: syscall     692
    recomp_syscall_handler(rdram, ctx, 0x80088548);
    return;
    // 0x8008854C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800DAA6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAA6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DAA70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DAA74: jal         0x8001B084
    // 0x800DAA78: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800DAA78: nop

    after_0:
    // 0x800DAA7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DAA80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DAA84: jr          $ra
    // 0x800DAA88: nop

    return;
    // 0x800DAA88: nop

;}
RECOMP_FUNC void func_80801684_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801684: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801688: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080168C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801690: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80801694: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801698: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080169C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808016A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808016A4: jal         0x80100094
    // 0x808016A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808016A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808016AC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808016B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808016B4: jal         0x8080104C
    // 0x808016B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080104C_chevilspirit(rdram, ctx);
        goto after_1;
    // 0x808016B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808016BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808016C0: jal         0x80100094
    // 0x808016C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808016C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808016C8: jal         0x8008A040
    // 0x808016CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808016CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808016D0: beq         $v0, $zero, L_808016E0
    if (ctx->r2 == 0) {
        // 0x808016D4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_808016E0;
    }
    // 0x808016D4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x808016D8: b           L_808016E0
    // 0x808016DC: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
        goto L_808016E0;
    // 0x808016DC: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
L_808016E0:
    // 0x808016E0: bne         $v0, $zero, L_808016F8
    if (ctx->r2 != 0) {
        // 0x808016E4: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_808016F8;
    }
    // 0x808016E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808016E8: jal         0x80100094
    // 0x808016EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808016EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808016F0: jal         0x8008A020
    // 0x808016F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808016F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
L_808016F8:
    // 0x808016F8: lh          $a1, 0x8($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X8);
    // 0x808016FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801700: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80801704: bne         $at, $zero, L_80801770
    if (ctx->r1 != 0) {
        // 0x80801708: nop
    
            goto L_80801770;
    }
    // 0x80801708: nop

    // 0x8080170C: lh          $v1, 0xA($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA);
    // 0x80801710: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80801714: beq         $at, $zero, L_80801728
    if (ctx->r1 == 0) {
        // 0x80801718: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80801728;
    }
    // 0x80801718: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8080171C: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x80801720: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80801724: bne         $s3, $t8, L_8080176C
    if (ctx->r19 != ctx->r24) {
        // 0x80801728: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8080176C;
    }
L_80801728:
    // 0x80801728: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
L_8080172C:
    // 0x8080172C: bnel        $at, $zero, L_8080173C
    if (ctx->r1 != 0) {
        // 0x80801730: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_8080173C;
    }
    goto skip_0;
    // 0x80801730: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    skip_0:
    // 0x80801734: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801738: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_8080173C:
    // 0x8080173C: addu        $v0, $s2, $t9
    ctx->r2 = ADD32(ctx->r18, ctx->r25);
    // 0x80801740: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x80801744: bnel        $s3, $t0, L_80801758
    if (ctx->r19 != ctx->r8) {
        // 0x80801748: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80801758;
    }
    goto skip_1;
    // 0x80801748: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    skip_1:
    // 0x8080174C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80801750: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801754: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
L_80801758:
    // 0x80801758: beql        $at, $zero, L_8080172C
    if (ctx->r1 == 0) {
        // 0x8080175C: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8080172C;
    }
    goto skip_2;
    // 0x8080175C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    skip_2:
    // 0x80801760: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80801764: beql        $s3, $t1, L_8080172C
    if (ctx->r19 == ctx->r9) {
        // 0x80801768: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8080172C;
    }
    goto skip_3;
    // 0x80801768: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    skip_3:
L_8080176C:
    // 0x8080176C: sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
L_80801770:
    // 0x80801770: jal         0x80016B54
    // 0x80801774: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80016B54(rdram, ctx);
        goto after_6;
    // 0x80801774: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80801778: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080177C: bnel        $v0, $at, L_808017C8
    if (ctx->r2 != ctx->r1) {
        // 0x80801780: lh          $a1, 0x8($s2)
        ctx->r5 = MEM_H(ctx->r18, 0X8);
            goto L_808017C8;
    }
    goto skip_4;
    // 0x80801780: lh          $a1, 0x8($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X8);
    skip_4:
    // 0x80801784: lh          $t2, 0x8($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X8);
    // 0x80801788: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8080178C: bnel        $at, $zero, L_808017C8
    if (ctx->r1 != 0) {
        // 0x80801790: lh          $a1, 0x8($s2)
        ctx->r5 = MEM_H(ctx->r18, 0X8);
            goto L_808017C8;
    }
    goto skip_5;
    // 0x80801790: lh          $a1, 0x8($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X8);
    skip_5:
    // 0x80801794: lh          $t3, 0xA($s2)
    ctx->r11 = MEM_H(ctx->r18, 0XA);
    // 0x80801798: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080179C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808017A0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x808017A4: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x808017A8: jal         0x80801988
    // 0x808017AC: lw          $a1, 0xC($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC);
    func_80801988_chevilspirit(rdram, ctx);
        goto after_7;
    // 0x808017AC: lw          $a1, 0xC($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC);
    after_7:
    // 0x808017B0: lh          $t6, 0xA($s2)
    ctx->r14 = MEM_H(ctx->r18, 0XA);
    // 0x808017B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808017B8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x808017BC: b           L_80801820
    // 0x808017C0: sh          $t7, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r15;
        goto L_80801820;
    // 0x808017C0: sh          $t7, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r15;
    // 0x808017C4: lh          $a1, 0x8($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X8);
L_808017C8:
    // 0x808017C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808017CC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x808017D0: blezl       $a1, L_80801820
    if (SIGNED(ctx->r5) <= 0) {
        // 0x808017D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801820;
    }
    goto skip_6;
    // 0x808017D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
L_808017D8:
    // 0x808017D8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x808017DC: beql        $s3, $a0, L_80801810
    if (ctx->r19 == ctx->r4) {
        // 0x808017E0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80801810;
    }
    goto skip_7;
    // 0x808017E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x808017E4: lh          $t8, 0xA($s2)
    ctx->r24 = MEM_H(ctx->r18, 0XA);
    // 0x808017E8: bnel        $s1, $t8, L_80801810
    if (ctx->r17 != ctx->r24) {
        // 0x808017EC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80801810;
    }
    goto skip_8;
    // 0x808017EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x808017F0: jal         0x80106790
    // 0x808017F4: nop

    func_80106790(rdram, ctx);
        goto after_8;
    // 0x808017F4: nop

    after_8:
    // 0x808017F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808017FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801800: jal         0x80801B00
    // 0x80801804: addiu       $a2, $zero, 0x9DE
    ctx->r6 = ADD32(0, 0X9DE);
    func_80801B00_chevilspirit(rdram, ctx);
        goto after_9;
    // 0x80801804: addiu       $a2, $zero, 0x9DE
    ctx->r6 = ADD32(0, 0X9DE);
    after_9:
    // 0x80801808: lh          $a1, 0x8($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X8);
    // 0x8080180C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80801810:
    // 0x80801810: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80801814: bne         $at, $zero, L_808017D8
    if (ctx->r1 != 0) {
        // 0x80801818: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808017D8;
    }
    // 0x80801818: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080181C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801820:
    // 0x80801820: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801824: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801828: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080182C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801830: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801834: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801838: jr          $ra
    // 0x8080183C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080183C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808007F0_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007FC: jal         0x80100094
    // 0x80800800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800804: lbu         $t6, 0x8F4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8F4);
    // 0x80800808: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080080C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800810: bne         $t6, $at, L_80800820
    if (ctx->r14 != ctx->r1) {
        // 0x80800814: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800820;
    }
    // 0x80800814: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800818: jal         0x80100074
    // 0x8080081C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x8080081C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80800820:
    // 0x80800820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800828: jr          $ra
    // 0x8080082C: nop

    return;
    // 0x8080082C: nop

;}
RECOMP_FUNC void sumole_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B80: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800B84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B88: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B8C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800B90: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80800B94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B98: beql        $t6, $zero, L_80801290
    if (ctx->r14 == 0) {
        // 0x80800B9C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801290;
    }
    goto skip_0;
    // 0x80800B9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800BA0: lbu         $t7, 0x7A($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7A);
    // 0x80800BA4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80800BA8: bnel        $t8, $zero, L_80800BC8
    if (ctx->r24 != 0) {
        // 0x80800BAC: lwc1        $f4, 0x54($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
            goto L_80800BC8;
    }
    goto skip_1;
    // 0x80800BAC: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    skip_1:
    // 0x80800BB0: jal         0x8008A4B0
    // 0x80800BB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800BB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800BB8: lbu         $t0, 0x7A($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X7A);
    // 0x80800BBC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80800BC0: sb          $t1, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r9;
    // 0x80800BC4: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
L_80800BC8:
    // 0x80800BC8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80800BCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800BD0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800BD4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80800BD8: nop

    // 0x80800BDC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80800BE0: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80800BE4: lb          $a0, 0xA($t6)
    ctx->r4 = MEM_B(ctx->r14, 0XA);
    // 0x80800BE8: beq         $a0, $at, L_80800C54
    if (ctx->r4 == ctx->r1) {
        // 0x80800BEC: xori        $v1, $a0, 0x18
        ctx->r3 = ctx->r4 ^ 0X18;
            goto L_80800C54;
    }
    // 0x80800BEC: xori        $v1, $a0, 0x18
    ctx->r3 = ctx->r4 ^ 0X18;
    // 0x80800BF0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800BF4: bnel        $v1, $zero, L_80800C0C
    if (ctx->r3 != 0) {
        // 0x80800BF8: lw          $t7, 0x74($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X74);
            goto L_80800C0C;
    }
    goto skip_2;
    // 0x80800BF8: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    skip_2:
    // 0x80800BFC: jal         0x800C6E38
    // 0x80800C00: nop

    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x80800C00: nop

    after_1:
    // 0x80800C04: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800C08: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
L_80800C0C:
    // 0x80800C0C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800C10: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80800C14: beql        $v1, $t9, L_80800C58
    if (ctx->r3 == ctx->r25) {
        // 0x80800C18: lhu         $t8, 0x72($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X72);
            goto L_80800C58;
    }
    goto skip_3;
    // 0x80800C18: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    skip_3:
    // 0x80800C1C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800C20: jal         0x80106790
    // 0x80800C24: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800C24: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800C28: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C2C: lbu         $t3, 0x74($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X74);
    // 0x80800C30: sll         $t0, $a0, 5
    ctx->r8 = S32(ctx->r4 << 5);
    // 0x80800C34: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x80800C38: andi        $t4, $t3, 0xFFDF
    ctx->r12 = ctx->r11 & 0XFFDF;
    // 0x80800C3C: or          $t2, $t1, $t4
    ctx->r10 = ctx->r9 | ctx->r12;
    // 0x80800C40: sb          $t2, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r10;
    // 0x80800C44: lbu         $t5, 0x74($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X74);
    // 0x80800C48: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x80800C4C: or          $t7, $t1, $t6
    ctx->r15 = ctx->r9 | ctx->r14;
    // 0x80800C50: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
L_80800C54:
    // 0x80800C54: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
L_80800C58:
    // 0x80800C58: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800C5C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800C60: sltiu       $at, $t0, 0x16
    ctx->r1 = ctx->r8 < 0X16 ? 1 : 0;
    // 0x80800C64: beq         $at, $zero, L_8080128C
    if (ctx->r1 == 0) {
        // 0x80800C68: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8080128C;
    }
    // 0x80800C68: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800C6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3158, 0X2450) << 16);
    // 0x80800C70: addu        $at, $at, $t0
    gpr jr_addend_80800C78 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800C74: lw          $t0, 0x2450($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3158, 0X2450));
    // 0x80800C78: jr          $t0
    // 0x80800C7C: nop

    switch (jr_addend_80800C78 >> 2) {
        case 0: goto L_80800C80; break;
        case 1: goto L_80800E68; break;
        case 2: goto L_80800FD4; break;
        case 3: goto L_80800E9C; break;
        case 4: goto L_80801078; break;
        case 5: goto L_80801094; break;
        case 6: goto L_80800ED4; break;
        case 7: goto L_80800F0C; break;
        case 8: goto L_80801118; break;
        case 9: goto L_80800F7C; break;
        case 10: goto L_80800FB4; break;
        case 11: goto L_80801280; break;
        case 12: goto L_8080128C; break;
        case 13: goto L_808010B0; break;
        case 14: goto L_808010E0; break;
        case 15: goto L_80801040; break;
        case 16: goto L_80801170; break;
        case 17: goto L_80801134; break;
        case 18: goto L_8080105C; break;
        case 19: goto L_80801194; break;
        case 20: goto L_80801150; break;
        case 21: goto L_8080128C; break;
        default: switch_error(__func__, 0x80800C78, 0x80802450);
    }
    // 0x80800C7C: nop

L_80800C80:
    // 0x80800C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C84: jal         0x80800000
    // 0x80800C88: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80800000_sumole(rdram, ctx);
        goto after_3;
    // 0x80800C88: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x80800C8C: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800C90: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C98: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800C9C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800CA0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800CA4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80800CA8: nop

    // 0x80800CAC: sll         $t2, $t4, 4
    ctx->r10 = S32(ctx->r12 << 4);
    // 0x80800CB0: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x80800CB4: jal         0x808000E8
    // 0x80800CB8: lb          $a3, 0xA($t5)
    ctx->r7 = MEM_B(ctx->r13, 0XA);
    sumole_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800CB8: lb          $a3, 0xA($t5)
    ctx->r7 = MEM_B(ctx->r13, 0XA);
    after_4:
    // 0x80800CBC: beql        $v0, $zero, L_80801290
    if (ctx->r2 == 0) {
        // 0x80800CC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801290;
    }
    goto skip_4;
    // 0x80800CC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80800CC4: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800CC8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80800CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CD0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800CD4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800CD8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80800CDC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80800CE0: nop

    // 0x80800CE4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800CE8: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80800CEC: jal         0x808012A0
    // 0x80800CF0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    sumole_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800CF0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_5:
    // 0x80800CF4: beq         $v0, $zero, L_80800DD8
    if (ctx->r2 == 0) {
        // 0x80800CF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DD8;
    }
    // 0x80800CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CFC: jal         0x800DA298
    // 0x80800D00: addiu       $a0, $zero, 0x40C
    ctx->r4 = ADD32(0, 0X40C);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800D00: addiu       $a0, $zero, 0x40C
    ctx->r4 = ADD32(0, 0X40C);
    after_6:
    // 0x80800D04: bne         $v0, $zero, L_80800D1C
    if (ctx->r2 != 0) {
        // 0x80800D08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D1C;
    }
    // 0x80800D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D0C: jal         0x80800454
    // 0x80800D10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    sumole_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800D10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800D14: b           L_80801290
    // 0x80800D18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80800D18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D1C:
    // 0x80800D1C: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800D20: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80800D24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800D28: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800D2C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80800D30: nop

    // 0x80800D34: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80800D38: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x80800D3C: lb          $a0, 0xA($t5)
    ctx->r4 = MEM_B(ctx->r13, 0XA);
    // 0x80800D40: beql        $a0, $at, L_80800DBC
    if (ctx->r4 == ctx->r1) {
        // 0x80800D44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DBC;
    }
    goto skip_5;
    // 0x80800D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80800D48: jal         0x800C6E38
    // 0x80800D4C: nop

    func_800C6E38(rdram, ctx);
        goto after_8;
    // 0x80800D4C: nop

    after_8:
    // 0x80800D50: bne         $v0, $zero, L_80800DB8
    if (ctx->r2 != 0) {
        // 0x80800D54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DB8;
    }
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D58: jal         0x80800000
    // 0x80800D5C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80800000_sumole(rdram, ctx);
        goto after_9;
    // 0x80800D5C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_9:
    // 0x80800D60: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800D64: jal         0x800D035C
    // 0x80800D68: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800D035C(rdram, ctx);
        goto after_10;
    // 0x80800D68: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_10:
    // 0x80800D6C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D74: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800D78: beq         $at, $zero, L_80800D9C
    if (ctx->r1 == 0) {
        // 0x80800D7C: nop
    
            goto L_80800D9C;
    }
    // 0x80800D7C: nop

    // 0x80800D80: jal         0x80800454
    // 0x80800D84: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    sumole_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800D84: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_11:
    // 0x80800D88: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800D8C: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800D90: ori         $t6, $t8, 0xF
    ctx->r14 = ctx->r24 | 0XF;
    // 0x80800D94: b           L_8080128C
    // 0x80800D98: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
        goto L_8080128C;
    // 0x80800D98: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
L_80800D9C:
    // 0x80800D9C: jal         0x808013F8
    // 0x80800DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sumole_entrypoint_7(rdram, ctx);
        goto after_12;
    // 0x80800DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DA8: jal         0x80800454
    // 0x80800DAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    sumole_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80800DAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x80800DB0: b           L_80801290
    // 0x80800DB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80800DB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800DB8:
    // 0x80800DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800DBC:
    // 0x80800DBC: jal         0x80800454
    // 0x80800DC0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    sumole_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x80800DC0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_14:
    // 0x80800DC4: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800DC8: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800DCC: ori         $t4, $t0, 0xA
    ctx->r12 = ctx->r8 | 0XA;
    // 0x80800DD0: b           L_8080128C
    // 0x80800DD4: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
        goto L_8080128C;
    // 0x80800DD4: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
L_80800DD8:
    // 0x80800DD8: jal         0x80800454
    // 0x80800DDC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    sumole_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x80800DDC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_15:
    // 0x80800DE0: jal         0x80090178
    // 0x80800DE4: addiu       $a0, $zero, 0x601
    ctx->r4 = ADD32(0, 0X601);
    func_80090178(rdram, ctx);
        goto after_16;
    // 0x80800DE4: addiu       $a0, $zero, 0x601
    ctx->r4 = ADD32(0, 0X601);
    after_16:
    // 0x80800DE8: beql        $v0, $zero, L_80800E58
    if (ctx->r2 == 0) {
        // 0x80800DEC: lhu         $t2, 0x6E($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0X6E);
            goto L_80800E58;
    }
    goto skip_6;
    // 0x80800DEC: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    skip_6:
    // 0x80800DF0: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800DF4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80800DF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800DFC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800E00: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80800E04: nop

    // 0x80800E08: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x80800E0C: addu        $t7, $t1, $t5
    ctx->r15 = ADD32(ctx->r9, ctx->r13);
    // 0x80800E10: lb          $a0, 0xA($t7)
    ctx->r4 = MEM_B(ctx->r15, 0XA);
    // 0x80800E14: beql        $a0, $at, L_80800E44
    if (ctx->r4 == ctx->r1) {
        // 0x80800E18: lhu         $t0, 0x6E($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X6E);
            goto L_80800E44;
    }
    goto skip_7;
    // 0x80800E18: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    skip_7:
    // 0x80800E1C: jal         0x800C6E38
    // 0x80800E20: nop

    func_800C6E38(rdram, ctx);
        goto after_17;
    // 0x80800E20: nop

    after_17:
    // 0x80800E24: bnel        $v0, $zero, L_80800E44
    if (ctx->r2 != 0) {
        // 0x80800E28: lhu         $t0, 0x6E($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X6E);
            goto L_80800E44;
    }
    goto skip_8;
    // 0x80800E28: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    skip_8:
    // 0x80800E2C: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800E30: andi        $t6, $t8, 0xFE00
    ctx->r14 = ctx->r24 & 0XFE00;
    // 0x80800E34: ori         $t9, $t6, 0x2
    ctx->r25 = ctx->r14 | 0X2;
    // 0x80800E38: b           L_8080128C
    // 0x80800E3C: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
        goto L_8080128C;
    // 0x80800E3C: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
    // 0x80800E40: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
L_80800E44:
    // 0x80800E44: andi        $t4, $t0, 0xFE00
    ctx->r12 = ctx->r8 & 0XFE00;
    // 0x80800E48: ori         $t3, $t4, 0xA
    ctx->r11 = ctx->r12 | 0XA;
    // 0x80800E4C: b           L_8080128C
    // 0x80800E50: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
        goto L_8080128C;
    // 0x80800E50: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
    // 0x80800E54: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
L_80800E58:
    // 0x80800E58: andi        $t1, $t2, 0xFE00
    ctx->r9 = ctx->r10 & 0XFE00;
    // 0x80800E5C: ori         $t5, $t1, 0x2
    ctx->r13 = ctx->r9 | 0X2;
    // 0x80800E60: b           L_8080128C
    // 0x80800E64: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
        goto L_8080128C;
    // 0x80800E64: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
L_80800E68:
    // 0x80800E68: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800E6C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80800E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E74: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800E78: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800E7C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80800E80: nop

    // 0x80800E84: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x80800E88: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80800E8C: jal         0x80801630
    // 0x80800E90: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    sumole_entrypoint_15(rdram, ctx);
        goto after_18;
    // 0x80800E90: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_18:
    // 0x80800E94: b           L_80801290
    // 0x80800E98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80800E98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E9C:
    // 0x80800E9C: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800EA0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80800EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EA8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800EAC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800EB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800EB4: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80800EB8: nop

    // 0x80800EBC: sll         $t1, $t2, 4
    ctx->r9 = S32(ctx->r10 << 4);
    // 0x80800EC0: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x80800EC4: jal         0x80801B34
    // 0x80800EC8: lh          $a1, 0x4($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X4);
    sumole_entrypoint_17(rdram, ctx);
        goto after_19;
    // 0x80800EC8: lh          $a1, 0x4($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X4);
    after_19:
    // 0x80800ECC: b           L_80801290
    // 0x80800ED0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80800ED0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800ED4:
    // 0x80800ED4: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800ED8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800EE4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800EE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800EEC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80800EF0: nop

    // 0x80800EF4: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80800EF8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800EFC: jal         0x80801B34
    // 0x80800F00: lh          $a1, 0x6($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X6);
    sumole_entrypoint_17(rdram, ctx);
        goto after_20;
    // 0x80800F00: lh          $a1, 0x6($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X6);
    after_20:
    // 0x80800F04: b           L_80801290
    // 0x80800F08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80800F08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F0C:
    // 0x80800F0C: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x80800F10: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F18: srl         $t2, $t3, 4
    ctx->r10 = S32(U32(ctx->r11) >> 4);
    // 0x80800F1C: beql        $t2, $at, L_80800F30
    if (ctx->r10 == ctx->r1) {
        // 0x80800F20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F30;
    }
    goto skip_9;
    // 0x80800F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_9:
    // 0x80800F24: jal         0x80801D3C
    // 0x80800F28: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sumole_entrypoint_19(rdram, ctx);
        goto after_21;
    // 0x80800F28: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_21:
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F30:
    // 0x80800F30: jal         0x80801C78
    // 0x80800F34: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    sumole_entrypoint_18(rdram, ctx);
        goto after_22;
    // 0x80800F34: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_22:
    // 0x80800F38: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800F3C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80800F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F44: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800F48: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800F4C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80800F50: nop

    // 0x80800F54: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80800F58: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80800F5C: jal         0x80802118
    // 0x80800F60: lb          $a1, 0xB($t7)
    ctx->r5 = MEM_B(ctx->r15, 0XB);
    sumole_entrypoint_20(rdram, ctx);
        goto after_23;
    // 0x80800F60: lb          $a1, 0xB($t7)
    ctx->r5 = MEM_B(ctx->r15, 0XB);
    after_23:
    // 0x80800F64: beq         $v0, $zero, L_8080128C
    if (ctx->r2 == 0) {
        // 0x80800F68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080128C;
    }
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F6C: jal         0x80800454
    // 0x80800F70: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    sumole_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x80800F70: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_24:
    // 0x80800F74: b           L_80801290
    // 0x80800F78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80800F78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F7C:
    // 0x80800F7C: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800F80: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80800F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F88: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800F8C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800F90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800F94: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80800F98: nop

    // 0x80800F9C: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x80800FA0: addu        $t2, $t8, $t3
    ctx->r10 = ADD32(ctx->r24, ctx->r11);
    // 0x80800FA4: jal         0x80801B34
    // 0x80800FA8: lh          $a1, 0x8($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X8);
    sumole_entrypoint_17(rdram, ctx);
        goto after_25;
    // 0x80800FA8: lh          $a1, 0x8($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X8);
    after_25:
    // 0x80800FAC: b           L_80801290
    // 0x80800FB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80800FB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800FB4:
    // 0x80800FB4: jal         0x808015F8
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sumole_entrypoint_14(rdram, ctx);
        goto after_26;
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800FBC: beq         $v0, $zero, L_8080128C
    if (ctx->r2 == 0) {
        // 0x80800FC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080128C;
    }
    // 0x80800FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FC4: jal         0x80800454
    // 0x80800FC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sumole_entrypoint_2(rdram, ctx);
        goto after_27;
    // 0x80800FC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80800FCC: b           L_80801290
    // 0x80800FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80800FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800FD4:
    // 0x80800FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD8: jal         0x80801424
    // 0x80800FDC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    sumole_entrypoint_8(rdram, ctx);
        goto after_28;
    // 0x80800FDC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_28:
    // 0x80800FE0: beq         $v0, $zero, L_8080128C
    if (ctx->r2 == 0) {
        // 0x80800FE4: addiu       $a0, $zero, 0x40C
        ctx->r4 = ADD32(0, 0X40C);
            goto L_8080128C;
    }
    // 0x80800FE4: addiu       $a0, $zero, 0x40C
    ctx->r4 = ADD32(0, 0X40C);
    // 0x80800FE8: jal         0x800DA9E4
    // 0x80800FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_29;
    // 0x80800FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80800FF0: bne         $v0, $zero, L_8080100C
    if (ctx->r2 != 0) {
        // 0x80800FF4: addiu       $a0, $zero, 0x424
        ctx->r4 = ADD32(0, 0X424);
            goto L_8080100C;
    }
    // 0x80800FF4: addiu       $a0, $zero, 0x424
    ctx->r4 = ADD32(0, 0X424);
    // 0x80800FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FFC: jal         0x80800454
    // 0x80801000: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sumole_entrypoint_2(rdram, ctx);
        goto after_30;
    // 0x80801000: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_30:
    // 0x80801004: b           L_80801290
    // 0x80801008: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80801008: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080100C:
    // 0x8080100C: jal         0x800DA9E4
    // 0x80801010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_31;
    // 0x80801010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x80801014: bne         $v0, $zero, L_80801030
    if (ctx->r2 != 0) {
        // 0x80801018: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801030;
    }
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801020: jal         0x80800454
    // 0x80801024: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    sumole_entrypoint_2(rdram, ctx);
        goto after_32;
    // 0x80801024: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_32:
    // 0x80801028: b           L_80801290
    // 0x8080102C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x8080102C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801030:
    // 0x80801030: jal         0x80800454
    // 0x80801034: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    sumole_entrypoint_2(rdram, ctx);
        goto after_33;
    // 0x80801034: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_33:
    // 0x80801038: b           L_80801290
    // 0x8080103C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x8080103C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801040:
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801044: addiu       $a1, $zero, 0xDB6
    ctx->r5 = ADD32(0, 0XDB6);
    // 0x80801048: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080104C: jal         0x80801B34
    // 0x80801050: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sumole_entrypoint_17(rdram, ctx);
        goto after_34;
    // 0x80801050: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_34:
    // 0x80801054: b           L_80801290
    // 0x80801058: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80801058: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080105C:
    // 0x8080105C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801060: addiu       $a1, $zero, 0xDBE
    ctx->r5 = ADD32(0, 0XDBE);
    // 0x80801064: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80801068: jal         0x80801B34
    // 0x8080106C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sumole_entrypoint_17(rdram, ctx);
        goto after_35;
    // 0x8080106C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_35:
    // 0x80801070: b           L_80801290
    // 0x80801074: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80801074: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801078:
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080107C: addiu       $a1, $zero, 0xD6C
    ctx->r5 = ADD32(0, 0XD6C);
    // 0x80801080: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80801084: jal         0x80801B34
    // 0x80801088: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sumole_entrypoint_17(rdram, ctx);
        goto after_36;
    // 0x80801088: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_36:
    // 0x8080108C: b           L_80801290
    // 0x80801090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80801090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801094:
    // 0x80801094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801098: addiu       $a1, $zero, 0xD6D
    ctx->r5 = ADD32(0, 0XD6D);
    // 0x8080109C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x808010A0: jal         0x80801B34
    // 0x808010A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sumole_entrypoint_17(rdram, ctx);
        goto after_37;
    // 0x808010A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_37:
    // 0x808010A8: b           L_80801290
    // 0x808010AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x808010AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808010B0:
    // 0x808010B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B4: jal         0x808014DC
    // 0x808010B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    sumole_entrypoint_10(rdram, ctx);
        goto after_38;
    // 0x808010B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_38:
    // 0x808010BC: beql        $v0, $zero, L_80801290
    if (ctx->r2 == 0) {
        // 0x808010C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801290;
    }
    goto skip_10;
    // 0x808010C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x808010C4: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010CC: andi        $t1, $a1, 0x1FF
    ctx->r9 = ctx->r5 & 0X1FF;
    // 0x808010D0: jal         0x80800454
    // 0x808010D4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    sumole_entrypoint_2(rdram, ctx);
        goto after_39;
    // 0x808010D4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_39:
    // 0x808010D8: b           L_80801290
    // 0x808010DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x808010DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808010E0:
    // 0x808010E0: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808010E4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x808010E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010EC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808010F0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x808010F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808010F8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x808010FC: nop

    // 0x80801100: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80801104: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x80801108: jal         0x80801B34
    // 0x8080110C: lh          $a1, 0x4($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X4);
    sumole_entrypoint_17(rdram, ctx);
        goto after_40;
    // 0x8080110C: lh          $a1, 0x4($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X4);
    after_40:
    // 0x80801110: b           L_80801290
    // 0x80801114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80801114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801118:
    // 0x80801118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080111C: addiu       $a1, $zero, 0xD6E
    ctx->r5 = ADD32(0, 0XD6E);
    // 0x80801120: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80801124: jal         0x80801B34
    // 0x80801128: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sumole_entrypoint_17(rdram, ctx);
        goto after_41;
    // 0x80801128: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_41:
    // 0x8080112C: b           L_80801290
    // 0x80801130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80801130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801134:
    // 0x80801134: jal         0x80801568
    // 0x80801138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sumole_entrypoint_11(rdram, ctx);
        goto after_42;
    // 0x80801138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x8080113C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801140: jal         0x80800454
    // 0x80801144: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    sumole_entrypoint_2(rdram, ctx);
        goto after_43;
    // 0x80801144: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_43:
    // 0x80801148: b           L_80801290
    // 0x8080114C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x8080114C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801150:
    // 0x80801150: jal         0x80801594
    // 0x80801154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sumole_entrypoint_12(rdram, ctx);
        goto after_44;
    // 0x80801154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x80801158: beq         $v0, $zero, L_8080128C
    if (ctx->r2 == 0) {
        // 0x8080115C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080128C;
    }
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801160: jal         0x80800454
    // 0x80801164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sumole_entrypoint_2(rdram, ctx);
        goto after_45;
    // 0x80801164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_45:
    // 0x80801168: b           L_80801290
    // 0x8080116C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x8080116C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801170:
    // 0x80801170: jal         0x8008FBE0
    // 0x80801174: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FBE0(rdram, ctx);
        goto after_46;
    // 0x80801174: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_46:
    // 0x80801178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080117C: addiu       $a1, $zero, 0xDB7
    ctx->r5 = ADD32(0, 0XDB7);
    // 0x80801180: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80801184: jal         0x80801B34
    // 0x80801188: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sumole_entrypoint_17(rdram, ctx);
        goto after_47;
    // 0x80801188: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_47:
    // 0x8080118C: b           L_80801290
    // 0x80801190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x80801190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801194:
    // 0x80801194: jal         0x8008FC00
    // 0x80801198: nop

    func_8008FC00(rdram, ctx);
        goto after_48;
    // 0x80801198: nop

    after_48:
    // 0x8080119C: jal         0x8008FC28
    // 0x808011A0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8008FC28(rdram, ctx);
        goto after_49;
    // 0x808011A0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_49:
    // 0x808011A4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808011A8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808011AC: bne         $at, $zero, L_808011F0
    if (ctx->r1 != 0) {
        // 0x808011B0: nop
    
            goto L_808011F0;
    }
    // 0x808011B0: nop

    // 0x808011B4: jal         0x80106790
    // 0x808011B8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_50;
    // 0x808011B8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_50:
    // 0x808011BC: jal         0x80086928
    // 0x808011C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _chmolehill_entrypoint_3(rdram, ctx);
        goto after_51;
    // 0x808011C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_51:
    // 0x808011C4: beq         $v0, $zero, L_808011E0
    if (ctx->r2 == 0) {
        // 0x808011C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808011E0;
    }
    // 0x808011C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011D0: jal         0x80800454
    // 0x808011D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    sumole_entrypoint_2(rdram, ctx);
        goto after_52;
    // 0x808011D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_52:
    // 0x808011D8: b           L_80801290
    // 0x808011DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x808011DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808011E0:
    // 0x808011E0: jal         0x80800454
    // 0x808011E4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    sumole_entrypoint_2(rdram, ctx);
        goto after_53;
    // 0x808011E4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_53:
    // 0x808011E8: b           L_80801290
    // 0x808011EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x808011EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808011F0:
    // 0x808011F0: jal         0x800D8FF8
    // 0x808011F4: nop

    func_800D8FF8(rdram, ctx);
        goto after_54;
    // 0x808011F4: nop

    after_54:
    // 0x808011F8: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808011FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801200: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80801204: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    // 0x80801208: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8080120C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80801210: nop

    // 0x80801214: bc1fl       L_80801290
    if (!c1cs) {
        // 0x80801218: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801290;
    }
    goto skip_11;
    // 0x80801218: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_11:
    // 0x8080121C: jal         0x8008FC00
    // 0x80801220: nop

    func_8008FC00(rdram, ctx);
        goto after_55;
    // 0x80801220: nop

    after_55:
    // 0x80801224: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801228: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080122C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801230: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80801234: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80801238: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080123C: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80801240: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801244: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x80801248: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080124C: jal         0x800F10B4
    // 0x80801250: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_56;
    // 0x80801250: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_56:
    // 0x80801254: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3158, 0X24A8) << 16);
    // 0x80801258: lwc1        $f16, 0x24A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3158, 0X24A8));
    // 0x8080125C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801260: addiu       $a0, $zero, 0x66C
    ctx->r4 = ADD32(0, 0X66C);
    // 0x80801264: addiu       $a2, $zero, 0x3E80
    ctx->r6 = ADD32(0, 0X3E80);
    // 0x80801268: jal         0x800C3FC0
    // 0x8080126C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    func_800C3FC0(rdram, ctx);
        goto after_57;
    // 0x8080126C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    after_57:
    // 0x80801270: jal         0x8008FC50
    // 0x80801274: nop

    func_8008FC50(rdram, ctx);
        goto after_58;
    // 0x80801274: nop

    after_58:
    // 0x80801278: b           L_80801290
    // 0x8080127C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801290;
    // 0x8080127C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801280:
    // 0x80801280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801284: jal         0x80800454
    // 0x80801288: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    sumole_entrypoint_2(rdram, ctx);
        goto after_59;
    // 0x80801288: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_59:
L_8080128C:
    // 0x8080128C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801290:
    // 0x80801290: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801294: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801298: jr          $ra
    // 0x8080129C: nop

    return;
    // 0x8080129C: nop

;}
RECOMP_FUNC void glsavegame_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800438: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080043C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800440: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800448: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080044C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_80800450:
    // 0x80800450: jal         0x80800418
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    glsavegame_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800458: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x8080045C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800468;
    }
    // 0x8080045C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800460: b           L_80800474
    // 0x80800464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800474;
    // 0x80800464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800468:
    // 0x80800468: bne         $s0, $s1, L_80800450
    if (ctx->r16 != ctx->r17) {
        // 0x8080046C: nop
    
            goto L_80800450;
    }
    // 0x8080046C: nop

    // 0x80800470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800474:
    // 0x80800474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800478: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080047C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800480: jr          $ra
    // 0x80800484: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800484: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _sucoasterdata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A258: syscall     831
    recomp_syscall_handler(rdram, ctx, 0x8008A258);
    return;
    // 0x8008A25C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bswalk_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801304: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801308: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080130C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801310: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801314: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801318: jal         0x8080016C
    // 0x8080131C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8080016C_bswalk(rdram, ctx);
        goto after_0;
    // 0x8080131C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x80801320: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80801324: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080132C: jal         0x800A2CE8
    // 0x80801330: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_1;
    // 0x80801330: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80801334: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80801338: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x8080133C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801340: jal         0x800A2CE8
    // 0x80801344: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_2;
    // 0x80801344: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80801348: jal         0x80800000
    // 0x8080134C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bswalk(rdram, ctx);
        goto after_3;
    // 0x8080134C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801350: jal         0x8008DE24
    // 0x80801354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DE24(rdram, ctx);
        goto after_4;
    // 0x80801354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801358: bne         $v0, $zero, L_80801364
    if (ctx->r2 != 0) {
        // 0x8080135C: nop
    
            goto L_80801364;
    }
    // 0x8080135C: nop

    // 0x80801360: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80801364:
    // 0x80801364: jal         0x8009EF10
    // 0x80801368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_5;
    // 0x80801368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080136C: bne         $v0, $zero, L_80801378
    if (ctx->r2 != 0) {
        // 0x80801370: nop
    
            goto L_80801378;
    }
    // 0x80801370: nop

    // 0x80801374: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80801378:
    // 0x80801378: jal         0x80097AD0
    // 0x8080137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_6;
    // 0x8080137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801380: beq         $v0, $zero, L_80801394
    if (ctx->r2 == 0) {
        // 0x80801384: nop
    
            goto L_80801394;
    }
    // 0x80801384: nop

    // 0x80801388: jal         0x800848A8
    // 0x8080138C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_7;
    // 0x8080138C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801390: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80801394:
    // 0x80801394: jal         0x8008DD04
    // 0x80801398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_8;
    // 0x80801398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080139C: beq         $v0, $zero, L_808013A8
    if (ctx->r2 == 0) {
        // 0x808013A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808013A8;
    }
    // 0x808013A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013A4: addiu       $s1, $zero, 0x2F
    ctx->r17 = ADD32(0, 0X2F);
L_808013A8:
    // 0x808013A8: jal         0x800919F4
    // 0x808013AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_9;
    // 0x808013AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808013B0: beq         $v0, $zero, L_808013BC
    if (ctx->r2 == 0) {
        // 0x808013B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808013BC;
    }
    // 0x808013B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013B8: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
L_808013BC:
    // 0x808013BC: jal         0x80800248
    // 0x808013C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800248_bswalk(rdram, ctx);
        goto after_10;
    // 0x808013C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x808013C4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808013C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013CC: jal         0x80091A58
    // 0x808013D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_11;
    // 0x808013D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_11:
    // 0x808013D4: beq         $v0, $zero, L_808013E8
    if (ctx->r2 == 0) {
        // 0x808013D8: nop
    
            goto L_808013E8;
    }
    // 0x808013D8: nop

    // 0x808013DC: jal         0x8009FE84
    // 0x808013E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getTypeOfJump(rdram, ctx);
        goto after_12;
    // 0x808013E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808013E4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_808013E8:
    // 0x808013E8: jal         0x8008E148
    // 0x808013EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_13;
    // 0x808013EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808013F0: beq         $v0, $zero, L_80801404
    if (ctx->r2 == 0) {
        // 0x808013F4: nop
    
            goto L_80801404;
    }
    // 0x808013F4: nop

    // 0x808013F8: jal         0x800848B0
    // 0x808013FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_14;
    // 0x808013FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801400: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80801404:
    // 0x80801404: jal         0x8008E35C
    // 0x80801408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_15;
    // 0x80801408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080140C: beq         $v0, $zero, L_80801418
    if (ctx->r2 == 0) {
        // 0x80801410: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801418;
    }
    // 0x80801410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801414: addiu       $s1, $zero, 0x2D
    ctx->r17 = ADD32(0, 0X2D);
L_80801418:
    // 0x80801418: jal         0x800A02DC
    // 0x8080141C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A02DC(rdram, ctx);
        goto after_16;
    // 0x8080141C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_16:
    // 0x80801420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801424: jal         0x8009E5C8
    // 0x80801428: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_17;
    // 0x80801428: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x8080142C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801430: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801434: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801438: jr          $ra
    // 0x8080143C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080143C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800CF40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF40C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CF410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF414: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CF418: jal         0x800CEA60
    // 0x800CF41C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CEA60(rdram, ctx);
        goto after_0;
    // 0x800CF41C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800CF420: jal         0x800CF640
    // 0x800CF424: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800CF640(rdram, ctx);
        goto after_1;
    // 0x800CF424: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800CF428: jal         0x800CEF00
    // 0x800CF42C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800CEF00(rdram, ctx);
        goto after_2;
    // 0x800CF42C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800CF430: jal         0x800CF6D0
    // 0x800CF434: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800CF6D0(rdram, ctx);
        goto after_3;
    // 0x800CF434: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800CF438: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CF43C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800CF440: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800CF444: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800CF448: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CF44C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CF450: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF454: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CF458: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CF45C: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800CF460: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x800CF464: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800CF468: nop

    // 0x800CF46C: bc1fl       L_800CF47C
    if (!c1cs) {
        // 0x800CF470: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_800CF47C;
    }
    goto skip_0;
    // 0x800CF470: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_0:
    // 0x800CF474: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800CF478: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_800CF47C:
    // 0x800CF47C: jal         0x800CE980
    // 0x800CF480: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE980(rdram, ctx);
        goto after_4;
    // 0x800CF480: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x800CF484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF488: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CF48C: jr          $ra
    // 0x800CF490: nop

    return;
    // 0x800CF490: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800338: jal         0x80800018
    // 0x8080033C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800018_glcutDll(rdram, ctx);
        goto after_0;
    // 0x8080033C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800340: jal         0x800EA05C
    // 0x80800344: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800344: nop

    after_1:
    // 0x80800348: jal         0x808004CC
    // 0x8080034C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    glcutDll_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x8080034C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800350: jal         0x808004D8
    // 0x80800354: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    glcutDll_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800354: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800358: jal         0x80800000
    // 0x8080035C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800000_glcutDll(rdram, ctx);
        goto after_4;
    // 0x8080035C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80800360: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800364: addiu       $v0, $v0, 0x75E8
    ctx->r2 = ADD32(ctx->r2, 0X75E8);
    // 0x80800368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080036C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800370: sb          $t6, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r14;
    // 0x80800374: sb          $zero, 0xB($v0)
    MEM_B(0XB, ctx->r2) = 0;
    // 0x80800378: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x8080037C: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x80800380: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80800384: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    // 0x80800388: jr          $ra
    // 0x8080038C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080038C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80096E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096E30: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80096E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096E38: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x80096E3C: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x80096E40: sw          $a2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r6;
    // 0x80096E44: sw          $a3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r7;
    // 0x80096E48: lw          $a2, 0xD8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD8);
    // 0x80096E4C: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x80096E50: jal         0x800EFA20
    // 0x80096E54: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EFA20(rdram, ctx);
        goto after_0;
    // 0x80096E54: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80096E58: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80096E5C: lw          $a1, 0xD0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD0);
    // 0x80096E60: jal         0x800EE780
    // 0x80096E64: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800EE780(rdram, ctx);
        goto after_1;
    // 0x80096E64: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80096E68: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80096E6C: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x80096E70: jal         0x800EFA20
    // 0x80096E74: lw          $a2, 0xD4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD4);
    func_800EFA20(rdram, ctx);
        goto after_2;
    // 0x80096E74: lw          $a2, 0xD4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD4);
    after_2:
    // 0x80096E78: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80096E7C: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80096E80: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80096E84: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80096E88: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80096E8C: jal         0x800EF934
    // 0x80096E90: nop

    func_800EF934(rdram, ctx);
        goto after_3;
    // 0x80096E90: nop

    after_3:
    // 0x80096E94: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80096E98: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80096E9C: jal         0x800EF934
    // 0x80096EA0: lw          $a2, 0xDC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XDC);
    func_800EF934(rdram, ctx);
        goto after_4;
    // 0x80096EA0: lw          $a2, 0xDC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XDC);
    after_4:
    // 0x80096EA4: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80096EA8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80096EAC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80096EB0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80096EB4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80096EB8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80096EBC: jal         0x800EFA4C
    // 0x80096EC0: nop

    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x80096EC0: nop

    after_5:
    // 0x80096EC4: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80096EC8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80096ECC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80096ED0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80096ED4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80096ED8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80096EDC: jal         0x800EFA4C
    // 0x80096EE0: nop

    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x80096EE0: nop

    after_6:
    // 0x80096EE4: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80096EE8: jal         0x800EF368
    // 0x80096EEC: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    func_800EF368(rdram, ctx);
        goto after_7;
    // 0x80096EEC: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_7:
    // 0x80096EF0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80096EF4: jal         0x800EF368
    // 0x80096EF8: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    func_800EF368(rdram, ctx);
        goto after_8;
    // 0x80096EF8: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_8:
    // 0x80096EFC: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80096F00: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80096F04: jal         0x800EE780
    // 0x80096F08: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    func_800EE780(rdram, ctx);
        goto after_9;
    // 0x80096F08: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    after_9:
    // 0x80096F0C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80096F10: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80096F14: jal         0x800EE780
    // 0x80096F18: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800EE780(rdram, ctx);
        goto after_10;
    // 0x80096F18: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_10:
    // 0x80096F1C: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80096F20: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x80096F24: jal         0x800EE780
    // 0x80096F28: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    func_800EE780(rdram, ctx);
        goto after_11;
    // 0x80096F28: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    after_11:
    // 0x80096F2C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80096F30: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80096F34: jal         0x800EE780
    // 0x80096F38: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EE780(rdram, ctx);
        goto after_12;
    // 0x80096F38: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_12:
    // 0x80096F3C: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80096F40: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80096F44: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    // 0x80096F48: jal         0x80096DD4
    // 0x80096F4C: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    func_80096DD4(rdram, ctx);
        goto after_13;
    // 0x80096F4C: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    after_13:
    // 0x80096F50: bne         $v0, $zero, L_80096F60
    if (ctx->r2 != 0) {
        // 0x80096F54: addiu       $a0, $sp, 0x58
        ctx->r4 = ADD32(ctx->r29, 0X58);
            goto L_80096F60;
    }
    // 0x80096F54: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80096F58: b           L_80096FFC
    // 0x80096F5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80096FFC;
    // 0x80096F5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80096F60:
    // 0x80096F60: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80096F64: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80096F68: jal         0x80096DD4
    // 0x80096F6C: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    func_80096DD4(rdram, ctx);
        goto after_14;
    // 0x80096F6C: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    after_14:
    // 0x80096F70: bne         $v0, $zero, L_80096F80
    if (ctx->r2 != 0) {
        // 0x80096F74: addiu       $a0, $sp, 0xAC
        ctx->r4 = ADD32(ctx->r29, 0XAC);
            goto L_80096F80;
    }
    // 0x80096F74: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x80096F78: b           L_80096FFC
    // 0x80096F7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80096FFC;
    // 0x80096F7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80096F80:
    // 0x80096F80: jal         0x800EEAA4
    // 0x80096F84: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EEAA4(rdram, ctx);
        goto after_15;
    // 0x80096F84: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_15:
    // 0x80096F88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096F8C: lwc1        $f4, 0x4DFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4DFC);
    // 0x80096F90: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    // 0x80096F94: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x80096F98: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80096F9C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80096FA0: bc1f        L_80096FB0
    if (!c1cs) {
        // 0x80096FA4: nop
    
            goto L_80096FB0;
    }
    // 0x80096FA4: nop

    // 0x80096FA8: b           L_80096FFC
    // 0x80096FAC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80096FFC;
    // 0x80096FAC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80096FB0:
    // 0x80096FB0: jal         0x800EFE50
    // 0x80096FB4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    func_800EFE50(rdram, ctx);
        goto after_16;
    // 0x80096FB4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_16:
    // 0x80096FB8: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x80096FBC: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80096FC0: jal         0x800EE780
    // 0x80096FC4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_800EE780(rdram, ctx);
        goto after_17;
    // 0x80096FC4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_17:
    // 0x80096FC8: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x80096FCC: jal         0x800EF334
    // 0x80096FD0: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    func_800EF334(rdram, ctx);
        goto after_18;
    // 0x80096FD0: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    after_18:
    // 0x80096FD4: jal         0x800EF2A0
    // 0x80096FD8: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    func_800EF2A0(rdram, ctx);
        goto after_19;
    // 0x80096FD8: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_19:
    // 0x80096FDC: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x80096FE0: jal         0x800EECE0
    // 0x80096FE4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EECE0(rdram, ctx);
        goto after_20;
    // 0x80096FE4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_20:
    // 0x80096FE8: beq         $v0, $zero, L_80096FF8
    if (ctx->r2 == 0) {
        // 0x80096FEC: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_80096FF8;
    }
    // 0x80096FEC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80096FF0: b           L_80096FF8
    // 0x80096FF4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80096FF8;
    // 0x80096FF4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80096FF8:
    // 0x80096FF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80096FFC:
    // 0x80096FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097000: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x80097004: jr          $ra
    // 0x80097008: nop

    return;
    // 0x80097008: nop

;}
RECOMP_FUNC void gcdialogcamera_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800090: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080009C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808000A0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808000A4: jal         0x80800000
    // 0x808000A8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_80800000_gcdialogcamera(rdram, ctx);
        goto after_0;
    // 0x808000A8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x808000AC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808000B0: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x808000B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B8: bne         $t6, $at, L_808000EC
    if (ctx->r14 != ctx->r1) {
        // 0x808000BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000EC;
    }
    // 0x808000BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000C0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000C4: jal         0x80089628
    // 0x808000C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _ncpoddialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808000C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808000CC: beq         $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000D0: nop
    
            goto L_808000E4;
    }
    // 0x808000D0: nop

    // 0x808000D4: jal         0x800856B8
    // 0x808000D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x808000DC: b           L_808000EC
    // 0x808000E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808000EC;
    // 0x808000E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808000E4:
    // 0x808000E4: b           L_808000EC
    // 0x808000E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808000EC;
    // 0x808000E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
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
RECOMP_FUNC void func_800FEC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEC28: bne         $a0, $zero, L_800FEC58
    if (ctx->r4 != 0) {
        // 0x800FEC2C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800FEC58;
    }
    // 0x800FEC2C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800FEC30: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800FEC34: lbu         $t6, 0x762C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X762C);
    // 0x800FEC38: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800FEC3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800FEC40: bne         $t6, $at, L_800FEC50
    if (ctx->r14 != ctx->r1) {
        // 0x800FEC44: nop
    
            goto L_800FEC50;
    }
    // 0x800FEC44: nop

    // 0x800FEC48: jr          $ra
    // 0x800FEC4C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x800FEC4C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800FEC50:
    // 0x800FEC50: jr          $ra
    // 0x800FEC54: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800FEC54: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800FEC58:
    // 0x800FEC58: jr          $ra
    // 0x800FEC5C: nop

    return;
    // 0x800FEC5C: nop

;}
RECOMP_FUNC void _chmole_lagoon_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DA0: syscall     452
    recomp_syscall_handler(rdram, ctx, 0x80086DA0);
    return;
    // 0x80086DA4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800F78_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F80: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x80800F84: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800F88: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800F8C: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800F90: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    // 0x80800F94: lbu         $t9, 0x65($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X65);
    // 0x80800F98: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800F9C: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80800FA0: sb          $t0, 0x65($a1)
    MEM_B(0X65, ctx->r5) = ctx->r8;
    // 0x80800FA4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80800FA8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800FAC: jal         0x80800950
    // 0x80800FB0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_0;
    // 0x80800FB0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80800FB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800FB8: jal         0x80100094
    // 0x80800FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800FC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800FC4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800FC8: jal         0x80100094
    // 0x80800FCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800FCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800FD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800FD4: jal         0x8008A048
    // 0x80800FD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddielink_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80800FD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80800FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800FE4: jr          $ra
    // 0x80800FE8: nop

    return;
    // 0x80800FE8: nop

;}
RECOMP_FUNC void baeggcursor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80800114: jr          $ra
    // 0x80800118: lbu         $v0, 0x9($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X9);
    return;
    // 0x80800118: lbu         $v0, 0x9($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X9);
;}
RECOMP_FUNC void func_80800664_chbadshad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800664: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800668: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080066C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800670: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800674: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800678: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8080067C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800680: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800684: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80800688: bgezl       $t8, L_808006B8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080068C: lw          $a0, 0x40($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X40);
            goto L_808006B8;
    }
    goto skip_0;
    // 0x8080068C: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    skip_0:
    // 0x80800690: lw          $a0, 0x40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X40);
    // 0x80800694: beq         $a0, $zero, L_808006AC
    if (ctx->r4 == 0) {
        // 0x80800698: nop
    
            goto L_808006AC;
    }
    // 0x80800698: nop

    // 0x8080069C: jal         0x80106790
    // 0x808006A0: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808006A0: nop

    after_0:
    // 0x808006A4: jal         0x8080082C
    // 0x808006A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8080082C_chbadshad(rdram, ctx);
        goto after_1;
    // 0x808006A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
L_808006AC:
    // 0x808006AC: b           L_80800778
    // 0x808006B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800778;
    // 0x808006B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808006B4: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
L_808006B8:
    // 0x808006B8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808006BC: bne         $a0, $zero, L_808006F0
    if (ctx->r4 != 0) {
        // 0x808006C0: nop
    
            goto L_808006F0;
    }
    // 0x808006C0: nop

    // 0x808006C4: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x808006C8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808006CC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x808006D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808006D4: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x808006D8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808006DC: addiu       $a0, $a0, 0x5788
    ctx->r4 = ADD32(ctx->r4, 0X5788);
    // 0x808006E0: jal         0x80086D50
    // 0x808006E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808006E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_2:
    // 0x808006E8: b           L_80800778
    // 0x808006EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800778;
    // 0x808006EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006F0:
    // 0x808006F0: jal         0x80106790
    // 0x808006F4: nop

    func_80106790(rdram, ctx);
        goto after_3;
    // 0x808006F4: nop

    after_3:
    // 0x808006F8: lw          $t1, 0x64($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X64);
    // 0x808006FC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800700: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800704: sll         $t3, $t1, 14
    ctx->r11 = S32(ctx->r9 << 14);
    // 0x80800708: bgez        $t3, L_80800718
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8080070C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80800718;
    }
    // 0x8080070C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800710: b           L_80800778
    // 0x80800714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800778;
    // 0x80800714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800718:
    // 0x80800718: jal         0x8080078C
    // 0x8080071C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8080078C_chbadshad(rdram, ctx);
        goto after_4;
    // 0x8080071C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80800720: beq         $v0, $zero, L_80800748
    if (ctx->r2 == 0) {
        // 0x80800724: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_80800748;
    }
    // 0x80800724: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080072C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800730: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800734: jal         0x8080028C
    // 0x80800738: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8080028C_chbadshad(rdram, ctx);
        goto after_5;
    // 0x80800738: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_5:
    // 0x8080073C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800740: b           L_80800758
    // 0x80800744: swc1        $f0, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f0.u32l;
        goto L_80800758;
    // 0x80800744: swc1        $f0, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f0.u32l;
L_80800748:
    // 0x80800748: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8080074C: swc1        $f4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f4.u32l;
    // 0x80800750: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800754: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
L_80800758:
    // 0x80800758: jal         0x8001211C
    // 0x8080075C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001211C(rdram, ctx);
        goto after_6;
    // 0x8080075C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80800760: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800764: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x80800768: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080076C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80800770: b           L_80800778
    // 0x80800774: swc1        $f8, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f8.u32l;
        goto L_80800778;
    // 0x80800774: swc1        $f8, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f8.u32l;
L_80800778:
    // 0x80800778: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080077C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800780: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800784: jr          $ra
    // 0x80800788: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800788: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800D5A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5A6C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800D5A70: lw          $t6, -0x4700($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4700);
    // 0x800D5A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D5A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5A7C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800D5A80: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5A84: addiu       $a1, $a1, -0x4BC0
    ctx->r5 = ADD32(ctx->r5, -0X4BC0);
    // 0x800D5A88: jal         0x8001E210
    // 0x800D5A8C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x800D5A8C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x800D5A90: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800D5A94: lw          $t9, -0x4BC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4BC0);
    // 0x800D5A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5A9C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D5AA0: lw          $t8, -0x4BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BB8);
    // 0x800D5AA4: srl         $t0, $t9, 6
    ctx->r8 = S32(U32(ctx->r25) >> 6);
    // 0x800D5AA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D5AAC: jr          $ra
    // 0x800D5AB0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    return;
    // 0x800D5AB0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
;}
RECOMP_FUNC void func_80020C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020C98: jr          $ra
    // 0x80020C9C: nop

    return;
    // 0x80020C9C: nop

;}
RECOMP_FUNC void _ncbadive_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089298: syscall     770
    recomp_syscall_handler(rdram, ctx, 0x80089298);
    return;
    // 0x8008929C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_8080761C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080761C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807624: jal         0x80100094
    // 0x80807628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080762C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807630: lh          $v0, 0x80($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X80);
    // 0x80807634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807638: jr          $ra
    // 0x8080763C: nop

    return;
    // 0x8080763C: nop

;}
RECOMP_FUNC void func_800F2168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2168: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800F216C: addiu       $t0, $a0, 0xC
    ctx->r8 = ADD32(ctx->r4, 0XC);
    // 0x800F2170: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
L_800F2174:
    // 0x800F2174: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
    // 0x800F2178: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F217C: bc1fl       L_800F218C
    if (!c1cs) {
        // 0x800F2180: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800F218C;
    }
    goto skip_0;
    // 0x800F2180: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    skip_0:
    // 0x800F2184: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800F2188: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800F218C:
    // 0x800F218C: bnel        $t0, $a0, L_800F2174
    if (ctx->r8 != ctx->r4) {
        // 0x800F2190: lwc1        $f2, 0x0($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800F2174;
    }
    goto skip_1;
    // 0x800F2190: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x800F2194: jr          $ra
    // 0x800F2198: nop

    return;
    // 0x800F2198: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5C0: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5C0);
    return;
    // 0x8008A5C4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800BA4_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800BB0: jal         0x80082840
    // 0x80800BB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800BB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800BB8: jal         0x800839E8
    // 0x80800BBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800BBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800BC0: beq         $v0, $zero, L_80800BCC
    if (ctx->r2 == 0) {
        // 0x80800BC4: addiu       $t6, $zero, 0x8C
        ctx->r14 = ADD32(0, 0X8C);
            goto L_80800BCC;
    }
    // 0x80800BC4: addiu       $t6, $zero, 0x8C
    ctx->r14 = ADD32(0, 0X8C);
    // 0x80800BC8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800BCC:
    // 0x80800BCC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800BD0: jal         0x8009E5C8
    // 0x80800BD4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800BD4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BE0: jr          $ra
    // 0x80800BE4: nop

    return;
    // 0x80800BE4: nop

;}
RECOMP_FUNC void func_808000AC_chjigsawdance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B4: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x808000B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808000BC: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x808000C0: beq         $t6, $zero, L_808000E0
    if (ctx->r14 == 0) {
        // 0x808000C4: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_808000E0;
    }
    // 0x808000C4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808000C8: jal         0x800C8B84
    // 0x808000CC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x808000CC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000D0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000D4: lhu         $t7, 0x6E($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X6E);
    // 0x808000D8: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x808000DC: sh          $t8, 0x6E($a1)
    MEM_H(0X6E, ctx->r5) = ctx->r24;
L_808000E0:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_80800430_chminisubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800438: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080043C: jal         0x80100094
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800444: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800448: jal         0x8008A2F8
    // 0x8080044C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8080044C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800450: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800454: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800458: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    // 0x8080045C: jal         0x8008A2B0
    // 0x80800460: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800460: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800464: beq         $v0, $zero, L_80800474
    if (ctx->r2 == 0) {
        // 0x80800468: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800474;
    }
    // 0x80800468: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080046C: jal         0x8008A2C0
    // 0x80800470: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800470: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_80800474:
    // 0x80800474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800478: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080047C: jr          $ra
    // 0x80800480: nop

    return;
    // 0x80800480: nop

;}
RECOMP_FUNC void capod_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080022C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800230: jal         0x8008FFE8
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800238: jal         0x80110024
    // 0x8080023C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x8080023C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800240: beq         $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x80800244: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800250;
    }
    // 0x80800244: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800248: jal         0x80089520
    // 0x8080024C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _ncpod_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x8080024C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80800250:
    // 0x80800250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800258: jr          $ra
    // 0x8080025C: nop

    return;
    // 0x8080025C: nop

;}
RECOMP_FUNC void susplinet_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080033C: jr          $ra
    // 0x80800340: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80800340: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
;}
