#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsbabykaz_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827F8: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x800827F8);
    return;
    // 0x800827FC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800110_basub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800118: jal         0x800D8FF8
    // 0x8080011C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080011C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800124: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800128: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x8080012C: lwc1        $f2, 0x58($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80800130: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800134: nop

    // 0x80800138: bc1fl       L_8080016C
    if (!c1cs) {
        // 0x8080013C: lbu         $v1, 0x5D($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X5D);
            goto L_8080016C;
    }
    goto skip_0;
    // 0x8080013C: lbu         $v1, 0x5D($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5D);
    skip_0:
    // 0x80800140: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80800144: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80800148: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x8080014C: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80800150: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x80800154: nop

    // 0x80800158: bc1fl       L_8080016C
    if (!c1cs) {
        // 0x8080015C: lbu         $v1, 0x5D($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X5D);
            goto L_8080016C;
    }
    goto skip_1;
    // 0x8080015C: lbu         $v1, 0x5D($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5D);
    skip_1:
    // 0x80800160: sb          $zero, 0x5E($v0)
    MEM_B(0X5E, ctx->r2) = 0;
    // 0x80800164: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x80800168: lbu         $v1, 0x5D($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5D);
L_8080016C:
    // 0x8080016C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800170: beq         $v1, $at, L_80800188
    if (ctx->r3 == ctx->r1) {
        // 0x80800174: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800188;
    }
    // 0x80800174: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800178: beql        $v1, $at, L_808001E0
    if (ctx->r3 == ctx->r1) {
        // 0x8080017C: lwc1        $f16, 0x54($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
            goto L_808001E0;
    }
    goto skip_2;
    // 0x8080017C: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
    skip_2:
    // 0x80800180: b           L_80800248
    // 0x80800184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800248;
    // 0x80800184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800188:
    // 0x80800188: lwc1        $f2, 0x54($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8080018C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800190: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800194: nop

    // 0x80800198: bc1fl       L_808001B4
    if (!c1cs) {
        // 0x8080019C: c.le.s      $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
            goto L_808001B4;
    }
    goto skip_3;
    // 0x8080019C: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    skip_3:
    // 0x808001A0: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x808001A4: swc1        $f8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f8.u32l;
    // 0x808001A8: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x808001AC: lwc1        $f2, 0x54($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X54);
    // 0x808001B0: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
L_808001B4:
    // 0x808001B4: nop

    // 0x808001B8: bc1fl       L_80800248
    if (!c1cs) {
        // 0x808001BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800248;
    }
    goto skip_4;
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x808001C0: lbu         $t6, 0x5E($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5E);
    // 0x808001C4: beql        $t6, $zero, L_80800248
    if (ctx->r14 == 0) {
        // 0x808001C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800248;
    }
    goto skip_5;
    // 0x808001C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x808001CC: jal         0x80800008
    // 0x808001D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800008_basub(rdram, ctx);
        goto after_1;
    // 0x808001D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808001D4: b           L_80800248
    // 0x808001D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800248;
    // 0x808001D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001DC: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
L_808001E0:
    // 0x808001E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001E4: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x808001E8: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
    // 0x808001EC: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x808001F0: lwc1        $f6, 0x54($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X54);
    // 0x808001F4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x808001F8: nop

    // 0x808001FC: bc1fl       L_80800248
    if (!c1cs) {
        // 0x80800200: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800248;
    }
    goto skip_6;
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x80800204: lbu         $t7, 0x5C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5C);
    // 0x80800208: beq         $t7, $zero, L_8080023C
    if (ctx->r15 == 0) {
        // 0x8080020C: nop
    
            goto L_8080023C;
    }
    // 0x8080020C: nop

    // 0x80800210: lbu         $t8, 0x5E($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5E);
    // 0x80800214: beq         $t8, $zero, L_8080022C
    if (ctx->r24 == 0) {
        // 0x80800218: nop
    
            goto L_8080022C;
    }
    // 0x80800218: nop

    // 0x8080021C: jal         0x80800008
    // 0x80800220: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800008_basub(rdram, ctx);
        goto after_2;
    // 0x80800220: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800224: b           L_80800248
    // 0x80800228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800248;
    // 0x80800228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080022C:
    // 0x8080022C: jal         0x80800008
    // 0x80800230: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800008_basub(rdram, ctx);
        goto after_3;
    // 0x80800230: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800234: b           L_80800248
    // 0x80800238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800248;
    // 0x80800238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080023C:
    // 0x8080023C: jal         0x80800008
    // 0x80800240: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800008_basub(rdram, ctx);
        goto after_4;
    // 0x80800240: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800248:
    // 0x80800248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080024C: jr          $ra
    // 0x80800250: nop

    return;
    // 0x80800250: nop

;}
RECOMP_FUNC void func_800D55DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D55DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D55E0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D55E4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800D55E8: addiu       $s3, $s3, -0x4810
    ctx->r19 = ADD32(ctx->r19, -0X4810);
    // 0x800D55EC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800D55F0: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    // 0x800D55F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D55F8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D55FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D5600: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D5604: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x800D5608: jal         0x800B296C
    // 0x800D560C: sw          $a0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r4;
    vector_end(rdram, ctx);
        goto after_0;
    // 0x800D560C: sw          $a0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r4;
    after_0:
    // 0x800D5610: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800D5614: jal         0x800B28C4
    // 0x800D5618: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x800D5618: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_1:
    // 0x800D561C: sltu        $at, $v0, $s2
    ctx->r1 = ctx->r2 < ctx->r18 ? 1 : 0;
    // 0x800D5620: beq         $at, $zero, L_800D5664
    if (ctx->r1 == 0) {
        // 0x800D5624: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800D5664;
    }
    // 0x800D5624: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D5628: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_800D562C:
    // 0x800D562C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D5630: blezl       $t7, L_800D5658
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800D5634: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_800D5658;
    }
    goto skip_0;
    // 0x800D5634: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    skip_0:
L_800D5638:
    // 0x800D5638: jal         0x800D56C4
    // 0x800D563C: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    func_800D56C4(rdram, ctx);
        goto after_2;
    // 0x800D563C: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_2:
    // 0x800D5640: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800D5644: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D5648: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800D564C: bne         $at, $zero, L_800D5638
    if (ctx->r1 != 0) {
        // 0x800D5650: nop
    
            goto L_800D5638;
    }
    // 0x800D5650: nop

    // 0x800D5654: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_800D5658:
    // 0x800D5658: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x800D565C: bnel        $at, $zero, L_800D562C
    if (ctx->r1 != 0) {
        // 0x800D5660: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_800D562C;
    }
    goto skip_1;
    // 0x800D5660: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_1:
L_800D5664:
    // 0x800D5664: jal         0x800B28B8
    // 0x800D5668: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    vector_clear(rdram, ctx);
        goto after_3;
    // 0x800D5668: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_3:
    // 0x800D566C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D5670: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D5674: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D5678: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D567C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D5680: jr          $ra
    // 0x800D5684: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D5684: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80103BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103BF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103BF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80103BFC: bne         $a2, $zero, L_80103C18
    if (ctx->r6 != 0) {
        // 0x80103C00: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80103C18;
    }
    // 0x80103C00: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80103C04: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80103C08: jal         0x80103964
    // 0x80103C0C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80103964(rdram, ctx);
        goto after_0;
    // 0x80103C0C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80103C10: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80103C14: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80103C18:
    // 0x80103C18: bnel        $a2, $zero, L_80103C2C
    if (ctx->r6 != 0) {
        // 0x80103C1C: lbu         $t6, 0x70($a3)
        ctx->r14 = MEM_BU(ctx->r7, 0X70);
            goto L_80103C2C;
    }
    goto skip_0;
    // 0x80103C1C: lbu         $t6, 0x70($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X70);
    skip_0:
    // 0x80103C20: b           L_80103C84
    // 0x80103C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103C84;
    // 0x80103C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80103C28: lbu         $t6, 0x70($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X70);
L_80103C2C:
    // 0x80103C2C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80103C30: beql        $t7, $zero, L_80103C5C
    if (ctx->r15 == 0) {
        // 0x80103C34: lw          $t1, 0x70($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X70);
            goto L_80103C5C;
    }
    goto skip_1;
    // 0x80103C34: lw          $t1, 0x70($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X70);
    skip_1:
    // 0x80103C38: lbu         $t8, 0x71($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X71);
    // 0x80103C3C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80103C40: lh          $a0, 0x60($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X60);
    // 0x80103C44: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80103C48: jal         0x80100A74
    // 0x80103C4C: xor         $a1, $t9, $t0
    ctx->r5 = ctx->r25 ^ ctx->r8;
    func_80100A74(rdram, ctx);
        goto after_1;
    // 0x80103C4C: xor         $a1, $t9, $t0
    ctx->r5 = ctx->r25 ^ ctx->r8;
    after_1:
    // 0x80103C50: b           L_80103C88
    // 0x80103C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80103C88;
    // 0x80103C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103C58: lw          $t1, 0x70($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X70);
L_80103C5C:
    // 0x80103C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80103C60: sll         $t3, $t1, 10
    ctx->r11 = S32(ctx->r9 << 10);
    // 0x80103C64: bgez        $t3, L_80103C7C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80103C68: nop
    
            goto L_80103C7C;
    }
    // 0x80103C68: nop

    // 0x80103C6C: jal         0x80100A74
    // 0x80103C70: lh          $a0, 0x60($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X60);
    func_80100A74(rdram, ctx);
        goto after_2;
    // 0x80103C70: lh          $a0, 0x60($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X60);
    after_2:
    // 0x80103C74: b           L_80103C88
    // 0x80103C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80103C88;
    // 0x80103C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103C7C:
    // 0x80103C7C: jal         0x800B2840
    // 0x80103C80: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800B2840(rdram, ctx);
        goto after_3;
    // 0x80103C80: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
L_80103C84:
    // 0x80103C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103C88:
    // 0x80103C88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103C8C: jr          $ra
    // 0x80103C90: nop

    return;
    // 0x80103C90: nop

;}
RECOMP_FUNC void func_8080009C_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000A8: jal         0x800CEAA8
    // 0x808000AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800CEAA8(rdram, ctx);
        goto after_0;
    // 0x808000AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void func_80800000_bsbanpackwhack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800010: jal         0x800B5BE4
    // 0x80800014: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80800018: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080001C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800024: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080002C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800030: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800034: nop

    // 0x80800038: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8080003C: jal         0x800BA77C
    // 0x80800040: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_1;
    // 0x80800040: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x80800044: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(37, 0X4D0) << 16);
    // 0x80800048: addiu       $t9, $t9, 0x4D0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(37, 0X4D0));
    // 0x8080004C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800050: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800054: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080005C: jal         0x800BABB8
    // 0x80800060: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800060: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800068: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void _chweldarbossfusebox_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086630: syscall     351
    recomp_syscall_handler(rdram, ctx, 0x80086630);
    return;
    // 0x80086634: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chcrackarchwall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F48: syscall     480
    recomp_syscall_handler(rdram, ctx, 0x80086F48);
    return;
    // 0x80086F4C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bawandglow_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800164: lw          $t6, 0x148($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X148);
    // 0x80800168: sb          $zero, 0x10($t6)
    MEM_B(0X10, ctx->r14) = 0;
    // 0x8080016C: lw          $t7, 0x148($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X148);
    // 0x80800170: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    // 0x80800174: jal         0x800EFD24
    // 0x80800178: lw          $a0, 0x148($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X148);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80800178: lw          $a0, 0x148($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X148);
    after_0:
    // 0x8080017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800184: jr          $ra
    // 0x80800188: nop

    return;
    // 0x80800188: nop

;}
RECOMP_FUNC void _gczoomboxdata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088410: syscall     682
    recomp_syscall_handler(rdram, ctx, 0x80088410);
    return;
    // 0x80088414: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chperspexbox_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2088, 0X138) << 16);
    // 0x80800084: jr          $ra
    // 0x80800088: addiu       $v0, $v0, 0x138
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2088, 0X138));
    return;
    // 0x80800088: addiu       $v0, $v0, 0x138
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2088, 0X138));
    // 0x8080008C: nop

;}
RECOMP_FUNC void _chchuffycont_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C38: syscall     433
    recomp_syscall_handler(rdram, ctx, 0x80086C38);
    return;
    // 0x80086C3C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8010473C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010473C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80104740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104744: jal         0x801043D8
    // 0x80104748: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_801043D8(rdram, ctx);
        goto after_0;
    // 0x80104748: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010474C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80104750: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80104754: beql        $a1, $zero, L_8010476C
    if (ctx->r5 == 0) {
        // 0x80104758: lh          $t6, 0x16($a0)
        ctx->r14 = MEM_H(ctx->r4, 0X16);
            goto L_8010476C;
    }
    goto skip_0;
    // 0x80104758: lh          $t6, 0x16($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X16);
    skip_0:
    // 0x8010475C: jal         0x801048E4
    // 0x80104760: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_801048E4(rdram, ctx);
        goto after_1;
    // 0x80104760: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80104764: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80104768: lh          $t6, 0x16($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X16);
L_8010476C:
    // 0x8010476C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104770: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80104774: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80104778: jr          $ra
    // 0x8010477C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    return;
    // 0x8010477C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
;}
RECOMP_FUNC void func_80809310_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809310: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80809314: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80809318: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080931C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80809320: jal         0x80101080
    // 0x80809324: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80809324: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80809328: jal         0x80106790
    // 0x8080932C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x8080932C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80809330: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80809334: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80809338: jal         0x80100094
    // 0x8080933C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x8080933C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80809340: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80809344: lw          $t6, 0xDC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XDC);
    // 0x80809348: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA204) << 16);
    // 0x8080934C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80809350: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80809354: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x80809358: lh          $a2, -0x5DFC($a2)
    ctx->r6 = MEM_H(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA204));
    // 0x8080935C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80809360: jal         0x80802938
    // 0x80809364: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    func_80802938_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80809364: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    after_3:
    // 0x80809368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080936C: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80809370: jal         0x80086688
    // 0x80809374: lui         $a2, 0x4496
    ctx->r6 = S32(0X4496 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80809374: lui         $a2, 0x4496
    ctx->r6 = S32(0X4496 << 16);
    after_4:
    // 0x80809378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080937C: jal         0x800866B8
    // 0x80809380: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x80809380: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    after_5:
    // 0x80809384: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(1480, 0XA240) << 16);
    // 0x80809388: addiu       $a1, $a1, -0x5DC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1480, 0XA240));
    // 0x8080938C: jal         0x800866B0
    // 0x80809390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chexploder_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80809390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80809394: jal         0x808093F8
    // 0x80809398: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808093F8_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x80809398: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8080939C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x808093A0: lw          $a0, 0xE4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XE4);
    // 0x808093A4: beql        $a0, $zero, L_808093B8
    if (ctx->r4 == 0) {
        // 0x808093A8: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_808093B8;
    }
    goto skip_0;
    // 0x808093A8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x808093AC: jal         0x800FFA88
    // 0x808093B0: nop

    func_800FFA88(rdram, ctx);
        goto after_8;
    // 0x808093B0: nop

    after_8:
    // 0x808093B4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_808093B8:
    // 0x808093B8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808093BC: sw          $t9, 0xE4($t0)
    MEM_W(0XE4, ctx->r8) = ctx->r25;
    // 0x808093C0: lw          $t1, 0x3C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X3C);
    // 0x808093C4: beql        $t1, $zero, L_808093E8
    if (ctx->r9 == 0) {
        // 0x808093C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808093E8;
    }
    goto skip_1;
    // 0x808093C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808093CC: jal         0x80802228
    // 0x808093D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x808093D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x808093D4: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x808093D8: sw          $zero, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = 0;
    // 0x808093DC: jal         0x800FFAB0
    // 0x808093E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808093E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x808093E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808093E8:
    // 0x808093E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808093EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808093F0: jr          $ra
    // 0x808093F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808093F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bashoes_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800518: lw          $t6, 0x10C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10C);
    // 0x8080051C: jr          $ra
    // 0x80800520: sw          $a1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r5;
    return;
    // 0x80800520: sw          $a1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80808084_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80808088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080808C: jal         0x80092744
    // 0x80808090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092744(rdram, ctx);
        goto after_0;
    // 0x80808090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080809C: jr          $ra
    // 0x808080A0: nop

    return;
    // 0x808080A0: nop

;}
RECOMP_FUNC void chdoormake_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800188: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080018C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800190: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800194: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800198: jal         0x80800000
    // 0x8080019C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_chdoormake(rdram, ctx);
        goto after_0;
    // 0x8080019C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808001A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808001A4: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001A8: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808001AC: jal         0x800136E4
    // 0x808001B0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x808001B0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x808001B4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808001B8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x808001C4: nop

    // 0x808001C8: sh          $t7, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r15;
    // 0x808001CC: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001D0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808001D4: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x808001D8: jal         0x808008C4
    // 0x808001DC: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    func_808008C4_chdoormake(rdram, ctx);
        goto after_2;
    // 0x808001DC: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    after_2:
    // 0x808001E0: bne         $v0, $zero, L_808001F8
    if (ctx->r2 != 0) {
        // 0x808001E4: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_808001F8;
    }
    // 0x808001E4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x808001E8: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x808001EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808001F0: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x808001F4: bne         $t1, $at, L_80800244
    if (ctx->r9 != ctx->r1) {
        // 0x808001F8: andi        $t3, $t2, 0x1
        ctx->r11 = ctx->r10 & 0X1;
            goto L_80800244;
    }
L_808001F8:
    // 0x808001F8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x808001FC: beq         $t3, $zero, L_80800214
    if (ctx->r11 == 0) {
        // 0x80800200: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_80800214;
    }
    // 0x80800200: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80800204: jal         0x800FFAB0
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080020C: b           L_80800250
    // 0x80800210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800250;
    // 0x80800210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800214:
    // 0x80800214: lh          $t5, 0x10($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X10);
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800220: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80800224: nop

    // 0x80800228: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080022C: jal         0x80101FDC
    // 0x80800230: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800230: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x80800234: jal         0x808000B8
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B8_chdoormake(rdram, ctx);
        goto after_5;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080023C: b           L_80800250
    // 0x80800240: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800250;
    // 0x80800240: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800244:
    // 0x80800244: jal         0x808000B8
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B8_chdoormake(rdram, ctx);
        goto after_6;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080024C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800250:
    // 0x80800250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void func_800DC634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC634: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800DC638: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DC63C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DC640: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DC644: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x800DC648: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DC64C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800DC650: beq         $t6, $zero, L_800DC72C
    if (ctx->r14 == 0) {
        // 0x800DC654: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_800DC72C;
    }
    // 0x800DC654: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800DC658: jal         0x800193C4
    // 0x800DC65C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800193C4(rdram, ctx);
        goto after_0;
    // 0x800DC65C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x800DC660: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800DC664: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800DC668: jal         0x80018E1C
    // 0x800DC66C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    mlMtx_push_translation(rdram, ctx);
        goto after_1;
    // 0x800DC66C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800DC670: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC674: jal         0x80018FE8
    // 0x800DC678: lwc1        $f12, -0x3154($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3154);
    mlMtxRotYaw(rdram, ctx);
        goto after_2;
    // 0x800DC678: lwc1        $f12, -0x3154($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3154);
    after_2:
    // 0x800DC67C: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x800DC680: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC684: bne         $t7, $zero, L_800DC694
    if (ctx->r15 != 0) {
        // 0x800DC688: nop
    
            goto L_800DC694;
    }
    // 0x800DC688: nop

    // 0x800DC68C: jal         0x80018F50
    // 0x800DC690: lwc1        $f12, -0x3158($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3158);
    mlMtxRotPitch(rdram, ctx);
        goto after_3;
    // 0x800DC690: lwc1        $f12, -0x3158($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3158);
    after_3:
L_800DC694:
    // 0x800DC694: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC698: jal         0x80019148
    // 0x800DC69C: lwc1        $f12, -0x36B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X36B8);
    mlMtxScale(rdram, ctx);
        goto after_4;
    // 0x800DC69C: lwc1        $f12, -0x36B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X36B8);
    after_4:
    // 0x800DC6A0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800DC6A4: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DC6A8: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800DC6AC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800DC6B0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800DC6B4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800DC6B8: jal         0x80019C84
    // 0x800DC6BC: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    mlMtxTranslate(rdram, ctx);
        goto after_5;
    // 0x800DC6BC: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_5:
    // 0x800DC6C0: jal         0x80018C28
    // 0x800DC6C4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_6;
    // 0x800DC6C4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x800DC6C8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800DC6CC: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800DC6D0: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x800DC6D4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800DC6D8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800DC6DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800DC6E0: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x800DC6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DC6E8: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800DC6EC: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x800DC6F0: addiu       $t2, $t1, 0x40
    ctx->r10 = ADD32(ctx->r9, 0X40);
    // 0x800DC6F4: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x800DC6F8: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
    // 0x800DC6FC: jal         0x800DE2A4
    // 0x800DC700: addu        $a1, $s1, $t3
    ctx->r5 = ADD32(ctx->r17, ctx->r11);
    func_800DE2A4(rdram, ctx);
        goto after_7;
    // 0x800DC700: addu        $a1, $s1, $t3
    ctx->r5 = ADD32(ctx->r17, ctx->r11);
    after_7:
    // 0x800DC704: jal         0x80018DAC
    // 0x800DC708: nop

    mlMtxPop(rdram, ctx);
        goto after_8;
    // 0x800DC708: nop

    after_8:
    // 0x800DC70C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800DC710: lui         $t5, 0xD838
    ctx->r13 = S32(0XD838 << 16);
    // 0x800DC714: ori         $t5, $t5, 0x2
    ctx->r13 = ctx->r13 | 0X2;
    // 0x800DC718: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800DC71C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800DC720: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x800DC724: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800DC728: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800DC72C:
    // 0x800DC72C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DC730: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DC734: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DC738: jr          $ra
    // 0x800DC73C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800DC73C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void idflashbaddie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000AC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808000B0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808000B4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x808000B8: jr          $ra
    // 0x808000BC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x808000BC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800174C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800174C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800174C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800174C8: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800174CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800174D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800174D4: jal         0x80017778
    // 0x800174D8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80017778(rdram, ctx);
        goto after_0;
    // 0x800174D8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800174DC: bne         $v0, $zero, L_80017524
    if (ctx->r2 != 0) {
        // 0x800174E0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80017524;
    }
    // 0x800174E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800174E4: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800174E8: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800174EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800174F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800174F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800174F8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800174FC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80017500: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017504: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80017508: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001750C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80017510: lbu         $t8, -0x605E($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X605E);
    // 0x80017514: bnel        $t8, $zero, L_80017528
    if (ctx->r24 != 0) {
        // 0x80017518: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80017528;
    }
    goto skip_0;
    // 0x80017518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001751C: jal         0x80017D74
    // 0x80017520: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_80017D74(rdram, ctx);
        goto after_1;
    // 0x80017520: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
L_80017524:
    // 0x80017524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80017528:
    // 0x80017528: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001752C: jr          $ra
    // 0x80017530: nop

    return;
    // 0x80017530: nop

;}
RECOMP_FUNC void subaddiefade_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800370: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800378: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x8080037C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800380: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800384: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800388: bgez        $t8, L_808003B0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080038C: nop
    
            goto L_808003B0;
    }
    // 0x8080038C: nop

    // 0x80800390: jal         0x80800450
    // 0x80800394: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80800450_subaddiefade(rdram, ctx);
        goto after_0;
    // 0x80800394: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800398: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080039C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808003A0: jal         0x800F2F20
    // 0x808003A4: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    func_800F2F20(rdram, ctx);
        goto after_1;
    // 0x808003A4: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    after_1:
    // 0x808003A8: b           L_808003BC
    // 0x808003AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003BC;
    // 0x808003AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B0:
    // 0x808003B0: jal         0x800F2F20
    // 0x808003B4: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    func_800F2F20(rdram, ctx);
        goto after_2;
    // 0x808003B4: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    after_2:
    // 0x808003B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003BC:
    // 0x808003BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003C0: jr          $ra
    // 0x808003C4: nop

    return;
    // 0x808003C4: nop

;}
RECOMP_FUNC void _dbvtxnormal_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A00: syscall     648
    recomp_syscall_handler(rdram, ctx, 0x80087A00);
    return;
    // 0x80087A04: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800198_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800198: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080019C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A8: jal         0x8009E69C
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E69C(rdram, ctx);
        goto after_0;
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808001B0: bne         $v0, $zero, L_808001DC
    if (ctx->r2 != 0) {
        // 0x808001B4: nop
    
            goto L_808001DC;
    }
    // 0x808001B4: nop

    // 0x808001B8: jal         0x8009BC90
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_1;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001C0: jal         0x8009BC6C
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: jal         0x800961AC
    // 0x808001D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x808001D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808001D4: jal         0x8009F2A4
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_func_8009F2A4(rdram, ctx);
        goto after_4;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808001DC:
    // 0x808001DC: jal         0x80083800
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsmum_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001F0: jr          $ra
    // 0x808001F4: nop

    return;
    // 0x808001F4: nop

;}
RECOMP_FUNC void func_801005B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801005B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801005BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801005C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801005C4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x801005C8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x801005CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801005D0: addiu       $s1, $s1, 0x43DC
    ctx->r17 = ADD32(ctx->r17, 0X43DC);
    // 0x801005D4: addiu       $s0, $s0, 0x43A0
    ctx->r16 = ADD32(ctx->r16, 0X43A0);
    // 0x801005D8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
L_801005DC:
    // 0x801005DC: beql        $a0, $zero, L_801005F4
    if (ctx->r4 == 0) {
        // 0x801005E0: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_801005F4;
    }
    goto skip_0;
    // 0x801005E0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x801005E4: jal         0x8001BAFC
    // 0x801005E8: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x801005E8: nop

    after_0:
    // 0x801005EC: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x801005F0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_801005F4:
    // 0x801005F4: bnel        $s0, $s1, L_801005DC
    if (ctx->r16 != ctx->r17) {
        // 0x801005F8: lw          $a0, 0x8($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X8);
            goto L_801005DC;
    }
    goto skip_1;
    // 0x801005F8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x801005FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80100600: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80100604: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80100608: jr          $ra
    // 0x8010060C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010060C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8080001C_chtransparencypot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080001C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800024: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080002C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800030: beq         $a1, $at, L_8080007C
    if (ctx->r5 == ctx->r1) {
        // 0x80800034: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8080007C;
    }
    // 0x80800034: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800038: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080003C: bnel        $a1, $at, L_8080009C
    if (ctx->r5 != ctx->r1) {
        // 0x80800040: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080009C;
    }
    goto skip_0;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800044: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x80800048: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x8080004C: jal         0x8010A570
    // 0x80800050: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    func_8010A570(rdram, ctx);
        goto after_0;
    // 0x80800050: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    after_0:
    // 0x80800054: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800058: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080005C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800060: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800064: jal         0x800DC178
    // 0x80800068: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800068: nop

    after_1:
    // 0x8080006C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800070: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800074: b           L_80800098
    // 0x80800078: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
        goto L_80800098;
    // 0x80800078: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
L_8080007C:
    // 0x8080007C: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80800088: jal         0x8010A590
    // 0x8080008C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_8010A590(rdram, ctx);
        goto after_2;
    // 0x8080008C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_2:
    // 0x80800090: jal         0x80089CA0
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80800098:
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080009C:
    // 0x8080009C: jal         0x80101FDC
    // 0x808000A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808000A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x808000A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void _idglow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CE8: syscall     734
    recomp_syscall_handler(rdram, ctx, 0x80088CE8);
    return;
    // 0x80088CEC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808037E4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808037E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808037E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808037EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808037F0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x808037F4: jal         0x800852F0
    // 0x808037F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x808037F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808037FC: beq         $v0, $zero, L_80803808
    if (ctx->r2 == 0) {
        // 0x80803800: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80803808;
    }
    // 0x80803800: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80803804: addiu       $a2, $zero, 0xCA
    ctx->r6 = ADD32(0, 0XCA);
L_80803808:
    // 0x80803808: beq         $a2, $zero, L_80803818
    if (ctx->r6 == 0) {
        // 0x8080380C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80803818;
    }
    // 0x8080380C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80803810: jal         0x8009E5C8
    // 0x80803814: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80803814: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
L_80803818:
    // 0x80803818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080381C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803820: jr          $ra
    // 0x80803824: nop

    return;
    // 0x80803824: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E98: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E98);
    return;
    // 0x80089E9C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void vpscroll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D4: jal         0x8001B084
    // 0x808000D8: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x808000D8: nop

    after_0:
    // 0x808000DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void bsbanshack_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B40: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800B44: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(45, 0XCF0) << 16);
    // 0x80800B48: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B4C: jr          $ra
    // 0x80800B50: lw          $v0, 0xCF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XCF0));
    return;
    // 0x80800B50: lw          $v0, 0xCF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XCF0));
;}
RECOMP_FUNC void func_80800878_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800878: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080087C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800880: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800884: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800888: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8080088C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800890: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800894: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800898: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080089C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808008A0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808008A4: addiu       $a2, $zero, 0x55F0
    ctx->r6 = ADD32(0, 0X55F0);
    // 0x808008A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808008AC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x808008B0: jal         0x800C4104
    // 0x808008B4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C4104(rdram, ctx);
        goto after_0;
    // 0x808008B4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x808008B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008C0: jr          $ra
    // 0x808008C4: nop

    return;
    // 0x808008C4: nop

;}
RECOMP_FUNC void func_808002D4_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808002DC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808002E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808002E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808002EC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x808002F0: jal         0x80100094
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808002FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800300: slti        $at, $a2, 0x5A
    ctx->r1 = SIGNED(ctx->r6) < 0X5A ? 1 : 0;
    // 0x80800304: bne         $at, $zero, L_80800320
    if (ctx->r1 != 0) {
        // 0x80800308: addiu       $t6, $a2, -0x2E
        ctx->r14 = ADD32(ctx->r6, -0X2E);
            goto L_80800320;
    }
    // 0x80800308: addiu       $t6, $a2, -0x2E
    ctx->r14 = ADD32(ctx->r6, -0X2E);
    // 0x8080030C: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
    // 0x80800310: beq         $a2, $at, L_80800534
    if (ctx->r6 == ctx->r1) {
        // 0x80800314: nop
    
            goto L_80800534;
    }
    // 0x80800314: nop

    // 0x80800318: b           L_808005FC
    // 0x8080031C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005FC;
    // 0x8080031C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800320:
    // 0x80800320: slti        $at, $a2, 0xC
    ctx->r1 = SIGNED(ctx->r6) < 0XC ? 1 : 0;
    // 0x80800324: bne         $at, $zero, L_80800348
    if (ctx->r1 != 0) {
        // 0x80800328: sltiu       $at, $t6, 0x2C
        ctx->r1 = ctx->r14 < 0X2C ? 1 : 0;
            goto L_80800348;
    }
    // 0x80800328: sltiu       $at, $t6, 0x2C
    ctx->r1 = ctx->r14 < 0X2C ? 1 : 0;
    // 0x8080032C: beq         $at, $zero, L_80800354
    if (ctx->r1 == 0) {
        // 0x80800330: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800354;
    }
    // 0x80800330: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800334: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1CD4) << 16);
    // 0x80800338: addu        $at, $at, $t6
    gpr jr_addend_80800340 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080033C: lw          $t6, 0x1CD4($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1CD4));
    // 0x80800340: jr          $t6
    // 0x80800344: nop

    switch (jr_addend_80800340 >> 2) {
        case 0: goto L_8080035C; break;
        case 1: goto L_80800354; break;
        case 2: goto L_80800378; break;
        case 3: goto L_80800354; break;
        case 4: goto L_80800354; break;
        case 5: goto L_80800354; break;
        case 6: goto L_80800354; break;
        case 7: goto L_80800354; break;
        case 8: goto L_80800354; break;
        case 9: goto L_80800354; break;
        case 10: goto L_80800354; break;
        case 11: goto L_80800354; break;
        case 12: goto L_80800354; break;
        case 13: goto L_80800354; break;
        case 14: goto L_80800354; break;
        case 15: goto L_80800394; break;
        case 16: goto L_80800354; break;
        case 17: goto L_80800354; break;
        case 18: goto L_80800354; break;
        case 19: goto L_80800354; break;
        case 20: goto L_80800354; break;
        case 21: goto L_80800354; break;
        case 22: goto L_80800354; break;
        case 23: goto L_80800354; break;
        case 24: goto L_80800354; break;
        case 25: goto L_80800354; break;
        case 26: goto L_80800354; break;
        case 27: goto L_80800400; break;
        case 28: goto L_80800354; break;
        case 29: goto L_80800354; break;
        case 30: goto L_80800354; break;
        case 31: goto L_80800354; break;
        case 32: goto L_80800354; break;
        case 33: goto L_80800354; break;
        case 34: goto L_80800354; break;
        case 35: goto L_80800354; break;
        case 36: goto L_80800354; break;
        case 37: goto L_80800354; break;
        case 38: goto L_80800354; break;
        case 39: goto L_80800354; break;
        case 40: goto L_80800354; break;
        case 41: goto L_80800584; break;
        case 42: goto L_80800354; break;
        case 43: goto L_808005B4; break;
        default: switch_error(__func__, 0x80800340, 0x80801CD4);
    }
    // 0x80800344: nop

L_80800348:
    // 0x80800348: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080034C: beq         $a2, $at, L_808003A8
    if (ctx->r6 == ctx->r1) {
        // 0x80800350: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_808003A8;
    }
    // 0x80800350: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_80800354:
    // 0x80800354: b           L_808005FC
    // 0x80800358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005FC;
    // 0x80800358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080035C:
    // 0x8080035C: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800360: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800364: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800368: jal         0x8080078C
    // 0x8080036C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080078C_chmonsterinterior(rdram, ctx);
        goto after_1;
    // 0x8080036C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800370: b           L_808005FC
    // 0x80800374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005FC;
    // 0x80800374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800378:
    // 0x80800378: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x8080037C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800380: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800384: jal         0x808009C0
    // 0x80800388: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808009C0_chmonsterinterior(rdram, ctx);
        goto after_2;
    // 0x80800388: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8080038C: b           L_80800600
    // 0x80800390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800600;
    // 0x80800390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800394:
    // 0x80800394: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800398: jal         0x80800A44
    // 0x8080039C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800A44_chmonsterinterior(rdram, ctx);
        goto after_3;
    // 0x8080039C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x808003A0: b           L_808005FC
    // 0x808003A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005FC;
    // 0x808003A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A8:
    // 0x808003A8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808003AC: bne         $t7, $at, L_808003F8
    if (ctx->r15 != ctx->r1) {
        // 0x808003B0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808003F8;
    }
    // 0x808003B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003B4: jal         0x8008A2C0
    // 0x808003B8: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808003B8: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    after_4:
    // 0x808003BC: jal         0x800F54E4
    // 0x808003C0: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x808003C0: nop

    after_5:
    // 0x808003C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003C8: jal         0x800F7B9C
    // 0x808003CC: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    func_800F7B9C(rdram, ctx);
        goto after_6;
    // 0x808003CC: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    after_6:
    // 0x808003D0: jal         0x800F54E4
    // 0x808003D4: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x808003D4: nop

    after_7:
    // 0x808003D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003DC: jal         0x800F82D4
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_8;
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808003E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003E8: jal         0x80101FDC
    // 0x808003EC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x808003EC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_9:
    // 0x808003F0: b           L_808005FC
    // 0x808003F4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808005FC;
    // 0x808003F4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808003F8:
    // 0x808003F8: b           L_808005FC
    // 0x808003FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808005FC;
    // 0x808003FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800400:
    // 0x80800400: jal         0x800F54E4
    // 0x80800404: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800404: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_10:
    // 0x80800408: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8080040C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800410: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800414: lhu         $t9, 0x72($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X72);
    // 0x80800418: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x8080041C: beq         $t0, $at, L_8080042C
    if (ctx->r8 == ctx->r1) {
        // 0x80800420: nop
    
            goto L_8080042C;
    }
    // 0x80800420: nop

    // 0x80800424: b           L_808005FC
    // 0x80800428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005FC;
    // 0x80800428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080042C:
    // 0x8080042C: jal         0x80088848
    // 0x80800430: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_11;
    // 0x80800430: nop

    after_11:
    // 0x80800434: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x80800438: addiu       $a0, $zero, 0x370
        ctx->r4 = ADD32(0, 0X370);
            goto L_8080044C;
    }
    // 0x80800438: addiu       $a0, $zero, 0x370
    ctx->r4 = ADD32(0, 0X370);
    // 0x8080043C: jal         0x800FFAB0
    // 0x80800440: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x80800440: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x80800444: b           L_808005FC
    // 0x80800448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005FC;
    // 0x80800448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080044C:
    // 0x8080044C: jal         0x800DA9E4
    // 0x80800450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_13;
    // 0x80800450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800454: bne         $v0, $zero, L_8080049C
    if (ctx->r2 != 0) {
        // 0x80800458: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080049C;
    }
    // 0x80800458: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080045C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800460: addiu       $a1, $a1, 0x4318
    ctx->r5 = ADD32(ctx->r5, 0X4318);
    // 0x80800464: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800468: jal         0x800F49D4
    // 0x8080046C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F49D4(rdram, ctx);
        goto after_14;
    // 0x8080046C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80800470: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800474: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800478: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080047C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800480: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800484: jal         0x8008A2D0
    // 0x80800488: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x80800488: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_15:
    // 0x8080048C: jal         0x800861A8
    // 0x80800490: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x80800490: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80800494: b           L_80800524
    // 0x80800498: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_80800524;
    // 0x80800498: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_8080049C:
    // 0x8080049C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004A0: jal         0x800F49D4
    // 0x808004A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F49D4(rdram, ctx);
        goto after_17;
    // 0x808004A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x808004A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004AC: jal         0x800F7B9C
    // 0x808004B0: addiu       $a1, $zero, 0x8F
    ctx->r5 = ADD32(0, 0X8F);
    func_800F7B9C(rdram, ctx);
        goto after_18;
    // 0x808004B0: addiu       $a1, $zero, 0x8F
    ctx->r5 = ADD32(0, 0X8F);
    after_18:
    // 0x808004B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004B8: jal         0x800F7B9C
    // 0x808004BC: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    func_800F7B9C(rdram, ctx);
        goto after_19;
    // 0x808004BC: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_19:
    // 0x808004C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004C4: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x808004C8: jal         0x800F7C58
    // 0x808004CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F7C58(rdram, ctx);
        goto after_20;
    // 0x808004CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x808004D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808004D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004D8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808004DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808004E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808004E4: jal         0x8008A2C8
    // 0x808004E8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_21;
    // 0x808004E8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_21:
    // 0x808004EC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808004F0: addiu       $t2, $zero, 0xB3
    ctx->r10 = ADD32(0, 0XB3);
    // 0x808004F4: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x808004F8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x808004FC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800500: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80800504: jal         0x8008A208
    // 0x80800508: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_22;
    // 0x80800508: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_22:
    // 0x8080050C: jal         0x800F54E4
    // 0x80800510: nop

    func_800F54E4(rdram, ctx);
        goto after_23;
    // 0x80800510: nop

    after_23:
    // 0x80800514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800518: jal         0x800F82D4
    // 0x8080051C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_24;
    // 0x8080051C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_24:
    // 0x80800520: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800524:
    // 0x80800524: jal         0x80101FDC
    // 0x80800528: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_25;
    // 0x80800528: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_25:
    // 0x8080052C: b           L_808005FC
    // 0x80800530: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005FC;
    // 0x80800530: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800534:
    // 0x80800534: jal         0x800D395C
    // 0x80800538: nop

    func_800D395C(rdram, ctx);
        goto after_26;
    // 0x80800538: nop

    after_26:
    // 0x8080053C: beq         $v0, $zero, L_8080054C
    if (ctx->r2 == 0) {
        // 0x80800540: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_8080054C;
    }
    // 0x80800540: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80800544: b           L_80800550
    // 0x80800548: addiu       $a1, $zero, 0x181A
    ctx->r5 = ADD32(0, 0X181A);
        goto L_80800550;
    // 0x80800548: addiu       $a1, $zero, 0x181A
    ctx->r5 = ADD32(0, 0X181A);
L_8080054C:
    // 0x8080054C: addiu       $a1, $zero, 0x17F2
    ctx->r5 = ADD32(0, 0X17F2);
L_80800550:
    // 0x80800550: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800554: addiu       $t4, $zero, 0xB3
    ctx->r12 = ADD32(0, 0XB3);
    // 0x80800558: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080055C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80800560: jal         0x8008A208
    // 0x80800564: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_27;
    // 0x80800564: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_27:
    // 0x80800568: jal         0x800F54E4
    // 0x8080056C: nop

    func_800F54E4(rdram, ctx);
        goto after_28;
    // 0x8080056C: nop

    after_28:
    // 0x80800570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800574: jal         0x800F82D4
    // 0x80800578: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_29;
    // 0x80800578: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_29:
    // 0x8080057C: b           L_808005FC
    // 0x80800580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005FC;
    // 0x80800580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800584:
    // 0x80800584: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800588: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8080058C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800590: andi        $t5, $a2, 0xFFFF
    ctx->r13 = ctx->r6 & 0XFFFF;
    // 0x80800594: and         $t6, $a3, $at
    ctx->r14 = ctx->r7 & ctx->r1;
    // 0x80800598: srl         $a3, $t6, 16
    ctx->r7 = S32(U32(ctx->r14) >> 16);
    // 0x8080059C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x808005A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005A4: jal         0x8008A2B8
    // 0x808005A8: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_30;
    // 0x808005A8: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    after_30:
    // 0x808005AC: b           L_80800600
    // 0x808005B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800600;
    // 0x808005B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005B4:
    // 0x808005B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808005B8: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x808005BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005C0: beq         $a1, $at, L_808005F0
    if (ctx->r5 == ctx->r1) {
        // 0x808005C4: addiu       $at, $zero, 0xCEC
        ctx->r1 = ADD32(0, 0XCEC);
            goto L_808005F0;
    }
    // 0x808005C4: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x808005C8: bne         $a1, $at, L_808005F8
    if (ctx->r5 != ctx->r1) {
        // 0x808005CC: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808005F8;
    }
    // 0x808005CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005D0: jal         0x8080068C
    // 0x808005D4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8080068C_chmonsterinterior(rdram, ctx);
        goto after_31;
    // 0x808005D4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_31:
    // 0x808005D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808005DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005E0: jal         0x8008A2C0
    // 0x808005E4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_32;
    // 0x808005E4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_32:
    // 0x808005E8: b           L_808005FC
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005FC;
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F0:
    // 0x808005F0: jal         0x8008A2C0
    // 0x808005F4: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_33;
    // 0x808005F4: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    after_33:
L_808005F8:
    // 0x808005F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005FC:
    // 0x808005FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800600:
    // 0x80800600: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800604: jr          $ra
    // 0x80800608: nop

    return;
    // 0x80800608: nop

;}
RECOMP_FUNC void _baflameline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B80: syscall     130
    recomp_syscall_handler(rdram, ctx, 0x80084B80);
    return;
    // 0x80084B84: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chpawnbroker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1012, 0XFD0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xFD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1012, 0XFD0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xFD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1012, 0XFD0));
;}
RECOMP_FUNC void func_8080000C_chminelobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x800EA090
    // 0x80800018: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EA090(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800020: bne         $v0, $at, L_80800058
    if (ctx->r2 != ctx->r1) {
        // 0x80800024: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_80800058;
    }
    // 0x80800024: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80800028: jal         0x800D0A9C
    // 0x8080002C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800030: beql        $v0, $zero, L_80800050
    if (ctx->r2 == 0) {
        // 0x80800034: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800050;
    }
    goto skip_0;
    // 0x80800034: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800038: jal         0x8009E958
    // 0x8080003C: nop

    func_8009E958(rdram, ctx);
        goto after_2;
    // 0x8080003C: nop

    after_2:
    // 0x80800040: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800044: beql        $v0, $at, L_8080005C
    if (ctx->r2 == ctx->r1) {
        // 0x80800048: addiu       $t6, $zero, 0x8
        ctx->r14 = ADD32(0, 0X8);
            goto L_8080005C;
    }
    goto skip_1;
    // 0x80800048: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    skip_1:
    // 0x8080004C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800050:
    // 0x80800050: jal         0x80101FDC
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80800058:
    // 0x80800058: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
L_8080005C:
    // 0x8080005C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800060: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800064: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800068: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080006C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800070: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800074: jal         0x80086898
    // 0x80800078: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800078: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_4:
    // 0x8080007C: beq         $v0, $zero, L_80800098
    if (ctx->r2 == 0) {
        // 0x80800080: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800098;
    }
    // 0x80800080: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800084: jal         0x800868A8
    // 0x80800088: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800088: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_5:
    // 0x8080008C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800090: jal         0x800868C0
    // 0x80800094: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800094: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_6:
L_80800098:
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080009C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000EC: jal         0x80800000
    // 0x808000F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x808000F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000F4: bne         $v0, $zero, L_80800104
    if (ctx->r2 != 0) {
        // 0x808000F8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800104;
    }
    // 0x808000F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000FC: b           L_80800110
    // 0x80800100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800110;
    // 0x80800100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800104:
    // 0x80800104: jal         0x800EE7F8
    // 0x80800108: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800108: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080010C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800110:
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void func_800DAA8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAA8C: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x800DAA90: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800DAA94: bne         $at, $zero, L_800DAAF0
    if (ctx->r1 != 0) {
        // 0x800DAA98: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800DAAF0;
    }
    // 0x800DAA98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DAA9C: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x800DAAA0: andi        $t6, $a3, 0x3
    ctx->r14 = ctx->r7 & 0X3;
    // 0x800DAAA4: beq         $t6, $zero, L_800DAAC8
    if (ctx->r14 == 0) {
        // 0x800DAAA8: addiu       $a1, $t6, 0x1
        ctx->r5 = ADD32(ctx->r14, 0X1);
            goto L_800DAAC8;
    }
    // 0x800DAAA8: addiu       $a1, $t6, 0x1
    ctx->r5 = ADD32(ctx->r14, 0X1);
    // 0x800DAAAC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800DAAB0: addu        $v1, $a0, $t7
    ctx->r3 = ADD32(ctx->r4, ctx->r15);
L_800DAAB4:
    // 0x800DAAB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800DAAB8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800DAABC: bne         $a1, $v0, L_800DAAB4
    if (ctx->r5 != ctx->r2) {
        // 0x800DAAC0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800DAAB4;
    }
    // 0x800DAAC0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800DAAC4: beq         $v0, $a2, L_800DAAF0
    if (ctx->r2 == ctx->r6) {
        // 0x800DAAC8: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_800DAAF0;
    }
L_800DAAC8:
    // 0x800DAAC8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800DAACC: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800DAAD0: addu        $a1, $t9, $a0
    ctx->r5 = ADD32(ctx->r25, ctx->r4);
    // 0x800DAAD4: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
L_800DAAD8:
    // 0x800DAAD8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800DAADC: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x800DAAE0: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x800DAAE4: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x800DAAE8: bne         $v1, $a1, L_800DAAD8
    if (ctx->r3 != ctx->r5) {
        // 0x800DAAEC: sw          $zero, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = 0;
            goto L_800DAAD8;
    }
    // 0x800DAAEC: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
L_800DAAF0:
    // 0x800DAAF0: jr          $ra
    // 0x800DAAF4: nop

    return;
    // 0x800DAAF4: nop

;}
RECOMP_FUNC void func_80800160_chmole_overworld(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800168: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1784, 0X190) << 16);
    // 0x8080016C: jal         0x800899F0
    // 0x80800170: addiu       $a1, $a1, 0x190
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1784, 0X190));
    _sumole_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800170: addiu       $a1, $a1, 0x190
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1784, 0X190));
    after_0:
    // 0x80800174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800178: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
RECOMP_FUNC void bstnt_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F48: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801F4C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(404, 0X259C) << 16);
    // 0x80801F50: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801F54: jr          $ra
    // 0x80801F58: lw          $v0, 0x259C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X259C));
    return;
    // 0x80801F58: lw          $v0, 0x259C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X259C));
;}
RECOMP_FUNC void bacough_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800060: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080006C: beq         $a1, $at, L_80800088
    if (ctx->r5 == ctx->r1) {
        // 0x80800070: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800088;
    }
    // 0x80800070: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800074: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800078: beq         $a1, $at, L_808000A4
    if (ctx->r5 == ctx->r1) {
        // 0x8080007C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808000A4;
    }
    // 0x8080007C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800080: b           L_808000CC
    // 0x80800084: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
        goto L_808000CC;
    // 0x80800084: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
L_80800088:
    // 0x80800088: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800090: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800094: jal         0x8009ADF0
    // 0x80800098: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8009ADF0(rdram, ctx);
        goto after_0;
    // 0x80800098: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080009C: b           L_808000C8
    // 0x808000A0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C8;
    // 0x808000A0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_808000A4:
    // 0x808000A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808000A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000AC: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x808000B0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x808000B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808000B8: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x808000BC: jal         0x8009ADF0
    // 0x808000C0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8009ADF0(rdram, ctx);
        goto after_1;
    // 0x808000C0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x808000C4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_808000C8:
    // 0x808000C8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
L_808000CC:
    // 0x808000CC: lw          $t9, 0x44($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X44);
    // 0x808000D0: sb          $a3, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r7;
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void gspropctrl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8080000C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80800010: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80800014: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80800018: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x8080001C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80800020: lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X6);
    // 0x80800024: srl         $t9, $v0, 7
    ctx->r25 = S32(U32(ctx->r2) >> 7);
    // 0x80800028: jr          $ra
    // 0x8080002C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    return;
    // 0x8080002C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
;}
RECOMP_FUNC void func_8080015C_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800164: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800168: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080016C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800170: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x80800174: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800178: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080017C: srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
    // 0x80800180: beq         $v0, $zero, L_808001A8
    if (ctx->r2 == 0) {
        // 0x80800184: nop
    
            goto L_808001A8;
    }
    // 0x80800184: nop

    // 0x80800188: beq         $v0, $at, L_808001C4
    if (ctx->r2 == ctx->r1) {
        // 0x8080018C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001C4;
    }
    // 0x8080018C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800190: beq         $v0, $at, L_808001B8
    if (ctx->r2 == ctx->r1) {
        // 0x80800194: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808001B8;
    }
    // 0x80800194: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800198: beql        $v0, $at, L_808001BC
    if (ctx->r2 == ctx->r1) {
        // 0x8080019C: andi        $t6, $v1, 0x7F
        ctx->r14 = ctx->r3 & 0X7F;
            goto L_808001BC;
    }
    goto skip_0;
    // 0x8080019C: andi        $t6, $v1, 0x7F
    ctx->r14 = ctx->r3 & 0X7F;
    skip_0:
    // 0x808001A0: b           L_808001D8
    // 0x808001A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001D8;
    // 0x808001A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001A8:
    // 0x808001A8: jal         0x80800000
    // 0x808001AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_chhumba(rdram, ctx);
        goto after_0;
    // 0x808001AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001B4: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
L_808001B8:
    // 0x808001B8: andi        $t6, $v1, 0x7F
    ctx->r14 = ctx->r3 & 0X7F;
L_808001BC:
    // 0x808001BC: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x808001C0: sh          $t7, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r15;
L_808001C4:
    // 0x808001C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808001C8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808001CC: jal         0x800856D0
    // 0x808001D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808001D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808001D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001D8:
    // 0x808001D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001DC: jr          $ra
    // 0x808001E0: nop

    return;
    // 0x808001E0: nop

;}
RECOMP_FUNC void func_80800EE4_chjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EEC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1672, 0X1358) << 16);
    // 0x80800EF0: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x80800EF4: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800EF8: addiu       $a2, $a2, 0x1358
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1672, 0X1358));
    // 0x80800EFC: jal         0x80089D20
    // 0x80800F00: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800F00: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F0C: jr          $ra
    // 0x80800F10: nop

    return;
    // 0x80800F10: nop

;}
RECOMP_FUNC void func_8009659C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009659C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800965A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800965A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800965A8: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800965AC: jal         0x800C6744
    // 0x800965B0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C6744(rdram, ctx);
        goto after_0;
    // 0x800965B0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800965B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800965B8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800965BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800965C0: jr          $ra
    // 0x800965C4: and         $v0, $v0, $t7
    ctx->r2 = ctx->r2 & ctx->r15;
    return;
    // 0x800965C4: and         $v0, $v0, $t7
    ctx->r2 = ctx->r2 & ctx->r15;
;}
RECOMP_FUNC void func_808057BC_inantab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808057BC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808057C0: addiu       $t6, $a0, -0x25
    ctx->r14 = ADD32(ctx->r4, -0X25);
    // 0x808057C4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808057C8: sltiu       $at, $t6, 0x44
    ctx->r1 = ctx->r14 < 0X44 ? 1 : 0;
    // 0x808057CC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808057D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808057D4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808057D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808057DC: beq         $at, $zero, L_808064B8
    if (ctx->r1 == 0) {
        // 0x808057E0: sw          $a2, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r6;
            goto L_808064B8;
    }
    // 0x808057E0: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x808057E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808057E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6974) << 16);
    // 0x808057EC: addu        $at, $at, $t6
    gpr jr_addend_808057F4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808057F0: lw          $t6, 0x6974($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6974));
    // 0x808057F4: jr          $t6
    // 0x808057F8: nop

    switch (jr_addend_808057F4 >> 2) {
        case 0: goto L_80805A24; break;
        case 1: goto L_808057FC; break;
        case 2: goto L_80805AC8; break;
        case 3: goto L_808064B8; break;
        case 4: goto L_808064B8; break;
        case 5: goto L_808064B8; break;
        case 6: goto L_808064B8; break;
        case 7: goto L_808064B8; break;
        case 8: goto L_808064B8; break;
        case 9: goto L_808064B8; break;
        case 10: goto L_808064B8; break;
        case 11: goto L_808064B8; break;
        case 12: goto L_808064B8; break;
        case 13: goto L_808064B8; break;
        case 14: goto L_808064B8; break;
        case 15: goto L_808064B8; break;
        case 16: goto L_808064B8; break;
        case 17: goto L_808064B8; break;
        case 18: goto L_80805968; break;
        case 19: goto L_808064B8; break;
        case 20: goto L_808064B8; break;
        case 21: goto L_808064B8; break;
        case 22: goto L_808064B8; break;
        case 23: goto L_808064B8; break;
        case 24: goto L_808064B8; break;
        case 25: goto L_808064B8; break;
        case 26: goto L_80805E1C; break;
        case 27: goto L_80805E84; break;
        case 28: goto L_80805EAC; break;
        case 29: goto L_80805ED4; break;
        case 30: goto L_80805EFC; break;
        case 31: goto L_808064B8; break;
        case 32: goto L_808064B8; break;
        case 33: goto L_808064B8; break;
        case 34: goto L_80805F24; break;
        case 35: goto L_80805FD4; break;
        case 36: goto L_8080602C; break;
        case 37: goto L_808064B8; break;
        case 38: goto L_808064B8; break;
        case 39: goto L_80806118; break;
        case 40: goto L_8080613C; break;
        case 41: goto L_80806160; break;
        case 42: goto L_80806184; break;
        case 43: goto L_808061A8; break;
        case 44: goto L_808064B8; break;
        case 45: goto L_808064B8; break;
        case 46: goto L_808064B8; break;
        case 47: goto L_80806220; break;
        case 48: goto L_80806258; break;
        case 49: goto L_808064B8; break;
        case 50: goto L_808064B8; break;
        case 51: goto L_808064B8; break;
        case 52: goto L_808064B8; break;
        case 53: goto L_808064B8; break;
        case 54: goto L_808064B8; break;
        case 55: goto L_808064B8; break;
        case 56: goto L_808064B8; break;
        case 57: goto L_808064B8; break;
        case 58: goto L_808064B8; break;
        case 59: goto L_808064B8; break;
        case 60: goto L_80806294; break;
        case 61: goto L_808064B8; break;
        case 62: goto L_808064B8; break;
        case 63: goto L_808064B8; break;
        case 64: goto L_808064B8; break;
        case 65: goto L_808064B8; break;
        case 66: goto L_80805A84; break;
        case 67: goto L_808062D0; break;
        default: switch_error(__func__, 0x808057F4, 0x80806974);
    }
    // 0x808057F8: nop

L_808057FC:
    // 0x808057FC: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80805800: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805804: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805808: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x8080580C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80805810: jal         0x80085998
    // 0x80805814: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80805814: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80805818: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x8080581C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80805820: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80805824: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080582C: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805830: jal         0x80085998
    // 0x80805834: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80805834: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80805838: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7684) << 16);
    // 0x8080583C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80805840: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2958, 0X76D8) << 16);
    // 0x80805844: addiu       $s2, $s2, 0x76D8
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2958, 0X76D8));
    // 0x80805848: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x8080584C: addiu       $v0, $v0, 0x7684
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7684));
    // 0x80805850: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
L_80805854:
    // 0x80805854: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80805858: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8080585C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80805860: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805864: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80805868: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080586C: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80805870: jal         0x80082630
    // 0x80805874: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80805874: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_2:
    // 0x80805878: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8080587C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80805880: bnel        $v0, $s2, L_80805854
    if (ctx->r2 != ctx->r18) {
        // 0x80805884: addiu       $t8, $zero, 0xE
        ctx->r24 = ADD32(0, 0XE);
            goto L_80805854;
    }
    goto skip_0;
    // 0x80805884: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    skip_0:
    // 0x80805888: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7684) << 16);
    // 0x8080588C: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2958, 0X76D8) << 16);
    // 0x80805890: addiu       $s2, $s2, 0x76D8
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2958, 0X76D8));
    // 0x80805894: addiu       $v0, $v0, 0x7684
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7684));
    // 0x80805898: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
L_8080589C:
    // 0x8080589C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x808058A0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808058A4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808058A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808058AC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808058B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808058B4: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x808058B8: jal         0x80082630
    // 0x808058BC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808058BC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_3:
    // 0x808058C0: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x808058C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808058C8: bnel        $v0, $s2, L_8080589C
    if (ctx->r2 != ctx->r18) {
        // 0x808058CC: addiu       $t0, $zero, 0xE
        ctx->r8 = ADD32(0, 0XE);
            goto L_8080589C;
    }
    goto skip_1;
    // 0x808058CC: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
    skip_1:
    // 0x808058D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X76D8) << 16);
    // 0x808058D4: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2958, 0X771C) << 16);
    // 0x808058D8: addiu       $s2, $s2, 0x771C
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2958, 0X771C));
    // 0x808058DC: addiu       $v0, $v0, 0x76D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X76D8));
    // 0x808058E0: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
L_808058E4:
    // 0x808058E4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x808058E8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808058EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808058F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808058F4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808058F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808058FC: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80805900: jal         0x80082630
    // 0x80805904: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80805904: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_4:
    // 0x80805908: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8080590C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80805910: bnel        $v0, $s2, L_808058E4
    if (ctx->r2 != ctx->r18) {
        // 0x80805914: addiu       $t2, $zero, 0xE
        ctx->r10 = ADD32(0, 0XE);
            goto L_808058E4;
    }
    goto skip_2;
    // 0x80805914: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    skip_2:
    // 0x80805918: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X76D8) << 16);
    // 0x8080591C: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2958, 0X771C) << 16);
    // 0x80805920: addiu       $s2, $s2, 0x771C
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2958, 0X771C));
    // 0x80805924: addiu       $v0, $v0, 0x76D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X76D8));
    // 0x80805928: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
L_8080592C:
    // 0x8080592C: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80805930: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80805934: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80805938: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080593C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80805940: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80805944: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80805948: jal         0x80082630
    // 0x8080594C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x8080594C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_5:
    // 0x80805950: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80805954: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80805958: bnel        $v0, $s2, L_8080592C
    if (ctx->r2 != ctx->r18) {
        // 0x8080595C: addiu       $t4, $zero, 0xE
        ctx->r12 = ADD32(0, 0XE);
            goto L_8080592C;
    }
    goto skip_3;
    // 0x8080595C: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    skip_3:
    // 0x80805960: b           L_808064C4
    // 0x80805964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80805964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805968:
    // 0x80805968: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x8080596C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805970: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805974: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805978: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8080597C: jal         0x80085998
    // 0x80805980: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80805980: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80805984: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80805988: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080598C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80805990: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805994: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805998: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x8080599C: jal         0x80085998
    // 0x808059A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x808059A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x808059A4: lui         $a1, 0x3CF5
    ctx->r5 = S32(0X3CF5 << 16);
    // 0x808059A8: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x808059AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808059B0: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x808059B4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808059B8: jal         0x80085998
    // 0x808059BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x808059BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x808059C0: lui         $a1, 0x3EDA
    ctx->r5 = S32(0X3EDA << 16);
    // 0x808059C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808059C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808059CC: ori         $a1, $a1, 0x1CAC
    ctx->r5 = ctx->r5 | 0X1CAC;
    // 0x808059D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808059D4: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x808059D8: jal         0x80085998
    // 0x808059DC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x808059DC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_9:
    // 0x808059E0: lui         $a1, 0x3F6F
    ctx->r5 = S32(0X3F6F << 16);
    // 0x808059E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808059E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808059EC: ori         $a1, $a1, 0x1AA0
    ctx->r5 = ctx->r5 | 0X1AA0;
    // 0x808059F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808059F4: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x808059F8: jal         0x80085998
    // 0x808059FC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x808059FC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_10:
    // 0x80805A00: lui         $a1, 0x3F6F
    ctx->r5 = S32(0X3F6F << 16);
    // 0x80805A04: ori         $a1, $a1, 0x1AA0
    ctx->r5 = ctx->r5 | 0X1AA0;
    // 0x80805A08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805A0C: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805A10: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80805A14: jal         0x80085998
    // 0x80805A18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x80805A18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x80805A1C: b           L_808064C4
    // 0x80805A20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80805A20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805A24:
    // 0x80805A24: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80805A28: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805A2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805A30: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805A34: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80805A38: jal         0x80085998
    // 0x80805A3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80805A3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_12:
    // 0x80805A40: lui         $a1, 0x3D0E
    ctx->r5 = S32(0X3D0E << 16);
    // 0x80805A44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80805A48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80805A4C: ori         $a1, $a1, 0x8A72
    ctx->r5 = ctx->r5 | 0X8A72;
    // 0x80805A50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805A54: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805A58: jal         0x80085998
    // 0x80805A5C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x80805A5C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_13:
    // 0x80805A60: lui         $a1, 0x3ED6
    ctx->r5 = S32(0X3ED6 << 16);
    // 0x80805A64: ori         $a1, $a1, 0x419
    ctx->r5 = ctx->r5 | 0X419;
    // 0x80805A68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805A6C: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805A70: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80805A74: jal         0x80085998
    // 0x80805A78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x80805A78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_14:
    // 0x80805A7C: b           L_808064C4
    // 0x80805A80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80805A80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805A84:
    // 0x80805A84: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80805A88: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805A8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805A90: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805A94: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80805A98: jal         0x80085998
    // 0x80805A9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x80805A9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_15:
    // 0x80805AA0: lui         $a1, 0x3CFF
    ctx->r5 = S32(0X3CFF << 16);
    // 0x80805AA4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80805AA8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80805AAC: ori         $a1, $a1, 0x9724
    ctx->r5 = ctx->r5 | 0X9724;
    // 0x80805AB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805AB4: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805AB8: jal         0x80085998
    // 0x80805ABC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_16;
    // 0x80805ABC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_16:
    // 0x80805AC0: b           L_808064C4
    // 0x80805AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80805AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805AC8:
    // 0x80805AC8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80805ACC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X771C) << 16);
    // 0x80805AD0: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2958, 0X7740) << 16);
    // 0x80805AD4: addiu       $s2, $s2, 0x7740
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2958, 0X7740));
    // 0x80805AD8: addiu       $v0, $v0, 0x771C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X771C));
    // 0x80805ADC: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80805AE0: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
L_80805AE4:
    // 0x80805AE4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80805AE8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80805AEC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80805AF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805AF4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80805AF8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80805AFC: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80805B00: jal         0x80082630
    // 0x80805B04: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80805B04: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_17:
    // 0x80805B08: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80805B0C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80805B10: bnel        $v0, $s2, L_80805AE4
    if (ctx->r2 != ctx->r18) {
        // 0x80805B14: addiu       $t1, $zero, 0xF
        ctx->r9 = ADD32(0, 0XF);
            goto L_80805AE4;
    }
    goto skip_4;
    // 0x80805B14: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    skip_4:
    // 0x80805B18: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80805B1C: lui         $s0, 0x7
    ctx->r16 = S32(0X7 << 16);
    // 0x80805B20: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80805B24: ori         $s0, $s0, 0x6
    ctx->r16 = ctx->r16 | 0X6;
    // 0x80805B28: addiu       $s2, $s2, -0x7078
    ctx->r18 = ADD32(ctx->r18, -0X7078);
    // 0x80805B2C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80805B30: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80805B34: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80805B38: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80805B3C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805B40: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805B44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805B48: jal         0x80082630
    // 0x80805B4C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x80805B4C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_18:
    // 0x80805B50: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80805B54: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x80805B58: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80805B5C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80805B60: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80805B64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805B68: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805B6C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805B70: jal         0x80082630
    // 0x80805B74: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80805B74: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_19:
    // 0x80805B78: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80805B7C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80805B80: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80805B84: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80805B88: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80805B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805B90: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805B94: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805B98: jal         0x80082630
    // 0x80805B9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_20;
    // 0x80805B9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_20:
    // 0x80805BA0: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80805BA4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80805BA8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80805BAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805BB0: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x80805BB4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805BB8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805BBC: jal         0x80082630
    // 0x80805BC0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_21;
    // 0x80805BC0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_21:
    // 0x80805BC4: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80805BC8: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80805BCC: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80805BD0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80805BD4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80805BD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805BDC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805BE0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805BE4: jal         0x80082630
    // 0x80805BE8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x80805BE8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_22:
    // 0x80805BEC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80805BF0: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x80805BF4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80805BF8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80805BFC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80805C00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805C04: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805C08: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805C0C: jal         0x80082630
    // 0x80805C10: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x80805C10: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_23:
    // 0x80805C14: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80805C18: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80805C1C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80805C20: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80805C24: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80805C28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805C2C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805C30: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805C34: jal         0x80082630
    // 0x80805C38: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_24;
    // 0x80805C38: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_24:
    // 0x80805C3C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80805C40: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x80805C44: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80805C48: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80805C4C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80805C50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805C54: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805C58: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805C5C: jal         0x80082630
    // 0x80805C60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_25;
    // 0x80805C60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_25:
    // 0x80805C64: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80805C68: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80805C6C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80805C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805C74: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80805C78: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805C7C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805C80: jal         0x80082630
    // 0x80805C84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x80805C84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_26:
    // 0x80805C88: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80805C8C: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x80805C90: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80805C94: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80805C98: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80805C9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805CA0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805CA4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805CA8: jal         0x80082630
    // 0x80805CAC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_27;
    // 0x80805CAC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_27:
    // 0x80805CB0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80805CB4: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80805CB8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80805CBC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80805CC0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80805CC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805CC8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805CCC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805CD0: jal         0x80082630
    // 0x80805CD4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_28;
    // 0x80805CD4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_28:
    // 0x80805CD8: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80805CDC: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80805CE0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80805CE4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80805CE8: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80805CEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805CF0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805CF4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805CF8: jal         0x80082630
    // 0x80805CFC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x80805CFC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_29:
    // 0x80805D00: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80805D04: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80805D08: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80805D0C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80805D10: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80805D14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805D18: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805D1C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805D20: jal         0x80082630
    // 0x80805D24: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_30;
    // 0x80805D24: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_30:
    // 0x80805D28: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80805D2C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80805D30: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80805D34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805D38: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x80805D3C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805D40: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805D44: jal         0x80082630
    // 0x80805D48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_31;
    // 0x80805D48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_31:
    // 0x80805D4C: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80805D50: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80805D54: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80805D58: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80805D5C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80805D60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805D64: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805D68: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805D6C: jal         0x80082630
    // 0x80805D70: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_32;
    // 0x80805D70: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_32:
    // 0x80805D74: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80805D78: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80805D7C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80805D80: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80805D84: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80805D88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805D8C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805D90: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805D94: jal         0x80082630
    // 0x80805D98: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_33;
    // 0x80805D98: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_33:
    // 0x80805D9C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80805DA0: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80805DA4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80805DA8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80805DAC: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80805DB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805DB4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805DB8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805DBC: jal         0x80082630
    // 0x80805DC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_34;
    // 0x80805DC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_34:
    // 0x80805DC4: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80805DC8: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    // 0x80805DCC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80805DD0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80805DD4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80805DD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805DDC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805DE0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805DE4: jal         0x80082630
    // 0x80805DE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_35;
    // 0x80805DE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_35:
    // 0x80805DEC: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80805DF0: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x80805DF4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80805DF8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80805DFC: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x80805E00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805E04: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80805E08: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80805E0C: jal         0x80082630
    // 0x80805E10: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_36;
    // 0x80805E10: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_36:
    // 0x80805E14: b           L_808064C4
    // 0x80805E18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80805E18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805E1C:
    // 0x80805E1C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80805E20: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80805E24: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80805E28: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805E2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805E30: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805E34: jal         0x80085998
    // 0x80805E38: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_37;
    // 0x80805E38: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_37:
    // 0x80805E3C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80805E40: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80805E44: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80805E48: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805E4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805E50: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805E54: jal         0x80085998
    // 0x80805E58: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_38;
    // 0x80805E58: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_38:
    // 0x80805E5C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80805E60: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80805E64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80805E68: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805E6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805E70: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805E74: jal         0x80085998
    // 0x80805E78: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_39;
    // 0x80805E78: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_39:
    // 0x80805E7C: b           L_808064C4
    // 0x80805E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80805E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805E84:
    // 0x80805E84: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80805E88: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80805E8C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80805E90: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805E94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805E98: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805E9C: jal         0x80085998
    // 0x80805EA0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_40;
    // 0x80805EA0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_40:
    // 0x80805EA4: b           L_808064C4
    // 0x80805EA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80805EA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805EAC:
    // 0x80805EAC: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80805EB0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80805EB4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80805EB8: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805EBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805EC0: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805EC4: jal         0x80085998
    // 0x80805EC8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_41;
    // 0x80805EC8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_41:
    // 0x80805ECC: b           L_808064C4
    // 0x80805ED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80805ED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805ED4:
    // 0x80805ED4: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80805ED8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80805EDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80805EE0: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805EE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805EE8: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805EEC: jal         0x80085998
    // 0x80805EF0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_42;
    // 0x80805EF0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_42:
    // 0x80805EF4: b           L_808064C4
    // 0x80805EF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80805EF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805EFC:
    // 0x80805EFC: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80805F00: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80805F04: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80805F08: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80805F0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805F10: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805F14: jal         0x80085998
    // 0x80805F18: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_43;
    // 0x80805F18: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_43:
    // 0x80805F1C: b           L_808064C4
    // 0x80805F20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80805F20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805F24:
    // 0x80805F24: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80805F28: addiu       $s0, $s0, -0x7098
    ctx->r16 = ADD32(ctx->r16, -0X7098);
    // 0x80805F2C: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x80805F30: addiu       $t9, $zero, 0x200
    ctx->r25 = ADD32(0, 0X200);
    // 0x80805F34: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80805F38: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80805F3C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80805F40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805F44: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80805F48: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80805F4C: jal         0x80082638
    // 0x80805F50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_4(rdram, ctx);
        goto after_44;
    // 0x80805F50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_44:
    // 0x80805F54: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x80805F58: addiu       $t1, $zero, 0x200
    ctx->r9 = ADD32(0, 0X200);
    // 0x80805F5C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80805F60: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80805F64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805F68: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80805F6C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80805F70: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80805F74: jal         0x80082638
    // 0x80805F78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_4(rdram, ctx);
        goto after_45;
    // 0x80805F78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_45:
    // 0x80805F7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805F80: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80805F84: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805F88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80805F8C: jal         0x80085998
    // 0x80805F90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_46;
    // 0x80805F90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_46:
    // 0x80805F94: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80805F98: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80805F9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805FA0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80805FA4: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805FA8: jal         0x80085998
    // 0x80805FAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_47;
    // 0x80805FAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_47:
    // 0x80805FB0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80805FB4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80805FB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805FBC: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    // 0x80805FC0: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80805FC4: jal         0x800859A0
    // 0x80805FC8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _chanim_entrypoint_5(rdram, ctx);
        goto after_48;
    // 0x80805FC8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_48:
    // 0x80805FCC: b           L_808064C4
    // 0x80805FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80805FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805FD4:
    // 0x80805FD4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80805FD8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7740) << 16);
    // 0x80805FDC: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2958, 0X7764) << 16);
    // 0x80805FE0: addiu       $s2, $s2, 0x7764
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2958, 0X7764));
    // 0x80805FE4: addiu       $v0, $v0, 0x7740
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7740));
    // 0x80805FE8: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80805FEC: addiu       $t4, $zero, 0x13
    ctx->r12 = ADD32(0, 0X13);
L_80805FF0:
    // 0x80805FF0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80805FF4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80805FF8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80805FFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806000: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80806004: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80806008: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x8080600C: jal         0x80082630
    // 0x80806010: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_49;
    // 0x80806010: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_49:
    // 0x80806014: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80806018: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080601C: bnel        $v0, $s2, L_80805FF0
    if (ctx->r2 != ctx->r18) {
        // 0x80806020: addiu       $t4, $zero, 0x13
        ctx->r12 = ADD32(0, 0X13);
            goto L_80805FF0;
    }
    goto skip_5;
    // 0x80806020: addiu       $t4, $zero, 0x13
    ctx->r12 = ADD32(0, 0X13);
    skip_5:
    // 0x80806024: b           L_808064C4
    // 0x80806028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80806028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080602C:
    // 0x8080602C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80806030: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7764) << 16);
    // 0x80806034: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2958, 0X7768) << 16);
    // 0x80806038: addiu       $s2, $s2, 0x7768
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2958, 0X7768));
    // 0x8080603C: addiu       $v0, $v0, 0x7764
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7764));
    // 0x80806040: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80806044: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
L_80806048:
    // 0x80806048: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8080604C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80806050: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80806054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806058: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080605C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80806060: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80806064: jal         0x80082630
    // 0x80806068: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_50;
    // 0x80806068: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_50:
    // 0x8080606C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80806070: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80806074: bnel        $v0, $s2, L_80806048
    if (ctx->r2 != ctx->r18) {
        // 0x80806078: addiu       $t6, $zero, 0x14
        ctx->r14 = ADD32(0, 0X14);
            goto L_80806048;
    }
    goto skip_6;
    // 0x80806078: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    skip_6:
    // 0x8080607C: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80806080: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7768) << 16);
    // 0x80806084: addiu       $v0, $v0, 0x7768
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7768));
    // 0x80806088: addiu       $s2, $s2, -0x7078
    ctx->r18 = ADD32(ctx->r18, -0X7078);
    // 0x8080608C: lui         $s0, 0x3
    ctx->r16 = S32(0X3 << 16);
    // 0x80806090: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
L_80806094:
    // 0x80806094: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80806098: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080609C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808060A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808060A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808060A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808060AC: jal         0x80082630
    // 0x808060B0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_51;
    // 0x808060B0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_51:
    // 0x808060B4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x808060B8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2958, 0X776C) << 16);
    // 0x808060BC: addiu       $t9, $t9, 0x776C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2958, 0X776C));
    // 0x808060C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808060C4: bnel        $v0, $t9, L_80806094
    if (ctx->r2 != ctx->r25) {
        // 0x808060C8: addiu       $t8, $zero, -0x100
        ctx->r24 = ADD32(0, -0X100);
            goto L_80806094;
    }
    goto skip_7;
    // 0x808060C8: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    skip_7:
    // 0x808060CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X776C) << 16);
    // 0x808060D0: addiu       $v0, $v0, 0x776C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X776C));
    // 0x808060D4: addiu       $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
L_808060D8:
    // 0x808060D8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808060DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808060E0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808060E4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808060E8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808060EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808060F0: jal         0x80082630
    // 0x808060F4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_52;
    // 0x808060F4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_52:
    // 0x808060F8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x808060FC: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2958, 0X7770) << 16);
    // 0x80806100: addiu       $t1, $t1, 0x7770
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2958, 0X7770));
    // 0x80806104: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80806108: bnel        $v0, $t1, L_808060D8
    if (ctx->r2 != ctx->r9) {
        // 0x8080610C: addiu       $t0, $zero, 0x4C
        ctx->r8 = ADD32(0, 0X4C);
            goto L_808060D8;
    }
    goto skip_8;
    // 0x8080610C: addiu       $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
    skip_8:
    // 0x80806110: b           L_808064C4
    // 0x80806114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80806114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806118:
    // 0x80806118: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x8080611C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80806120: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806124: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80806128: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8080612C: jal         0x80085998
    // 0x80806130: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_53;
    // 0x80806130: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_53:
    // 0x80806134: b           L_808064C4
    // 0x80806138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80806138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080613C:
    // 0x8080613C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80806140: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80806144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806148: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x8080614C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80806150: jal         0x80085998
    // 0x80806154: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_54;
    // 0x80806154: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_54:
    // 0x80806158: b           L_808064C4
    // 0x8080615C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x8080615C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806160:
    // 0x80806160: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80806164: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80806168: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080616C: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80806170: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80806174: jal         0x80085998
    // 0x80806178: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_55;
    // 0x80806178: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_55:
    // 0x8080617C: b           L_808064C4
    // 0x80806180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80806180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806184:
    // 0x80806184: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80806188: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x8080618C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806190: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80806194: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80806198: jal         0x80085998
    // 0x8080619C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_56;
    // 0x8080619C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_56:
    // 0x808061A0: b           L_808064C4
    // 0x808061A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x808061A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808061A8:
    // 0x808061A8: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x808061AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808061B0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808061B4: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x808061B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808061BC: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x808061C0: jal         0x80085998
    // 0x808061C4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_57;
    // 0x808061C4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_57:
    // 0x808061C8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808061CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7770) << 16);
    // 0x808061D0: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2958, 0X777C) << 16);
    // 0x808061D4: addiu       $s2, $s2, 0x777C
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2958, 0X777C));
    // 0x808061D8: addiu       $v0, $v0, 0x7770
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7770));
    // 0x808061DC: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x808061E0: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
L_808061E4:
    // 0x808061E4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x808061E8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808061EC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808061F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808061F4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808061F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808061FC: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80806200: jal         0x80082630
    // 0x80806204: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_58;
    // 0x80806204: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_58:
    // 0x80806208: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8080620C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80806210: bnel        $v0, $s2, L_808061E4
    if (ctx->r2 != ctx->r18) {
        // 0x80806214: addiu       $t3, $zero, 0x18
        ctx->r11 = ADD32(0, 0X18);
            goto L_808061E4;
    }
    goto skip_9;
    // 0x80806214: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    skip_9:
    // 0x80806218: b           L_808064C4
    // 0x8080621C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x8080621C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806220:
    // 0x80806220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806224: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80806228: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x8080622C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80806230: jal         0x80085998
    // 0x80806234: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_59;
    // 0x80806234: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_59:
    // 0x80806238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080623C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80806240: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80806244: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80806248: jal         0x80085998
    // 0x8080624C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_60;
    // 0x8080624C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_60:
    // 0x80806250: b           L_808064C4
    // 0x80806254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80806254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806258:
    // 0x80806258: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8080625C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80806260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806264: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80806268: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x8080626C: jal         0x80085998
    // 0x80806270: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_61;
    // 0x80806270: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_61:
    // 0x80806274: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806278: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080627C: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80806280: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80806284: jal         0x80085998
    // 0x80806288: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_62;
    // 0x80806288: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_62:
    // 0x8080628C: b           L_808064C4
    // 0x80806290: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x80806290: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806294:
    // 0x80806294: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806298: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080629C: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x808062A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808062A4: jal         0x80085998
    // 0x808062A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_63;
    // 0x808062A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_63:
    // 0x808062AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808062B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808062B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808062B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808062BC: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x808062C0: jal         0x80085998
    // 0x808062C4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_64;
    // 0x808062C4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_64:
    // 0x808062C8: b           L_808064C4
    // 0x808062CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x808062CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808062D0:
    // 0x808062D0: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808062D4: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x808062D8: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808062DC: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x808062E0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x808062E4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808062E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808062EC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808062F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808062F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808062F8: jal         0x80082630
    // 0x808062FC: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_65;
    // 0x808062FC: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    after_65:
    // 0x80806300: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80806304: addiu       $t9, $zero, 0x1B
    ctx->r25 = ADD32(0, 0X1B);
    // 0x80806308: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8080630C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80806310: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80806314: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80806318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080631C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80806320: jal         0x80082630
    // 0x80806324: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_66;
    // 0x80806324: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    after_66:
    // 0x80806328: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8080632C: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x80806330: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80806334: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80806338: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080633C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80806340: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806344: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80806348: jal         0x80082630
    // 0x8080634C: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_67;
    // 0x8080634C: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    after_67:
    // 0x80806350: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80806354: addiu       $t3, $zero, 0x1D
    ctx->r11 = ADD32(0, 0X1D);
    // 0x80806358: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8080635C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80806360: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80806364: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80806368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080636C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80806370: jal         0x80082630
    // 0x80806374: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_68;
    // 0x80806374: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    after_68:
    // 0x80806378: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x8080637C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80806380: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80806384: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80806388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080638C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80806390: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80806394: jal         0x80082630
    // 0x80806398: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_69;
    // 0x80806398: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    after_69:
    // 0x8080639C: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x808063A0: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x808063A4: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x808063A8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808063AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808063B0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808063B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808063B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808063BC: jal         0x80082630
    // 0x808063C0: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_70;
    // 0x808063C0: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    after_70:
    // 0x808063C4: addiu       $t9, $zero, 0x1B
    ctx->r25 = ADD32(0, 0X1B);
    // 0x808063C8: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x808063CC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808063D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808063D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808063D8: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x808063DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808063E0: jal         0x80082630
    // 0x808063E4: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_71;
    // 0x808063E4: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    after_71:
    // 0x808063E8: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x808063EC: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x808063F0: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x808063F4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x808063F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808063FC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80806400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806404: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80806408: jal         0x80082630
    // 0x8080640C: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_72;
    // 0x8080640C: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    after_72:
    // 0x80806410: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80806414: addiu       $t3, $zero, 0x1D
    ctx->r11 = ADD32(0, 0X1D);
    // 0x80806418: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x8080641C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80806420: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80806424: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80806428: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080642C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80806430: jal         0x80082630
    // 0x80806434: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_73;
    // 0x80806434: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    after_73:
    // 0x80806438: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x8080643C: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x80806440: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80806444: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80806448: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080644C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80806450: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806454: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80806458: jal         0x80082630
    // 0x8080645C: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_74;
    // 0x8080645C: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    after_74:
    // 0x80806460: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X777C) << 16);
    // 0x80806464: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80806468: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2958, 0X7780) << 16);
    // 0x8080646C: addiu       $s2, $s2, 0x7780
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2958, 0X7780));
    // 0x80806470: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80806474: addiu       $v0, $v0, 0x777C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X777C));
    // 0x80806478: addiu       $t7, $zero, 0xB5
    ctx->r15 = ADD32(0, 0XB5);
L_8080647C:
    // 0x8080647C: addiu       $t8, $zero, -0x2
    ctx->r24 = ADD32(0, -0X2);
    // 0x80806480: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80806484: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80806488: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080648C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80806490: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80806494: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80806498: jal         0x80082630
    // 0x8080649C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_75;
    // 0x8080649C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_75:
    // 0x808064A0: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x808064A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808064A8: bnel        $v0, $s2, L_8080647C
    if (ctx->r2 != ctx->r18) {
        // 0x808064AC: addiu       $t7, $zero, 0xB5
        ctx->r15 = ADD32(0, 0XB5);
            goto L_8080647C;
    }
    goto skip_10;
    // 0x808064AC: addiu       $t7, $zero, 0xB5
    ctx->r15 = ADD32(0, 0XB5);
    skip_10:
    // 0x808064B0: b           L_808064C4
    // 0x808064B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064C4;
    // 0x808064B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808064B8:
    // 0x808064B8: b           L_808064C4
    // 0x808064BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808064C4;
    // 0x808064BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808064C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808064C4:
    // 0x808064C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808064C8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808064CC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808064D0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808064D4: jr          $ra
    // 0x808064D8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808064D8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8080001C_gspropprop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080001C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800024: jal         0x80088C90
    // 0x80800028: nop

    _gsproplookup_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800028: nop

    after_0:
    // 0x8080002C: jal         0x800BFC94
    // 0x80800030: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BFC94(rdram, ctx);
        goto after_1;
    // 0x80800030: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800034: jal         0x800B0CFC
    // 0x80800038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B0CFC(rdram, ctx);
        goto after_2;
    // 0x80800038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800040: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800048: jr          $ra
    // 0x8080004C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    return;
    // 0x8080004C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
;}
RECOMP_FUNC void func_808000DC_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E4: lhu         $t6, 0x140($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X140);
    // 0x808000E8: beq         $t6, $zero, L_808000F4
    if (ctx->r14 == 0) {
        // 0x808000EC: nop
    
            goto L_808000F4;
    }
    // 0x808000EC: nop

    // 0x808000F0: sh          $zero, 0x140($a0)
    MEM_H(0X140, ctx->r4) = 0;
L_808000F4:
    // 0x808000F4: jal         0x808000C4
    // 0x808000F8: nop

    func_808000C4_gczoombox(rdram, ctx);
        goto after_0;
    // 0x808000F8: nop

    after_0:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_80800350_chwaspstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800350: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800354: addiu       $t6, $a1, -0xB
    ctx->r14 = ADD32(ctx->r5, -0XB);
    // 0x80800358: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080035C: sltiu       $at, $t6, 0x36
    ctx->r1 = ctx->r14 < 0X36 ? 1 : 0;
    // 0x80800360: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800364: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800368: beq         $at, $zero, L_808004F0
    if (ctx->r1 == 0) {
        // 0x8080036C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808004F0;
    }
    // 0x8080036C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800370: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800374: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2364, 0X660) << 16);
    // 0x80800378: addu        $at, $at, $t6
    gpr jr_addend_80800380 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080037C: lw          $t6, 0x660($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2364, 0X660));
    // 0x80800380: jr          $t6
    // 0x80800384: nop

    switch (jr_addend_80800380 >> 2) {
        case 0: goto L_80800448; break;
        case 1: goto L_808004F0; break;
        case 2: goto L_808004F0; break;
        case 3: goto L_808004F0; break;
        case 4: goto L_808004F0; break;
        case 5: goto L_808004F0; break;
        case 6: goto L_808004F0; break;
        case 7: goto L_808004F0; break;
        case 8: goto L_808004F0; break;
        case 9: goto L_808004F0; break;
        case 10: goto L_808004F0; break;
        case 11: goto L_808004F0; break;
        case 12: goto L_808004F0; break;
        case 13: goto L_808004F0; break;
        case 14: goto L_808004F0; break;
        case 15: goto L_808004F0; break;
        case 16: goto L_808004F0; break;
        case 17: goto L_808004F0; break;
        case 18: goto L_808004F0; break;
        case 19: goto L_808004F0; break;
        case 20: goto L_80800474; break;
        case 21: goto L_808004F0; break;
        case 22: goto L_808004F0; break;
        case 23: goto L_808004F0; break;
        case 24: goto L_808004F0; break;
        case 25: goto L_808004F0; break;
        case 26: goto L_808004F0; break;
        case 27: goto L_808004F0; break;
        case 28: goto L_808004F0; break;
        case 29: goto L_808004F0; break;
        case 30: goto L_808004F0; break;
        case 31: goto L_808004F0; break;
        case 32: goto L_808004F0; break;
        case 33: goto L_808004F0; break;
        case 34: goto L_808004F0; break;
        case 35: goto L_808004F0; break;
        case 36: goto L_808004F0; break;
        case 37: goto L_808004B8; break;
        case 38: goto L_808004F0; break;
        case 39: goto L_808004F0; break;
        case 40: goto L_808004F0; break;
        case 41: goto L_808004F0; break;
        case 42: goto L_808004F0; break;
        case 43: goto L_808004F0; break;
        case 44: goto L_808004F0; break;
        case 45: goto L_808004F0; break;
        case 46: goto L_808004F0; break;
        case 47: goto L_808004F0; break;
        case 48: goto L_808004F0; break;
        case 49: goto L_808004F0; break;
        case 50: goto L_808004F0; break;
        case 51: goto L_808004F0; break;
        case 52: goto L_80800388; break;
        case 53: goto L_808003C4; break;
        default: switch_error(__func__, 0x80800380, 0x80800660);
    }
    // 0x80800384: nop

L_80800388:
    // 0x80800388: jal         0x800DA298
    // 0x8080038C: addiu       $a0, $zero, 0x6DA
    ctx->r4 = ADD32(0, 0X6DA);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080038C: addiu       $a0, $zero, 0x6DA
    ctx->r4 = ADD32(0, 0X6DA);
    after_0:
    // 0x80800390: bne         $v0, $zero, L_808003BC
    if (ctx->r2 != 0) {
        // 0x80800394: nop
    
            goto L_808003BC;
    }
    // 0x80800394: nop

    // 0x80800398: jal         0x800DA544
    // 0x8080039C: addiu       $a0, $zero, 0x6DA
    ctx->r4 = ADD32(0, 0X6DA);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x8080039C: addiu       $a0, $zero, 0x6DA
    ctx->r4 = ADD32(0, 0X6DA);
    after_1:
    // 0x808003A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808003A4: addiu       $t7, $zero, 0x6D
    ctx->r15 = ADD32(0, 0X6D);
    // 0x808003A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808003AC: addiu       $a1, $zero, 0x1417
    ctx->r5 = ADD32(0, 0X1417);
    // 0x808003B0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808003B4: jal         0x8008A208
    // 0x808003B8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x808003B8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_2:
L_808003BC:
    // 0x808003BC: b           L_808004F4
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004F4;
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C4:
    // 0x808003C4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808003C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x808003D4: bne         $t8, $at, L_808003F4
    if (ctx->r24 != ctx->r1) {
        // 0x808003D8: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_808003F4;
    }
    // 0x808003D8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x808003DC: jal         0x80800134
    // 0x808003E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800134_chwaspstatue(rdram, ctx);
        goto after_3;
    // 0x808003E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808003E4: jal         0x800FC660
    // 0x808003E8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x808003E8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_4:
    // 0x808003EC: b           L_808004F4
    // 0x808003F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004F4;
    // 0x808003F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003F4:
    // 0x808003F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808003F8: bne         $v0, $at, L_80800440
    if (ctx->r2 != ctx->r1) {
        // 0x808003FC: nop
    
            goto L_80800440;
    }
    // 0x808003FC: nop

    // 0x80800400: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x80800404: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80800410: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x80800414: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x80800418: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8080041C: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
    // 0x80800420: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80800424: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800428: bne         $t7, $zero, L_80800438
    if (ctx->r15 != 0) {
        // 0x8080042C: nop
    
            goto L_80800438;
    }
    // 0x8080042C: nop

    // 0x80800430: jal         0x80800134
    // 0x80800434: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800134_chwaspstatue(rdram, ctx);
        goto after_5;
    // 0x80800434: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
L_80800438:
    // 0x80800438: jal         0x800FC660
    // 0x8080043C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_6;
    // 0x8080043C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_6:
L_80800440:
    // 0x80800440: b           L_808004F4
    // 0x80800444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004F4;
    // 0x80800444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800448:
    // 0x80800448: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8080044C: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: bne         $t8, $at, L_8080046C
    if (ctx->r24 != ctx->r1) {
        // 0x80800458: nop
    
            goto L_8080046C;
    }
    // 0x80800458: nop

    // 0x8080045C: jal         0x80800134
    // 0x80800460: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800134_chwaspstatue(rdram, ctx);
        goto after_7;
    // 0x80800460: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800464: jal         0x800DA544
    // 0x80800468: addiu       $a0, $zero, 0x6D8
    ctx->r4 = ADD32(0, 0X6D8);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x80800468: addiu       $a0, $zero, 0x6D8
    ctx->r4 = ADD32(0, 0X6D8);
    after_8:
L_8080046C:
    // 0x8080046C: b           L_808004F4
    // 0x80800470: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808004F4;
    // 0x80800470: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800474:
    // 0x80800474: jal         0x801015D0
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_9;
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080047C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800480: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800484: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800488: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080048C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800490: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800494: jal         0x800F10B4
    // 0x80800498: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x80800498: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x8080049C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808004A0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x808004A4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x808004A8: jal         0x800DF6BC
    // 0x808004AC: nop

    func_800DF6BC(rdram, ctx);
        goto after_11;
    // 0x808004AC: nop

    after_11:
    // 0x808004B0: b           L_808004F4
    // 0x808004B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004F4;
    // 0x808004B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004B8:
    // 0x808004B8: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x808004BC: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x808004C0: addiu       $at, $zero, 0x1416
    ctx->r1 = ADD32(0, 0X1416);
    // 0x808004C4: bne         $t0, $at, L_808004E8
    if (ctx->r8 != ctx->r1) {
        // 0x808004C8: nop
    
            goto L_808004E8;
    }
    // 0x808004C8: nop

    // 0x808004CC: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x808004D0: beq         $t1, $zero, L_808004E0
    if (ctx->r9 == 0) {
        // 0x808004D4: nop
    
            goto L_808004E0;
    }
    // 0x808004D4: nop

    // 0x808004D8: b           L_808004F4
    // 0x808004DC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_808004F4;
    // 0x808004DC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_808004E0:
    // 0x808004E0: b           L_808004F4
    // 0x808004E4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_808004F4;
    // 0x808004E4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_808004E8:
    // 0x808004E8: b           L_808004F4
    // 0x808004EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004F4;
    // 0x808004EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004F0:
    // 0x808004F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004F4:
    // 0x808004F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800500: jr          $ra
    // 0x80800504: nop

    return;
    // 0x80800504: nop

;}
RECOMP_FUNC void _sumole_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A78: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A78);
    return;
    // 0x80089A7C: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_800A9A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9A1C: jal         0x8001211C
    // 0x800A9A20: nop

    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x800A9A20: nop

    after_0:
    // 0x800A9A24: jal         0x80087AC0
    // 0x800A9A28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _gcgoto_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x800A9A28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800A9A2C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A9A30: addiu       $v1, $v1, 0x7760
    ctx->r3 = ADD32(ctx->r3, 0X7760);
    // 0x800A9A34: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x800A9A38: beql        $t6, $zero, L_800A9A60
    if (ctx->r14 == 0) {
        // 0x800A9A3C: lbu         $v0, 0x0($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X0);
            goto L_800A9A60;
    }
    goto skip_0;
    // 0x800A9A3C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    skip_0:
    // 0x800A9A40: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    // 0x800A9A44: bnel        $t7, $zero, L_800A9A60
    if (ctx->r15 != 0) {
        // 0x800A9A48: lbu         $v0, 0x0($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X0);
            goto L_800A9A60;
    }
    goto skip_1;
    // 0x800A9A48: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    skip_1:
    // 0x800A9A4C: jal         0x800A98E0
    // 0x800A9A50: nop

    func_800A98E0(rdram, ctx);
        goto after_2;
    // 0x800A9A50: nop

    after_2:
    // 0x800A9A54: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A9A58: addiu       $v1, $v1, 0x7760
    ctx->r3 = ADD32(ctx->r3, 0X7760);
    // 0x800A9A5C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
L_800A9A60:
    // 0x800A9A60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9A64: beq         $v0, $at, L_800A9A7C
    if (ctx->r2 == ctx->r1) {
        // 0x800A9A68: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A9A7C;
    }
    // 0x800A9A68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9A6C: beq         $v0, $at, L_800A9A8C
    if (ctx->r2 == ctx->r1) {
        // 0x800A9A70: nop
    
            goto L_800A9A8C;
    }
    // 0x800A9A70: nop

    // 0x800A9A74: b           L_800A9A98
    // 0x800A9A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A9A98;
    // 0x800A9A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9A7C:
    // 0x800A9A7C: jal         0x800E8144
    // 0x800A9A80: nop

    func_800E8144(rdram, ctx);
        goto after_3;
    // 0x800A9A80: nop

    after_3:
    // 0x800A9A84: b           L_800A9A98
    // 0x800A9A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A9A98;
    // 0x800A9A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9A8C:
    // 0x800A9A8C: jal         0x80088C60
    // 0x800A9A90: nop

    _gsattract_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x800A9A90: nop

    after_4:
    // 0x800A9A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9A98:
    // 0x800A9A98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9A9C: jr          $ra
    // 0x800A9AA0: nop

    return;
    // 0x800A9AA0: nop

;}
