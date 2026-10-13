#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80803158_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803158: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080315C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803160: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803164: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80803168: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080316C: addiu       $t7, $zero, 0xAB
    ctx->r15 = ADD32(0, 0XAB);
    // 0x80803170: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80803174: jal         0x8008A208
    // 0x80803178: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80803178: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x8080317C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803184: jr          $ra
    // 0x80803188: nop

    return;
    // 0x80803188: nop

;}
RECOMP_FUNC void chlagoonentrygate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1968, 0X150) << 16);
    // 0x80800140: jr          $ra
    // 0x80800144: addiu       $v0, $v0, 0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1968, 0X150));
    return;
    // 0x80800144: addiu       $v0, $v0, 0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1968, 0X150));
    // 0x80800148: nop

    // 0x8080014C: nop

;}
RECOMP_FUNC void _chdinofamilymother_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087728: syscall     613
    recomp_syscall_handler(rdram, ctx, 0x80087728);
    return;
    // 0x8008772C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800CD1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD1E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD1E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CD1EC: jal         0x800CD08C
    // 0x800CD1F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800CD08C(rdram, ctx);
        goto after_0;
    // 0x800CD1F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CD1F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD1F8: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800CD1FC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800CD200: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800CD204: nop

    // 0x800CD208: bc1fl       L_800CD218
    if (!c1cs) {
        // 0x800CD20C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CD218;
    }
    goto skip_0;
    // 0x800CD20C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CD210: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800CD214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CD218:
    // 0x800CD218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD21C: jr          $ra
    // 0x800CD220: nop

    return;
    // 0x800CD220: nop

    // 0x800CD224: nop

    // 0x800CD228: nop

    // 0x800CD22C: nop

;}
RECOMP_FUNC void _badrone_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848D0: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800848D0);
    return;
    // 0x800848D4: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void func_80800000_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009BB94
    // 0x8080000C: nop

    func_8009BB94(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800014: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(296, 0X16A0) << 16);
    // 0x80800020: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800024: lwc1        $f8, 0x16A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(296, 0X16A0));
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    return;
    // 0x80800030: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
;}
RECOMP_FUNC void func_8080004C_chbobpanel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800050: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: bne         $a1, $at, L_80800094
    if (ctx->r5 != ctx->r1) {
        // 0x8080005C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800094;
    }
    // 0x8080005C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800060: jal         0x801015D0
    // 0x80800064: nop

    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x80800064: nop

    after_0:
    // 0x80800068: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080006C: jal         0x800DF744
    // 0x80800070: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800070: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800074: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800078: jal         0x800DF744
    // 0x8080007C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x8080007C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800080: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800084: jal         0x800DF744
    // 0x80800088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080008C: b           L_80800098
    // 0x80800090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800098;
    // 0x80800090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800094:
    // 0x80800094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800098:
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void _gcfrontend_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088180: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088180);
    return;
    // 0x80088184: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _ncbawaypoint_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089460: syscall     780
    recomp_syscall_handler(rdram, ctx, 0x80089460);
    return;
    // 0x80089464: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8008E430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E438: jal         0x80084FE0
    // 0x8008E43C: nop

    _bashoes_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8008E43C: nop

    after_0:
    // 0x8008E440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E444: xori        $t6, $v0, 0x5
    ctx->r14 = ctx->r2 ^ 0X5;
    // 0x8008E448: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008E44C: jr          $ra
    // 0x8008E450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008E450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800A48_chdinoswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A50: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80800A54: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800A58: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1048, 0XB2C) << 16);
    // 0x80800A5C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800A60: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80800A64: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800A68: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80800A6C: lhu         $a1, 0xB2C($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1048, 0XB2C));
    // 0x80800A70: jal         0x80103140
    // 0x80800A74: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80800A74: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    after_0:
    // 0x80800A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A80: jr          $ra
    // 0x80800A84: nop

    return;
    // 0x80800A84: nop

;}
RECOMP_FUNC void func_808001F0_chfactoryentrydoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001F8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808001FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800200: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800204: bne         $a1, $at, L_80800280
    if (ctx->r5 != ctx->r1) {
        // 0x80800208: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800280;
    }
    // 0x80800208: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080020C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2016, 0X2F8) << 16);
    // 0x80800210: addiu       $t6, $t6, 0x2F8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2016, 0X2F8));
    // 0x80800214: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800218: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8080021C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800220: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800224: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800228: jal         0x800BABB8
    // 0x8080022C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x8080022C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800230: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2016, 0X390) << 16);
    // 0x80800234: addiu       $a1, $a1, 0x390
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2016, 0X390));
    // 0x80800238: jal         0x800C4AF0
    // 0x8080023C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800C4AF0(rdram, ctx);
        goto after_1;
    // 0x8080023C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800240: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800244: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800248: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080024C: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80800250: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080025C: jal         0x80103110
    // 0x80800260: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x80800260: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80800264: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80800268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080026C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80800270: nop

    // 0x80800274: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800278: b           L_80800284
    // 0x8080027C: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
        goto L_80800284;
    // 0x8080027C: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
L_80800280:
    // 0x80800280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800284:
    // 0x80800284: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800288: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080028C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800290: jr          $ra
    // 0x80800294: nop

    return;
    // 0x80800294: nop

;}
RECOMP_FUNC void chfactorybattery_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2276, 0X1B34) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1B34
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2276, 0X1B34));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1B34
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2276, 0X1B34));
;}
RECOMP_FUNC void chbaddieDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800068: jal         0x800FF564
    // 0x8080006C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800FF564(rdram, ctx);
        goto after_0;
    // 0x8080006C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800070: jal         0x800CB9D8
    // 0x80800074: nop

    func_800CB9D8(rdram, ctx);
        goto after_1;
    // 0x80800074: nop

    after_1:
    // 0x80800078: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080007C: jal         0x8001B084
    // 0x80800080: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    heap_free(rdram, ctx);
        goto after_2;
    // 0x80800080: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x80800084: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800088: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8080008C: sb          $zero, 0x4($t7)
    MEM_B(0X4, ctx->r15) = 0;
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void _chswitch_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085828: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x80085828);
    return;
    // 0x8008582C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800900_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800900: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800904: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800908: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x8080090C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800910: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80800914: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(439, 0XA5B0) << 16);
    // 0x80800918: bc1f        L_8080092C
    if (!c1cs) {
        // 0x8080091C: nop
    
            goto L_8080092C;
    }
    // 0x8080091C: nop

    // 0x80800920: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800924: b           L_8080092C
    // 0x80800928: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_8080092C;
    // 0x80800928: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8080092C:
    // 0x8080092C: lw          $t6, 0x8C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8C);
    // 0x80800930: addiu       $t8, $t8, -0x5A50
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(439, 0XA5B0));
    // 0x80800934: swc1        $f12, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f12.u32l;
    // 0x80800938: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8080093C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80800940: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80800944: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80800948: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8080094C: swc1        $f6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f6.u32l;
    // 0x80800950: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80800954: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80800958: swc1        $f10, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f10.u32l;
    // 0x8080095C: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80800960: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80800964: swc1        $f18, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f18.u32l;
    // 0x80800968: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8080096C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80800970: jr          $ra
    // 0x80800974: swc1        $f6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f6.u32l;
    return;
    // 0x80800974: swc1        $f6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80801618_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801618: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080161C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801620: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801624: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801628: jal         0x80800AEC
    // 0x8080162C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_80800AEC_bssub(rdram, ctx);
        goto after_0;
    // 0x8080162C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80801630: jal         0x80800634
    // 0x80801634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800634_bssub(rdram, ctx);
        goto after_1;
    // 0x80801634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801638: jal         0x80800768
    // 0x8080163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800768_bssub(rdram, ctx);
        goto after_2;
    // 0x8080163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801640: jal         0x80800254
    // 0x80801644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800254_bssub(rdram, ctx);
        goto after_3;
    // 0x80801644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801648: jal         0x80800834
    // 0x8080164C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800834_bssub(rdram, ctx);
        goto after_4;
    // 0x8080164C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801650: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801654: lwc1        $f6, 0x16C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80801658: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x8080165C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801660: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80801664: nop

    // 0x80801668: bc1t        L_80801674
    if (c1cs) {
        // 0x8080166C: nop
    
            goto L_80801674;
    }
    // 0x8080166C: nop

    // 0x80801670: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80801674:
    // 0x80801674: jal         0x8009E5C8
    // 0x80801678: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x80801678: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x8080167C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801680: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801684: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801688: jr          $ra
    // 0x8080168C: nop

    return;
    // 0x8080168C: nop

;}
RECOMP_FUNC void func_80800000_bskazhatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800008: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800010: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800014: beq         $a1, $zero, L_80800090
    if (ctx->r5 == 0) {
        // 0x80800018: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80800090;
    }
    // 0x80800018: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080001C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800020: beq         $a1, $at, L_80800048
    if (ctx->r5 == ctx->r1) {
        // 0x80800024: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800048;
    }
    // 0x80800024: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800028: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080002C: beq         $a1, $at, L_80800084
    if (ctx->r5 == ctx->r1) {
        // 0x80800030: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800084;
    }
    // 0x80800030: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800034: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800038: beql        $a1, $at, L_80800094
    if (ctx->r5 == ctx->r1) {
        // 0x8080003C: sb          $s0, 0x15C($s1)
        MEM_B(0X15C, ctx->r17) = ctx->r16;
            goto L_80800094;
    }
    goto skip_0;
    // 0x8080003C: sb          $s0, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = ctx->r16;
    skip_0:
    // 0x80800040: b           L_80800094
    // 0x80800044: sb          $s0, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = ctx->r16;
        goto L_80800094;
    // 0x80800044: sb          $s0, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = ctx->r16;
L_80800048:
    // 0x80800048: addiu       $a1, $zero, 0x13F
    ctx->r5 = ADD32(0, 0X13F);
    // 0x8080004C: jal         0x8008CCBC
    // 0x80800050: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x80800050: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    after_0:
    // 0x80800054: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800058: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080005C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800064: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800068: jal         0x8009FFD8
    // 0x8080006C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x8080006C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800070: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800074: jal         0x8009B9B0
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x8080007C: b           L_80800094
    // 0x80800080: sb          $s0, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = ctx->r16;
        goto L_80800094;
    // 0x80800080: sb          $s0, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = ctx->r16;
L_80800084:
    // 0x80800084: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x80800088: jal         0x8008CCBC
    // 0x8080008C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_3;
    // 0x8080008C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_3:
L_80800090:
    // 0x80800090: sb          $s0, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = ctx->r16;
L_80800094:
    // 0x80800094: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800098: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080009C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A0: jr          $ra
    // 0x808000A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080059C_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080059C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808005A0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x808005A4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x808005A8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x808005AC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x808005B0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x808005B4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x808005B8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x808005BC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x808005C0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x808005C4: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x808005C8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x808005CC: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x808005D0: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808005D4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808005D8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808005DC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808005E0: jal         0x800D8FF8
    // 0x808005E4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808005E4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x808005E8: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x808005EC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x808005F0: jal         0x80100094
    // 0x808005F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808005F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808005F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22B8) << 16);
    // 0x808005FC: lwc1        $f30, 0x22B8($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22B8));
    // 0x80800600: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800604: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800608: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22BC) << 16);
    // 0x8080060C: lwc1        $f26, 0x22BC($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22BC));
    // 0x80800610: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22C0) << 16);
    // 0x80800614: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800618: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x8080061C: lwc1        $f22, 0x22C0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22C0));
    // 0x80800620: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800624: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800628: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080062C: addiu       $s4, $v0, 0x154
    ctx->r20 = ADD32(ctx->r2, 0X154);
    // 0x80800630: addiu       $s5, $v0, 0x64
    ctx->r21 = ADD32(ctx->r2, 0X64);
    // 0x80800634: addiu       $s6, $v0, 0xDC
    ctx->r22 = ADD32(ctx->r2, 0XDC);
L_80800638:
    // 0x80800638: lw          $v0, 0x27C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X27C);
    // 0x8080063C: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80800640: beql        $at, $zero, L_80800694
    if (ctx->r1 == 0) {
        // 0x80800644: slti        $at, $v0, 0x3D
        ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
            goto L_80800694;
    }
    goto skip_0;
    // 0x80800644: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    skip_0:
    // 0x80800648: lwc1        $f4, 0x278($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X278);
    // 0x8080064C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800650: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800654: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x80800658: addiu       $s2, $s7, 0x14
    ctx->r18 = ADD32(ctx->r23, 0X14);
    // 0x8080065C: bc1f        L_80800674
    if (!c1cs) {
        // 0x80800660: nop
    
            goto L_80800674;
    }
    // 0x80800660: nop

    // 0x80800664: jal         0x80800410
    // 0x80800668: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80800410_chchuffy(rdram, ctx);
        goto after_2;
    // 0x80800668: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_2:
    // 0x8080066C: b           L_80800690
    // 0x80800670: lw          $v0, 0x27C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X27C);
        goto L_80800690;
    // 0x80800670: lw          $v0, 0x27C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X27C);
L_80800674:
    // 0x80800674: jal         0x800EFD24
    // 0x80800678: swc1        $f20, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->f20.u32l;
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x80800678: swc1        $f20, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->f20.u32l;
    after_3:
    // 0x8080067C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800680: jal         0x800EE7F8
    // 0x80800684: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800684: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80800688: swc1        $f20, 0x244($s1)
    MEM_W(0X244, ctx->r17) = ctx->f20.u32l;
    // 0x8080068C: lw          $v0, 0x27C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X27C);
L_80800690:
    // 0x80800690: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
L_80800694:
    // 0x80800694: bne         $at, $zero, L_808006AC
    if (ctx->r1 != 0) {
        // 0x80800698: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_808006AC;
    }
    // 0x80800698: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080069C: lwc1        $f6, 0x244($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X244);
    // 0x808006A0: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x808006A4: b           L_808006C4
    // 0x808006A8: swc1        $f8, 0x244($s1)
    MEM_W(0X244, ctx->r17) = ctx->f8.u32l;
        goto L_808006C4;
    // 0x808006A8: swc1        $f8, 0x244($s1)
    MEM_W(0X244, ctx->r17) = ctx->f8.u32l;
L_808006AC:
    // 0x808006AC: lwc1        $f10, 0x1D0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1D0);
    // 0x808006B0: sub.s       $f16, $f10, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f28.fl;
    // 0x808006B4: swc1        $f16, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->f16.u32l;
    // 0x808006B8: lwc1        $f18, 0x244($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X244);
    // 0x808006BC: mul.s       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f30.fl);
    // 0x808006C0: swc1        $f4, 0x244($s1)
    MEM_W(0X244, ctx->r17) = ctx->f4.u32l;
L_808006C4:
    // 0x808006C4: jal         0x800DC128
    // 0x808006C8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_800DC128(rdram, ctx);
        goto after_5;
    // 0x808006C8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_5:
    // 0x808006CC: lw          $t6, 0x27C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X27C);
    // 0x808006D0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808006D4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808006D8: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x808006DC: sw          $t7, 0x27C($s1)
    MEM_W(0X27C, ctx->r17) = ctx->r15;
    // 0x808006E0: lwc1        $f8, 0x1D0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1D0);
    // 0x808006E4: lwc1        $f18, 0x158($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X158);
    // 0x808006E8: lwc1        $f6, 0x154($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X154);
    // 0x808006EC: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x808006F0: lwc1        $f8, 0x15C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X15C);
    // 0x808006F4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x808006F8: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x808006FC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800700: mul.s       $f6, $f8, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80800704: swc1        $f4, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f4.u32l;
    // 0x80800708: swc1        $f16, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f16.u32l;
    // 0x8080070C: jal         0x800EE780
    // 0x80800710: swc1        $f6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f6.u32l;
    func_800EE780(rdram, ctx);
        goto after_6;
    // 0x80800710: swc1        $f6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x80800714: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80800718: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080071C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800720: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80800724: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80800728: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x8080072C: bne         $s3, $at, L_80800638
    if (ctx->r19 != ctx->r1) {
        // 0x80800730: addiu       $s6, $s6, 0xC
        ctx->r22 = ADD32(ctx->r22, 0XC);
            goto L_80800638;
    }
    // 0x80800730: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
    // 0x80800734: lwc1        $f10, 0x38($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X38);
    // 0x80800738: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x8080073C: nop

    // 0x80800740: bc1f        L_808007BC
    if (!c1cs) {
        // 0x80800744: nop
    
            goto L_808007BC;
    }
    // 0x80800744: nop

    // 0x80800748: lw          $a1, 0x6C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X6C);
    // 0x8080074C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80800750: andi        $t8, $a1, 0x1FF
    ctx->r24 = ctx->r5 & 0X1FF;
    // 0x80800754: jal         0x80800410
    // 0x80800758: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_80800410_chchuffy(rdram, ctx);
        goto after_7;
    // 0x80800758: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_7:
    // 0x8080075C: lw          $t0, 0x6C($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X6C);
    // 0x80800760: lhu         $t3, 0x6E($fp)
    ctx->r11 = MEM_HU(ctx->r30, 0X6E);
    // 0x80800764: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800768: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8080076C: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x80800770: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x80800774: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800778: sh          $t5, 0x6E($fp)
    MEM_H(0X6E, ctx->r30) = ctx->r13;
    // 0x8080077C: lw          $t6, 0x6C($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X6C);
    // 0x80800780: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800784: bne         $t7, $at, L_808007A0
    if (ctx->r15 != ctx->r1) {
        // 0x80800788: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1700, 0X22C4) << 16);
            goto L_808007A0;
    }
    // 0x80800788: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22C4) << 16);
    // 0x8080078C: lwc1        $f16, 0x22C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22C4));
    // 0x80800790: swc1        $f16, 0x278($s7)
    MEM_W(0X278, ctx->r23) = ctx->f16.u32l;
    // 0x80800794: lhu         $t8, 0x6E($fp)
    ctx->r24 = MEM_HU(ctx->r30, 0X6E);
    // 0x80800798: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x8080079C: sh          $t9, 0x6E($fp)
    MEM_H(0X6E, ctx->r30) = ctx->r25;
L_808007A0:
    // 0x808007A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22C8) << 16);
    // 0x808007A4: lwc1        $f12, 0x22C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22C8));
    // 0x808007A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22CC) << 16);
    // 0x808007AC: jal         0x800DC178
    // 0x808007B0: lwc1        $f14, 0x22CC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22CC));
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808007B0: lwc1        $f14, 0x22CC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22CC));
    after_8:
    // 0x808007B4: b           L_808007D0
    // 0x808007B8: swc1        $f0, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->f0.u32l;
        goto L_808007D0;
    // 0x808007B8: swc1        $f0, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->f0.u32l;
L_808007BC:
    // 0x808007BC: jal         0x800D8FF8
    // 0x808007C0: nop

    func_800D8FF8(rdram, ctx);
        goto after_9;
    // 0x808007C0: nop

    after_9:
    // 0x808007C4: lwc1        $f18, 0x278($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X278);
    // 0x808007C8: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x808007CC: swc1        $f4, 0x278($s7)
    MEM_W(0X278, ctx->r23) = ctx->f4.u32l;
L_808007D0:
    // 0x808007D0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x808007D4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808007D8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808007DC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808007E0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808007E4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808007E8: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x808007EC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x808007F0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x808007F4: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x808007F8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x808007FC: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80800800: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80800804: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80800808: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8080080C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80800810: jr          $ra
    // 0x80800814: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800814: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void _bafpctrl_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084CE0: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084CE0);
    return;
    // 0x80084CE4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void gccubesearch_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x808006C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808006CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808006D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808006DC: sw          $a2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r6;
    // 0x808006E0: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x808006E4: jal         0x800BE554
    // 0x808006E8: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    func_800BE554(rdram, ctx);
        goto after_0;
    // 0x808006E8: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    after_0:
    // 0x808006EC: lw          $a2, 0x9C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X9C);
    // 0x808006F0: beql        $a2, $zero, L_80800858
    if (ctx->r6 == 0) {
        // 0x808006F4: lw          $v1, 0x80($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X80);
            goto L_80800858;
    }
    goto skip_0;
    // 0x808006F4: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    skip_0:
    // 0x808006F8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x808006FC: addiu       $s1, $sp, 0x8C
    ctx->r17 = ADD32(ctx->r29, 0X8C);
    // 0x80800700: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800704: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800708: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8080070C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800710: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80800714: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x80800718: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8080071C: nop

    // 0x80800720: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800724: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x80800728: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x8080072C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80800730: nop

    // 0x80800734: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800738: jal         0x800BD64C
    // 0x8080073C: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    func_800BD64C(rdram, ctx);
        goto after_1;
    // 0x8080073C: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80800740: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80800744: addiu       $t0, $sp, 0x8C
    ctx->r8 = ADD32(ctx->r29, 0X8C);
    // 0x80800748: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8080074C: addiu       $t1, $sp, 0x7C
    ctx->r9 = ADD32(ctx->r29, 0X7C);
    // 0x80800750: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    // 0x80800754: addiu       $t2, $sp, 0x7C
    ctx->r10 = ADD32(ctx->r29, 0X7C);
L_80800758:
    // 0x80800758: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8080075C: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80800760: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80800764: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80800768: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8080076C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800770: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80800774: beq         $at, $zero, L_80800780
    if (ctx->r1 == 0) {
        // 0x80800778: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_80800780;
    }
    // 0x80800778: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8080077C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
L_80800780:
    // 0x80800780: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800784: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80800788: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8080078C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80800790: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80800794: beq         $at, $zero, L_808007A0
    if (ctx->r1 == 0) {
        // 0x80800798: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_808007A0;
    }
    // 0x80800798: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8080079C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_808007A0:
    // 0x808007A0: bne         $a3, $t2, L_80800758
    if (ctx->r7 != ctx->r10) {
        // 0x808007A4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80800758;
    }
    // 0x808007A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808007A8: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x808007AC: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x808007B0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x808007B4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808007B8: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808007BC: bne         $at, $zero, L_80800854
    if (ctx->r1 != 0) {
        // 0x808007C0: sw          $t4, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r12;
            goto L_80800854;
    }
    // 0x808007C0: sw          $t4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r12;
L_808007C4:
    // 0x808007C4: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x808007C8: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808007CC: bnel        $at, $zero, L_80800840
    if (ctx->r1 != 0) {
        // 0x808007D0: lw          $t6, 0x8C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X8C);
            goto L_80800840;
    }
    goto skip_1;
    // 0x808007D0: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    skip_1:
    // 0x808007D4: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
L_808007D8:
    // 0x808007D8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808007DC: bne         $at, $zero, L_8080082C
    if (ctx->r1 != 0) {
        // 0x808007E0: sw          $v0, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r2;
            goto L_8080082C;
    }
    // 0x808007E0: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x808007E4: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
L_808007E8:
    // 0x808007E8: jal         0x800BDAD4
    // 0x808007EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BDAD4(rdram, ctx);
        goto after_2;
    // 0x808007EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808007F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007F4: jal         0x80088C38
    // 0x808007F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gspropmarker_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808007F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x808007FC: beql        $v0, $zero, L_80800810
    if (ctx->r2 == 0) {
        // 0x80800800: lw          $v0, 0x94($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X94);
            goto L_80800810;
    }
    goto skip_2;
    // 0x80800800: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    skip_2:
    // 0x80800804: b           L_80800920
    // 0x80800808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800920;
    // 0x80800808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080080C: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
L_80800810:
    // 0x80800810: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800814: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800818: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080081C: beq         $at, $zero, L_808007E8
    if (ctx->r1 == 0) {
        // 0x80800820: sw          $v0, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r2;
            goto L_808007E8;
    }
    // 0x80800820: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80800824: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80800828: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
L_8080082C:
    // 0x8080082C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800830: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800834: beql        $at, $zero, L_808007D8
    if (ctx->r1 == 0) {
        // 0x80800838: lw          $v0, 0x60($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X60);
            goto L_808007D8;
    }
    goto skip_3;
    // 0x80800838: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    skip_3:
    // 0x8080083C: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
L_80800840:
    // 0x80800840: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80800844: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800848: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8080084C: beq         $at, $zero, L_808007C4
    if (ctx->r1 == 0) {
        // 0x80800850: sw          $t7, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r15;
            goto L_808007C4;
    }
    // 0x80800850: sw          $t7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r15;
L_80800854:
    // 0x80800854: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
L_80800858:
    // 0x80800858: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x8080085C: addiu       $s1, $sp, 0x8C
    ctx->r17 = ADD32(ctx->r29, 0X8C);
    // 0x80800860: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800864: bnel        $at, $zero, L_8080091C
    if (ctx->r1 != 0) {
        // 0x80800868: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080091C;
    }
    goto skip_4;
    // 0x80800868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x8080086C: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
L_80800870:
    // 0x80800870: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    // 0x80800874: jal         0x800D2E90
    // 0x80800878: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    func_800D2E90(rdram, ctx);
        goto after_4;
    // 0x80800878: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    after_4:
    // 0x8080087C: beq         $v0, $zero, L_80800900
    if (ctx->r2 == 0) {
        // 0x80800880: lw          $t3, 0x7C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X7C);
            goto L_80800900;
    }
    // 0x80800880: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80800884: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80800888: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x8080088C: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x80800890: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80800894: bnel        $at, $zero, L_80800904
    if (ctx->r1 != 0) {
        // 0x80800898: lw          $v1, 0x90($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X90);
            goto L_80800904;
    }
    goto skip_5;
    // 0x80800898: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    skip_5:
L_8080089C:
    // 0x8080089C: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x808008A0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808008A4: bne         $at, $zero, L_808008E8
    if (ctx->r1 != 0) {
        // 0x808008A8: sw          $v0, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r2;
            goto L_808008E8;
    }
    // 0x808008A8: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
L_808008AC:
    // 0x808008AC: jal         0x800BDAD4
    // 0x808008B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BDAD4(rdram, ctx);
        goto after_5;
    // 0x808008B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x808008B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008B8: jal         0x80088C38
    // 0x808008BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gspropmarker_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x808008BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x808008C0: beql        $v0, $zero, L_808008D4
    if (ctx->r2 == 0) {
        // 0x808008C4: lw          $v0, 0x94($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X94);
            goto L_808008D4;
    }
    goto skip_6;
    // 0x808008C4: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    skip_6:
    // 0x808008C8: b           L_80800920
    // 0x808008CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800920;
    // 0x808008CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008D0: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
L_808008D4:
    // 0x808008D4: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x808008D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808008DC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808008E0: beq         $at, $zero, L_808008AC
    if (ctx->r1 == 0) {
        // 0x808008E4: sw          $v0, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r2;
            goto L_808008AC;
    }
    // 0x808008E4: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
L_808008E8:
    // 0x808008E8: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x808008EC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x808008F0: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x808008F4: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x808008F8: beq         $at, $zero, L_8080089C
    if (ctx->r1 == 0) {
        // 0x808008FC: sw          $t6, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r14;
            goto L_8080089C;
    }
    // 0x808008FC: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
L_80800900:
    // 0x80800900: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
L_80800904:
    // 0x80800904: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80800908: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080090C: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800910: beql        $at, $zero, L_80800870
    if (ctx->r1 == 0) {
        // 0x80800914: lw          $v0, 0x80($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X80);
            goto L_80800870;
    }
    goto skip_7;
    // 0x80800914: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    skip_7:
    // 0x80800918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080091C:
    // 0x8080091C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800920:
    // 0x80800920: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800924: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800928: jr          $ra
    // 0x8080092C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8080092C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void bskazshock_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080043C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800444: jal         0x800C2FDC
    // 0x80800448: lbu         $a0, 0x164($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X164);
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800448: lbu         $a0, 0x164($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X164);
    after_0:
    // 0x8080044C: jal         0x80092BF4
    // 0x80800450: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80092BF4(rdram, ctx);
        goto after_1;
    // 0x80800450: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800454: jal         0x800832E8
    // 0x80800458: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800458: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void func_808027F8_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808027FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802800: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80802804: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80802808: jal         0x800EFD24
    // 0x8080280C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x8080280C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80802810: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80802814: jal         0x80102D78
    // 0x80802818: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x80802818: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8080281C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80802820: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80802824: swc1        $f0, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f0.u32l;
    // 0x80802828: swc1        $f0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f0.u32l;
    // 0x8080282C: swc1        $f2, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f2.u32l;
    // 0x80802830: swc1        $f2, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f2.u32l;
    // 0x80802834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802838: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080283C: jr          $ra
    // 0x80802840: nop

    return;
    // 0x80802840: nop

;}
RECOMP_FUNC void func_800AF04C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF04C: lhu         $t4, 0xC($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0XC);
    // 0x800AF050: srl         $t5, $t4, 5
    ctx->r13 = S32(U32(ctx->r12) >> 5);
    // 0x800AF054: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800AF058: addu        $t5, $t5, $a3
    ctx->r13 = ADD32(ctx->r13, ctx->r7);
    // 0x800AF05C: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x800AF060: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800AF064: andi        $t4, $t4, 0x1F
    ctx->r12 = ctx->r12 & 0X1F;
    // 0x800AF068: sllv        $t5, $t5, $t4
    ctx->r13 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x800AF06C: and         $t6, $t6, $t5
    ctx->r14 = ctx->r14 & ctx->r13;
    // 0x800AF070: beq         $t6, $zero, L_800AF2E8
    if (ctx->r14 == 0) {
        // 0x800AF074: nop
    
            goto L_800AF2E8;
    }
    // 0x800AF074: nop

    // 0x800AF078: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AF07C: addiu       $t4, $t4, -0x5B60
    ctx->r12 = ADD32(ctx->r12, -0X5B60);
    // 0x800AF080: swc1        $f0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f0.u32l;
    // 0x800AF084: swc1        $f1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f_odd[(1 - 1) * 2];
    // 0x800AF088: swc1        $f2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f2.u32l;
    // 0x800AF08C: swc1        $f3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f_odd[(3 - 1) * 2];
    // 0x800AF090: swc1        $f4, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f4.u32l;
    // 0x800AF094: swc1        $f5, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f_odd[(5 - 1) * 2];
    // 0x800AF098: swc1        $f6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f6.u32l;
    // 0x800AF09C: swc1        $f7, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f_odd[(7 - 1) * 2];
    // 0x800AF0A0: swc1        $f8, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f8.u32l;
    // 0x800AF0A4: swc1        $f9, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f_odd[(9 - 1) * 2];
    // 0x800AF0A8: swc1        $f10, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f10.u32l;
    // 0x800AF0AC: swc1        $f11, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f_odd[(11 - 1) * 2];
    // 0x800AF0B0: swc1        $f12, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f12.u32l;
    // 0x800AF0B4: swc1        $f13, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f_odd[(13 - 1) * 2];
    // 0x800AF0B8: swc1        $f14, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->f14.u32l;
    // 0x800AF0BC: swc1        $f15, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f_odd[(15 - 1) * 2];
    // 0x800AF0C0: swc1        $f16, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f16.u32l;
    // 0x800AF0C4: swc1        $f17, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f_odd[(17 - 1) * 2];
    // 0x800AF0C8: swc1        $f18, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f18.u32l;
    // 0x800AF0CC: swc1        $f19, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->f_odd[(19 - 1) * 2];
    // 0x800AF0D0: swc1        $f20, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f20.u32l;
    // 0x800AF0D4: swc1        $f21, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AF0D8: swc1        $f22, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f22.u32l;
    // 0x800AF0DC: swc1        $f23, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = ctx->f_odd[(23 - 1) * 2];
    // 0x800AF0E0: swc1        $f24, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f24.u32l;
    // 0x800AF0E4: swc1        $f25, 0x64($t4)
    MEM_W(0X64, ctx->r12) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AF0E8: swc1        $f26, 0x68($t4)
    MEM_W(0X68, ctx->r12) = ctx->f26.u32l;
    // 0x800AF0EC: swc1        $f27, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f_odd[(27 - 1) * 2];
    // 0x800AF0F0: swc1        $f28, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f28.u32l;
    // 0x800AF0F4: swc1        $f29, 0x74($t4)
    MEM_W(0X74, ctx->r12) = ctx->f_odd[(29 - 1) * 2];
    // 0x800AF0F8: swc1        $f30, 0x78($t4)
    MEM_W(0X78, ctx->r12) = ctx->f30.u32l;
    // 0x800AF0FC: swc1        $f31, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->f_odd[(31 - 1) * 2];
    // 0x800AF100: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800AF104: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x800AF108: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x800AF10C: sw          $at, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r1;
    // 0x800AF110: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x800AF114: sw          $v1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r3;
    // 0x800AF118: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x800AF11C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800AF120: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800AF124: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800AF128: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800AF12C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800AF130: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800AF134: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800AF138: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800AF13C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800AF140: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800AF144: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x800AF148: sw          $k0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r26;
    // 0x800AF14C: sw          $k1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r27;
    // 0x800AF150: sw          $gp, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r28;
    // 0x800AF154: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x800AF158: sdc1        $f0, 0x58($sp)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X58, ctx->r29);
    // 0x800AF15C: sdc1        $f2, 0x60($sp)
    CHECK_FR(ctx, 2);
    SD(ctx->f2.u64, 0X60, ctx->r29);
    // 0x800AF160: sdc1        $f4, 0x68($sp)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X68, ctx->r29);
    // 0x800AF164: sdc1        $f6, 0x70($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X70, ctx->r29);
    // 0x800AF168: sdc1        $f8, 0x78($sp)
    CHECK_FR(ctx, 8);
    SD(ctx->f8.u64, 0X78, ctx->r29);
    // 0x800AF16C: sdc1        $f10, 0x80($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X80, ctx->r29);
    // 0x800AF170: sdc1        $f12, 0x88($sp)
    CHECK_FR(ctx, 12);
    SD(ctx->f12.u64, 0X88, ctx->r29);
    // 0x800AF174: sdc1        $f14, 0x90($sp)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0X90, ctx->r29);
    // 0x800AF178: sdc1        $f16, 0x98($sp)
    CHECK_FR(ctx, 16);
    SD(ctx->f16.u64, 0X98, ctx->r29);
    // 0x800AF17C: sdc1        $f18, 0xA0($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0XA0, ctx->r29);
    // 0x800AF180: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AF184: lhu         $a1, 0xC($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0XC);
    // 0x800AF188: addiu       $a2, $a2, -0x5A60
    ctx->r6 = ADD32(ctx->r6, -0X5A60);
    // 0x800AF18C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800AF190: swc1        $f11, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f_odd[(11 - 1) * 2];
    // 0x800AF194: swc1        $f12, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f12.u32l;
    // 0x800AF198: swc1        $f13, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f_odd[(13 - 1) * 2];
    // 0x800AF19C: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x800AF1A0: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x800AF1A4: nor         $t1, $t1, $zero
    ctx->r9 = ~(ctx->r9 | 0);
    // 0x800AF1A8: and         $t0, $t0, $t1
    ctx->r8 = ctx->r8 & ctx->r9;
    // 0x800AF1AC: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x800AF1B0: jal         0x800E0E94
    // 0x800AF1B4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    func_800E0E94(rdram, ctx);
        goto after_0;
    // 0x800AF1B4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    after_0:
    // 0x800AF1B8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800AF1BC: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x800AF1C0: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x800AF1C4: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800AF1C8: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x800AF1CC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF1D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AF1D4: addiu       $t4, $t4, -0x5B60
    ctx->r12 = ADD32(ctx->r12, -0X5B60);
    // 0x800AF1D8: ldc1        $f0, 0x58($sp)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r29, 0X58);
    // 0x800AF1DC: ldc1        $f2, 0x60($sp)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r29, 0X60);
    // 0x800AF1E0: ldc1        $f4, 0x68($sp)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r29, 0X68);
    // 0x800AF1E4: ldc1        $f6, 0x70($sp)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r29, 0X70);
    // 0x800AF1E8: ldc1        $f8, 0x78($sp)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r29, 0X78);
    // 0x800AF1EC: ldc1        $f10, 0x80($sp)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r29, 0X80);
    // 0x800AF1F0: ldc1        $f12, 0x88($sp)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r29, 0X88);
    // 0x800AF1F4: ldc1        $f14, 0x90($sp)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r29, 0X90);
    // 0x800AF1F8: ldc1        $f16, 0x98($sp)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r29, 0X98);
    // 0x800AF1FC: ldc1        $f18, 0xA0($sp)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r29, 0XA0);
    // 0x800AF200: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800AF204: lwc1        $f1, 0x4($t4)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r12, 0X4);
    // 0x800AF208: lwc1        $f2, 0x8($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800AF20C: lwc1        $f3, 0xC($t4)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r12, 0XC);
    // 0x800AF210: lwc1        $f4, 0x10($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800AF214: lwc1        $f5, 0x14($t4)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r12, 0X14);
    // 0x800AF218: lwc1        $f6, 0x18($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X18);
    // 0x800AF21C: lwc1        $f7, 0x1C($t4)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r12, 0X1C);
    // 0x800AF220: lwc1        $f8, 0x20($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X20);
    // 0x800AF224: lwc1        $f9, 0x24($t4)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r12, 0X24);
    // 0x800AF228: lwc1        $f10, 0x28($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X28);
    // 0x800AF22C: lwc1        $f11, 0x2C($t4)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r12, 0X2C);
    // 0x800AF230: lwc1        $f12, 0x30($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X30);
    // 0x800AF234: lwc1        $f13, 0x34($t4)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r12, 0X34);
    // 0x800AF238: lwc1        $f14, 0x38($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X38);
    // 0x800AF23C: lwc1        $f15, 0x3C($t4)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r12, 0X3C);
    // 0x800AF240: lwc1        $f16, 0x40($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X40);
    // 0x800AF244: lwc1        $f17, 0x44($t4)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r12, 0X44);
    // 0x800AF248: lwc1        $f18, 0x48($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X48);
    // 0x800AF24C: lwc1        $f19, 0x4C($t4)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r12, 0X4C);
    // 0x800AF250: lwc1        $f20, 0x50($t4)
    ctx->f20.u32l = MEM_W(ctx->r12, 0X50);
    // 0x800AF254: lwc1        $f21, 0x54($t4)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r12, 0X54);
    // 0x800AF258: lwc1        $f22, 0x58($t4)
    ctx->f22.u32l = MEM_W(ctx->r12, 0X58);
    // 0x800AF25C: lwc1        $f23, 0x5C($t4)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r12, 0X5C);
    // 0x800AF260: lwc1        $f24, 0x60($t4)
    ctx->f24.u32l = MEM_W(ctx->r12, 0X60);
    // 0x800AF264: lwc1        $f25, 0x64($t4)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r12, 0X64);
    // 0x800AF268: lwc1        $f26, 0x68($t4)
    ctx->f26.u32l = MEM_W(ctx->r12, 0X68);
    // 0x800AF26C: lwc1        $f27, 0x6C($t4)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r12, 0X6C);
    // 0x800AF270: lwc1        $f28, 0x70($t4)
    ctx->f28.u32l = MEM_W(ctx->r12, 0X70);
    // 0x800AF274: lwc1        $f29, 0x74($t4)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r12, 0X74);
    // 0x800AF278: lwc1        $f30, 0x78($t4)
    ctx->f30.u32l = MEM_W(ctx->r12, 0X78);
    // 0x800AF27C: lwc1        $f31, 0x7C($t4)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r12, 0X7C);
    // 0x800AF280: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AF284: addiu       $t4, $t4, -0x5A60
    ctx->r12 = ADD32(ctx->r12, -0X5A60);
    // 0x800AF288: lw          $at, 0x0($sp)
    ctx->r1 = MEM_W(ctx->r29, 0X0);
    // 0x800AF28C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800AF290: lw          $v1, 0x8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8);
    // 0x800AF294: lw          $a0, 0xC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC);
    // 0x800AF298: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x800AF29C: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x800AF2A0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800AF2A4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF2A8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800AF2AC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800AF2B0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800AF2B4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800AF2B8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800AF2BC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800AF2C0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800AF2C4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800AF2C8: lw          $k0, 0x44($sp)
    ctx->r26 = MEM_W(ctx->r29, 0X44);
    // 0x800AF2CC: lw          $k1, 0x48($sp)
    ctx->r27 = MEM_W(ctx->r29, 0X48);
    // 0x800AF2D0: lw          $gp, 0x4C($sp)
    ctx->r28 = MEM_W(ctx->r29, 0X4C);
    // 0x800AF2D4: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x800AF2D8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x800AF2DC: lwc1        $f11, 0x0($t4)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r12, 0X0);
    // 0x800AF2E0: lwc1        $f12, 0x4($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800AF2E4: lwc1        $f13, 0x8($t4)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r12, 0X8);
L_800AF2E8:
    // 0x800AF2E8: jr          $ra
    // 0x800AF2EC: nop

    return;
    // 0x800AF2EC: nop

;}
RECOMP_FUNC void bitfield_set_n_bits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9F84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D9F88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D9F8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D9F90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D9F94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D9F98: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800D9F9C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800D9FA0: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800D9FA4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D9FA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D9FAC: blez        $a3, L_800D9FDC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800D9FB0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800D9FDC;
    }
    // 0x800D9FB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D9FB4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_800D9FB8:
    // 0x800D9FB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D9FBC: sllv        $t7, $t6, $s0
    ctx->r15 = S32(ctx->r14 << (ctx->r16 & 31));
    // 0x800D9FC0: and         $a2, $t7, $s4
    ctx->r6 = ctx->r15 & ctx->r20;
    // 0x800D9FC4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D9FC8: jal         0x800D9F18
    // 0x800D9FCC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bitfield_set_bit(rdram, ctx);
        goto after_0;
    // 0x800D9FCC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800D9FD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D9FD4: bne         $s0, $s2, L_800D9FB8
    if (ctx->r16 != ctx->r18) {
        // 0x800D9FD8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800D9FB8;
    }
    // 0x800D9FD8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800D9FDC:
    // 0x800D9FDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800D9FE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D9FE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9FE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D9FEC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D9FF0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D9FF4: jr          $ra
    // 0x800D9FF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D9FF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void chcablecar_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(972, 0XEF8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xEF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(972, 0XEF8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xEF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(972, 0XEF8));
;}
RECOMP_FUNC void _mlspline_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089118: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x80089118);
    return;
    // 0x8008911C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void baanim_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C86C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C870: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8008C874: jal         0x8008ADBC
    // 0x8008C878: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_8008ADBC(rdram, ctx);
        goto after_0;
    // 0x8008C878: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x8008C87C: jal         0x8008CFF0
    // 0x8008C880: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008CFF0(rdram, ctx);
        goto after_1;
    // 0x8008C880: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008C884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C88C: jr          $ra
    // 0x8008C890: nop

    return;
    // 0x8008C890: nop

;}
RECOMP_FUNC void bssub_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801564: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801568: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(380, 0X18F0) << 16);
    // 0x8080156C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801570: jr          $ra
    // 0x80801574: lw          $v0, 0x18F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18F0));
    return;
    // 0x80801574: lw          $v0, 0x18F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18F0));
;}
RECOMP_FUNC void func_80802D04_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802D0C: jal         0x80106790
    // 0x80802D10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802D10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802D14: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80802D18: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
    // 0x80802D1C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80802D20: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x80802D24: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x80802D28: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80802D2C: sb          $t2, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r10;
    // 0x80802D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802D34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802D38: jr          $ra
    // 0x80802D3C: nop

    return;
    // 0x80802D3C: nop

;}
RECOMP_FUNC void cheggproximity_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080001C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800020: jal         0x8008A488
    // 0x80800024: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80800024: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800028: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    // 0x8080002C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800030: jal         0x8008A3D0
    // 0x80800034: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _suegg_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800034: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800038: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080003C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800040: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800044: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800048: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x8080004C: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800050: jal         0x80013B7C
    // 0x80800054: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    func_80013B7C(rdram, ctx);
        goto after_2;
    // 0x80800054: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    after_2:
    // 0x80800058: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: jal         0x8008A460
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sueggmove_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800068: lui         $a2, 0xC6AB
    ctx->r6 = S32(0XC6AB << 16);
    // 0x8080006C: ori         $a2, $a2, 0xE000
    ctx->r6 = ctx->r6 | 0XE000;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: jal         0x8008A468
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: jal         0x8008A470
    // 0x80800084: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sueggmove_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80800084: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x8008A380
    // 0x80800090: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _suegg_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800090: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_6:
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800098: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8080009C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A0: jr          $ra
    // 0x808000A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chalienbeam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086610: syscall     348
    recomp_syscall_handler(rdram, ctx, 0x80086610);
    return;
    // 0x80086614: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808008C8_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008D0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808008D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808008D8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808008DC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808008E0: sltiu       $at, $t8, 0xD
    ctx->r1 = ctx->r24 < 0XD ? 1 : 0;
    // 0x808008E4: beq         $at, $zero, L_80800938
    if (ctx->r1 == 0) {
        // 0x808008E8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800938;
    }
    // 0x808008E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808008EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2276, 0X1894) << 16);
    // 0x808008F0: addu        $at, $at, $t8
    gpr jr_addend_808008F8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808008F4: lw          $t8, 0x1894($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2276, 0X1894));
    // 0x808008F8: jr          $t8
    // 0x808008FC: nop

    switch (jr_addend_808008F8 >> 2) {
        case 0: goto L_80800900; break;
        case 1: goto L_80800900; break;
        case 2: goto L_80800900; break;
        case 3: goto L_80800900; break;
        case 4: goto L_80800910; break;
        case 5: goto L_80800900; break;
        case 6: goto L_80800910; break;
        case 7: goto L_80800938; break;
        case 8: goto L_80800900; break;
        case 9: goto L_80800910; break;
        case 10: goto L_80800938; break;
        case 11: goto L_80800938; break;
        case 12: goto L_80800910; break;
        default: switch_error(__func__, 0x808008F8, 0x80801894);
    }
    // 0x808008FC: nop

L_80800900:
    // 0x80800900: lbu         $t9, 0x79($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X79);
    // 0x80800904: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x80800908: b           L_80800938
    // 0x8080090C: sb          $t0, 0x79($a2)
    MEM_B(0X79, ctx->r6) = ctx->r8;
        goto L_80800938;
    // 0x8080090C: sb          $t0, 0x79($a2)
    MEM_B(0X79, ctx->r6) = ctx->r8;
L_80800910:
    // 0x80800910: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800914: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800918: jal         0x800DC128
    // 0x8080091C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x8080091C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800920: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800924: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x80800928: lbu         $t4, 0x79($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X79);
    // 0x8080092C: andi        $t5, $t4, 0xFF0F
    ctx->r13 = ctx->r12 & 0XFF0F;
    // 0x80800930: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80800934: sb          $t6, 0x79($a2)
    MEM_B(0X79, ctx->r6) = ctx->r14;
L_80800938:
    // 0x80800938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080093C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800940: jr          $ra
    // 0x80800944: nop

    return;
    // 0x80800944: nop

;}
RECOMP_FUNC void func_808003CC_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003CC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808003D0: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x808003D4: jr          $ra
    // 0x808003D8: swc1        $f12, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808003D8: swc1        $f12, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_8008C27C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C27C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C284: jal         0x8008BD1C
    // 0x8008C288: nop

    func_8008BD1C(rdram, ctx);
        goto after_0;
    // 0x8008C288: nop

    after_0:
    // 0x8008C28C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C294: jr          $ra
    // 0x8008C298: nop

    return;
    // 0x8008C298: nop

    // 0x8008C29C: nop

;}
RECOMP_FUNC void _chlavagargoyle_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087588: syscall     589
    recomp_syscall_handler(rdram, ctx, 0x80087588);
    return;
    // 0x8008758C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80093070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093070: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80093074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80093078: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8009307C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80093080: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80093084: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80093088: jal         0x800D674C
    // 0x8009308C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x8009308C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80093090: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80093094: jal         0x800D674C
    // 0x80093098: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80093098: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x8009309C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800930A0: jal         0x800A25D0
    // 0x800930A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800A25D0(rdram, ctx);
        goto after_2;
    // 0x800930A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x800930A8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800930AC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800930B0: lbu         $v1, 0x0($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X0);
    // 0x800930B4: beq         $v1, $zero, L_800930D0
    if (ctx->r3 == 0) {
        // 0x800930B8: sll         $a0, $v1, 16
        ctx->r4 = S32(ctx->r3 << 16);
            goto L_800930D0;
    }
    // 0x800930B8: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x800930BC: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800930C0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800930C4: jal         0x80100E18
    // 0x800930C8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80100E18(rdram, ctx);
        goto after_3;
    // 0x800930C8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x800930CC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_800930D0:
    // 0x800930D0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800930D4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800930D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800930DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800930E0: jal         0x80100D24
    // 0x800930E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80100D24(rdram, ctx);
        goto after_4;
    // 0x800930E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x800930E8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800930EC: sb          $v0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r2;
    // 0x800930F0: jal         0x800B2840
    // 0x800930F4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800B2840(rdram, ctx);
        goto after_5;
    // 0x800930F4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x800930F8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800930FC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80093100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093104: jal         0x80100A74
    // 0x80093108: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    func_80100A74(rdram, ctx);
        goto after_6;
    // 0x80093108: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    after_6:
    // 0x8009310C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80093110: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093114: jal         0x800B25D8
    // 0x80093118: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800B25D8(rdram, ctx);
        goto after_7;
    // 0x80093118: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8009311C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80093120: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80093124: jr          $ra
    // 0x80093128: nop

    return;
    // 0x80093128: nop

;}
RECOMP_FUNC void gcmapsects_lagoonmid_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080000C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800010: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800014: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x80087F50
    // 0x8080001C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    _gcmapsects_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80800020: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2618, 0X230) << 16);
    // 0x80800024: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2618, 0X23C) << 16);
    // 0x80800028: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2618, 0X248) << 16);
    // 0x8080002C: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2618, 0X2F8) << 16);
    // 0x80800030: addiu       $s2, $s2, 0x2F8
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2618, 0X2F8));
    // 0x80800034: addiu       $s1, $s1, 0x248
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2618, 0X248));
    // 0x80800038: addiu       $s3, $s3, 0x23C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2618, 0X23C));
    // 0x8080003C: addiu       $s0, $s0, 0x230
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2618, 0X230));
L_80800040:
    // 0x80800040: lh          $t6, 0x24($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X24);
    // 0x80800044: lh          $a0, 0x26($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X26);
    // 0x80800048: lh          $a1, 0x28($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X28);
    // 0x8080004C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800050: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800054: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80800058: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080005C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80800060: jal         0x80087F00
    // 0x80800064: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _gcmapsects_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800064: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80800068: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x8080006C: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80800070: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x80800074: bne         $at, $zero, L_80800040
    if (ctx->r1 != 0) {
        // 0x80800078: addiu       $s3, $s3, 0x2C
        ctx->r19 = ADD32(ctx->r19, 0X2C);
            goto L_80800040;
    }
    // 0x80800078: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
    // 0x8080007C: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2618, 0X2E0) << 16);
    // 0x80800080: addiu       $s0, $s0, 0x2E0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2618, 0X2E0));
    // 0x80800084: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80800088:
    // 0x80800088: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8080008C: jal         0x80087F18
    // 0x80800090: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    _gcmapsects_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800090: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    after_2:
    // 0x80800094: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800098: sltiu       $at, $s2, 0x3
    ctx->r1 = ctx->r18 < 0X3 ? 1 : 0;
    // 0x8080009C: bne         $at, $zero, L_80800088
    if (ctx->r1 != 0) {
        // 0x808000A0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80800088;
    }
    // 0x808000A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808000A4: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2618, 0X2EC) << 16);
    // 0x808000A8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2618, 0X2F4) << 16);
    // 0x808000AC: addiu       $s1, $s1, 0x2F4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2618, 0X2F4));
    // 0x808000B0: addiu       $s0, $s0, 0x2EC
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2618, 0X2EC));
    // 0x808000B4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_808000B8:
    // 0x808000B8: jal         0x80087F08
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcmapsects_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808000C0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x808000C4: jal         0x80087F10
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcmapsects_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000CC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x808000D0: bnel        $s0, $s1, L_808000B8
    if (ctx->r16 != ctx->r17) {
        // 0x808000D4: lh          $a0, 0x0($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X0);
            goto L_808000B8;
    }
    goto skip_0;
    // 0x808000D4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    skip_0:
    // 0x808000D8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808000DC: jal         0x80087F60
    // 0x808000E0: addiu       $a0, $a0, 0x7FF8
    ctx->r4 = ADD32(ctx->r4, 0X7FF8);
    _gcmapsects_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x808000E0: addiu       $a0, $a0, 0x7FF8
    ctx->r4 = ADD32(ctx->r4, 0X7FF8);
    after_5:
    // 0x808000E4: jal         0x80087F70
    // 0x808000E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _gcmapsects_entrypoint_14(rdram, ctx);
        goto after_6;
    // 0x808000E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x808000EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808000F0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808000F8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808000FC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800100: jr          $ra
    // 0x80800104: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800104: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bskazmove_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808009F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A00: jal         0x8008E39C
    // 0x80800A04: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_8008E39C(rdram, ctx);
        goto after_0;
    // 0x80800A04: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800A08: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800A0C: jal         0x80800754
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800754_bskazmove(rdram, ctx);
        goto after_1;
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A14: jal         0x80800790
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bskazmove_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A24: jal         0x8009D2F0
    // 0x80800A28: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_3;
    // 0x80800A28: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_3:
    // 0x80800A2C: jal         0x808000A0
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bskazmove_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800A34: jal         0x8009EF10
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_5;
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800A3C: beq         $v0, $zero, L_80800A58
    if (ctx->r2 == 0) {
        // 0x80800A40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A58;
    }
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A48: beq         $v0, $at, L_80800A70
    if (ctx->r2 == ctx->r1) {
        // 0x80800A4C: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80800A70;
    }
    // 0x80800A4C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800A50: b           L_80800A8C
    // 0x80800A54: nop

        goto L_80800A8C;
    // 0x80800A54: nop

L_80800A58:
    // 0x80800A58: jal         0x8009BCD4
    // 0x80800A5C: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_6;
    // 0x80800A5C: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    after_6:
    // 0x80800A60: beq         $v0, $zero, L_80800A8C
    if (ctx->r2 == 0) {
        // 0x80800A64: addiu       $t6, $zero, 0xBB
        ctx->r14 = ADD32(0, 0XBB);
            goto L_80800A8C;
    }
    // 0x80800A64: addiu       $t6, $zero, 0xBB
    ctx->r14 = ADD32(0, 0XBB);
    // 0x80800A68: b           L_80800A8C
    // 0x80800A6C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_80800A8C;
    // 0x80800A6C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800A70:
    // 0x80800A70: bne         $t7, $zero, L_80800A8C
    if (ctx->r15 != 0) {
        // 0x80800A74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A8C;
    }
    // 0x80800A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A78: jal         0x8009BCD4
    // 0x80800A7C: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    func_8009BCD4(rdram, ctx);
        goto after_7;
    // 0x80800A7C: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_7:
    // 0x80800A80: beq         $v0, $zero, L_80800A8C
    if (ctx->r2 == 0) {
        // 0x80800A84: addiu       $t8, $zero, 0xBC
        ctx->r24 = ADD32(0, 0XBC);
            goto L_80800A8C;
    }
    // 0x80800A84: addiu       $t8, $zero, 0xBC
    ctx->r24 = ADD32(0, 0XBC);
    // 0x80800A88: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800A8C:
    // 0x80800A8C: jal         0x8008DD04
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_8;
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800A94: beq         $v0, $zero, L_80800AA4
    if (ctx->r2 == 0) {
        // 0x80800A98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AA4;
    }
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A9C: addiu       $t9, $zero, 0xDF
    ctx->r25 = ADD32(0, 0XDF);
    // 0x80800AA0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800AA4:
    // 0x80800AA4: jal         0x800919F4
    // 0x80800AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_9;
    // 0x80800AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800AAC: beql        $v0, $zero, L_80800ACC
    if (ctx->r2 == 0) {
        // 0x80800AB0: lw          $t1, 0x20($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X20);
            goto L_80800ACC;
    }
    goto skip_0;
    // 0x80800AB0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800AB4: jal         0x8008E39C
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E39C(rdram, ctx);
        goto after_10;
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800ABC: bne         $v0, $zero, L_80800AC8
    if (ctx->r2 != 0) {
        // 0x80800AC0: addiu       $t0, $zero, 0xDD
        ctx->r8 = ADD32(0, 0XDD);
            goto L_80800AC8;
    }
    // 0x80800AC0: addiu       $t0, $zero, 0xDD
    ctx->r8 = ADD32(0, 0XDD);
    // 0x80800AC4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80800AC8:
    // 0x80800AC8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
L_80800ACC:
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD0: beq         $t1, $zero, L_80800AE8
    if (ctx->r9 == 0) {
        // 0x80800AD4: nop
    
            goto L_80800AE8;
    }
    // 0x80800AD4: nop

    // 0x80800AD8: jal         0x8080025C
    // 0x80800ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080025C_bskazmove(rdram, ctx);
        goto after_11;
    // 0x80800ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800AE0: b           L_80800AF8
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800AF8;
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AE8:
    // 0x80800AE8: jal         0x808001C4
    // 0x80800AEC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808001C4_bskazmove(rdram, ctx);
        goto after_12;
    // 0x80800AEC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80800AF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AF8:
    // 0x80800AF8: jal         0x80091A58
    // 0x80800AFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_13;
    // 0x80800AFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
    // 0x80800B00: beq         $v0, $zero, L_80800B54
    if (ctx->r2 == 0) {
        // 0x80800B04: nop
    
            goto L_80800B54;
    }
    // 0x80800B04: nop

    // 0x80800B08: jal         0x800832F0
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800B10: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800B14: jal         0x8009BB00
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_15;
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800B1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800B20: nop

    // 0x80800B24: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800B28: nop

    // 0x80800B2C: bc1f        L_80800B54
    if (!c1cs) {
        // 0x80800B30: nop
    
            goto L_80800B54;
    }
    // 0x80800B30: nop

    // 0x80800B34: jal         0x8008D790
    // 0x80800B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D790(rdram, ctx);
        goto after_16;
    // 0x80800B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800B3C: beq         $v0, $zero, L_80800B54
    if (ctx->r2 == 0) {
        // 0x80800B40: nop
    
            goto L_80800B54;
    }
    // 0x80800B40: nop

    // 0x80800B44: jal         0x80084978
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_12(rdram, ctx);
        goto after_17;
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800B4C: b           L_80800BA0
    // 0x80800B50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BA0;
    // 0x80800B50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B54:
    // 0x80800B54: jal         0x8008DF18
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_18;
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800B5C: beq         $v0, $zero, L_80800B70
    if (ctx->r2 == 0) {
        // 0x80800B60: nop
    
            goto L_80800B70;
    }
    // 0x80800B60: nop

    // 0x80800B64: jal         0x800848B0
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_19;
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800B6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800B70:
    // 0x80800B70: jal         0x8008E35C
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_20;
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800B78: beq         $v0, $zero, L_80800B88
    if (ctx->r2 == 0) {
        // 0x80800B7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B88;
    }
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B80: addiu       $t2, $zero, 0x15D
    ctx->r10 = ADD32(0, 0X15D);
    // 0x80800B84: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80800B88:
    // 0x80800B88: jal         0x800A02DC
    // 0x80800B8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800A02DC(rdram, ctx);
        goto after_21;
    // 0x80800B8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_21:
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B94: jal         0x8009E5C8
    // 0x80800B98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_22;
    // 0x80800B98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_22:
    // 0x80800B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BA0:
    // 0x80800BA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800BA8: jr          $ra
    // 0x80800BAC: nop

    return;
    // 0x80800BAC: nop

;}
RECOMP_FUNC void chfactoryprop_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800570: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800574: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800578: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080057C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800580: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800584: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800588: jal         0x80106790
    // 0x8080058C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080058C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800590: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80800594: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800598: lwc1        $f12, 0x28($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8080059C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808005A0: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    // 0x808005A4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808005A8: jal         0x800F12D4
    // 0x808005AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x808005AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x808005B0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808005B4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808005B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808005BC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x808005C0: addu        $v0, $t7, $a1
    ctx->r2 = ADD32(ctx->r15, ctx->r5);
    // 0x808005C4: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x808005C8: beql        $at, $zero, L_80800668
    if (ctx->r1 == 0) {
        // 0x808005CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800668;
    }
    goto skip_0;
    // 0x808005CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808005D0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x808005D4: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x808005D8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808005DC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x808005E0: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x808005E4: nop

    // 0x808005E8: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x808005EC: beql        $v1, $zero, L_8080063C
    if (ctx->r3 == 0) {
        // 0x808005F0: mfc1        $v1, $f6
        ctx->r3 = (int32_t)ctx->f6.u32l;
            goto L_8080063C;
    }
    goto skip_1;
    // 0x808005F0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x808005F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808005FC: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80800600: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80800604: nop

    // 0x80800608: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8080060C: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80800610: nop

    // 0x80800614: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80800618: bne         $v1, $zero, L_80800630
    if (ctx->r3 != 0) {
        // 0x8080061C: nop
    
            goto L_80800630;
    }
    // 0x8080061C: nop

    // 0x80800620: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80800624: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800628: b           L_80800648
    // 0x8080062C: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_80800648;
    // 0x8080062C: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_80800630:
    // 0x80800630: b           L_80800648
    // 0x80800634: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80800648;
    // 0x80800634: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80800638: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
L_8080063C:
    // 0x8080063C: nop

    // 0x80800640: bltz        $v1, L_80800630
    if (SIGNED(ctx->r3) < 0) {
        // 0x80800644: nop
    
            goto L_80800630;
    }
    // 0x80800644: nop

L_80800648:
    // 0x80800648: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8080064C: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x80800650: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_80800654:
    // 0x80800654: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80800658: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8080065C: bne         $at, $zero, L_80800654
    if (ctx->r1 != 0) {
        // 0x80800660: sb          $v1, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r3;
            goto L_80800654;
    }
    // 0x80800660: sb          $v1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r3;
    // 0x80800664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800668:
    // 0x80800668: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080066C: jr          $ra
    // 0x80800670: nop

    return;
    // 0x80800670: nop

;}
RECOMP_FUNC void func_80801EAC_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801EB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801EB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801EB8: jal         0x80100094
    // 0x80801EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801EC0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801EC4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801EC8: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80801ECC: lw          $t7, 0x70($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X70);
    // 0x80801ED0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1700, 0X2690) << 16);
    // 0x80801ED4: addiu       $a3, $a3, 0x2690
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1700, 0X2690));
    // 0x80801ED8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80801EDC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801EE0: addiu       $a1, $v0, 0x20
    ctx->r5 = ADD32(ctx->r2, 0X20);
    // 0x80801EE4: jal         0x80089D68
    // 0x80801EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80801EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80801EEC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80801EF0: sb          $v0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r2;
    // 0x80801EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801EF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801EFC: jr          $ra
    // 0x80801F00: nop

    return;
    // 0x80801F00: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BF8: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083BF8);
    return;
    // 0x80083BFC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void glhittableDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800114: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080011C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800120: bne         $a2, $at, L_80800130
    if (ctx->r6 != ctx->r1) {
        // 0x80800124: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80800130;
    }
    // 0x80800124: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800128: b           L_80800164
    // 0x8080012C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800164;
    // 0x8080012C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800130:
    // 0x80800130: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80800134: bne         $a2, $at, L_80800144
    if (ctx->r6 != ctx->r1) {
        // 0x80800138: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800144;
    }
    // 0x80800138: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080013C: b           L_80800164
    // 0x80800140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800164;
    // 0x80800140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800144:
    // 0x80800144: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800148: jal         0x800EB2DC
    // 0x8080014C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800EB2DC(rdram, ctx);
        goto after_0;
    // 0x8080014C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800150: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800154: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800158: jal         0x800EB2DC
    // 0x8080015C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800EB2DC(rdram, ctx);
        goto after_1;
    // 0x8080015C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800164:
    // 0x80800164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080016C: jr          $ra
    // 0x80800170: nop

    return;
    // 0x80800170: nop

;}
RECOMP_FUNC void bainvisible_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808004F4: lw          $a1, 0xA8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XA8);
    // 0x808004F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808004FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800500: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x80800504: jal         0x80800000
    // 0x80800508: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800000_bainvisible(rdram, ctx);
        goto after_0;
    // 0x80800508: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080050C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800510: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800514: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800518: jal         0x80800000
    // 0x8080051C: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_80800000_bainvisible(rdram, ctx);
        goto after_1;
    // 0x8080051C: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_1:
    // 0x80800520: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800524: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800528: jal         0x800917A8
    // 0x8080052C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    bastatetimer_set(rdram, ctx);
        goto after_2;
    // 0x8080052C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800534: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void func_808003BC_chintroticker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: jr          $ra
    // 0x808003C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808003C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808016E4_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808016E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016EC: jal         0x80100094
    // 0x808016F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808016F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808016F4: lh          $t6, 0x820($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X820);
    // 0x808016F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808016FC: beql        $t6, $zero, L_80801718
    if (ctx->r14 == 0) {
        // 0x80801700: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801718;
    }
    goto skip_0;
    // 0x80801700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801704: jal         0x800856B8
    // 0x80801708: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _capod_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801708: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080170C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801710: sh          $zero, 0x820($v1)
    MEM_H(0X820, ctx->r3) = 0;
    // 0x80801714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801718:
    // 0x80801718: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080171C: jr          $ra
    // 0x80801720: nop

    return;
    // 0x80801720: nop

;}
RECOMP_FUNC void func_80805498_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805498: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080549C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808054A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808054A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808054A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808054AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808054B0: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x808054B4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808054B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808054BC: beq         $a2, $zero, L_808054E0
    if (ctx->r6 == 0) {
        // 0x808054C0: lui         $s1, 0x8081
        ctx->r17 = S32(RELOC_HI16(804, 0X83FC) << 16);
            goto L_808054E0;
    }
    // 0x808054C0: lui         $s1, 0x8081
    ctx->r17 = S32(RELOC_HI16(804, 0X83FC) << 16);
    // 0x808054C4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808054C8: beq         $a2, $at, L_80805564
    if (ctx->r6 == ctx->r1) {
        // 0x808054CC: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80805564;
    }
    // 0x808054CC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808054D0: beq         $a2, $at, L_808055AC
    if (ctx->r6 == ctx->r1) {
        // 0x808054D4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808055AC;
    }
    // 0x808054D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808054D8: b           L_80805688
    // 0x808054DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80805688;
    // 0x808054DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808054E0:
    // 0x808054E0: addiu       $s1, $s1, -0x7C04
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(804, 0X83FC));
L_808054E4:
    // 0x808054E4: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    // 0x808054E8: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x808054EC: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808054F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808054F4: jal         0x80087CF8
    // 0x808054F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_0;
    // 0x808054F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x808054FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805500: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80805504: jal         0x80087D90
    // 0x80805508: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_1;
    // 0x80805508: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    after_1:
    // 0x8080550C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805510: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80805514: jal         0x80805BA0
    // 0x80805518: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80805BA0_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80805518: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8080551C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80805520: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80805524: bne         $s0, $at, L_808054E4
    if (ctx->r16 != ctx->r1) {
        // 0x80805528: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808054E4;
    }
    // 0x80805528: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080552C: jal         0x80088360
    // 0x80805530: nop

    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80805530: nop

    after_3:
    // 0x80805534: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80805538: bne         $at, $zero, L_80805550
    if (ctx->r1 != 0) {
        // 0x8080553C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80805550;
    }
    // 0x8080553C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80805540: jal         0x80088360
    // 0x80805544: nop

    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80805544: nop

    after_4:
    // 0x80805548: b           L_80805550
    // 0x8080554C: addiu       $a2, $v0, -0x2
    ctx->r6 = ADD32(ctx->r2, -0X2);
        goto L_80805550;
    // 0x8080554C: addiu       $a2, $v0, -0x2
    ctx->r6 = ADD32(ctx->r2, -0X2);
L_80805550:
    // 0x80805550: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805554: jal         0x80087DE0
    // 0x80805558: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcnewoption_entrypoint_41(rdram, ctx);
        goto after_5;
    // 0x80805558: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_5:
    // 0x8080555C: b           L_80805688
    // 0x80805560: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80805688;
    // 0x80805560: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80805564:
    // 0x80805564: jal         0x80088360
    // 0x80805568: nop

    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80805568: nop

    after_6:
    // 0x8080556C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80805570: blez        $v0, L_80805684
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80805574: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80805684;
    }
    // 0x80805574: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80805578:
    // 0x80805578: jal         0x808062A8
    // 0x8080557C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808062A8_chgameselect(rdram, ctx);
        goto after_7;
    // 0x8080557C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80805580: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805584: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80805588: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8080558C: jal         0x80806218
    // 0x80805590: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80806218_chgameselect(rdram, ctx);
        goto after_8;
    // 0x80805590: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80805594: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80805598: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8080559C: bne         $at, $zero, L_80805578
    if (ctx->r1 != 0) {
        // 0x808055A0: nop
    
            goto L_80805578;
    }
    // 0x808055A0: nop

    // 0x808055A4: b           L_80805688
    // 0x808055A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80805688;
    // 0x808055A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808055AC:
    // 0x808055AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808055B0: jal         0x80087CF8
    // 0x808055B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_9;
    // 0x808055B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x808055B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808055BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808055C0: jal         0x80087CF8
    // 0x808055C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_10;
    // 0x808055C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x808055C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808055CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808055D0: jal         0x80087CF8
    // 0x808055D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x808055D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x808055D8: jal         0x80806A30
    // 0x808055DC: nop

    func_80806A30_chgameselect(rdram, ctx);
        goto after_12;
    // 0x808055DC: nop

    after_12:
    // 0x808055E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808055E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808055E8: jal         0x80806AF4
    // 0x808055EC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80806AF4_chgameselect(rdram, ctx);
        goto after_13;
    // 0x808055EC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_13:
    // 0x808055F0: jal         0x80088360
    // 0x808055F4: nop

    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_14;
    // 0x808055F4: nop

    after_14:
    // 0x808055F8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x808055FC: beq         $at, $zero, L_80805628
    if (ctx->r1 == 0) {
        // 0x80805600: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80805628;
    }
    // 0x80805600: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805604: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80805608: jal         0x80087CF8
    // 0x8080560C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_15;
    // 0x8080560C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_15:
    // 0x80805610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805614: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80805618: jal         0x8080401C
    // 0x8080561C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080401C_chgameselect(rdram, ctx);
        goto after_16;
    // 0x8080561C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x80805620: b           L_80805640
    // 0x80805624: nop

        goto L_80805640;
    // 0x80805624: nop

L_80805628:
    // 0x80805628: jal         0x808068E8
    // 0x8080562C: nop

    func_808068E8_chgameselect(rdram, ctx);
        goto after_17;
    // 0x8080562C: nop

    after_17:
    // 0x80805630: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805634: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80805638: jal         0x80806AF4
    // 0x8080563C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80806AF4_chgameselect(rdram, ctx);
        goto after_18;
    // 0x8080563C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_18:
L_80805640:
    // 0x80805640: lui         $s1, 0x8081
    ctx->r17 = S32(RELOC_HI16(804, 0X840C) << 16);
    // 0x80805644: addiu       $s1, $s1, -0x7BF4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(804, 0X840C));
    // 0x80805648: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8080564C:
    // 0x8080564C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805650: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80805654: jal         0x80087D90
    // 0x80805658: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_19;
    // 0x80805658: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    after_19:
    // 0x8080565C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80805660: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80805664: bne         $s0, $at, L_8080564C
    if (ctx->r16 != ctx->r1) {
        // 0x80805668: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080564C;
    }
    // 0x80805668: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080566C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80805670: jal         0x80805ECC
    // 0x80805674: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80805ECC_chgameselect(rdram, ctx);
        goto after_20;
    // 0x80805674: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_20:
    // 0x80805678: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080567C: jal         0x80087DE0
    // 0x80805680: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gcnewoption_entrypoint_41(rdram, ctx);
        goto after_21;
    // 0x80805680: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_21:
L_80805684:
    // 0x80805684: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80805688:
    // 0x80805688: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080568C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80805690: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80805694: jr          $ra
    // 0x80805698: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80805698: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80802530_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802538: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080253C: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    // 0x80802540: jal         0x80087B00
    // 0x80802544: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _gczoombox_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80802544: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802548: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080254C: jal         0x80087AF8
    // 0x80802550: lw          $a0, 0x28($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X28);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80802550: lw          $a0, 0x28($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X28);
    after_1:
    // 0x80802554: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80802558: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080255C: lw          $t6, 0x20($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X20);
    // 0x80802560: beql        $v0, $t6, L_8080257C
    if (ctx->r2 == ctx->r14) {
        // 0x80802564: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080257C;
    }
    goto skip_0;
    // 0x80802564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802568: bne         $v0, $at, L_80802578
    if (ctx->r2 != ctx->r1) {
        // 0x8080256C: sw          $v0, 0x20($a1)
        MEM_W(0X20, ctx->r5) = ctx->r2;
            goto L_80802578;
    }
    // 0x8080256C: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
    // 0x80802570: jal         0x80800CA0
    // 0x80802574: lw          $a0, 0x3C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X3C);
    func_80800CA0_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80802574: lw          $a0, 0x3C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X3C);
    after_2:
L_80802578:
    // 0x80802578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080257C:
    // 0x8080257C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802580: jr          $ra
    // 0x80802584: nop

    return;
    // 0x80802584: nop

;}
RECOMP_FUNC void func_800DF744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF744: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800DF748: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF74C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800DF750: jr          $ra
    // 0x800DF754: sw          $a1, -0x37B0($at)
    MEM_W(-0X37B0, ctx->r1) = ctx->r5;
    return;
    // 0x800DF754: sw          $a1, -0x37B0($at)
    MEM_W(-0X37B0, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_8080090C_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080090C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800914: jal         0x80082FE8
    // 0x80800918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080091C: jal         0x80084138
    // 0x80800920: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsvan_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800920: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080092C: jr          $ra
    // 0x80800930: nop

    return;
    // 0x80800930: nop

;}
