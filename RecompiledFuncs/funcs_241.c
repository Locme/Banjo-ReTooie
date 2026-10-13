#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chprisonbits_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087008: syscall     491
    recomp_syscall_handler(rdram, ctx, 0x80087008);
    return;
    // 0x8008700C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _idflashbaddie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DD0: syscall     741
    recomp_syscall_handler(rdram, ctx, 0x80088DD0);
    return;
    // 0x80088DD4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void ncpod_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808005A4: jr          $ra
    // 0x808005A8: swc1        $f12, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x808005A8: swc1        $f12, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void bababykaz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x808000B8: jr          $ra
    // 0x808000BC: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
    return;
    // 0x808000BC: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
;}
RECOMP_FUNC void func_808001BC_bainvisible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001BC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808001C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001C8: lw          $t6, 0xA8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA8);
    // 0x808001CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001D0: addiu       $t7, $t6, 0x1C
    ctx->r15 = ADD32(ctx->r14, 0X1C);
    // 0x808001D4: jal         0x800D8FF8
    // 0x808001D8: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808001D8: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    after_0:
    // 0x808001DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808001EC: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808001F0: jal         0x8009BC08
    // 0x808001F4: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    func_8009BC08(rdram, ctx);
        goto after_1;
    // 0x808001F4: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x808001F8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808001FC: jal         0x800EFB8C
    // 0x80800200: lw          $a1, 0xA8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XA8);
    func_800EFB8C(rdram, ctx);
        goto after_2;
    // 0x80800200: lw          $a1, 0xA8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XA8);
    after_2:
    // 0x80800204: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800208: lw          $a0, 0xA8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA8);
    // 0x8080020C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800210: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800214: jal         0x800EE7F8
    // 0x80800218: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800218: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8080021C: lw          $t8, 0xA8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XA8);
    // 0x80800220: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: lwc1        $f0, 0x14($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8080022C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800230: nop

    // 0x80800234: bc1f        L_80800248
    if (!c1cs) {
        // 0x80800238: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800248;
    }
    // 0x80800238: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080023C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800240: b           L_8080024C
    // 0x80800244: nop

        goto L_8080024C;
    // 0x80800244: nop

L_80800248:
    // 0x80800248: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
L_8080024C:
    // 0x8080024C: jal         0x8009C984
    // 0x80800250: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    yaw_get(rdram, ctx);
        goto after_4;
    // 0x80800250: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x80800254: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80800258: lw          $t9, 0xA8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XA8);
    // 0x8080025C: lwc1        $f10, 0xC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80800260: jal         0x80013728
    // 0x80800264: sub.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f10.fl;
    func_80013728(rdram, ctx);
        goto after_5;
    // 0x80800264: sub.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f10.fl;
    after_5:
    // 0x80800268: jal         0x800F2100
    // 0x8080026C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x8080026C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x80800270: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800274: lw          $t0, 0xA8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XA8);
    // 0x80800278: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8080027C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800280: swc1        $f16, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f16.u32l;
    // 0x80800284: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800288: lw          $v0, 0xA8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA8);
    // 0x8080028C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800290: mul.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800294: lwc1        $f14, 0x18($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800298: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x8080029C: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x808002A0: nop

    // 0x808002A4: bc1fl       L_808002BC
    if (!c1cs) {
        // 0x808002A8: div.s       $f0, $f12, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
            goto L_808002BC;
    }
    goto skip_0;
    // 0x808002A8: div.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    skip_0:
    // 0x808002AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808002B0: b           L_808002C0
    // 0x808002B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
        goto L_808002C0;
    // 0x808002B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808002B8: div.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
L_808002BC:
    // 0x808002BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_808002C0:
    // 0x808002C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(653, 0X9A8) << 16);
    // 0x808002C4: bc1fl       L_808002D8
    if (!c1cs) {
        // 0x808002C8: swc1        $f0, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
            goto L_808002D8;
    }
    goto skip_1;
    // 0x808002C8: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    skip_1:
    // 0x808002CC: b           L_808002D8
    // 0x808002D0: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
        goto L_808002D8;
    // 0x808002D0: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x808002D4: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
L_808002D8:
    // 0x808002D8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808002DC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x808002E0: bc1fl       L_808002F4
    if (!c1cs) {
        // 0x808002E4: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_808002F4;
    }
    goto skip_2;
    // 0x808002E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_2:
    // 0x808002E8: b           L_808002F4
    // 0x808002EC: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_808002F4;
    // 0x808002EC: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x808002F0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_808002F4:
    // 0x808002F4: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x808002F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x808002FC: bnel        $v0, $t1, L_80800320
    if (ctx->r2 != ctx->r9) {
        // 0x80800300: lbu         $t2, 0x30($a1)
        ctx->r10 = MEM_BU(ctx->r5, 0X30);
            goto L_80800320;
    }
    goto skip_3;
    // 0x80800300: lbu         $t2, 0x30($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X30);
    skip_3:
    // 0x80800304: lwc1        $f4, 0x9A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(653, 0X9A8));
    // 0x80800308: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(653, 0X9AC) << 16);
    // 0x8080030C: lwc1        $f8, 0x9AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(653, 0X9AC));
    // 0x80800310: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80800314: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800318: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    // 0x8080031C: lbu         $t2, 0x30($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X30);
L_80800320:
    // 0x80800320: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(653, 0X9B0) << 16);
    // 0x80800324: bnel        $v0, $t2, L_80800348
    if (ctx->r2 != ctx->r10) {
        // 0x80800328: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80800348;
    }
    goto skip_4;
    // 0x80800328: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_4:
    // 0x8080032C: lwc1        $f16, 0x9B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(653, 0X9B0));
    // 0x80800330: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(653, 0X9B4) << 16);
    // 0x80800334: lwc1        $f4, 0x9B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(653, 0X9B4));
    // 0x80800338: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8080033C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800340: swc1        $f6, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f6.u32l;
    // 0x80800344: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80800348:
    // 0x80800348: lbu         $t3, 0x1C($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1C);
    // 0x8080034C: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x80800350: beq         $t3, $zero, L_80800390
    if (ctx->r11 == 0) {
        // 0x80800354: nop
    
            goto L_80800390;
    }
    // 0x80800354: nop

    // 0x80800358: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8080035C: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80800360: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800364: nop

    // 0x80800368: bc1fl       L_8080037C
    if (!c1cs) {
        // 0x8080036C: lwc1        $f2, 0x14($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
            goto L_8080037C;
    }
    goto skip_5;
    // 0x8080036C: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    skip_5:
    // 0x80800370: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x80800374: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800378: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
L_8080037C:
    // 0x8080037C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800380: nop

    // 0x80800384: bc1f        L_80800390
    if (!c1cs) {
        // 0x80800388: nop
    
            goto L_80800390;
    }
    // 0x80800388: nop

    // 0x8080038C: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
L_80800390:
    // 0x80800390: bne         $v1, $a0, L_80800348
    if (ctx->r3 != ctx->r4) {
        // 0x80800394: addiu       $v0, $v0, 0x30
        ctx->r2 = ADD32(ctx->r2, 0X30);
            goto L_80800348;
    }
    // 0x80800394: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x80800398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080039C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x808003A4: jr          $ra
    // 0x808003A8: nop

    return;
    // 0x808003A8: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_42(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D94: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80802D98: jr          $ra
    // 0x80802D9C: swc1        $f12, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80802D9C: swc1        $f12, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void _chtntmineshoot_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873A0: syscall     559
    recomp_syscall_handler(rdram, ctx, 0x800873A0);
    return;
    // 0x800873A4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bstaxi_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EA8: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083EA8);
    return;
    // 0x80083EAC: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void _ncbaledge_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891C8: syscall     766
    recomp_syscall_handler(rdram, ctx, 0x800891C8);
    return;
    // 0x800891CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bawandglow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800350_chtorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800350: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800358: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080035C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800360: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80800364: jal         0x800F1A88
    // 0x80800368: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800F1A88(rdram, ctx);
        goto after_0;
    // 0x80800368: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8080036C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800370: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800374: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800378: swc1        $f6, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f6.u32l;
    // 0x8080037C: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800380: swc1        $f8, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f8.u32l;
    // 0x80800384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800388: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void func_800EED58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EED58: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800EED5C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800EED60: xor         $v0, $t6, $t7
    ctx->r2 = ctx->r14 ^ ctx->r15;
    // 0x800EED64: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800EED68: beq         $v0, $zero, L_800EED98
    if (ctx->r2 == 0) {
        // 0x800EED6C: nop
    
            goto L_800EED98;
    }
    // 0x800EED6C: nop

    // 0x800EED70: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x800EED74: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800EED78: xor         $v0, $t8, $t9
    ctx->r2 = ctx->r24 ^ ctx->r25;
    // 0x800EED7C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800EED80: beq         $v0, $zero, L_800EED98
    if (ctx->r2 == 0) {
        // 0x800EED84: nop
    
            goto L_800EED98;
    }
    // 0x800EED84: nop

    // 0x800EED88: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800EED8C: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x800EED90: xor         $v0, $t0, $t1
    ctx->r2 = ctx->r8 ^ ctx->r9;
    // 0x800EED94: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800EED98:
    // 0x800EED98: jr          $ra
    // 0x800EED9C: nop

    return;
    // 0x800EED9C: nop

;}
RECOMP_FUNC void bashoes_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800388: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080038C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800390: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800394: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800398: lw          $v0, 0x10C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10C);
    // 0x8080039C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808003A4: lbu         $s1, 0x4($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0X4);
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: beq         $s1, $at, L_808003D0
    if (ctx->r17 == ctx->r1) {
        // 0x808003B0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808003D0;
    }
    // 0x808003B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003B4: beq         $s1, $at, L_808003E0
    if (ctx->r17 == ctx->r1) {
        // 0x808003B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003E0;
    }
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808003C0: beq         $s1, $at, L_808003F0
    if (ctx->r17 == ctx->r1) {
        // 0x808003C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: b           L_80800400
    // 0x808003CC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_80800400;
    // 0x808003CC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_808003D0:
    // 0x808003D0: jal         0x808000D4
    // 0x808003D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808000D4_bashoes(rdram, ctx);
        goto after_0;
    // 0x808003D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x808003D8: b           L_808003FC
    // 0x808003DC: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
        goto L_808003FC;
    // 0x808003DC: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
L_808003E0:
    // 0x808003E0: jal         0x808000D4
    // 0x808003E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808000D4_bashoes(rdram, ctx);
        goto after_1;
    // 0x808003E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808003E8: b           L_808003FC
    // 0x808003EC: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
        goto L_808003FC;
    // 0x808003EC: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
L_808003F0:
    // 0x808003F0: jal         0x808000D4
    // 0x808003F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808000D4_bashoes(rdram, ctx);
        goto after_2;
    // 0x808003F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808003F8: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
L_808003FC:
    // 0x808003FC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800400:
    // 0x80800400: sb          $t6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r14;
    // 0x80800404: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800408: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080040C: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80800410: beq         $at, $zero, L_808004D8
    if (ctx->r1 == 0) {
        // 0x80800414: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808004D8;
    }
    // 0x80800414: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800418: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(592, 0XAA0) << 16);
    // 0x8080041C: addu        $at, $at, $t8
    gpr jr_addend_80800424 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800420: lw          $t8, 0xAA0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(592, 0XAA0));
    // 0x80800424: jr          $t8
    // 0x80800428: nop

    switch (jr_addend_80800424 >> 2) {
        case 0: goto L_8080042C; break;
        case 1: goto L_80800444; break;
        case 2: goto L_8080045C; break;
        case 3: goto L_80800488; break;
        case 4: goto L_808004B4; break;
        default: switch_error(__func__, 0x80800424, 0x80800AA0);
    }
    // 0x80800428: nop

L_8080042C:
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80800434: jal         0x8009ADF0
    // 0x80800438: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009ADF0(rdram, ctx);
        goto after_3;
    // 0x80800438: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8080043C: b           L_808004DC
    // 0x80800440: lw          $t9, 0x10C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10C);
        goto L_808004DC;
    // 0x80800440: lw          $t9, 0x10C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10C);
L_80800444:
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8080044C: jal         0x8009ADF0
    // 0x80800450: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_4;
    // 0x80800450: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800454: b           L_808004DC
    // 0x80800458: lw          $t9, 0x10C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10C);
        goto L_808004DC;
    // 0x80800458: lw          $t9, 0x10C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10C);
L_8080045C:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80800464: jal         0x8009ADF0
    // 0x80800468: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_5;
    // 0x80800468: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800474: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800478: jal         0x80800128
    // 0x8080047C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80800128_bashoes(rdram, ctx);
        goto after_6;
    // 0x8080047C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_6:
    // 0x80800480: b           L_808004DC
    // 0x80800484: lw          $t9, 0x10C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10C);
        goto L_808004DC;
    // 0x80800484: lw          $t9, 0x10C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10C);
L_80800488:
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80800490: jal         0x8009ADF0
    // 0x80800494: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_7;
    // 0x80800494: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080049C: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x808004A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808004A4: jal         0x80800128
    // 0x808004A8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80800128_bashoes(rdram, ctx);
        goto after_8;
    // 0x808004A8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_8:
    // 0x808004AC: b           L_808004DC
    // 0x808004B0: lw          $t9, 0x10C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10C);
        goto L_808004DC;
    // 0x808004B0: lw          $t9, 0x10C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10C);
L_808004B4:
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x808004BC: jal         0x8009ADF0
    // 0x808004C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_9;
    // 0x808004C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x808004CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808004D0: jal         0x80800128
    // 0x808004D4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80800128_bashoes(rdram, ctx);
        goto after_10;
    // 0x808004D4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_10:
L_808004D8:
    // 0x808004D8: lw          $t9, 0x10C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10C);
L_808004DC:
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808004E4: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x808004E8: beql        $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808004FC;
    }
    goto skip_0;
    // 0x808004EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808004F0: jalr        $v0
    // 0x808004F4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_11;
    // 0x808004F4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x808004F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004FC:
    // 0x808004FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800500: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800504: jr          $ra
    // 0x80800508: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800508: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _bstntswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FD0: syscall     100
    recomp_syscall_handler(rdram, ctx, 0x80083FD0);
    return;
    // 0x80083FD4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsdronebitten_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083030: syscall     39
    recomp_syscall_handler(rdram, ctx, 0x80083030);
    return;
    // 0x80083034: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800594_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800594: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800598: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080059C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808005A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808005A4: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x808005A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808005B0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808005B4: jal         0x800A2CE8
    // 0x808005B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_0;
    // 0x808005B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x808005BC: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808005C0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C8: jal         0x800A2CE8
    // 0x808005CC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_1;
    // 0x808005CC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x808005D0: jal         0x80800128
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800128_bscarry(rdram, ctx);
        goto after_2;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808005D8: jal         0x8009EF10
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_3;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005E0: beq         $v0, $zero, L_808005FC
    if (ctx->r2 == 0) {
        // 0x808005E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005FC;
    }
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005EC: beql        $v0, $at, L_80800618
    if (ctx->r2 == ctx->r1) {
        // 0x808005F0: addiu       $s1, $zero, 0x9F
        ctx->r17 = ADD32(0, 0X9F);
            goto L_80800618;
    }
    goto skip_0;
    // 0x808005F0: addiu       $s1, $zero, 0x9F
    ctx->r17 = ADD32(0, 0X9F);
    skip_0:
    // 0x808005F4: b           L_80800618
    // 0x808005F8: nop

        goto L_80800618;
    // 0x808005F8: nop

L_808005FC:
    // 0x808005FC: jal         0x8009BCD4
    // 0x80800600: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_4;
    // 0x80800600: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80800604: beq         $v0, $zero, L_80800618
    if (ctx->r2 == 0) {
        // 0x80800608: nop
    
            goto L_80800618;
    }
    // 0x80800608: nop

    // 0x8080060C: b           L_80800618
    // 0x80800610: addiu       $s1, $zero, 0x3A
    ctx->r17 = ADD32(0, 0X3A);
        goto L_80800618;
    // 0x80800610: addiu       $s1, $zero, 0x3A
    ctx->r17 = ADD32(0, 0X3A);
    // 0x80800614: addiu       $s1, $zero, 0x9F
    ctx->r17 = ADD32(0, 0X9F);
L_80800618:
    // 0x80800618: jal         0x80084D40
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bahold_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800620: bne         $v0, $zero, L_8080062C
    if (ctx->r2 != 0) {
        // 0x80800624: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080062C;
    }
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800628: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8080062C:
    // 0x8080062C: jal         0x8009E5C8
    // 0x80800630: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x80800630: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80800634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800638: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080063C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800640: jr          $ra
    // 0x80800644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _gczoomboxdata_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088440: syscall     682
    recomp_syscall_handler(rdram, ctx, 0x80088440);
    return;
    // 0x80088444: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800660_gccollectDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800660: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800664: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800668: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080066C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800670: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800674: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800678: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080067C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800680: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800684: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80800688: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8080068C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800690: addu        $s0, $t8, $a0
    ctx->r16 = ADD32(ctx->r24, ctx->r4);
    // 0x80800694: lh          $s4, 0x0($s0)
    ctx->r20 = MEM_H(ctx->r16, 0X0);
    // 0x80800698: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080069C: blezl       $s4, L_808006F0
    if (SIGNED(ctx->r20) <= 0) {
        // 0x808006A0: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_808006F0;
    }
    goto skip_0;
    // 0x808006A0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    skip_0:
L_808006A4:
    // 0x808006A4: lh          $s2, 0x0($s0)
    ctx->r18 = MEM_H(ctx->r16, 0X0);
    // 0x808006A8: jal         0x800CF87C
    // 0x808006AC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    func_800CF87C(rdram, ctx);
        goto after_0;
    // 0x808006AC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x808006B0: addu        $a0, $v0, $s2
    ctx->r4 = ADD32(ctx->r2, ctx->r18);
    // 0x808006B4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808006B8: jal         0x800D0A9C
    // 0x808006BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x808006BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808006C0: beq         $v0, $zero, L_808006E0
    if (ctx->r2 == 0) {
        // 0x808006C4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808006E0;
    }
    // 0x808006C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006C8: jal         0x800D0B68
    // 0x808006CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x808006CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808006D0: bne         $v0, $zero, L_808006E0
    if (ctx->r2 != 0) {
        // 0x808006D4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808006E0;
    }
    // 0x808006D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006D8: jal         0x808005BC
    // 0x808006DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808005BC_gccollectDll(rdram, ctx);
        goto after_3;
    // 0x808006DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
L_808006E0:
    // 0x808006E0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x808006E4: bne         $s3, $s4, L_808006A4
    if (ctx->r19 != ctx->r20) {
        // 0x808006E8: addiu       $s0, $s0, 0x6
        ctx->r16 = ADD32(ctx->r16, 0X6);
            goto L_808006A4;
    }
    // 0x808006E8: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x808006EC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_808006F0:
    // 0x808006F0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x808006F4: subu        $t1, $s0, $v0
    ctx->r9 = SUB32(ctx->r16, ctx->r2);
    // 0x808006F8: sra         $t2, $t1, 2
    ctx->r10 = S32(SIGNED(ctx->r9) >> 2);
    // 0x808006FC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80800700: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800704: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800708: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080070C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800710: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800714: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800718: jr          $ra
    // 0x8080071C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080071C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chtrashcompactor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861D8: syscall     288
    recomp_syscall_handler(rdram, ctx, 0x800861D8);
    return;
    // 0x800861DC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800F98_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800F9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FA0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800FA4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800FA8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800FAC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800FB0: jal         0x80100094
    // 0x80800FB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800FB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800FB8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800FBC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80800FC0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800FC4: slti        $at, $a3, 0xCED
    ctx->r1 = SIGNED(ctx->r7) < 0XCED ? 1 : 0;
    // 0x80800FC8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800FCC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80800FD0: bne         $at, $zero, L_80801028
    if (ctx->r1 != 0) {
        // 0x80800FD4: sw          $zero, 0x30($sp)
        MEM_W(0X30, ctx->r29) = 0;
            goto L_80801028;
    }
    // 0x80800FD4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80800FD8: slti        $at, $a3, 0x1411
    ctx->r1 = SIGNED(ctx->r7) < 0X1411 ? 1 : 0;
    // 0x80800FDC: bne         $at, $zero, L_80801008
    if (ctx->r1 != 0) {
        // 0x80800FE0: addiu       $t8, $a3, -0x1405
        ctx->r24 = ADD32(ctx->r7, -0X1405);
            goto L_80801008;
    }
    // 0x80800FE0: addiu       $t8, $a3, -0x1405
    ctx->r24 = ADD32(ctx->r7, -0X1405);
    // 0x80800FE4: addiu       $t7, $a3, -0x1449
    ctx->r15 = ADD32(ctx->r7, -0X1449);
    // 0x80800FE8: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80800FEC: beq         $at, $zero, L_80801228
    if (ctx->r1 == 0) {
        // 0x80800FF0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80801228;
    }
    // 0x80800FF0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800FF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(776, 0X1EA0) << 16);
    // 0x80800FF8: addu        $at, $at, $t7
    gpr jr_addend_80801000 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800FFC: lw          $t7, 0x1EA0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(776, 0X1EA0));
    // 0x80801000: jr          $t7
    // 0x80801004: nop

    switch (jr_addend_80801000 >> 2) {
        case 0: goto L_808010F0; break;
        case 1: goto L_808010F0; break;
        case 2: goto L_808010F0; break;
        case 3: goto L_80801218; break;
        case 4: goto L_808010F0; break;
        case 5: goto L_80801218; break;
        case 6: goto L_80801218; break;
        case 7: goto L_80801218; break;
        default: switch_error(__func__, 0x80801000, 0x80801EA0);
    }
    // 0x80801004: nop

L_80801008:
    // 0x80801008: sltiu       $at, $t8, 0xC
    ctx->r1 = ctx->r24 < 0XC ? 1 : 0;
    // 0x8080100C: beq         $at, $zero, L_80801228
    if (ctx->r1 == 0) {
        // 0x80801010: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801228;
    }
    // 0x80801010: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801014: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(776, 0X1EC0) << 16);
    // 0x80801018: addu        $at, $at, $t8
    gpr jr_addend_80801020 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080101C: lw          $t8, 0x1EC0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(776, 0X1EC0));
    // 0x80801020: jr          $t8
    // 0x80801024: nop

    switch (jr_addend_80801020 >> 2) {
        case 0: goto L_80801044; break;
        case 1: goto L_80801044; break;
        case 2: goto L_80801044; break;
        case 3: goto L_80801070; break;
        case 4: goto L_808010C0; break;
        case 5: goto L_80801194; break;
        case 6: goto L_808011D8; break;
        case 7: goto L_808011D8; break;
        case 8: goto L_80801218; break;
        case 9: goto L_80801218; break;
        case 10: goto L_80801218; break;
        case 11: goto L_80801218; break;
        default: switch_error(__func__, 0x80801020, 0x80801EC0);
    }
    // 0x80801024: nop

L_80801028:
    // 0x80801028: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x8080102C: beq         $a3, $at, L_8080110C
    if (ctx->r7 == ctx->r1) {
        // 0x80801030: addiu       $at, $zero, 0xCEC
        ctx->r1 = ADD32(0, 0XCEC);
            goto L_8080110C;
    }
    // 0x80801030: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80801034: beq         $a3, $at, L_808010FC
    if (ctx->r7 == ctx->r1) {
        // 0x80801038: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808010FC;
    }
    // 0x80801038: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080103C: b           L_8080122C
    // 0x80801040: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
        goto L_8080122C;
    // 0x80801040: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_80801044:
    // 0x80801044: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801048: addiu       $a1, $v1, 0x24
    ctx->r5 = ADD32(ctx->r3, 0X24);
    // 0x8080104C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80801050: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801054: jal         0x8008A2C8
    // 0x80801058: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80801058: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8080105C: addiu       $t9, $zero, 0x1408
    ctx->r25 = ADD32(0, 0X1408);
    // 0x80801060: addiu       $t0, $zero, 0x46
    ctx->r8 = ADD32(0, 0X46);
    // 0x80801064: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80801068: b           L_80801228
    // 0x8080106C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
        goto L_80801228;
    // 0x8080106C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80801070:
    // 0x80801070: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801074: bne         $a0, $at, L_808010A4
    if (ctx->r4 != ctx->r1) {
        // 0x80801078: addiu       $t2, $zero, 0xCEC
        ctx->r10 = ADD32(0, 0XCEC);
            goto L_808010A4;
    }
    // 0x80801078: addiu       $t2, $zero, 0xCEC
    ctx->r10 = ADD32(0, 0XCEC);
    // 0x8080107C: addiu       $t1, $zero, 0x1409
    ctx->r9 = ADD32(0, 0X1409);
    // 0x80801080: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80801084: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801088: addiu       $a1, $v1, 0x24
    ctx->r5 = ADD32(ctx->r3, 0X24);
    // 0x8080108C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80801090: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80801094: jal         0x8008A2D0
    // 0x80801098: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80801098: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8080109C: b           L_8080122C
    // 0x808010A0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
        goto L_8080122C;
    // 0x808010A0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_808010A4:
    // 0x808010A4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x808010A8: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    // 0x808010AC: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x808010B0: jal         0x80101180
    // 0x808010B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x808010B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808010B8: b           L_8080122C
    // 0x808010BC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
        goto L_8080122C;
    // 0x808010BC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_808010C0:
    // 0x808010C0: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    // 0x808010C4: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x808010C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808010CC: jal         0x80101180
    // 0x808010D0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_80101180(rdram, ctx);
        goto after_4;
    // 0x808010D0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_4:
    // 0x808010D4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808010D8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808010DC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808010E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808010E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808010E8: jal         0x8008A2C8
    // 0x808010EC: addiu       $a1, $v1, 0x24
    ctx->r5 = ADD32(ctx->r3, 0X24);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x808010EC: addiu       $a1, $v1, 0x24
    ctx->r5 = ADD32(ctx->r3, 0X24);
    after_5:
L_808010F0:
    // 0x808010F0: addiu       $t3, $zero, 0xCEC
    ctx->r11 = ADD32(0, 0XCEC);
    // 0x808010F4: b           L_80801228
    // 0x808010F8: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
        goto L_80801228;
    // 0x808010F8: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
L_808010FC:
    // 0x808010FC: jal         0x80800018
    // 0x80801100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800018_chwaspnestgame(rdram, ctx);
        goto after_6;
    // 0x80801100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80801104: b           L_8080122C
    // 0x80801108: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
        goto L_8080122C;
    // 0x80801108: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_8080110C:
    // 0x8080110C: jal         0x800D395C
    // 0x80801110: nop

    func_800D395C(rdram, ctx);
        goto after_7;
    // 0x80801110: nop

    after_7:
    // 0x80801114: beq         $v0, $zero, L_80801148
    if (ctx->r2 == 0) {
        // 0x80801118: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80801148;
    }
    // 0x80801118: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080111C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801120: bne         $a0, $at, L_80801138
    if (ctx->r4 != ctx->r1) {
        // 0x80801124: nop
    
            goto L_80801138;
    }
    // 0x80801124: nop

    // 0x80801128: jal         0x80088188
    // 0x8080112C: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x8080112C: nop

    after_8:
    // 0x80801130: b           L_8080122C
    // 0x80801134: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
        goto L_8080122C;
    // 0x80801134: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_80801138:
    // 0x80801138: jal         0x80088180
    // 0x8080113C: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x8080113C: nop

    after_9:
    // 0x80801140: b           L_8080122C
    // 0x80801144: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
        goto L_8080122C;
    // 0x80801144: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_80801148:
    // 0x80801148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080114C: bne         $a0, $at, L_80801160
    if (ctx->r4 != ctx->r1) {
        // 0x80801150: addiu       $a2, $zero, 0x136
        ctx->r6 = ADD32(0, 0X136);
            goto L_80801160;
    }
    // 0x80801150: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x80801154: addiu       $a2, $zero, 0x139
    ctx->r6 = ADD32(0, 0X139);
    // 0x80801158: b           L_80801164
    // 0x8080115C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80801164;
    // 0x8080115C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80801160:
    // 0x80801160: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
L_80801164:
    // 0x80801164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801168: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080116C: jal         0x80090708
    // 0x80801170: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80090708(rdram, ctx);
        goto after_10;
    // 0x80801170: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_10:
    // 0x80801174: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801178: jal         0x80800018
    // 0x8080117C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800018_chwaspnestgame(rdram, ctx);
        goto after_11;
    // 0x8080117C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80801180: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801184: jal         0x80087A58
    // 0x80801188: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80801188: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x8080118C: b           L_8080122C
    // 0x80801190: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
        goto L_8080122C;
    // 0x80801190: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_80801194:
    // 0x80801194: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80801198: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8080119C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808011A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808011A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808011A8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x808011AC: jal         0x800D1000
    // 0x808011B0: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    func_800D1000(rdram, ctx);
        goto after_13;
    // 0x808011B0: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    after_13:
    // 0x808011B4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808011B8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808011BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808011C0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x808011C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808011C8: jal         0x8008A2D0
    // 0x808011CC: addiu       $a1, $v1, 0x24
    ctx->r5 = ADD32(ctx->r3, 0X24);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x808011CC: addiu       $a1, $v1, 0x24
    ctx->r5 = ADD32(ctx->r3, 0X24);
    after_14:
    // 0x808011D0: b           L_8080122C
    // 0x808011D4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
        goto L_8080122C;
    // 0x808011D4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_808011D8:
    // 0x808011D8: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x808011DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808011E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808011E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808011E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808011EC: jal         0x800D1000
    // 0x808011F0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800D1000(rdram, ctx);
        goto after_15;
    // 0x808011F0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_15:
    // 0x808011F4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808011F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808011FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80801200: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80801204: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801208: jal         0x8008A2D0
    // 0x8080120C: addiu       $a1, $v1, 0x24
    ctx->r5 = ADD32(ctx->r3, 0X24);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_16;
    // 0x8080120C: addiu       $a1, $v1, 0x24
    ctx->r5 = ADD32(ctx->r3, 0X24);
    after_16:
    // 0x80801210: b           L_8080122C
    // 0x80801214: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
        goto L_8080122C;
    // 0x80801214: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_80801218:
    // 0x80801218: addiu       $t4, $zero, 0xCEB
    ctx->r12 = ADD32(0, 0XCEB);
    // 0x8080121C: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x80801220: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80801224: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_80801228:
    // 0x80801228: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_8080122C:
    // 0x8080122C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80801230: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80801234: beq         $t6, $zero, L_80801250
    if (ctx->r14 == 0) {
        // 0x80801238: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80801250;
    }
    // 0x80801238: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8080123C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80801240: addiu       $t8, $zero, 0x99
    ctx->r24 = ADD32(0, 0X99);
    // 0x80801244: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801248: jal         0x8008A208
    // 0x8080124C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x8080124C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
L_80801250:
    // 0x80801250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801254: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801258: jr          $ra
    // 0x8080125C: nop

    return;
    // 0x8080125C: nop

;}
RECOMP_FUNC void func_800C08F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C08F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C08FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0900: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0904: jal         0x800881F8
    // 0x800C0908: lw          $a0, -0x750C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X750C);
    _gcnewpause_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800C0908: lw          $a0, -0x750C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X750C);
    after_0:
    // 0x800C090C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0910: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0914: sw          $v0, -0x7510($at)
    MEM_W(-0X7510, ctx->r1) = ctx->r2;
    // 0x800C0918: jr          $ra
    // 0x800C091C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C091C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800BA4_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800BB0: jal         0x800839E8
    // 0x80800BB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800BB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800BB8: beq         $v0, $zero, L_80800BC4
    if (ctx->r2 == 0) {
        // 0x80800BBC: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BC4;
    }
    // 0x80800BBC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BC0: addiu       $a1, $zero, 0x16C
    ctx->r5 = ADD32(0, 0X16C);
L_80800BC4:
    // 0x80800BC4: jal         0x8009E5C8
    // 0x80800BC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80800BC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BD4: jr          $ra
    // 0x80800BD8: nop

    return;
    // 0x80800BD8: nop

;}
RECOMP_FUNC void func_808001D0_chjigsaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D8: jal         0x80105834
    // 0x808001DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80105834(rdram, ctx);
        goto after_0;
    // 0x808001DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001E0: jal         0x8080011C
    // 0x808001E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080011C_chjigsaw(rdram, ctx);
        goto after_1;
    // 0x808001E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F0: jr          $ra
    // 0x808001F4: nop

    return;
    // 0x808001F4: nop

;}
RECOMP_FUNC void func_80801964_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801964: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801968: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080196C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801970: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801974: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80801978: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080197C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80801980: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801984: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80801988: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8080198C: jal         0x80100094
    // 0x80801990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801998: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8080199C: jal         0x80102424
    // 0x808019A0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808019A0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x808019A4: jal         0x8080305C
    // 0x808019A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080305C_chklungo(rdram, ctx);
        goto after_2;
    // 0x808019A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808019AC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x808019B0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808019B4: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x808019B8: sltiu       $at, $t9, 0x22
    ctx->r1 = ctx->r25 < 0X22 ? 1 : 0;
    // 0x808019BC: beq         $at, $zero, L_808020BC
    if (ctx->r1 == 0) {
        // 0x808019C0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808020BC;
    }
    // 0x808019C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808019C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X37E4) << 16);
    // 0x808019C8: addu        $at, $at, $t9
    gpr jr_addend_808019D0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808019CC: lw          $t9, 0x37E4($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1240, 0X37E4));
    // 0x808019D0: jr          $t9
    // 0x808019D4: nop

    switch (jr_addend_808019D0 >> 2) {
        case 0: goto L_808019D8; break;
        case 1: goto L_808020BC; break;
        case 2: goto L_808020BC; break;
        case 3: goto L_80801A00; break;
        case 4: goto L_80801A88; break;
        case 5: goto L_80801ACC; break;
        case 6: goto L_808020BC; break;
        case 7: goto L_80801AEC; break;
        case 8: goto L_808020BC; break;
        case 9: goto L_808020BC; break;
        case 10: goto L_80801B00; break;
        case 11: goto L_80801B54; break;
        case 12: goto L_80801BE0; break;
        case 13: goto L_80801C5C; break;
        case 14: goto L_80801C98; break;
        case 15: goto L_80801CB4; break;
        case 16: goto L_80801CE8; break;
        case 17: goto L_80801D3C; break;
        case 18: goto L_80801D50; break;
        case 19: goto L_808020BC; break;
        case 20: goto L_808020BC; break;
        case 21: goto L_80801DC0; break;
        case 22: goto L_80801E00; break;
        case 23: goto L_80801E48; break;
        case 24: goto L_80801D3C; break;
        case 25: goto L_808020BC; break;
        case 26: goto L_80801E6C; break;
        case 27: goto L_80801F6C; break;
        case 28: goto L_80801FD8; break;
        case 29: goto L_8080200C; break;
        case 30: goto L_808020BC; break;
        case 31: goto L_80802028; break;
        case 32: goto L_80802038; break;
        case 33: goto L_80802080; break;
        default: switch_error(__func__, 0x808019D0, 0x808037E4);
    }
    // 0x808019D4: nop

L_808019D8:
    // 0x808019D8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808019DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808019E0: sh          $t0, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r8;
    // 0x808019E4: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x808019E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X386C) << 16);
    // 0x808019EC: lwc1        $f8, 0x386C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1240, 0X386C));
    // 0x808019F0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808019F4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808019F8: b           L_808020BC
    // 0x808019FC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_808020BC;
    // 0x808019FC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_80801A00:
    // 0x80801A00: jal         0x800F54E4
    // 0x80801A04: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80801A04: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_3:
    // 0x80801A08: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A10: jal         0x808025CC
    // 0x80801A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808025CC_chklungo(rdram, ctx);
        goto after_4;
    // 0x80801A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80801A18: jal         0x800F497C
    // 0x80801A1C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F497C(rdram, ctx);
        goto after_5;
    // 0x80801A1C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80801A20: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801A24: jal         0x800F49A8
    // 0x80801A28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F49A8(rdram, ctx);
        goto after_6;
    // 0x80801A28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80801A2C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80801A30: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x80801A34: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801A38: jal         0x800F49D4
    // 0x80801A3C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_7;
    // 0x80801A3C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80801A40: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80801A44: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    // 0x80801A48: lh          $t1, 0x40($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X40);
    // 0x80801A4C: beq         $t1, $zero, L_80801A5C
    if (ctx->r9 == 0) {
        // 0x80801A50: nop
    
            goto L_80801A5C;
    }
    // 0x80801A50: nop

    // 0x80801A54: b           L_80801A5C
    // 0x80801A58: addiu       $v0, $zero, 0xDC
    ctx->r2 = ADD32(0, 0XDC);
        goto L_80801A5C;
    // 0x80801A58: addiu       $v0, $zero, 0xDC
    ctx->r2 = ADD32(0, 0XDC);
L_80801A5C:
    // 0x80801A5C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80801A60: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801A64: addiu       $a1, $v1, 0x64
    ctx->r5 = ADD32(ctx->r3, 0X64);
    // 0x80801A68: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801A6C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80801A70: jal         0x800F4A58
    // 0x80801A74: nop

    func_800F4A58(rdram, ctx);
        goto after_8;
    // 0x80801A74: nop

    after_8:
    // 0x80801A78: jal         0x800FDC28
    // 0x80801A7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_9;
    // 0x80801A7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x80801A80: b           L_808020C0
    // 0x80801A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801A88:
    // 0x80801A88: lh          $t2, 0x42($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X42);
    // 0x80801A8C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80801A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A94: beq         $t2, $zero, L_80801AAC
    if (ctx->r10 == 0) {
        // 0x80801A98: nop
    
            goto L_80801AAC;
    }
    // 0x80801A98: nop

    // 0x80801A9C: jal         0x80801964
    // 0x80801AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801964_chklungo(rdram, ctx);
        goto after_10;
    // 0x80801AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801AA4: b           L_80801AB8
    // 0x80801AA8: addiu       $a0, $zero, 0x41F
    ctx->r4 = ADD32(0, 0X41F);
        goto L_80801AB8;
    // 0x80801AA8: addiu       $a0, $zero, 0x41F
    ctx->r4 = ADD32(0, 0X41F);
L_80801AAC:
    // 0x80801AAC: jal         0x808025CC
    // 0x80801AB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808025CC_chklungo(rdram, ctx);
        goto after_11;
    // 0x80801AB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80801AB4: addiu       $a0, $zero, 0x41F
    ctx->r4 = ADD32(0, 0X41F);
L_80801AB8:
    // 0x80801AB8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80801ABC: jal         0x80101180
    // 0x80801AC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_12;
    // 0x80801AC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80801AC4: b           L_808020C0
    // 0x80801AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801ACC:
    // 0x80801ACC: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x80801AD0: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x80801AD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801AD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801ADC: jal         0x800861A0
    // 0x80801AE0: addiu       $a1, $a1, 0xB
    ctx->r5 = ADD32(ctx->r5, 0XB);
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x80801AE0: addiu       $a1, $a1, 0xB
    ctx->r5 = ADD32(ctx->r5, 0XB);
    after_13:
    // 0x80801AE4: b           L_808020C0
    // 0x80801AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801AEC:
    // 0x80801AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AF0: jal         0x808025CC
    // 0x80801AF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808025CC_chklungo(rdram, ctx);
        goto after_14;
    // 0x80801AF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x80801AF8: b           L_808020C0
    // 0x80801AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801B00:
    // 0x80801B00: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x80801B04: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(1240, 0X38A0) << 16);
    // 0x80801B08: addiu       $t5, $t5, 0x38A0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(1240, 0X38A0));
    // 0x80801B0C: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80801B10: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80801B14: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80801B18: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80801B1C: lwc1        $f12, 0x68($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80801B20: jal         0x800DC178
    // 0x80801B24: lwc1        $f14, 0x6C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X6C);
    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x80801B24: lwc1        $f14, 0x6C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X6C);
    after_15:
    // 0x80801B28: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80801B2C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80801B30: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80801B34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801B38: bne         $t6, $at, L_80801B4C
    if (ctx->r14 != ctx->r1) {
        // 0x80801B3C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80801B4C;
    }
    // 0x80801B3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801B40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801B44: nop

    // 0x80801B48: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80801B4C:
    // 0x80801B4C: b           L_808020BC
    // 0x80801B50: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
        goto L_808020BC;
    // 0x80801B50: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_80801B54:
    // 0x80801B54: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    // 0x80801B58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B60: beq         $v0, $zero, L_80801B84
    if (ctx->r2 == 0) {
        // 0x80801B64: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80801B84;
    }
    // 0x80801B64: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801B68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801B6C: beq         $v0, $at, L_80801BA0
    if (ctx->r2 == ctx->r1) {
        // 0x80801B70: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801BA0;
    }
    // 0x80801B70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801B74: beql        $v0, $at, L_80801B98
    if (ctx->r2 == ctx->r1) {
        // 0x80801B78: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80801B98;
    }
    goto skip_0;
    // 0x80801B78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80801B7C: b           L_80801BA0
    // 0x80801B80: nop

        goto L_80801BA0;
    // 0x80801B80: nop

L_80801B84:
    // 0x80801B84: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80801B88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801B8C: b           L_80801BA0
    // 0x80801B90: nop

        goto L_80801BA0;
    // 0x80801B90: nop

    // 0x80801B94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80801B98:
    // 0x80801B98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801B9C: nop

L_80801BA0:
    // 0x80801BA0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3BC0) << 16);
    // 0x80801BA4: addiu       $a2, $a2, 0x3BC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3BC0));
    // 0x80801BA8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80801BAC: jal         0x80089D18
    // 0x80801BB0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x80801BB0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x80801BB4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BBC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801BC0: jal         0x8080322C
    // 0x80801BC4: nop

    func_8080322C_chklungo(rdram, ctx);
        goto after_17;
    // 0x80801BC4: nop

    after_17:
    // 0x80801BC8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80801BCC: jal         0x800EE7F8
    // 0x80801BD0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_18;
    // 0x80801BD0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_18:
    // 0x80801BD4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801BD8: b           L_808020BC
    // 0x80801BDC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
        goto L_808020BC;
    // 0x80801BDC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_80801BE0:
    // 0x80801BE0: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80801BE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801BE8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801BEC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80801BF0: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    // 0x80801BF4: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x80801BF8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C00: bnel        $t1, $at, L_80801C10
    if (ctx->r9 != ctx->r1) {
        // 0x80801C04: lbu         $t3, 0x49($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X49);
            goto L_80801C10;
    }
    goto skip_1;
    // 0x80801C04: lbu         $t3, 0x49($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X49);
    skip_1:
    // 0x80801C08: sb          $t2, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r10;
    // 0x80801C0C: lbu         $t3, 0x49($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X49);
L_80801C10:
    // 0x80801C10: beq         $t3, $zero, L_80801C24
    if (ctx->r11 == 0) {
        // 0x80801C14: nop
    
            goto L_80801C24;
    }
    // 0x80801C14: nop

    // 0x80801C18: lbu         $t4, 0x12($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X12);
    // 0x80801C1C: beq         $t4, $zero, L_80801C38
    if (ctx->r12 == 0) {
        // 0x80801C20: nop
    
            goto L_80801C38;
    }
    // 0x80801C20: nop

L_80801C24:
    // 0x80801C24: jal         0x808018D4
    // 0x80801C28: sb          $t5, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r13;
    func_808018D4_chklungo(rdram, ctx);
        goto after_19;
    // 0x80801C28: sb          $t5, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r13;
    after_19:
    // 0x80801C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C30: jal         0x808025CC
    // 0x80801C34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808025CC_chklungo(rdram, ctx);
        goto after_20;
    // 0x80801C34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_20:
L_80801C38:
    // 0x80801C38: jal         0x80802FCC
    // 0x80801C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802FCC_chklungo(rdram, ctx);
        goto after_21;
    // 0x80801C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80801C40: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3A2C) << 16);
    // 0x80801C44: addiu       $a2, $a2, 0x3A2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3A2C));
    // 0x80801C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C4C: jal         0x80089D18
    // 0x80801C50: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_22;
    // 0x80801C50: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_22:
    // 0x80801C54: b           L_808020C0
    // 0x80801C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801C5C:
    // 0x80801C5C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80801C60: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80801C64: beql        $t6, $at, L_808020C0
    if (ctx->r14 == ctx->r1) {
        // 0x80801C68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808020C0;
    }
    goto skip_2;
    // 0x80801C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80801C6C: lh          $t7, 0x26($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X26);
    // 0x80801C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C74: addiu       $a1, $zero, 0x1632
    ctx->r5 = ADD32(0, 0X1632);
    // 0x80801C78: bne         $t7, $zero, L_808020BC
    if (ctx->r15 != 0) {
        // 0x80801C7C: addiu       $a2, $zero, 0x44
        ctx->r6 = ADD32(0, 0X44);
            goto L_808020BC;
    }
    // 0x80801C7C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80801C80: jal         0x80803158
    // 0x80801C84: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80803158_chklungo(rdram, ctx);
        goto after_23;
    // 0x80801C84: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_23:
    // 0x80801C88: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80801C8C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801C90: b           L_808020BC
    // 0x80801C94: sh          $t8, 0x26($v1)
    MEM_H(0X26, ctx->r3) = ctx->r24;
        goto L_808020BC;
    // 0x80801C94: sh          $t8, 0x26($v1)
    MEM_H(0X26, ctx->r3) = ctx->r24;
L_80801C98:
    // 0x80801C98: jal         0x80802F30
    // 0x80801C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802F30_chklungo(rdram, ctx);
        goto after_24;
    // 0x80801C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80801CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CA4: jal         0x808020F0
    // 0x80801CA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808020F0_chklungo(rdram, ctx);
        goto after_25;
    // 0x80801CA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80801CAC: b           L_808020C0
    // 0x80801CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801CB4:
    // 0x80801CB4: lh          $t9, 0x8($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X8);
    // 0x80801CB8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X3910) << 16);
    // 0x80801CBC: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801CC0: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80801CC4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80801CC8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80801CCC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80801CD0: lwc1        $f4, 0x3910($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1240, 0X3910));
    // 0x80801CD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801CD8: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x80801CDC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80801CE0: b           L_808020BC
    // 0x80801CE4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
        goto L_808020BC;
    // 0x80801CE4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
L_80801CE8:
    // 0x80801CE8: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x80801CEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801CF0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801CF4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80801CF8: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x80801CFC: lh          $t4, 0x4($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X4);
    // 0x80801D00: bne         $t4, $at, L_80801D0C
    if (ctx->r12 != ctx->r1) {
        // 0x80801D04: nop
    
            goto L_80801D0C;
    }
    // 0x80801D04: nop

    // 0x80801D08: sb          $t5, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r13;
L_80801D0C:
    // 0x80801D0C: jal         0x80802FCC
    // 0x80801D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802FCC_chklungo(rdram, ctx);
        goto after_26;
    // 0x80801D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80801D14: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3A2C) << 16);
    // 0x80801D18: addiu       $a2, $a2, 0x3A2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3A2C));
    // 0x80801D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D20: jal         0x80089D18
    // 0x80801D24: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_27;
    // 0x80801D24: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_27:
    // 0x80801D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D2C: jal         0x808020F0
    // 0x80801D30: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808020F0_chklungo(rdram, ctx);
        goto after_28;
    // 0x80801D30: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_28:
    // 0x80801D34: b           L_808020C0
    // 0x80801D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801D3C:
    // 0x80801D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D40: jal         0x80109FE8
    // 0x80801D44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_29;
    // 0x80801D44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80801D48: b           L_808020C0
    // 0x80801D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801D50:
    // 0x80801D50: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x80801D54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801D58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801D5C: beq         $v0, $zero, L_80801D80
    if (ctx->r2 == 0) {
        // 0x80801D60: nop
    
            goto L_80801D80;
    }
    // 0x80801D60: nop

    // 0x80801D64: beq         $v0, $at, L_80801D88
    if (ctx->r2 == ctx->r1) {
        // 0x80801D68: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80801D88;
    }
    // 0x80801D68: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80801D6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801D70: beq         $v0, $at, L_80801D90
    if (ctx->r2 == ctx->r1) {
        // 0x80801D74: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_80801D90;
    }
    // 0x80801D74: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80801D78: b           L_80801D98
    // 0x80801D7C: lh          $t9, 0x1C($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X1C);
        goto L_80801D98;
    // 0x80801D7C: lh          $t9, 0x1C($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X1C);
L_80801D80:
    // 0x80801D80: b           L_80801D94
    // 0x80801D84: sh          $t6, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r14;
        goto L_80801D94;
    // 0x80801D84: sh          $t6, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r14;
L_80801D88:
    // 0x80801D88: b           L_80801D94
    // 0x80801D8C: sh          $t7, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r15;
        goto L_80801D94;
    // 0x80801D8C: sh          $t7, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r15;
L_80801D90:
    // 0x80801D90: sh          $t8, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r24;
L_80801D94:
    // 0x80801D94: lh          $t9, 0x1C($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X1C);
L_80801D98:
    // 0x80801D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D9C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801DA0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80801DA4: jal         0x80108B04
    // 0x80801DA8: sh          $t0, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r8;
    func_80108B04(rdram, ctx);
        goto after_30;
    // 0x80801DA8: sh          $t0, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r8;
    after_30:
    // 0x80801DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801DB0: jal         0x8010A800
    // 0x80801DB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_31;
    // 0x80801DB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_31:
    // 0x80801DB8: b           L_808020C0
    // 0x80801DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801DC0:
    // 0x80801DC0: lh          $t1, 0x8($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X8);
    // 0x80801DC4: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1240, 0X38A0) << 16);
    // 0x80801DC8: addiu       $t3, $t3, 0x38A0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1240, 0X38A0));
    // 0x80801DCC: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x80801DD0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80801DD4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80801DD8: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80801DDC: lwc1        $f12, 0x60($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80801DE0: lwc1        $f14, 0x64($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X64);
    // 0x80801DE4: jal         0x800DC178
    // 0x80801DE8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_800DC178(rdram, ctx);
        goto after_32;
    // 0x80801DE8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_32:
    // 0x80801DEC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80801DF0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801DF4: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80801DF8: b           L_808020BC
    // 0x80801DFC: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
        goto L_808020BC;
    // 0x80801DFC: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_80801E00:
    // 0x80801E00: lh          $t5, 0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X4);
    // 0x80801E04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801E08: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801E0C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80801E10: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x80801E14: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80801E18: bne         $t7, $at, L_80801E24
    if (ctx->r15 != ctx->r1) {
        // 0x80801E1C: nop
    
            goto L_80801E24;
    }
    // 0x80801E1C: nop

    // 0x80801E20: sb          $t8, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r24;
L_80801E24:
    // 0x80801E24: jal         0x80802FCC
    // 0x80801E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802FCC_chklungo(rdram, ctx);
        goto after_33;
    // 0x80801E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80801E2C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3A2C) << 16);
    // 0x80801E30: addiu       $a2, $a2, 0x3A2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3A2C));
    // 0x80801E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E38: jal         0x80089D18
    // 0x80801E3C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_34;
    // 0x80801E3C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_34:
    // 0x80801E40: b           L_808020C0
    // 0x80801E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801E48:
    // 0x80801E48: jal         0x8010A570
    // 0x80801E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_35;
    // 0x80801E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80801E50: jal         0x80089CA8
    // 0x80801E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_36;
    // 0x80801E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80801E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E5C: jal         0x8010A800
    // 0x80801E60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_37;
    // 0x80801E60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_37:
    // 0x80801E64: b           L_808020C0
    // 0x80801E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801E6C:
    // 0x80801E6C: lh          $t9, 0x22($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X22);
    // 0x80801E70: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80801E74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801E78: bne         $t9, $zero, L_80801EC4
    if (ctx->r25 != 0) {
        // 0x80801E7C: addiu       $a0, $zero, 0x685
        ctx->r4 = ADD32(0, 0X685);
            goto L_80801EC4;
    }
    // 0x80801E7C: addiu       $a0, $zero, 0x685
    ctx->r4 = ADD32(0, 0X685);
    // 0x80801E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E84: jal         0x80801964
    // 0x80801E88: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80801964_chklungo(rdram, ctx);
        goto after_38;
    // 0x80801E88: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_38:
    // 0x80801E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E90: jal         0x808025CC
    // 0x80801E94: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808025CC_chklungo(rdram, ctx);
        goto after_39;
    // 0x80801E94: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_39:
    // 0x80801E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E9C: addiu       $a1, $zero, 0x162F
    ctx->r5 = ADD32(0, 0X162F);
    // 0x80801EA0: jal         0x80803158
    // 0x80801EA4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_80803158_chklungo(rdram, ctx);
        goto after_40;
    // 0x80801EA4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_40:
    // 0x80801EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EAC: jal         0x80108B04
    // 0x80801EB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_41;
    // 0x80801EB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_41:
    // 0x80801EB4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80801EB8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801EBC: b           L_808020BC
    // 0x80801EC0: sh          $t0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r8;
        goto L_808020BC;
    // 0x80801EC0: sh          $t0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r8;
L_80801EC4:
    // 0x80801EC4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80801EC8: jal         0x800DA298
    // 0x80801ECC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_800DA298(rdram, ctx);
        goto after_42;
    // 0x80801ECC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_42:
    // 0x80801ED0: bne         $v0, $zero, L_80801F38
    if (ctx->r2 != 0) {
        // 0x80801ED4: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_80801F38;
    }
    // 0x80801ED4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80801ED8: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x80801EDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801EE0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80801EE4: beql        $v0, $zero, L_80801F0C
    if (ctx->r2 == 0) {
        // 0x80801EE8: sh          $t2, 0x2($v1)
        MEM_H(0X2, ctx->r3) = ctx->r10;
            goto L_80801F0C;
    }
    goto skip_3;
    // 0x80801EE8: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
    skip_3:
    // 0x80801EEC: beq         $v0, $at, L_80801F18
    if (ctx->r2 == ctx->r1) {
        // 0x80801EF0: addiu       $t4, $zero, 0x5
        ctx->r12 = ADD32(0, 0X5);
            goto L_80801F18;
    }
    // 0x80801EF0: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80801EF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801EF8: beq         $v0, $at, L_80801F28
    if (ctx->r2 == ctx->r1) {
        // 0x80801EFC: addiu       $t6, $zero, 0x7
        ctx->r14 = ADD32(0, 0X7);
            goto L_80801F28;
    }
    // 0x80801EFC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80801F00: b           L_80801F4C
    // 0x80801F04: lh          $t0, 0x44($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X44);
        goto L_80801F4C;
    // 0x80801F04: lh          $t0, 0x44($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X44);
    // 0x80801F08: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
L_80801F0C:
    // 0x80801F0C: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80801F10: b           L_80801F48
    // 0x80801F14: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
        goto L_80801F48;
    // 0x80801F14: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
L_80801F18:
    // 0x80801F18: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
    // 0x80801F1C: lh          $t5, 0x2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2);
    // 0x80801F20: b           L_80801F48
    // 0x80801F24: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
        goto L_80801F48;
    // 0x80801F24: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
L_80801F28:
    // 0x80801F28: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
    // 0x80801F2C: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x80801F30: b           L_80801F48
    // 0x80801F34: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
        goto L_80801F48;
    // 0x80801F34: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
L_80801F38:
    // 0x80801F38: addiu       $t8, $zero, 0x2710
    ctx->r24 = ADD32(0, 0X2710);
    // 0x80801F3C: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x80801F40: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x80801F44: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
L_80801F48:
    // 0x80801F48: lh          $t0, 0x44($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X44);
L_80801F4C:
    // 0x80801F4C: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x80801F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F54: bnel        $t0, $zero, L_808020C0
    if (ctx->r8 != 0) {
        // 0x80801F58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808020C0;
    }
    goto skip_4;
    // 0x80801F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80801F5C: jal         0x80108B04
    // 0x80801F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_43;
    // 0x80801F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_43:
    // 0x80801F64: b           L_808020C0
    // 0x80801F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801F6C:
    // 0x80801F6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801F70: jal         0x800FDC28
    // 0x80801F74: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_800FDC28(rdram, ctx);
        goto after_44;
    // 0x80801F74: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_44:
    // 0x80801F78: jal         0x80802FCC
    // 0x80801F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802FCC_chklungo(rdram, ctx);
        goto after_45;
    // 0x80801F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80801F80: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3BD0) << 16);
    // 0x80801F84: addiu       $a2, $a2, 0x3BD0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3BD0));
    // 0x80801F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F8C: jal         0x80089D18
    // 0x80801F90: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_46;
    // 0x80801F90: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_46:
    // 0x80801F94: jal         0x808018D4
    // 0x80801F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018D4_chklungo(rdram, ctx);
        goto after_47;
    // 0x80801F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80801F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FA0: jal         0x808025CC
    // 0x80801FA4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808025CC_chklungo(rdram, ctx);
        goto after_48;
    // 0x80801FA4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_48:
    // 0x80801FA8: jal         0x8010A570
    // 0x80801FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_49;
    // 0x80801FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80801FB0: addiu       $a0, $zero, 0x423
    ctx->r4 = ADD32(0, 0X423);
    // 0x80801FB4: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x80801FB8: jal         0x80101180
    // 0x80801FBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_50;
    // 0x80801FBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_50:
    // 0x80801FC0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80801FC4: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x80801FC8: jal         0x800DA544
    // 0x80801FCC: addiu       $a0, $a0, 0x318
    ctx->r4 = ADD32(ctx->r4, 0X318);
    func_800DA544(rdram, ctx);
        goto after_51;
    // 0x80801FCC: addiu       $a0, $a0, 0x318
    ctx->r4 = ADD32(ctx->r4, 0X318);
    after_51:
    // 0x80801FD0: b           L_808020C0
    // 0x80801FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80801FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801FD8:
    // 0x80801FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FDC: jal         0x808025CC
    // 0x80801FE0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808025CC_chklungo(rdram, ctx);
        goto after_52;
    // 0x80801FE0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_52:
    // 0x80801FE4: addiu       $a0, $zero, 0x41F
    ctx->r4 = ADD32(0, 0X41F);
    // 0x80801FE8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801FEC: jal         0x80101180
    // 0x80801FF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_53;
    // 0x80801FF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_53:
    // 0x80801FF4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    // 0x80801FF8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801FFC: jal         0x80101180
    // 0x80802000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_54;
    // 0x80802000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_54:
    // 0x80802004: b           L_808020C0
    // 0x80802008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x80802008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080200C:
    // 0x8080200C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802010: jal         0x808025CC
    // 0x80802014: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808025CC_chklungo(rdram, ctx);
        goto after_55;
    // 0x80802014: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_55:
    // 0x80802018: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X3870) << 16);
    // 0x8080201C: lwc1        $f8, 0x3870($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1240, 0X3870));
    // 0x80802020: b           L_808020BC
    // 0x80802024: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_808020BC;
    // 0x80802024: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80802028:
    // 0x80802028: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080202C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802030: b           L_808020BC
    // 0x80802034: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_808020BC;
    // 0x80802034: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80802038:
    // 0x80802038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080203C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802040: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80802044: jal         0x80802588
    // 0x80802048: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80802588_chklungo(rdram, ctx);
        goto after_56;
    // 0x80802048: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_56:
    // 0x8080204C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80802050: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1240, 0X3918) << 16);
    // 0x80802054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802058: lh          $t1, 0x8($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X8);
    // 0x8080205C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80802060: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x80802064: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80802068: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8080206C: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x80802070: jal         0x80803158
    // 0x80802074: lh          $a1, 0x3918($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1240, 0X3918));
    func_80803158_chklungo(rdram, ctx);
        goto after_57;
    // 0x80802074: lh          $a1, 0x3918($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1240, 0X3918));
    after_57:
    // 0x80802078: b           L_808020C0
    // 0x8080207C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808020C0;
    // 0x8080207C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802080:
    // 0x80802080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802084: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80802088: jal         0x808025CC
    // 0x8080208C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_808025CC_chklungo(rdram, ctx);
        goto after_58;
    // 0x8080208C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_58:
    // 0x80802090: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80802094: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1240, 0X391A) << 16);
    // 0x80802098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080209C: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x808020A0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x808020A4: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x808020A8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x808020AC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x808020B0: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x808020B4: jal         0x80803158
    // 0x808020B8: lh          $a1, 0x391A($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1240, 0X391A));
    func_80803158_chklungo(rdram, ctx);
        goto after_59;
    // 0x808020B8: lh          $a1, 0x391A($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1240, 0X391A));
    after_59:
L_808020BC:
    // 0x808020BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808020C0:
    // 0x808020C0: jal         0x80109FE8
    // 0x808020C4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_80109FE8(rdram, ctx);
        goto after_60;
    // 0x808020C4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_60:
    // 0x808020C8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x808020CC: beql        $t5, $zero, L_808020E0
    if (ctx->r13 == 0) {
        // 0x808020D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808020E0;
    }
    goto skip_5;
    // 0x808020D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x808020D4: jal         0x80803000
    // 0x808020D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803000_chklungo(rdram, ctx);
        goto after_61;
    // 0x808020D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x808020DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808020E0:
    // 0x808020E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808020E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808020E8: jr          $ra
    // 0x808020EC: nop

    return;
    // 0x808020EC: nop

;}
RECOMP_FUNC void func_8080132C_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080132C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801330: beq         $a0, $at, L_80801350
    if (ctx->r4 == ctx->r1) {
        // 0x80801334: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801350;
    }
    // 0x80801334: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801338: beq         $a0, $at, L_80801358
    if (ctx->r4 == ctx->r1) {
        // 0x8080133C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801358;
    }
    // 0x8080133C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801340: beq         $a0, $at, L_80801360
    if (ctx->r4 == ctx->r1) {
        // 0x80801344: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80801360;
    }
    // 0x80801344: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80801348: b           L_80801368
    // 0x8080134C: nop

        goto L_80801368;
    // 0x8080134C: nop

L_80801350:
    // 0x80801350: jr          $ra
    // 0x80801354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80801354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801358:
    // 0x80801358: jr          $ra
    // 0x8080135C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x8080135C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80801360:
    // 0x80801360: jr          $ra
    // 0x80801364: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80801364: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801368:
    // 0x80801368: jr          $ra
    // 0x8080136C: nop

    return;
    // 0x8080136C: nop

;}
RECOMP_FUNC void chdoormake_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800348: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080034C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800350: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800354: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800358: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8080035C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80800360: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800364: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80800368: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8080036C: jal         0x80800000
    // 0x80800370: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800000_chdoormake(rdram, ctx);
        goto after_0;
    // 0x80800370: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800374: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800378: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080037C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800380: jal         0x800EE940
    // 0x80800384: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    func_800EE940(rdram, ctx);
        goto after_1;
    // 0x80800384: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    after_1:
    // 0x80800388: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8080038C: jal         0x800EE7F8
    // 0x80800390: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800390: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800394: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800398: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8080039C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x808003A0: jal         0x800EF214
    // 0x808003A4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    func_800EF214(rdram, ctx);
        goto after_3;
    // 0x808003A4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x808003A8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808003AC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808003B0: jal         0x800EE940
    // 0x808003B4: addiu       $a0, $a0, 0x16
    ctx->r4 = ADD32(ctx->r4, 0X16);
    func_800EE940(rdram, ctx);
        goto after_4;
    // 0x808003B4: addiu       $a0, $a0, 0x16
    ctx->r4 = ADD32(ctx->r4, 0X16);
    after_4:
    // 0x808003B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003BC: jal         0x800EEAD4
    // 0x808003C0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EEAD4(rdram, ctx);
        goto after_5;
    // 0x808003C0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x808003C4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x808003C8: jal         0x80103EAC
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_6;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1544, 0X990) << 16);
    // 0x808003D4: lwc1        $f6, 0x990($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1544, 0X990));
    // 0x808003D8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808003DC: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x808003E0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808003E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003E8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x808003EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003F0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808003FC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800400: nop

    // 0x80800404: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80800408: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080040C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80800410: jal         0x808008C4
    // 0x80800414: sh          $t7, 0x1C($t8)
    MEM_H(0X1C, ctx->r24) = ctx->r15;
    func_808008C4_chdoormake(rdram, ctx);
        goto after_7;
    // 0x80800414: sh          $t7, 0x1C($t8)
    MEM_H(0X1C, ctx->r24) = ctx->r15;
    after_7:
    // 0x80800418: bne         $v0, $zero, L_80800430
    if (ctx->r2 != 0) {
        // 0x8080041C: lw          $t1, 0x48($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X48);
            goto L_80800430;
    }
    // 0x8080041C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80800420: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80800424: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800428: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x8080042C: bne         $t0, $at, L_8080049C
    if (ctx->r8 != ctx->r1) {
        // 0x80800430: andi        $t2, $t1, 0x1
        ctx->r10 = ctx->r9 & 0X1;
            goto L_8080049C;
    }
L_80800430:
    // 0x80800430: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80800434: beq         $t2, $zero, L_8080044C
    if (ctx->r10 == 0) {
        // 0x80800438: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080044C;
    }
    // 0x80800438: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080043C: jal         0x800FFAB0
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800444: b           L_808004A8
    // 0x80800448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004A8;
    // 0x80800448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080044C:
    // 0x8080044C: jal         0x800EE7F8
    // 0x80800450: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80800450: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_9:
    // 0x80800454: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80800458: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8080045C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800460: lh          $t4, 0x1C($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X1C);
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800468: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080046C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80800470: nop

    // 0x80800474: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800478: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080047C: jal         0x80101FDC
    // 0x80800480: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x80800480: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    after_10:
    // 0x80800484: jal         0x80103014
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_11;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080048C: jal         0x808000B8
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B8_chdoormake(rdram, ctx);
        goto after_12;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800494: b           L_808004A8
    // 0x80800498: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808004A8;
    // 0x80800498: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8080049C:
    // 0x8080049C: jal         0x808000B8
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B8_chdoormake(rdram, ctx);
        goto after_13;
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808004A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004A8:
    // 0x808004A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808004B4: jr          $ra
    // 0x808004B8: nop

    return;
    // 0x808004B8: nop

;}
RECOMP_FUNC void func_8080264C_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080264C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802654: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802658: jal         0x80802760
    // 0x8080265C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80802760_sucoaster(rdram, ctx);
        goto after_0;
    // 0x8080265C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80802660: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80802664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802668: bne         $v0, $at, L_80802678
    if (ctx->r2 != ctx->r1) {
        // 0x8080266C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80802678;
    }
    // 0x8080266C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802670: b           L_80802680
    // 0x80802674: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
        goto L_80802680;
    // 0x80802674: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
L_80802678:
    // 0x80802678: jal         0x8010CD50
    // 0x8080267C: nop

    func_8010CD50(rdram, ctx);
        goto after_1;
    // 0x8080267C: nop

    after_1:
L_80802680:
    // 0x80802680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802688: jr          $ra
    // 0x8080268C: nop

    return;
    // 0x8080268C: nop

;}
RECOMP_FUNC void _chnicecavemen_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086100: syscall     279
    recomp_syscall_handler(rdram, ctx, 0x80086100);
    return;
    // 0x80086104: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _dbvtxnormal_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879F0: syscall     648
    recomp_syscall_handler(rdram, ctx, 0x800879F0);
    return;
    // 0x800879F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void ncbawaypoint_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8080009C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x808000A4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x808000A8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x808000AC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x808000B0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x808000B4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x808000B8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x808000BC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808000C0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808000C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808000C8: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x808000CC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808000D0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808000D4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x808000D8: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x808000DC: mov.s       $f24, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    ctx->f24.fl = ctx->f22.fl;
    // 0x808000E0: beq         $v1, $zero, L_8080028C
    if (ctx->r3 == 0) {
        // 0x808000E4: sll         $t6, $v1, 5
        ctx->r14 = S32(ctx->r3 << 5);
            goto L_8080028C;
    }
    // 0x808000E4: sll         $t6, $v1, 5
    ctx->r14 = S32(ctx->r3 << 5);
    // 0x808000E8: addu        $s6, $v0, $t6
    ctx->r22 = ADD32(ctx->r2, ctx->r14);
    // 0x808000EC: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x808000F0: addiu       $s1, $v0, 0x4
    ctx->r17 = ADD32(ctx->r2, 0X4);
    // 0x808000F4: sltu        $at, $s1, $s6
    ctx->r1 = ctx->r17 < ctx->r22 ? 1 : 0;
    // 0x808000F8: beq         $at, $zero, L_80800124
    if (ctx->r1 == 0) {
        // 0x808000FC: sw          $a2, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r6;
            goto L_80800124;
    }
    // 0x808000FC: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80800100: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
L_80800104:
    // 0x80800104: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800108: jal         0x800EEAD4
    // 0x8080010C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_0;
    // 0x8080010C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_0:
    // 0x80800110: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80800114: sltu        $at, $s1, $s6
    ctx->r1 = ctx->r17 < ctx->r22 ? 1 : 0;
    // 0x80800118: bne         $at, $zero, L_80800104
    if (ctx->r1 != 0) {
        // 0x8080011C: swc1        $f0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f0.u32l;
            goto L_80800104;
    }
    // 0x8080011C: swc1        $f0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f0.u32l;
    // 0x80800120: lw          $v0, 0x5C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X5C);
L_80800124:
    // 0x80800124: addiu       $s1, $v0, 0x24
    ctx->r17 = ADD32(ctx->r2, 0X24);
    // 0x80800128: sltu        $at, $s1, $s6
    ctx->r1 = ctx->r17 < ctx->r22 ? 1 : 0;
    // 0x8080012C: beq         $at, $zero, L_808001E4
    if (ctx->r1 == 0) {
        // 0x80800130: lw          $a3, 0xA0($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XA0);
            goto L_808001E4;
    }
    // 0x80800130: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x80800134: sw          $a3, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r7;
    // 0x80800138: addiu       $s4, $sp, 0x6C
    ctx->r20 = ADD32(ctx->r29, 0X6C);
    // 0x8080013C: addiu       $s2, $s1, -0x20
    ctx->r18 = ADD32(ctx->r17, -0X20);
L_80800140:
    // 0x80800140: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80800144: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800148: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080014C: jal         0x8001BBC8
    // 0x80800150: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    aligned4_memcpy(rdram, ctx);
        goto after_1;
    // 0x80800150: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_1:
    // 0x80800154: lw          $t7, 0x5C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X5C);
    // 0x80800158: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8080015C: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80800160: sltu        $at, $s2, $t8
    ctx->r1 = ctx->r18 < ctx->r24 ? 1 : 0;
    // 0x80800164: bnel        $at, $zero, L_808001C0
    if (ctx->r1 != 0) {
        // 0x80800168: addiu       $a0, $s0, 0x20
        ctx->r4 = ADD32(ctx->r16, 0X20);
            goto L_808001C0;
    }
    goto skip_0;
    // 0x80800168: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    skip_0:
    // 0x8080016C: lwc1        $f6, 0x1C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x80800170: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800174: nop

    // 0x80800178: bc1f        L_808001BC
    if (!c1cs) {
        // 0x8080017C: addiu       $a0, $s0, 0x20
        ctx->r4 = ADD32(ctx->r16, 0X20);
            goto L_808001BC;
    }
    // 0x8080017C: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
L_80800180:
    // 0x80800180: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800184: jal         0x8001BBC8
    // 0x80800188: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    aligned4_memcpy(rdram, ctx);
        goto after_2;
    // 0x80800188: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_2:
    // 0x8080018C: lw          $t9, 0x5C($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X5C);
    // 0x80800190: addiu       $s0, $s0, -0x20
    ctx->r16 = ADD32(ctx->r16, -0X20);
    // 0x80800194: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80800198: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x8080019C: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x808001A0: bnel        $at, $zero, L_808001C0
    if (ctx->r1 != 0) {
        // 0x808001A4: addiu       $a0, $s0, 0x20
        ctx->r4 = ADD32(ctx->r16, 0X20);
            goto L_808001C0;
    }
    goto skip_1;
    // 0x808001A4: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    skip_1:
    // 0x808001A8: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808001AC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808001B0: nop

    // 0x808001B4: bc1tl       L_80800180
    if (c1cs) {
        // 0x808001B8: addiu       $a0, $s0, 0x20
        ctx->r4 = ADD32(ctx->r16, 0X20);
            goto L_80800180;
    }
    goto skip_2;
    // 0x808001B8: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    skip_2:
L_808001BC:
    // 0x808001BC: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
L_808001C0:
    // 0x808001C0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808001C4: jal         0x8001BBC8
    // 0x808001C8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    aligned4_memcpy(rdram, ctx);
        goto after_3;
    // 0x808001C8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_3:
    // 0x808001CC: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x808001D0: sltu        $at, $s1, $s6
    ctx->r1 = ctx->r17 < ctx->r22 ? 1 : 0;
    // 0x808001D4: bnel        $at, $zero, L_80800140
    if (ctx->r1 != 0) {
        // 0x808001D8: addiu       $s2, $s1, -0x20
        ctx->r18 = ADD32(ctx->r17, -0X20);
            goto L_80800140;
    }
    goto skip_3;
    // 0x808001D8: addiu       $s2, $s1, -0x20
    ctx->r18 = ADD32(ctx->r17, -0X20);
    skip_3:
    // 0x808001DC: lw          $v0, 0x5C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X5C);
    // 0x808001E0: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
L_808001E4:
    // 0x808001E4: addiu       $s1, $v0, 0x4
    ctx->r17 = ADD32(ctx->r2, 0X4);
    // 0x808001E8: sltu        $at, $s1, $s6
    ctx->r1 = ctx->r17 < ctx->r22 ? 1 : 0;
    // 0x808001EC: beql        $at, $zero, L_80800290
    if (ctx->r1 == 0) {
        // 0x808001F0: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80800290;
    }
    goto skip_4;
    // 0x808001F0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_4:
    // 0x808001F4: sw          $a3, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r7;
    // 0x808001F8: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
L_808001FC:
    // 0x808001FC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80800200: jal         0x800EEAA4
    // 0x80800204: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_4;
    // 0x80800204: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800208: lwc1        $f16, 0x18($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8080020C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800210: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800214: jal         0x800EEAA4
    // 0x80800218: sub.s       $f20, $f0, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f16.fl;
    func_800EEAA4(rdram, ctx);
        goto after_5;
    // 0x80800218: sub.s       $f20, $f0, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f16.fl;
    after_5:
    // 0x8080021C: lwc1        $f18, 0x18($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80800220: sub.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80800224: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x80800228: nop

    // 0x8080022C: bc1fl       L_80800248
    if (!c1cs) {
        // 0x80800230: c.le.s      $f22, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl <= ctx->f2.fl;
            goto L_80800248;
    }
    goto skip_5;
    // 0x80800230: c.le.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl <= ctx->f2.fl;
    skip_5:
    // 0x80800234: c.le.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl <= ctx->f22.fl;
    // 0x80800238: nop

    // 0x8080023C: bc1tl       L_80800280
    if (c1cs) {
        // 0x80800240: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_80800280;
    }
    goto skip_6;
    // 0x80800240: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_6:
    // 0x80800244: c.le.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl <= ctx->f2.fl;
L_80800248:
    // 0x80800248: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080024C: bc1f        L_80800264
    if (!c1cs) {
        // 0x80800250: nop
    
            goto L_80800264;
    }
    // 0x80800250: nop

    // 0x80800254: c.le.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl <= ctx->f20.fl;
    // 0x80800258: nop

    // 0x8080025C: bc1tl       L_80800280
    if (c1cs) {
        // 0x80800260: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_80800280;
    }
    goto skip_7;
    // 0x80800260: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_7:
L_80800264:
    // 0x80800264: jal         0x800EEAD4
    // 0x80800268: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_6;
    // 0x80800268: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8080026C: add.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f0.fl;
    // 0x80800270: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800274: jal         0x800EE7F8
    // 0x80800278: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800278: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x8080027C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
L_80800280:
    // 0x80800280: sltu        $at, $s1, $s6
    ctx->r1 = ctx->r17 < ctx->r22 ? 1 : 0;
    // 0x80800284: bnel        $at, $zero, L_808001FC
    if (ctx->r1 != 0) {
        // 0x80800288: addiu       $s0, $s1, 0xC
        ctx->r16 = ADD32(ctx->r17, 0XC);
            goto L_808001FC;
    }
    goto skip_8;
    // 0x80800288: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    skip_8:
L_8080028C:
    // 0x8080028C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80800290:
    // 0x80800290: mov.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.fl = ctx->f24.fl;
    // 0x80800294: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800298: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080029C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808002A0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808002A4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x808002A8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x808002AC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x808002B0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x808002B4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x808002B8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x808002BC: jr          $ra
    // 0x808002C0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x808002C0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x808002C4: nop

    // 0x808002C8: nop

    // 0x808002CC: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001F0: jal         0x80800120
    // 0x808001F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800120_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x808001F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001F8: bne         $v0, $zero, L_80800208
    if (ctx->r2 != 0) {
        // 0x808001FC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800208;
    }
    // 0x808001FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800200: b           L_80800214
    // 0x80800204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800214;
    // 0x80800204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800208:
    // 0x80800208: jal         0x800EE7F8
    // 0x8080020C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080020C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800214:
    // 0x80800214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080021C: jr          $ra
    // 0x80800220: nop

    return;
    // 0x80800220: nop

;}
RECOMP_FUNC void gspropctrl_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8080007C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2870, 0X140) << 16);
    // 0x80800080: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800084: jr          $ra
    // 0x80800088: lh          $v0, 0x140($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2870, 0X140));
    return;
    // 0x80800088: lh          $v0, 0x140($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2870, 0X140));
;}
RECOMP_FUNC void func_80800044_chlavacolumns(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800048: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080004C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800054: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800058: bne         $a1, $at, L_80800134
    if (ctx->r5 != ctx->r1) {
        // 0x8080005C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800134;
    }
    // 0x8080005C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800060: jal         0x80088840
    // 0x80800064: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80800064: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_0:
    // 0x80800068: beq         $v0, $zero, L_808000D8
    if (ctx->r2 == 0) {
        // 0x8080006C: lui         $at, 0xC3C8
        ctx->r1 = S32(0XC3C8 << 16);
            goto L_808000D8;
    }
    // 0x8080006C: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x80800070: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800074: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800080: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800088: jal         0x80103110
    // 0x8080008C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x8080008C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: jal         0x80102FE8
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80102FE8(rdram, ctx);
        goto after_2;
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080009C: jal         0x8008A490
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x80101FDC
    // 0x808000AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808000AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80800200
    // 0x808000B8: lui         $a1, 0xC3C8
    ctx->r5 = S32(0XC3C8 << 16);
    func_80800200_chlavacolumns(rdram, ctx);
        goto after_5;
    // 0x808000B8: lui         $a1, 0xC3C8
    ctx->r5 = S32(0XC3C8 << 16);
    after_5:
    // 0x808000BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C4: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x808000C8: jal         0x80085708
    // 0x808000CC: addiu       $a3, $zero, 0x910
    ctx->r7 = ADD32(0, 0X910);
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x808000CC: addiu       $a3, $zero, 0x910
    ctx->r7 = ADD32(0, 0X910);
    after_6:
    // 0x808000D0: b           L_80800124
    // 0x808000D4: nop

        goto L_80800124;
    // 0x808000D4: nop

L_808000D8:
    // 0x808000D8: jal         0x800DA298
    // 0x808000DC: addiu       $a0, $zero, 0x390
    ctx->r4 = ADD32(0, 0X390);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808000DC: addiu       $a0, $zero, 0x390
    ctx->r4 = ADD32(0, 0X390);
    after_7:
    // 0x808000E0: beq         $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x808000E4: lui         $at, 0xC3C8
        ctx->r1 = S32(0XC3C8 << 16);
            goto L_80800110;
    }
    // 0x808000E4: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x808000E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808000F4: jal         0x80101FDC
    // 0x808000F8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x808000F8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_8:
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: jal         0x80800200
    // 0x80800104: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80800200_chlavacolumns(rdram, ctx);
        goto after_9;
    // 0x80800104: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
    // 0x80800108: b           L_80800124
    // 0x8080010C: nop

        goto L_80800124;
    // 0x8080010C: nop

L_80800110:
    // 0x80800110: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800118: lui         $a1, 0xC3C8
    ctx->r5 = S32(0XC3C8 << 16);
    // 0x8080011C: jal         0x80800200
    // 0x80800120: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    func_80800200_chlavacolumns(rdram, ctx);
        goto after_10;
    // 0x80800120: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_10:
L_80800124:
    // 0x80800124: jal         0x80103014
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_11;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080012C: b           L_80800138
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800138;
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800134:
    // 0x80800134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800138:
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080013C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800140: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800144: jr          $ra
    // 0x80800148: nop

    return;
    // 0x80800148: nop

;}
RECOMP_FUNC void func_800BDBEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDBEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BDBF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BDBF4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800BDBF8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BDBFC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800BDC00: nop

    // 0x800BDC04: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800BDC08: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800BDC0C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BDC10: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BDC14: nop

    // 0x800BDC18: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800BDC1C: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800BDC20: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800BDC24: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800BDC28: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800BDC2C: jal         0x800BDBC4
    // 0x800BDC30: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    func_800BDBC4(rdram, ctx);
        goto after_0;
    // 0x800BDC30: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_0:
    // 0x800BDC34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDC38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BDC3C: jr          $ra
    // 0x800BDC40: nop

    return;
    // 0x800BDC40: nop

;}
RECOMP_FUNC void func_80800084_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080008C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800094: jal         0x80091A58
    // 0x80800098: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80800098: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8080009C: beq         $v0, $zero, L_808000A8
    if (ctx->r2 == 0) {
        // 0x808000A0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808000A8;
    }
    // 0x808000A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: addiu       $v1, $zero, 0x169
    ctx->r3 = ADD32(0, 0X169);
L_808000A8:
    // 0x808000A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000AC: jal         0x8008E148
    // 0x808000B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8008E148(rdram, ctx);
        goto after_1;
    // 0x808000B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x808000B4: beq         $v0, $zero, L_808000C0
    if (ctx->r2 == 0) {
        // 0x808000B8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808000C0;
    }
    // 0x808000B8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808000C0:
    // 0x808000C0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808000C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000C8: lbu         $t7, 0x15F($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X15F);
    // 0x808000CC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808000D0: bnel        $t7, $zero, L_808000F0
    if (ctx->r15 != 0) {
        // 0x808000D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000F0;
    }
    goto skip_0;
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000D8: jal         0x80091A30
    // 0x808000DC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    bakey_released(rdram, ctx);
        goto after_2;
    // 0x808000DC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x808000E0: beq         $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x808000E4: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808000EC;
    }
    // 0x808000E4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E8: addiu       $v1, $zero, 0x164
    ctx->r3 = ADD32(0, 0X164);
L_808000EC:
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F0:
    // 0x808000F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void func_80803BFC_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803BFC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80803C00: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80803C04: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80803C08: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80803C0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803C10: lhu         $t6, 0x64($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X64);
    // 0x80803C14: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80803C18: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80803C1C: beql        $t7, $zero, L_808040C0
    if (ctx->r15 == 0) {
        // 0x80803C20: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808040C0;
    }
    goto skip_0;
    // 0x80803C20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80803C24: lhu         $t8, 0x72($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X72);
    // 0x80803C28: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2484, 0X7528) << 16);
    // 0x80803C2C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80803C30: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80803C34: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80803C38: lhu         $t1, 0x7528($t1)
    ctx->r9 = MEM_HU(ctx->r9, (int16_t)RELOC_LO16(2484, 0X7528));
    // 0x80803C3C: addiu       $t2, $t1, -0x4C2
    ctx->r10 = ADD32(ctx->r9, -0X4C2);
    // 0x80803C40: sltiu       $at, $t2, 0x6
    ctx->r1 = ctx->r10 < 0X6 ? 1 : 0;
    // 0x80803C44: beq         $at, $zero, L_808040BC
    if (ctx->r1 == 0) {
        // 0x80803C48: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808040BC;
    }
    // 0x80803C48: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80803C4C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67C0) << 16);
    // 0x80803C50: addu        $at, $at, $t2
    gpr jr_addend_80803C58 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80803C54: lw          $t2, 0x67C0($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67C0));
    // 0x80803C58: jr          $t2
    // 0x80803C5C: nop

    switch (jr_addend_80803C58 >> 2) {
        case 0: goto L_808040BC; break;
        case 1: goto L_808040BC; break;
        case 2: goto L_80803C60; break;
        case 3: goto L_80803C80; break;
        case 4: goto L_808040BC; break;
        case 5: goto L_80803CE0; break;
        default: switch_error(__func__, 0x80803C58, 0x808067C0);
    }
    // 0x80803C5C: nop

L_80803C60:
    // 0x80803C60: jal         0x80101DDC
    // 0x80803C64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80101DDC(rdram, ctx);
        goto after_0;
    // 0x80803C64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80803C68: beq         $v0, $zero, L_808040BC
    if (ctx->r2 == 0) {
        // 0x80803C6C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808040BC;
    }
    // 0x80803C6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803C70: jal         0x80102424
    // 0x80803C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80803C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80803C78: b           L_808040C0
    // 0x80803C7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808040C0;
    // 0x80803C7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80803C80:
    // 0x80803C80: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2484, 0X7570) << 16);
    // 0x80803C84: addiu       $t3, $t3, 0x7570
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2484, 0X7570));
    // 0x80803C88: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80803C8C: addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
    // 0x80803C90: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2484, 0X75B0) << 16);
    // 0x80803C94: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x80803C98: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80803C9C: addiu       $a2, $a2, 0x75B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2484, 0X75B0));
    // 0x80803CA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803CA4: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80803CA8: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80803CAC: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x80803CB0: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    // 0x80803CB4: lw          $t5, 0xC($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC);
    // 0x80803CB8: jal         0x80089D28
    // 0x80803CBC: sw          $t5, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r13;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80803CBC: sw          $t5, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r13;
    after_2:
    // 0x80803CC0: jal         0x80101DDC
    // 0x80803CC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80101DDC(rdram, ctx);
        goto after_3;
    // 0x80803CC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80803CC8: beq         $v0, $zero, L_808040BC
    if (ctx->r2 == 0) {
        // 0x80803CCC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808040BC;
    }
    // 0x80803CCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803CD0: jal         0x80102424
    // 0x80803CD4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80803CD4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x80803CD8: b           L_808040C0
    // 0x80803CDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808040C0;
    // 0x80803CDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80803CE0:
    // 0x80803CE0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2484, 0X7580) << 16);
    // 0x80803CE4: addiu       $t7, $t7, 0x7580
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2484, 0X7580));
    // 0x80803CE8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80803CEC: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80803CF0: addiu       $t6, $sp, 0x78
    ctx->r14 = ADD32(ctx->r29, 0X78);
    // 0x80803CF4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80803CF8: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80803CFC: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x80803D00: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80803D04: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2484, 0X7598) << 16);
    // 0x80803D08: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x80803D0C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80803D10: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x80803D14: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x80803D18: addiu       $t1, $t1, 0x7598
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2484, 0X7598));
    // 0x80803D1C: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80803D20: sw          $t9, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r25;
    // 0x80803D24: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x80803D28: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80803D2C: addiu       $t0, $sp, 0x60
    ctx->r8 = ADD32(ctx->r29, 0X60);
    // 0x80803D30: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80803D34: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80803D38: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80803D3C: lw          $t4, 0xC($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XC);
    // 0x80803D40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803D44: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x80803D48: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x80803D4C: lw          $t4, 0x14($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X14);
    // 0x80803D50: lw          $at, 0x10($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X10);
    // 0x80803D54: sw          $t4, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r12;
    // 0x80803D58: jal         0x80101F24
    // 0x80803D5C: sw          $at, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r1;
    func_80101F24(rdram, ctx);
        goto after_5;
    // 0x80803D5C: sw          $at, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r1;
    after_5:
    // 0x80803D60: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80803D64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803D68: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x80803D6C: jal         0x8008A0D0
    // 0x80803D70: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80803D70: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_6:
    // 0x80803D74: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x80803D78: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2484, 0X7640) << 16);
    // 0x80803D7C: lui         $a3, 0x3EA8
    ctx->r7 = S32(0X3EA8 << 16);
    // 0x80803D80: ori         $a3, $a3, 0xF5C3
    ctx->r7 = ctx->r7 | 0XF5C3;
    // 0x80803D84: addiu       $a2, $a2, 0x7640
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2484, 0X7640));
    // 0x80803D88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803D8C: jal         0x80089D20
    // 0x80803D90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80803D90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80803D94: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2484, 0X765C) << 16);
    // 0x80803D98: lui         $a3, 0x3F61
    ctx->r7 = S32(0X3F61 << 16);
    // 0x80803D9C: ori         $a3, $a3, 0x47AE
    ctx->r7 = ctx->r7 | 0X47AE;
    // 0x80803DA0: addiu       $a2, $a2, 0x765C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2484, 0X765C));
    // 0x80803DA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803DA8: jal         0x80089D20
    // 0x80803DAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80803DAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80803DB0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2484, 0X7624) << 16);
    // 0x80803DB4: lui         $a3, 0x3DB8
    ctx->r7 = S32(0X3DB8 << 16);
    // 0x80803DB8: ori         $a3, $a3, 0x51EC
    ctx->r7 = ctx->r7 | 0X51EC;
    // 0x80803DBC: addiu       $a2, $a2, 0x7624
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2484, 0X7624));
    // 0x80803DC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803DC4: jal         0x80089D20
    // 0x80803DC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80803DC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80803DCC: lui         $a1, 0x3DB8
    ctx->r5 = S32(0X3DB8 << 16);
    // 0x80803DD0: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80803DD4: jal         0x80101E14
    // 0x80803DD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80101E14(rdram, ctx);
        goto after_10;
    // 0x80803DD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x80803DDC: beq         $v0, $zero, L_80803DF8
    if (ctx->r2 == 0) {
        // 0x80803DE0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803DF8;
    }
    // 0x80803DE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803DE4: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80803DE8: jal         0x800C3F48
    // 0x80803DEC: ori         $a0, $a0, 0xFE87
    ctx->r4 = ctx->r4 | 0XFE87;
    func_800C3F48(rdram, ctx);
        goto after_11;
    // 0x80803DEC: ori         $a0, $a0, 0xFE87
    ctx->r4 = ctx->r4 | 0XFE87;
    after_11:
    // 0x80803DF0: b           L_80803E3C
    // 0x80803DF4: nop

        goto L_80803E3C;
    // 0x80803DF4: nop

L_80803DF8:
    // 0x80803DF8: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80803DFC: jal         0x80101E14
    // 0x80803E00: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_12;
    // 0x80803E00: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_12:
    // 0x80803E04: beq         $v0, $zero, L_80803E20
    if (ctx->r2 == 0) {
        // 0x80803E08: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803E20;
    }
    // 0x80803E08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803E0C: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80803E10: jal         0x800C3F48
    // 0x80803E14: ori         $a0, $a0, 0xFE88
    ctx->r4 = ctx->r4 | 0XFE88;
    func_800C3F48(rdram, ctx);
        goto after_13;
    // 0x80803E14: ori         $a0, $a0, 0xFE88
    ctx->r4 = ctx->r4 | 0XFE88;
    after_13:
    // 0x80803E18: b           L_80803E3C
    // 0x80803E1C: nop

        goto L_80803E3C;
    // 0x80803E1C: nop

L_80803E20:
    // 0x80803E20: lui         $a1, 0x3EA8
    ctx->r5 = S32(0X3EA8 << 16);
    // 0x80803E24: jal         0x80101E14
    // 0x80803E28: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x80803E28: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    after_14:
    // 0x80803E2C: beq         $v0, $zero, L_80803E3C
    if (ctx->r2 == 0) {
        // 0x80803E30: lui         $a0, 0x7FFF
        ctx->r4 = S32(0X7FFF << 16);
            goto L_80803E3C;
    }
    // 0x80803E30: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80803E34: jal         0x800C3F48
    // 0x80803E38: ori         $a0, $a0, 0xFE89
    ctx->r4 = ctx->r4 | 0XFE89;
    func_800C3F48(rdram, ctx);
        goto after_15;
    // 0x80803E38: ori         $a0, $a0, 0xFE89
    ctx->r4 = ctx->r4 | 0XFE89;
    after_15:
L_80803E3C:
    // 0x80803E3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67D8) << 16);
    // 0x80803E40: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80803E44: lwc1        $f4, 0x67D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67D8));
    // 0x80803E48: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80803E4C: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80803E50: nop

    // 0x80803E54: bc1f        L_80803F84
    if (!c1cs) {
        // 0x80803E58: nop
    
            goto L_80803F84;
    }
    // 0x80803E58: nop

    // 0x80803E5C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803E60: jal         0x800F1214
    // 0x80803E64: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800F1214(rdram, ctx);
        goto after_16;
    // 0x80803E64: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_16:
    // 0x80803E68: jal         0x800DC298
    // 0x80803E6C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800DC298(rdram, ctx);
        goto after_17;
    // 0x80803E6C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_17:
    // 0x80803E70: beq         $v0, $zero, L_80803F84
    if (ctx->r2 == 0) {
        // 0x80803E74: lwc1        $f0, 0x50($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
            goto L_80803F84;
    }
    // 0x80803E74: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80803E78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67DC) << 16);
    // 0x80803E7C: lwc1        $f6, 0x67DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67DC));
    // 0x80803E80: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80803E84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67E0) << 16);
    // 0x80803E88: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80803E8C: nop

    // 0x80803E90: bc1f        L_80803EB0
    if (!c1cs) {
        // 0x80803E94: nop
    
            goto L_80803EB0;
    }
    // 0x80803E94: nop

    // 0x80803E98: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80803E9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80803EA0: jal         0x800DC298
    // 0x80803EA4: nop

    func_800DC298(rdram, ctx);
        goto after_18;
    // 0x80803EA4: nop

    after_18:
    // 0x80803EA8: b           L_80803EF0
    // 0x80803EAC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
        goto L_80803EF0;
    // 0x80803EAC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
L_80803EB0:
    // 0x80803EB0: lwc1        $f8, 0x67E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67E0));
    // 0x80803EB4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80803EB8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67E4) << 16);
    // 0x80803EBC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80803EC0: nop

    // 0x80803EC4: bc1f        L_80803ED4
    if (!c1cs) {
        // 0x80803EC8: nop
    
            goto L_80803ED4;
    }
    // 0x80803EC8: nop

    // 0x80803ECC: b           L_80803EF0
    // 0x80803ED0: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
        goto L_80803EF0;
    // 0x80803ED0: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
L_80803ED4:
    // 0x80803ED4: lwc1        $f10, 0x67E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67E4));
    // 0x80803ED8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80803EDC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80803EE0: nop

    // 0x80803EE4: bc1fl       L_80803EF4
    if (!c1cs) {
        // 0x80803EE8: lw          $t8, 0x48($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X48);
            goto L_80803EF4;
    }
    goto skip_1;
    // 0x80803EE8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    skip_1:
    // 0x80803EEC: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
L_80803EF0:
    // 0x80803EF0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
L_80803EF4:
    // 0x80803EF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80803EF8: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x80803EFC: blez        $t8, L_80803F84
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80803F00: nop
    
            goto L_80803F84;
    }
    // 0x80803F00: nop

L_80803F04:
    // 0x80803F04: jal         0x800DC0C0
    // 0x80803F08: nop

    func_800DC0C0(rdram, ctx);
        goto after_19;
    // 0x80803F08: nop

    after_19:
    // 0x80803F0C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80803F10: jal         0x80103EAC
    // 0x80803F14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80103EAC(rdram, ctx);
        goto after_20;
    // 0x80803F14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_20:
    // 0x80803F18: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80803F1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803F20: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80803F24: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67E8) << 16);
    // 0x80803F28: lwc1        $f6, 0x67E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67E8));
    // 0x80803F2C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80803F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803F34: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80803F38: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80803F3C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80803F40: jal         0x800EEB9C
    // 0x80803F44: nop

    func_800EEB9C(rdram, ctx);
        goto after_21;
    // 0x80803F44: nop

    after_21:
    // 0x80803F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803F4C: jal         0x800EF04C
    // 0x80803F50: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EF04C(rdram, ctx);
        goto after_22;
    // 0x80803F50: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_22:
    // 0x80803F54: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2484, 0X75C0) << 16);
    // 0x80803F58: addiu       $t6, $t6, 0x75C0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2484, 0X75C0));
    // 0x80803F5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80803F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803F64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803F68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80803F6C: jal         0x800BBCB8
    // 0x80803F70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_23;
    // 0x80803F70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_23:
    // 0x80803F74: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80803F78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80803F7C: bne         $s1, $t7, L_80803F04
    if (ctx->r17 != ctx->r15) {
        // 0x80803F80: nop
    
            goto L_80803F04;
    }
    // 0x80803F80: nop

L_80803F84:
    // 0x80803F84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67EC) << 16);
    // 0x80803F88: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80803F8C: lwc1        $f10, 0x67EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67EC));
    // 0x80803F90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67F0) << 16);
    // 0x80803F94: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80803F98: nop

    // 0x80803F9C: bc1f        L_80803FB4
    if (!c1cs) {
        // 0x80803FA0: nop
    
            goto L_80803FB4;
    }
    // 0x80803FA0: nop

    // 0x80803FA4: lwc1        $f16, 0x67F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67F0));
    // 0x80803FA8: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80803FAC: nop

    // 0x80803FB0: bc1t        L_80804038
    if (c1cs) {
        // 0x80803FB4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2484, 0X67F4) << 16);
            goto L_80804038;
    }
L_80803FB4:
    // 0x80803FB4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67F4) << 16);
    // 0x80803FB8: lwc1        $f18, 0x67F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67F4));
    // 0x80803FBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67F8) << 16);
    // 0x80803FC0: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80803FC4: nop

    // 0x80803FC8: bc1f        L_80803FE0
    if (!c1cs) {
        // 0x80803FCC: nop
    
            goto L_80803FE0;
    }
    // 0x80803FCC: nop

    // 0x80803FD0: lwc1        $f4, 0x67F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67F8));
    // 0x80803FD4: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80803FD8: nop

    // 0x80803FDC: bc1t        L_80804038
    if (c1cs) {
        // 0x80803FE0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2484, 0X67FC) << 16);
            goto L_80804038;
    }
L_80803FE0:
    // 0x80803FE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67FC) << 16);
    // 0x80803FE4: lwc1        $f6, 0x67FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67FC));
    // 0x80803FE8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6800) << 16);
    // 0x80803FEC: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80803FF0: nop

    // 0x80803FF4: bc1f        L_8080400C
    if (!c1cs) {
        // 0x80803FF8: nop
    
            goto L_8080400C;
    }
    // 0x80803FF8: nop

    // 0x80803FFC: lwc1        $f8, 0x6800($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6800));
    // 0x80804000: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80804004: nop

    // 0x80804008: bc1t        L_80804038
    if (c1cs) {
        // 0x8080400C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2484, 0X6804) << 16);
            goto L_80804038;
    }
L_8080400C:
    // 0x8080400C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6804) << 16);
    // 0x80804010: lwc1        $f10, 0x6804($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6804));
    // 0x80804014: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6808) << 16);
    // 0x80804018: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x8080401C: nop

    // 0x80804020: bc1fl       L_8080405C
    if (!c1cs) {
        // 0x80804024: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080405C;
    }
    goto skip_2;
    // 0x80804024: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
    // 0x80804028: lwc1        $f16, 0x6808($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6808));
    // 0x8080402C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80804030: nop

    // 0x80804034: bc1f        L_80804058
    if (!c1cs) {
        // 0x80804038: lui         $t2, 0x8080
        ctx->r10 = S32(RELOC_HI16(2484, 0X75EC) << 16);
            goto L_80804058;
    }
L_80804038:
    // 0x80804038: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2484, 0X75EC) << 16);
    // 0x8080403C: addiu       $t2, $t2, 0x75EC
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2484, 0X75EC));
    // 0x80804040: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80804044: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80804048: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080404C: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x80804050: jal         0x800BBCB8
    // 0x80804054: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_800BBCB8(rdram, ctx);
        goto after_24;
    // 0x80804054: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_24:
L_80804058:
    // 0x80804058: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080405C:
    // 0x8080405C: jal         0x80101E4C
    // 0x80804060: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    func_80101E4C(rdram, ctx);
        goto after_25;
    // 0x80804060: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_25:
    // 0x80804064: beq         $v0, $zero, L_80804074
    if (ctx->r2 == 0) {
        // 0x80804068: nop
    
            goto L_80804074;
    }
    // 0x80804068: nop

    // 0x8080406C: jal         0x80803B88
    // 0x80804070: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_80803B88_chquiz(rdram, ctx);
        goto after_26;
    // 0x80804070: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_26:
L_80804074:
    // 0x80804074: jal         0x80101DDC
    // 0x80804078: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80101DDC(rdram, ctx);
        goto after_27;
    // 0x80804078: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_27:
    // 0x8080407C: beql        $v0, $zero, L_808040C0
    if (ctx->r2 == 0) {
        // 0x80804080: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808040C0;
    }
    goto skip_3;
    // 0x80804080: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x80804084: jal         0x800D395C
    // 0x80804088: nop

    func_800D395C(rdram, ctx);
        goto after_28;
    // 0x80804088: nop

    after_28:
    // 0x8080408C: beq         $v0, $zero, L_808040A8
    if (ctx->r2 == 0) {
        // 0x80804090: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808040A8;
    }
    // 0x80804090: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804094: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804098: jal         0x80804170
    // 0x8080409C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80804170_chquiz(rdram, ctx);
        goto after_29;
    // 0x8080409C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_29:
    // 0x808040A0: b           L_808040B4
    // 0x808040A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_808040B4;
    // 0x808040A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808040A8:
    // 0x808040A8: jal         0x80804170
    // 0x808040AC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    func_80804170_chquiz(rdram, ctx);
        goto after_30;
    // 0x808040AC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_30:
    // 0x808040B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808040B4:
    // 0x808040B4: jal         0x80102424
    // 0x808040B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_31;
    // 0x808040B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
L_808040BC:
    // 0x808040BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808040C0:
    // 0x808040C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808040C4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808040C8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808040CC: jr          $ra
    // 0x808040D0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x808040D0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80800228_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080022C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800230: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800234: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800238: jal         0x80100094
    // 0x8080023C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080023C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800240: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800244: jal         0x80800BCC
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BCC_chtntmineshoot(rdram, ctx);
        goto after_1;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: jal         0x80800440
    // 0x80800254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800440_chtntmineshoot(rdram, ctx);
        goto after_2;
    // 0x80800254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800258: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800264: jal         0x80089F70
    // 0x80800268: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800268: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_3:
    // 0x8080026C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800270: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800274: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800278: jr          $ra
    // 0x8080027C: nop

    return;
    // 0x8080027C: nop

;}
RECOMP_FUNC void chbobpanel_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2496, 0XC0) << 16);
    // 0x808000AC: jr          $ra
    // 0x808000B0: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2496, 0XC0));
    return;
    // 0x808000B0: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2496, 0XC0));
    // 0x808000B4: nop

    // 0x808000B8: nop

    // 0x808000BC: nop

;}
RECOMP_FUNC void func_80800020_bsblongleg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: beq         $a1, $zero, L_80800044
    if (ctx->r5 == 0) {
        // 0x80800028: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800044;
    }
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: lui         $a2, 0x3F61
    ctx->r6 = S32(0X3F61 << 16);
    // 0x80800030: ori         $a2, $a2, 0x47AE
    ctx->r6 = ctx->r6 | 0X47AE;
    // 0x80800034: jal         0x8009DE38
    // 0x80800038: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    func_8009DE38(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    after_0:
    // 0x8080003C: b           L_80800058
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800058;
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800044:
    // 0x80800044: lui         $a2, 0x3F75
    ctx->r6 = S32(0X3F75 << 16);
    // 0x80800048: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8080004C: jal         0x8009DE38
    // 0x80800050: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    func_8009DE38(rdram, ctx);
        goto after_1;
    // 0x80800050: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    after_1:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void _chlifeforcespell_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086598: syscall     338
    recomp_syscall_handler(rdram, ctx, 0x80086598);
    return;
    // 0x8008659C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800F70BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F70BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F70C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F70C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F70C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F70CC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F70D0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F70D4: jal         0x8009E71C
    // 0x800F70D8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8009E71C(rdram, ctx);
        goto after_0;
    // 0x800F70D8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_0:
    // 0x800F70DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F70E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F70E4: jr          $ra
    // 0x800F70E8: nop

    return;
    // 0x800F70E8: nop

;}
RECOMP_FUNC void func_8080843C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080843C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808444: jal         0x80100094
    // 0x80808448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80808448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080844C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80808450: jal         0x80089D48
    // 0x80808454: lbu         $a0, 0x78($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X78);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80808454: lbu         $a0, 0x78($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X78);
    after_1:
    // 0x80808458: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080845C: sb          $v0, 0x78($t6)
    MEM_B(0X78, ctx->r14) = ctx->r2;
    // 0x80808460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808464: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80808468: jr          $ra
    // 0x8080846C: nop

    return;
    // 0x8080846C: nop

;}
RECOMP_FUNC void _baduo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084918: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084918);
    return;
    // 0x8008491C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80800930_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800930: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800934: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800938: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080093C: jal         0x80800234
    // 0x80800940: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bssnowball_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800940: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800948: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x8080094C: jal         0x8008CB3C
    // 0x80800950: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800950: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_1:
    // 0x80800954: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80800958: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800960: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800964: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800968: jal         0x8009FFD8
    // 0x8080096C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080096C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800970: jal         0x8008CABC
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_3;
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800978: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080097C: jal         0x8008B134
    // 0x80800980: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x80800980: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800984: jal         0x80800164
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bssnowball(rdram, ctx);
        goto after_5;
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080098C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800990: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800994: sb          $zero, 0x164($s0)
    MEM_B(0X164, ctx->r16) = 0;
    // 0x80800998: swc1        $f4, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f4.u32l;
    // 0x8080099C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808009A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009A8: jr          $ra
    // 0x808009AC: nop

    return;
    // 0x808009AC: nop

;}
RECOMP_FUNC void chfiregen_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801038: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X1A44) << 16);
    // 0x8080103C: jr          $ra
    // 0x80801040: addiu       $v0, $v0, 0x1A44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1A44));
    return;
    // 0x80801040: addiu       $v0, $v0, 0x1A44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1A44));
;}
RECOMP_FUNC void baanim_isStopped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CAEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CAF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CAF4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CAF8: jal         0x8008B324
    // 0x8008CAFC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    anctrl_isStopped(rdram, ctx);
        goto after_0;
    // 0x8008CAFC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CB00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CB04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CB08: jr          $ra
    // 0x8008CB0C: nop

    return;
    // 0x8008CB0C: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083988: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x80083988);
    return;
    // 0x8008398C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80102EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102EC0: jr          $ra
    // 0x80102EC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80102EC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _sumissilehome_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A788: syscall     850
    recomp_syscall_handler(rdram, ctx, 0x8008A788);
    return;
    // 0x8008A78C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _gcskyDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088058: syscall     667
    recomp_syscall_handler(rdram, ctx, 0x80088058);
    return;
    // 0x8008805C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
