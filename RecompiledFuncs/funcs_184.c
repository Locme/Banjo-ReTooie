#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800160_gccubesearch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800164: mflo        $t6
    ctx->r14 = lo;
    // 0x80800168: nop

    // 0x8080016C: nop

    // 0x80800170: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800174: mflo        $t7
    ctx->r15 = lo;
    // 0x80800178: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8080017C: nop

    // 0x80800180: multu       $a2, $a2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800184: mflo        $t9
    ctx->r25 = lo;
    // 0x80800188: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void func_808006DC_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808006E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006EC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808006F0: jal         0x800D8FF8
    // 0x808006F4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808006F4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x808006F8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808006FC: jal         0x80013728
    // 0x80800700: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x80800700: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    after_1:
    // 0x80800704: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x80800708: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080070C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800710: jal         0x800F0D50
    // 0x80800714: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_800F0D50(rdram, ctx);
        goto after_2;
    // 0x80800714: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_2:
    // 0x80800718: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8080071C: jal         0x80013728
    // 0x80800720: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    func_80013728(rdram, ctx);
        goto after_3;
    // 0x80800720: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    after_3:
    // 0x80800724: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x80800728: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080072C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800730: jal         0x800F0D50
    // 0x80800734: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_800F0D50(rdram, ctx);
        goto after_4;
    // 0x80800734: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_4:
    // 0x80800738: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080073C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800740: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800744: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800748: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080074C: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800750: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800754: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x80800758: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8080075C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800760: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800764: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80800768: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8080076C: jal         0x800F1FF0
    // 0x80800770: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_5;
    // 0x80800770: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80800774: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800778: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080077C: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800780: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800784: lwc1        $f14, 0x50($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800788: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x8080078C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800790: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800794: jal         0x800F1FF0
    // 0x80800798: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_6;
    // 0x80800798: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x8080079C: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x808007A0: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808007A4: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808007A8: jal         0x800F20BC
    // 0x808007AC: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    func_800F20BC(rdram, ctx);
        goto after_7;
    // 0x808007AC: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_7:
    // 0x808007B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808007BC: jr          $ra
    // 0x808007C0: nop

    return;
    // 0x808007C0: nop

;}
RECOMP_FUNC void func_80095068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095068: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009506C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80095070: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80095074: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80095078: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8009507C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80095080: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80095084: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80095088: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8009508C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80095090: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80095094: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80095098: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009509C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800950A0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_800950A4:
    // 0x800950A4: lw          $t6, 0x78($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X78);
    // 0x800950A8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800950AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800950B0: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800950B4: swc1        $f20, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f20.u32l;
    // 0x800950B8: lw          $t8, 0x78($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X78);
    // 0x800950BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800950C0: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800950C4: jal         0x80095004
    // 0x800950C8: sb          $zero, 0x4($t9)
    MEM_B(0X4, ctx->r25) = 0;
    func_80095004(rdram, ctx);
        goto after_0;
    // 0x800950C8: sb          $zero, 0x4($t9)
    MEM_B(0X4, ctx->r25) = 0;
    after_0:
    // 0x800950CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800950D0: bne         $s0, $s3, L_800950A4
    if (ctx->r16 != ctx->r19) {
        // 0x800950D4: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_800950A4;
    }
    // 0x800950D4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800950D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800950DC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800950E0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800950E4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800950E8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800950EC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800950F0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800950F4: jr          $ra
    // 0x800950F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800950F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chmumbohealspell_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087730: syscall     614
    recomp_syscall_handler(rdram, ctx, 0x80087730);
    return;
    // 0x80087734: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800D50_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D58: jal         0x80082840
    // 0x80800D5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800D5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D64: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80800D68: jal         0x80084C38
    // 0x80800D6C: addiu       $a2, $zero, 0x85
    ctx->r6 = ADD32(0, 0X85);
    _bafly_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80800D6C: addiu       $a2, $zero, 0x85
    ctx->r6 = ADD32(0, 0X85);
    after_1:
    // 0x80800D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D78: jr          $ra
    // 0x80800D7C: nop

    return;
    // 0x80800D7C: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BE4: jal         0x80100094
    // 0x80800BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BF4: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x80800BF8: jr          $ra
    // 0x80800BFC: nop

    return;
    // 0x80800BFC: nop

;}
RECOMP_FUNC void func_80115870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115870: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80115874: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80115878: nop

    // 0x8011587C: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x80115880: nop

    // 0x80115884: bc1fl       L_8011589C
    if (!c1cs) {
        // 0x80115888: lw          $t8, 0x3C($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X3C);
            goto L_8011589C;
    }
    goto skip_0;
    // 0x80115888: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    skip_0:
    // 0x8011588C: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80115890: b           L_801158A4
    // 0x80115894: sb          $zero, 0x10($t6)
    MEM_B(0X10, ctx->r14) = 0;
        goto L_801158A4;
    // 0x80115894: sb          $zero, 0x10($t6)
    MEM_B(0X10, ctx->r14) = 0;
    // 0x80115898: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
L_8011589C:
    // 0x8011589C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801158A0: sb          $t7, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r15;
L_801158A4:
    // 0x801158A4: lw          $t9, 0x3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X3C);
    // 0x801158A8: jr          $ra
    // 0x801158AC: swc1        $f12, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f12.u32l;
    return;
    // 0x801158AC: swc1        $f12, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800308_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800308: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080030C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800314: beq         $a1, $at, L_8080033C
    if (ctx->r5 == ctx->r1) {
        // 0x80800318: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8080033C;
    }
    // 0x80800318: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080031C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800320: beq         $a1, $at, L_808003E0
    if (ctx->r5 == ctx->r1) {
        // 0x80800324: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003E0;
    }
    // 0x80800324: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800328: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x8080032C: beql        $a1, $at, L_80800388
    if (ctx->r5 == ctx->r1) {
        // 0x80800330: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_80800388;
    }
    goto skip_0;
    // 0x80800330: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    skip_0:
    // 0x80800334: b           L_8080044C
    // 0x80800338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080044C;
    // 0x80800338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080033C:
    // 0x8080033C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800340: bne         $a2, $at, L_8080037C
    if (ctx->r6 != ctx->r1) {
        // 0x80800344: nop
    
            goto L_8080037C;
    }
    // 0x80800344: nop

    // 0x80800348: jal         0x80085710
    // 0x8080034C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x8080034C: nop

    after_0:
    // 0x80800350: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800354: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800358: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8080035C: addiu       $a3, $zero, 0x2910
    ctx->r7 = ADD32(0, 0X2910);
    // 0x80800360: jal         0x80085708
    // 0x80800364: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800364: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x80800368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080036C: jal         0x80108B04
    // 0x80800370: addiu       $a1, $zero, 0x210
    ctx->r5 = ADD32(0, 0X210);
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x80800370: addiu       $a1, $zero, 0x210
    ctx->r5 = ADD32(0, 0X210);
    after_2:
    // 0x80800374: b           L_8080044C
    // 0x80800378: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080044C;
    // 0x80800378: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8080037C:
    // 0x8080037C: b           L_8080044C
    // 0x80800380: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080044C;
    // 0x80800380: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800384: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
L_80800388:
    // 0x80800388: bne         $a2, $at, L_808003D8
    if (ctx->r6 != ctx->r1) {
        // 0x8080038C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003D8;
    }
    // 0x8080038C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800390: jal         0x80102424
    // 0x80800394: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800394: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800398: lui         $a1, 0x3E5D
    ctx->r5 = S32(0X3E5D << 16);
    // 0x8080039C: ori         $a1, $a1, 0x1746
    ctx->r5 = ctx->r5 | 0X1746;
    // 0x808003A0: jal         0x80101EE4
    // 0x808003A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80101EE4(rdram, ctx);
        goto after_4;
    // 0x808003A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808003A8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808003AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808003B4: lbu         $t8, 0x79($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X79);
    // 0x808003B8: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    // 0x808003BC: andi        $t9, $t8, 0xFF0F
    ctx->r25 = ctx->r24 & 0XFF0F;
    // 0x808003C0: sb          $t9, 0x79($t7)
    MEM_B(0X79, ctx->r15) = ctx->r25;
    // 0x808003C4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808003C8: jal         0x80085708
    // 0x808003CC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x808003CC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_5:
    // 0x808003D0: b           L_8080044C
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080044C;
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003D8:
    // 0x808003D8: b           L_8080044C
    // 0x808003DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080044C;
    // 0x808003DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003E0:
    // 0x808003E0: jal         0x80100094
    // 0x808003E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x808003E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x808003E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808003EC: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x808003F0: addiu       $a0, $zero, 0x210
    ctx->r4 = ADD32(0, 0X210);
    // 0x808003F4: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x808003F8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003FC: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80800400: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800404: jal         0x80108528
    // 0x80800408: nop

    func_80108528(rdram, ctx);
        goto after_7;
    // 0x80800408: nop

    after_7:
    // 0x8080040C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80800410: lhu         $t8, 0x76($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X76);
    // 0x80800414: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800418: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x8080041C: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80800420: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80800424: sll         $t6, $t4, 7
    ctx->r14 = S32(ctx->r12 << 7);
    // 0x80800428: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8080042C: sh          $t7, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r15;
    // 0x80800430: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800434: jal         0x800862D8
    // 0x80800438: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800438: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x8080043C: b           L_8080044C
    // 0x80800440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080044C;
    // 0x80800440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800444: b           L_8080044C
    // 0x80800448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080044C;
    // 0x80800448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080044C:
    // 0x8080044C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800450: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800454: jr          $ra
    // 0x80800458: nop

    return;
    // 0x80800458: nop

;}
RECOMP_FUNC void func_80800228_charea51gate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080022C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800230: jal         0x80101080
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800238: jal         0x80106790
    // 0x8080023C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x8080023C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800244: jal         0x800866B8
    // 0x80800248: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800248: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_2:
    // 0x8080024C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800250: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(980, 0X2D8) << 16);
    // 0x80800254: addiu       $a2, $a2, 0x2D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(980, 0X2D8));
    // 0x80800258: jal         0x80089D18
    // 0x8080025C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080025C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x80800260: jal         0x800FFAB0
    // 0x80800264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800268: jal         0x800DA544
    // 0x8080026C: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x8080026C: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_5:
    // 0x80800270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800278: jr          $ra
    // 0x8080027C: nop

    return;
    // 0x8080027C: nop

;}
RECOMP_FUNC void chhoney_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F48: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1668, 0X1048) << 16);
    // 0x80800F4C: jr          $ra
    // 0x80800F50: addiu       $v0, $v0, 0x1048
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1668, 0X1048));
    return;
    // 0x80800F50: addiu       $v0, $v0, 0x1048
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1668, 0X1048));
;}
RECOMP_FUNC void func_808012AC_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808012B8: jal         0x80100094
    // 0x808012BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808012BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808012C0: lh          $v1, 0x18($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X18);
    // 0x808012C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808012C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808012CC: beq         $v1, $zero, L_808012EC
    if (ctx->r3 == 0) {
        // 0x808012D0: nop
    
            goto L_808012EC;
    }
    // 0x808012D0: nop

    // 0x808012D4: beq         $v1, $at, L_808012FC
    if (ctx->r3 == ctx->r1) {
        // 0x808012D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808012FC;
    }
    // 0x808012D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808012DC: beq         $v1, $at, L_8080130C
    if (ctx->r3 == ctx->r1) {
        // 0x808012E0: nop
    
            goto L_8080130C;
    }
    // 0x808012E0: nop

    // 0x808012E4: b           L_80801318
    // 0x808012E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801318;
    // 0x808012E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808012EC:
    // 0x808012EC: jal         0x8080142C
    // 0x808012F0: nop

    func_8080142C_chaliendad(rdram, ctx);
        goto after_1;
    // 0x808012F0: nop

    after_1:
    // 0x808012F4: b           L_80801318
    // 0x808012F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801318;
    // 0x808012F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808012FC:
    // 0x808012FC: jal         0x8080152C
    // 0x80801300: nop

    func_8080152C_chaliendad(rdram, ctx);
        goto after_2;
    // 0x80801300: nop

    after_2:
    // 0x80801304: b           L_80801318
    // 0x80801308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801318;
    // 0x80801308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080130C:
    // 0x8080130C: jal         0x80801868
    // 0x80801310: nop

    func_80801868_chaliendad(rdram, ctx);
        goto after_3;
    // 0x80801310: nop

    after_3:
    // 0x80801314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801318:
    // 0x80801318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080131C: jr          $ra
    // 0x80801320: nop

    return;
    // 0x80801320: nop

;}
RECOMP_FUNC void func_8080025C_bskazmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800268: jal         0x80091A58
    // 0x8080026C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x8080026C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80800270: beq         $v0, $zero, L_80800280
    if (ctx->r2 == 0) {
        // 0x80800274: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800280;
    }
    // 0x80800274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800278: jal         0x80085008
    // 0x8080027C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bashoes_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080027C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
L_80800280:
    // 0x80800280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800288: jr          $ra
    // 0x8080028C: nop

    return;
    // 0x8080028C: nop

;}
RECOMP_FUNC void func_80800834_basub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800834: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800838: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080083C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800840: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800844: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800848: jal         0x8009C128
    // 0x8080084C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8080084C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800850: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(616, 0XC24) << 16);
    // 0x80800854: addiu       $a3, $a3, 0xC24
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(616, 0XC24));
    // 0x80800858: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8080085C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800860: jal         0x8010D930
    // 0x80800864: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_8010D930(rdram, ctx);
        goto after_1;
    // 0x80800864: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80800868: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080086C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800870: addiu       $a0, $a0, 0x51B8
    ctx->r4 = ADD32(ctx->r4, 0X51B8);
    // 0x80800874: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800878: jal         0x80086D38
    // 0x8080087C: lw          $a1, 0x184($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X184);
    _chbaddiesetup_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080087C: lw          $a1, 0x184($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X184);
    after_2:
    // 0x80800880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800884: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800888: jr          $ra
    // 0x8080088C: nop

    return;
    // 0x8080088C: nop

;}
RECOMP_FUNC void func_8080000C_chjiggybeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800010: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800014: jr          $ra
    // 0x80800018: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80800018: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80802C40_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C48: jal         0x800F54E4
    // 0x80802C4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80802C4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802C50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802C54: jal         0x800F64A4
    // 0x80802C58: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x80802C58: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_1:
    // 0x80802C5C: beq         $v0, $zero, L_80802CA4
    if (ctx->r2 == 0) {
        // 0x80802C60: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80802CA4;
    }
    // 0x80802C60: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80802C64: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80802C68: lui         $a2, 0x44A2
    ctx->r6 = S32(0X44A2 << 16);
    // 0x80802C6C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80802C70: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80802C74: jal         0x800EFA4C
    // 0x80802C78: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80802C78: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    after_2:
    // 0x80802C7C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80802C80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802C84: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80802C88: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80802C8C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80802C90: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80802C94: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80802C98: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80802C9C: jal         0x80089F18
    // 0x80802CA0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80802CA0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_3:
L_80802CA4:
    // 0x80802CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802CA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802CAC: jr          $ra
    // 0x80802CB0: nop

    return;
    // 0x80802CB0: nop

;}
RECOMP_FUNC void subaddieskeleton_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080011C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800120: jal         0x800DBEFC
    // 0x80800124: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_0;
    // 0x80800124: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_0:
    // 0x80800128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080012C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800130: jr          $ra
    // 0x80800134: nop

    return;
    // 0x80800134: nop

;}
RECOMP_FUNC void func_80801034_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801034: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801038: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080103C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801040: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801048: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080104C: jal         0x8009D3A8
    // 0x80801050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x80801050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801054: jal         0x80800000
    // 0x80801058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsvan(rdram, ctx);
        goto after_1;
    // 0x80801058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080105C: jal         0x8080032C
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080032C_bsvan(rdram, ctx);
        goto after_2;
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801064: jal         0x8009EF10
    // 0x80801068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_3;
    // 0x80801068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080106C: bne         $v0, $zero, L_80801078
    if (ctx->r2 != 0) {
        // 0x80801070: nop
    
            goto L_80801078;
    }
    // 0x80801070: nop

    // 0x80801074: addiu       $s1, $zero, 0x11A
    ctx->r17 = ADD32(0, 0X11A);
L_80801078:
    // 0x80801078: jal         0x8008E148
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_4;
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801080: beq         $v0, $zero, L_80801094
    if (ctx->r2 == 0) {
        // 0x80801084: nop
    
            goto L_80801094;
    }
    // 0x80801084: nop

    // 0x80801088: jal         0x800848B0
    // 0x8080108C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_5;
    // 0x8080108C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801090: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80801094:
    // 0x80801094: jal         0x8008DD04
    // 0x80801098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_6;
    // 0x80801098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080109C: beq         $v0, $zero, L_808010A8
    if (ctx->r2 == 0) {
        // 0x808010A0: nop
    
            goto L_808010A8;
    }
    // 0x808010A0: nop

    // 0x808010A4: addiu       $s1, $zero, 0x114
    ctx->r17 = ADD32(0, 0X114);
L_808010A8:
    // 0x808010A8: jal         0x808000BC
    // 0x808010AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000BC_bsvan(rdram, ctx);
        goto after_7;
    // 0x808010AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808010B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B4: jal         0x80091A58
    // 0x808010B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_8;
    // 0x808010B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x808010BC: beq         $v0, $zero, L_808010C8
    if (ctx->r2 == 0) {
        // 0x808010C0: nop
    
            goto L_808010C8;
    }
    // 0x808010C0: nop

    // 0x808010C4: addiu       $s1, $zero, 0x115
    ctx->r17 = ADD32(0, 0X115);
L_808010C8:
    // 0x808010C8: jal         0x8008E35C
    // 0x808010CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_9;
    // 0x808010CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808010D0: beq         $v0, $zero, L_808010DC
    if (ctx->r2 == 0) {
        // 0x808010D4: nop
    
            goto L_808010DC;
    }
    // 0x808010D4: nop

    // 0x808010D8: addiu       $s1, $zero, 0x11B
    ctx->r17 = ADD32(0, 0X11B);
L_808010DC:
    // 0x808010DC: jal         0x808003BC
    // 0x808010E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsvan_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808010E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808010E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010E8: jal         0x8009E5C8
    // 0x808010EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x808010EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
    // 0x808010F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808010F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808010F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808010FC: jr          $ra
    // 0x80801100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void subaddiedraw25d_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800140: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800144: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800148: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080014C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800150: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800154: jal         0x80103AE4
    // 0x80800158: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80103AE4(rdram, ctx);
        goto after_0;
    // 0x80800158: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080015C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800160: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800164: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800168: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8080016C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800170: lhu         $t6, 0x78($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X78);
    // 0x80800174: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80800178: beq         $t7, $zero, L_80800198
    if (ctx->r15 == 0) {
        // 0x8080017C: nop
    
            goto L_80800198;
    }
    // 0x8080017C: nop

    // 0x80800180: jal         0x800E257C
    // 0x80800184: lbu         $a0, 0x9B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9B);
    func_800E257C(rdram, ctx);
        goto after_1;
    // 0x80800184: lbu         $a0, 0x9B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9B);
    after_1:
    // 0x80800188: jal         0x800E2588
    // 0x8080018C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_2;
    // 0x8080018C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800190: b           L_808001C8
    // 0x80800194: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
        goto L_808001C8;
    // 0x80800194: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
L_80800198:
    // 0x80800198: jal         0x800AF5A8
    // 0x8080019C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800AF5A8(rdram, ctx);
        goto after_3;
    // 0x8080019C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x808001A0: andi        $t8, $v0, 0xB00
    ctx->r24 = ctx->r2 & 0XB00;
    // 0x808001A4: beq         $t8, $zero, L_808001BC
    if (ctx->r24 == 0) {
        // 0x808001A8: nop
    
            goto L_808001BC;
    }
    // 0x808001A8: nop

    // 0x808001AC: jal         0x800E2588
    // 0x808001B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_4;
    // 0x808001B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x808001B4: b           L_808001C8
    // 0x808001B8: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
        goto L_808001C8;
    // 0x808001B8: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
L_808001BC:
    // 0x808001BC: jal         0x800E2588
    // 0x808001C0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800E2588(rdram, ctx);
        goto after_5;
    // 0x808001C0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_5:
    // 0x808001C4: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
L_808001C8:
    // 0x808001C8: sll         $t1, $t9, 30
    ctx->r9 = S32(ctx->r25 << 30);
    // 0x808001CC: bgez        $t1, L_808001E4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808001D0: nop
    
            goto L_808001E4;
    }
    // 0x808001D0: nop

    // 0x808001D4: lbu         $a0, 0x98($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X98);
    // 0x808001D8: lbu         $a1, 0x99($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X99);
    // 0x808001DC: jal         0x800E24F8
    // 0x808001E0: lbu         $a2, 0x9A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9A);
    func_800E24F8(rdram, ctx);
        goto after_6;
    // 0x808001E0: lbu         $a2, 0x9A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9A);
    after_6:
L_808001E4:
    // 0x808001E4: jal         0x8080024C
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    subaddiedraw25d_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001EC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x808001F0: addiu       $a0, $a0, -0x6400
    ctx->r4 = ADD32(ctx->r4, -0X6400);
    // 0x808001F4: jal         0x800E24E4
    // 0x808001F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E24E4(rdram, ctx);
        goto after_8;
    // 0x808001F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x808001FC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80800200: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x80800204: addiu       $t7, $sp, 0x3C
    ctx->r15 = ADD32(ctx->r29, 0X3C);
    // 0x80800208: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8080020C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800210: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800214: lhu         $a2, 0xA($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0XA);
    // 0x80800218: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8080021C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800220: srl         $t3, $a2, 11
    ctx->r11 = S32(U32(ctx->r6) >> 11);
    // 0x80800224: sll         $t4, $a3, 26
    ctx->r12 = S32(ctx->r7 << 26);
    // 0x80800228: srl         $a3, $t4, 31
    ctx->r7 = S32(U32(ctx->r12) >> 31);
    // 0x8080022C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80800230: jal         0x800E2AA4
    // 0x80800234: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800E2AA4(rdram, ctx);
        goto after_9;
    // 0x80800234: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_9:
    // 0x80800238: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080023C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800240: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
RECOMP_FUNC void func_808000D4_chhagstraindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000E4: bne         $a1, $at, L_80800124
    if (ctx->r5 != ctx->r1) {
        // 0x808000E8: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800124;
    }
    // 0x808000E8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808000EC: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x808000F0: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808000F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000F8: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808000FC: bne         $t7, $at, L_8080010C
    if (ctx->r15 != ctx->r1) {
        // 0x80800100: addiu       $v0, $zero, 0x950
        ctx->r2 = ADD32(0, 0X950);
            goto L_8080010C;
    }
    // 0x80800100: addiu       $v0, $zero, 0x950
    ctx->r2 = ADD32(0, 0X950);
    // 0x80800104: b           L_8080010C
    // 0x80800108: addiu       $v0, $zero, 0x94F
    ctx->r2 = ADD32(0, 0X94F);
        goto L_8080010C;
    // 0x80800108: addiu       $v0, $zero, 0x94F
    ctx->r2 = ADD32(0, 0X94F);
L_8080010C:
    // 0x8080010C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80800110: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800114: jal         0x80103140
    // 0x80800118: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80800118: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080011C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800120: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800124:
    // 0x80800124: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800128: jal         0x80086248
    // 0x8080012C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080012C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_80800404_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800404: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800408: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8080040C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800410: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800414: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800418: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8080041C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80800420: jal         0x800B53A4
    // 0x80800424: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800424: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800428: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080042C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800430: jal         0x80100094
    // 0x80800434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800438: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8080043C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800440: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800444: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x80800448: jal         0x800DBEFC
    // 0x8080044C: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x8080044C: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_2:
    // 0x80800450: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1748, 0X2150) << 16);
    // 0x80800454: addiu       $t7, $t7, 0x2150
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1748, 0X2150));
    // 0x80800458: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800468: jal         0x800BABB8
    // 0x8080046C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x8080046C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80800470: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800474: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800478: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8080047C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800480: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800484: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800488: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8080048C: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80800490: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800494: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80800498: lwc1        $f12, 0x38($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X38);
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A0: sub.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x808004A4: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x808004A8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808004AC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808004B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004B4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808004B8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808004BC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808004C0: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x808004C4: add.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x808004C8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808004CC: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x808004D0: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x808004D4: sub.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x808004D8: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x808004DC: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x808004E0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808004E4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808004E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004EC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x808004F0: add.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x808004F4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x808004F8: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x808004FC: sll         $t5, $a3, 16
    ctx->r13 = S32(ctx->r7 << 16);
    // 0x80800500: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80800504: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80800508: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080050C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800510: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800514: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80800518: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8080051C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800520: jal         0x800BA994
    // 0x80800524: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    func_800BA994(rdram, ctx);
        goto after_4;
    // 0x80800524: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_4:
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: jal         0x800BA22C
    // 0x80800530: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x80800530: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800534: jal         0x800B53A4
    // 0x80800538: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800B53A4(rdram, ctx);
        goto after_6;
    // 0x80800538: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x8080053C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80800540: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800544: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80800548: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8080054C: jal         0x800DBEFC
    // 0x80800550: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_7;
    // 0x80800550: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    after_7:
    // 0x80800554: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(1748, 0X2150) << 16);
    // 0x80800558: addiu       $t4, $t4, 0x2150
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(1748, 0X2150));
    // 0x8080055C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800564: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800568: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080056C: jal         0x800BABB8
    // 0x80800570: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_8;
    // 0x80800570: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x80800574: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80800578: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8080057C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800580: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800584: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80800588: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8080058C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800590: sub.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x80800594: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800598: lwc1        $f12, 0x38($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X38);
    // 0x8080059C: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A4: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x808005A8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808005AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808005B0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808005B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808005B8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808005BC: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x808005C0: add.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x808005C4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808005C8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x808005CC: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x808005D0: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x808005D4: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x808005D8: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x808005DC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808005E0: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808005E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005E8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808005EC: add.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x808005F0: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x808005F4: mul.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x808005F8: sll         $t2, $a3, 16
    ctx->r10 = S32(ctx->r7 << 16);
    // 0x808005FC: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80800600: sra         $a3, $t2, 16
    ctx->r7 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80800604: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800608: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080060C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800610: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80800614: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80800618: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080061C: jal         0x800BA994
    // 0x80800620: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_800BA994(rdram, ctx);
        goto after_9;
    // 0x80800620: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_9:
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800628: jal         0x800BA22C
    // 0x8080062C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800BA22C(rdram, ctx);
        goto after_10;
    // 0x8080062C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800630: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800634: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80800638: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8080063C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80800640: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800644: jr          $ra
    // 0x80800648: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800648: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _basetup_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FB8: syscall     146
    recomp_syscall_handler(rdram, ctx, 0x80084FB8);
    return;
    // 0x80084FBC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800040_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: jal         0x800DC0C0
    // 0x8080004C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x8080004C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800050: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800060: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800064: addiu       $a1, $zero, 0x510
    ctx->r5 = ADD32(0, 0X510);
    // 0x80800068: bc1f        L_80800080
    if (!c1cs) {
        // 0x8080006C: nop
    
            goto L_80800080;
    }
    // 0x8080006C: nop

    // 0x80800070: jal         0x8009DE38
    // 0x80800074: addiu       $a1, $zero, 0x50F
    ctx->r5 = ADD32(0, 0X50F);
    func_8009DE38(rdram, ctx);
        goto after_1;
    // 0x80800074: addiu       $a1, $zero, 0x50F
    ctx->r5 = ADD32(0, 0X50F);
    after_1:
    // 0x80800078: b           L_8080008C
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080008C;
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800080:
    // 0x80800080: jal         0x8009DE38
    // 0x80800084: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_2;
    // 0x80800084: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080008C:
    // 0x8080008C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void _bsbswim_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B90: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082B90);
    return;
    // 0x80082B94: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800D7DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7DEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7DF0: jal         0x80105494
    // 0x800D7DF4: nop

    func_80105494(rdram, ctx);
        goto after_0;
    // 0x800D7DF4: nop

    after_0:
    // 0x800D7DF8: lh          $t7, 0x26($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X26);
    // 0x800D7DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7E04: bgez        $t7, L_800D7E14
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800D7E08: addiu       $a0, $zero, 0x100
        ctx->r4 = ADD32(0, 0X100);
            goto L_800D7E14;
    }
    // 0x800D7E08: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x800D7E0C: b           L_800D7E14
    // 0x800D7E10: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
        goto L_800D7E14;
    // 0x800D7E10: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
L_800D7E14:
    // 0x800D7E14: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x800D7E18: addiu       $v1, $zero, 0x200
    ctx->r3 = ADD32(0, 0X200);
    // 0x800D7E1C: sll         $t0, $t8, 17
    ctx->r8 = S32(ctx->r24 << 17);
    // 0x800D7E20: bgez        $t0, L_800D7E30
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800D7E24: nop
    
            goto L_800D7E30;
    }
    // 0x800D7E24: nop

    // 0x800D7E28: b           L_800D7E30
    // 0x800D7E2C: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
        goto L_800D7E30;
    // 0x800D7E2C: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
L_800D7E30:
    // 0x800D7E30: jr          $ra
    // 0x800D7E34: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    return;
    // 0x800D7E34: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void func_800B5C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5C7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B5C80: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B5C84: addiu       $a1, $a1, -0x7E80
    ctx->r5 = ADD32(ctx->r5, -0X7E80);
    // 0x800B5C88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B5C8C: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800B5C90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B5C94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B5C98: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x800B5C9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B5CA0: blez        $a0, L_800B5DB0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B5CA4: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800B5DB0;
    }
    // 0x800B5CA4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800B5CA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B5CAC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_800B5CB0:
    // 0x800B5CB0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B5CB4: addiu       $t7, $t7, -0x7E50
    ctx->r15 = ADD32(ctx->r15, -0X7E50);
    // 0x800B5CB8: addu        $v0, $t0, $t7
    ctx->r2 = ADD32(ctx->r8, ctx->r15);
    // 0x800B5CBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B5CC0: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
L_800B5CC4:
    // 0x800B5CC4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B5CC8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B5CCC: div         $zero, $v1, $t8
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r24)));
    // 0x800B5CD0: mflo        $t9
    ctx->r25 = lo;
    // 0x800B5CD4: sb          $t9, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r25;
    // 0x800B5CD8: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x800B5CDC: bne         $t8, $zero, L_800B5CE8
    if (ctx->r24 != 0) {
        // 0x800B5CE0: nop
    
            goto L_800B5CE8;
    }
    // 0x800B5CE0: nop

    // 0x800B5CE4: break       7
    do_break(2148228324);
L_800B5CE8:
    // 0x800B5CE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B5CEC: bne         $t8, $at, L_800B5D00
    if (ctx->r24 != ctx->r1) {
        // 0x800B5CF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B5D00;
    }
    // 0x800B5CF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B5CF4: bne         $v1, $at, L_800B5D00
    if (ctx->r3 != ctx->r1) {
        // 0x800B5CF8: nop
    
            goto L_800B5D00;
    }
    // 0x800B5CF8: nop

    // 0x800B5CFC: break       6
    do_break(2148228348);
L_800B5D00:
    // 0x800B5D00: div         $zero, $v1, $t1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r9)));
    // 0x800B5D04: mflo        $t2
    ctx->r10 = lo;
    // 0x800B5D08: sb          $t2, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r10;
    // 0x800B5D0C: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x800B5D10: bne         $t1, $zero, L_800B5D1C
    if (ctx->r9 != 0) {
        // 0x800B5D14: nop
    
            goto L_800B5D1C;
    }
    // 0x800B5D14: nop

    // 0x800B5D18: break       7
    do_break(2148228376);
L_800B5D1C:
    // 0x800B5D1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B5D20: bne         $t1, $at, L_800B5D34
    if (ctx->r9 != ctx->r1) {
        // 0x800B5D24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B5D34;
    }
    // 0x800B5D24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B5D28: bne         $v1, $at, L_800B5D34
    if (ctx->r3 != ctx->r1) {
        // 0x800B5D2C: nop
    
            goto L_800B5D34;
    }
    // 0x800B5D2C: nop

    // 0x800B5D30: break       6
    do_break(2148228400);
L_800B5D34:
    // 0x800B5D34: div         $zero, $v1, $t3
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r11)));
    // 0x800B5D38: mflo        $t4
    ctx->r12 = lo;
    // 0x800B5D3C: sb          $t4, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r12;
    // 0x800B5D40: lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X8);
    // 0x800B5D44: bne         $t3, $zero, L_800B5D50
    if (ctx->r11 != 0) {
        // 0x800B5D48: nop
    
            goto L_800B5D50;
    }
    // 0x800B5D48: nop

    // 0x800B5D4C: break       7
    do_break(2148228428);
L_800B5D50:
    // 0x800B5D50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B5D54: bne         $t3, $at, L_800B5D68
    if (ctx->r11 != ctx->r1) {
        // 0x800B5D58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B5D68;
    }
    // 0x800B5D58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B5D5C: bne         $v1, $at, L_800B5D68
    if (ctx->r3 != ctx->r1) {
        // 0x800B5D60: nop
    
            goto L_800B5D68;
    }
    // 0x800B5D60: nop

    // 0x800B5D64: break       6
    do_break(2148228452);
L_800B5D68:
    // 0x800B5D68: div         $zero, $v1, $t5
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r13)));
    // 0x800B5D6C: mflo        $t6
    ctx->r14 = lo;
    // 0x800B5D70: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
    // 0x800B5D74: bne         $t5, $zero, L_800B5D80
    if (ctx->r13 != 0) {
        // 0x800B5D78: nop
    
            goto L_800B5D80;
    }
    // 0x800B5D78: nop

    // 0x800B5D7C: break       7
    do_break(2148228476);
L_800B5D80:
    // 0x800B5D80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B5D84: bne         $t5, $at, L_800B5D98
    if (ctx->r13 != ctx->r1) {
        // 0x800B5D88: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B5D98;
    }
    // 0x800B5D88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B5D8C: bne         $v1, $at, L_800B5D98
    if (ctx->r3 != ctx->r1) {
        // 0x800B5D90: nop
    
            goto L_800B5D98;
    }
    // 0x800B5D90: nop

    // 0x800B5D94: break       6
    do_break(2148228500);
L_800B5D98:
    // 0x800B5D98: bnel        $a0, $a2, L_800B5CC4
    if (ctx->r4 != ctx->r6) {
        // 0x800B5D9C: lw          $t8, 0x8($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X8);
            goto L_800B5CC4;
    }
    goto skip_0;
    // 0x800B5D9C: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    skip_0:
    // 0x800B5DA0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B5DA4: addiu       $v1, $v1, 0xFF
    ctx->r3 = ADD32(ctx->r3, 0XFF);
    // 0x800B5DA8: bne         $a3, $s0, L_800B5CB0
    if (ctx->r7 != ctx->r16) {
        // 0x800B5DAC: addiu       $t0, $t0, 0x20
        ctx->r8 = ADD32(ctx->r8, 0X20);
            goto L_800B5CB0;
    }
    // 0x800B5DAC: addiu       $t0, $t0, 0x20
    ctx->r8 = ADD32(ctx->r8, 0X20);
L_800B5DB0:
    // 0x800B5DB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B5DB4: addiu       $a0, $a0, -0x7E50
    ctx->r4 = ADD32(ctx->r4, -0X7E50);
    // 0x800B5DB8: jal         0x8002E660
    // 0x800B5DBC: sll         $a1, $s0, 5
    ctx->r5 = S32(ctx->r16 << 5);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x800B5DBC: sll         $a1, $s0, 5
    ctx->r5 = S32(ctx->r16 << 5);
    after_0:
    // 0x800B5DC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5DC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B5DC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B5DCC: jr          $ra
    // 0x800B5DD0: nop

    return;
    // 0x800B5DD0: nop

;}
RECOMP_FUNC void func_8009216C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009216C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80092170: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80092174: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80092178: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009217C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80092180: jal         0x800920F0
    // 0x80092184: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800920F0(rdram, ctx);
        goto after_0;
    // 0x80092184: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80092188: jal         0x8009C53C
    // 0x8009218C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_get(rdram, ctx);
        goto after_1;
    // 0x8009218C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80092190: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x80092194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092198: jal         0x8009BFCC
    // 0x8009219C: swc1        $f0, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f0.u32l;
    func_8009BFCC(rdram, ctx);
        goto after_2;
    // 0x8009219C: swc1        $f0, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f0.u32l;
    after_2:
    // 0x800921A0: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x800921A4: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x800921A8: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x800921AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800921B0: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x800921B4: lw          $a2, 0x28($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X28);
    // 0x800921B8: jal         0x800EFA4C
    // 0x800921BC: lw          $a3, 0x24($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X24);
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x800921BC: lw          $a3, 0x24($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X24);
    after_3:
    // 0x800921C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800921C4: jal         0x8009C128
    // 0x800921C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_4;
    // 0x800921C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x800921CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800921D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800921D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800921D8: jr          $ra
    // 0x800921DC: nop

    return;
    // 0x800921DC: nop

;}
RECOMP_FUNC void func_808002BC_suexpressmorph(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808002C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808002C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808002CC: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x808002D0: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x808002D4: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(3170, 0X1320) << 16);
    // 0x808002D8: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808002DC: addiu       $t2, $t2, 0x1320
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(3170, 0X1320));
    // 0x808002E0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808002E4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808002E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808002EC: mflo        $t7
    ctx->r15 = lo;
    // 0x808002F0: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x808002F4: lbu         $t9, 0x7($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X7);
    // 0x808002F8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x808002FC: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80800300: addu        $a3, $t4, $a1
    ctx->r7 = ADD32(ctx->r12, ctx->r5);
    // 0x80800304: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80800308: jal         0x800D52F4
    // 0x8080030C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_800D52F4(rdram, ctx);
        goto after_0;
    // 0x8080030C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800310: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x80800314: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800318: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8080031C: bnel        $v0, $t5, L_80800524
    if (ctx->r2 != ctx->r13) {
        // 0x80800320: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800524;
    }
    goto skip_0;
    // 0x80800320: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800324: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80800328: jal         0x800D52A4
    // 0x8080032C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_800D52A4(rdram, ctx);
        goto after_1;
    // 0x8080032C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_1:
    // 0x80800330: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x80800334: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80800338: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(3170, 0X1320) << 16);
    // 0x8080033C: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800340: addiu       $t2, $t2, 0x1320
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(3170, 0X1320));
    // 0x80800344: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800348: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8080034C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800350: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80800354: mflo        $t7
    ctx->r15 = lo;
    // 0x80800358: addu        $a0, $t2, $t7
    ctx->r4 = ADD32(ctx->r10, ctx->r15);
    // 0x8080035C: lbu         $a2, 0x6($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X6);
    // 0x80800360: blezl       $a2, L_80800394
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800364: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_80800394;
    }
    goto skip_1;
    // 0x80800364: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_1:
    // 0x80800368: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
L_8080036C:
    // 0x8080036C: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x80800370: bnel        $t1, $t8, L_80800380
    if (ctx->r9 != ctx->r24) {
        // 0x80800374: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800380;
    }
    goto skip_2;
    // 0x80800374: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x80800378: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8080037C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800380:
    // 0x80800380: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800384: bne         $at, $zero, L_8080036C
    if (ctx->r1 != 0) {
        // 0x80800388: addiu       $a1, $a1, 0x24
        ctx->r5 = ADD32(ctx->r5, 0X24);
            goto L_8080036C;
    }
    // 0x80800388: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x8080038C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800390: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_80800394:
    // 0x80800394: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80800398: jal         0x800D5298
    // 0x8080039C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_800D5298(rdram, ctx);
        goto after_2;
    // 0x8080039C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_2:
    // 0x808003A0: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(3170, 0X1320) << 16);
    // 0x808003A4: addiu       $t2, $t2, 0x1320
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(3170, 0X1320));
    // 0x808003A8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808003AC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808003B0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808003B4: beq         $v0, $zero, L_80800494
    if (ctx->r2 == 0) {
        // 0x808003B8: addiu       $t3, $zero, 0xC
        ctx->r11 = ADD32(0, 0XC);
            goto L_80800494;
    }
    // 0x808003B8: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x808003BC: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x808003C0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808003C4: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808003C8: mflo        $t4
    ctx->r12 = lo;
    // 0x808003CC: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    // 0x808003D0: lbu         $a2, 0x7($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X7);
    // 0x808003D4: blezl       $a2, L_80800524
    if (SIGNED(ctx->r6) <= 0) {
        // 0x808003D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800524;
    }
    goto skip_3;
    // 0x808003D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808003DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808003E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003E4:
    // 0x808003E4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x808003E8: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x808003EC: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x808003F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808003F4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x808003F8: addu        $a1, $t7, $v0
    ctx->r5 = ADD32(ctx->r15, ctx->r2);
    // 0x808003FC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80800400: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800404: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x80800408: nop

    // 0x8080040C: bc1tl       L_80800480
    if (c1cs) {
        // 0x80800410: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80800480;
    }
    goto skip_4;
    // 0x80800410: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    skip_4:
    // 0x80800414: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80800418: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8080041C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800420: nop

    // 0x80800424: bc1fl       L_80800480
    if (!c1cs) {
        // 0x80800428: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80800480;
    }
    goto skip_5;
    // 0x80800428: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    skip_5:
    // 0x8080042C: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x80800430: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80800434: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x80800438: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x8080043C: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800440: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800444: mflo        $t9
    ctx->r25 = lo;
    // 0x80800448: addu        $t4, $t2, $t9
    ctx->r12 = ADD32(ctx->r10, ctx->r25);
    // 0x8080044C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80800450: addu        $t9, $s1, $v0
    ctx->r25 = ADD32(ctx->r17, ctx->r2);
    // 0x80800454: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80800458: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8080045C: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80800460: swc1        $f8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f8.u32l;
    // 0x80800464: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80800468: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8080046C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80800470: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800474: addu        $a0, $t2, $t5
    ctx->r4 = ADD32(ctx->r10, ctx->r13);
    // 0x80800478: lbu         $a2, 0x7($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X7);
    // 0x8080047C: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
L_80800480:
    // 0x80800480: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800484: bne         $at, $zero, L_808003E4
    if (ctx->r1 != 0) {
        // 0x80800488: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_808003E4;
    }
    // 0x80800488: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8080048C: b           L_80800524
    // 0x80800490: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800524;
    // 0x80800490: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800494:
    // 0x80800494: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x80800498: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080049C: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808004A0: mflo        $t7
    ctx->r15 = lo;
    // 0x808004A4: addu        $a0, $t2, $t7
    ctx->r4 = ADD32(ctx->r10, ctx->r15);
    // 0x808004A8: lbu         $a2, 0x7($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X7);
    // 0x808004AC: blezl       $a2, L_80800524
    if (SIGNED(ctx->r6) <= 0) {
        // 0x808004B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800524;
    }
    goto skip_6;
    // 0x808004B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x808004B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808004B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004BC:
    // 0x808004BC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x808004C0: sll         $t9, $t0, 3
    ctx->r25 = S32(ctx->r8 << 3);
    // 0x808004C4: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x808004C8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808004CC: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x808004D0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x808004D4: lwc1        $f0, 0x4($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X4);
    // 0x808004D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808004DC: addu        $t6, $s1, $v0
    ctx->r14 = ADD32(ctx->r17, ctx->r2);
    // 0x808004E0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x808004E4: nop

    // 0x808004E8: bc1tl       L_80800518
    if (c1cs) {
        // 0x808004EC: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80800518;
    }
    goto skip_7;
    // 0x808004EC: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    skip_7:
    // 0x808004F0: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x808004F4: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x808004F8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(3170, 0X1320) << 16);
    // 0x808004FC: addiu       $t9, $t9, 0x1320
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(3170, 0X1320));
    // 0x80800500: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800504: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800508: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080050C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80800510: lbu         $a2, 0x7($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X7);
    // 0x80800514: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
L_80800518:
    // 0x80800518: bne         $at, $zero, L_808004BC
    if (ctx->r1 != 0) {
        // 0x8080051C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_808004BC;
    }
    // 0x8080051C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800524:
    // 0x80800524: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800528: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080052C: jr          $ra
    // 0x80800530: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800530: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chfiregen_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086998: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x80086998);
    return;
    // 0x8008699C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800030_chhotwaterpoolbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080003C: jal         0x80085808
    // 0x80800040: addiu       $a1, $zero, 0x167
    ctx->r5 = ADD32(0, 0X167);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800040: addiu       $a1, $zero, 0x167
    ctx->r5 = ADD32(0, 0X167);
    after_0:
    // 0x80800044: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800048: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080004C: jal         0x80085810
    // 0x80800050: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800050: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_1:
    // 0x80800054: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800058: beql        $t6, $zero, L_8080006C
    if (ctx->r14 == 0) {
        // 0x8080005C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080006C;
    }
    goto skip_0;
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800060: jal         0x80085818
    // 0x80800064: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800064: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080006C:
    // 0x8080006C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DF8: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DF8);
    return;
    // 0x80082DFC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_8010C100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C100: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8010C104: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8010C108: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x8010C10C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010C110: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8010C114: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8010C118: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8010C11C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8010C120: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8010C124: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8010C128: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8010C12C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8010C130: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010C134: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8010C138: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8010C13C: jal         0x80103F38
    // 0x8010C140: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80103F38(rdram, ctx);
        goto after_0;
    // 0x8010C140: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_0:
    // 0x8010C144: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8010C148: jal         0x8010A40C
    // 0x8010C14C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8010A40C(rdram, ctx);
        goto after_1;
    // 0x8010C14C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x8010C150: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010C154: lwc1        $f4, 0x6520($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6520);
    // 0x8010C158: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8010C15C: addiu       $a0, $s4, 0x4
    ctx->r4 = ADD32(ctx->r20, 0X4);
    // 0x8010C160: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010C164: nop

    // 0x8010C168: mul.s       $f20, $f0, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010C16C: jal         0x800BE3F8
    // 0x8010C170: nop

    func_800BE3F8(rdram, ctx);
        goto after_2;
    // 0x8010C170: nop

    after_2:
    // 0x8010C174: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8010C178: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8010C17C: beq         $t6, $zero, L_8010C2A8
    if (ctx->r14 == 0) {
        // 0x8010C180: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_8010C2A8;
    }
    // 0x8010C180: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_8010C184:
    // 0x8010C184: jal         0x800E9E88
    // 0x8010C188: nop

    func_800E9E88(rdram, ctx);
        goto after_3;
    // 0x8010C188: nop

    after_3:
    // 0x8010C18C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010C190: jal         0x800E9EB4
    // 0x8010C194: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_4;
    // 0x8010C194: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_4:
    // 0x8010C198: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8010C19C: beq         $at, $zero, L_8010C298
    if (ctx->r1 == 0) {
        // 0x8010C1A0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8010C298;
    }
    // 0x8010C1A0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8010C1A4: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
L_8010C1A8:
    // 0x8010C1A8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8010C1AC: beql        $t8, $zero, L_8010C28C
    if (ctx->r24 == 0) {
        // 0x8010C1B0: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8010C28C;
    }
    goto skip_0;
    // 0x8010C1B0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x8010C1B4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8010C1B8: lhu         $t9, 0x18($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X18);
    // 0x8010C1BC: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8010C1C0: beql        $t0, $zero, L_8010C28C
    if (ctx->r8 == 0) {
        // 0x8010C1C4: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8010C28C;
    }
    goto skip_1;
    // 0x8010C1C4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x8010C1C8: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x8010C1CC: beql        $s1, $t1, L_8010C28C
    if (ctx->r17 == ctx->r9) {
        // 0x8010C1D0: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8010C28C;
    }
    goto skip_2;
    // 0x8010C1D0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_2:
    // 0x8010C1D4: jal         0x80106790
    // 0x8010C1D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x8010C1D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8010C1DC: lhu         $t2, 0x70($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X70);
    // 0x8010C1E0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8010C1E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010C1E8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8010C1EC: beq         $t3, $zero, L_8010C288
    if (ctx->r11 == 0) {
        // 0x8010C1F0: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_8010C288;
    }
    // 0x8010C1F0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8010C1F4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8010C1F8: jal         0x8010C2D8
    // 0x8010C1FC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_8010C2D8(rdram, ctx);
        goto after_6;
    // 0x8010C1FC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_6:
    // 0x8010C200: beql        $v0, $zero, L_8010C28C
    if (ctx->r2 == 0) {
        // 0x8010C204: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8010C28C;
    }
    goto skip_3;
    // 0x8010C204: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_3:
    // 0x8010C208: lbu         $t4, 0x74($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X74);
    // 0x8010C20C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8010C210: beql        $t5, $zero, L_8010C248
    if (ctx->r13 == 0) {
        // 0x8010C214: lbu         $t8, 0x74($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X74);
            goto L_8010C248;
    }
    goto skip_4;
    // 0x8010C214: lbu         $t8, 0x74($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X74);
    skip_4:
    // 0x8010C218: lbu         $t6, 0x74($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X74);
    // 0x8010C21C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010C220: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8010C224: bnel        $t7, $zero, L_8010C248
    if (ctx->r15 != 0) {
        // 0x8010C228: lbu         $t8, 0x74($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X74);
            goto L_8010C248;
    }
    goto skip_5;
    // 0x8010C228: lbu         $t8, 0x74($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X74);
    skip_5:
    // 0x8010C22C: jal         0x80102F74
    // 0x8010C230: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    func_80102F74(rdram, ctx);
        goto after_7;
    // 0x8010C230: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    after_7:
    // 0x8010C234: beq         $v0, $zero, L_8010C244
    if (ctx->r2 == 0) {
        // 0x8010C238: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8010C244;
    }
    // 0x8010C238: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010C23C: jal         0x800860D0
    // 0x8010C240: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _chflamer_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x8010C240: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
L_8010C244:
    // 0x8010C244: lbu         $t8, 0x74($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X74);
L_8010C248:
    // 0x8010C248: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8010C24C: bne         $t9, $zero, L_8010C280
    if (ctx->r25 != 0) {
        // 0x8010C250: nop
    
            goto L_8010C280;
    }
    // 0x8010C250: nop

    // 0x8010C254: lbu         $t0, 0x74($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0X74);
    // 0x8010C258: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010C25C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8010C260: beq         $t1, $zero, L_8010C280
    if (ctx->r9 == 0) {
        // 0x8010C264: nop
    
            goto L_8010C280;
    }
    // 0x8010C264: nop

    // 0x8010C268: jal         0x80102F74
    // 0x8010C26C: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    func_80102F74(rdram, ctx);
        goto after_9;
    // 0x8010C26C: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    after_9:
    // 0x8010C270: beq         $v0, $zero, L_8010C280
    if (ctx->r2 == 0) {
        // 0x8010C274: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8010C280;
    }
    // 0x8010C274: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010C278: jal         0x800860D0
    // 0x8010C27C: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    _chflamer_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x8010C27C: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    after_10:
L_8010C280:
    // 0x8010C280: b           L_8010C2AC
    // 0x8010C284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010C2AC;
    // 0x8010C284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010C288:
    // 0x8010C288: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_8010C28C:
    // 0x8010C28C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8010C290: bnel        $at, $zero, L_8010C1A8
    if (ctx->r1 != 0) {
        // 0x8010C294: lw          $t7, 0x8($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X8);
            goto L_8010C1A8;
    }
    goto skip_6;
    // 0x8010C294: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    skip_6:
L_8010C298:
    // 0x8010C298: lw          $a0, 0x4($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X4);
    // 0x8010C29C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8010C2A0: bne         $a0, $zero, L_8010C184
    if (ctx->r4 != 0) {
        // 0x8010C2A4: nop
    
            goto L_8010C184;
    }
    // 0x8010C2A4: nop

L_8010C2A8:
    // 0x8010C2A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010C2AC:
    // 0x8010C2AC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8010C2B0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010C2B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8010C2B8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8010C2BC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8010C2C0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8010C2C4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8010C2C8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8010C2CC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8010C2D0: jr          $ra
    // 0x8010C2D4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8010C2D4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void bamum_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800268: lw          $t6, 0xD0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD0);
    // 0x8080026C: jr          $ra
    // 0x80800270: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800270: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    // 0x80800274: nop

    // 0x80800278: nop

    // 0x8080027C: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801BB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801BB4: jal         0x80100094
    // 0x80801BB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801BB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801BBC: beq         $v0, $zero, L_80801BD8
    if (ctx->r2 == 0) {
        // 0x80801BC0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801BD8;
    }
    // 0x80801BC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801BC4: jal         0x80100094
    // 0x80801BC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801BC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801BCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801BD0: jal         0x80089818
    // 0x80801BD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_2;
    // 0x80801BD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80801BD8:
    // 0x80801BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801BE0: jr          $ra
    // 0x80801BE4: nop

    return;
    // 0x80801BE4: nop

;}
RECOMP_FUNC void func_808008F8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800900: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800904: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800908: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080090C: jal         0x800EA05C
    // 0x80800910: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800910: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800914: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800918: jal         0x800DA298
    // 0x8080091C: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080091C: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_1:
    // 0x80800920: beq         $v0, $zero, L_80800938
    if (ctx->r2 == 0) {
        // 0x80800924: addiu       $at, $zero, 0x15D
        ctx->r1 = ADD32(0, 0X15D);
            goto L_80800938;
    }
    // 0x80800924: addiu       $at, $zero, 0x15D
    ctx->r1 = ADD32(0, 0X15D);
    // 0x80800928: jal         0x800FFAB0
    // 0x8080092C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080092C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800930: b           L_80800A38
    // 0x80800934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800A38;
    // 0x80800934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800938:
    // 0x80800938: bnel        $s0, $at, L_80800968
    if (ctx->r16 != ctx->r1) {
        // 0x8080093C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800968;
    }
    goto skip_0;
    // 0x8080093C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x80800940: jal         0x800EA090
    // 0x80800944: nop

    func_800EA090(rdram, ctx);
        goto after_3;
    // 0x80800944: nop

    after_3:
    // 0x80800948: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080094C: beql        $v0, $at, L_80800968
    if (ctx->r2 == ctx->r1) {
        // 0x80800950: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800968;
    }
    goto skip_1;
    // 0x80800950: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_1:
    // 0x80800954: jal         0x800FFAB0
    // 0x80800958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8080095C: b           L_80800A38
    // 0x80800960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800A38;
    // 0x80800960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800964: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800968:
    // 0x80800968: addiu       $s2, $zero, 0xF
    ctx->r18 = ADD32(0, 0XF);
    // 0x8080096C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800970:
    // 0x80800970: jal         0x80802158
    // 0x80800974: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80802158_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80800974: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800978: beq         $v0, $zero, L_80800998
    if (ctx->r2 == 0) {
        // 0x8080097C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800998;
    }
    // 0x8080097C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800980: jal         0x800DA298
    // 0x80800984: nop

    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800984: nop

    after_6:
    // 0x80800988: beq         $v0, $zero, L_80800998
    if (ctx->r2 == 0) {
        // 0x8080098C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800998;
    }
    // 0x8080098C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800990: jal         0x80802170
    // 0x80800994: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x80800994: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
L_80800998:
    // 0x80800998: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080099C: bnel        $s0, $s2, L_80800970
    if (ctx->r16 != ctx->r18) {
        // 0x808009A0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800970;
    }
    goto skip_2;
    // 0x808009A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x808009A4: lbu         $t6, 0x75($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X75);
    // 0x808009A8: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x808009AC: jal         0x80087CA8
    // 0x808009B0: sb          $t7, 0x75($s1)
    MEM_B(0X75, ctx->r17) = ctx->r15;
    _gcnewoption_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808009B0: sb          $t7, 0x75($s1)
    MEM_B(0X75, ctx->r17) = ctx->r15;
    after_8:
    // 0x808009B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808009BC: jal         0x80100074
    // 0x808009C0: addiu       $a2, $v0, 0x10C
    ctx->r6 = ADD32(ctx->r2, 0X10C);
    func_80100074(rdram, ctx);
        goto after_9;
    // 0x808009C0: addiu       $a2, $v0, 0x10C
    ctx->r6 = ADD32(ctx->r2, 0X10C);
    after_9:
    // 0x808009C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009CC: jal         0x80109FE8
    // 0x808009D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_10;
    // 0x808009D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808009D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009D8: jal         0x80109EEC
    // 0x808009DC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109EEC(rdram, ctx);
        goto after_11;
    // 0x808009DC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_11:
    // 0x808009E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009E4: jal         0x80102FDC
    // 0x808009E8: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_12;
    // 0x808009E8: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_12:
    // 0x808009EC: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x808009F0: sb          $t8, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r24;
    // 0x808009F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009F8: jal         0x8010A828
    // 0x808009FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A828(rdram, ctx);
        goto after_13;
    // 0x808009FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800A00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A08: jal         0x80803BE8
    // 0x80800A0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_14;
    // 0x80800A0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80800A10: jal         0x80802CDC
    // 0x80800A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802CDC_chdiggerboss(rdram, ctx);
        goto after_15;
    // 0x80800A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800A18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A1C: jal         0x80802BE0
    // 0x80800A20: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80802BE0_chdiggerboss(rdram, ctx);
        goto after_16;
    // 0x80800A20: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_16:
    // 0x80800A24: jal         0x800DA524
    // 0x80800A28: addiu       $a0, $zero, 0xA4F
    ctx->r4 = ADD32(0, 0XA4F);
    func_800DA524(rdram, ctx);
        goto after_17;
    // 0x80800A28: addiu       $a0, $zero, 0xA4F
    ctx->r4 = ADD32(0, 0XA4F);
    after_17:
    // 0x80800A2C: jal         0x800DA524
    // 0x80800A30: addiu       $a0, $zero, 0xA50
    ctx->r4 = ADD32(0, 0XA50);
    func_800DA524(rdram, ctx);
        goto after_18;
    // 0x80800A30: addiu       $a0, $zero, 0xA50
    ctx->r4 = ADD32(0, 0XA50);
    after_18:
    // 0x80800A34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A38:
    // 0x80800A38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A3C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A40: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800A44: jr          $ra
    // 0x80800A48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800A48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bskazegghead_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808002C4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(252, 0X2F0) << 16);
    // 0x808002C8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808002CC: jr          $ra
    // 0x808002D0: lw          $v0, 0x2F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(252, 0X2F0));
    return;
    // 0x808002D0: lw          $v0, 0x2F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(252, 0X2F0));
;}
RECOMP_FUNC void bsdrone_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F8: jal         0x80800000
    // 0x808000FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_bsdrone(rdram, ctx);
        goto after_0;
    // 0x808000FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800100: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800104: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80800108: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080010C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(160, 0X18C) << 16);
    // 0x80800110: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80800114: lw          $t9, 0x18C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(160, 0X18C));
    // 0x80800118: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: jalr        $t9
    // 0x80800120: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80800120: nop

    after_1:
    // 0x80800124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080012C: jr          $ra
    // 0x80800130: nop

    return;
    // 0x80800130: nop

;}
RECOMP_FUNC void _gcextra_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088408: syscall     681
    recomp_syscall_handler(rdram, ctx, 0x80088408);
    return;
    // 0x8008840C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bashoessuck_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850A0: syscall     149
    recomp_syscall_handler(rdram, ctx, 0x800850A0);
    return;
    // 0x800850A4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void baroll_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C53C: lw          $t6, 0xF4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF4);
    // 0x8009C540: jr          $ra
    // 0x8009C544: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    return;
    // 0x8009C544: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void func_800EE718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE718: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800EE71C: lbu         $t6, 0x5483($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5483);
    // 0x800EE720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EE724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EE728: beql        $t6, $zero, L_800EE73C
    if (ctx->r14 == 0) {
        // 0x800EE72C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EE73C;
    }
    goto skip_0;
    // 0x800EE72C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800EE730: jal         0x80088CC8
    // 0x800EE734: nop

    _idbounce_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x800EE734: nop

    after_0:
    // 0x800EE738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EE73C:
    // 0x800EE73C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EE740: jr          $ra
    // 0x800EE744: nop

    return;
    // 0x800EE744: nop

;}
RECOMP_FUNC void func_8008D694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D69C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D6A0: jal         0x800C6E38
    // 0x8008D6A4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D6A4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x8008D6A8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D6AC: beq         $t6, $zero, L_8008D6C4
    if (ctx->r14 == 0) {
        // 0x8008D6B0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D6C4;
    }
    // 0x8008D6B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D6B4: jal         0x800A3304
    // 0x8008D6B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D6B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008D6BC: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D6C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008D6C4:
    // 0x8008D6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D6C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D6CC: jr          $ra
    // 0x8008D6D0: nop

    return;
    // 0x8008D6D0: nop

;}
RECOMP_FUNC void func_808006D4_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808006D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808006DC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808006E0: lui         $a1, 0x3EB0
    ctx->r5 = S32(0X3EB0 << 16);
    // 0x808006E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808006E8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808006EC: jal         0x80101E14
    // 0x808006F0: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x808006F0: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    after_0:
    // 0x808006F4: beq         $v0, $zero, L_808007E0
    if (ctx->r2 == 0) {
        // 0x808006F8: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_808007E0;
    }
    // 0x808006F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808006FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800700: jal         0x8008A0E8
    // 0x80800704: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800704: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80800708: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x8080070C: addiu       $a0, $sp, 0x3C
        ctx->r4 = ADD32(ctx->r29, 0X3C);
            goto L_808008F0;
    }
    // 0x8080070C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800710: lw          $a1, 0x48($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X48);
    // 0x80800714: jal         0x800EF1B8
    // 0x80800718: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x80800718: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_2:
    // 0x8080071C: jal         0x800B53A4
    // 0x80800720: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800B53A4(rdram, ctx);
        goto after_3;
    // 0x80800720: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_3:
    // 0x80800724: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(940, 0X106C) << 16);
    // 0x80800728: addiu       $t6, $t6, 0x106C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(940, 0X106C));
    // 0x8080072C: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    // 0x80800730: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800734: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800738: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080073C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800740: jal         0x800BABB8
    // 0x80800744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080074C: addiu       $a1, $zero, -0x64
    ctx->r5 = ADD32(0, -0X64);
    // 0x80800750: jal         0x800BA610
    // 0x80800754: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    func_800BA610(rdram, ctx);
        goto after_5;
    // 0x80800754: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    after_5:
    // 0x80800758: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080075C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800760: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80800764: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800768: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080076C: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80800770: lwc1        $f2, 0x38($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800774: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80800778: add.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8080077C: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80800780: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80800784: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080078C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80800790: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800794: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800798: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8080079C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007A0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808007A4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x808007A8: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x808007AC: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x808007B0: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x808007B4: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x808007B8: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x808007BC: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x808007C0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x808007C4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808007C8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x808007CC: jal         0x800BA994
    // 0x808007D0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_800BA994(rdram, ctx);
        goto after_6;
    // 0x808007D0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_6:
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D8: jal         0x800BA22C
    // 0x808007DC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x808007DC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_7:
L_808007E0:
    // 0x808007E0: lui         $a1, 0x3EDC
    ctx->r5 = S32(0X3EDC << 16);
    // 0x808007E4: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    // 0x808007E8: jal         0x80101E14
    // 0x808007EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x808007EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x808007F0: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x808007F4: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_808008F0;
    }
    // 0x808007F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808007F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x808007FC: jal         0x8008A0E8
    // 0x80800800: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800800: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_9:
    // 0x80800804: beql        $v0, $zero, L_808008F4
    if (ctx->r2 == 0) {
        // 0x80800808: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808008F4;
    }
    goto skip_0;
    // 0x80800808: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080080C: jal         0x800B53A4
    // 0x80800810: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800B53A4(rdram, ctx);
        goto after_10;
    // 0x80800810: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_10:
    // 0x80800814: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(940, 0XE40) << 16);
    // 0x80800818: lwc1        $f18, 0xE40($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(940, 0XE40));
    // 0x8080081C: lwc1        $f16, 0x38($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800820: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(940, 0X106C) << 16);
    // 0x80800824: addiu       $t8, $t8, 0x106C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(940, 0X106C));
    // 0x80800828: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080082C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800830: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800834: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800838: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8080083C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800840: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800844: jal         0x800BABB8
    // 0x80800848: nop

    func_800BABB8(rdram, ctx);
        goto after_11;
    // 0x80800848: nop

    after_11:
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800850: addiu       $a1, $zero, -0x320
    ctx->r5 = ADD32(0, -0X320);
    // 0x80800854: jal         0x800BA610
    // 0x80800858: addiu       $a2, $zero, -0x3E8
    ctx->r6 = ADD32(0, -0X3E8);
    func_800BA610(rdram, ctx);
        goto after_12;
    // 0x80800858: addiu       $a2, $zero, -0x3E8
    ctx->r6 = ADD32(0, -0X3E8);
    after_12:
    // 0x8080085C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800860: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800864: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800868: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080086C: lwc1        $f6, 0x48($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80800870: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800874: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800878: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080087C: lwc1        $f2, 0x38($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800880: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800884: addiu       $t5, $zero, -0xF
    ctx->r13 = ADD32(0, -0XF);
    // 0x80800888: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8080088C: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80800890: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800894: add.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080089C: addiu       $a1, $zero, -0x19
    ctx->r5 = ADD32(0, -0X19);
    // 0x808008A0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808008A4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808008A8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808008AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808008B0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808008B4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808008B8: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x808008BC: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x808008C0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x808008C4: sll         $t3, $a3, 16
    ctx->r11 = S32(ctx->r7 << 16);
    // 0x808008C8: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    // 0x808008CC: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x808008D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808008D4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808008D8: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x808008DC: jal         0x800BA994
    // 0x808008E0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_800BA994(rdram, ctx);
        goto after_13;
    // 0x808008E0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_13:
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E8: jal         0x800BA22C
    // 0x808008EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800BA22C(rdram, ctx);
        goto after_14;
    // 0x808008EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_14:
L_808008F0:
    // 0x808008F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808008F4:
    // 0x808008F4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808008F8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808008FC: jr          $ra
    // 0x80800900: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800900: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void badeathmatch_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800248: addiu       $t6, $a0, -0x40
    ctx->r14 = ADD32(ctx->r4, -0X40);
    // 0x8080024C: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80800250: beq         $at, $zero, L_808002A0
    if (ctx->r1 == 0) {
        // 0x80800254: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808002A0;
    }
    // 0x80800254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800258: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080025C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(657, 0X530) << 16);
    // 0x80800260: addu        $at, $at, $t6
    gpr jr_addend_80800268 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800264: lw          $t6, 0x530($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(657, 0X530));
    // 0x80800268: jr          $t6
    // 0x8080026C: nop

    switch (jr_addend_80800268 >> 2) {
        case 0: goto L_80800270; break;
        case 1: goto L_80800278; break;
        case 2: goto L_80800280; break;
        case 3: goto L_80800288; break;
        case 4: goto L_80800290; break;
        case 5: goto L_80800298; break;
        default: switch_error(__func__, 0x80800268, 0x80800530);
    }
    // 0x8080026C: nop

L_80800270:
    // 0x80800270: jr          $ra
    // 0x80800274: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800274: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800278:
    // 0x80800278: jr          $ra
    // 0x8080027C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x8080027C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800280:
    // 0x80800280: jr          $ra
    // 0x80800284: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80800284: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800288:
    // 0x80800288: jr          $ra
    // 0x8080028C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x8080028C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800290:
    // 0x80800290: jr          $ra
    // 0x80800294: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x80800294: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80800298:
    // 0x80800298: jr          $ra
    // 0x8080029C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x8080029C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_808002A0:
    // 0x808002A0: jr          $ra
    // 0x808002A4: nop

    return;
    // 0x808002A4: nop

;}
RECOMP_FUNC void func_80801040_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801040: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801044: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080104C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801050: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801054: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80801058: jal         0x80102EC8
    // 0x8080105C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80102EC8(rdram, ctx);
        goto after_0;
    // 0x8080105C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801060: bne         $v0, $zero, L_80801078
    if (ctx->r2 != 0) {
        // 0x80801064: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_80801078;
    }
    // 0x80801064: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80801068: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080106C: nop

    // 0x80801070: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80801074: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
L_80801078:
    // 0x80801078: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080107C: jal         0x800EF04C
    // 0x80801080: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x80801080: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_1:
    // 0x80801084: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801088: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080108C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801090: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801094: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80801098: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8080109C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808010A4: bc1f        L_808010B0
    if (!c1cs) {
        // 0x808010A8: swc1        $f8, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
            goto L_808010B0;
    }
    // 0x808010A8: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x808010AC: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_808010B0:
    // 0x808010B0: jal         0x80102CF4
    // 0x808010B4: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    func_80102CF4(rdram, ctx);
        goto after_2;
    // 0x808010B4: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_2:
    // 0x808010B8: bne         $v0, $zero, L_808010C8
    if (ctx->r2 != 0) {
        // 0x808010BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010C8;
    }
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010C0: jal         0x80102B2C
    // 0x808010C4: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B2C(rdram, ctx);
        goto after_3;
    // 0x808010C4: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_3:
L_808010C8:
    // 0x808010C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808010CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808010D4: jr          $ra
    // 0x808010D8: nop

    return;
    // 0x808010D8: nop

;}
RECOMP_FUNC void func_80104668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104668: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010466C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104670: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80104674: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80104678: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8010467C: jal         0x80104544
    // 0x80104680: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_80104544(rdram, ctx);
        goto after_0;
    // 0x80104680: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80104684: bne         $v0, $zero, L_80104694
    if (ctx->r2 != 0) {
        // 0x80104688: nop
    
            goto L_80104694;
    }
    // 0x80104688: nop

    // 0x8010468C: b           L_8010472C
    // 0x80104690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010472C;
    // 0x80104690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80104694:
    // 0x80104694: jal         0x801043D8
    // 0x80104698: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_801043D8(rdram, ctx);
        goto after_1;
    // 0x80104698: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8010469C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801046A0: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x801046A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801046A8: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x801046AC: beq         $t7, $zero, L_801046BC
    if (ctx->r15 == 0) {
        // 0x801046B0: nop
    
            goto L_801046BC;
    }
    // 0x801046B0: nop

    // 0x801046B4: b           L_8010472C
    // 0x801046B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010472C;
    // 0x801046B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801046BC:
    // 0x801046BC: jal         0x800EE7F8
    // 0x801046C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x801046C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x801046C4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x801046C8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801046CC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801046D0: lh          $t9, 0x16($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X16);
    // 0x801046D4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801046D8: nop

    // 0x801046DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801046E0: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x801046E4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x801046E8: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x801046EC: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x801046F0: jal         0x800F0E00
    // 0x801046F4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    func_800F0E00(rdram, ctx);
        goto after_3;
    // 0x801046F4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_3:
    // 0x801046F8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x801046FC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80104700: swc1        $f0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f0.u32l;
    // 0x80104704: jal         0x801048E4
    // 0x80104708: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_801048E4(rdram, ctx);
        goto after_4;
    // 0x80104708: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8010470C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80104710: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80104714: jal         0x800F1988
    // 0x80104718: addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    func_800F1988(rdram, ctx);
        goto after_5;
    // 0x80104718: addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    after_5:
    // 0x8010471C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80104720: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80104724: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104728: swc1        $f16, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f16.u32l;
L_8010472C:
    // 0x8010472C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104730: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80104734: jr          $ra
    // 0x80104738: nop

    return;
    // 0x80104738: nop

;}
RECOMP_FUNC void func_8010DF3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DF3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010DF40: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010DF44: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010DF48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010DF4C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8010DF50: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
L_8010DF54:
    // 0x8010DF54: jal         0x80104148
    // 0x8010DF58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104148(rdram, ctx);
        goto after_0;
    // 0x8010DF58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8010DF5C: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8010DF60: beql        $t6, $zero, L_8010DF7C
    if (ctx->r14 == 0) {
        // 0x8010DF64: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8010DF7C;
    }
    goto skip_0;
    // 0x8010DF64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8010DF68: jal         0x80104200
    // 0x8010DF6C: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    func_80104200(rdram, ctx);
        goto after_1;
    // 0x8010DF6C: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x8010DF70: jal         0x8008ADE4
    // 0x8010DF74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008ADE4(rdram, ctx);
        goto after_2;
    // 0x8010DF74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8010DF78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8010DF7C:
    // 0x8010DF7C: bne         $s0, $s1, L_8010DF54
    if (ctx->r16 != ctx->r17) {
        // 0x8010DF80: nop
    
            goto L_8010DF54;
    }
    // 0x8010DF80: nop

    // 0x8010DF84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010DF88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010DF8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010DF90: jr          $ra
    // 0x8010DF94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010DF94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800008_bsbbilldrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: jal         0x800BF8E4
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800BF8E4(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080001C: blezl       $v0, L_808000B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800020: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000B0;
    }
    goto skip_0;
    // 0x80800020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800024: lw          $t6, 0x168($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X168);
    // 0x80800028: bnel        $t6, $zero, L_8080005C
    if (ctx->r14 != 0) {
        // 0x8080002C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080005C;
    }
    goto skip_1;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800030: jal         0x800C8A98
    // 0x80800034: nop

    func_800C8A98(rdram, ctx);
        goto after_1;
    // 0x80800034: nop

    after_1:
    // 0x80800038: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x8080003C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800040: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800044: jal         0x800C8E54
    // 0x80800048: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    func_800C8E54(rdram, ctx);
        goto after_2;
    // 0x80800048: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    after_2:
    // 0x8080004C: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    // 0x80800050: jal         0x800C8F64
    // 0x80800054: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_800C8F64(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080005C:
    // 0x8080005C: jal         0x8009C128
    // 0x80800060: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_4;
    // 0x80800060: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800064: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800068: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080006C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800070: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800074: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800078: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8080007C: jal         0x800C8CB8
    // 0x80800080: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    func_800C8CB8(rdram, ctx);
        goto after_5;
    // 0x80800080: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    after_5:
    // 0x80800084: jal         0x8001210C
    // 0x80800088: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_6;
    // 0x80800088: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8080008C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800090: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80800094: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(61, 0XAB0) << 16);
    // 0x80800098: addiu       $t8, $t8, 0xAB0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(61, 0XAB0));
    // 0x8080009C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000A0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x808000A4: jal         0x800C8E84
    // 0x808000A8: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    func_800C8E84(rdram, ctx);
        goto after_7;
    // 0x808000A8: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    after_7:
    // 0x808000AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000B0:
    // 0x808000B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void chboxingglove_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(944, 0X708) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x708
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(944, 0X708));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x708
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(944, 0X708));
;}
RECOMP_FUNC void func_800A940C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A940C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A9410: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9414: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800A9418: jr          $ra
    // 0x800A941C: lw          $v0, 0x76E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X76E8);
    return;
    // 0x800A941C: lw          $v0, 0x76E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X76E8);
;}
RECOMP_FUNC void func_80801D70_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D78: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x80801D7C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801D80: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80801D84: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80801D88: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801D8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801D90: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80801D94: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80801D98: swc1        $f2, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f2.u32l;
    // 0x80801D9C: swc1        $f12, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f12.u32l;
    // 0x80801DA0: swc1        $f0, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->f0.u32l;
    // 0x80801DA4: swc1        $f0, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->f0.u32l;
    // 0x80801DA8: jal         0x80084B00
    // 0x80801DAC: swc1        $f0, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f0.u32l;
    _baeggcursor_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80801DAC: swc1        $f0, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f0.u32l;
    after_0:
    // 0x80801DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801DB8: jr          $ra
    // 0x80801DBC: nop

    return;
    // 0x80801DBC: nop

;}
