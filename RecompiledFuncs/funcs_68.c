#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800B88_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800B94: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800B98: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80800B9C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800BA0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800BA4: beq         $v0, $zero, L_80800BC8
    if (ctx->r2 == 0) {
        // 0x80800BA8: addiu       $a1, $zero, 0x11
        ctx->r5 = ADD32(0, 0X11);
            goto L_80800BC8;
    }
    // 0x80800BA8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80800BAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800BB0: beq         $v0, $at, L_80800BE0
    if (ctx->r2 == ctx->r1) {
        // 0x80800BB4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800BE0;
    }
    // 0x80800BB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BB8: beql        $v0, $at, L_80800BDC
    if (ctx->r2 == ctx->r1) {
        // 0x80800BBC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800BDC;
    }
    goto skip_0;
    // 0x80800BBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x80800BC0: b           L_80800BF4
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800BF4;
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BC8:
    // 0x80800BC8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800BCC: jal         0x800856B0
    // 0x80800BD0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800BD0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800BD4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800BD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80800BDC:
    // 0x80800BDC: sw          $t6, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r14;
L_80800BE0:
    // 0x80800BE0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800BE4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BE8: jal         0x800856D0
    // 0x80800BEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800BEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BF4:
    // 0x80800BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BF8: jr          $ra
    // 0x80800BFC: nop

    return;
    // 0x80800BFC: nop

;}
RECOMP_FUNC void subaddietaxi_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800334: jr          $ra
    // 0x80800338: nop

    return;
    // 0x80800338: nop

;}
RECOMP_FUNC void func_800D1FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1FC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1FC8: addiu       $a0, $a0, -0x80
    ctx->r4 = ADD32(ctx->r4, -0X80);
    // 0x800D1FCC: jal         0x800D395C
    // 0x800D1FD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D395C(rdram, ctx);
        goto after_0;
    // 0x800D1FD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D1FD4: beq         $v0, $zero, L_800D1FF0
    if (ctx->r2 == 0) {
        // 0x800D1FD8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800D1FF0;
    }
    // 0x800D1FD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D1FDC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D1FE0: addiu       $t7, $t7, -0x4D70
    ctx->r15 = ADD32(ctx->r15, -0X4D70);
    // 0x800D1FE4: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800D1FE8: b           L_800D2000
    // 0x800D1FEC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
        goto L_800D2000;
    // 0x800D1FEC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
L_800D1FF0:
    // 0x800D1FF0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800D1FF4: addiu       $t9, $t9, -0x4DA0
    ctx->r25 = ADD32(ctx->r25, -0X4DA0);
    // 0x800D1FF8: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800D1FFC: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
L_800D2000:
    // 0x800D2000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2008: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D200C: jr          $ra
    // 0x800D2010: nop

    return;
    // 0x800D2010: nop

;}
RECOMP_FUNC void bsdronegoto_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003D0: lw          $v0, 0x190($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X190);
    // 0x808003D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003D8: beq         $v0, $at, L_808003F0
    if (ctx->r2 == ctx->r1) {
        // 0x808003DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003F0;
    }
    // 0x808003DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003E0: beq         $v0, $at, L_80800400
    if (ctx->r2 == ctx->r1) {
        // 0x808003E4: nop
    
            goto L_80800400;
    }
    // 0x808003E4: nop

    // 0x808003E8: b           L_8080040C
    // 0x808003EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080040C;
    // 0x808003EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003F0:
    // 0x808003F0: jal         0x808000E0
    // 0x808003F4: nop

    func_808000E0_bsdronegoto(rdram, ctx);
        goto after_0;
    // 0x808003F4: nop

    after_0:
    // 0x808003F8: b           L_8080040C
    // 0x808003FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080040C;
    // 0x808003FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800400:
    // 0x80800400: jal         0x8080026C
    // 0x80800404: nop

    func_8080026C_bsdronegoto(rdram, ctx);
        goto after_1;
    // 0x80800404: nop

    after_1:
    // 0x80800408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080040C:
    // 0x8080040C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800410: jr          $ra
    // 0x80800414: nop

    return;
    // 0x80800414: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A888: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A888);
    return;
    // 0x8008A88C: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void func_80800098_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080009C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000A4: jal         0x800856B8
    // 0x808000A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808000A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808000AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void _basudie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085210: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085210);
    return;
    // 0x80085214: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void suspline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800124: lwc1        $f4, 0x5C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x80800128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080012C: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80800130: nop

    // 0x80800134: bc1f        L_80800158
    if (!c1cs) {
        // 0x80800138: nop
    
            goto L_80800158;
    }
    // 0x80800138: nop

    // 0x8080013C: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800140: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80800144: nop

    // 0x80800148: bc1f        L_80800158
    if (!c1cs) {
        // 0x8080014C: nop
    
            goto L_80800158;
    }
    // 0x8080014C: nop

    // 0x80800150: jr          $ra
    // 0x80800154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800158:
    // 0x80800158: jr          $ra
    // 0x8080015C: nop

    return;
    // 0x8080015C: nop

;}
RECOMP_FUNC void func_808006EC_scinfobar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800700: jal         0x80088B30
    // 0x80800704: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    _fxdialog_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800704: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800708: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080070C: jal         0x80088B38
    // 0x80800710: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _fxdialog_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800710: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800714: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800718: jal         0x80088B40
    // 0x8080071C: lwc1        $f12, 0xC($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC);
    _fxdialog_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080071C: lwc1        $f12, 0xC($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC);
    after_2:
    // 0x80800720: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800724: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800728: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8080072C: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x80800730: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80800734: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    // 0x80800738: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8080073C: nop

    // 0x80800740: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800744: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800748: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8080074C: jal         0x80088B48
    // 0x80800750: nop

    _fxdialog_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800750: nop

    after_3:
    // 0x80800754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080075C: jr          $ra
    // 0x80800760: nop

    return;
    // 0x80800760: nop

;}
RECOMP_FUNC void _chboggykidshome_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866E0: syscall     355
    recomp_syscall_handler(rdram, ctx, 0x800866E0);
    return;
    // 0x800866E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800CBDD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBDD4: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800CBDD8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800CBDDC: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800CBDE0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CBDE4: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800CBDE8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800CBDEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800CBDF0: addiu       $s5, $s5, -0x5180
    ctx->r21 = ADD32(ctx->r21, -0X5180);
    // 0x800CBDF4: lw          $t6, 0x8($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X8);
    // 0x800CBDF8: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800CBDFC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800CBE00: lw          $s4, 0xC($s5)
    ctx->r20 = MEM_W(ctx->r21, 0XC);
    // 0x800CBE04: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800CBE08: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800CBE0C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800CBE10: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800CBE14: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800CBE18: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800CBE1C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800CBE20: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800CBE24: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800CBE28: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800CBE2C: add.s       $f20, $f18, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800CBE30: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800CBE34: addu        $v0, $t7, $s4
    ctx->r2 = ADD32(ctx->r15, ctx->r20);
    // 0x800CBE38: sub.s       $f22, $f18, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800CBE3C: sltu        $at, $s4, $v0
    ctx->r1 = ctx->r20 < ctx->r2 ? 1 : 0;
    // 0x800CBE40: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800CBE44: beq         $at, $zero, L_800CC048
    if (ctx->r1 == 0) {
        // 0x800CBE48: or          $s3, $a2, $zero
        ctx->r19 = ctx->r6 | 0;
            goto L_800CC048;
    }
    // 0x800CBE48: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800CBE4C: lbu         $t8, 0x2($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X2);
L_800CBE50:
    // 0x800CBE50: addiu       $a0, $s4, 0x4
    ctx->r4 = ADD32(ctx->r20, 0X4);
    // 0x800CBE54: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800CBE58: beql        $t9, $zero, L_800CC03C
    if (ctx->r25 == 0) {
        // 0x800CBE5C: addiu       $s4, $s4, 0x1C
        ctx->r20 = ADD32(ctx->r20, 0X1C);
            goto L_800CC03C;
    }
    goto skip_0;
    // 0x800CBE5C: addiu       $s4, $s4, 0x1C
    ctx->r20 = ADD32(ctx->r20, 0X1C);
    skip_0:
    // 0x800CBE60: jal         0x800EFC7C
    // 0x800CBE64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_0;
    // 0x800CBE64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800CBE68: lwc1        $f10, 0x10($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X10);
    // 0x800CBE6C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800CBE70: nop

    // 0x800CBE74: bc1fl       L_800CC024
    if (!c1cs) {
        // 0x800CBE78: lw          $t0, 0x8($s5)
        ctx->r8 = MEM_W(ctx->r21, 0X8);
            goto L_800CC024;
    }
    goto skip_1;
    // 0x800CBE78: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
    skip_1:
    // 0x800CBE7C: jal         0x800CB910
    // 0x800CBE80: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800CB910(rdram, ctx);
        goto after_1;
    // 0x800CBE80: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x800CBE84: lw          $t0, 0x14($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X14);
    // 0x800CBE88: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CBE8C: andi        $t6, $s3, 0x1
    ctx->r14 = ctx->r19 & 0X1;
    // 0x800CBE90: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x800CBE94: lbu         $t2, 0x18($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X18);
    // 0x800CBE98: bne         $t2, $zero, L_800CBEBC
    if (ctx->r10 != 0) {
        // 0x800CBE9C: nop
    
            goto L_800CBEBC;
    }
    // 0x800CBE9C: nop

    // 0x800CBEA0: lw          $t3, 0x8($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X8);
    // 0x800CBEA4: lw          $t5, 0xC($s5)
    ctx->r13 = MEM_W(ctx->r21, 0XC);
    // 0x800CBEA8: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800CBEAC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800CBEB0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800CBEB4: b           L_800CC038
    // 0x800CBEB8: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
        goto L_800CC038;
    // 0x800CBEB8: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_800CBEBC:
    // 0x800CBEBC: beq         $t6, $zero, L_800CBF64
    if (ctx->r14 == 0) {
        // 0x800CBEC0: nop
    
            goto L_800CBF64;
    }
    // 0x800CBEC0: nop

    // 0x800CBEC4: jal         0x800CB8F0
    // 0x800CBEC8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800CB8F0(rdram, ctx);
        goto after_2;
    // 0x800CBEC8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x800CBECC: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x800CBED0: beq         $at, $zero, L_800CC020
    if (ctx->r1 == 0) {
        // 0x800CBED4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800CC020;
    }
    // 0x800CBED4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CBED8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
L_800CBEDC:
    // 0x800CBEDC: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800CBEE0: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x800CBEE4: and         $t0, $t9, $s3
    ctx->r8 = ctx->r25 & ctx->r19;
    // 0x800CBEE8: beql        $t0, $zero, L_800CBF50
    if (ctx->r8 == 0) {
        // 0x800CBEEC: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CBF50;
    }
    goto skip_2;
    // 0x800CBEEC: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_2:
    // 0x800CBEF0: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CBEF4: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800CBEF8: nop

    // 0x800CBEFC: bc1fl       L_800CBF50
    if (!c1cs) {
        // 0x800CBF00: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CBF50;
    }
    goto skip_3;
    // 0x800CBF00: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_3:
    // 0x800CBF04: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800CBF08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CBF0C: bc1fl       L_800CBF50
    if (!c1cs) {
        // 0x800CBF10: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CBF50;
    }
    goto skip_4;
    // 0x800CBF10: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_4:
    // 0x800CBF14: jal         0x800EFC7C
    // 0x800CBF18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_3;
    // 0x800CBF18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x800CBF1C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CBF20: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800CBF24: nop

    // 0x800CBF28: bc1fl       L_800CBF50
    if (!c1cs) {
        // 0x800CBF2C: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CBF50;
    }
    goto skip_5;
    // 0x800CBF2C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_5:
    // 0x800CBF30: lw          $t1, 0xC($s5)
    ctx->r9 = MEM_W(ctx->r21, 0XC);
    // 0x800CBF34: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800CBF38: subu        $v0, $s4, $t1
    ctx->r2 = SUB32(ctx->r20, ctx->r9);
    // 0x800CBF3C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CBF40: mflo        $v0
    ctx->r2 = lo;
    // 0x800CBF44: b           L_800CC050
    // 0x800CBF48: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800CC050;
    // 0x800CBF48: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800CBF4C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_800CBF50:
    // 0x800CBF50: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800CBF54: bnel        $at, $zero, L_800CBEDC
    if (ctx->r1 != 0) {
        // 0x800CBF58: lw          $t7, 0x14($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X14);
            goto L_800CBEDC;
    }
    goto skip_6;
    // 0x800CBF58: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    skip_6:
    // 0x800CBF5C: b           L_800CC024
    // 0x800CBF60: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
        goto L_800CC024;
    // 0x800CBF60: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
L_800CBF64:
    // 0x800CBF64: jal         0x800CB8F0
    // 0x800CBF68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800CB8F0(rdram, ctx);
        goto after_4;
    // 0x800CBF68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x800CBF6C: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x800CBF70: beq         $at, $zero, L_800CC020
    if (ctx->r1 == 0) {
        // 0x800CBF74: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800CC020;
    }
    // 0x800CBF74: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CBF78: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_800CBF7C:
    // 0x800CBF7C: sll         $t3, $v0, 12
    ctx->r11 = S32(ctx->r2 << 12);
    // 0x800CBF80: srl         $t4, $t3, 29
    ctx->r12 = S32(U32(ctx->r11) >> 29);
    // 0x800CBF84: and         $t5, $t4, $s3
    ctx->r13 = ctx->r12 & ctx->r19;
    // 0x800CBF88: beq         $t5, $zero, L_800CC010
    if (ctx->r13 == 0) {
        // 0x800CBF8C: andi        $t6, $t4, 0x2
        ctx->r14 = ctx->r12 & 0X2;
            goto L_800CC010;
    }
    // 0x800CBF8C: andi        $t6, $t4, 0x2
    ctx->r14 = ctx->r12 & 0X2;
    // 0x800CBF90: bne         $t6, $zero, L_800CBFD8
    if (ctx->r14 != 0) {
        // 0x800CBF94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800CBFD8;
    }
    // 0x800CBF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CBF98: lh          $t7, 0xE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE);
    // 0x800CBF9C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CBFA0: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800CBFA4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800CBFA8: nop

    // 0x800CBFAC: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CBFB0: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800CBFB4: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x800CBFB8: nop

    // 0x800CBFBC: bc1fl       L_800CC014
    if (!c1cs) {
        // 0x800CBFC0: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC014;
    }
    goto skip_7;
    // 0x800CBFC0: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_7:
    // 0x800CBFC4: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800CBFC8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800CBFCC: nop

    // 0x800CBFD0: bc1fl       L_800CC014
    if (!c1cs) {
        // 0x800CBFD4: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC014;
    }
    goto skip_8;
    // 0x800CBFD4: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_8:
L_800CBFD8:
    // 0x800CBFD8: jal         0x800EFC7C
    // 0x800CBFDC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_5;
    // 0x800CBFDC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x800CBFE0: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CBFE4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800CBFE8: nop

    // 0x800CBFEC: bc1fl       L_800CC014
    if (!c1cs) {
        // 0x800CBFF0: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC014;
    }
    goto skip_9;
    // 0x800CBFF0: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_9:
    // 0x800CBFF4: lw          $t8, 0xC($s5)
    ctx->r24 = MEM_W(ctx->r21, 0XC);
    // 0x800CBFF8: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800CBFFC: subu        $v0, $s4, $t8
    ctx->r2 = SUB32(ctx->r20, ctx->r24);
    // 0x800CC000: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CC004: mflo        $v0
    ctx->r2 = lo;
    // 0x800CC008: b           L_800CC050
    // 0x800CC00C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800CC050;
    // 0x800CC00C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800CC010:
    // 0x800CC010: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_800CC014:
    // 0x800CC014: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800CC018: bnel        $at, $zero, L_800CBF7C
    if (ctx->r1 != 0) {
        // 0x800CC01C: lw          $v0, 0x14($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X14);
            goto L_800CBF7C;
    }
    goto skip_10;
    // 0x800CC01C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    skip_10:
L_800CC020:
    // 0x800CC020: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
L_800CC024:
    // 0x800CC024: lw          $t2, 0xC($s5)
    ctx->r10 = MEM_W(ctx->r21, 0XC);
    // 0x800CC028: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800CC02C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800CC030: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800CC034: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
L_800CC038:
    // 0x800CC038: addiu       $s4, $s4, 0x1C
    ctx->r20 = ADD32(ctx->r20, 0X1C);
L_800CC03C:
    // 0x800CC03C: sltu        $at, $s4, $v0
    ctx->r1 = ctx->r20 < ctx->r2 ? 1 : 0;
    // 0x800CC040: bnel        $at, $zero, L_800CBE50
    if (ctx->r1 != 0) {
        // 0x800CC044: lbu         $t8, 0x2($s4)
        ctx->r24 = MEM_BU(ctx->r20, 0X2);
            goto L_800CBE50;
    }
    goto skip_11;
    // 0x800CC044: lbu         $t8, 0x2($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X2);
    skip_11:
L_800CC048:
    // 0x800CC048: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800CC04C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800CC050:
    // 0x800CC050: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800CC054: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800CC058: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800CC05C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800CC060: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800CC064: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800CC068: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800CC06C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800CC070: jr          $ra
    // 0x800CC074: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800CC074: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _chgate1doors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FB8: syscall     487
    recomp_syscall_handler(rdram, ctx, 0x80086FB8);
    return;
    // 0x80086FBC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802CC8_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802CCC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802CD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802CD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802CD8: jal         0x80106790
    // 0x80802CDC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802CDC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80802CE0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80802CE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802CE8: jal         0x80100094
    // 0x80802CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80802CF0: jal         0x800D8FF8
    // 0x80802CF4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80802CF4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x80802CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802D00: jal         0x80100094
    // 0x80802D04: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80802D04: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80802D08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802D0C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80802D10: jal         0x800897D8
    // 0x80802D14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80802D14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80802D18: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80802D1C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80802D20: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80802D24: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x80802D28: sltiu       $at, $t8, 0x16
    ctx->r1 = ctx->r24 < 0X16 ? 1 : 0;
    // 0x80802D2C: beq         $at, $zero, L_808032B0
    if (ctx->r1 == 0) {
        // 0x80802D30: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808032B0;
    }
    // 0x80802D30: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80802D34: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X383C) << 16);
    // 0x80802D38: addu        $at, $at, $t8
    gpr jr_addend_80802D40 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80802D3C: lw          $t8, 0x383C($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1564, 0X383C));
    // 0x80802D40: jr          $t8
    // 0x80802D44: nop

    switch (jr_addend_80802D40 >> 2) {
        case 0: goto L_80802EDC; break;
        case 1: goto L_808032B0; break;
        case 2: goto L_808032B0; break;
        case 3: goto L_80802F68; break;
        case 4: goto L_80802F88; break;
        case 5: goto L_80803014; break;
        case 6: goto L_8080306C; break;
        case 7: goto L_808030AC; break;
        case 8: goto L_80803104; break;
        case 9: goto L_80803150; break;
        case 10: goto L_80803198; break;
        case 11: goto L_808031CC; break;
        case 12: goto L_808031F4; break;
        case 13: goto L_8080322C; break;
        case 14: goto L_808032B0; break;
        case 15: goto L_80802E28; break;
        case 16: goto L_80803244; break;
        case 17: goto L_808032B0; break;
        case 18: goto L_80802D48; break;
        case 19: goto L_80802D7C; break;
        case 20: goto L_80802DB0; break;
        case 21: goto L_80802DD0; break;
        default: switch_error(__func__, 0x80802D40, 0x8080383C);
    }
    // 0x80802D44: nop

L_80802D48:
    // 0x80802D48: jal         0x808021C4
    // 0x80802D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808021C4_chclockworkmouse(rdram, ctx);
        goto after_5;
    // 0x80802D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802D50: jal         0x80105A5C
    // 0x80802D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_6;
    // 0x80802D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802D58: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80802D5C: nop
    
            goto L_808032B0;
    }
    // 0x80802D5C: nop

    // 0x80802D60: jal         0x80105634
    // 0x80802D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105634(rdram, ctx);
        goto after_7;
    // 0x80802D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80802D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D6C: jal         0x808026E0
    // 0x80802D70: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_8;
    // 0x80802D70: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_8:
    // 0x80802D74: b           L_808032B0
    // 0x80802D78: nop

        goto L_808032B0;
    // 0x80802D78: nop

L_80802D7C:
    // 0x80802D7C: jal         0x8080297C
    // 0x80802D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080297C_chclockworkmouse(rdram, ctx);
        goto after_9;
    // 0x80802D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80802D84: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80802D88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x80802D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D8C: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80802D90: jal         0x80101E14
    // 0x80802D94: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_10;
    // 0x80802D94: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_10:
    // 0x80802D98: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80802D9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x80802D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DA0: jal         0x808026E0
    // 0x80802DA4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_11;
    // 0x80802DA4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_11:
    // 0x80802DA8: b           L_808032B0
    // 0x80802DAC: nop

        goto L_808032B0;
    // 0x80802DAC: nop

L_80802DB0:
    // 0x80802DB0: jal         0x80101DDC
    // 0x80802DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_12;
    // 0x80802DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80802DB8: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80802DBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x80802DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DC0: jal         0x808026E0
    // 0x80802DC4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_13;
    // 0x80802DC4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_13:
    // 0x80802DC8: b           L_808032B0
    // 0x80802DCC: nop

        goto L_808032B0;
    // 0x80802DCC: nop

L_80802DD0:
    // 0x80802DD0: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802DD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80802DD8: nop

    // 0x80802DDC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80802DE0: nop

    // 0x80802DE4: bc1f        L_80802DF8
    if (!c1cs) {
        // 0x80802DE8: nop
    
            goto L_80802DF8;
    }
    // 0x80802DE8: nop

    // 0x80802DEC: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80802DF0: b           L_808032B0
    // 0x80802DF4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808032B0;
    // 0x80802DF4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80802DF8:
    // 0x80802DF8: jal         0x80088840
    // 0x80802DFC: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_14;
    // 0x80802DFC: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    after_14:
    // 0x80802E00: beq         $v0, $zero, L_80802E18
    if (ctx->r2 == 0) {
        // 0x80802E04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802E18;
    }
    // 0x80802E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E08: jal         0x80088830
    // 0x80802E0C: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_15;
    // 0x80802E0C: nop

    after_15:
    // 0x80802E10: b           L_808032B0
    // 0x80802E14: nop

        goto L_808032B0;
    // 0x80802E14: nop

L_80802E18:
    // 0x80802E18: jal         0x808026E0
    // 0x80802E1C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_16;
    // 0x80802E1C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_16:
    // 0x80802E20: b           L_808032B0
    // 0x80802E24: nop

        goto L_808032B0;
    // 0x80802E24: nop

L_80802E28:
    // 0x80802E28: jal         0x80802BCC
    // 0x80802E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BCC_chclockworkmouse(rdram, ctx);
        goto after_17;
    // 0x80802E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80802E30: jal         0x80802A48
    // 0x80802E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802A48_chclockworkmouse(rdram, ctx);
        goto after_18;
    // 0x80802E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80802E38: jal         0x800DA298
    // 0x80802E3C: addiu       $a0, $zero, 0x42B
    ctx->r4 = ADD32(0, 0X42B);
    func_800DA298(rdram, ctx);
        goto after_19;
    // 0x80802E3C: addiu       $a0, $zero, 0x42B
    ctx->r4 = ADD32(0, 0X42B);
    after_19:
    // 0x80802E40: beq         $v0, $zero, L_80802E58
    if (ctx->r2 == 0) {
        // 0x80802E44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802E58;
    }
    // 0x80802E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E48: jal         0x808026E0
    // 0x80802E4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_20;
    // 0x80802E4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_20:
    // 0x80802E50: b           L_808032B0
    // 0x80802E54: nop

        goto L_808032B0;
    // 0x80802E54: nop

L_80802E58:
    // 0x80802E58: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80802E5C: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x80802E60: bltz        $t1, L_808032B0
    if (SIGNED(ctx->r9) < 0) {
        // 0x80802E64: nop
    
            goto L_808032B0;
    }
    // 0x80802E64: nop

    // 0x80802E68: jal         0x80090178
    // 0x80802E6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_21;
    // 0x80802E6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_21:
    // 0x80802E70: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80802E74: nop
    
            goto L_808032B0;
    }
    // 0x80802E74: nop

    // 0x80802E78: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802E7C: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80802E80: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802E84: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80802E88: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80802E8C: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80802E90: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x80802E94: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80802E98: jal         0x8008A1C8
    // 0x80802E9C: nop

    _subaddiedialog_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x80802E9C: nop

    after_22:
    // 0x80802EA0: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80802EA4: nop
    
            goto L_808032B0;
    }
    // 0x80802EA4: nop

    // 0x80802EA8: jal         0x800DA544
    // 0x80802EAC: addiu       $a0, $zero, 0x42B
    ctx->r4 = ADD32(0, 0X42B);
    func_800DA544(rdram, ctx);
        goto after_23;
    // 0x80802EAC: addiu       $a0, $zero, 0x42B
    ctx->r4 = ADD32(0, 0X42B);
    after_23:
    // 0x80802EB0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80802EB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802EB8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80802EBC: jal         0x8080079C
    // 0x80802EC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8080079C_chclockworkmouse(rdram, ctx);
        goto after_24;
    // 0x80802EC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_24:
    // 0x80802EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802EC8: addiu       $a1, $zero, 0x1426
    ctx->r5 = ADD32(0, 0X1426);
    // 0x80802ECC: jal         0x80801B44
    // 0x80802ED0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80801B44_chclockworkmouse(rdram, ctx);
        goto after_25;
    // 0x80802ED0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_25:
    // 0x80802ED4: b           L_808032B0
    // 0x80802ED8: nop

        goto L_808032B0;
    // 0x80802ED8: nop

L_80802EDC:
    // 0x80802EDC: jal         0x80802BCC
    // 0x80802EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BCC_chclockworkmouse(rdram, ctx);
        goto after_26;
    // 0x80802EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80802EE4: jal         0x80802A48
    // 0x80802EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802A48_chclockworkmouse(rdram, ctx);
        goto after_27;
    // 0x80802EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80802EEC: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80802EF0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80802EF4: bltz        $t6, L_808032B0
    if (SIGNED(ctx->r14) < 0) {
        // 0x80802EF8: nop
    
            goto L_808032B0;
    }
    // 0x80802EF8: nop

    // 0x80802EFC: jal         0x80090178
    // 0x80802F00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_28;
    // 0x80802F00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_28:
    // 0x80802F04: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80802F08: nop
    
            goto L_808032B0;
    }
    // 0x80802F08: nop

    // 0x80802F0C: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802F10: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80802F14: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80802F18: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80802F1C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80802F20: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80802F24: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x80802F28: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80802F2C: jal         0x8008A1E0
    // 0x80802F30: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_29;
    // 0x80802F30: nop

    after_29:
    // 0x80802F34: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80802F38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x80802F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802F3C: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80802F40: addiu       $a1, $zero, 0x1427
    ctx->r5 = ADD32(0, 0X1427);
    // 0x80802F44: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x80802F48: bgez        $t1, L_80802F58
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80802F4C: nop
    
            goto L_80802F58;
    }
    // 0x80802F4C: nop

    // 0x80802F50: b           L_80802F58
    // 0x80802F54: addiu       $a1, $zero, 0x1436
    ctx->r5 = ADD32(0, 0X1436);
        goto L_80802F58;
    // 0x80802F54: addiu       $a1, $zero, 0x1436
    ctx->r5 = ADD32(0, 0X1436);
L_80802F58:
    // 0x80802F58: jal         0x80801B44
    // 0x80802F5C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80801B44_chclockworkmouse(rdram, ctx);
        goto after_30;
    // 0x80802F5C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_30:
    // 0x80802F60: b           L_808032B0
    // 0x80802F64: nop

        goto L_808032B0;
    // 0x80802F64: nop

L_80802F68:
    // 0x80802F68: jal         0x80802A48
    // 0x80802F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802A48_chclockworkmouse(rdram, ctx);
        goto after_31;
    // 0x80802F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80802F70: jal         0x80802BCC
    // 0x80802F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BCC_chclockworkmouse(rdram, ctx);
        goto after_32;
    // 0x80802F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80802F78: jal         0x808021C4
    // 0x80802F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808021C4_chclockworkmouse(rdram, ctx);
        goto after_33;
    // 0x80802F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80802F80: b           L_808032B0
    // 0x80802F84: nop

        goto L_808032B0;
    // 0x80802F84: nop

L_80802F88:
    // 0x80802F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802F8C: jal         0x80802724
    // 0x80802F90: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80802724_chclockworkmouse(rdram, ctx);
        goto after_34;
    // 0x80802F90: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_34:
    // 0x80802F94: jal         0x808021C4
    // 0x80802F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808021C4_chclockworkmouse(rdram, ctx);
        goto after_35;
    // 0x80802F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80802F9C: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80802FA0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802FA4: jal         0x80105998
    // 0x80802FA8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80105998(rdram, ctx);
        goto after_36;
    // 0x80802FA8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_36:
    // 0x80802FAC: beq         $v0, $zero, L_80802FE8
    if (ctx->r2 == 0) {
        // 0x80802FB0: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_80802FE8;
    }
    // 0x80802FB0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80802FB4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80802FB8: sb          $t2, 0xFE($t3)
    MEM_B(0XFE, ctx->r11) = ctx->r10;
    // 0x80802FBC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80802FC0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80802FC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802FC8: lw          $t5, 0x64($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X64);
    // 0x80802FCC: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x80802FD0: bgez        $t7, L_80802FE0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80802FD4: nop
    
            goto L_80802FE0;
    }
    // 0x80802FD4: nop

    // 0x80802FD8: b           L_80802FE0
    // 0x80802FDC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80802FE0;
    // 0x80802FDC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80802FE0:
    // 0x80802FE0: jal         0x80800968
    // 0x80802FE4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800968_chclockworkmouse(rdram, ctx);
        goto after_37;
    // 0x80802FE4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_37:
L_80802FE8:
    // 0x80802FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802FEC: jal         0x80802C04
    // 0x80802FF0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80802C04_chclockworkmouse(rdram, ctx);
        goto after_38;
    // 0x80802FF0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_38:
    // 0x80802FF4: jal         0x80105A5C
    // 0x80802FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_39;
    // 0x80802FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80802FFC: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80803000: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x80803000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803004: jal         0x808026E0
    // 0x80803008: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_40;
    // 0x80803008: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_40:
    // 0x8080300C: b           L_808032B0
    // 0x80803010: nop

        goto L_808032B0;
    // 0x80803010: nop

L_80803014:
    // 0x80803014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803018: jal         0x80802724
    // 0x8080301C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80802724_chclockworkmouse(rdram, ctx);
        goto after_41;
    // 0x8080301C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_41:
    // 0x80803020: jal         0x808021C4
    // 0x80803024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808021C4_chclockworkmouse(rdram, ctx);
        goto after_42;
    // 0x80803024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80803028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080302C: jal         0x80802C64
    // 0x80803030: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80802C64_chclockworkmouse(rdram, ctx);
        goto after_43;
    // 0x80803030: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_43:
    // 0x80803034: jal         0x80090248
    // 0x80803038: nop

    func_80090248(rdram, ctx);
        goto after_44;
    // 0x80803038: nop

    after_44:
    // 0x8080303C: beq         $v0, $zero, L_8080304C
    if (ctx->r2 == 0) {
        // 0x80803040: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080304C;
    }
    // 0x80803040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803044: jal         0x808026E0
    // 0x80803048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_45;
    // 0x80803048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_45:
L_8080304C:
    // 0x8080304C: jal         0x80105A5C
    // 0x80803050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_46;
    // 0x80803050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x80803054: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80803058: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x80803058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080305C: jal         0x808026E0
    // 0x80803060: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_47;
    // 0x80803060: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_47:
    // 0x80803064: b           L_808032B0
    // 0x80803068: nop

        goto L_808032B0;
    // 0x80803068: nop

L_8080306C:
    // 0x8080306C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803070: jal         0x80802724
    // 0x80803074: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80802724_chclockworkmouse(rdram, ctx);
        goto after_48;
    // 0x80803074: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_48:
    // 0x80803078: jal         0x808021C4
    // 0x8080307C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808021C4_chclockworkmouse(rdram, ctx);
        goto after_49;
    // 0x8080307C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80803080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803084: jal         0x80802C64
    // 0x80803088: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80802C64_chclockworkmouse(rdram, ctx);
        goto after_50;
    // 0x80803088: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_50:
    // 0x8080308C: jal         0x80105A5C
    // 0x80803090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_51;
    // 0x80803090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80803094: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80803098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x80803098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080309C: jal         0x808026E0
    // 0x808030A0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_52;
    // 0x808030A0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_52:
    // 0x808030A4: b           L_808032B0
    // 0x808030A8: nop

        goto L_808032B0;
    // 0x808030A8: nop

L_808030AC:
    // 0x808030AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808030B0: jal         0x80802C04
    // 0x808030B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80802C04_chclockworkmouse(rdram, ctx);
        goto after_53;
    // 0x808030B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_53:
    // 0x808030B8: jal         0x80105A5C
    // 0x808030BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80105A5C(rdram, ctx);
        goto after_54;
    // 0x808030BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_54:
    // 0x808030C0: beq         $v0, $zero, L_808030D0
    if (ctx->r2 == 0) {
        // 0x808030C4: nop
    
            goto L_808030D0;
    }
    // 0x808030C4: nop

    // 0x808030C8: jal         0x80800C64
    // 0x808030CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80800C64_chclockworkmouse(rdram, ctx);
        goto after_55;
    // 0x808030CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_55:
L_808030D0:
    // 0x808030D0: jal         0x8080297C
    // 0x808030D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080297C_chclockworkmouse(rdram, ctx);
        goto after_56;
    // 0x808030D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x808030D8: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x808030DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x808030DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808030E0: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808030E4: jal         0x80101E14
    // 0x808030E8: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_57;
    // 0x808030E8: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_57:
    // 0x808030EC: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x808030F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x808030F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808030F4: jal         0x808026E0
    // 0x808030F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_58;
    // 0x808030F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_58:
    // 0x808030FC: b           L_808032B0
    // 0x80803100: nop

        goto L_808032B0;
    // 0x80803100: nop

L_80803104:
    // 0x80803104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803108: jal         0x80802C04
    // 0x8080310C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80802C04_chclockworkmouse(rdram, ctx);
        goto after_59;
    // 0x8080310C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_59:
    // 0x80803110: jal         0x80802BCC
    // 0x80803114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BCC_chclockworkmouse(rdram, ctx);
        goto after_60;
    // 0x80803114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80803118: jal         0x80105A5C
    // 0x8080311C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80105A5C(rdram, ctx);
        goto after_61;
    // 0x8080311C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_61:
    // 0x80803120: beq         $v0, $zero, L_80803130
    if (ctx->r2 == 0) {
        // 0x80803124: nop
    
            goto L_80803130;
    }
    // 0x80803124: nop

    // 0x80803128: jal         0x80800C64
    // 0x8080312C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80800C64_chclockworkmouse(rdram, ctx);
        goto after_62;
    // 0x8080312C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_62:
L_80803130:
    // 0x80803130: jal         0x80101DDC
    // 0x80803134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_63;
    // 0x80803134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x80803138: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x8080313C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x8080313C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803140: jal         0x808026E0
    // 0x80803144: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_64;
    // 0x80803144: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_64:
    // 0x80803148: b           L_808032B0
    // 0x8080314C: nop

        goto L_808032B0;
    // 0x8080314C: nop

L_80803150:
    // 0x80803150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803154: jal         0x80802C04
    // 0x80803158: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80802C04_chclockworkmouse(rdram, ctx);
        goto after_65;
    // 0x80803158: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_65:
    // 0x8080315C: jal         0x80802BCC
    // 0x80803160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BCC_chclockworkmouse(rdram, ctx);
        goto after_66;
    // 0x80803160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x80803164: jal         0x80802A48
    // 0x80803168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802A48_chclockworkmouse(rdram, ctx);
        goto after_67;
    // 0x80803168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x8080316C: jal         0x80105A5C
    // 0x80803170: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80105A5C(rdram, ctx);
        goto after_68;
    // 0x80803170: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_68:
    // 0x80803174: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x80803178: nop
    
            goto L_808032B0;
    }
    // 0x80803178: nop

    // 0x8080317C: jal         0x80800C64
    // 0x80803180: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80800C64_chclockworkmouse(rdram, ctx);
        goto after_69;
    // 0x80803180: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_69:
    // 0x80803184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803188: jal         0x808026E0
    // 0x8080318C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_70;
    // 0x8080318C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_70:
    // 0x80803190: b           L_808032B0
    // 0x80803194: nop

        goto L_808032B0;
    // 0x80803194: nop

L_80803198:
    // 0x80803198: jal         0x8080297C
    // 0x8080319C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080297C_chclockworkmouse(rdram, ctx);
        goto after_71;
    // 0x8080319C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_71:
    // 0x808031A0: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x808031A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x808031A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031A8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808031AC: jal         0x80101E14
    // 0x808031B0: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_72;
    // 0x808031B0: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_72:
    // 0x808031B4: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x808031B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x808031B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031BC: jal         0x808026E0
    // 0x808031C0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_73;
    // 0x808031C0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_73:
    // 0x808031C4: b           L_808032B0
    // 0x808031C8: nop

        goto L_808032B0;
    // 0x808031C8: nop

L_808031CC:
    // 0x808031CC: jal         0x80802BCC
    // 0x808031D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BCC_chclockworkmouse(rdram, ctx);
        goto after_74;
    // 0x808031D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_74:
    // 0x808031D4: jal         0x80101DDC
    // 0x808031D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_75;
    // 0x808031D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_75:
    // 0x808031DC: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x808031E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    // 0x808031E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031E4: jal         0x808026E0
    // 0x808031E8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_76;
    // 0x808031E8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_76:
    // 0x808031EC: b           L_808032B0
    // 0x808031F0: nop

        goto L_808032B0;
    // 0x808031F0: nop

L_808031F4:
    // 0x808031F4: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808031F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808031FC: nop

    // 0x80803200: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80803204: nop

    // 0x80803208: bc1f        L_8080321C
    if (!c1cs) {
        // 0x8080320C: nop
    
            goto L_8080321C;
    }
    // 0x8080320C: nop

    // 0x80803210: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80803214: b           L_808032B0
    // 0x80803218: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808032B0;
    // 0x80803218: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_8080321C:
    // 0x8080321C: jal         0x8080019C
    // 0x80803220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080019C_chclockworkmouse(rdram, ctx);
        goto after_77;
    // 0x80803220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_77:
    // 0x80803224: b           L_808032B0
    // 0x80803228: nop

        goto L_808032B0;
    // 0x80803228: nop

L_8080322C:
    // 0x8080322C: jal         0x80802A48
    // 0x80803230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802A48_chclockworkmouse(rdram, ctx);
        goto after_78;
    // 0x80803230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x80803234: jal         0x80802BCC
    // 0x80803238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BCC_chclockworkmouse(rdram, ctx);
        goto after_79;
    // 0x80803238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_79:
    // 0x8080323C: b           L_808032B0
    // 0x80803240: nop

        goto L_808032B0;
    // 0x80803240: nop

L_80803244:
    // 0x80803244: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80803248: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080324C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803250: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80803254: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80803258: nop

    // 0x8080325C: bc1f        L_80803278
    if (!c1cs) {
        // 0x80803260: nop
    
            goto L_80803278;
    }
    // 0x80803260: nop

    // 0x80803264: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803268: nop

    // 0x8080326C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80803270: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80803274: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_80803278:
    // 0x80803278: jal         0x808021C4
    // 0x8080327C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808021C4_chclockworkmouse(rdram, ctx);
        goto after_80;
    // 0x8080327C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_80:
    // 0x80803280: jal         0x80105A5C
    // 0x80803284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_81;
    // 0x80803284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_81:
    // 0x80803288: beq         $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x8080328C: nop
    
            goto L_808032B0;
    }
    // 0x8080328C: nop

    // 0x80803290: jal         0x80105634
    // 0x80803294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105634(rdram, ctx);
        goto after_82;
    // 0x80803294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_82:
    // 0x80803298: jal         0x808009F4
    // 0x8080329C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_808009F4_chclockworkmouse(rdram, ctx);
        goto after_83;
    // 0x8080329C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_83:
    // 0x808032A0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808032A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032A8: jal         0x800FFAB0
    // 0x808032AC: sw          $zero, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = 0;
    func_800FFAB0(rdram, ctx);
        goto after_84;
    // 0x808032AC: sw          $zero, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = 0;
    after_84:
L_808032B0:
    // 0x808032B0: jal         0x80801E2C
    // 0x808032B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801E2C_chclockworkmouse(rdram, ctx);
        goto after_85;
    // 0x808032B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_85:
    // 0x808032B8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x808032BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808032C0: lbu         $a1, 0xFB($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0XFB);
    // 0x808032C4: beq         $a1, $at, L_808032D4
    if (ctx->r5 == ctx->r1) {
        // 0x808032C8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808032D4;
    }
    // 0x808032C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808032CC: bnel        $a1, $at, L_808032E8
    if (ctx->r5 != ctx->r1) {
        // 0x808032D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808032E8;
    }
    goto skip_0;
    // 0x808032D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_808032D4:
    // 0x808032D4: jal         0x80800A44
    // 0x808032D8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80800A44_chclockworkmouse(rdram, ctx);
        goto after_86;
    // 0x808032D8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_86:
    // 0x808032DC: jal         0x808004B0
    // 0x808032E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_808004B0_chclockworkmouse(rdram, ctx);
        goto after_87;
    // 0x808032E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_87:
    // 0x808032E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808032E8:
    // 0x808032E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808032EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808032F0: jr          $ra
    // 0x808032F4: nop

    return;
    // 0x808032F4: nop

;}
RECOMP_FUNC void _glgamestore_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884C8: syscall     688
    recomp_syscall_handler(rdram, ctx, 0x800884C8);
    return;
    // 0x800884CC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800DB7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB7C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800DB7C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DB7C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800DB7CC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800DB7D0: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x800DB7D4: jal         0x80088588
    // 0x800DB7D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _glgamedata_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800DB7D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x800DB7DC: beq         $v0, $zero, L_800DB830
    if (ctx->r2 == 0) {
        // 0x800DB7E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DB830;
    }
    // 0x800DB7E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DB7E4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800DB7E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DB7EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DB7F0: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x800DB7F4: blez        $a2, L_800DB828
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800DB7F8: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_800DB828;
    }
    // 0x800DB7F8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800DB7FC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800DB800: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
L_800DB804:
    // 0x800DB804: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x800DB808: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x800DB80C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800DB810: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800DB814: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800DB818: or          $v1, $t9, $t1
    ctx->r3 = ctx->r25 | ctx->r9;
    // 0x800DB81C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800DB820: bne         $at, $zero, L_800DB804
    if (ctx->r1 != 0) {
        // 0x800DB824: addu        $a1, $a1, $v1
        ctx->r5 = ADD32(ctx->r5, ctx->r3);
            goto L_800DB804;
    }
    // 0x800DB824: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
L_800DB828:
    // 0x800DB828: b           L_800DB834
    // 0x800DB82C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800DB834;
    // 0x800DB82C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800DB830:
    // 0x800DB830: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800DB834:
    // 0x800DB834: jr          $ra
    // 0x800DB838: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800DB838: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void idglow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80800244: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800248: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080024C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800250: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800254: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800258: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8080025C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80800260: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2894, 0X320) << 16);
    // 0x80800264: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800268: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8080026C: lwc1        $f18, 0x320($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2894, 0X320));
    // 0x80800270: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800274: jr          $ra
    // 0x80800278: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80800278: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void _batranslate_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085348: syscall     158
    recomp_syscall_handler(rdram, ctx, 0x80085348);
    return;
    // 0x8008534C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800A7C_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A84: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1704, 0XB78) << 16);
    // 0x80800A88: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1704, 0XB68) << 16);
    // 0x80800A8C: addiu       $a3, $a3, 0xB68
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1704, 0XB68));
    // 0x80800A90: addiu       $a1, $a1, 0xB78
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1704, 0XB78));
    // 0x80800A94: jal         0x80089D50
    // 0x80800A98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800A98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AA4: jr          $ra
    // 0x80800AA8: nop

    return;
    // 0x80800AA8: nop

;}
RECOMP_FUNC void chbadshad_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800590: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800598: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080059C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808005A0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808005A4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x808005A8: jal         0x80106790
    // 0x808005AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808005AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005B0: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808005B4: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808005B8: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808005BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808005C0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x808005C4: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x808005C8: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x808005CC: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x808005D0: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808005D4: addiu       $a0, $zero, 0x243
    ctx->r4 = ADD32(0, 0X243);
    // 0x808005D8: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x808005DC: bltz        $t8, L_80800654
    if (SIGNED(ctx->r24) < 0) {
        // 0x808005E0: addiu       $a1, $sp, 0x24
        ctx->r5 = ADD32(ctx->r29, 0X24);
            goto L_80800654;
    }
    // 0x808005E0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808005E4: jal         0x801084B0
    // 0x808005E8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x808005E8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x808005EC: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x808005F0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800654;
    }
    // 0x808005F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808005F4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x808005F8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808005FC: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80800600: sw          $t0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r8;
    // 0x80800604: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800608: jal         0x8080028C
    // 0x8080060C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8080028C_chbadshad(rdram, ctx);
        goto after_2;
    // 0x8080060C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800610: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800614: lw          $t1, 0x64($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X64);
    // 0x80800618: swc1        $f0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f0.u32l;
    // 0x8080061C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80800620: sll         $t3, $t1, 14
    ctx->r11 = S32(ctx->r9 << 14);
    // 0x80800624: bltzl       $t3, L_80800658
    if (SIGNED(ctx->r11) < 0) {
        // 0x80800628: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800658;
    }
    goto skip_0;
    // 0x80800628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080062C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80800630: sw          $t4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r12;
    // 0x80800634: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800638: swc1        $f16, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f16.u32l;
    // 0x8080063C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800640: sw          $t6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->r14;
    // 0x80800644: jal         0x8001211C
    // 0x80800648: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8001211C(rdram, ctx);
        goto after_3;
    // 0x80800648: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x8080064C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800650: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
L_80800654:
    // 0x80800654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800658:
    // 0x80800658: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080065C: jr          $ra
    // 0x80800660: nop

    return;
    // 0x80800660: nop

;}
RECOMP_FUNC void func_8080096C_chdinofamilymother(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080096C: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x80800970: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800974: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800978: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2420, 0X1344) << 16);
    // 0x8080097C: addiu       $at, $zero, 0x3AC
    ctx->r1 = ADD32(0, 0X3AC);
    // 0x80800980: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800984: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800988: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8080098C: lhu         $t9, 0x1344($t9)
    ctx->r25 = MEM_HU(ctx->r25, (int16_t)RELOC_LO16(2420, 0X1344));
    // 0x80800990: lui         $a1, 0x3CCC
    ctx->r5 = S32(0X3CCC << 16);
    // 0x80800994: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800998: bne         $t9, $at, L_80800F18
    if (ctx->r25 != ctx->r1) {
        // 0x8080099C: nop
    
            goto L_80800F18;
    }
    // 0x8080099C: nop

    // 0x808009A0: lui         $a1, 0x3E6B
    ctx->r5 = S32(0X3E6B << 16);
    // 0x808009A4: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x808009A8: jal         0x80101E14
    // 0x808009AC: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x808009AC: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009B0: bne         $v0, $zero, L_80800A08
    if (ctx->r2 != 0) {
        // 0x808009B4: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800A08;
    }
    // 0x808009B4: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x808009B8: lui         $a1, 0x3F11
    ctx->r5 = S32(0X3F11 << 16);
    // 0x808009BC: jal         0x80101E14
    // 0x808009C0: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x808009C0: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    after_1:
    // 0x808009C4: bne         $v0, $zero, L_80800A08
    if (ctx->r2 != 0) {
        // 0x808009C8: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800A08;
    }
    // 0x808009C8: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x808009CC: lui         $a1, 0x3F4A
    ctx->r5 = S32(0X3F4A << 16);
    // 0x808009D0: jal         0x80101E14
    // 0x808009D4: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x808009D4: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    after_2:
    // 0x808009D8: bne         $v0, $zero, L_80800A08
    if (ctx->r2 != 0) {
        // 0x808009DC: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800A08;
    }
    // 0x808009DC: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x808009E0: lui         $a1, 0x3F70
    ctx->r5 = S32(0X3F70 << 16);
    // 0x808009E4: jal         0x80101E14
    // 0x808009E8: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x808009E8: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    after_3:
    // 0x808009EC: bne         $v0, $zero, L_80800A08
    if (ctx->r2 != 0) {
        // 0x808009F0: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800A08;
    }
    // 0x808009F0: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x808009F4: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x808009F8: jal         0x80101E14
    // 0x808009FC: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    func_80101E14(rdram, ctx);
        goto after_4;
    // 0x808009FC: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    after_4:
    // 0x80800A00: beql        $v0, $zero, L_80800B28
    if (ctx->r2 == 0) {
        // 0x80800A04: lui         $a1, 0x3F6B
        ctx->r5 = S32(0X3F6B << 16);
            goto L_80800B28;
    }
    goto skip_0;
    // 0x80800A04: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    skip_0:
L_80800A08:
    // 0x80800A08: jal         0x800B53A4
    // 0x80800A0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800B53A4(rdram, ctx);
        goto after_5;
    // 0x80800A0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80800A10: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    // 0x80800A14: jal         0x800B53A4
    // 0x80800A18: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800B53A4(rdram, ctx);
        goto after_6;
    // 0x80800A18: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80800A1C: sw          $v0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r2;
    // 0x80800A20: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800A24: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    // 0x80800A28: jal         0x8008A0D0
    // 0x80800A2C: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800A2C: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    after_7:
    // 0x80800A30: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800A34: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x80800A38: jal         0x8008A0D0
    // 0x80800A3C: addiu       $a2, $sp, 0xD0
    ctx->r6 = ADD32(ctx->r29, 0XD0);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80800A3C: addiu       $a2, $sp, 0xD0
    ctx->r6 = ADD32(ctx->r29, 0XD0);
    after_8:
    // 0x80800A40: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2420, 0X1404) << 16);
    // 0x80800A44: addiu       $t0, $t0, 0x1404
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2420, 0X1404));
    // 0x80800A48: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800A4C: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    // 0x80800A50: addiu       $a1, $sp, 0xDC
    ctx->r5 = ADD32(ctx->r29, 0XDC);
    // 0x80800A54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800A58: jal         0x800BABB8
    // 0x80800A5C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_9;
    // 0x80800A5C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_9:
    // 0x80800A60: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    // 0x80800A64: addiu       $a1, $sp, 0xDC
    ctx->r5 = ADD32(ctx->r29, 0XDC);
    // 0x80800A68: addiu       $a2, $sp, 0xD0
    ctx->r6 = ADD32(ctx->r29, 0XD0);
    // 0x80800A6C: jal         0x800BA1D0
    // 0x80800A70: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BA1D0(rdram, ctx);
        goto after_10;
    // 0x80800A70: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_10:
    // 0x80800A74: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800A78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A7C: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80800A80: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800A84: jal         0x800DC0C0
    // 0x80800A88: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_11;
    // 0x80800A88: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x80800A8C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800A94: addiu       $a1, $zero, 0x8A3
    ctx->r5 = ADD32(0, 0X8A3);
    // 0x80800A98: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800A9C: nop

    // 0x80800AA0: bc1f        L_80800AB0
    if (!c1cs) {
        // 0x80800AA4: nop
    
            goto L_80800AB0;
    }
    // 0x80800AA4: nop

    // 0x80800AA8: b           L_80800AB0
    // 0x80800AAC: addiu       $a1, $zero, 0x8A2
    ctx->r5 = ADD32(0, 0X8A2);
        goto L_80800AB0;
    // 0x80800AAC: addiu       $a1, $zero, 0x8A2
    ctx->r5 = ADD32(0, 0X8A2);
L_80800AB0:
    // 0x80800AB0: jal         0x800BA670
    // 0x80800AB4: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    func_800BA670(rdram, ctx);
        goto after_12;
    // 0x80800AB4: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_12:
    // 0x80800AB8: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x80800ABC: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x80800AC0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80800AC4: jal         0x800BAA60
    // 0x80800AC8: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_800BAA60(rdram, ctx);
        goto after_13;
    // 0x80800AC8: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_13:
    // 0x80800ACC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800AD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800AD4: lwc1        $f16, 0xD4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80800AD8: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2420, 0X1440) << 16);
    // 0x80800ADC: addiu       $t1, $t1, 0x1440
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2420, 0X1440));
    // 0x80800AE0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800AE4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800AE8: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x80800AEC: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x80800AF0: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x80800AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800AF8: jal         0x800BABB8
    // 0x80800AFC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_14;
    // 0x80800AFC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_14:
    // 0x80800B00: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x80800B04: jal         0x800BA22C
    // 0x80800B08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800BA22C(rdram, ctx);
        goto after_15;
    // 0x80800B08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x80800B0C: lui         $a0, 0x5995
    ctx->r4 = S32(0X5995 << 16);
    // 0x80800B10: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x80800B14: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x80800B18: ori         $a0, $a0, 0x7C4B
    ctx->r4 = ctx->r4 | 0X7C4B;
    // 0x80800B1C: jal         0x800C4140
    // 0x80800B20: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    func_800C4140(rdram, ctx);
        goto after_16;
    // 0x80800B20: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    after_16:
    // 0x80800B24: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
L_80800B28:
    // 0x80800B28: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80800B2C: jal         0x80101E14
    // 0x80800B30: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    func_80101E14(rdram, ctx);
        goto after_17;
    // 0x80800B30: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    after_17:
    // 0x80800B34: beq         $v0, $zero, L_80800C84
    if (ctx->r2 == 0) {
        // 0x80800B38: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800C84;
    }
    // 0x80800B38: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800B3C: jal         0x800B53A4
    // 0x80800B40: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B53A4(rdram, ctx);
        goto after_18;
    // 0x80800B40: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_18:
    // 0x80800B44: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x80800B48: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800B4C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800B50: jal         0x8008A0D0
    // 0x80800B54: addiu       $a2, $sp, 0xBC
    ctx->r6 = ADD32(ctx->r29, 0XBC);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_19;
    // 0x80800B54: addiu       $a2, $sp, 0xBC
    ctx->r6 = ADD32(ctx->r29, 0XBC);
    after_19:
    // 0x80800B58: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x80800B5C: jal         0x800EE7F8
    // 0x80800B60: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    func_800EE7F8(rdram, ctx);
        goto after_20;
    // 0x80800B60: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    after_20:
    // 0x80800B64: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800B68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B6C: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80800B70: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x80800B74: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x80800B78: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800B7C: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    // 0x80800B80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800B84: jal         0x800BEF00
    // 0x80800B88: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    func_800BEF00(rdram, ctx);
        goto after_21;
    // 0x80800B88: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    after_21:
    // 0x80800B8C: jal         0x800DC0C0
    // 0x80800B90: nop

    func_800DC0C0(rdram, ctx);
        goto after_22;
    // 0x80800B90: nop

    after_22:
    // 0x80800B94: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800B98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B9C: addiu       $a1, $zero, 0x8A3
    ctx->r5 = ADD32(0, 0X8A3);
    // 0x80800BA0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800BA4: nop

    // 0x80800BA8: bc1f        L_80800BB8
    if (!c1cs) {
        // 0x80800BAC: nop
    
            goto L_80800BB8;
    }
    // 0x80800BAC: nop

    // 0x80800BB0: b           L_80800BB8
    // 0x80800BB4: addiu       $a1, $zero, 0x8A2
    ctx->r5 = ADD32(0, 0X8A2);
        goto L_80800BB8;
    // 0x80800BB4: addiu       $a1, $zero, 0x8A2
    ctx->r5 = ADD32(0, 0X8A2);
L_80800BB8:
    // 0x80800BB8: jal         0x800BA670
    // 0x80800BBC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    func_800BA670(rdram, ctx);
        goto after_23;
    // 0x80800BBC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_23:
    // 0x80800BC0: addiu       $t2, $zero, -0x12C
    ctx->r10 = ADD32(0, -0X12C);
    // 0x80800BC4: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x80800BC8: addiu       $t4, $zero, -0x96
    ctx->r12 = ADD32(0, -0X96);
    // 0x80800BCC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80800BD0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800BD4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800BD8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80800BDC: addiu       $a1, $zero, -0x15E
    ctx->r5 = ADD32(0, -0X15E);
    // 0x80800BE0: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80800BE4: jal         0x800BA930
    // 0x80800BE8: addiu       $a3, $zero, -0xC8
    ctx->r7 = ADD32(0, -0XC8);
    func_800BA930(rdram, ctx);
        goto after_24;
    // 0x80800BE8: addiu       $a3, $zero, -0xC8
    ctx->r7 = ADD32(0, -0XC8);
    after_24:
    // 0x80800BEC: addiu       $t5, $zero, 0xAF
    ctx->r13 = ADD32(0, 0XAF);
    // 0x80800BF0: addiu       $t6, $zero, -0xC8
    ctx->r14 = ADD32(0, -0XC8);
    // 0x80800BF4: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80800BF8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800BFC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800C00: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800C04: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80800C08: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80800C0C: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    // 0x80800C10: jal         0x800BA450
    // 0x80800C14: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    func_800BA450(rdram, ctx);
        goto after_25;
    // 0x80800C14: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_25:
    // 0x80800C18: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2420, 0X1440) << 16);
    // 0x80800C1C: addiu       $t8, $t8, 0x1440
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2420, 0X1440));
    // 0x80800C20: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800C24: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80800C28: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x80800C2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C30: jal         0x800BABB8
    // 0x80800C34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_26;
    // 0x80800C34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_26:
    // 0x80800C38: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80800C3C: jal         0x800BA22C
    // 0x80800C40: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800BA22C(rdram, ctx);
        goto after_27;
    // 0x80800C40: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_27:
    // 0x80800C44: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2420, 0X1404) << 16);
    // 0x80800C48: addiu       $t9, $t9, 0x1404
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2420, 0X1404));
    // 0x80800C4C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800C50: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x80800C54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C58: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800C5C: jal         0x800BBCB8
    // 0x80800C60: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_28;
    // 0x80800C60: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_28:
    // 0x80800C64: lui         $a0, 0x4CAE
    ctx->r4 = S32(0X4CAE << 16);
    // 0x80800C68: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x80800C6C: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x80800C70: ori         $a0, $a0, 0xA44B
    ctx->r4 = ctx->r4 | 0XA44B;
    // 0x80800C74: jal         0x800C4140
    // 0x80800C78: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    func_800C4140(rdram, ctx);
        goto after_29;
    // 0x80800C78: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    after_29:
    // 0x80800C7C: b           L_80800D3C
    // 0x80800C80: lui         $a1, 0x3ED7
    ctx->r5 = S32(0X3ED7 << 16);
        goto L_80800D3C;
    // 0x80800C80: lui         $a1, 0x3ED7
    ctx->r5 = S32(0X3ED7 << 16);
L_80800C84:
    // 0x80800C84: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800C88: jal         0x80101E14
    // 0x80800C8C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_30;
    // 0x80800C8C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_30:
    // 0x80800C90: bne         $v0, $zero, L_80800CBC
    if (ctx->r2 != 0) {
        // 0x80800C94: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800CBC;
    }
    // 0x80800C94: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800C98: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
    // 0x80800C9C: jal         0x80101E14
    // 0x80800CA0: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    func_80101E14(rdram, ctx);
        goto after_31;
    // 0x80800CA0: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    after_31:
    // 0x80800CA4: bne         $v0, $zero, L_80800CBC
    if (ctx->r2 != 0) {
        // 0x80800CA8: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800CBC;
    }
    // 0x80800CA8: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800CAC: jal         0x80101E14
    // 0x80800CB0: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80101E14(rdram, ctx);
        goto after_32;
    // 0x80800CB0: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_32:
    // 0x80800CB4: beql        $v0, $zero, L_80800D3C
    if (ctx->r2 == 0) {
        // 0x80800CB8: lui         $a1, 0x3ED7
        ctx->r5 = S32(0X3ED7 << 16);
            goto L_80800D3C;
    }
    goto skip_1;
    // 0x80800CB8: lui         $a1, 0x3ED7
    ctx->r5 = S32(0X3ED7 << 16);
    skip_1:
L_80800CBC:
    // 0x80800CBC: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800CC0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800CC4: jal         0x8008A0D0
    // 0x80800CC8: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_33;
    // 0x80800CC8: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    after_33:
    // 0x80800CCC: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80800CD0: jal         0x800EE7F8
    // 0x80800CD4: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    func_800EE7F8(rdram, ctx);
        goto after_34;
    // 0x80800CD4: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    after_34:
    // 0x80800CD8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800CDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800CE0: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800CE4: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80800CE8: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80800CEC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800CF0: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x80800CF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800CF8: jal         0x800BEF00
    // 0x80800CFC: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    func_800BEF00(rdram, ctx);
        goto after_35;
    // 0x80800CFC: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    after_35:
    // 0x80800D00: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2420, 0X1404) << 16);
    // 0x80800D04: addiu       $t0, $t0, 0x1404
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2420, 0X1404));
    // 0x80800D08: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800D0C: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80800D10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D14: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800D18: jal         0x800BBCB8
    // 0x80800D1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_36;
    // 0x80800D1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_36:
    // 0x80800D20: lui         $a0, 0x4CAE
    ctx->r4 = S32(0X4CAE << 16);
    // 0x80800D24: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x80800D28: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x80800D2C: ori         $a0, $a0, 0xA44B
    ctx->r4 = ctx->r4 | 0XA44B;
    // 0x80800D30: jal         0x800C4140
    // 0x80800D34: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    func_800C4140(rdram, ctx);
        goto after_37;
    // 0x80800D34: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_37:
    // 0x80800D38: lui         $a1, 0x3ED7
    ctx->r5 = S32(0X3ED7 << 16);
L_80800D3C:
    // 0x80800D3C: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    // 0x80800D40: jal         0x80101E14
    // 0x80800D44: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    func_80101E14(rdram, ctx);
        goto after_38;
    // 0x80800D44: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    after_38:
    // 0x80800D48: beq         $v0, $zero, L_80800E24
    if (ctx->r2 == 0) {
        // 0x80800D4C: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800E24;
    }
    // 0x80800D4C: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800D50: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80800D54: jal         0x8008A0D0
    // 0x80800D58: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_39;
    // 0x80800D58: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_39:
    // 0x80800D5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X1328) << 16);
    // 0x80800D60: lwc1        $f12, 0x1328($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2420, 0X1328));
    // 0x80800D64: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X132C) << 16);
    // 0x80800D68: jal         0x800DC178
    // 0x80800D6C: lwc1        $f14, 0x132C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2420, 0X132C));
    func_800DC178(rdram, ctx);
        goto after_40;
    // 0x80800D6C: lwc1        $f14, 0x132C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2420, 0X132C));
    after_40:
    // 0x80800D70: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X1330) << 16);
    // 0x80800D74: lwc1        $f8, 0x1330($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2420, 0X1330));
    // 0x80800D78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800D7C: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x80800D80: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800D84: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x80800D88: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800D8C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80800D90: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80800D94: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800D98: nop

    // 0x80800D9C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800DA0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800DA4: nop

    // 0x80800DA8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800DAC: beql        $a0, $zero, L_80800DFC
    if (ctx->r4 == 0) {
        // 0x80800DB0: mfc1        $a0, $f16
        ctx->r4 = (int32_t)ctx->f16.u32l;
            goto L_80800DFC;
    }
    goto skip_2;
    // 0x80800DB0: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x80800DB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800DB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800DBC: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800DC0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800DC4: nop

    // 0x80800DC8: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800DCC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800DD0: nop

    // 0x80800DD4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800DD8: bne         $a0, $zero, L_80800DF0
    if (ctx->r4 != 0) {
        // 0x80800DDC: nop
    
            goto L_80800DF0;
    }
    // 0x80800DDC: nop

    // 0x80800DE0: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80800DE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800DE8: b           L_80800E08
    // 0x80800DEC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800E08;
    // 0x80800DEC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800DF0:
    // 0x80800DF0: b           L_80800E08
    // 0x80800DF4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800E08;
    // 0x80800DF4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800DF8: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
L_80800DFC:
    // 0x80800DFC: nop

    // 0x80800E00: bltz        $a0, L_80800DF0
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800E04: nop
    
            goto L_80800DF0;
    }
    // 0x80800E04: nop

L_80800E08:
    // 0x80800E08: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80800E0C: lui         $at, 0xB
    ctx->r1 = S32(0XB << 16);
    // 0x80800E10: ori         $at, $at, 0xBCCA
    ctx->r1 = ctx->r1 | 0XBCCA;
    // 0x80800E14: sll         $t3, $t2, 21
    ctx->r11 = S32(ctx->r10 << 21);
    // 0x80800E18: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800E1C: jal         0x800C4140
    // 0x80800E20: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_41;
    // 0x80800E20: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    after_41:
L_80800E24:
    // 0x80800E24: lui         $a1, 0x3F45
    ctx->r5 = S32(0X3F45 << 16);
    // 0x80800E28: ori         $a1, $a1, 0xA1CB
    ctx->r5 = ctx->r5 | 0XA1CB;
    // 0x80800E2C: jal         0x80101E14
    // 0x80800E30: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    func_80101E14(rdram, ctx);
        goto after_42;
    // 0x80800E30: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    after_42:
    // 0x80800E34: beq         $v0, $zero, L_80801108
    if (ctx->r2 == 0) {
        // 0x80800E38: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80801108;
    }
    // 0x80800E38: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800E3C: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80800E40: jal         0x8008A0D0
    // 0x80800E44: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_43;
    // 0x80800E44: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_43:
    // 0x80800E48: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800E4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800E50: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X1334) << 16);
    // 0x80800E54: jal         0x800DC178
    // 0x80800E58: lwc1        $f14, 0x1334($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2420, 0X1334));
    func_800DC178(rdram, ctx);
        goto after_44;
    // 0x80800E58: lwc1        $f14, 0x1334($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2420, 0X1334));
    after_44:
    // 0x80800E5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X1338) << 16);
    // 0x80800E60: lwc1        $f18, 0x1338($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2420, 0X1338));
    // 0x80800E64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800E68: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x80800E6C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800E70: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x80800E74: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800E78: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80800E7C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80800E80: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800E84: nop

    // 0x80800E88: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800E8C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800E90: nop

    // 0x80800E94: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800E98: beql        $a0, $zero, L_80800EE8
    if (ctx->r4 == 0) {
        // 0x80800E9C: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_80800EE8;
    }
    goto skip_3;
    // 0x80800E9C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x80800EA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800EA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800EA8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800EAC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800EB0: nop

    // 0x80800EB4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800EB8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800EBC: nop

    // 0x80800EC0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800EC4: bne         $a0, $zero, L_80800EDC
    if (ctx->r4 != 0) {
        // 0x80800EC8: nop
    
            goto L_80800EDC;
    }
    // 0x80800EC8: nop

    // 0x80800ECC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800ED0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800ED4: b           L_80800EF4
    // 0x80800ED8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800EF4;
    // 0x80800ED8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800EDC:
    // 0x80800EDC: b           L_80800EF4
    // 0x80800EE0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800EF4;
    // 0x80800EE0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800EE4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_80800EE8:
    // 0x80800EE8: nop

    // 0x80800EEC: bltz        $a0, L_80800EDC
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800EF0: nop
    
            goto L_80800EDC;
    }
    // 0x80800EF0: nop

L_80800EF4:
    // 0x80800EF4: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
    // 0x80800EF8: lui         $at, 0xB
    ctx->r1 = S32(0XB << 16);
    // 0x80800EFC: ori         $at, $at, 0xBCCA
    ctx->r1 = ctx->r1 | 0XBCCA;
    // 0x80800F00: sll         $t6, $t5, 21
    ctx->r14 = S32(ctx->r13 << 21);
    // 0x80800F04: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80800F08: jal         0x800C4140
    // 0x80800F0C: addu        $a0, $t6, $at
    ctx->r4 = ADD32(ctx->r14, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_45;
    // 0x80800F0C: addu        $a0, $t6, $at
    ctx->r4 = ADD32(ctx->r14, ctx->r1);
    after_45:
    // 0x80800F10: b           L_8080110C
    // 0x80800F14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080110C;
    // 0x80800F14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F18:
    // 0x80800F18: jal         0x80101E14
    // 0x80800F1C: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    func_80101E14(rdram, ctx);
        goto after_46;
    // 0x80800F1C: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    after_46:
    // 0x80800F20: bne         $v0, $zero, L_80800F8C
    if (ctx->r2 != 0) {
        // 0x80800F24: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800F8C;
    }
    // 0x80800F24: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800F28: lui         $a1, 0x3E42
    ctx->r5 = S32(0X3E42 << 16);
    // 0x80800F2C: jal         0x80101E14
    // 0x80800F30: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    func_80101E14(rdram, ctx);
        goto after_47;
    // 0x80800F30: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    after_47:
    // 0x80800F34: bne         $v0, $zero, L_80800F8C
    if (ctx->r2 != 0) {
        // 0x80800F38: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800F8C;
    }
    // 0x80800F38: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800F3C: lui         $a1, 0x3EB8
    ctx->r5 = S32(0X3EB8 << 16);
    // 0x80800F40: jal         0x80101E14
    // 0x80800F44: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    func_80101E14(rdram, ctx);
        goto after_48;
    // 0x80800F44: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    after_48:
    // 0x80800F48: bne         $v0, $zero, L_80800F8C
    if (ctx->r2 != 0) {
        // 0x80800F4C: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800F8C;
    }
    // 0x80800F4C: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800F50: lui         $a1, 0x3F05
    ctx->r5 = S32(0X3F05 << 16);
    // 0x80800F54: jal         0x80101E14
    // 0x80800F58: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    func_80101E14(rdram, ctx);
        goto after_49;
    // 0x80800F58: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    after_49:
    // 0x80800F5C: bne         $v0, $zero, L_80800F8C
    if (ctx->r2 != 0) {
        // 0x80800F60: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800F8C;
    }
    // 0x80800F60: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800F64: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800F68: jal         0x80101E14
    // 0x80800F6C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_50;
    // 0x80800F6C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_50:
    // 0x80800F70: bne         $v0, $zero, L_80800F8C
    if (ctx->r2 != 0) {
        // 0x80800F74: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800F8C;
    }
    // 0x80800F74: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800F78: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80800F7C: jal         0x80101E14
    // 0x80800F80: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_51;
    // 0x80800F80: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_51:
    // 0x80800F84: beql        $v0, $zero, L_80800FD8
    if (ctx->r2 == 0) {
        // 0x80800F88: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800FD8;
    }
    goto skip_4;
    // 0x80800F88: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    skip_4:
L_80800F8C:
    // 0x80800F8C: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800F90: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x80800F94: jal         0x8008A0D0
    // 0x80800F98: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_52;
    // 0x80800F98: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_52:
    // 0x80800F9C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2420, 0X1404) << 16);
    // 0x80800FA0: addiu       $t7, $t7, 0x1404
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2420, 0X1404));
    // 0x80800FA4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800FA8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80800FAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800FB0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800FB4: jal         0x800BBCB8
    // 0x80800FB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_53;
    // 0x80800FB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_53:
    // 0x80800FBC: lui         $a0, 0x4CB5
    ctx->r4 = S32(0X4CB5 << 16);
    // 0x80800FC0: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x80800FC4: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x80800FC8: ori         $a0, $a0, 0x7C4B
    ctx->r4 = ctx->r4 | 0X7C4B;
    // 0x80800FCC: jal         0x800C4140
    // 0x80800FD0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800C4140(rdram, ctx);
        goto after_54;
    // 0x80800FD0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_54:
    // 0x80800FD4: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
L_80800FD8:
    // 0x80800FD8: jal         0x80101E14
    // 0x80800FDC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_55;
    // 0x80800FDC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_55:
    // 0x80800FE0: bne         $v0, $zero, L_80800FFC
    if (ctx->r2 != 0) {
        // 0x80800FE4: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80800FFC;
    }
    // 0x80800FE4: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80800FE8: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800FEC: jal         0x80101E14
    // 0x80800FF0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_56;
    // 0x80800FF0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_56:
    // 0x80800FF4: beql        $v0, $zero, L_8080110C
    if (ctx->r2 == 0) {
        // 0x80800FF8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080110C;
    }
    goto skip_5;
    // 0x80800FF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
L_80800FFC:
    // 0x80800FFC: jal         0x800B53A4
    // 0x80801000: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B53A4(rdram, ctx);
        goto after_57;
    // 0x80801000: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_57:
    // 0x80801004: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80801008: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x8080100C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80801010: jal         0x8008A0D0
    // 0x80801014: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_58;
    // 0x80801014: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_58:
    // 0x80801018: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080101C: jal         0x800EE7F8
    // 0x80801020: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_59;
    // 0x80801020: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_59:
    // 0x80801024: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80801028: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080102C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801030: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80801034: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80801038: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8080103C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80801040: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801044: jal         0x800BEF00
    // 0x80801048: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    func_800BEF00(rdram, ctx);
        goto after_60;
    // 0x80801048: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_60:
    // 0x8080104C: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x80801050: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x80801054: addiu       $t0, $zero, 0x15E
    ctx->r8 = ADD32(0, 0X15E);
    // 0x80801058: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8080105C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801060: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801064: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801068: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x8080106C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80801070: jal         0x800BA930
    // 0x80801074: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    func_800BA930(rdram, ctx);
        goto after_61;
    // 0x80801074: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    after_61:
    // 0x80801078: addiu       $t1, $zero, -0x64
    ctx->r9 = ADD32(0, -0X64);
    // 0x8080107C: addiu       $t2, $zero, -0xC8
    ctx->r10 = ADD32(0, -0XC8);
    // 0x80801080: addiu       $t3, $zero, -0xAF
    ctx->r11 = ADD32(0, -0XAF);
    // 0x80801084: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80801088: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8080108C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801090: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801094: addiu       $a1, $zero, -0x32
    ctx->r5 = ADD32(0, -0X32);
    // 0x80801098: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    // 0x8080109C: jal         0x800BA450
    // 0x808010A0: addiu       $a3, $zero, -0x64
    ctx->r7 = ADD32(0, -0X64);
    func_800BA450(rdram, ctx);
        goto after_62;
    // 0x808010A0: addiu       $a3, $zero, -0x64
    ctx->r7 = ADD32(0, -0X64);
    after_62:
    // 0x808010A4: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2420, 0X1440) << 16);
    // 0x808010A8: addiu       $t4, $t4, 0x1440
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2420, 0X1440));
    // 0x808010AC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808010B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808010B4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808010B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808010BC: jal         0x800BABB8
    // 0x808010C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_63;
    // 0x808010C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_63:
    // 0x808010C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808010C8: jal         0x800BA22C
    // 0x808010CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800BA22C(rdram, ctx);
        goto after_64;
    // 0x808010CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_64:
    // 0x808010D0: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2420, 0X1404) << 16);
    // 0x808010D4: addiu       $t5, $t5, 0x1404
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2420, 0X1404));
    // 0x808010D8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808010DC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808010E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808010E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808010E8: jal         0x800BBCB8
    // 0x808010EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_65;
    // 0x808010EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_65:
    // 0x808010F0: lui         $a0, 0x3FED
    ctx->r4 = S32(0X3FED << 16);
    // 0x808010F4: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x808010F8: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x808010FC: ori         $a0, $a0, 0xAC11
    ctx->r4 = ctx->r4 | 0XAC11;
    // 0x80801100: jal         0x800C4140
    // 0x80801104: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800C4140(rdram, ctx);
        goto after_66;
    // 0x80801104: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_66:
L_80801108:
    // 0x80801108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080110C:
    // 0x8080110C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x80801110: jr          $ra
    // 0x80801114: nop

    return;
    // 0x80801114: nop

;}
RECOMP_FUNC void _glgamedata_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885A0: syscall     693
    recomp_syscall_handler(rdram, ctx, 0x800885A0);
    return;
    // 0x800885A4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _chmole_training_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A38: syscall     408
    recomp_syscall_handler(rdram, ctx, 0x80086A38);
    return;
    // 0x80086A3C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void ncpod_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F60: jal         0x80110024
    // 0x80800F64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80110024(rdram, ctx);
        goto after_0;
    // 0x80800F64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800F68: jal         0x80089638
    // 0x80800F6C: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    _ncpoducam_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800F6C: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x80800F70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F74: jal         0x80089688
    // 0x80800F78: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _ncpoducam_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800F78: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F84: jr          $ra
    // 0x80800F88: nop

    return;
    // 0x80800F88: nop

;}
RECOMP_FUNC void chfactorybtwmdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800314: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2288, 0X344) << 16);
    // 0x80800318: jr          $ra
    // 0x8080031C: addiu       $v0, $v0, 0x344
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2288, 0X344));
    return;
    // 0x8080031C: addiu       $v0, $v0, 0x344
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2288, 0X344));
;}
RECOMP_FUNC void _gcgoto_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AC8: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087AC8);
    return;
    // 0x80087ACC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_8080010C_dbzone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x80800110: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80800114: slt         $v0, $v1, $t6
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800118: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8080011C: beq         $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x80800120: nop
    
            goto L_80800188;
    }
    // 0x80800120: nop

    // 0x80800124: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x80800128: slt         $v0, $t7, $v1
    ctx->r2 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8080012C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80800130: beq         $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x80800134: nop
    
            goto L_80800188;
    }
    // 0x80800134: nop

    // 0x80800138: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x8080013C: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x80800140: slt         $v0, $v1, $t8
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800144: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80800148: beq         $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x8080014C: nop
    
            goto L_80800188;
    }
    // 0x8080014C: nop

    // 0x80800150: lh          $t9, 0x8($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8);
    // 0x80800154: slt         $v0, $t9, $v1
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800158: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8080015C: beq         $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x80800160: nop
    
            goto L_80800188;
    }
    // 0x80800160: nop

    // 0x80800164: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x80800168: lh          $t0, 0x4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4);
    // 0x8080016C: slt         $v0, $v1, $t0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80800170: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80800174: beq         $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x80800178: nop
    
            goto L_80800188;
    }
    // 0x80800178: nop

    // 0x8080017C: lh          $t1, 0xA($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XA);
    // 0x80800180: slt         $v0, $t1, $v1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800184: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_80800188:
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D20: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083D20);
    return;
    // 0x80083D24: addi        $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
;}
RECOMP_FUNC void gclevel_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080013C: jal         0x80800314
    // 0x80800140: nop

    func_80800314_gclevel(rdram, ctx);
        goto after_0;
    // 0x80800140: nop

    after_0:
    // 0x80800144: bne         $v0, $zero, L_80800154
    if (ctx->r2 != 0) {
        // 0x80800148: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800154;
    }
    // 0x80800148: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080014C: b           L_8080015C
    // 0x80800150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080015C;
    // 0x80800150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800154:
    // 0x80800154: jal         0x800DA298
    // 0x80800158: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800158: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    after_1:
L_8080015C:
    // 0x8080015C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void glsavegame_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080049C: jr          $ra
    // 0x808004A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808004A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800DD024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DD028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DD02C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DD030: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800DD034: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800DD038: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DD03C: lw          $t6, -0x36A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36A0);
    // 0x800DD040: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800DD044: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800DD048: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x800DD04C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800DD050: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800DD054: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x800DD058: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800DD05C: jal         0x8002E330
    // 0x800DD060: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800DD060: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800DD064: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD068: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800DD06C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DD070: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800DD074: jr          $ra
    // 0x800DD078: nop

    return;
    // 0x800DD078: nop

;}
RECOMP_FUNC void func_8080019C_bsbbilldrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001A4: jal         0x800DC0C0
    // 0x808001A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x808001A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(61, 0XA60) << 16);
    // 0x808001B0: lwc1        $f4, 0xA60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(61, 0XA60));
    // 0x808001B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(61, 0XA68) << 16);
    // 0x808001B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808001BC: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x808001C0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808001C4: bc1f        L_808001D8
    if (!c1cs) {
        // 0x808001C8: nop
    
            goto L_808001D8;
    }
    // 0x808001C8: nop

    // 0x808001CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(61, 0XA64) << 16);
    // 0x808001D0: b           L_808001DC
    // 0x808001D4: lwc1        $f0, 0xA64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(61, 0XA64));
        goto L_808001DC;
    // 0x808001D4: lwc1        $f0, 0xA64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(61, 0XA64));
L_808001D8:
    // 0x808001D8: lwc1        $f0, 0xA68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(61, 0XA68));
L_808001DC:
    // 0x808001DC: jal         0x8009C128
    // 0x808001E0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x808001E0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x808001E4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808001E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001EC: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808001F0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808001F4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808001F8: jal         0x80800158
    // 0x808001FC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    func_80800158_bsbbilldrill(rdram, ctx);
        goto after_2;
    // 0x808001FC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80800200: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800204: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800208: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080020C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800210: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800214: jal         0x800BA7C4
    // 0x80800218: nop

    func_800BA7C4(rdram, ctx);
        goto after_3;
    // 0x80800218: nop

    after_3:
    // 0x8080021C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800220: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800224: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800228: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080022C: jal         0x800BA7FC
    // 0x80800230: nop

    func_800BA7FC(rdram, ctx);
        goto after_4;
    // 0x80800230: nop

    after_4:
    // 0x80800234: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800238: jal         0x800BA22C
    // 0x8080023C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x8080023C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800244: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800248: jr          $ra
    // 0x8080024C: nop

    return;
    // 0x8080024C: nop

;}
RECOMP_FUNC void batranslate_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: jr          $ra
    // 0x80800068: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800068: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void bsvanswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800608: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080060C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(431, 0X990) << 16);
    // 0x80800610: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800614: jr          $ra
    // 0x80800618: lw          $v0, 0x990($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(431, 0X990));
    return;
    // 0x80800618: lw          $v0, 0x990($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(431, 0X990));
;}
RECOMP_FUNC void func_80801318_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801318: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080131C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801320: jal         0x808009B0
    // 0x80801324: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_808009B0_bssub(rdram, ctx);
        goto after_0;
    // 0x80801324: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801328: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x8080132C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801330: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801334: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801338: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080133C: addiu       $a1, $zero, 0x130
    ctx->r5 = ADD32(0, 0X130);
    // 0x80801340: jal         0x80085150
    // 0x80801344: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _baspin_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801344: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80801348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080134C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801350: jr          $ra
    // 0x80801354: nop

    return;
    // 0x80801354: nop

;}
RECOMP_FUNC void func_800DC128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC12C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC130: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DC134: jal         0x800DC0C0
    // 0x800DC138: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x800DC138: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800DC13C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800DC140: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800DC144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC148: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800DC14C: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x800DC150: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800DC154: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800DC158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC15C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DC160: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800DC164: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800DC168: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800DC16C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800DC170: jr          $ra
    // 0x800DC174: nop

    return;
    // 0x800DC174: nop

;}
RECOMP_FUNC void _idwave_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D28: syscall     736
    recomp_syscall_handler(rdram, ctx, 0x80088D28);
    return;
    // 0x80088D2C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080666C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080666C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806674: jal         0x80100094
    // 0x80806678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080667C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80806680: jal         0x80089D48
    // 0x80806684: lbu         $a0, 0x78($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X78);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80806684: lbu         $a0, 0x78($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X78);
    after_1:
    // 0x80806688: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080668C: sb          $v0, 0x78($t6)
    MEM_B(0X78, ctx->r14) = ctx->r2;
    // 0x80806690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806698: jr          $ra
    // 0x8080669C: nop

    return;
    // 0x8080669C: nop

;}
RECOMP_FUNC void func_808000A8_chjiggytemple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: jr          $ra
    // 0x808000AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800540_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800544: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800548: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080054C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800550: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800554: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800558: jal         0x800EE7F8
    // 0x8080055C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080055C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800560: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800564: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800568: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080056C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800570: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800574: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800578: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080057C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800580: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80800584: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80800588: lwc1        $f10, 0x48($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X48);
    // 0x8080058C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800590: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800594: jal         0x800EF1B8
    // 0x80800598: nop

    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800598: nop

    after_1:
    // 0x8080059C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(964, 0X8F4) << 16);
    // 0x808005A0: addiu       $t7, $t7, 0x8F4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(964, 0X8F4));
    // 0x808005A4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808005A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005AC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808005B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005B4: jal         0x800BBCB8
    // 0x808005B8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x808005B8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_2:
    // 0x808005BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(964, 0X924) << 16);
    // 0x808005C0: addiu       $a2, $a2, 0x924
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(964, 0X924));
    // 0x808005C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808005C8: jal         0x80089D18
    // 0x808005CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808005CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808005D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005D8: jr          $ra
    // 0x808005DC: nop

    return;
    // 0x808005DC: nop

;}
RECOMP_FUNC void func_808012A4_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808012A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808012B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808012B4: jal         0x80100094
    // 0x808012B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808012B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808012BC: lbu         $v1, 0x25($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X25);
    // 0x808012C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808012C4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808012C8: beq         $v1, $at, L_808012FC
    if (ctx->r3 == ctx->r1) {
        // 0x808012CC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808012FC;
    }
    // 0x808012CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808012D0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808012D4: beq         $v1, $at, L_808012E8
    if (ctx->r3 == ctx->r1) {
        // 0x808012D8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808012E8;
    }
    // 0x808012D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808012DC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808012E0: bnel        $v1, $at, L_80801300
    if (ctx->r3 != ctx->r1) {
        // 0x808012E4: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_80801300;
    }
    goto skip_0;
    // 0x808012E4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_808012E8:
    // 0x808012E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808012EC: jal         0x80090658
    // 0x808012F0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80090658(rdram, ctx);
        goto after_1;
    // 0x808012F0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x808012F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808012F8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_808012FC:
    // 0x808012FC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80801300:
    // 0x80801300: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80801304: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x80801308: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x8080130C: beq         $at, $zero, L_808013A4
    if (ctx->r1 == 0) {
        // 0x80801310: sb          $t6, 0x25($a1)
        MEM_B(0X25, ctx->r5) = ctx->r14;
            goto L_808013A4;
    }
    // 0x80801310: sb          $t6, 0x25($a1)
    MEM_B(0X25, ctx->r5) = ctx->r14;
    // 0x80801314: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801318: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3F44) << 16);
    // 0x8080131C: addu        $at, $at, $t8
    gpr jr_addend_80801324 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801320: lw          $t8, 0x3F44($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3F44));
    // 0x80801324: jr          $t8
    // 0x80801328: nop

    switch (jr_addend_80801324 >> 2) {
        case 0: goto L_808013A4; break;
        case 1: goto L_8080133C; break;
        case 2: goto L_808013A4; break;
        case 3: goto L_8080132C; break;
        case 4: goto L_8080132C; break;
        case 5: goto L_80801364; break;
        case 6: goto L_8080137C; break;
        case 7: goto L_80801394; break;
        default: switch_error(__func__, 0x80801324, 0x80803F44);
    }
    // 0x80801328: nop

L_8080132C:
    // 0x8080132C: jal         0x80090658
    // 0x80801330: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090658(rdram, ctx);
        goto after_2;
    // 0x80801330: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80801334: b           L_808013A8
    // 0x80801338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808013A8;
    // 0x80801338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080133C:
    // 0x8080133C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801340: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801344: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801348: swc1        $f4, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->f4.u32l;
    // 0x8080134C: jal         0x800FDC28
    // 0x80801350: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800FDC28(rdram, ctx);
        goto after_3;
    // 0x80801350: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x80801354: jal         0x80800F98
    // 0x80801358: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800F98_chflysaucer(rdram, ctx);
        goto after_4;
    // 0x80801358: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8080135C: b           L_808013A8
    // 0x80801360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808013A8;
    // 0x80801360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801364:
    // 0x80801364: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801368: addiu       $a1, $zero, 0x10C8
    ctx->r5 = ADD32(0, 0X10C8);
    // 0x8080136C: jal         0x8080105C
    // 0x80801370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_5;
    // 0x80801370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80801374: b           L_808013A8
    // 0x80801378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808013A8;
    // 0x80801378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080137C:
    // 0x8080137C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801380: addiu       $a1, $zero, 0x10C9
    ctx->r5 = ADD32(0, 0X10C9);
    // 0x80801384: jal         0x8080105C
    // 0x80801388: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_6;
    // 0x80801388: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8080138C: b           L_808013A8
    // 0x80801390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808013A8;
    // 0x80801390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801394:
    // 0x80801394: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801398: addiu       $a1, $zero, 0x10E5
    ctx->r5 = ADD32(0, 0X10E5);
    // 0x8080139C: jal         0x8080105C
    // 0x808013A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_7;
    // 0x808013A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
L_808013A4:
    // 0x808013A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013A8:
    // 0x808013A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808013AC: jr          $ra
    // 0x808013B0: nop

    return;
    // 0x808013B0: nop

;}
RECOMP_FUNC void func_80800290_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800298: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080029C: jal         0x80100094
    // 0x808002A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808002A8: lbu         $v1, 0x95($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X95);
    // 0x808002AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002B0: beq         $v1, $at, L_808002E0
    if (ctx->r3 == ctx->r1) {
        // 0x808002B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808002E0;
    }
    // 0x808002B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002B8: beq         $v1, $at, L_808002E0
    if (ctx->r3 == ctx->r1) {
        // 0x808002BC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808002E0;
    }
    // 0x808002BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808002C0: bnel        $v1, $at, L_808002EC
    if (ctx->r3 != ctx->r1) {
        // 0x808002C4: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_808002EC;
    }
    goto skip_0;
    // 0x808002C4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002C8: jal         0x800F54E4
    // 0x808002CC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808002CC: nop

    after_1:
    // 0x808002D0: jal         0x800F4B20
    // 0x808002D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4B20(rdram, ctx);
        goto after_2;
    // 0x808002D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808002D8: b           L_808002EC
    // 0x808002DC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
        goto L_808002EC;
    // 0x808002DC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_808002E0:
    // 0x808002E0: jal         0x80800098
    // 0x808002E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800098_chevilmumbo(rdram, ctx);
        goto after_3;
    // 0x808002E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808002E8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_808002EC:
    // 0x808002EC: sb          $zero, 0x95($t6)
    MEM_B(0X95, ctx->r14) = 0;
    // 0x808002F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002F8: jr          $ra
    // 0x808002FC: nop

    return;
    // 0x808002FC: nop

;}
RECOMP_FUNC void func_800F0E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0E00: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x800F0E04: nop

    // 0x800F0E08: bc1fl       L_800F0E20
    if (!c1cs) {
        // 0x800F0E0C: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_800F0E20;
    }
    goto skip_0;
    // 0x800F0E0C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_0:
    // 0x800F0E10: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800F0E14: jr          $ra
    // 0x800F0E18: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x800F0E18: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800F0E1C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_800F0E20:
    // 0x800F0E20: jr          $ra
    // 0x800F0E24: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800F0E24: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80800018_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080001C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
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
    // 0x80800030: jal         0x80088848
    // 0x80800034: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800034: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800038: beq         $v0, $zero, L_80800058
    if (ctx->r2 == 0) {
        // 0x8080003C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800058;
    }
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x80102424
    // 0x80800044: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800044: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_2:
    // 0x80800048: lbu         $t6, 0x75($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X75);
    // 0x8080004C: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800050: b           L_80800180
    // 0x80800054: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
        goto L_80800180;
    // 0x80800054: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
L_80800058:
    // 0x80800058: jal         0x800DA298
    // 0x8080005C: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080005C: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_3:
    // 0x80800060: beq         $v0, $zero, L_8080012C
    if (ctx->r2 == 0) {
        // 0x80800064: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080012C;
    }
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080006C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800070: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x80800074: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80800078: jal         0x8008A0C8
    // 0x8080007C: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080007C: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80800080: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800084: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800088: jal         0x800EE7F8
    // 0x8080008C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x8080008C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80800090: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800094: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800098: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080009C: jal         0x800DC178
    // 0x808000A0: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808000A0: nop

    after_6:
    // 0x808000A4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808000A8: jal         0x8008A498
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808000B8: jal         0x80089F70
    // 0x808000BC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808000BC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x80102424
    // 0x808000C8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x808000C8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_9:
    // 0x808000CC: jal         0x8010A590
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_10;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808000D4: jal         0x80104E78
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104E78(rdram, ctx);
        goto after_11;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808000DC: lbu         $t0, 0x75($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X75);
    // 0x808000E0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808000E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000E8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x808000EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000F0: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x808000F4: jal         0x800DC178
    // 0x808000F8: sb          $t1, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r9;
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x808000F8: sb          $t1, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r9;
    after_12:
    // 0x808000FC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800100: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800104: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800108: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080010C: jal         0x800DC178
    // 0x80800110: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x80800110: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    after_13:
    // 0x80800114: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80800118: swc1        $f0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f0.u32l;
    // 0x8080011C: lbu         $t4, 0x7B($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X7B);
    // 0x80800120: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80800124: b           L_80800180
    // 0x80800128: sb          $t5, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r13;
        goto L_80800180;
    // 0x80800128: sb          $t5, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r13;
L_8080012C:
    // 0x8080012C: jal         0x800DA298
    // 0x80800130: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x80800130: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_14:
    // 0x80800134: beql        $v0, $zero, L_80800178
    if (ctx->r2 == 0) {
        // 0x80800138: lbu         $t8, 0x75($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X75);
            goto L_80800178;
    }
    goto skip_0;
    // 0x80800138: lbu         $t8, 0x75($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X75);
    skip_0:
    // 0x8080013C: jal         0x800DA298
    // 0x80800140: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x80800140: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_15:
    // 0x80800144: bne         $v0, $zero, L_8080015C
    if (ctx->r2 != 0) {
        // 0x80800148: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080015C;
    }
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x800FFAB0
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_16;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800154: b           L_80800184
    // 0x80800158: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800184;
    // 0x80800158: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080015C:
    // 0x8080015C: jal         0x80102424
    // 0x80800160: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x80800160: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_17:
    // 0x80800164: lbu         $t6, 0x75($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X75);
    // 0x80800168: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x8080016C: b           L_80800180
    // 0x80800170: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
        goto L_80800180;
    // 0x80800170: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
    // 0x80800174: lbu         $t8, 0x75($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X75);
L_80800178:
    // 0x80800178: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x8080017C: sb          $t9, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r25;
L_80800180:
    // 0x80800180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800184:
    // 0x80800184: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800188: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void _sccustom_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A650: syscall     846
    recomp_syscall_handler(rdram, ctx, 0x8008A650);
    return;
    // 0x8008A654: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void fxstep_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800648: lbu         $t6, 0x27($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X27);
    // 0x8080064C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800650: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800654: beql        $t6, $zero, L_80800668
    if (ctx->r14 == 0) {
        // 0x80800658: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800668;
    }
    goto skip_0;
    // 0x80800658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080065C: jal         0x80800210
    // 0x80800660: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_80800210_fxstep(rdram, ctx);
        goto after_0;
    // 0x80800660: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x80800664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800668:
    // 0x80800668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080066C: jr          $ra
    // 0x80800670: nop

    return;
    // 0x80800670: nop

;}
RECOMP_FUNC void func_808003C4_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003D0: jal         0x800F54E4
    // 0x808003D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808003D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003D8: jal         0x800EA090
    // 0x808003DC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800EA090(rdram, ctx);
        goto after_1;
    // 0x808003DC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x808003E0: jal         0x808008B4
    // 0x808003E4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_808008B4_chdumbwaiterlift(rdram, ctx);
        goto after_2;
    // 0x808003E4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x808003E8: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x808003EC: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1200, 0XBC2) << 16);
    // 0x808003F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808003F4: lh          $t8, 0xBC2($t8)
    ctx->r24 = MEM_H(ctx->r24, (int16_t)RELOC_LO16(1200, 0XBC2));
    // 0x808003F8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808003FC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800400: bnel        $t6, $t8, L_808004D8
    if (ctx->r14 != ctx->r24) {
        // 0x80800404: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808004D8;
    }
    goto skip_0;
    // 0x80800404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800408: jal         0x8080094C
    // 0x8080040C: nop

    func_8080094C_chdumbwaiterlift(rdram, ctx);
        goto after_3;
    // 0x8080040C: nop

    after_3:
    // 0x80800410: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800414: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800418: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8080041C: jal         0x800EE7F8
    // 0x80800420: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800420: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_4:
    // 0x80800424: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800428: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8080042C: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80800430: beq         $at, $zero, L_80800444
    if (ctx->r1 == 0) {
        // 0x80800434: lui         $at, 0xC316
        ctx->r1 = S32(0XC316 << 16);
            goto L_80800444;
    }
    // 0x80800434: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x80800438: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080043C: b           L_80800454
    // 0x80800440: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
        goto L_80800454;
    // 0x80800440: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
L_80800444:
    // 0x80800444: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800448: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080044C: nop

    // 0x80800450: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
L_80800454:
    // 0x80800454: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800458: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8080045C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80800460: jal         0x800EE7F8
    // 0x80800464: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800464: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800468: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080046C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800478: jal         0x80101FDC
    // 0x8080047C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x8080047C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_6:
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: jal         0x8008A4B0
    // 0x80800488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8080048C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800490: jal         0x800F608C
    // 0x80800494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F608C(rdram, ctx);
        goto after_8;
    // 0x80800494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800498: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080049C: jal         0x800F8294
    // 0x808004A0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800F8294(rdram, ctx);
        goto after_9;
    // 0x808004A0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x808004A4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808004A8: jal         0x800F832C
    // 0x808004AC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    func_800F832C(rdram, ctx);
        goto after_10;
    // 0x808004AC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_10:
    // 0x808004B0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808004B4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1200, 0XBC6) << 16);
    // 0x808004B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004BC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x808004C0: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x808004C4: lbu         $a2, 0xBC6($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(1200, 0XBC6));
    // 0x808004C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004CC: jal         0x80085748
    // 0x808004D0: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    _capod_entrypoint_21(rdram, ctx);
        goto after_11;
    // 0x808004D0: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    after_11:
    // 0x808004D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004D8:
    // 0x808004D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808004E0: jr          $ra
    // 0x808004E4: nop

    return;
    // 0x808004E4: nop

;}
RECOMP_FUNC void func_80800634_chboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800634: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800638: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080063C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800640: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800644: bgez        $t7, L_80800658
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800648: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800658;
    }
    // 0x80800648: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080064C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800650: nop

    // 0x80800654: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800658:
    // 0x80800658: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080065C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800660: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800664: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800668: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080066C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800670: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
    // 0x80800674: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80800678: jr          $ra
    // 0x8080067C: swc1        $f18, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x8080067C: swc1        $f18, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void bssplitup_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800400: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800404: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800408: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080040C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800410: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x80800414: jal         0x8008CB3C
    // 0x80800418: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80800418: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    after_0:
    // 0x8080041C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800420: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080042C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800430: jal         0x8009FFD8
    // 0x80800434: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800434: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080043C: jal         0x8009B94C
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_2;
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: jal         0x8009BA9C
    // 0x8080044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_3;
    // 0x8080044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800450: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800454: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: jal         0x80085338
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_4;
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800468: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080046C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800470: jr          $ra
    // 0x80800474: nop

    return;
    // 0x80800474: nop

;}
RECOMP_FUNC void func_80800488_chamazonstadiumguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080048C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800490: addiu       $at, $zero, 0xF09
    ctx->r1 = ADD32(0, 0XF09);
    // 0x80800494: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080049C: beq         $a1, $at, L_80800514
    if (ctx->r5 == ctx->r1) {
        // 0x808004A0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800514;
    }
    // 0x808004A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808004A4: addiu       $at, $zero, 0xF0A
    ctx->r1 = ADD32(0, 0XF0A);
    // 0x808004A8: beq         $a1, $at, L_808004CC
    if (ctx->r5 == ctx->r1) {
        // 0x808004AC: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_808004CC;
    }
    // 0x808004AC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x808004B0: addiu       $at, $zero, 0xF0B
    ctx->r1 = ADD32(0, 0XF0B);
    // 0x808004B4: beq         $a1, $at, L_80800514
    if (ctx->r5 == ctx->r1) {
        // 0x808004B8: addiu       $at, $zero, 0xF0C
        ctx->r1 = ADD32(0, 0XF0C);
            goto L_80800514;
    }
    // 0x808004B8: addiu       $at, $zero, 0xF0C
    ctx->r1 = ADD32(0, 0XF0C);
    // 0x808004BC: beq         $a1, $at, L_80800504
    if (ctx->r5 == ctx->r1) {
        // 0x808004C0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800504;
    }
    // 0x808004C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808004C4: b           L_80800524
    // 0x808004C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800524;
    // 0x808004C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004CC:
    // 0x808004CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004D0: jal         0x800C01A8
    // 0x808004D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C01A8(rdram, ctx);
        goto after_0;
    // 0x808004D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808004D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808004DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004E0: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x808004E4: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    // 0x808004E8: jal         0x80085708
    // 0x808004EC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808004EC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x808004F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004F4: jal         0x80102424
    // 0x808004F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808004F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x808004FC: b           L_80800524
    // 0x80800500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800524;
    // 0x80800500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800504:
    // 0x80800504: jal         0x80102424
    // 0x80800508: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800508: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x8080050C: b           L_80800524
    // 0x80800510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800524;
    // 0x80800510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800514:
    // 0x80800514: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800518: jal         0x80102424
    // 0x8080051C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x8080051C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800524:
    // 0x80800524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800528: jr          $ra
    // 0x8080052C: nop

    return;
    // 0x8080052C: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801368: jr          $ra
    // 0x8080136C: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    return;
    // 0x8080136C: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
;}
