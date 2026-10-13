#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chjinjo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080017C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800180: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800184: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800188: jal         0x800D0C78
    // 0x8080018C: addiu       $a0, $a0, 0x51
    ctx->r4 = ADD32(ctx->r4, 0X51);
    func_800D0C78(rdram, ctx);
        goto after_0;
    // 0x8080018C: addiu       $a0, $a0, 0x51
    ctx->r4 = ADD32(ctx->r4, 0X51);
    after_0:
    // 0x80800190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800198: jr          $ra
    // 0x8080019C: nop

    return;
    // 0x8080019C: nop

;}
RECOMP_FUNC void func_800B43E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B43E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B43E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B43E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B43EC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800B43F0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800B43F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B43F8: addiu       $s1, $s1, 0x7F03
    ctx->r17 = ADD32(ctx->r17, 0X7F03);
    // 0x800B43FC: addiu       $s0, $s0, 0x7F00
    ctx->r16 = ADD32(ctx->r16, 0X7F00);
L_800B4400:
    // 0x800B4400: jal         0x800B5758
    // 0x800B4404: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800B5758(rdram, ctx);
        goto after_0;
    // 0x800B4404: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x800B4408: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B440C: bne         $s0, $s1, L_800B4400
    if (ctx->r16 != ctx->r17) {
        // 0x800B4410: sb          $v0, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r2;
            goto L_800B4400;
    }
    // 0x800B4410: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // 0x800B4414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4418: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B441C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B4420: jr          $ra
    // 0x800B4424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B4424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void dbzone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800194: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800198: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8080019C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808001A4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808001A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808001B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001B4: addiu       $a0, $sp, 0x3E
    ctx->r4 = ADD32(ctx->r29, 0X3E);
    // 0x808001B8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x808001BC: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x808001C0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x808001C4: div.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x808001C8: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808001CC: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x808001D0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x808001D4: sub.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x808001D8: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x808001DC: beql        $v0, $a0, L_8080021C
    if (ctx->r2 == ctx->r4) {
        // 0x808001E0: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_8080021C;
    }
    goto skip_0;
    // 0x808001E0: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_0:
    // 0x808001E4: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_808001E8:
    // 0x808001E8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x808001EC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808001F0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x808001F4: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x808001F8: nop

    // 0x808001FC: sh          $t7, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r15;
    // 0x80800200: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800204: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800208: sub.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x8080020C: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80800210: bnel        $v0, $a0, L_808001E8
    if (ctx->r2 != ctx->r4) {
        // 0x80800214: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_808001E8;
    }
    goto skip_1;
    // 0x80800214: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_1:
    // 0x80800218: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_8080021C:
    // 0x8080021C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800220: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80800224: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80800228: nop

    // 0x8080022C: sh          $t7, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r15;
    // 0x80800230: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x80800234: addiu       $s0, $s2, 0x2
    ctx->r16 = ADD32(ctx->r18, 0X2);
    // 0x80800238: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8080023C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80800240: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80800244: addu        $s1, $t9, $s2
    ctx->r17 = ADD32(ctx->r25, ctx->r18);
    // 0x80800248: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8080024C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80800250: beq         $at, $zero, L_80800274
    if (ctx->r1 == 0) {
        // 0x80800254: addiu       $s2, $sp, 0x38
        ctx->r18 = ADD32(ctx->r29, 0X38);
            goto L_80800274;
    }
    // 0x80800254: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
L_80800258:
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: jal         0x8080010C
    // 0x80800260: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8080010C_dbzone(rdram, ctx);
        goto after_0;
    // 0x80800260: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80800264: addiu       $s0, $s0, 0xE
    ctx->r16 = ADD32(ctx->r16, 0XE);
    // 0x80800268: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x8080026C: bne         $at, $zero, L_80800258
    if (ctx->r1 != 0) {
        // 0x80800270: sb          $v0, -0x2($s0)
        MEM_B(-0X2, ctx->r16) = ctx->r2;
            goto L_80800258;
    }
    // 0x80800270: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
L_80800274:
    // 0x80800274: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800278: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080027C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800280: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800284: jr          $ra
    // 0x80800288: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800288: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void bababykaz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x800A3274
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800018: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8080001C: bnel        $v0, $at, L_80800044
    if (ctx->r2 != ctx->r1) {
        // 0x80800020: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800044;
    }
    goto skip_0;
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800024: jal         0x800EA068
    // 0x80800028: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800EA068(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x8080002C: bne         $v0, $zero, L_80800040
    if (ctx->r2 != 0) {
        // 0x80800030: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800040;
    }
    // 0x80800030: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80800038: jal         0x8009EA94
    // 0x8080003C: lwc1        $f12, 0x4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X4);
    func_8009EA94(rdram, ctx);
        goto after_2;
    // 0x8080003C: lwc1        $f12, 0x4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X4);
    after_2:
L_80800040:
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800044:
    // 0x80800044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void func_80800D28_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D30: jal         0x80800234
    // 0x80800D34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bssnowball_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800D34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D38: jal         0x800839C8
    // 0x80800D3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800D3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D48: jr          $ra
    // 0x80800D4C: nop

    return;
    // 0x80800D4C: nop

;}
RECOMP_FUNC void func_8010C668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C668: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C66C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C670: lw          $v1, 0x70($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X70);
    // 0x8010C674: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8010C678: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8010C67C: srl         $a3, $v1, 25
    ctx->r7 = S32(U32(ctx->r3) >> 25);
    // 0x8010C680: bnel        $a3, $zero, L_8010C694
    if (ctx->r7 != 0) {
        // 0x8010C684: lwc1        $f2, 0x4($a1)
        ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
            goto L_8010C694;
    }
    goto skip_0;
    // 0x8010C684: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x8010C688: b           L_8010C700
    // 0x8010C68C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010C700;
    // 0x8010C68C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010C690: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
L_8010C694:
    // 0x8010C694: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010C698: addiu       $a0, $a0, 0x6F50
    ctx->r4 = ADD32(ctx->r4, 0X6F50);
    // 0x8010C69C: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8010C6A0: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8010C6A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010C6A8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8010C6AC: nop

    // 0x8010C6B0: bc1f        L_8010C6BC
    if (!c1cs) {
        // 0x8010C6B4: nop
    
            goto L_8010C6BC;
    }
    // 0x8010C6B4: nop

    // 0x8010C6B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010C6BC:
    // 0x8010C6BC: beql        $v0, $zero, L_8010C704
    if (ctx->r2 == 0) {
        // 0x8010C6C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010C704;
    }
    goto skip_1;
    // 0x8010C6C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8010C6C4: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8010C6C8: sll         $a2, $v1, 22
    ctx->r6 = S32(ctx->r3 << 22);
    // 0x8010C6CC: srl         $t6, $a2, 26
    ctx->r14 = S32(U32(ctx->r6) >> 26);
    // 0x8010C6D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010C6D4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8010C6D8: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    // 0x8010C6DC: bc1f        L_8010C6E8
    if (!c1cs) {
        // 0x8010C6E0: nop
    
            goto L_8010C6E8;
    }
    // 0x8010C6E0: nop

    // 0x8010C6E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010C6E8:
    // 0x8010C6E8: beql        $v0, $zero, L_8010C704
    if (ctx->r2 == 0) {
        // 0x8010C6EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010C704;
    }
    goto skip_2;
    // 0x8010C6EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8010C6F0: jal         0x800CC338
    // 0x8010C6F4: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    func_800CC338(rdram, ctx);
        goto after_0;
    // 0x8010C6F4: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    after_0:
    // 0x8010C6F8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8010C6FC: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
L_8010C700:
    // 0x8010C700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010C704:
    // 0x8010C704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C708: jr          $ra
    // 0x8010C70C: nop

    return;
    // 0x8010C70C: nop

;}
RECOMP_FUNC void func_808004B4_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004C0: jal         0x8008E3E8
    // 0x808004C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8008E3E8(rdram, ctx);
        goto after_0;
    // 0x808004C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808004C8: beql        $v0, $zero, L_8080051C
    if (ctx->r2 == 0) {
        // 0x808004CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080051C;
    }
    goto skip_0;
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808004D0: jal         0x8009EF10
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808004D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004DC: bnel        $v0, $at, L_8080051C
    if (ctx->r2 != ctx->r1) {
        // 0x808004E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080051C;
    }
    goto skip_1;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808004E4: jal         0x8009EF1C
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZonePosition(rdram, ctx);
        goto after_2;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808004EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2DF0) << 16);
    // 0x808004F0: lwc1        $f4, 0x2DF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2DF0));
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808004FC: nop

    // 0x80800500: bc1fl       L_8080051C
    if (!c1cs) {
        // 0x80800504: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080051C;
    }
    goto skip_2;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800508: jal         0x800962B0
    // 0x8080050C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800962B0(rdram, ctx);
        goto after_3;
    // 0x8080050C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800510: b           L_80800528
    // 0x80800514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800528;
    // 0x80800514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080051C:
    // 0x8080051C: jal         0x800962B0
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800962B0(rdram, ctx);
        goto after_4;
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800524: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800528:
    // 0x80800528: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080052C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800530: jr          $ra
    // 0x80800534: nop

    return;
    // 0x80800534: nop

;}
RECOMP_FUNC void func_80800E0C_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800E14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800E18: jal         0x8080055C
    // 0x80800E1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bsbabykaz_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800E1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800E20: lui         $a2, 0x3F28
    ctx->r6 = S32(0X3F28 << 16);
    // 0x80800E24: ori         $a2, $a2, 0xF5C3
    ctx->r6 = ctx->r6 | 0XF5C3;
    // 0x80800E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E2C: jal         0x8008CB3C
    // 0x80800E30: addiu       $a1, $zero, 0xA6
    ctx->r5 = ADD32(0, 0XA6);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800E30: addiu       $a1, $zero, 0xA6
    ctx->r5 = ADD32(0, 0XA6);
    after_1:
    // 0x80800E34: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800E38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E40: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800E44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800E48: jal         0x8009FFD8
    // 0x80800E4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800E4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800E50: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800E54: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E5C: jal         0x8008C9BC
    // 0x80800E60: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_3;
    // 0x80800E60: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_3:
    // 0x80800E64: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(68, 0X1724) << 16);
    // 0x80800E68: lwc1        $f4, 0x1724($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(68, 0X1724));
    // 0x80800E6C: lui         $a3, 0x3F0A
    ctx->r7 = S32(0X3F0A << 16);
    // 0x80800E70: ori         $a3, $a3, 0x3D71
    ctx->r7 = ctx->r7 | 0X3D71;
    // 0x80800E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E78: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800E7C: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x80800E80: jal         0x8008C9F0
    // 0x80800E84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_4;
    // 0x80800E84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E8C: jal         0x8008CA30
    // 0x80800E90: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_5;
    // 0x80800E90: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x80800E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E98: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800E9C: jal         0x8009BFE4
    // 0x80800EA0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_6;
    // 0x80800EA0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_6:
    // 0x80800EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EA8: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800EAC: jal         0x8009C554
    // 0x80800EB0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_7;
    // 0x80800EB0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_7:
    // 0x80800EB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800EB8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800EBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800EC0: jr          $ra
    // 0x80800EC4: nop

    return;
    // 0x80800EC4: nop

;}
RECOMP_FUNC void func_80800210_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800214: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080021C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800220: beq         $a1, $at, L_80800248
    if (ctx->r5 == ctx->r1) {
        // 0x80800224: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80800248;
    }
    // 0x80800224: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800228: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080022C: beq         $a1, $at, L_8080027C
    if (ctx->r5 == ctx->r1) {
        // 0x80800230: addiu       $a0, $zero, 0x29E
        ctx->r4 = ADD32(0, 0X29E);
            goto L_8080027C;
    }
    // 0x80800230: addiu       $a0, $zero, 0x29E
    ctx->r4 = ADD32(0, 0X29E);
    // 0x80800234: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800238: beq         $a1, $at, L_80800264
    if (ctx->r5 == ctx->r1) {
        // 0x8080023C: addiu       $a0, $zero, 0x1B8
        ctx->r4 = ADD32(0, 0X1B8);
            goto L_80800264;
    }
    // 0x8080023C: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    // 0x80800240: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800244: bne         $a1, $at, L_80800290
    if (ctx->r5 != ctx->r1) {
        // 0x80800248: addiu       $a0, $zero, 0x155
        ctx->r4 = ADD32(0, 0X155);
            goto L_80800290;
    }
L_80800248:
    // 0x80800248: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    // 0x8080024C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800250: jal         0x801084B0
    // 0x80800254: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x80800254: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800258: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8080025C: b           L_80800290
    // 0x80800260: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80800290;
    // 0x80800260: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80800264:
    // 0x80800264: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800268: jal         0x801084B0
    // 0x8080026C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x8080026C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800270: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800274: b           L_80800290
    // 0x80800278: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80800290;
    // 0x80800278: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_8080027C:
    // 0x8080027C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800280: jal         0x801084B0
    // 0x80800284: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_801084B0(rdram, ctx);
        goto after_2;
    // 0x80800284: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x80800288: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8080028C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80800290:
    // 0x80800290: jal         0x800EA05C
    // 0x80800294: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x80800294: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800298: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x8080029C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A0: beq         $v0, $at, L_808002E8
    if (ctx->r2 == ctx->r1) {
        // 0x808002A4: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_808002E8;
    }
    // 0x808002A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808002A8: lui         $at, 0xC3EB
    ctx->r1 = S32(0XC3EB << 16);
    // 0x808002AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808002B0: lui         $at, 0x43EB
    ctx->r1 = S32(0X43EB << 16);
    // 0x808002B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002B8: jal         0x800DC178
    // 0x808002BC: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808002BC: nop

    after_4:
    // 0x808002C0: lui         $at, 0xC3EB
    ctx->r1 = S32(0XC3EB << 16);
    // 0x808002C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808002C8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808002CC: lui         $at, 0x43EB
    ctx->r1 = S32(0X43EB << 16);
    // 0x808002D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002D4: jal         0x800DC178
    // 0x808002D8: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x808002D8: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
    after_5:
    // 0x808002DC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808002E0: b           L_80800344
    // 0x808002E4: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_80800344;
    // 0x808002E4: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
L_808002E8:
    // 0x808002E8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808002EC: beq         $a2, $at, L_8080032C
    if (ctx->r6 == ctx->r1) {
        // 0x808002F0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1608, 0X4E08) << 16);
            goto L_8080032C;
    }
    // 0x808002F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4E08) << 16);
    // 0x808002F4: lwc1        $f12, 0x4E08($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E08));
    // 0x808002F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4E0C) << 16);
    // 0x808002FC: jal         0x800DC178
    // 0x80800300: lwc1        $f14, 0x4E0C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E0C));
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800300: lwc1        $f14, 0x4E0C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E0C));
    after_6:
    // 0x80800304: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800308: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4E10) << 16);
    // 0x8080030C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80800310: lwc1        $f12, 0x4E10($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E10));
    // 0x80800314: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4E14) << 16);
    // 0x80800318: jal         0x800DC178
    // 0x8080031C: lwc1        $f14, 0x4E14($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E14));
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x8080031C: lwc1        $f14, 0x4E14($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E14));
    after_7:
    // 0x80800320: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800324: b           L_80800344
    // 0x80800328: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_80800344;
    // 0x80800328: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
L_8080032C:
    // 0x8080032C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4E18) << 16);
    // 0x80800330: lwc1        $f4, 0x4E18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E18));
    // 0x80800334: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x80800338: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080033C: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80800340: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
L_80800344:
    // 0x80800344: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800348: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8080034C: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
    // 0x80800350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800354: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800358: jr          $ra
    // 0x8080035C: nop

    return;
    // 0x8080035C: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CF4: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x80802CF8: sh          $a1, 0x254($a0)
    MEM_H(0X254, ctx->r4) = ctx->r5;
    // 0x80802CFC: sh          $a2, 0x256($a0)
    MEM_H(0X256, ctx->r4) = ctx->r6;
    // 0x80802D00: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802D04: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80802D08: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80802D0C: swc1        $f8, 0x258($a0)
    MEM_W(0X258, ctx->r4) = ctx->f8.u32l;
    // 0x80802D10: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80802D14: jr          $ra
    // 0x80802D18: swc1        $f10, 0x25C($a0)
    MEM_W(0X25C, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80802D18: swc1        $f10, 0x25C($a0)
    MEM_W(0X25C, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_800A33A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A33A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A33A4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A33A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A33AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A33B0: lw          $a1, 0xA0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XA0);
    // 0x800A33B4: jal         0x800EE7F8
    // 0x800A33B8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800A33B8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x800A33BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A33C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A33C4: jr          $ra
    // 0x800A33C8: nop

    return;
    // 0x800A33C8: nop

;}
RECOMP_FUNC void bawandglow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: jal         0x800F53D0
    // 0x80800048: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x80800048: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080004C: lw          $t6, 0x148($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X148);
    // 0x80800050: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800054: addiu       $a1, $a1, 0x53B8
    ctx->r5 = ADD32(ctx->r5, 0X53B8);
    // 0x80800058: lbu         $t7, 0x10($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X10);
    // 0x8080005C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800060: beql        $t7, $zero, L_80800080
    if (ctx->r15 == 0) {
        // 0x80800064: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800080;
    }
    goto skip_0;
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800068: jal         0x800872F0
    // 0x8080006C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _chwandglow_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080006C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800070: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800074: lw          $t8, 0x148($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X148);
    // 0x80800078: sw          $v0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r2;
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800080:
    // 0x80800080: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void _chtntmineshoot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087390: syscall     559
    recomp_syscall_handler(rdram, ctx, 0x80087390);
    return;
    // 0x80087394: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bstaxi_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E98: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E98);
    return;
    // 0x80083E9C: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void func_800D05E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D05E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D05E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D05EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D05F0: bne         $a1, $at, L_800D0624
    if (ctx->r5 != ctx->r1) {
        // 0x800D05F4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800D0624;
    }
    // 0x800D05F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D05F8: jal         0x800CFC5C
    // 0x800D05FC: nop

    func_800CFC5C(rdram, ctx);
        goto after_0;
    // 0x800D05FC: nop

    after_0:
    // 0x800D0600: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D0604: beq         $v0, $at, L_800D0624
    if (ctx->r2 == ctx->r1) {
        // 0x800D0608: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_800D0624;
    }
    // 0x800D0608: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D060C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800D0610: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x800D0614: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D0618: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D061C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D0620: sw          $t6, -0x4E74($at)
    MEM_W(-0X4E74, ctx->r1) = ctx->r14;
L_800D0624:
    // 0x800D0624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D062C: jr          $ra
    // 0x800D0630: nop

    return;
    // 0x800D0630: nop

;}
RECOMP_FUNC void _bsthrow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EF0: syscall     97
    recomp_syscall_handler(rdram, ctx, 0x80083EF0);
    return;
    // 0x80083EF4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bashoes_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002DC: lw          $t6, 0x10C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10C);
    // 0x808002E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002E4: sb          $zero, 0x10($t6)
    MEM_B(0X10, ctx->r14) = 0;
    // 0x808002E8: lw          $t7, 0x10C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10C);
    // 0x808002EC: swc1        $f4, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f4.u32l;
    // 0x808002F0: lw          $t8, 0x10C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10C);
    // 0x808002F4: sb          $zero, 0x5($t8)
    MEM_B(0X5, ctx->r24) = 0;
    // 0x808002F8: lw          $t9, 0x10C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10C);
    // 0x808002FC: sw          $zero, 0x8($t9)
    MEM_W(0X8, ctx->r25) = 0;
    // 0x80800300: lw          $t0, 0x10C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10C);
    // 0x80800304: sb          $zero, 0x4($t0)
    MEM_B(0X4, ctx->r8) = 0;
    // 0x80800308: jal         0x8008DAA8
    // 0x8080030C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008DAA8(rdram, ctx);
        goto after_0;
    // 0x8080030C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800310: beq         $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x80800314: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800360;
    }
    // 0x80800314: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800318: jal         0x8009EA4C
    // 0x8080031C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009EA4C(rdram, ctx);
        goto after_1;
    // 0x8080031C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800320: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800324: bne         $v0, $at, L_80800360
    if (ctx->r2 != ctx->r1) {
        // 0x80800328: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800360;
    }
    // 0x80800328: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080032C: jal         0x8009EA70
    // 0x80800330: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009EA70(rdram, ctx);
        goto after_2;
    // 0x80800330: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800334: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800338: beq         $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x8080033C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800350;
    }
    // 0x8080033C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800340: jal         0x80800384
    // 0x80800344: nop

    bashoes_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800344: nop

    after_3:
    // 0x80800348: b           L_8080036C
    // 0x8080034C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080036C;
    // 0x8080034C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800350:
    // 0x80800350: jal         0x80800384
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800358: b           L_8080036C
    // 0x8080035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080036C;
    // 0x8080035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800360:
    // 0x80800360: jal         0x80800384
    // 0x80800364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080036C:
    // 0x8080036C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800370: jr          $ra
    // 0x80800374: nop

    return;
    // 0x80800374: nop

;}
RECOMP_FUNC void func_80800554_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800558: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080055C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800560: beq         $a1, $at, L_808005FC
    if (ctx->r5 == ctx->r1) {
        // 0x80800564: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808005FC;
    }
    // 0x80800564: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800568: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x8080056C: beq         $a1, $at, L_808005A4
    if (ctx->r5 == ctx->r1) {
        // 0x80800570: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_808005A4;
    }
    // 0x80800570: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800574: beq         $a1, $at, L_808005B4
    if (ctx->r5 == ctx->r1) {
        // 0x80800578: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_808005B4;
    }
    // 0x80800578: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080057C: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x80800580: beq         $a1, $at, L_808005E4
    if (ctx->r5 == ctx->r1) {
        // 0x80800584: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_808005E4;
    }
    // 0x80800584: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800588: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8080058C: beq         $a1, $at, L_808005C4
    if (ctx->r5 == ctx->r1) {
        // 0x80800590: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808005C4;
    }
    // 0x80800590: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800594: beq         $a1, $at, L_808005D4
    if (ctx->r5 == ctx->r1) {
        // 0x80800598: nop
    
            goto L_808005D4;
    }
    // 0x80800598: nop

    // 0x8080059C: b           L_8080064C
    // 0x808005A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080064C;
    // 0x808005A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005A4:
    // 0x808005A4: jal         0x808007E4
    // 0x808005A8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_808007E4_chseaweedbaddy(rdram, ctx);
        goto after_0;
    // 0x808005A8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x808005AC: b           L_8080064C
    // 0x808005B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080064C;
    // 0x808005B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005B4:
    // 0x808005B4: jal         0x80086670
    // 0x808005B8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808005B8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x808005BC: b           L_8080064C
    // 0x808005C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080064C;
    // 0x808005C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005C4:
    // 0x808005C4: jal         0x80800BCC
    // 0x808005C8: nop

    func_80800BCC_chseaweedbaddy(rdram, ctx);
        goto after_2;
    // 0x808005C8: nop

    after_2:
    // 0x808005CC: b           L_8080064C
    // 0x808005D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080064C;
    // 0x808005D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005D4:
    // 0x808005D4: jal         0x80089F60
    // 0x808005D8: nop

    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808005D8: nop

    after_3:
    // 0x808005DC: b           L_8080064C
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080064C;
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005E4:
    // 0x808005E4: bnel        $t6, $zero, L_8080064C
    if (ctx->r14 != 0) {
        // 0x808005E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080064C;
    }
    goto skip_0;
    // 0x808005E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808005EC: jal         0x80800710
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800710_chseaweedbaddy(rdram, ctx);
        goto after_4;
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808005F4: b           L_8080064C
    // 0x808005F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080064C;
    // 0x808005F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005FC:
    // 0x808005FC: jal         0x8008A4A8
    // 0x80800600: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800600: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_5:
    // 0x80800604: bne         $v0, $zero, L_80800630
    if (ctx->r2 != 0) {
        // 0x80800608: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800630;
    }
    // 0x80800608: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080060C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800610: jal         0x80107070
    // 0x80800614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80107070(rdram, ctx);
        goto after_6;
    // 0x80800614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_6:
    // 0x80800618: bne         $v0, $zero, L_80800648
    if (ctx->r2 != 0) {
        // 0x8080061C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800648;
    }
    // 0x8080061C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800620: jal         0x80089CA8
    // 0x80800624: nop

    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800624: nop

    after_7:
    // 0x80800628: b           L_8080064C
    // 0x8080062C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080064C;
    // 0x8080062C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800630:
    // 0x80800630: jal         0x80800710
    // 0x80800634: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800710_chseaweedbaddy(rdram, ctx);
        goto after_8;
    // 0x80800634: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_8:
    // 0x80800638: b           L_8080064C
    // 0x8080063C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080064C;
    // 0x8080063C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800640: b           L_8080064C
    // 0x80800644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080064C;
    // 0x80800644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800648:
    // 0x80800648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080064C:
    // 0x8080064C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800654: jr          $ra
    // 0x80800658: nop

    return;
    // 0x80800658: nop

;}
RECOMP_FUNC void _bsdronebitten_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083040: syscall     39
    recomp_syscall_handler(rdram, ctx, 0x80083040);
    return;
    // 0x80083044: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void boot_handle_CpU(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80800CB0_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB0: lh          $v0, 0x5E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X5E);
    // 0x80800CB4: addiu       $at, $zero, 0xD1
    ctx->r1 = ADD32(0, 0XD1);
    // 0x80800CB8: beq         $v0, $at, L_80800CD0
    if (ctx->r2 == ctx->r1) {
        // 0x80800CBC: addiu       $at, $zero, 0xE7
        ctx->r1 = ADD32(0, 0XE7);
            goto L_80800CD0;
    }
    // 0x80800CBC: addiu       $at, $zero, 0xE7
    ctx->r1 = ADD32(0, 0XE7);
    // 0x80800CC0: beq         $v0, $at, L_80800CD8
    if (ctx->r2 == ctx->r1) {
        // 0x80800CC4: nop
    
            goto L_80800CD8;
    }
    // 0x80800CC4: nop

    // 0x80800CC8: b           L_80800CE0
    // 0x80800CCC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800CE0;
    // 0x80800CCC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800CD0:
    // 0x80800CD0: jr          $ra
    // 0x80800CD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800CD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CD8:
    // 0x80800CD8: jr          $ra
    // 0x80800CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CE0:
    // 0x80800CE0: jr          $ra
    // 0x80800CE4: nop

    return;
    // 0x80800CE4: nop

    // 0x80800CE8: nop

    // 0x80800CEC: nop

;}
RECOMP_FUNC void func_800BF744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF744: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BF748: addiu       $v0, $v0, -0x7A50
    ctx->r2 = ADD32(ctx->r2, -0X7A50);
    // 0x800BF74C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BF750: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BF754: sw          $a1, 0x88($t7)
    MEM_W(0X88, ctx->r15) = ctx->r5;
    // 0x800BF758: lw          $t8, 0x88($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X88);
    // 0x800BF75C: slt         $at, $t8, $a0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BF760: beq         $at, $zero, L_800BF76C
    if (ctx->r1 == 0) {
        // 0x800BF764: nop
    
            goto L_800BF76C;
    }
    // 0x800BF764: nop

    // 0x800BF768: sw          $a0, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r4;
L_800BF76C:
    // 0x800BF76C: jr          $ra
    // 0x800BF770: nop

    return;
    // 0x800BF770: nop

;}
RECOMP_FUNC void func_8080046C_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080046C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800470: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800478: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8080047C: jal         0x80087D98
    // 0x80800480: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    _gcnewoption_entrypoint_32(rdram, ctx);
        goto after_0;
    // 0x80800480: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    after_0:
    // 0x80800484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800488: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080048C: jr          $ra
    // 0x80800490: nop

    return;
    // 0x80800490: nop

;}
RECOMP_FUNC void func_800C6C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6C94: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C6C98: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C6C9C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C6CA0: addiu       $s2, $s2, -0x55C0
    ctx->r18 = ADD32(ctx->r18, -0X55C0);
    // 0x800C6CA4: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
    // 0x800C6CA8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C6CAC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C6CB0: addiu       $t6, $t6, -0x55BF
    ctx->r14 = ADD32(ctx->r14, -0X55BF);
    // 0x800C6CB4: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800C6CB8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C6CBC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C6CC0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C6CC4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C6CC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C6CCC: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x800C6CD0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800C6CD4: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800C6CD8: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x800C6CDC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C6CE0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C6CE4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800C6CE8: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
    // 0x800C6CEC: bne         $at, $zero, L_800C6D64
    if (ctx->r1 != 0) {
        // 0x800C6CF0: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800C6D64;
    }
    // 0x800C6CF0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800C6CF4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_800C6CF8:
    // 0x800C6CF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C6CFC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800C6D00: beql        $v0, $zero, L_800C6D58
    if (ctx->r2 == 0) {
        // 0x800C6D04: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800C6D58;
    }
    goto skip_0;
    // 0x800C6D04: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_0:
    // 0x800C6D08: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800C6D0C: jalr        $v0
    // 0x800C6D10: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800C6D10: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_0:
    // 0x800C6D14: beq         $v0, $zero, L_800C6D3C
    if (ctx->r2 == 0) {
        // 0x800C6D18: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800C6D3C;
    }
    // 0x800C6D18: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800C6D1C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800C6D20: beql        $v0, $zero, L_800C6D3C
    if (ctx->r2 == 0) {
        // 0x800C6D24: sw          $zero, 0x84($s2)
        MEM_W(0X84, ctx->r18) = 0;
            goto L_800C6D3C;
    }
    goto skip_1;
    // 0x800C6D24: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
    skip_1:
    // 0x800C6D28: jalr        $v0
    // 0x800C6D2C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800C6D2C: nop

    after_1:
    // 0x800C6D30: b           L_800C6D3C
    // 0x800C6D34: sw          $v0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r2;
        goto L_800C6D3C;
    // 0x800C6D34: sw          $v0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r2;
    // 0x800C6D38: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
L_800C6D3C:
    // 0x800C6D3C: beql        $s1, $zero, L_800C6D54
    if (ctx->r17 == 0) {
        // 0x800C6D40: lw          $v1, 0x80($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X80);
            goto L_800C6D54;
    }
    goto skip_2;
    // 0x800C6D40: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
    skip_2:
    // 0x800C6D44: or          $s6, $s1, $zero
    ctx->r22 = ctx->r17 | 0;
    // 0x800C6D48: b           L_800C6D54
    // 0x800C6D4C: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
        goto L_800C6D54;
    // 0x800C6D4C: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
    // 0x800C6D50: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
L_800C6D54:
    // 0x800C6D54: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_800C6D58:
    // 0x800C6D58: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x800C6D5C: bnel        $at, $zero, L_800C6CF8
    if (ctx->r1 != 0) {
        // 0x800C6D60: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_800C6CF8;
    }
    goto skip_3;
    // 0x800C6D60: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_3:
L_800C6D64:
    // 0x800C6D64: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C6D68: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x800C6D6C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C6D70: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C6D74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C6D78: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C6D7C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C6D80: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6D84: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C6D88: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C6D8C: jr          $ra
    // 0x800C6D90: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C6D90: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800C6D94: nop

    // 0x800C6D98: nop

    // 0x800C6D9C: nop

;}
RECOMP_FUNC void _gczoomboxdata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088430: syscall     682
    recomp_syscall_handler(rdram, ctx, 0x80088430);
    return;
    // 0x80088434: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800C7290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7298: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800C729C: jal         0x800C71B0
    // 0x800C72A0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_800C71B0(rdram, ctx);
        goto after_0;
    // 0x800C72A0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x800C72A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C72A8: jal         0x800FC9B4
    // 0x800C72AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FC9B4(rdram, ctx);
        goto after_1;
    // 0x800C72AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800C72B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C72B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C72B8: jr          $ra
    // 0x800C72BC: nop

    return;
    // 0x800C72BC: nop

;}
RECOMP_FUNC void func_800ABA9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABA9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ABAA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ABAA4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ABAA8: jal         0x8001211C
    // 0x800ABAAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x800ABAAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800ABAB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800ABAB4: lw          $t6, 0x798C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X798C);
    // 0x800ABAB8: addiu       $a0, $v0, -0x28
    ctx->r4 = ADD32(ctx->r2, -0X28);
    // 0x800ABABC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800ABAC0: lw          $s0, 0x4($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X4);
    // 0x800ABAC4: beq         $s0, $zero, L_800ABAF8
    if (ctx->r16 == 0) {
        // 0x800ABAC8: nop
    
            goto L_800ABAF8;
    }
    // 0x800ABAC8: nop

    // 0x800ABACC: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800ABAD0: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800ABAD4: beq         $at, $zero, L_800ABAF8
    if (ctx->r1 == 0) {
        // 0x800ABAD8: nop
    
            goto L_800ABAF8;
    }
    // 0x800ABAD8: nop

    // 0x800ABADC: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_800ABAE0:
    // 0x800ABAE0: beq         $s0, $zero, L_800ABAF8
    if (ctx->r16 == 0) {
        // 0x800ABAE4: nop
    
            goto L_800ABAF8;
    }
    // 0x800ABAE4: nop

    // 0x800ABAE8: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800ABAEC: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800ABAF0: bnel        $at, $zero, L_800ABAE0
    if (ctx->r1 != 0) {
        // 0x800ABAF4: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_800ABAE0;
    }
    goto skip_0;
    // 0x800ABAF4: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
L_800ABAF8:
    // 0x800ABAF8: beql        $s0, $zero, L_800ABB24
    if (ctx->r16 == 0) {
        // 0x800ABAFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800ABB24;
    }
    goto skip_1;
    // 0x800ABAFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800ABB00: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800ABB04: beq         $s0, $zero, L_800ABB20
    if (ctx->r16 == 0) {
        // 0x800ABB08: sw          $zero, 0x4($t9)
        MEM_W(0X4, ctx->r25) = 0;
            goto L_800ABB20;
    }
    // 0x800ABB08: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_800ABB0C:
    // 0x800ABB0C: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x800ABB10: jal         0x8001B084
    // 0x800ABB14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    heap_free(rdram, ctx);
        goto after_1;
    // 0x800ABB14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800ABB18: bne         $s1, $zero, L_800ABB0C
    if (ctx->r17 != 0) {
        // 0x800ABB1C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800ABB0C;
    }
    // 0x800ABB1C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800ABB20:
    // 0x800ABB20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800ABB24:
    // 0x800ABB24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ABB28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ABB2C: jr          $ra
    // 0x800ABB30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800ABB30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80801764_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801764: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801768: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080176C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80801770: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801774: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801778: jal         0x80100094
    // 0x8080177C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080177C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801780: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80801784: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80801788: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080178C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80801790: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80801794: bne         $t6, $at, L_80801800
    if (ctx->r14 != ctx->r1) {
        // 0x80801798: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80801800;
    }
    // 0x80801798: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8080179C: beql        $t7, $t6, L_80801804
    if (ctx->r15 == ctx->r14) {
        // 0x808017A0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801804;
    }
    goto skip_0;
    // 0x808017A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_0:
    // 0x808017A4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808017A8: beql        $a0, $zero, L_80801804
    if (ctx->r4 == 0) {
        // 0x808017AC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801804;
    }
    goto skip_1;
    // 0x808017AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x808017B0: jal         0x80106790
    // 0x808017B4: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808017B4: nop

    after_1:
    // 0x808017B8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x808017BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808017C0: jal         0x80089AC8
    // 0x808017C4: lbu         $a1, 0x20($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X20);
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808017C4: lbu         $a1, 0x20($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X20);
    after_2:
    // 0x808017C8: beq         $v0, $zero, L_808017DC
    if (ctx->r2 == 0) {
        // 0x808017CC: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_808017DC;
    }
    // 0x808017CC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x808017D0: lbu         $a0, 0x20($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X20);
    // 0x808017D4: jal         0x800F4F98
    // 0x808017D8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F4F98(rdram, ctx);
        goto after_3;
    // 0x808017D8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
L_808017DC:
    // 0x808017DC: jal         0x80106790
    // 0x808017E0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x808017E0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_4:
    // 0x808017E4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x808017E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808017EC: jal         0x80089AF0
    // 0x808017F0: lbu         $a1, 0x20($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808017F0: lbu         $a1, 0x20($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X20);
    after_5:
    // 0x808017F4: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808017F8: srl         $t1, $v1, 10
    ctx->r9 = S32(U32(ctx->r3) >> 10);
    // 0x808017FC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80801800:
    // 0x80801800: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80801804:
    // 0x80801804: bne         $v1, $at, L_80801860
    if (ctx->r3 != ctx->r1) {
        // 0x80801808: lw          $t2, 0x44($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X44);
            goto L_80801860;
    }
    // 0x80801808: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8080180C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801810: bnel        $t2, $at, L_80801864
    if (ctx->r10 != ctx->r1) {
        // 0x80801814: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801864;
    }
    goto skip_2;
    // 0x80801814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80801818: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8080181C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80801820: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80801824: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x80801828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080182C: srl         $t5, $t4, 22
    ctx->r13 = S32(U32(ctx->r12) >> 22);
    // 0x80801830: bne         $t5, $at, L_80801860
    if (ctx->r13 != ctx->r1) {
        // 0x80801834: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80801860;
    }
    // 0x80801834: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80801838: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080183C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801840: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801844: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
    // 0x80801848: jal         0x80089CA8
    // 0x8080184C: swc1        $f6, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f6.u32l;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x8080184C: swc1        $f6, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f6.u32l;
    after_6:
    // 0x80801850: jal         0x808021D4
    // 0x80801854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808021D4_chcollballcontrol(rdram, ctx);
        goto after_7;
    // 0x80801854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801858: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8080185C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_80801860:
    // 0x80801860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801864:
    // 0x80801864: jal         0x80101FDC
    // 0x80801868: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80801868: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_8:
    // 0x8080186C: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80801870: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80801874: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80801878: bnel        $t9, $at, L_80801910
    if (ctx->r25 != ctx->r1) {
        // 0x8080187C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801910;
    }
    goto skip_3;
    // 0x8080187C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x80801880: jal         0x808021D4
    // 0x80801884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808021D4_chcollballcontrol(rdram, ctx);
        goto after_9;
    // 0x80801884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801888: jal         0x80089CA8
    // 0x8080188C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x8080188C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801890: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801894: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801898: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080189C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1840, 0X4DF0) << 16);
    // 0x808018A0: addiu       $t0, $zero, 0x7D
    ctx->r8 = ADD32(0, 0X7D);
    // 0x808018A4: addiu       $t1, $zero, 0xFA
    ctx->r9 = ADD32(0, 0XFA);
    // 0x808018A8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x808018AC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x808018B0: addiu       $a2, $a2, 0x4DF0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1840, 0X4DF0));
    // 0x808018B4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808018B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808018BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808018C0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x808018C4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808018C8: jal         0x800B4470
    // 0x808018CC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B4470(rdram, ctx);
        goto after_11;
    // 0x808018CC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x808018D0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x808018D4: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x808018D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018DC: lw          $v0, 0x24($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X24);
    // 0x808018E0: srl         $t3, $v0, 22
    ctx->r11 = S32(U32(ctx->r2) >> 22);
    // 0x808018E4: beq         $t3, $at, L_80801904
    if (ctx->r11 == ctx->r1) {
        // 0x808018E8: addiu       $at, $zero, 0x44
        ctx->r1 = ADD32(0, 0X44);
            goto L_80801904;
    }
    // 0x808018E8: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x808018EC: bne         $t3, $at, L_8080190C
    if (ctx->r11 != ctx->r1) {
        // 0x808018F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080190C;
    }
    // 0x808018F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018F4: jal         0x80802264
    // 0x808018F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802264_chcollballcontrol(rdram, ctx);
        goto after_12;
    // 0x808018F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808018FC: b           L_80801910
    // 0x80801900: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80801910;
    // 0x80801900: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80801904:
    // 0x80801904: jal         0x80802264
    // 0x80801908: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80802264_chcollballcontrol(rdram, ctx);
        goto after_13;
    // 0x80801908: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
L_8080190C:
    // 0x8080190C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80801910:
    // 0x80801910: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80801914: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801918: jr          $ra
    // 0x8080191C: nop

    return;
    // 0x8080191C: nop

;}
RECOMP_FUNC void func_80800228_chmineproplight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: jr          $ra
    // 0x8080022C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080022C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800000_idflame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800004: lbu         $v0, 0xA($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA);
    // 0x80800008: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8080000C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800010: blez        $v0, L_8080003C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800014: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8080003C;
    }
    // 0x80800014: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800018: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_8080001C:
    // 0x8080001C: lh          $t8, 0xC($a2)
    ctx->r24 = MEM_H(ctx->r6, 0XC);
    // 0x80800020: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800024: bne         $at, $zero, L_8080003C
    if (ctx->r1 != 0) {
        // 0x80800028: nop
    
            goto L_8080003C;
    }
    // 0x80800028: nop

    // 0x8080002C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800030: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800034: bne         $at, $zero, L_8080001C
    if (ctx->r1 != 0) {
        // 0x80800038: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8080001C;
    }
    // 0x80800038: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8080003C:
    // 0x8080003C: jr          $ra
    // 0x80800040: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800040: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_808025E8_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808025EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808025F0: jal         0x800EA05C
    // 0x808025F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808025F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808025F8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x808025FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802600: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802604: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80802608: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8080260C: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80802610: jal         0x80088840
    // 0x80802614: sw          $t7, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r15;
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80802614: sw          $t7, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r15;
    after_1:
    // 0x80802618: bnel        $v0, $zero, L_80802660
    if (ctx->r2 != 0) {
        // 0x8080261C: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_80802660;
    }
    goto skip_0;
    // 0x8080261C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    skip_0:
    // 0x80802620: jal         0x800DA298
    // 0x80802624: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80802624: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    after_2:
    // 0x80802628: beq         $v0, $zero, L_80802660
    if (ctx->r2 == 0) {
        // 0x8080262C: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80802660;
    }
    // 0x8080262C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80802630: addiu       $at, $zero, 0x112
    ctx->r1 = ADD32(0, 0X112);
    // 0x80802634: bne         $t9, $at, L_80802660
    if (ctx->r25 != ctx->r1) {
        // 0x80802638: addiu       $a0, $zero, 0x234
        ctx->r4 = ADD32(0, 0X234);
            goto L_80802660;
    }
    // 0x80802638: addiu       $a0, $zero, 0x234
    ctx->r4 = ADD32(0, 0X234);
    // 0x8080263C: jal         0x80089C30
    // 0x80802640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80802640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80802644: bne         $v0, $zero, L_80802660
    if (ctx->r2 != 0) {
        // 0x80802648: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80802660;
    }
    // 0x80802648: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080264C: jal         0x80108B04
    // 0x80802650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_4;
    // 0x80802650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80802654: b           L_80802660
    // 0x80802658: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
        goto L_80802660;
    // 0x80802658: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8080265C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80802660:
    // 0x80802660: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80802664: beql        $t0, $zero, L_80802678
    if (ctx->r8 == 0) {
        // 0x80802668: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802678;
    }
    goto skip_1;
    // 0x80802668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8080266C: jal         0x800FFAB0
    // 0x80802670: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80802670: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80802674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802678:
    // 0x80802678: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080267C: jr          $ra
    // 0x80802680: nop

    return;
    // 0x80802680: nop

;}
RECOMP_FUNC void _chfactorycrusher_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086208: syscall     290
    recomp_syscall_handler(rdram, ctx, 0x80086208);
    return;
    // 0x8008620C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chmole_hailfire_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1828, 0XE0) << 16);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1828, 0XE0));
    return;
    // 0x808000BC: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1828, 0XE0));
;}
RECOMP_FUNC void func_8080136C_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080136C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801370: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801374: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801378: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080137C: jal         0x800E8B74
    // 0x80801380: addiu       $a0, $zero, 0xB59
    ctx->r4 = ADD32(0, 0XB59);
    func_800E8B74(rdram, ctx);
        goto after_0;
    // 0x80801380: addiu       $a0, $zero, 0xB59
    ctx->r4 = ADD32(0, 0XB59);
    after_0:
    // 0x80801384: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80801388: sb          $v0, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r2;
    // 0x8080138C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801390: jal         0x800E8D28
    // 0x80801394: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    func_800E8D28(rdram, ctx);
        goto after_1;
    // 0x80801394: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_1:
    // 0x80801398: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2658, 0X21CC) << 16);
    // 0x8080139C: addiu       $a1, $a1, 0x21CC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2658, 0X21CC));
    // 0x808013A0: lbu         $a0, 0x1C($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C);
    // 0x808013A4: jal         0x800E8D5C
    // 0x808013A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800E8D5C(rdram, ctx);
        goto after_2;
    // 0x808013A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x808013AC: jal         0x800E8B74
    // 0x808013B0: addiu       $a0, $zero, 0xB57
    ctx->r4 = ADD32(0, 0XB57);
    func_800E8B74(rdram, ctx);
        goto after_3;
    // 0x808013B0: addiu       $a0, $zero, 0xB57
    ctx->r4 = ADD32(0, 0XB57);
    after_3:
    // 0x808013B4: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808013B8: sb          $v0, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r2;
    // 0x808013BC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808013C0: jal         0x800E8D28
    // 0x808013C4: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    func_800E8D28(rdram, ctx);
        goto after_4;
    // 0x808013C4: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_4:
    // 0x808013C8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2658, 0X21E4) << 16);
    // 0x808013CC: addiu       $a1, $a1, 0x21E4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2658, 0X21E4));
    // 0x808013D0: lbu         $a0, 0x1D($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1D);
    // 0x808013D4: jal         0x800E8D5C
    // 0x808013D8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800E8D5C(rdram, ctx);
        goto after_5;
    // 0x808013D8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x808013DC: lb          $v0, 0x6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X6);
    // 0x808013E0: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    // 0x808013E4: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
    // 0x808013E8: negu        $t7, $v0
    ctx->r15 = SUB32(0, ctx->r2);
    // 0x808013EC: sh          $t7, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r15;
    // 0x808013F0: sh          $t7, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r15;
    // 0x808013F4: sh          $t7, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r15;
    // 0x808013F8: sb          $zero, 0x22($s0)
    MEM_B(0X22, ctx->r16) = 0;
    // 0x808013FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801400: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801404: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801408: jr          $ra
    // 0x8080140C: nop

    return;
    // 0x8080140C: nop

;}
RECOMP_FUNC void chdoormake_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808005C4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808005C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005CC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808005D0: jal         0x80800000
    // 0x808005D4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800000_chdoormake(rdram, ctx);
        goto after_0;
    // 0x808005D4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x808005D8: jal         0x808008C4
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008C4_chdoormake(rdram, ctx);
        goto after_1;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808005E0: bne         $v0, $zero, L_808005F8
    if (ctx->r2 != 0) {
        // 0x808005E4: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_808005F8;
    }
    // 0x808005E4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808005E8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808005EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808005F0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808005F4: bne         $t7, $at, L_80800638
    if (ctx->r15 != ctx->r1) {
        // 0x808005F8: andi        $t9, $t8, 0x1
        ctx->r25 = ctx->r24 & 0X1;
            goto L_80800638;
    }
L_808005F8:
    // 0x808005F8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x808005FC: beq         $t9, $zero, L_80800614
    if (ctx->r25 == 0) {
        // 0x80800600: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800614;
    }
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800604: jal         0x800FFAB0
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080060C: b           L_80800644
    // 0x80800610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800644;
    // 0x80800610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800614:
    // 0x80800614: jal         0x80089C98
    // 0x80800618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800620: jal         0x80101FDC
    // 0x80800624: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800624: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80800628: jal         0x808000B8
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B8_chdoormake(rdram, ctx);
        goto after_5;
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800630: b           L_80800644
    // 0x80800634: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800644;
    // 0x80800634: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800638:
    // 0x80800638: jal         0x808000B8
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B8_chdoormake(rdram, ctx);
        goto after_6;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800644:
    // 0x80800644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800648: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080064C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800650: jr          $ra
    // 0x80800654: nop

    return;
    // 0x80800654: nop

;}
RECOMP_FUNC void boot_osSetEventMesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800F44DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F44DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F44E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F44E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800F44E8: jal         0x800A4C88
    // 0x800F44EC: sw          $a1, 0x17C($a0)
    MEM_W(0X17C, ctx->r4) = ctx->r5;
    func_800A4C88(rdram, ctx);
        goto after_0;
    // 0x800F44EC: sw          $a1, 0x17C($a0)
    MEM_W(0X17C, ctx->r4) = ctx->r5;
    after_0:
    // 0x800F44F0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800F44F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F44F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F44FC: beq         $t7, $zero, L_800F450C
    if (ctx->r15 == 0) {
        // 0x800F4500: nop
    
            goto L_800F450C;
    }
    // 0x800F4500: nop

    // 0x800F4504: b           L_800F450C
    // 0x800F4508: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_800F450C;
    // 0x800F4508: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800F450C:
    // 0x800F450C: jal         0x8010F9C0
    // 0x800F4510: nop

    func_8010F9C0(rdram, ctx);
        goto after_1;
    // 0x800F4510: nop

    after_1:
    // 0x800F4514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F451C: jr          $ra
    // 0x800F4520: nop

    return;
    // 0x800F4520: nop

;}
RECOMP_FUNC void func_8009039C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009039C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800903A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800903A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800903A8: jal         0x800F54E4
    // 0x800903AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800903AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800903B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800903B4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800903B8: jal         0x800F7700
    // 0x800903BC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F7700(rdram, ctx);
        goto after_1;
    // 0x800903BC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800903C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800903C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800903C8: jr          $ra
    // 0x800903CC: nop

    return;
    // 0x800903CC: nop

;}
RECOMP_FUNC void func_808000E8_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000F4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000F8: beql        $a1, $t7, L_8080017C
    if (ctx->r5 == ctx->r15) {
        // 0x808000FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080017C;
    }
    goto skip_0;
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800104: jal         0x80102424
    // 0x80800108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080010C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800110: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800114: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: beq         $a1, $at, L_80800178
    if (ctx->r5 == ctx->r1) {
        // 0x8080011C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800178;
    }
    // 0x8080011C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800120: beq         $a1, $at, L_80800148
    if (ctx->r5 == ctx->r1) {
        // 0x80800124: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1776, 0X1760) << 16);
            goto L_80800148;
    }
    // 0x80800124: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1776, 0X1760) << 16);
    // 0x80800128: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080012C: beq         $a1, $at, L_80800164
    if (ctx->r5 == ctx->r1) {
        // 0x80800130: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1776, 0X1778) << 16);
            goto L_80800164;
    }
    // 0x80800130: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1776, 0X1778) << 16);
    // 0x80800134: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800138: beql        $a1, $at, L_8080017C
    if (ctx->r5 == ctx->r1) {
        // 0x8080013C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080017C;
    }
    goto skip_1;
    // 0x8080013C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800140: b           L_8080017C
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080017C;
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800148:
    // 0x80800148: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x8080014C: jal         0x80089D18
    // 0x80800150: addiu       $a2, $a2, 0x1760
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1776, 0X1760));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800150: addiu       $a2, $a2, 0x1760
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1776, 0X1760));
    after_1:
    // 0x80800154: jal         0x800FC660
    // 0x80800158: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_2;
    // 0x80800158: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_2:
    // 0x8080015C: b           L_8080017C
    // 0x80800160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080017C;
    // 0x80800160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800164:
    // 0x80800164: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800168: jal         0x80089D18
    // 0x8080016C: addiu       $a2, $a2, 0x1778
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1776, 0X1778));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080016C: addiu       $a2, $a2, 0x1778
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1776, 0X1778));
    after_3:
    // 0x80800170: jal         0x800FC660
    // 0x80800174: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x80800174: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_4:
L_80800178:
    // 0x80800178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080017C:
    // 0x8080017C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void func_80800454_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800454: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800458: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080045C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800460: jal         0x808019C8
    // 0x80800464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808019C8_chalienkids(rdram, ctx);
        goto after_0;
    // 0x80800464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800468: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080046C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800470: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x80800474: sltiu       $at, $t8, 0xF
    ctx->r1 = ctx->r24 < 0XF ? 1 : 0;
    // 0x80800478: beq         $at, $zero, L_80800624
    if (ctx->r1 == 0) {
        // 0x8080047C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800624;
    }
    // 0x8080047C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800480: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1324, 0X1CC8) << 16);
    // 0x80800484: addu        $at, $at, $t8
    gpr jr_addend_8080048C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800488: lw          $t8, 0x1CC8($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1324, 0X1CC8));
    // 0x8080048C: jr          $t8
    // 0x80800490: nop

    switch (jr_addend_8080048C >> 2) {
        case 0: goto L_80800494; break;
        case 1: goto L_808004A4; break;
        case 2: goto L_80800624; break;
        case 3: goto L_80800624; break;
        case 4: goto L_80800624; break;
        case 5: goto L_80800624; break;
        case 6: goto L_80800624; break;
        case 7: goto L_808004D4; break;
        case 8: goto L_80800624; break;
        case 9: goto L_8080053C; break;
        case 10: goto L_80800598; break;
        case 11: goto L_808005BC; break;
        case 12: goto L_80800624; break;
        case 13: goto L_80800624; break;
        case 14: goto L_80800610; break;
        default: switch_error(__func__, 0x8080048C, 0x80801CC8);
    }
    // 0x80800490: nop

L_80800494:
    // 0x80800494: jal         0x80801884
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801884_chalienkids(rdram, ctx);
        goto after_1;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080049C: b           L_80800624
    // 0x808004A0: nop

        goto L_80800624;
    // 0x808004A0: nop

L_808004A4:
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: jal         0x80801158
    // 0x808004AC: addiu       $a1, $zero, 0x9E5
    ctx->r5 = ADD32(0, 0X9E5);
    func_80801158_chalienkids(rdram, ctx);
        goto after_2;
    // 0x808004AC: addiu       $a1, $zero, 0x9E5
    ctx->r5 = ADD32(0, 0X9E5);
    after_2:
    // 0x808004B0: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x808004B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800624;
    }
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: jal         0x80102424
    // 0x808004BC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808004BC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: jal         0x8008A4B0
    // 0x808004C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808004C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808004CC: b           L_80800624
    // 0x808004D0: nop

        goto L_80800624;
    // 0x808004D0: nop

L_808004D4:
    // 0x808004D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1324, 0X21FC) << 16);
    // 0x808004D8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1324, 0X1E98) << 16);
    // 0x808004DC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808004E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808004E4: addiu       $a3, $a3, 0x1E98
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1324, 0X1E98));
    // 0x808004E8: addiu       $a2, $a2, 0x21FC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1324, 0X21FC));
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: jal         0x8008A1F0
    // 0x808004F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x808004F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808004F8: bne         $v0, $zero, L_80800624
    if (ctx->r2 != 0) {
        // 0x808004FC: nop
    
            goto L_80800624;
    }
    // 0x808004FC: nop

    // 0x80800500: jal         0x800878B0
    // 0x80800504: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800504: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x80800508: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080050C: beq         $v0, $at, L_80800624
    if (ctx->r2 == ctx->r1) {
        // 0x80800510: addiu       $a0, $zero, 0x371
        ctx->r4 = ADD32(0, 0X371);
            goto L_80800624;
    }
    // 0x80800510: addiu       $a0, $zero, 0x371
    ctx->r4 = ADD32(0, 0X371);
    // 0x80800514: jal         0x800DA298
    // 0x80800518: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800518: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_7:
    // 0x8080051C: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x80800520: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_80800624;
    }
    // 0x80800520: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800524: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800528: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8080052C: jal         0x800F7BC8
    // 0x80800530: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F7BC8(rdram, ctx);
        goto after_8;
    // 0x80800530: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x80800534: b           L_80800624
    // 0x80800538: nop

        goto L_80800624;
    // 0x80800538: nop

L_8080053C:
    // 0x8080053C: jal         0x800D9078
    // 0x80800540: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_9;
    // 0x80800540: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_9:
    // 0x80800544: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x80800548: nop
    
            goto L_80800624;
    }
    // 0x80800548: nop

    // 0x8080054C: jal         0x800F54E4
    // 0x80800550: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800550: nop

    after_10:
    // 0x80800554: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800558: jal         0x800F82D4
    // 0x8080055C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_11;
    // 0x8080055C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800564: jal         0x80102424
    // 0x80800568: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x80800568: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_12:
    // 0x8080056C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800570: addiu       $t0, $zero, 0xB7
    ctx->r8 = ADD32(0, 0XB7);
    // 0x80800574: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800578: addiu       $a1, $zero, 0x1286
    ctx->r5 = ADD32(0, 0X1286);
    // 0x8080057C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800580: jal         0x8008A208
    // 0x80800584: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80800584: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x80800588: jal         0x8010A624
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_14;
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800590: b           L_80800624
    // 0x80800594: nop

        goto L_80800624;
    // 0x80800594: nop

L_80800598:
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080059C: jal         0x80801158
    // 0x808005A0: addiu       $a1, $zero, 0x9E6
    ctx->r5 = ADD32(0, 0X9E6);
    func_80801158_chalienkids(rdram, ctx);
        goto after_15;
    // 0x808005A0: addiu       $a1, $zero, 0x9E6
    ctx->r5 = ADD32(0, 0X9E6);
    after_15:
    // 0x808005A4: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x808005A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800624;
    }
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: jal         0x80801520
    // 0x808005B0: addiu       $a1, $zero, 0x374
    ctx->r5 = ADD32(0, 0X374);
    func_80801520_chalienkids(rdram, ctx);
        goto after_16;
    // 0x808005B0: addiu       $a1, $zero, 0x374
    ctx->r5 = ADD32(0, 0X374);
    after_16:
    // 0x808005B4: b           L_80800624
    // 0x808005B8: nop

        goto L_80800624;
    // 0x808005B8: nop

L_808005BC:
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: jal         0x80801158
    // 0x808005C4: addiu       $a1, $zero, 0x9E6
    ctx->r5 = ADD32(0, 0X9E6);
    func_80801158_chalienkids(rdram, ctx);
        goto after_17;
    // 0x808005C4: addiu       $a1, $zero, 0x9E6
    ctx->r5 = ADD32(0, 0X9E6);
    after_17:
    // 0x808005C8: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x808005CC: nop
    
            goto L_80800624;
    }
    // 0x808005CC: nop

    // 0x808005D0: jal         0x80085710
    // 0x808005D4: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_18;
    // 0x808005D4: nop

    after_18:
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: jal         0x8008A4B0
    // 0x808005E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x808005E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: jal         0x80102424
    // 0x808005EC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80102424(rdram, ctx);
        goto after_20;
    // 0x808005EC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_20:
    // 0x808005F0: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    // 0x808005F4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    // 0x808005F8: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x808005FC: sll         $t1, $a2, 11
    ctx->r9 = S32(ctx->r6 << 11);
    // 0x80800600: jal         0x80101180
    // 0x80800604: srl         $a2, $t1, 20
    ctx->r6 = S32(U32(ctx->r9) >> 20);
    func_80101180(rdram, ctx);
        goto after_21;
    // 0x80800604: srl         $a2, $t1, 20
    ctx->r6 = S32(U32(ctx->r9) >> 20);
    after_21:
    // 0x80800608: b           L_80800624
    // 0x8080060C: nop

        goto L_80800624;
    // 0x8080060C: nop

L_80800610:
    // 0x80800610: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1324, 0X1EA8) << 16);
    // 0x80800614: addiu       $a1, $a1, 0x1EA8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1324, 0X1EA8));
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080061C: jal         0x8080184C
    // 0x80800620: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8080184C_chalienkids(rdram, ctx);
        goto after_22;
    // 0x80800620: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_22:
L_80800624:
    // 0x80800624: jal         0x808016D4
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016D4_chalienkids(rdram, ctx);
        goto after_23;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x8080062C: jal         0x8080158C
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080158C_chalienkids(rdram, ctx);
        goto after_24;
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800638: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080063C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800640: jr          $ra
    // 0x80800644: nop

    return;
    // 0x80800644: nop

;}
RECOMP_FUNC void _baflameline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B60: syscall     130
    recomp_syscall_handler(rdram, ctx, 0x80084B60);
    return;
    // 0x80084B64: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void ncbawaypoint_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    return;
    // 0x80800010: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
;}
RECOMP_FUNC void func_80800000_bsdronesuckunder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800004: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800010: lui         $a2, 0xC3A6
    ctx->r6 = S32(0XC3A6 << 16);
    // 0x80800014: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800018: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080001C: ori         $a2, $a2, 0xAAAA
    ctx->r6 = ctx->r6 | 0XAAAA;
    // 0x80800020: jal         0x800EFA4C
    // 0x80800024: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800028: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080002C: jal         0x8009BA9C
    // 0x80800030: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009BA9C(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_80802C7C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C84: jal         0x80106790
    // 0x80802C88: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802C88: nop

    after_0:
    // 0x80802C8C: lbu         $t6, 0x65($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X65);
    // 0x80802C90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802C94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802C98: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80802C9C: jal         0x80100094
    // 0x80802CA0: sb          $t7, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r15;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802CA0: sb          $t7, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r15;
    after_1:
    // 0x80802CA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802CA8: jal         0x80087DC0
    // 0x80802CAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_2;
    // 0x80802CAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80802CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802CB8: jr          $ra
    // 0x80802CBC: nop

    return;
    // 0x80802CBC: nop

;}
RECOMP_FUNC void func_80800E10_chtransparentfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800E14: blez        $a0, L_80800ED8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80800E18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800ED8;
    }
    // 0x80800E18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800E1C: andi        $a3, $a0, 0x3
    ctx->r7 = ctx->r4 & 0X3;
    // 0x80800E20: beq         $a3, $zero, L_80800E64
    if (ctx->r7 == 0) {
        // 0x80800E24: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80800E64;
    }
    // 0x80800E24: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80800E28: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x80800E2C: subu        $t6, $t6, $zero
    ctx->r14 = SUB32(ctx->r14, 0);
    // 0x80800E30: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2232, 0X10E0) << 16);
    // 0x80800E34: addiu       $t7, $t7, 0x10E0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2232, 0X10E0));
    // 0x80800E38: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800E3C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80800E40: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80800E44:
    // 0x80800E44: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x80800E48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800E4C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80800E50: xor         $t9, $a3, $t8
    ctx->r25 = ctx->r7 ^ ctx->r24;
    // 0x80800E54: sltu        $t9, $zero, $t9
    ctx->r25 = 0 < ctx->r25 ? 1 : 0;
    // 0x80800E58: bne         $a2, $v0, L_80800E44
    if (ctx->r6 != ctx->r2) {
        // 0x80800E5C: and         $v1, $v1, $t9
        ctx->r3 = ctx->r3 & ctx->r25;
            goto L_80800E44;
    }
    // 0x80800E5C: and         $v1, $v1, $t9
    ctx->r3 = ctx->r3 & ctx->r25;
    // 0x80800E60: beq         $v0, $a0, L_80800ED8
    if (ctx->r2 == ctx->r4) {
        // 0x80800E64: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_80800ED8;
    }
L_80800E64:
    // 0x80800E64: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80800E68: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2232, 0X10E0) << 16);
    // 0x80800E6C: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80800E70: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x80800E74: addiu       $t1, $t1, 0x10E0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2232, 0X10E0));
    // 0x80800E78: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80800E7C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800E80: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800E84: addu        $a2, $t2, $t1
    ctx->r6 = ADD32(ctx->r10, ctx->r9);
    // 0x80800E88: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x80800E8C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80800E90:
    // 0x80800E90: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x80800E94: lw          $t5, 0x14($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X14);
    // 0x80800E98: lw          $t7, 0x20($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X20);
    // 0x80800E9C: lw          $t9, 0x2C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2C);
    // 0x80800EA0: xor         $t4, $a3, $t3
    ctx->r12 = ctx->r7 ^ ctx->r11;
    // 0x80800EA4: sltu        $t4, $zero, $t4
    ctx->r12 = 0 < ctx->r12 ? 1 : 0;
    // 0x80800EA8: xor         $t6, $a3, $t5
    ctx->r14 = ctx->r7 ^ ctx->r13;
    // 0x80800EAC: sltu        $t6, $zero, $t6
    ctx->r14 = 0 < ctx->r14 ? 1 : 0;
    // 0x80800EB0: and         $v1, $v1, $t4
    ctx->r3 = ctx->r3 & ctx->r12;
    // 0x80800EB4: xor         $t8, $a3, $t7
    ctx->r24 = ctx->r7 ^ ctx->r15;
    // 0x80800EB8: sltu        $t8, $zero, $t8
    ctx->r24 = 0 < ctx->r24 ? 1 : 0;
    // 0x80800EBC: and         $v1, $v1, $t6
    ctx->r3 = ctx->r3 & ctx->r14;
    // 0x80800EC0: xor         $t0, $a3, $t9
    ctx->r8 = ctx->r7 ^ ctx->r25;
    // 0x80800EC4: sltu        $t0, $zero, $t0
    ctx->r8 = 0 < ctx->r8 ? 1 : 0;
    // 0x80800EC8: and         $v1, $v1, $t8
    ctx->r3 = ctx->r3 & ctx->r24;
    // 0x80800ECC: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    // 0x80800ED0: bne         $a1, $a2, L_80800E90
    if (ctx->r5 != ctx->r6) {
        // 0x80800ED4: and         $v1, $v1, $t0
        ctx->r3 = ctx->r3 & ctx->r8;
            goto L_80800E90;
    }
    // 0x80800ED4: and         $v1, $v1, $t0
    ctx->r3 = ctx->r3 & ctx->r8;
L_80800ED8:
    // 0x80800ED8: jr          $ra
    // 0x80800EDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800EDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void cadbfunc_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002C4: jal         0x80800224
    // 0x808002C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800224_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x808002C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002CC: bne         $v0, $zero, L_808002DC
    if (ctx->r2 != 0) {
        // 0x808002D0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808002DC;
    }
    // 0x808002D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D4: b           L_808002E8
    // 0x808002D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002E8;
    // 0x808002D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002DC:
    // 0x808002DC: jal         0x800EE7F8
    // 0x808002E0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808002E0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808002E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002E8:
    // 0x808002E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002F0: jr          $ra
    // 0x808002F4: nop

    return;
    // 0x808002F4: nop

;}
RECOMP_FUNC void func_80800BA0_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BA4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800BB0: beq         $a1, $at, L_80800BEC
    if (ctx->r5 == ctx->r1) {
        // 0x80800BB4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800BEC;
    }
    // 0x80800BB4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800BB8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800BBC: beq         $a1, $at, L_80800C08
    if (ctx->r5 == ctx->r1) {
        // 0x80800BC0: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800C08;
    }
    // 0x80800BC0: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800BC4: beq         $a1, $at, L_80800C60
    if (ctx->r5 == ctx->r1) {
        // 0x80800BC8: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1036, 0X12B8) << 16);
            goto L_80800C60;
    }
    // 0x80800BC8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1036, 0X12B8) << 16);
    // 0x80800BCC: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80800BD0: beq         $a1, $at, L_80800C38
    if (ctx->r5 == ctx->r1) {
        // 0x80800BD4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800C38;
    }
    // 0x80800BD4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800BD8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800BDC: beq         $a1, $at, L_80800C74
    if (ctx->r5 == ctx->r1) {
        // 0x80800BE0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800C74;
    }
    // 0x80800BE0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800BE4: b           L_80800CB4
    // 0x80800BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800CB4;
    // 0x80800BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BEC:
    // 0x80800BEC: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800BF0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800BF4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800BF8: jal         0x80800D28
    // 0x80800BFC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800D28_chjollyroger(rdram, ctx);
        goto after_0;
    // 0x80800BFC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80800C00: b           L_80800CB4
    // 0x80800C04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CB4;
    // 0x80800C04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C08:
    // 0x80800C08: lbu         $t7, 0x65($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X65);
    // 0x80800C0C: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800C10: sb          $t8, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r24;
    // 0x80800C14: jal         0x800F54E4
    // 0x80800C18: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800C18: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800C1C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800C20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C28: jal         0x800F8300
    // 0x80800C2C: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    func_800F8300(rdram, ctx);
        goto after_2;
    // 0x80800C2C: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    after_2:
    // 0x80800C30: b           L_80800CB4
    // 0x80800C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CB4;
    // 0x80800C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C38:
    // 0x80800C38: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800C3C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800C40: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800C44: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x80800C48: and         $t0, $a2, $at
    ctx->r8 = ctx->r6 & ctx->r1;
    // 0x80800C4C: srl         $a2, $t0, 16
    ctx->r6 = S32(U32(ctx->r8) >> 16);
    // 0x80800C50: jal         0x80800DD8
    // 0x80800C54: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_80800DD8_chjollyroger(rdram, ctx);
        goto after_3;
    // 0x80800C54: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_3:
    // 0x80800C58: b           L_80800CB8
    // 0x80800C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800CB8;
    // 0x80800C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C60:
    // 0x80800C60: addiu       $a0, $a0, 0x12B8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1036, 0X12B8));
    // 0x80800C64: jal         0x80088090
    // 0x80800C68: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800C68: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_4:
    // 0x80800C6C: b           L_80800CB4
    // 0x80800C70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CB4;
    // 0x80800C70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C74:
    // 0x80800C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C78: jal         0x800897C0
    // 0x80800C7C: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80800C7C: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    after_5:
    // 0x80800C80: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C88: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800C8C: jal         0x800897E8
    // 0x80800C90: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x80800C90: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_6:
    // 0x80800C94: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C98: jal         0x80089810
    // 0x80800C9C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_7;
    // 0x80800C9C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_7:
    // 0x80800CA0: b           L_80800CB4
    // 0x80800CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CB4;
    // 0x80800CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800CA8: b           L_80800CB4
    // 0x80800CAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800CB4;
    // 0x80800CAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CB4:
    // 0x80800CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CB8:
    // 0x80800CB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CBC: jr          $ra
    // 0x80800CC0: nop

    return;
    // 0x80800CC0: nop

;}
RECOMP_FUNC void _baduo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084928: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084928);
    return;
    // 0x8008492C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chquiz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877D8: syscall     629
    recomp_syscall_handler(rdram, ctx, 0x800877D8);
    return;
    // 0x800877DC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gspropctrl_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: jr          $ra
    // 0x80800054: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    return;
    // 0x80800054: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
;}
