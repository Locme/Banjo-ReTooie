#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8010545C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010545C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80105460: lw          $a0, 0x6EC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EC0);
    // 0x80105464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010546C: beql        $a0, $zero, L_80105488
    if (ctx->r4 == 0) {
        // 0x80105470: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80105488;
    }
    goto skip_0;
    // 0x80105470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80105474: jal         0x800B32E4
    // 0x80105478: nop

    freelist_defrag(rdram, ctx);
        goto after_0;
    // 0x80105478: nop

    after_0:
    // 0x8010547C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80105480: sw          $v0, 0x6EC0($at)
    MEM_W(0X6EC0, ctx->r1) = ctx->r2;
    // 0x80105484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80105488:
    // 0x80105488: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010548C: jr          $ra
    // 0x80105490: nop

    return;
    // 0x80105490: nop

;}
RECOMP_FUNC void _glglobalsettings_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886E8: syscall     699
    recomp_syscall_handler(rdram, ctx, 0x800886E8);
    return;
    // 0x800886EC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _idworldmake_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F50: syscall     749
    recomp_syscall_handler(rdram, ctx, 0x80088F50);
    return;
    // 0x80088F54: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800BAB60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAB60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BAB64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BAB68: jal         0x800F2EA0
    // 0x800BAB6C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800F2EA0(rdram, ctx);
        goto after_0;
    // 0x800BAB6C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_0:
    // 0x800BAB70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BAB74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BAB78: jr          $ra
    // 0x800BAB7C: nop

    return;
    // 0x800BAB7C: nop

;}
RECOMP_FUNC void func_8080039C_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080039C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003A8: jal         0x80800098
    // 0x808003AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800098_bsbansnooze(rdram, ctx);
        goto after_0;
    // 0x808003AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003B0: lui         $a2, 0x3FCC
    ctx->r6 = S32(0X3FCC << 16);
    // 0x808003B4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003BC: jal         0x8008CCBC
    // 0x808003C0: addiu       $a1, $zero, 0x279
    ctx->r5 = ADD32(0, 0X279);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x808003C0: addiu       $a1, $zero, 0x279
    ctx->r5 = ADD32(0, 0X279);
    after_1:
    // 0x808003C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808003C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808003D8: jal         0x8009FFD8
    // 0x808003DC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808003DC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E4: jal         0x8009B9B0
    // 0x808003E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x808003E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F0: addiu       $a1, $zero, 0x58D
    ctx->r5 = ADD32(0, 0X58D);
    // 0x808003F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808003F8: jal         0x8009DF94
    // 0x808003FC: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    func_8009DF94(rdram, ctx);
        goto after_4;
    // 0x808003FC: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    after_4:
    // 0x80800400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800404: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080040C: jr          $ra
    // 0x80800410: nop

    return;
    // 0x80800410: nop

;}
RECOMP_FUNC void func_80012D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012D4C: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x80012D50: addiu       $v1, $v1, -0x65D0
    ctx->r3 = ADD32(ctx->r3, -0X65D0);
    // 0x80012D54: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80012D58: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x80012D5C: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80012D60: bne         $t6, $zero, L_80012D7C
    if (ctx->r14 != 0) {
        // 0x80012D64: addiu       $v0, $v0, 0x2BB4
        ctx->r2 = ADD32(ctx->r2, 0X2BB4);
            goto L_80012D7C;
    }
    // 0x80012D64: addiu       $v0, $v0, 0x2BB4
    ctx->r2 = ADD32(ctx->r2, 0X2BB4);
    // 0x80012D68: addiu       $t7, $t7, -0x65C0
    ctx->r15 = ADD32(ctx->r15, -0X65C0);
    // 0x80012D6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80012D70: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012D74: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x80012D78: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_80012D7C:
    // 0x80012D7C: jr          $ra
    // 0x80012D80: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    return;
    // 0x80012D80: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_8010E3C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E3C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8010E3C8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8010E3CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E3D0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8010E3D4: addiu       $v1, $sp, 0x24
    ctx->r3 = ADD32(ctx->r29, 0X24);
L_8010E3D8:
    // 0x8010E3D8: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8010E3DC: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8010E3E0: lwc1        $f14, 0x4($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8010E3E4: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8010E3E8: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8010E3EC: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8010E3F0: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8010E3F4: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8010E3F8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8010E3FC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8010E400: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8010E404: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8010E408: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8010E40C: bne         $v1, $a0, L_8010E3D8
    if (ctx->r3 != ctx->r4) {
        // 0x8010E410: swc1        $f12, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f12.u32l;
            goto L_8010E3D8;
    }
    // 0x8010E410: swc1        $f12, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f12.u32l;
    // 0x8010E414: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8010E418: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010E41C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010E420: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8010E424: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8010E428: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8010E42C: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8010E430: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8010E434: jal         0x8002DCA0
    // 0x8010E438: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8010E438: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_0:
    // 0x8010E43C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010E440: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8010E444: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8010E448: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8010E44C: nop

    // 0x8010E450: bc1fl       L_8010E4AC
    if (!c1cs) {
        // 0x8010E454: sw          $zero, 0x8($a1)
        MEM_W(0X8, ctx->r5) = 0;
            goto L_8010E4AC;
    }
    goto skip_0;
    // 0x8010E454: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    skip_0:
    // 0x8010E458: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010E45C: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8010E460: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8010E464: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8010E468: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8010E46C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8010E470: nop

    // 0x8010E474: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8010E478: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010E47C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8010E480: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8010E484: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8010E488: nop

    // 0x8010E48C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8010E490: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010E494: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8010E498: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8010E49C: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8010E4A0: b           L_8010E4B4
    // 0x8010E4A4: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
        goto L_8010E4B4;
    // 0x8010E4A4: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x8010E4A8: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
L_8010E4AC:
    // 0x8010E4AC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8010E4B0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8010E4B4:
    // 0x8010E4B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010E4B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8010E4BC: jr          $ra
    // 0x8010E4C0: nop

    return;
    // 0x8010E4C0: nop

;}
RECOMP_FUNC void glintrosyncDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8080033C: addiu       $v0, $v0, 0x75D0
    ctx->r2 = ADD32(ctx->r2, 0X75D0);
    // 0x80800340: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2738, 0X48C) << 16);
    // 0x80800344: lwc1        $f2, 0x48C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2738, 0X48C));
    // 0x80800348: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8080034C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800350: add.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80800354: bc1f        L_8080037C
    if (!c1cs) {
        // 0x80800358: nop
    
            goto L_8080037C;
    }
    // 0x80800358: nop

    // 0x8080035C: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80800360: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2738, 0X490) << 16);
    // 0x80800364: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x80800368: nop

    // 0x8080036C: bc1f        L_8080037C
    if (!c1cs) {
        // 0x80800370: nop
    
            goto L_8080037C;
    }
    // 0x80800370: nop

    // 0x80800374: lwc1        $f6, 0x490($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2738, 0X490));
    // 0x80800378: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
L_8080037C:
    // 0x8080037C: jr          $ra
    // 0x80800380: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x80800380: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_800A26B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A26B0: jr          $ra
    // 0x800A26B4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x800A26B4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800F8B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8B70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F8B74: jr          $ra
    // 0x800F8B78: lbu         $v0, 0x54FC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X54FC);
    return;
    // 0x800F8B78: lbu         $v0, 0x54FC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X54FC);
;}
RECOMP_FUNC void func_80800068_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(404, 0X2230) << 16);
    // 0x80800074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800078: addiu       $a2, $a2, 0x2230
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(404, 0X2230));
    // 0x8080007C: jal         0x8009D454
    // 0x80800080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D454(rdram, ctx);
        goto after_0;
    // 0x80800080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800084: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800088: sb          $v0, 0x160($t6)
    MEM_B(0X160, ctx->r14) = ctx->r2;
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void _bsstand_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B88: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B88);
    return;
    // 0x80083B8C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800000_chboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2072, 0X690) << 16);
    // 0x80800004: lwc1        $f4, 0x690($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2072, 0X690));
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800014: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80800018: jal         0x800DA298
    // 0x8080001C: addiu       $a0, $zero, 0x439
    ctx->r4 = ADD32(0, 0X439);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $zero, 0x439
    ctx->r4 = ADD32(0, 0X439);
    after_0:
    // 0x80800020: bnel        $v0, $zero, L_8080003C
    if (ctx->r2 != 0) {
        // 0x80800024: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080003C;
    }
    goto skip_0;
    // 0x80800024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800028: jal         0x80088848
    // 0x8080002C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x8080002C: nop

    after_1:
    // 0x80800030: beql        $v0, $zero, L_80800048
    if (ctx->r2 == 0) {
        // 0x80800034: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800048;
    }
    goto skip_1;
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080003C:
    // 0x8080003C: jal         0x80101FDC
    // 0x80800040: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800040: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800048:
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void func_80800150_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800158: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2204, 0X25DC) << 16);
    // 0x8080015C: addiu       $a3, $a3, 0x25DC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2204, 0X25DC));
    // 0x80800160: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800164: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800168: jal         0x80089D50
    // 0x8080016C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080016C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800174: sb          $zero, 0x5F($a0)
    MEM_B(0X5F, ctx->r4) = 0;
    // 0x80800178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080017C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void func_80800A9C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AA4: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800AA8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(804, 0X7E00) << 16);
    // 0x80800AAC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800AB0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800AB4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800AB8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800ABC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800AC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800AC4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800AC8: lw          $v0, 0x7E00($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(804, 0X7E00));
    // 0x80800ACC: beql        $v0, $zero, L_80800AE0
    if (ctx->r2 == 0) {
        // 0x80800AD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800AE0;
    }
    goto skip_0;
    // 0x80800AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800AD4: jalr        $v0
    // 0x80800AD8: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80800AD8: nop

    after_0:
    // 0x80800ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800AE0:
    // 0x80800AE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AE4: jr          $ra
    // 0x80800AE8: nop

    return;
    // 0x80800AE8: nop

;}
RECOMP_FUNC void chcollballcontrol_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803240: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1840, 0X4FE8) << 16);
    // 0x80803244: jr          $ra
    // 0x80803248: addiu       $v0, $v0, 0x4FE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4FE8));
    return;
    // 0x80803248: addiu       $v0, $v0, 0x4FE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4FE8));
;}
RECOMP_FUNC void _chlagoonbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FD0: syscall     268
    recomp_syscall_handler(rdram, ctx, 0x80085FD0);
    return;
    // 0x80085FD4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80804AC8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804AC8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80804ACC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80804AD0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80804AD4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80804AD8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80804ADC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80804AE0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80804AE4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80804AE8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80804AEC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80804AF0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80804AF4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80804AF8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80804AFC: beq         $a1, $zero, L_80804BF0
    if (ctx->r5 == 0) {
        // 0x80804B00: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_80804BF0;
    }
    // 0x80804B00: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80804B04: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B90) << 16);
    // 0x80804B08: lwc1        $f22, -0x6470($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B90));
    // 0x80804B0C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B94) << 16);
    // 0x80804B10: lwc1        $f20, -0x646C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B94));
    // 0x80804B14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80804B18: lui         $fp, 0x1000
    ctx->r30 = S32(0X1000 << 16);
    // 0x80804B1C: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    // 0x80804B20: addiu       $s6, $sp, 0x78
    ctx->r22 = ADD32(ctx->r29, 0X78);
    // 0x80804B24: addiu       $s5, $sp, 0x84
    ctx->r21 = ADD32(ctx->r29, 0X84);
    // 0x80804B28: addiu       $s4, $sp, 0x6C
    ctx->r20 = ADD32(ctx->r29, 0X6C);
    // 0x80804B2C: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
L_80804B30:
    // 0x80804B30: jal         0x800F6438
    // 0x80804B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x80804B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80804B38: beql        $v0, $zero, L_80804BE8
    if (ctx->r2 == 0) {
        // 0x80804B3C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80804BE8;
    }
    goto skip_0;
    // 0x80804B3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80804B40: jal         0x800F6478
    // 0x80804B44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F6478(rdram, ctx);
        goto after_1;
    // 0x80804B44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80804B48: beql        $v0, $zero, L_80804BE8
    if (ctx->r2 == 0) {
        // 0x80804B4C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80804BE8;
    }
    goto skip_1;
    // 0x80804B4C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80804B50: jal         0x800F581C
    // 0x80804B54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F581C(rdram, ctx);
        goto after_2;
    // 0x80804B54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80804B58: and         $t6, $v0, $fp
    ctx->r14 = ctx->r2 & ctx->r30;
    // 0x80804B5C: beq         $t6, $zero, L_80804BE4
    if (ctx->r14 == 0) {
        // 0x80804B60: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80804BE4;
    }
    // 0x80804B60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80804B64: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x80804B68: jal         0x800EE7F8
    // 0x80804B6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80804B6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80804B70: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80804B74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80804B78: jal         0x800EF1B8
    // 0x80804B7C: lw          $a1, 0x48($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x80804B7C: lw          $a1, 0x48($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X48);
    after_4:
    // 0x80804B80: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80804B84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804B88: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80804B8C: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80804B90: jal         0x800F5A00
    // 0x80804B94: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    func_800F5A00(rdram, ctx);
        goto after_5;
    // 0x80804B94: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80804B98: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80804B9C: jal         0x800EE7F8
    // 0x80804BA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80804BA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80804BA4: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80804BA8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80804BAC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80804BB0: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80804BB4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80804BB8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80804BBC: jal         0x800F018C
    // 0x80804BC0: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    func_800F018C(rdram, ctx);
        goto after_7;
    // 0x80804BC0: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80804BC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804BC8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80804BCC: jal         0x800F7A2C
    // 0x80804BD0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800F7A2C(rdram, ctx);
        goto after_8;
    // 0x80804BD0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_8:
    // 0x80804BD4: jal         0x808026F8
    // 0x80804BD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_808026F8_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80804BD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80804BDC: jal         0x808062B8
    // 0x80804BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808062B8_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x80804BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
L_80804BE4:
    // 0x80804BE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80804BE8:
    // 0x80804BE8: bne         $s1, $s7, L_80804B30
    if (ctx->r17 != ctx->r23) {
        // 0x80804BEC: nop
    
            goto L_80804B30;
    }
    // 0x80804BEC: nop

L_80804BF0:
    // 0x80804BF0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80804BF4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80804BF8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80804BFC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80804C00: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80804C04: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80804C08: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80804C0C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80804C10: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80804C14: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80804C18: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80804C1C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80804C20: jr          $ra
    // 0x80804C24: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80804C24: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80800704_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800704: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800708: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080070C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800710: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800714: jal         0x80100094
    // 0x80800718: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800718: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080071C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800720: sb          $zero, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = 0;
    // 0x80800724: jal         0x808007C8
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007C8_chstonepillar(rdram, ctx);
        goto after_1;
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800730: jal         0x80101FDC
    // 0x80800734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800738: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8080073C: jal         0x800D0B68
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_3;
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800744: beq         $v0, $zero, L_8080075C
    if (ctx->r2 == 0) {
        // 0x80800748: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_8080075C;
    }
    // 0x80800748: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8080074C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800750: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80800754: b           L_808007B4
    // 0x80800758: sh          $t6, 0x2C($t7)
    MEM_H(0X2C, ctx->r15) = ctx->r14;
        goto L_808007B4;
    // 0x80800758: sh          $t6, 0x2C($t7)
    MEM_H(0X2C, ctx->r15) = ctx->r14;
L_8080075C:
    // 0x8080075C: lh          $t9, 0x2C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2C);
    // 0x80800760: addiu       $a0, $zero, 0x9CD
    ctx->r4 = ADD32(0, 0X9CD);
    // 0x80800764: bnel        $t9, $zero, L_808007B8
    if (ctx->r25 != 0) {
        // 0x80800768: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808007B8;
    }
    goto skip_0;
    // 0x80800768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080076C: jal         0x800DA564
    // 0x80800770: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_4;
    // 0x80800770: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800778: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080077C: jal         0x808005B4
    // 0x80800780: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_808005B4_chstonepillar(rdram, ctx);
        goto after_5;
    // 0x80800780: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x80800784: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800788: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080078C: jal         0x800D1254
    // 0x80800790: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800D1254(rdram, ctx);
        goto after_6;
    // 0x80800790: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x80800794: jal         0x800DA298
    // 0x80800798: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800798: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    after_7:
    // 0x8080079C: beql        $v0, $zero, L_808007B8
    if (ctx->r2 == 0) {
        // 0x808007A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808007B8;
    }
    goto skip_1;
    // 0x808007A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808007A4: jal         0x80801174
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801174_chstonepillar(rdram, ctx);
        goto after_8;
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808007AC: jal         0x800DA544
    // 0x808007B0: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x808007B0: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    after_9:
L_808007B4:
    // 0x808007B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007B8:
    // 0x808007B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808007C0: jr          $ra
    // 0x808007C4: nop

    return;
    // 0x808007C4: nop

;}
RECOMP_FUNC void func_80800AA4_badata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800AB0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800AB4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800AB8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80800ABC: jal         0x80800000
    // 0x80800AC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800AC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800AC4: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80800AC8: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800ACC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80800AD0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800AD4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800AD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800ADC: mflo        $t6
    ctx->r14 = lo;
    // 0x80800AE0: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x80800AE4: lw          $v1, 0x4($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X4);
    // 0x80800AE8: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800AEC: bne         $at, $zero, L_80800AFC
    if (ctx->r1 != 0) {
        // 0x80800AF0: nop
    
            goto L_80800AFC;
    }
    // 0x80800AF0: nop

    // 0x80800AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800AF8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80800AFC:
    // 0x80800AFC: multu       $a1, $a3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800B00: sll         $a0, $a2, 3
    ctx->r4 = S32(ctx->r6 << 3);
    // 0x80800B04: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B08: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80800B0C: mflo        $t8
    ctx->r24 = lo;
    // 0x80800B10: addu        $v1, $t1, $t8
    ctx->r3 = ADD32(ctx->r9, ctx->r24);
    // 0x80800B14: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80800B18: addu        $t2, $t9, $a0
    ctx->r10 = ADD32(ctx->r25, ctx->r4);
    // 0x80800B1C: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80800B20: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80800B24: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80800B28: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800B2C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800B30: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x80800B34: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80800B38: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800B3C: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x80800B40: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80800B44: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80800B48: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80800B4C: lh          $t2, 0x2($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X2);
    // 0x80800B50: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B5C: jr          $ra
    // 0x80800B60: nop

    return;
    // 0x80800B60: nop

;}
RECOMP_FUNC void func_800E96B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E96B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E96B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E96B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E96BC: jal         0x800E95AC
    // 0x800E96C0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    func_800E95AC(rdram, ctx);
        goto after_0;
    // 0x800E96C0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x800E96C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E96C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E96CC: jr          $ra
    // 0x800E96D0: nop

    return;
    // 0x800E96D0: nop

    // 0x800E96D4: nop

    // 0x800E96D8: nop

    // 0x800E96DC: nop

;}
RECOMP_FUNC void func_80800F08_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800F1C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800F20: jal         0x80800BD8
    // 0x80800F24: addiu       $a1, $zero, 0x1D5
    ctx->r5 = ADD32(0, 0X1D5);
    func_80800BD8_chnests(rdram, ctx);
        goto after_0;
    // 0x80800F24: addiu       $a1, $zero, 0x1D5
    ctx->r5 = ADD32(0, 0X1D5);
    after_0:
    // 0x80800F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F30: jr          $ra
    // 0x80800F34: nop

    return;
    // 0x80800F34: nop

;}
RECOMP_FUNC void chhoneyb_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(800, 0X1068) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1068
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(800, 0X1068));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1068
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(800, 0X1068));
;}
RECOMP_FUNC void func_808000A0_chdinofamilymother(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000AC: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000B8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808000BC: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x808000C0: beq         $at, $zero, L_808001F4
    if (ctx->r1 == 0) {
        // 0x808000C4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808001F4;
    }
    // 0x808000C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X1270) << 16);
    // 0x808000CC: addu        $at, $at, $t8
    gpr jr_addend_808000D4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000D0: lw          $t8, 0x1270($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2420, 0X1270));
    // 0x808000D4: jr          $t8
    // 0x808000D8: nop

    switch (jr_addend_808000D4 >> 2) {
        case 0: goto L_808000DC; break;
        case 1: goto L_808001F4; break;
        case 2: goto L_808001F4; break;
        case 3: goto L_808001F4; break;
        case 4: goto L_808001F4; break;
        case 5: goto L_808001F4; break;
        case 6: goto L_808001F4; break;
        case 7: goto L_808001F4; break;
        case 8: goto L_808001BC; break;
        default: switch_error(__func__, 0x808000D4, 0x80801270);
    }
    // 0x808000D8: nop

L_808000DC:
    // 0x808000DC: jal         0x800DA298
    // 0x808000E0: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000E0: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_0:
    // 0x808000E4: beq         $v0, $zero, L_80800144
    if (ctx->r2 == 0) {
        // 0x808000E8: nop
    
            goto L_80800144;
    }
    // 0x808000E8: nop

    // 0x808000EC: jal         0x800F54E4
    // 0x808000F0: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808000F0: nop

    after_1:
    // 0x808000F4: jal         0x800F5410
    // 0x808000F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_2;
    // 0x808000F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808000FC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800100: bne         $v0, $at, L_80800114
    if (ctx->r2 != ctx->r1) {
        // 0x80800104: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800114;
    }
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: addiu       $t9, $zero, 0x1814
    ctx->r25 = ADD32(0, 0X1814);
    // 0x8080010C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X13B8) << 16);
    // 0x80800110: sh          $t9, 0x13B8($at)
    MEM_H((int16_t)RELOC_LO16(2420, 0X13B8), ctx->r1) = ctx->r25;
L_80800114:
    // 0x80800114: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2420, 0X13B4) << 16);
    // 0x80800118: addiu       $a2, $a2, 0x13B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2420, 0X13B4));
    // 0x8080011C: jal         0x8008A1E8
    // 0x80800120: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800120: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_3:
    // 0x80800124: beq         $v0, $zero, L_808001F4
    if (ctx->r2 == 0) {
        // 0x80800128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F4;
    }
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800134: jal         0x8080119C
    // 0x80800138: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8080119C_chdinofamilymother(rdram, ctx);
        goto after_4;
    // 0x80800138: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8080013C: b           L_808001F4
    // 0x80800140: nop

        goto L_808001F4;
    // 0x80800140: nop

L_80800144:
    // 0x80800144: jal         0x800F54E4
    // 0x80800148: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800148: nop

    after_5:
    // 0x8080014C: jal         0x800F5410
    // 0x80800150: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_6;
    // 0x80800150: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800154: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800158: beq         $v0, $at, L_80800174
    if (ctx->r2 == ctx->r1) {
        // 0x8080015C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800174;
    }
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800164: beq         $v0, $at, L_80800184
    if (ctx->r2 == ctx->r1) {
        // 0x80800168: addiu       $t1, $zero, 0x1813
        ctx->r9 = ADD32(0, 0X1813);
            goto L_80800184;
    }
    // 0x80800168: addiu       $t1, $zero, 0x1813
    ctx->r9 = ADD32(0, 0X1813);
    // 0x8080016C: b           L_8080018C
    // 0x80800170: nop

        goto L_8080018C;
    // 0x80800170: nop

L_80800174:
    // 0x80800174: addiu       $t0, $zero, 0x1812
    ctx->r8 = ADD32(0, 0X1812);
    // 0x80800178: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X139C) << 16);
    // 0x8080017C: b           L_8080018C
    // 0x80800180: sh          $t0, 0x139C($at)
    MEM_H((int16_t)RELOC_LO16(2420, 0X139C), ctx->r1) = ctx->r8;
        goto L_8080018C;
    // 0x80800180: sh          $t0, 0x139C($at)
    MEM_H((int16_t)RELOC_LO16(2420, 0X139C), ctx->r1) = ctx->r8;
L_80800184:
    // 0x80800184: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X139C) << 16);
    // 0x80800188: sh          $t1, 0x139C($at)
    MEM_H((int16_t)RELOC_LO16(2420, 0X139C), ctx->r1) = ctx->r9;
L_8080018C:
    // 0x8080018C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2420, 0X1398) << 16);
    // 0x80800190: addiu       $a2, $a2, 0x1398
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2420, 0X1398));
    // 0x80800194: jal         0x8008A1E8
    // 0x80800198: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x80800198: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_7:
    // 0x8080019C: beq         $v0, $zero, L_808001F4
    if (ctx->r2 == 0) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F4;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001AC: jal         0x8080119C
    // 0x808001B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8080119C_chdinofamilymother(rdram, ctx);
        goto after_8;
    // 0x808001B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x808001B4: b           L_808001F4
    // 0x808001B8: nop

        goto L_808001F4;
    // 0x808001B8: nop

L_808001BC:
    // 0x808001BC: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    // 0x808001C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808001C4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x808001C8: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    // 0x808001CC: jal         0x8008A1D0
    // 0x808001D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x808001D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x808001D4: beq         $v0, $zero, L_808001F4
    if (ctx->r2 == 0) {
        // 0x808001D8: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_808001F4;
    }
    // 0x808001D8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808001DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001E0: addiu       $t2, $zero, 0x65
    ctx->r10 = ADD32(0, 0X65);
    // 0x808001E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808001E8: addiu       $a1, $zero, 0x17C6
    ctx->r5 = ADD32(0, 0X17C6);
    // 0x808001EC: jal         0x8008A208
    // 0x808001F0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x808001F0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_10:
L_808001F4:
    // 0x808001F4: jal         0x808008E4
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008E4_chdinofamilymother(rdram, ctx);
        goto after_11;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001FC: jal         0x8080096C
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080096C_chdinofamilymother(rdram, ctx);
        goto after_12;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800208: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080020C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void func_8008C9F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C9F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8008C9F4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008C9F8: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008C9FC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8008CA00: swc1        $f12, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f12.u32l;
    // 0x8008CA04: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8008CA08: swc1        $f14, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f14.u32l;
    // 0x8008CA0C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8008CA10: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8008CA14: swc1        $f4, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f4.u32l;
    // 0x8008CA18: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8008CA1C: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8008CA20: swc1        $f6, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f6.u32l;
    // 0x8008CA24: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x8008CA28: jr          $ra
    // 0x8008CA2C: sb          $zero, 0x38($t0)
    MEM_B(0X38, ctx->r8) = 0;
    return;
    // 0x8008CA2C: sb          $zero, 0x38($t0)
    MEM_B(0X38, ctx->r8) = 0;
;}
RECOMP_FUNC void func_808006AC_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006B8: jal         0x800DA298
    // 0x808006BC: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808006BC: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    after_0:
    // 0x808006C0: beq         $v0, $zero, L_808006F4
    if (ctx->r2 == 0) {
        // 0x808006C4: addiu       $a0, $zero, 0x9CD
        ctx->r4 = ADD32(0, 0X9CD);
            goto L_808006F4;
    }
    // 0x808006C4: addiu       $a0, $zero, 0x9CD
    ctx->r4 = ADD32(0, 0X9CD);
    // 0x808006C8: jal         0x800DA564
    // 0x808006CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x808006CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808006D0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808006D4: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x808006D8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(880, 0X1480) << 16);
    // 0x808006DC: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x808006E0: lh          $a2, 0x1480($a2)
    ctx->r6 = MEM_H(ctx->r6, (int16_t)RELOC_LO16(880, 0X1480));
    // 0x808006E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006E8: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    // 0x808006EC: jal         0x80085708
    // 0x808006F0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x808006F0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
L_808006F4:
    // 0x808006F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006FC: jr          $ra
    // 0x80800700: nop

    return;
    // 0x80800700: nop

;}
RECOMP_FUNC void func_80800544_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800544: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800548: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080054C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800550: jal         0x80800090
    // 0x80800554: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800090_bskazglide(rdram, ctx);
        goto after_0;
    // 0x80800554: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800558: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x8080055C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800564: jal         0x8008CDB8
    // 0x80800568: addiu       $a1, $zero, 0x11C
    ctx->r5 = ADD32(0, 0X11C);
    baanim_playForDuration_once(rdram, ctx);
        goto after_1;
    // 0x80800568: addiu       $a1, $zero, 0x11C
    ctx->r5 = ADD32(0, 0X11C);
    after_1:
    // 0x8080056C: jal         0x8009D9D4
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D9D4(rdram, ctx);
        goto after_2;
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: jal         0x8009C128
    // 0x8080057C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x8080057C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: jal         0x800A32C4
    // 0x80800588: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800A32C4(rdram, ctx);
        goto after_4;
    // 0x80800588: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x8080058C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800590: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800594: jal         0x800F1E6C
    // 0x80800598: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800F1E6C(rdram, ctx);
        goto after_5;
    // 0x80800598: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x8080059C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808005A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005A4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808005A8: jal         0x800136E4
    // 0x808005AC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x808005AC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_6:
    // 0x808005B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005B4: jal         0x8009C914
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_7;
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808005BC: jal         0x8009C974
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_8;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C8: jal         0x8009B9B0
    // 0x808005CC: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_9;
    // 0x808005CC: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_9:
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D4: jal         0x8009B9C0
    // 0x808005D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_10;
    // 0x808005D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x808005DC: jal         0x8009BB00
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808005E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005EC: jal         0x8009BA68
    // 0x808005F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x808005F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x808005F4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x808005F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800604: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800608: jal         0x8009FFD8
    // 0x8080060C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_13;
    // 0x8080060C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_13:
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: jal         0x8009BA58
    // 0x80800618: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_14;
    // 0x80800618: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    after_14:
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800620: jal         0x8009BCB4
    // 0x80800624: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_15;
    // 0x80800624: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_15:
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: jal         0x8009BCC4
    // 0x80800630: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_16;
    // 0x80800630: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    after_16:
    // 0x80800634: jal         0x8008E944
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_17;
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080063C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800640: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800644: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800648: jr          $ra
    // 0x8080064C: nop

    return;
    // 0x8080064C: nop

;}
RECOMP_FUNC void func_80801330_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801334: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080133C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801340: addiu       $a1, $a3, 0x1A
    ctx->r5 = ADD32(ctx->r7, 0X1A);
    // 0x80801344: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80801348: jal         0x80801248
    // 0x8080134C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_80801248_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x8080134C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80801350: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80801354: sb          $v0, 0x1B($a3)
    MEM_B(0X1B, ctx->r7) = ctx->r2;
    // 0x80801358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080135C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801360: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80801364: jr          $ra
    // 0x80801368: nop

    return;
    // 0x80801368: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AA8: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082AA8);
    return;
    // 0x80082AAC: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void chping_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2144, 0X410) << 16);
    // 0x808003EC: jr          $ra
    // 0x808003F0: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2144, 0X410));
    return;
    // 0x808003F0: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2144, 0X410));
    // 0x808003F4: nop

    // 0x808003F8: nop

    // 0x808003FC: nop

;}
RECOMP_FUNC void func_800978A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800978A4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800978A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800978AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800978B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800978B4: jal         0x8009C15C
    // 0x800978B8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C15C(rdram, ctx);
        goto after_0;
    // 0x800978B8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x800978BC: lw          $v0, 0x98($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X98);
    // 0x800978C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800978C4: lbu         $t6, 0x26($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X26);
    // 0x800978C8: beq         $t6, $zero, L_800978EC
    if (ctx->r14 == 0) {
        // 0x800978CC: nop
    
            goto L_800978EC;
    }
    // 0x800978CC: nop

    // 0x800978D0: sb          $zero, 0x26($v0)
    MEM_B(0X26, ctx->r2) = 0;
    // 0x800978D4: lw          $a1, 0x98($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X98);
    // 0x800978D8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800978DC: jal         0x800EE7F8
    // 0x800978E0: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800978E0: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_1:
    // 0x800978E4: b           L_800978F8
    // 0x800978E8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
        goto L_800978F8;
    // 0x800978E8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
L_800978EC:
    // 0x800978EC: jal         0x8009C128
    // 0x800978F0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x800978F0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x800978F4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
L_800978F8:
    // 0x800978F8: jal         0x800EE7F8
    // 0x800978FC: lw          $a1, 0x98($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X98);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x800978FC: lw          $a1, 0x98($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X98);
    after_3:
    // 0x80097900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097904: jal         0x800972BC
    // 0x80097908: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800972BC(rdram, ctx);
        goto after_4;
    // 0x80097908: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x8009790C: beq         $v0, $zero, L_80097938
    if (ctx->r2 == 0) {
        // 0x80097910: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80097938;
    }
    // 0x80097910: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80097914: lw          $a1, 0x98($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X98);
    // 0x80097918: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8009791C: jal         0x800EE7F8
    // 0x80097920: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80097920: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_5:
    // 0x80097924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097928: jal         0x8009BA58
    // 0x8009792C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x8009792C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x80097930: b           L_80097950
    // 0x80097934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80097950;
    // 0x80097934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80097938:
    // 0x80097938: jal         0x800EE7F8
    // 0x8009793C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8009793C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x80097940: lw          $a0, 0x98($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X98);
    // 0x80097944: jal         0x800EE7F8
    // 0x80097948: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80097948: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_8:
    // 0x8009794C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80097950:
    // 0x80097950: jal         0x8009C0F8
    // 0x80097954: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009C0F8(rdram, ctx);
        goto after_9;
    // 0x80097954: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x80097958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009795C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80097960: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80097964: jr          $ra
    // 0x80097968: nop

    return;
    // 0x80097968: nop

    // 0x8009796C: nop

;}
RECOMP_FUNC void func_8080013C_chfairgroundworker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800140: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80800144: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80800148: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080014C: addiu       $s2, $sp, 0x54
    ctx->r18 = ADD32(ctx->r29, 0X54);
    // 0x80800150: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800154: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80800158: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8080015C: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80800160: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80800164: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800168: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080016C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800170: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800174: jal         0x800EE7F8
    // 0x80800178: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800178: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x8080017C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800180: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800184: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800188: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080018C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800190: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800194: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800198: jal         0x800EF1B8
    // 0x8080019C: nop

    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x8080019C: nop

    after_1:
    // 0x808001A0: jal         0x800B53A4
    // 0x808001A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x808001A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x808001A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001AC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808001B0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808001B4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808001B8: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x808001BC: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(840, 0X430) << 16);
    // 0x808001C0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808001C4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808001C8: addiu       $s4, $s4, 0x430
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(840, 0X430));
    // 0x808001CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001D0: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x808001D4: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
    // 0x808001D8: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
L_808001DC:
    // 0x808001DC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808001E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001E4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808001E8: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x808001EC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808001F0: jal         0x800EEB9C
    // 0x808001F4: nop

    func_800EEB9C(rdram, ctx);
        goto after_3;
    // 0x808001F4: nop

    after_3:
    // 0x808001F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001FC: jal         0x800EF04C
    // 0x80800200: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80800200: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80800204: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800208: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080020C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800210: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800214: jal         0x800BABB8
    // 0x80800218: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x80800218: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_5:
    // 0x8080021C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800220: bnel        $s0, $s5, L_808001DC
    if (ctx->r16 != ctx->r21) {
        // 0x80800224: mtc1        $s0, $f10
        ctx->f10.u32l = ctx->r16;
            goto L_808001DC;
    }
    goto skip_0;
    // 0x80800224: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    skip_0:
    // 0x80800228: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8080022C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800230: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800234: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800238: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8080023C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80800240: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80800244: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80800248: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8080024C: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x80800250: jr          $ra
    // 0x80800254: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800254: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800258: nop

    // 0x8080025C: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080092C: jal         0x80800888
    // 0x80800930: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_80800888_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800930: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80800934: bne         $v0, $zero, L_80800944
    if (ctx->r2 != 0) {
        // 0x80800938: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800944;
    }
    // 0x80800938: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080093C: b           L_80800950
    // 0x80800940: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800950;
    // 0x80800940: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800944:
    // 0x80800944: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080094C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_80800950:
    // 0x80800950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800958: jr          $ra
    // 0x8080095C: nop

    return;
    // 0x8080095C: nop

;}
RECOMP_FUNC void func_808017A0_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808017A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808017A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808017AC: jal         0x808001A8
    // 0x808017B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bsvan_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808017B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808017B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017B8: addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
    // 0x808017BC: jal         0x8008CB3C
    // 0x808017C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808017C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x808017C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808017C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808017CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808017D4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808017D8: jal         0x8009FFD8
    // 0x808017DC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808017DC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808017E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017E4: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808017E8: jal         0x8009C99C
    // 0x808017EC: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x808017EC: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_3:
    // 0x808017F0: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x808017F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017F8: jal         0x8080164C
    // 0x808017FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080164C_bsvan(rdram, ctx);
        goto after_4;
    // 0x808017FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80801800: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801804: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801808: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080180C: jr          $ra
    // 0x80801810: nop

    return;
    // 0x80801810: nop

;}
RECOMP_FUNC void func_8001862C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001862C: jr          $ra
    // 0x80018630: nop

    return;
    // 0x80018630: nop

;}
RECOMP_FUNC void func_800DAB54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAB54: sra         $t6, $a1, 5
    ctx->r14 = S32(SIGNED(ctx->r5) >> 5);
    // 0x800DAB58: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800DAB5C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800DAB60: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800DAB64: andi        $t0, $a1, 0x1F
    ctx->r8 = ctx->r5 & 0X1F;
    // 0x800DAB68: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800DAB6C: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x800DAB70: and         $t3, $t9, $t2
    ctx->r11 = ctx->r25 & ctx->r10;
    // 0x800DAB74: beq         $t3, $zero, L_800DAB84
    if (ctx->r11 == 0) {
        // 0x800DAB78: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800DAB84;
    }
    // 0x800DAB78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800DAB7C: jr          $ra
    // 0x800DAB80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800DAB80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DAB84:
    // 0x800DAB84: jr          $ra
    // 0x800DAB88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800DAB88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80096530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096530: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096534: lbu         $v0, 0xA3($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA3);
    // 0x80096538: xori        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 ^ 0X3;
    // 0x8009653C: jr          $ra
    // 0x80096540: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    return;
    // 0x80096540: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void subaddietaxi_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080075C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800760: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800764: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800768: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080076C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800770: jal         0x8010410C
    // 0x80800774: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8010410C(rdram, ctx);
        goto after_0;
    // 0x80800774: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800778: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080077C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800780: bltz        $a1, L_80800790
    if (SIGNED(ctx->r5) < 0) {
        // 0x80800784: nop
    
            goto L_80800790;
    }
    // 0x80800784: nop

    // 0x80800788: jal         0x80102424
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80800790:
    // 0x80800790: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3334, 0XD38) << 16);
    // 0x80800794: lwc1        $f4, 0xD38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3334, 0XD38));
    // 0x80800798: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080079C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808007A0: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x808007A4: jal         0x800EEB9C
    // 0x808007A8: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    func_800EEB9C(rdram, ctx);
        goto after_2;
    // 0x808007A8: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x808007AC: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x808007B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007B4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808007B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007BC: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808007C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3334, 0XD3C) << 16);
    // 0x808007C4: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x808007C8: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x808007CC: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x808007D0: lwc1        $f16, 0xD3C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3334, 0XD3C));
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007DC: jal         0x8008A4B0
    // 0x808007E0: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808007E0: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x808007E4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808007E8: sh          $zero, 0x20($t6)
    MEM_H(0X20, ctx->r14) = 0;
    // 0x808007EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007F8: jr          $ra
    // 0x808007FC: nop

    return;
    // 0x808007FC: nop

;}
RECOMP_FUNC void func_801063EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801063EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801063F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801063F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801063F8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801063FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106400: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x80106404: lw          $a0, 0x6ED0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6ED0);
    // 0x80106408: jal         0x800B301C
    // 0x8010640C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x8010640C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80106410: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80106414: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80106418: beql        $a2, $t6, L_80106470
    if (ctx->r6 == ctx->r14) {
        // 0x8010641C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106470;
    }
    goto skip_0;
    // 0x8010641C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80106420: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80106424: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80106428: jal         0x800B296C
    // 0x8010642C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_1;
    // 0x8010642C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80106430: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80106434: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80106438: jal         0x800B28C4
    // 0x8010643C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_2;
    // 0x8010643C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80106440: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80106444: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80106448: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010644C: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80106450: beq         $at, $zero, L_80106464
    if (ctx->r1 == 0) {
        // 0x80106454: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_80106464;
    }
L_80106454:
    // 0x80106454: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    // 0x80106458: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8010645C: bne         $at, $zero, L_80106454
    if (ctx->r1 != 0) {
        // 0x80106460: sw          $a2, -0xA8($v1)
        MEM_W(-0XA8, ctx->r3) = ctx->r6;
            goto L_80106454;
    }
    // 0x80106460: sw          $a2, -0xA8($v1)
    MEM_W(-0XA8, ctx->r3) = ctx->r6;
L_80106464:
    // 0x80106464: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80106468: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x8010646C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106470:
    // 0x80106470: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80106474: jr          $ra
    // 0x80106478: nop

    return;
    // 0x80106478: nop

;}
RECOMP_FUNC void func_800F5C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5C94: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5C98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5C9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5CA4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5CA8: jal         0x800F3ED0
    // 0x800F5CAC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F3ED0(rdram, ctx);
        goto after_0;
    // 0x800F5CAC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5CB8: jr          $ra
    // 0x800F5CBC: nop

    return;
    // 0x800F5CBC: nop

;}
RECOMP_FUNC void _bainvisible_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854F0: syscall     164
    recomp_syscall_handler(rdram, ctx, 0x800854F0);
    return;
    // 0x800854F4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800410_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800418: jal         0x80096388
    // 0x8080041C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80096388(rdram, ctx);
        goto after_0;
    // 0x8080041C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800420: xori        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 ^ 0X7;
    // 0x80800424: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80800428: beql        $v0, $zero, L_80800444
    if (ctx->r2 == 0) {
        // 0x8080042C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800444;
    }
    goto skip_0;
    // 0x8080042C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800430: jal         0x80097524
    // 0x80800434: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80097524(rdram, ctx);
        goto after_1;
    // 0x80800434: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800438: xori        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 ^ 0X4;
    // 0x8080043C: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
    // 0x80800440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800444:
    // 0x80800444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800448: jr          $ra
    // 0x8080044C: nop

    return;
    // 0x8080044C: nop

;}
RECOMP_FUNC void _bskaztorpedo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083770: syscall     72
    recomp_syscall_handler(rdram, ctx, 0x80083770);
    return;
    // 0x80083774: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chalienkids_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1324, 0X2124) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x2124
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1324, 0X2124));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x2124
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1324, 0X2124));
;}
RECOMP_FUNC void bamovegoto_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x808001E4: sw          $a1, 0x80($t6)
    MEM_W(0X80, ctx->r14) = ctx->r5;
    // 0x808001E8: lw          $t7, 0xC8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC8);
    // 0x808001EC: jr          $ra
    // 0x808001F0: sw          $a2, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->r6;
    return;
    // 0x808001F0: sw          $a2, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->r6;
;}
RECOMP_FUNC void func_800EA3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA3A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EA3A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800EA3A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800EA3AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EA3B0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800EA3B4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800EA3B8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800EA3BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EA3C0: addiu       $s2, $s2, 0x2E78
    ctx->r18 = ADD32(ctx->r18, 0X2E78);
    // 0x800EA3C4: addiu       $s1, $s1, 0x2DD8
    ctx->r17 = ADD32(ctx->r17, 0X2DD8);
    // 0x800EA3C8: addiu       $s0, $s0, 0x2DD0
    ctx->r16 = ADD32(ctx->r16, 0X2DD0);
L_800EA3CC:
    // 0x800EA3CC: jal         0x800EFD24
    // 0x800EA3D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800EA3D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800EA3D4: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x800EA3D8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800EA3DC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800EA3E0: bne         $s1, $s2, L_800EA3CC
    if (ctx->r17 != ctx->r18) {
        // 0x800EA3E4: sw          $zero, 0x4($s0)
        MEM_W(0X4, ctx->r16) = 0;
            goto L_800EA3CC;
    }
    // 0x800EA3E4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800EA3E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800EA3EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EA3F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800EA3F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800EA3F8: jr          $ra
    // 0x800EA3FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800EA3FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800000_chdrawbridgeswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80085808
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800018: jal         0x80085810
    // 0x8080001C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080001C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void _baswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085278: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x80085278);
    return;
    // 0x8008527C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void sufreezy_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800110: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800114: jal         0x80106790
    // 0x80800118: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800118: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080011C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800120: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(3174, 0X328) << 16);
    // 0x80800124: addiu       $t6, $t6, 0x328
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(3174, 0X328));
    // 0x80800128: lw          $a2, 0x38($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X38);
    // 0x8080012C: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800130: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800134: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800138: jal         0x800BBCB8
    // 0x8080013C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x8080013C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800140: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3174, 0X314) << 16);
    // 0x80800144: addiu       $a2, $a2, 0x314
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3174, 0X314));
    // 0x80800148: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080014C: jal         0x80089D18
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800154: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800158: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3174, 0X2F0) << 16);
    // 0x8080015C: lwc1        $f6, 0x2F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3174, 0X2F0));
    // 0x80800160: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80800164: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800168: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080016C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800170: jal         0x801094E0
    // 0x80800174: nop

    func_801094E0(rdram, ctx);
        goto after_3;
    // 0x80800174: nop

    after_3:
    // 0x80800178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080017C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A808: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A808);
    return;
    // 0x8008A80C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
