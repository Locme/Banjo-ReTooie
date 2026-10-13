#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsbeggass_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828E8: syscall     18
    recomp_syscall_handler(rdram, ctx, 0x800828E8);
    return;
    // 0x800828EC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800BFFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFFA0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BFFA4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BFFA8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800BFFAC: jr          $ra
    // 0x800BFFB0: lw          $v0, -0x7888($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7888);
    return;
    // 0x800BFFB0: lw          $v0, -0x7888($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7888);
;}
RECOMP_FUNC void _bsbfly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082968: syscall     22
    recomp_syscall_handler(rdram, ctx, 0x80082968);
    return;
    // 0x8008296C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chjigsaw_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(704, 0X770) << 16);
    // 0x808006C4: jr          $ra
    // 0x808006C8: addiu       $v0, $v0, 0x770
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(704, 0X770));
    return;
    // 0x808006C8: addiu       $v0, $v0, 0x770
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(704, 0X770));
;}
RECOMP_FUNC void _bssnowball_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A20: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A20);
    return;
    // 0x80083A24: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void yaw_rotateTimed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C9C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009C9CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C9D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009C9D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8009C9D8: lw          $v0, 0xF8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C9DC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009C9E0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009C9E4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009C9E8: jal         0x800F2100
    // 0x8009C9EC: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x8009C9EC: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8009C9F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009C9F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009C9F8: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8009C9FC: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009CA00: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8009CA04: nop

    // 0x8009CA08: bc1f        L_8009CA44
    if (!c1cs) {
        // 0x8009CA0C: nop
    
            goto L_8009CA44;
    }
    // 0x8009CA0C: nop

    // 0x8009CA10: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009CA14: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8009CA18: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8009CA1C: nop

    // 0x8009CA20: bc1fl       L_8009CA3C
    if (!c1cs) {
        // 0x8009CA24: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8009CA3C;
    }
    goto skip_0;
    // 0x8009CA24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8009CA28: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009CA2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009CA30: b           L_8009CA44
    // 0x8009CA34: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
        goto L_8009CA44;
    // 0x8009CA34: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8009CA38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8009CA3C:
    // 0x8009CA3C: nop

    // 0x8009CA40: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
L_8009CA44:
    // 0x8009CA44: jal         0x800F2100
    // 0x8009CA48: div.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f16.fl);
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x8009CA48: div.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f16.fl);
    after_1:
    // 0x8009CA4C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8009CA50: lw          $t8, 0xF8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XF8);
    // 0x8009CA54: swc1        $f0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f0.u32l;
    // 0x8009CA58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CA5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009CA60: jr          $ra
    // 0x8009CA64: nop

    return;
    // 0x8009CA64: nop

;}
RECOMP_FUNC void _gccubeDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C68: syscall     655
    recomp_syscall_handler(rdram, ctx, 0x80087C68);
    return;
    // 0x80087C6C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8009ACF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ACF4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009ACF8: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x8009ACFC: jr          $ra
    // 0x8009AD00: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009AD00: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800610_chflowerbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080061C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800620: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80800624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800628: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x8080062C: bgez        $t9, L_8080063C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800630: nop
    
            goto L_8080063C;
    }
    // 0x80800630: nop

    // 0x80800634: b           L_8080063C
    // 0x80800638: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8080063C;
    // 0x80800638: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080063C:
    // 0x8080063C: jal         0x800DF744
    // 0x80800640: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80800640: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800644: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080064C: lw          $t1, 0x64($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X64);
    // 0x80800650: sll         $t3, $t1, 11
    ctx->r11 = S32(ctx->r9 << 11);
    // 0x80800654: bgez        $t3, L_80800664
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800658: nop
    
            goto L_80800664;
    }
    // 0x80800658: nop

    // 0x8080065C: b           L_80800664
    // 0x80800660: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80800664;
    // 0x80800660: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800664:
    // 0x80800664: jal         0x800DF744
    // 0x80800668: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800668: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x8080066C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800670: jal         0x800DF744
    // 0x80800674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800678: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080067C: jal         0x800DF744
    // 0x80800680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800684: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800688: jal         0x80101870
    // 0x8080068C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_4;
    // 0x8080068C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80800690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800698: jr          $ra
    // 0x8080069C: nop

    return;
    // 0x8080069C: nop

;}
RECOMP_FUNC void func_800A4CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4CF0: jal         0x800A4C48
    // 0x800A4CF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A4C48(rdram, ctx);
        goto after_0;
    // 0x800A4CF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A4CF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A4CFC: jal         0x800CA7E4
    // 0x800A4D00: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800CA7E4(rdram, ctx);
        goto after_1;
    // 0x800A4D00: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800A4D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4D0C: jr          $ra
    // 0x800A4D10: nop

    return;
    // 0x800A4D10: nop

;}
RECOMP_FUNC void _chlavafall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086830: syscall     385
    recomp_syscall_handler(rdram, ctx, 0x80086830);
    return;
    // 0x80086834: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800EB350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EB354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EB358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EB35C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EB360: jal         0x80103328
    // 0x800EB364: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80103328(rdram, ctx);
        goto after_0;
    // 0x800EB364: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EB368: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800EB36C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EB370: lhu         $t6, 0x6A($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X6A);
    // 0x800EB374: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x800EB378: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800EB37C: bgez        $t6, L_800EB390
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800EB380: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800EB390;
    }
    // 0x800EB380: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EB384: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EB388: nop

    // 0x800EB38C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800EB390:
    // 0x800EB390: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800EB394: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EB398: lwc1        $f18, 0x5E5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5E5C);
    // 0x800EB39C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800EB3A0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800EB3A4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800EB3A8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800EB3AC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800EB3B0: jal         0x800AAEF4
    // 0x800EB3B4: nop

    func_800AAEF4(rdram, ctx);
        goto after_1;
    // 0x800EB3B4: nop

    after_1:
    // 0x800EB3B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EB3BC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800EB3C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800EB3C4: jr          $ra
    // 0x800EB3C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EB3C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EB3CC: nop

;}
RECOMP_FUNC void func_800173B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800173B0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800173B4: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800173B8: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800173BC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800173C0: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x800173C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800173C8: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800173CC: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800173D0: addiu       $t0, $t0, -0x6060
    ctx->r8 = ADD32(ctx->r8, -0X6060);
    // 0x800173D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800173D8: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800173DC: lh          $t1, 0x26C($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X26C);
    // 0x800173E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800173E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800173E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800173EC: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
    // 0x800173F0: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x800173F4: sb          $v1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r3;
    // 0x800173F8: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x800173FC: jr          $ra
    // 0x80017400: sh          $t1, 0x26E($v0)
    MEM_H(0X26E, ctx->r2) = ctx->r9;
    return;
    // 0x80017400: sh          $t1, 0x26E($v0)
    MEM_H(0X26E, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void gspropsDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808000A4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808000A8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808000AC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808000B0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808000B4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x808000B8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808000C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000C4: blez        $a1, L_808001E0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x808000C8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_808001E0;
    }
    // 0x808000C8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_808000CC:
    // 0x808000CC: blez        $s3, L_808001D0
    if (SIGNED(ctx->r19) <= 0) {
        // 0x808000D0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_808001D0;
    }
    // 0x808000D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000D4: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x808000D8: andi        $v0, $s3, 0x3
    ctx->r2 = ctx->r19 & 0X3;
    // 0x808000DC: beq         $v0, $zero, L_80800124
    if (ctx->r2 == 0) {
        // 0x808000E0: addu        $s0, $s1, $t6
        ctx->r16 = ADD32(ctx->r17, ctx->r14);
            goto L_80800124;
    }
    // 0x808000E0: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
    // 0x808000E4: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x808000E8: addu        $a0, $s1, $t7
    ctx->r4 = ADD32(ctx->r17, ctx->r15);
    // 0x808000EC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_808000F0:
    // 0x808000F0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x808000F4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x808000F8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x808000FC: lhu         $t8, 0x8($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X8);
    // 0x80800100: lhu         $t9, 0x8($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X8);
    // 0x80800104: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x80800108: beq         $at, $zero, L_80800118
    if (ctx->r1 == 0) {
        // 0x8080010C: nop
    
            goto L_80800118;
    }
    // 0x8080010C: nop

    // 0x80800110: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80800114: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
L_80800118:
    // 0x80800118: bne         $a3, $a2, L_808000F0
    if (ctx->r7 != ctx->r6) {
        // 0x8080011C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_808000F0;
    }
    // 0x8080011C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800120: beq         $a2, $s3, L_808001D0
    if (ctx->r6 == ctx->r19) {
        // 0x80800124: sll         $t0, $a2, 2
        ctx->r8 = S32(ctx->r6 << 2);
            goto L_808001D0;
    }
L_80800124:
    // 0x80800124: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80800128: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x8080012C: addu        $a3, $t1, $s1
    ctx->r7 = ADD32(ctx->r9, ctx->r17);
    // 0x80800130: addu        $a0, $s1, $t0
    ctx->r4 = ADD32(ctx->r17, ctx->r8);
    // 0x80800134: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80800138:
    // 0x80800138: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8080013C: lhu         $a2, 0x8($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X8);
    // 0x80800140: lhu         $t2, 0x8($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X8);
    // 0x80800144: sltu        $at, $a2, $t2
    ctx->r1 = ctx->r6 < ctx->r10 ? 1 : 0;
    // 0x80800148: beql        $at, $zero, L_80800164
    if (ctx->r1 == 0) {
        // 0x8080014C: lw          $a1, 0x4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X4);
            goto L_80800164;
    }
    goto skip_0;
    // 0x8080014C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x80800150: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80800154: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // 0x80800158: lhu         $a2, 0x8($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X8);
    // 0x8080015C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800160: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
L_80800164:
    // 0x80800164: lhu         $t3, 0x8($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X8);
    // 0x80800168: sltu        $at, $a2, $t3
    ctx->r1 = ctx->r6 < ctx->r11 ? 1 : 0;
    // 0x8080016C: beql        $at, $zero, L_80800188
    if (ctx->r1 == 0) {
        // 0x80800170: lw          $a1, 0x8($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X8);
            goto L_80800188;
    }
    goto skip_1;
    // 0x80800170: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x80800174: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80800178: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // 0x8080017C: lhu         $a2, 0x8($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X8);
    // 0x80800180: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800184: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
L_80800188:
    // 0x80800188: lhu         $t4, 0x8($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0X8);
    // 0x8080018C: sltu        $at, $a2, $t4
    ctx->r1 = ctx->r6 < ctx->r12 ? 1 : 0;
    // 0x80800190: beql        $at, $zero, L_808001AC
    if (ctx->r1 == 0) {
        // 0x80800194: lw          $a1, 0xC($a0)
        ctx->r5 = MEM_W(ctx->r4, 0XC);
            goto L_808001AC;
    }
    goto skip_2;
    // 0x80800194: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    skip_2:
    // 0x80800198: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x8080019C: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // 0x808001A0: lhu         $a2, 0x8($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X8);
    // 0x808001A4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x808001A8: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
L_808001AC:
    // 0x808001AC: lhu         $t5, 0x8($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X8);
    // 0x808001B0: sltu        $at, $a2, $t5
    ctx->r1 = ctx->r6 < ctx->r13 ? 1 : 0;
    // 0x808001B4: beql        $at, $zero, L_808001C8
    if (ctx->r1 == 0) {
        // 0x808001B8: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_808001C8;
    }
    goto skip_3;
    // 0x808001B8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    skip_3:
    // 0x808001BC: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x808001C0: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // 0x808001C4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_808001C8:
    // 0x808001C8: bnel        $a0, $a3, L_80800138
    if (ctx->r4 != ctx->r7) {
        // 0x808001CC: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_80800138;
    }
    goto skip_4;
    // 0x808001CC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_4:
L_808001D0:
    // 0x808001D0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x808001D4: bne         $s3, $s4, L_808000CC
    if (ctx->r19 != ctx->r20) {
        // 0x808001D8: nop
    
            goto L_808000CC;
    }
    // 0x808001D8: nop

    // 0x808001DC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_808001E0:
    // 0x808001E0: blez        $s4, L_80800284
    if (SIGNED(ctx->r20) <= 0) {
        // 0x808001E4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80800284;
    }
    // 0x808001E4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_808001E8:
    // 0x808001E8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x808001EC: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808001F0: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x808001F4: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x808001F8: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x808001FC: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80800200: lh          $t8, 0x4($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4);
    // 0x80800204: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x80800208: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x8080020C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80800210: lhu         $a0, 0x8($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X8);
    // 0x80800214: sll         $t0, $v0, 11
    ctx->r8 = S32(ctx->r2 << 11);
    // 0x80800218: srl         $t1, $t0, 21
    ctx->r9 = S32(U32(ctx->r8) >> 21);
    // 0x8080021C: srl         $t9, $a2, 23
    ctx->r25 = S32(U32(ctx->r6) >> 23);
    // 0x80800220: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80800224: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800228: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8080022C: jal         0x80108DC0
    // 0x80800230: srl         $a3, $v0, 21
    ctx->r7 = S32(U32(ctx->r2) >> 21);
    func_80108DC0(rdram, ctx);
        goto after_0;
    // 0x80800230: srl         $a3, $v0, 21
    ctx->r7 = S32(U32(ctx->r2) >> 21);
    after_0:
    // 0x80800234: beq         $v0, $zero, L_80800278
    if (ctx->r2 == 0) {
        // 0x80800238: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800278;
    }
    // 0x80800238: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080023C: lhu         $t2, 0x6($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X6);
    // 0x80800240: lhu         $t6, 0x76($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X76);
    // 0x80800244: lbu         $t0, 0x7B($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X7B);
    // 0x80800248: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x8080024C: sll         $t5, $t3, 7
    ctx->r13 = S32(ctx->r11 << 7);
    // 0x80800250: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x80800254: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80800258: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x8080025C: sh          $t8, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r24;
    // 0x80800260: sb          $t1, 0x7B($v0)
    MEM_B(0X7B, ctx->r2) = ctx->r9;
    // 0x80800264: jal         0x80088C50
    // 0x80800268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _gspropmarker_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8080026C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800270: jal         0x80102FDC
    // 0x80800274: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x80800274: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
L_80800278:
    // 0x80800278: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8080027C: bne         $s3, $s4, L_808001E8
    if (ctx->r19 != ctx->r20) {
        // 0x80800280: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808001E8;
    }
    // 0x80800280: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80800284:
    // 0x80800284: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800288: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080028C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800290: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800294: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800298: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8080029C: jr          $ra
    // 0x808002A0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x808002A0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void bababykaz_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80800214: jr          $ra
    // 0x80800218: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    return;
    // 0x80800218: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void fxsplash25d_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8080002C
    // 0x8080000C: nop

    func_8080002C_fxsplash25d(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800014: jal         0x800BA22C
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_1;
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void chattract_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(812, 0X4F4) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x4F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(812, 0X4F4));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x4F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(812, 0X4F4));
;}
RECOMP_FUNC void func_808004AC_chgoldfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004B0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808004B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808004BC: beq         $a1, $at, L_808004EC
    if (ctx->r5 == ctx->r1) {
        // 0x808004C0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808004EC;
    }
    // 0x808004C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808004C4: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x808004C8: beq         $a1, $at, L_80800548
    if (ctx->r5 == ctx->r1) {
        // 0x808004CC: lh          $v1, 0x20($sp)
        ctx->r3 = MEM_H(ctx->r29, 0X20);
            goto L_80800548;
    }
    // 0x808004CC: lh          $v1, 0x20($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X20);
    // 0x808004D0: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x808004D4: beq         $a1, $at, L_80800594
    if (ctx->r5 == ctx->r1) {
        // 0x808004D8: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800594;
    }
    // 0x808004D8: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808004DC: beq         $a1, $at, L_80800580
    if (ctx->r5 == ctx->r1) {
        // 0x808004E0: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(2312, 0XD3C) << 16);
            goto L_80800580;
    }
    // 0x808004E0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2312, 0XD3C) << 16);
    // 0x808004E4: b           L_808005E0
    // 0x808004E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005E0;
    // 0x808004E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004EC:
    // 0x808004EC: lh          $v1, 0x20($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X20);
    // 0x808004F0: addiu       $at, $zero, 0x15BF
    ctx->r1 = ADD32(0, 0X15BF);
    // 0x808004F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004F8: beq         $v1, $at, L_80800510
    if (ctx->r3 == ctx->r1) {
        // 0x808004FC: addiu       $at, $zero, 0x15C0
        ctx->r1 = ADD32(0, 0X15C0);
            goto L_80800510;
    }
    // 0x808004FC: addiu       $at, $zero, 0x15C0
    ctx->r1 = ADD32(0, 0X15C0);
    // 0x80800500: beq         $v1, $at, L_80800520
    if (ctx->r3 == ctx->r1) {
        // 0x80800504: addiu       $a0, $zero, 0x648
        ctx->r4 = ADD32(0, 0X648);
            goto L_80800520;
    }
    // 0x80800504: addiu       $a0, $zero, 0x648
    ctx->r4 = ADD32(0, 0X648);
    // 0x80800508: b           L_808005E0
    // 0x8080050C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005E0;
    // 0x8080050C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800510:
    // 0x80800510: jal         0x808005F0
    // 0x80800514: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_0;
    // 0x80800514: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800518: b           L_808005E0
    // 0x8080051C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005E0;
    // 0x8080051C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800520:
    // 0x80800520: jal         0x800DA298
    // 0x80800524: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800524: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800528: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x8080052C: jal         0x800C7074
    // 0x80800530: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    func_800C7074(rdram, ctx);
        goto after_2;
    // 0x80800530: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    after_2:
    // 0x80800534: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800538: jal         0x808005F0
    // 0x8080053C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_3;
    // 0x8080053C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x80800540: b           L_808005E0
    // 0x80800544: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005E0;
    // 0x80800544: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800548:
    // 0x80800548: addiu       $at, $zero, 0x15C0
    ctx->r1 = ADD32(0, 0X15C0);
    // 0x8080054C: bne         $v1, $at, L_80800578
    if (ctx->r3 != ctx->r1) {
        // 0x80800550: lh          $t6, 0x22($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X22);
            goto L_80800578;
    }
    // 0x80800550: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x80800554: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800558: bne         $t6, $at, L_80800578
    if (ctx->r14 != ctx->r1) {
        // 0x8080055C: nop
    
            goto L_80800578;
    }
    // 0x8080055C: nop

    // 0x80800560: jal         0x800DA298
    // 0x80800564: addiu       $a0, $zero, 0x649
    ctx->r4 = ADD32(0, 0X649);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800564: addiu       $a0, $zero, 0x649
    ctx->r4 = ADD32(0, 0X649);
    after_4:
    // 0x80800568: beq         $v0, $zero, L_80800578
    if (ctx->r2 == 0) {
        // 0x8080056C: nop
    
            goto L_80800578;
    }
    // 0x8080056C: nop

    // 0x80800570: jal         0x800CF700
    // 0x80800574: nop

    func_800CF700(rdram, ctx);
        goto after_5;
    // 0x80800574: nop

    after_5:
L_80800578:
    // 0x80800578: b           L_808005E0
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005E0;
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800580:
    // 0x80800580: addiu       $a0, $a0, 0xD3C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2312, 0XD3C));
    // 0x80800584: jal         0x80088090
    // 0x80800588: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800588: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_6:
    // 0x8080058C: b           L_808005E0
    // 0x80800590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005E0;
    // 0x80800590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800594:
    // 0x80800594: lhu         $v0, 0x72($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X72);
    // 0x80800598: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080059C: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x808005A0: beq         $t7, $at, L_808005B0
    if (ctx->r15 == ctx->r1) {
        // 0x808005A4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808005B0;
    }
    // 0x808005A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808005A8: bne         $t7, $at, L_808005D8
    if (ctx->r15 != ctx->r1) {
        // 0x808005AC: nop
    
            goto L_808005D8;
    }
    // 0x808005AC: nop

L_808005B0:
    // 0x808005B0: jal         0x800F54E4
    // 0x808005B4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x808005B4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_7:
    // 0x808005B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005BC: jal         0x800F64A4
    // 0x808005C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_8;
    // 0x808005C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808005C4: beq         $v0, $zero, L_808005D8
    if (ctx->r2 == 0) {
        // 0x808005C8: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_808005D8;
    }
    // 0x808005C8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808005CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808005D0: jal         0x808005F0
    // 0x808005D4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_9;
    // 0x808005D4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
L_808005D8:
    // 0x808005D8: b           L_808005E0
    // 0x808005DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005E0;
    // 0x808005DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005E0:
    // 0x808005E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005E8: jr          $ra
    // 0x808005EC: nop

    return;
    // 0x808005EC: nop

;}
RECOMP_FUNC void func_80800B5C_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B64: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800B68: jal         0x80085300
    // 0x80800B6C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _batimer_get(rdram, ctx);
        goto after_0;
    // 0x80800B6C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800B70: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800B74: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800B78: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800B7C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800B80: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B84: jal         0x800F10B4
    // 0x80800B88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800B88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800B8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B94: jr          $ra
    // 0x80800B98: nop

    return;
    // 0x80800B98: nop

;}
RECOMP_FUNC void func_8009E6C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E6C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E6C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E6CC: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E6D0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8009E6D4: jal         0x8009CA70
    // 0x8009E6D8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8009CA70(rdram, ctx);
        goto after_0;
    // 0x8009E6D8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8009E6DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E6E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E6E4: jr          $ra
    // 0x8009E6E8: nop

    return;
    // 0x8009E6E8: nop

;}
RECOMP_FUNC void func_808000FC_chclimbbase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800104: jal         0x80088240
    // 0x80800108: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    _gclevel_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800108: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_0:
    // 0x8080010C: beq         $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x80800110: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080011C;
    }
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800114: b           L_80800120
    // 0x80800118: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800120;
    // 0x80800118: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8080011C:
    // 0x8080011C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800120:
    // 0x80800120: jr          $ra
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chweather_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859F8: syscall     185
    recomp_syscall_handler(rdram, ctx, 0x800859F8);
    return;
    // 0x800859FC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void gcmapsects_lagoontop_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080010C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800110: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800114: jal         0x800E39A8
    // 0x80800118: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800E39A8(rdram, ctx);
        goto after_0;
    // 0x80800118: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8080011C: jal         0x80013728
    // 0x80800120: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x80800120: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800124: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800128: jal         0x800136E4
    // 0x8080012C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x8080012C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800130: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80800134: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800138: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080013C: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x80800140: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2614, 0X600) << 16);
    // 0x80800144: lw          $t6, 0xA4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA4);
    // 0x80800148: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8080014C: beql        $t7, $zero, L_80800200
    if (ctx->r15 == 0) {
        // 0x80800150: lw          $t6, 0x4C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X4C);
            goto L_80800200;
    }
    goto skip_0;
    // 0x80800150: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    skip_0:
    // 0x80800154: lwc1        $f6, 0x600($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2614, 0X600));
    // 0x80800158: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2614, 0X604) << 16);
    // 0x8080015C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800160: nop

    // 0x80800164: bc1f        L_8080018C
    if (!c1cs) {
        // 0x80800168: nop
    
            goto L_8080018C;
    }
    // 0x80800168: nop

    // 0x8080016C: lbu         $t8, 0xA4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XA4);
    // 0x80800170: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x80800174: sb          $t9, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = ctx->r25;
    // 0x80800178: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x8080017C: lbu         $t0, 0xA4($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XA4);
    // 0x80800180: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x80800184: sb          $t1, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = ctx->r9;
    // 0x80800188: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
L_8080018C:
    // 0x8080018C: lwc1        $f8, 0x604($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2614, 0X604));
    // 0x80800190: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800194: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x80800198: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080019C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808001A0: nop

    // 0x808001A4: bc1fl       L_80800200
    if (!c1cs) {
        // 0x808001A8: lw          $t6, 0x4C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X4C);
            goto L_80800200;
    }
    goto skip_1;
    // 0x808001A8: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    skip_1:
    // 0x808001AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001B0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x808001B4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808001B8: nop

    // 0x808001BC: bc1fl       L_80800200
    if (!c1cs) {
        // 0x808001C0: lw          $t6, 0x4C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X4C);
            goto L_80800200;
    }
    goto skip_2;
    // 0x808001C0: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    skip_2:
    // 0x808001C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001C8: nop

    // 0x808001CC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x808001D0: nop

    // 0x808001D4: bc1fl       L_80800200
    if (!c1cs) {
        // 0x808001D8: lw          $t6, 0x4C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X4C);
            goto L_80800200;
    }
    goto skip_3;
    // 0x808001D8: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    skip_3:
    // 0x808001DC: lbu         $t2, 0xA4($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XA4);
    // 0x808001E0: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x808001E4: sb          $t3, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = ctx->r11;
    // 0x808001E8: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x808001EC: lbu         $t4, 0xA4($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XA4);
    // 0x808001F0: andi        $t5, $t4, 0xFFBF
    ctx->r13 = ctx->r12 & 0XFFBF;
    // 0x808001F4: sb          $t5, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = ctx->r13;
    // 0x808001F8: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x808001FC: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
L_80800200:
    // 0x80800200: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800204: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2614, 0X608) << 16);
    // 0x80800208: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8080020C: beql        $t7, $zero, L_808002AC
    if (ctx->r15 == 0) {
        // 0x80800210: lw          $v0, 0x68($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X68);
            goto L_808002AC;
    }
    goto skip_4;
    // 0x80800210: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    skip_4:
    // 0x80800214: lwc1        $f8, 0x608($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2614, 0X608));
    // 0x80800218: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080021C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2614, 0X60C) << 16);
    // 0x80800220: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800224: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800228: bc1f        L_80800258
    if (!c1cs) {
        // 0x8080022C: nop
    
            goto L_80800258;
    }
    // 0x8080022C: nop

    // 0x80800230: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800234: nop

    // 0x80800238: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8080023C: nop

    // 0x80800240: bc1f        L_80800258
    if (!c1cs) {
        // 0x80800244: nop
    
            goto L_80800258;
    }
    // 0x80800244: nop

    // 0x80800248: lbu         $t8, 0x4C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4C);
    // 0x8080024C: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x80800250: b           L_808002A8
    // 0x80800254: sb          $t9, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r25;
        goto L_808002A8;
    // 0x80800254: sb          $t9, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r25;
L_80800258:
    // 0x80800258: lwc1        $f4, 0x60C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2614, 0X60C));
    // 0x8080025C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2614, 0X720) << 16);
    // 0x80800260: lui         $a1, 0x449C
    ctx->r5 = S32(0X449C << 16);
    // 0x80800264: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800268: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x8080026C: addiu       $a0, $a0, 0x720
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2614, 0X720));
    // 0x80800270: bc1fl       L_808002AC
    if (!c1cs) {
        // 0x80800274: lw          $v0, 0x68($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X68);
            goto L_808002AC;
    }
    goto skip_5;
    // 0x80800274: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    skip_5:
    // 0x80800278: jal         0x800E3E8C
    // 0x8080027C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800E3E8C(rdram, ctx);
        goto after_3;
    // 0x8080027C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800280: bne         $v0, $zero, L_808002A8
    if (ctx->r2 != 0) {
        // 0x80800284: lw          $a2, 0x40($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X40);
            goto L_808002A8;
    }
    // 0x80800284: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80800288: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x8080028C: lbu         $t0, 0x4C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X4C);
    // 0x80800290: andi        $t1, $t0, 0xFF7F
    ctx->r9 = ctx->r8 & 0XFF7F;
    // 0x80800294: sb          $t1, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r9;
    // 0x80800298: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x8080029C: lbu         $t2, 0x4C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4C);
    // 0x808002A0: andi        $t3, $t2, 0xFFBF
    ctx->r11 = ctx->r10 & 0XFFBF;
    // 0x808002A4: sb          $t3, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r11;
L_808002A8:
    // 0x808002A8: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
L_808002AC:
    // 0x808002AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2614, 0X610) << 16);
    // 0x808002B0: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808002B4: lw          $t4, 0x1AC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1AC);
    // 0x808002B8: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x808002BC: beql        $t5, $zero, L_808002FC
    if (ctx->r13 == 0) {
        // 0x808002C0: lw          $t0, 0xFC($v0)
        ctx->r8 = MEM_W(ctx->r2, 0XFC);
            goto L_808002FC;
    }
    goto skip_6;
    // 0x808002C0: lw          $t0, 0xFC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XFC);
    skip_6:
    // 0x808002C4: lwc1        $f6, 0x610($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2614, 0X610));
    // 0x808002C8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808002CC: nop

    // 0x808002D0: bc1fl       L_808002FC
    if (!c1cs) {
        // 0x808002D4: lw          $t0, 0xFC($v0)
        ctx->r8 = MEM_W(ctx->r2, 0XFC);
            goto L_808002FC;
    }
    goto skip_7;
    // 0x808002D4: lw          $t0, 0xFC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XFC);
    skip_7:
    // 0x808002D8: lbu         $t6, 0x1AC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1AC);
    // 0x808002DC: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x808002E0: sb          $t7, 0x1AC($v0)
    MEM_B(0X1AC, ctx->r2) = ctx->r15;
    // 0x808002E4: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x808002E8: lbu         $t8, 0x1AC($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1AC);
    // 0x808002EC: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x808002F0: sb          $t9, 0x1AC($v0)
    MEM_B(0X1AC, ctx->r2) = ctx->r25;
    // 0x808002F4: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x808002F8: lw          $t0, 0xFC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XFC);
L_808002FC:
    // 0x808002FC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800300: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x80800304: beql        $t1, $zero, L_80800430
    if (ctx->r9 == 0) {
        // 0x80800308: lw          $v1, 0x1AC($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X1AC);
            goto L_80800430;
    }
    goto skip_8;
    // 0x80800308: lw          $v1, 0x1AC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1AC);
    skip_8:
    // 0x8080030C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800310: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80800314: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800318: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8080031C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800320: bc1f        L_8080037C
    if (!c1cs) {
        // 0x80800324: nop
    
            goto L_8080037C;
    }
    // 0x80800324: nop

    // 0x80800328: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080032C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80800330: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800334: nop

    // 0x80800338: bc1f        L_8080037C
    if (!c1cs) {
        // 0x8080033C: nop
    
            goto L_8080037C;
    }
    // 0x8080033C: nop

    // 0x80800340: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800344: nop

    // 0x80800348: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080034C: nop

    // 0x80800350: bc1f        L_8080037C
    if (!c1cs) {
        // 0x80800354: nop
    
            goto L_8080037C;
    }
    // 0x80800354: nop

    // 0x80800358: lbu         $t2, 0xFC($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XFC);
    // 0x8080035C: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x80800360: sb          $t3, 0xFC($v0)
    MEM_B(0XFC, ctx->r2) = ctx->r11;
    // 0x80800364: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x80800368: lbu         $t4, 0xFC($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XFC);
    // 0x8080036C: andi        $t5, $t4, 0xFFBF
    ctx->r13 = ctx->r12 & 0XFFBF;
    // 0x80800370: sb          $t5, 0xFC($v0)
    MEM_B(0XFC, ctx->r2) = ctx->r13;
    // 0x80800374: b           L_8080042C
    // 0x80800378: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
        goto L_8080042C;
    // 0x80800378: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
L_8080037C:
    // 0x8080037C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2614, 0X614) << 16);
    // 0x80800380: lwc1        $f8, 0x614($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2614, 0X614));
    // 0x80800384: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2614, 0X72C) << 16);
    // 0x80800388: addiu       $a0, $a0, 0x72C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2614, 0X72C));
    // 0x8080038C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800390: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800394: bc1f        L_808003D4
    if (!c1cs) {
        // 0x80800398: nop
    
            goto L_808003D4;
    }
    // 0x80800398: nop

    // 0x8080039C: jal         0x800E3E8C
    // 0x808003A0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800E3E8C(rdram, ctx);
        goto after_4;
    // 0x808003A0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_4:
    // 0x808003A4: bne         $v0, $zero, L_808003D4
    if (ctx->r2 != 0) {
        // 0x808003A8: lw          $a2, 0x40($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X40);
            goto L_808003D4;
    }
    // 0x808003A8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x808003AC: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x808003B0: lbu         $t6, 0xFC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XFC);
    // 0x808003B4: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x808003B8: sb          $t7, 0xFC($v0)
    MEM_B(0XFC, ctx->r2) = ctx->r15;
    // 0x808003BC: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x808003C0: lbu         $t8, 0xFC($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XFC);
    // 0x808003C4: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x808003C8: sb          $t9, 0xFC($v0)
    MEM_B(0XFC, ctx->r2) = ctx->r25;
    // 0x808003CC: b           L_8080042C
    // 0x808003D0: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
        goto L_8080042C;
    // 0x808003D0: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
L_808003D4:
    // 0x808003D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2614, 0X618) << 16);
    // 0x808003D8: lwc1        $f16, 0x618($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2614, 0X618));
    // 0x808003DC: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808003E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2614, 0X61C) << 16);
    // 0x808003E4: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x808003E8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808003EC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808003F0: bc1fl       L_80800430
    if (!c1cs) {
        // 0x808003F4: lw          $v1, 0x1AC($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X1AC);
            goto L_80800430;
    }
    goto skip_9;
    // 0x808003F4: lw          $v1, 0x1AC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1AC);
    skip_9:
    // 0x808003F8: lwc1        $f6, 0x61C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2614, 0X61C));
    // 0x808003FC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800400: nop

    // 0x80800404: bc1fl       L_80800430
    if (!c1cs) {
        // 0x80800408: lw          $v1, 0x1AC($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X1AC);
            goto L_80800430;
    }
    goto skip_10;
    // 0x80800408: lw          $v1, 0x1AC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1AC);
    skip_10:
    // 0x8080040C: lbu         $t0, 0xFC($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XFC);
    // 0x80800410: andi        $t1, $t0, 0xFF7F
    ctx->r9 = ctx->r8 & 0XFF7F;
    // 0x80800414: sb          $t1, 0xFC($v0)
    MEM_B(0XFC, ctx->r2) = ctx->r9;
    // 0x80800418: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x8080041C: lbu         $t2, 0xFC($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XFC);
    // 0x80800420: andi        $t3, $t2, 0xFFBF
    ctx->r11 = ctx->r10 & 0XFFBF;
    // 0x80800424: sb          $t3, 0xFC($v0)
    MEM_B(0XFC, ctx->r2) = ctx->r11;
    // 0x80800428: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
L_8080042C:
    // 0x8080042C: lw          $v1, 0x1AC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1AC);
L_80800430:
    // 0x80800430: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80800434: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800438: srl         $t4, $v1, 31
    ctx->r12 = S32(U32(ctx->r3) >> 31);
    // 0x8080043C: beql        $t4, $zero, L_808004F4
    if (ctx->r12 == 0) {
        // 0x80800440: lbu         $v0, 0x7E($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X7E);
            goto L_808004F4;
    }
    goto skip_11;
    // 0x80800440: lbu         $v0, 0x7E($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X7E);
    skip_11:
    // 0x80800444: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800448: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080044C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800450: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800454: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x80800458: bc1f        L_808004B0
    if (!c1cs) {
        // 0x8080045C: nop
    
            goto L_808004B0;
    }
    // 0x8080045C: nop

    // 0x80800460: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800464: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80800468: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8080046C: nop

    // 0x80800470: bc1fl       L_808004F4
    if (!c1cs) {
        // 0x80800474: lbu         $v0, 0x7E($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X7E);
            goto L_808004F4;
    }
    goto skip_12;
    // 0x80800474: lbu         $v0, 0x7E($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X7E);
    skip_12:
    // 0x80800478: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080047C: nop

    // 0x80800480: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800484: nop

    // 0x80800488: bc1fl       L_808004F4
    if (!c1cs) {
        // 0x8080048C: lbu         $v0, 0x7E($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X7E);
            goto L_808004F4;
    }
    goto skip_13;
    // 0x8080048C: lbu         $v0, 0x7E($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X7E);
    skip_13:
    // 0x80800490: lbu         $t5, 0x1AC($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1AC);
    // 0x80800494: andi        $t6, $t5, 0xFF7F
    ctx->r14 = ctx->r13 & 0XFF7F;
    // 0x80800498: sb          $t6, 0x1AC($v0)
    MEM_B(0X1AC, ctx->r2) = ctx->r14;
    // 0x8080049C: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x808004A0: lbu         $t7, 0x1AC($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1AC);
    // 0x808004A4: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x808004A8: b           L_808004F0
    // 0x808004AC: sb          $t8, 0x1AC($v0)
    MEM_B(0X1AC, ctx->r2) = ctx->r24;
        goto L_808004F0;
    // 0x808004AC: sb          $t8, 0x1AC($v0)
    MEM_B(0X1AC, ctx->r2) = ctx->r24;
L_808004B0:
    // 0x808004B0: bltz        $t0, L_808004F0
    if (SIGNED(ctx->r8) < 0) {
        // 0x808004B4: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(2614, 0X738) << 16);
            goto L_808004F0;
    }
    // 0x808004B4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2614, 0X738) << 16);
    // 0x808004B8: addiu       $a0, $a0, 0x738
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2614, 0X738));
    // 0x808004BC: lui         $a1, 0x43E1
    ctx->r5 = S32(0X43E1 << 16);
    // 0x808004C0: jal         0x800E3E8C
    // 0x808004C4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800E3E8C(rdram, ctx);
        goto after_5;
    // 0x808004C4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_5:
    // 0x808004C8: bne         $v0, $zero, L_808004F0
    if (ctx->r2 != 0) {
        // 0x808004CC: lw          $a2, 0x40($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X40);
            goto L_808004F0;
    }
    // 0x808004CC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x808004D0: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x808004D4: lbu         $t1, 0x1AC($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1AC);
    // 0x808004D8: andi        $t2, $t1, 0xFF7F
    ctx->r10 = ctx->r9 & 0XFF7F;
    // 0x808004DC: sb          $t2, 0x1AC($v0)
    MEM_B(0X1AC, ctx->r2) = ctx->r10;
    // 0x808004E0: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x808004E4: lbu         $t3, 0x1AC($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1AC);
    // 0x808004E8: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x808004EC: sb          $t4, 0x1AC($v0)
    MEM_B(0X1AC, ctx->r2) = ctx->r12;
L_808004F0:
    // 0x808004F0: lbu         $v0, 0x7E($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X7E);
L_808004F4:
    // 0x808004F4: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808004F8: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x808004FC: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800500: nop
    
            goto L_80800570;
    }
    // 0x80800500: nop

    // 0x80800504: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800508: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8080050C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800510: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800514: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800518: bc1f        L_80800534
    if (!c1cs) {
        // 0x8080051C: nop
    
            goto L_80800534;
    }
    // 0x8080051C: nop

    // 0x80800520: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800524: nop

    // 0x80800528: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8080052C: nop

    // 0x80800530: bc1t        L_80800568
    if (c1cs) {
        // 0x80800534: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2614, 0X620) << 16);
            goto L_80800568;
    }
L_80800534:
    // 0x80800534: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2614, 0X620) << 16);
    // 0x80800538: lwc1        $f4, 0x620($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2614, 0X620));
    // 0x8080053C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800540: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800544: nop

    // 0x80800548: bc1f        L_80800570
    if (!c1cs) {
        // 0x8080054C: nop
    
            goto L_80800570;
    }
    // 0x8080054C: nop

    // 0x80800550: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800554: nop

    // 0x80800558: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8080055C: nop

    // 0x80800560: bc1f        L_80800570
    if (!c1cs) {
        // 0x80800564: nop
    
            goto L_80800570;
    }
    // 0x80800564: nop

L_80800568:
    // 0x80800568: sb          $zero, 0x7E($a2)
    MEM_B(0X7E, ctx->r6) = 0;
    // 0x8080056C: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
L_80800570:
    // 0x80800570: beq         $v0, $zero, L_808005C4
    if (ctx->r2 == 0) {
        // 0x80800574: lwc1        $f10, 0x38($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
            goto L_808005C4;
    }
    // 0x80800574: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800578: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x8080057C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800580: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800584: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800588: nop

    // 0x8080058C: bc1fl       L_808005C8
    if (!c1cs) {
        // 0x80800590: lw          $v0, 0x68($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X68);
            goto L_808005C8;
    }
    goto skip_14;
    // 0x80800590: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    skip_14:
    // 0x80800594: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800598: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2614, 0X744) << 16);
    // 0x8080059C: lui         $a1, 0x4475
    ctx->r5 = S32(0X4475 << 16);
    // 0x808005A0: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x808005A4: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808005A8: addiu       $a0, $a0, 0x744
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2614, 0X744));
    // 0x808005AC: bc1fl       L_808005C8
    if (!c1cs) {
        // 0x808005B0: lw          $v0, 0x68($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X68);
            goto L_808005C8;
    }
    goto skip_15;
    // 0x808005B0: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    skip_15:
    // 0x808005B4: jal         0x800E3E8C
    // 0x808005B8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800E3E8C(rdram, ctx);
        goto after_6;
    // 0x808005B8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_6:
    // 0x808005BC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x808005C0: sb          $v0, 0x7E($a2)
    MEM_B(0X7E, ctx->r6) = ctx->r2;
L_808005C4:
    // 0x808005C4: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
L_808005C8:
    // 0x808005C8: lw          $t5, 0x4C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4C);
    // 0x808005CC: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x808005D0: bgezl       $t7, L_808005E8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808005D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005E8;
    }
    goto skip_16;
    // 0x808005D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_16:
    // 0x808005D8: lbu         $t9, 0xA4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XA4);
    // 0x808005DC: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x808005E0: sb          $t0, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = ctx->r8;
    // 0x808005E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005E8:
    // 0x808005E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808005EC: jr          $ra
    // 0x808005F0: nop

    return;
    // 0x808005F0: nop

    // 0x808005F4: nop

    // 0x808005F8: nop

    // 0x808005FC: nop

;}
RECOMP_FUNC void _chfactoryposter_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867A8: syscall     374
    recomp_syscall_handler(rdram, ctx, 0x800867A8);
    return;
    // 0x800867AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bastick_resetZones(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F1E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009F1E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009F1E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009F1EC: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x8009F1F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009F1F4: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8009F1F8: jal         0x8009F1C8
    // 0x8009F1FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_0;
    // 0x8009F1FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8009F200: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8009F204: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8009F208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009F20C: jal         0x8009F1C8
    // 0x8009F210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bastick_setZoneMax(rdram, ctx);
        goto after_1;
    // 0x8009F210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8009F214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009F218: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8009F21C: jal         0x8009F1C8
    // 0x8009F220: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_2;
    // 0x8009F220: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_2:
    // 0x8009F224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009F228: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8009F22C: jal         0x8009F1C8
    // 0x8009F230: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_3;
    // 0x8009F230: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_3:
    // 0x8009F234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009F238: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8009F23C: jal         0x8009F1C8
    // 0x8009F240: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x8009F240: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x8009F244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009F248: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009F24C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009F250: jr          $ra
    // 0x8009F254: nop

    return;
    // 0x8009F254: nop

;}
RECOMP_FUNC void rtlight_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800154: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800158: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8080015C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800160: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800164: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800168: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080016C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800170: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800174: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800178: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080017C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80800180: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80800184: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x80800188: lhu         $s1, 0x10($a0)
    ctx->r17 = MEM_HU(ctx->r4, 0X10);
    // 0x8080018C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800190: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800194: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800198: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080019C: sll         $t6, $s1, 5
    ctx->r14 = S32(ctx->r17 << 5);
    // 0x808001A0: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x808001A4: jal         0x8001ACCC
    // 0x808001A8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x808001A8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x808001AC: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x808001B0: lh          $t9, 0x12($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X12);
    // 0x808001B4: sh          $s1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r17;
    // 0x808001B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001BC: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x808001C0: lh          $t2, 0x12($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X12);
    // 0x808001C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001C8: sll         $t3, $s1, 5
    ctx->r11 = S32(ctx->r17 << 5);
    // 0x808001CC: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x808001D0: addu        $a0, $t3, $v0
    ctx->r4 = ADD32(ctx->r11, ctx->r2);
    // 0x808001D4: addiu       $s2, $v0, 0xC
    ctx->r18 = ADD32(ctx->r2, 0XC);
    // 0x808001D8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808001DC: addiu       $s5, $a0, 0xC
    ctx->r21 = ADD32(ctx->r4, 0XC);
    // 0x808001E0: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
    // 0x808001E4: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x808001E8: addiu       $s3, $s0, 0x18
    ctx->r19 = ADD32(ctx->r16, 0X18);
    // 0x808001EC: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
    // 0x808001F0: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808001F4: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x808001F8: addiu       $s7, $sp, 0x4C
    ctx->r23 = ADD32(ctx->r29, 0X4C);
    // 0x808001FC: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80800200: beq         $at, $zero, L_808002B4
    if (ctx->r1 == 0) {
        // 0x80800204: swc1        $f10, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
            goto L_808002B4;
    }
    // 0x80800204: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
L_80800208:
    // 0x80800208: lhu         $t4, 0x2($s3)
    ctx->r12 = MEM_HU(ctx->r19, 0X2);
    // 0x8080020C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800210: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80800214: bne         $t4, $zero, L_80800224
    if (ctx->r12 != 0) {
        // 0x80800218: subu        $a3, $s2, $s4
        ctx->r7 = SUB32(ctx->r18, ctx->r20);
            goto L_80800224;
    }
    // 0x80800218: subu        $a3, $s2, $s4
    ctx->r7 = SUB32(ctx->r18, ctx->r20);
    // 0x8080021C: b           L_808002A4
    // 0x80800220: sb          $s6, 0xF($s2)
    MEM_B(0XF, ctx->r18) = ctx->r22;
        goto L_808002A4;
    // 0x80800220: sb          $s6, 0xF($s2)
    MEM_B(0XF, ctx->r18) = ctx->r22;
L_80800224:
    // 0x80800224: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800228: slti        $at, $v1, 0xF
    ctx->r1 = SIGNED(ctx->r3) < 0XF ? 1 : 0;
    // 0x8080022C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800230: bne         $at, $zero, L_80800224
    if (ctx->r1 != 0) {
        // 0x80800234: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_80800224;
    }
    // 0x80800234: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x80800238: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x8080023C: sra         $a1, $a3, 5
    ctx->r5 = S32(SIGNED(ctx->r7) >> 5);
    // 0x80800240: jal         0x80800000
    // 0x80800244: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_80800000_rtlight(rdram, ctx);
        goto after_1;
    // 0x80800244: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_1:
    // 0x80800248: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080024C: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
L_80800250:
    // 0x80800250: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80800254: lh          $t7, 0x12($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X12);
    // 0x80800258: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080025C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80800260: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800264: mflo        $t6
    ctx->r14 = lo;
    // 0x80800268: addiu       $t8, $t6, -0x14
    ctx->r24 = ADD32(ctx->r14, -0X14);
    // 0x8080026C: sh          $t8, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r24;
    // 0x80800270: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x80800274: lh          $t3, 0x12($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X12);
    // 0x80800278: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8080027C: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800280: mflo        $t4
    ctx->r12 = lo;
    // 0x80800284: addiu       $t5, $t4, 0x14
    ctx->r13 = ADD32(ctx->r12, 0X14);
    // 0x80800288: bne         $v0, $s1, L_80800250
    if (ctx->r2 != ctx->r17) {
        // 0x8080028C: sh          $t5, 0x14($a0)
        MEM_H(0X14, ctx->r4) = ctx->r13;
            goto L_80800250;
    }
    // 0x8080028C: sh          $t5, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r13;
    // 0x80800290: lhu         $t7, 0x0($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X0);
    // 0x80800294: sh          $t7, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r15;
    // 0x80800298: lhu         $t6, 0x2($s3)
    ctx->r14 = MEM_HU(ctx->r19, 0X2);
    // 0x8080029C: sb          $zero, 0xF($s2)
    MEM_B(0XF, ctx->r18) = 0;
    // 0x808002A0: sh          $t6, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r14;
L_808002A4:
    // 0x808002A4: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x808002A8: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
    // 0x808002AC: bne         $at, $zero, L_80800208
    if (ctx->r1 != 0) {
        // 0x808002B0: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80800208;
    }
    // 0x808002B0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_808002B4:
    // 0x808002B4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x808002B8: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x808002BC: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x808002C0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808002C4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808002C8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808002CC: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x808002D0: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x808002D4: jal         0x800B2190
    // 0x808002D8: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    func_800B2190(rdram, ctx);
        goto after_2;
    // 0x808002D8: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    after_2:
    // 0x808002DC: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x808002E0: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x808002E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808002E8: sltu        $at, $s2, $t1
    ctx->r1 = ctx->r18 < ctx->r9 ? 1 : 0;
    // 0x808002EC: beql        $at, $zero, L_8080033C
    if (ctx->r1 == 0) {
        // 0x808002F0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8080033C;
    }
    goto skip_0;
    // 0x808002F0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
L_808002F4:
    // 0x808002F4: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x808002F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002FC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80800300: sh          $t2, -0x6($s1)
    MEM_H(-0X6, ctx->r17) = ctx->r10;
    // 0x80800304: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x80800308: sltu        $at, $s1, $t1
    ctx->r1 = ctx->r17 < ctx->r9 ? 1 : 0;
    // 0x8080030C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800310: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80800314: addu        $a1, $t4, $v0
    ctx->r5 = ADD32(ctx->r12, ctx->r2);
L_80800318:
    // 0x80800318: lbu         $t5, 0xC($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XC);
    // 0x8080031C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800320: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800324: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800328: bne         $v1, $a2, L_80800318
    if (ctx->r3 != ctx->r6) {
        // 0x8080032C: sb          $t5, 0x7($a0)
        MEM_B(0X7, ctx->r4) = ctx->r13;
            goto L_80800318;
    }
    // 0x8080032C: sb          $t5, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r13;
    // 0x80800330: bne         $at, $zero, L_808002F4
    if (ctx->r1 != 0) {
        // 0x80800334: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_808002F4;
    }
    // 0x80800334: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80800338: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8080033C:
    // 0x8080033C: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x80800340: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800344: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800348: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080034C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800350: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800354: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800358: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8080035C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800360: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800364: jr          $ra
    // 0x80800368: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800368: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void bahitspline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: jr          $ra
    // 0x80800120: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800120: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800124: nop

    // 0x80800128: nop

    // 0x8080012C: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_36(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DB8: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DB8);
    return;
    // 0x80087DBC: addi        $t0, $zero, 0x90
    ctx->r8 = ADD32(0, 0X90);
;}
RECOMP_FUNC void func_808000D4_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000E0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000EC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000F0: beq         $t6, $at, L_80800110
    if (ctx->r14 == ctx->r1) {
        // 0x808000F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800110;
    }
    // 0x808000F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000F8: beq         $t6, $at, L_80800134
    if (ctx->r14 == ctx->r1) {
        // 0x808000FC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800134;
    }
    // 0x808000FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800100: beq         $t6, $at, L_8080020C
    if (ctx->r14 == ctx->r1) {
        // 0x80800104: addiu       $t7, $a0, 0x4
        ctx->r15 = ADD32(ctx->r4, 0X4);
            goto L_8080020C;
    }
    // 0x80800104: addiu       $t7, $a0, 0x4
    ctx->r15 = ADD32(ctx->r4, 0X4);
    // 0x80800108: b           L_808002C8
    // 0x8080010C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
        goto L_808002C8;
    // 0x8080010C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_80800110:
    // 0x80800110: jal         0x800DA298
    // 0x80800114: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800114: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    after_0:
    // 0x80800118: bne         $v0, $zero, L_80800128
    if (ctx->r2 != 0) {
        // 0x8080011C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800128;
    }
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x80101FDC
    // 0x80800124: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800124: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
L_80800128:
    // 0x80800128: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    // 0x8080012C: b           L_808002C8
    // 0x80800130: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_808002C8;
    // 0x80800130: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_80800134:
    // 0x80800134: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x80800140: bgezl       $t1, L_80800164
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800144: lui         $a1, 0x3F66
        ctx->r5 = S32(0X3F66 << 16);
            goto L_80800164;
    }
    goto skip_0;
    // 0x80800144: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    skip_0:
    // 0x80800148: jal         0x80101E14
    // 0x8080014C: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x8080014C: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_2:
    // 0x80800150: beql        $v0, $zero, L_80800164
    if (ctx->r2 == 0) {
        // 0x80800154: lui         $a1, 0x3F66
        ctx->r5 = S32(0X3F66 << 16);
            goto L_80800164;
    }
    goto skip_1;
    // 0x80800154: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    skip_1:
    // 0x80800158: jal         0x80800394
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800394_chcrusher(rdram, ctx);
        goto after_3;
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800160: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
L_80800164:
    // 0x80800164: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800168: jal         0x80101E14
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_4;
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800170: beq         $v0, $zero, L_808001B4
    if (ctx->r2 == 0) {
        // 0x80800174: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B4;
    }
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080017C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1624, 0XB30) << 16);
    // 0x80800180: addiu       $a2, $a2, 0xB30
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1624, 0XB30));
    // 0x80800184: jal         0x80089D18
    // 0x80800188: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800188: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_5:
    // 0x8080018C: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800190: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800194: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800198: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x8080019C: jal         0x800E1610
    // 0x808001A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800E1610(rdram, ctx);
        goto after_6;
    // 0x808001A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x808001A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001A8: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    // 0x808001AC: jal         0x80018820
    // 0x808001B0: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    func_80018820(rdram, ctx);
        goto after_7;
    // 0x808001B0: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_7:
L_808001B4:
    // 0x808001B4: lui         $a1, 0x3EF5
    ctx->r5 = S32(0X3EF5 << 16);
    // 0x808001B8: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x808001BC: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x808001C0: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x808001C4: jal         0x80101E14
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001CC: beql        $v0, $zero, L_808002CC
    if (ctx->r2 == 0) {
        // 0x808001D0: lw          $v0, 0x7C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X7C);
            goto L_808002CC;
    }
    goto skip_2;
    // 0x808001D0: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    skip_2:
    // 0x808001D4: jal         0x800DA298
    // 0x808001D8: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808001D8: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    after_9:
    // 0x808001DC: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F8;
    }
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x80101FDC
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808001F0: b           L_808002CC
    // 0x808001F4: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
        goto L_808002CC;
    // 0x808001F4: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
L_808001F8:
    // 0x808001F8: jal         0x80101FDC
    // 0x808001FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x808001FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80800200: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800204: b           L_808002C8
    // 0x80800208: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808002C8;
    // 0x80800208: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_8080020C:
    // 0x8080020C: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800210: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x80800214: jal         0x800D8FF8
    // 0x80800218: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    func_800D8FF8(rdram, ctx);
        goto after_12;
    // 0x80800218: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    after_12:
    // 0x8080021C: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800220: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800224: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80800228: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8080022C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1624, 0XB48) << 16);
    // 0x80800230: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800234: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800238: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8080023C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80800240: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80800244: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x80800248: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8080024C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800250: lwc1        $f18, 0xB48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1624, 0XB48));
    // 0x80800254: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800258: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8080025C: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80800260: nop

    // 0x80800264: bc1fl       L_808002C4
    if (!c1cs) {
        // 0x80800268: addiu       $t1, $s0, 0x4
        ctx->r9 = ADD32(ctx->r16, 0X4);
            goto L_808002C4;
    }
    goto skip_3;
    // 0x80800268: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    skip_3:
    // 0x8080026C: beq         $at, $zero, L_80800288
    if (ctx->r1 == 0) {
        // 0x80800270: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800288;
    }
    // 0x80800270: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800274: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800278: nop

    // 0x8080027C: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80800280: b           L_80800294
    // 0x80800284: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
        goto L_80800294;
    // 0x80800284: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
L_80800288:
    // 0x80800288: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080028C: nop

    // 0x80800290: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
L_80800294:
    // 0x80800294: jal         0x800DA298
    // 0x80800298: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80800298: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    after_13:
    // 0x8080029C: beq         $v0, $zero, L_808002B8
    if (ctx->r2 == 0) {
        // 0x808002A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002B8;
    }
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: jal         0x80101FDC
    // 0x808002AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x808002AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x808002B0: b           L_808002C4
    // 0x808002B4: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
        goto L_808002C4;
    // 0x808002B4: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
L_808002B8:
    // 0x808002B8: jal         0x80101FDC
    // 0x808002BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_15;
    // 0x808002BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x808002C0: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
L_808002C4:
    // 0x808002C4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
L_808002C8:
    // 0x808002C8: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
L_808002CC:
    // 0x808002CC: sll         $t2, $v0, 19
    ctx->r10 = S32(ctx->r2 << 19);
    // 0x808002D0: srl         $v0, $t2, 31
    ctx->r2 = S32(U32(ctx->r10) >> 31);
    // 0x808002D4: beq         $v0, $zero, L_80800314
    if (ctx->r2 == 0) {
        // 0x808002D8: nop
    
            goto L_80800314;
    }
    // 0x808002D8: nop

    // 0x808002DC: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x808002E0: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x808002E4: bltz        $t6, L_80800314
    if (SIGNED(ctx->r14) < 0) {
        // 0x808002E8: nop
    
            goto L_80800314;
    }
    // 0x808002E8: nop

    // 0x808002EC: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x808002F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002F4: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808002F8: bne         $t8, $at, L_80800314
    if (ctx->r24 != ctx->r1) {
        // 0x808002FC: nop
    
            goto L_80800314;
    }
    // 0x808002FC: nop

    // 0x80800300: jal         0x808003E4
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003E4_chcrusher(rdram, ctx);
        goto after_16;
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800308: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8080030C: sll         $t9, $v0, 19
    ctx->r25 = S32(ctx->r2 << 19);
    // 0x80800310: srl         $v0, $t9, 31
    ctx->r2 = S32(U32(ctx->r25) >> 31);
L_80800314:
    // 0x80800314: beql        $v0, $zero, L_80800328
    if (ctx->r2 == 0) {
        // 0x80800318: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80800328;
    }
    goto skip_4;
    // 0x80800318: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_4:
    // 0x8080031C: jal         0x80800508
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800508_chcrusher(rdram, ctx);
        goto after_17;
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800324: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80800328:
    // 0x80800328: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800330: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800334: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800338: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080033C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1624, 0XBE0) << 16);
    // 0x80800340: bc1f        L_8080034C
    if (!c1cs) {
        // 0x80800344: nop
    
            goto L_8080034C;
    }
    // 0x80800344: nop

    // 0x80800348: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8080034C:
    // 0x8080034C: jal         0x80089D50
    // 0x80800350: addiu       $a3, $a3, 0xBE0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1624, 0XBE0));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_18;
    // 0x80800350: addiu       $a3, $a3, 0xBE0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1624, 0XBE0));
    after_18:
    // 0x80800354: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800358: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080035C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800360: nop

    // 0x80800364: bc1fl       L_80800384
    if (!c1cs) {
        // 0x80800368: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800384;
    }
    goto skip_5;
    // 0x80800368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8080036C: jal         0x800D8FF8
    // 0x80800370: nop

    func_800D8FF8(rdram, ctx);
        goto after_19;
    // 0x80800370: nop

    after_19:
    // 0x80800374: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800378: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8080037C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80800380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800384:
    // 0x80800384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800388: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x808000D0: jr          $ra
    // 0x808000D4: sb          $a0, -0x4BF2($at)
    MEM_B(-0X4BF2, ctx->r1) = ctx->r4;
    return;
    // 0x808000D4: sb          $a0, -0x4BF2($at)
    MEM_B(-0X4BF2, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80015D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015D60: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80015D64: lw          $t6, -0x24AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X24AC);
    // 0x80015D68: lui         $t7, 0xE955
    ctx->r15 = S32(0XE955 << 16);
    // 0x80015D6C: ori         $t7, $t7, 0xCCDD
    ctx->r15 = ctx->r15 | 0XCCDD;
    // 0x80015D70: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80015D74: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80015D78: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80015D7C: blez        $a0, L_80015DF4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80015D80: lwc1        $f2, 0x0($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X0);
            goto L_80015DF4;
    }
    // 0x80015D80: lwc1        $f2, 0x0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80015D84: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015D88: beq         $at, $zero, L_80015D98
    if (ctx->r1 == 0) {
        // 0x80015D8C: subu        $t1, $a2, $a1
        ctx->r9 = SUB32(ctx->r6, ctx->r5);
            goto L_80015D98;
    }
    // 0x80015D8C: subu        $t1, $a2, $a1
    ctx->r9 = SUB32(ctx->r6, ctx->r5);
    // 0x80015D90: b           L_80015DB0
    // 0x80015D94: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_80015DB0;
    // 0x80015D94: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80015D98:
    // 0x80015D98: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80015D9C: beq         $at, $zero, L_80015DAC
    if (ctx->r1 == 0) {
        // 0x80015DA0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80015DAC;
    }
    // 0x80015DA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80015DA4: b           L_80015DAC
    // 0x80015DA8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80015DAC;
    // 0x80015DA8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80015DAC:
    // 0x80015DAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80015DB0:
    // 0x80015DB0: subu        $t9, $a0, $a1
    ctx->r25 = SUB32(ctx->r4, ctx->r5);
    // 0x80015DB4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80015DB8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80015DBC: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80015DC0: div         $zero, $t0, $t1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r9)));
    // 0x80015DC4: mflo        $a0
    ctx->r4 = lo;
    // 0x80015DC8: bne         $t1, $zero, L_80015DD4
    if (ctx->r9 != 0) {
        // 0x80015DCC: nop
    
            goto L_80015DD4;
    }
    // 0x80015DCC: nop

    // 0x80015DD0: break       7
    do_break(2147573200);
L_80015DD4:
    // 0x80015DD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80015DD8: bne         $t1, $at, L_80015DEC
    if (ctx->r9 != ctx->r1) {
        // 0x80015DDC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80015DEC;
    }
    // 0x80015DDC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80015DE0: bne         $t0, $at, L_80015DEC
    if (ctx->r8 != ctx->r1) {
        // 0x80015DE4: nop
    
            goto L_80015DEC;
    }
    // 0x80015DE4: nop

    // 0x80015DE8: break       6
    do_break(2147573224);
L_80015DEC:
    // 0x80015DEC: b           L_80015E6C
    // 0x80015DF0: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
        goto L_80015E6C;
    // 0x80015DF0: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
L_80015DF4:
    // 0x80015DF4: bgez        $a0, L_80015E68
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80015DF8: negu        $v0, $a2
        ctx->r2 = SUB32(0, ctx->r6);
            goto L_80015E68;
    }
    // 0x80015DF8: negu        $v0, $a2
    ctx->r2 = SUB32(0, ctx->r6);
    // 0x80015DFC: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015E00: beq         $at, $zero, L_80015E10
    if (ctx->r1 == 0) {
        // 0x80015E04: subu        $t4, $a2, $a1
        ctx->r12 = SUB32(ctx->r6, ctx->r5);
            goto L_80015E10;
    }
    // 0x80015E04: subu        $t4, $a2, $a1
    ctx->r12 = SUB32(ctx->r6, ctx->r5);
    // 0x80015E08: b           L_80015E2C
    // 0x80015E0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80015E2C;
    // 0x80015E0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80015E10:
    // 0x80015E10: negu        $v1, $a1
    ctx->r3 = SUB32(0, ctx->r5);
    // 0x80015E14: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015E18: beq         $at, $zero, L_80015E28
    if (ctx->r1 == 0) {
        // 0x80015E1C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80015E28;
    }
    // 0x80015E1C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80015E20: b           L_80015E28
    // 0x80015E24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80015E28;
    // 0x80015E24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80015E28:
    // 0x80015E28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80015E2C:
    // 0x80015E2C: addu        $t2, $a0, $a1
    ctx->r10 = ADD32(ctx->r4, ctx->r5);
    // 0x80015E30: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80015E34: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80015E38: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80015E3C: div         $zero, $t3, $t4
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r12)));
    // 0x80015E40: mflo        $a0
    ctx->r4 = lo;
    // 0x80015E44: bne         $t4, $zero, L_80015E50
    if (ctx->r12 != 0) {
        // 0x80015E48: nop
    
            goto L_80015E50;
    }
    // 0x80015E48: nop

    // 0x80015E4C: break       7
    do_break(2147573324);
L_80015E50:
    // 0x80015E50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80015E54: bne         $t4, $at, L_80015E68
    if (ctx->r12 != ctx->r1) {
        // 0x80015E58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80015E68;
    }
    // 0x80015E58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80015E5C: bne         $t3, $at, L_80015E68
    if (ctx->r11 != ctx->r1) {
        // 0x80015E60: nop
    
            goto L_80015E68;
    }
    // 0x80015E60: nop

    // 0x80015E64: break       6
    do_break(2147573348);
L_80015E68:
    // 0x80015E68: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
L_80015E6C:
    // 0x80015E6C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80015E70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015E74: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80015E78: jr          $ra
    // 0x80015E7C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80015E7C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_8010A3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A3E8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8010A3EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8010A3F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010A3F4: nop

    // 0x8010A3F8: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8010A3FC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8010A400: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8010A404: jr          $ra
    // 0x8010A408: sh          $t7, 0x92($a0)
    MEM_H(0X92, ctx->r4) = ctx->r15;
    return;
    // 0x8010A408: sh          $t7, 0x92($a0)
    MEM_H(0X92, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80800FB4_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FB4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800FB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800FBC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800FC0: jal         0x80800E98
    // 0x80800FC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800E98_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x80800FC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800FC8: jal         0x80092AD8
    // 0x80800FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092AD8(rdram, ctx);
        goto after_1;
    // 0x80800FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800FD0: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80800FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FD8: jal         0x800E0AF0
    // 0x80800FDC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_2;
    // 0x80800FDC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800FE0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800FE4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800FE8: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x80800FEC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800FF0: lwc1        $f4, 0x174($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X174);
    // 0x80800FF4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800FF8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800FFC: jal         0x800E0AFC
    // 0x80801000: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_3;
    // 0x80801000: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80801004: lui         $a1, 0x38D1
    ctx->r5 = S32(0X38D1 << 16);
    // 0x80801008: ori         $a1, $a1, 0xB717
    ctx->r5 = ctx->r5 | 0XB717;
    // 0x8080100C: jal         0x8008CB10
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801014: bne         $v0, $zero, L_80801028
    if (ctx->r2 != 0) {
        // 0x80801018: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801028;
    }
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080101C: jal         0x8008CB10
    // 0x80801020: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_5;
    // 0x80801020: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_5:
    // 0x80801024: beq         $v0, $zero, L_8080103C
    if (ctx->r2 == 0) {
        // 0x80801028: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080103C;
    }
L_80801028:
    // 0x80801028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080102C: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x80801030: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801034: jal         0x8009DF18
    // 0x80801038: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF18(rdram, ctx);
        goto after_6;
    // 0x80801038: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_6:
L_8080103C:
    // 0x8080103C: jal         0x800D8FF8
    // 0x80801040: nop

    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x80801040: nop

    after_7:
    // 0x80801044: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80801048: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080104C: lwc1        $f6, 0x174($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X174);
    // 0x80801050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801054: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80801058: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x8080105C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801060: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80801064: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80801068: jal         0x80091290
    // 0x8080106C: swc1        $f16, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f16.u32l;
    func_80091290(rdram, ctx);
        goto after_8;
    // 0x8080106C: swc1        $f16, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f16.u32l;
    after_8:
    // 0x80801070: jal         0x80084DD8
    // 0x80801074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80801074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801078: beq         $v0, $zero, L_8080117C
    if (ctx->r2 == 0) {
        // 0x8080107C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080117C;
    }
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801080: jal         0x8009C128
    // 0x80801084: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_10;
    // 0x80801084: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_10:
    // 0x80801088: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080108C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801090: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80801094: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80801098: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8080109C: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808010A0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x808010A4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808010A8: jal         0x800EFA4C
    // 0x808010AC: nop

    func_800EFA4C(rdram, ctx);
        goto after_11;
    // 0x808010AC: nop

    after_11:
    // 0x808010B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808010B8: jal         0x8009FBB0
    // 0x808010BC: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_8009FBB0(rdram, ctx);
        goto after_12;
    // 0x808010BC: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_12:
    // 0x808010C0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(296, 0X1770) << 16);
    // 0x808010C4: addiu       $t6, $t6, 0x1770
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(296, 0X1770));
    // 0x808010C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808010CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010D0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808010D4: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x808010D8: jal         0x800BABB8
    // 0x808010DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_13;
    // 0x808010DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_13:
    // 0x808010E0: jal         0x800F82C0
    // 0x808010E4: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F82C0(rdram, ctx);
        goto after_14;
    // 0x808010E4: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_14:
    // 0x808010E8: jal         0x800F911C
    // 0x808010EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F911C(rdram, ctx);
        goto after_15;
    // 0x808010EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x808010F0: jal         0x800878A0
    // 0x808010F4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x808010F4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_16:
    // 0x808010F8: jal         0x800F53D0
    // 0x808010FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_17;
    // 0x808010FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x80801100: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801104: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801108: jal         0x80084950
    // 0x8080110C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baduo_entrypoint_7(rdram, ctx);
        goto after_18;
    // 0x8080110C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80801110: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801114: jal         0x800A3410
    // 0x80801118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3410(rdram, ctx);
        goto after_19;
    // 0x80801118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x8080111C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801120: jal         0x800A3904
    // 0x80801124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3904(rdram, ctx);
        goto after_20;
    // 0x80801124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x80801128: jal         0x800D5234
    // 0x8080112C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D5234(rdram, ctx);
        goto after_21;
    // 0x8080112C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
    // 0x80801130: jal         0x800A16BC
    // 0x80801134: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A16BC(rdram, ctx);
        goto after_22;
    // 0x80801134: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x80801138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080113C: addiu       $a1, $zero, 0x45A5
    ctx->r5 = ADD32(0, 0X45A5);
    // 0x80801140: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801144: jal         0x8009DB04
    // 0x80801148: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DB04(rdram, ctx);
        goto after_23;
    // 0x80801148: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_23:
    // 0x8080114C: jal         0x8009E6F8
    // 0x80801150: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    bs_getCurrentState(rdram, ctx);
        goto after_24;
    // 0x80801150: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_24:
    // 0x80801154: addiu       $at, $zero, 0xED
    ctx->r1 = ADD32(0, 0XED);
    // 0x80801158: bne         $v0, $at, L_80801174
    if (ctx->r2 != ctx->r1) {
        // 0x8080115C: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80801174;
    }
    // 0x8080115C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801160: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801164: jal         0x8009E5C8
    // 0x80801168: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    bs_setState(rdram, ctx);
        goto after_25;
    // 0x80801168: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    after_25:
    // 0x8080116C: b           L_80801180
    // 0x80801170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801180;
    // 0x80801170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801174:
    // 0x80801174: jal         0x800A0CF4
    // 0x80801178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_26;
    // 0x80801178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
L_8080117C:
    // 0x8080117C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801180:
    // 0x80801180: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801184: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80801188: jr          $ra
    // 0x8080118C: nop

    return;
    // 0x8080118C: nop

;}
RECOMP_FUNC void func_8010410C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010410C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80104110: jr          $ra
    // 0x80104114: addiu       $v0, $v0, 0x6BC0
    ctx->r2 = ADD32(ctx->r2, 0X6BC0);
    return;
    // 0x80104114: addiu       $v0, $v0, 0x6BC0
    ctx->r2 = ADD32(ctx->r2, 0X6BC0);
;}
RECOMP_FUNC void inantab_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800BF744
    // 0x8080000C: nop

    func_800BF744(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800018: jr          $ra
    // 0x8080001C: nop

    return;
    // 0x8080001C: nop

;}
RECOMP_FUNC void func_8080000C_chdinocoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x8008A0F8
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sucoaster_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80800028: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080002C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800030: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800034: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800038: jal         0x80102FDC
    // 0x8080003C: nop

    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x8080003C: nop

    after_1:
    // 0x80800040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800044: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800048: nop

    // 0x8080004C: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x80800050: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void baeggsetup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800030: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800034: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800038: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080003C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800040: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800044: jal         0x800F53D0
    // 0x80800048: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x80800048: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080004C: addiu       $s2, $sp, 0x54
    ctx->r18 = ADD32(ctx->r29, 0X54);
    // 0x80800050: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800054: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800058: jal         0x800EE7F8
    // 0x8080005C: lw          $a1, 0x70($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X70);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080005C: lw          $a1, 0x70($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X70);
    after_1:
    // 0x80800060: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80800064: addiu       $s3, $sp, 0x3C
    ctx->r19 = ADD32(ctx->r29, 0X3C);
    // 0x80800068: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080006C: jal         0x800EE7F8
    // 0x80800070: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800070: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_2:
    // 0x80800074: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80800078: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080007C: jal         0x800EE7F8
    // 0x80800080: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800080: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_3:
    // 0x80800084: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
    // 0x80800088: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x8080008C: lbu         $t7, 0x24($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X24);
    // 0x80800090: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800094: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80800098: beq         $at, $zero, L_80800154
    if (ctx->r1 == 0) {
        // 0x8080009C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800154;
    }
    // 0x8080009C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(504, 0X7E0) << 16);
    // 0x808000A4: addu        $at, $at, $t8
    gpr jr_addend_808000AC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000A8: lw          $t8, 0x7E0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(504, 0X7E0));
    // 0x808000AC: jr          $t8
    // 0x808000B0: nop

    switch (jr_addend_808000AC >> 2) {
        case 0: goto L_808000B4; break;
        case 1: goto L_808000CC; break;
        case 2: goto L_808000E4; break;
        case 3: goto L_808000FC; break;
        case 4: goto L_80800114; break;
        case 5: goto L_80800154; break;
        case 6: goto L_80800144; break;
        default: switch_error(__func__, 0x808000AC, 0x808007E0);
    }
    // 0x808000B0: nop

L_808000B4:
    // 0x808000B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808000BC: jal         0x80087250
    // 0x808000C0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _cheggnormal_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808000C0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_4:
    // 0x808000C4: b           L_80800158
    // 0x808000C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800158;
    // 0x808000C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808000CC:
    // 0x808000CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000D0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808000D4: jal         0x800871E8
    // 0x808000D8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _cheggfire_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808000D8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_5:
    // 0x808000DC: b           L_80800158
    // 0x808000E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800158;
    // 0x808000E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808000E4:
    // 0x808000E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808000EC: jal         0x80087238
    // 0x808000F0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _cheggice_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808000F0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_6:
    // 0x808000F4: b           L_80800158
    // 0x808000F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800158;
    // 0x808000F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808000FC:
    // 0x808000FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800100: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800104: jal         0x80087220
    // 0x80800108: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _chegggrenade_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800108: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_7:
    // 0x8080010C: b           L_80800158
    // 0x80800110: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800158;
    // 0x80800110: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800114:
    // 0x80800114: jal         0x800844D8
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080011C: jal         0x80800008
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_baeggsetup(rdram, ctx);
        goto after_9;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800124: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80800128: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080012C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800130: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80800134: jal         0x800871C8
    // 0x80800138: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    _cheggclockwork_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800138: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_10:
    // 0x8080013C: b           L_80800158
    // 0x80800140: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800158;
    // 0x80800140: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800144:
    // 0x80800144: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800148: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080014C: jal         0x80087200
    // 0x80800150: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _chegggolden_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800150: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_11:
L_80800154:
    // 0x80800154: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800158:
    // 0x80800158: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800164: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800168: jr          $ra
    // 0x8080016C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8080016C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80012128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012128: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001212C: jr          $ra
    // 0x80012130: sw          $zero, 0x59C8($at)
    MEM_W(0X59C8, ctx->r1) = 0;
    return;
    // 0x80012130: sw          $zero, 0x59C8($at)
    MEM_W(0X59C8, ctx->r1) = 0;
;}
RECOMP_FUNC void bsdronebitten_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800268: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080026C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800270: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800274: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800278: lbu         $v0, 0x191($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X191);
    // 0x8080027C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800280: beq         $v0, $at, L_808002D8
    if (ctx->r2 == ctx->r1) {
        // 0x80800284: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808002D8;
    }
    // 0x80800284: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800288: bnel        $v0, $at, L_808002DC
    if (ctx->r2 != ctx->r1) {
        // 0x8080028C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002DC;
    }
    goto skip_0;
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800290: jal         0x80084DD0
    // 0x80800294: nop

    _bamovegoto_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800294: nop

    after_0:
    // 0x80800298: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080029C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002A0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808002A4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x808002A8: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808002AC: jal         0x80013970
    // 0x808002B0: nop

    func_80013970(rdram, ctx);
        goto after_1;
    // 0x808002B0: nop

    after_1:
    // 0x808002B4: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808002B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808002C0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808002C4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x808002C8: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808002CC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808002D0: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x808002D4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_808002D8:
    // 0x808002D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002DC:
    // 0x808002DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void _chcablecar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E48: syscall     248
    recomp_syscall_handler(rdram, ctx, 0x80085E48);
    return;
    // 0x80085E4C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800C2900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2900: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C2904: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C2908: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C290C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C2910: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C2914: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C2918: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C291C: addiu       $s0, $s0, -0x73F0
    ctx->r16 = ADD32(ctx->r16, -0X73F0);
    // 0x800C2920: addiu       $s1, $zero, 0x3C
    ctx->r17 = ADD32(0, 0X3C);
    // 0x800C2924: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800C2928:
    // 0x800C2928: lbu         $t6, 0x78($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X78);
    // 0x800C292C: beql        $t6, $zero, L_800C2940
    if (ctx->r14 == 0) {
        // 0x800C2930: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800C2940;
    }
    goto skip_0;
    // 0x800C2930: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800C2934: jal         0x800C2FDC
    // 0x800C2938: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x800C2938: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_0:
    // 0x800C293C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800C2940:
    // 0x800C2940: bne         $s2, $s1, L_800C2928
    if (ctx->r18 != ctx->r17) {
        // 0x800C2944: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_800C2928;
    }
    // 0x800C2944: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x800C2948: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C294C: addiu       $s3, $s3, -0x5670
    ctx->r19 = ADD32(ctx->r19, -0X5670);
L_800C2950:
    // 0x800C2950: jal         0x800C2718
    // 0x800C2954: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_800C2718(rdram, ctx);
        goto after_1;
    // 0x800C2954: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_1:
    // 0x800C2958: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C295C: lbu         $t7, -0x7378($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X7378);
    // 0x800C2960: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C2964: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C2968: beq         $t7, $zero, L_800C2974
    if (ctx->r15 == 0) {
        // 0x800C296C: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800C2974;
    }
    // 0x800C296C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C2970: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800C2974:
    // 0x800C2974: lbu         $t8, -0x72F8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X72F8);
    // 0x800C2978: addiu       $s0, $s0, -0x7270
    ctx->r16 = ADD32(ctx->r16, -0X7270);
    // 0x800C297C: beq         $t8, $zero, L_800C2988
    if (ctx->r24 == 0) {
        // 0x800C2980: nop
    
            goto L_800C2988;
    }
    // 0x800C2980: nop

    // 0x800C2984: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800C2988:
    // 0x800C2988: lbu         $t9, -0x7278($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X7278);
    // 0x800C298C: beq         $t9, $zero, L_800C2998
    if (ctx->r25 == 0) {
        // 0x800C2990: nop
    
            goto L_800C2998;
    }
    // 0x800C2990: nop

    // 0x800C2994: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800C2998:
    // 0x800C2998: lbu         $t0, 0x78($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X78);
L_800C299C:
    // 0x800C299C: beql        $t0, $zero, L_800C29AC
    if (ctx->r8 == 0) {
        // 0x800C29A0: lbu         $t1, 0xF8($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0XF8);
            goto L_800C29AC;
    }
    goto skip_1;
    // 0x800C29A0: lbu         $t1, 0xF8($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XF8);
    skip_1:
    // 0x800C29A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C29A8: lbu         $t1, 0xF8($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XF8);
L_800C29AC:
    // 0x800C29AC: beql        $t1, $zero, L_800C29BC
    if (ctx->r9 == 0) {
        // 0x800C29B0: lbu         $t2, 0x178($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X178);
            goto L_800C29BC;
    }
    goto skip_2;
    // 0x800C29B0: lbu         $t2, 0x178($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X178);
    skip_2:
    // 0x800C29B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C29B8: lbu         $t2, 0x178($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X178);
L_800C29BC:
    // 0x800C29BC: beql        $t2, $zero, L_800C29CC
    if (ctx->r10 == 0) {
        // 0x800C29C0: lbu         $t3, 0x1F8($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X1F8);
            goto L_800C29CC;
    }
    goto skip_3;
    // 0x800C29C0: lbu         $t3, 0x1F8($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1F8);
    skip_3:
    // 0x800C29C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C29C8: lbu         $t3, 0x1F8($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1F8);
L_800C29CC:
    // 0x800C29CC: addiu       $s0, $s0, 0x200
    ctx->r16 = ADD32(ctx->r16, 0X200);
    // 0x800C29D0: beq         $t3, $zero, L_800C29DC
    if (ctx->r11 == 0) {
        // 0x800C29D4: nop
    
            goto L_800C29DC;
    }
    // 0x800C29D4: nop

    // 0x800C29D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800C29DC:
    // 0x800C29DC: bnel        $s0, $s3, L_800C299C
    if (ctx->r16 != ctx->r19) {
        // 0x800C29E0: lbu         $t0, 0x78($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X78);
            goto L_800C299C;
    }
    goto skip_4;
    // 0x800C29E0: lbu         $t0, 0x78($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X78);
    skip_4:
    // 0x800C29E4: bne         $s1, $zero, L_800C2950
    if (ctx->r17 != 0) {
        // 0x800C29E8: nop
    
            goto L_800C2950;
    }
    // 0x800C29E8: nop

    // 0x800C29EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C29F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C29F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C29F8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C29FC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C2A00: jr          $ra
    // 0x800C2A04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C2A04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void suquiz_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DCC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3370, 0X10F0) << 16);
    // 0x80800DD0: addiu       $a1, $a1, 0x10F0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3370, 0X10F0));
    // 0x80800DD4: addiu       $a0, $zero, 0x217
    ctx->r4 = ADD32(0, 0X217);
    // 0x80800DD8: jal         0x80108474
    // 0x80800DDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_0;
    // 0x80800DDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DE8: jr          $ra
    // 0x80800DEC: nop

    return;
    // 0x80800DEC: nop

;}
RECOMP_FUNC void babuzz_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B8: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x808002BC: jr          $ra
    // 0x808002C0: sw          $a1, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r5;
    return;
    // 0x808002C0: sw          $a1, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800E87E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E87E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E87E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E87E8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800E87EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E87F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E87F4: jal         0x800B32C0
    // 0x800E87F8: lw          $a0, -0x2A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A00);
    freelist_erase(rdram, ctx);
        goto after_0;
    // 0x800E87F8: lw          $a0, -0x2A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A00);
    after_0:
    // 0x800E87FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8800: jal         0x800B3204
    // 0x800E8804: lw          $a0, -0x2A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A00);
    freelist_used_count(rdram, ctx);
        goto after_1;
    // 0x800E8804: lw          $a0, -0x2A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A00);
    after_1:
    // 0x800E8808: bne         $v0, $zero, L_800E8820
    if (ctx->r2 != 0) {
        // 0x800E880C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800E8820;
    }
    // 0x800E880C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8810: jal         0x800B3248
    // 0x800E8814: lw          $a0, -0x2A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A00);
    freelist_free(rdram, ctx);
        goto after_2;
    // 0x800E8814: lw          $a0, -0x2A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A00);
    after_2:
    // 0x800E8818: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E881C: sw          $zero, -0x2A00($at)
    MEM_W(-0X2A00, ctx->r1) = 0;
L_800E8820:
    // 0x800E8820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8828: jr          $ra
    // 0x800E882C: nop

    return;
    // 0x800E882C: nop

;}
RECOMP_FUNC void _chpiranha_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DD0: syscall     458
    recomp_syscall_handler(rdram, ctx, 0x80086DD0);
    return;
    // 0x80086DD4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chweather_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(732, 0X5F0) << 16);
    // 0x80800124: jr          $ra
    // 0x80800128: addiu       $v0, $v0, 0x5F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X5F0));
    return;
    // 0x80800128: addiu       $v0, $v0, 0x5F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X5F0));
;}
RECOMP_FUNC void func_808012BC_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012C4: jal         0x808001A8
    // 0x808012C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001A8_bswasher(rdram, ctx);
        goto after_0;
    // 0x808012C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808012CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808012D0: jal         0x800845D8
    // 0x808012D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808012D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808012D8: lui         $a2, 0x3F03
    ctx->r6 = S32(0X3F03 << 16);
    // 0x808012DC: ori         $a2, $a2, 0x46DC
    ctx->r6 = ctx->r6 | 0X46DC;
    // 0x808012E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808012E4: jal         0x800845E0
    // 0x808012E8: addiu       $a1, $zero, 0x358
    ctx->r5 = ADD32(0, 0X358);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808012E8: addiu       $a1, $zero, 0x358
    ctx->r5 = ADD32(0, 0X358);
    after_2:
    // 0x808012EC: jal         0x8008CABC
    // 0x808012F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_3;
    // 0x808012F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808012F4: lui         $a1, 0x3DD2
    ctx->r5 = S32(0X3DD2 << 16);
    // 0x808012F8: ori         $a1, $a1, 0x1FF3
    ctx->r5 = ctx->r5 | 0X1FF3;
    // 0x808012FC: jal         0x8008B10C
    // 0x80801300: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B10C(rdram, ctx);
        goto after_4;
    // 0x80801300: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80801304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080130C: jr          $ra
    // 0x80801310: nop

    return;
    // 0x80801310: nop

;}
RECOMP_FUNC void basetup_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B28: jr          $ra
    // 0x80800B2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800B2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80802628_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080262C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802630: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80802634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802638: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x8080263C: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x80802640: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80802644: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
    // 0x80802648: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x8080264C: jal         0x80108B04
    // 0x80802650: sh          $t2, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r10;
    func_80108B04(rdram, ctx);
        goto after_0;
    // 0x80802650: sh          $t2, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r10;
    after_0:
    // 0x80802654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080265C: jr          $ra
    // 0x80802660: nop

    return;
    // 0x80802660: nop

;}
RECOMP_FUNC void func_801020A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801020A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801020AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801020B0: jal         0x80104248
    // 0x801020B4: nop

    func_80104248(rdram, ctx);
        goto after_0;
    // 0x801020B4: nop

    after_0:
    // 0x801020B8: beq         $v0, $zero, L_801020CC
    if (ctx->r2 == 0) {
        // 0x801020BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801020CC;
    }
    // 0x801020BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801020C0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801020C4: jal         0x8008B1C8
    // 0x801020C8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_8008B1C8(rdram, ctx);
        goto after_1;
    // 0x801020C8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_1:
L_801020CC:
    // 0x801020CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801020D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801020D4: jr          $ra
    // 0x801020D8: nop

    return;
    // 0x801020D8: nop

;}
