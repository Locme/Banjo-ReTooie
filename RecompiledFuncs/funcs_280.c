#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _fxairbub_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889D0: syscall     716
    recomp_syscall_handler(rdram, ctx, 0x800889D0);
    return;
    // 0x800889D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808013B8_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013C0: jal         0x800D8FF8
    // 0x808013C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808013C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808013CC: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // 0x808013D0: ori         $a1, $a1, 0x8
    ctx->r5 = ctx->r5 | 0X8;
    // 0x808013D4: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    // 0x808013D8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808013DC: jal         0x8010B990
    // 0x808013E0: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    func_8010B990(rdram, ctx);
        goto after_1;
    // 0x808013E0: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    after_1:
    // 0x808013E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808013E8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808013EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808013F0: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808013F4: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x808013F8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x808013FC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80801400: nop

    // 0x80801404: bc1fl       L_80801418
    if (!c1cs) {
        // 0x80801408: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801418;
    }
    goto skip_0;
    // 0x80801408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080140C: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80801410: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x80801414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801418:
    // 0x80801418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080141C: jr          $ra
    // 0x80801420: nop

    return;
    // 0x80801420: nop

;}
RECOMP_FUNC void func_80800684_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800684: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800688: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080068C: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800690: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800698: bne         $a1, $at, L_8080070C
    if (ctx->r5 != ctx->r1) {
        // 0x8080069C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8080070C;
    }
    // 0x8080069C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808006A0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808006A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006A8: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
    // 0x808006AC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808006B0: bne         $t7, $at, L_80800714
    if (ctx->r15 != ctx->r1) {
        // 0x808006B4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800714;
    }
    // 0x808006B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808006B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006BC: jal         0x8010D254
    // 0x808006C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x808006C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808006C4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808006C8: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x808006CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006D0: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x808006D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808006D8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808006DC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808006E0: nop

    // 0x808006E4: bc1fl       L_80800718
    if (!c1cs) {
        // 0x808006E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800718;
    }
    goto skip_0;
    // 0x808006E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808006EC: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x808006F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808006F4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x808006F8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x808006FC: jal         0x80090494
    // 0x80800700: swc1        $f16, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f16.u32l;
    func_80090494(rdram, ctx);
        goto after_1;
    // 0x80800700: swc1        $f16, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f16.u32l;
    after_1:
    // 0x80800704: b           L_80800718
    // 0x80800708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800718;
    // 0x80800708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080070C:
    // 0x8080070C: b           L_80800718
    // 0x80800710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800718;
    // 0x80800710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800714:
    // 0x80800714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800718:
    // 0x80800718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080071C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800720: jr          $ra
    // 0x80800724: nop

    return;
    // 0x80800724: nop

;}
RECOMP_FUNC void bsbshock_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808001B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001C4: jal         0x8008CABC
    // 0x808001C8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001C8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x808001CC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808001D0: jal         0x8008E078
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_1;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001D8: beq         $v0, $zero, L_80800214
    if (ctx->r2 == 0) {
        // 0x808001DC: nop
    
            goto L_80800214;
    }
    // 0x808001DC: nop

    // 0x808001E0: jal         0x8001211C
    // 0x808001E4: nop

    func_8001211C(rdram, ctx);
        goto after_2;
    // 0x808001E4: nop

    after_2:
    // 0x808001E8: bgez        $v0, L_808001FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x808001EC: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_808001FC;
    }
    // 0x808001EC: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x808001F0: beq         $t6, $zero, L_808001FC
    if (ctx->r14 == 0) {
        // 0x808001F4: nop
    
            goto L_808001FC;
    }
    // 0x808001F4: nop

    // 0x808001F8: addiu       $t6, $t6, -0x2
    ctx->r14 = ADD32(ctx->r14, -0X2);
L_808001FC:
    // 0x808001FC: beq         $t6, $zero, L_8080021C
    if (ctx->r14 == 0) {
        // 0x80800200: nop
    
            goto L_8080021C;
    }
    // 0x80800200: nop

    // 0x80800204: jal         0x8009FC80
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FC80(rdram, ctx);
        goto after_3;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080020C: b           L_8080021C
    // 0x80800210: nop

        goto L_8080021C;
    // 0x80800210: nop

L_80800214:
    // 0x80800214: jal         0x8009FC80
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FC80(rdram, ctx);
        goto after_4;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8080021C:
    // 0x8080021C: jal         0x800841D8
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: jal         0x8009BB24
    // 0x8080022C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_6;
    // 0x8080022C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: jal         0x80091A30
    // 0x80800238: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_7;
    // 0x80800238: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x8080023C: beq         $v0, $zero, L_80800264
    if (ctx->r2 == 0) {
        // 0x80800240: lwc1        $f6, 0x28($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800264;
    }
    // 0x80800240: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800244: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800248: nop

    // 0x8080024C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800250: nop

    // 0x80800254: bc1fl       L_80800268
    if (!c1cs) {
        // 0x80800258: lw          $v0, 0x160($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X160);
            goto L_80800268;
    }
    goto skip_0;
    // 0x80800258: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    skip_0:
    // 0x8080025C: jal         0x8009BC6C
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_8;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800264:
    // 0x80800264: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
L_80800268:
    // 0x80800268: beq         $v0, $zero, L_80800280
    if (ctx->r2 == 0) {
        // 0x8080026C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800280;
    }
    // 0x8080026C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800270: beq         $v0, $at, L_808002DC
    if (ctx->r2 == ctx->r1) {
        // 0x80800274: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808002DC;
    }
    // 0x80800274: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800278: b           L_80800334
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800334;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800280:
    // 0x80800280: jal         0x8008E260
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_9;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800288: beq         $v0, $zero, L_80800298
    if (ctx->r2 == 0) {
        // 0x8080028C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800298;
    }
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: addiu       $t7, $zero, 0x3D
    ctx->r15 = ADD32(0, 0X3D);
    // 0x80800294: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80800298:
    // 0x80800298: jal         0x8008DF8C
    // 0x8080029C: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_10;
    // 0x8080029C: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_10:
    // 0x808002A0: beq         $v0, $zero, L_80800330
    if (ctx->r2 == 0) {
        // 0x808002A4: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800330;
    }
    // 0x808002A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808002A8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808002AC: jal         0x8008B1D4
    // 0x808002B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_11;
    // 0x808002B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_11:
    // 0x808002B4: lui         $a1, 0x4033
    ctx->r5 = S32(0X4033 << 16);
    // 0x808002B8: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808002BC: jal         0x8008B1BC
    // 0x808002C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_12;
    // 0x808002C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x808002C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808002C8: jal         0x8008B134
    // 0x808002CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_13;
    // 0x808002CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808002D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808002D4: b           L_80800330
    // 0x808002D8: sw          $t8, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r24;
        goto L_80800330;
    // 0x808002D8: sw          $t8, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r24;
L_808002DC:
    // 0x808002DC: lui         $a1, 0x3DE1
    ctx->r5 = S32(0X3DE1 << 16);
    // 0x808002E0: jal         0x8008B348
    // 0x808002E4: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    anctrl_isAt(rdram, ctx);
        goto after_14;
    // 0x808002E4: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    after_14:
    // 0x808002E8: beql        $v0, $zero, L_808002FC
    if (ctx->r2 == 0) {
        // 0x808002EC: lui         $a1, 0x3ECE
        ctx->r5 = S32(0X3ECE << 16);
            goto L_808002FC;
    }
    goto skip_1;
    // 0x808002EC: lui         $a1, 0x3ECE
    ctx->r5 = S32(0X3ECE << 16);
    skip_1:
    // 0x808002F0: jal         0x800C3BDC
    // 0x808002F4: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    func_800C3BDC(rdram, ctx);
        goto after_15;
    // 0x808002F4: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    after_15:
    // 0x808002F8: lui         $a1, 0x3ECE
    ctx->r5 = S32(0X3ECE << 16);
L_808002FC:
    // 0x808002FC: ori         $a1, $a1, 0xA4A9
    ctx->r5 = ctx->r5 | 0XA4A9;
    // 0x80800300: jal         0x8008B348
    // 0x80800304: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isAt(rdram, ctx);
        goto after_16;
    // 0x80800304: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_16:
    // 0x80800308: beq         $v0, $zero, L_8080031C
    if (ctx->r2 == 0) {
        // 0x8080030C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8080031C;
    }
    // 0x8080030C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800310: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80800314: jal         0x8008B1BC
    // 0x80800318: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    anctrl_setDuration(rdram, ctx);
        goto after_17;
    // 0x80800318: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_17:
L_8080031C:
    // 0x8080031C: jal         0x8008B324
    // 0x80800320: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_18;
    // 0x80800320: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_18:
    // 0x80800324: beq         $v0, $zero, L_80800330
    if (ctx->r2 == 0) {
        // 0x80800328: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80800330;
    }
    // 0x80800328: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080032C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80800330:
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800334:
    // 0x80800334: jal         0x8008DF8C
    // 0x80800338: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_8008DF8C(rdram, ctx);
        goto after_19;
    // 0x80800338: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_19:
    // 0x8080033C: beq         $v0, $zero, L_8080039C
    if (ctx->r2 == 0) {
        // 0x80800340: nop
    
            goto L_8080039C;
    }
    // 0x80800340: nop

    // 0x80800344: jal         0x8008B2B4
    // 0x80800348: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_20;
    // 0x80800348: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_20:
    // 0x8080034C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(116, 0X860) << 16);
    // 0x80800350: lwc1        $f8, 0x860($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(116, 0X860));
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8080035C: nop

    // 0x80800360: bc1f        L_8080037C
    if (!c1cs) {
        // 0x80800364: nop
    
            goto L_8080037C;
    }
    // 0x80800364: nop

    // 0x80800368: jal         0x80091A30
    // 0x8080036C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_21;
    // 0x8080036C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_21:
    // 0x80800370: beq         $v0, $zero, L_8080037C
    if (ctx->r2 == 0) {
        // 0x80800374: nop
    
            goto L_8080037C;
    }
    // 0x80800374: nop

    // 0x80800378: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_8080037C:
    // 0x8080037C: jal         0x8008E078
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_22;
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800384: beq         $v0, $zero, L_808003C4
    if (ctx->r2 == 0) {
        // 0x80800388: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C4;
    }
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: jal         0x8009B9B0
    // 0x80800390: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_23;
    // 0x80800390: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_23:
    // 0x80800394: b           L_808003C8
    // 0x80800398: lui         $a1, 0x3EBA
    ctx->r5 = S32(0X3EBA << 16);
        goto L_808003C8;
    // 0x80800398: lui         $a1, 0x3EBA
    ctx->r5 = S32(0X3EBA << 16);
L_8080039C:
    // 0x8080039C: jal         0x80097DF4
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097DF4(rdram, ctx);
        goto after_24;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808003A4: beq         $v0, $zero, L_808003B0
    if (ctx->r2 == 0) {
        // 0x808003A8: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_808003B0;
    }
    // 0x808003A8: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x808003AC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_808003B0:
    // 0x808003B0: jal         0x80097A90
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_bust(rdram, ctx);
        goto after_25;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808003B8: beq         $v0, $zero, L_808003C4
    if (ctx->r2 == 0) {
        // 0x808003BC: addiu       $t1, $zero, 0xF
        ctx->r9 = ADD32(0, 0XF);
            goto L_808003C4;
    }
    // 0x808003BC: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x808003C0: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_808003C4:
    // 0x808003C4: lui         $a1, 0x3EBA
    ctx->r5 = S32(0X3EBA << 16);
L_808003C8:
    // 0x808003C8: ori         $a1, $a1, 0x36E3
    ctx->r5 = ctx->r5 | 0X36E3;
    // 0x808003CC: jal         0x8008B348
    // 0x808003D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isAt(rdram, ctx);
        goto after_26;
    // 0x808003D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_26:
    // 0x808003D4: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x808003D8: lui         $a1, 0x3EEE
        ctx->r5 = S32(0X3EEE << 16);
            goto L_808003F0;
    }
    // 0x808003D8: lui         $a1, 0x3EEE
    ctx->r5 = S32(0X3EEE << 16);
    // 0x808003DC: lw          $t2, 0x15C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X15C);
    // 0x808003E0: addiu       $t3, $zero, 0x22
    ctx->r11 = ADD32(0, 0X22);
    // 0x808003E4: beql        $t2, $zero, L_808003F4
    if (ctx->r10 == 0) {
        // 0x808003E8: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808003F4;
    }
    goto skip_2;
    // 0x808003E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x808003EC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_808003F0:
    // 0x808003F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_808003F4:
    // 0x808003F4: jal         0x8008B348
    // 0x808003F8: ori         $a1, $a1, 0x3BCD
    ctx->r5 = ctx->r5 | 0X3BCD;
    anctrl_isAt(rdram, ctx);
        goto after_27;
    // 0x808003F8: ori         $a1, $a1, 0x3BCD
    ctx->r5 = ctx->r5 | 0X3BCD;
    after_27:
    // 0x808003FC: beq         $v0, $zero, L_80800424
    if (ctx->r2 == 0) {
        // 0x80800400: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800424;
    }
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: jal         0x8009BA58
    // 0x80800408: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_28;
    // 0x80800408: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    after_28:
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: jal         0x80093300
    // 0x80800414: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093300(rdram, ctx);
        goto after_29;
    // 0x80800414: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_29:
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: jal         0x8009C1B4
    // 0x80800420: lui         $a1, 0x42AE
    ctx->r5 = S32(0X42AE << 16);
    func_8009C1B4(rdram, ctx);
        goto after_30;
    // 0x80800420: lui         $a1, 0x42AE
    ctx->r5 = S32(0X42AE << 16);
    after_30:
L_80800424:
    // 0x80800424: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800428: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8080042C: nop

    // 0x80800430: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800434: nop

    // 0x80800438: bc1fl       L_80800458
    if (!c1cs) {
        // 0x8080043C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800458;
    }
    goto skip_3;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800440: jal         0x8008E35C
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_31;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800448: beq         $v0, $zero, L_80800454
    if (ctx->r2 == 0) {
        // 0x8080044C: addiu       $t4, $zero, 0x4C
        ctx->r12 = ADD32(0, 0X4C);
            goto L_80800454;
    }
    // 0x8080044C: addiu       $t4, $zero, 0x4C
    ctx->r12 = ADD32(0, 0X4C);
    // 0x80800450: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80800454:
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800458:
    // 0x80800458: jal         0x8009E5C8
    // 0x8080045C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_32;
    // 0x8080045C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_32:
    // 0x80800460: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800464: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800468: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080046C: jr          $ra
    // 0x80800470: nop

    return;
    // 0x80800470: nop

;}
RECOMP_FUNC void _bainvisible_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854B8: syscall     164
    recomp_syscall_handler(rdram, ctx, 0x800854B8);
    return;
    // 0x800854BC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chlagoonufoext_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(744, 0X558) << 16);
    // 0x808001D0: jr          $ra
    // 0x808001D4: addiu       $v0, $v0, 0x558
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(744, 0X558));
    return;
    // 0x808001D4: addiu       $v0, $v0, 0x558
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(744, 0X558));
;}
RECOMP_FUNC void func_80800144_scinfobar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080014C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80800150: beql        $a1, $v0, L_80800224
    if (ctx->r5 == ctx->r2) {
        // 0x80800154: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800224;
    }
    goto skip_0;
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800158: lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2);
    // 0x8080015C: beql        $v1, $zero, L_80800184
    if (ctx->r3 == 0) {
        // 0x80800160: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80800184;
    }
    goto skip_1;
    // 0x80800160: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    skip_1:
    // 0x80800164: bnel        $v0, $v1, L_80800184
    if (ctx->r2 != ctx->r3) {
        // 0x80800168: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80800184;
    }
    goto skip_2;
    // 0x80800168: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    skip_2:
    // 0x8080016C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800170: jal         0x808000C4
    // 0x80800174: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_808000C4_scinfobar(rdram, ctx);
        goto after_0;
    // 0x80800174: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800178: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080017C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800180: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
L_80800184:
    // 0x80800184: beq         $a1, $at, L_80800214
    if (ctx->r5 == ctx->r1) {
        // 0x80800188: sb          $a1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r5;
            goto L_80800214;
    }
    // 0x80800188: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x8080018C: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80800190: beq         $a1, $at, L_808001B4
    if (ctx->r5 == ctx->r1) {
        // 0x80800194: lui         $v1, 0x8080
        ctx->r3 = S32(RELOC_HI16(3338, 0XD58) << 16);
            goto L_808001B4;
    }
    // 0x80800194: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(3338, 0XD58) << 16);
    // 0x80800198: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x8080019C: beq         $a1, $at, L_80800204
    if (ctx->r5 == ctx->r1) {
        // 0x808001A0: addiu       $at, $zero, 0x67
        ctx->r1 = ADD32(0, 0X67);
            goto L_80800204;
    }
    // 0x808001A0: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x808001A4: beql        $a1, $at, L_80800224
    if (ctx->r5 == ctx->r1) {
        // 0x808001A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800224;
    }
    goto skip_3;
    // 0x808001A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x808001AC: b           L_80800224
    // 0x808001B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800224;
    // 0x808001B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001B4:
    // 0x808001B4: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x808001B8: beql        $t6, $zero, L_808001CC
    if (ctx->r14 == 0) {
        // 0x808001BC: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_808001CC;
    }
    goto skip_4;
    // 0x808001BC: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    skip_4:
    // 0x808001C0: b           L_808001CC
    // 0x808001C4: lh          $v0, 0x30($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X30);
        goto L_808001CC;
    // 0x808001C4: lh          $v0, 0x30($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X30);
    // 0x808001C8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
L_808001CC:
    // 0x808001CC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x808001D0: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x808001D4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808001D8: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x808001DC: lw          $v1, 0xD58($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(3338, 0XD58));
    // 0x808001E0: beql        $v1, $zero, L_80800224
    if (ctx->r3 == 0) {
        // 0x808001E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800224;
    }
    goto skip_5;
    // 0x808001E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x808001E8: jalr        $v1
    // 0x808001EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x808001EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808001F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001F4: jal         0x80800530
    // 0x808001F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scinfobar_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808001F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x808001FC: b           L_80800224
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800224;
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800204:
    // 0x80800204: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800208: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080020C: b           L_80800220
    // 0x80800210: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
        goto L_80800220;
    // 0x80800210: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
L_80800214:
    // 0x80800214: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800218: nop

    // 0x8080021C: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
L_80800220:
    // 0x80800220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800224:
    // 0x80800224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800228: jr          $ra
    // 0x8080022C: nop

    return;
    // 0x8080022C: nop

;}
RECOMP_FUNC void chpowerhutwitchy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1080, 0XB28) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xB28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1080, 0XB28));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xB28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1080, 0XB28));
;}
RECOMP_FUNC void glidmake_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D0: jal         0x800D674C
    // 0x808000D4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x808000D4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x808000D8: jal         0x800B274C
    // 0x808000DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B274C(rdram, ctx);
        goto after_1;
    // 0x808000DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
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
RECOMP_FUNC void bscrouch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800148: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080014C: jal         0x8008CABC
    // 0x80800150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800154: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800158: jal         0x8009E710
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800160: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800164: beq         $v0, $at, L_80800188
    if (ctx->r2 == ctx->r1) {
        // 0x80800168: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80800188;
    }
    // 0x80800168: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080016C: beq         $v0, $at, L_80800188
    if (ctx->r2 == ctx->r1) {
        // 0x80800170: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80800188;
    }
    // 0x80800170: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80800174: beq         $v0, $at, L_80800188
    if (ctx->r2 == ctx->r1) {
        // 0x80800178: nop
    
            goto L_80800188;
    }
    // 0x80800178: nop

    // 0x8080017C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800180: b           L_80800194
    // 0x80800184: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
        goto L_80800194;
    // 0x80800184: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
L_80800188:
    // 0x80800188: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(152, 0X974) << 16);
    // 0x8080018C: lwc1        $f6, 0x974($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(152, 0X974));
    // 0x80800190: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
L_80800194:
    // 0x80800194: jal         0x8008AF24
    // 0x80800198: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800198: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x8080019C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808001A0: jal         0x8008AED4
    // 0x808001A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x808001A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808001A8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808001AC: jal         0x8008B1BC
    // 0x808001B0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x808001B0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_4:
    // 0x808001B4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808001B8: jal         0x8008B134
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808001C0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808001C4: jal         0x8008B24C
    // 0x808001C8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x808001C8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x808001CC: jal         0x8008B064
    // 0x808001D0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x808001D0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x8008CA4C
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_8;
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x8009C908
    // 0x808001E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_9;
    // 0x808001E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x808001F4: jal         0x8009C99C
    // 0x808001F8: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_10;
    // 0x808001F8: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    after_10:
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800200: jal         0x8009D2D8
    // 0x80800204: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8009D2D8(rdram, ctx);
        goto after_11;
    // 0x80800204: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_11:
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: jal         0x8009CFD8
    // 0x80800210: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_8009CFD8(rdram, ctx);
        goto after_12;
    // 0x80800210: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_12:
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x8009B800
    // 0x8080021C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baphysics_set_type(rdram, ctx);
        goto after_13;
    // 0x8080021C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x80800220: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800224: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: jal         0x80085338
    // 0x80800230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_14;
    // 0x80800230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800234: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80800238: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800240: jal         0x80085338
    // 0x80800244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_set(rdram, ctx);
        goto after_15;
    // 0x80800244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: jal         0x8009BB24
    // 0x80800250: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009BB24(rdram, ctx);
        goto after_16;
    // 0x80800250: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_16:
    // 0x80800254: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800258: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080025C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800260: nop

    // 0x80800264: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800268: jal         0x8002DCA0
    // 0x8080026C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_17;
    // 0x8080026C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_17:
    // 0x80800270: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80800274: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800278: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x8080027C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800280: nop

    // 0x80800284: bc1fl       L_80800298
    if (!c1cs) {
        // 0x80800288: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80800298;
    }
    goto skip_0;
    // 0x80800288: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    skip_0:
    // 0x8080028C: jal         0x8009D658
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_18;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800294: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_80800298:
    // 0x80800298: jal         0x800F1EA4
    // 0x8080029C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F1EA4(rdram, ctx);
        goto after_19;
    // 0x8080029C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_19:
    // 0x808002A0: beq         $v0, $zero, L_808002B0
    if (ctx->r2 == 0) {
        // 0x808002A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002B0;
    }
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: jal         0x8009B9C0
    // 0x808002AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_20;
    // 0x808002AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_20:
L_808002B0:
    // 0x808002B0: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x808002B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808002C0: jr          $ra
    // 0x808002C4: nop

    return;
    // 0x808002C4: nop

;}
RECOMP_FUNC void _suflamefx_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089950: syscall     798
    recomp_syscall_handler(rdram, ctx, 0x80089950);
    return;
    // 0x80089954: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bavan_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085380: syscall     159
    recomp_syscall_handler(rdram, ctx, 0x80085380);
    return;
    // 0x80085384: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chmricecube_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086360: syscall     312
    recomp_syscall_handler(rdram, ctx, 0x80086360);
    return;
    // 0x80086364: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800DF4_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DF4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800DF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DFC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800E00: jal         0x808001B8
    // 0x80800E04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001B8_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80800E04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800E08: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800E0C: jal         0x80800164
    // 0x80800E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80800E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800E14: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800E18: jal         0x80800248
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800248_bsbtrot(rdram, ctx);
        goto after_2;
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800E20: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800E24: jal         0x808001EC
    // 0x80800E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001EC_bsbtrot(rdram, ctx);
        goto after_3;
    // 0x80800E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E34: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800E38: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80800E3C: jal         0x8008C9F0
    // 0x80800E40: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_4;
    // 0x80800E40: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80800E44: jal         0x8008E1A0
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E1A0(rdram, ctx);
        goto after_5;
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800E4C: beq         $v0, $zero, L_80800E94
    if (ctx->r2 == 0) {
        // 0x80800E50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E94;
    }
    // 0x80800E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E54: jal         0x8009BBB8
    // 0x80800E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BBB8(rdram, ctx);
        goto after_6;
    // 0x80800E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800E5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2E0C) << 16);
    // 0x80800E60: lwc1        $f4, 0x2E0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2E0C));
    // 0x80800E64: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800E68: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x80800E6C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800E70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800E74: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800E78: jal         0x800F10B4
    // 0x80800E7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800E7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80800E80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800E84: jal         0x8008CA30
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008CA30(rdram, ctx);
        goto after_8;
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800E8C: b           L_80800EA0
    // 0x80800E90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800EA0;
    // 0x80800E90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E94:
    // 0x80800E94: jal         0x8008CA30
    // 0x80800E98: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_9;
    // 0x80800E98: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_9:
    // 0x80800E9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800EA0:
    // 0x80800EA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800EA4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800EA8: jr          $ra
    // 0x80800EAC: nop

    return;
    // 0x80800EAC: nop

;}
RECOMP_FUNC void func_800984F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800984F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800984F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800984F8: lw          $t7, 0xAC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XAC);
    // 0x800984FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80098500: sb          $t6, 0x29($t7)
    MEM_B(0X29, ctx->r15) = ctx->r14;
    // 0x80098504: lw          $a0, 0xAC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XAC);
    // 0x80098508: jal         0x800EE7F8
    // 0x8009850C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009850C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x80098510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098518: jr          $ra
    // 0x8009851C: nop

    return;
    // 0x8009851C: nop

;}
RECOMP_FUNC void func_800200B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800200B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800200BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800200C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800200C4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800200C8: lbu         $t7, 0x44($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X44);
    // 0x800200CC: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800200D0: beq         $t8, $zero, L_800200F0
    if (ctx->r24 == 0) {
        // 0x800200D4: nop
    
            goto L_800200F0;
    }
    // 0x800200D4: nop

    // 0x800200D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800200DC: jal         0x80026FF0
    // 0x800200E0: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80026FF0(rdram, ctx);
        goto after_0;
    // 0x800200E0: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800200E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800200E8: jal         0x80027090
    // 0x800200EC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80027090(rdram, ctx);
        goto after_1;
    // 0x800200EC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
L_800200F0:
    // 0x800200F0: jal         0x800205D0
    // 0x800200F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800205D0(rdram, ctx);
        goto after_2;
    // 0x800200F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800200F8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800200FC: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x80020100: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80020104: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80020108: jal         0x800201A4
    // 0x8002010C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_800201A4(rdram, ctx);
        goto after_3;
    // 0x8002010C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_3:
    // 0x80020110: b           L_80020118
    // 0x80020114: nop

        goto L_80020118;
    // 0x80020114: nop

L_80020118:
    // 0x80020118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002011C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020120: jr          $ra
    // 0x80020124: nop

    return;
    // 0x80020124: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_43(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808025C8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2EF0) << 16);
    // 0x808025CC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808025D0: jr          $ra
    // 0x808025D4: lw          $v0, 0x2EF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2EF0));
    return;
    // 0x808025D4: lw          $v0, 0x2EF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2EF0));
;}
RECOMP_FUNC void _ncbafly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892C0: syscall     771
    recomp_syscall_handler(rdram, ctx, 0x800892C0);
    return;
    // 0x800892C4: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80094370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094378: jal         0x800946C4
    // 0x8009437C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800946C4(rdram, ctx);
        goto after_0;
    // 0x8009437C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80094380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094388: jr          $ra
    // 0x8009438C: nop

    return;
    // 0x8009438C: nop

;}
RECOMP_FUNC void gcgoto_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800550: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800554: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800558: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080055C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800560: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800564: jal         0x8008FE68
    // 0x80800568: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008FE68(rdram, ctx);
        goto after_0;
    // 0x80800568: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8080056C: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x80800570: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800574: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800578: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080057C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800580: jal         0x80800468
    // 0x80800584: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    gcgoto_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800584: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80800588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080058C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800590: jr          $ra
    // 0x80800594: nop

    return;
    // 0x80800594: nop

;}
RECOMP_FUNC void func_808024B8_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808024B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808024BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808024C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808024C4: jal         0x800FDC28
    // 0x808024C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_0;
    // 0x808024C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x808024CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808024D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808024D4: jr          $ra
    // 0x808024D8: nop

    return;
    // 0x808024D8: nop

;}
RECOMP_FUNC void func_800E368C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E368C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3694: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800E3698: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E369C: jal         0x800E22F0
    // 0x800E36A0: lw          $a1, -0x2B0C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2B0C);
    func_800E22F0(rdram, ctx);
        goto after_0;
    // 0x800E36A0: lw          $a1, -0x2B0C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2B0C);
    after_0:
    // 0x800E36A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E36A8: sw          $zero, -0x2B0C($at)
    MEM_W(-0X2B0C, ctx->r1) = 0;
    // 0x800E36AC: jal         0x800E4640
    // 0x800E36B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800E4640(rdram, ctx);
        goto after_1;
    // 0x800E36B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800E36B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E36B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E36BC: jr          $ra
    // 0x800E36C0: nop

    return;
    // 0x800E36C0: nop

    // 0x800E36C4: nop

    // 0x800E36C8: nop

    // 0x800E36CC: nop

;}
RECOMP_FUNC void func_808015C4_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808015C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808015CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808015D0: jal         0x8008CABC
    // 0x808015D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808015D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808015D8: lui         $a1, 0x3EBB
    ctx->r5 = S32(0X3EBB << 16);
    // 0x808015DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808015E0: ori         $a1, $a1, 0x573F
    ctx->r5 = ctx->r5 | 0X573F;
    // 0x808015E4: jal         0x8008B348
    // 0x808015E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x808015E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808015EC: beq         $v0, $zero, L_80801618
    if (ctx->r2 == 0) {
        // 0x808015F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801618;
    }
    // 0x808015F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015F4: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x808015F8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808015FC: jal         0x8009DF18
    // 0x80801600: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DF18(rdram, ctx);
        goto after_2;
    // 0x80801600: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_2:
    // 0x80801604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801608: addiu       $a1, $zero, 0x4454
    ctx->r5 = ADD32(0, 0X4454);
    // 0x8080160C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801610: jal         0x8009DF18
    // 0x80801614: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF18(rdram, ctx);
        goto after_3;
    // 0x80801614: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_3:
L_80801618:
    // 0x80801618: lui         $a1, 0x3F2F
    ctx->r5 = S32(0X3F2F << 16);
    // 0x8080161C: ori         $a1, $a1, 0xAACE
    ctx->r5 = ctx->r5 | 0XAACE;
    // 0x80801620: jal         0x8008B348
    // 0x80801624: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x80801624: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801628: beq         $v0, $zero, L_80801658
    if (ctx->r2 == 0) {
        // 0x8080162C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801658;
    }
    // 0x8080162C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801630: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80801634: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801638: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x8080163C: jal         0x8009DF18
    // 0x80801640: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_5;
    // 0x80801640: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_5:
    // 0x80801644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801648: addiu       $a1, $zero, 0x427
    ctx->r5 = ADD32(0, 0X427);
    // 0x8080164C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801650: jal         0x8009DF18
    // 0x80801654: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF18(rdram, ctx);
        goto after_6;
    // 0x80801654: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_6:
L_80801658:
    // 0x80801658: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x8080165C: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80801660: jal         0x8008B348
    // 0x80801664: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x80801664: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80801668: beq         $v0, $zero, L_80801678
    if (ctx->r2 == 0) {
        // 0x8080166C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801678;
    }
    // 0x8080166C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801670: jal         0x8009B9B0
    // 0x80801674: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x80801674: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
L_80801678:
    // 0x80801678: jal         0x8008B2B4
    // 0x8080167C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_9;
    // 0x8080167C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x80801680: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(96, 0X1D18) << 16);
    // 0x80801684: lwc1        $f4, 0x1D18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(96, 0X1D18));
    // 0x80801688: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080168C: nop

    // 0x80801690: bc1fl       L_808016A4
    if (!c1cs) {
        // 0x80801694: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808016A4;
    }
    goto skip_0;
    // 0x80801694: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801698: jal         0x80084A10
    // 0x8080169C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x8080169C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808016A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808016A4:
    // 0x808016A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808016A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808016AC: jr          $ra
    // 0x808016B0: nop

    return;
    // 0x808016B0: nop

;}
RECOMP_FUNC void func_80800268_chbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080026C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800270: beq         $a1, $at, L_808002A4
    if (ctx->r5 == ctx->r1) {
        // 0x80800274: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808002A4;
    }
    // 0x80800274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800278: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080027C: beq         $a1, $at, L_80800294
    if (ctx->r5 == ctx->r1) {
        // 0x80800280: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_80800294;
    }
    // 0x80800280: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800284: beql        $a1, $at, L_808002CC
    if (ctx->r5 == ctx->r1) {
        // 0x80800288: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808002CC;
    }
    goto skip_0;
    // 0x80800288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080028C: b           L_808002CC
    // 0x80800290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002CC;
    // 0x80800290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800294:
    // 0x80800294: jal         0x808000CC
    // 0x80800298: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_808000CC_chbeehive(rdram, ctx);
        goto after_0;
    // 0x80800298: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8080029C: b           L_808002CC
    // 0x808002A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002CC;
    // 0x808002A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002A4:
    // 0x808002A4: jal         0x801015D0
    // 0x808002A8: nop

    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x808002A8: nop

    after_1:
    // 0x808002AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808002B0: jal         0x800DF744
    // 0x808002B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808002B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808002B8: b           L_808002CC
    // 0x808002BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002CC;
    // 0x808002BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002C0: b           L_808002CC
    // 0x808002C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002CC;
    // 0x808002C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002CC:
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829E8: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x800829E8);
    return;
    // 0x800829EC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8009BD30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BD30: jr          $ra
    // 0x8009BD34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009BD34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void chphlegm_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1064, 0XB58) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1064, 0XB58));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1064, 0XB58));
;}
RECOMP_FUNC void func_80800000_chlavacolumnswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: bne         $a1, $at, L_80800024
    if (ctx->r5 != ctx->r1) {
        // 0x8080000C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800024;
    }
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    // 0x80800014: jal         0x800887D8
    // 0x80800018: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x8080001C: b           L_8080002C
    // 0x80800020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080002C;
    // 0x80800020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800024:
    // 0x80800024: jal         0x80085820
    // 0x80800028: nop

    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800028: nop

    after_1:
L_8080002C:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825A8: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825A8);
    return;
    // 0x800825AC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _chelectricfence_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862B8: syscall     301
    recomp_syscall_handler(rdram, ctx, 0x800862B8);
    return;
    // 0x800862BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gspropctrl_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BC0: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088BC0);
    return;
    // 0x80088BC4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _idtwinklecolour_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088EC0: syscall     747
    recomp_syscall_handler(rdram, ctx, 0x80088EC0);
    return;
    // 0x80088EC4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800FF0_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FF8: jal         0x80100094
    // 0x80800FFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800FFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801000: lbu         $v1, 0x24($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X24);
    // 0x80801004: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080100C: beq         $v1, $at, L_80801024
    if (ctx->r3 == ctx->r1) {
        // 0x80801010: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801024;
    }
    // 0x80801010: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801014: beq         $v1, $at, L_80801024
    if (ctx->r3 == ctx->r1) {
        // 0x80801018: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801024;
    }
    // 0x80801018: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080101C: bne         $v1, $at, L_8080102C
    if (ctx->r3 != ctx->r1) {
        // 0x80801020: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080102C;
    }
    // 0x80801020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801024:
    // 0x80801024: b           L_8080102C
    // 0x80801028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080102C;
    // 0x80801028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080102C:
    // 0x8080102C: jr          $ra
    // 0x80801030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80801030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void bsjump_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C14: jal         0x800961AC
    // 0x80800C18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_0;
    // 0x80800C18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800C1C: jal         0x8009BC6C
    // 0x80800C20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x80800C20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C2C: jr          $ra
    // 0x80800C30: nop

    return;
    // 0x80800C30: nop

;}
RECOMP_FUNC void _indrv_lights_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F88: syscall     751
    recomp_syscall_handler(rdram, ctx, 0x80088F88);
    return;
    // 0x80088F8C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _subaddiesect_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F50: syscall     817
    recomp_syscall_handler(rdram, ctx, 0x80089F50);
    return;
    // 0x80089F54: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800018_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080001C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800024: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800028: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080002C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800030: jal         0x80100094
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800038: lbu         $t7, 0x73($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X73);
    // 0x8080003C: lbu         $t0, 0x7B($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X7B);
    // 0x80800040: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80800044: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800048: ori         $t1, $t0, 0xC0
    ctx->r9 = ctx->r8 | 0XC0;
    // 0x8080004C: sb          $t8, 0x73($s1)
    MEM_B(0X73, ctx->r17) = ctx->r24;
    // 0x80800050: sb          $t1, 0x7B($s1)
    MEM_B(0X7B, ctx->r17) = ctx->r9;
    // 0x80800054: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800058: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x8080005C: jal         0x800EE7F8
    // 0x80800060: addiu       $a0, $v0, 0x11C
    ctx->r4 = ADD32(ctx->r2, 0X11C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a0, $v0, 0x11C
    ctx->r4 = ADD32(ctx->r2, 0X11C);
    after_1:
    // 0x80800064: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800068: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080006C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800070: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x80800074: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80800078: jal         0x8008A0C8
    // 0x8080007C: addiu       $a3, $s2, 0xA4
    ctx->r7 = ADD32(ctx->r18, 0XA4);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080007C: addiu       $a3, $s2, 0xA4
    ctx->r7 = ADD32(ctx->r18, 0XA4);
    after_2:
    // 0x80800080: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800084: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800088: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080008C: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x80800090: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x80800094: jal         0x8008A0C8
    // 0x80800098: addiu       $a3, $s2, 0xBC
    ctx->r7 = ADD32(ctx->r18, 0XBC);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800098: addiu       $a3, $s2, 0xBC
    ctx->r7 = ADD32(ctx->r18, 0XBC);
    after_3:
    // 0x8080009C: addiu       $a3, $s2, 0xD4
    ctx->r7 = ADD32(ctx->r18, 0XD4);
    // 0x808000A0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808000A4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808000A8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808000AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000B0: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x808000B4: jal         0x8008A0C8
    // 0x808000B8: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808000B8: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    after_4:
    // 0x808000BC: addiu       $a3, $s2, 0xEC
    ctx->r7 = ADD32(ctx->r18, 0XEC);
    // 0x808000C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808000C4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808000C8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x808000CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000D0: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x808000D4: jal         0x8008A0C8
    // 0x808000D8: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808000D8: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    after_5:
    // 0x808000DC: addiu       $a3, $s2, 0x104
    ctx->r7 = ADD32(ctx->r18, 0X104);
    // 0x808000E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000E8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808000EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000F0: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x808000F4: jal         0x8008A0C8
    // 0x808000F8: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808000F8: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    after_6:
    // 0x808000FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800100: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80800104: sh          $t7, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r15;
    // 0x80800108: sw          $zero, 0x9C($s2)
    MEM_W(0X9C, ctx->r18) = 0;
    // 0x8080010C: sw          $zero, 0xA0($s2)
    MEM_W(0XA0, ctx->r18) = 0;
    // 0x80800110: sh          $zero, 0x92($s2)
    MEM_H(0X92, ctx->r18) = 0;
    // 0x80800114: sh          $t8, 0x96($s2)
    MEM_H(0X96, ctx->r18) = ctx->r24;
    // 0x80800118: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080011C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800120:
    // 0x80800120: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800124: jal         0x808015F4
    // 0x80800128: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808015F4_changlerboss(rdram, ctx);
        goto after_7;
    // 0x80800128: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x8080012C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800130: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800134: bnel        $s0, $at, L_80800120
    if (ctx->r16 != ctx->r1) {
        // 0x80800138: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800120;
    }
    goto skip_0;
    // 0x80800138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8080013C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800140: jal         0x80109F08
    // 0x80800144: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109F08(rdram, ctx);
        goto after_8;
    // 0x80800144: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_8:
    // 0x80800148: jal         0x800F54E4
    // 0x8080014C: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x8080014C: nop

    after_9:
    // 0x80800150: jal         0x80088848
    // 0x80800154: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_10;
    // 0x80800154: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_10:
    // 0x80800158: beq         $v0, $zero, L_8080019C
    if (ctx->r2 == 0) {
        // 0x8080015C: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8080019C;
    }
    // 0x8080015C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800160: jal         0x800EE7F8
    // 0x80800164: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80800164: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x80800168: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080016C: jal         0x80102424
    // 0x80800170: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x80800170: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_12:
    // 0x80800174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800178: jal         0x8010A85C
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_13;
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800180: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2DA0) << 16);
    // 0x80800184: addiu       $a2, $a2, 0x2DA0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2DA0));
    // 0x80800188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080018C: jal         0x80089D18
    // 0x80800190: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x80800190: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_14:
    // 0x80800194: b           L_808002CC
    // 0x80800198: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808002CC;
    // 0x80800198: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080019C:
    // 0x8080019C: jal         0x800DA298
    // 0x808001A0: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x808001A0: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_15:
    // 0x808001A4: beq         $v0, $zero, L_808001F0
    if (ctx->r2 == 0) {
        // 0x808001A8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001F0;
    }
    // 0x808001A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001B0: jal         0x8010A85C
    // 0x808001B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_16;
    // 0x808001B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808001B8: jal         0x8010A590
    // 0x808001BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010A590(rdram, ctx);
        goto after_17;
    // 0x808001BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x808001C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001C4: jal         0x808012E0
    // 0x808001C8: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_18;
    // 0x808001C8: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_18:
    // 0x808001CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808001D0: jal         0x800EE7F8
    // 0x808001D4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_19;
    // 0x808001D4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_19:
    // 0x808001D8: lwc1        $f4, 0xFC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XFC);
    // 0x808001DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808001E0: jal         0x800861A8
    // 0x808001E4: swc1        $f4, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f4.u32l;
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_20;
    // 0x808001E4: swc1        $f4, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f4.u32l;
    after_20:
    // 0x808001E8: b           L_808002CC
    // 0x808001EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808002CC;
    // 0x808001EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808001F0:
    // 0x808001F0: jal         0x8010A85C
    // 0x808001F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A85C(rdram, ctx);
        goto after_21;
    // 0x808001F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_21:
    // 0x808001F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808001FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800200: addiu       $a0, $zero, 0x1AF
    ctx->r4 = ADD32(0, 0X1AF);
    // 0x80800204: jal         0x800DA298
    // 0x80800208: swc1        $f6, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f6.u32l;
    func_800DA298(rdram, ctx);
        goto after_22;
    // 0x80800208: swc1        $f6, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f6.u32l;
    after_22:
    // 0x8080020C: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800210: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080027C;
    }
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800218: jal         0x800EE7F8
    // 0x8080021C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_23;
    // 0x8080021C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_23:
    // 0x80800220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800224: jal         0x808012E0
    // 0x80800228: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_24;
    // 0x80800228: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_24:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x800F608C
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F608C(rdram, ctx);
        goto after_25;
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x800F8294
    // 0x80800240: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800F8294(rdram, ctx);
        goto after_26;
    // 0x80800240: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_26:
    // 0x80800244: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800248: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x8080024C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800250: addiu       $a1, $zero, 0x1028
    ctx->r5 = ADD32(0, 0X1028);
    // 0x80800254: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    // 0x80800258: jal         0x8008A208
    // 0x8080025C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_27;
    // 0x8080025C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_27:
    // 0x80800260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800264: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80800268: jal         0x808021E4
    // 0x8080026C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_28;
    // 0x8080026C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_28:
    // 0x80800270: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800274: b           L_808002C8
    // 0x80800278: sb          $t0, 0x12A($s2)
    MEM_B(0X12A, ctx->r18) = ctx->r8;
        goto L_808002C8;
    // 0x80800278: sb          $t0, 0x12A($s2)
    MEM_B(0X12A, ctx->r18) = ctx->r8;
L_8080027C:
    // 0x8080027C: jal         0x800F608C
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F608C(rdram, ctx);
        goto after_29;
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80800284: jal         0x800F497C
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F497C(rdram, ctx);
        goto after_30;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8080028C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80800290: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x800F49D4
    // 0x8080029C: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_31;
    // 0x8080029C: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    after_31:
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808002A8: jal         0x800F4AC0
    // 0x808002AC: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800F4AC0(rdram, ctx);
        goto after_32;
    // 0x808002AC: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_32:
    // 0x808002B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002B4: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x808002B8: jal         0x808021E4
    // 0x808002BC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_33;
    // 0x808002BC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_33:
    // 0x808002C0: jal         0x800861A8
    // 0x808002C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_34;
    // 0x808002C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_34:
L_808002C8:
    // 0x808002C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002CC:
    // 0x808002CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002D0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808002D4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808002D8: jr          $ra
    // 0x808002DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808002DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800758_bskazstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080075C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800760: jal         0x800832E8
    // 0x80800764: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800764: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800768: jal         0x80082FF0
    // 0x8080076C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080076C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800778: jr          $ra
    // 0x8080077C: nop

    return;
    // 0x8080077C: nop

;}
RECOMP_FUNC void idworldmake_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800860: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800864: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x80800868: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080086C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800870: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800874: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800878: beq         $a0, $zero, L_808008EC
    if (ctx->r4 == 0) {
        // 0x8080087C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_808008EC;
    }
    // 0x8080087C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800880: jal         0x800B296C
    // 0x80800884: nop

    vector_end(rdram, ctx);
        goto after_0;
    // 0x80800884: nop

    after_0:
    // 0x80800888: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8080088C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800890: jal         0x800B28C4
    // 0x80800894: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x80800894: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    after_1:
    // 0x80800898: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x8080089C: beq         $at, $zero, L_808008D8
    if (ctx->r1 == 0) {
        // 0x808008A0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808008D8;
    }
    // 0x808008A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808008A4: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2954, 0XAB0) << 16);
    // 0x808008A8: addiu       $s2, $s2, 0xAB0
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2954, 0XAB0));
    // 0x808008AC: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
L_808008B0:
    // 0x808008B0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x808008B4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808008B8: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x808008BC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x808008C0: jalr        $t9
    // 0x808008C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x808008C4: nop

    after_2:
    // 0x808008C8: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
    // 0x808008CC: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x808008D0: bnel        $at, $zero, L_808008B0
    if (ctx->r1 != 0) {
        // 0x808008D4: lbu         $t6, 0x6($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X6);
            goto L_808008B0;
    }
    goto skip_0;
    // 0x808008D4: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    skip_0:
L_808008D8:
    // 0x808008D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x808008DC: jal         0x800B2D28
    // 0x808008E0: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    vector_free(rdram, ctx);
        goto after_3;
    // 0x808008E0: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    after_3:
    // 0x808008E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808008E8: sw          $zero, 0x7EF8($at)
    MEM_W(0X7EF8, ctx->r1) = 0;
L_808008EC:
    // 0x808008EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808008F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808008FC: jr          $ra
    // 0x80800900: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800900: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void basudie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800068: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080006C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800070: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800074: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800078: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8080007C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800080: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800084: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800088: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8080008C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800090: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800094: jal         0x808000F0
    // 0x80800098: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    basudie_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800098: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void func_800AA4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA4D4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800AA4D8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800AA4DC: lh          $t6, 0x12($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X12);
    // 0x800AA4E0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AA4E4: addiu       $t1, $t1, 0x77A0
    ctx->r9 = ADD32(ctx->r9, 0X77A0);
    // 0x800AA4E8: bnel        $t6, $zero, L_800AA51C
    if (ctx->r14 != 0) {
        // 0x800AA4EC: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_800AA51C;
    }
    goto skip_0;
    // 0x800AA4EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x800AA4F0: sw          $t1, 0x190($t1)
    MEM_W(0X190, ctx->r9) = ctx->r9;
    // 0x800AA4F4: addiu       $t7, $a0, 0x18
    ctx->r15 = ADD32(ctx->r4, 0X18);
    // 0x800AA4F8: addiu       $t5, $t1, 0x4
    ctx->r13 = ADD32(ctx->r9, 0X4);
    // 0x800AA4FC: sw          $t5, 0x190($t1)
    MEM_W(0X190, ctx->r9) = ctx->r13;
    // 0x800AA500: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800AA504: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x800AA508: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800AA50C: lw          $t6, 0x190($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X190);
    // 0x800AA510: b           L_800AA7F4
    // 0x800AA514: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
        goto L_800AA7F4;
    // 0x800AA514: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AA518: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_800AA51C:
    // 0x800AA51C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800AA520: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x800AA524: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800AA528: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800AA52C: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800AA530: addiu       $t4, $sp, 0x44
    ctx->r12 = ADD32(ctx->r29, 0X44);
L_800AA534:
    // 0x800AA534: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800AA538: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AA53C: lh          $v0, 0x12($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X12);
    // 0x800AA540: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AA544: nop

    // 0x800AA548: bc1fl       L_800AA598
    if (!c1cs) {
        // 0x800AA54C: trunc.w.s   $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_800AA598;
    }
    goto skip_1;
    // 0x800AA54C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_1:
    // 0x800AA550: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AA554: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800AA558: nop

    // 0x800AA55C: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x800AA560: mflo        $t5
    ctx->r13 = lo;
    // 0x800AA564: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800AA568: bne         $v0, $zero, L_800AA574
    if (ctx->r2 != 0) {
        // 0x800AA56C: nop
    
            goto L_800AA574;
    }
    // 0x800AA56C: nop

    // 0x800AA570: break       7
    do_break(2148181360);
L_800AA574:
    // 0x800AA574: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA578: bne         $v0, $at, L_800AA58C
    if (ctx->r2 != ctx->r1) {
        // 0x800AA57C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AA58C;
    }
    // 0x800AA57C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA580: bne         $t9, $at, L_800AA58C
    if (ctx->r25 != ctx->r1) {
        // 0x800AA584: nop
    
            goto L_800AA58C;
    }
    // 0x800AA584: nop

    // 0x800AA588: break       6
    do_break(2148181384);
L_800AA58C:
    // 0x800AA58C: b           L_800AA5D8
    // 0x800AA590: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
        goto L_800AA5D8;
    // 0x800AA590: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800AA594: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
L_800AA598:
    // 0x800AA598: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800AA59C: nop

    // 0x800AA5A0: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x800AA5A4: mflo        $t8
    ctx->r24 = lo;
    // 0x800AA5A8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800AA5AC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800AA5B0: bne         $v0, $zero, L_800AA5BC
    if (ctx->r2 != 0) {
        // 0x800AA5B4: nop
    
            goto L_800AA5BC;
    }
    // 0x800AA5B4: nop

    // 0x800AA5B8: break       7
    do_break(2148181432);
L_800AA5BC:
    // 0x800AA5BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA5C0: bne         $v0, $at, L_800AA5D4
    if (ctx->r2 != ctx->r1) {
        // 0x800AA5C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AA5D4;
    }
    // 0x800AA5C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA5C8: bne         $t7, $at, L_800AA5D4
    if (ctx->r15 != ctx->r1) {
        // 0x800AA5CC: nop
    
            goto L_800AA5D4;
    }
    // 0x800AA5CC: nop

    // 0x800AA5D0: break       6
    do_break(2148181456);
L_800AA5D4:
    // 0x800AA5D4: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
L_800AA5D8:
    // 0x800AA5D8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AA5DC: nop

    // 0x800AA5E0: bc1fl       L_800AA634
    if (!c1cs) {
        // 0x800AA5E4: trunc.w.s   $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_800AA634;
    }
    goto skip_2;
    // 0x800AA5E4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_2:
    // 0x800AA5E8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AA5EC: lh          $t7, 0x12($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X12);
    // 0x800AA5F0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800AA5F4: nop

    // 0x800AA5F8: div         $zero, $t6, $t7
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r15)));
    // 0x800AA5FC: mflo        $t8
    ctx->r24 = lo;
    // 0x800AA600: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800AA604: bne         $t7, $zero, L_800AA610
    if (ctx->r15 != 0) {
        // 0x800AA608: nop
    
            goto L_800AA610;
    }
    // 0x800AA608: nop

    // 0x800AA60C: break       7
    do_break(2148181516);
L_800AA610:
    // 0x800AA610: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA614: bne         $t7, $at, L_800AA628
    if (ctx->r15 != ctx->r1) {
        // 0x800AA618: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AA628;
    }
    // 0x800AA618: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA61C: bne         $t6, $at, L_800AA628
    if (ctx->r14 != ctx->r1) {
        // 0x800AA620: nop
    
            goto L_800AA628;
    }
    // 0x800AA620: nop

    // 0x800AA624: break       6
    do_break(2148181540);
L_800AA628:
    // 0x800AA628: b           L_800AA678
    // 0x800AA62C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
        goto L_800AA678;
    // 0x800AA62C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800AA630: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
L_800AA634:
    // 0x800AA634: lh          $t6, 0x12($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X12);
    // 0x800AA638: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800AA63C: nop

    // 0x800AA640: div         $zero, $t5, $t6
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r14)));
    // 0x800AA644: mflo        $t7
    ctx->r15 = lo;
    // 0x800AA648: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800AA64C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800AA650: bne         $t6, $zero, L_800AA65C
    if (ctx->r14 != 0) {
        // 0x800AA654: nop
    
            goto L_800AA65C;
    }
    // 0x800AA654: nop

    // 0x800AA658: break       7
    do_break(2148181592);
L_800AA65C:
    // 0x800AA65C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA660: bne         $t6, $at, L_800AA674
    if (ctx->r14 != ctx->r1) {
        // 0x800AA664: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AA674;
    }
    // 0x800AA664: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA668: bne         $t5, $at, L_800AA674
    if (ctx->r13 != ctx->r1) {
        // 0x800AA66C: nop
    
            goto L_800AA674;
    }
    // 0x800AA66C: nop

    // 0x800AA670: break       6
    do_break(2148181616);
L_800AA674:
    // 0x800AA674: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_800AA678:
    // 0x800AA678: lh          $a1, 0x0($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X0);
    // 0x800AA67C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AA680: beql        $at, $zero, L_800AA694
    if (ctx->r1 == 0) {
        // 0x800AA684: lh          $a1, 0x6($t2)
        ctx->r5 = MEM_H(ctx->r10, 0X6);
            goto L_800AA694;
    }
    goto skip_3;
    // 0x800AA684: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
    skip_3:
    // 0x800AA688: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x800AA68C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800AA690: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
L_800AA694:
    // 0x800AA694: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800AA698: beql        $at, $zero, L_800AA6AC
    if (ctx->r1 == 0) {
        // 0x800AA69C: lw          $t3, 0x0($t1)
        ctx->r11 = MEM_W(ctx->r9, 0X0);
            goto L_800AA6AC;
    }
    goto skip_4;
    // 0x800AA69C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    skip_4:
    // 0x800AA6A0: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x800AA6A4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800AA6A8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
L_800AA6AC:
    // 0x800AA6AC: lh          $a1, 0x0($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X0);
    // 0x800AA6B0: slt         $at, $t3, $a1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AA6B4: beql        $at, $zero, L_800AA6C8
    if (ctx->r1 == 0) {
        // 0x800AA6B8: lh          $a1, 0x6($t2)
        ctx->r5 = MEM_H(ctx->r10, 0X6);
            goto L_800AA6C8;
    }
    goto skip_5;
    // 0x800AA6B8: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
    skip_5:
    // 0x800AA6BC: sw          $a1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r5;
    // 0x800AA6C0: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800AA6C4: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
L_800AA6C8:
    // 0x800AA6C8: slt         $at, $a1, $t3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800AA6CC: beql        $at, $zero, L_800AA6E0
    if (ctx->r1 == 0) {
        // 0x800AA6D0: lh          $t9, 0x0($t2)
        ctx->r25 = MEM_H(ctx->r10, 0X0);
            goto L_800AA6E0;
    }
    goto skip_6;
    // 0x800AA6D0: lh          $t9, 0x0($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X0);
    skip_6:
    // 0x800AA6D4: sw          $a1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r5;
    // 0x800AA6D8: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800AA6DC: lh          $t9, 0x0($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X0);
L_800AA6E0:
    // 0x800AA6E0: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800AA6E4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800AA6E8: subu        $t5, $v0, $t9
    ctx->r13 = SUB32(ctx->r2, ctx->r25);
    // 0x800AA6EC: sw          $t5, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r13;
    // 0x800AA6F0: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x800AA6F4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800AA6F8: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x800AA6FC: subu        $t7, $t3, $t6
    ctx->r15 = SUB32(ctx->r11, ctx->r14);
    // 0x800AA700: bne         $t1, $t4, L_800AA534
    if (ctx->r9 != ctx->r12) {
        // 0x800AA704: sw          $t7, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r15;
            goto L_800AA534;
    }
    // 0x800AA704: sw          $t7, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r15;
    // 0x800AA708: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800AA70C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800AA710: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AA714: addiu       $t1, $t1, 0x77A0
    ctx->r9 = ADD32(ctx->r9, 0X77A0);
    // 0x800AA718: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AA71C: bne         $at, $zero, L_800AA7E4
    if (ctx->r1 != 0) {
        // 0x800AA720: sw          $t1, 0x190($t1)
        MEM_W(0X190, ctx->r9) = ctx->r9;
            goto L_800AA7E4;
    }
    // 0x800AA720: sw          $t1, 0x190($t1)
    MEM_W(0X190, ctx->r9) = ctx->r9;
    // 0x800AA724: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800AA728: addiu       $t2, $t2, 0x7930
    ctx->r10 = ADD32(ctx->r10, 0X7930);
    // 0x800AA72C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800AA730: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800AA734:
    // 0x800AA734: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800AA738: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AA73C: bnel        $at, $zero, L_800AA7D4
    if (ctx->r1 != 0) {
        // 0x800AA740: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_800AA7D4;
    }
    goto skip_7;
    // 0x800AA740: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    skip_7:
    // 0x800AA744: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
L_800AA748:
    // 0x800AA748: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AA74C: bnel        $at, $zero, L_800AA7C0
    if (ctx->r1 != 0) {
        // 0x800AA750: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_800AA7C0;
    }
    goto skip_8;
    // 0x800AA750: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    skip_8:
    // 0x800AA754: lw          $v0, 0x190($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X190);
L_800AA758:
    // 0x800AA758: sltu        $at, $v0, $t2
    ctx->r1 = ctx->r2 < ctx->r10 ? 1 : 0;
    // 0x800AA75C: beql        $at, $zero, L_800AA7B0
    if (ctx->r1 == 0) {
        // 0x800AA760: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800AA7B0;
    }
    goto skip_9;
    // 0x800AA760: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_9:
    // 0x800AA764: lhu         $t5, 0xE($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0XE);
    // 0x800AA768: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800AA76C: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AA770: mflo        $t6
    ctx->r14 = lo;
    // 0x800AA774: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AA778: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x800AA77C: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800AA780: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x800AA784: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AA788: mflo        $t7
    ctx->r15 = lo;
    // 0x800AA78C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AA790: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800AA794: addiu       $t6, $t9, 0x18
    ctx->r14 = ADD32(ctx->r25, 0X18);
    // 0x800AA798: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AA79C: lw          $t7, 0x190($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X190);
    // 0x800AA7A0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800AA7A4: addiu       $t5, $t7, 0x4
    ctx->r13 = ADD32(ctx->r15, 0X4);
    // 0x800AA7A8: sw          $t5, 0x190($t1)
    MEM_W(0X190, ctx->r9) = ctx->r13;
    // 0x800AA7AC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800AA7B0:
    // 0x800AA7B0: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AA7B4: beql        $at, $zero, L_800AA758
    if (ctx->r1 == 0) {
        // 0x800AA7B8: lw          $v0, 0x190($t1)
        ctx->r2 = MEM_W(ctx->r9, 0X190);
            goto L_800AA758;
    }
    goto skip_10;
    // 0x800AA7B8: lw          $v0, 0x190($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X190);
    skip_10:
    // 0x800AA7BC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_800AA7C0:
    // 0x800AA7C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800AA7C4: slt         $at, $t8, $a1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AA7C8: beql        $at, $zero, L_800AA748
    if (ctx->r1 == 0) {
        // 0x800AA7CC: lw          $a2, 0x44($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X44);
            goto L_800AA748;
    }
    goto skip_11;
    // 0x800AA7CC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    skip_11:
    // 0x800AA7D0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_800AA7D4:
    // 0x800AA7D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AA7D8: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AA7DC: beql        $at, $zero, L_800AA734
    if (ctx->r1 == 0) {
        // 0x800AA7E0: lw          $a1, 0x48($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X48);
            goto L_800AA734;
    }
    goto skip_12;
    // 0x800AA7E0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    skip_12:
L_800AA7E4:
    // 0x800AA7E4: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x800AA7E8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800AA7EC: lw          $t6, 0x190($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X190);
    // 0x800AA7F0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_800AA7F4:
    // 0x800AA7F4: jr          $ra
    // 0x800AA7F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800AA7F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void bamovehover_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void sujiggy_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080033C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800340: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800344: jal         0x800FE844
    // 0x80800348: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FE844(rdram, ctx);
        goto after_0;
    // 0x80800348: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8080034C: jal         0x800FE734
    // 0x80800350: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FE734(rdram, ctx);
        goto after_1;
    // 0x80800350: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800354: jal         0x800DA544
    // 0x80800358: addiu       $a0, $zero, 0xD4F
    ctx->r4 = ADD32(0, 0XD4F);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800358: addiu       $a0, $zero, 0xD4F
    ctx->r4 = ADD32(0, 0XD4F);
    after_2:
    // 0x8080035C: jal         0x800DA298
    // 0x80800360: addiu       $a0, $zero, 0xD4D
    ctx->r4 = ADD32(0, 0XD4D);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800360: addiu       $a0, $zero, 0xD4D
    ctx->r4 = ADD32(0, 0XD4D);
    after_3:
    // 0x80800364: beq         $v0, $zero, L_80800380
    if (ctx->r2 == 0) {
        // 0x80800368: addiu       $a0, $zero, 0xD57
        ctx->r4 = ADD32(0, 0XD57);
            goto L_80800380;
    }
    // 0x80800368: addiu       $a0, $zero, 0xD57
    ctx->r4 = ADD32(0, 0XD57);
    // 0x8080036C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800370: jal         0x800DA7A8
    // 0x80800374: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800DA7A8(rdram, ctx);
        goto after_4;
    // 0x80800374: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x80800378: b           L_80800398
    // 0x8080037C: nop

        goto L_80800398;
    // 0x8080037C: nop

L_80800380:
    // 0x80800380: jal         0x80800758
    // 0x80800384: nop

    sujiggy_entrypoint_19(rdram, ctx);
        goto after_5;
    // 0x80800384: nop

    after_5:
    // 0x80800388: addiu       $a0, $zero, 0xD57
    ctx->r4 = ADD32(0, 0XD57);
    // 0x8080038C: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x80800390: jal         0x800DA7A8
    // 0x80800394: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800DA7A8(rdram, ctx);
        goto after_6;
    // 0x80800394: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
L_80800398:
    // 0x80800398: jal         0x800A9C50
    // 0x8080039C: nop

    func_800A9C50(rdram, ctx);
        goto after_7;
    // 0x8080039C: nop

    after_7:
    // 0x808003A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003A8: jr          $ra
    // 0x808003AC: nop

    return;
    // 0x808003AC: nop

;}
RECOMP_FUNC void _chweldarboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865E8: syscall     346
    recomp_syscall_handler(rdram, ctx, 0x800865E8);
    return;
    // 0x800865EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chfactoryrobot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1140, 0X2928) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2928
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1140, 0X2928));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2928
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1140, 0X2928));
;}
RECOMP_FUNC void _fxleaves_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088950: syscall     711
    recomp_syscall_handler(rdram, ctx, 0x80088950);
    return;
    // 0x80088954: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void baanim_playForDuration_onceSmoothStartingAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CD30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008CD34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008CD38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CD3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008CD40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008CD44: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8008CD48: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CD4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008CD50: jal         0x8008AF24
    // 0x8008CD54: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    anctrl_reset(rdram, ctx);
        goto after_0;
    // 0x8008CD54: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CD58: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008CD5C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008CD60: jal         0x8008AED4
    // 0x8008CD64: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    anctrl_setIndex(rdram, ctx);
        goto after_1;
    // 0x8008CD64: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x8008CD68: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008CD6C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008CD70: jal         0x8008B1BC
    // 0x8008CD74: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x8008CD74: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x8008CD78: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8008CD7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8008CD80: jal         0x8008B24C
    // 0x8008CD84: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    anctrl_setStart(rdram, ctx);
        goto after_3;
    // 0x8008CD84: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x8008CD88: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8008CD8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008CD90: jal         0x8008B134
    // 0x8008CD94: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x8008CD94: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x8008CD98: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8008CD9C: jal         0x8008B064
    // 0x8008CDA0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    anctrl_start(rdram, ctx);
        goto after_5;
    // 0x8008CDA0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_5:
    // 0x8008CDA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CDA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008CDAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008CDB0: jr          $ra
    // 0x8008CDB4: nop

    return;
    // 0x8008CDB4: nop

;}
RECOMP_FUNC void baswim_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B0: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x808005B4: jr          $ra
    // 0x808005B8: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    return;
    // 0x808005B8: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x808005BC: nop

;}
RECOMP_FUNC void bsdronejump_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080009C: jal         0x800961A0
    // 0x808000A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800961A0(rdram, ctx);
        goto after_0;
    // 0x808000A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_80800580_chcaptainblubber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800580: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800584: slti        $at, $a1, 0xF
    ctx->r1 = SIGNED(ctx->r5) < 0XF ? 1 : 0;
    // 0x80800588: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080058C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800590: bne         $at, $zero, L_808005D8
    if (ctx->r1 != 0) {
        // 0x80800594: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_808005D8;
    }
    // 0x80800594: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800598: slti        $at, $a1, 0x53
    ctx->r1 = SIGNED(ctx->r5) < 0X53 ? 1 : 0;
    // 0x8080059C: bne         $at, $zero, L_808005B8
    if (ctx->r1 != 0) {
        // 0x808005A0: addiu       $t6, $a1, -0x2E
        ctx->r14 = ADD32(ctx->r5, -0X2E);
            goto L_808005B8;
    }
    // 0x808005A0: addiu       $t6, $a1, -0x2E
    ctx->r14 = ADD32(ctx->r5, -0X2E);
    // 0x808005A4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808005A8: beq         $a1, $at, L_808005F4
    if (ctx->r5 == ctx->r1) {
        // 0x808005AC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808005F4;
    }
    // 0x808005AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808005B0: b           L_80800A0C
    // 0x808005B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x808005B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005B8:
    // 0x808005B8: sltiu       $at, $t6, 0x25
    ctx->r1 = ctx->r14 < 0X25 ? 1 : 0;
    // 0x808005BC: beq         $at, $zero, L_80800A08
    if (ctx->r1 == 0) {
        // 0x808005C0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800A08;
    }
    // 0x808005C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808005C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1538) << 16);
    // 0x808005C8: addu        $at, $at, $t6
    gpr jr_addend_808005D0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808005CC: lw          $t6, 0x1538($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1538));
    // 0x808005D0: jr          $t6
    // 0x808005D4: nop

    switch (jr_addend_808005D0 >> 2) {
        case 0: goto L_80800624; break;
        case 1: goto L_80800830; break;
        case 2: goto L_80800790; break;
        case 3: goto L_80800A08; break;
        case 4: goto L_8080092C; break;
        case 5: goto L_80800A08; break;
        case 6: goto L_80800A08; break;
        case 7: goto L_80800A08; break;
        case 8: goto L_80800A08; break;
        case 9: goto L_80800A08; break;
        case 10: goto L_80800A08; break;
        case 11: goto L_80800A08; break;
        case 12: goto L_80800A08; break;
        case 13: goto L_80800A08; break;
        case 14: goto L_80800A08; break;
        case 15: goto L_808008B8; break;
        case 16: goto L_80800A08; break;
        case 17: goto L_80800A08; break;
        case 18: goto L_80800A08; break;
        case 19: goto L_80800A08; break;
        case 20: goto L_80800A08; break;
        case 21: goto L_80800A08; break;
        case 22: goto L_80800A08; break;
        case 23: goto L_80800A08; break;
        case 24: goto L_80800A08; break;
        case 25: goto L_80800A08; break;
        case 26: goto L_80800A08; break;
        case 27: goto L_80800A08; break;
        case 28: goto L_80800A08; break;
        case 29: goto L_80800A08; break;
        case 30: goto L_80800A08; break;
        case 31: goto L_80800A08; break;
        case 32: goto L_80800A08; break;
        case 33: goto L_80800A08; break;
        case 34: goto L_80800A08; break;
        case 35: goto L_80800A08; break;
        case 36: goto L_8080089C; break;
        default: switch_error(__func__, 0x808005D0, 0x80801538);
    }
    // 0x808005D4: nop

L_808005D8:
    // 0x808005D8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808005DC: beq         $a1, $at, L_808007F0
    if (ctx->r5 == ctx->r1) {
        // 0x808005E0: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_808007F0;
    }
    // 0x808005E0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x808005E4: beq         $a1, $at, L_808007CC
    if (ctx->r5 == ctx->r1) {
        // 0x808005E8: nop
    
            goto L_808007CC;
    }
    // 0x808005E8: nop

    // 0x808005EC: b           L_80800A0C
    // 0x808005F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x808005F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005F4:
    // 0x808005F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005F8: jal         0x800897C0
    // 0x808005FC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808005FC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_0:
    // 0x80800600: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800604: jal         0x80100094
    // 0x80800608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080060C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800610: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800614: jal         0x800897E8
    // 0x80800618: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800618: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_2:
    // 0x8080061C: b           L_80800A0C
    // 0x80800620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800624:
    // 0x80800624: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x80800628: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8080062C: slti        $at, $v0, 0x1040
    ctx->r1 = SIGNED(ctx->r2) < 0X1040 ? 1 : 0;
    // 0x80800630: bne         $at, $zero, L_8080064C
    if (ctx->r1 != 0) {
        // 0x80800634: addiu       $t7, $v0, -0x1006
        ctx->r15 = ADD32(ctx->r2, -0X1006);
            goto L_8080064C;
    }
    // 0x80800634: addiu       $t7, $v0, -0x1006
    ctx->r15 = ADD32(ctx->r2, -0X1006);
    // 0x80800638: addiu       $at, $zero, 0x106B
    ctx->r1 = ADD32(0, 0X106B);
    // 0x8080063C: beql        $v0, $at, L_8080068C
    if (ctx->r2 == ctx->r1) {
        // 0x80800640: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_8080068C;
    }
    goto skip_0;
    // 0x80800640: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80800644: b           L_80800A0C
    // 0x80800648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x80800648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080064C:
    // 0x8080064C: slti        $at, $v0, 0x100C
    ctx->r1 = SIGNED(ctx->r2) < 0X100C ? 1 : 0;
    // 0x80800650: bne         $at, $zero, L_80800668
    if (ctx->r1 != 0) {
        // 0x80800654: addiu       $at, $zero, 0x103F
        ctx->r1 = ADD32(0, 0X103F);
            goto L_80800668;
    }
    // 0x80800654: addiu       $at, $zero, 0x103F
    ctx->r1 = ADD32(0, 0X103F);
    // 0x80800658: beq         $v0, $at, L_80800780
    if (ctx->r2 == ctx->r1) {
        // 0x8080065C: nop
    
            goto L_80800780;
    }
    // 0x8080065C: nop

    // 0x80800660: b           L_80800A0C
    // 0x80800664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x80800664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800668:
    // 0x80800668: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x8080066C: beq         $at, $zero, L_80800788
    if (ctx->r1 == 0) {
        // 0x80800670: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800788;
    }
    // 0x80800670: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800674: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X15CC) << 16);
    // 0x80800678: addu        $at, $at, $t7
    gpr jr_addend_80800680 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080067C: lw          $t7, 0x15CC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15CC));
    // 0x80800680: jr          $t7
    // 0x80800684: nop

    switch (jr_addend_80800680 >> 2) {
        case 0: goto L_80800688; break;
        case 1: goto L_80800688; break;
        case 2: goto L_808006BC; break;
        case 3: goto L_80800730; break;
        case 4: goto L_80800730; break;
        case 5: goto L_80800744; break;
        default: switch_error(__func__, 0x80800680, 0x808015CC);
    }
    // 0x80800684: nop

L_80800688:
    // 0x80800688: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
L_8080068C:
    // 0x8080068C: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80800690: addiu       $a1, $zero, 0x1008
    ctx->r5 = ADD32(0, 0X1008);
    // 0x80800694: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800698: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080069C: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x808006A0: jal         0x8008A208
    // 0x808006A4: addiu       $a3, $t8, 0x4
    ctx->r7 = ADD32(ctx->r24, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808006A4: addiu       $a3, $t8, 0x4
    ctx->r7 = ADD32(ctx->r24, 0X4);
    after_3:
    // 0x808006A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808006AC: jal         0x80102424
    // 0x808006B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x808006B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808006B4: b           L_80800A0C
    // 0x808006B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x808006B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006BC:
    // 0x808006BC: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x808006C0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x808006C4: addiu       $a1, $zero, 0x1009
    ctx->r5 = ADD32(0, 0X1009);
    // 0x808006C8: blez        $t0, L_80800714
    if (SIGNED(ctx->r8) <= 0) {
        // 0x808006CC: addiu       $a2, $zero, 0xE
        ctx->r6 = ADD32(0, 0XE);
            goto L_80800714;
    }
    // 0x808006CC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808006D0: jal         0x800D1A04
    // 0x808006D4: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    func_800D1A04(rdram, ctx);
        goto after_5;
    // 0x808006D4: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_5:
    // 0x808006D8: bgtz        $v0, L_80800704
    if (SIGNED(ctx->r2) > 0) {
        // 0x808006DC: lw          $t1, 0x30($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X30);
            goto L_80800704;
    }
    // 0x808006DC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x808006E0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x808006E4: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x808006E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808006EC: addiu       $a1, $zero, 0x100A
    ctx->r5 = ADD32(0, 0X100A);
    // 0x808006F0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808006F4: jal         0x8008A208
    // 0x808006F8: addiu       $a3, $t1, 0x4
    ctx->r7 = ADD32(ctx->r9, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808006F8: addiu       $a3, $t1, 0x4
    ctx->r7 = ADD32(ctx->r9, 0X4);
    after_6:
    // 0x808006FC: b           L_80800A0C
    // 0x80800700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800704:
    // 0x80800704: jal         0x80800078
    // 0x80800708: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800078_chcaptainblubber(rdram, ctx);
        goto after_7;
    // 0x80800708: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8080070C: b           L_80800A0C
    // 0x80800710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800714:
    // 0x80800714: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800718: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x8080071C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800720: jal         0x8008A208
    // 0x80800724: addiu       $a3, $t3, 0x4
    ctx->r7 = ADD32(ctx->r11, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800724: addiu       $a3, $t3, 0x4
    ctx->r7 = ADD32(ctx->r11, 0X4);
    after_8:
    // 0x80800728: b           L_80800A0C
    // 0x8080072C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x8080072C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800730:
    // 0x80800730: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800734: jal         0x80102424
    // 0x80800738: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800738: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8080073C: b           L_80800A0C
    // 0x80800740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800744:
    // 0x80800744: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80800748: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8080074C: addiu       $a1, $zero, 0x103F
    ctx->r5 = ADD32(0, 0X103F);
    // 0x80800750: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80800754: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800758: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x8080075C: jal         0x8008A208
    // 0x80800760: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800760: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    after_10:
    // 0x80800764: jal         0x800DA544
    // 0x80800768: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x80800768: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    after_11:
    // 0x8080076C: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x80800770: jal         0x800D175C
    // 0x80800774: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800D175C(rdram, ctx);
        goto after_12;
    // 0x80800774: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_12:
    // 0x80800778: b           L_80800A0C
    // 0x8080077C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x8080077C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800780:
    // 0x80800780: b           L_80800A0C
    // 0x80800784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800788:
    // 0x80800788: b           L_80800A0C
    // 0x8080078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x8080078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800790:
    // 0x80800790: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x80800794: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80800798: addiu       $at, $zero, 0x1006
    ctx->r1 = ADD32(0, 0X1006);
    // 0x8080079C: beq         $v0, $at, L_808007BC
    if (ctx->r2 == ctx->r1) {
        // 0x808007A0: addiu       $at, $zero, 0x1007
        ctx->r1 = ADD32(0, 0X1007);
            goto L_808007BC;
    }
    // 0x808007A0: addiu       $at, $zero, 0x1007
    ctx->r1 = ADD32(0, 0X1007);
    // 0x808007A4: beq         $v0, $at, L_808007BC
    if (ctx->r2 == ctx->r1) {
        // 0x808007A8: addiu       $at, $zero, 0x1008
        ctx->r1 = ADD32(0, 0X1008);
            goto L_808007BC;
    }
    // 0x808007A8: addiu       $at, $zero, 0x1008
    ctx->r1 = ADD32(0, 0X1008);
    // 0x808007AC: beq         $v0, $at, L_808007BC
    if (ctx->r2 == ctx->r1) {
        // 0x808007B0: addiu       $at, $zero, 0x106B
        ctx->r1 = ADD32(0, 0X106B);
            goto L_808007BC;
    }
    // 0x808007B0: addiu       $at, $zero, 0x106B
    ctx->r1 = ADD32(0, 0X106B);
    // 0x808007B4: bne         $v0, $at, L_808007C4
    if (ctx->r2 != ctx->r1) {
        // 0x808007B8: nop
    
            goto L_808007C4;
    }
    // 0x808007B8: nop

L_808007BC:
    // 0x808007BC: b           L_80800A0C
    // 0x808007C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x808007C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007C4:
    // 0x808007C4: b           L_80800A0C
    // 0x808007C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x808007C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007CC:
    // 0x808007CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X15E4) << 16);
    // 0x808007D0: jal         0x80085728
    // 0x808007D4: lwc1        $f12, 0x15E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15E4));
    _capod_entrypoint_17(rdram, ctx);
        goto after_13;
    // 0x808007D4: lwc1        $f12, 0x15E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15E4));
    after_13:
    // 0x808007D8: beq         $v0, $zero, L_808007E8
    if (ctx->r2 == 0) {
        // 0x808007DC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808007E8;
    }
    // 0x808007DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808007E0: jal         0x80108B04
    // 0x808007E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_14;
    // 0x808007E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
L_808007E8:
    // 0x808007E8: b           L_80800A0C
    // 0x808007EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800A0C;
    // 0x808007EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808007F0:
    // 0x808007F0: jal         0x80085710
    // 0x808007F4: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_15;
    // 0x808007F4: nop

    after_15:
    // 0x808007F8: jal         0x800C064C
    // 0x808007FC: nop

    func_800C064C(rdram, ctx);
        goto after_16;
    // 0x808007FC: nop

    after_16:
    // 0x80800800: beq         $v0, $zero, L_80800828
    if (ctx->r2 == 0) {
        // 0x80800804: addiu       $a0, $zero, 0x6B
        ctx->r4 = ADD32(0, 0X6B);
            goto L_80800828;
    }
    // 0x80800804: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    // 0x80800808: jal         0x800C01A8
    // 0x8080080C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_17;
    // 0x8080080C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800810: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800814: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800818: addiu       $a3, $zero, 0x2011
    ctx->r7 = ADD32(0, 0X2011);
    // 0x8080081C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800820: jal         0x80085748
    // 0x80800824: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_21(rdram, ctx);
        goto after_18;
    // 0x80800824: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_18:
L_80800828:
    // 0x80800828: b           L_80800A0C
    // 0x8080082C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800A0C;
    // 0x8080082C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800830:
    // 0x80800830: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x80800834: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80800838: addiu       $at, $zero, 0x100B
    ctx->r1 = ADD32(0, 0X100B);
    // 0x8080083C: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    // 0x80800840: beq         $v0, $at, L_80800858
    if (ctx->r2 == ctx->r1) {
        // 0x80800844: addiu       $at, $zero, 0x103F
        ctx->r1 = ADD32(0, 0X103F);
            goto L_80800858;
    }
    // 0x80800844: addiu       $at, $zero, 0x103F
    ctx->r1 = ADD32(0, 0X103F);
    // 0x80800848: beq         $v0, $at, L_80800888
    if (ctx->r2 == ctx->r1) {
        // 0x8080084C: lw          $t9, 0x30($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X30);
            goto L_80800888;
    }
    // 0x8080084C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800850: b           L_80800A0C
    // 0x80800854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800858:
    // 0x80800858: jal         0x800C01A8
    // 0x8080085C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_19;
    // 0x8080085C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80800860: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800864: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800868: addiu       $a3, $zero, 0x6010
    ctx->r7 = ADD32(0, 0X6010);
    // 0x8080086C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800870: jal         0x80085708
    // 0x80800874: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_20;
    // 0x80800874: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_20:
    // 0x80800878: jal         0x800FC6B0
    // 0x8080087C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_21;
    // 0x8080087C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_21:
    // 0x80800880: b           L_80800A0C
    // 0x80800884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800888:
    // 0x80800888: lbu         $t1, 0x65($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X65);
    // 0x8080088C: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80800890: sb          $t2, 0x65($t9)
    MEM_B(0X65, ctx->r25) = ctx->r10;
    // 0x80800894: b           L_80800A0C
    // 0x80800898: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800898: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080089C:
    // 0x8080089C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x808008A0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2228, 0X16D8) << 16);
    // 0x808008A4: addiu       $a0, $a0, 0x16D8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2228, 0X16D8));
    // 0x808008A8: jal         0x80088090
    // 0x808008AC: lw          $a1, 0x38($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x808008AC: lw          $a1, 0x38($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X38);
    after_22:
    // 0x808008B0: b           L_80800A0C
    // 0x808008B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x808008B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008B8:
    // 0x808008B8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x808008BC: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
    // 0x808008C0: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x808008C4: lwc1        $f4, 0x54($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X54);
    // 0x808008C8: addiu       $a1, $t4, 0x18
    ctx->r5 = ADD32(ctx->r12, 0X18);
    // 0x808008CC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808008D0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808008D4: jal         0x80108528
    // 0x808008D8: nop

    func_80108528(rdram, ctx);
        goto after_23;
    // 0x808008D8: nop

    after_23:
    // 0x808008DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808008E0: lhu         $t6, 0x76($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X76);
    // 0x808008E4: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x808008E8: ori         $t8, $t7, 0x1980
    ctx->r24 = ctx->r15 | 0X1980;
    // 0x808008EC: jal         0x800DB9B0
    // 0x808008F0: sh          $t8, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r24;
    func_800DB9B0(rdram, ctx);
        goto after_24;
    // 0x808008F0: sh          $t8, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r24;
    after_24:
    // 0x808008F4: beq         $v0, $zero, L_8080090C
    if (ctx->r2 == 0) {
        // 0x808008F8: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_8080090C;
    }
    // 0x808008F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808008FC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80800900: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800904: jal         0x800862D8
    // 0x80800908: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_25;
    // 0x80800908: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_25:
L_8080090C:
    // 0x8080090C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800910: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80800914: beq         $t0, $zero, L_80800924
    if (ctx->r8 == 0) {
        // 0x80800918: nop
    
            goto L_80800924;
    }
    // 0x80800918: nop

    // 0x8080091C: jal         0x800FFA88
    // 0x80800920: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_26;
    // 0x80800920: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_26:
L_80800924:
    // 0x80800924: b           L_80800A0C
    // 0x80800928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080092C:
    // 0x8080092C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800930: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x80800934: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80800938: lhu         $v0, 0x72($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X72);
    // 0x8080093C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800944: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x80800948: beq         $t3, $at, L_80800964
    if (ctx->r11 == ctx->r1) {
        // 0x8080094C: addiu       $a0, $zero, 0xDF
        ctx->r4 = ADD32(0, 0XDF);
            goto L_80800964;
    }
    // 0x8080094C: addiu       $a0, $zero, 0xDF
    ctx->r4 = ADD32(0, 0XDF);
    // 0x80800950: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800954: beq         $t3, $at, L_808009C8
    if (ctx->r11 == ctx->r1) {
        // 0x80800958: addiu       $t4, $zero, 0x4E
        ctx->r12 = ADD32(0, 0X4E);
            goto L_808009C8;
    }
    // 0x80800958: addiu       $t4, $zero, 0x4E
    ctx->r12 = ADD32(0, 0X4E);
    // 0x8080095C: b           L_808009D0
    // 0x80800960: nop

        goto L_808009D0;
    // 0x80800960: nop

L_80800964:
    // 0x80800964: jal         0x800DA298
    // 0x80800968: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_27;
    // 0x80800968: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_27:
    // 0x8080096C: beq         $v0, $zero, L_8080097C
    if (ctx->r2 == 0) {
        // 0x80800970: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_8080097C;
    }
    // 0x80800970: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800974: b           L_808009D0
    // 0x80800978: addiu       $a1, $zero, 0x1007
    ctx->r5 = ADD32(0, 0X1007);
        goto L_808009D0;
    // 0x80800978: addiu       $a1, $zero, 0x1007
    ctx->r5 = ADD32(0, 0X1007);
L_8080097C:
    // 0x8080097C: addiu       $a0, $zero, 0xDF
    ctx->r4 = ADD32(0, 0XDF);
    // 0x80800980: jal         0x800DA544
    // 0x80800984: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800DA544(rdram, ctx);
        goto after_28;
    // 0x80800984: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_28:
    // 0x80800988: jal         0x800F54E4
    // 0x8080098C: nop

    func_800F54E4(rdram, ctx);
        goto after_29;
    // 0x8080098C: nop

    after_29:
    // 0x80800990: jal         0x800F5410
    // 0x80800994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_30;
    // 0x80800994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
    // 0x80800998: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080099C: beq         $v0, $at, L_808009B8
    if (ctx->r2 == ctx->r1) {
        // 0x808009A0: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_808009B8;
    }
    // 0x808009A0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808009A4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808009A8: beq         $v0, $at, L_808009C0
    if (ctx->r2 == ctx->r1) {
        // 0x808009AC: nop
    
            goto L_808009C0;
    }
    // 0x808009AC: nop

    // 0x808009B0: b           L_808009D0
    // 0x808009B4: nop

        goto L_808009D0;
    // 0x808009B4: nop

L_808009B8:
    // 0x808009B8: b           L_808009D0
    // 0x808009BC: addiu       $a1, $zero, 0x1006
    ctx->r5 = ADD32(0, 0X1006);
        goto L_808009D0;
    // 0x808009BC: addiu       $a1, $zero, 0x1006
    ctx->r5 = ADD32(0, 0X1006);
L_808009C0:
    // 0x808009C0: b           L_808009D0
    // 0x808009C4: addiu       $a1, $zero, 0x106B
    ctx->r5 = ADD32(0, 0X106B);
        goto L_808009D0;
    // 0x808009C4: addiu       $a1, $zero, 0x106B
    ctx->r5 = ADD32(0, 0X106B);
L_808009C8:
    // 0x808009C8: addiu       $a1, $zero, 0x1008
    ctx->r5 = ADD32(0, 0X1008);
    // 0x808009CC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
L_808009D0:
    // 0x808009D0: beq         $a1, $zero, L_808009F0
    if (ctx->r5 == 0) {
        // 0x808009D4: lw          $t5, 0x30($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X30);
            goto L_808009F0;
    }
    // 0x808009D4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x808009D8: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x808009DC: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x808009E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009E4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808009E8: jal         0x8008A208
    // 0x808009EC: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_31;
    // 0x808009EC: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    after_31:
L_808009F0:
    // 0x808009F0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x808009F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808009F8: lbu         $t8, 0x65($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X65);
    // 0x808009FC: andi        $t0, $t8, 0xFFEF
    ctx->r8 = ctx->r24 & 0XFFEF;
    // 0x80800A00: b           L_80800A0C
    // 0x80800A04: sb          $t0, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r8;
        goto L_80800A0C;
    // 0x80800A04: sb          $t0, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r8;
L_80800A08:
    // 0x80800A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A0C:
    // 0x80800A0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800A14: jr          $ra
    // 0x80800A18: nop

    return;
    // 0x80800A18: nop

;}
