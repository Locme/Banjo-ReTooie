#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808001A8_chjujubagfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808001AC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1728, 0X4B8) << 16);
    // 0x808001B0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808001B4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808001B8: addiu       $t7, $t7, 0x4B8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1728, 0X4B8));
    // 0x808001BC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x808001C0: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x808001C4: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x808001C8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x808001CC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x808001D0: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1728, 0X4C4) << 16);
    // 0x808001D4: addiu       $t2, $t2, 0x4C4
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1728, 0X4C4));
    // 0x808001D8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x808001DC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x808001E0: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x808001E4: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x808001E8: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x808001EC: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x808001F0: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x808001F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001FC: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80800200: jal         0x80100094
    // 0x80800204: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800204: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    after_0:
    // 0x80800208: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080020C: jal         0x800DA298
    // 0x80800210: addiu       $a0, $zero, 0x9F3
    ctx->r4 = ADD32(0, 0X9F3);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800210: addiu       $a0, $zero, 0x9F3
    ctx->r4 = ADD32(0, 0X9F3);
    after_1:
    // 0x80800214: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x80800218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800224;
    }
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x8080000C
    // 0x80800220: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080000C_chjujubagfx(rdram, ctx);
        goto after_2;
    // 0x80800220: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
L_80800224:
    // 0x80800224: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800228: sll         $t6, $t9, 11
    ctx->r14 = S32(ctx->r25 << 11);
    // 0x8080022C: bltzl       $t6, L_8080027C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800230: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_8080027C;
    }
    goto skip_0;
    // 0x80800230: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800234: jal         0x8010D278
    // 0x80800238: nop

    func_8010D278(rdram, ctx);
        goto after_3;
    // 0x80800238: nop

    after_3:
    // 0x8080023C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800240: beq         $v0, $at, L_80800270
    if (ctx->r2 == ctx->r1) {
        // 0x80800244: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800270;
    }
    // 0x80800244: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800248: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080024C: beql        $a0, $zero, L_8080027C
    if (ctx->r4 == 0) {
        // 0x80800250: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_8080027C;
    }
    goto skip_1;
    // 0x80800250: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x80800254: jal         0x80106790
    // 0x80800258: nop

    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80800258: nop

    after_4:
    // 0x8080025C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800260: jal         0x80086978
    // 0x80800264: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _chnewmumbo_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800264: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800268: b           L_8080027C
    // 0x8080026C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_8080027C;
    // 0x8080026C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800270:
    // 0x80800270: jal         0x8008FE94
    // 0x80800274: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_8008FE94(rdram, ctx);
        goto after_6;
    // 0x80800274: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80800278: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_8080027C:
    // 0x8080027C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800280: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800284: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80800288: beq         $t7, $at, L_808002B0
    if (ctx->r15 == ctx->r1) {
        // 0x8080028C: addiu       $t0, $s0, 0x4
        ctx->r8 = ADD32(ctx->r16, 0X4);
            goto L_808002B0;
    }
    // 0x8080028C: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
    // 0x80800290: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800294: beq         $t7, $at, L_80800320
    if (ctx->r15 == ctx->r1) {
        // 0x80800298: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800320;
    }
    // 0x80800298: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080029C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808002A0: beq         $t7, $at, L_80800360
    if (ctx->r15 == ctx->r1) {
        // 0x808002A4: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800360;
    }
    // 0x808002A4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002A8: b           L_808003C4
    // 0x808002AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003C4;
    // 0x808002AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002B0:
    // 0x808002B0: jal         0x800898B0
    // 0x808002B4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_7;
    // 0x808002B4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_7:
    // 0x808002B8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x808002BC: addiu       $t3, $sp, 0x40
    ctx->r11 = ADD32(ctx->r29, 0X40);
    // 0x808002C0: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
    // 0x808002C4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x808002C8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808002CC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002D0: lui         $a1, 0x41E0
    ctx->r5 = S32(0X41E0 << 16);
    // 0x808002D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002D8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x808002DC: jal         0x80089878
    // 0x808002E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x808002E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_8:
    // 0x808002E4: jal         0x800898E8
    // 0x808002E8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_9;
    // 0x808002E8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_9:
    // 0x808002EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002F0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002F4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808002F8: nop

    // 0x808002FC: bc1fl       L_808003C4
    if (!c1cs) {
        // 0x80800300: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808003C4;
    }
    goto skip_2;
    // 0x80800300: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80800304: jal         0x800898C8
    // 0x80800308: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_10;
    // 0x80800308: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_10:
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: jal         0x8080000C
    // 0x80800314: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080000C_chjujubagfx(rdram, ctx);
        goto after_11;
    // 0x80800314: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80800318: b           L_808003C4
    // 0x8080031C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003C4;
    // 0x8080031C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800320:
    // 0x80800320: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x80800324: jal         0x800898B0
    // 0x80800328: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_12;
    // 0x80800328: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_12:
    // 0x8080032C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80800330: addiu       $t9, $sp, 0x40
    ctx->r25 = ADD32(ctx->r29, 0X40);
    // 0x80800334: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x80800338: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8080033C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800340: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800344: lui         $a1, 0x41E0
    ctx->r5 = S32(0X41E0 << 16);
    // 0x80800348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080034C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80800350: jal         0x80089878
    // 0x80800354: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_13;
    // 0x80800354: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_13:
    // 0x80800358: b           L_808003C4
    // 0x8080035C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003C4;
    // 0x8080035C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800360:
    // 0x80800360: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x80800364: jal         0x800898B0
    // 0x80800368: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_14;
    // 0x80800368: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_14:
    // 0x8080036C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800370: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x80800374: addiu       $t4, $sp, 0x4C
    ctx->r12 = ADD32(ctx->r29, 0X4C);
    // 0x80800378: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8080037C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800380: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800384: lui         $a1, 0x41E0
    ctx->r5 = S32(0X41E0 << 16);
    // 0x80800388: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080038C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80800390: jal         0x80089878
    // 0x80800394: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_15;
    // 0x80800394: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_15:
    // 0x80800398: jal         0x800898F0
    // 0x8080039C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _sumumbofx_entrypoint_22(rdram, ctx);
        goto after_16;
    // 0x8080039C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_16:
    // 0x808003A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1728, 0X460) << 16);
    // 0x808003A4: lwc1        $f6, 0x460($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1728, 0X460));
    // 0x808003A8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808003AC: nop

    // 0x808003B0: bc1fl       L_808003C4
    if (!c1cs) {
        // 0x808003B4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808003C4;
    }
    goto skip_3;
    // 0x808003B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x808003B8: jal         0x800FFAB0
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_17;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808003C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003C4:
    // 0x808003C4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808003C8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808003CC: jr          $ra
    // 0x808003D0: nop

    return;
    // 0x808003D0: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808010D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808010D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808010D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808010DC: jal         0x808000C8
    // 0x808010E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_808000C8_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x808010E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808010E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010E8: jal         0x8009D3A8
    // 0x808010EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x808010EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808010F0: jal         0x800839E8
    // 0x808010F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808010F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808010F8: beql        $v0, $zero, L_80801110
    if (ctx->r2 == 0) {
        // 0x808010FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801110;
    }
    goto skip_0;
    // 0x808010FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801100: jal         0x800839B0
    // 0x80801104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80801104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801108: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080110C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801110:
    // 0x80801110: jal         0x8009E5C8
    // 0x80801114: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80801114: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080111C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801120: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801124: jr          $ra
    // 0x80801128: nop

    return;
    // 0x80801128: nop

;}
RECOMP_FUNC void func_800DFF2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFF2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DFF30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFF34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DFF38: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800DFF3C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800DFF40: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x800DFF44: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800DFF48: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800DFF4C: jal         0x800D9600
    // 0x800DFF50: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    func_800D9600(rdram, ctx);
        goto after_0;
    // 0x800DFF50: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_0:
    // 0x800DFF54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFF58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DFF5C: jr          $ra
    // 0x800DFF60: nop

    return;
    // 0x800DFF60: nop

;}
RECOMP_FUNC void func_80800264_baeggaim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080026C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800270: jal         0x800A4CA8
    // 0x80800274: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x80800274: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800278: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8080027C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800280: jal         0x80089408
    // 0x80800284: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _ncba1p_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800284: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800288: jal         0x80084C90
    // 0x8080028C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _bafpctrl_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080028C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800290: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800294: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800298: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080029C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808002A0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808002A4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808002A8: jal         0x80800170
    // 0x808002AC: nop

    func_80800170_baeggaim(rdram, ctx);
        goto after_3;
    // 0x808002AC: nop

    after_3:
    // 0x808002B0: jal         0x800D8FF8
    // 0x808002B4: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x808002B4: nop

    after_4:
    // 0x808002B8: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808002BC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808002C0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808002C4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808002C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808002CC: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x808002D0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x808002D4: jal         0x80095738
    // 0x808002D8: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    baflag_isTrue(rdram, ctx);
        goto after_5;
    // 0x808002D8: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x808002DC: bne         $v0, $zero, L_80800300
    if (ctx->r2 != 0) {
        // 0x808002E0: lwc1        $f4, 0x20($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80800300;
    }
    // 0x808002E0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808002E4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808002E8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808002EC: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808002F0: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x808002F4: jal         0x80083128
    // 0x808002F8: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    _bsdronelook_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808002F8: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x808002FC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_80800300:
    // 0x80800300: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800304: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800308: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080030C: jal         0x80089400
    // 0x80800310: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    _ncba1p_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x80800310: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x80800314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800318: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080031C: jr          $ra
    // 0x80800320: nop

    return;
    // 0x80800320: nop

;}
RECOMP_FUNC void _sudeflect_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F30: syscall     816
    recomp_syscall_handler(rdram, ctx, 0x80089F30);
    return;
    // 0x80089F34: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void suegg_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800848: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080084C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800850: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800854: jal         0x80100094
    // 0x80800858: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800858: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080085C: jal         0x800D3948
    // 0x80800860: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800D3948(rdram, ctx);
        goto after_1;
    // 0x80800860: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800864: beq         $v0, $zero, L_80800874
    if (ctx->r2 == 0) {
        // 0x80800868: lw          $t6, 0x34($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X34);
            goto L_80800874;
    }
    // 0x80800868: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080086C: b           L_8080093C
    // 0x80800870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080093C;
    // 0x80800870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800874:
    // 0x80800874: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3322, 0XE30) << 16);
    // 0x80800878: lwc1        $f6, 0xE30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3322, 0XE30));
    // 0x8080087C: lwc1        $f4, 0x30($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X30);
    // 0x80800880: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800884: nop

    // 0x80800888: bc1f        L_80800898
    if (!c1cs) {
        // 0x8080088C: nop
    
            goto L_80800898;
    }
    // 0x8080088C: nop

    // 0x80800890: b           L_8080093C
    // 0x80800894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080093C;
    // 0x80800894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800898:
    // 0x80800898: jal         0x8010D254
    // 0x8080089C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8010D254(rdram, ctx);
        goto after_2;
    // 0x8080089C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x808008A0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808008A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808008A8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808008AC: jal         0x800EFB24
    // 0x808008B0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x808008B0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_3:
    // 0x808008B4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x808008B8: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808008BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008C0: lwc1        $f0, 0x8($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X8);
    // 0x808008C4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808008C8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808008CC: nop

    // 0x808008D0: bc1f        L_808008DC
    if (!c1cs) {
        // 0x808008D4: nop
    
            goto L_808008DC;
    }
    // 0x808008D4: nop

    // 0x808008D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008DC:
    // 0x808008DC: beql        $v0, $zero, L_80800940
    if (ctx->r2 == 0) {
        // 0x808008E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800940;
    }
    goto skip_0;
    // 0x808008E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808008E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808008E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008EC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808008F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808008F4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808008F8: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808008FC: bc1f        L_80800908
    if (!c1cs) {
        // 0x80800900: nop
    
            goto L_80800908;
    }
    // 0x80800900: nop

    // 0x80800904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800908:
    // 0x80800908: beql        $v0, $zero, L_80800940
    if (ctx->r2 == 0) {
        // 0x8080090C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800940;
    }
    goto skip_1;
    // 0x8080090C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800910: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800914: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3322, 0XE34) << 16);
    // 0x80800918: lwc1        $f8, 0xE34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3322, 0XE34));
    // 0x8080091C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800924: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800928: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8080092C: nop

    // 0x80800930: bc1fl       L_80800940
    if (!c1cs) {
        // 0x80800934: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800940;
    }
    goto skip_2;
    // 0x80800934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080093C:
    // 0x8080093C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800940:
    // 0x80800940: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800944: jr          $ra
    // 0x80800948: nop

    return;
    // 0x80800948: nop

;}
RECOMP_FUNC void func_800DAA28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAA28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800DAA2C: jr          $ra
    // 0x800DAA30: sw          $a0, -0x4670($at)
    MEM_W(-0X4670, ctx->r1) = ctx->r4;
    return;
    // 0x800DAA30: sw          $a0, -0x4670($at)
    MEM_W(-0X4670, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void badrone_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C4: jal         0x80800348
    // 0x808003C8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800348_badrone(rdram, ctx);
        goto after_0;
    // 0x808003C8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_0:
    // 0x808003CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003D4: jr          $ra
    // 0x808003D8: nop

    return;
    // 0x808003D8: nop

;}
RECOMP_FUNC void func_80015F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015F28: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80015F2C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80015F30: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80015F34: addiu       $t7, $t7, -0x6620
    ctx->r15 = ADD32(ctx->r15, -0X6620);
    // 0x80015F38: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80015F3C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80015F40: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x80015F44: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80015F48: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x80015F4C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80015F50: lw          $t0, 0x20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X20);
    // 0x80015F54: jr          $ra
    // 0x80015F58: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    return;
    // 0x80015F58: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
;}
RECOMP_FUNC void func_800E144C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E144C: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800E1450: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800E1454: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E1458: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E145C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E1460: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800E1464: jr          $ra
    // 0x800E1468: swc1        $f12, -0x3054($at)
    MEM_W(-0X3054, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800E1468: swc1        $f12, -0x3054($at)
    MEM_W(-0X3054, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_808009F0_chfog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009F4: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x808009F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009FC: bne         $a1, $at, L_80800A1C
    if (ctx->r5 != ctx->r1) {
        // 0x80800A00: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800A1C;
    }
    // 0x80800A00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800A04: jal         0x80089CA8
    // 0x80800A08: nop

    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800A08: nop

    after_0:
    // 0x80800A0C: jal         0x800CF494
    // 0x80800A10: nop

    func_800CF494(rdram, ctx);
        goto after_1;
    // 0x80800A10: nop

    after_1:
    // 0x80800A14: b           L_80800A24
    // 0x80800A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A24;
    // 0x80800A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A1C:
    // 0x80800A1C: b           L_80800A24
    // 0x80800A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A24;
    // 0x80800A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A24:
    // 0x80800A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A2C: jr          $ra
    // 0x80800A30: nop

    return;
    // 0x80800A30: nop

;}
RECOMP_FUNC void func_80801D94_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D98: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80801D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801DA0: bne         $a1, $at, L_80801DC0
    if (ctx->r5 != ctx->r1) {
        // 0x80801DA4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801DC0;
    }
    // 0x80801DA4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801DA8: lhu         $a1, 0x1A($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X1A);
    // 0x80801DAC: srl         $t7, $a1, 5
    ctx->r15 = S32(U32(ctx->r5) >> 5);
    // 0x80801DB0: jal         0x80801DD8
    // 0x80801DB4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_80801DD8_chfactorytwinklies(rdram, ctx);
        goto after_0;
    // 0x80801DB4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_0:
    // 0x80801DB8: b           L_80801DC8
    // 0x80801DBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DC8;
    // 0x80801DBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801DC0:
    // 0x80801DC0: b           L_80801DC8
    // 0x80801DC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801DC8;
    // 0x80801DC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801DC8:
    // 0x80801DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801DD0: jr          $ra
    // 0x80801DD4: nop

    return;
    // 0x80801DD4: nop

;}
RECOMP_FUNC void plcamera_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800258: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080025C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800260: jal         0x800F5EF8
    // 0x80800264: nop

    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x80800264: nop

    after_0:
    // 0x80800268: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080026C: jal         0x80110014
    // 0x80800270: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x80800270: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800274: jal         0x80110928
    // 0x80800278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110928(rdram, ctx);
        goto after_2;
    // 0x80800278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080027C: jal         0x8010FD88
    // 0x80800280: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8010FD88(rdram, ctx);
        goto after_3;
    // 0x80800280: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800288: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080028C: jr          $ra
    // 0x80800290: nop

    return;
    // 0x80800290: nop

;}
RECOMP_FUNC void func_80800C98_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800CA4: jal         0x800845C8
    // 0x80800CA8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800CA8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800CAC: beq         $v0, $zero, L_80800CBC
    if (ctx->r2 == 0) {
        // 0x80800CB0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800CBC;
    }
    // 0x80800CB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CB4: jal         0x80800064
    // 0x80800CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800064_bssnowball(rdram, ctx);
        goto after_1;
    // 0x80800CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80800CBC:
    // 0x80800CBC: jal         0x80084600
    // 0x80800CC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _babounce_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800CC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800CC4: beq         $v0, $zero, L_80800CD0
    if (ctx->r2 == 0) {
        // 0x80800CC8: addiu       $t6, $zero, 0x17D
        ctx->r14 = ADD32(0, 0X17D);
            goto L_80800CD0;
    }
    // 0x80800CC8: addiu       $t6, $zero, 0x17D
    ctx->r14 = ADD32(0, 0X17D);
    // 0x80800CCC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800CD0:
    // 0x80800CD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CD4: jal         0x8009E5C8
    // 0x80800CD8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80800CD8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CE4: jr          $ra
    // 0x80800CE8: nop

    return;
    // 0x80800CE8: nop

;}
RECOMP_FUNC void chfactorymagnet_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808013E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808013E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808013EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808013F0: jal         0x800DA524
    // 0x808013F4: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x808013F4: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    after_0:
    // 0x808013F8: jal         0x800EA05C
    // 0x808013FC: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x808013FC: nop

    after_1:
    // 0x80801400: addiu       $at, $zero, 0x107
    ctx->r1 = ADD32(0, 0X107);
    // 0x80801404: beq         $v0, $at, L_80801414
    if (ctx->r2 == ctx->r1) {
        // 0x80801408: nop
    
            goto L_80801414;
    }
    // 0x80801408: nop

    // 0x8080140C: jal         0x800DA524
    // 0x80801410: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x80801410: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_2:
L_80801414:
    // 0x80801414: jal         0x800DA298
    // 0x80801418: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80801418: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    after_3:
    // 0x8080141C: bnel        $v0, $zero, L_80801454
    if (ctx->r2 != 0) {
        // 0x80801420: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801454;
    }
    goto skip_0;
    // 0x80801420: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801424: jal         0x80086B58
    // 0x80801428: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80801428: nop

    after_4:
    // 0x8080142C: addiu       $t6, $zero, 0xA3
    ctx->r14 = ADD32(0, 0XA3);
    // 0x80801430: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80801434: addiu       $a0, $zero, 0x1338
    ctx->r4 = ADD32(0, 0X1338);
    // 0x80801438: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080143C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801440: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801444: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801448: jal         0x800C05B8
    // 0x8080144C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800C05B8(rdram, ctx);
        goto after_5;
    // 0x8080144C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x80801450: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801454:
    // 0x80801454: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801458: jr          $ra
    // 0x8080145C: nop

    return;
    // 0x8080145C: nop

;}
RECOMP_FUNC void func_800DB9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB9B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DB9B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DB9B8: jal         0x800DA298
    // 0x800DB9BC: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x800DB9BC: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    after_0:
    // 0x800DB9C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DB9C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DB9C8: jr          $ra
    // 0x800DB9CC: nop

    return;
    // 0x800DB9CC: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A38: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A38);
    return;
    // 0x80082A3C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_808000F0_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800100: jal         0x8009E74C
    // 0x80800104: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800104: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_0:
    // 0x80800108: bne         $v0, $zero, L_80800194
    if (ctx->r2 != 0) {
        // 0x8080010C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800194;
    }
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800114: jal         0x800947EC
    // 0x80800118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_1;
    // 0x80800118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x8009BF5C
    // 0x80800124: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_2;
    // 0x80800124: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x8009C4CC
    // 0x80800130: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_3;
    // 0x80800130: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800134: jal         0x8009C000
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C000(rdram, ctx);
        goto after_4;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080013C: jal         0x8009C570
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_resetAngularVelocity(rdram, ctx);
        goto after_5;
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800144: jal         0x8009EF60
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_6;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080014C: jal         0x80095A40
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_7;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: jal         0x80095964
    // 0x8080015C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80095964(rdram, ctx);
        goto after_8;
    // 0x8080015C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800160: jal         0x8009E474
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_9;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: jal         0x80095774
    // 0x80800170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_clear(rdram, ctx);
        goto after_10;
    // 0x80800170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80095774
    // 0x8080017C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    baflag_clear(rdram, ctx);
        goto after_11;
    // 0x8080017C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80800180: jal         0x800853F8
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawasher_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: jal         0x80092864
    // 0x80800190: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_13;
    // 0x80800190: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
L_80800194:
    // 0x80800194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080019C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void func_80092864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092864: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80092868: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x8009286C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80092870: swc1        $f12, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f12.u32l;
    // 0x80092874: lw          $t8, 0x50($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X50);
    // 0x80092878: jr          $ra
    // 0x8009287C: sb          $t7, 0x7C($t8)
    MEM_B(0X7C, ctx->r24) = ctx->r15;
    return;
    // 0x8009287C: sb          $t7, 0x7C($t8)
    MEM_B(0X7C, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void func_80800A8C_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A98: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800A9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AA0: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800AA4: bltzl       $t8, L_80800B30
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800AA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B30;
    }
    goto skip_0;
    // 0x80800AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800AAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800AB0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800AB4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800AB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800ABC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800AC0: jal         0x800EFA4C
    // 0x80800AC4: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800AC4: nop

    after_0:
    // 0x80800AC8: jal         0x800F54E4
    // 0x80800ACC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800ACC: nop

    after_1:
    // 0x80800AD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AD4: jal         0x800F8444
    // 0x80800AD8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F8444(rdram, ctx);
        goto after_2;
    // 0x80800AD8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80800ADC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800AE0: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80800AE4: jal         0x800856B0
    // 0x80800AE8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    _capod_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800AE8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_3:
    // 0x80800AEC: jal         0x800856E0
    // 0x80800AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800AF4: jal         0x800880B8
    // 0x80800AF8: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800AF8: nop

    after_5:
    // 0x80800AFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800B00: jal         0x800856F8
    // 0x80800B04: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _capod_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800B04: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x80800B08: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800B0C: jal         0x800856D8
    // 0x80800B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _capod_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x80800B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: jal         0x8008A4B0
    // 0x80800B1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800B1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800B20: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800B24: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80800B28: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800B2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B30:
    // 0x80800B30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800B38: jr          $ra
    // 0x80800B3C: nop

    return;
    // 0x80800B3C: nop

;}
RECOMP_FUNC void chdumbwaiterlift_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1200, 0XBE8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xBE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1200, 0XBE8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xBE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1200, 0XBE8));
;}
RECOMP_FUNC void func_80800044_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800048: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080004C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800050: lhu         $v1, 0x72($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X72);
    // 0x80800054: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800058: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080005C: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800060: xori        $a2, $t6, 0x2
    ctx->r6 = ctx->r14 ^ 0X2;
    // 0x80800064: sltiu       $a2, $a2, 0x1
    ctx->r6 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x80800068: bne         $a2, $zero, L_80800078
    if (ctx->r6 != 0) {
        // 0x8080006C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80800078;
    }
    // 0x8080006C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80800070: xori        $a2, $t6, 0x6
    ctx->r6 = ctx->r14 ^ 0X6;
    // 0x80800074: sltiu       $a2, $a2, 0x1
    ctx->r6 = ctx->r6 < 0X1 ? 1 : 0;
L_80800078:
    // 0x80800078: bne         $a2, $zero, L_80800094
    if (ctx->r6 != 0) {
        // 0x8080007C: lui         $a3, 0x8080
        ctx->r7 = S32(RELOC_HI16(1200, 0XC30) << 16);
            goto L_80800094;
    }
    // 0x8080007C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1200, 0XC30) << 16);
    // 0x80800080: bnel        $a2, $zero, L_808000B0
    if (ctx->r6 != 0) {
        // 0x80800084: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_808000B0;
    }
    goto skip_0;
    // 0x80800084: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x80800088: lbu         $t7, 0x5F($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5F);
    // 0x8080008C: beql        $t7, $zero, L_808000B0
    if (ctx->r15 == 0) {
        // 0x80800090: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_808000B0;
    }
    goto skip_1;
    // 0x80800090: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    skip_1:
L_80800094:
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x80089D50
    // 0x8080009C: addiu       $a3, $a3, 0xC30
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1200, 0XC30));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080009C: addiu       $a3, $a3, 0xC30
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1200, 0XC30));
    after_0:
    // 0x808000A0: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808000A4: srl         $t8, $v1, 10
    ctx->r24 = S32(U32(ctx->r3) >> 10);
    // 0x808000A8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x808000AC: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
L_808000B0:
    // 0x808000B0: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x808000B4: beq         $at, $zero, L_80800254
    if (ctx->r1 == 0) {
        // 0x808000B8: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800254;
    }
    // 0x808000B8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808000BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1200, 0XBA0) << 16);
    // 0x808000C0: addu        $at, $at, $t9
    gpr jr_addend_808000C8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808000C4: lw          $t9, 0xBA0($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1200, 0XBA0));
    // 0x808000C8: jr          $t9
    // 0x808000CC: nop

    switch (jr_addend_808000C8 >> 2) {
        case 0: goto L_808000D0; break;
        case 1: goto L_808000E0; break;
        case 2: goto L_80800164; break;
        case 3: goto L_80800174; break;
        case 4: goto L_80800190; break;
        case 5: goto L_808001BC; break;
        default: switch_error(__func__, 0x808000C8, 0x80800BA0);
    }
    // 0x808000CC: nop

L_808000D0:
    // 0x808000D0: jal         0x80800770
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800770_chdumbwaiterlift(rdram, ctx);
        goto after_1;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000D8: b           L_80800258
    // 0x808000DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800258;
    // 0x808000DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000E0:
    // 0x808000E0: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
    // 0x808000E4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x808000E8: jal         0x800D9078
    // 0x808000EC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x808000EC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x808000F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808000F4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808000F8: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808000FC: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x80800100: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800104: jal         0x800F10B4
    // 0x80800108: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800108: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x8080010C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800110: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800114: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800118: jal         0x800EFE50
    // 0x8080011C: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_4;
    // 0x8080011C: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_4:
    // 0x80800120: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080012C: beq         $t1, $zero, L_80800254
    if (ctx->r9 == 0) {
        // 0x80800130: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1200, 0XC40) << 16);
            goto L_80800254;
    }
    // 0x80800130: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1200, 0XC40) << 16);
    // 0x80800134: jal         0x80089D18
    // 0x80800138: addiu       $a2, $a2, 0xC40
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1200, 0XC40));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800138: addiu       $a2, $a2, 0xC40
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1200, 0XC40));
    after_5:
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x80101FDC
    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x8008A4B0
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800154: jal         0x80085750
    // 0x80800158: nop

    _capod_entrypoint_22(rdram, ctx);
        goto after_8;
    // 0x80800158: nop

    after_8:
    // 0x8080015C: b           L_80800258
    // 0x80800160: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800258;
    // 0x80800160: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800164:
    // 0x80800164: jal         0x80800804
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800804_chdumbwaiterlift(rdram, ctx);
        goto after_9;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080016C: b           L_80800258
    // 0x80800170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800258;
    // 0x80800170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800174:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80100094
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800180: jal         0x80087C98
    // 0x80800184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80800188: b           L_80800258
    // 0x8080018C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800258;
    // 0x8080018C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800190:
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: jal         0x80087CC8
    // 0x80800198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x80800198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: jal         0x80101FDC
    // 0x808001A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x808001A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x8010A828
    // 0x808001B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A828(rdram, ctx);
        goto after_14;
    // 0x808001B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x808001B4: b           L_80800258
    // 0x808001B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800258;
    // 0x808001B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001BC:
    // 0x808001BC: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x808001C0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x808001C4: jal         0x800D9078
    // 0x808001C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_15;
    // 0x808001C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_15:
    // 0x808001CC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001D0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808001D4: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001D8: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x808001DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808001E0: jal         0x800F10B4
    // 0x808001E4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x808001E4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_16:
    // 0x808001E8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808001F0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x808001F4: jal         0x800EFE50
    // 0x808001F8: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_17;
    // 0x808001F8: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_17:
    // 0x808001FC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80800200: beql        $t3, $zero, L_80800258
    if (ctx->r11 == 0) {
        // 0x80800204: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800258;
    }
    goto skip_2;
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800208: jal         0x808008B4
    // 0x8080020C: nop

    func_808008B4_chdumbwaiterlift(rdram, ctx);
        goto after_18;
    // 0x8080020C: nop

    after_18:
    // 0x80800210: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x80800214: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1200, 0XBC4) << 16);
    // 0x80800218: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x8080021C: jal         0x800DA544
    // 0x80800220: lh          $a0, 0xBC4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1200, 0XBC4));
    func_800DA544(rdram, ctx);
        goto after_19;
    // 0x80800220: lh          $a0, 0xBC4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1200, 0XBC4));
    after_19:
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: jal         0x8008A4B0
    // 0x8080022C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x8080022C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80800230: lw          $t5, 0x6C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X6C);
    // 0x80800234: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1200, 0XBC0) << 16);
    // 0x80800238: addiu       $t8, $t8, 0xBC0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1200, 0XBC0));
    // 0x8080023C: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80800240: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800244: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80800248: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8080024C: jal         0x80087A58
    // 0x80800250: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_21;
    // 0x80800250: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    after_21:
L_80800254:
    // 0x80800254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800258:
    // 0x80800258: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080025C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800260: jr          $ra
    // 0x80800264: nop

    return;
    // 0x80800264: nop

;}
RECOMP_FUNC void func_8080009C_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A4: jal         0x80800040
    // 0x808000A8: nop

    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_0;
    // 0x808000A8: nop

    after_0:
    // 0x808000AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4B10) << 16);
    // 0x808000B0: lwc1        $f4, 0x4B10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4B10));
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000BC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808000C0: jr          $ra
    // 0x808000C4: nop

    return;
    // 0x808000C4: nop

;}
RECOMP_FUNC void _chbilldrillplate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862F0: syscall     304
    recomp_syscall_handler(rdram, ctx, 0x800862F0);
    return;
    // 0x800862F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808000C0_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000C4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1932, 0X10F0) << 16);
    // 0x808000C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808000D4: addiu       $t7, $t7, 0x10F0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1932, 0X10F0));
    // 0x808000D8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x808000DC: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x808000E0: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x808000E4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x808000E8: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x808000EC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F4: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x808000F8: lwr         $at, 0xE($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0XE);
    // 0x808000FC: swr         $at, 0xE($t6)
    do_swr(rdram, 0XE, ctx->r14, ctx->r1);
    // 0x80800100: jal         0x80100094
    // 0x80800104: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800104: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x80800108: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080010C: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x80800110: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80800114: addiu       $a0, $zero, 0x32B
    ctx->r4 = ADD32(0, 0X32B);
    // 0x80800118: jal         0x800DA564
    // 0x8080011C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x8080011C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800120: bne         $v0, $zero, L_80800140
    if (ctx->r2 != 0) {
        // 0x80800124: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800140;
    }
    // 0x80800124: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800128: jal         0x800DC128
    // 0x8080012C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x8080012C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800130: addiu       $a0, $zero, 0x32B
    ctx->r4 = ADD32(0, 0X32B);
    // 0x80800134: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x80800138: jal         0x800DA7A8
    // 0x8080013C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_3;
    // 0x8080013C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
L_80800140:
    // 0x80800140: addiu       $a0, $zero, 0x32B
    ctx->r4 = ADD32(0, 0X32B);
    // 0x80800144: jal         0x800DA564
    // 0x80800148: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_4;
    // 0x80800148: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8080014C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80800150: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80800154: addiu       $t2, $t1, -0x5
    ctx->r10 = ADD32(ctx->r9, -0X5);
    // 0x80800158: addiu       $t3, $sp, 0x38
    ctx->r11 = ADD32(ctx->r29, 0X38);
    // 0x8080015C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x80800160: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x80800164: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800168: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x8080016C: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x80800170: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x80800174: addu        $v0, $s0, $a0
    ctx->r2 = ADD32(ctx->r16, ctx->r4);
    // 0x80800178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080017C: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80800180: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x80800184: addiu       $a2, $zero, -0xAF
    ctx->r6 = ADD32(0, -0XAF);
    // 0x80800188: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8080018C: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x80800190: sb          $t8, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r24;
    // 0x80800194: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x80800198: sb          $t6, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r14;
    // 0x8080019C: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x808001A0: jal         0x8080005C
    // 0x808001A4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8080005C_chprisonbits(rdram, ctx);
        goto after_5;
    // 0x808001A4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_5:
    // 0x808001A8: jal         0x800DA298
    // 0x808001AC: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808001AC: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    after_6:
    // 0x808001B0: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x808001B4: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x808001B8: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x808001BC: lbu         $t3, 0x65($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X65);
    // 0x808001C0: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x808001C4: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x808001C8: sb          $t5, 0x65($t2)
    MEM_B(0X65, ctx->r10) = ctx->r13;
    // 0x808001CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001D4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void func_80800ACC_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ACC: jr          $ra
    // 0x80800AD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800AD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800C9074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9074: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C9078: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C907C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9084: beql        $a0, $zero, L_800C90A0
    if (ctx->r4 == 0) {
        // 0x800C9088: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C90A0;
    }
    goto skip_0;
    // 0x800C9088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C908C: jal         0x800B2F58
    // 0x800C9090: nop

    vector_defrag(rdram, ctx);
        goto after_0;
    // 0x800C9090: nop

    after_0:
    // 0x800C9094: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C9098: sw          $v0, -0x5500($at)
    MEM_W(-0X5500, ctx->r1) = ctx->r2;
    // 0x800C909C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C90A0:
    // 0x800C90A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C90A4: jr          $ra
    // 0x800C90A8: nop

    return;
    // 0x800C90A8: nop

;}
RECOMP_FUNC void _bssplitup_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B00: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083B00);
    return;
    // 0x80083B04: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _chdiggerfly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CA8: syscall     221
    recomp_syscall_handler(rdram, ctx, 0x80085CA8);
    return;
    // 0x80085CAC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800DA544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DA548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA54C: jal         0x800DA3B8
    // 0x800DA550: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_0;
    // 0x800DA550: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800DA554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DA558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DA55C: jr          $ra
    // 0x800DA560: nop

    return;
    // 0x800DA560: nop

;}
RECOMP_FUNC void func_800A9BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9BFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A9C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9C04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A9C08: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A9C0C: jal         0x800A9B84
    // 0x800A9C10: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800A9B84(rdram, ctx);
        goto after_0;
    // 0x800A9C10: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A9C14: jal         0x800EA05C
    // 0x800A9C18: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x800A9C18: nop

    after_1:
    // 0x800A9C1C: jal         0x800EA090
    // 0x800A9C20: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800EA090(rdram, ctx);
        goto after_2;
    // 0x800A9C20: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x800A9C24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A9C28: jal         0x800A9B8C
    // 0x800A9C2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A9B8C(rdram, ctx);
        goto after_3;
    // 0x800A9C2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x800A9C30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A9C34: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A9C38: jal         0x800A9BA0
    // 0x800A9C3C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800A9BA0(rdram, ctx);
        goto after_4;
    // 0x800A9C3C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x800A9C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9C44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A9C48: jr          $ra
    // 0x800A9C4C: nop

    return;
    // 0x800A9C4C: nop

;}
RECOMP_FUNC void func_80800588_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080058C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800590: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800594: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800598: jal         0x80100094
    // 0x8080059C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080059C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808005A0: lw          $t6, 0xA4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA4);
    // 0x808005A4: bnel        $t6, $zero, L_808005E0
    if (ctx->r14 != 0) {
        // 0x808005A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005E0;
    }
    goto skip_0;
    // 0x808005A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808005AC: jal         0x80800874
    // 0x808005B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800874_cheggproximity(rdram, ctx);
        goto after_1;
    // 0x808005B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808005B4: jal         0x80800BF4
    // 0x808005B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800BF4_cheggproximity(rdram, ctx);
        goto after_2;
    // 0x808005B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808005BC: bne         $v0, $zero, L_808005DC
    if (ctx->r2 != 0) {
        // 0x808005C0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_808005DC;
    }
    // 0x808005C0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808005C4: jal         0x800D9078
    // 0x808005C8: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x808005C8: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_3:
    // 0x808005CC: beq         $v0, $zero, L_808005DC
    if (ctx->r2 == 0) {
        // 0x808005D0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808005DC;
    }
    // 0x808005D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005D4: jal         0x80800718
    // 0x808005D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800718_cheggproximity(rdram, ctx);
        goto after_4;
    // 0x808005D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
L_808005DC:
    // 0x808005DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005E0:
    // 0x808005E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005E4: jr          $ra
    // 0x808005E8: nop

    return;
    // 0x808005E8: nop

;}
RECOMP_FUNC void func_8008F9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F9F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F9FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FA00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FA04: jal         0x800F54E4
    // 0x8008FA08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FA08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008FA0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FA10: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008FA14: jal         0x800F4AC0
    // 0x8008FA18: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F4AC0(rdram, ctx);
        goto after_1;
    // 0x8008FA18: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8008FA1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FA20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FA24: jr          $ra
    // 0x8008FA28: nop

    return;
    // 0x8008FA28: nop

;}
RECOMP_FUNC void _chterryegg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086170: syscall     283
    recomp_syscall_handler(rdram, ctx, 0x80086170);
    return;
    // 0x80086174: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800D30_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D3C: beq         $a2, $at, L_80800D68
    if (ctx->r6 == ctx->r1) {
        // 0x80800D40: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80800D68;
    }
    // 0x80800D40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800D48: beq         $a2, $at, L_80800D88
    if (ctx->r6 == ctx->r1) {
        // 0x80800D4C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800D88;
    }
    // 0x80800D4C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800D50: beq         $a2, $at, L_80800D98
    if (ctx->r6 == ctx->r1) {
        // 0x80800D54: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800D98;
    }
    // 0x80800D54: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800D58: beql        $a2, $at, L_80800ED4
    if (ctx->r6 == ctx->r1) {
        // 0x80800D5C: lw          $t6, 0x15C($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X15C);
            goto L_80800ED4;
    }
    goto skip_0;
    // 0x80800D5C: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    skip_0:
    // 0x80800D60: b           L_80800F54
    // 0x80800D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F54;
    // 0x80800D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D68:
    // 0x80800D68: lbu         $v0, 0x15F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X15F);
    // 0x80800D6C: srl         $t6, $v0, 6
    ctx->r14 = S32(U32(ctx->r2) >> 6);
    // 0x80800D70: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800D74: sll         $t9, $t7, 6
    ctx->r25 = S32(ctx->r15 << 6);
    // 0x80800D78: andi        $t0, $v0, 0xFF3F
    ctx->r8 = ctx->r2 & 0XFF3F;
    // 0x80800D7C: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80800D80: b           L_80800F50
    // 0x80800D84: sb          $t1, 0x15F($a0)
    MEM_B(0X15F, ctx->r4) = ctx->r9;
        goto L_80800F50;
    // 0x80800D84: sb          $t1, 0x15F($a0)
    MEM_B(0X15F, ctx->r4) = ctx->r9;
L_80800D88:
    // 0x80800D88: jal         0x80800A50
    // 0x80800D8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x80800D8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800D90: b           L_80800F54
    // 0x80800D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F54;
    // 0x80800D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D98:
    // 0x80800D98: lbu         $t2, 0x15C($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X15C);
    // 0x80800D9C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800DA0: bnel        $t2, $at, L_80800E34
    if (ctx->r10 != ctx->r1) {
        // 0x80800DA4: lbu         $t6, 0x11C($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X11C);
            goto L_80800E34;
    }
    goto skip_1;
    // 0x80800DA4: lbu         $t6, 0x11C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X11C);
    skip_1:
    // 0x80800DA8: lw          $t4, 0x15C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X15C);
    // 0x80800DAC: lbu         $t7, 0x15F($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X15F);
    // 0x80800DB0: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80800DB4: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x80800DB8: andi        $t8, $t7, 0xFFFC
    ctx->r24 = ctx->r15 & 0XFFFC;
    // 0x80800DBC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80800DC0: sb          $t9, 0x15F($a0)
    MEM_B(0X15F, ctx->r4) = ctx->r25;
    // 0x80800DC4: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x80800DC8: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80800DCC: bnel        $t1, $zero, L_80800F54
    if (ctx->r9 != 0) {
        // 0x80800DD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F54;
    }
    goto skip_2;
    // 0x80800DD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800DD4: lbu         $t2, 0x11C($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X11C);
    // 0x80800DD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800DE0: srl         $t3, $t2, 6
    ctx->r11 = S32(U32(ctx->r10) >> 6);
    // 0x80800DE4: beq         $t3, $zero, L_80800DF4
    if (ctx->r11 == 0) {
        // 0x80800DE8: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80800DF4;
    }
    // 0x80800DE8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800DEC: b           L_80800DF4
    // 0x80800DF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800DF4;
    // 0x80800DF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800DF4:
    // 0x80800DF4: lbu         $t4, 0x11D($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X11D);
    // 0x80800DF8: srl         $t5, $t4, 6
    ctx->r13 = S32(U32(ctx->r12) >> 6);
    // 0x80800DFC: beq         $t5, $zero, L_80800E0C
    if (ctx->r13 == 0) {
        // 0x80800E00: nop
    
            goto L_80800E0C;
    }
    // 0x80800E00: nop

    // 0x80800E04: b           L_80800E0C
    // 0x80800E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E0C;
    // 0x80800E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E0C:
    // 0x80800E0C: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x80800E10: beq         $t7, $zero, L_80800E20
    if (ctx->r15 == 0) {
        // 0x80800E14: nop
    
            goto L_80800E20;
    }
    // 0x80800E14: nop

    // 0x80800E18: b           L_80800E20
    // 0x80800E1C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
        goto L_80800E20;
    // 0x80800E1C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_80800E20:
    // 0x80800E20: jal         0x80800A50
    // 0x80800E24: nop

    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_1;
    // 0x80800E24: nop

    after_1:
    // 0x80800E28: b           L_80800F54
    // 0x80800E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F54;
    // 0x80800E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E30: lbu         $t6, 0x11C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X11C);
L_80800E34:
    // 0x80800E34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800E38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E3C: srl         $t8, $t6, 6
    ctx->r24 = S32(U32(ctx->r14) >> 6);
    // 0x80800E40: beq         $t8, $zero, L_80800E50
    if (ctx->r24 == 0) {
        // 0x80800E44: nop
    
            goto L_80800E50;
    }
    // 0x80800E44: nop

    // 0x80800E48: b           L_80800E50
    // 0x80800E4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E50;
    // 0x80800E4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E50:
    // 0x80800E50: lbu         $t9, 0x11D($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X11D);
    // 0x80800E54: srl         $t0, $t9, 6
    ctx->r8 = S32(U32(ctx->r25) >> 6);
    // 0x80800E58: beq         $t0, $zero, L_80800E68
    if (ctx->r8 == 0) {
        // 0x80800E5C: nop
    
            goto L_80800E68;
    }
    // 0x80800E5C: nop

    // 0x80800E60: b           L_80800E68
    // 0x80800E64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800E68;
    // 0x80800E64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800E68:
    // 0x80800E68: lw          $v1, 0x15C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X15C);
    // 0x80800E6C: addu        $t3, $a1, $v0
    ctx->r11 = ADD32(ctx->r5, ctx->r2);
    // 0x80800E70: sll         $t1, $v1, 26
    ctx->r9 = S32(ctx->r3 << 26);
    // 0x80800E74: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80800E78: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80800E7C: beq         $at, $zero, L_80800F50
    if (ctx->r1 == 0) {
        // 0x80800E80: addiu       $t4, $t2, 0x1
        ctx->r12 = ADD32(ctx->r10, 0X1);
            goto L_80800F50;
    }
    // 0x80800E80: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80800E84: lbu         $t6, 0x15F($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15F);
    // 0x80800E88: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80800E8C: andi        $t7, $t5, 0x30
    ctx->r15 = ctx->r13 & 0X30;
    // 0x80800E90: andi        $t8, $t6, 0xFFCF
    ctx->r24 = ctx->r14 & 0XFFCF;
    // 0x80800E94: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80800E98: sb          $t9, 0x15F($a0)
    MEM_B(0X15F, ctx->r4) = ctx->r25;
    // 0x80800E9C: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80800EA0: lbu         $t0, 0x15D($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X15D);
    // 0x80800EA4: sll         $t1, $v0, 26
    ctx->r9 = S32(ctx->r2 << 26);
    // 0x80800EA8: sll         $t3, $v0, 28
    ctx->r11 = S32(ctx->r2 << 28);
    // 0x80800EAC: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x80800EB0: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80800EB4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80800EB8: bnel        $t0, $t5, L_80800F54
    if (ctx->r8 != ctx->r13) {
        // 0x80800EBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F54;
    }
    goto skip_3;
    // 0x80800EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80800EC0: jal         0x80800A50
    // 0x80800EC4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_2;
    // 0x80800EC4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x80800EC8: b           L_80800F54
    // 0x80800ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F54;
    // 0x80800ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800ED0: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
L_80800ED4:
    // 0x80800ED4: lbu         $t2, 0x15F($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X15F);
    // 0x80800ED8: lbu         $v1, 0x15D($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X15D);
    // 0x80800EDC: sll         $t7, $t6, 28
    ctx->r15 = S32(ctx->r14 << 28);
    // 0x80800EE0: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80800EE4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80800EE8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80800EEC: andi        $t3, $t1, 0xC
    ctx->r11 = ctx->r9 & 0XC;
    // 0x80800EF0: andi        $t4, $t2, 0xFFF3
    ctx->r12 = ctx->r10 & 0XFFF3;
    // 0x80800EF4: or          $t0, $t3, $t4
    ctx->r8 = ctx->r11 | ctx->r12;
    // 0x80800EF8: sb          $t0, 0x15F($a0)
    MEM_B(0X15F, ctx->r4) = ctx->r8;
    // 0x80800EFC: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80800F00: sll         $a1, $v0, 28
    ctx->r5 = S32(ctx->r2 << 28);
    // 0x80800F04: srl         $t5, $a1, 30
    ctx->r13 = S32(U32(ctx->r5) >> 30);
    // 0x80800F08: bne         $v1, $t5, L_80800F34
    if (ctx->r3 != ctx->r13) {
        // 0x80800F0C: or          $a1, $t5, $zero
        ctx->r5 = ctx->r13 | 0;
            goto L_80800F34;
    }
    // 0x80800F0C: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80800F10: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800F14: jal         0x80800A50
    // 0x80800F18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_3;
    // 0x80800F18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800F1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F20: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80800F24: lbu         $v1, 0x15D($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X15D);
    // 0x80800F28: sll         $a1, $v0, 28
    ctx->r5 = S32(ctx->r2 << 28);
    // 0x80800F2C: srl         $t6, $a1, 30
    ctx->r14 = S32(U32(ctx->r5) >> 30);
    // 0x80800F30: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_80800F34:
    // 0x80800F34: sll         $t7, $v0, 26
    ctx->r15 = S32(ctx->r2 << 26);
    // 0x80800F38: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80800F3C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80800F40: bnel        $v1, $t9, L_80800F54
    if (ctx->r3 != ctx->r25) {
        // 0x80800F44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F54;
    }
    goto skip_4;
    // 0x80800F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80800F48: jal         0x80800A50
    // 0x80800F4C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_4;
    // 0x80800F4C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
L_80800F50:
    // 0x80800F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F54:
    // 0x80800F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F58: jr          $ra
    // 0x80800F5C: nop

    return;
    // 0x80800F5C: nop

;}
RECOMP_FUNC void _bsjump_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083248: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083248);
    return;
    // 0x8008324C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808006F8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800700: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800704: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800708: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080070C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800710: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800714: jal         0x80100094
    // 0x80800718: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800718: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080071C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800720: jal         0x801015D0
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800728: jal         0x801022E4
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_2;
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800730: bnel        $v0, $zero, L_80800770
    if (ctx->r2 != 0) {
        // 0x80800734: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_80800770;
    }
    goto skip_0;
    // 0x80800734: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    skip_0:
    // 0x80800738: jal         0x800B27E0
    // 0x8080073C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B27E0(rdram, ctx);
        goto after_3;
    // 0x8080073C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800740: jal         0x801040D0
    // 0x80800744: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_801040D0(rdram, ctx);
        goto after_4;
    // 0x80800744: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_4:
    // 0x80800748: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8080074C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800750: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800754: jal         0x800AE1E8
    // 0x80800758: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_800AE1E8(rdram, ctx);
        goto after_5;
    // 0x80800758: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_5:
    // 0x8080075C: jal         0x801040A8
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801040A8(rdram, ctx);
        goto after_6;
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800764: jal         0x800DF72C
    // 0x80800768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF72C(rdram, ctx);
        goto after_7;
    // 0x80800768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x8080076C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80800770:
    // 0x80800770: lui         $s2, 0x8081
    ctx->r18 = S32(RELOC_HI16(1480, 0X9EE0) << 16);
    // 0x80800774: lui         $s0, 0x8081
    ctx->r16 = S32(RELOC_HI16(1480, 0X9ED4) << 16);
    // 0x80800778: addiu       $s0, $s0, -0x612C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1480, 0X9ED4));
    // 0x8080077C: addiu       $s2, $s2, -0x6120
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1480, 0X9EE0));
L_80800780:
    // 0x80800780: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80800784: jal         0x800DF744
    // 0x80800788: lbu         $a1, 0xE4($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XE4);
    func_800DF744(rdram, ctx);
        goto after_8;
    // 0x80800788: lbu         $a1, 0xE4($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XE4);
    after_8:
    // 0x8080078C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80800790: bne         $s0, $s2, L_80800780
    if (ctx->r16 != ctx->r18) {
        // 0x80800794: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800780;
    }
    // 0x80800794: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800798: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080079C: jal         0x800DF744
    // 0x808007A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_9;
    // 0x808007A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808007A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808007A8: jal         0x800DF744
    // 0x808007AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_10;
    // 0x808007AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808007B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808007B4: jal         0x800DF744
    // 0x808007B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_11;
    // 0x808007B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x808007BC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808007C0: jal         0x800DF744
    // 0x808007C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_12;
    // 0x808007C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808007C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808007D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808007D8: jr          $ra
    // 0x808007DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808007DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80802634_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802634: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802638: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080263C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802640: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80802644: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802648: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x8080264C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3BE0) << 16);
    // 0x80802650: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80802654: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80802658: addiu       $a2, $a2, 0x3BE0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3BE0));
    // 0x8080265C: jal         0x80089D20
    // 0x80802660: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80802660: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80802664: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3BEC) << 16);
    // 0x80802668: lui         $a3, 0x3F47
    ctx->r7 = S32(0X3F47 << 16);
    // 0x8080266C: ori         $a3, $a3, 0xAE14
    ctx->r7 = ctx->r7 | 0XAE14;
    // 0x80802670: addiu       $a2, $a2, 0x3BEC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3BEC));
    // 0x80802674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802678: jal         0x80089D20
    // 0x8080267C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080267C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80802680: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3C0C) << 16);
    // 0x80802684: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1240, 0X3C2C) << 16);
    // 0x80802688: addiu       $a3, $a3, 0x3C2C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1240, 0X3C2C));
    // 0x8080268C: addiu       $a2, $a2, 0x3C0C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3C0C));
    // 0x80802690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802694: jal         0x80089D28
    // 0x80802698: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80802698: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8080269C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3BFC) << 16);
    // 0x808026A0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1240, 0X3C1C) << 16);
    // 0x808026A4: addiu       $a3, $a3, 0x3C1C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1240, 0X3C1C));
    // 0x808026A8: addiu       $a2, $a2, 0x3BFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3BFC));
    // 0x808026AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026B0: jal         0x80089D28
    // 0x808026B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808026B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x808026B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808026BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808026C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808026C4: jr          $ra
    // 0x808026C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808026C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808017F8_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801800: jal         0x80800104
    // 0x80801804: nop

    func_80800104_bsbswim(rdram, ctx);
        goto after_0;
    // 0x80801804: nop

    after_0:
    // 0x80801808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080180C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801810: jr          $ra
    // 0x80801814: nop

    return;
    // 0x80801814: nop

;}
RECOMP_FUNC void func_800E257C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E257C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2580: jr          $ra
    // 0x800E2584: sh          $a0, -0x2B74($at)
    MEM_H(-0X2B74, ctx->r1) = ctx->r4;
    return;
    // 0x800E2584: sh          $a0, -0x2B74($at)
    MEM_H(-0X2B74, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void subaddiejoy_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080044C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800450: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80800454: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800458: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8080045C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800460: bgez        $t7, L_8080047C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800464: sll         $a0, $v0, 3
        ctx->r4 = S32(ctx->r2 << 3);
            goto L_8080047C;
    }
    // 0x80800464: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x80800468: srl         $t8, $a0, 30
    ctx->r24 = S32(U32(ctx->r4) >> 30);
    // 0x8080046C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800470: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80800474: jal         0x80018820
    // 0x80800478: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80018820(rdram, ctx);
        goto after_0;
    // 0x80800478: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
L_8080047C:
    // 0x8080047C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800484: jr          $ra
    // 0x80800488: nop

    return;
    // 0x80800488: nop

    // 0x8080048C: nop

;}
RECOMP_FUNC void func_80800944_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800944: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080094C: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800950: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800954: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800958: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x8080095C: bgezl       $t8, L_808009CC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800960: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808009CC;
    }
    goto skip_0;
    // 0x80800960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800964: jal         0x8001210C
    // 0x80800968: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80800968: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080096C: bne         $v0, $zero, L_808009C8
    if (ctx->r2 != 0) {
        // 0x80800970: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_808009C8;
    }
    // 0x80800970: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800974: jal         0x8008A110
    // 0x80800978: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800978: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x8080097C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800980: jal         0x800EE88C
    // 0x80800984: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80800984: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800988: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080098C: jal         0x800EE7F8
    // 0x80800990: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800990: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80800994: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800998: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080099C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808009A0: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(852, 0XCF0) << 16);
    // 0x808009A4: addiu       $t9, $t9, 0xCF0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(852, 0XCF0));
    // 0x808009A8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808009AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808009B0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808009B4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808009B8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x808009BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808009C0: jal         0x800BBCB8
    // 0x808009C4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x808009C4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_4:
L_808009C8:
    // 0x808009C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009CC:
    // 0x808009CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808009D0: jr          $ra
    // 0x808009D4: nop

    return;
    // 0x808009D4: nop

;}
RECOMP_FUNC void func_8009D4A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D4A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009D4AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D4B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8009D4B4: jal         0x8009C128
    // 0x8009D4B8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009D4B8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8009D4BC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8009D4C0: jal         0x800C4AF0
    // 0x8009D4C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800C4AF0(rdram, ctx);
        goto after_1;
    // 0x8009D4C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8009D4C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D4CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009D4D0: jr          $ra
    // 0x8009D4D4: nop

    return;
    // 0x8009D4D4: nop

;}
RECOMP_FUNC void func_808005A4_chjigsawcollect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808005A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808005AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808005B0: jr          $ra
    // 0x808005B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808005B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80800A4C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A4C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800A50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A5C: jal         0x80100094
    // 0x80800A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A64: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800A68: jal         0x80800000
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A70: jal         0x80806300
    // 0x80800A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80806300_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80800A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800A78: jal         0x80807B54
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807B54_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A80: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800A84: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80800A88: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80800A8C: sltiu       $at, $t7, 0x47
    ctx->r1 = ctx->r15 < 0X47 ? 1 : 0;
    // 0x80800A90: beq         $at, $zero, L_80801968
    if (ctx->r1 == 0) {
        // 0x80800A94: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80801968;
    }
    // 0x80800A94: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800A98: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X971C) << 16);
    // 0x80800A9C: addu        $at, $at, $t7
    gpr jr_addend_80800AA4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800AA0: lw          $t7, -0x68E4($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X971C));
    // 0x80800AA4: jr          $t7
    // 0x80800AA8: nop

    switch (jr_addend_80800AA4 >> 2) {
        case 0: goto L_80800AAC; break;
        case 1: goto L_80801968; break;
        case 2: goto L_80800AE0; break;
        case 3: goto L_80801968; break;
        case 4: goto L_80800B50; break;
        case 5: goto L_80800B70; break;
        case 6: goto L_80801968; break;
        case 7: goto L_80800BCC; break;
        case 8: goto L_80800BF4; break;
        case 9: goto L_80800C74; break;
        case 10: goto L_80800C94; break;
        case 11: goto L_80801968; break;
        case 12: goto L_80800CFC; break;
        case 13: goto L_80800D1C; break;
        case 14: goto L_80801968; break;
        case 15: goto L_80800D40; break;
        case 16: goto L_80800D68; break;
        case 17: goto L_80800DE8; break;
        case 18: goto L_80800E08; break;
        case 19: goto L_80801968; break;
        case 20: goto L_80800E8C; break;
        case 21: goto L_80800EAC; break;
        case 22: goto L_80801968; break;
        case 23: goto L_80800ED0; break;
        case 24: goto L_80800EF8; break;
        case 25: goto L_80800F68; break;
        case 26: goto L_80800F90; break;
        case 27: goto L_80801968; break;
        case 28: goto L_8080102C; break;
        case 29: goto L_8080104C; break;
        case 30: goto L_80801968; break;
        case 31: goto L_80801070; break;
        case 32: goto L_80801098; break;
        case 33: goto L_80801108; break;
        case 34: goto L_80801130; break;
        case 35: goto L_80801968; break;
        case 36: goto L_808011B8; break;
        case 37: goto L_80801204; break;
        case 38: goto L_8080124C; break;
        case 39: goto L_80801968; break;
        case 40: goto L_80801270; break;
        case 41: goto L_80801298; break;
        case 42: goto L_808012CC; break;
        case 43: goto L_80801310; break;
        case 44: goto L_80801324; break;
        case 45: goto L_80801370; break;
        case 46: goto L_80801968; break;
        case 47: goto L_80801390; break;
        case 48: goto L_808013D8; break;
        case 49: goto L_808013FC; break;
        case 50: goto L_80801424; break;
        case 51: goto L_8080144C; break;
        case 52: goto L_80801480; break;
        case 53: goto L_808014A4; break;
        case 54: goto L_808014B8; break;
        case 55: goto L_80801968; break;
        case 56: goto L_80801598; break;
        case 57: goto L_80801968; break;
        case 58: goto L_80801658; break;
        case 59: goto L_80801968; break;
        case 60: goto L_80801728; break;
        case 61: goto L_80801968; break;
        case 62: goto L_80801804; break;
        case 63: goto L_80801814; break;
        case 64: goto L_80801968; break;
        case 65: goto L_80801838; break;
        case 66: goto L_80801878; break;
        case 67: goto L_808018D4; break;
        case 68: goto L_80801968; break;
        case 69: goto L_80801930; break;
        case 70: goto L_80801968; break;
        default: switch_error(__func__, 0x80800AA4, 0x8080971C);
    }
    // 0x80800AA8: nop

L_80800AAC:
    // 0x80800AAC: jal         0x80101DDC
    // 0x80800AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_4;
    // 0x80800AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800AB4: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800AB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ABC: addiu       $a1, $zero, 0x171E
    ctx->r5 = ADD32(0, 0X171E);
    // 0x80800AC0: jal         0x80803660
    // 0x80800AC4: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80800AC4: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_5:
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ACC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800AD0: jal         0x80803BE8
    // 0x80800AD4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80800AD4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_6:
    // 0x80800AD8: b           L_8080196C
    // 0x80800ADC: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800ADC: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800AE0:
    // 0x80800AE0: jal         0x80101DDC
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_7;
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800AE8: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800AEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF0: jal         0x80802170
    // 0x80800AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80800AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800AF8: bne         $v0, $zero, L_80800B34
    if (ctx->r2 != 0) {
        // 0x80800AFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B34;
    }
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B00: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800B04: jal         0x80803BE8
    // 0x80800B08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80800B08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B10: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80800B14: jal         0x8080290C
    // 0x80800B18: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x80800B18: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_10:
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B20: addiu       $a1, $zero, 0x1720
    ctx->r5 = ADD32(0, 0X1720);
    // 0x80800B24: jal         0x80803660
    // 0x80800B28: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x80800B28: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    after_11:
    // 0x80800B2C: b           L_8080196C
    // 0x80800B30: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800B30: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800B34:
    // 0x80800B34: jal         0x800FDC28
    // 0x80800B38: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800FDC28(rdram, ctx);
        goto after_12;
    // 0x80800B38: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_12:
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B40: jal         0x80805A00
    // 0x80800B44: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80805A00_chdiggerboss(rdram, ctx);
        goto after_13;
    // 0x80800B44: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_13:
    // 0x80800B48: b           L_8080196C
    // 0x80800B4C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800B4C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800B50:
    // 0x80800B50: jal         0x80805A64
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80805A64_chdiggerboss(rdram, ctx);
        goto after_14;
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800B58: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800B5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B60: jal         0x80802F00
    // 0x80800B64: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80802F00_chdiggerboss(rdram, ctx);
        goto after_15;
    // 0x80800B64: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_15:
    // 0x80800B68: b           L_8080196C
    // 0x80800B6C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800B6C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800B70:
    // 0x80800B70: jal         0x80101DDC
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_16;
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800B78: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800B7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B80: jal         0x80802170
    // 0x80800B84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_17;
    // 0x80800B84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800B88: bne         $v0, $zero, L_80800BB8
    if (ctx->r2 != 0) {
        // 0x80800B8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BB8;
    }
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B94: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800B98: jal         0x80803BE8
    // 0x80800B9C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_18;
    // 0x80800B9C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_18:
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA4: addiu       $a1, $zero, 0x172E
    ctx->r5 = ADD32(0, 0X172E);
    // 0x80800BA8: jal         0x80803660
    // 0x80800BAC: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_19;
    // 0x80800BAC: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_19:
    // 0x80800BB0: b           L_8080196C
    // 0x80800BB4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800BB4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800BB8:
    // 0x80800BB8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800BBC: jal         0x80802FEC
    // 0x80800BC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802FEC_chdiggerboss(rdram, ctx);
        goto after_20;
    // 0x80800BC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x80800BC4: b           L_8080196C
    // 0x80800BC8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800BC8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800BCC:
    // 0x80800BCC: jal         0x80802D00
    // 0x80800BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D00_chdiggerboss(rdram, ctx);
        goto after_21;
    // 0x80800BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800BD4: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800BD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BDC: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9C60) << 16);
    // 0x80800BE0: addiu       $a2, $a2, -0x63A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9C60));
    // 0x80800BE4: jal         0x80806A78
    // 0x80800BE8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_22;
    // 0x80800BE8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_22:
    // 0x80800BEC: b           L_8080196C
    // 0x80800BF0: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800BF0: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800BF4:
    // 0x80800BF4: jal         0x808066A0
    // 0x80800BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808066A0_chdiggerboss(rdram, ctx);
        goto after_23;
    // 0x80800BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800BFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C00: beq         $v0, $at, L_80800C1C
    if (ctx->r2 == ctx->r1) {
        // 0x80800C04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C1C;
    }
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C0C: beq         $v0, $at, L_80800C40
    if (ctx->r2 == ctx->r1) {
        // 0x80800C10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C40;
    }
    // 0x80800C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C14: b           L_8080196C
    // 0x80800C18: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800C18: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800C1C:
    // 0x80800C1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800C20: jal         0x80802878
    // 0x80800C24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_24;
    // 0x80800C24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_24:
    // 0x80800C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C2C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800C30: jal         0x80803BE8
    // 0x80800C34: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_25;
    // 0x80800C34: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_25:
    // 0x80800C38: b           L_8080196C
    // 0x80800C3C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800C3C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800C40:
    // 0x80800C40: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800C44: jal         0x80803BE8
    // 0x80800C48: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_26;
    // 0x80800C48: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_26:
    // 0x80800C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C50: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800C54: jal         0x80802878
    // 0x80800C58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_27;
    // 0x80800C58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_27:
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C60: addiu       $a1, $zero, 0x1731
    ctx->r5 = ADD32(0, 0X1731);
    // 0x80800C64: jal         0x80803660
    // 0x80800C68: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_28;
    // 0x80800C68: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_28:
    // 0x80800C6C: b           L_8080196C
    // 0x80800C70: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800C70: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800C74:
    // 0x80800C74: jal         0x80101DDC
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_29;
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800C7C: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800C80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C84: jal         0x80805A00
    // 0x80800C88: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80805A00_chdiggerboss(rdram, ctx);
        goto after_30;
    // 0x80800C88: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_30:
    // 0x80800C8C: b           L_8080196C
    // 0x80800C90: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800C90: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800C94:
    // 0x80800C94: jal         0x80101DDC
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_31;
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800C9C: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800CA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA4: jal         0x80802170
    // 0x80800CA8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_32;
    // 0x80800CA8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_32:
    // 0x80800CAC: bne         $v0, $zero, L_80800CEC
    if (ctx->r2 != 0) {
        // 0x80800CB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CEC;
    }
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CB8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80800CBC: jal         0x80803BE8
    // 0x80800CC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_33;
    // 0x80800CC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_33:
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC8: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x80800CCC: jal         0x8080290C
    // 0x80800CD0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_34;
    // 0x80800CD0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_34:
    // 0x80800CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CD8: addiu       $a1, $zero, 0x1721
    ctx->r5 = ADD32(0, 0X1721);
    // 0x80800CDC: jal         0x80803660
    // 0x80800CE0: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_35;
    // 0x80800CE0: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    after_35:
    // 0x80800CE4: b           L_8080196C
    // 0x80800CE8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800CE8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800CEC:
    // 0x80800CEC: jal         0x80805A00
    // 0x80800CF0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80805A00_chdiggerboss(rdram, ctx);
        goto after_36;
    // 0x80800CF0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_36:
    // 0x80800CF4: b           L_8080196C
    // 0x80800CF8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800CF8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800CFC:
    // 0x80800CFC: jal         0x80805A64
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80805A64_chdiggerboss(rdram, ctx);
        goto after_37;
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800D04: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800D08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D0C: jal         0x80802F00
    // 0x80800D10: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80802F00_chdiggerboss(rdram, ctx);
        goto after_38;
    // 0x80800D10: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_38:
    // 0x80800D14: b           L_8080196C
    // 0x80800D18: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800D18: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800D1C:
    // 0x80800D1C: jal         0x80101DDC
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_39;
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80800D24: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800D28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D2C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80800D30: jal         0x80802FEC
    // 0x80800D34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802FEC_chdiggerboss(rdram, ctx);
        goto after_40;
    // 0x80800D34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_40:
    // 0x80800D38: b           L_8080196C
    // 0x80800D3C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800D3C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800D40:
    // 0x80800D40: jal         0x80802D00
    // 0x80800D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D00_chdiggerboss(rdram, ctx);
        goto after_41;
    // 0x80800D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80800D48: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800D4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D50: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9C70) << 16);
    // 0x80800D54: addiu       $a2, $a2, -0x6390
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9C70));
    // 0x80800D58: jal         0x80806A78
    // 0x80800D5C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_42;
    // 0x80800D5C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_42:
    // 0x80800D60: b           L_8080196C
    // 0x80800D64: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800D64: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800D68:
    // 0x80800D68: jal         0x808066A0
    // 0x80800D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808066A0_chdiggerboss(rdram, ctx);
        goto after_43;
    // 0x80800D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80800D70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D74: beq         $v0, $at, L_80800D90
    if (ctx->r2 == ctx->r1) {
        // 0x80800D78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D90;
    }
    // 0x80800D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D80: beq         $v0, $at, L_80800DB4
    if (ctx->r2 == ctx->r1) {
        // 0x80800D84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DB4;
    }
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D88: b           L_8080196C
    // 0x80800D8C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800D8C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800D90:
    // 0x80800D90: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800D94: jal         0x80802878
    // 0x80800D98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_44;
    // 0x80800D98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_44:
    // 0x80800D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DA0: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80800DA4: jal         0x80803BE8
    // 0x80800DA8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_45;
    // 0x80800DA8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_45:
    // 0x80800DAC: b           L_8080196C
    // 0x80800DB0: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800DB0: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800DB4:
    // 0x80800DB4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800DB8: jal         0x80803BE8
    // 0x80800DBC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_46;
    // 0x80800DBC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_46:
    // 0x80800DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800DC8: jal         0x80802878
    // 0x80800DCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_47;
    // 0x80800DCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_47:
    // 0x80800DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD4: addiu       $a1, $zero, 0x1732
    ctx->r5 = ADD32(0, 0X1732);
    // 0x80800DD8: jal         0x80803660
    // 0x80800DDC: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_48;
    // 0x80800DDC: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_48:
    // 0x80800DE0: b           L_8080196C
    // 0x80800DE4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800DE4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800DE8:
    // 0x80800DE8: jal         0x80101DDC
    // 0x80800DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_49;
    // 0x80800DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80800DF0: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800DF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF8: jal         0x80805A00
    // 0x80800DFC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80805A00_chdiggerboss(rdram, ctx);
        goto after_50;
    // 0x80800DFC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_50:
    // 0x80800E00: b           L_8080196C
    // 0x80800E04: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800E04: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800E08:
    // 0x80800E08: jal         0x80101DDC
    // 0x80800E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_51;
    // 0x80800E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80800E10: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800E14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E18: jal         0x80802170
    // 0x80800E1C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_52;
    // 0x80800E1C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_52:
    // 0x80800E20: bne         $v0, $zero, L_80800E5C
    if (ctx->r2 != 0) {
        // 0x80800E24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E5C;
    }
    // 0x80800E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E28: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80800E2C: jal         0x80803BE8
    // 0x80800E30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_53;
    // 0x80800E30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_53:
    // 0x80800E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E38: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x80800E3C: jal         0x8080290C
    // 0x80800E40: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_54;
    // 0x80800E40: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_54:
    // 0x80800E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E48: addiu       $a1, $zero, 0x1723
    ctx->r5 = ADD32(0, 0X1723);
    // 0x80800E4C: jal         0x80803660
    // 0x80800E50: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_55;
    // 0x80800E50: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    after_55:
    // 0x80800E54: b           L_8080196C
    // 0x80800E58: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800E58: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800E5C:
    // 0x80800E5C: jal         0x80802228
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_56;
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x80800E64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E68: jal         0x8080041C
    // 0x80800E6C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_57;
    // 0x80800E6C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_57:
    // 0x80800E70: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CF0) << 16);
    // 0x80800E74: addiu       $a2, $a2, -0x6310
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CF0));
    // 0x80800E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E7C: jal         0x80807280
    // 0x80800E80: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_80807280_chdiggerboss(rdram, ctx);
        goto after_58;
    // 0x80800E80: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_58:
    // 0x80800E84: b           L_8080196C
    // 0x80800E88: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800E88: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800E8C:
    // 0x80800E8C: jal         0x808070B0
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808070B0_chdiggerboss(rdram, ctx);
        goto after_59;
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x80800E94: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800E98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E9C: jal         0x80802F00
    // 0x80800EA0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_80802F00_chdiggerboss(rdram, ctx);
        goto after_60;
    // 0x80800EA0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_60:
    // 0x80800EA4: b           L_8080196C
    // 0x80800EA8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800EA8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800EAC:
    // 0x80800EAC: jal         0x80101DDC
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_61;
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80800EB4: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800EB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EBC: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80800EC0: jal         0x80802FEC
    // 0x80800EC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802FEC_chdiggerboss(rdram, ctx);
        goto after_62;
    // 0x80800EC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_62:
    // 0x80800EC8: b           L_8080196C
    // 0x80800ECC: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800ECC: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800ED0:
    // 0x80800ED0: jal         0x80802D00
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D00_chdiggerboss(rdram, ctx);
        goto after_63;
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x80800ED8: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800EDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE0: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9C80) << 16);
    // 0x80800EE4: addiu       $a2, $a2, -0x6380
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9C80));
    // 0x80800EE8: jal         0x80806A78
    // 0x80800EEC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_64;
    // 0x80800EEC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_64:
    // 0x80800EF0: b           L_8080196C
    // 0x80800EF4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800EF4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800EF8:
    // 0x80800EF8: jal         0x808066A0
    // 0x80800EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808066A0_chdiggerboss(rdram, ctx);
        goto after_65;
    // 0x80800EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x80800F00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F04: beq         $v0, $at, L_80800F20
    if (ctx->r2 == ctx->r1) {
        // 0x80800F08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F20;
    }
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F10: beq         $v0, $at, L_80800F44
    if (ctx->r2 == ctx->r1) {
        // 0x80800F14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F44;
    }
    // 0x80800F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F18: b           L_8080196C
    // 0x80800F1C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800F1C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800F20:
    // 0x80800F20: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800F24: jal         0x80802878
    // 0x80800F28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_66;
    // 0x80800F28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_66:
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F30: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80800F34: jal         0x80803BE8
    // 0x80800F38: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_67;
    // 0x80800F38: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_67:
    // 0x80800F3C: b           L_8080196C
    // 0x80800F40: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800F40: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800F44:
    // 0x80800F44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800F48: jal         0x80802878
    // 0x80800F4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_68;
    // 0x80800F4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_68:
    // 0x80800F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F54: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80800F58: jal         0x80803BE8
    // 0x80800F5C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_69;
    // 0x80800F5C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_69:
    // 0x80800F60: b           L_8080196C
    // 0x80800F64: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800F64: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800F68:
    // 0x80800F68: jal         0x80101DDC
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_70;
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_70:
    // 0x80800F70: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800F74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F78: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CF0) << 16);
    // 0x80800F7C: addiu       $a2, $a2, -0x6310
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CF0));
    // 0x80800F80: jal         0x80807280
    // 0x80800F84: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_80807280_chdiggerboss(rdram, ctx);
        goto after_71;
    // 0x80800F84: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_71:
    // 0x80800F88: b           L_8080196C
    // 0x80800F8C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800F8C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800F90:
    // 0x80800F90: jal         0x80101DDC
    // 0x80800F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_72;
    // 0x80800F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_72:
    // 0x80800F98: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80800F9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA0: jal         0x80802170
    // 0x80800FA4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_73;
    // 0x80800FA4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_73:
    // 0x80800FA8: bne         $v0, $zero, L_80800FFC
    if (ctx->r2 != 0) {
        // 0x80800FAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FFC;
    }
    // 0x80800FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FB0: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80800FB4: jal         0x80803BE8
    // 0x80800FB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_74;
    // 0x80800FB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_74:
    // 0x80800FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FC0: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x80800FC4: jal         0x8080290C
    // 0x80800FC8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_75;
    // 0x80800FC8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_75:
    // 0x80800FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD0: addiu       $a1, $zero, 0x1724
    ctx->r5 = ADD32(0, 0X1724);
    // 0x80800FD4: jal         0x80803660
    // 0x80800FD8: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_76;
    // 0x80800FD8: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    after_76:
    // 0x80800FDC: jal         0x80802228
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_77;
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_77:
    // 0x80800FE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FE8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800FEC: jal         0x808008C0
    // 0x80800FF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_78;
    // 0x80800FF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_78:
    // 0x80800FF4: b           L_8080196C
    // 0x80800FF8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80800FF8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80800FFC:
    // 0x80800FFC: jal         0x80802228
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_79;
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_79:
    // 0x80801004: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801008: jal         0x8080041C
    // 0x8080100C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_80;
    // 0x8080100C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_80:
    // 0x80801010: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9D00) << 16);
    // 0x80801014: addiu       $a2, $a2, -0x6300
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9D00));
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080101C: jal         0x80807280
    // 0x80801020: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_80807280_chdiggerboss(rdram, ctx);
        goto after_81;
    // 0x80801020: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_81:
    // 0x80801024: b           L_8080196C
    // 0x80801028: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801028: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_8080102C:
    // 0x8080102C: jal         0x808070B0
    // 0x80801030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808070B0_chdiggerboss(rdram, ctx);
        goto after_82;
    // 0x80801030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_82:
    // 0x80801034: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80801038: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80801038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080103C: jal         0x80802F00
    // 0x80801040: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    func_80802F00_chdiggerboss(rdram, ctx);
        goto after_83;
    // 0x80801040: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_83:
    // 0x80801044: b           L_8080196C
    // 0x80801048: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801048: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_8080104C:
    // 0x8080104C: jal         0x80101DDC
    // 0x80801050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_84;
    // 0x80801050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_84:
    // 0x80801054: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80801058: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80801058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080105C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80801060: jal         0x80802FEC
    // 0x80801064: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802FEC_chdiggerboss(rdram, ctx);
        goto after_85;
    // 0x80801064: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_85:
    // 0x80801068: b           L_8080196C
    // 0x8080106C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x8080106C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801070:
    // 0x80801070: jal         0x80802D00
    // 0x80801074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D00_chdiggerboss(rdram, ctx);
        goto after_86;
    // 0x80801074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_86:
    // 0x80801078: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x8080107C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801080: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9C90) << 16);
    // 0x80801084: addiu       $a2, $a2, -0x6370
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9C90));
    // 0x80801088: jal         0x80806A78
    // 0x8080108C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_87;
    // 0x8080108C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_87:
    // 0x80801090: b           L_8080196C
    // 0x80801094: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801094: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801098:
    // 0x80801098: jal         0x808066A0
    // 0x8080109C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808066A0_chdiggerboss(rdram, ctx);
        goto after_88;
    // 0x8080109C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_88:
    // 0x808010A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808010A4: beq         $v0, $at, L_808010C0
    if (ctx->r2 == ctx->r1) {
        // 0x808010A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010C0;
    }
    // 0x808010A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808010B0: beq         $v0, $at, L_808010E4
    if (ctx->r2 == ctx->r1) {
        // 0x808010B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010E4;
    }
    // 0x808010B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B8: b           L_8080196C
    // 0x808010BC: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808010BC: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808010C0:
    // 0x808010C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808010C4: jal         0x80802878
    // 0x808010C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_89;
    // 0x808010C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_89:
    // 0x808010CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010D0: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x808010D4: jal         0x80803BE8
    // 0x808010D8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_90;
    // 0x808010D8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_90:
    // 0x808010DC: b           L_8080196C
    // 0x808010E0: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808010E0: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808010E4:
    // 0x808010E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808010E8: jal         0x80802878
    // 0x808010EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_91;
    // 0x808010EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_91:
    // 0x808010F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010F4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x808010F8: jal         0x80803BE8
    // 0x808010FC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_92;
    // 0x808010FC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_92:
    // 0x80801100: b           L_8080196C
    // 0x80801104: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801104: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801108:
    // 0x80801108: jal         0x80101DDC
    // 0x8080110C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_93;
    // 0x8080110C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_93:
    // 0x80801110: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80801114: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80801114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801118: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9D00) << 16);
    // 0x8080111C: addiu       $a2, $a2, -0x6300
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9D00));
    // 0x80801120: jal         0x80807280
    // 0x80801124: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_80807280_chdiggerboss(rdram, ctx);
        goto after_94;
    // 0x80801124: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_94:
    // 0x80801128: b           L_8080196C
    // 0x8080112C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x8080112C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801130:
    // 0x80801130: jal         0x80101DDC
    // 0x80801134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_95;
    // 0x80801134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_95:
    // 0x80801138: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x8080113C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x8080113C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801140: jal         0x80802170
    // 0x80801144: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_96;
    // 0x80801144: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_96:
    // 0x80801148: bne         $v0, $zero, L_80801184
    if (ctx->r2 != 0) {
        // 0x8080114C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801184;
    }
    // 0x8080114C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801150: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    // 0x80801154: jal         0x80803BE8
    // 0x80801158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_97;
    // 0x80801158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_97:
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801160: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x80801164: jal         0x8080290C
    // 0x80801168: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_98;
    // 0x80801168: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_98:
    // 0x8080116C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801170: addiu       $a1, $zero, 0x1725
    ctx->r5 = ADD32(0, 0X1725);
    // 0x80801174: jal         0x80803660
    // 0x80801178: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_99;
    // 0x80801178: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    after_99:
    // 0x8080117C: b           L_8080196C
    // 0x80801180: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801180: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801184:
    // 0x80801184: jal         0x80802228
    // 0x80801188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_100;
    // 0x80801188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_100:
    // 0x8080118C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801190: jal         0x8080041C
    // 0x80801194: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_101;
    // 0x80801194: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_101:
    // 0x80801198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080119C: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x808011A0: jal         0x80803BE8
    // 0x808011A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_102;
    // 0x808011A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_102:
    // 0x808011A8: jal         0x808027F4
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808027F4_chdiggerboss(rdram, ctx);
        goto after_103;
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_103:
    // 0x808011B0: b           L_8080196C
    // 0x808011B4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808011B4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808011B8:
    // 0x808011B8: jal         0x80802228
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_104;
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_104:
    // 0x808011C0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808011C4: jal         0x801022E4
    // 0x808011C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_801022E4(rdram, ctx);
        goto after_105;
    // 0x808011C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_105:
    // 0x808011CC: bne         $v0, $zero, L_80801968
    if (ctx->r2 != 0) {
        // 0x808011D0: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80801968;
    }
    // 0x808011D0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808011D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808011D8: jal         0x80805448
    // 0x808011DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_106;
    // 0x808011DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_106:
    // 0x808011E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808011E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808011E8: jal         0x80805448
    // 0x808011EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_107;
    // 0x808011EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_107:
    // 0x808011F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011F4: jal         0x80805D64
    // 0x808011F8: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    func_80805D64_chdiggerboss(rdram, ctx);
        goto after_108;
    // 0x808011F8: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_108:
    // 0x808011FC: b           L_8080196C
    // 0x80801200: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801200: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801204:
    // 0x80801204: jal         0x80805DF4
    // 0x80801208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80805DF4_chdiggerboss(rdram, ctx);
        goto after_109;
    // 0x80801208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_109:
    // 0x8080120C: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80801210: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_80801968;
    }
    // 0x80801210: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80801214: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x80801218: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8080121C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801220: beq         $t9, $at, L_8080123C
    if (ctx->r25 == ctx->r1) {
        // 0x80801224: addiu       $a1, $zero, 0x2D
        ctx->r5 = ADD32(0, 0X2D);
            goto L_8080123C;
    }
    // 0x80801224: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80801228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080122C: jal         0x80802F00
    // 0x80801230: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_80802F00_chdiggerboss(rdram, ctx);
        goto after_110;
    // 0x80801230: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_110:
    // 0x80801234: b           L_8080196C
    // 0x80801238: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801238: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_8080123C:
    // 0x8080123C: jal         0x80807754
    // 0x80801240: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_80807754_chdiggerboss(rdram, ctx);
        goto after_111;
    // 0x80801240: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_111:
    // 0x80801244: b           L_8080196C
    // 0x80801248: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801248: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_8080124C:
    // 0x8080124C: jal         0x80101DDC
    // 0x80801250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_112;
    // 0x80801250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_112:
    // 0x80801254: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80801258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80801258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080125C: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80801260: jal         0x80802FEC
    // 0x80801264: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80802FEC_chdiggerboss(rdram, ctx);
        goto after_113;
    // 0x80801264: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_113:
    // 0x80801268: b           L_8080196C
    // 0x8080126C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x8080126C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801270:
    // 0x80801270: jal         0x80802D00
    // 0x80801274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D00_chdiggerboss(rdram, ctx);
        goto after_114;
    // 0x80801274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_114:
    // 0x80801278: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x8080127C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x8080127C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801280: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CA0) << 16);
    // 0x80801284: addiu       $a2, $a2, -0x6360
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CA0));
    // 0x80801288: jal         0x80806A78
    // 0x8080128C: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_115;
    // 0x8080128C: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_115:
    // 0x80801290: b           L_8080196C
    // 0x80801294: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801294: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801298:
    // 0x80801298: jal         0x808066A0
    // 0x8080129C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808066A0_chdiggerboss(rdram, ctx);
        goto after_116;
    // 0x8080129C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_116:
    // 0x808012A0: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x808012A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x808012A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808012AC: jal         0x80802878
    // 0x808012B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_117;
    // 0x808012B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_117:
    // 0x808012B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012B8: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x808012BC: jal         0x80803BE8
    // 0x808012C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_118;
    // 0x808012C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_118:
    // 0x808012C4: b           L_8080196C
    // 0x808012C8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808012C8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808012CC:
    // 0x808012CC: jal         0x80101DDC
    // 0x808012D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_119;
    // 0x808012D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_119:
    // 0x808012D4: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x808012D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x808012D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012DC: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x808012E0: jal         0x80807754
    // 0x808012E4: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_80807754_chdiggerboss(rdram, ctx);
        goto after_120;
    // 0x808012E4: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_120:
    // 0x808012E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012EC: jal         0x80802170
    // 0x808012F0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_121;
    // 0x808012F0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_121:
    // 0x808012F4: bne         $v0, $zero, L_80801968
    if (ctx->r2 != 0) {
        // 0x808012F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x808012F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012FC: addiu       $a1, $zero, 0x1727
    ctx->r5 = ADD32(0, 0X1727);
    // 0x80801300: jal         0x80803660
    // 0x80801304: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_122;
    // 0x80801304: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    after_122:
    // 0x80801308: b           L_8080196C
    // 0x8080130C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x8080130C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801310:
    // 0x80801310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801314: jal         0x8080783C
    // 0x80801318: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    func_8080783C_chdiggerboss(rdram, ctx);
        goto after_123;
    // 0x80801318: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_123:
    // 0x8080131C: b           L_8080196C
    // 0x80801320: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801320: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801324:
    // 0x80801324: jal         0x80101DDC
    // 0x80801328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_124;
    // 0x80801328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_124:
    // 0x8080132C: beql        $v0, $zero, L_8080196C
    if (ctx->r2 == 0) {
        // 0x80801330: lw          $t6, 0x70($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X70);
            goto L_8080196C;
    }
    goto skip_0;
    // 0x80801330: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
    skip_0:
    // 0x80801334: jal         0x800F54E4
    // 0x80801338: nop

    func_800F54E4(rdram, ctx);
        goto after_125;
    // 0x80801338: nop

    after_125:
    // 0x8080133C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801340: jal         0x800F82D4
    // 0x80801344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_126;
    // 0x80801344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_126:
    // 0x80801348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080134C: addiu       $a1, $zero, 0x1733
    ctx->r5 = ADD32(0, 0X1733);
    // 0x80801350: jal         0x80803660
    // 0x80801354: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_127;
    // 0x80801354: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_127:
    // 0x80801358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080135C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x80801360: jal         0x80803BE8
    // 0x80801364: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_128;
    // 0x80801364: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_128:
    // 0x80801368: b           L_8080196C
    // 0x8080136C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x8080136C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801370:
    // 0x80801370: jal         0x80101DDC
    // 0x80801374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_129;
    // 0x80801374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_129:
    // 0x80801378: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x8080137C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x8080137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801380: jal         0x80805D64
    // 0x80801384: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    func_80805D64_chdiggerboss(rdram, ctx);
        goto after_130;
    // 0x80801384: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_130:
    // 0x80801388: b           L_8080196C
    // 0x8080138C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x8080138C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801390:
    // 0x80801390: jal         0x80805DF4
    // 0x80801394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80805DF4_chdiggerboss(rdram, ctx);
        goto after_131;
    // 0x80801394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_131:
    // 0x80801398: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x8080139C: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80801968;
    }
    // 0x8080139C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x808013A0: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x808013A4: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x808013A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013AC: beq         $t1, $at, L_808013C8
    if (ctx->r9 == ctx->r1) {
        // 0x808013B0: addiu       $a1, $zero, 0x37
        ctx->r5 = ADD32(0, 0X37);
            goto L_808013C8;
    }
    // 0x808013B0: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x808013B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013B8: jal         0x80802F00
    // 0x808013BC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    func_80802F00_chdiggerboss(rdram, ctx);
        goto after_132;
    // 0x808013BC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_132:
    // 0x808013C0: b           L_8080196C
    // 0x808013C4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808013C4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808013C8:
    // 0x808013C8: jal         0x80807754
    // 0x808013CC: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80807754_chdiggerboss(rdram, ctx);
        goto after_133;
    // 0x808013CC: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_133:
    // 0x808013D0: b           L_8080196C
    // 0x808013D4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808013D4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808013D8:
    // 0x808013D8: jal         0x80101DDC
    // 0x808013DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_134;
    // 0x808013DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_134:
    // 0x808013E0: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x808013E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x808013E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013E8: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x808013EC: jal         0x80802FEC
    // 0x808013F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80802FEC_chdiggerboss(rdram, ctx);
        goto after_135;
    // 0x808013F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_135:
    // 0x808013F4: b           L_8080196C
    // 0x808013F8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808013F8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808013FC:
    // 0x808013FC: jal         0x80802D00
    // 0x80801400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D00_chdiggerboss(rdram, ctx);
        goto after_136;
    // 0x80801400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_136:
    // 0x80801404: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80801408: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80801408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080140C: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CB0) << 16);
    // 0x80801410: addiu       $a2, $a2, -0x6350
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CB0));
    // 0x80801414: jal         0x80806A78
    // 0x80801418: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_137;
    // 0x80801418: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_137:
    // 0x8080141C: b           L_8080196C
    // 0x80801420: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801420: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801424:
    // 0x80801424: jal         0x80802D00
    // 0x80801428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D00_chdiggerboss(rdram, ctx);
        goto after_138;
    // 0x80801428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_138:
    // 0x8080142C: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80801430: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80801430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801434: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CB0) << 16);
    // 0x80801438: addiu       $a2, $a2, -0x6350
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CB0));
    // 0x8080143C: jal         0x80806A78
    // 0x80801440: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_139;
    // 0x80801440: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_139:
    // 0x80801444: b           L_8080196C
    // 0x80801448: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801448: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_8080144C:
    // 0x8080144C: jal         0x808066A0
    // 0x80801450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808066A0_chdiggerboss(rdram, ctx);
        goto after_140;
    // 0x80801450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_140:
    // 0x80801454: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80801458: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80801458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080145C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801460: jal         0x80802878
    // 0x80801464: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_141;
    // 0x80801464: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_141:
    // 0x80801468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080146C: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x80801470: jal         0x80803BE8
    // 0x80801474: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_142;
    // 0x80801474: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_142:
    // 0x80801478: b           L_8080196C
    // 0x8080147C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x8080147C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801480:
    // 0x80801480: jal         0x80101DDC
    // 0x80801484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_143;
    // 0x80801484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_143:
    // 0x80801488: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x8080148C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x8080148C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801490: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x80801494: jal         0x80807754
    // 0x80801498: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80807754_chdiggerboss(rdram, ctx);
        goto after_144;
    // 0x80801498: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_144:
    // 0x8080149C: b           L_8080196C
    // 0x808014A0: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808014A0: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808014A4:
    // 0x808014A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014A8: jal         0x8080783C
    // 0x808014AC: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    func_8080783C_chdiggerboss(rdram, ctx);
        goto after_145;
    // 0x808014AC: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_145:
    // 0x808014B0: b           L_8080196C
    // 0x808014B4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808014B4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808014B8:
    // 0x808014B8: jal         0x80101DDC
    // 0x808014BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_146;
    // 0x808014BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_146:
    // 0x808014C0: beql        $v0, $zero, L_8080196C
    if (ctx->r2 == 0) {
        // 0x808014C4: lw          $t6, 0x70($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X70);
            goto L_8080196C;
    }
    goto skip_1;
    // 0x808014C4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
    skip_1:
    // 0x808014C8: jal         0x800F54E4
    // 0x808014CC: nop

    func_800F54E4(rdram, ctx);
        goto after_147;
    // 0x808014CC: nop

    after_147:
    // 0x808014D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808014D4: jal         0x800F82D4
    // 0x808014D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_148;
    // 0x808014D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_148:
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014E0: jal         0x80802170
    // 0x808014E4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_149;
    // 0x808014E4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_149:
    // 0x808014E8: bne         $v0, $zero, L_80801514
    if (ctx->r2 != 0) {
        // 0x808014EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801514;
    }
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014F0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x808014F4: jal         0x8080290C
    // 0x808014F8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_150;
    // 0x808014F8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_150:
    // 0x808014FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801500: addiu       $a1, $zero, 0x1734
    ctx->r5 = ADD32(0, 0X1734);
    // 0x80801504: jal         0x80803660
    // 0x80801508: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_151;
    // 0x80801508: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    after_151:
    // 0x8080150C: b           L_80801584
    // 0x80801510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801584;
    // 0x80801510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801514:
    // 0x80801514: jal         0x80802228
    // 0x80801518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_152;
    // 0x80801518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_152:
    // 0x8080151C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80801520: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801524: jal         0x80804A50
    // 0x80801528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80804A50_chdiggerboss(rdram, ctx);
        goto after_153;
    // 0x80801528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_153:
    // 0x8080152C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801530: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80801534:
    // 0x80801534: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80801538: jal         0x80805448
    // 0x8080153C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_154;
    // 0x8080153C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_154:
    // 0x80801540: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801544: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801548: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8080154C: bnel        $a1, $at, L_80801534
    if (ctx->r5 != ctx->r1) {
        // 0x80801550: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80801534;
    }
    goto skip_2;
    // 0x80801550: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x80801554: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801558: jal         0x808041E4
    // 0x8080155C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808041E4_chdiggerboss(rdram, ctx);
        goto after_155;
    // 0x8080155C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_155:
    // 0x80801560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801564: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801568: jal         0x80802878
    // 0x8080156C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_156;
    // 0x8080156C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_156:
    // 0x80801570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801574: addiu       $a1, $zero, 0x1729
    ctx->r5 = ADD32(0, 0X1729);
    // 0x80801578: jal         0x80803660
    // 0x8080157C: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_157;
    // 0x8080157C: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_157:
    // 0x80801580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801584:
    // 0x80801584: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x80801588: jal         0x80803BE8
    // 0x8080158C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_158;
    // 0x8080158C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_158:
    // 0x80801590: b           L_8080196C
    // 0x80801594: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801594: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801598:
    // 0x80801598: jal         0x808066A0
    // 0x8080159C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808066A0_chdiggerboss(rdram, ctx);
        goto after_159;
    // 0x8080159C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_159:
    // 0x808015A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808015A4: beq         $v0, $at, L_808015C0
    if (ctx->r2 == ctx->r1) {
        // 0x808015A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015C0;
    }
    // 0x808015A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808015B0: beq         $v0, $at, L_808015D8
    if (ctx->r2 == ctx->r1) {
        // 0x808015B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015D8;
    }
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015B8: b           L_8080196C
    // 0x808015BC: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808015BC: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808015C0:
    // 0x808015C0: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CC0) << 16);
    // 0x808015C4: addiu       $a2, $a2, -0x6340
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CC0));
    // 0x808015C8: jal         0x80806A78
    // 0x808015CC: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_160;
    // 0x808015CC: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    after_160:
    // 0x808015D0: b           L_8080196C
    // 0x808015D4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808015D4: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808015D8:
    // 0x808015D8: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x808015DC: jal         0x80803BE8
    // 0x808015E0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_161;
    // 0x808015E0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_161:
    // 0x808015E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015E8: jal         0x80802170
    // 0x808015EC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_162;
    // 0x808015EC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_162:
    // 0x808015F0: bne         $v0, $zero, L_8080161C
    if (ctx->r2 != 0) {
        // 0x808015F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080161C;
    }
    // 0x808015F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015F8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x808015FC: jal         0x8080290C
    // 0x80801600: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_163;
    // 0x80801600: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_163:
    // 0x80801604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801608: addiu       $a1, $zero, 0x172A
    ctx->r5 = ADD32(0, 0X172A);
    // 0x8080160C: jal         0x80803660
    // 0x80801610: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_164;
    // 0x80801610: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    after_164:
    // 0x80801614: b           L_8080196C
    // 0x80801618: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801618: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_8080161C:
    // 0x8080161C: jal         0x80802228
    // 0x80801620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_165;
    // 0x80801620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_165:
    // 0x80801624: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801628: jal         0x8080041C
    // 0x8080162C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_166;
    // 0x8080162C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_166:
    // 0x80801630: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CD0) << 16);
    // 0x80801634: addiu       $a2, $a2, -0x6330
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CD0));
    // 0x80801638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080163C: jal         0x80806A78
    // 0x80801640: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_167;
    // 0x80801640: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_167:
    // 0x80801644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801648: jal         0x80806EE4
    // 0x8080164C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80806EE4_chdiggerboss(rdram, ctx);
        goto after_168;
    // 0x8080164C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_168:
    // 0x80801650: b           L_8080196C
    // 0x80801654: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801654: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801658:
    // 0x80801658: jal         0x808066A0
    // 0x8080165C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808066A0_chdiggerboss(rdram, ctx);
        goto after_169;
    // 0x8080165C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_169:
    // 0x80801660: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801664: beq         $v0, $at, L_80801680
    if (ctx->r2 == ctx->r1) {
        // 0x80801668: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801680;
    }
    // 0x80801668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080166C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801670: beq         $v0, $at, L_80801698
    if (ctx->r2 == ctx->r1) {
        // 0x80801674: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801698;
    }
    // 0x80801674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801678: b           L_8080196C
    // 0x8080167C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x8080167C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801680:
    // 0x80801680: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CD0) << 16);
    // 0x80801684: addiu       $a2, $a2, -0x6330
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CD0));
    // 0x80801688: jal         0x80806A78
    // 0x8080168C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_170;
    // 0x8080168C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_170:
    // 0x80801690: b           L_8080196C
    // 0x80801694: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801694: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801698:
    // 0x80801698: jal         0x80802170
    // 0x8080169C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_171;
    // 0x8080169C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_171:
    // 0x808016A0: bne         $v0, $zero, L_808016DC
    if (ctx->r2 != 0) {
        // 0x808016A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808016DC;
    }
    // 0x808016A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016A8: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x808016AC: jal         0x80803BE8
    // 0x808016B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_172;
    // 0x808016B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_172:
    // 0x808016B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016B8: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x808016BC: jal         0x8080290C
    // 0x808016C0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_173;
    // 0x808016C0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_173:
    // 0x808016C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016C8: addiu       $a1, $zero, 0x172B
    ctx->r5 = ADD32(0, 0X172B);
    // 0x808016CC: jal         0x80803660
    // 0x808016D0: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_174;
    // 0x808016D0: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    after_174:
    // 0x808016D4: b           L_8080196C
    // 0x808016D8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808016D8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808016DC:
    // 0x808016DC: jal         0x80802228
    // 0x808016E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_175;
    // 0x808016E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_175:
    // 0x808016E4: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CE0) << 16);
    // 0x808016E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808016EC: addiu       $a2, $a2, -0x6320
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CE0));
    // 0x808016F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016F4: jal         0x80806A78
    // 0x808016F8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_176;
    // 0x808016F8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_176:
    // 0x808016FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801700: jal         0x80806EE4
    // 0x80801704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80806EE4_chdiggerboss(rdram, ctx);
        goto after_177;
    // 0x80801704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_177:
    // 0x80801708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080170C: jal         0x80807DC0
    // 0x80801710: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80807DC0_chdiggerboss(rdram, ctx);
        goto after_178;
    // 0x80801710: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_178:
    // 0x80801714: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801718: jal         0x808080C0
    // 0x8080171C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808080C0_chdiggerboss(rdram, ctx);
        goto after_179;
    // 0x8080171C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_179:
    // 0x80801720: b           L_8080196C
    // 0x80801724: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801724: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801728:
    // 0x80801728: jal         0x808066A0
    // 0x8080172C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808066A0_chdiggerboss(rdram, ctx);
        goto after_180;
    // 0x8080172C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_180:
    // 0x80801730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801734: beq         $v0, $at, L_80801750
    if (ctx->r2 == ctx->r1) {
        // 0x80801738: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801750;
    }
    // 0x80801738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080173C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801740: beq         $v0, $at, L_80801768
    if (ctx->r2 == ctx->r1) {
        // 0x80801744: nop
    
            goto L_80801768;
    }
    // 0x80801744: nop

    // 0x80801748: b           L_8080196C
    // 0x8080174C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x8080174C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801750:
    // 0x80801750: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9CE0) << 16);
    // 0x80801754: addiu       $a2, $a2, -0x6320
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9CE0));
    // 0x80801758: jal         0x80806A78
    // 0x8080175C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    func_80806A78_chdiggerboss(rdram, ctx);
        goto after_181;
    // 0x8080175C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_181:
    // 0x80801760: b           L_8080196C
    // 0x80801764: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801764: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801768:
    // 0x80801768: jal         0x80802228
    // 0x8080176C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_182;
    // 0x8080176C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_182:
    // 0x80801770: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801774: jal         0x808080C0
    // 0x80801778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808080C0_chdiggerboss(rdram, ctx);
        goto after_183;
    // 0x80801778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_183:
    // 0x8080177C: jal         0x80807DF4
    // 0x80801780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807DF4_chdiggerboss(rdram, ctx);
        goto after_184;
    // 0x80801780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_184:
    // 0x80801784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801788: jal         0x808021E8
    // 0x8080178C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808021E8_chdiggerboss(rdram, ctx);
        goto after_185;
    // 0x8080178C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_185:
    // 0x80801790: bne         $v0, $zero, L_808017DC
    if (ctx->r2 != 0) {
        // 0x80801794: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808017DC;
    }
    // 0x80801794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080179C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x808017A0: jal         0x80803BE8
    // 0x808017A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_186;
    // 0x808017A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_186:
    // 0x808017A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017AC: jal         0x80802BE0
    // 0x808017B0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_80802BE0_chdiggerboss(rdram, ctx);
        goto after_187;
    // 0x808017B0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_187:
    // 0x808017B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808017BC: jal         0x80802878
    // 0x808017C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_188;
    // 0x808017C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_188:
    // 0x808017C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017C8: addiu       $a1, $zero, 0x172C
    ctx->r5 = ADD32(0, 0X172C);
    // 0x808017CC: jal         0x80803660
    // 0x808017D0: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_189;
    // 0x808017D0: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_189:
    // 0x808017D4: b           L_8080196C
    // 0x808017D8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x808017D8: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_808017DC:
    // 0x808017DC: jal         0x80802BE0
    // 0x808017E0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80802BE0_chdiggerboss(rdram, ctx);
        goto after_190;
    // 0x808017E0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_190:
    // 0x808017E4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x808017E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808017EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017F0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x808017F4: jal         0x80808470
    // 0x808017F8: sb          $t2, 0xCD($t3)
    MEM_B(0XCD, ctx->r11) = ctx->r10;
    func_80808470_chdiggerboss(rdram, ctx);
        goto after_191;
    // 0x808017F8: sb          $t2, 0xCD($t3)
    MEM_B(0XCD, ctx->r11) = ctx->r10;
    after_191:
    // 0x808017FC: b           L_8080196C
    // 0x80801800: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801800: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801804:
    // 0x80801804: jal         0x80808258
    // 0x80801808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808258_chdiggerboss(rdram, ctx);
        goto after_192;
    // 0x80801808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_192:
    // 0x8080180C: b           L_8080196C
    // 0x80801810: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801810: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801814:
    // 0x80801814: jal         0x80101DDC
    // 0x80801818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_193;
    // 0x80801818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_193:
    // 0x8080181C: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80801820: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80801820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801824: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    // 0x80801828: jal         0x80803BE8
    // 0x8080182C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_194;
    // 0x8080182C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_194:
    // 0x80801830: b           L_8080196C
    // 0x80801834: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801834: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801838:
    // 0x80801838: jal         0x808091E4
    // 0x8080183C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808091E4_chdiggerboss(rdram, ctx);
        goto after_195;
    // 0x8080183C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_195:
    // 0x80801840: bne         $v0, $zero, L_80801968
    if (ctx->r2 != 0) {
        // 0x80801844: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80801844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801848: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080184C: jal         0x80802878
    // 0x80801850: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_196;
    // 0x80801850: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_196:
    // 0x80801854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801858: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x8080185C: jal         0x80803BE8
    // 0x80801860: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_197;
    // 0x80801860: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_197:
    // 0x80801864: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9838) << 16);
    // 0x80801868: lwc1        $f4, -0x67C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9838));
    // 0x8080186C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80801870: b           L_80801968
    // 0x80801874: swc1        $f4, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f4.u32l;
        goto L_80801968;
    // 0x80801874: swc1        $f4, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f4.u32l;
L_80801878:
    // 0x80801878: jal         0x800D9078
    // 0x8080187C: addiu       $a0, $v0, 0xF8
    ctx->r4 = ADD32(ctx->r2, 0XF8);
    func_800D9078(rdram, ctx);
        goto after_198;
    // 0x8080187C: addiu       $a0, $v0, 0xF8
    ctx->r4 = ADD32(ctx->r2, 0XF8);
    after_198:
    // 0x80801880: beql        $v0, $zero, L_8080196C
    if (ctx->r2 == 0) {
        // 0x80801884: lw          $t6, 0x70($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X70);
            goto L_8080196C;
    }
    goto skip_3;
    // 0x80801884: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
    skip_3:
    // 0x80801888: jal         0x80802248
    // 0x8080188C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_199;
    // 0x8080188C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_199:
    // 0x80801890: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80801894: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801898: jal         0x800F7B9C
    // 0x8080189C: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    func_800F7B9C(rdram, ctx);
        goto after_200;
    // 0x8080189C: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_200:
    // 0x808018A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808018A4: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x808018A8: jal         0x800F7C58
    // 0x808018AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800F7C58(rdram, ctx);
        goto after_201;
    // 0x808018AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_201:
    // 0x808018B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018B4: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x808018B8: jal         0x80803BE8
    // 0x808018BC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_202;
    // 0x808018BC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_202:
    // 0x808018C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808018C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808018C8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x808018CC: b           L_80801968
    // 0x808018D0: swc1        $f6, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f6.u32l;
        goto L_80801968;
    // 0x808018D0: swc1        $f6, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f6.u32l;
L_808018D4:
    // 0x808018D4: jal         0x800D9078
    // 0x808018D8: addiu       $a0, $v0, 0xF8
    ctx->r4 = ADD32(ctx->r2, 0XF8);
    func_800D9078(rdram, ctx);
        goto after_203;
    // 0x808018D8: addiu       $a0, $v0, 0xF8
    ctx->r4 = ADD32(ctx->r2, 0XF8);
    after_203:
    // 0x808018DC: beql        $v0, $zero, L_8080196C
    if (ctx->r2 == 0) {
        // 0x808018E0: lw          $t6, 0x70($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X70);
            goto L_8080196C;
    }
    goto skip_4;
    // 0x808018E0: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
    skip_4:
    // 0x808018E4: jal         0x800D395C
    // 0x808018E8: nop

    func_800D395C(rdram, ctx);
        goto after_204;
    // 0x808018E8: nop

    after_204:
    // 0x808018EC: beq         $v0, $zero, L_8080190C
    if (ctx->r2 == 0) {
        // 0x808018F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080190C;
    }
    // 0x808018F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018F4: jal         0x800FDC28
    // 0x808018F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_205;
    // 0x808018F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_205:
    // 0x808018FC: jal         0x80088180
    // 0x80801900: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_206;
    // 0x80801900: nop

    after_206:
    // 0x80801904: b           L_8080196C
    // 0x80801908: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x80801908: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_8080190C:
    // 0x8080190C: addiu       $a1, $zero, 0x14D8
    ctx->r5 = ADD32(0, 0X14D8);
    // 0x80801910: jal         0x80803660
    // 0x80801914: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_207;
    // 0x80801914: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_207:
    // 0x80801918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080191C: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x80801920: jal         0x80803BE8
    // 0x80801924: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_208;
    // 0x80801924: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_208:
    // 0x80801928: b           L_8080196C
    // 0x8080192C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
        goto L_8080196C;
    // 0x8080192C: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_80801930:
    // 0x80801930: jal         0x80101DDC
    // 0x80801934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_209;
    // 0x80801934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_209:
    // 0x80801938: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x8080193C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x8080193C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801940: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80801944: jal         0x80803BE8
    // 0x80801948: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_210;
    // 0x80801948: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_210:
    // 0x8080194C: jal         0x800D395C
    // 0x80801950: nop

    func_800D395C(rdram, ctx);
        goto after_211;
    // 0x80801950: nop

    after_211:
    // 0x80801954: beq         $v0, $zero, L_80801968
    if (ctx->r2 == 0) {
        // 0x80801958: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801968;
    }
    // 0x80801958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080195C: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80801960: jal         0x80803660
    // 0x80801964: addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_212;
    // 0x80801964: addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
    after_212:
L_80801968:
    // 0x80801968: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_8080196C:
    // 0x8080196C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801970: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x80801974: bgezl       $t8, L_80801998
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801978: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801998;
    }
    goto skip_5;
    // 0x80801978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8080197C: jal         0x80100094
    // 0x80801980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_213;
    // 0x80801980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_213:
    // 0x80801984: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801988: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8080198C: jal         0x800897D8
    // 0x80801990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_214;
    // 0x80801990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_214:
    // 0x80801994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801998:
    // 0x80801998: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080199C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808019A0: jr          $ra
    // 0x808019A4: nop

    return;
    // 0x808019A4: nop

;}
RECOMP_FUNC void _inantab_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F68: syscall     750
    recomp_syscall_handler(rdram, ctx, 0x80088F68);
    return;
    // 0x80088F6C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsblongleg_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800738: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080073C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(104, 0X1480) << 16);
    // 0x80800740: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800744: jr          $ra
    // 0x80800748: lw          $v0, 0x1480($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X1480));
    return;
    // 0x80800748: lw          $v0, 0x1480($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X1480));
;}
RECOMP_FUNC void func_800D0A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0A80: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800D0A84: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D0A88: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800D0A8C: lw          $t7, -0x50FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X50FC);
    // 0x800D0A90: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800D0A94: jr          $ra
    // 0x800D0A98: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    return;
    // 0x800D0A98: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
;}
RECOMP_FUNC void _bsdronefalldie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083090: syscall     41
    recomp_syscall_handler(rdram, ctx, 0x80083090);
    return;
    // 0x80083094: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800DC214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC21C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DC220: jal         0x800DC1AC
    // 0x800DC224: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DC1AC(rdram, ctx);
        goto after_0;
    // 0x800DC224: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800DC228: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800DC22C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800DC230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC234: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800DC238: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x800DC23C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800DC240: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800DC244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC248: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DC24C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800DC250: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800DC254: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800DC258: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800DC25C: jr          $ra
    // 0x800DC260: nop

    return;
    // 0x800DC260: nop

;}
