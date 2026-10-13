#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void ncbatarget_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800258: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080025C: lw          $t6, 0x58($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X58);
    // 0x80800260: jr          $ra
    // 0x80800264: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800264: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void chcrusherboulder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801274: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1640, 0X14EC) << 16);
    // 0x80801278: jr          $ra
    // 0x8080127C: addiu       $v0, $v0, 0x14EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1640, 0X14EC));
    return;
    // 0x8080127C: addiu       $v0, $v0, 0x14EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1640, 0X14EC));
;}
RECOMP_FUNC void func_8008DF18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DF18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DF1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DF20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008DF24: jal         0x80091570
    // 0x8008DF28: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    bastatetimer_isActive(rdram, ctx);
        goto after_0;
    // 0x8008DF28: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x8008DF2C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008DF30: bne         $t6, $zero, L_8008DF7C
    if (ctx->r14 != 0) {
        // 0x8008DF34: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008DF7C;
    }
    // 0x8008DF34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008DF38: jal         0x800A3378
    // 0x8008DF3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3378(rdram, ctx);
        goto after_1;
    // 0x8008DF3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008DF40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008DF44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008DF48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008DF4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008DF50: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8008DF54: nop

    // 0x8008DF58: bc1f        L_8008DF64
    if (!c1cs) {
        // 0x8008DF5C: nop
    
            goto L_8008DF64;
    }
    // 0x8008DF5C: nop

    // 0x8008DF60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DF64:
    // 0x8008DF64: beql        $v0, $zero, L_8008DF80
    if (ctx->r2 == 0) {
        // 0x8008DF68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008DF80;
    }
    goto skip_0;
    // 0x8008DF68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008DF6C: jal         0x8009659C
    // 0x8008DF70: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_8009659C(rdram, ctx);
        goto after_2;
    // 0x8008DF70: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
    // 0x8008DF74: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008DF78: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008DF7C:
    // 0x8008DF7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DF80:
    // 0x8008DF80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DF84: jr          $ra
    // 0x8008DF88: nop

    return;
    // 0x8008DF88: nop

;}
RECOMP_FUNC void func_808068E8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808068E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808068EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808068F0: jal         0x80809D6C
    // 0x808068F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80809D6C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808068F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808068F8: beq         $v0, $zero, L_80806910
    if (ctx->r2 == 0) {
        // 0x808068FC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80806910;
    }
    // 0x808068FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80806900: jal         0x808069BC
    // 0x80806904: nop

    func_808069BC_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80806904: nop

    after_1:
    // 0x80806908: b           L_8080691C
    // 0x8080690C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080691C;
    // 0x8080690C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806910:
    // 0x80806910: jal         0x808069FC
    // 0x80806914: nop

    func_808069FC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80806914: nop

    after_2:
    // 0x80806918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080691C:
    // 0x8080691C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806920: jr          $ra
    // 0x80806924: nop

    return;
    // 0x80806924: nop

;}
RECOMP_FUNC void _gldialog_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088758: syscall     702
    recomp_syscall_handler(rdram, ctx, 0x80088758);
    return;
    // 0x8008875C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bskazshoessuckspline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835D0: syscall     68
    recomp_syscall_handler(rdram, ctx, 0x800835D0);
    return;
    // 0x800835D4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800123F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800123F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800123F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800123FC: jal         0x8001207C
    // 0x80012400: nop

    func_8001207C(rdram, ctx);
        goto after_0;
    // 0x80012400: nop

    after_0:
    // 0x80012404: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80012408: lw          $t6, 0x3380($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3380);
    // 0x8001240C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012410: bne         $t6, $at, L_80012428
    if (ctx->r14 != ctx->r1) {
        // 0x80012414: nop
    
            goto L_80012428;
    }
    // 0x80012414: nop

    // 0x80012418: jal         0x800A8184
    // 0x8001241C: nop

    func_800A8184(rdram, ctx);
        goto after_1;
    // 0x8001241C: nop

    after_1:
    // 0x80012420: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80012424: beq         $v0, $at, L_8001243C
    if (ctx->r2 == ctx->r1) {
        // 0x80012428: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8001243C;
    }
L_80012428:
    // 0x80012428: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001242C: addiu       $v0, $v0, 0x59C8
    ctx->r2 = ADD32(ctx->r2, 0X59C8);
    // 0x80012430: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80012434: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80012438: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8001243C:
    // 0x8001243C: jal         0x80012530
    // 0x80012440: nop

    func_80012530(rdram, ctx);
        goto after_2;
    // 0x80012440: nop

    after_2:
    // 0x80012444: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012448: bne         $v0, $at, L_80012458
    if (ctx->r2 != ctx->r1) {
        // 0x8001244C: nop
    
            goto L_80012458;
    }
    // 0x8001244C: nop

    // 0x80012450: jal         0x800A7D30
    // 0x80012454: nop

    func_800A7D30(rdram, ctx);
        goto after_3;
    // 0x80012454: nop

    after_3:
L_80012458:
    // 0x80012458: jal         0x8001608C
    // 0x8001245C: nop

    func_8001608C(rdram, ctx);
        goto after_4;
    // 0x8001245C: nop

    after_4:
    // 0x80012460: jal         0x80018444
    // 0x80012464: nop

    func_80018444(rdram, ctx);
        goto after_5;
    // 0x80012464: nop

    after_5:
    // 0x80012468: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8001246C: lw          $t9, 0x3380($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3380);
    // 0x80012470: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012474: bne         $t9, $at, L_80012484
    if (ctx->r25 != ctx->r1) {
        // 0x80012478: nop
    
            goto L_80012484;
    }
    // 0x80012478: nop

    // 0x8001247C: jal         0x800123BC
    // 0x80012480: nop

    func_800123BC(rdram, ctx);
        goto after_6;
    // 0x80012480: nop

    after_6:
L_80012484:
    // 0x80012484: jal         0x8008160C
    // 0x80012488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008160C(rdram, ctx);
        goto after_7;
    // 0x80012488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x8001248C: jal         0x8001E010
    // 0x80012490: nop

    func_8001E010(rdram, ctx);
        goto after_8;
    // 0x80012490: nop

    after_8:
    // 0x80012494: jal         0x800D9004
    // 0x80012498: nop

    func_800D9004(rdram, ctx);
        goto after_9;
    // 0x80012498: nop

    after_9:
    // 0x8001249C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800124A0: lwc1        $f4, 0x16A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X16A0);
    // 0x800124A4: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800124A8: nop

    // 0x800124AC: bc1f        L_800124BC
    if (!c1cs) {
        // 0x800124B0: nop
    
            goto L_800124BC;
    }
    // 0x800124B0: nop

    // 0x800124B4: jal         0x8001EAB4
    // 0x800124B8: nop

    do_crc_check(rdram, ctx);
        goto after_10;
    // 0x800124B8: nop

    after_10:
L_800124BC:
    // 0x800124BC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800124C0: lw          $v0, 0x3384($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3384);
    // 0x800124C4: beql        $v0, $zero, L_800124E0
    if (ctx->r2 == 0) {
        // 0x800124C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800124E0;
    }
    goto skip_0;
    // 0x800124C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800124CC: jal         0x8001209C
    // 0x800124D0: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    func_8001209C(rdram, ctx);
        goto after_11;
    // 0x800124D0: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    after_11:
    // 0x800124D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800124D8: sw          $zero, 0x3384($at)
    MEM_W(0X3384, ctx->r1) = 0;
    // 0x800124DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800124E0:
    // 0x800124E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800124E4: jr          $ra
    // 0x800124E8: nop

    return;
    // 0x800124E8: nop

;}
RECOMP_FUNC void func_8010AE9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AE9C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010AEA0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8010AEA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010AEA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010AEAC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8010AEB0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8010AEB4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8010AEB8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8010AEBC: jal         0x800EC708
    // 0x8010AEC0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800EC708(rdram, ctx);
        goto after_0;
    // 0x8010AEC0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8010AEC4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8010AEC8: jal         0x8010A40C
    // 0x8010AECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A40C(rdram, ctx);
        goto after_1;
    // 0x8010AECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8010AED0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010AED4: lwc1        $f6, 0x651C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X651C);
    // 0x8010AED8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010AEDC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8010AEE0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8010AEE4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010AEE8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8010AEEC: addiu       $a3, $a3, 0x6F30
    ctx->r7 = ADD32(ctx->r7, 0X6F30);
    // 0x8010AEF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010AEF4: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010AEF8: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8010AEFC: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8010AF00: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8010AF04: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8010AF08: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x8010AF0C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010AF10: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8010AF14: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8010AF18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8010AF1C: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8010AF20: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8010AF24: jal         0x800BF0E0
    // 0x8010AF28: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_800BF0E0(rdram, ctx);
        goto after_2;
    // 0x8010AF28: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x8010AF2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010AF30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8010AF34: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8010AF38: jal         0x800EE7F8
    // 0x8010AF3C: addiu       $a0, $a0, 0x6F20
    ctx->r4 = ADD32(ctx->r4, 0X6F20);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x8010AF3C: addiu       $a0, $a0, 0x6F20
    ctx->r4 = ADD32(ctx->r4, 0X6F20);
    after_3:
    // 0x8010AF40: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010AF44: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8010AF48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010AF4C: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8010AF50: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x8010AF54: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010AF58: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8010AF5C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8010AF60: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8010AF64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010AF68: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8010AF6C: beq         $t8, $zero, L_8010AF7C
    if (ctx->r24 == 0) {
        // 0x8010AF70: nop
    
            goto L_8010AF7C;
    }
    // 0x8010AF70: nop

    // 0x8010AF74: b           L_8010AF7C
    // 0x8010AF78: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8010AF7C;
    // 0x8010AF78: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8010AF7C:
    // 0x8010AF7C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8010AF80: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8010AF84: jr          $ra
    // 0x8010AF88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8010AF88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8080055C_chdinofoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080055C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800560: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800564: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800568: jal         0x80800408
    // 0x8080056C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800408_chdinofoot(rdram, ctx);
        goto after_0;
    // 0x8080056C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800570: beql        $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x80800574: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808005B0;
    }
    goto skip_0;
    // 0x80800574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800578: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8080057C: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80800588: jal         0x8010CD28
    // 0x8080058C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    func_8010CD28(rdram, ctx);
        goto after_1;
    // 0x8080058C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x80800590: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800594: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800598: jal         0x800136E4
    // 0x8080059C: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x8080059C: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    after_2:
    // 0x808005A0: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808005A4: b           L_808005B0
    // 0x808005A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005B0;
    // 0x808005A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005B0:
    // 0x808005B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005BC: jr          $ra
    // 0x808005C0: nop

    return;
    // 0x808005C0: nop

;}
RECOMP_FUNC void bskazstill_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003D8: jal         0x8008CABC
    // 0x808003DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808003DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003E0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808003E4: jal         0x8009EF10
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003EC: bnel        $v0, $zero, L_8080043C
    if (ctx->r2 != 0) {
        // 0x808003F0: lw          $t7, 0x164($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X164);
            goto L_8080043C;
    }
    goto skip_0;
    // 0x808003F0: lw          $t7, 0x164($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X164);
    skip_0:
    // 0x808003F4: jal         0x8009EF04
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_2;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808003FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800400: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800408: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080040C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800410: bc1fl       L_8080043C
    if (!c1cs) {
        // 0x80800414: lw          $t7, 0x164($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X164);
            goto L_8080043C;
    }
    goto skip_1;
    // 0x80800414: lw          $t7, 0x164($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X164);
    skip_1:
    // 0x80800418: jal         0x8009C908
    // 0x8080041C: sw          $t6, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r14;
    yaw_setUpdateType(rdram, ctx);
        goto after_3;
    // 0x8080041C: sw          $t6, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r14;
    after_3:
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800424: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800428: jal         0x8009C99C
    // 0x8080042C: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_4;
    // 0x8080042C: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    after_4:
    // 0x80800430: b           L_80800468
    // 0x80800434: nop

        goto L_80800468;
    // 0x80800434: nop

    // 0x80800438: lw          $t7, 0x164($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X164);
L_8080043C:
    // 0x8080043C: beql        $t7, $zero, L_8080045C
    if (ctx->r15 == 0) {
        // 0x80800440: sw          $zero, 0x164($s0)
        MEM_W(0X164, ctx->r16) = 0;
            goto L_8080045C;
    }
    goto skip_2;
    // 0x80800440: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    skip_2:
    // 0x80800444: jal         0x8009C984
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_5;
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080044C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800450: jal         0x8009C914
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800458: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
L_8080045C:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: jal         0x8009C908
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_7;
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_80800468:
    // 0x80800468: jal         0x8008E39C
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E39C(rdram, ctx);
        goto after_8;
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800470: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800474: lw          $v1, 0x15C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X15C);
    // 0x80800478: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080047C: beq         $v1, $at, L_80800604
    if (ctx->r3 == ctx->r1) {
        // 0x80800480: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800604;
    }
    // 0x80800480: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800484: beq         $v1, $at, L_808004A0
    if (ctx->r3 == ctx->r1) {
        // 0x80800488: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808004A0;
    }
    // 0x80800488: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080048C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800490: beq         $v1, $at, L_808005C4
    if (ctx->r3 == ctx->r1) {
        // 0x80800494: nop
    
            goto L_808005C4;
    }
    // 0x80800494: nop

    // 0x80800498: b           L_80800604
    // 0x8080049C: nop

        goto L_80800604;
    // 0x8080049C: nop

L_808004A0:
    // 0x808004A0: lui         $a1, 0x3EB7
    ctx->r5 = S32(0X3EB7 << 16);
    // 0x808004A4: jal         0x8008B348
    // 0x808004A8: ori         $a1, $a1, 0xA787
    ctx->r5 = ctx->r5 | 0XA787;
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x808004A8: ori         $a1, $a1, 0xA787
    ctx->r5 = ctx->r5 | 0XA787;
    after_9:
    // 0x808004AC: beq         $v0, $zero, L_808004C8
    if (ctx->r2 == 0) {
        // 0x808004B0: lui         $a2, 0x3FE6
        ctx->r6 = S32(0X3FE6 << 16);
            goto L_808004C8;
    }
    // 0x808004B0: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x808004B4: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004BC: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x808004C0: jal         0x8009DF18
    // 0x808004C4: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF18(rdram, ctx);
        goto after_10;
    // 0x808004C4: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_10:
L_808004C8:
    // 0x808004C8: lui         $a1, 0x3EC5
    ctx->r5 = S32(0X3EC5 << 16);
    // 0x808004CC: ori         $a1, $a1, 0x94AF
    ctx->r5 = ctx->r5 | 0X94AF;
    // 0x808004D0: jal         0x8008B348
    // 0x808004D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_11;
    // 0x808004D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_11:
    // 0x808004D8: beq         $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x808004DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004F4;
    }
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x808004E4: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808004E8: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x808004EC: jal         0x8009DF18
    // 0x808004F0: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF18(rdram, ctx);
        goto after_12;
    // 0x808004F0: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_12:
L_808004F4:
    // 0x808004F4: lui         $a1, 0x3F02
    ctx->r5 = S32(0X3F02 << 16);
    // 0x808004F8: ori         $a1, $a1, 0xCA58
    ctx->r5 = ctx->r5 | 0XCA58;
    // 0x808004FC: jal         0x8008B348
    // 0x80800500: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_13;
    // 0x80800500: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x80800504: beq         $v0, $zero, L_80800520
    if (ctx->r2 == 0) {
        // 0x80800508: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800520;
    }
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080050C: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800510: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800514: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x80800518: jal         0x8009DF18
    // 0x8080051C: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF18(rdram, ctx);
        goto after_14;
    // 0x8080051C: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_14:
L_80800520:
    // 0x80800520: lui         $a1, 0x3F0F
    ctx->r5 = S32(0X3F0F << 16);
    // 0x80800524: ori         $a1, $a1, 0x4F0E
    ctx->r5 = ctx->r5 | 0X4F0E;
    // 0x80800528: jal         0x8008B348
    // 0x8080052C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_15;
    // 0x8080052C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_15:
    // 0x80800530: beq         $v0, $zero, L_8080054C
    if (ctx->r2 == 0) {
        // 0x80800534: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080054C;
    }
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x8080053C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800540: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x80800544: jal         0x8009DF18
    // 0x80800548: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF18(rdram, ctx);
        goto after_16;
    // 0x80800548: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_16:
L_8080054C:
    // 0x8080054C: lui         $a1, 0x3F5B
    ctx->r5 = S32(0X3F5B << 16);
    // 0x80800550: ori         $a1, $a1, 0xD3C3
    ctx->r5 = ctx->r5 | 0XD3C3;
    // 0x80800554: jal         0x8008B348
    // 0x80800558: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_17;
    // 0x80800558: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_17:
    // 0x8080055C: beq         $v0, $zero, L_80800578
    if (ctx->r2 == 0) {
        // 0x80800560: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800578;
    }
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800564: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800568: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080056C: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x80800570: jal         0x8009DF18
    // 0x80800574: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF18(rdram, ctx);
        goto after_18;
    // 0x80800574: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_18:
L_80800578:
    // 0x80800578: lui         $a1, 0x3F64
    ctx->r5 = S32(0X3F64 << 16);
    // 0x8080057C: ori         $a1, $a1, 0x2C3D
    ctx->r5 = ctx->r5 | 0X2C3D;
    // 0x80800580: jal         0x8008B348
    // 0x80800584: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_19;
    // 0x80800584: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_19:
    // 0x80800588: beq         $v0, $zero, L_808005A4
    if (ctx->r2 == 0) {
        // 0x8080058C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005A4;
    }
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800594: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800598: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x8080059C: jal         0x8009DF18
    // 0x808005A0: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF18(rdram, ctx);
        goto after_20;
    // 0x808005A0: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_20:
L_808005A4:
    // 0x808005A4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: beq         $t8, $zero, L_80800614
    if (ctx->r24 == 0) {
        // 0x808005B0: nop
    
            goto L_80800614;
    }
    // 0x808005B0: nop

    // 0x808005B4: jal         0x80800030
    // 0x808005B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800030_bskazstill(rdram, ctx);
        goto after_21;
    // 0x808005B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_21:
    // 0x808005BC: b           L_80800614
    // 0x808005C0: nop

        goto L_80800614;
    // 0x808005C0: nop

L_808005C4:
    // 0x808005C4: beq         $v0, $zero, L_808005F4
    if (ctx->r2 == 0) {
        // 0x808005C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F4;
    }
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005CC: jal         0x80084FE0
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_22;
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808005D4: lw          $t9, 0x168($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X168);
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: beq         $v0, $t9, L_80800614
    if (ctx->r2 == ctx->r25) {
        // 0x808005E0: nop
    
            goto L_80800614;
    }
    // 0x808005E0: nop

    // 0x808005E4: jal         0x80800030
    // 0x808005E8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800030_bskazstill(rdram, ctx);
        goto after_23;
    // 0x808005E8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_23:
    // 0x808005EC: b           L_80800614
    // 0x808005F0: nop

        goto L_80800614;
    // 0x808005F0: nop

L_808005F4:
    // 0x808005F4: jal         0x80800030
    // 0x808005F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800030_bskazstill(rdram, ctx);
        goto after_24;
    // 0x808005F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x808005FC: b           L_80800614
    // 0x80800600: nop

        goto L_80800614;
    // 0x80800600: nop

L_80800604:
    // 0x80800604: beq         $v0, $zero, L_80800614
    if (ctx->r2 == 0) {
        // 0x80800608: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800614;
    }
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080060C: jal         0x80800030
    // 0x80800610: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800030_bskazstill(rdram, ctx);
        goto after_25;
    // 0x80800610: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_25:
L_80800614:
    // 0x80800614: jal         0x8008B324
    // 0x80800618: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isStopped(rdram, ctx);
        goto after_26;
    // 0x80800618: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_26:
    // 0x8080061C: beql        $v0, $zero, L_8080063C
    if (ctx->r2 == 0) {
        // 0x80800620: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080063C;
    }
    goto skip_3;
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800624: jal         0x80800000
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazstill(rdram, ctx);
        goto after_27;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: jal         0x80800030
    // 0x80800634: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800030_bskazstill(rdram, ctx);
        goto after_28;
    // 0x80800634: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_28:
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080063C:
    // 0x8080063C: jal         0x808001A4
    // 0x80800640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808001A4_bskazstill(rdram, ctx);
        goto after_29;
    // 0x80800640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: jal         0x8009E5C8
    // 0x8080064C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_30;
    // 0x8080064C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_30:
    // 0x80800650: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800654: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800658: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080065C: jr          $ra
    // 0x80800660: nop

    return;
    // 0x80800660: nop

;}
RECOMP_FUNC void func_808007B8_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007C0: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x808007C4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808007C8: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x808007CC: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808007D0: bne         $t7, $at, L_808007E0
    if (ctx->r15 != ctx->r1) {
        // 0x808007D4: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_808007E0;
    }
    // 0x808007D4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808007D8: b           L_80800818
    // 0x808007DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800818;
    // 0x808007DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007E0:
    // 0x808007E0: jal         0x8010D254
    // 0x808007E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x808007E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808007E8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808007EC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808007F0: jal         0x800EEB40
    // 0x808007F4: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x808007F4: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    after_1:
    // 0x808007F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(968, 0XB64) << 16);
    // 0x808007FC: lwc1        $f4, 0xB64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(968, 0XB64));
    // 0x80800800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800804: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800808: nop

    // 0x8080080C: bc1fl       L_8080081C
    if (!c1cs) {
        // 0x80800810: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080081C;
    }
    goto skip_0;
    // 0x80800810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800814: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800818:
    // 0x80800818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080081C:
    // 0x8080081C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800820: jr          $ra
    // 0x80800824: nop

    return;
    // 0x80800824: nop

;}
RECOMP_FUNC void func_80801D20_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801D24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801D2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801D30: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801D34: jal         0x8009EF10
    // 0x80801D38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x80801D38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x80801D3C: blez        $v0, L_80801D48
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801D40: nop
    
            goto L_80801D48;
    }
    // 0x80801D40: nop

    // 0x80801D44: addiu       $s0, $zero, 0x166
    ctx->r16 = ADD32(0, 0X166);
L_80801D48:
    // 0x80801D48: jal         0x8008E35C
    // 0x80801D4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    player_inWater(rdram, ctx);
        goto after_1;
    // 0x80801D4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80801D50: beq         $v0, $zero, L_80801D5C
    if (ctx->r2 == 0) {
        // 0x80801D54: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801D5C;
    }
    // 0x80801D54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801D58: addiu       $s0, $zero, 0x167
    ctx->r16 = ADD32(0, 0X167);
L_80801D5C:
    // 0x80801D5C: jal         0x80800084
    // 0x80801D60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800084_bsbansack(rdram, ctx);
        goto after_2;
    // 0x80801D60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80801D64: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801D68: jal         0x8008E260
    // 0x80801D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008E260(rdram, ctx);
        goto after_3;
    // 0x80801D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80801D70: beq         $v0, $zero, L_80801D7C
    if (ctx->r2 == 0) {
        // 0x80801D74: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801D7C;
    }
    // 0x80801D74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801D78: addiu       $s0, $zero, 0x3D
    ctx->r16 = ADD32(0, 0X3D);
L_80801D7C:
    // 0x80801D7C: jal         0x8009E5C8
    // 0x80801D80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80801D80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80801D84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801D8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801D90: jr          $ra
    // 0x80801D94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801D94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chtimetable_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A18: syscall     405
    recomp_syscall_handler(rdram, ctx, 0x80086A18);
    return;
    // 0x80086A1C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chhoopswoop_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1016, 0X1EC0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1EC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1016, 0X1EC0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1EC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1016, 0X1EC0));
;}
RECOMP_FUNC void func_80804238_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804238: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080423C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804240: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804244: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80804248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080424C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804250: beq         $v0, $zero, L_80804268
    if (ctx->r2 == 0) {
        // 0x80804254: nop
    
            goto L_80804268;
    }
    // 0x80804254: nop

    // 0x80804258: beq         $v0, $at, L_808042A8
    if (ctx->r2 == ctx->r1) {
        // 0x8080425C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808042A8;
    }
    // 0x8080425C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804260: b           L_808042EC
    // 0x80804264: nop

        goto L_808042EC;
    // 0x80804264: nop

L_80804268:
    // 0x80804268: jal         0x8008CABC
    // 0x8080426C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080426C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80804270: jal         0x8008B324
    // 0x80804274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_1;
    // 0x80804274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80804278: beq         $v0, $zero, L_808042EC
    if (ctx->r2 == 0) {
        // 0x8080427C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808042EC;
    }
    // 0x8080427C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80804284: jal         0x80085338
    // 0x80804288: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    _batimer_set(rdram, ctx);
        goto after_2;
    // 0x80804288: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_2:
    // 0x8080428C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80804294: jal         0x800A38F0
    // 0x80804298: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_3;
    // 0x80804298: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8080429C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808042A0: b           L_808042EC
    // 0x808042A4: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_808042EC;
    // 0x808042A4: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_808042A8:
    // 0x808042A8: jal         0x800852F0
    // 0x808042AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_4;
    // 0x808042AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808042B0: beq         $v0, $zero, L_808042EC
    if (ctx->r2 == 0) {
        // 0x808042B4: nop
    
            goto L_808042EC;
    }
    // 0x808042B4: nop

    // 0x808042B8: jal         0x800D3948
    // 0x808042BC: nop

    func_800D3948(rdram, ctx);
        goto after_5;
    // 0x808042BC: nop

    after_5:
    // 0x808042C0: beq         $v0, $zero, L_808042DC
    if (ctx->r2 == 0) {
        // 0x808042C4: addiu       $a0, $zero, 0x2C4
        ctx->r4 = ADD32(0, 0X2C4);
            goto L_808042DC;
    }
    // 0x808042C4: addiu       $a0, $zero, 0x2C4
    ctx->r4 = ADD32(0, 0X2C4);
    // 0x808042C8: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x808042CC: jal         0x80101180
    // 0x808042D0: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x808042D0: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    after_6:
    // 0x808042D4: b           L_808042E8
    // 0x808042D8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
        goto L_808042E8;
    // 0x808042D8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_808042DC:
    // 0x808042DC: jal         0x80085200
    // 0x808042E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x808042E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808042E4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_808042E8:
    // 0x808042E8: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_808042EC:
    // 0x808042EC: jal         0x80809198
    // 0x808042F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809198_bsfirstp(rdram, ctx);
        goto after_8;
    // 0x808042F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808042F4: jal         0x80807D48
    // 0x808042F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x808042F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808042FC: jal         0x80809250
    // 0x80804300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809250_bsfirstp(rdram, ctx);
        goto after_10;
    // 0x80804300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80804304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804308: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080430C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804310: jr          $ra
    // 0x80804314: nop

    return;
    // 0x80804314: nop

;}
RECOMP_FUNC void func_800E7A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7A4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E7A50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7A54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E7A58: jal         0x800E7928
    // 0x800E7A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800E7928(rdram, ctx);
        goto after_0;
    // 0x800E7A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800E7A60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E7A64: jal         0x800E7988
    // 0x800E7A68: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    func_800E7988(rdram, ctx);
        goto after_1;
    // 0x800E7A68: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    after_1:
    // 0x800E7A6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E7A70: jal         0x800E78C8
    // 0x800E7A74: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    func_800E78C8(rdram, ctx);
        goto after_2;
    // 0x800E7A74: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    after_2:
    // 0x800E7A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E7A7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E7A80: sb          $zero, -0x2A5B($at)
    MEM_B(-0X2A5B, ctx->r1) = 0;
    // 0x800E7A84: jr          $ra
    // 0x800E7A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800E7A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void scinfobar_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x808005DC: xori        $t6, $v0, 0x64
    ctx->r14 = ctx->r2 ^ 0X64;
    // 0x808005E0: jr          $ra
    // 0x808005E4: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x808005E4: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_808011AC_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808011B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808011B8: jal         0x8010D600
    // 0x808011BC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D600(rdram, ctx);
        goto after_0;
    // 0x808011BC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808011C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808011C4: jal         0x80102D78
    // 0x808011C8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x808011C8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x808011CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808011D0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808011D4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808011D8: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808011DC: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    // 0x808011E0: jal         0x80102BF8
    // 0x808011E4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_80102BF8(rdram, ctx);
        goto after_2;
    // 0x808011E4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x808011E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808011F0: jr          $ra
    // 0x808011F4: nop

    return;
    // 0x808011F4: nop

;}
RECOMP_FUNC void _bsbanshack_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082700: syscall     8
    recomp_syscall_handler(rdram, ctx, 0x80082700);
    return;
    // 0x80082704: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800E2A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2A3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E2A40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E2A44: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E2A48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E2A4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E2A50: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800E2A54: jal         0x800E1DF4
    // 0x800E2A58: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800E1DF4(rdram, ctx);
        goto after_0;
    // 0x800E2A58: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E2A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2A60: jal         0x800E204C
    // 0x800E2A64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800E204C(rdram, ctx);
        goto after_1;
    // 0x800E2A64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800E2A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2A6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E2A70: jal         0x800E2180
    // 0x800E2A74: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800E2180(rdram, ctx);
        goto after_2;
    // 0x800E2A74: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800E2A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2A7C: jal         0x800E2260
    // 0x800E2A80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800E2260(rdram, ctx);
        goto after_3;
    // 0x800E2A80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800E2A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2A88: jal         0x800E22F0
    // 0x800E2A8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800E22F0(rdram, ctx);
        goto after_4;
    // 0x800E2A8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800E2A90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E2A94: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E2A98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E2A9C: jr          $ra
    // 0x800E2AA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800E2AA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8009EAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EAE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EAEC: jr          $ra
    // 0x8009EAF0: sh          $a0, 0x707C($at)
    MEM_H(0X707C, ctx->r1) = ctx->r4;
    return;
    // 0x8009EAF0: sh          $a0, 0x707C($at)
    MEM_H(0X707C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800018_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800028: jal         0x80100094
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800030: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800034: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800040: jal         0x80800FE0
    // 0x80800044: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    func_80800FE0_chstonepillar(rdram, ctx);
        goto after_1;
    // 0x80800044: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_1:
    // 0x80800048: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8080004C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800050: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800054: lh          $t9, 0x2C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2C);
    // 0x80800058: beq         $t9, $at, L_80800070
    if (ctx->r25 == ctx->r1) {
        // 0x8080005C: nop
    
            goto L_80800070;
    }
    // 0x8080005C: nop

    // 0x80800060: jal         0x800D0B68
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800068: beq         $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
        // 0x8080006C: nop
    
            goto L_8080009C;
    }
    // 0x8080006C: nop

L_80800070:
    // 0x80800070: jal         0x80088840
    // 0x80800074: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_3:
    // 0x80800078: beq         $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x8080007C: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_808001E8;
    }
    // 0x8080007C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800080: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800084: bne         $t0, $at, L_808001E8
    if (ctx->r8 != ctx->r1) {
        // 0x80800088: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E8;
    }
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x80800ADC
    // 0x80800090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800ADC_chstonepillar(rdram, ctx);
        goto after_4;
    // 0x80800090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800094: b           L_808001EC
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001EC;
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080009C:
    // 0x8080009C: jal         0x800DA298
    // 0x808000A0: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808000A0: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    after_5:
    // 0x808000A4: bnel        $v0, $zero, L_808000BC
    if (ctx->r2 != 0) {
        // 0x808000A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000BC;
    }
    goto skip_0;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808000AC: jal         0x8080112C
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080112C_chstonepillar(rdram, ctx);
        goto after_6;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000B4: beq         $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x808000B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E8;
    }
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000BC:
    // 0x808000BC: jal         0x80801374
    // 0x808000C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801374_chstonepillar(rdram, ctx);
        goto after_7;
    // 0x808000C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808000C4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808000C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000CC: srl         $t1, $v0, 10
    ctx->r9 = S32(U32(ctx->r2) >> 10);
    // 0x808000D0: beq         $t1, $at, L_808000F0
    if (ctx->r9 == ctx->r1) {
        // 0x808000D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000F0;
    }
    // 0x808000D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000D8: beq         $t1, $at, L_808001B0
    if (ctx->r9 == ctx->r1) {
        // 0x808000DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808001B0;
    }
    // 0x808000DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000E0: beq         $t1, $at, L_808001D0
    if (ctx->r9 == ctx->r1) {
        // 0x808000E4: nop
    
            goto L_808001D0;
    }
    // 0x808000E4: nop

    // 0x808000E8: b           L_808001EC
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001EC;
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F0:
    // 0x808000F0: jal         0x800DA298
    // 0x808000F4: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x808000F4: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    after_8:
    // 0x808000F8: beq         $v0, $zero, L_8080017C
    if (ctx->r2 == 0) {
        // 0x808000FC: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_8080017C;
    }
    // 0x808000FC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80800100: lh          $t3, 0x2C($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2C);
    // 0x80800104: bne         $t3, $zero, L_8080017C
    if (ctx->r11 != 0) {
        // 0x80800108: nop
    
            goto L_8080017C;
    }
    // 0x80800108: nop

    // 0x8080010C: jal         0x80801174
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801174_chstonepillar(rdram, ctx);
        goto after_9;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800114: jal         0x80800B58
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B58_chstonepillar(rdram, ctx);
        goto after_10;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080011C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800120: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800124: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80800128: addiu       $a0, $zero, 0x9D7
    ctx->r4 = ADD32(0, 0X9D7);
    // 0x8080012C: jal         0x800DA524
    // 0x80800130: swc1        $f4, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f4.u32l;
    func_800DA524(rdram, ctx);
        goto after_11;
    // 0x80800130: swc1        $f4, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f4.u32l;
    after_11:
    // 0x80800134: jal         0x800DA298
    // 0x80800138: addiu       $a0, $zero, 0x9D9
    ctx->r4 = ADD32(0, 0X9D9);
    func_800DA298(rdram, ctx);
        goto after_12;
    // 0x80800138: addiu       $a0, $zero, 0x9D9
    ctx->r4 = ADD32(0, 0X9D9);
    after_12:
    // 0x8080013C: bne         $v0, $zero, L_808001E8
    if (ctx->r2 != 0) {
        // 0x80800140: addiu       $a3, $zero, 0x810
        ctx->r7 = ADD32(0, 0X810);
            goto L_808001E8;
    }
    // 0x80800140: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    // 0x80800144: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80800148: jal         0x80088840
    // 0x8080014C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_13;
    // 0x8080014C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_13:
    // 0x80800150: beq         $v0, $zero, L_8080015C
    if (ctx->r2 == 0) {
        // 0x80800154: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_8080015C;
    }
    // 0x80800154: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800158: addiu       $a3, $zero, 0x910
    ctx->r7 = ADD32(0, 0X910);
L_8080015C:
    // 0x8080015C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800164: jal         0x80085708
    // 0x80800168: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    _capod_entrypoint_13(rdram, ctx);
        goto after_14;
    // 0x80800168: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_14:
    // 0x8080016C: jal         0x800DA544
    // 0x80800170: addiu       $a0, $zero, 0x9D9
    ctx->r4 = ADD32(0, 0X9D9);
    func_800DA544(rdram, ctx);
        goto after_15;
    // 0x80800170: addiu       $a0, $zero, 0x9D9
    ctx->r4 = ADD32(0, 0X9D9);
    after_15:
    // 0x80800174: b           L_808001EC
    // 0x80800178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001EC;
    // 0x80800178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080017C:
    // 0x8080017C: jal         0x80800474
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800474_chstonepillar(rdram, ctx);
        goto after_16;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800184: beq         $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x80800188: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808001E8;
    }
    // 0x80800188: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080018C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800198: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080019C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001A0: jal         0x808011CC
    // 0x808001A4: nop

    func_808011CC_chstonepillar(rdram, ctx);
        goto after_17;
    // 0x808001A4: nop

    after_17:
    // 0x808001A8: b           L_808001EC
    // 0x808001AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001EC;
    // 0x808001AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001B0:
    // 0x808001B0: jal         0x80801238
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801238_chstonepillar(rdram, ctx);
        goto after_18;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808001B8: bne         $v0, $zero, L_808001E8
    if (ctx->r2 != 0) {
        // 0x808001BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E8;
    }
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: jal         0x80101FDC
    // 0x808001C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x808001C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_19:
    // 0x808001C8: b           L_808001EC
    // 0x808001CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001EC;
    // 0x808001CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001D0:
    // 0x808001D0: jal         0x80800870
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800870_chstonepillar(rdram, ctx);
        goto after_20;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808001D8: bne         $v0, $zero, L_808001E8
    if (ctx->r2 != 0) {
        // 0x808001DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E8;
    }
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: jal         0x80800ADC
    // 0x808001E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800ADC_chstonepillar(rdram, ctx);
        goto after_21;
    // 0x808001E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
L_808001E8:
    // 0x808001E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001EC:
    // 0x808001EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
RECOMP_FUNC void func_808010DC_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010E4: addiu       $a0, $zero, 0x175
    ctx->r4 = ADD32(0, 0X175);
    // 0x808010E8: jal         0x800DA564
    // 0x808010EC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x808010EC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x808010F0: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x808010F4: beq         $t6, $zero, L_80801100
    if (ctx->r14 == 0) {
        // 0x808010F8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80801100;
    }
    // 0x808010F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808010FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80801100:
    // 0x80801100: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x80801104: beq         $t7, $zero, L_80801110
    if (ctx->r15 == 0) {
        // 0x80801108: andi        $t8, $v0, 0x4
        ctx->r24 = ctx->r2 & 0X4;
            goto L_80801110;
    }
    // 0x80801108: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8080110C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80801110:
    // 0x80801110: beq         $t8, $zero, L_8080111C
    if (ctx->r24 == 0) {
        // 0x80801114: andi        $t9, $v0, 0x8
        ctx->r25 = ctx->r2 & 0X8;
            goto L_8080111C;
    }
    // 0x80801114: andi        $t9, $v0, 0x8
    ctx->r25 = ctx->r2 & 0X8;
    // 0x80801118: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8080111C:
    // 0x8080111C: beq         $t9, $zero, L_80801128
    if (ctx->r25 == 0) {
        // 0x80801120: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801128;
    }
    // 0x80801120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801124: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80801128:
    // 0x80801128: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8080112C: subu        $v0, $t0, $v1
    ctx->r2 = SUB32(ctx->r8, ctx->r3);
    // 0x80801130: jr          $ra
    // 0x80801134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80801134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800FA240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA240: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FA244: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FA248: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800FA24C: addiu       $t7, $t7, 0x3880
    ctx->r15 = ADD32(ctx->r15, 0X3880);
    // 0x800FA250: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FA254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FA258: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800FA25C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FA260: beq         $a1, $zero, L_800FA27C
    if (ctx->r5 == 0) {
        // 0x800FA264: sb          $a1, 0x10($v0)
        MEM_B(0X10, ctx->r2) = ctx->r5;
            goto L_800FA27C;
    }
    // 0x800FA264: sb          $a1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r5;
    // 0x800FA268: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800FA26C: beql        $a1, $at, L_800FA29C
    if (ctx->r5 == ctx->r1) {
        // 0x800FA270: lbu         $t9, 0xC($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0XC);
            goto L_800FA29C;
    }
    goto skip_0;
    // 0x800FA270: lbu         $t9, 0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XC);
    skip_0:
    // 0x800FA274: b           L_800FA2B4
    // 0x800FA278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FA2B4;
    // 0x800FA278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FA27C:
    // 0x800FA27C: lbu         $t8, 0xC($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XC);
    // 0x800FA280: beql        $t8, $zero, L_800FA2B4
    if (ctx->r24 == 0) {
        // 0x800FA284: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FA2B4;
    }
    goto skip_1;
    // 0x800FA284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800FA288: jal         0x800FA130
    // 0x800FA28C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800FA130(rdram, ctx);
        goto after_0;
    // 0x800FA28C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x800FA290: b           L_800FA2B4
    // 0x800FA294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FA2B4;
    // 0x800FA294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FA298: lbu         $t9, 0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XC);
L_800FA29C:
    // 0x800FA29C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800FA2A0: beql        $t9, $at, L_800FA2B4
    if (ctx->r25 == ctx->r1) {
        // 0x800FA2A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FA2B4;
    }
    goto skip_2;
    // 0x800FA2A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800FA2A8: jal         0x800FA130
    // 0x800FA2AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800FA130(rdram, ctx);
        goto after_1;
    // 0x800FA2AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800FA2B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FA2B4:
    // 0x800FA2B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FA2B8: jr          $ra
    // 0x800FA2BC: nop

    return;
    // 0x800FA2BC: nop

;}
RECOMP_FUNC void subaddielink_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: beq         $a1, $zero, L_8080002C
    if (ctx->r5 == 0) {
        // 0x80800014: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8080002C;
    }
    // 0x80800014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800018: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x8080001C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80800020: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80800024: b           L_80800034
    // 0x80800028: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
        goto L_80800034;
    // 0x80800028: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
L_8080002C:
    // 0x8080002C: jal         0x80800000
    // 0x80800030: nop

    subaddielink_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800030: nop

    after_0:
L_80800034:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_80800720_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800720: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800728: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080072C: jal         0x800839E8
    // 0x80800730: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800730: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800734: beq         $v0, $zero, L_80800740
    if (ctx->r2 == 0) {
        // 0x80800738: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800740;
    }
    // 0x80800738: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080073C: addiu       $a1, $zero, 0x16F
    ctx->r5 = ADD32(0, 0X16F);
L_80800740:
    // 0x80800740: jal         0x8009E5C8
    // 0x80800744: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80800744: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080074C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800750: jr          $ra
    // 0x80800754: nop

    return;
    // 0x80800754: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D4C: jal         0x80800060
    // 0x80800D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800060_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x80800D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D5C: jal         0x80800B38
    // 0x80800D60: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_80800B38_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x80800D60: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80800D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D6C: jr          $ra
    // 0x80800D70: nop

    return;
    // 0x80800D70: nop

;}
RECOMP_FUNC void func_808002FC_chklungospiral(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800300: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800304: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800308: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080030C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800310: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800314: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800318: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080031C: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800320: beq         $t6, $zero, L_80800344
    if (ctx->r14 == 0) {
        // 0x80800324: addiu       $a1, $zero, 0xC
        ctx->r5 = ADD32(0, 0XC);
            goto L_80800344;
    }
    // 0x80800324: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800328: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080032C: beq         $t6, $at, L_8080034C
    if (ctx->r14 == ctx->r1) {
        // 0x80800330: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080034C;
    }
    // 0x80800330: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800334: beql        $t6, $at, L_80800390
    if (ctx->r14 == ctx->r1) {
        // 0x80800338: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800390;
    }
    goto skip_0;
    // 0x80800338: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080033C: b           L_8080039C
    // 0x80800340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080039C;
    // 0x80800340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800344:
    // 0x80800344: jal         0x800856B0
    // 0x80800348: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800348: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_8080034C:
    // 0x8080034C: jal         0x800856E0
    // 0x80800350: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800350: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800354: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800358: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1468, 0X5F0) << 16);
    // 0x8080035C: addiu       $a0, $a0, 0x5F0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1468, 0X5F0));
    // 0x80800360: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800364: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80800368: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
    // 0x8080036C: jal         0x80088090
    // 0x80800370: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800370: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80800374: jal         0x80088098
    // 0x80800378: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800378: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x8080037C: jal         0x800880A0
    // 0x80800380: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800380: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x80800384: jal         0x800880B8
    // 0x80800388: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800388: nop

    after_5:
    // 0x8080038C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80800390:
    // 0x80800390: jal         0x800856D8
    // 0x80800394: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800394: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080039C:
    // 0x8080039C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003A4: jr          $ra
    // 0x808003A8: nop

    return;
    // 0x808003A8: nop

;}
RECOMP_FUNC void _fxstep_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889E8: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x800889E8);
    return;
    // 0x800889EC: xori        $t0, $zero, 0x4
    ctx->r8 = 0 ^ 0X4;
;}
RECOMP_FUNC void func_800E86DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E86DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E86E0: lw          $a0, -0x2A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A00);
    // 0x800E86E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E86E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E86EC: beql        $a0, $zero, L_800E8708
    if (ctx->r4 == 0) {
        // 0x800E86F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E8708;
    }
    goto skip_0;
    // 0x800E86F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E86F4: jal         0x800B3248
    // 0x800E86F8: nop

    freelist_free(rdram, ctx);
        goto after_0;
    // 0x800E86F8: nop

    after_0:
    // 0x800E86FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E8700: sw          $zero, -0x2A00($at)
    MEM_W(-0X2A00, ctx->r1) = 0;
    // 0x800E8704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E8708:
    // 0x800E8708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E870C: jr          $ra
    // 0x800E8710: nop

    return;
    // 0x800E8710: nop

;}
RECOMP_FUNC void bareact_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8010A63C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A63C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8010A640: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8010A644: lbu         $t8, 0xB($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XB);
    // 0x8010A648: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8010A64C: jr          $ra
    // 0x8010A650: sb          $t9, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r25;
    return;
    // 0x8010A650: sb          $t9, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_80800704_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800704: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800708: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x8080070C: jr          $ra
    // 0x80800710: swc1        $f12, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800710: swc1        $f12, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80117448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117448: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8011744C: sw          $zero, 0x7388($at)
    MEM_W(0X7388, ctx->r1) = 0;
    // 0x80117450: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80117454: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80117458: sltu        $at, $s5, $t0
    ctx->r1 = ctx->r21 < ctx->r8 ? 1 : 0;
    // 0x8011745C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80117460: beq         $at, $zero, L_80117470
    if (ctx->r1 == 0) {
        // 0x80117464: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80117470;
    }
    // 0x80117464: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80117468: jal         0x80116F30
    // 0x8011746C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80116F30(rdram, ctx);
        goto after_0;
    // 0x8011746C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_0:
L_80117470:
    // 0x80117470: andi        $s0, $s6, 0x1
    ctx->r16 = ctx->r22 & 0X1;
    // 0x80117474: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x80117478: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x8011747C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80117480: sltu        $at, $s5, $t0
    ctx->r1 = ctx->r21 < ctx->r8 ? 1 : 0;
    // 0x80117484: beql        $at, $zero, L_80117498
    if (ctx->r1 == 0) {
        // 0x80117488: andi        $t1, $s6, 0x3
        ctx->r9 = ctx->r22 & 0X3;
            goto L_80117498;
    }
    goto skip_0;
    // 0x80117488: andi        $t1, $s6, 0x3
    ctx->r9 = ctx->r22 & 0X3;
    skip_0:
    // 0x8011748C: jal         0x80116F30
    // 0x80117490: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80116F30(rdram, ctx);
        goto after_1;
    // 0x80117490: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x80117494: andi        $t1, $s6, 0x3
    ctx->r9 = ctx->r22 & 0X3;
L_80117498:
    // 0x80117498: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8011749C: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x801174A0: beq         $t1, $at, L_801174D4
    if (ctx->r9 == ctx->r1) {
        // 0x801174A4: sub         $s5, $s5, $t0
        ctx->r21 = SUB32(ctx->r21, ctx->r8);
            goto L_801174D4;
    }
    // 0x801174A4: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x801174A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801174AC: beq         $t1, $at, L_801174C4
    if (ctx->r9 == ctx->r1) {
        // 0x801174B0: nop
    
            goto L_801174C4;
    }
    // 0x801174B0: nop

    // 0x801174B4: jal         0x8011797C
    // 0x801174B8: nop

    func_8011797C(rdram, ctx);
        goto after_2;
    // 0x801174B8: nop

    after_2:
    // 0x801174BC: j           L_801174DC
    // 0x801174C0: nop

        goto L_801174DC;
    // 0x801174C0: nop

L_801174C4:
    // 0x801174C4: jal         0x80117824
    // 0x801174C8: nop

    func_80117824(rdram, ctx);
        goto after_3;
    // 0x801174C8: nop

    after_3:
    // 0x801174CC: j           L_801174DC
    // 0x801174D0: nop

        goto L_801174DC;
    // 0x801174D0: nop

L_801174D4:
    // 0x801174D4: jal         0x801174F4
    // 0x801174D8: nop

    func_801174F4(rdram, ctx);
        goto after_4;
    // 0x801174D8: nop

    after_4:
L_801174DC:
    // 0x801174DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801174E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801174E4: sub         $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x801174E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801174EC: jr          $ra
    // 0x801174F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801174F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80807698_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807698: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080769C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808076A0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808076A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808076A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808076AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808076B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808076B4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808076B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808076BC: jal         0x80100094
    // 0x808076C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808076C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808076C4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808076C8: jal         0x80802228
    // 0x808076CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x808076CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808076D0: beq         $s1, $zero, L_808076E0
    if (ctx->r17 == 0) {
        // 0x808076D4: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_808076E0;
    }
    // 0x808076D4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808076D8: b           L_808076FC
    // 0x808076DC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_808076FC;
    // 0x808076DC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_808076E0:
    // 0x808076E0: lbu         $t6, 0xA3($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0XA3);
    // 0x808076E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808076E8: beq         $t6, $zero, L_808076F8
    if (ctx->r14 == 0) {
        // 0x808076EC: nop
    
            goto L_808076F8;
    }
    // 0x808076EC: nop

    // 0x808076F0: b           L_808076F8
    // 0x808076F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808076F8;
    // 0x808076F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808076F8:
    // 0x808076F8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_808076FC:
    // 0x808076FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80807700: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80807704: lbu         $t7, 0xA2($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0XA2);
L_80807708:
    // 0x80807708: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080770C: sllv        $t9, $t8, $s0
    ctx->r25 = S32(ctx->r24 << (ctx->r16 & 31));
    // 0x80807710: and         $t0, $t7, $t9
    ctx->r8 = ctx->r15 & ctx->r25;
    // 0x80807714: beq         $t0, $zero, L_80807728
    if (ctx->r8 == 0) {
        // 0x80807718: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80807728;
    }
    // 0x80807718: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080771C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80807720: jal         0x80805448
    // 0x80807724: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80807724: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
L_80807728:
    // 0x80807728: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080772C: bnel        $s0, $s1, L_80807708
    if (ctx->r16 != ctx->r17) {
        // 0x80807730: lbu         $t7, 0xA2($s3)
        ctx->r15 = MEM_BU(ctx->r19, 0XA2);
            goto L_80807708;
    }
    goto skip_0;
    // 0x80807730: lbu         $t7, 0xA2($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0XA2);
    skip_0:
    // 0x80807734: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80807738: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080773C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80807740: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80807744: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80807748: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8080774C: jr          $ra
    // 0x80807750: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80807750: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800850_cheggclockwork(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800850: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800858: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080085C: jal         0x80100094
    // 0x80800860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800864: jal         0x8001B798
    // 0x80800868: lh          $a0, 0x2C($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2C);
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x80800868: lh          $a0, 0x2C($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2C);
    after_1:
    // 0x8080086C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800870: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x80800874: jal         0x800EE7F8
    // 0x80800878: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800878: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    after_2:
    // 0x8080087C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800880: jal         0x800EE7F8
    // 0x80800884: addiu       $a0, $a1, 0xC
    ctx->r4 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800884: addiu       $a0, $a1, 0xC
    ctx->r4 = ADD32(ctx->r5, 0XC);
    after_3:
    // 0x80800888: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080088C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800890: jal         0x800EE7F8
    // 0x80800894: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800894: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x80800898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080089C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008A0: jr          $ra
    // 0x808008A4: nop

    return;
    // 0x808008A4: nop

    // 0x808008A8: nop

    // 0x808008AC: nop

;}
RECOMP_FUNC void func_800A50B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A50B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A50B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A50B8: jal         0x8008FFE8
    // 0x800A50BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x800A50BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A50C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A50C4: jal         0x8010F9C0
    // 0x800A50C8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_8010F9C0(rdram, ctx);
        goto after_1;
    // 0x800A50C8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A50CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A50D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A50D4: jr          $ra
    // 0x800A50D8: nop

    return;
    // 0x800A50D8: nop

;}
RECOMP_FUNC void func_800C8800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8804: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C8808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C880C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C8810: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8814: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8818: jal         0x800B28CC
    // 0x800C881C: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C881C: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x800C8820: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8824: jal         0x800EE88C
    // 0x800C8828: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x800C8828: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800C882C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8834: jr          $ra
    // 0x800C8838: nop

    return;
    // 0x800C8838: nop

;}
RECOMP_FUNC void bsmum_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800170: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800174: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800178: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080017C: jal         0x8009E74C
    // 0x80800180: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800180: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80800184: bne         $v0, $zero, L_808001CC
    if (ctx->r2 != 0) {
        // 0x80800188: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001CC;
    }
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800190: jal         0x800947EC
    // 0x80800194: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_1;
    // 0x80800194: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800198: jal         0x8009E474
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_2;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001A0: jal         0x8009F1E0
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_3;
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x80093230
    // 0x808001B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80093230(rdram, ctx);
        goto after_4;
    // 0x808001B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: jal         0x80084F28
    // 0x808001BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bamum_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808001BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: jal         0x80092864
    // 0x808001C8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_6;
    // 0x808001C8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
L_808001CC:
    // 0x808001CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void func_80800D14_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800D20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800D24: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800D28: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80800D2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D30: beql        $t6, $zero, L_80800DB8
    if (ctx->r14 == 0) {
        // 0x80800D34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800DB8;
    }
    goto skip_0;
    // 0x80800D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800D38: jal         0x800F54E4
    // 0x80800D3C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800D3C: nop

    after_0:
    // 0x80800D40: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800D44: jal         0x80106790
    // 0x80800D48: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800D48: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80800D4C: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800D50: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800D54: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800D58: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800D5C: jal         0x800EE7F8
    // 0x80800D60: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800D60: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x80800D64: jal         0x80103014
    // 0x80800D68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80103014(rdram, ctx);
        goto after_3;
    // 0x80800D68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D70: jal         0x8008A4B0
    // 0x80800D74: lhu         $a1, 0x7C($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X7C);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800D74: lhu         $a1, 0x7C($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X7C);
    after_4:
    // 0x80800D78: jal         0x800F6C88
    // 0x80800D7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F6C88(rdram, ctx);
        goto after_5;
    // 0x80800D7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800D80: beq         $v0, $zero, L_80800DB4
    if (ctx->r2 == 0) {
        // 0x80800D84: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800DB4;
    }
    // 0x80800D84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D88: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80800D8C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800D90: jal         0x800F4F34
    // 0x80800D94: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    func_800F4F34(rdram, ctx);
        goto after_6;
    // 0x80800D94: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_6:
    // 0x80800D98: beq         $v0, $zero, L_80800DB4
    if (ctx->r2 == 0) {
        // 0x80800D9C: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800DB4;
    }
    // 0x80800D9C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DA0: beq         $t7, $zero, L_80800DB4
    if (ctx->r15 == 0) {
        // 0x80800DA4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800DB4;
    }
    // 0x80800DA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800DA8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800DAC: jal         0x800F76B0
    // 0x80800DB0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    func_800F76B0(rdram, ctx);
        goto after_7;
    // 0x80800DB0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    after_7:
L_80800DB4:
    // 0x80800DB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800DB8:
    // 0x80800DB8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800DBC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800DC0: jr          $ra
    // 0x80800DC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800DC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800BF0E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF0E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800BF0E4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800BF0E8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800BF0EC: addiu       $s0, $s0, -0x7A50
    ctx->r16 = ADD32(ctx->r16, -0X7A50);
    // 0x800BF0F0: lbu         $t6, 0x77($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X77);
    // 0x800BF0F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BF0F8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800BF0FC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800BF100: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800BF104: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800BF108: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF10C: beq         $t6, $zero, L_800BF144
    if (ctx->r14 == 0) {
        // 0x800BF110: sw          $zero, 0x1B0($s0)
        MEM_W(0X1B0, ctx->r16) = 0;
            goto L_800BF144;
    }
    // 0x800BF110: sw          $zero, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = 0;
    // 0x800BF114: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800BF118: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800BF11C: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800BF120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BF124: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800BF128: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF12C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800BF130: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800BF134: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800BF138: jal         0x80087FB8
    // 0x800BF13C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    _gcmapsects_entrypoint_23(rdram, ctx);
        goto after_0;
    // 0x800BF13C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x800BF140: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800BF144:
    // 0x800BF144: bne         $v1, $zero, L_800BF198
    if (ctx->r3 != 0) {
        // 0x800BF148: nop
    
            goto L_800BF198;
    }
    // 0x800BF148: nop

    // 0x800BF14C: lbu         $t0, 0x2A($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X2A);
    // 0x800BF150: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800BF154: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF158: beq         $t0, $zero, L_800BF198
    if (ctx->r8 == 0) {
        // 0x800BF15C: lwc1        $f4, 0x40($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
            goto L_800BF198;
    }
    // 0x800BF15C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800BF160: lbu         $t1, 0x29($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X29);
    // 0x800BF164: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800BF168: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800BF16C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800BF170: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800BF174: lw          $a1, 0x10($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X10);
    // 0x800BF178: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800BF17C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800BF180: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800BF184: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800BF188: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800BF18C: jal         0x800AC638
    // 0x800BF190: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_800AC638(rdram, ctx);
        goto after_1;
    // 0x800BF190: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_1:
    // 0x800BF194: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800BF198:
    // 0x800BF198: beql        $v1, $zero, L_800BF1AC
    if (ctx->r3 == 0) {
        // 0x800BF19C: lbu         $t8, 0x56($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X56);
            goto L_800BF1AC;
    }
    goto skip_0;
    // 0x800BF19C: lbu         $t8, 0x56($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X56);
    skip_0:
    // 0x800BF1A0: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800BF1A4: sw          $t7, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r15;
    // 0x800BF1A8: lbu         $t8, 0x56($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X56);
L_800BF1AC:
    // 0x800BF1AC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800BF1B0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF1B4: bne         $t8, $zero, L_800BF1C4
    if (ctx->r24 != 0) {
        // 0x800BF1B8: lwc1        $f6, 0x40($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
            goto L_800BF1C4;
    }
    // 0x800BF1B8: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800BF1BC: b           L_800BF214
    // 0x800BF1C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800BF214;
    // 0x800BF1C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800BF1C4:
    // 0x800BF1C4: lbu         $t9, 0x55($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X55);
    // 0x800BF1C8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800BF1CC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800BF1D0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800BF1D4: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800BF1D8: lw          $a1, 0x3C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X3C);
    // 0x800BF1DC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800BF1E0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800BF1E4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800BF1E8: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x800BF1EC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800BF1F0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800BF1F4: jal         0x800AC638
    // 0x800BF1F8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    func_800AC638(rdram, ctx);
        goto after_2;
    // 0x800BF1F8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    after_2:
    // 0x800BF1FC: beq         $v0, $zero, L_800BF210
    if (ctx->r2 == 0) {
        // 0x800BF200: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_800BF210;
    }
    // 0x800BF200: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800BF204: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x800BF208: b           L_800BF214
    // 0x800BF20C: sw          $t5, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r13;
        goto L_800BF214;
    // 0x800BF20C: sw          $t5, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r13;
L_800BF210:
    // 0x800BF210: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800BF214:
    // 0x800BF214: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF218: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800BF21C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800BF220: jr          $ra
    // 0x800BF224: nop

    return;
    // 0x800BF224: nop

;}
RECOMP_FUNC void func_8001207C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001207C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80012080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012084: jal         0x800D5E74
    // 0x80012088: nop

    func_800D5E74(rdram, ctx);
        goto after_0;
    // 0x80012088: nop

    after_0:
    // 0x8001208C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80012094: jr          $ra
    // 0x80012098: nop

    return;
    // 0x80012098: nop

;}
RECOMP_FUNC void func_80800BC0_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BC8: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800BCC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800BD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800BD4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800BD8: beql        $t7, $zero, L_80800BFC
    if (ctx->r15 == 0) {
        // 0x80800BDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800BFC;
    }
    goto skip_0;
    // 0x80800BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800BE0: jal         0x800856B8
    // 0x80800BE4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800BE4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800BE8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800BEC: lhu         $t8, 0x6E($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6E);
    // 0x80800BF0: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800BF4: sh          $t9, 0x6E($a1)
    MEM_H(0X6E, ctx->r5) = ctx->r25;
    // 0x80800BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BFC:
    // 0x80800BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C00: jr          $ra
    // 0x80800C04: nop

    return;
    // 0x80800C04: nop

;}
RECOMP_FUNC void _sumumbofx_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898E8: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898E8);
    return;
    // 0x800898EC: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void bamovethrust_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800064: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800068: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8080006C: swc1        $f0, 0x8C($t6)
    MEM_W(0X8C, ctx->r14) = ctx->f0.u32l;
    // 0x80800070: lw          $t7, 0xC8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC8);
    // 0x80800074: swc1        $f0, 0x84($t7)
    MEM_W(0X84, ctx->r15) = ctx->f0.u32l;
    // 0x80800078: lw          $t8, 0xC8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC8);
    // 0x8080007C: jr          $ra
    // 0x80800080: swc1        $f0, 0x88($t8)
    MEM_W(0X88, ctx->r24) = ctx->f0.u32l;
    return;
    // 0x80800080: swc1        $f0, 0x88($t8)
    MEM_W(0X88, ctx->r24) = ctx->f0.u32l;
;}
RECOMP_FUNC void bafpctrl_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C1C: jr          $ra
    // 0x80800C20: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800C20: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _fxegg_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A80: syscall     719
    recomp_syscall_handler(rdram, ctx, 0x80088A80);
    return;
    // 0x80088A84: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800DAC50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAC50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DAC54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DAC58: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DAC5C: lw          $a1, -0x3890($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3890);
    // 0x800DAC60: jal         0x8001BBA0
    // 0x800DAC64: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    rare_memcpy(rdram, ctx);
        goto after_0;
    // 0x800DAC64: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    after_0:
    // 0x800DAC68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DAC6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DAC70: jr          $ra
    // 0x800DAC74: nop

    return;
    // 0x800DAC74: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836B0: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836B0);
    return;
    // 0x800836B4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_808010C8_subaddiedialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808010D4: bgez        $a1, L_808010F8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x808010D8: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_808010F8;
    }
    // 0x808010D8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808010DC: negu        $t8, $a3
    ctx->r24 = SUB32(0, ctx->r7);
    // 0x808010E0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x808010E4: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x808010E8: or          $a2, $t7, $t9
    ctx->r6 = ctx->r15 | ctx->r25;
    // 0x808010EC: jal         0x8010108C
    // 0x808010F0: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    func_8010108C(rdram, ctx);
        goto after_0;
    // 0x808010F0: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    after_0:
    // 0x808010F4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_808010F8:
    // 0x808010F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801100: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80801104: jr          $ra
    // 0x80801108: nop

    return;
    // 0x80801108: nop

;}
