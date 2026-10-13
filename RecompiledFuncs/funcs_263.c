#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800C3868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C386C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3870: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3874: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800C3878: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C387C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3880: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C3884: beq         $t6, $zero, L_800C38D4
    if (ctx->r14 == 0) {
        // 0x800C3888: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800C38D4;
    }
    // 0x800C3888: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C388C: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    // 0x800C3890: jal         0x800C1414
    // 0x800C3894: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3894: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800C3898: lhu         $t7, 0x7A($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X7A);
    // 0x800C389C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C38A0: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C38A4: andi        $t8, $t7, 0xFC3F
    ctx->r24 = ctx->r15 & 0XFC3F;
    // 0x800C38A8: ori         $t9, $t8, 0xC0
    ctx->r25 = ctx->r24 | 0XC0;
    // 0x800C38AC: sh          $t9, 0x7A($v0)
    MEM_H(0X7A, ctx->r2) = ctx->r25;
    // 0x800C38B0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C38B4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C38B8: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x800C38BC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C38C0: swc1        $f12, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f12.u32l;
    // 0x800C38C4: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x800C38C8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C38CC: jal         0x800C31DC
    // 0x800C38D0: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    func_800C31DC(rdram, ctx);
        goto after_1;
    // 0x800C38D0: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    after_1:
L_800C38D4:
    // 0x800C38D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C38D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C38DC: jr          $ra
    // 0x800C38E0: nop

    return;
    // 0x800C38E0: nop

;}
RECOMP_FUNC void func_800C3418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3418: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C341C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C3420: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3424: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C342C: beq         $t6, $zero, L_800C34B8
    if (ctx->r14 == 0) {
        // 0x800C3430: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800C34B8;
    }
    // 0x800C3430: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C3434: jal         0x800C1414
    // 0x800C3438: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3438: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C343C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800C3440: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C3444: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C3448: beq         $a1, $zero, L_800C346C
    if (ctx->r5 == 0) {
        // 0x800C344C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C346C;
    }
    // 0x800C344C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C3450: beq         $a1, $at, L_800C3488
    if (ctx->r5 == ctx->r1) {
        // 0x800C3454: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C3488;
    }
    // 0x800C3454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C3458: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C345C: beq         $a1, $at, L_800C34A4
    if (ctx->r5 == ctx->r1) {
        // 0x800C3460: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C34A4;
    }
    // 0x800C3460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C3464: b           L_800C34BC
    // 0x800C3468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800C34BC;
    // 0x800C3468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C346C:
    // 0x800C346C: jal         0x800C13B0
    // 0x800C3470: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_800C13B0(rdram, ctx);
        goto after_1;
    // 0x800C3470: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x800C3474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C3478: jal         0x800C13B0
    // 0x800C347C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800C13B0(rdram, ctx);
        goto after_2;
    // 0x800C347C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_2:
    // 0x800C3480: b           L_800C34BC
    // 0x800C3484: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800C34BC;
    // 0x800C3484: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C3488:
    // 0x800C3488: jal         0x800C13A0
    // 0x800C348C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_800C13A0(rdram, ctx);
        goto after_3;
    // 0x800C348C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
    // 0x800C3490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C3494: jal         0x800C13B0
    // 0x800C3498: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800C13B0(rdram, ctx);
        goto after_4;
    // 0x800C3498: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_4:
    // 0x800C349C: b           L_800C34BC
    // 0x800C34A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800C34BC;
    // 0x800C34A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C34A4:
    // 0x800C34A4: jal         0x800C13A0
    // 0x800C34A8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_800C13A0(rdram, ctx);
        goto after_5;
    // 0x800C34A8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_5:
    // 0x800C34AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C34B0: jal         0x800C13A0
    // 0x800C34B4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800C13A0(rdram, ctx);
        goto after_6;
    // 0x800C34B4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_6:
L_800C34B8:
    // 0x800C34B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C34BC:
    // 0x800C34BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C34C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C34C4: jr          $ra
    // 0x800C34C8: nop

    return;
    // 0x800C34C8: nop

;}
RECOMP_FUNC void func_80800194_suautobaddies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080019C: jal         0x800EA05C
    // 0x808001A0: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808001A0: nop

    after_0:
    // 0x808001A4: jal         0x800DB9B0
    // 0x808001A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x808001A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001AC: bnel        $v0, $zero, L_8080024C
    if (ctx->r2 != 0) {
        // 0x808001B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080024C;
    }
    goto skip_0;
    // 0x808001B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001B4: jal         0x800887B0
    // 0x808001B8: nop

    _glcutDll_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808001B8: nop

    after_2:
    // 0x808001BC: bnel        $v0, $zero, L_8080024C
    if (ctx->r2 != 0) {
        // 0x808001C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080024C;
    }
    goto skip_1;
    // 0x808001C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808001C4: jal         0x800DA298
    // 0x808001C8: addiu       $a0, $zero, 0x647
    ctx->r4 = ADD32(0, 0X647);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808001C8: addiu       $a0, $zero, 0x647
    ctx->r4 = ADD32(0, 0X647);
    after_3:
    // 0x808001CC: bnel        $v0, $zero, L_8080024C
    if (ctx->r2 != 0) {
        // 0x808001D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080024C;
    }
    goto skip_2;
    // 0x808001D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808001D4: jal         0x800A9C98
    // 0x808001D8: nop

    func_800A9C98(rdram, ctx);
        goto after_4;
    // 0x808001D8: nop

    after_4:
    // 0x808001DC: bnel        $v0, $zero, L_8080024C
    if (ctx->r2 != 0) {
        // 0x808001E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080024C;
    }
    goto skip_3;
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808001E4: jal         0x80088268
    // 0x808001E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808001E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x808001EC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808001F0: beql        $v0, $at, L_8080024C
    if (ctx->r2 == ctx->r1) {
        // 0x808001F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080024C;
    }
    goto skip_4;
    // 0x808001F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x808001F8: jal         0x800D3934
    // 0x808001FC: nop

    func_800D3934(rdram, ctx);
        goto after_6;
    // 0x808001FC: nop

    after_6:
    // 0x80800200: bne         $v0, $zero, L_80800214
    if (ctx->r2 != 0) {
        // 0x80800204: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_80800214;
    }
    // 0x80800204: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800208: addiu       $at, $zero, 0xAF
    ctx->r1 = ADD32(0, 0XAF);
    // 0x8080020C: bne         $t6, $at, L_80800240
    if (ctx->r14 != ctx->r1) {
        // 0x80800210: nop
    
            goto L_80800240;
    }
    // 0x80800210: nop

L_80800214:
    // 0x80800214: jal         0x800DA544
    // 0x80800218: addiu       $a0, $zero, 0x6A7
    ctx->r4 = ADD32(0, 0X6A7);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x80800218: addiu       $a0, $zero, 0x6A7
    ctx->r4 = ADD32(0, 0X6A7);
    after_7:
    // 0x8080021C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800220: addiu       $a0, $a0, 0x6D68
    ctx->r4 = ADD32(ctx->r4, 0X6D68);
    // 0x80800224: addiu       $a1, $zero, 0x153
    ctx->r5 = ADD32(0, 0X153);
    // 0x80800228: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080022C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800230: jal         0x80086D48
    // 0x80800234: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chbaddiesetup_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800234: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80800238: b           L_8080024C
    // 0x8080023C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080024C;
    // 0x8080023C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800240:
    // 0x80800240: jal         0x800DA524
    // 0x80800244: addiu       $a0, $zero, 0x6A7
    ctx->r4 = ADD32(0, 0X6A7);
    func_800DA524(rdram, ctx);
        goto after_9;
    // 0x80800244: addiu       $a0, $zero, 0x6A7
    ctx->r4 = ADD32(0, 0X6A7);
    after_9:
    // 0x80800248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080024C:
    // 0x8080024C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800250: jr          $ra
    // 0x80800254: nop

    return;
    // 0x80800254: nop

;}
RECOMP_FUNC void chstarspinnerctrl_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080077C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800780: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800784: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800788: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080078C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800790: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800794: jal         0x800DA298
    // 0x80800798: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800798: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    after_0:
    // 0x8080079C: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x808007A0: bnel        $a1, $zero, L_808007B8
    if (ctx->r5 != 0) {
        // 0x808007A4: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_808007B8;
    }
    goto skip_0;
    // 0x808007A4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x808007A8: jal         0x80088848
    // 0x808007AC: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808007AC: nop

    after_1:
    // 0x808007B0: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x808007B4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_808007B8:
    // 0x808007B8: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    // 0x808007BC: bne         $a0, $zero, L_808007CC
    if (ctx->r4 != 0) {
        // 0x808007C0: nop
    
            goto L_808007CC;
    }
    // 0x808007C0: nop

    // 0x808007C4: b           L_80800890
    // 0x808007C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800890;
    // 0x808007C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007CC:
    // 0x808007CC: jal         0x80106790
    // 0x808007D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x808007D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x808007D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808007D8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808007DC: beq         $a1, $zero, L_8080080C
    if (ctx->r5 == 0) {
        // 0x808007E0: nop
    
            goto L_8080080C;
    }
    // 0x808007E0: nop

    // 0x808007E4: bne         $s0, $zero, L_8080080C
    if (ctx->r16 != 0) {
        // 0x808007E8: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8080080C;
    }
    // 0x808007E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808007EC: jal         0x80800604
    // 0x808007F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    chstarspinnerctrl_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808007F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x808007F4: beq         $v0, $zero, L_8080080C
    if (ctx->r2 == 0) {
        // 0x808007F8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8080080C;
    }
    // 0x808007F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808007FC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0X8E8) << 16);
    // 0x80800800: addiu       $a1, $a1, 0x8E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X8E8));
    // 0x80800804: jal         0x800C8E84
    // 0x80800808: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x80800808: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
L_8080080C:
    // 0x8080080C: bne         $s0, $zero, L_8080081C
    if (ctx->r16 != 0) {
        // 0x80800810: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080081C;
    }
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800814: b           L_80800890
    // 0x80800818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800890;
    // 0x80800818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080081C:
    // 0x8080081C: jal         0x800C8CB8
    // 0x80800820: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800C8CB8(rdram, ctx);
        goto after_5;
    // 0x80800820: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x80800824: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800828: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x8080082C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800830: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800834: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x80800838: beq         $at, $zero, L_8080088C
    if (ctx->r1 == 0) {
        // 0x8080083C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8080088C;
    }
    // 0x8080083C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800840: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(960, 0X8C4) << 16);
    // 0x80800844: addu        $at, $at, $t0
    gpr jr_addend_8080084C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800848: lw          $t0, 0x8C4($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(960, 0X8C4));
    // 0x8080084C: jr          $t0
    // 0x80800850: nop

    switch (jr_addend_8080084C >> 2) {
        case 0: goto L_80800854; break;
        case 1: goto L_80800854; break;
        case 2: goto L_80800864; break;
        case 3: goto L_8080087C; break;
        case 4: goto L_8080087C; break;
        default: switch_error(__func__, 0x8080084C, 0x808008C4);
    }
    // 0x80800850: nop

L_80800854:
    // 0x80800854: jal         0x800C8B84
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C8B84(rdram, ctx);
        goto after_6;
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080085C: b           L_8080088C
    // 0x80800860: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8080088C;
    // 0x80800860: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800864:
    // 0x80800864: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0X8F4) << 16);
    // 0x80800868: addiu       $a1, $a1, 0x8F4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X8F4));
    // 0x8080086C: jal         0x800C8E84
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C8E84(rdram, ctx);
        goto after_7;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800874: b           L_80800890
    // 0x80800878: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80800890;
    // 0x80800878: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8080087C:
    // 0x8080087C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0X8F4) << 16);
    // 0x80800880: addiu       $a1, $a1, 0x8F4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X8F4));
    // 0x80800884: jal         0x800C8E84
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C8E84(rdram, ctx);
        goto after_8;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_8080088C:
    // 0x8080088C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80800890:
    // 0x80800890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800894: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800898: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080089C: jr          $ra
    // 0x808008A0: nop

    return;
    // 0x808008A0: nop

    // 0x808008A4: nop

    // 0x808008A8: nop

    // 0x808008AC: nop

;}
RECOMP_FUNC void func_808011BC_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011C4: jal         0x800EA05C
    // 0x808011C8: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808011C8: nop

    after_0:
    // 0x808011CC: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x808011D0: beq         $v0, $at, L_808011E0
    if (ctx->r2 == ctx->r1) {
        // 0x808011D4: addiu       $at, $zero, 0x121
        ctx->r1 = ADD32(0, 0X121);
            goto L_808011E0;
    }
    // 0x808011D4: addiu       $at, $zero, 0x121
    ctx->r1 = ADD32(0, 0X121);
    // 0x808011D8: bne         $v0, $at, L_808011F0
    if (ctx->r2 != ctx->r1) {
        // 0x808011DC: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_808011F0;
    }
    // 0x808011DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
L_808011E0:
    // 0x808011E0: jal         0x80086C48
    // 0x808011E4: nop

    _chchuffycont_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808011E4: nop

    after_1:
    // 0x808011E8: b           L_808011F4
    // 0x808011EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_808011F4;
    // 0x808011EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_808011F0:
    // 0x808011F0: lbu         $a1, 0x762D($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X762D);
L_808011F4:
    // 0x808011F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2658, 0X20A8) << 16);
    // 0x808011F8: addiu       $a2, $a2, 0x20A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2658, 0X20A8));
    // 0x808011FC: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x80801200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801208: beq         $t6, $zero, L_80801238
    if (ctx->r14 == 0) {
        // 0x8080120C: addiu       $sp, $sp, 0x18
        ctx->r29 = ADD32(ctx->r29, 0X18);
            goto L_80801238;
    }
    // 0x8080120C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801210: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2658, 0X20A8) << 16);
    // 0x80801214: addiu       $v0, $t7, 0x20A8
    ctx->r2 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2658, 0X20A8));
    // 0x80801218: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
L_8080121C:
    // 0x8080121C: beql        $a1, $v1, L_8080123C
    if (ctx->r5 == ctx->r3) {
        // 0x80801220: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8080123C;
    }
    goto skip_0;
    // 0x80801220: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    skip_0:
    // 0x80801224: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80801228: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8080122C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801230: bne         $v1, $zero, L_8080121C
    if (ctx->r3 != 0) {
        // 0x80801234: nop
    
            goto L_8080121C;
    }
    // 0x80801234: nop

L_80801238:
    // 0x80801238: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
L_8080123C:
    // 0x8080123C: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80801240: jr          $ra
    // 0x80801244: lh          $v0, 0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X2);
    return;
    // 0x80801244: lh          $v0, 0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X2);
;}
RECOMP_FUNC void _bsbeefly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082860: syscall     16
    recomp_syscall_handler(rdram, ctx, 0x80082860);
    return;
    // 0x80082864: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80013474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013474: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80013478: lw          $v0, 0x6A08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A08);
    // 0x8001347C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80013480: jr          $ra
    // 0x80013484: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x80013484: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_808003AC_subaddiestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003AC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808003B0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x808003B4: addiu       $fp, $sp, 0x58
    ctx->r30 = ADD32(ctx->r29, 0X58);
    // 0x808003B8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808003BC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x808003C0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808003C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808003C8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x808003CC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808003D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808003D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808003D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808003DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003E0: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x808003E4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x808003E8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x808003EC: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x808003F0: jal         0x801067C4
    // 0x808003F4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x808003F4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_0:
    // 0x808003F8: beq         $v0, $zero, L_808004B8
    if (ctx->r2 == 0) {
        // 0x808003FC: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_808004B8;
    }
    // 0x808003FC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800400: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
L_80800404:
    // 0x80800404: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800408: jal         0x80800260
    // 0x8080040C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80800260_subaddiestore(rdram, ctx);
        goto after_1;
    // 0x8080040C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x80800410: beq         $v0, $zero, L_808004A8
    if (ctx->r2 == 0) {
        // 0x80800414: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808004A8;
    }
    // 0x80800414: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800418: beq         $v0, $at, L_80800434
    if (ctx->r2 == ctx->r1) {
        // 0x8080041C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800434;
    }
    // 0x8080041C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800420: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800424: beql        $v0, $at, L_808004A4
    if (ctx->r2 == ctx->r1) {
        // 0x80800428: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_808004A4;
    }
    goto skip_0;
    // 0x80800428: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_0:
    // 0x8080042C: b           L_808004A8
    // 0x80800430: nop

        goto L_808004A8;
    // 0x80800430: nop

L_80800434:
    // 0x80800434: lw          $t6, 0x7C($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X7C);
    // 0x80800438: addiu       $s2, $s2, 0xB0
    ctx->r18 = ADD32(ctx->r18, 0XB0);
    // 0x8080043C: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80800440: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80800444: beql        $t7, $zero, L_80800454
    if (ctx->r15 == 0) {
        // 0x80800448: lw          $t8, 0x94($s5)
        ctx->r24 = MEM_W(ctx->r21, 0X94);
            goto L_80800454;
    }
    goto skip_1;
    // 0x80800448: lw          $t8, 0x94($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X94);
    skip_1:
    // 0x8080044C: addiu       $s2, $s2, 0x48
    ctx->r18 = ADD32(ctx->r18, 0X48);
    // 0x80800450: lw          $t8, 0x94($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X94);
L_80800454:
    // 0x80800454: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800458: srl         $t0, $t9, 22
    ctx->r8 = S32(U32(ctx->r25) >> 22);
    // 0x8080045C: beq         $t0, $zero, L_80800468
    if (ctx->r8 == 0) {
        // 0x80800460: nop
    
            goto L_80800468;
    }
    // 0x80800460: nop

    // 0x80800464: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
L_80800468:
    // 0x80800468: lh          $a0, 0x82($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X82);
    // 0x8080046C: beql        $a0, $zero, L_80800484
    if (ctx->r4 == 0) {
        // 0x80800470: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80800484;
    }
    goto skip_2;
    // 0x80800470: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_2:
    // 0x80800474: jal         0x8001B7B8
    // 0x80800478: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    func_8001B7B8(rdram, ctx);
        goto after_2;
    // 0x80800478: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    after_2:
    // 0x8080047C: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80800480: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80800484:
    // 0x80800484: bne         $s0, $s4, L_80800468
    if (ctx->r16 != ctx->r20) {
        // 0x80800488: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_80800468;
    }
    // 0x80800488: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8080048C: beq         $s3, $zero, L_80800498
    if (ctx->r19 == 0) {
        // 0x80800490: nop
    
            goto L_80800498;
    }
    // 0x80800490: nop

    // 0x80800494: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
L_80800498:
    // 0x80800498: b           L_808004A8
    // 0x8080049C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
        goto L_808004A8;
    // 0x8080049C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x808004A0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_808004A4:
    // 0x808004A4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_808004A8:
    // 0x808004A8: jal         0x8010682C
    // 0x808004AC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_8010682C(rdram, ctx);
        goto after_3;
    // 0x808004AC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_3:
    // 0x808004B0: bne         $v0, $zero, L_80800404
    if (ctx->r2 != 0) {
        // 0x808004B4: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_80800404;
    }
    // 0x808004B4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_808004B8:
    // 0x808004B8: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x808004BC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x808004C0: sw          $s6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r22;
    // 0x808004C4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x808004C8: sw          $s7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r23;
    // 0x808004CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808004D0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x808004D4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x808004D8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808004DC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808004E0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808004E4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808004E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808004EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808004F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004F4: jr          $ra
    // 0x808004F8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808004F8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80091E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091E10: jr          $ra
    // 0x80091E14: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80091E14: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800166DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800166DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800166E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800166E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800166E8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800166EC: jal         0x80030170
    // 0x800166F0: addiu       $a0, $a0, -0x64A0
    ctx->r4 = ADD32(ctx->r4, -0X64A0);
    osEepromProbe_recomp(rdram, ctx);
        goto after_0;
    // 0x800166F0: addiu       $a0, $a0, -0x64A0
    ctx->r4 = ADD32(ctx->r4, -0X64A0);
    after_0:
    // 0x800166F4: jal         0x80016864
    // 0x800166F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80016864(rdram, ctx);
        goto after_1;
    // 0x800166F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800166FC: jal         0x80014DC4
    // 0x80016700: nop

    func_80014DC4(rdram, ctx);
        goto after_2;
    // 0x80016700: nop

    after_2:
    // 0x80016704: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80016708: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8001670C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80016710: beq         $at, $zero, L_8001671C
    if (ctx->r1 == 0) {
        // 0x80016714: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_8001671C;
    }
    // 0x80016714: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016718: sb          $t7, -0x646D($at)
    MEM_B(-0X646D, ctx->r1) = ctx->r15;
L_8001671C:
    // 0x8001671C: jal         0x8001662C
    // 0x80016720: nop

    func_8001662C(rdram, ctx);
        goto after_3;
    // 0x80016720: nop

    after_3:
    // 0x80016724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016728: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001672C: jr          $ra
    // 0x80016730: nop

    return;
    // 0x80016730: nop

;}
RECOMP_FUNC void _gcextra_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088400: syscall     681
    recomp_syscall_handler(rdram, ctx, 0x80088400);
    return;
    // 0x80088404: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808000C0_bsbbilldrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000CC: lw          $a3, 0x168($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X168);
    // 0x808000D0: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x808000D4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808000D8: beq         $a3, $zero, L_808000F0
    if (ctx->r7 == 0) {
        // 0x808000DC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808000F0;
    }
    // 0x808000DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808000E0: jal         0x800863E8
    // 0x808000E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x808000E8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808000EC: sw          $v0, 0x168($t7)
    MEM_W(0X168, ctx->r15) = ctx->r2;
L_808000F0:
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void func_80800EFC_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800F00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F0C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800F10: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80800F14: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800F18: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80800F1C: jal         0x800EFB24
    // 0x80800F20: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x80800F20: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80800F24: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800F28: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800F2C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800F30: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800F34: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800F38: beq         $t6, $at, L_80801028
    if (ctx->r14 == ctx->r1) {
        // 0x80800F3C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80801028;
    }
    // 0x80800F3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800F40: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80800F44: addiu       $at, $zero, 0x2C2
    ctx->r1 = ADD32(0, 0X2C2);
    // 0x80800F48: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80800F4C: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80800F50: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800F54: addiu       $a3, $s0, 0x24
    ctx->r7 = ADD32(ctx->r16, 0X24);
    // 0x80800F58: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x80800F5C: beq         $t9, $at, L_80800FCC
    if (ctx->r25 == ctx->r1) {
        // 0x80800F60: nop
    
            goto L_80800FCC;
    }
    // 0x80800F60: nop

    // 0x80800F64: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80800F68: bne         $v1, $t6, L_80800F80
    if (ctx->r3 != ctx->r14) {
        // 0x80800F6C: addiu       $a1, $s0, 0x18
        ctx->r5 = ADD32(ctx->r16, 0X18);
            goto L_80800F80;
    }
    // 0x80800F6C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800F70: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800F74: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800F78: b           L_80800F8C
    // 0x80800F7C: nop

        goto L_80800F8C;
    // 0x80800F7C: nop

L_80800F80:
    // 0x80800F80: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800F84: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800F88: nop

L_80800F8C:
    // 0x80800F8C: bne         $v1, $v0, L_80800FA4
    if (ctx->r3 != ctx->r2) {
        // 0x80800F90: addiu       $a3, $s0, 0x24
        ctx->r7 = ADD32(ctx->r16, 0X24);
            goto L_80800FA4;
    }
    // 0x80800F90: addiu       $a3, $s0, 0x24
    ctx->r7 = ADD32(ctx->r16, 0X24);
    // 0x80800F94: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800F98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800F9C: b           L_80800FB4
    // 0x80800FA0: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
        goto L_80800FB4;
    // 0x80800FA0: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
L_80800FA4:
    // 0x80800FA4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800FA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800FAC: nop

    // 0x80800FB0: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
L_80800FB4:
    // 0x80800FB4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80800FB8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80800FBC: jal         0x80800CEC
    // 0x80800FC0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80800CEC_chpiranha(rdram, ctx);
        goto after_1;
    // 0x80800FC0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800FC4: b           L_80801050
    // 0x80800FC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_80801050;
    // 0x80800FC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800FCC:
    // 0x80800FCC: bne         $v1, $v0, L_80800FE4
    if (ctx->r3 != ctx->r2) {
        // 0x80800FD0: lui         $at, 0x41C8
        ctx->r1 = S32(0X41C8 << 16);
            goto L_80800FE4;
    }
    // 0x80800FD0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800FD4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800FD8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800FDC: b           L_80800FEC
    // 0x80800FE0: nop

        goto L_80800FEC;
    // 0x80800FE0: nop

L_80800FE4:
    // 0x80800FE4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800FE8: nop

L_80800FEC:
    // 0x80800FEC: bne         $v1, $v0, L_80801004
    if (ctx->r3 != ctx->r2) {
        // 0x80800FF0: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80801004;
    }
    // 0x80800FF0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800FF4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800FF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800FFC: b           L_80801010
    // 0x80801000: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
        goto L_80801010;
    // 0x80801000: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
L_80801004:
    // 0x80801004: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801008: nop

    // 0x8080100C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
L_80801010:
    // 0x80801010: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80801014: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80801018: jal         0x80800CEC
    // 0x8080101C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80800CEC_chpiranha(rdram, ctx);
        goto after_2;
    // 0x8080101C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_2:
    // 0x80801020: b           L_80801050
    // 0x80801024: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_80801050;
    // 0x80801024: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80801028:
    // 0x80801028: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080102C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801030: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80801034: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80801038: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080103C: addiu       $a3, $s0, 0x24
    ctx->r7 = ADD32(ctx->r16, 0X24);
    // 0x80801040: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80801044: jal         0x80800CEC
    // 0x80801048: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80800CEC_chpiranha(rdram, ctx);
        goto after_3;
    // 0x80801048: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8080104C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80801050:
    // 0x80801050: jal         0x800EF04C
    // 0x80801054: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80801054: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x80801058: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080105C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801060: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801064: jr          $ra
    // 0x80801068: nop

    return;
    // 0x80801068: nop

;}
RECOMP_FUNC void func_800E7B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E7B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7B90: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E7B94: lui         $t8, 0x12
    ctx->r24 = S32(0X12 << 16);
    // 0x800E7B98: addiu       $t8, $t8, 0x3340
    ctx->r24 = ADD32(ctx->r24, 0X3340);
    // 0x800E7B9C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E7BA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E7BA4: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800E7BA8: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x800E7BAC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E7BB0: jal         0x800E7FF8
    // 0x800E7BB4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    func_800E7FF8(rdram, ctx);
        goto after_0;
    // 0x800E7BB4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    after_0:
    // 0x800E7BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E7BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E7BC0: jr          $ra
    // 0x800E7BC4: nop

    return;
    // 0x800E7BC4: nop

;}
RECOMP_FUNC void func_80801DB8_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801DBC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80801DC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801DC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801DC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801DCC: addiu       $a2, $s0, 0x148
    ctx->r6 = ADD32(ctx->r16, 0X148);
    // 0x80801DD0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801DD4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801DD8: jal         0x80800000
    // 0x80801DDC: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_80800000_ncpoddialog(rdram, ctx);
        goto after_0;
    // 0x80801DDC: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80801DE0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801DE4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801DE8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80801DEC: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80801DF0: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x80801DF4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80801DF8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80801DFC: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80801E00: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80801E04: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801E08: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80801E0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801E10: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80801E14: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80801E18: lwc1        $f4, 0x44($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X44);
    // 0x80801E1C: bc1f        L_80801E28
    if (!c1cs) {
        // 0x80801E20: add.s       $f12, $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
            goto L_80801E28;
    }
    // 0x80801E20: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x80801E24: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80801E28:
    // 0x80801E28: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80801E2C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80801E30: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80801E34: nop

    // 0x80801E38: bc1fl       L_80801E48
    if (!c1cs) {
        // 0x80801E3C: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_80801E48;
    }
    goto skip_0;
    // 0x80801E3C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x80801E40: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80801E44: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_80801E48:
    // 0x80801E48: jal         0x800EEB9C
    // 0x80801E4C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x80801E4C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80801E50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801E54: jal         0x800EF04C
    // 0x80801E58: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80801E58: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80801E5C: lwc1        $f10, 0x14C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x80801E60: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    // 0x80801E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801E6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801E70: jr          $ra
    // 0x80801E74: nop

    return;
    // 0x80801E74: nop

;}
RECOMP_FUNC void func_80104F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104F2C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80104F30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80104F34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80104F38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80104F3C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80104F40: bne         $a1, $zero, L_80104F4C
    if (ctx->r5 != 0) {
        // 0x80104F44: sw          $a2, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r6;
            goto L_80104F4C;
    }
    // 0x80104F44: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80104F48: beq         $a2, $zero, L_80104FFC
    if (ctx->r6 == 0) {
        // 0x80104F4C: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80104FFC;
    }
L_80104F4C:
    // 0x80104F4C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80104F50: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80104F54: jal         0x800EE7F8
    // 0x80104F58: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80104F58: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x80104F5C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80104F60: jal         0x800EE7F8
    // 0x80104F64: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80104F64: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80104F68: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80104F6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80104F70: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80104F74: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80104F78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80104F7C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80104F80: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80104F84: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80104F88: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80104F8C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80104F90: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80104F94: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80104F98: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80104F9C: jal         0x800BEF00
    // 0x80104FA0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x80104FA0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_2:
    // 0x80104FA4: beq         $v0, $zero, L_80104FFC
    if (ctx->r2 == 0) {
        // 0x80104FA8: lw          $t8, 0x5C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X5C);
            goto L_80104FFC;
    }
    // 0x80104FA8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80104FAC: beq         $t8, $zero, L_80104FC4
    if (ctx->r24 == 0) {
        // 0x80104FB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80104FC4;
    }
    // 0x80104FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80104FB4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80104FB8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80104FBC: jal         0x801045AC
    // 0x80104FC0: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    func_801045AC(rdram, ctx);
        goto after_3;
    // 0x80104FC0: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    after_3:
L_80104FC4:
    // 0x80104FC4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80104FC8: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80104FCC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80104FD0: beq         $t9, $zero, L_80104FFC
    if (ctx->r25 == 0) {
        // 0x80104FD4: addiu       $a1, $sp, 0x34
        ctx->r5 = ADD32(ctx->r29, 0X34);
            goto L_80104FFC;
    }
    // 0x80104FD4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80104FD8: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80104FDC: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80104FE0: jal         0x800F1B78
    // 0x80104FE4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800F1B78(rdram, ctx);
        goto after_4;
    // 0x80104FE4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80104FE8: beq         $v0, $zero, L_80104FFC
    if (ctx->r2 == 0) {
        // 0x80104FEC: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80104FFC;
    }
    // 0x80104FEC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80104FF0: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x80104FF4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80104FF8: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
L_80104FFC:
    // 0x80104FFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80105000: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80105004: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80105008: jr          $ra
    // 0x8010500C: nop

    return;
    // 0x8010500C: nop

;}
RECOMP_FUNC void func_80800044_chtntbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080004C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800050: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800054: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080005C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800060: beq         $t6, $at, L_80800078
    if (ctx->r14 == ctx->r1) {
        // 0x80800064: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800078;
    }
    // 0x80800064: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800068: beq         $t6, $at, L_80800108
    if (ctx->r14 == ctx->r1) {
        // 0x8080006C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800108;
    }
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: b           L_8080014C
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080014C;
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800078:
    // 0x80800078: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080007C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800080: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800084: nop

    // 0x80800088: bc1fl       L_808000AC
    if (!c1cs) {
        // 0x8080008C: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_808000AC;
    }
    goto skip_0;
    // 0x8080008C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80800090: jal         0x800D8FF8
    // 0x80800094: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800094: nop

    after_0:
    // 0x80800098: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080009C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808000A0: b           L_80800148
    // 0x808000A4: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80800148;
    // 0x808000A4: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x808000A8: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_808000AC:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808000B4: bgezl       $t9, L_808000D4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808000B8: lhu         $a1, 0x76($s0)
        ctx->r5 = MEM_HU(ctx->r16, 0X76);
            goto L_808000D4;
    }
    goto skip_1;
    // 0x808000B8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    skip_1:
    // 0x808000BC: jal         0x80089BD8
    // 0x808000C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808000C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000C4: xori        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 ^ 0X1;
    // 0x808000C8: b           L_808000F0
    // 0x808000CC: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
        goto L_808000F0;
    // 0x808000CC: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x808000D0: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_808000D4:
    // 0x808000D4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000D8: srl         $t0, $a1, 7
    ctx->r8 = S32(U32(ctx->r5) >> 7);
    // 0x808000DC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808000E0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x808000E4: jal         0x8010C9B0
    // 0x808000E8: sll         $a1, $t1, 1
    ctx->r5 = S32(ctx->r9 << 1);
    func_8010C9B0(rdram, ctx);
        goto after_2;
    // 0x808000E8: sll         $a1, $t1, 1
    ctx->r5 = S32(ctx->r9 << 1);
    after_2:
    // 0x808000EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808000F0:
    // 0x808000F0: beq         $v1, $zero, L_80800148
    if (ctx->r3 == 0) {
        // 0x808000F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800148;
    }
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: jal         0x80102424
    // 0x808000FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808000FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800100: b           L_8080014C
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080014C;
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800108:
    // 0x80800108: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8080010C: jal         0x80101E14
    // 0x80800110: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_4;
    // 0x80800110: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_4:
    // 0x80800114: beq         $v0, $zero, L_80800124
    if (ctx->r2 == 0) {
        // 0x80800118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800124;
    }
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x80108B04
    // 0x80800120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x80800120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_80800124:
    // 0x80800124: jal         0x80101DDC
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_6;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080012C: beq         $v0, $zero, L_80800148
    if (ctx->r2 == 0) {
        // 0x80800130: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800148;
    }
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x80102424
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8080013C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1892, 0X8B0) << 16);
    // 0x80800140: lwc1        $f16, 0x8B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1892, 0X8B0));
    // 0x80800144: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_80800148:
    // 0x80800148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080014C:
    // 0x8080014C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800150: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void func_800E7694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7694: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800E7698: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E769C: jr          $ra
    // 0x800E76A0: sb          $t6, -0x2A5C($at)
    MEM_B(-0X2A5C, ctx->r1) = ctx->r14;
    return;
    // 0x800E76A0: sb          $t6, -0x2A5C($at)
    MEM_B(-0X2A5C, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_808005C8_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005D0: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x808005D4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808005D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808005DC: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x808005E0: beq         $t6, $at, L_80800608
    if (ctx->r14 == ctx->r1) {
        // 0x808005E4: addiu       $at, $zero, 0x33
        ctx->r1 = ADD32(0, 0X33);
            goto L_80800608;
    }
    // 0x808005E4: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x808005E8: beq         $t6, $at, L_80800618
    if (ctx->r14 == ctx->r1) {
        // 0x808005EC: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_80800618;
    }
    // 0x808005EC: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x808005F0: beql        $t6, $at, L_80800630
    if (ctx->r14 == ctx->r1) {
        // 0x808005F4: lhu         $t4, 0x6E($a0)
        ctx->r12 = MEM_HU(ctx->r4, 0X6E);
            goto L_80800630;
    }
    goto skip_0;
    // 0x808005F4: lhu         $t4, 0x6E($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X6E);
    skip_0:
    // 0x808005F8: lhu         $t7, 0x6E($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X6E);
    // 0x808005FC: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800600: b           L_8080063C
    // 0x80800604: sh          $t8, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r24;
        goto L_8080063C;
    // 0x80800604: sh          $t8, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r24;
L_80800608:
    // 0x80800608: lhu         $t9, 0x6E($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6E);
    // 0x8080060C: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800610: b           L_8080063C
    // 0x80800614: sh          $t0, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r8;
        goto L_8080063C;
    // 0x80800614: sh          $t0, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r8;
L_80800618:
    // 0x80800618: lhu         $t1, 0x6E($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X6E);
    // 0x8080061C: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x80800620: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80800624: b           L_8080063C
    // 0x80800628: sh          $t3, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r11;
        goto L_8080063C;
    // 0x80800628: sh          $t3, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r11;
    // 0x8080062C: lhu         $t4, 0x6E($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X6E);
L_80800630:
    // 0x80800630: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x80800634: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x80800638: sh          $t6, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r14;
L_8080063C:
    // 0x8080063C: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x80800640: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1624, 0XB14) << 16);
    // 0x80800644: lwc1        $f6, 0xB14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1624, 0XB14));
    // 0x80800648: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080064C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800650: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80800654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800658: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8080065C: jal         0x80101FDC
    // 0x80800660: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800660: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800664: lui         $a1, 0x3EF5
    ctx->r5 = S32(0X3EF5 << 16);
    // 0x80800668: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080066C: jal         0x80101EE4
    // 0x80800670: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    func_80101EE4(rdram, ctx);
        goto after_1;
    // 0x80800670: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    after_1:
    // 0x80800674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080067C: jr          $ra
    // 0x80800680: nop

    return;
    // 0x80800680: nop

;}
RECOMP_FUNC void func_808040D8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808040D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808040DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808040E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808040E4: jal         0x80100094
    // 0x808040E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808040E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808040EC: lbu         $t6, 0xA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XA);
    // 0x808040F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808040F4: beq         $t6, $zero, L_80804108
    if (ctx->r14 == 0) {
        // 0x808040F8: nop
    
            goto L_80804108;
    }
    // 0x808040F8: nop

    // 0x808040FC: jal         0x800E8C08
    // 0x80804100: lbu         $a0, 0xA($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XA);
    func_800E8C08(rdram, ctx);
        goto after_1;
    // 0x80804100: lbu         $a0, 0xA($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XA);
    after_1:
    // 0x80804104: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
L_80804108:
    // 0x80804108: jal         0x80089D48
    // 0x8080410C: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080410C: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    after_2:
    // 0x80804110: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x80804114: jal         0x80089D48
    // 0x80804118: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80804118: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_3:
    // 0x8080411C: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x80804120: jal         0x80089D48
    // 0x80804124: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80804124: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    after_4:
    // 0x80804128: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x8080412C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804130: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804138: jr          $ra
    // 0x8080413C: nop

    return;
    // 0x8080413C: nop

;}
RECOMP_FUNC void badeathmatch_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001A0: jal         0x800A3274
    // 0x808001A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x808001A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001A8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808001AC: beql        $v0, $at, L_80800238
    if (ctx->r2 == ctx->r1) {
        // 0x808001B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800238;
    }
    goto skip_0;
    // 0x808001B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001B4: jal         0x8009E6F8
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_1;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001BC: addiu       $at, $zero, 0xD7
    ctx->r1 = ADD32(0, 0XD7);
    // 0x808001C0: beql        $v0, $at, L_80800238
    if (ctx->r2 == ctx->r1) {
        // 0x808001C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800238;
    }
    goto skip_1;
    // 0x808001C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808001C8: lw          $v0, 0x158($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X158);
    // 0x808001CC: lbu         $t6, 0x21($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X21);
    // 0x808001D0: bnel        $t6, $zero, L_80800210
    if (ctx->r14 != 0) {
        // 0x808001D4: lbu         $t9, 0x22($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X22);
            goto L_80800210;
    }
    goto skip_2;
    // 0x808001D4: lbu         $t9, 0x22($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X22);
    skip_2:
    // 0x808001D8: lbu         $v1, 0x23($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X23);
    // 0x808001DC: sltiu       $t7, $v1, 0x1
    ctx->r15 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x808001E0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x808001E4: beql        $t8, $zero, L_80800238
    if (ctx->r24 == 0) {
        // 0x808001E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800238;
    }
    goto skip_3;
    // 0x808001E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808001EC: jal         0x80097D28
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097D28(rdram, ctx);
        goto after_2;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001F4: beql        $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x808001F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800238;
    }
    goto skip_4;
    // 0x808001F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x808001FC: jal         0x80800038
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    badeathmatch_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800204: b           L_80800238
    // 0x80800208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800238;
    // 0x80800208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080020C: lbu         $t9, 0x22($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X22);
L_80800210:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: beql        $t9, $zero, L_80800238
    if (ctx->r25 == 0) {
        // 0x80800218: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800238;
    }
    goto skip_5;
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8080021C: jal         0x800852F0
    // 0x80800220: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _batimer_decrement(rdram, ctx);
        goto after_4;
    // 0x80800220: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_4:
    // 0x80800224: beq         $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800228: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800234;
    }
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: jal         0x808003B8
    // 0x80800230: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    badeathmatch_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800230: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
L_80800234:
    // 0x80800234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800238:
    // 0x80800238: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080023C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800240: jr          $ra
    // 0x80800244: nop

    return;
    // 0x80800244: nop

;}
RECOMP_FUNC void suexpression_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800428: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080042C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800430: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800434: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800438: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8080043C: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80800440: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800444: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800448: beq         $v0, $zero, L_80800458
    if (ctx->r2 == 0) {
        // 0x8080044C: addu        $a1, $s0, $v0
        ctx->r5 = ADD32(ctx->r16, ctx->r2);
            goto L_80800458;
    }
    // 0x8080044C: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    // 0x80800450: jal         0x80089778
    // 0x80800454: lbu         $a2, 0x12($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X12);
    _suexpressjoint_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800454: lbu         $a2, 0x12($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X12);
    after_0:
L_80800458:
    // 0x80800458: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8080045C: beql        $v0, $zero, L_80800470
    if (ctx->r2 == 0) {
        // 0x80800460: lh          $t6, 0x4($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X4);
            goto L_80800470;
    }
    goto skip_0;
    // 0x80800460: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    skip_0:
    // 0x80800464: jal         0x80089B40
    // 0x80800468: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    _suexpressmorph_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800468: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    after_1:
    // 0x8080046C: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
L_80800470:
    // 0x80800470: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80800474: bne         $t6, $zero, L_808004A0
    if (ctx->r14 != 0) {
        // 0x80800478: nop
    
            goto L_808004A0;
    }
    // 0x80800478: nop

    // 0x8080047C: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x80800480: bne         $t7, $zero, L_808004A0
    if (ctx->r15 != 0) {
        // 0x80800484: nop
    
            goto L_808004A0;
    }
    // 0x80800484: nop

    // 0x80800488: lh          $t8, 0x8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8);
    // 0x8080048C: bne         $t8, $zero, L_808004A0
    if (ctx->r24 != 0) {
        // 0x80800490: nop
    
            goto L_808004A0;
    }
    // 0x80800490: nop

    // 0x80800494: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x80800498: beql        $t9, $zero, L_8080057C
    if (ctx->r25 == 0) {
        // 0x8080049C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8080057C;
    }
    goto skip_1;
    // 0x8080049C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_1:
L_808004A0:
    // 0x808004A0: beq         $t0, $zero, L_808004BC
    if (ctx->r8 == 0) {
        // 0x808004A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004BC;
    }
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808004AC: jal         0x8080073C
    // 0x808004B0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    suexpression_entrypoint_15(rdram, ctx);
        goto after_2;
    // 0x808004B0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_2:
    // 0x808004B4: b           L_80800568
    // 0x808004B8: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
        goto L_80800568;
    // 0x808004B8: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
L_808004BC:
    // 0x808004BC: jal         0x8010D23C
    // 0x808004C0: nop

    func_8010D23C(rdram, ctx);
        goto after_3;
    // 0x808004C0: nop

    after_3:
    // 0x808004C4: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x808004C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080055C;
    }
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: lbu         $t1, 0x13($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X13);
    // 0x808004D0: bne         $t1, $zero, L_8080055C
    if (ctx->r9 != 0) {
        // 0x808004D4: nop
    
            goto L_8080055C;
    }
    // 0x808004D4: nop

    // 0x808004D8: jal         0x80106790
    // 0x808004DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x808004DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x808004E0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808004E4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808004E8: jal         0x8008FE94
    // 0x808004EC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8008FE94(rdram, ctx);
        goto after_5;
    // 0x808004EC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x808004F0: lh          $t2, 0xE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE);
    // 0x808004F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004F8: beq         $t2, $zero, L_80800534
    if (ctx->r10 == 0) {
        // 0x808004FC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80800534;
    }
    // 0x808004FC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800500: jal         0x800EEB40
    // 0x80800504: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EEB40(rdram, ctx);
        goto after_6;
    // 0x80800504: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x80800508: lh          $v0, 0xE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE);
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800510: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800514: mflo        $t3
    ctx->r11 = lo;
    // 0x80800518: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8080051C: nop

    // 0x80800520: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800524: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800528: nop

    // 0x8080052C: bc1f        L_8080054C
    if (!c1cs) {
        // 0x80800530: nop
    
            goto L_8080054C;
    }
    // 0x80800530: nop

L_80800534:
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8080053C: jal         0x8080073C
    // 0x80800540: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    suexpression_entrypoint_15(rdram, ctx);
        goto after_7;
    // 0x80800540: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x80800544: b           L_80800568
    // 0x80800548: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
        goto L_80800568;
    // 0x80800548: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
L_8080054C:
    // 0x8080054C: jal         0x80800AE8
    // 0x80800550: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    suexpression_entrypoint_16(rdram, ctx);
        goto after_8;
    // 0x80800550: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_8:
    // 0x80800554: b           L_80800568
    // 0x80800558: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
        goto L_80800568;
    // 0x80800558: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
L_8080055C:
    // 0x8080055C: jal         0x80800AE8
    // 0x80800560: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    suexpression_entrypoint_16(rdram, ctx);
        goto after_9;
    // 0x80800560: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_9:
    // 0x80800564: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
L_80800568:
    // 0x80800568: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080056C: bnel        $t4, $at, L_8080057C
    if (ctx->r12 != ctx->r1) {
        // 0x80800570: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8080057C;
    }
    goto skip_2;
    // 0x80800570: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_2:
    // 0x80800574: sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    // 0x80800578: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8080057C:
    // 0x8080057C: sb          $t5, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r13;
    // 0x80800580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800584: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800588: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080058C: jr          $ra
    // 0x80800590: nop

    return;
    // 0x80800590: nop

;}
RECOMP_FUNC void func_8001B4E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B4E8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001B4EC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001B4F0: addiu       $v0, $v0, -0x3920
    ctx->r2 = ADD32(ctx->r2, -0X3920);
    // 0x8001B4F4: addiu       $v1, $v1, -0x40E0
    ctx->r3 = ADD32(ctx->r3, -0X40E0);
    // 0x8001B4F8: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
L_8001B4FC:
    // 0x8001B4FC: bnel        $v1, $v0, L_8001B4FC
    if (ctx->r3 != ctx->r2) {
        // 0x8001B500: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_8001B4FC;
    }
    goto skip_0;
    // 0x8001B500: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    skip_0:
    // 0x8001B504: jr          $ra
    // 0x8001B508: nop

    return;
    // 0x8001B508: nop

;}
RECOMP_FUNC void func_800A5124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A512C: jal         0x800A9318
    // 0x800A5130: nop

    func_800A9318(rdram, ctx);
        goto after_0;
    // 0x800A5130: nop

    after_0:
    // 0x800A5134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5138: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A513C: jr          $ra
    // 0x800A5140: nop

    return;
    // 0x800A5140: nop

;}
RECOMP_FUNC void func_800DF4A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF4A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF4A8: jr          $ra
    // 0x800DF4AC: sw          $a0, -0x36A0($at)
    MEM_W(-0X36A0, ctx->r1) = ctx->r4;
    return;
    // 0x800DF4AC: sw          $a0, -0x36A0($at)
    MEM_W(-0X36A0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800F4C_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F54: jal         0x808006F0
    // 0x80800F58: nop

    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800F58: nop

    after_0:
    // 0x80800F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F64: jr          $ra
    // 0x80800F68: nop

    return;
    // 0x80800F68: nop

;}
RECOMP_FUNC void _bskaz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832F0: syscall     53
    recomp_syscall_handler(rdram, ctx, 0x800832F0);
    return;
    // 0x800832F4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080026C_bsdronegoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080026C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800270: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800274: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800278: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080027C: jal         0x8009BB24
    // 0x80800280: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009BB24(rdram, ctx);
        goto after_0;
    // 0x80800280: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80800284: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800288: jal         0x800F1EA4
    // 0x8080028C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F1EA4(rdram, ctx);
        goto after_1;
    // 0x8080028C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80800290: beq         $v0, $zero, L_808002A0
    if (ctx->r2 == 0) {
        // 0x80800294: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A0;
    }
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x8009C914
    // 0x8080029C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    yaw_setIdeal(rdram, ctx);
        goto after_2;
    // 0x8080029C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
L_808002A0:
    // 0x808002A0: jal         0x8009FF00
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FF00(rdram, ctx);
        goto after_3;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002A8: jal         0x80084DD8
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002B0: beql        $v0, $zero, L_8080031C
    if (ctx->r2 == 0) {
        // 0x808002B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080031C;
    }
    goto skip_0;
    // 0x808002B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002B8: lw          $v0, 0x194($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X194);
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: bne         $v0, $zero, L_80800318
    if (ctx->r2 != 0) {
        // 0x808002C4: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80800318;
    }
    // 0x808002C4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x808002C8: jal         0x80084830
    // 0x808002CC: sw          $t6, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->r14;
    _badrone_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x808002CC: sw          $t6, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->r14;
    after_5:
    // 0x808002D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002D4: bne         $v0, $at, L_80800310
    if (ctx->r2 != ctx->r1) {
        // 0x808002D8: nop
    
            goto L_80800310;
    }
    // 0x808002D8: nop

    // 0x808002DC: jal         0x8008E124
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E124(rdram, ctx);
        goto after_6;
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808002E4: beq         $v0, $zero, L_808002FC
    if (ctx->r2 == 0) {
        // 0x808002E8: nop
    
            goto L_808002FC;
    }
    // 0x808002E8: nop

    // 0x808002EC: jal         0x80084740
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_32(rdram, ctx);
        goto after_7;
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002F4: b           L_80800308
    // 0x808002F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80800308;
    // 0x808002F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_808002FC:
    // 0x808002FC: jal         0x80084750
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_34(rdram, ctx);
        goto after_8;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800304: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800308:
    // 0x80800308: jal         0x8009E5C8
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_setState(rdram, ctx);
        goto after_9;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800310:
    // 0x80800310: jal         0x80084818
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80800318:
    // 0x80800318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080031C:
    // 0x8080031C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800320: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800324: jr          $ra
    // 0x80800328: nop

    return;
    // 0x80800328: nop

;}
RECOMP_FUNC void func_800D5034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5034: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D5038: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800D503C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5040: bne         $a1, $at, L_800D504C
    if (ctx->r5 != ctx->r1) {
        // 0x800D5044: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800D504C;
    }
    // 0x800D5044: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800D5048: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800D504C:
    // 0x800D504C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800D5050: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D5054: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800D5058: addiu       $v1, $v1, -0x49C0
    ctx->r3 = ADD32(ctx->r3, -0X49C0);
    // 0x800D505C: addiu       $t7, $a3, -0x1
    ctx->r15 = ADD32(ctx->r7, -0X1);
    // 0x800D5060: sltiu       $at, $t7, 0x13
    ctx->r1 = ctx->r15 < 0X13 ? 1 : 0;
    // 0x800D5064: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D5068: mflo        $t6
    ctx->r14 = lo;
    // 0x800D506C: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x800D5070: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    // 0x800D5074: beq         $at, $zero, L_800D5160
    if (ctx->r1 == 0) {
        // 0x800D5078: lbu         $a1, 0x2($v0)
        ctx->r5 = MEM_BU(ctx->r2, 0X2);
            goto L_800D5160;
    }
    // 0x800D5078: lbu         $a1, 0x2($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X2);
    // 0x800D507C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D5080: addu        $at, $at, $t7
    gpr jr_addend_800D5088 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D5084: lw          $t7, 0x5B8C($at)
    ctx->r15 = ADD32(ctx->r1, 0X5B8C);
    // 0x800D5088: jr          $t7
    // 0x800D508C: nop

    switch (jr_addend_800D5088 >> 2) {
        case 0: goto L_800D5090; break;
        case 1: goto L_800D50C8; break;
        case 2: goto L_800D5160; break;
        case 3: goto L_800D5160; break;
        case 4: goto L_800D5160; break;
        case 5: goto L_800D50D0; break;
        case 6: goto L_800D50D0; break;
        case 7: goto L_800D50D0; break;
        case 8: goto L_800D5160; break;
        case 9: goto L_800D50D8; break;
        case 10: goto L_800D50D8; break;
        case 11: goto L_800D50D0; break;
        case 12: goto L_800D50D0; break;
        case 13: goto L_800D50D0; break;
        case 14: goto L_800D50D0; break;
        case 15: goto L_800D50D0; break;
        case 16: goto L_800D50D0; break;
        case 17: goto L_800D50D0; break;
        case 18: goto L_800D50D0; break;
        default: switch_error(__func__, 0x800D5088, 0x80125B8C);
    }
    // 0x800D508C: nop

L_800D5090:
    // 0x800D5090: sltiu       $at, $a0, 0x14
    ctx->r1 = ctx->r4 < 0X14 ? 1 : 0;
    // 0x800D5094: beq         $at, $zero, L_800D5160
    if (ctx->r1 == 0) {
        // 0x800D5098: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_800D5160;
    }
    // 0x800D5098: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800D509C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D50A0: addu        $at, $at, $t8
    gpr jr_addend_800D50A8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800D50A4: lw          $t8, 0x5BD8($at)
    ctx->r24 = ADD32(ctx->r1, 0X5BD8);
    // 0x800D50A8: jr          $t8
    // 0x800D50AC: nop

    switch (jr_addend_800D50A8 >> 2) {
        case 0: goto L_800D50B0; break;
        case 1: goto L_800D5160; break;
        case 2: goto L_800D50B0; break;
        case 3: goto L_800D5160; break;
        case 4: goto L_800D5160; break;
        case 5: goto L_800D5160; break;
        case 6: goto L_800D50B0; break;
        case 7: goto L_800D50B0; break;
        case 8: goto L_800D50B0; break;
        case 9: goto L_800D5160; break;
        case 10: goto L_800D50B8; break;
        case 11: goto L_800D50B8; break;
        case 12: goto L_800D50B0; break;
        case 13: goto L_800D5160; break;
        case 14: goto L_800D5160; break;
        case 15: goto L_800D50B0; break;
        case 16: goto L_800D50B0; break;
        case 17: goto L_800D5160; break;
        case 18: goto L_800D50B0; break;
        case 19: goto L_800D50B0; break;
        default: switch_error(__func__, 0x800D50A8, 0x80125BD8);
    }
    // 0x800D50AC: nop

L_800D50B0:
    // 0x800D50B0: b           L_800D5160
    // 0x800D50B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
        goto L_800D5160;
    // 0x800D50B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_800D50B8:
    // 0x800D50B8: lbu         $t9, 0x22($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X22);
    // 0x800D50BC: lbu         $t1, 0x1F($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X1F);
    // 0x800D50C0: b           L_800D5160
    // 0x800D50C4: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
        goto L_800D5160;
    // 0x800D50C4: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
L_800D50C8:
    // 0x800D50C8: b           L_800D5160
    // 0x800D50CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800D5160;
    // 0x800D50CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800D50D0:
    // 0x800D50D0: b           L_800D5160
    // 0x800D50D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
        goto L_800D5160;
    // 0x800D50D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_800D50D8:
    // 0x800D50D8: sltiu       $t2, $a0, 0x1
    ctx->r10 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x800D50DC: beq         $t2, $zero, L_800D5110
    if (ctx->r10 == 0) {
        // 0x800D50E0: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800D5110;
    }
    // 0x800D50E0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800D50E4: bne         $a3, $at, L_800D50F4
    if (ctx->r7 != ctx->r1) {
        // 0x800D50E8: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800D50F4;
    }
    // 0x800D50E8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800D50EC: b           L_800D50F8
    // 0x800D50F0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
        goto L_800D50F8;
    // 0x800D50F0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
L_800D50F4:
    // 0x800D50F4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_800D50F8:
    // 0x800D50F8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800D50FC: jal         0x800D4FB8
    // 0x800D5100: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800D4FB8(rdram, ctx);
        goto after_0;
    // 0x800D5100: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D5104: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800D5108: b           L_800D5160
    // 0x800D510C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
        goto L_800D5160;
    // 0x800D510C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_800D5110:
    // 0x800D5110: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D5114: mflo        $t3
    ctx->r11 = lo;
    // 0x800D5118: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800D511C: lbu         $v0, 0x1($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X1);
    // 0x800D5120: bgez        $v0, L_800D5130
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D5124: sra         $a2, $v0, 1
        ctx->r6 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800D5130;
    }
    // 0x800D5124: sra         $a2, $v0, 1
    ctx->r6 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800D5128: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x800D512C: sra         $a2, $at, 1
    ctx->r6 = S32(SIGNED(ctx->r1) >> 1);
L_800D5130:
    // 0x800D5130: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800D5134: bne         $a3, $at, L_800D5154
    if (ctx->r7 != ctx->r1) {
        // 0x800D5138: nop
    
            goto L_800D5154;
    }
    // 0x800D5138: nop

    // 0x800D513C: bgez        $v0, L_800D5150
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D5140: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_800D5150;
    }
    // 0x800D5140: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x800D5144: beq         $t5, $zero, L_800D5150
    if (ctx->r13 == 0) {
        // 0x800D5148: nop
    
            goto L_800D5150;
    }
    // 0x800D5148: nop

    // 0x800D514C: addiu       $t5, $t5, -0x2
    ctx->r13 = ADD32(ctx->r13, -0X2);
L_800D5150:
    // 0x800D5150: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
L_800D5154:
    // 0x800D5154: bnel        $a2, $zero, L_800D5164
    if (ctx->r6 != 0) {
        // 0x800D5158: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800D5164;
    }
    goto skip_0;
    // 0x800D5158: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x800D515C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800D5160:
    // 0x800D5160: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_800D5164:
    // 0x800D5164: jal         0x800D4FB8
    // 0x800D5168: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800D4FB8(rdram, ctx);
        goto after_1;
    // 0x800D5168: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x800D516C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D5174: jr          $ra
    // 0x800D5178: nop

    return;
    // 0x800D5178: nop

;}
RECOMP_FUNC void func_8080007C_chskeletonexplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800084: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800088: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8080008C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800090: jal         0x80100094
    // 0x80800094: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800094: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800098: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080009C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808000A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000A8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x808000AC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808000B0: nop

    // 0x808000B4: bc1fl       L_808000DC
    if (!c1cs) {
        // 0x808000B8: lbu         $t7, 0xF4($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0XF4);
            goto L_808000DC;
    }
    goto skip_0;
    // 0x808000B8: lbu         $t7, 0xF4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF4);
    skip_0:
    // 0x808000BC: jal         0x800D8FF8
    // 0x808000C0: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808000C0: nop

    after_1:
    // 0x808000C4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C8: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x808000CC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808000D0: b           L_808001AC
    // 0x808000D4: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
        goto L_808001AC;
    // 0x808000D4: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x808000D8: lbu         $t7, 0xF4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF4);
L_808000DC:
    // 0x808000DC: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x808000E0: beq         $at, $zero, L_8080019C
    if (ctx->r1 == 0) {
        // 0x808000E4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080019C;
    }
    // 0x808000E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1808, 0X1060) << 16);
    // 0x808000EC: addu        $at, $at, $t7
    gpr jr_addend_808000F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808000F0: lw          $t7, 0x1060($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1808, 0X1060));
    // 0x808000F4: jr          $t7
    // 0x808000F8: nop

    switch (jr_addend_808000F4 >> 2) {
        case 0: goto L_8080019C; break;
        case 1: goto L_808000FC; break;
        case 2: goto L_80800114; break;
        case 3: goto L_8080012C; break;
        case 4: goto L_80800144; break;
        case 5: goto L_8080015C; break;
        case 6: goto L_80800174; break;
        case 7: goto L_8080018C; break;
        default: switch_error(__func__, 0x808000F4, 0x80801060);
    }
    // 0x808000F8: nop

L_808000FC:
    // 0x808000FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1808, 0X1090) << 16);
    // 0x80800100: addiu       $a2, $a2, 0x1090
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1808, 0X1090));
    // 0x80800104: jal         0x80089D18
    // 0x80800108: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800108: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x8080010C: b           L_808001A0
    // 0x80800110: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
        goto L_808001A0;
    // 0x80800110: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80800114:
    // 0x80800114: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1808, 0X10A8) << 16);
    // 0x80800118: addiu       $a2, $a2, 0x10A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1808, 0X10A8));
    // 0x8080011C: jal         0x80089D18
    // 0x80800120: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800120: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_3:
    // 0x80800124: b           L_808001A0
    // 0x80800128: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
        goto L_808001A0;
    // 0x80800128: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_8080012C:
    // 0x8080012C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1808, 0X10C0) << 16);
    // 0x80800130: addiu       $a2, $a2, 0x10C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1808, 0X10C0));
    // 0x80800134: jal         0x80089D18
    // 0x80800138: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800138: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_4:
    // 0x8080013C: b           L_808001A0
    // 0x80800140: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
        goto L_808001A0;
    // 0x80800140: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80800144:
    // 0x80800144: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1808, 0X10D8) << 16);
    // 0x80800148: addiu       $a2, $a2, 0x10D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1808, 0X10D8));
    // 0x8080014C: jal         0x80089D18
    // 0x80800150: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800150: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_5:
    // 0x80800154: b           L_808001A0
    // 0x80800158: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
        goto L_808001A0;
    // 0x80800158: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_8080015C:
    // 0x8080015C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1808, 0X10F0) << 16);
    // 0x80800160: addiu       $a2, $a2, 0x10F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1808, 0X10F0));
    // 0x80800164: jal         0x80089D18
    // 0x80800168: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800168: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_6:
    // 0x8080016C: b           L_808001A0
    // 0x80800170: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
        goto L_808001A0;
    // 0x80800170: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80800174:
    // 0x80800174: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1808, 0X1108) << 16);
    // 0x80800178: addiu       $a2, $a2, 0x1108
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1808, 0X1108));
    // 0x8080017C: jal         0x80089D18
    // 0x80800180: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800180: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_7:
    // 0x80800184: b           L_808001A0
    // 0x80800188: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
        goto L_808001A0;
    // 0x80800188: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_8080018C:
    // 0x8080018C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1808, 0X1120) << 16);
    // 0x80800190: addiu       $a2, $a2, 0x1120
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1808, 0X1120));
    // 0x80800194: jal         0x80089D18
    // 0x80800198: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800198: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
L_8080019C:
    // 0x8080019C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_808001A0:
    // 0x808001A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001A4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A8: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
L_808001AC:
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001B4: jr          $ra
    // 0x808001B8: nop

    return;
    // 0x808001B8: nop

;}
RECOMP_FUNC void ncpod_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800BCC: jal         0x808007D8
    // 0x80800BD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_808007D8_ncpod(rdram, ctx);
        goto after_0;
    // 0x80800BD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800BD4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BD8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800BDC: sw          $t6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r14;
    // 0x80800BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BE8: jr          $ra
    // 0x80800BEC: nop

    return;
    // 0x80800BEC: nop

;}
RECOMP_FUNC void chboxingglove_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(944, 0X750) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x750
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(944, 0X750));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x750
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(944, 0X750));
;}
RECOMP_FUNC void func_80800774_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080077C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800780: addiu       $a1, $zero, 0x816
    ctx->r5 = ADD32(0, 0X816);
    // 0x80800784: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    // 0x80800788: jal         0x801032B0
    // 0x8080078C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801032B0(rdram, ctx);
        goto after_0;
    // 0x8080078C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800790: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800794: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800798: lbu         $t8, 0x65($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X65);
    // 0x8080079C: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x808007A0: jal         0x80100094
    // 0x808007A4: sb          $t9, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r25;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808007A4: sb          $t9, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r25;
    after_1:
    // 0x808007A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007AC: jal         0x800897A8
    // 0x808007B0: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    _suexpression_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808007B0: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    after_2:
    // 0x808007B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007BC: jr          $ra
    // 0x808007C0: nop

    return;
    // 0x808007C0: nop

;}
RECOMP_FUNC void func_80801114_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080111C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801120: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80801124: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(896, 0X13E8) << 16);
    // 0x80801128: addiu       $t7, $t7, 0x13E8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(896, 0X13E8));
    // 0x8080112C: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80801130: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801134: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80801138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080113C: jal         0x800BBCB8
    // 0x80801140: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80801140: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80801144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080114C: jr          $ra
    // 0x80801150: nop

    return;
    // 0x80801150: nop

;}
RECOMP_FUNC void func_80800000_bsdronebitten(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x80800044: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800044: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
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
RECOMP_FUNC void sukickball_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808009C8: jal         0x80100094
    // 0x808009CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009D0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808009D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009D8: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x808009DC: lbu         $v0, 0xA($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0XA);
    // 0x808009E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009E4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x808009E8: jr          $ra
    // 0x808009EC: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
    return;
    // 0x808009EC: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void bstaxi_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808008B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808008BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808008C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008C4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x808008C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008CC: jal         0x80098140
    // 0x808008D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_0;
    // 0x808008D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x808008D4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808008D8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808008DC: jal         0x8008CB10
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808008E4: beq         $v0, $zero, L_80800914
    if (ctx->r2 == 0) {
        // 0x808008E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800914;
    }
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008EC: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x808008F0: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x808008F4: addiu       $t6, $zero, 0x4E20
    ctx->r14 = ADD32(0, 0X4E20);
    // 0x808008F8: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x808008FC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800900: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800904: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800908: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080090C: jal         0x8009DEC0
    // 0x80800910: addiu       $a1, $zero, 0x588
    ctx->r5 = ADD32(0, 0X588);
    func_8009DEC0(rdram, ctx);
        goto after_2;
    // 0x80800910: addiu       $a1, $zero, 0x588
    ctx->r5 = ADD32(0, 0X588);
    after_2:
L_80800914:
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800918: jal         0x8009D3A8
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_3;
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800920: lui         $a1, 0x3DAC
    ctx->r5 = S32(0X3DAC << 16);
    // 0x80800924: ori         $a1, $a1, 0x831
    ctx->r5 = ctx->r5 | 0X831;
    // 0x80800928: jal         0x8008CB10
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800930: beq         $v0, $zero, L_8080094C
    if (ctx->r2 == 0) {
        // 0x80800934: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080094C;
    }
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800938: jal         0x80084538
    // 0x8080093C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _babackpack_set_state(rdram, ctx);
        goto after_5;
    // 0x8080093C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800944: jal         0x800A0CD0
    // 0x80800948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CD0(rdram, ctx);
        goto after_6;
    // 0x80800948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_8080094C:
    // 0x8080094C: jal         0x8008CAEC
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_7;
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800954: beq         $v0, $zero, L_80800960
    if (ctx->r2 == 0) {
        // 0x80800958: addiu       $t8, $zero, 0x125
        ctx->r24 = ADD32(0, 0X125);
            goto L_80800960;
    }
    // 0x80800958: addiu       $t8, $zero, 0x125
    ctx->r24 = ADD32(0, 0X125);
    // 0x8080095C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80800960:
    // 0x80800960: jal         0x8008CAC8
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_8;
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800968: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1F04) << 16);
    // 0x8080096C: lwc1        $f4, 0x1F04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(392, 0X1F04));
    // 0x80800970: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800974: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800978: nop

    // 0x8080097C: bc1f        L_808009B0
    if (!c1cs) {
        // 0x80800980: nop
    
            goto L_808009B0;
    }
    // 0x80800980: nop

    // 0x80800984: jal         0x8009EF10
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_9;
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080098C: blez        $v0, L_8080099C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800990: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080099C;
    }
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800994: addiu       $t9, $zero, 0x123
    ctx->r25 = ADD32(0, 0X123);
    // 0x80800998: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8080099C:
    // 0x8080099C: jal         0x80091A30
    // 0x808009A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_10;
    // 0x808009A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808009A4: beq         $v0, $zero, L_808009B0
    if (ctx->r2 == 0) {
        // 0x808009A8: addiu       $t0, $zero, 0x127
        ctx->r8 = ADD32(0, 0X127);
            goto L_808009B0;
    }
    // 0x808009A8: addiu       $t0, $zero, 0x127
    ctx->r8 = ADD32(0, 0X127);
    // 0x808009AC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_808009B0:
    // 0x808009B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1F08) << 16);
    // 0x808009B4: lwc1        $f6, 0x1F08($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(392, 0X1F08));
    // 0x808009B8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808009C4: nop

    // 0x808009C8: bc1fl       L_808009E8
    if (!c1cs) {
        // 0x808009CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009E8;
    }
    goto skip_0;
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808009D0: jal         0x80091A58
    // 0x808009D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_11;
    // 0x808009D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_11:
    // 0x808009D8: beq         $v0, $zero, L_808009E4
    if (ctx->r2 == 0) {
        // 0x808009DC: addiu       $t1, $zero, 0x124
        ctx->r9 = ADD32(0, 0X124);
            goto L_808009E4;
    }
    // 0x808009DC: addiu       $t1, $zero, 0x124
    ctx->r9 = ADD32(0, 0X124);
    // 0x808009E0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_808009E4:
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009E8:
    // 0x808009E8: jal         0x8009E5C8
    // 0x808009EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x808009EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x808009F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808009F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808009FC: jr          $ra
    // 0x80800A00: nop

    return;
    // 0x80800A00: nop

;}
RECOMP_FUNC void func_8009E6EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E6EC: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E6F0: jr          $ra
    // 0x8009E6F4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    return;
    // 0x8009E6F4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
;}
RECOMP_FUNC void func_80800830_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800830: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800834: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800838: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080083C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800840: or          $t8, $a0, $zero
    ctx->r24 = ctx->r4 | 0;
    // 0x80800844: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80800848: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080084C: addiu       $t9, $zero, 0x35
    ctx->r25 = ADD32(0, 0X35);
    // 0x80800850: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800854: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800858: addiu       $a3, $t8, 0x4
    ctx->r7 = ADD32(ctx->r24, 0X4);
    // 0x8080085C: jal         0x8008A208
    // 0x80800860: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800860: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_0:
    // 0x80800864: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800868: jal         0x80102424
    // 0x8080086C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080086C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80800870: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800874: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80800878: lbu         $t2, 0x2A($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2A);
    // 0x8080087C: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x80800880: sb          $t3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r11;
    // 0x80800884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800888: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080088C: jr          $ra
    // 0x80800890: nop

    return;
    // 0x80800890: nop

;}
RECOMP_FUNC void func_8008FB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FB58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FB5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FB60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FB64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FB68: jal         0x800F54E4
    // 0x8008FB6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FB6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8008FB70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FB74: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008FB78: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008FB7C: jal         0x800F4F34
    // 0x8008FB80: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800F4F34(rdram, ctx);
        goto after_1;
    // 0x8008FB80: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8008FB84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FB88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FB8C: jr          $ra
    // 0x8008FB90: nop

    return;
    // 0x8008FB90: nop

;}
RECOMP_FUNC void func_80800028_ncbaclimb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: jal         0x80112524
    // 0x80800034: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800034: nop

    after_0:
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080003C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void _chglowbo_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AE8: syscall     414
    recomp_syscall_handler(rdram, ctx, 0x80086AE8);
    return;
    // 0x80086AEC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087CE8: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087CE8);
    return;
    // 0x80087CEC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void boot___osCleanupThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void _bsjig_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083208: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x80083208);
    return;
    // 0x8008320C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_808000D0_chmrsboggyhome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D8: jal         0x800897C8
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_800158E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800158E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800158E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800158EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800158F0: jal         0x80015860
    // 0x800158F4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80015860(rdram, ctx);
        goto after_0;
    // 0x800158F4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800158F8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800158FC: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80015900: addiu       $t8, $t8, -0x68E8
    ctx->r24 = ADD32(ctx->r24, -0X68E8);
    // 0x80015904: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80015908: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8001590C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80015910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015914: mflo        $t0
    ctx->r8 = lo;
    // 0x80015918: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001591C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80015920: sb          $zero, -0x68F0($at)
    MEM_B(-0X68F0, ctx->r1) = 0;
    // 0x80015924: jr          $ra
    // 0x80015928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80015928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80109EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109EEC: jr          $ra
    // 0x80109EF0: sh          $a1, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r5;
    return;
    // 0x80109EF0: sh          $a1, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_800C5968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5968: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800C596C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C5970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C5974: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5978: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x800C597C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C5980: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C5984: addiu       $v0, $v0, -0x55E0
    ctx->r2 = ADD32(ctx->r2, -0X55E0);
    // 0x800C5988: bc1tl       L_800C59D0
    if (c1cs) {
        // 0x800C598C: sb          $zero, 0x11($v0)
        MEM_B(0X11, ctx->r2) = 0;
            goto L_800C59D0;
    }
    goto skip_0;
    // 0x800C598C: sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
    skip_0:
    // 0x800C5990: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5994: addiu       $v0, $v0, -0x55E0
    ctx->r2 = ADD32(ctx->r2, -0X55E0);
    // 0x800C5998: lbu         $t7, 0x8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8);
    // 0x800C599C: lbu         $t8, 0x9($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X9);
    // 0x800C59A0: lbu         $t9, 0xA($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XA);
    // 0x800C59A4: sb          $t6, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r14;
    // 0x800C59A8: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x800C59AC: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x800C59B0: sb          $a0, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r4;
    // 0x800C59B4: sb          $a1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r5;
    // 0x800C59B8: sb          $a2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r6;
    // 0x800C59BC: sb          $t7, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r15;
    // 0x800C59C0: sb          $t8, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r24;
    // 0x800C59C4: b           L_800C59E0
    // 0x800C59C8: sb          $t9, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r25;
        goto L_800C59E0;
    // 0x800C59C8: sb          $t9, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r25;
    // 0x800C59CC: sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
L_800C59D0:
    // 0x800C59D0: sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
    // 0x800C59D4: sb          $a1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r5;
    // 0x800C59D8: jal         0x800C57C0
    // 0x800C59DC: sb          $a2, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r6;
    func_800C57C0(rdram, ctx);
        goto after_0;
    // 0x800C59DC: sb          $a2, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r6;
    after_0:
L_800C59E0:
    // 0x800C59E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C59E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C59E8: jr          $ra
    // 0x800C59EC: nop

    return;
    // 0x800C59EC: nop

;}
RECOMP_FUNC void _chgobihailfire_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086330: syscall     308
    recomp_syscall_handler(rdram, ctx, 0x80086330);
    return;
    // 0x80086334: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
