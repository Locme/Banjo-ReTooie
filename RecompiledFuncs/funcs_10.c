#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chfiregen_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X15FC) << 16);
    // 0x808000B4: jr          $ra
    // 0x808000B8: addiu       $v0, $v0, 0x15FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X15FC));
    return;
    // 0x808000B8: addiu       $v0, $v0, 0x15FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X15FC));
;}
RECOMP_FUNC void func_800EE108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE108: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EE10C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EE110: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EE114: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EE118: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800EE11C: jal         0x800D8FF8
    // 0x800EE120: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800EE120: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EE124: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800EE128: lwc1        $f2, 0x74($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800EE12C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EE130: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800EE134: addiu       $a2, $a2, -0x3610
    ctx->r6 = ADD32(ctx->r6, -0X3610);
    // 0x800EE138: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800EE13C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800EE140: bc1fl       L_800EE1B4
    if (!c1cs) {
        // 0x800EE144: lwc1        $f0, 0x9C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X9C);
            goto L_800EE1B4;
    }
    goto skip_0;
    // 0x800EE144: lwc1        $f0, 0x9C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X9C);
    skip_0:
    // 0x800EE148: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800EE14C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800EE150: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x800EE154: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800EE158: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x800EE15C: nop

    // 0x800EE160: bc1fl       L_800EE184
    if (!c1cs) {
        // 0x800EE164: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_800EE184;
    }
    goto skip_1;
    // 0x800EE164: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x800EE168: lbu         $t6, 0x28($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X28);
    // 0x800EE16C: swc1        $f2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f2.u32l;
    // 0x800EE170: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800EE174: bnel        $t6, $zero, L_800EE184
    if (ctx->r14 != 0) {
        // 0x800EE178: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_800EE184;
    }
    goto skip_2;
    // 0x800EE178: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x800EE17C: sb          $t7, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r15;
    // 0x800EE180: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_800EE184:
    // 0x800EE184: jal         0x80088660
    // 0x800EE188: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x800EE188: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x800EE18C: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
    // 0x800EE190: beq         $v0, $zero, L_800EE1B0
    if (ctx->r2 == 0) {
        // 0x800EE194: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800EE1B0;
    }
    // 0x800EE194: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800EE198: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800EE19C: bne         $t9, $zero, L_800EE1B0
    if (ctx->r25 != 0) {
        // 0x800EE1A0: sb          $t8, 0x28($s0)
        MEM_B(0X28, ctx->r16) = ctx->r24;
            goto L_800EE1B0;
    }
    // 0x800EE1A0: sb          $t8, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r24;
    // 0x800EE1A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800EE1A8: nop

    // 0x800EE1AC: swc1        $f18, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f18.u32l;
L_800EE1B0:
    // 0x800EE1B0: lwc1        $f0, 0x9C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X9C);
L_800EE1B4:
    // 0x800EE1B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EE1B8: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EE1BC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800EE1C0: nop

    // 0x800EE1C4: bc1fl       L_800EE29C
    if (!c1cs) {
        // 0x800EE1C8: lbu         $v0, 0x29($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X29);
            goto L_800EE29C;
    }
    goto skip_3;
    // 0x800EE1C8: lbu         $v0, 0x29($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X29);
    skip_3:
    // 0x800EE1CC: lwc1        $f6, 0x98($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X98);
    // 0x800EE1D0: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800EE1D4: addiu       $a2, $a2, -0x2864
    ctx->r6 = ADD32(ctx->r6, -0X2864);
    // 0x800EE1D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800EE1DC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800EE1E0: swc1        $f10, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f10.u32l;
    // 0x800EE1E4: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x800EE1E8: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x800EE1EC: nop

    // 0x800EE1F0: bc1fl       L_800EE214
    if (!c1cs) {
        // 0x800EE1F4: lbu         $v0, 0x29($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X29);
            goto L_800EE214;
    }
    goto skip_4;
    // 0x800EE1F4: lbu         $v0, 0x29($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X29);
    skip_4:
    // 0x800EE1F8: lbu         $t0, 0x28($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X28);
    // 0x800EE1FC: swc1        $f0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f0.u32l;
    // 0x800EE200: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800EE204: bnel        $t0, $zero, L_800EE214
    if (ctx->r8 != 0) {
        // 0x800EE208: lbu         $v0, 0x29($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X29);
            goto L_800EE214;
    }
    goto skip_5;
    // 0x800EE208: lbu         $v0, 0x29($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X29);
    skip_5:
    // 0x800EE20C: sb          $t1, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r9;
    // 0x800EE210: lbu         $v0, 0x29($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X29);
L_800EE214:
    // 0x800EE214: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800EE218: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800EE21C: beq         $v0, $at, L_800EE234
    if (ctx->r2 == ctx->r1) {
        // 0x800EE220: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_800EE234;
    }
    // 0x800EE220: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800EE224: beq         $v0, $at, L_800EE244
    if (ctx->r2 == ctx->r1) {
        // 0x800EE228: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_800EE244;
    }
    // 0x800EE228: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800EE22C: b           L_800EE260
    // 0x800EE230: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_800EE260;
    // 0x800EE230: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_800EE234:
    // 0x800EE234: jal         0x80088660
    // 0x800EE238: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _glid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x800EE238: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x800EE23C: b           L_800EE278
    // 0x800EE240: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
        goto L_800EE278;
    // 0x800EE240: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
L_800EE244:
    // 0x800EE244: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800EE248: addiu       $a2, $a2, -0x2BDC
    ctx->r6 = ADD32(ctx->r6, -0X2BDC);
    // 0x800EE24C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800EE250: jal         0x80088660
    // 0x800EE254: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x800EE254: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x800EE258: b           L_800EE278
    // 0x800EE25C: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
        goto L_800EE278;
    // 0x800EE25C: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
L_800EE260:
    // 0x800EE260: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800EE264: addiu       $a2, $a2, -0x2EBC
    ctx->r6 = ADD32(ctx->r6, -0X2EBC);
    // 0x800EE268: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800EE26C: jal         0x80088660
    // 0x800EE270: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x800EE270: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x800EE274: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
L_800EE278:
    // 0x800EE278: beq         $v0, $zero, L_800EE298
    if (ctx->r2 == 0) {
        // 0x800EE27C: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_800EE298;
    }
    // 0x800EE27C: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800EE280: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800EE284: bne         $t3, $zero, L_800EE298
    if (ctx->r11 != 0) {
        // 0x800EE288: sb          $t2, 0x28($s0)
        MEM_B(0X28, ctx->r16) = ctx->r10;
            goto L_800EE298;
    }
    // 0x800EE288: sb          $t2, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r10;
    // 0x800EE28C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EE290: nop

    // 0x800EE294: swc1        $f4, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f4.u32l;
L_800EE298:
    // 0x800EE298: lbu         $v0, 0x29($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X29);
L_800EE29C:
    // 0x800EE29C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800EE2A0: beql        $v0, $zero, L_800EE51C
    if (ctx->r2 == 0) {
        // 0x800EE2A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800EE51C;
    }
    goto skip_6;
    // 0x800EE2A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x800EE2A8: beq         $v0, $at, L_800EE518
    if (ctx->r2 == ctx->r1) {
        // 0x800EE2AC: lwc1        $f8, 0x2C($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_800EE518;
    }
    // 0x800EE2AC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EE2B0: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800EE2B4: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800EE2B8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800EE2BC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x800EE2C0: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800EE2C4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800EE2C8: nop

    // 0x800EE2CC: bc1fl       L_800EE2DC
    if (!c1cs) {
        // 0x800EE2D0: lbu         $a0, 0x0($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X0);
            goto L_800EE2DC;
    }
    goto skip_7;
    // 0x800EE2D0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    skip_7:
    // 0x800EE2D4: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x800EE2D8: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
L_800EE2DC:
    // 0x800EE2DC: beql        $a0, $zero, L_800EE410
    if (ctx->r4 == 0) {
        // 0x800EE2E0: lbu         $t5, 0x29($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X29);
            goto L_800EE410;
    }
    goto skip_8;
    // 0x800EE2E0: lbu         $t5, 0x29($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X29);
    skip_8:
    // 0x800EE2E4: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800EE2E8: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800EE2EC: jal         0x800C395C
    // 0x800EE2F0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    func_800C395C(rdram, ctx);
        goto after_5;
    // 0x800EE2F0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x800EE2F4: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800EE2F8: jal         0x800C3920
    // 0x800EE2FC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800C3920(rdram, ctx);
        goto after_6;
    // 0x800EE2FC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x800EE300: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800EE304: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800EE308: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EE30C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800EE310: jal         0x800DC264
    // 0x800EE314: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800DC264(rdram, ctx);
        goto after_7;
    // 0x800EE314: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_7:
    // 0x800EE318: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EE31C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EE320: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800EE324: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800EE328: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800EE32C: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x800EE330: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x800EE334: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800EE338: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x800EE33C: nop

    // 0x800EE340: bc1fl       L_800EE350
    if (!c1cs) {
        // 0x800EE344: lwc1        $f0, 0x24($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
            goto L_800EE350;
    }
    goto skip_9;
    // 0x800EE344: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    skip_9:
    // 0x800EE348: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x800EE34C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
L_800EE350:
    // 0x800EE350: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800EE354: nop

    // 0x800EE358: bc1fl       L_800EE368
    if (!c1cs) {
        // 0x800EE35C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800EE368;
    }
    goto skip_10;
    // 0x800EE35C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    skip_10:
    // 0x800EE360: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x800EE364: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
L_800EE368:
    // 0x800EE368: jal         0x800DC214
    // 0x800EE36C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_800DC214(rdram, ctx);
        goto after_8;
    // 0x800EE36C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x800EE370: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800EE374: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800EE378: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EE37C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800EE380: slt         $at, $a2, $at
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800EE384: bne         $at, $zero, L_800EE390
    if (ctx->r1 != 0) {
        // 0x800EE388: lwc1        $f2, 0x28($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
            goto L_800EE390;
    }
    // 0x800EE388: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800EE38C: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
L_800EE390:
    // 0x800EE390: slti        $at, $a2, 0x7918
    ctx->r1 = SIGNED(ctx->r6) < 0X7918 ? 1 : 0;
    // 0x800EE394: beq         $at, $zero, L_800EE3A0
    if (ctx->r1 == 0) {
        // 0x800EE398: nop
    
            goto L_800EE3A0;
    }
    // 0x800EE398: nop

    // 0x800EE39C: addiu       $a2, $zero, 0x7918
    ctx->r6 = ADD32(0, 0X7918);
L_800EE3A0:
    // 0x800EE3A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EE3A4: lwc1        $f0, 0x5E74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5E74);
    // 0x800EE3A8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800EE3AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EE3B0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800EE3B4: nop

    // 0x800EE3B8: bc1fl       L_800EE3F8
    if (!c1cs) {
        // 0x800EE3BC: lbu         $a0, 0x0($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X0);
            goto L_800EE3F8;
    }
    goto skip_11;
    // 0x800EE3BC: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    skip_11:
    // 0x800EE3C0: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800EE3C4: lwc1        $f4, 0x5E78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5E78);
    // 0x800EE3C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EE3CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EE3D0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800EE3D4: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    // 0x800EE3D8: nop

    // 0x800EE3DC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800EE3E0: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800EE3E4: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800EE3E8: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800EE3EC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800EE3F0: nop

    // 0x800EE3F4: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
L_800EE3F8:
    // 0x800EE3F8: jal         0x800C31DC
    // 0x800EE3FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800C31DC(rdram, ctx);
        goto after_9;
    // 0x800EE3FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_9:
    // 0x800EE400: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800EE404: jal         0x800C3058
    // 0x800EE408: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_800C3058(rdram, ctx);
        goto after_10;
    // 0x800EE408: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_10:
    // 0x800EE40C: lbu         $t5, 0x29($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X29);
L_800EE410:
    // 0x800EE410: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800EE414: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x800EE418: beq         $at, $zero, L_800EE4CC
    if (ctx->r1 == 0) {
        // 0x800EE41C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800EE4CC;
    }
    // 0x800EE41C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800EE420: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EE424: addu        $at, $at, $t6
    gpr jr_addend_800EE42C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800EE428: lw          $t6, 0x5E7C($at)
    ctx->r14 = ADD32(ctx->r1, 0X5E7C);
    // 0x800EE42C: jr          $t6
    // 0x800EE430: nop

    switch (jr_addend_800EE42C >> 2) {
        case 0: goto L_800EE434; break;
        case 1: goto L_800EE454; break;
        case 2: goto L_800EE474; break;
        case 3: goto L_800EE494; break;
        case 4: goto L_800EE4CC; break;
        case 5: goto L_800EE4CC; break;
        case 6: goto L_800EE4B4; break;
        default: switch_error(__func__, 0x800EE42C, 0x80125E7C);
    }
    // 0x800EE430: nop

L_800EE434:
    // 0x800EE434: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800EE438: addiu       $a2, $a2, -0x32A0
    ctx->r6 = ADD32(ctx->r6, -0X32A0);
    // 0x800EE43C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800EE440: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800EE444: jal         0x80088660
    // 0x800EE448: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x800EE448: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_11:
    // 0x800EE44C: b           L_800EE4D0
    // 0x800EE450: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
        goto L_800EE4D0;
    // 0x800EE450: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
L_800EE454:
    // 0x800EE454: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800EE458: addiu       $a2, $a2, -0x3114
    ctx->r6 = ADD32(ctx->r6, -0X3114);
    // 0x800EE45C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800EE460: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800EE464: jal         0x80088660
    // 0x800EE468: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x800EE468: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_12:
    // 0x800EE46C: b           L_800EE4D0
    // 0x800EE470: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
        goto L_800EE4D0;
    // 0x800EE470: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
L_800EE474:
    // 0x800EE474: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800EE478: addiu       $a2, $a2, -0x2F9C
    ctx->r6 = ADD32(ctx->r6, -0X2F9C);
    // 0x800EE47C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800EE480: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800EE484: jal         0x80088660
    // 0x800EE488: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x800EE488: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_13:
    // 0x800EE48C: b           L_800EE4D0
    // 0x800EE490: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
        goto L_800EE4D0;
    // 0x800EE490: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
L_800EE494:
    // 0x800EE494: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800EE498: addiu       $a2, $a2, -0x2808
    ctx->r6 = ADD32(ctx->r6, -0X2808);
    // 0x800EE49C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800EE4A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800EE4A4: jal         0x80088660
    // 0x800EE4A8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x800EE4A8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_14:
    // 0x800EE4AC: b           L_800EE4D0
    // 0x800EE4B0: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
        goto L_800EE4D0;
    // 0x800EE4B0: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
L_800EE4B4:
    // 0x800EE4B4: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800EE4B8: addiu       $a2, $a2, -0x2F2C
    ctx->r6 = ADD32(ctx->r6, -0X2F2C);
    // 0x800EE4BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800EE4C0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800EE4C4: jal         0x80088660
    // 0x800EE4C8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x800EE4C8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_15:
L_800EE4CC:
    // 0x800EE4CC: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
L_800EE4D0:
    // 0x800EE4D0: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800EE4D4: c.le.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl <= ctx->f18.fl;
    // 0x800EE4D8: nop

    // 0x800EE4DC: bc1fl       L_800EE51C
    if (!c1cs) {
        // 0x800EE4E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800EE51C;
    }
    goto skip_12;
    // 0x800EE4E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x800EE4E4: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800EE4E8: lh          $t7, 0x4E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4E);
    // 0x800EE4EC: sb          $zero, 0x29($s0)
    MEM_B(0X29, ctx->r16) = 0;
    // 0x800EE4F0: beq         $v0, $zero, L_800EE500
    if (ctx->r2 == 0) {
        // 0x800EE4F4: sh          $t7, 0x4C($s0)
        MEM_H(0X4C, ctx->r16) = ctx->r15;
            goto L_800EE500;
    }
    // 0x800EE4F4: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
    // 0x800EE4F8: jalr        $v0
    // 0x800EE4FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_16;
    // 0x800EE4FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_800EE500:
    // 0x800EE500: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800EE504: beql        $a0, $zero, L_800EE51C
    if (ctx->r4 == 0) {
        // 0x800EE508: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800EE51C;
    }
    goto skip_13;
    // 0x800EE508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x800EE50C: jal         0x800C2FDC
    // 0x800EE510: nop

    func_800C2FDC(rdram, ctx);
        goto after_17;
    // 0x800EE510: nop

    after_17:
    // 0x800EE514: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_800EE518:
    // 0x800EE518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800EE51C:
    // 0x800EE51C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EE520: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800EE524: jr          $ra
    // 0x800EE528: nop

    return;
    // 0x800EE528: nop

    // 0x800EE52C: nop

;}
RECOMP_FUNC void chsilo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801220: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1820, 0X1384) << 16);
    // 0x80801224: jr          $ra
    // 0x80801228: addiu       $v0, $v0, 0x1384
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1820, 0X1384));
    return;
    // 0x80801228: addiu       $v0, $v0, 0x1384
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1820, 0X1384));
    // 0x8080122C: nop

;}
RECOMP_FUNC void func_80800670_chtoxicroomprops(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800670: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800674: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800678: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080067C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800680: jal         0x800D90A4
    // 0x80800684: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80800684: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800688: beq         $v0, $zero, L_808006D8
    if (ctx->r2 == 0) {
        // 0x8080068C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D8;
    }
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800694: jal         0x80800390
    // 0x80800698: lui         $a1, 0xC000
    ctx->r5 = S32(0XC000 << 16);
    func_80800390_chtoxicroomprops(rdram, ctx);
        goto after_1;
    // 0x80800698: lui         $a1, 0xC000
    ctx->r5 = S32(0XC000 << 16);
    after_1:
    // 0x8080069C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808006A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006A4: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808006A8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808006AC: nop

    // 0x808006B0: bc1fl       L_808006E4
    if (!c1cs) {
        // 0x808006B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808006E4;
    }
    goto skip_0;
    // 0x808006B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808006B8: jal         0x80089D40
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808006C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808006C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006C8: jal         0x800FFA88
    // 0x808006CC: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    func_800FFA88(rdram, ctx);
        goto after_3;
    // 0x808006CC: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x808006D0: b           L_808006E4
    // 0x808006D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808006E4;
    // 0x808006D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006D8:
    // 0x808006D8: jal         0x80800390
    // 0x808006DC: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80800390_chtoxicroomprops(rdram, ctx);
        goto after_4;
    // 0x808006DC: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_4:
    // 0x808006E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006E4:
    // 0x808006E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006EC: jr          $ra
    // 0x808006F0: nop

    return;
    // 0x808006F0: nop

;}
RECOMP_FUNC void func_80801BE0_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80801BE0_chstoneballcontrol");
    // 0x80801BE0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80801BE4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801BE8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80801BEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801BF0: jal         0x80100094
    // 0x80801BF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801BF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801BF8: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80801BFC: jal         0x80106790
    // 0x80801C00: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801C00: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80801C04: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x80801C08: jal         0x80090178
    // 0x80801C0C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_80090178(rdram, ctx);
        goto after_2;
    // 0x80801C0C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_2:
    // 0x80801C10: bne         $v0, $zero, L_80801C24
    if (ctx->r2 != 0) {
        // 0x80801C14: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_80801C24;
    }
    // 0x80801C14: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80801C18: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801C1C: jal         0x8008FB58
    // 0x80801C20: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    func_8008FB58(rdram, ctx);
        goto after_3;
    // 0x80801C20: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    after_3:
L_80801C24:
    // 0x80801C24: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80801C28: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801C2C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80801C30: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80801C34: beq         $at, $zero, L_80802288
    if (ctx->r1 == 0) {
        // 0x80801C38: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80802288;
    }
    // 0x80801C38: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801C3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4ED8) << 16);
    // 0x80801C40: addu        $at, $at, $t8
    gpr jr_addend_80801C48 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801C44: lw          $t8, 0x4ED8($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4ED8));
    // 0x80801C48: jr          $t8
    // 0x80801C4C: nop

    switch (jr_addend_80801C48 >> 2) {
        case 0: goto L_80801EC0; break;
        case 1: goto L_80801EE0; break;
        case 2: goto L_80802100; break;
        case 3: goto L_80802254; break;
        case 4: goto L_80801C50; break;
        case 5: goto L_8080226C; break;
        default: switch_error(__func__, 0x80801C48, 0x80804ED8);
    }
    // 0x80801C4C: nop

L_80801C50:
    // 0x80801C50: jal         0x800EA05C
    // 0x80801C54: nop

    func_800EA05C(rdram, ctx);
        goto after_4;
    // 0x80801C54: nop

    after_4:
    // 0x80801C58: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x80801C5C: beq         $v0, $at, L_80801D90
    if (ctx->r2 == ctx->r1) {
        // 0x80801C60: lui         $at, 0x41C8
        ctx->r1 = S32(0X41C8 << 16);
            goto L_80801D90;
    }
    // 0x80801C60: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80801C64: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801C68: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801C6C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801C70: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80801C74: nop

    // 0x80801C78: bc1fl       L_80801C94
    if (!c1cs) {
        // 0x80801C7C: lbu         $t9, 0x9B($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X9B);
            goto L_80801C94;
    }
    goto skip_0;
    // 0x80801C7C: lbu         $t9, 0x9B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X9B);
    skip_0:
    // 0x80801C80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801C84: nop

    // 0x80801C88: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80801C8C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80801C90: lbu         $t9, 0x9B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X9B);
L_80801C94:
    // 0x80801C94: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801C98: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80801C9C: bgez        $t9, L_80801CB0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80801CA0: cvt.s.w     $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80801CB0;
    }
    // 0x80801CA0: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801CA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801CA8: nop

    // 0x80801CAC: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_80801CB0:
    // 0x80801CB0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80801CB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801CB8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80801CBC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80801CC0: nop

    // 0x80801CC4: bc1fl       L_80801D64
    if (!c1cs) {
        // 0x80801CC8: lwc1        $f10, 0x8($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
            goto L_80801D64;
    }
    goto skip_1;
    // 0x80801CC8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x80801CCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801CD0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801CD4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801CD8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80801CDC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80801CE0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80801CE4: nop

    // 0x80801CE8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801CEC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80801CF0: nop

    // 0x80801CF4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80801CF8: beql        $t1, $zero, L_80801D48
    if (ctx->r9 == 0) {
        // 0x80801CFC: mfc1        $t1, $f8
        ctx->r9 = (int32_t)ctx->f8.u32l;
            goto L_80801D48;
    }
    goto skip_2;
    // 0x80801CFC: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x80801D00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801D04: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801D08: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801D0C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80801D10: nop

    // 0x80801D14: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80801D18: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80801D1C: nop

    // 0x80801D20: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80801D24: bne         $t1, $zero, L_80801D3C
    if (ctx->r9 != 0) {
        // 0x80801D28: nop
    
            goto L_80801D3C;
    }
    // 0x80801D28: nop

    // 0x80801D2C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80801D30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801D34: b           L_80801D54
    // 0x80801D38: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80801D54;
    // 0x80801D38: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80801D3C:
    // 0x80801D3C: b           L_80801D54
    // 0x80801D40: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80801D54;
    // 0x80801D40: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801D44: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
L_80801D48:
    // 0x80801D48: nop

    // 0x80801D4C: bltz        $t1, L_80801D3C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80801D50: nop
    
            goto L_80801D3C;
    }
    // 0x80801D50: nop

L_80801D54:
    // 0x80801D54: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80801D58: b           L_80802288
    // 0x80801D5C: sb          $t1, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r9;
        goto L_80802288;
    // 0x80801D5C: sb          $t1, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r9;
    // 0x80801D60: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
L_80801D64:
    // 0x80801D64: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x80801D68: nop

    // 0x80801D6C: bc1fl       L_8080228C
    if (!c1cs) {
        // 0x80801D70: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_8080228C;
    }
    goto skip_3;
    // 0x80801D70: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_3:
    // 0x80801D74: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
    // 0x80801D78: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80801D7C: sb          $t5, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r13;
    // 0x80801D80: andi        $t3, $t2, 0xFF03
    ctx->r11 = ctx->r10 & 0XFF03;
    // 0x80801D84: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x80801D88: b           L_80802288
    // 0x80801D8C: sb          $t4, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r12;
        goto L_80802288;
    // 0x80801D8C: sb          $t4, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r12;
L_80801D90:
    // 0x80801D90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4EF0) << 16);
    // 0x80801D94: lwc1        $f2, 0x4EF0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4EF0));
    // 0x80801D98: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801D9C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801DA0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80801DA4: nop

    // 0x80801DA8: bc1fl       L_80801DC4
    if (!c1cs) {
        // 0x80801DAC: lbu         $t6, 0x9B($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X9B);
            goto L_80801DC4;
    }
    goto skip_4;
    // 0x80801DAC: lbu         $t6, 0x9B($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X9B);
    skip_4:
    // 0x80801DB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801DB4: nop

    // 0x80801DB8: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80801DBC: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80801DC0: lbu         $t6, 0x9B($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X9B);
L_80801DC4:
    // 0x80801DC4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801DC8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80801DCC: bgez        $t6, L_80801DE0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80801DD0: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80801DE0;
    }
    // 0x80801DD0: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801DD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801DD8: nop

    // 0x80801DDC: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_80801DE0:
    // 0x80801DE0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80801DE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801DE8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80801DEC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80801DF0: nop

    // 0x80801DF4: bc1fl       L_80801E94
    if (!c1cs) {
        // 0x80801DF8: lwc1        $f8, 0x8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
            goto L_80801E94;
    }
    goto skip_5;
    // 0x80801DF8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    skip_5:
    // 0x80801DFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801E00: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801E04: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801E08: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80801E0C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80801E10: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80801E14: nop

    // 0x80801E18: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80801E1C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80801E20: nop

    // 0x80801E24: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80801E28: beql        $t8, $zero, L_80801E78
    if (ctx->r24 == 0) {
        // 0x80801E2C: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_80801E78;
    }
    goto skip_6;
    // 0x80801E2C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_6:
    // 0x80801E30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801E34: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801E38: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801E3C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80801E40: nop

    // 0x80801E44: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801E48: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80801E4C: nop

    // 0x80801E50: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80801E54: bne         $t8, $zero, L_80801E6C
    if (ctx->r24 != 0) {
        // 0x80801E58: nop
    
            goto L_80801E6C;
    }
    // 0x80801E58: nop

    // 0x80801E5C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80801E60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801E64: b           L_80801E84
    // 0x80801E68: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80801E84;
    // 0x80801E68: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80801E6C:
    // 0x80801E6C: b           L_80801E84
    // 0x80801E70: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80801E84;
    // 0x80801E70: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80801E74: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_80801E78:
    // 0x80801E78: nop

    // 0x80801E7C: bltz        $t8, L_80801E6C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801E80: nop
    
            goto L_80801E6C;
    }
    // 0x80801E80: nop

L_80801E84:
    // 0x80801E84: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80801E88: b           L_80802288
    // 0x80801E8C: sb          $t8, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r24;
        goto L_80802288;
    // 0x80801E8C: sb          $t8, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r24;
    // 0x80801E90: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
L_80801E94:
    // 0x80801E94: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80801E98: nop

    // 0x80801E9C: bc1fl       L_8080228C
    if (!c1cs) {
        // 0x80801EA0: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_8080228C;
    }
    goto skip_7;
    // 0x80801EA0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_7:
    // 0x80801EA4: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
    // 0x80801EA8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80801EAC: sb          $t2, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r10;
    // 0x80801EB0: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x80801EB4: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x80801EB8: b           L_80802288
    // 0x80801EBC: sb          $t1, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r9;
        goto L_80802288;
    // 0x80801EBC: sb          $t1, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r9;
L_80801EC0:
    // 0x80801EC0: jal         0x80803148
    // 0x80801EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803148_chstoneballcontrol(rdram, ctx);
        goto after_5;
    // 0x80801EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801EC8: jal         0x80802C30
    // 0x80801ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802C30_chstoneballcontrol(rdram, ctx);
        goto after_6;
    // 0x80801ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801ED0: jal         0x808023AC
    // 0x80801ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808023AC_chstoneballcontrol(rdram, ctx);
        goto after_7;
    // 0x80801ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801ED8: b           L_8080228C
    // 0x80801EDC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_8080228C;
    // 0x80801EDC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80801EE0:
    // 0x80801EE0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801EE4: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x80801EE8: jal         0x800EE7F8
    // 0x80801EEC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80801EEC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_8:
    // 0x80801EF0: jal         0x80802C30
    // 0x80801EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802C30_chstoneballcontrol(rdram, ctx);
        goto after_9;
    // 0x80801EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801EF8: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x80801EFC: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80801F00: jal         0x80089AC8
    // 0x80801F04: lbu         $a1, 0x20($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X20);
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x80801F04: lbu         $a1, 0x20($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X20);
    after_10:
    // 0x80801F08: beq         $v0, $zero, L_80801F90
    if (ctx->r2 == 0) {
        // 0x80801F0C: lw          $t7, 0x84($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X84);
            goto L_80801F90;
    }
    // 0x80801F0C: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80801F10: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x80801F14: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80801F18: jal         0x800F5A00
    // 0x80801F1C: lbu         $a0, 0x20($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_11;
    // 0x80801F1C: lbu         $a0, 0x20($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X20);
    after_11:
    // 0x80801F20: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x80801F24: jal         0x800F5F24
    // 0x80801F28: lbu         $a0, 0x20($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X20);
    func_800F5F24(rdram, ctx);
        goto after_12;
    // 0x80801F28: lbu         $a0, 0x20($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X20);
    after_12:
    // 0x80801F2C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801F30: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80801F34: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801F38: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80801F3C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801F40: jal         0x800EFCD8
    // 0x80801F44: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_800EFCD8(rdram, ctx);
        goto after_13;
    // 0x80801F44: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_13:
    // 0x80801F48: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801F4C: jal         0x800EF04C
    // 0x80801F50: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_800EF04C(rdram, ctx);
        goto after_14;
    // 0x80801F50: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_14:
    // 0x80801F54: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x80801F58: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80801F5C: jal         0x800F5D70
    // 0x80801F60: lbu         $a0, 0x20($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X20);
    func_800F5D70(rdram, ctx);
        goto after_15;
    // 0x80801F60: lbu         $a0, 0x20($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X20);
    after_15:
    // 0x80801F64: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80801F68: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80801F6C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80801F70: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80801F74: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80801F78: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80801F7C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80801F80: jal         0x800EE7F8
    // 0x80801F84: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x80801F84: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    after_16:
    // 0x80801F88: b           L_80801FFC
    // 0x80801F8C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
        goto L_80801FFC;
    // 0x80801F8C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
L_80801F90:
    // 0x80801F90: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80801F94: jal         0x80089AD8
    // 0x80801F98: lbu         $a1, 0x20($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X20);
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_17;
    // 0x80801F98: lbu         $a1, 0x20($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X20);
    after_17:
    // 0x80801F9C: jal         0x80106790
    // 0x80801FA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_18;
    // 0x80801FA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_18:
    // 0x80801FA4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80801FA8: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80801FAC: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80801FB0: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80801FB4: lw          $a1, 0x48($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X48);
    // 0x80801FB8: jal         0x800EFCD8
    // 0x80801FBC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800EFCD8(rdram, ctx);
        goto after_19;
    // 0x80801FBC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_19:
    // 0x80801FC0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80801FC4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801FC8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80801FCC: jal         0x800EF04C
    // 0x80801FD0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800EF04C(rdram, ctx);
        goto after_20;
    // 0x80801FD0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_20:
    // 0x80801FD4: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80801FD8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80801FDC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80801FE0: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80801FE4: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x80801FE8: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80801FEC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80801FF0: jal         0x800EE7F8
    // 0x80801FF4: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_21;
    // 0x80801FF4: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    after_21:
    // 0x80801FF8: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
L_80801FFC:
    // 0x80801FFC: jal         0x800EFBFC
    // 0x80802000: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_800EFBFC(rdram, ctx);
        goto after_22;
    // 0x80802000: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_22:
    // 0x80802004: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80802008: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080200C: nop

    // 0x80802010: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80802014: nop

    // 0x80802018: bc1f        L_80802078
    if (!c1cs) {
        // 0x8080201C: nop
    
            goto L_80802078;
    }
    // 0x8080201C: nop

    // 0x80802020: jal         0x800DC0C0
    // 0x80802024: nop

    func_800DC0C0(rdram, ctx);
        goto after_23;
    // 0x80802024: nop

    after_23:
    // 0x80802028: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4EF4) << 16);
    // 0x8080202C: lwc1        $f10, 0x4EF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4EF4));
    // 0x80802030: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1608, 0X5120) << 16);
    // 0x80802034: addiu       $a2, $a2, 0x5120
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1608, 0X5120));
    // 0x80802038: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8080203C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80802040: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80802044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802048: bc1f        L_80802078
    if (!c1cs) {
        // 0x8080204C: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80802078;
    }
    // 0x8080204C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80802050: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802054: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80802058: addiu       $t8, $zero, 0x4B
    ctx->r24 = ADD32(0, 0X4B);
    // 0x8080205C: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x80802060: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80802064: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80802068: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8080206C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80802070: jal         0x800B4470
    // 0x80802074: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B4470(rdram, ctx);
        goto after_24;
    // 0x80802074: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_24:
L_80802078:
    // 0x80802078: jal         0x800D9078
    // 0x8080207C: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    func_800D9078(rdram, ctx);
        goto after_25;
    // 0x8080207C: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_25:
    // 0x80802080: jal         0x80803148
    // 0x80802084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803148_chstoneballcontrol(rdram, ctx);
        goto after_26;
    // 0x80802084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80802088: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x8080208C: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80802090: jal         0x80089AD0
    // 0x80802094: lbu         $a1, 0x20($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X20);
    _sukickball_entrypoint_7(rdram, ctx);
        goto after_27;
    // 0x80802094: lbu         $a1, 0x20($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X20);
    after_27:
    // 0x80802098: beq         $v0, $zero, L_808020F0
    if (ctx->r2 == 0) {
        // 0x8080209C: lw          $t1, 0x84($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X84);
            goto L_808020F0;
    }
    // 0x8080209C: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x808020A0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x808020A4: jal         0x80089AD8
    // 0x808020A8: lbu         $a1, 0x20($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X20);
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_28;
    // 0x808020A8: lbu         $a1, 0x20($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X20);
    after_28:
    // 0x808020AC: jal         0x80106790
    // 0x808020B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_29;
    // 0x808020B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_29:
    // 0x808020B4: lw          $t2, 0x64($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X64);
    // 0x808020B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808020BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020C0: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x808020C4: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x808020C8: bne         $t4, $at, L_808020F0
    if (ctx->r12 != ctx->r1) {
        // 0x808020CC: nop
    
            goto L_808020F0;
    }
    // 0x808020CC: nop

    // 0x808020D0: jal         0x80803538
    // 0x808020D4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    func_80803538_chstoneballcontrol(rdram, ctx);
        goto after_30;
    // 0x808020D4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_30:
    // 0x808020D8: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x808020DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808020E0: lbu         $t5, 0x65($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X65);
    // 0x808020E4: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
    // 0x808020E8: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x808020EC: sb          $t6, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r14;
L_808020F0:
    // 0x808020F0: jal         0x808023AC
    // 0x808020F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808023AC_chstoneballcontrol(rdram, ctx);
        goto after_31;
    // 0x808020F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x808020F8: b           L_8080228C
    // 0x808020FC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_8080228C;
    // 0x808020FC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80802100:
    // 0x80802100: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x80802104: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80802108: jal         0x80802C30
    // 0x8080210C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802C30_chstoneballcontrol(rdram, ctx);
        goto after_32;
    // 0x8080210C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80802110: jal         0x800D8FF8
    // 0x80802114: nop

    func_800D8FF8(rdram, ctx);
        goto after_33;
    // 0x80802114: nop

    after_33:
    // 0x80802118: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080211C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80802120: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80802124: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80802128: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8080212C: jal         0x800EF1B8
    // 0x80802130: nop

    func_800EF1B8(rdram, ctx);
        goto after_34;
    // 0x80802130: nop

    after_34:
    // 0x80802134: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80802138: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080213C: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802140: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80802144: addiu       $at, $zero, 0x253
    ctx->r1 = ADD32(0, 0X253);
    // 0x80802148: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8080214C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802150: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80802154: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80802158: srl         $t0, $t9, 22
    ctx->r8 = S32(U32(ctx->r25) >> 22);
    // 0x8080215C: bne         $t0, $at, L_808021A0
    if (ctx->r8 != ctx->r1) {
        // 0x80802160: lui         $at, 0x4416
        ctx->r1 = S32(0X4416 << 16);
            goto L_808021A0;
    }
    // 0x80802160: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80802164: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802168: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080216C: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x80802170: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80802174: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80802178: nop

    // 0x8080217C: bc1fl       L_808021A4
    if (!c1cs) {
        // 0x80802180: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_808021A4;
    }
    goto skip_8;
    // 0x80802180: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_8:
    // 0x80802184: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80802188: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8080218C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802190: add.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80802194: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80802198: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x8080219C: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
L_808021A0:
    // 0x808021A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_808021A4:
    // 0x808021A4: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808021A8: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x808021AC: nop

    // 0x808021B0: bc1f        L_808021C8
    if (!c1cs) {
        // 0x808021B4: nop
    
            goto L_808021C8;
    }
    // 0x808021B4: nop

    // 0x808021B8: jal         0x80801944
    // 0x808021BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801944_chstoneballcontrol(rdram, ctx);
        goto after_35;
    // 0x808021BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x808021C0: jal         0x808024F8
    // 0x808021C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808024F8_chstoneballcontrol(rdram, ctx);
        goto after_36;
    // 0x808021C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
L_808021C8:
    // 0x808021C8: jal         0x80803148
    // 0x808021CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803148_chstoneballcontrol(rdram, ctx);
        goto after_37;
    // 0x808021CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x808021D0: jal         0x800DC0C0
    // 0x808021D4: nop

    func_800DC0C0(rdram, ctx);
        goto after_38;
    // 0x808021D4: nop

    after_38:
    // 0x808021D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4EF8) << 16);
    // 0x808021DC: lwc1        $f6, 0x4EF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4EF8));
    // 0x808021E0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808021E4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808021E8: nop

    // 0x808021EC: bc1f        L_80802244
    if (!c1cs) {
        // 0x808021F0: nop
    
            goto L_80802244;
    }
    // 0x808021F0: nop

    // 0x808021F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808021F8: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808021FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1608, 0X5120) << 16);
    // 0x80802200: addiu       $a2, $a2, 0x5120
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1608, 0X5120));
    // 0x80802204: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80802208: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8080220C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80802210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802214: bc1f        L_80802244
    if (!c1cs) {
        // 0x80802218: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80802244;
    }
    // 0x80802218: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080221C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802220: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802224: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80802228: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x8080222C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80802230: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80802234: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80802238: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8080223C: jal         0x800B4470
    // 0x80802240: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B4470(rdram, ctx);
        goto after_39;
    // 0x80802240: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_39:
L_80802244:
    // 0x80802244: jal         0x808023AC
    // 0x80802248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808023AC_chstoneballcontrol(rdram, ctx);
        goto after_40;
    // 0x80802248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x8080224C: b           L_8080228C
    // 0x80802250: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_8080228C;
    // 0x80802250: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80802254:
    // 0x80802254: jal         0x80802C30
    // 0x80802258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802C30_chstoneballcontrol(rdram, ctx);
        goto after_41;
    // 0x80802258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x8080225C: jal         0x80802418
    // 0x80802260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802418_chstoneballcontrol(rdram, ctx);
        goto after_42;
    // 0x80802260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80802264: b           L_8080228C
    // 0x80802268: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_8080228C;
    // 0x80802268: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_8080226C:
    // 0x8080226C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80802270: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802274: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080227C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80802280: jal         0x80802418
    // 0x80802284: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    func_80802418_chstoneballcontrol(rdram, ctx);
        goto after_43;
    // 0x80802284: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    after_43:
L_80802288:
    // 0x80802288: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_8080228C:
    // 0x8080228C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802290: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802294: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80802298: nop

    // 0x8080229C: bc1fl       L_808022F8
    if (!c1cs) {
        // 0x808022A0: lw          $t3, 0x0($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X0);
            goto L_808022F8;
    }
    goto skip_9;
    // 0x808022A0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x808022A4: jal         0x800137AC
    // 0x808022A8: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800137AC(rdram, ctx);
        goto after_44;
    // 0x808022A8: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_44:
    // 0x808022AC: jal         0x800137C4
    // 0x808022B0: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_800137C4(rdram, ctx);
        goto after_45;
    // 0x808022B0: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_45:
    // 0x808022B4: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808022B8: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808022BC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808022C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808022C4: mul.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808022C8: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808022CC: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808022D0: mul.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808022D4: add.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x808022D8: div.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x808022DC: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x808022E0: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x808022E4: div.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x808022E8: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x808022EC: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x808022F0: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x808022F4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
L_808022F8:
    // 0x808022F8: addiu       $at, $zero, 0x253
    ctx->r1 = ADD32(0, 0X253);
    // 0x808022FC: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x80802300: srl         $t5, $t4, 22
    ctx->r13 = S32(U32(ctx->r12) >> 22);
    // 0x80802304: bnel        $t5, $at, L_80802368
    if (ctx->r13 != ctx->r1) {
        // 0x80802308: lw          $t0, 0x84($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X84);
            goto L_80802368;
    }
    goto skip_10;
    // 0x80802308: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    skip_10:
    // 0x8080230C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80802310: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802314: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80802318: beq         $t6, $at, L_80802364
    if (ctx->r14 == ctx->r1) {
        // 0x8080231C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80802364;
    }
    // 0x8080231C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80802320: beql        $t6, $at, L_80802368
    if (ctx->r14 == ctx->r1) {
        // 0x80802324: lw          $t0, 0x84($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X84);
            goto L_80802368;
    }
    goto skip_11;
    // 0x80802324: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    skip_11:
    // 0x80802328: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x8080232C: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80802330: bgezl       $t9, L_80802368
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80802334: lw          $t0, 0x84($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X84);
            goto L_80802368;
    }
    goto skip_12;
    // 0x80802334: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    skip_12:
    // 0x80802338: jal         0x800DC0C0
    // 0x8080233C: nop

    func_800DC0C0(rdram, ctx);
        goto after_46;
    // 0x8080233C: nop

    after_46:
    // 0x80802340: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4EFC) << 16);
    // 0x80802344: lwc1        $f18, 0x4EFC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4EFC));
    // 0x80802348: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x8080234C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80802350: nop

    // 0x80802354: bc1fl       L_80802368
    if (!c1cs) {
        // 0x80802358: lw          $t0, 0x84($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X84);
            goto L_80802368;
    }
    goto skip_13;
    // 0x80802358: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    skip_13:
    // 0x8080235C: jal         0x80802614
    // 0x80802360: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_80802614_chstoneballcontrol(rdram, ctx);
        goto after_47;
    // 0x80802360: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_47:
L_80802364:
    // 0x80802364: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
L_80802368:
    // 0x80802368: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080236C: lwc1        $f6, 0x1C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80802370: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80802374: nop

    // 0x80802378: bc1fl       L_8080239C
    if (!c1cs) {
        // 0x8080237C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8080239C;
    }
    goto skip_14;
    // 0x8080237C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_14:
    // 0x80802380: jal         0x800D8FF8
    // 0x80802384: nop

    func_800D8FF8(rdram, ctx);
        goto after_48;
    // 0x80802384: nop

    after_48:
    // 0x80802388: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x8080238C: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80802390: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80802394: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    // 0x80802398: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8080239C:
    // 0x8080239C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808023A0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x808023A4: jr          $ra
    // 0x808023A8: nop

    return;
    // 0x808023A8: nop

;}
RECOMP_FUNC void func_80802B84_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B84: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80802B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802B8C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80802B90: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80802B94: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x80802B98: jal         0x80100094
    // 0x80802B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802BA0: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80802BA4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80802BA8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80802BAC: beq         $a2, $zero, L_80802BD4
    if (ctx->r6 == 0) {
        // 0x80802BB0: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80802BD4;
    }
    // 0x80802BB0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80802BB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802BB8: beq         $a2, $at, L_80802CD0
    if (ctx->r6 == ctx->r1) {
        // 0x80802BBC: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80802CD0;
    }
    // 0x80802BBC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80802BC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802BC4: beq         $a2, $at, L_80802D20
    if (ctx->r6 == ctx->r1) {
        // 0x80802BC8: lw          $t1, 0x48($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X48);
            goto L_80802D20;
    }
    // 0x80802BC8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80802BCC: b           L_80802DE8
    // 0x80802BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802DE8;
    // 0x80802BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802BD4:
    // 0x80802BD4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80802BD8: jal         0x8008A0E0
    // 0x80802BDC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80802BDC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80802BE0: bne         $v0, $zero, L_80802BF0
    if (ctx->r2 != 0) {
        // 0x80802BE4: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80802BF0;
    }
    // 0x80802BE4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80802BE8: jal         0x80103DFC
    // 0x80802BEC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80103DFC(rdram, ctx);
        goto after_2;
    // 0x80802BEC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
L_80802BF0:
    // 0x80802BF0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80802BF4: addiu       $a0, $zero, 0x422
    ctx->r4 = ADD32(0, 0X422);
    // 0x80802BF8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80802BFC: lwc1        $f4, 0x48($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X48);
    // 0x80802C00: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x80802C04: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80802C08: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80802C0C: jal         0x80108528
    // 0x80802C10: nop

    func_80108528(rdram, ctx);
        goto after_3;
    // 0x80802C10: nop

    after_3:
    // 0x80802C14: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80802C18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802C1C: addiu       $a0, $zero, 0x683
    ctx->r4 = ADD32(0, 0X683);
    // 0x80802C20: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    // 0x80802C24: jal         0x800DA298
    // 0x80802C28: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80802C28: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_4:
    // 0x80802C2C: beq         $v0, $zero, L_80802C5C
    if (ctx->r2 == 0) {
        // 0x80802C30: lw          $a2, 0x40($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X40);
            goto L_80802C5C;
    }
    // 0x80802C30: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80802C34: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80802C38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X38F8) << 16);
    // 0x80802C3C: lh          $t0, 0x8($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X8);
    // 0x80802C40: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x80802C44: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80802C48: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80802C4C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80802C50: lwc1        $f10, 0x38F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1240, 0X38F8));
    // 0x80802C54: b           L_80802C68
    // 0x80802C58: swc1        $f10, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f10.u32l;
        goto L_80802C68;
    // 0x80802C58: swc1        $f10, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f10.u32l;
L_80802C5C:
    // 0x80802C5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X388C) << 16);
    // 0x80802C60: lwc1        $f16, 0x388C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1240, 0X388C));
    // 0x80802C64: swc1        $f16, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f16.u32l;
L_80802C68:
    // 0x80802C68: addiu       $a0, $zero, 0x684
    ctx->r4 = ADD32(0, 0X684);
    // 0x80802C6C: jal         0x800DA298
    // 0x80802C70: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80802C70: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_5:
    // 0x80802C74: bne         $v0, $zero, L_80802CA4
    if (ctx->r2 != 0) {
        // 0x80802C78: lw          $a2, 0x40($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X40);
            goto L_80802CA4;
    }
    // 0x80802C78: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80802C7C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80802C80: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X38FC) << 16);
    // 0x80802C84: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x80802C88: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80802C8C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80802C90: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80802C94: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80802C98: lwc1        $f18, 0x38FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1240, 0X38FC));
    // 0x80802C9C: b           L_80802CB0
    // 0x80802CA0: swc1        $f18, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f18.u32l;
        goto L_80802CB0;
    // 0x80802CA0: swc1        $f18, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f18.u32l;
L_80802CA4:
    // 0x80802CA4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X3890) << 16);
    // 0x80802CA8: lwc1        $f4, 0x3890($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1240, 0X3890));
    // 0x80802CAC: swc1        $f4, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f4.u32l;
L_80802CB0:
    // 0x80802CB0: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80802CB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80802CB8: jal         0x80102FDC
    // 0x80802CBC: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_6;
    // 0x80802CBC: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    after_6:
    // 0x80802CC0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80802CC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802CC8: b           L_80802DE4
    // 0x80802CCC: sh          $t6, 0x6($t7)
    MEM_H(0X6, ctx->r15) = ctx->r14;
        goto L_80802DE4;
    // 0x80802CCC: sh          $t6, 0x6($t7)
    MEM_H(0X6, ctx->r15) = ctx->r14;
L_80802CD0:
    // 0x80802CD0: jal         0x80103DFC
    // 0x80802CD4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80103DFC(rdram, ctx);
        goto after_7;
    // 0x80802CD4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_7:
    // 0x80802CD8: addiu       $a0, $zero, 0x421
    ctx->r4 = ADD32(0, 0X421);
    // 0x80802CDC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80802CE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802CE4: jal         0x80108528
    // 0x80802CE8: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    func_80108528(rdram, ctx);
        goto after_8;
    // 0x80802CE8: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_8:
    // 0x80802CEC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80802CF0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X3894) << 16);
    // 0x80802CF4: lwc1        $f8, 0x3894($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1240, 0X3894));
    // 0x80802CF8: lwc1        $f6, 0x38($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X38);
    // 0x80802CFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802D00: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802D04: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80802D08: jal         0x80102FDC
    // 0x80802D0C: nop

    func_80102FDC(rdram, ctx);
        goto after_9;
    // 0x80802D0C: nop

    after_9:
    // 0x80802D10: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80802D14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80802D18: b           L_80802DE4
    // 0x80802D1C: sh          $t9, 0x44($t0)
    MEM_H(0X44, ctx->r8) = ctx->r25;
        goto L_80802DE4;
    // 0x80802D1C: sh          $t9, 0x44($t0)
    MEM_H(0X44, ctx->r8) = ctx->r25;
L_80802D20:
    // 0x80802D20: lhu         $t2, 0x72($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X72);
    // 0x80802D24: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80802D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802D2C: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80802D30: beq         $t3, $at, L_80802D48
    if (ctx->r11 == ctx->r1) {
        // 0x80802D34: addiu       $a0, $zero, 0x41E
        ctx->r4 = ADD32(0, 0X41E);
            goto L_80802D48;
    }
    // 0x80802D34: addiu       $a0, $zero, 0x41E
    ctx->r4 = ADD32(0, 0X41E);
    // 0x80802D38: jal         0x8010A800
    // 0x80802D3C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_8010A800(rdram, ctx);
        goto after_10;
    // 0x80802D3C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_10:
    // 0x80802D40: b           L_80802DE8
    // 0x80802D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802DE8;
    // 0x80802D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802D48:
    // 0x80802D48: jal         0x801084B0
    // 0x80802D4C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_801084B0(rdram, ctx);
        goto after_11;
    // 0x80802D4C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_11:
    // 0x80802D50: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x80802D54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802D58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802D5C: srl         $t5, $t4, 25
    ctx->r13 = S32(U32(ctx->r12) >> 25);
    // 0x80802D60: bne         $t5, $zero, L_80802D88
    if (ctx->r13 != 0) {
        // 0x80802D64: nop
    
            goto L_80802D88;
    }
    // 0x80802D64: nop

    // 0x80802D68: jal         0x800FFAB0
    // 0x80802D6C: nop

    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x80802D6C: nop

    after_12:
    // 0x80802D70: addiu       $a0, $zero, 0x41E
    ctx->r4 = ADD32(0, 0X41E);
    // 0x80802D74: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80802D78: jal         0x80101180
    // 0x80802D7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_13;
    // 0x80802D7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80802D80: b           L_80802DE8
    // 0x80802D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802DE8;
    // 0x80802D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802D88:
    // 0x80802D88: jal         0x80100094
    // 0x80802D8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_14;
    // 0x80802D8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_14:
    // 0x80802D90: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80802D94: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802D98: lh          $t6, 0x1E($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1E);
    // 0x80802D9C: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80802DA0: sh          $t7, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r15;
    // 0x80802DA4: sh          $t8, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r24;
    // 0x80802DA8: jal         0x80100120
    // 0x80802DAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80100120(rdram, ctx);
        goto after_15;
    // 0x80802DAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_15:
    // 0x80802DB0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80802DB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802DB8: jal         0x80102FDC
    // 0x80802DBC: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_16;
    // 0x80802DBC: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    after_16:
    // 0x80802DC0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80802DC4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80802DC8: lh          $t2, 0x1E($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X1E);
    // 0x80802DCC: bne         $t2, $zero, L_80802DDC
    if (ctx->r10 != 0) {
        // 0x80802DD0: nop
    
            goto L_80802DDC;
    }
    // 0x80802DD0: nop

    // 0x80802DD4: b           L_80802DDC
    // 0x80802DD8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
        goto L_80802DDC;
    // 0x80802DD8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
L_80802DDC:
    // 0x80802DDC: jal         0x80801964
    // 0x80802DE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80801964_chklungo(rdram, ctx);
        goto after_17;
    // 0x80802DE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_17:
L_80802DE4:
    // 0x80802DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802DE8:
    // 0x80802DE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80802DEC: jr          $ra
    // 0x80802DF0: nop

    return;
    // 0x80802DF0: nop

;}
RECOMP_FUNC void func_800F52E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F52E4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F52E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F52EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F52F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F52F4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F52F8: jal         0x8008F4F0
    // 0x800F52FC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008F4F0(rdram, ctx);
        goto after_0;
    // 0x800F52FC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5308: jr          $ra
    // 0x800F530C: nop

    return;
    // 0x800F530C: nop

;}
RECOMP_FUNC void _cheggproximity_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873D8: syscall     563
    recomp_syscall_handler(rdram, ctx, 0x800873D8);
    return;
    // 0x800873DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chgameselect_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021D8: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(804, 0X82E0) << 16);
    // 0x808021DC: jr          $ra
    // 0x808021E0: addiu       $v0, $v0, -0x7D20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X82E0));
    return;
    // 0x808021E0: addiu       $v0, $v0, -0x7D20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X82E0));
;}
RECOMP_FUNC void vector_begin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B28C4: jr          $ra
    // 0x800B28C8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    return;
    // 0x800B28C8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
;}
RECOMP_FUNC void mlAbsF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2100: jr          $ra
    // 0x800F2104: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    return;
    // 0x800F2104: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
;}
RECOMP_FUNC void func_80800698_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800698: lb          $t6, 0x211($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X211);
    // 0x8080069C: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x808006A0: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x808006A4: beq         $at, $zero, L_808006C8
    if (ctx->r1 == 0) {
        // 0x808006A8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808006C8;
    }
    // 0x808006A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808006AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3094, 0X29C0) << 16);
    // 0x808006B0: addu        $at, $at, $t7
    gpr jr_addend_808006B8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808006B4: lw          $t7, 0x29C0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3094, 0X29C0));
    // 0x808006B8: jr          $t7
    // 0x808006BC: nop

    switch (jr_addend_808006B8 >> 2) {
        case 0: goto L_808006C0; break;
        case 1: goto L_808006C8; break;
        case 2: goto L_808006C0; break;
        case 3: goto L_808006C0; break;
        case 4: goto L_808006C0; break;
        case 5: goto L_808006C8; break;
        case 6: goto L_808006C0; break;
        case 7: goto L_808006C0; break;
        default: switch_error(__func__, 0x808006B8, 0x808029C0);
    }
    // 0x808006BC: nop

L_808006C0:
    // 0x808006C0: jr          $ra
    // 0x808006C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808006C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006C8:
    // 0x808006C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808006CC: jr          $ra
    // 0x808006D0: nop

    return;
    // 0x808006D0: nop

;}
RECOMP_FUNC void func_80800A24_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A28: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A2C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A30: jal         0x808001FC
    // 0x80800A34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001FC_bsstatue(rdram, ctx);
        goto after_0;
    // 0x80800A34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800A40: jal         0x8009E55C
    // 0x80800A44: lui         $a2, 0x42DC
    ctx->r6 = S32(0X42DC << 16);
    func_8009E55C(rdram, ctx);
        goto after_1;
    // 0x80800A44: lui         $a2, 0x42DC
    ctx->r6 = S32(0X42DC << 16);
    after_1:
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800A50: jal         0x8009E5A4
    // 0x80800A54: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8009E5A4(rdram, ctx);
        goto after_2;
    // 0x80800A54: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80800A58: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80800A5C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A64: jal         0x8008CCBC
    // 0x80800A68: addiu       $a1, $zero, 0x1F0
    ctx->r5 = ADD32(0, 0X1F0);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_3;
    // 0x80800A68: addiu       $a1, $zero, 0x1F0
    ctx->r5 = ADD32(0, 0X1F0);
    after_3:
    // 0x80800A6C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800A70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800A80: jal         0x8009FFD8
    // 0x80800A84: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_4;
    // 0x80800A84: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_4:
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A8C: jal         0x8009B9B0
    // 0x80800A90: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x80800A90: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800A94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800A98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800AA0: jr          $ra
    // 0x80800AA4: nop

    return;
    // 0x80800AA4: nop

;}
RECOMP_FUNC void ncbadolly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x80800014: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080001C: jal         0x801124D0
    // 0x80800020: sb          $t6, 0x21($t7)
    MEM_B(0X21, ctx->r15) = ctx->r14;
    func_801124D0(rdram, ctx);
        goto after_0;
    // 0x80800020: sb          $t6, 0x21($t7)
    MEM_B(0X21, ctx->r15) = ctx->r14;
    after_0:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void func_80800AEC_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800AF8: jal         0x800DA298
    // 0x80800AFC: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800AFC: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x80800B00: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800B04: bne         $a1, $zero, L_80800B18
    if (ctx->r5 != 0) {
        // 0x80800B08: nop
    
            goto L_80800B18;
    }
    // 0x80800B08: nop

    // 0x80800B0C: jal         0x80088848
    // 0x80800B10: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800B10: nop

    after_1:
    // 0x80800B14: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
L_80800B18:
    // 0x80800B18: jal         0x800EA05C
    // 0x80800B1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80800B1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800B20: addiu       $at, $zero, 0xED
    ctx->r1 = ADD32(0, 0XED);
    // 0x80800B24: beq         $v0, $at, L_80800B40
    if (ctx->r2 == ctx->r1) {
        // 0x80800B28: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B40;
    }
    // 0x80800B28: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B2C: addiu       $at, $zero, 0xF8
    ctx->r1 = ADD32(0, 0XF8);
    // 0x80800B30: beq         $v0, $at, L_80800B80
    if (ctx->r2 == ctx->r1) {
        // 0x80800B34: nop
    
            goto L_80800B80;
    }
    // 0x80800B34: nop

    // 0x80800B38: b           L_80800B94
    // 0x80800B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B94;
    // 0x80800B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B40:
    // 0x80800B40: bne         $v1, $zero, L_80800B58
    if (ctx->r3 != 0) {
        // 0x80800B44: nop
    
            goto L_80800B58;
    }
    // 0x80800B44: nop

    // 0x80800B48: jal         0x800FFAB0
    // 0x80800B4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800B4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800B50: b           L_80800B94
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B94;
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B58:
    // 0x80800B58: jal         0x80088848
    // 0x80800B5C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800B5C: nop

    after_4:
    // 0x80800B60: beq         $v0, $zero, L_80800B70
    if (ctx->r2 == 0) {
        // 0x80800B64: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80800B70;
    }
    // 0x80800B64: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800B68: b           L_80800B70
    // 0x80800B6C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
        goto L_80800B70;
    // 0x80800B6C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_80800B70:
    // 0x80800B70: jal         0x80102424
    // 0x80800B74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800B74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800B78: b           L_80800B94
    // 0x80800B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B94;
    // 0x80800B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B80:
    // 0x80800B80: beql        $v1, $zero, L_80800B94
    if (ctx->r3 == 0) {
        // 0x80800B84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B94;
    }
    goto skip_0;
    // 0x80800B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800B88: jal         0x800FFAB0
    // 0x80800B8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800B8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B94:
    // 0x80800B94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B98: jr          $ra
    // 0x80800B9C: nop

    return;
    // 0x80800B9C: nop

;}
RECOMP_FUNC void ncbafly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080000C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800010: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800014: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80800024: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800028: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x8080002C: jal         0x80111590
    // 0x80800030: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80111590(rdram, ctx);
        goto after_0;
    // 0x80800030: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x8080003C: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x80800040: jal         0x8080023C
    // 0x80800044: lui         $a3, 0x43AF
    ctx->r7 = S32(0X43AF << 16);
    ncbafly_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800044: lui         $a3, 0x43AF
    ctx->r7 = S32(0X43AF << 16);
    after_1:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x80800250
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ncbafly_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x8080005C: jal         0x80111B8C
    // 0x80800060: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_3;
    // 0x80800060: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_3:
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: jal         0x80115858
    // 0x8080006C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80115858(rdram, ctx);
        goto after_4;
    // 0x8080006C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: jal         0x80115870
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80115870(rdram, ctx);
        goto after_5;
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: jal         0x801124D0
    // 0x80800084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_6;
    // 0x80800084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800088: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080008C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800090: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_80800B74_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800B78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B7C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B80: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800B84: lbu         $v0, 0x60($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X60);
    // 0x80800B88: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800B8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800B94: beq         $v0, $at, L_80800BD0
    if (ctx->r2 == ctx->r1) {
        // 0x80800B98: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80800BD0;
    }
    // 0x80800B98: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800B9C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800BA0: beq         $v0, $at, L_80800BD0
    if (ctx->r2 == ctx->r1) {
        // 0x80800BA4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800BD0;
    }
    // 0x80800BA4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800BA8: bne         $v0, $at, L_80800BEC
    if (ctx->r2 != ctx->r1) {
        // 0x80800BAC: nop
    
            goto L_80800BEC;
    }
    // 0x80800BAC: nop

    // 0x80800BB0: lh          $a0, 0x2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2);
    // 0x80800BB4: jal         0x8001B798
    // 0x80800BB8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80800BB8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800BBC: jal         0x80089E30
    // 0x80800BC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _susplinet_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800BC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800BC4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800BC8: b           L_80800BEC
    // 0x80800BCC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80800BEC;
    // 0x80800BCC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800BD0:
    // 0x80800BD0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80800BD4: jal         0x8001B798
    // 0x80800BD8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x80800BD8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800BDC: jal         0x80089D80
    // 0x80800BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suspline_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800BE4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800BE8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800BEC:
    // 0x80800BEC: beql        $v1, $zero, L_80800CA4
    if (ctx->r3 == 0) {
        // 0x80800BF0: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80800CA4;
    }
    goto skip_0;
    // 0x80800BF0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    skip_0:
    // 0x80800BF4: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x80800BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BFC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800C00: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x80800C04: beq         $t7, $zero, L_80800C50
    if (ctx->r15 == 0) {
        // 0x80800C08: nop
    
            goto L_80800C50;
    }
    // 0x80800C08: nop

    // 0x80800C0C: jal         0x8080145C
    // 0x80800C10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8080145C_ncpoducam(rdram, ctx);
        goto after_4;
    // 0x80800C10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x80800C14: jal         0x80110024
    // 0x80800C18: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80110024(rdram, ctx);
        goto after_5;
    // 0x80800C18: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x80800C1C: lh          $a3, 0x58($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X58);
    // 0x80800C20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800C24: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800C28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800C2C: jal         0x800894E8
    // 0x80800C30: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    _ncpod_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80800C30: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_6:
    // 0x80800C34: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800C38: bne         $v0, $at, L_80800C48
    if (ctx->r2 != ctx->r1) {
        // 0x80800C3C: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80800C48;
    }
    // 0x80800C3C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800C40: b           L_80800CA4
    // 0x80800C44: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_80800CA4;
    // 0x80800C44: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80800C48:
    // 0x80800C48: b           L_80800CA0
    // 0x80800C4C: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
        goto L_80800CA0;
    // 0x80800C4C: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
L_80800C50:
    // 0x80800C50: jal         0x80110024
    // 0x80800C54: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80110024(rdram, ctx);
        goto after_7;
    // 0x80800C54: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800C58: lh          $a3, 0x58($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X58);
    // 0x80800C5C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800C60: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800C64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800C68: jal         0x800894E8
    // 0x80800C6C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    _ncpod_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x80800C6C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_8:
    // 0x80800C70: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800C74: bne         $v0, $at, L_80800C84
    if (ctx->r2 != ctx->r1) {
        // 0x80800C78: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80800C84;
    }
    // 0x80800C78: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800C7C: b           L_80800CA8
    // 0x80800C80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800CA8;
    // 0x80800C80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C84:
    // 0x80800C84: sw          $a3, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r7;
    // 0x80800C88: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80800C8C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C94: jal         0x8080145C
    // 0x80800C98: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8080145C_ncpoducam(rdram, ctx);
        goto after_9;
    // 0x80800C98: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_9:
    // 0x80800C9C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
L_80800CA0:
    // 0x80800CA0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80800CA4:
    // 0x80800CA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CA8:
    // 0x80800CA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800CAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800CB0: jr          $ra
    // 0x80800CB4: nop

    return;
    // 0x80800CB4: nop

;}
RECOMP_FUNC void _bamovespline_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084EA8: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084EA8);
    return;
    // 0x80084EAC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800A05DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A05DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A05E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A05E4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A05E8: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x800A05EC: sh          $zero, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = 0;
    // 0x800A05F0: jal         0x800F9110
    // 0x800A05F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F9110(rdram, ctx);
        goto after_0;
    // 0x800A05F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A05F8: jal         0x800A9C98
    // 0x800A05FC: nop

    func_800A9C98(rdram, ctx);
        goto after_1;
    // 0x800A05FC: nop

    after_1:
    // 0x800A0600: beq         $v0, $zero, L_800A0618
    if (ctx->r2 == 0) {
        // 0x800A0604: nop
    
            goto L_800A0618;
    }
    // 0x800A0604: nop

    // 0x800A0608: jal         0x800A9CDC
    // 0x800A060C: nop

    func_800A9CDC(rdram, ctx);
        goto after_2;
    // 0x800A060C: nop

    after_2:
    // 0x800A0610: b           L_800A06D0
    // 0x800A0614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A06D0;
    // 0x800A0614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A0618:
    // 0x800A0618: jal         0x8008E23C
    // 0x800A061C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8008E23C(rdram, ctx);
        goto after_3;
    // 0x800A061C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800A0620: beql        $v0, $zero, L_800A068C
    if (ctx->r2 == 0) {
        // 0x800A0624: lh          $t7, 0x2E($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X2E);
            goto L_800A068C;
    }
    goto skip_0;
    // 0x800A0624: lh          $t7, 0x2E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2E);
    skip_0:
    // 0x800A0628: jal         0x800F8F3C
    // 0x800A062C: nop

    func_800F8F3C(rdram, ctx);
        goto after_4;
    // 0x800A062C: nop

    after_4:
    // 0x800A0630: jal         0x800F8DA8
    // 0x800A0634: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800F8DA8(rdram, ctx);
        goto after_5;
    // 0x800A0634: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_5:
    // 0x800A0638: beq         $v0, $zero, L_800A0648
    if (ctx->r2 == 0) {
        // 0x800A063C: addiu       $a1, $sp, 0x1C
        ctx->r5 = ADD32(ctx->r29, 0X1C);
            goto L_800A0648;
    }
    // 0x800A063C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800A0640: b           L_800A064C
    // 0x800A0644: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
        goto L_800A064C;
    // 0x800A0644: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_800A0648:
    // 0x800A0648: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
L_800A064C:
    // 0x800A064C: jal         0x800F89E4
    // 0x800A0650: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F89E4(rdram, ctx);
        goto after_6;
    // 0x800A0650: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_6:
    // 0x800A0654: jal         0x800EA05C
    // 0x800A0658: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_7;
    // 0x800A0658: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    after_7:
    // 0x800A065C: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x800A0660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A0664: beq         $v0, $t6, L_800A067C
    if (ctx->r2 == ctx->r14) {
        // 0x800A0668: nop
    
            goto L_800A067C;
    }
    // 0x800A0668: nop

    // 0x800A066C: jal         0x800F8A80
    // 0x800A0670: nop

    func_800F8A80(rdram, ctx);
        goto after_8;
    // 0x800A0670: nop

    after_8:
    // 0x800A0674: b           L_800A0688
    // 0x800A0678: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
        goto L_800A0688;
    // 0x800A0678: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
L_800A067C:
    // 0x800A067C: jal         0x800EA090
    // 0x800A0680: nop

    func_800EA090(rdram, ctx);
        goto after_9;
    // 0x800A0680: nop

    after_9:
    // 0x800A0684: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
L_800A0688:
    // 0x800A0688: lh          $t7, 0x2E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2E);
L_800A068C:
    // 0x800A068C: beq         $t7, $zero, L_800A069C
    if (ctx->r15 == 0) {
        // 0x800A0690: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800A069C;
    }
    // 0x800A0690: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A0694: jal         0x8009EB24
    // 0x800A0698: lh          $a1, 0x2C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2C);
    func_8009EB24(rdram, ctx);
        goto after_10;
    // 0x800A0698: lh          $a1, 0x2C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2C);
    after_10:
L_800A069C:
    // 0x800A069C: addiu       $a0, $sp, 0x2A
    ctx->r4 = ADD32(ctx->r29, 0X2A);
    // 0x800A06A0: jal         0x8009EC08
    // 0x800A06A4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009EC08(rdram, ctx);
        goto after_11;
    // 0x800A06A4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_11:
    // 0x800A06A8: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x800A06AC: beql        $t8, $zero, L_800A06C0
    if (ctx->r24 == 0) {
        // 0x800A06B0: lh          $a0, 0x2A($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X2A);
            goto L_800A06C0;
    }
    goto skip_1;
    // 0x800A06B0: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    skip_1:
    // 0x800A06B4: jal         0x8009EBD0
    // 0x800A06B8: nop

    func_8009EBD0(rdram, ctx);
        goto after_12;
    // 0x800A06B8: nop

    after_12:
    // 0x800A06BC: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
L_800A06C0:
    // 0x800A06C0: lh          $a1, 0x28($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X28);
    // 0x800A06C4: jal         0x800A794C
    // 0x800A06C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A794C(rdram, ctx);
        goto after_13;
    // 0x800A06C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x800A06CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A06D0:
    // 0x800A06D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A06D4: jr          $ra
    // 0x800A06D8: nop

    return;
    // 0x800A06D8: nop

    // 0x800A06DC: nop

;}
RECOMP_FUNC void _glhittableDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088648: syscall     696
    recomp_syscall_handler(rdram, ctx, 0x80088648);
    return;
    // 0x8008864C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800A5C_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A64: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A68: jal         0x80800EB0
    // 0x80800A6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800EB0_chhoney(rdram, ctx);
        goto after_0;
    // 0x80800A6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800A70: lw          $a0, 0x78($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X78);
    // 0x80800A74: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x80800A78: sll         $t6, $a0, 28
    ctx->r14 = S32(ctx->r4 << 28);
    // 0x80800A7C: sll         $t8, $v1, 11
    ctx->r24 = S32(ctx->r3 << 11);
    // 0x80800A80: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80800A84: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80800A88: beq         $t7, $t9, L_80800B00
    if (ctx->r15 == ctx->r25) {
        // 0x80800A8C: nop
    
            goto L_80800B00;
    }
    // 0x80800A8C: nop

    // 0x80800A90: beq         $t7, $zero, L_80800ABC
    if (ctx->r15 == 0) {
        // 0x80800A94: sll         $t3, $v1, 12
        ctx->r11 = S32(ctx->r3 << 12);
            goto L_80800ABC;
    }
    // 0x80800A94: sll         $t3, $v1, 12
    ctx->r11 = S32(ctx->r3 << 12);
    // 0x80800A98: sll         $t1, $v1, 12
    ctx->r9 = S32(ctx->r3 << 12);
    // 0x80800A9C: bgez        $t1, L_80800AAC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800AA0: nop
    
            goto L_80800AAC;
    }
    // 0x80800AA0: nop

    // 0x80800AA4: jal         0x8010DCB4
    // 0x80800AA8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8010DCB4(rdram, ctx);
        goto after_1;
    // 0x80800AA8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
L_80800AAC:
    // 0x80800AAC: jal         0x8010DC50
    // 0x80800AB0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8010DC50(rdram, ctx);
        goto after_2;
    // 0x80800AB0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80800AB4: b           L_80800AD8
    // 0x80800AB8: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
        goto L_80800AD8;
    // 0x80800AB8: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
L_80800ABC:
    // 0x80800ABC: bgez        $t3, L_80800ACC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800AC0: nop
    
            goto L_80800ACC;
    }
    // 0x80800AC0: nop

    // 0x80800AC4: jal         0x8010DCB4
    // 0x80800AC8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8010DCB4(rdram, ctx);
        goto after_3;
    // 0x80800AC8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
L_80800ACC:
    // 0x80800ACC: jal         0x8010DC50
    // 0x80800AD0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8010DC50(rdram, ctx);
        goto after_4;
    // 0x80800AD0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x80800AD4: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
L_80800AD8:
    // 0x80800AD8: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800ADC: sll         $t5, $t4, 28
    ctx->r13 = S32(ctx->r12 << 28);
    // 0x80800AE0: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x80800AE4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800AE8: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80800AEC: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800AF0: or          $t3, $t8, $t0
    ctx->r11 = ctx->r24 | ctx->r8;
    // 0x80800AF4: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80800AF8: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x80800AFC: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_80800B00:
    // 0x80800B00: jal         0x800D8FF8
    // 0x80800B04: nop

    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x80800B04: nop

    after_5:
    // 0x80800B08: jal         0x8008FC28
    // 0x80800B0C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_8008FC28(rdram, ctx);
        goto after_6;
    // 0x80800B0C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80800B10: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800B14: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
    // 0x80800B18: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x80800B1C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800B20: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80800B24: beq         $at, $zero, L_80800E9C
    if (ctx->r1 == 0) {
        // 0x80800B28: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800E9C;
    }
    // 0x80800B28: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800B2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFF0) << 16);
    // 0x80800B30: addu        $at, $at, $t7
    gpr jr_addend_80800B38 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800B34: lw          $t7, 0xFF0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFF0));
    // 0x80800B38: jr          $t7
    // 0x80800B3C: nop

    switch (jr_addend_80800B38 >> 2) {
        case 0: goto L_80800B40; break;
        case 1: goto L_80800BC4; break;
        case 2: goto L_80800C44; break;
        case 3: goto L_80800DE4; break;
        case 4: goto L_80800CB0; break;
        case 5: goto L_80800D6C; break;
        case 6: goto L_80800BB4; break;
        case 7: goto L_80800C34; break;
        default: switch_error(__func__, 0x80800B38, 0x80800FF0);
    }
    // 0x80800B3C: nop

L_80800B40:
    // 0x80800B40: bne         $v0, $zero, L_80800B58
    if (ctx->r2 != 0) {
        // 0x80800B44: nop
    
            goto L_80800B58;
    }
    // 0x80800B44: nop

    // 0x80800B48: jal         0x8010A570
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800B50: b           L_80800B64
    // 0x80800B54: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
        goto L_80800B64;
    // 0x80800B54: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_80800B58:
    // 0x80800B58: jal         0x8010A590
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_8;
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800B60: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_80800B64:
    // 0x80800B64: addiu       $at, $zero, 0x22B
    ctx->r1 = ADD32(0, 0X22B);
    // 0x80800B68: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800B6C: lw          $v0, 0x24($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X24);
    // 0x80800B70: srl         $t8, $v0, 22
    ctx->r24 = S32(U32(ctx->r2) >> 22);
    // 0x80800B74: beq         $t8, $at, L_80800B84
    if (ctx->r24 == ctx->r1) {
        // 0x80800B78: addiu       $at, $zero, 0x22C
        ctx->r1 = ADD32(0, 0X22C);
            goto L_80800B84;
    }
    // 0x80800B78: addiu       $at, $zero, 0x22C
    ctx->r1 = ADD32(0, 0X22C);
    // 0x80800B7C: bne         $t8, $at, L_80800BA4
    if (ctx->r24 != ctx->r1) {
        // 0x80800B80: nop
    
            goto L_80800BA4;
    }
    // 0x80800B80: nop

L_80800B84:
    // 0x80800B84: jal         0x8010CAC0
    // 0x80800B88: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8010CAC0(rdram, ctx);
        goto after_9;
    // 0x80800B88: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_9:
    // 0x80800B8C: beq         $v0, $zero, L_80800BA4
    if (ctx->r2 == 0) {
        // 0x80800B90: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_80800BA4;
    }
    // 0x80800B90: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80800B94: beq         $t0, $zero, L_80800BA4
    if (ctx->r8 == 0) {
        // 0x80800B98: nop
    
            goto L_80800BA4;
    }
    // 0x80800B98: nop

    // 0x80800B9C: jal         0x8008FBE0
    // 0x80800BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FBE0(rdram, ctx);
        goto after_10;
    // 0x80800BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
L_80800BA4:
    // 0x80800BA4: jal         0x80800754
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800754_chhoney(rdram, ctx);
        goto after_11;
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800BAC: b           L_80800EA0
    // 0x80800BB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800EA0;
    // 0x80800BB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BB4:
    // 0x80800BB4: jal         0x8008FBE0
    // 0x80800BB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FBE0(rdram, ctx);
        goto after_12;
    // 0x80800BB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80800BBC: b           L_80800EA0
    // 0x80800BC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800EA0;
    // 0x80800BC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BC4:
    // 0x80800BC4: jal         0x8008FBE0
    // 0x80800BC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FBE0(rdram, ctx);
        goto after_13;
    // 0x80800BC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BD0: jal         0x808008F8
    // 0x80800BD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808008F8_chhoney(rdram, ctx);
        goto after_14;
    // 0x80800BD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800BD8: jal         0x80090080
    // 0x80800BDC: nop

    func_80090080(rdram, ctx);
        goto after_15;
    // 0x80800BDC: nop

    after_15:
    // 0x80800BE0: beq         $v0, $zero, L_80800C14
    if (ctx->r2 == 0) {
        // 0x80800BE4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800C14;
    }
    // 0x80800BE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800BE8: jal         0x80016B30
    // 0x80800BEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_16;
    // 0x80800BEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800BF0: beq         $v0, $zero, L_80800C14
    if (ctx->r2 == 0) {
        // 0x80800BF4: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_80800C14;
    }
    // 0x80800BF4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800BF8: jal         0x800CE88C
    // 0x80800BFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_17;
    // 0x80800BFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C04: jal         0x808000C4
    // 0x80800C08: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808000C4_chhoney(rdram, ctx);
        goto after_18;
    // 0x80800C08: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_18:
    // 0x80800C0C: b           L_80800EA0
    // 0x80800C10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800EA0;
    // 0x80800C10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C14:
    // 0x80800C14: jal         0x800CEAD0
    // 0x80800C18: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800CEAD0(rdram, ctx);
        goto after_19;
    // 0x80800C18: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_19:
    // 0x80800C1C: beq         $v0, $zero, L_80800E9C
    if (ctx->r2 == 0) {
        // 0x80800C20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E9C;
    }
    // 0x80800C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C24: jal         0x808000C4
    // 0x80800C28: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808000C4_chhoney(rdram, ctx);
        goto after_20;
    // 0x80800C28: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_20:
    // 0x80800C2C: b           L_80800EA0
    // 0x80800C30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800EA0;
    // 0x80800C30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C34:
    // 0x80800C34: jal         0x8008FBE0
    // 0x80800C38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FBE0(rdram, ctx);
        goto after_21;
    // 0x80800C38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_21:
    // 0x80800C3C: b           L_80800EA0
    // 0x80800C40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800EA0;
    // 0x80800C40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C44:
    // 0x80800C44: jal         0x8008FBE0
    // 0x80800C48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FBE0(rdram, ctx);
        goto after_22;
    // 0x80800C48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_22:
    // 0x80800C4C: jal         0x808009BC
    // 0x80800C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009BC_chhoney(rdram, ctx);
        goto after_23;
    // 0x80800C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800C54: jal         0x80090080
    // 0x80800C58: nop

    func_80090080(rdram, ctx);
        goto after_24;
    // 0x80800C58: nop

    after_24:
    // 0x80800C5C: beq         $v0, $zero, L_80800C90
    if (ctx->r2 == 0) {
        // 0x80800C60: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800C90;
    }
    // 0x80800C60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800C64: jal         0x80016B30
    // 0x80800C68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_25;
    // 0x80800C68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80800C6C: beq         $v0, $zero, L_80800C90
    if (ctx->r2 == 0) {
        // 0x80800C70: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_80800C90;
    }
    // 0x80800C70: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800C74: jal         0x800CE88C
    // 0x80800C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_26;
    // 0x80800C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80800C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C80: jal         0x808000C4
    // 0x80800C84: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808000C4_chhoney(rdram, ctx);
        goto after_27;
    // 0x80800C84: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_27:
    // 0x80800C88: b           L_80800EA0
    // 0x80800C8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800EA0;
    // 0x80800C8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C90:
    // 0x80800C90: jal         0x800CEAD0
    // 0x80800C94: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800CEAD0(rdram, ctx);
        goto after_28;
    // 0x80800C94: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_28:
    // 0x80800C98: beq         $v0, $zero, L_80800E9C
    if (ctx->r2 == 0) {
        // 0x80800C9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E9C;
    }
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA0: jal         0x808000C4
    // 0x80800CA4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808000C4_chhoney(rdram, ctx);
        goto after_29;
    // 0x80800CA4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_29:
    // 0x80800CA8: b           L_80800EA0
    // 0x80800CAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800EA0;
    // 0x80800CAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CB0:
    // 0x80800CB0: jal         0x8008FBE0
    // 0x80800CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FBE0(rdram, ctx);
        goto after_30;
    // 0x80800CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_30:
    // 0x80800CB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800CBC: jal         0x800FA9F4
    // 0x80800CC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800FA9F4(rdram, ctx);
        goto after_31;
    // 0x80800CC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x80800CC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800CC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800CCC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800CD0: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800CD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0X1010) << 16);
    // 0x80800CD8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800CDC: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800CE0: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80800CE4: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800CE8: lwc1        $f18, 0x1010($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0X1010));
    // 0x80800CEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800CF0: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800CF4: nop

    // 0x80800CF8: bc1f        L_80800D4C
    if (!c1cs) {
        // 0x80800CFC: nop
    
            goto L_80800D4C;
    }
    // 0x80800CFC: nop

    // 0x80800D00: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800D04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800D08: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800D0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800D10: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800D14: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D1C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80800D20: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800D24: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800D28: nop

    // 0x80800D2C: bc1f        L_80800D44
    if (!c1cs) {
        // 0x80800D30: nop
    
            goto L_80800D44;
    }
    // 0x80800D30: nop

    // 0x80800D34: jal         0x808000C4
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C4_chhoney(rdram, ctx);
        goto after_32;
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800D3C: b           L_80800D4C
    // 0x80800D40: nop

        goto L_80800D4C;
    // 0x80800D40: nop

L_80800D44:
    // 0x80800D44: jal         0x808000C4
    // 0x80800D48: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808000C4_chhoney(rdram, ctx);
        goto after_33;
    // 0x80800D48: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_33:
L_80800D4C:
    // 0x80800D4C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1668, 0X1038) << 16);
    // 0x80800D50: addiu       $a3, $a3, 0x1038
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1668, 0X1038));
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D58: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800D5C: jal         0x80089D50
    // 0x80800D60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_34;
    // 0x80800D60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_34:
    // 0x80800D64: b           L_80800EA0
    // 0x80800D68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800EA0;
    // 0x80800D68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D6C:
    // 0x80800D6C: jal         0x8008FBE0
    // 0x80800D70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FBE0(rdram, ctx);
        goto after_35;
    // 0x80800D70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x80800D74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D78: jal         0x800FA9F4
    // 0x80800D7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800FA9F4(rdram, ctx);
        goto after_36;
    // 0x80800D7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_36:
    // 0x80800D80: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800D84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800D88: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800D8C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800D90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0X1014) << 16);
    // 0x80800D94: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D9C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800DA0: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80800DA4: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800DA8: lwc1        $f18, 0x1014($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0X1014));
    // 0x80800DAC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800DB0: nop

    // 0x80800DB4: bc1f        L_80800DC4
    if (!c1cs) {
        // 0x80800DB8: nop
    
            goto L_80800DC4;
    }
    // 0x80800DB8: nop

    // 0x80800DBC: jal         0x808000C4
    // 0x80800DC0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808000C4_chhoney(rdram, ctx);
        goto after_37;
    // 0x80800DC0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_37:
L_80800DC4:
    // 0x80800DC4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1668, 0X1038) << 16);
    // 0x80800DC8: addiu       $a3, $a3, 0x1038
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1668, 0X1038));
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800DD4: jal         0x80089D50
    // 0x80800DD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_38;
    // 0x80800DD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_38:
    // 0x80800DDC: b           L_80800EA0
    // 0x80800DE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800EA0;
    // 0x80800DE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800DE4:
    // 0x80800DE4: jal         0x8008FBE0
    // 0x80800DE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FBE0(rdram, ctx);
        goto after_39;
    // 0x80800DE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_39:
    // 0x80800DEC: jal         0x800D8FF8
    // 0x80800DF0: nop

    func_800D8FF8(rdram, ctx);
        goto after_40;
    // 0x80800DF0: nop

    after_40:
    // 0x80800DF4: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800DF8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800DFC: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80800E00: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x80800E04: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800E08: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80800E0C: nop

    // 0x80800E10: bc1fl       L_80800EA0
    if (!c1cs) {
        // 0x80800E14: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800EA0;
    }
    goto skip_0;
    // 0x80800E14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800E18: jal         0x8008FC00
    // 0x80800E1C: nop

    func_8008FC00(rdram, ctx);
        goto after_41;
    // 0x80800E1C: nop

    after_41:
    // 0x80800E20: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0X1018) << 16);
    // 0x80800E24: lwc1        $f18, 0x1018($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0X1018));
    // 0x80800E28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E2C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800E30: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80800E34: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800E38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E3C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80800E40: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800E44: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x80800E48: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80800E4C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800E50: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x80800E54: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800E58: jal         0x800F10B4
    // 0x80800E5C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_42;
    // 0x80800E5C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_42:
    // 0x80800E60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800E64: addiu       $a0, $zero, 0x66C
    ctx->r4 = ADD32(0, 0X66C);
    // 0x80800E68: jal         0x800C3FC0
    // 0x80800E6C: addiu       $a2, $zero, 0x3E80
    ctx->r6 = ADD32(0, 0X3E80);
    func_800C3FC0(rdram, ctx);
        goto after_43;
    // 0x80800E6C: addiu       $a2, $zero, 0x3E80
    ctx->r6 = ADD32(0, 0X3E80);
    after_43:
    // 0x80800E70: jal         0x8008FC70
    // 0x80800E74: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008FC70(rdram, ctx);
        goto after_44;
    // 0x80800E74: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_44:
    // 0x80800E78: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
    // 0x80800E7C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E80: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x80800E84: bnel        $t1, $t3, L_80800EA0
    if (ctx->r9 != ctx->r11) {
        // 0x80800E88: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800EA0;
    }
    goto skip_1;
    // 0x80800E88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800E8C: jal         0x80090708
    // 0x80800E90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_45;
    // 0x80800E90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_45:
    // 0x80800E94: jal         0x800FFAB0
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_46;
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
L_80800E9C:
    // 0x80800E9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800EA0:
    // 0x80800EA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800EA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800EA8: jr          $ra
    // 0x80800EAC: nop

    return;
    // 0x80800EAC: nop

;}
RECOMP_FUNC void chwandglow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003AC: jal         0x800FFA88
    // 0x808003B0: nop

    func_800FFA88(rdram, ctx);
        goto after_0;
    // 0x808003B0: nop

    after_0:
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003BC: jr          $ra
    // 0x808003C0: nop

    return;
    // 0x808003C0: nop

;}
RECOMP_FUNC void bsdronefalldie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080006C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800074: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800078: jal         0x80085208
    // 0x8080007C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080007C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800080: jal         0x8008CABC
    // 0x80800084: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x80800084: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800088: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x8080008C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800090: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800094: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800098: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080009C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x808000A0: jal         0x80084670
    // 0x808000A4: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    _badata_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808000A4: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x808000A8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808000AC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808000B0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x808000B4: nop

    // 0x808000B8: bc1f        L_80800118
    if (!c1cs) {
        // 0x808000BC: nop
    
            goto L_80800118;
    }
    // 0x808000BC: nop

    // 0x808000C0: jal         0x8008AF24
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_3;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x8008AED4
    // 0x808000D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x808000D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: jal         0x8008B1BC
    // 0x808000DC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x808000DC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x8008B24C
    // 0x808000E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x808000E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808000F4: jal         0x8008B1D4
    // 0x808000F8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    anctrl_setSubrange(rdram, ctx);
        goto after_7;
    // 0x808000F8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: jal         0x8008B134
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800108: jal         0x8008B064
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800110: b           L_80800160
    // 0x80800114: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
        goto L_80800160;
    // 0x80800114: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80800118:
    // 0x80800118: jal         0x8008AF24
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_10;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: jal         0x8008AED4
    // 0x80800128: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    anctrl_setIndex(rdram, ctx);
        goto after_11;
    // 0x80800128: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: jal         0x8008B1BC
    // 0x80800134: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_12;
    // 0x80800134: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800140: jal         0x8008B1D4
    // 0x80800144: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    anctrl_setSubrange(rdram, ctx);
        goto after_13;
    // 0x80800144: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_13:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x8008B134
    // 0x80800150: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_14;
    // 0x80800150: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x80800154: jal         0x8008B064
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_15;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080015C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80800160:
    // 0x80800160: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080016C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800170: jal         0x8009FFD8
    // 0x80800174: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_16;
    // 0x80800174: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_16:
    // 0x80800178: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080017C: jal         0x800961AC
    // 0x80800180: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800961AC(rdram, ctx);
        goto after_17;
    // 0x80800180: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_17:
    // 0x80800184: jal         0x800A0180
    // 0x80800188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A0180(rdram, ctx);
        goto after_18;
    // 0x80800188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x8080018C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800190: jal         0x800A4DFC
    // 0x80800194: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800A4DFC(rdram, ctx);
        goto after_19;
    // 0x80800194: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_19:
    // 0x80800198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080019C: jal         0x80098B4C
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80098B4C(rdram, ctx);
        goto after_20;
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x808001A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001A8: jal         0x80092880
    // 0x808001AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092880(rdram, ctx);
        goto after_21;
    // 0x808001AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x808001B0: sw          $zero, 0x190($s1)
    MEM_W(0X190, ctx->r17) = 0;
    // 0x808001B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001B8: jal         0x80800000
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_bsdronefalldie(rdram, ctx);
        goto after_22;
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x808001C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001C4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808001CC: jr          $ra
    // 0x808001D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808001D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gemarkersDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8080003C: jal         0x800A9C98
    // 0x80800040: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800A9C98(rdram, ctx);
        goto after_0;
    // 0x80800040: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800044: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800048: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x8080004C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800068;
    }
    // 0x8080004C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800050: blez        $a0, L_8080007C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80800054: slti        $at, $a0, 0x9
        ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
            goto L_8080007C;
    }
    // 0x80800054: slti        $at, $a0, 0x9
    ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // 0x80800058: beql        $at, $zero, L_80800080
    if (ctx->r1 == 0) {
        // 0x8080005C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800080;
    }
    goto skip_0;
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800060: b           L_8080007C
    // 0x80800064: addiu       $v1, $a0, 0x7F
    ctx->r3 = ADD32(ctx->r4, 0X7F);
        goto L_8080007C;
    // 0x80800064: addiu       $v1, $a0, 0x7F
    ctx->r3 = ADD32(ctx->r4, 0X7F);
L_80800068:
    // 0x80800068: blez        $a0, L_8080007C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8080006C: slti        $at, $a0, 0x29
        ctx->r1 = SIGNED(ctx->r4) < 0X29 ? 1 : 0;
            goto L_8080007C;
    }
    // 0x8080006C: slti        $at, $a0, 0x29
    ctx->r1 = SIGNED(ctx->r4) < 0X29 ? 1 : 0;
    // 0x80800070: beql        $at, $zero, L_80800080
    if (ctx->r1 == 0) {
        // 0x80800074: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800080;
    }
    goto skip_1;
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800078: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8080007C:
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800080:
    // 0x80800080: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800084: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void _chdragonbrothers_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086EF8: syscall     470
    recomp_syscall_handler(rdram, ctx, 0x80086EF8);
    return;
    // 0x80086EFC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800F46D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F46D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F46DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F46E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F46E4: jal         0x80099544
    // 0x800F46E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80099544(rdram, ctx);
        goto after_0;
    // 0x800F46E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800F46EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F46F0: jal         0x8001BAFC
    // 0x800F46F4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    defrag(rdram, ctx);
        goto after_1;
    // 0x800F46F4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    after_1:
    // 0x800F46F8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800F46FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800F4700: bnel        $a2, $v0, L_800F4714
    if (ctx->r6 != ctx->r2) {
        // 0x800F4704: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_800F4714;
    }
    goto skip_0;
    // 0x800F4704: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800F4708: b           L_800F47A0
    // 0x800F470C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800F47A0;
    // 0x800F470C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800F4710: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_800F4714:
    // 0x800F4714: subu        $t0, $v0, $a2
    ctx->r8 = SUB32(ctx->r2, ctx->r6);
    // 0x800F4718: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x800F471C: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800F4720: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800F4724: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800F4728: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800F472C: addiu       $t1, $zero, 0x56
    ctx->r9 = ADD32(0, 0X56);
    // 0x800F4730: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800F4734: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_800F4738:
    // 0x800F4738: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x800F473C: addu        $a0, $v0, $t2
    ctx->r4 = ADD32(ctx->r2, ctx->r10);
    // 0x800F4740: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800F4744: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x800F4748: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800F474C: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x800F4750: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    // 0x800F4754: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800F4758: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800F475C: addiu       $t9, $v1, 0x2
    ctx->r25 = ADD32(ctx->r3, 0X2);
    // 0x800F4760: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800F4764: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x800F4768: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800F476C: addu        $a2, $v0, $t2
    ctx->r6 = ADD32(ctx->r2, ctx->r10);
    // 0x800F4770: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800F4774: addiu       $t5, $v1, 0x3
    ctx->r13 = ADD32(ctx->r3, 0X3);
    // 0x800F4778: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800F477C: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x800F4780: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800F4784: addu        $a3, $v0, $t6
    ctx->r7 = ADD32(ctx->r2, ctx->r14);
    // 0x800F4788: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800F478C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800F4790: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x800F4794: bne         $v1, $t1, L_800F4738
    if (ctx->r3 != ctx->r9) {
        // 0x800F4798: sw          $t8, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r24;
            goto L_800F4738;
    }
    // 0x800F4798: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800F479C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800F47A0:
    // 0x800F47A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F47A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F47A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F47AC: jr          $ra
    // 0x800F47B0: nop

    return;
    // 0x800F47B0: nop

    // 0x800F47B4: nop

    // 0x800F47B8: nop

    // 0x800F47BC: nop

;}
RECOMP_FUNC void func_80098B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098B5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80098B60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80098B64: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80098B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098B6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80098B70: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80098B74: lw          $a1, 0xBC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XBC);
    // 0x80098B78: jal         0x800EE7F8
    // 0x80098B7C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80098B7C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x80098B80: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80098B84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80098B88: jal         0x800EE7F8
    // 0x80098B8C: lw          $a1, 0xBC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XBC);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80098B8C: lw          $a1, 0xBC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XBC);
    after_1:
    // 0x80098B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098B98: jr          $ra
    // 0x80098B9C: nop

    return;
    // 0x80098B9C: nop

;}
RECOMP_FUNC void func_80800264_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: addiu       $t6, $a1, -0x10B4
    ctx->r14 = ADD32(ctx->r5, -0X10B4);
    // 0x80800268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080026C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80800270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800274: beq         $at, $zero, L_808002BC
    if (ctx->r1 == 0) {
        // 0x80800278: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808002BC;
    }
    // 0x80800278: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080027C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800280: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2132, 0X450) << 16);
    // 0x80800284: addu        $at, $at, $t6
    gpr jr_addend_8080028C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800288: lw          $t6, 0x450($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2132, 0X450));
    // 0x8080028C: jr          $t6
    // 0x80800290: nop

    switch (jr_addend_8080028C >> 2) {
        case 0: goto L_80800294; break;
        case 1: goto L_808002A4; break;
        case 2: goto L_808002A4; break;
        case 3: goto L_808002A4; break;
        case 4: goto L_808002B4; break;
        default: switch_error(__func__, 0x8080028C, 0x80800450);
    }
    // 0x80800290: nop

L_80800294:
    // 0x80800294: jal         0x80090708
    // 0x80800298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_0;
    // 0x80800298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8080029C: b           L_808002C0
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002C0;
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002A4:
    // 0x808002A4: jal         0x808000A4
    // 0x808002A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808000A4_chfaircoinbox(rdram, ctx);
        goto after_1;
    // 0x808002A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808002AC: b           L_808002C0
    // 0x808002B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002C0;
    // 0x808002B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002B4:
    // 0x808002B4: jal         0x808000A4
    // 0x808002B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808000A4_chfaircoinbox(rdram, ctx);
        goto after_2;
    // 0x808002B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
L_808002BC:
    // 0x808002BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002C0:
    // 0x808002C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002C4: jr          $ra
    // 0x808002C8: nop

    return;
    // 0x808002C8: nop

;}
RECOMP_FUNC void func_800C6A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6A60: jr          $ra
    // 0x800C6A64: nop

    return;
    // 0x800C6A64: nop

;}
RECOMP_FUNC void _chbobpanel_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087820: syscall     632
    recomp_syscall_handler(rdram, ctx, 0x80087820);
    return;
    // 0x80087824: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bskazstilt_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005A8: jal         0x80800234
    // 0x808005AC: nop

    func_80800234_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x808005AC: nop

    after_0:
    // 0x808005B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005B8: jr          $ra
    // 0x808005BC: nop

    return;
    // 0x808005BC: nop

;}
RECOMP_FUNC void bamovegoto_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800134: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x80800138: jr          $ra
    // 0x8080013C: lwc1        $f0, 0x74($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X74);
    return;
    // 0x8080013C: lwc1        $f0, 0x74($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X74);
;}
RECOMP_FUNC void func_80802030_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802030: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802034: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802038: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080203C: jal         0x800D8FF8
    // 0x80802040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80802040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802044: lh          $t6, 0x90($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X90);
    // 0x80802048: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8080204C: beql        $t6, $zero, L_80802068
    if (ctx->r14 == 0) {
        // 0x80802050: lwc1        $f4, 0x58($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
            goto L_80802068;
    }
    goto skip_0;
    // 0x80802050: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    skip_0:
    // 0x80802054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802058: jal         0x80801CE8
    // 0x8080205C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_80801CE8_chjiggygamenew(rdram, ctx);
        goto after_1;
    // 0x8080205C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80802060: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80802064: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
L_80802068:
    // 0x80802068: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x8080206C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80802070: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80802074: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80802078: beq         $at, $zero, L_80802440
    if (ctx->r1 == 0) {
        // 0x8080207C: swc1        $f6, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
            goto L_80802440;
    }
    // 0x8080207C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80802080: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80802084: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39E0) << 16);
    // 0x80802088: addu        $at, $at, $t8
    gpr jr_addend_80802090 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080208C: lw          $t8, 0x39E0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(772, 0X39E0));
    // 0x80802090: jr          $t8
    // 0x80802094: nop

    switch (jr_addend_80802090 >> 2) {
        case 0: goto L_80802098; break;
        case 1: goto L_80802104; break;
        case 2: goto L_80802440; break;
        case 3: goto L_80802284; break;
        case 4: goto L_808022BC; break;
        case 5: goto L_80802440; break;
        case 6: goto L_808023F0; break;
        case 7: goto L_808023F0; break;
        default: switch_error(__func__, 0x80802090, 0x808039E0);
    }
    // 0x80802094: nop

L_80802098:
    // 0x80802098: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3A00) << 16);
    // 0x8080209C: lwc1        $f8, 0x3A00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3A00));
    // 0x808020A0: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808020A4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808020A8: nop

    // 0x808020AC: bc1f        L_80802440
    if (!c1cs) {
        // 0x808020B0: nop
    
            goto L_80802440;
    }
    // 0x808020B0: nop

    // 0x808020B4: jal         0x800FC6B0
    // 0x808020B8: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    func_800FC6B0(rdram, ctx);
        goto after_2;
    // 0x808020B8: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    after_2:
    // 0x808020BC: jal         0x800FCCD4
    // 0x808020C0: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    func_800FCCD4(rdram, ctx);
        goto after_3;
    // 0x808020C0: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_3:
    // 0x808020C4: beq         $v0, $zero, L_808020E0
    if (ctx->r2 == 0) {
        // 0x808020C8: addiu       $a0, $zero, 0x2E
        ctx->r4 = ADD32(0, 0X2E);
            goto L_808020E0;
    }
    // 0x808020C8: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x808020CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808020D0: jal         0x800FCAE0
    // 0x808020D4: addiu       $a2, $zero, 0x1D3
    ctx->r6 = ADD32(0, 0X1D3);
    func_800FCAE0(rdram, ctx);
        goto after_4;
    // 0x808020D4: addiu       $a2, $zero, 0x1D3
    ctx->r6 = ADD32(0, 0X1D3);
    after_4:
    // 0x808020D8: jal         0x800FCA90
    // 0x808020DC: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    func_800FCA90(rdram, ctx);
        goto after_5;
    // 0x808020DC: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_5:
L_808020E0:
    // 0x808020E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808020E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808020E8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808020EC: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x808020F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020F4: jal         0x80800834
    // 0x808020F8: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    func_80800834_chjiggygamenew(rdram, ctx);
        goto after_6;
    // 0x808020F8: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    after_6:
    // 0x808020FC: b           L_80802440
    // 0x80802100: nop

        goto L_80802440;
    // 0x80802100: nop

L_80802104:
    // 0x80802104: jal         0x800D90A4
    // 0x80802108: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x80802108: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_7:
    // 0x8080210C: beq         $v0, $zero, L_80802440
    if (ctx->r2 == 0) {
        // 0x80802110: nop
    
            goto L_80802440;
    }
    // 0x80802110: nop

    // 0x80802114: jal         0x80800AF8
    // 0x80802118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AF8_chjiggygamenew(rdram, ctx);
        goto after_8;
    // 0x80802118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080211C: jal         0x800FC74C
    // 0x80802120: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    func_800FC74C(rdram, ctx);
        goto after_9;
    // 0x80802120: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    after_9:
    // 0x80802124: jal         0x800FC6B0
    // 0x80802128: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    func_800FC6B0(rdram, ctx);
        goto after_10;
    // 0x80802128: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    after_10:
    // 0x8080212C: jal         0x800FCA90
    // 0x80802130: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    func_800FCA90(rdram, ctx);
        goto after_11;
    // 0x80802130: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    after_11:
    // 0x80802134: jal         0x8008A740
    // 0x80802138: nop

    _sujiggy_entrypoint_21(rdram, ctx);
        goto after_12;
    // 0x80802138: nop

    after_12:
    // 0x8080213C: beq         $v0, $zero, L_808021E4
    if (ctx->r2 == 0) {
        // 0x80802140: nop
    
            goto L_808021E4;
    }
    // 0x80802140: nop

    // 0x80802144: jal         0x800DA298
    // 0x80802148: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80802148: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    after_13:
    // 0x8080214C: bne         $v0, $zero, L_8080218C
    if (ctx->r2 != 0) {
        // 0x80802150: nop
    
            goto L_8080218C;
    }
    // 0x80802150: nop

    // 0x80802154: jal         0x800C082C
    // 0x80802158: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C082C(rdram, ctx);
        goto after_14;
    // 0x80802158: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8080215C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80802160: addiu       $t0, $zero, 0x97
    ctx->r8 = ADD32(0, 0X97);
    // 0x80802164: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80802168: addiu       $a1, $zero, 0x155F
    ctx->r5 = ADD32(0, 0X155F);
    // 0x8080216C: addiu       $a2, $zero, 0x4C7
    ctx->r6 = ADD32(0, 0X4C7);
    // 0x80802170: jal         0x8008A208
    // 0x80802174: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80802174: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x80802178: jal         0x800C082C
    // 0x8080217C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C082C(rdram, ctx);
        goto after_16;
    // 0x8080217C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80802180: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80802184: b           L_80802440
    // 0x80802188: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
        goto L_80802440;
    // 0x80802188: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
L_8080218C:
    // 0x8080218C: jal         0x8008A758
    // 0x80802190: nop

    _sujiggy_entrypoint_24(rdram, ctx);
        goto after_17;
    // 0x80802190: nop

    after_17:
    // 0x80802194: beq         $v0, $zero, L_808021D4
    if (ctx->r2 == 0) {
        // 0x80802198: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808021D4;
    }
    // 0x80802198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080219C: jal         0x800C082C
    // 0x808021A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C082C(rdram, ctx);
        goto after_18;
    // 0x808021A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x808021A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808021A8: addiu       $t2, $zero, 0x97
    ctx->r10 = ADD32(0, 0X97);
    // 0x808021AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808021B0: addiu       $a1, $zero, 0x1560
    ctx->r5 = ADD32(0, 0X1560);
    // 0x808021B4: addiu       $a2, $zero, 0x4C7
    ctx->r6 = ADD32(0, 0X4C7);
    // 0x808021B8: jal         0x8008A208
    // 0x808021BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_19;
    // 0x808021BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_19:
    // 0x808021C0: jal         0x800C082C
    // 0x808021C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C082C(rdram, ctx);
        goto after_20;
    // 0x808021C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x808021C8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x808021CC: b           L_80802440
    // 0x808021D0: sw          $t3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r11;
        goto L_80802440;
    // 0x808021D0: sw          $t3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r11;
L_808021D4:
    // 0x808021D4: jal         0x80801E4C
    // 0x808021D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801E4C_chjiggygamenew(rdram, ctx);
        goto after_21;
    // 0x808021D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x808021DC: b           L_80802440
    // 0x808021E0: nop

        goto L_80802440;
    // 0x808021E0: nop

L_808021E4:
    // 0x808021E4: jal         0x800DA298
    // 0x808021E8: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    func_800DA298(rdram, ctx);
        goto after_22;
    // 0x808021E8: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    after_22:
    // 0x808021EC: bne         $v0, $zero, L_8080222C
    if (ctx->r2 != 0) {
        // 0x808021F0: nop
    
            goto L_8080222C;
    }
    // 0x808021F0: nop

    // 0x808021F4: jal         0x800C082C
    // 0x808021F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C082C(rdram, ctx);
        goto after_23;
    // 0x808021F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x808021FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80802200: addiu       $t4, $zero, 0x97
    ctx->r12 = ADD32(0, 0X97);
    // 0x80802204: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80802208: addiu       $a1, $zero, 0x14F9
    ctx->r5 = ADD32(0, 0X14F9);
    // 0x8080220C: addiu       $a2, $zero, 0x4C7
    ctx->r6 = ADD32(0, 0X4C7);
    // 0x80802210: jal         0x8008A208
    // 0x80802214: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_24;
    // 0x80802214: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_24:
    // 0x80802218: jal         0x800C082C
    // 0x8080221C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C082C(rdram, ctx);
        goto after_25;
    // 0x8080221C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_25:
    // 0x80802220: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80802224: b           L_80802440
    // 0x80802228: sw          $t5, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r13;
        goto L_80802440;
    // 0x80802228: sw          $t5, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r13;
L_8080222C:
    // 0x8080222C: jal         0x8008A728
    // 0x80802230: nop

    _sujiggy_entrypoint_18(rdram, ctx);
        goto after_26;
    // 0x80802230: nop

    after_26:
    // 0x80802234: beq         $v0, $zero, L_80802274
    if (ctx->r2 == 0) {
        // 0x80802238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802274;
    }
    // 0x80802238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080223C: jal         0x800C082C
    // 0x80802240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C082C(rdram, ctx);
        goto after_27;
    // 0x80802240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
    // 0x80802244: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80802248: addiu       $t6, $zero, 0x97
    ctx->r14 = ADD32(0, 0X97);
    // 0x8080224C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802250: addiu       $a1, $zero, 0x1554
    ctx->r5 = ADD32(0, 0X1554);
    // 0x80802254: addiu       $a2, $zero, 0x4C7
    ctx->r6 = ADD32(0, 0X4C7);
    // 0x80802258: jal         0x8008A208
    // 0x8080225C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_28;
    // 0x8080225C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
    // 0x80802260: jal         0x800C082C
    // 0x80802264: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C082C(rdram, ctx);
        goto after_29;
    // 0x80802264: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_29:
    // 0x80802268: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8080226C: b           L_80802440
    // 0x80802270: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
        goto L_80802440;
    // 0x80802270: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
L_80802274:
    // 0x80802274: jal         0x80801E4C
    // 0x80802278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801E4C_chjiggygamenew(rdram, ctx);
        goto after_30;
    // 0x80802278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
    // 0x8080227C: b           L_80802440
    // 0x80802280: nop

        goto L_80802440;
    // 0x80802280: nop

L_80802284:
    // 0x80802284: jal         0x800C082C
    // 0x80802288: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C082C(rdram, ctx);
        goto after_31;
    // 0x80802288: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x8080228C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80802290: addiu       $t8, $zero, 0x97
    ctx->r24 = ADD32(0, 0X97);
    // 0x80802294: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80802298: addiu       $a1, $zero, 0x1555
    ctx->r5 = ADD32(0, 0X1555);
    // 0x8080229C: addiu       $a2, $zero, 0x4C6
    ctx->r6 = ADD32(0, 0X4C6);
    // 0x808022A0: jal         0x8008A208
    // 0x808022A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_32;
    // 0x808022A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_32:
    // 0x808022A8: jal         0x800C082C
    // 0x808022AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C082C(rdram, ctx);
        goto after_33;
    // 0x808022AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_33:
    // 0x808022B0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x808022B4: b           L_80802440
    // 0x808022B8: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
        goto L_80802440;
    // 0x808022B8: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
L_808022BC:
    // 0x808022BC: jal         0x80801C20
    // 0x808022C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C20_chjiggygamenew(rdram, ctx);
        goto after_34;
    // 0x808022C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x808022C4: beql        $v0, $zero, L_808022F4
    if (ctx->r2 == 0) {
        // 0x808022C8: lw          $t0, 0x64($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X64);
            goto L_808022F4;
    }
    goto skip_1;
    // 0x808022C8: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x808022CC: jal         0x808004E0
    // 0x808022D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_808004E0_chjiggygamenew(rdram, ctx);
        goto after_35;
    // 0x808022D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_35:
    // 0x808022D4: jal         0x80106790
    // 0x808022D8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_36;
    // 0x808022D8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_36:
    // 0x808022DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808022E0: jal         0x80102424
    // 0x808022E4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_37;
    // 0x808022E4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_37:
    // 0x808022E8: b           L_80802440
    // 0x808022EC: nop

        goto L_80802440;
    // 0x808022EC: nop

    // 0x808022F0: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_808022F4:
    // 0x808022F4: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x808022F8: bltz        $t2, L_80802440
    if (SIGNED(ctx->r10) < 0) {
        // 0x808022FC: nop
    
            goto L_80802440;
    }
    // 0x808022FC: nop

    // 0x80802300: jal         0x800343B0
    // 0x80802304: nop

    osGetCount_recomp(rdram, ctx);
        goto after_38;
    // 0x80802304: nop

    after_38:
    // 0x80802308: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x8080230C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80802310: bne         $at, $zero, L_80802320
    if (ctx->r1 != 0) {
        // 0x80802314: subu        $a0, $v0, $v1
        ctx->r4 = SUB32(ctx->r2, ctx->r3);
            goto L_80802320;
    }
    // 0x80802314: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // 0x80802318: b           L_80802320
    // 0x8080231C: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
        goto L_80802320;
    // 0x8080231C: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
L_80802320:
    // 0x80802320: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80802324: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3A04) << 16);
    // 0x80802328: lwc1        $f6, 0x3A04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3A04));
    // 0x8080232C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80802330: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3A08) << 16);
    // 0x80802334: lwc1        $f10, 0x3A08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3A08));
    // 0x80802338: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8080233C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80802340: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80802344: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80802348: jal         0x800343B0
    // 0x8080234C: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    osGetCount_recomp(rdram, ctx);
        goto after_39;
    // 0x8080234C: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    after_39:
    // 0x80802350: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80802354: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802358: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080235C: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80802360: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3A0C) << 16);
    // 0x80802364: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80802368: nop

    // 0x8080236C: bc1f        L_808023A8
    if (!c1cs) {
        // 0x80802370: nop
    
            goto L_808023A8;
    }
    // 0x80802370: nop

    // 0x80802374: lwc1        $f10, 0x3A0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3A0C));
    // 0x80802378: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8080237C: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80802380: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3A10) << 16);
    // 0x80802384: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80802388: lwc1        $f8, 0x3A10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3A10));
    // 0x8080238C: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    // 0x80802390: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80802394: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80802398: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8080239C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808023A0: jal         0x800FCD14
    // 0x808023A4: nop

    func_800FCD14(rdram, ctx);
        goto after_40;
    // 0x808023A4: nop

    after_40:
L_808023A8:
    // 0x808023A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3A14) << 16);
    // 0x808023AC: lwc1        $f16, 0x3A14($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3A14));
    // 0x808023B0: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808023B4: addiu       $a1, $zero, 0xD4B
    ctx->r5 = ADD32(0, 0XD4B);
    // 0x808023B8: addiu       $a2, $zero, 0x14FB
    ctx->r6 = ADD32(0, 0X14FB);
    // 0x808023BC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808023C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808023C4: bc1fl       L_808023E0
    if (!c1cs) {
        // 0x808023C8: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_808023E0;
    }
    goto skip_2;
    // 0x808023C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_2:
    // 0x808023CC: jal         0x808006E0
    // 0x808023D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_808006E0_chjiggygamenew(rdram, ctx);
        goto after_41;
    // 0x808023D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_41:
    // 0x808023D4: b           L_80802440
    // 0x808023D8: nop

        goto L_80802440;
    // 0x808023D8: nop

    // 0x808023DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_808023E0:
    // 0x808023E0: jal         0x800CE980
    // 0x808023E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE980(rdram, ctx);
        goto after_42;
    // 0x808023E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_42:
    // 0x808023E8: b           L_80802440
    // 0x808023EC: nop

        goto L_80802440;
    // 0x808023EC: nop

L_808023F0:
    // 0x808023F0: jal         0x80801C20
    // 0x808023F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C20_chjiggygamenew(rdram, ctx);
        goto after_43;
    // 0x808023F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x808023F8: beq         $v0, $zero, L_80802440
    if (ctx->r2 == 0) {
        // 0x808023FC: nop
    
            goto L_80802440;
    }
    // 0x808023FC: nop

    // 0x80802400: jal         0x800C0638
    // 0x80802404: nop

    func_800C0638(rdram, ctx);
        goto after_44;
    // 0x80802404: nop

    after_44:
    // 0x80802408: bne         $v0, $zero, L_80802440
    if (ctx->r2 != 0) {
        // 0x8080240C: nop
    
            goto L_80802440;
    }
    // 0x8080240C: nop

    // 0x80802410: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80802414: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80802418: bne         $t4, $at, L_80802430
    if (ctx->r12 != ctx->r1) {
        // 0x8080241C: nop
    
            goto L_80802430;
    }
    // 0x8080241C: nop

    // 0x80802420: jal         0x8008A6F0
    // 0x80802424: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    _sujiggy_entrypoint_11(rdram, ctx);
        goto after_45;
    // 0x80802424: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_45:
    // 0x80802428: b           L_8080243C
    // 0x8080242C: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
        goto L_8080243C;
    // 0x8080242C: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
L_80802430:
    // 0x80802430: jal         0x8008A6E8
    // 0x80802434: nop

    _sujiggy_entrypoint_10(rdram, ctx);
        goto after_46;
    // 0x80802434: nop

    after_46:
    // 0x80802438: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
L_8080243C:
    // 0x8080243C: sw          $t5, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r13;
L_80802440:
    // 0x80802440: jal         0x80800CC0
    // 0x80802444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC0_chjiggygamenew(rdram, ctx);
        goto after_47;
    // 0x80802444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80802448: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080244C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802450: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80802454: jr          $ra
    // 0x80802458: nop

    return;
    // 0x80802458: nop

;}
RECOMP_FUNC void func_80805310_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805310: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80805314: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80805318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080531C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80805320: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x80805324: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(804, 0X7DB0) << 16);
    // 0x80805328: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    // 0x8080532C: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80805330: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80805334: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80805338: lh          $a1, 0x7DB0($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(804, 0X7DB0));
    // 0x8080533C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80805340: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    tooie_vanilla_widescreen_rows(rdram, ctx);
    // 0x80805344: jal         0x80802AD4
    // 0x80805348: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80802AD4_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80805348: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8080534C: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80805350: jal         0x80802D04
    // 0x80805354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802D04_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80805354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80805358: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x8080535C: jal         0x808026C8
    // 0x80805360: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80805360: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80805364: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80805368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080536C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80805370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80805374: jr          $ra
    // 0x80805378: nop

    return;
    // 0x80805378: nop

;}
RECOMP_FUNC void func_800C0284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0284: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C0288: lbu         $t6, -0x75F4($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X75F4);
    // 0x800C028C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C0290: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C0294: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C0298: beq         $t6, $zero, L_800C02AC
    if (ctx->r14 == 0) {
        // 0x800C029C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800C02AC;
    }
    // 0x800C029C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C02A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C02A4: jal         0x80087E78
    // 0x800C02A8: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    _gcdialogexec_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x800C02A8: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    after_0:
L_800C02AC:
    // 0x800C02AC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C02B0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C02B4: addiu       $s1, $s1, -0x7748
    ctx->r17 = ADD32(ctx->r17, -0X7748);
    // 0x800C02B8: addiu       $s0, $s0, -0x7750
    ctx->r16 = ADD32(ctx->r16, -0X7750);
    // 0x800C02BC: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
L_800C02C0:
    // 0x800C02C0: beql        $a0, $zero, L_800C02D4
    if (ctx->r4 == 0) {
        // 0x800C02C4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800C02D4;
    }
    goto skip_0;
    // 0x800C02C4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800C02C8: jal         0x80087B00
    // 0x800C02CC: nop

    _gczoombox_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x800C02CC: nop

    after_1:
    // 0x800C02D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800C02D4:
    // 0x800C02D4: bnel        $s0, $s1, L_800C02C0
    if (ctx->r16 != ctx->r17) {
        // 0x800C02D8: lw          $a0, 0x120($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X120);
            goto L_800C02C0;
    }
    goto skip_1;
    // 0x800C02D8: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    skip_1:
    // 0x800C02DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C02E0: lw          $a0, -0x7624($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7624);
    // 0x800C02E4: beql        $a0, $zero, L_800C02F8
    if (ctx->r4 == 0) {
        // 0x800C02E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C02F8;
    }
    goto skip_2;
    // 0x800C02E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800C02EC: jal         0x80087B00
    // 0x800C02F0: nop

    _gczoombox_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x800C02F0: nop

    after_2:
    // 0x800C02F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C02F8:
    // 0x800C02F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C02FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C0300: jr          $ra
    // 0x800C0304: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C0304: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80105A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105A64: jal         0x80105494
    // 0x80105A68: nop

    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80105A68: nop

    after_0:
    // 0x80105A6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80105A70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80105A74: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80105A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80105A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105A80: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80105A84: nop

    // 0x80105A88: bc1f        L_80105A94
    if (!c1cs) {
        // 0x80105A8C: nop
    
            goto L_80105A94;
    }
    // 0x80105A8C: nop

    // 0x80105A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80105A94:
    // 0x80105A94: jr          $ra
    // 0x80105A98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105A98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800AF8_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800B04: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800B08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800B0C: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80800B10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B14: jal         0x80108528
    // 0x80800B18: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    func_80108528(rdram, ctx);
        goto after_0;
    // 0x80800B18: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    after_0:
    // 0x80800B1C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800B20: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x80800B24: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800B28: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    // 0x80800B2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800B30: jal         0x800EE7F8
    // 0x80800B34: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800B34: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800B38: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B3C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B40: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(776, 0X1F70) << 16);
    // 0x80800B44: lhu         $t0, 0x6E($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800B48: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800B4C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x80800B50: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80800B54: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800B58: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x80800B5C: sh          $t2, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r10;
    // 0x80800B60: lhu         $a1, 0x1F70($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(776, 0X1F70));
    // 0x80800B64: jal         0x80103140
    // 0x80800B68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80103140(rdram, ctx);
        goto after_2;
    // 0x80800B68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B70: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B78: jr          $ra
    // 0x80800B7C: nop

    return;
    // 0x80800B7C: nop

;}
RECOMP_FUNC void _chhoneyb_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BA0: syscall     204
    recomp_syscall_handler(rdram, ctx, 0x80085BA0);
    return;
    // 0x80085BA4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808007B0_chtntbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808007B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808007BC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1892, 0XA80) << 16);
    // 0x808007C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007C4: addiu       $t6, $t6, 0xA80
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1892, 0XA80));
    // 0x808007C8: lui         $a3, 0x3FB3
    ctx->r7 = S32(0X3FB3 << 16);
    // 0x808007CC: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808007D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808007D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007DC: jal         0x800BABB8
    // 0x808007E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x808007E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x808007E4: jal         0x8001211C
    // 0x808007E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8001211C(rdram, ctx);
        goto after_1;
    // 0x808007E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808007EC: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x808007F0: beq         $t7, $zero, L_80800800
    if (ctx->r15 == 0) {
        // 0x808007F4: addiu       $a1, $zero, 0x9E2
        ctx->r5 = ADD32(0, 0X9E2);
            goto L_80800800;
    }
    // 0x808007F4: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    // 0x808007F8: b           L_80800800
    // 0x808007FC: addiu       $a1, $zero, 0x9E3
    ctx->r5 = ADD32(0, 0X9E3);
        goto L_80800800;
    // 0x808007FC: addiu       $a1, $zero, 0x9E3
    ctx->r5 = ADD32(0, 0X9E3);
L_80800800:
    // 0x80800800: jal         0x800BA3FC
    // 0x80800804: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800BA3FC(rdram, ctx);
        goto after_2;
    // 0x80800804: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800808: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080080C: jal         0x800BA22C
    // 0x80800810: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800810: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800818: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080081C: jr          $ra
    // 0x80800820: nop

    return;
    // 0x80800820: nop

;}
RECOMP_FUNC void func_800B8CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8CFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B8D00: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B8D04: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800B8D08: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800B8D0C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800B8D10: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B8D14: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800B8D18: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800B8D1C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B8D20: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800B8D24: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B8D28: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B8D2C: jal         0x800E7188
    // 0x800B8D30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_800E7188(rdram, ctx);
        goto after_0;
    // 0x800B8D30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x800B8D34: blez        $v0, L_800B8DA0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B8D38: addu        $s0, $s5, $s1
        ctx->r16 = ADD32(ctx->r21, ctx->r17);
            goto L_800B8DA0;
    }
    // 0x800B8D38: addu        $s0, $s5, $s1
    ctx->r16 = ADD32(ctx->r21, ctx->r17);
    // 0x800B8D3C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B8D40: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800B8D44: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800B8D48: addiu       $s4, $s4, -0x7D40
    ctx->r20 = ADD32(ctx->r20, -0X7D40);
    // 0x800B8D4C: lbu         $a0, 0x6($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X6);
L_800B8D50:
    // 0x800B8D50: jal         0x800D36C4
    // 0x800B8D54: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    func_800D36C4(rdram, ctx);
        goto after_1;
    // 0x800B8D54: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    after_1:
    // 0x800B8D58: addu        $t6, $v0, $s3
    ctx->r14 = ADD32(ctx->r2, ctx->r19);
    // 0x800B8D5C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800B8D60: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x800B8D64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B8D68: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B8D6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8D70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B8D74: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800B8D78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B8D7C: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800B8D80: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800B8D84: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B8D88: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x800B8D8C: jal         0x800E7188
    // 0x800B8D90: nop

    func_800E7188(rdram, ctx);
        goto after_2;
    // 0x800B8D90: nop

    after_2:
    // 0x800B8D94: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B8D98: bnel        $at, $zero, L_800B8D50
    if (ctx->r1 != 0) {
        // 0x800B8D9C: lbu         $a0, 0x6($s4)
        ctx->r4 = MEM_BU(ctx->r20, 0X6);
            goto L_800B8D50;
    }
    goto skip_0;
    // 0x800B8D9C: lbu         $a0, 0x6($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X6);
    skip_0:
L_800B8DA0:
    // 0x800B8DA0: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x800B8DA4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800B8DA8: addiu       $s4, $s4, -0x7D40
    ctx->r20 = ADD32(ctx->r20, -0X7D40);
    // 0x800B8DAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B8DB0: lwc1        $f6, 0x14($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800B8DB4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800B8DB8: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800B8DBC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800B8DC0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800B8DC4: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800B8DC8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8DCC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B8DD0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800B8DD4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800B8DD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800B8DDC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800B8DE0: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800B8DE4: jr          $ra
    // 0x800B8DE8: nop

    return;
    // 0x800B8DE8: nop

;}
RECOMP_FUNC void func_8080047C_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080047C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800484: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800488: jal         0x80100094
    // 0x8080048C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080048C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800490: jal         0x801040D0
    // 0x80800494: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_801040D0(rdram, ctx);
        goto after_1;
    // 0x80800494: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800498: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8080049C: jal         0x801015D0
    // 0x808004A0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_801015D0(rdram, ctx);
        goto after_2;
    // 0x808004A0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x808004A4: jal         0x800DF41C
    // 0x808004A8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800DF41C(rdram, ctx);
        goto after_3;
    // 0x808004A8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x808004AC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x808004B0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808004B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004B8: lwc1        $f4, 0x44($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X44);
    // 0x808004BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808004C0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808004C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808004C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808004CC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808004D0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808004D4: jal         0x800EFA4C
    // 0x808004D8: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x808004D8: nop

    after_4:
    // 0x808004DC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808004E0: jal         0x800D93A0
    // 0x808004E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800D93A0(rdram, ctx);
        goto after_5;
    // 0x808004E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x808004E8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808004EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004F0: jal         0x800DFF2C
    // 0x808004F4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800DFF2C(rdram, ctx);
        goto after_6;
    // 0x808004F4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_6:
    // 0x808004F8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x808004FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800500: jal         0x800DF744
    // 0x80800504: lw          $a1, 0x24($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X24);
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x80800504: lw          $a1, 0x24($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X24);
    after_7:
    // 0x80800508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080050C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800510: jr          $ra
    // 0x80800514: nop

    return;
    // 0x80800514: nop

;}
RECOMP_FUNC void _chclimbbase_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085760: syscall     172
    recomp_syscall_handler(rdram, ctx, 0x80085760);
    return;
    // 0x80085764: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800BE554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BE558: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BE55C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE560: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BE564: jal         0x800EE830
    // 0x800BE568: addiu       $a1, $a1, -0x7BEC
    ctx->r5 = ADD32(ctx->r5, -0X7BEC);
    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x800BE568: addiu       $a1, $a1, -0x7BEC
    ctx->r5 = ADD32(ctx->r5, -0X7BEC);
    after_0:
    // 0x800BE56C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BE570: addiu       $a1, $a1, -0x7BE0
    ctx->r5 = ADD32(ctx->r5, -0X7BE0);
    // 0x800BE574: jal         0x800EE830
    // 0x800BE578: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EE830(rdram, ctx);
        goto after_1;
    // 0x800BE578: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800BE57C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BE580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BE584: jr          $ra
    // 0x800BE588: nop

    return;
    // 0x800BE588: nop

;}
RECOMP_FUNC void func_80017FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017FC0: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x80017FC4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80017FC8: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80017FCC: addiu       $t7, $t7, -0x4D30
    ctx->r15 = ADD32(ctx->r15, -0X4D30);
    // 0x80017FD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80017FD4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80017FD8: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80017FDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80017FE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017FE4: beq         $t8, $zero, L_80018018
    if (ctx->r24 == 0) {
        // 0x80017FE8: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80018018;
    }
    // 0x80017FE8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80017FEC: jal         0x80016934
    // 0x80017FF0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80016934(rdram, ctx);
        goto after_0;
    // 0x80017FF0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80017FF4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80017FF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80017FFC: jal         0x80030640
    // 0x80018000: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    __osMotorAccess_recomp(rdram, ctx);
        goto after_1;
    // 0x80018000: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    after_1:
    // 0x80018004: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80018008: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8001800C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018010: jal         0x80016934
    // 0x80018014: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    func_80016934(rdram, ctx);
        goto after_2;
    // 0x80018014: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    after_2:
L_80018018:
    // 0x80018018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001801C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80018020: jr          $ra
    // 0x80018024: nop

    return;
    // 0x80018024: nop

;}
RECOMP_FUNC void chswitch_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080033C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800340: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80800344: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800348: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080034C: beq         $a1, $at, L_80800370
    if (ctx->r5 == ctx->r1) {
        // 0x80800350: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800370;
    }
    // 0x80800350: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800354: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800358: beq         $a1, $at, L_80800380
    if (ctx->r5 == ctx->r1) {
        // 0x8080035C: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800380;
    }
    // 0x8080035C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800360: beq         $a1, $at, L_808003DC
    if (ctx->r5 == ctx->r1) {
        // 0x80800364: nop
    
            goto L_808003DC;
    }
    // 0x80800364: nop

    // 0x80800368: b           L_80800430
    // 0x8080036C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800430;
    // 0x8080036C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800370:
    // 0x80800370: jal         0x8080093C
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080093C_chswitch(rdram, ctx);
        goto after_0;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800378: b           L_80800434
    // 0x8080037C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800434;
    // 0x8080037C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800380:
    // 0x80800380: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800384: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800388: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080038C: bne         $t7, $at, L_808003D4
    if (ctx->r15 != ctx->r1) {
        // 0x80800390: nop
    
            goto L_808003D4;
    }
    // 0x80800390: nop

    // 0x80800394: jal         0x800880D0
    // 0x80800398: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800398: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A0: jal         0x80102424
    // 0x808003A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808003A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808003A8: jal         0x8010A570
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: jal         0x80103110
    // 0x808003B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x808003B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808003BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003C4: jal         0x800F7F98
    // 0x808003C8: sw          $a0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r4;
    func_800F7F98(rdram, ctx);
        goto after_5;
    // 0x808003C8: sw          $a0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r4;
    after_5:
    // 0x808003CC: b           L_80800430
    // 0x808003D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800430;
    // 0x808003D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003D4:
    // 0x808003D4: b           L_80800430
    // 0x808003D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800430;
    // 0x808003D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003DC:
    // 0x808003DC: jal         0x800DA298
    // 0x808003E0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808003E0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_6:
    // 0x808003E4: beq         $v0, $zero, L_80800414
    if (ctx->r2 == 0) {
        // 0x808003E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800414;
    }
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F0: jal         0x80102424
    // 0x808003F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x808003F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x808003F8: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800400: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80800404: jal         0x8010A570
    // 0x80800408: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    func_8010A570(rdram, ctx);
        goto after_8;
    // 0x80800408: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_8:
    // 0x8080040C: b           L_80800430
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800430;
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800414:
    // 0x80800414: jal         0x80102424
    // 0x80800418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8080041C: b           L_80800430
    // 0x80800420: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800430;
    // 0x80800420: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800424: b           L_80800430
    // 0x80800428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800430;
    // 0x80800428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080042C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800430:
    // 0x80800430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800434:
    // 0x80800434: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800438: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080043C: jr          $ra
    // 0x80800440: nop

    return;
    // 0x80800440: nop

;}
RECOMP_FUNC void func_80800360_chappearfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800364: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080036C: bne         $a1, $at, L_8080038C
    if (ctx->r5 != ctx->r1) {
        // 0x80800370: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080038C;
    }
    // 0x80800370: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800374: jal         0x80100094
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080037C: jal         0x8008A038
    // 0x80800380: addiu       $a0, $v0, 0x14
    ctx->r4 = ADD32(ctx->r2, 0X14);
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800380: addiu       $a0, $v0, 0x14
    ctx->r4 = ADD32(ctx->r2, 0X14);
    after_1:
    // 0x80800384: b           L_80800390
    // 0x80800388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800390;
    // 0x80800388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080038C:
    // 0x8080038C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800390:
    // 0x80800390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800398: jr          $ra
    // 0x8080039C: nop

    return;
    // 0x8080039C: nop

;}
RECOMP_FUNC void func_808006D0_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808006D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006DC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808006E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006E4: jal         0x80100094
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006EC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808006F0: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x808006F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808006F8: xori        $t6, $a1, 0x2
    ctx->r14 = ctx->r5 ^ 0X2;
    // 0x808006FC: jal         0x800DF744
    // 0x80800700: sltu        $a1, $zero, $t6
    ctx->r5 = 0 < ctx->r14 ? 1 : 0;
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800700: sltu        $a1, $zero, $t6
    ctx->r5 = 0 < ctx->r14 ? 1 : 0;
    after_1:
    // 0x80800704: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80800708: lbu         $t8, 0x4($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X4);
    // 0x8080070C: beql        $t8, $zero, L_8080072C
    if (ctx->r24 == 0) {
        // 0x80800710: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080072C;
    }
    goto skip_0;
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800714: lbu         $a0, 0x98($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X98);
    // 0x80800718: lbu         $a1, 0x99($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X99);
    // 0x8080071C: lbu         $a2, 0x9A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9A);
    // 0x80800720: jal         0x800DF5D8
    // 0x80800724: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    func_800DF5D8(rdram, ctx);
        goto after_2;
    // 0x80800724: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    after_2:
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080072C:
    // 0x8080072C: jal         0x80101870
    // 0x80800730: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80101870(rdram, ctx);
        goto after_3;
    // 0x80800730: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_3:
    // 0x80800734: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x80800738: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x8080073C: bgezl       $t1, L_80800820
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800740: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800820;
    }
    goto skip_1;
    // 0x80800740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800744: jal         0x80800C90
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C90_chtntmineshoot(rdram, ctx);
        goto after_4;
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080074C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80800750: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800754: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x80800758: bne         $t3, $at, L_8080081C
    if (ctx->r11 != ctx->r1) {
        // 0x8080075C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8080081C;
    }
    // 0x8080075C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800760: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800764: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800768: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8080076C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800770: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800774: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x80800778: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8080077C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80800780: nop

    // 0x80800784: bc1f        L_80800798
    if (!c1cs) {
        // 0x80800788: nop
    
            goto L_80800798;
    }
    // 0x80800788: nop

    // 0x8080078C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800790: nop

    // 0x80800794: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
L_80800798:
    // 0x80800798: jal         0x80104130
    // 0x8080079C: nop

    func_80104130(rdram, ctx);
        goto after_5;
    // 0x8080079C: nop

    after_5:
    // 0x808007A0: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x808007A4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x808007A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007AC: jal         0x800DBEFC
    // 0x808007B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_6;
    // 0x808007B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x808007B4: jal         0x800D674C
    // 0x808007B8: addiu       $a0, $zero, 0x9C6
    ctx->r4 = ADD32(0, 0X9C6);
    func_800D674C(rdram, ctx);
        goto after_7;
    // 0x808007B8: addiu       $a0, $zero, 0x9C6
    ctx->r4 = ADD32(0, 0X9C6);
    after_7:
    // 0x808007BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808007C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808007C4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808007C8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808007CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808007D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808007D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808007D8: jal         0x800EFA4C
    // 0x808007DC: nop

    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x808007DC: nop

    after_8:
    // 0x808007E0: jal         0x800E2588
    // 0x808007E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_9;
    // 0x808007E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x808007E8: jal         0x800E24D8
    // 0x808007EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E24D8(rdram, ctx);
        goto after_10;
    // 0x808007EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x808007F0: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808007F4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x808007F8: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x808007FC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800800: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800804: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800808: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8080080C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800810: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800814: jal         0x800E2AA4
    // 0x80800818: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800E2AA4(rdram, ctx);
        goto after_11;
    // 0x80800818: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_11:
L_8080081C:
    // 0x8080081C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800820:
    // 0x80800820: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800824: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800828: jr          $ra
    // 0x8080082C: nop

    return;
    // 0x8080082C: nop

;}
RECOMP_FUNC void _bskazflamethrower_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083358: syscall     56
    recomp_syscall_handler(rdram, ctx, 0x80083358);
    return;
    // 0x8008335C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800708_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800708: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080070C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800714: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800718: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080071C: beq         $a1, $at, L_80800738
    if (ctx->r5 == ctx->r1) {
        // 0x80800720: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800738;
    }
    // 0x80800720: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800724: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800728: beq         $a1, $at, L_80800774
    if (ctx->r5 == ctx->r1) {
        // 0x8080072C: addiu       $a0, $zero, 0x3F3
        ctx->r4 = ADD32(0, 0X3F3);
            goto L_80800774;
    }
    // 0x8080072C: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x80800730: b           L_80800790
    // 0x80800734: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_80800790;
    // 0x80800734: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800738:
    // 0x80800738: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2280, 0XA98) << 16);
    // 0x8080073C: addiu       $t7, $t7, 0xA98
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2280, 0XA98));
    // 0x80800740: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800744: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800748: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x8080074C: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80800750: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80800754: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x80800758: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x8080075C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80800760: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800764: jal         0x80108528
    // 0x80800768: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    func_80108528(rdram, ctx);
        goto after_0;
    // 0x80800768: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    after_0:
    // 0x8080076C: b           L_80800790
    // 0x80800770: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_80800790;
    // 0x80800770: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800774:
    // 0x80800774: jal         0x80089C30
    // 0x80800778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080077C: bne         $v0, $zero, L_8080078C
    if (ctx->r2 != 0) {
        // 0x80800780: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080078C;
    }
    // 0x80800780: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800784: jal         0x80108B04
    // 0x80800788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x80800788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8080078C:
    // 0x8080078C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800790:
    // 0x80800790: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800794: jal         0x80085820
    // 0x80800798: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800798: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8080079C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007A4: jr          $ra
    // 0x808007A8: nop

    return;
    // 0x808007A8: nop

;}
RECOMP_FUNC void func_800D7400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7400: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D7404: jr          $ra
    // 0x800D7408: addiu       $v0, $v0, -0x4190
    ctx->r2 = ADD32(ctx->r2, -0X4190);
    return;
    // 0x800D7408: addiu       $v0, $v0, -0x4190
    ctx->r2 = ADD32(ctx->r2, -0X4190);
;}
