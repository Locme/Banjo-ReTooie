#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800320_chstarspinnerstar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800324: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800328: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080032C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800330: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800334: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800338: addiu       $a1, $zero, 0x337
    ctx->r5 = ADD32(0, 0X337);
    // 0x8080033C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800340: jal         0x80089C20
    // 0x80800344: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800344: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80800348: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: jal         0x80800660
    // 0x80800354: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
    func_80800660_chstarspinnerstar(rdram, ctx);
        goto after_1;
    // 0x80800354: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
    after_1:
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: jal         0x80085E18
    // 0x80800360: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _chstarspinnerctrl_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800360: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800364: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800368: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x8080036C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800370: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x80800374: jal         0x800EE7F8
    // 0x80800378: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800378: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8080037C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800380: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800384: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800388: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080038C: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80800390: nop

    // 0x80800394: bc1fl       L_808003B0
    if (!c1cs) {
        // 0x80800398: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_808003B0;
    }
    goto skip_0;
    // 0x80800398: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_0:
    // 0x8080039C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808003A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003A4: b           L_808003B8
    // 0x808003A8: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
        goto L_808003B8;
    // 0x808003A8: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x808003AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_808003B0:
    // 0x808003B0: nop

    // 0x808003B4: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
L_808003B8:
    // 0x808003B8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808003BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003C4: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x808003C8: jal         0x800EA05C
    // 0x808003CC: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    func_800EA05C(rdram, ctx);
        goto after_4;
    // 0x808003CC: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    after_4:
    // 0x808003D0: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x808003D4: beql        $v0, $at, L_808003E8
    if (ctx->r2 == ctx->r1) {
        // 0x808003D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003E8;
    }
    goto skip_1;
    // 0x808003D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808003DC: jal         0x8010A624
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_5;
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808003E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003E8:
    // 0x808003E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003F0: jr          $ra
    // 0x808003F4: nop

    return;
    // 0x808003F4: nop

;}
RECOMP_FUNC void func_80800744_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080074C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800750: jal         0x808005DC
    // 0x80800754: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808005DC_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x80800754: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800758: jal         0x80800164
    // 0x8080075C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800164_bsbanshack(rdram, ctx);
        goto after_1;
    // 0x8080075C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800768: jr          $ra
    // 0x8080076C: nop

    return;
    // 0x8080076C: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F70: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F70);
    return;
    // 0x80087F74: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void _changlerbossbubble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865B8: syscall     341
    recomp_syscall_handler(rdram, ctx, 0x800865B8);
    return;
    // 0x800865BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chlavaarchgrill3switches_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087108: syscall     517
    recomp_syscall_handler(rdram, ctx, 0x80087108);
    return;
    // 0x8008710C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsmum_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D04: jal         0x808001E0
    // 0x80800D08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800D08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D10: jal         0x800845D8
    // 0x80800D14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800D14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800D18: lui         $a2, 0x3F0E
    ctx->r6 = S32(0X3F0E << 16);
    // 0x80800D1C: ori         $a2, $a2, 0x9100
    ctx->r6 = ctx->r6 | 0X9100;
    // 0x80800D20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D24: jal         0x800845E0
    // 0x80800D28: addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800D28: addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    after_2:
    // 0x80800D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D34: jr          $ra
    // 0x80800D38: nop

    return;
    // 0x80800D38: nop

;}
RECOMP_FUNC void func_80013DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013DE4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80013DE8: addiu       $v1, $v1, -0x7158
    ctx->r3 = ADD32(ctx->r3, -0X7158);
    // 0x80013DEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80013DF0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80013DF4: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80013DF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80013DFC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80013E00: addiu       $t7, $t7, -0x7154
    ctx->r15 = ADD32(ctx->r15, -0X7154);
    // 0x80013E04: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80013E08: mfhi        $v0
    ctx->r2 = hi;
    // 0x80013E0C: beq         $v0, $t8, L_80013E2C
    if (ctx->r2 == ctx->r24) {
        // 0x80013E10: nop
    
            goto L_80013E2C;
    }
    // 0x80013E10: nop

    // 0x80013E14: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80013E18: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013E1C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80013E20: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80013E24: sw          $a0, -0x71A8($at)
    MEM_W(-0X71A8, ctx->r1) = ctx->r4;
    // 0x80013E28: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80013E2C:
    // 0x80013E2C: jr          $ra
    // 0x80013E30: nop

    return;
    // 0x80013E30: nop

;}
RECOMP_FUNC void func_800138D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800138D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800138D4: lwc1        $f14, 0x16E4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X16E4);
    // 0x800138D8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800138DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800138E0: nop

    // 0x800138E4: mul.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800138E8: lui         $at, 0x4B00
    ctx->r1 = S32(0X4B00 << 16);
    // 0x800138EC: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800138F0: addiu       $t1, $t1, -0x2C60
    ctx->r9 = ADD32(ctx->r9, -0X2C60);
    // 0x800138F4: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800138F8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800138FC: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80013900: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80013904: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80013908: mul.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8001390C: nop

    // 0x80013910: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80013914: round.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = lroundf(ctx->f4.fl);
    // 0x80013918: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8001391C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013920: lwc1        $f6, 0x16E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X16E8);
    // 0x80013924: andi        $t2, $a0, 0xFFF
    ctx->r10 = ctx->r4 & 0XFFF;
    // 0x80013928: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8001392C: srl         $t0, $a0, 10
    ctx->r8 = S32(U32(ctx->r4) >> 10);
    // 0x80013930: addiu       $t0, $t0, 0x800
    ctx->r8 = ADD32(ctx->r8, 0X800);
    // 0x80013934: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013938: andi        $t0, $t0, 0x1FFC
    ctx->r8 = ctx->r8 & 0X1FFC;
    // 0x8001393C: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80013940: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80013944: lwc1        $f12, 0x4($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80013948: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001394C: sub.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80013950: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80013954: jr          $ra
    // 0x80013958: add.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f10.fl;
    return;
    // 0x80013958: add.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f10.fl;
;}
RECOMP_FUNC void bsbanshack_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(45, 0XCC0) << 16);
    // 0x808005D0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005D4: jr          $ra
    // 0x808005D8: lw          $v0, 0xCC0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XCC0));
    return;
    // 0x808005D8: lw          $v0, 0xCC0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XCC0));
;}
RECOMP_FUNC void func_80800C50_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C5C: jal         0x80100094
    // 0x80800C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C64: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800C68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C6C: lbu         $v1, 0x79($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X79);
    // 0x80800C70: srl         $t6, $v1, 4
    ctx->r14 = S32(U32(ctx->r3) >> 4);
    // 0x80800C74: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800C78: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80800C7C: andi        $t0, $v1, 0xFF0F
    ctx->r8 = ctx->r3 & 0XFF0F;
    // 0x80800C80: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80800C84: sb          $t1, 0x79($a3)
    MEM_B(0X79, ctx->r7) = ctx->r9;
    // 0x80800C88: lbu         $t2, 0x93($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X93);
    // 0x80800C8C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80800C90: sb          $t3, 0x93($v0)
    MEM_B(0X93, ctx->r2) = ctx->r11;
    // 0x80800C94: lbu         $t4, 0x79($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X79);
    // 0x80800C98: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x80800C9C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80800CA0: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80800CA4: beq         $at, $zero, L_80800E00
    if (ctx->r1 == 0) {
        // 0x80800CA8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800E00;
    }
    // 0x80800CA8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800CAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3DC4) << 16);
    // 0x80800CB0: addu        $at, $at, $t6
    gpr jr_addend_80800CB8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800CB4: lw          $t6, 0x3DC4($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3DC4));
    // 0x80800CB8: jr          $t6
    // 0x80800CBC: nop

    switch (jr_addend_80800CB8 >> 2) {
        case 0: goto L_80800CC0; break;
        case 1: goto L_80800D0C; break;
        case 2: goto L_80800D54; break;
        case 3: goto L_80800D88; break;
        case 4: goto L_80800D9C; break;
        case 5: goto L_80800DB4; break;
        case 6: goto L_80800DE4; break;
        case 7: goto L_80800DF8; break;
        default: switch_error(__func__, 0x80800CB8, 0x80803DC4);
    }
    // 0x80800CBC: nop

L_80800CC0:
    // 0x80800CC0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80800CC4: jal         0x800DC0C0
    // 0x80800CC8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80800CC8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800CCC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800CD0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CD4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800CD8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800CDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800CE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800CE4: bc1tl       L_80800D00
    if (c1cs) {
        // 0x80800CE8: sb          $a1, 0x88($a0)
        MEM_B(0X88, ctx->r4) = ctx->r5;
            goto L_80800D00;
    }
    goto skip_0;
    // 0x80800CE8: sb          $a1, 0x88($a0)
    MEM_B(0X88, ctx->r4) = ctx->r5;
    skip_0:
    // 0x80800CEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800CF0: sb          $a1, 0x87($a0)
    MEM_B(0X87, ctx->r4) = ctx->r5;
    // 0x80800CF4: b           L_80800E00
    // 0x80800CF8: sb          $zero, 0x94($a0)
    MEM_B(0X94, ctx->r4) = 0;
        goto L_80800E00;
    // 0x80800CF8: sb          $zero, 0x94($a0)
    MEM_B(0X94, ctx->r4) = 0;
    // 0x80800CFC: sb          $a1, 0x88($a0)
    MEM_B(0X88, ctx->r4) = ctx->r5;
L_80800D00:
    // 0x80800D00: sb          $v1, 0x85($a0)
    MEM_B(0X85, ctx->r4) = ctx->r3;
    // 0x80800D04: b           L_80800E00
    // 0x80800D08: sb          $v1, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r3;
        goto L_80800E00;
    // 0x80800D08: sb          $v1, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r3;
L_80800D0C:
    // 0x80800D0C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80800D10: jal         0x800DC0C0
    // 0x80800D14: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x80800D14: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800D18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800D1C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D20: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800D24: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800D28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800D2C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80800D30: bc1tl       L_80800D4C
    if (c1cs) {
        // 0x80800D34: sb          $a1, 0x8A($a0)
        MEM_B(0X8A, ctx->r4) = ctx->r5;
            goto L_80800D4C;
    }
    goto skip_1;
    // 0x80800D34: sb          $a1, 0x8A($a0)
    MEM_B(0X8A, ctx->r4) = ctx->r5;
    skip_1:
    // 0x80800D38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800D3C: sb          $a1, 0x89($a0)
    MEM_B(0X89, ctx->r4) = ctx->r5;
    // 0x80800D40: b           L_80800E00
    // 0x80800D44: sb          $a1, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r5;
        goto L_80800E00;
    // 0x80800D44: sb          $a1, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r5;
    // 0x80800D48: sb          $a1, 0x8A($a0)
    MEM_B(0X8A, ctx->r4) = ctx->r5;
L_80800D4C:
    // 0x80800D4C: b           L_80800E00
    // 0x80800D50: sb          $t7, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r15;
        goto L_80800E00;
    // 0x80800D50: sb          $t7, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r15;
L_80800D54:
    // 0x80800D54: lbu         $t8, 0x88($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X88);
    // 0x80800D58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D5C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800D60: bne         $t8, $at, L_80800D78
    if (ctx->r24 != ctx->r1) {
        // 0x80800D64: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800D78;
    }
    // 0x80800D64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800D68: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800D6C: sb          $a1, 0x87($v0)
    MEM_B(0X87, ctx->r2) = ctx->r5;
    // 0x80800D70: b           L_80800E00
    // 0x80800D74: sb          $zero, 0x94($v0)
    MEM_B(0X94, ctx->r2) = 0;
        goto L_80800E00;
    // 0x80800D74: sb          $zero, 0x94($v0)
    MEM_B(0X94, ctx->r2) = 0;
L_80800D78:
    // 0x80800D78: sb          $a1, 0x88($v0)
    MEM_B(0X88, ctx->r2) = ctx->r5;
    // 0x80800D7C: sb          $v1, 0x85($v0)
    MEM_B(0X85, ctx->r2) = ctx->r3;
    // 0x80800D80: b           L_80800E00
    // 0x80800D84: sb          $v1, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r3;
        goto L_80800E00;
    // 0x80800D84: sb          $v1, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r3;
L_80800D88:
    // 0x80800D88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800D8C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80800D90: sb          $a1, 0x86($v0)
    MEM_B(0X86, ctx->r2) = ctx->r5;
    // 0x80800D94: b           L_80800E00
    // 0x80800D98: sb          $t9, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r25;
        goto L_80800E00;
    // 0x80800D98: sb          $t9, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r25;
L_80800D9C:
    // 0x80800D9C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800DA0: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80800DA4: sb          $a1, 0x8B($v0)
    MEM_B(0X8B, ctx->r2) = ctx->r5;
    // 0x80800DA8: sb          $a1, 0x8C($v0)
    MEM_B(0X8C, ctx->r2) = ctx->r5;
    // 0x80800DAC: b           L_80800E00
    // 0x80800DB0: sb          $t0, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r8;
        goto L_80800E00;
    // 0x80800DB0: sb          $t0, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r8;
L_80800DB4:
    // 0x80800DB4: lbu         $t1, 0x8A($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X8A);
    // 0x80800DB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DBC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800DC0: bne         $t1, $at, L_80800DD8
    if (ctx->r9 != ctx->r1) {
        // 0x80800DC4: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_80800DD8;
    }
    // 0x80800DC4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80800DC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800DCC: sb          $a1, 0x89($v0)
    MEM_B(0X89, ctx->r2) = ctx->r5;
    // 0x80800DD0: b           L_80800E00
    // 0x80800DD4: sb          $a1, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r5;
        goto L_80800E00;
    // 0x80800DD4: sb          $a1, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r5;
L_80800DD8:
    // 0x80800DD8: sb          $a1, 0x8A($v0)
    MEM_B(0X8A, ctx->r2) = ctx->r5;
    // 0x80800DDC: b           L_80800E00
    // 0x80800DE0: sb          $t2, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r10;
        goto L_80800E00;
    // 0x80800DE0: sb          $t2, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r10;
L_80800DE4:
    // 0x80800DE4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80800DE8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80800DEC: sb          $t3, 0x86($v0)
    MEM_B(0X86, ctx->r2) = ctx->r11;
    // 0x80800DF0: b           L_80800E00
    // 0x80800DF4: sb          $t4, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r12;
        goto L_80800E00;
    // 0x80800DF4: sb          $t4, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r12;
L_80800DF8:
    // 0x80800DF8: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80800DFC: sb          $t5, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r13;
L_80800E00:
    // 0x80800E00: lbu         $t6, 0x93($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X93);
    // 0x80800E04: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800E08: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800E0C: blez        $t6, L_80800E38
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800E10: nop
    
            goto L_80800E38;
    }
    // 0x80800E10: nop

    // 0x80800E14: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800E18: jal         0x808007C4
    // 0x80800E1C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_3;
    // 0x80800E1C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800E20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800E28: jal         0x80086670
    // 0x80800E2C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800E2C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x80800E30: b           L_80800E44
    // 0x80800E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800E44;
    // 0x80800E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E38:
    // 0x80800E38: jal         0x808007C4
    // 0x80800E3C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_5;
    // 0x80800E3C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_5:
    // 0x80800E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E44:
    // 0x80800E44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E48: jr          $ra
    // 0x80800E4C: nop

    return;
    // 0x80800E4C: nop

;}
RECOMP_FUNC void func_800E7480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7480: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E7484: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E7488: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800E748C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800E7490: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800E7494: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800E7498: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E749C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E74A0: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800E74A4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800E74A8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E74AC: beq         $t6, $zero, L_800E75F8
    if (ctx->r14 == 0) {
        // 0x800E74B0: or          $s3, $a1, $zero
        ctx->r19 = ctx->r5 | 0;
            goto L_800E75F8;
    }
    // 0x800E74B0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800E74B4: lbu         $a1, 0x0($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X0);
    // 0x800E74B8: addiu       $s5, $zero, -0x8
    ctx->r21 = ADD32(0, -0X8);
    // 0x800E74BC: addiu       $s4, $zero, 0x25
    ctx->r20 = ADD32(0, 0X25);
    // 0x800E74C0: addiu       $s2, $zero, -0x4
    ctx->r18 = ADD32(0, -0X4);
L_800E74C4:
    // 0x800E74C4: beq         $s4, $a1, L_800E74E4
    if (ctx->r20 == ctx->r5) {
        // 0x800E74C8: slti        $at, $a1, 0x20
        ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
            goto L_800E74E4;
    }
    // 0x800E74C8: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x800E74CC: bnel        $at, $zero, L_800E75EC
    if (ctx->r1 != 0) {
        // 0x800E74D0: lbu         $a1, 0x1($s3)
        ctx->r5 = MEM_BU(ctx->r19, 0X1);
            goto L_800E75EC;
    }
    goto skip_0;
    // 0x800E74D0: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
    skip_0:
    // 0x800E74D4: jal         0x800E6A58
    // 0x800E74D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E6A58(rdram, ctx);
        goto after_0;
    // 0x800E74D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800E74DC: b           L_800E75EC
    // 0x800E74E0: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
        goto L_800E75EC;
    // 0x800E74E0: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
L_800E74E4:
    // 0x800E74E4: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
    // 0x800E74E8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800E74EC: addiu       $t7, $a1, -0x62
    ctx->r15 = ADD32(ctx->r5, -0X62);
    // 0x800E74F0: sltiu       $at, $t7, 0x17
    ctx->r1 = ctx->r15 < 0X17 ? 1 : 0;
    // 0x800E74F4: beq         $at, $zero, L_800E75E0
    if (ctx->r1 == 0) {
        // 0x800E74F8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800E75E0;
    }
    // 0x800E74F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E74FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800E7500: addu        $at, $at, $t7
    gpr jr_addend_800E7508 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800E7504: lw          $t7, 0x5DD8($at)
    ctx->r15 = ADD32(ctx->r1, 0X5DD8);
    // 0x800E7508: jr          $t7
    // 0x800E750C: nop

    switch (jr_addend_800E7508 >> 2) {
        case 0: goto L_800E7510; break;
        case 1: goto L_800E752C; break;
        case 2: goto L_800E7548; break;
        case 3: goto L_800E75E0; break;
        case 4: goto L_800E7564; break;
        case 5: goto L_800E75E0; break;
        case 6: goto L_800E75E0; break;
        case 7: goto L_800E75E0; break;
        case 8: goto L_800E75E0; break;
        case 9: goto L_800E75E0; break;
        case 10: goto L_800E75E0; break;
        case 11: goto L_800E75E0; break;
        case 12: goto L_800E75E0; break;
        case 13: goto L_800E75E0; break;
        case 14: goto L_800E758C; break;
        case 15: goto L_800E75E0; break;
        case 16: goto L_800E75E0; break;
        case 17: goto L_800E75A8; break;
        case 18: goto L_800E75E0; break;
        case 19: goto L_800E75E0; break;
        case 20: goto L_800E75E0; break;
        case 21: goto L_800E75E0; break;
        case 22: goto L_800E75C4; break;
        default: switch_error(__func__, 0x800E7508, 0x80125DD8);
    }
    // 0x800E750C: nop

L_800E7510:
    // 0x800E7510: addiu       $t8, $s0, 0x7
    ctx->r24 = ADD32(ctx->r16, 0X7);
    // 0x800E7514: and         $s0, $t8, $s2
    ctx->r16 = ctx->r24 & ctx->r18;
    // 0x800E7518: lw          $a1, -0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, -0X4);
    // 0x800E751C: jal         0x800E7368
    // 0x800E7520: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E7368(rdram, ctx);
        goto after_1;
    // 0x800E7520: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800E7524: b           L_800E75EC
    // 0x800E7528: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
        goto L_800E75EC;
    // 0x800E7528: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
L_800E752C:
    // 0x800E752C: addiu       $t9, $s0, 0x7
    ctx->r25 = ADD32(ctx->r16, 0X7);
    // 0x800E7530: and         $s0, $t9, $s2
    ctx->r16 = ctx->r25 & ctx->r18;
    // 0x800E7534: lbu         $a1, -0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, -0X1);
    // 0x800E7538: jal         0x800E6A58
    // 0x800E753C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E6A58(rdram, ctx);
        goto after_2;
    // 0x800E753C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800E7540: b           L_800E75EC
    // 0x800E7544: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
        goto L_800E75EC;
    // 0x800E7544: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
L_800E7548:
    // 0x800E7548: addiu       $t0, $s0, 0x7
    ctx->r8 = ADD32(ctx->r16, 0X7);
    // 0x800E754C: and         $s0, $t0, $s2
    ctx->r16 = ctx->r8 & ctx->r18;
    // 0x800E7550: lw          $a1, -0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, -0X4);
    // 0x800E7554: jal         0x800E6DB4
    // 0x800E7558: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_3;
    // 0x800E7558: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800E755C: b           L_800E75EC
    // 0x800E7560: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
        goto L_800E75EC;
    // 0x800E7560: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
L_800E7564:
    // 0x800E7564: addiu       $t1, $s0, 0xF
    ctx->r9 = ADD32(ctx->r16, 0XF);
    // 0x800E7568: and         $s0, $t1, $s5
    ctx->r16 = ctx->r9 & ctx->r21;
    // 0x800E756C: ldc1        $f0, -0x8($s0)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r16, -0X8);
    // 0x800E7570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E7574: cvt.s.d     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f4.fl = CVT_S_D(ctx->f0.d);
    // 0x800E7578: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800E757C: jal         0x800E6BAC
    // 0x800E7580: nop

    func_800E6BAC(rdram, ctx);
        goto after_4;
    // 0x800E7580: nop

    after_4:
    // 0x800E7584: b           L_800E75EC
    // 0x800E7588: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
        goto L_800E75EC;
    // 0x800E7588: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
L_800E758C:
    // 0x800E758C: addiu       $t2, $s0, 0x7
    ctx->r10 = ADD32(ctx->r16, 0X7);
    // 0x800E7590: and         $s0, $t2, $s2
    ctx->r16 = ctx->r10 & ctx->r18;
    // 0x800E7594: lw          $a1, -0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, -0X4);
    // 0x800E7598: jal         0x800E6F7C
    // 0x800E759C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E6F7C(rdram, ctx);
        goto after_5;
    // 0x800E759C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800E75A0: b           L_800E75EC
    // 0x800E75A4: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
        goto L_800E75EC;
    // 0x800E75A4: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
L_800E75A8:
    // 0x800E75A8: addiu       $t3, $s0, 0x7
    ctx->r11 = ADD32(ctx->r16, 0X7);
    // 0x800E75AC: and         $s0, $t3, $s2
    ctx->r16 = ctx->r11 & ctx->r18;
    // 0x800E75B0: lw          $a1, -0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, -0X4);
    // 0x800E75B4: jal         0x800E6A10
    // 0x800E75B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E6A10(rdram, ctx);
        goto after_6;
    // 0x800E75B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x800E75BC: b           L_800E75EC
    // 0x800E75C0: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
        goto L_800E75EC;
    // 0x800E75C0: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
L_800E75C4:
    // 0x800E75C4: addiu       $t4, $s0, 0x7
    ctx->r12 = ADD32(ctx->r16, 0X7);
    // 0x800E75C8: and         $s0, $t4, $s2
    ctx->r16 = ctx->r12 & ctx->r18;
    // 0x800E75CC: lw          $a1, -0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, -0X4);
    // 0x800E75D0: jal         0x800E6F7C
    // 0x800E75D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E6F7C(rdram, ctx);
        goto after_7;
    // 0x800E75D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x800E75D8: b           L_800E75EC
    // 0x800E75DC: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
        goto L_800E75EC;
    // 0x800E75DC: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
L_800E75E0:
    // 0x800E75E0: jal         0x800E6A58
    // 0x800E75E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E6A58(rdram, ctx);
        goto after_8;
    // 0x800E75E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x800E75E8: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
L_800E75EC:
    // 0x800E75EC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800E75F0: bne         $a1, $zero, L_800E74C4
    if (ctx->r5 != 0) {
        // 0x800E75F4: nop
    
            goto L_800E74C4;
    }
    // 0x800E75F4: nop

L_800E75F8:
    // 0x800E75F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800E75FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E7600: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E7604: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800E7608: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800E760C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800E7610: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800E7614: jr          $ra
    // 0x800E7618: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800E7618: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800E761C: nop

;}
RECOMP_FUNC void _anseq_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082640: syscall     3
    recomp_syscall_handler(rdram, ctx, 0x80082640);
    return;
    // 0x80082644: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808016D0_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808016D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016D8: jal         0x800EA05C
    // 0x808016DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808016DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808016E0: addiu       $at, $zero, 0xEC
    ctx->r1 = ADD32(0, 0XEC);
    // 0x808016E4: beq         $v0, $at, L_80801700
    if (ctx->r2 == ctx->r1) {
        // 0x808016E8: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80801700;
    }
    // 0x808016E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808016EC: addiu       $at, $zero, 0x114
    ctx->r1 = ADD32(0, 0X114);
    // 0x808016F0: beq         $v0, $at, L_80801750
    if (ctx->r2 == ctx->r1) {
        // 0x808016F4: nop
    
            goto L_80801750;
    }
    // 0x808016F4: nop

    // 0x808016F8: b           L_808017C4
    // 0x808016FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808017C4;
    // 0x808016FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801700:
    // 0x80801700: jal         0x800DA298
    // 0x80801704: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80801704: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    after_1:
    // 0x80801708: beql        $v0, $zero, L_808017C4
    if (ctx->r2 == 0) {
        // 0x8080170C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808017C4;
    }
    goto skip_0;
    // 0x8080170C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80801710: jal         0x800DA298
    // 0x80801714: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80801714: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    after_2:
    // 0x80801718: bnel        $v0, $zero, L_808017C4
    if (ctx->r2 != 0) {
        // 0x8080171C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808017C4;
    }
    goto skip_1;
    // 0x8080171C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80801720: jal         0x800DA298
    // 0x80801724: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80801724: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_3:
    // 0x80801728: bnel        $v0, $zero, L_808017C4
    if (ctx->r2 != 0) {
        // 0x8080172C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808017C4;
    }
    goto skip_2;
    // 0x8080172C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80801730: jal         0x8080167C
    // 0x80801734: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8080167C_chchuffy(rdram, ctx);
        goto after_4;
    // 0x80801734: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x80801738: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    // 0x8080173C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801740: jal         0x80088868
    // 0x80801744: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_5;
    // 0x80801744: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_5:
    // 0x80801748: b           L_808017C4
    // 0x8080174C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808017C4;
    // 0x8080174C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801750:
    // 0x80801750: jal         0x800DA298
    // 0x80801754: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80801754: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    after_6:
    // 0x80801758: beq         $v0, $zero, L_80801780
    if (ctx->r2 == 0) {
        // 0x8080175C: nop
    
            goto L_80801780;
    }
    // 0x8080175C: nop

    // 0x80801760: jal         0x8080167C
    // 0x80801764: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8080167C_chchuffy(rdram, ctx);
        goto after_7;
    // 0x80801764: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_7:
    // 0x80801768: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    // 0x8080176C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80801770: jal         0x80088868
    // 0x80801774: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_8;
    // 0x80801774: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    after_8:
    // 0x80801778: b           L_808017C4
    // 0x8080177C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808017C4;
    // 0x8080177C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801780:
    // 0x80801780: jal         0x800DA298
    // 0x80801784: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x80801784: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_9:
    // 0x80801788: beql        $v0, $zero, L_808017C4
    if (ctx->r2 == 0) {
        // 0x8080178C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808017C4;
    }
    goto skip_3;
    // 0x8080178C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80801790: jal         0x800DA298
    // 0x80801794: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80801794: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_10:
    // 0x80801798: beql        $v0, $zero, L_808017C4
    if (ctx->r2 == 0) {
        // 0x8080179C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808017C4;
    }
    goto skip_4;
    // 0x8080179C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x808017A0: jal         0x8080167C
    // 0x808017A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8080167C_chchuffy(rdram, ctx);
        goto after_11;
    // 0x808017A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_11:
    // 0x808017A8: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    // 0x808017AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808017B0: jal         0x80088868
    // 0x808017B4: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_12;
    // 0x808017B4: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_12:
    // 0x808017B8: b           L_808017C4
    // 0x808017BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808017C4;
    // 0x808017BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808017C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808017C4:
    // 0x808017C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808017C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808017CC: jr          $ra
    // 0x808017D0: nop

    return;
    // 0x808017D0: nop

;}
RECOMP_FUNC void func_800F55D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F55D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F55D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F55D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F55DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F55E0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F55E4: jal         0x800965D4
    // 0x800F55E8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800965D4(rdram, ctx);
        goto after_0;
    // 0x800F55E8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F55EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F55F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F55F4: jr          $ra
    // 0x800F55F8: nop

    return;
    // 0x800F55F8: nop

;}
RECOMP_FUNC void chdiggergroundgen_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(860, 0X500) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x500
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(860, 0X500));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x500
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(860, 0X500));
;}
RECOMP_FUNC void func_80809250_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809250: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80809254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80809258: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080925C: jal         0x8008CABC
    // 0x80809260: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80809260: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80809264: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80809268: jal         0x8008B2B4
    // 0x8080926C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_1;
    // 0x8080926C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80809270: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80809274: jal         0x8008B264
    // 0x80809278: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    anctrl_getIndex(rdram, ctx);
        goto after_2;
    // 0x80809278: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x8080927C: jal         0x800D674C
    // 0x80809280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x80809280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80809284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80809288: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8080928C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80809290: jal         0x800E0050
    // 0x80809294: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    func_800E0050(rdram, ctx);
        goto after_4;
    // 0x80809294: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_4:
    // 0x80809298: jal         0x80802484
    // 0x8080929C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802484_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x8080929C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808092A0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808092A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808092A8: jal         0x8009C128
    // 0x808092AC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_6;
    // 0x808092AC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x808092B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808092B4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808092B8: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808092BC: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x808092C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808092C4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x808092C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808092CC: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x808092D0: jal         0x8009C984
    // 0x808092D4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    yaw_get(rdram, ctx);
        goto after_7;
    // 0x808092D4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x808092D8: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808092DC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808092E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808092E4: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x808092E8: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808092EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808092F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808092F4: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x808092F8: jal         0x800A4CA8
    // 0x808092FC: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    func_800A4CA8(rdram, ctx);
        goto after_8;
    // 0x808092FC: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80809300: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80809304: jal         0x800893F8
    // 0x80809308: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _ncba1p_entrypoint_6(rdram, ctx);
        goto after_9;
    // 0x80809308: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_9:
    // 0x8080930C: jal         0x800A4CA8
    // 0x80809310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_10;
    // 0x80809310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80809314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80809318: jal         0x80089400
    // 0x8080931C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _ncba1p_entrypoint_7(rdram, ctx);
        goto after_11;
    // 0x8080931C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_11:
    // 0x80809320: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80809324: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80809328: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8080932C: jr          $ra
    // 0x80809330: nop

    return;
    // 0x80809330: nop

;}
RECOMP_FUNC void func_800B5534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5534: jr          $ra
    // 0x800B5538: sb          $zero, 0x9($a0)
    MEM_B(0X9, ctx->r4) = 0;
    return;
    // 0x800B5538: sb          $zero, 0x9($a0)
    MEM_B(0X9, ctx->r4) = 0;
;}
RECOMP_FUNC void batimer_decrement(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: lw          $t6, 0x13C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X13C);
    // 0x80800044: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80800048: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080004C: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x80800050: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800054: swc1        $f4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f4.u32l;
    // 0x80800058: lw          $t7, 0x13C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X13C);
    // 0x8080005C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80800060: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80800064: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80800068: nop

    // 0x8080006C: bc1fl       L_80800080
    if (!c1cs) {
        // 0x80800070: sw          $v1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r3;
            goto L_80800080;
    }
    goto skip_0;
    // 0x80800070: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    skip_0:
    // 0x80800074: b           L_808000E4
    // 0x80800078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000E4;
    // 0x80800078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080007C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
L_80800080:
    // 0x80800080: jal         0x800D8FF8
    // 0x80800084: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800084: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800088: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080008C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800094: lw          $t9, 0x13C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X13C);
    // 0x80800098: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x8080009C: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x808000A0: jal         0x800F0E00
    // 0x808000A4: sub.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_1;
    // 0x808000A4: sub.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f0.fl;
    after_1:
    // 0x808000A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000AC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x808000B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808000B4: lw          $t1, 0x13C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X13C);
    // 0x808000B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000BC: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x808000C0: swc1        $f0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f0.u32l;
    // 0x808000C4: lw          $t3, 0x13C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X13C);
    // 0x808000C8: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x808000CC: lwc1        $f18, 0x0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X0);
    // 0x808000D0: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x808000D4: nop

    // 0x808000D8: bc1fl       L_808000E8
    if (!c1cs) {
        // 0x808000DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000E8;
    }
    goto skip_1;
    // 0x808000DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808000E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000E4:
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000E8:
    // 0x808000E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void func_8001E830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E830: lui         $v0, 0xCC
    if (tooie_more_memory()) ctx->r2 = S32(0XCC << 16); else ctx->r2 = S32(0X2C << 16);
    // 0x8001E834: jr          $ra
    // 0x8001E838: ori         $v0, $v0, 0x4800
    if (tooie_more_memory()) ctx->r2 = ctx->r2 | 0X4800; else ctx->r2 = ctx->r2 | 0X8800;
    return;
    // 0x8001E838: ori         $v0, $v0, 0x4800
    if (tooie_more_memory()) ctx->r2 = ctx->r2 | 0X4800; else ctx->r2 = ctx->r2 | 0X8800;
    // 0x8001E83C: nop

;}
RECOMP_FUNC void func_80800170_baeggaim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800170: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800174: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800178: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080017C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800180: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x80800184: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800188: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8080018C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800190: lui         $at, 0x4362
    ctx->r1 = S32(0X4362 << 16);
    // 0x80800194: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80800198: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080019C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001A0: lui         $at, 0x4274
    ctx->r1 = S32(0X4274 << 16);
    // 0x808001A4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808001A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001AC: lui         $at, 0x4327
    ctx->r1 = S32(0X4327 << 16);
    // 0x808001B0: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
    // 0x808001B4: bc1f        L_808001C0
    if (!c1cs) {
        // 0x808001B8: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_808001C0;
    }
    // 0x808001B8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x808001BC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_808001C0:
    // 0x808001C0: sub.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x808001C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001C8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x808001CC: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x808001D0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808001D4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808001D8: bc1fl       L_808001E8
    if (!c1cs) {
        // 0x808001DC: lwc1        $f2, 0x4($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
            goto L_808001E8;
    }
    goto skip_0;
    // 0x808001DC: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x808001E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808001E4: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
L_808001E8:
    // 0x808001E8: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x808001EC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808001F0: nop

    // 0x808001F4: bc1fl       L_80800204
    if (!c1cs) {
        // 0x808001F8: sub.s       $f0, $f10, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f2.fl;
            goto L_80800204;
    }
    goto skip_1;
    // 0x808001F8: sub.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f2.fl;
    skip_1:
    // 0x808001FC: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x80800200: sub.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f2.fl;
L_80800204:
    // 0x80800204: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800208: nop

    // 0x8080020C: bc1fl       L_8080021C
    if (!c1cs) {
        // 0x80800210: swc1        $f4, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
            goto L_8080021C;
    }
    goto skip_2;
    // 0x80800210: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    skip_2:
    // 0x80800214: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x80800218: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
L_8080021C:
    // 0x8080021C: jal         0x800F1344
    // 0x80800220: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_800F1344(rdram, ctx);
        goto after_0;
    // 0x80800220: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80800224: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800228: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8080022C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800230: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x80800234: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800238: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8080023C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800240: lui         $a2, 0x4202
    ctx->r6 = S32(0X4202 << 16);
    // 0x80800244: jal         0x800F1344
    // 0x80800248: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F1344(rdram, ctx);
        goto after_1;
    // 0x80800248: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8080024C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800250: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x80800254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800258: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void func_8001B7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B7F4: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x8001B7F8: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8001B7FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001B800: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001B804: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x8001B808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B80C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001B810: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8001B814: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8001B818: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8001B81C: jal         0x8001BCF8
    // 0x8001B820: lw          $a0, -0x40F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X40F0);
    rare_memset(rdram, ctx);
        goto after_0;
    // 0x8001B820: lw          $a0, -0x40F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X40F0);
    after_0:
    // 0x8001B824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B828: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001B82C: jr          $ra
    // 0x8001B830: nop

    return;
    // 0x8001B830: nop

    // 0x8001B834: nop

    // 0x8001B838: nop

    // 0x8001B83C: nop

;}
RECOMP_FUNC void _bsdronebubbled_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083058: syscall     40
    recomp_syscall_handler(rdram, ctx, 0x80083058);
    return;
    // 0x8008305C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800970A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800970A4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800970A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800970AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800970B0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800970B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800970B8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800970BC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800970C0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800970C4: jal         0x800EE7B4
    // 0x800970C8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EE7B4(rdram, ctx);
        goto after_0;
    // 0x800970C8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800970CC: lui         $a3, 0x42
    ctx->r7 = S32(0X42 << 16);
    // 0x800970D0: ori         $a3, $a3, 0x25
    ctx->r7 = ctx->r7 | 0X25;
    // 0x800970D4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800970D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800970DC: jal         0x800C6A7C
    // 0x800970E0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800C6A7C(rdram, ctx);
        goto after_1;
    // 0x800970E0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x800970E4: beq         $v0, $zero, L_800970F4
    if (ctx->r2 == 0) {
        // 0x800970E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800970F4;
    }
    // 0x800970E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800970EC: b           L_800970F8
    // 0x800970F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800970F8;
    // 0x800970F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800970F4:
    // 0x800970F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800970F8:
    // 0x800970F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800970FC: jr          $ra
    // 0x80097100: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80097100: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8001DB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DB90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001DB94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001DB98: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x8001DB9C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8001DBA0: multu       $a1, $s3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DBA4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001DBA8: sll         $t6, $a2, 5
    ctx->r14 = S32(ctx->r6 << 5);
    // 0x8001DBAC: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x8001DBB0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001DBB4: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x8001DBB8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8001DBBC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001DBC0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001DBC4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001DBC8: mflo        $t7
    ctx->r15 = lo;
    // 0x8001DBCC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001DBD0: addiu       $t9, $t8, 0x260
    ctx->r25 = ADD32(ctx->r24, 0X260);
    // 0x8001DBD4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001DBD8: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8001DBDC: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8001DBE0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001DBE4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001DBE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DBEC: addu        $s5, $a0, $t0
    ctx->r21 = ADD32(ctx->r4, ctx->r8);
    // 0x8001DBF0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001DBF4: addiu       $s6, $zero, 0x850
    ctx->r22 = ADD32(0, 0X850);
    // 0x8001DBF8: sll         $t1, $s4, 1
    ctx->r9 = S32(ctx->r20 << 1);
L_8001DBFC:
    // 0x8001DBFC: addu        $s1, $t1, $s5
    ctx->r17 = ADD32(ctx->r9, ctx->r21);
    // 0x8001DC00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DC04: jal         0x8002E6E0
    // 0x8001DC08: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x8001DC08: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x8001DC0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001DC10: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
L_8001DC14:
    // 0x8001DC14: addu        $a0, $t2, $s1
    ctx->r4 = ADD32(ctx->r10, ctx->r17);
    // 0x8001DC18: jal         0x8001D5C4
    // 0x8001DC1C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8001D5C4(rdram, ctx);
        goto after_1;
    // 0x8001DC1C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8001DC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DC24: jal         0x8002E660
    // 0x8001DC28: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x8001DC28: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x8001DC2C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001DC30: bnel        $s0, $s3, L_8001DC14
    if (ctx->r16 != ctx->r19) {
        // 0x8001DC34: sll         $t2, $s0, 1
        ctx->r10 = S32(ctx->r16 << 1);
            goto L_8001DC14;
    }
    goto skip_0;
    // 0x8001DC34: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    skip_0:
    // 0x8001DC38: addiu       $s4, $s4, 0x130
    ctx->r20 = ADD32(ctx->r20, 0X130);
    // 0x8001DC3C: bnel        $s4, $s6, L_8001DBFC
    if (ctx->r20 != ctx->r22) {
        // 0x8001DC40: sll         $t1, $s4, 1
        ctx->r9 = S32(ctx->r20 << 1);
            goto L_8001DBFC;
    }
    goto skip_1;
    // 0x8001DC40: sll         $t1, $s4, 1
    ctx->r9 = S32(ctx->r20 << 1);
    skip_1:
    // 0x8001DC44: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001DC48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DC4C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DC50: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001DC54: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001DC58: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001DC5C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DC60: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001DC64: jr          $ra
    // 0x8001DC68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001DC68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void idwater_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: jr          $ra
    // 0x8080003C: lh          $v0, 0x10($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X10);
    return;
    // 0x8080003C: lh          $v0, 0x10($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X10);
;}
RECOMP_FUNC void func_8080098C_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080098C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800990: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800994: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800998: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080099C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808009A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808009A4: jal         0x80100094
    // 0x808009A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009AC: lbu         $v1, 0x5F($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5F);
    // 0x808009B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009B8: beq         $v1, $zero, L_808009D8
    if (ctx->r3 == 0) {
        // 0x808009BC: nop
    
            goto L_808009D8;
    }
    // 0x808009BC: nop

    // 0x808009C0: beq         $v1, $at, L_80800A00
    if (ctx->r3 == ctx->r1) {
        // 0x808009C4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A00;
    }
    // 0x808009C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808009C8: beq         $v1, $at, L_80800A54
    if (ctx->r3 == ctx->r1) {
        // 0x808009CC: nop
    
            goto L_80800A54;
    }
    // 0x808009CC: nop

    // 0x808009D0: b           L_80800A70
    // 0x808009D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A70;
    // 0x808009D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009D8:
    // 0x808009D8: jal         0x80800438
    // 0x808009DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800438_chdragonbrothers(rdram, ctx);
        goto after_1;
    // 0x808009DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808009E0: jal         0x800F5EF8
    // 0x808009E4: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800F5EF8(rdram, ctx);
        goto after_2;
    // 0x808009E4: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_2:
    // 0x808009E8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808009EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808009F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808009F8: jal         0x80089540
    // 0x808009FC: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    _ncpod_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x808009FC: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_3:
L_80800A00:
    // 0x80800A00: jal         0x800F5EF8
    // 0x80800A04: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800F5EF8(rdram, ctx);
        goto after_4;
    // 0x80800A04: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_4:
    // 0x80800A08: jal         0x80110024
    // 0x80800A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_5;
    // 0x80800A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800A10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A14: jal         0x80089520
    // 0x80800A18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _ncpod_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x80800A18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800A1C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800A20: sb          $t7, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r15;
    // 0x80800A24: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800A28: jal         0x800880A8
    // 0x80800A2C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x80800A2C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_7:
    // 0x80800A30: jal         0x800880B8
    // 0x80800A34: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x80800A34: nop

    after_8:
    // 0x80800A38: jal         0x800F5EF8
    // 0x80800A3C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800F5EF8(rdram, ctx);
        goto after_9;
    // 0x80800A3C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_9:
    // 0x80800A40: jal         0x80110024
    // 0x80800A44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_10;
    // 0x80800A44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x80800A48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A4C: jal         0x80089588
    // 0x80800A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_25(rdram, ctx);
        goto after_11;
    // 0x80800A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
L_80800A54:
    // 0x80800A54: jal         0x800F5EF8
    // 0x80800A58: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800F5EF8(rdram, ctx);
        goto after_12;
    // 0x80800A58: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_12:
    // 0x80800A5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A60: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800A64: jal         0x80089568
    // 0x80800A68: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _ncpod_entrypoint_21(rdram, ctx);
        goto after_13;
    // 0x80800A68: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x80800A6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A70:
    // 0x80800A70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A78: jr          $ra
    // 0x80800A7C: nop

    return;
    // 0x80800A7C: nop

;}
RECOMP_FUNC void _chdoubloon_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087450: syscall     572
    recomp_syscall_handler(rdram, ctx, 0x80087450);
    return;
    // 0x80087454: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808002F0_chcheatopage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F0: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(872, 0X378) << 16);
    // 0x808002F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(872, 0X379) << 16);
    // 0x808002F8: addiu       $v0, $v0, 0x379
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(872, 0X379));
    // 0x808002FC: addiu       $v1, $v1, 0x378
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(872, 0X378));
    // 0x80800300: lw          $a1, 0x50($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X50);
    // 0x80800304: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
L_80800308:
    // 0x80800308: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080030C: bne         $t6, $a1, L_8080031C
    if (ctx->r14 != ctx->r5) {
        // 0x80800310: nop
    
            goto L_8080031C;
    }
    // 0x80800310: nop

    // 0x80800314: jr          $ra
    // 0x80800318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080031C:
    // 0x8080031C: bnel        $v1, $v0, L_80800308
    if (ctx->r3 != ctx->r2) {
        // 0x80800320: lbu         $t6, 0x0($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X0);
            goto L_80800308;
    }
    goto skip_0;
    // 0x80800320: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    skip_0:
    // 0x80800324: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800328: jr          $ra
    // 0x8080032C: nop

    return;
    // 0x8080032C: nop

;}
RECOMP_FUNC void chanim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80106790
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800014: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800018: jal         0x80100094
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800020: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800028: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8080002C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void ncpod_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002BC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x808002C0: jal         0x8001B798
    // 0x808002C4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x808002C4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x808002C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D0: jr          $ra
    // 0x808002D4: nop

    return;
    // 0x808002D4: nop

;}
RECOMP_FUNC void _cheggclockwork_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871C8: syscall     534
    recomp_syscall_handler(rdram, ctx, 0x800871C8);
    return;
    // 0x800871CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D527C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D527C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D5280: addiu       $v0, $v0, -0x4BD0
    ctx->r2 = ADD32(ctx->r2, -0X4BD0);
    // 0x800D5284: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x800D5288: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D528C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800D5290: jr          $ra
    // 0x800D5294: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    return;
    // 0x800D5294: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void bsbtrot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800AA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800AA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800AAC: jal         0x80800538
    // 0x80800AB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80800AB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800AB4: jal         0x808004B4
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800ABC: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x80800AC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80800ACC: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80800AD0: jal         0x80800000
    // 0x80800AD4: addiu       $a3, $zero, 0x29F
    ctx->r7 = ADD32(0, 0X29F);
    func_80800000_bsbtrot(rdram, ctx);
        goto after_2;
    // 0x80800AD4: addiu       $a3, $zero, 0x29F
    ctx->r7 = ADD32(0, 0X29F);
    after_2:
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ADC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800AE0: jal         0x8008CDB8
    // 0x80800AE4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_once(rdram, ctx);
        goto after_3;
    // 0x80800AE4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x80800AE8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800AEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AFC: jal         0x8009FFD8
    // 0x80800B00: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_4;
    // 0x80800B00: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_4:
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B08: jal         0x8009B9B0
    // 0x80800B0C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x80800B0C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800B10: jal         0x8009D874
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_6;
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B20: jal         0x80098140
    // 0x80800B24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_7;
    // 0x80800B24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800B28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B34: jr          $ra
    // 0x80800B38: nop

    return;
    // 0x80800B38: nop

;}
RECOMP_FUNC void func_80800000_suquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sltiu       $at, $a0, 0x7
    ctx->r1 = ctx->r4 < 0X7 ? 1 : 0;
    // 0x80800008: beq         $at, $zero, L_80800060
    if (ctx->r1 == 0) {
        // 0x8080000C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800060;
    }
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800014: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3370, 0XF00) << 16);
    // 0x80800018: addu        $at, $at, $t6
    gpr jr_addend_80800020 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080001C: lw          $t6, 0xF00($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3370, 0XF00));
    // 0x80800020: jr          $t6
    // 0x80800024: nop

    switch (jr_addend_80800020 >> 2) {
        case 0: goto L_80800028; break;
        case 1: goto L_80800028; break;
        case 2: goto L_80800060; break;
        case 3: goto L_80800058; break;
        case 4: goto L_80800058; break;
        case 5: goto L_80800058; break;
        case 6: goto L_80800058; break;
        default: switch_error(__func__, 0x80800020, 0x80800F00);
    }
    // 0x80800024: nop

L_80800028:
    // 0x80800028: jal         0x80800584
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    suquiz_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800030: bne         $v0, $zero, L_8080004C
    if (ctx->r2 != 0) {
        // 0x80800034: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080004C;
    }
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8080003C: lw          $t7, 0x7614($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7614);
    // 0x80800040: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80800044: b           L_80800064
    // 0x80800048: lbu         $v0, 0x31($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X31);
        goto L_80800064;
    // 0x80800048: lbu         $v0, 0x31($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X31);
L_8080004C:
    // 0x8080004C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80800050: b           L_80800064
    // 0x80800054: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800064;
    // 0x80800054: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800058:
    // 0x80800058: b           L_80800064
    // 0x8080005C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800064;
    // 0x8080005C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800060:
    // 0x80800060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800064:
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void func_800EF080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF080: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800EF084: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x800EF088: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800EF08C: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x800EF090: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800EF094: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x800EF098: lh          $t0, 0x2($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X2);
    // 0x800EF09C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800EF0A0: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    // 0x800EF0A4: lh          $t3, 0x4($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X4);
    // 0x800EF0A8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800EF0AC: jr          $ra
    // 0x800EF0B0: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
    return;
    // 0x800EF0B0: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void func_80800E88_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E94: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800E98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E9C: jal         0x80100094
    // 0x80800EA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800EA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800EA4: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    // 0x80800EA8: jal         0x800DA298
    // 0x80800EAC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800EAC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800EB0: bne         $v0, $zero, L_80800F14
    if (ctx->r2 != 0) {
        // 0x80800EB4: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80800F14;
    }
    // 0x80800EB4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800EB8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800EBC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800EC0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800EC4: bnel        $t7, $at, L_80800F18
    if (ctx->r15 != ctx->r1) {
        // 0x80800EC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800F18;
    }
    goto skip_0;
    // 0x80800EC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800ECC: lh          $t8, 0x11E($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X11E);
    // 0x80800ED0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80800EDC: sh          $t9, 0x11E($v1)
    MEM_H(0X11E, ctx->r3) = ctx->r25;
    // 0x80800EE0: lh          $t0, 0x11E($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X11E);
    // 0x80800EE4: bnel        $t0, $at, L_80800EF8
    if (ctx->r8 != ctx->r1) {
        // 0x80800EE8: lhu         $t1, 0x72($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X72);
            goto L_80800EF8;
    }
    goto skip_1;
    // 0x80800EE8: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x80800EEC: jal         0x80109FE8
    // 0x80800EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_2;
    // 0x80800EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800EF4: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
L_80800EF8:
    // 0x80800EF8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80800EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F00: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80800F04: beql        $t2, $at, L_80800F18
    if (ctx->r10 == ctx->r1) {
        // 0x80800F08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800F18;
    }
    goto skip_2;
    // 0x80800F08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800F0C: jal         0x80800F70
    // 0x80800F10: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_3;
    // 0x80800F10: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_3:
L_80800F14:
    // 0x80800F14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F18:
    // 0x80800F18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F20: jr          $ra
    // 0x80800F24: nop

    return;
    // 0x80800F24: nop

;}
RECOMP_FUNC void _chtoothyfish_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D98: syscall     451
    recomp_syscall_handler(rdram, ctx, 0x80086D98);
    return;
    // 0x80086D9C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _susubgame_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2E8: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2E8);
    return;
    // 0x8008A2EC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80808A8C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808A8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80808A90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808A94: jal         0x80807C8C
    // 0x80808A98: nop

    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808A98: nop

    after_0:
    // 0x80808A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808AA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80808AA4: jr          $ra
    // 0x80808AA8: nop

    return;
    // 0x80808AA8: nop

;}
RECOMP_FUNC void glcrc_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800140: addu        $a1, $a0, $a1
    ctx->r5 = ADD32(ctx->r4, ctx->r5);
    // 0x80800144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800148: addiu       $a1, $a1, -0x8
    ctx->r5 = ADD32(ctx->r5, -0X8);
    // 0x8080014C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800150: jal         0x80800000
    // 0x80800154: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80800000_glcrc(rdram, ctx);
        goto after_0;
    // 0x80800154: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800158: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080015C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800160: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800164: jr          $ra
    // 0x80800168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800F5FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5FE0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5FE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5FEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5FF0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5FF4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F5FF8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800F5FFC: jal         0x80091C80
    // 0x800F6000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bakey_setState(rdram, ctx);
        goto after_0;
    // 0x800F6000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800F6004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6008: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F600C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F6010: jr          $ra
    // 0x800F6014: nop

    return;
    // 0x800F6014: nop

;}
RECOMP_FUNC void func_80114D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114D98: beq         $a1, $zero, L_80114DA8
    if (ctx->r5 == 0) {
        // 0x80114D9C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80114DA8;
    }
    // 0x80114D9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80114DA0: bne         $a1, $at, L_80114DD0
    if (ctx->r5 != ctx->r1) {
        // 0x80114DA4: nop
    
            goto L_80114DD0;
    }
    // 0x80114DA4: nop

L_80114DA8:
    // 0x80114DA8: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80114DAC: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x80114DB0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80114DB4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80114DB8: sh          $t6, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r14;
    // 0x80114DBC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80114DC0: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x80114DC4: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80114DC8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80114DCC: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
L_80114DD0:
    // 0x80114DD0: jr          $ra
    // 0x80114DD4: nop

    return;
    // 0x80114DD4: nop

;}
RECOMP_FUNC void func_800EF8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF8BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EF8C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EF8C4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800EF8C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EF8CC: jal         0x800137AC
    // 0x800EF8D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800137AC(rdram, ctx);
        goto after_0;
    // 0x800EF8D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800EF8D4: jal         0x800137C4
    // 0x800EF8D8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800137C4(rdram, ctx);
        goto after_1;
    // 0x800EF8D8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800EF8DC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800EF8E0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800EF8E4: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EF8E8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800EF8EC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800EF8F0: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800EF8F4: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800EF8F8: mul.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800EF8FC: nop

    // 0x800EF900: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800EF904: nop

    // 0x800EF908: mul.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800EF90C: nop

    // 0x800EF910: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF914: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800EF918: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x800EF91C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800EF920: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800EF924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EF928: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EF92C: jr          $ra
    // 0x800EF930: nop

    return;
    // 0x800EF930: nop

;}
RECOMP_FUNC void func_800CBB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBB70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CBB74: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800CBB78: jr          $ra
    // 0x800CBB7C: sb          $a1, -0x5168($at)
    MEM_B(-0X5168, ctx->r1) = ctx->r5;
    return;
    // 0x800CBB7C: sb          $a1, -0x5168($at)
    MEM_B(-0X5168, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_800C0130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0130: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C0134: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C0138: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C013C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C0140: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C0144: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C0148: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C014C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C0150: addiu       $s1, $s1, -0x7748
    ctx->r17 = ADD32(ctx->r17, -0X7748);
    // 0x800C0154: addiu       $s0, $s0, -0x7750
    ctx->r16 = ADD32(ctx->r16, -0X7750);
    // 0x800C0158: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
L_800C015C:
    // 0x800C015C: beql        $a0, $zero, L_800C0170
    if (ctx->r4 == 0) {
        // 0x800C0160: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800C0170;
    }
    goto skip_0;
    // 0x800C0160: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800C0164: jal         0x80087AF0
    // 0x800C0168: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _gczoombox_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800C0168: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800C016C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800C0170:
    // 0x800C0170: bnel        $s0, $s1, L_800C015C
    if (ctx->r16 != ctx->r17) {
        // 0x800C0174: lw          $a0, 0x120($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X120);
            goto L_800C015C;
    }
    goto skip_1;
    // 0x800C0174: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    skip_1:
    // 0x800C0178: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C017C: lw          $a0, -0x7624($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7624);
    // 0x800C0180: beql        $a0, $zero, L_800C0194
    if (ctx->r4 == 0) {
        // 0x800C0184: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C0194;
    }
    goto skip_2;
    // 0x800C0184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800C0188: jal         0x80087AF0
    // 0x800C018C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _gczoombox_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x800C018C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800C0190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C0194:
    // 0x800C0194: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C0198: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C019C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C01A0: jr          $ra
    // 0x800C01A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C01A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C87DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C87DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C87E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C87E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C87E8: jal         0x800EE830
    // 0x800C87EC: addiu       $a1, $a1, -0x54F0
    ctx->r5 = ADD32(ctx->r5, -0X54F0);
    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x800C87EC: addiu       $a1, $a1, -0x54F0
    ctx->r5 = ADD32(ctx->r5, -0X54F0);
    after_0:
    // 0x800C87F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C87F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C87F8: jr          $ra
    // 0x800C87FC: nop

    return;
    // 0x800C87FC: nop

;}
RECOMP_FUNC void func_8080003C_chlavatraindoorswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800048: jal         0x80085808
    // 0x8080004C: addiu       $a1, $zero, 0x1D0
    ctx->r5 = ADD32(0, 0X1D0);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080004C: addiu       $a1, $zero, 0x1D0
    ctx->r5 = ADD32(0, 0X1D0);
    after_0:
    // 0x80800050: jal         0x80085818
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void _capod_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856A8: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856A8);
    return;
    // 0x800856AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gsattract_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C68: syscall     731
    recomp_syscall_handler(rdram, ctx, 0x80088C68);
    return;
    // 0x80088C6C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chsignpost_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1656, 0X2E0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1656, 0X2E0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1656, 0X2E0));
;}
