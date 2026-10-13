#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bskazjump_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808001D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001E0: jal         0x8008CABC
    // 0x808001E4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001E4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x808001E8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808001EC: lw          $t6, 0x164($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X164);
    // 0x808001F0: beql        $t6, $zero, L_80800204
    if (ctx->r14 == 0) {
        // 0x808001F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800204;
    }
    goto skip_0;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001F8: jal         0x80083550
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazshock_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800204:
    // 0x80800204: jal         0x80095738
    // 0x80800208: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x80800208: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_2:
    // 0x8080020C: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x80800210: nop
    
            goto L_80800224;
    }
    // 0x80800210: nop

    // 0x80800214: jal         0x8009B7C0
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_3;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080021C: b           L_80800230
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800230;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800224:
    // 0x80800224: jal         0x800834B0
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800230:
    // 0x80800230: jal         0x8009BB24
    // 0x80800234: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_5;
    // 0x80800234: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x80091A30
    // 0x80800240: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_6;
    // 0x80800240: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x80800244: beq         $v0, $zero, L_80800270
    if (ctx->r2 == 0) {
        // 0x80800248: nop
    
            goto L_80800270;
    }
    // 0x80800248: nop

    // 0x8080024C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800250: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800254: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800258: nop

    // 0x8080025C: bc1f        L_80800270
    if (!c1cs) {
        // 0x80800260: nop
    
            goto L_80800270;
    }
    // 0x80800260: nop

    // 0x80800264: lw          $t7, 0x164($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X164);
    // 0x80800268: beq         $t7, $zero, L_80800280
    if (ctx->r15 == 0) {
        // 0x8080026C: nop
    
            goto L_80800280;
    }
    // 0x8080026C: nop

L_80800270:
    // 0x80800270: jal         0x8008D544
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D544(rdram, ctx);
        goto after_7;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800278: bnel        $v0, $zero, L_8080028C
    if (ctx->r2 != 0) {
        // 0x8080027C: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_8080028C;
    }
    goto skip_1;
    // 0x8080027C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_1:
L_80800280:
    // 0x80800280: jal         0x8009BC6C
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_8;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800288: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_8080028C:
    // 0x8080028C: beq         $v0, $zero, L_808002AC
    if (ctx->r2 == 0) {
        // 0x80800290: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808002AC;
    }
    // 0x80800290: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800294: beq         $v0, $at, L_80800304
    if (ctx->r2 == ctx->r1) {
        // 0x80800298: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800304;
    }
    // 0x80800298: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080029C: beql        $v0, $at, L_8080035C
    if (ctx->r2 == ctx->r1) {
        // 0x808002A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080035C;
    }
    goto skip_2;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808002A4: b           L_8080035C
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080035C;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002AC:
    // 0x808002AC: jal         0x8008B324
    // 0x808002B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_9;
    // 0x808002B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x808002B4: beq         $v0, $zero, L_808002D4
    if (ctx->r2 == 0) {
        // 0x808002B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002D4;
    }
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: lui         $a1, 0x3F2A
    ctx->r5 = S32(0X3F2A << 16);
    // 0x808002C0: ori         $a1, $a1, 0xACDA
    ctx->r5 = ctx->r5 | 0XACDA;
    // 0x808002C4: jal         0x8008CF1C
    // 0x808002C8: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_10;
    // 0x808002C8: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_10:
    // 0x808002CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808002D0: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_808002D4:
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: jal         0x8008DF8C
    // 0x808002DC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_11;
    // 0x808002DC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_11:
    // 0x808002E0: beq         $v0, $zero, L_80800358
    if (ctx->r2 == 0) {
        // 0x808002E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800358;
    }
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x808002EC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808002F0: jal         0x8008CF1C
    // 0x808002F4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_12;
    // 0x808002F4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_12:
    // 0x808002F8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808002FC: b           L_80800358
    // 0x80800300: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
        goto L_80800358;
    // 0x80800300: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
L_80800304:
    // 0x80800304: jal         0x8008CAEC
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_13;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080030C: beq         $v0, $zero, L_8080031C
    if (ctx->r2 == 0) {
        // 0x80800310: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080031C;
    }
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: addiu       $t0, $zero, 0xDF
    ctx->r8 = ADD32(0, 0XDF);
    // 0x80800318: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_8080031C:
    // 0x8080031C: lw          $t1, 0x164($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X164);
    // 0x80800320: addiu       $t2, $zero, 0xC3
    ctx->r10 = ADD32(0, 0XC3);
    // 0x80800324: beq         $t1, $zero, L_80800334
    if (ctx->r9 == 0) {
        // 0x80800328: nop
    
            goto L_80800334;
    }
    // 0x80800328: nop

    // 0x8080032C: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    // 0x80800330: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80800334:
    // 0x80800334: jal         0x8008DF8C
    // 0x80800338: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_14;
    // 0x80800338: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_14:
    // 0x8080033C: beq         $v0, $zero, L_80800358
    if (ctx->r2 == 0) {
        // 0x80800340: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800358;
    }
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800348: jal         0x8008CF1C
    // 0x8080034C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_15;
    // 0x8080034C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_15:
    // 0x80800350: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80800354: sw          $t3, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r11;
L_80800358:
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080035C:
    // 0x8080035C: jal         0x80091A30
    // 0x80800360: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_16;
    // 0x80800360: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_16:
    // 0x80800364: beq         $v0, $zero, L_80800370
    if (ctx->r2 == 0) {
        // 0x80800368: nop
    
            goto L_80800370;
    }
    // 0x80800368: nop

    // 0x8080036C: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
L_80800370:
    // 0x80800370: jal         0x80097D9C
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_feathery_flap(rdram, ctx);
        goto after_17;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800378: beq         $v0, $zero, L_80800384
    if (ctx->r2 == 0) {
        // 0x8080037C: addiu       $t4, $zero, 0x15C
        ctx->r12 = ADD32(0, 0X15C);
            goto L_80800384;
    }
    // 0x8080037C: addiu       $t4, $zero, 0x15C
    ctx->r12 = ADD32(0, 0X15C);
    // 0x80800380: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80800384:
    // 0x80800384: jal         0x80097FB8
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097FB8(rdram, ctx);
        goto after_18;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080038C: beq         $v0, $zero, L_80800398
    if (ctx->r2 == 0) {
        // 0x80800390: addiu       $t5, $zero, 0xC4
        ctx->r13 = ADD32(0, 0XC4);
            goto L_80800398;
    }
    // 0x80800390: addiu       $t5, $zero, 0xC4
    ctx->r13 = ADD32(0, 0XC4);
    // 0x80800394: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_80800398:
    // 0x80800398: jal         0x80097E74
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097E74(rdram, ctx);
        goto after_19;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808003A0: beq         $v0, $zero, L_808003CC
    if (ctx->r2 == 0) {
        // 0x808003A4: nop
    
            goto L_808003CC;
    }
    // 0x808003A4: nop

    // 0x808003A8: jal         0x8009BB50
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_20;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808003B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808003B4: addiu       $t6, $zero, 0xBE
    ctx->r14 = ADD32(0, 0XBE);
    // 0x808003B8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808003BC: nop

    // 0x808003C0: bc1f        L_808003CC
    if (!c1cs) {
        // 0x808003C4: nop
    
            goto L_808003CC;
    }
    // 0x808003C4: nop

    // 0x808003C8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_808003CC:
    // 0x808003CC: jal         0x8008E078
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_21;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808003D4: beql        $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x808003D8: lwc1        $f10, 0x28($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800420;
    }
    goto skip_3;
    // 0x808003D8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    skip_3:
    // 0x808003DC: jal         0x8009FE58
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_22;
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808003E4: jal         0x8009EF10
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_23;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808003EC: bne         $v0, $zero, L_808003FC
    if (ctx->r2 != 0) {
        // 0x808003F0: addiu       $t7, $zero, 0xDE
        ctx->r15 = ADD32(0, 0XDE);
            goto L_808003FC;
    }
    // 0x808003F0: addiu       $t7, $zero, 0xDE
    ctx->r15 = ADD32(0, 0XDE);
    // 0x808003F4: b           L_8080041C
    // 0x808003F8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_8080041C;
    // 0x808003F8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_808003FC:
    // 0x808003FC: jal         0x8008E39C
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E39C(rdram, ctx);
        goto after_24;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800404: beq         $v0, $zero, L_80800418
    if (ctx->r2 == 0) {
        // 0x80800408: addiu       $t9, $zero, 0xBC
        ctx->r25 = ADD32(0, 0XBC);
            goto L_80800418;
    }
    // 0x80800408: addiu       $t9, $zero, 0xBC
    ctx->r25 = ADD32(0, 0XBC);
    // 0x8080040C: addiu       $t8, $zero, 0xC7
    ctx->r24 = ADD32(0, 0XC7);
    // 0x80800410: b           L_8080041C
    // 0x80800414: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_8080041C;
    // 0x80800414: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80800418:
    // 0x80800418: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_8080041C:
    // 0x8080041C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
L_80800420:
    // 0x80800420: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800424: nop

    // 0x80800428: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8080042C: nop

    // 0x80800430: bc1fl       L_80800450
    if (!c1cs) {
        // 0x80800434: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800450;
    }
    goto skip_4;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800438: jal         0x8008E35C
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_25;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800440: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x80800444: addiu       $t0, $zero, 0x160
        ctx->r8 = ADD32(0, 0X160);
            goto L_8080044C;
    }
    // 0x80800444: addiu       $t0, $zero, 0x160
    ctx->r8 = ADD32(0, 0X160);
    // 0x80800448: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_8080044C:
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800450:
    // 0x80800450: jal         0x8009E5C8
    // 0x80800454: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_26;
    // 0x80800454: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_26:
    // 0x80800458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080045C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800460: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void _inantab_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F70: syscall     750
    recomp_syscall_handler(rdram, ctx, 0x80088F70);
    return;
    // 0x80088F74: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80805380_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805380: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80805384: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80805388: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8080538C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80805390: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80805394: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80805398: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8080539C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x808053A0: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x808053A4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x808053A8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808053AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808053B0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808053B4: jal         0x800D8FEC
    // 0x808053B8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_800D8FEC(rdram, ctx);
        goto after_0;
    // 0x808053B8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808053BC: beq         $v0, $zero, L_80805464
    if (ctx->r2 == 0) {
        // 0x808053C0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80805464;
    }
    // 0x808053C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808053C4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA470) << 16);
    // 0x808053C8: lwc1        $f30, -0x5B90($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA470));
    // 0x808053CC: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x808053D0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808053D4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x808053D8: nop

L_808053DC:
    // 0x808053DC: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808053E0: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x808053E4: jal         0x80013728
    // 0x808053E8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x808053E8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x808053EC: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808053F0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808053F4: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808053F8: c.eq.s      $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f24.fl == ctx->f2.fl;
    // 0x808053FC: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x80805400: bc1t        L_80805444
    if (c1cs) {
        // 0x80805404: nop
    
            goto L_80805444;
    }
    // 0x80805404: nop

    // 0x80805408: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    // 0x8080540C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80805410: bc1fl       L_80805434
    if (!c1cs) {
        // 0x80805414: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_80805434;
    }
    goto skip_0;
    // 0x80805414: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_0:
    // 0x80805418: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8080541C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80805420: jal         0x800F0D50
    // 0x80805424: neg.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = -ctx->f26.fl;
    func_800F0D50(rdram, ctx);
        goto after_2;
    // 0x80805424: neg.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = -ctx->f26.fl;
    after_2:
    // 0x80805428: b           L_80805444
    // 0x8080542C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_80805444;
    // 0x8080542C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80805430: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_80805434:
    // 0x80805434: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80805438: jal         0x800F0D50
    // 0x8080543C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800F0D50(rdram, ctx);
        goto after_3;
    // 0x8080543C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x80805440: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80805444:
    // 0x80805444: mul.s       $f12, $f20, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80805448: jal         0x800F212C
    // 0x8080544C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800F212C(rdram, ctx);
        goto after_4;
    // 0x8080544C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_4:
    // 0x80805450: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80805454: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80805458: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8080545C: bne         $s0, $zero, L_808053DC
    if (ctx->r16 != 0) {
        // 0x80805460: swc1        $f16, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
            goto L_808053DC;
    }
    // 0x80805460: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
L_80805464:
    // 0x80805464: jal         0x80013728
    // 0x80805468: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    func_80013728(rdram, ctx);
        goto after_5;
    // 0x80805468: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x8080546C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x80805470: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80805474: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80805478: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8080547C: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80805480: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80805484: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80805488: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8080548C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80805490: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80805494: jr          $ra
    // 0x80805498: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80805498: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _bskazglide_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833E0: syscall     59
    recomp_syscall_handler(rdram, ctx, 0x800833E0);
    return;
    // 0x800833E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _mlwave_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FA8: syscall     754
    recomp_syscall_handler(rdram, ctx, 0x80088FA8);
    return;
    // 0x80088FAC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800244_bskazspring(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080024C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800250: jal         0x80800064
    // 0x80800254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800064_bskazspring(rdram, ctx);
        goto after_0;
    // 0x80800254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800258: jal         0x800832E8
    // 0x8080025C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080025C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800268: jr          $ra
    // 0x8080026C: nop

    return;
    // 0x8080026C: nop

;}
RECOMP_FUNC void func_808019A4_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019A4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808019A8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x808019AC: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x808019B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808019B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808019B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808019BC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x808019C0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808019C4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808019C8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808019CC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808019D0: jal         0x80100094
    // 0x808019D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808019D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808019D8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808019DC: jal         0x800EFD24
    // 0x808019E0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x808019E0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808019E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019E8: jal         0x80100094
    // 0x808019EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808019EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808019F0: beq         $v0, $zero, L_80801A1C
    if (ctx->r2 == 0) {
        // 0x808019F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A1C;
    }
    // 0x808019F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019F8: jal         0x80100094
    // 0x808019FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808019FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801A00: jal         0x80089890
    // 0x80801A04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80801A04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80801A08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801A0C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80801A10: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801A14: jal         0x800DF5D8
    // 0x80801A18: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800DF5D8(rdram, ctx);
        goto after_5;
    // 0x80801A18: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_5:
L_80801A1C:
    // 0x80801A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A20: jal         0x80101870
    // 0x80801A24: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_80101870(rdram, ctx);
        goto after_6;
    // 0x80801A24: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_6:
    // 0x80801A28: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80801A2C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801A30: addiu       $a2, $s4, 0x14
    ctx->r6 = ADD32(ctx->r20, 0X14);
    // 0x80801A34: jal         0x800DBEFC
    // 0x80801A38: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_7;
    // 0x80801A38: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_7:
    // 0x80801A3C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80801A40: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801A44: addiu       $a2, $s4, 0x8
    ctx->r6 = ADD32(ctx->r20, 0X8);
    // 0x80801A48: jal         0x800DBEFC
    // 0x80801A4C: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_8;
    // 0x80801A4C: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_8:
    // 0x80801A50: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80801A54: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80801A58: addiu       $a2, $s4, 0x20
    ctx->r6 = ADD32(ctx->r20, 0X20);
    // 0x80801A5C: jal         0x800DBEFC
    // 0x80801A60: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_9;
    // 0x80801A60: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    after_9:
    // 0x80801A64: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80801A68: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80801A6C: addiu       $a2, $s4, 0x2C
    ctx->r6 = ADD32(ctx->r20, 0X2C);
    // 0x80801A70: jal         0x800DBEFC
    // 0x80801A74: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_10;
    // 0x80801A74: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    after_10:
    // 0x80801A78: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80801A7C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80801A80: addiu       $a2, $s4, 0x4C
    ctx->r6 = ADD32(ctx->r20, 0X4C);
    // 0x80801A84: jal         0x800DBEFC
    // 0x80801A88: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_11;
    // 0x80801A88: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    after_11:
    // 0x80801A8C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80801A90: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80801A94: addiu       $a2, $s4, 0x58
    ctx->r6 = ADD32(ctx->r20, 0X58);
    // 0x80801A98: jal         0x800DBEFC
    // 0x80801A9C: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_12;
    // 0x80801A9C: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    after_12:
    // 0x80801AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AA4: jal         0x80100094
    // 0x80801AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_13;
    // 0x80801AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80801AAC: beq         $v0, $zero, L_80801AC8
    if (ctx->r2 == 0) {
        // 0x80801AB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801AC8;
    }
    // 0x80801AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AB4: jal         0x80100094
    // 0x80801AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_14;
    // 0x80801AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80801ABC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801AC0: jal         0x80089880
    // 0x80801AC4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_15;
    // 0x80801AC4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_15:
L_80801AC8:
    // 0x80801AC8: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    // 0x80801ACC: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80801AD0: slti        $at, $t3, 0x6
    ctx->r1 = SIGNED(ctx->r11) < 0X6 ? 1 : 0;
    // 0x80801AD4: bnel        $at, $zero, L_80801B68
    if (ctx->r1 != 0) {
        // 0x80801AD8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80801B68;
    }
    goto skip_0;
    // 0x80801AD8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80801ADC: jal         0x800E2588
    // 0x80801AE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_16;
    // 0x80801AE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80801AE4: jal         0x800D674C
    // 0x80801AE8: lw          $a0, 0x2A8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X2A8);
    func_800D674C(rdram, ctx);
        goto after_17;
    // 0x80801AE8: lw          $a0, 0x2A8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X2A8);
    after_17:
    // 0x80801AEC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80801AF0: jal         0x800E2594
    // 0x80801AF4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E2594(rdram, ctx);
        goto after_18;
    // 0x80801AF4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_18:
    // 0x80801AF8: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80801AFC: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x80801B00: addiu       $s3, $s4, 0xDC
    ctx->r19 = ADD32(ctx->r20, 0XDC);
    // 0x80801B04: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x80801B08: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801B0C: addiu       $s5, $zero, 0x78
    ctx->r21 = ADD32(0, 0X78);
L_80801B10:
    // 0x80801B10: lwc1        $f4, 0x244($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X244);
    // 0x80801B14: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80801B18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801B1C: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x80801B20: lwc1        $f6, 0x244($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X244);
    // 0x80801B24: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80801B28: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x80801B2C: lwc1        $f8, 0x244($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X244);
    // 0x80801B30: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x80801B34: lbu         $a1, 0x26C($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X26C);
    // 0x80801B38: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80801B3C: lw          $t4, 0x27C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X27C);
    // 0x80801B40: jal         0x800E2720
    // 0x80801B44: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_800E2720(rdram, ctx);
        goto after_19;
    // 0x80801B44: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_19:
    // 0x80801B48: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80801B4C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801B50: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801B54: bne         $s2, $s5, L_80801B10
    if (ctx->r18 != ctx->r21) {
        // 0x80801B58: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_80801B10;
    }
    // 0x80801B58: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x80801B5C: jal         0x800E2A14
    // 0x80801B60: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800E2A14(rdram, ctx);
        goto after_20;
    // 0x80801B60: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_20:
    // 0x80801B64: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80801B68:
    // 0x80801B68: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801B6C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80801B70: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80801B74: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80801B78: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80801B7C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80801B80: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80801B84: jr          $ra
    // 0x80801B88: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80801B88: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void sumole_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080211C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802124: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80802128: jal         0x800C6E18
    // 0x8080212C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800C6E18(rdram, ctx);
        goto after_0;
    // 0x8080212C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80802130: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80802134: beq         $v0, $zero, L_80802164
    if (ctx->r2 == 0) {
        // 0x80802138: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80802164;
    }
    // 0x80802138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080213C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80802140: beq         $v1, $at, L_8080215C
    if (ctx->r3 == ctx->r1) {
        // 0x80802144: nop
    
            goto L_8080215C;
    }
    // 0x80802144: nop

    // 0x80802148: lbu         $t9, 0x72($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X72);
    // 0x8080214C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80802150: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x80802154: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80802158: sb          $t1, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r9;
L_8080215C:
    // 0x8080215C: b           L_80802168
    // 0x80802160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802168;
    // 0x80802160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802164:
    // 0x80802164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802168:
    // 0x80802168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080216C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802170: jr          $ra
    // 0x80802174: nop

    return;
    // 0x80802174: nop

;}
RECOMP_FUNC void func_808002AC_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808002B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002B8: jal         0x80800680
    // 0x808002BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800680_chhoneyb(rdram, ctx);
        goto after_0;
    // 0x808002BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808002C4: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x808002C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808002D0: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x808002D4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808002D8: jal         0x80089F20
    // 0x808002DC: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808002DC: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_1:
    // 0x808002E0: jal         0x80800B2C
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B2C_chhoneyb(rdram, ctx);
        goto after_2;
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002E8: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x808002EC: srl         $t7, $a0, 10
    ctx->r15 = S32(U32(ctx->r4) >> 10);
    // 0x808002F0: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x808002F4: jal         0x8008FBE0
    // 0x808002F8: sltiu       $a0, $t8, 0x1
    ctx->r4 = ctx->r24 < 0X1 ? 1 : 0;
    func_8008FBE0(rdram, ctx);
        goto after_3;
    // 0x808002F8: sltiu       $a0, $t8, 0x1
    ctx->r4 = ctx->r24 < 0X1 ? 1 : 0;
    after_3:
    // 0x808002FC: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800300: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800304: srl         $t9, $v1, 10
    ctx->r25 = S32(U32(ctx->r3) >> 10);
    // 0x80800308: beq         $t9, $at, L_80800334
    if (ctx->r25 == ctx->r1) {
        // 0x8080030C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800334;
    }
    // 0x8080030C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800310: beq         $t9, $at, L_808004F4
    if (ctx->r25 == ctx->r1) {
        // 0x80800314: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808004F4;
    }
    // 0x80800314: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800318: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080031C: beq         $t9, $at, L_80800468
    if (ctx->r25 == ctx->r1) {
        // 0x80800320: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800468;
    }
    // 0x80800320: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800324: beq         $t9, $at, L_808004B4
    if (ctx->r25 == ctx->r1) {
        // 0x80800328: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004B4;
    }
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080032C: b           L_8080061C
    // 0x80800330: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080061C;
    // 0x80800330: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800334:
    // 0x80800334: jal         0x80088848
    // 0x80800338: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800338: nop

    after_4:
    // 0x8080033C: bnel        $v0, $zero, L_80800394
    if (ctx->r2 != 0) {
        // 0x80800340: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800394;
    }
    goto skip_0;
    // 0x80800340: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80800344: jal         0x800D1824
    // 0x80800348: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    func_800D1824(rdram, ctx);
        goto after_5;
    // 0x80800348: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_5:
    // 0x8080034C: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
    // 0x80800350: bnel        $t0, $zero, L_80800394
    if (ctx->r8 != 0) {
        // 0x80800354: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800394;
    }
    goto skip_1;
    // 0x80800354: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80800358: jal         0x80800B78
    // 0x8080035C: nop

    func_80800B78_chhoneyb(rdram, ctx);
        goto after_6;
    // 0x8080035C: nop

    after_6:
    // 0x80800360: jal         0x80088400
    // 0x80800364: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    _gcextra_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800364: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_7:
    // 0x80800368: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8080036C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800370: beql        $at, $zero, L_80800394
    if (ctx->r1 == 0) {
        // 0x80800374: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800394;
    }
    goto skip_2;
    // 0x80800374: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80800378: jal         0x80800C0C
    // 0x8080037C: nop

    func_80800C0C_chhoneyb(rdram, ctx);
        goto after_8;
    // 0x8080037C: nop

    after_8:
    // 0x80800380: addiu       $a0, $zero, 0x107
    ctx->r4 = ADD32(0, 0X107);
    // 0x80800384: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800388: jal         0x800D2498
    // 0x8080038C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_9;
    // 0x8080038C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80800390: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800394:
    // 0x80800394: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x80800398: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8080039C: jal         0x8008A1D8
    // 0x808003A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_5(rdram, ctx);
        goto after_10;
    // 0x808003A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x808003A4: beql        $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x808003A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080061C;
    }
    goto skip_3;
    // 0x808003A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x808003AC: jal         0x80800B78
    // 0x808003B0: nop

    func_80800B78_chhoneyb(rdram, ctx);
        goto after_11;
    // 0x808003B0: nop

    after_11:
    // 0x808003B4: jal         0x80088400
    // 0x808003B8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    _gcextra_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x808003B8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_12:
    // 0x808003BC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808003C8: bne         $at, $zero, L_80800408
    if (ctx->r1 != 0) {
        // 0x808003CC: nop
    
            goto L_80800408;
    }
    // 0x808003CC: nop

    // 0x808003D0: jal         0x80100094
    // 0x808003D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_13;
    // 0x808003D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808003E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808003E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808003E8: jal         0x8008A2C8
    // 0x808003EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_14;
    // 0x808003EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_14:
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: addiu       $a1, $zero, 0x1521
    ctx->r5 = ADD32(0, 0X1521);
    // 0x808003F8: jal         0x80800018
    // 0x808003FC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800018_chhoneyb(rdram, ctx);
        goto after_15;
    // 0x808003FC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_15:
    // 0x80800400: b           L_8080061C
    // 0x80800404: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080061C;
    // 0x80800404: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800408:
    // 0x80800408: jal         0x800DA298
    // 0x8080040C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_16;
    // 0x8080040C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x80800410: beq         $v0, $zero, L_80800430
    if (ctx->r2 == 0) {
        // 0x80800414: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800430;
    }
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: addiu       $a1, $zero, 0x1519
    ctx->r5 = ADD32(0, 0X1519);
    // 0x80800420: jal         0x80800744
    // 0x80800424: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800744_chhoneyb(rdram, ctx);
        goto after_17;
    // 0x80800424: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80800428: b           L_8080061C
    // 0x8080042C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080061C;
    // 0x8080042C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800430:
    // 0x80800430: jal         0x80100094
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_18;
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080043C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800440: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800444: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800448: jal         0x8008A2C8
    // 0x8080044C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_19;
    // 0x8080044C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_19:
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: addiu       $a1, $zero, 0x1519
    ctx->r5 = ADD32(0, 0X1519);
    // 0x80800458: jal         0x80800018
    // 0x8080045C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800018_chhoneyb(rdram, ctx);
        goto after_20;
    // 0x8080045C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_20:
    // 0x80800460: b           L_8080061C
    // 0x80800464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080061C;
    // 0x80800464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800468:
    // 0x80800468: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80800474: bgezl       $t3, L_8080061C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800478: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080061C;
    }
    goto skip_4;
    // 0x80800478: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8080047C: jal         0x80100094
    // 0x80800480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_21;
    // 0x80800480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080048C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800490: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800494: jal         0x8008A2C8
    // 0x80800498: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_22;
    // 0x80800498: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_22:
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A0: addiu       $a1, $zero, 0x1518
    ctx->r5 = ADD32(0, 0X1518);
    // 0x808004A4: jal         0x80800018
    // 0x808004A8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800018_chhoneyb(rdram, ctx);
        goto after_23;
    // 0x808004A8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_23:
    // 0x808004AC: b           L_8080061C
    // 0x808004B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080061C;
    // 0x808004B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004B4:
    // 0x808004B4: jal         0x80103DFC
    // 0x808004B8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80103DFC(rdram, ctx);
        goto after_24;
    // 0x808004B8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_24:
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: jal         0x80100094
    // 0x808004C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_25;
    // 0x808004C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808004D0: jal         0x80089FE8
    // 0x808004D4: addiu       $a2, $v0, 0x18
    ctx->r6 = ADD32(ctx->r2, 0X18);
    _subaddieitem_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x808004D4: addiu       $a2, $v0, 0x18
    ctx->r6 = ADD32(ctx->r2, 0X18);
    after_26:
    // 0x808004D8: beq         $v0, $zero, L_80800618
    if (ctx->r2 == 0) {
        // 0x808004DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800618;
    }
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: addiu       $a1, $zero, 0x1553
    ctx->r5 = ADD32(0, 0X1553);
    // 0x808004E4: jal         0x80800018
    // 0x808004E8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800018_chhoneyb(rdram, ctx);
        goto after_27;
    // 0x808004E8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_27:
    // 0x808004EC: b           L_8080061C
    // 0x808004F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080061C;
    // 0x808004F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004F4:
    // 0x808004F4: jal         0x800FA9F4
    // 0x808004F8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    func_800FA9F4(rdram, ctx);
        goto after_28;
    // 0x808004F8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    after_28:
    // 0x808004FC: addiu       $a0, $zero, 0x119
    ctx->r4 = ADD32(0, 0X119);
    // 0x80800500: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80800504: jal         0x800D2498
    // 0x80800508: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    func_800D2498(rdram, ctx);
        goto after_29;
    // 0x80800508: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    after_29:
    // 0x8080050C: jal         0x800D27F4
    // 0x80800510: addiu       $a0, $zero, 0x119
    ctx->r4 = ADD32(0, 0X119);
    func_800D27F4(rdram, ctx);
        goto after_30;
    // 0x80800510: addiu       $a0, $zero, 0x119
    ctx->r4 = ADD32(0, 0X119);
    after_30:
    // 0x80800514: beq         $v0, $zero, L_80800618
    if (ctx->r2 == 0) {
        // 0x80800518: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800618;
    }
    // 0x80800518: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080051C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800520: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800524: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80800528: nop

    // 0x8080052C: bc1f        L_808005B4
    if (!c1cs) {
        // 0x80800530: nop
    
            goto L_808005B4;
    }
    // 0x80800530: nop

    // 0x80800534: jal         0x800D8FF8
    // 0x80800538: nop

    func_800D8FF8(rdram, ctx);
        goto after_31;
    // 0x80800538: nop

    after_31:
    // 0x8080053C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800540: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800544: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800548: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080054C: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800550: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800554: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800558: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080055C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800560: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x80800564: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800568: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x8080056C: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800570: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80800574: nop

    // 0x80800578: bc1f        L_808005B4
    if (!c1cs) {
        // 0x8080057C: nop
    
            goto L_808005B4;
    }
    // 0x8080057C: nop

    // 0x80800580: lw          $t4, 0x30($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X30);
    // 0x80800584: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800588: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080058C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800590: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800594: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x80800598: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8080059C: jal         0x800F10B4
    // 0x808005A0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_32;
    // 0x808005A0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_32:
    // 0x808005A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005A8: addiu       $a0, $zero, 0x66C
    ctx->r4 = ADD32(0, 0X66C);
    // 0x808005AC: jal         0x800C3FC0
    // 0x808005B0: addiu       $a2, $zero, 0x7D00
    ctx->r6 = ADD32(0, 0X7D00);
    func_800C3FC0(rdram, ctx);
        goto after_33;
    // 0x808005B0: addiu       $a2, $zero, 0x7D00
    ctx->r6 = ADD32(0, 0X7D00);
    after_33:
L_808005B4:
    // 0x808005B4: jal         0x800D9078
    // 0x808005B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_34;
    // 0x808005B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_34:
    // 0x808005BC: beql        $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x808005C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080061C;
    }
    goto skip_5;
    // 0x808005C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x808005C4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x808005C8: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x808005CC: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x808005D0: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x808005D4: bnel        $at, $zero, L_80800604
    if (ctx->r1 != 0) {
        // 0x808005D8: lui         $at, 0x3F40
        ctx->r1 = S32(0X3F40 << 16);
            goto L_80800604;
    }
    goto skip_6;
    // 0x808005D8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    skip_6:
    // 0x808005DC: jal         0x8080062C
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080062C_chhoneyb(rdram, ctx);
        goto after_35;
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808005E4: jal         0x80090708
    // 0x808005E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_36;
    // 0x808005E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_36:
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: jal         0x80102424
    // 0x808005F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_37;
    // 0x808005F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x808005F8: b           L_8080061C
    // 0x808005FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080061C;
    // 0x808005FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800600: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
L_80800604:
    // 0x80800604: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800608: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080060C: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
    // 0x80800610: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x80800614: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80800618:
    // 0x80800618: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080061C:
    // 0x8080061C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800620: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800624: jr          $ra
    // 0x80800628: nop

    return;
    // 0x80800628: nop

;}
RECOMP_FUNC void scinfobar_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F0: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x808004F4: beql        $t6, $zero, L_80800508
    if (ctx->r14 == 0) {
        // 0x808004F8: sw          $a1, 0x20($a0)
        MEM_W(0X20, ctx->r4) = ctx->r5;
            goto L_80800508;
    }
    goto skip_0;
    // 0x808004F8: sw          $a1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r5;
    skip_0:
    // 0x808004FC: jr          $ra
    // 0x80800500: sh          $a1, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r5;
    return;
    // 0x80800500: sh          $a1, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r5;
    // 0x80800504: sw          $a1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r5;
L_80800508:
    // 0x80800508: jr          $ra
    // 0x8080050C: nop

    return;
    // 0x8080050C: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080074C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800750: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800754: jal         0x8008CABC
    // 0x80800758: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800758: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080075C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800760: jal         0x8008AF24
    // 0x80800764: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800764: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800768: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080076C: jal         0x8008AED4
    // 0x80800770: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800770: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    after_2:
    // 0x80800774: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800778: jal         0x8008B134
    // 0x8080077C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_3;
    // 0x8080077C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800780: jal         0x8008B064
    // 0x80800784: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_start(rdram, ctx);
        goto after_4;
    // 0x80800784: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800788: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080078C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800790: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800794: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800798: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080079C: jal         0x8009FFD8
    // 0x808007A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_5;
    // 0x808007A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x808007A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(104, 0X1460) << 16);
    // 0x808007A8: lwc1        $f4, 0x1460($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0X1460));
    // 0x808007AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007B0: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x808007B4: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x808007B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808007BC: jal         0x8008C9F0
    // 0x808007C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_6;
    // 0x808007C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x808007C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007CC: jr          $ra
    // 0x808007D0: nop

    return;
    // 0x808007D0: nop

;}
RECOMP_FUNC void func_808003EC_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003F0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808003F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003F8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808003FC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(208, 0X121C) << 16);
    // 0x80800400: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800404: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800408: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080040C: addiu       $t6, $t6, 0x121C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(208, 0X121C));
    // 0x80800410: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800414: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800418: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080041C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800420: jal         0x800BABB8
    // 0x80800424: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x80800424: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800428: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(208, 0X1248) << 16);
    // 0x8080042C: addiu       $t7, $t7, 0x1248
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(208, 0X1248));
    // 0x80800430: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800434: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080043C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800440: jal         0x800BABB8
    // 0x80800444: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800444: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800448: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(208, 0X1274) << 16);
    // 0x8080044C: addiu       $t8, $t8, 0x1274
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(208, 0X1274));
    // 0x80800450: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800454: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800458: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080045C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800460: jal         0x800BABB8
    // 0x80800464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800468: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(208, 0X12B8) << 16);
    // 0x8080046C: addiu       $t9, $t9, 0x12B8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(208, 0X12B8));
    // 0x80800470: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800474: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080047C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800480: jal         0x800BABB8
    // 0x80800484: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80800484: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800488: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(208, 0X12D0) << 16);
    // 0x8080048C: addiu       $t0, $t0, 0x12D0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(208, 0X12D0));
    // 0x80800490: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800494: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800498: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080049C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004A0: jal         0x800BABB8
    // 0x808004A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x808004A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808004A8: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(208, 0X12F0) << 16);
    // 0x808004AC: addiu       $t1, $t1, 0x12F0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(208, 0X12F0));
    // 0x808004B0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808004B4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808004B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004C0: jal         0x800BABB8
    // 0x808004C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x808004C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x808004C8: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(208, 0X1334) << 16);
    // 0x808004CC: addiu       $t2, $t2, 0x1334
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(208, 0X1334));
    // 0x808004D0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808004D4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808004D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004E0: jal         0x800BABB8
    // 0x808004E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x808004E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808004E8: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(208, 0X134C) << 16);
    // 0x808004EC: addiu       $t3, $t3, 0x134C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(208, 0X134C));
    // 0x808004F0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808004F4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808004F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800500: jal         0x800BABB8
    // 0x80800504: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800504: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080050C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800510: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800514: jr          $ra
    // 0x80800518: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800518: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bsbtrot_entrypoint_39(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080236C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80802370: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2EE0) << 16);
    // 0x80802374: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80802378: jr          $ra
    // 0x8080237C: lw          $v0, 0x2EE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2EE0));
    return;
    // 0x8080237C: lw          $v0, 0x2EE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2EE0));
;}
RECOMP_FUNC void badata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007BC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808007C0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808007C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808007C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007CC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X2018) << 16);
    // 0x808007D0: jal         0x808006AC
    // 0x808007D4: addiu       $a1, $a1, 0x2018
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X2018));
    func_808006AC_badata(rdram, ctx);
        goto after_0;
    // 0x808007D4: addiu       $a1, $a1, 0x2018
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X2018));
    after_0:
    // 0x808007D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007E0: jr          $ra
    // 0x808007E4: nop

    return;
    // 0x808007E4: nop

;}
RECOMP_FUNC void chtempleinternaldoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2188, 0X1C0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2188, 0X1C0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2188, 0X1C0));
;}
RECOMP_FUNC void func_80800118_ncpodfixpos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080011C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800120: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800124: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800128: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080012C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800130: bne         $a2, $at, L_80800154
    if (ctx->r6 != ctx->r1) {
        // 0x80800134: sw          $a2, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->r6;
            goto L_80800154;
    }
    // 0x80800134: sw          $a2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r6;
    // 0x80800138: jal         0x800A5800
    // 0x8080013C: lh          $a0, 0x38($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X38);
    func_800A5800(rdram, ctx);
        goto after_0;
    // 0x8080013C: lh          $a0, 0x38($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X38);
    after_0:
    // 0x80800140: jal         0x80085580
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800148: jal         0x80085590
    // 0x8080014C: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080014C: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_2:
    // 0x80800150: sb          $zero, 0x42($s0)
    MEM_B(0X42, ctx->r16) = 0;
L_80800154:
    // 0x80800154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800158: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080015C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void func_800D8854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8854: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D8858: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D885C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D8860: lbu         $v0, -0x469F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X469F);
    // 0x800D8864: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800D8868: jr          $ra
    // 0x800D886C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800D886C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
;}
RECOMP_FUNC void func_80800EE8_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EF0: jal         0x80800508
    // 0x80800EF4: nop

    func_80800508_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x80800EF4: nop

    after_0:
    // 0x80800EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F00: jr          $ra
    // 0x80800F04: nop

    return;
    // 0x80800F04: nop

;}
RECOMP_FUNC void func_8080024C_chgobiwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800254: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800258: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080025C: jal         0x80085750
    // 0x80800260: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _capod_entrypoint_22(rdram, ctx);
        goto after_0;
    // 0x80800260: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800264: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800268: addiu       $at, $zero, 0x107B
    ctx->r1 = ADD32(0, 0X107B);
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800270: bne         $t6, $at, L_808002C4
    if (ctx->r14 != ctx->r1) {
        // 0x80800274: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002C4;
    }
    // 0x80800274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800278: jal         0x80100094
    // 0x8080027C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080027C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800280: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800288: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080028C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800290: jal         0x800897E8
    // 0x80800294: nop

    _suexpression_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800294: nop

    after_2:
    // 0x80800298: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080029C: jal         0x80101FDC
    // 0x808002A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808002A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x808002A4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808002A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808002B0: addiu       $a3, $zero, 0x2031
    ctx->r7 = ADD32(0, 0X2031);
    // 0x808002B4: jal         0x80085708
    // 0x808002B8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x808002B8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_4:
    // 0x808002BC: b           L_808002D0
    // 0x808002C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002D0;
    // 0x808002C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002C4:
    // 0x808002C4: jal         0x80101FDC
    // 0x808002C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x808002C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002D0:
    // 0x808002D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void func_808031C8_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808031C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808031CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808031D0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808031D4: jal         0x800D731C
    // 0x808031D8: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    func_800D731C(rdram, ctx);
        goto after_0;
    // 0x808031D8: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    after_0:
    // 0x808031DC: beq         $v0, $zero, L_80803214
    if (ctx->r2 == 0) {
        // 0x808031E0: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_80803214;
    }
    // 0x808031E0: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808031E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808031E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808031EC: jal         0x800DBE60
    // 0x808031F0: sb          $a0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r4;
    func_800DBE60(rdram, ctx);
        goto after_1;
    // 0x808031F0: sb          $a0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r4;
    after_1:
    // 0x808031F4: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x808031F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808031FC: jal         0x800DBE60
    // 0x80803200: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800DBE60(rdram, ctx);
        goto after_2;
    // 0x80803200: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80803204: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x80803208: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080320C: jal         0x800DBE60
    // 0x80803210: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800DBE60(rdram, ctx);
        goto after_3;
    // 0x80803210: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
L_80803214:
    // 0x80803214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080321C: jr          $ra
    // 0x80803220: nop

    return;
    // 0x80803220: nop

;}
RECOMP_FUNC void ncfixposrot_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800268: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080026C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800270: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800274: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800278: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080027C: jal         0x8010F9C0
    // 0x80800280: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8010F9C0(rdram, ctx);
        goto after_0;
    // 0x80800280: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800284: jal         0x8011001C
    // 0x80800288: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8011001C(rdram, ctx);
        goto after_1;
    // 0x80800288: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080028C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800294: jal         0x800EE7F8
    // 0x80800298: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800298: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8080029C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A0: jal         0x80800060
    // 0x808002A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    ncfixposrot_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808002A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002B0: jr          $ra
    // 0x808002B4: nop

    return;
    // 0x808002B4: nop

;}
RECOMP_FUNC void chegggrenade_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800398: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080039C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003A4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808003A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808003AC: jal         0x8008A488
    // 0x808003B0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808003B0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808003B4: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    // 0x808003B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003BC: jal         0x8008A3D0
    // 0x808003C0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _suegg_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808003C0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808003C4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808003C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003D8: jal         0x8008A460
    // 0x808003DC: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    _sueggmove_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808003DC: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x808003E0: lui         $a2, 0xC7C3
    ctx->r6 = S32(0XC7C3 << 16);
    // 0x808003E4: ori         $a2, $a2, 0x5000
    ctx->r6 = ctx->r6 | 0X5000;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: jal         0x8008A468
    // 0x808003F0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808003F0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: jal         0x8008A380
    // 0x808003FC: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _suegg_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808003FC: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_4:
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: jal         0x8008A470
    // 0x80800408: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sueggmove_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80800408: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x8080040C: lbu         $t6, 0x72($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X72);
    // 0x80800410: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800414: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x80800418: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x8080041C: sb          $t8, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r24;
    // 0x80800420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800424: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800428: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080042C: jr          $ra
    // 0x80800430: nop

    return;
    // 0x80800430: nop

    // 0x80800434: nop

    // 0x80800438: nop

    // 0x8080043C: nop

;}
RECOMP_FUNC void func_80801408_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801408: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080140C: slti        $at, $a1, 0x17B8
    ctx->r1 = SIGNED(ctx->r5) < 0X17B8 ? 1 : 0;
    // 0x80801410: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801414: bne         $at, $zero, L_80801444
    if (ctx->r1 != 0) {
        // 0x80801418: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80801444;
    }
    // 0x80801418: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080141C: addiu       $at, $zero, 0x17DF
    ctx->r1 = ADD32(0, 0X17DF);
    // 0x80801420: beq         $a1, $at, L_80801524
    if (ctx->r5 == ctx->r1) {
        // 0x80801424: addiu       $a0, $zero, 0x2F
        ctx->r4 = ADD32(0, 0X2F);
            goto L_80801524;
    }
    // 0x80801424: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x80801428: addiu       $at, $zero, 0x17FC
    ctx->r1 = ADD32(0, 0X17FC);
    // 0x8080142C: beq         $a1, $at, L_8080159C
    if (ctx->r5 == ctx->r1) {
        // 0x80801430: addiu       $at, $zero, 0x1801
        ctx->r1 = ADD32(0, 0X1801);
            goto L_8080159C;
    }
    // 0x80801430: addiu       $at, $zero, 0x1801
    ctx->r1 = ADD32(0, 0X1801);
    // 0x80801434: beql        $a1, $at, L_80801490
    if (ctx->r5 == ctx->r1) {
        // 0x80801438: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801490;
    }
    goto skip_0;
    // 0x80801438: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x8080143C: b           L_80801584
    // 0x80801440: nop

        goto L_80801584;
    // 0x80801440: nop

L_80801444:
    // 0x80801444: slti        $at, $a1, 0x120C
    ctx->r1 = SIGNED(ctx->r5) < 0X120C ? 1 : 0;
    // 0x80801448: bne         $at, $zero, L_80801470
    if (ctx->r1 != 0) {
        // 0x8080144C: addiu       $t6, $a1, -0x17B3
        ctx->r14 = ADD32(ctx->r5, -0X17B3);
            goto L_80801470;
    }
    // 0x8080144C: addiu       $t6, $a1, -0x17B3
    ctx->r14 = ADD32(ctx->r5, -0X17B3);
    // 0x80801450: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80801454: beq         $at, $zero, L_80801584
    if (ctx->r1 == 0) {
        // 0x80801458: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801584;
    }
    // 0x80801458: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080145C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X2A00) << 16);
    // 0x80801460: addu        $at, $at, $t6
    gpr jr_addend_80801468 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801464: lw          $t6, 0x2A00($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1060, 0X2A00));
    // 0x80801468: jr          $t6
    // 0x8080146C: nop

    switch (jr_addend_80801468 >> 2) {
        case 0: goto L_8080148C; break;
        case 1: goto L_8080159C; break;
        case 2: goto L_8080159C; break;
        case 3: goto L_808014AC; break;
        case 4: goto L_80801508; break;
        default: switch_error(__func__, 0x80801468, 0x80802A00);
    }
    // 0x8080146C: nop

L_80801470:
    // 0x80801470: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80801474: beq         $a1, $at, L_8080155C
    if (ctx->r5 == ctx->r1) {
        // 0x80801478: addiu       $at, $zero, 0x120B
        ctx->r1 = ADD32(0, 0X120B);
            goto L_8080155C;
    }
    // 0x80801478: addiu       $at, $zero, 0x120B
    ctx->r1 = ADD32(0, 0X120B);
    // 0x8080147C: beql        $a1, $at, L_8080150C
    if (ctx->r5 == ctx->r1) {
        // 0x80801480: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080150C;
    }
    goto skip_1;
    // 0x80801480: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80801484: b           L_80801584
    // 0x80801488: nop

        goto L_80801584;
    // 0x80801488: nop

L_8080148C:
    // 0x8080148C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80801490:
    // 0x80801490: jal         0x80800F70
    // 0x80801494: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_0;
    // 0x80801494: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80801498: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8080149C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808014A0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808014A4: b           L_8080159C
    // 0x808014A8: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
        goto L_8080159C;
    // 0x808014A8: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
L_808014AC:
    // 0x808014AC: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x808014B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808014B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808014B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808014BC: jal         0x800D1000
    // 0x808014C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_1;
    // 0x808014C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x808014C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808014C8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x808014CC: jal         0x8080248C
    // 0x808014D0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_2;
    // 0x808014D0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x808014D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808014D8: jal         0x80800F70
    // 0x808014DC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_3;
    // 0x808014DC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x808014E0: addiu       $a0, $zero, 0x461
    ctx->r4 = ADD32(0, 0X461);
    // 0x808014E4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808014E8: jal         0x80101180
    // 0x808014EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_4;
    // 0x808014EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808014F0: addiu       $a0, $zero, 0x469
    ctx->r4 = ADD32(0, 0X469);
    // 0x808014F4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808014F8: jal         0x80101180
    // 0x808014FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x808014FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80801500: b           L_808015A0
    // 0x80801504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808015A0;
    // 0x80801504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801508:
    // 0x80801508: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8080150C:
    // 0x8080150C: jal         0x80800F70
    // 0x80801510: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_6;
    // 0x80801510: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_6:
    // 0x80801514: jal         0x80085710
    // 0x80801518: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_7;
    // 0x80801518: nop

    after_7:
    // 0x8080151C: b           L_808015A0
    // 0x80801520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808015A0;
    // 0x80801520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801524:
    // 0x80801524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080152C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801530: jal         0x800D1000
    // 0x80801534: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_8;
    // 0x80801534: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80801538: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080153C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80801540: jal         0x8080248C
    // 0x80801544: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_9;
    // 0x80801544: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_9:
    // 0x80801548: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080154C: jal         0x80102424
    // 0x80801550: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x80801550: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_10:
    // 0x80801554: b           L_808015A0
    // 0x80801558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808015A0;
    // 0x80801558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080155C:
    // 0x8080155C: blez        $a2, L_80801574
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80801560: nop
    
            goto L_80801574;
    }
    // 0x80801560: nop

    // 0x80801564: jal         0x80088188
    // 0x80801568: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80801568: nop

    after_11:
    // 0x8080156C: b           L_808015A0
    // 0x80801570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808015A0;
    // 0x80801570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801574:
    // 0x80801574: jal         0x80088180
    // 0x80801578: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_12;
    // 0x80801578: nop

    after_12:
    // 0x8080157C: b           L_808015A0
    // 0x80801580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808015A0;
    // 0x80801580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801584:
    // 0x80801584: jal         0x800DA298
    // 0x80801588: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80801588: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    after_13:
    // 0x8080158C: beq         $v0, $zero, L_8080159C
    if (ctx->r2 == 0) {
        // 0x80801590: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080159C;
    }
    // 0x80801590: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801594: jal         0x80800F70
    // 0x80801598: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_14;
    // 0x80801598: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_14:
L_8080159C:
    // 0x8080159C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808015A0:
    // 0x808015A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808015A4: jr          $ra
    // 0x808015A8: nop

    return;
    // 0x808015A8: nop

;}
RECOMP_FUNC void idflash_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800008: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080000C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800010: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80800014: sll         $t8, $a3, 4
    ctx->r24 = S32(ctx->r7 << 4);
    // 0x80800018: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x8080001C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800020: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80800024: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800028: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8080002C: beq         $at, $zero, L_80800098
    if (ctx->r1 == 0) {
        // 0x80800030: nop
    
            goto L_80800098;
    }
    // 0x80800030: nop

L_80800034:
    // 0x80800034: lbu         $t9, 0xC($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XC);
    // 0x80800038: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
    // 0x8080003C: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x80800040: bnel        $at, $zero, L_80800050
    if (ctx->r1 != 0) {
        // 0x80800044: sb          $a0, 0xC($a2)
        MEM_B(0XC, ctx->r6) = ctx->r4;
            goto L_80800050;
    }
    goto skip_0;
    // 0x80800044: sb          $a0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r4;
    skip_0:
    // 0x80800048: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8080004C: sb          $a0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r4;
L_80800050:
    // 0x80800050: lbu         $t0, 0xD($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XD);
    // 0x80800054: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    // 0x80800058: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8080005C: bnel        $at, $zero, L_8080006C
    if (ctx->r1 != 0) {
        // 0x80800060: sb          $a0, 0xD($a2)
        MEM_B(0XD, ctx->r6) = ctx->r4;
            goto L_8080006C;
    }
    goto skip_1;
    // 0x80800060: sb          $a0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r4;
    skip_1:
    // 0x80800064: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80800068: sb          $a0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r4;
L_8080006C:
    // 0x8080006C: lbu         $t1, 0xE($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XE);
    // 0x80800070: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80800074: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    // 0x80800078: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8080007C: bnel        $at, $zero, L_8080008C
    if (ctx->r1 != 0) {
        // 0x80800080: sltu        $at, $a1, $v1
        ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
            goto L_8080008C;
    }
    goto skip_2;
    // 0x80800080: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    skip_2:
    // 0x80800084: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80800088: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
L_8080008C:
    // 0x8080008C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800090: bne         $at, $zero, L_80800034
    if (ctx->r1 != 0) {
        // 0x80800094: sb          $a0, -0x2($a2)
        MEM_B(-0X2, ctx->r6) = ctx->r4;
            goto L_80800034;
    }
    // 0x80800094: sb          $a0, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r4;
L_80800098:
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void func_8008D714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D71C: jal         0x80084930
    // 0x8008D720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baduo_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8008D720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008D724: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D728: beq         $t6, $zero, L_8008D740
    if (ctx->r14 == 0) {
        // 0x8008D72C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D740;
    }
    // 0x8008D72C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D730: jal         0x800A3304
    // 0x8008D734: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D734: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008D738: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D73C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008D740:
    // 0x8008D740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D748: jr          $ra
    // 0x8008D74C: nop

    return;
    // 0x8008D74C: nop

;}
RECOMP_FUNC void func_808000E8_chwandglow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000F4: lw          $a1, 0x6C($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X6C);
    // 0x808000F8: lw          $t9, 0x30($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X30);
    // 0x808000FC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800100: andi        $t6, $a1, 0x1FF
    ctx->r14 = ctx->r5 & 0X1FF;
    // 0x80800104: jalr        $t9
    // 0x80800108: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80800108: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x8080010C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void chquicksandbaddy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801254: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1896, 0X13D8) << 16);
    // 0x80801258: jr          $ra
    // 0x8080125C: addiu       $v0, $v0, 0x13D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1896, 0X13D8));
    return;
    // 0x8080125C: addiu       $v0, $v0, 0x13D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1896, 0X13D8));
;}
RECOMP_FUNC void func_80800128_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080012C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800130: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800134: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800138: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080013C: jal         0x80082840
    // 0x80800140: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800140: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x8009D3A8
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800150: jal         0x8008DD04
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_2;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800158: beq         $v0, $zero, L_80800164
    if (ctx->r2 == 0) {
        // 0x8080015C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800164;
    }
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: addiu       $s1, $zero, 0x88
    ctx->r17 = ADD32(0, 0X88);
L_80800164:
    // 0x80800164: jal         0x800919F4
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_3;
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080016C: beq         $v0, $zero, L_8080017C
    if (ctx->r2 == 0) {
        // 0x80800170: nop
    
            goto L_8080017C;
    }
    // 0x80800170: nop

    // 0x80800174: jal         0x80084550
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babee_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8080017C:
    // 0x8080017C: jal         0x80097AD0
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_5;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800184: beq         $v0, $zero, L_80800198
    if (ctx->r2 == 0) {
        // 0x80800188: nop
    
            goto L_80800198;
    }
    // 0x80800188: nop

    // 0x8080018C: jal         0x800848A8
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_6;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800194: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80800198:
    // 0x80800198: jal         0x8009EF10
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_7;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001A0: blez        $v0, L_808001AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808001A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001AC;
    }
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: addiu       $s1, $zero, 0x86
    ctx->r17 = ADD32(0, 0X86);
L_808001AC:
    // 0x808001AC: jal         0x80091A58
    // 0x808001B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_8;
    // 0x808001B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x808001B4: beq         $v0, $zero, L_808001C0
    if (ctx->r2 == 0) {
        // 0x808001B8: nop
    
            goto L_808001C0;
    }
    // 0x808001B8: nop

    // 0x808001BC: addiu       $s1, $zero, 0x87
    ctx->r17 = ADD32(0, 0X87);
L_808001C0:
    // 0x808001C0: jal         0x8008E35C
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_9;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001C8: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D4;
    }
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: addiu       $s1, $zero, 0x8C
    ctx->r17 = ADD32(0, 0X8C);
L_808001D4:
    // 0x808001D4: jal         0x800A02DC
    // 0x808001D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A02DC(rdram, ctx);
        goto after_10;
    // 0x808001D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: jal         0x8009E5C8
    // 0x808001E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x808001E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x808001E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808001F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808001F4: jr          $ra
    // 0x808001F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808001F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80801620_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801628: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080162C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801630: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801634: jal         0x800DF744
    // 0x80801638: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80801638: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x8080163C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80801640: jal         0x800DF744
    // 0x80801644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80801644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801648: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080164C: jal         0x800DF744
    // 0x80801650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80801650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801654: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801658: jal         0x800DF744
    // 0x8080165C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x8080165C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801664: jal         0x80101870
    // 0x80801668: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_4;
    // 0x80801668: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x8080166C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801674: jr          $ra
    // 0x80801678: nop

    return;
    // 0x80801678: nop

;}
RECOMP_FUNC void ncpoducam_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801654: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080165C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801660: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801664: lbu         $v0, 0x60($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X60);
    // 0x80801668: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080166C: beq         $v0, $at, L_808016A0
    if (ctx->r2 == ctx->r1) {
        // 0x80801670: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808016A0;
    }
    // 0x80801670: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80801674: beq         $v0, $at, L_808016A0
    if (ctx->r2 == ctx->r1) {
        // 0x80801678: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_808016A0;
    }
    // 0x80801678: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8080167C: bnel        $v0, $at, L_808016A4
    if (ctx->r2 != ctx->r1) {
        // 0x80801680: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808016A4;
    }
    goto skip_0;
    // 0x80801680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80801684: jal         0x8001B798
    // 0x80801688: lh          $a0, 0x2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80801688: lh          $a0, 0x2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2);
    after_0:
    // 0x8080168C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801690: jal         0x80089E40
    // 0x80801694: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _susplinet_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801694: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80801698: b           L_808016A8
    // 0x8080169C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808016A8;
    // 0x8080169C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808016A0:
    // 0x808016A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808016A4:
    // 0x808016A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808016A8:
    // 0x808016A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808016AC: jr          $ra
    // 0x808016B0: nop

    return;
    // 0x808016B0: nop

;}
RECOMP_FUNC void func_80800A1C_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A24: jal         0x800A587C
    // 0x80800A28: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x80800A28: nop

    after_0:
    // 0x80800A2C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800A30: bnel        $v0, $at, L_80800A4C
    if (ctx->r2 != ctx->r1) {
        // 0x80800A34: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800A4C;
    }
    goto skip_0;
    // 0x80800A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800A38: jal         0x800A586C
    // 0x80800A3C: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800A3C: nop

    after_1:
    // 0x80800A40: b           L_80800A50
    // 0x80800A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A50;
    // 0x80800A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A4C:
    // 0x80800A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A50:
    // 0x80800A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A54: jr          $ra
    // 0x80800A58: nop

    return;
    // 0x80800A58: nop

;}
RECOMP_FUNC void _bashoes_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085058: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085058);
    return;
    // 0x8008505C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80800000_bainvisible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080000C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800010: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
    // 0x80800014: lw          $v0, 0xA8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA8);
    // 0x80800018: sltiu       $at, $a2, 0x5
    ctx->r1 = ctx->r6 < 0X5 ? 1 : 0;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: addiu       $t6, $v0, 0x4C
    ctx->r14 = ADD32(ctx->r2, 0X4C);
    // 0x80800024: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800028: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8080002C: beq         $at, $zero, L_808001A8
    if (ctx->r1 == 0) {
        // 0x80800030: addiu       $s1, $v0, 0x1C
        ctx->r17 = ADD32(ctx->r2, 0X1C);
            goto L_808001A8;
    }
    // 0x80800030: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x80800034: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80800038: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(653, 0X990) << 16);
    // 0x8080003C: addu        $at, $at, $t7
    gpr jr_addend_80800044 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800040: lw          $t7, 0x990($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(653, 0X990));
    // 0x80800044: jr          $t7
    // 0x80800048: nop

    switch (jr_addend_80800044 >> 2) {
        case 0: goto L_8080004C; break;
        case 1: goto L_80800198; break;
        case 2: goto L_80800080; break;
        case 3: goto L_80800118; break;
        case 4: goto L_80800140; break;
        default: switch_error(__func__, 0x80800044, 0x80800990);
    }
    // 0x80800048: nop

L_8080004C:
    // 0x8080004C: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x80800050: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800054: bnel        $t8, $zero, L_808001AC
    if (ctx->r24 != 0) {
        // 0x80800058: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001AC;
    }
    goto skip_0;
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080005C: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800068: bnel        $t0, $zero, L_808001AC
    if (ctx->r8 != 0) {
        // 0x8080006C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001AC;
    }
    goto skip_1;
    // 0x8080006C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800070: jal         0x8009ADF0
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009ADF0(rdram, ctx);
        goto after_0;
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800078: b           L_808001AC
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001AC;
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800080:
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: jal         0x8009AD78
    // 0x80800088: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8009AD78(rdram, ctx);
        goto after_1;
    // 0x80800088: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x8080008C: bne         $v0, $zero, L_808001A8
    if (ctx->r2 != 0) {
        // 0x80800090: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001A8;
    }
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800098: jal         0x8009ADF0
    // 0x8080009C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_2;
    // 0x8080009C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x808000A0: lui         $a1, 0x443B
    ctx->r5 = S32(0X443B << 16);
    // 0x808000A4: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x80800410
    // 0x808000B0: lui         $a2, 0x4307
    ctx->r6 = S32(0X4307 << 16);
    bainvisible_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808000B0: lui         $a2, 0x4307
    ctx->r6 = S32(0X4307 << 16);
    after_3:
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x8009BC08
    // 0x808000BC: lw          $a1, 0xA8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XA8);
    func_8009BC08(rdram, ctx);
        goto after_4;
    // 0x808000BC: lw          $a1, 0xA8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XA8);
    after_4:
    // 0x808000C0: jal         0x8009C984
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_5;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808000D0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808000D4: lw          $t1, 0xA8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XA8);
    // 0x808000D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(653, 0X9A4) << 16);
    // 0x808000DC: lwc1        $f12, 0x9A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(653, 0X9A4));
    // 0x808000E0: swc1        $f0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f0.u32l;
    // 0x808000E4: sb          $zero, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = 0;
    // 0x808000E8: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
    // 0x808000EC: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x808000F0: sb          $zero, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = 0;
    // 0x808000F4: swc1        $f2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f2.u32l;
    // 0x808000F8: swc1        $f12, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f12.u32l;
    // 0x808000FC: lw          $t2, 0xA8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XA8);
    // 0x80800100: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: jal         0x808001BC
    // 0x8080010C: swc1        $f4, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f4.u32l;
    func_808001BC_bainvisible(rdram, ctx);
        goto after_6;
    // 0x8080010C: swc1        $f4, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f4.u32l;
    after_6:
    // 0x80800110: b           L_808001AC
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001AC;
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800118:
    // 0x80800118: bne         $a3, $s1, L_808001A8
    if (ctx->r7 != ctx->r17) {
        // 0x8080011C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808001A8;
    }
    // 0x8080011C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800120: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: addiu       $a1, $zero, 0x65E
    ctx->r5 = ADD32(0, 0X65E);
    // 0x8080012C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800130: jal         0x8009DBF0
    // 0x80800134: nop

    func_8009DBF0(rdram, ctx);
        goto after_7;
    // 0x80800134: nop

    after_7:
    // 0x80800138: b           L_808001AC
    // 0x8080013C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001AC;
    // 0x8080013C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800140:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800148: jal         0x8009AD78
    // 0x8080014C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8009AD78(rdram, ctx);
        goto after_8;
    // 0x8080014C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_8:
    // 0x80800150: bne         $v0, $zero, L_80800184
    if (ctx->r2 != 0) {
        // 0x80800154: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_80800184;
    }
    // 0x80800154: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800160: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800164: jal         0x8009ADF0
    // 0x80800168: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8009ADF0(rdram, ctx);
        goto after_9;
    // 0x80800168: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_9:
    // 0x8080016C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800170: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800174: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80800178: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080017C: swc1        $f2, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f2.u32l;
    // 0x80800180: swc1        $f2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f2.u32l;
L_80800184:
    // 0x80800184: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80800188: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080018C: swc1        $f6, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f6.u32l;
    // 0x80800190: b           L_808001A8
    // 0x80800194: swc1        $f8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f8.u32l;
        goto L_808001A8;
    // 0x80800194: swc1        $f8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f8.u32l;
L_80800198:
    // 0x80800198: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080019C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808001A0: sb          $zero, 0x1C($a3)
    MEM_B(0X1C, ctx->r7) = 0;
    // 0x808001A4: swc1        $f2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f2.u32l;
L_808001A8:
    // 0x808001A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001AC:
    // 0x808001AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808001B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808001B4: jr          $ra
    // 0x808001B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808001B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bstaxi_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EC0: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083EC0);
    return;
    // 0x80083EC4: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void chdragonbrothers_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803568: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1852, 0X56A8) << 16);
    // 0x8080356C: jr          $ra
    // 0x80803570: addiu       $v0, $v0, 0x56A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1852, 0X56A8));
    return;
    // 0x80803570: addiu       $v0, $v0, 0x56A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1852, 0X56A8));
;}
RECOMP_FUNC void _bsstand_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B50: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B50);
    return;
    // 0x80083B54: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808001D4_chtoxicroombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808001D8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x808001DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001F0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808001F4: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x808001F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001FC: lui         $a2, 0xC4FA
    ctx->r6 = S32(0XC4FA << 16);
    // 0x80800200: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800204: jal         0x800F10B4
    // 0x80800208: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80800208: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8080020C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800210: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800214: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80800218: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080021C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800220: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800224: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800228: jal         0x800138D0
    // 0x8080022C: nop

    func_800138D0(rdram, ctx);
        goto after_1;
    // 0x8080022C: nop

    after_1:
    // 0x80800230: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800234: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800238: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2308, 0XEE0) << 16);
    // 0x8080023C: lwc1        $f4, 0xEE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2308, 0XEE0));
    // 0x80800240: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800244: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800248: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080024C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80800250: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800254: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800258: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8080025C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800260: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800264: nop

    // 0x80800268: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080026C: jal         0x800138D0
    // 0x80800270: nop

    func_800138D0(rdram, ctx);
        goto after_2;
    // 0x80800270: nop

    after_2:
    // 0x80800274: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800278: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8080027C: jal         0x80101870
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101870(rdram, ctx);
        goto after_3;
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800284: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80800288: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x8080028C: bgezl       $t8, L_808003F4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800290: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003F4;
    }
    goto skip_0;
    // 0x80800290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800294: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800298: addiu       $at, $zero, 0x885
    ctx->r1 = ADD32(0, 0X885);
    // 0x8080029C: lhu         $t0, 0x14($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X14);
    // 0x808002A0: bnel        $t0, $at, L_808003F4
    if (ctx->r8 != ctx->r1) {
        // 0x808002A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003F4;
    }
    goto skip_1;
    // 0x808002A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808002A8: jal         0x800E3980
    // 0x808002AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800E3980(rdram, ctx);
        goto after_4;
    // 0x808002AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x808002B0: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x808002B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002B8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808002BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002C0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x808002C4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808002C8: nop

    // 0x808002CC: bc1f        L_808002EC
    if (!c1cs) {
        // 0x808002D0: nop
    
            goto L_808002EC;
    }
    // 0x808002D0: nop

    // 0x808002D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002D8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808002DC: jal         0x8008A0E0
    // 0x808002E0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808002E0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x808002E4: b           L_808002F4
    // 0x808002E8: nop

        goto L_808002F4;
    // 0x808002E8: nop

L_808002EC:
    // 0x808002EC: jal         0x8008A0E0
    // 0x808002F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808002F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
L_808002F4:
    // 0x808002F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2308, 0XEE4) << 16);
    // 0x808002F8: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808002FC: lwc1        $f8, 0xEE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2308, 0XEE4));
    // 0x80800300: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2308, 0XEE8) << 16);
    // 0x80800304: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800308: nop

    // 0x8080030C: bc1f        L_80800348
    if (!c1cs) {
        // 0x80800310: nop
    
            goto L_80800348;
    }
    // 0x80800310: nop

    // 0x80800314: lwc1        $f10, 0xEE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2308, 0XEE8));
    // 0x80800318: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080031C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800320: nop

    // 0x80800324: bc1f        L_80800348
    if (!c1cs) {
        // 0x80800328: nop
    
            goto L_80800348;
    }
    // 0x80800328: nop

    // 0x8080032C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800330: jal         0x800F2100
    // 0x80800334: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    mlAbsF(rdram, ctx);
        goto after_7;
    // 0x80800334: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    after_7:
    // 0x80800338: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080033C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800340: b           L_80800398
    // 0x80800344: div.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
        goto L_80800398;
    // 0x80800344: div.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
L_80800348:
    // 0x80800348: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2308, 0XEEC) << 16);
    // 0x8080034C: lwc1        $f4, 0xEEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2308, 0XEEC));
    // 0x80800350: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2308, 0XEF0) << 16);
    // 0x80800354: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800358: nop

    // 0x8080035C: bc1fl       L_808003F4
    if (!c1cs) {
        // 0x80800360: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003F4;
    }
    goto skip_2;
    // 0x80800360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800364: lwc1        $f6, 0xEF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2308, 0XEF0));
    // 0x80800368: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080036C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800370: nop

    // 0x80800374: bc1fl       L_808003F4
    if (!c1cs) {
        // 0x80800378: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003F4;
    }
    goto skip_3;
    // 0x80800378: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8080037C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800380: jal         0x800F2100
    // 0x80800384: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    mlAbsF(rdram, ctx);
        goto after_8;
    // 0x80800384: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    after_8:
    // 0x80800388: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080038C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800390: nop

    // 0x80800394: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
L_80800398:
    // 0x80800398: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080039C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808003A0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808003A4: sub.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x808003A8: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x808003AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003B4: jal         0x800EFA4C
    // 0x808003B8: nop

    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x808003B8: nop

    after_9:
    // 0x808003BC: jal         0x800E2588
    // 0x808003C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_10;
    // 0x808003C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x808003C4: jal         0x800D674C
    // 0x808003C8: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800D674C(rdram, ctx);
        goto after_11;
    // 0x808003C8: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_11:
    // 0x808003CC: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x808003D0: addiu       $t2, $sp, 0x34
    ctx->r10 = ADD32(ctx->r29, 0X34);
    // 0x808003D4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x808003D8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808003DC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808003E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808003E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003E8: jal         0x800E2AA4
    // 0x808003EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800E2AA4(rdram, ctx);
        goto after_12;
    // 0x808003EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x808003F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003F4:
    // 0x808003F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808003FC: jr          $ra
    // 0x80800400: nop

    return;
    // 0x80800400: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080084C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800850: jal         0x80800060
    // 0x80800854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800060_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x80800854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800858: jal         0x80082FE0
    // 0x8080085C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080085C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800868: jr          $ra
    // 0x8080086C: nop

    return;
    // 0x8080086C: nop

;}
RECOMP_FUNC void func_800CBAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBAC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CBACC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CBAD0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800CBAD4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800CBAD8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800CBADC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800CBAE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CBAE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CBAE8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CBAEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CBAF0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800CBAF4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800CBAF8: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    // 0x800CBAFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CBB00: jal         0x80087ED8
    // 0x800CBB04: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    _gcboundDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800CBB04: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x800CBB08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CBB0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CBB10: jr          $ra
    // 0x800CBB14: nop

    return;
    // 0x800CBB14: nop

;}
RECOMP_FUNC void func_80098840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80098844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098848: lw          $t6, 0xE0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE0);
    // 0x8009884C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80098850: sb          $zero, 0x2C($t6)
    MEM_B(0X2C, ctx->r14) = 0;
    // 0x80098854: lw          $a1, 0xE0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XE0);
    // 0x80098858: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8009885C: jal         0x800EE7F8
    // 0x80098860: addiu       $a0, $a1, 0x1C
    ctx->r4 = ADD32(ctx->r5, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80098860: addiu       $a0, $a1, 0x1C
    ctx->r4 = ADD32(ctx->r5, 0X1C);
    after_0:
    // 0x80098864: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80098868: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009886C: lwc1        $f4, 0x4E20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4E20);
    // 0x80098870: lw          $t7, 0xE0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XE0);
    // 0x80098874: swc1        $f4, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f4.u32l;
    // 0x80098878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009887C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098880: jr          $ra
    // 0x80098884: nop

    return;
    // 0x80098884: nop

    // 0x80098888: nop

    // 0x8009888C: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B10: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B10);
    return;
    // 0x80087B14: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void idwibble_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800708: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080070C: jal         0x800D8FF8
    // 0x80800710: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800710: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800714: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800718: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8080071C: addiu       $a2, $a2, -0x7190
    ctx->r6 = ADD32(ctx->r6, -0X7190);
    // 0x80800720: lwc1        $f6, 0x2C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x80800724: lwc1        $f4, 0x24($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80800728: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080072C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800730: swc1        $f10, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f10.u32l;
    // 0x80800734: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800738: jal         0x80088660
    // 0x8080073C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080073C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800748: jr          $ra
    // 0x8080074C: nop

    return;
    // 0x8080074C: nop

;}
RECOMP_FUNC void func_800BA730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA730: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BA734: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800BA738: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800BA73C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800BA740: sb          $t2, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r10;
    // 0x800BA744: sh          $a1, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r5;
    // 0x800BA748: sh          $a2, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r6;
    // 0x800BA74C: sh          $a3, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r7;
    // 0x800BA750: lh          $t3, 0x12($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X12);
    // 0x800BA754: jr          $ra
    // 0x800BA758: sh          $t3, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r11;
    return;
    // 0x800BA758: sh          $t3, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r11;
;}
RECOMP_FUNC void func_800CC078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC078: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800CC07C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800CC080: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800CC084: addiu       $s7, $s7, -0x5180
    ctx->r23 = ADD32(ctx->r23, -0X5180);
    // 0x800CC088: lw          $t6, 0x10($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X10);
    // 0x800CC08C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800CC090: addiu       $fp, $zero, 0x1C
    ctx->r30 = ADD32(0, 0X1C);
    // 0x800CC094: multu       $t6, $fp
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CC098: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800CC09C: lw          $s6, 0x14($s7)
    ctx->r22 = MEM_W(ctx->r23, 0X14);
    // 0x800CC0A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CC0A4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CC0A8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800CC0AC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800CC0B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800CC0B4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800CC0B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CC0BC: mflo        $t7
    ctx->r15 = lo;
    // 0x800CC0C0: addu        $t8, $t7, $s6
    ctx->r24 = ADD32(ctx->r15, ctx->r22);
    // 0x800CC0C4: sltu        $at, $s6, $t8
    ctx->r1 = ctx->r22 < ctx->r24 ? 1 : 0;
    // 0x800CC0C8: beq         $at, $zero, L_800CC304
    if (ctx->r1 == 0) {
        // 0x800CC0CC: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800CC304;
    }
    // 0x800CC0CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CC0D0: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x800CC0D4: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800CC0D8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800CC0DC: addiu       $a0, $s6, 0x4
    ctx->r4 = ADD32(ctx->r22, 0X4);
L_800CC0E0:
    // 0x800CC0E0: jal         0x800EFC7C
    // 0x800CC0E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_0;
    // 0x800CC0E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800CC0E8: lwc1        $f4, 0x10($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X10);
    // 0x800CC0EC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800CC0F0: nop

    // 0x800CC0F4: bc1fl       L_800CC2E4
    if (!c1cs) {
        // 0x800CC0F8: lw          $t2, 0x10($s7)
        ctx->r10 = MEM_W(ctx->r23, 0X10);
            goto L_800CC2E4;
    }
    goto skip_0;
    // 0x800CC0F8: lw          $t2, 0x10($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X10);
    skip_0:
    // 0x800CC0FC: jal         0x800CB910
    // 0x800CC100: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800CB910(rdram, ctx);
        goto after_1;
    // 0x800CC100: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x800CC104: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800CC108: jal         0x800CB8F0
    // 0x800CC10C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800CB8F0(rdram, ctx);
        goto after_2;
    // 0x800CC10C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x800CC110: sltu        $at, $v0, $s2
    ctx->r1 = ctx->r2 < ctx->r18 ? 1 : 0;
    // 0x800CC114: beq         $at, $zero, L_800CC2E0
    if (ctx->r1 == 0) {
        // 0x800CC118: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800CC2E0;
    }
    // 0x800CC118: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CC11C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_800CC120:
    // 0x800CC120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC124: sll         $t9, $v0, 12
    ctx->r25 = S32(ctx->r2 << 12);
    // 0x800CC128: srl         $t0, $t9, 29
    ctx->r8 = S32(U32(ctx->r25) >> 29);
    // 0x800CC12C: beq         $t0, $zero, L_800CC154
    if (ctx->r8 == 0) {
        // 0x800CC130: nop
    
            goto L_800CC154;
    }
    // 0x800CC130: nop

    // 0x800CC134: beql        $t0, $s3, L_800CC190
    if (ctx->r8 == ctx->r19) {
        // 0x800CC138: lh          $t3, 0xE($s0)
        ctx->r11 = MEM_H(ctx->r16, 0XE);
            goto L_800CC190;
    }
    goto skip_1;
    // 0x800CC138: lh          $t3, 0xE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XE);
    skip_1:
    // 0x800CC13C: beql        $t0, $s4, L_800CC20C
    if (ctx->r8 == ctx->r20) {
        // 0x800CC140: lh          $t6, 0xE($s0)
        ctx->r14 = MEM_H(ctx->r16, 0XE);
            goto L_800CC20C;
    }
    goto skip_2;
    // 0x800CC140: lh          $t6, 0xE($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE);
    skip_2:
    // 0x800CC144: beql        $t0, $s5, L_800CC270
    if (ctx->r8 == ctx->r21) {
        // 0x800CC148: lh          $t9, 0xE($s0)
        ctx->r25 = MEM_H(ctx->r16, 0XE);
            goto L_800CC270;
    }
    goto skip_3;
    // 0x800CC148: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    skip_3:
    // 0x800CC14C: b           L_800CC2D4
    // 0x800CC150: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
        goto L_800CC2D4;
    // 0x800CC150: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_800CC154:
    // 0x800CC154: jal         0x800EFC7C
    // 0x800CC158: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_3;
    // 0x800CC158: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800CC15C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC160: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800CC164: nop

    // 0x800CC168: bc1fl       L_800CC2D4
    if (!c1cs) {
        // 0x800CC16C: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC2D4;
    }
    goto skip_4;
    // 0x800CC16C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_4:
    // 0x800CC170: lw          $t1, 0x14($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X14);
    // 0x800CC174: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800CC178: subu        $v0, $s6, $t1
    ctx->r2 = SUB32(ctx->r22, ctx->r9);
    // 0x800CC17C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CC180: mflo        $v0
    ctx->r2 = lo;
    // 0x800CC184: b           L_800CC30C
    // 0x800CC188: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800CC30C;
    // 0x800CC188: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800CC18C: lh          $t3, 0xE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XE);
L_800CC190:
    // 0x800CC190: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CC194: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CC198: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800CC19C: nop

    // 0x800CC1A0: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CC1A4: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800CC1A8: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x800CC1AC: nop

    // 0x800CC1B0: bc1fl       L_800CC2D4
    if (!c1cs) {
        // 0x800CC1B4: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC2D4;
    }
    goto skip_5;
    // 0x800CC1B4: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_5:
    // 0x800CC1B8: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800CC1BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC1C0: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x800CC1C4: nop

    // 0x800CC1C8: bc1fl       L_800CC2D4
    if (!c1cs) {
        // 0x800CC1CC: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC2D4;
    }
    goto skip_6;
    // 0x800CC1CC: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_6:
    // 0x800CC1D0: jal         0x800EFC7C
    // 0x800CC1D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_4;
    // 0x800CC1D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800CC1D8: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC1DC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800CC1E0: nop

    // 0x800CC1E4: bc1fl       L_800CC2D4
    if (!c1cs) {
        // 0x800CC1E8: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC2D4;
    }
    goto skip_7;
    // 0x800CC1E8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_7:
    // 0x800CC1EC: lw          $t4, 0x14($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X14);
    // 0x800CC1F0: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800CC1F4: subu        $v0, $s6, $t4
    ctx->r2 = SUB32(ctx->r22, ctx->r12);
    // 0x800CC1F8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CC1FC: mflo        $v0
    ctx->r2 = lo;
    // 0x800CC200: b           L_800CC30C
    // 0x800CC204: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800CC30C;
    // 0x800CC204: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800CC208: lh          $t6, 0xE($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE);
L_800CC20C:
    // 0x800CC20C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CC210: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CC214: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800CC218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC21C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CC220: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800CC224: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800CC228: nop

    // 0x800CC22C: bc1fl       L_800CC2D4
    if (!c1cs) {
        // 0x800CC230: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC2D4;
    }
    goto skip_8;
    // 0x800CC230: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_8:
    // 0x800CC234: jal         0x800EFC7C
    // 0x800CC238: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_5;
    // 0x800CC238: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800CC23C: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC240: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800CC244: nop

    // 0x800CC248: bc1fl       L_800CC2D4
    if (!c1cs) {
        // 0x800CC24C: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC2D4;
    }
    goto skip_9;
    // 0x800CC24C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_9:
    // 0x800CC250: lw          $t7, 0x14($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X14);
    // 0x800CC254: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800CC258: subu        $v0, $s6, $t7
    ctx->r2 = SUB32(ctx->r22, ctx->r15);
    // 0x800CC25C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CC260: mflo        $v0
    ctx->r2 = lo;
    // 0x800CC264: b           L_800CC30C
    // 0x800CC268: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800CC30C;
    // 0x800CC268: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800CC26C: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
L_800CC270:
    // 0x800CC270: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CC274: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CC278: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800CC27C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC280: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CC284: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800CC288: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800CC28C: nop

    // 0x800CC290: bc1fl       L_800CC2D4
    if (!c1cs) {
        // 0x800CC294: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC2D4;
    }
    goto skip_10;
    // 0x800CC294: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_10:
    // 0x800CC298: jal         0x800EFC7C
    // 0x800CC29C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_6;
    // 0x800CC29C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800CC2A0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC2A4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800CC2A8: nop

    // 0x800CC2AC: bc1fl       L_800CC2D4
    if (!c1cs) {
        // 0x800CC2B0: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC2D4;
    }
    goto skip_11;
    // 0x800CC2B0: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_11:
    // 0x800CC2B4: lw          $t0, 0x14($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X14);
    // 0x800CC2B8: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800CC2BC: subu        $v0, $s6, $t0
    ctx->r2 = SUB32(ctx->r22, ctx->r8);
    // 0x800CC2C0: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CC2C4: mflo        $v0
    ctx->r2 = lo;
    // 0x800CC2C8: b           L_800CC30C
    // 0x800CC2CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800CC30C;
    // 0x800CC2CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800CC2D0: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_800CC2D4:
    // 0x800CC2D4: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800CC2D8: bnel        $at, $zero, L_800CC120
    if (ctx->r1 != 0) {
        // 0x800CC2DC: lw          $v0, 0x14($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X14);
            goto L_800CC120;
    }
    goto skip_12;
    // 0x800CC2DC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    skip_12:
L_800CC2E0:
    // 0x800CC2E0: lw          $t2, 0x10($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X10);
L_800CC2E4:
    // 0x800CC2E4: lw          $t4, 0x14($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X14);
    // 0x800CC2E8: addiu       $s6, $s6, 0x1C
    ctx->r22 = ADD32(ctx->r22, 0X1C);
    // 0x800CC2EC: multu       $t2, $fp
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CC2F0: mflo        $t3
    ctx->r11 = lo;
    // 0x800CC2F4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800CC2F8: sltu        $at, $s6, $t5
    ctx->r1 = ctx->r22 < ctx->r13 ? 1 : 0;
    // 0x800CC2FC: bnel        $at, $zero, L_800CC0E0
    if (ctx->r1 != 0) {
        // 0x800CC300: addiu       $a0, $s6, 0x4
        ctx->r4 = ADD32(ctx->r22, 0X4);
            goto L_800CC0E0;
    }
    goto skip_13;
    // 0x800CC300: addiu       $a0, $s6, 0x4
    ctx->r4 = ADD32(ctx->r22, 0X4);
    skip_13:
L_800CC304:
    // 0x800CC304: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800CC308: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800CC30C:
    // 0x800CC30C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CC310: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC314: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CC318: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800CC31C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800CC320: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800CC324: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800CC328: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800CC32C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800CC330: jr          $ra
    // 0x800CC334: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800CC334: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8080000C_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80106790
    // 0x80800018: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800018: nop

    after_0:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x80800024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_808099B4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808099B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808099B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808099BC: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x808099C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808099C4: lh          $v1, 0x248($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X248);
    // 0x808099C8: beql        $v1, $zero, L_80809A04
    if (ctx->r3 == 0) {
        // 0x808099CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80809A04;
    }
    goto skip_0;
    // 0x808099CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808099D0: beq         $v1, $at, L_808099E8
    if (ctx->r3 == ctx->r1) {
        // 0x808099D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808099E8;
    }
    // 0x808099D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808099D8: beq         $v1, $at, L_808099F8
    if (ctx->r3 == ctx->r1) {
        // 0x808099DC: nop
    
            goto L_808099F8;
    }
    // 0x808099DC: nop

    // 0x808099E0: b           L_80809A04
    // 0x808099E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80809A04;
    // 0x808099E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808099E8:
    // 0x808099E8: jal         0x80809A10
    // 0x808099EC: nop

    func_80809A10_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808099EC: nop

    after_0:
    // 0x808099F0: b           L_80809A04
    // 0x808099F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80809A04;
    // 0x808099F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808099F8:
    // 0x808099F8: jal         0x80809A7C
    // 0x808099FC: nop

    func_80809A7C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808099FC: nop

    after_1:
    // 0x80809A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80809A04:
    // 0x80809A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80809A08: jr          $ra
    // 0x80809A0C: nop

    return;
    // 0x80809A0C: nop

;}
RECOMP_FUNC void func_80800030_bsmummove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800038: jal         0x80083800
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsmum_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800044: jal         0x8009BF5C
    // 0x80800048: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x80800048: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: jal         0x8009C4CC
    // 0x80800054: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x80800054: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void vpflicker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B8: jal         0x8001B084
    // 0x808000BC: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x808000BC: nop

    after_0:
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_800DA9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA9E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DA9E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA9EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DA9F0: jal         0x800DA298
    // 0x800DA9F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x800DA9F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800DA9F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800DA9FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DAA00: jal         0x800DA3B8
    // 0x800DAA04: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DA3B8(rdram, ctx);
        goto after_1;
    // 0x800DAA04: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800DAA08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DAA0C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800DAA10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DAA14: jr          $ra
    // 0x800DAA18: nop

    return;
    // 0x800DAA18: nop

;}
RECOMP_FUNC void _bsvan_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084178: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084178);
    return;
    // 0x8008417C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
