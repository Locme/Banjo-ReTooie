#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800180_chstatictorch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800184: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800188: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080018C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800190: bne         $a1, $at, L_808001F8
    if (ctx->r5 != ctx->r1) {
        // 0x80800194: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808001F8;
    }
    // 0x80800194: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080019C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808001A0: jal         0x80089928
    // 0x808001A4: addiu       $a3, $zero, 0x9EB
    ctx->r7 = ADD32(0, 0X9EB);
    _suflamefx_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808001A4: addiu       $a3, $zero, 0x9EB
    ctx->r7 = ADD32(0, 0X9EB);
    after_0:
    // 0x808001A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001AC: jal         0x80100094
    // 0x808001B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808001B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808001B4: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x808001B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1712, 0X220) << 16);
    // 0x808001C0: lwc1        $f6, 0x220($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1712, 0X220));
    // 0x808001C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808001C8: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x808001CC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x808001D0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808001D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808001D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001DC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x808001E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808001E4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x808001E8: jal         0x80089960
    // 0x808001EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _suflamefx_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x808001EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x808001F0: b           L_80800200
    // 0x808001F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800200;
    // 0x808001F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001F8:
    // 0x808001F8: b           L_80800200
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800200;
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800200:
    // 0x80800200: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800204: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void func_80800008_ncba1p(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800018: jal         0x800EEAD4
    // 0x8080001C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800020: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800034: nop

    // 0x80800038: bc1f        L_80800044
    if (!c1cs) {
        // 0x8080003C: nop
    
            goto L_80800044;
    }
    // 0x8080003C: nop

    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800044:
    // 0x80800044: jr          $ra
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chscorepoints_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086468: syscall     325
    recomp_syscall_handler(rdram, ctx, 0x80086468);
    return;
    // 0x8008646C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80803200_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803200: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80803204: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80803208: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8080320C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803210: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80803214: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80803218: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8080321C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80803220: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80803224: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80803228: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8080322C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80803230: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80803234: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80803238: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8080323C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80803240: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80803244: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80803248: jal         0x80100094
    // 0x8080324C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080324C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803250: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80803254: jal         0x80106790
    // 0x80803258: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80803258: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x8080325C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80803260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803264: jal         0x80100094
    // 0x80803268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80803268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080326C: lbu         $t6, 0xC2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC2);
    // 0x80803270: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80803274: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80803278: blez        $t6, L_80803454
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8080327C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80803454;
    }
    // 0x8080327C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80803280: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80803284: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803288: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8080328C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80803290: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80803294: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CB8) << 16);
    // 0x80803298: lwc1        $f24, 0x4CB8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CB8));
    // 0x8080329C: lui         $at, 0x4311
    ctx->r1 = S32(0X4311 << 16);
    // 0x808032A0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808032A4: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x808032A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808032AC: addiu       $s2, $sp, 0x80
    ctx->r18 = ADD32(ctx->r29, 0X80);
    // 0x808032B0: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_808032B4:
    // 0x808032B4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808032B8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808032BC: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808032C0: beql        $s5, $t8, L_80803444
    if (ctx->r21 == ctx->r24) {
        // 0x808032C4: lbu         $t9, 0xC2($fp)
        ctx->r25 = MEM_BU(ctx->r30, 0XC2);
            goto L_80803444;
    }
    goto skip_0;
    // 0x808032C4: lbu         $t9, 0xC2($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0XC2);
    skip_0:
    // 0x808032C8: jal         0x8080000C
    // 0x808032CC: addiu       $s3, $s0, 0x4
    ctx->r19 = ADD32(ctx->r16, 0X4);
    func_8080000C_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x808032CC: addiu       $s3, $s0, 0x4
    ctx->r19 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808032D0: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808032D4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808032D8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808032DC: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x808032E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808032E4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808032E8: jal         0x800EEB9C
    // 0x808032EC: nop

    func_800EEB9C(rdram, ctx);
        goto after_4;
    // 0x808032EC: nop

    after_4:
    // 0x808032F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808032F4: jal         0x800EF04C
    // 0x808032F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808032F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
    // 0x808032FC: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80803300: addiu       $s4, $s1, 0x4
    ctx->r20 = ADD32(ctx->r17, 0X4);
    // 0x80803304: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80803308: jal         0x800F0064
    // 0x8080330C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800F0064(rdram, ctx);
        goto after_6;
    // 0x8080330C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80803310: beql        $v0, $zero, L_80803390
    if (ctx->r2 == 0) {
        // 0x80803314: lwc1        $f16, 0x48($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80803390;
    }
    goto skip_1;
    // 0x80803314: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    skip_1:
    // 0x80803318: jal         0x800DC0C0
    // 0x8080331C: swc1        $f28, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->f28.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x8080331C: swc1        $f28, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->f28.u32l;
    after_7:
    // 0x80803320: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x80803324: nop

    // 0x80803328: bc1fl       L_80803344
    if (!c1cs) {
        // 0x8080332C: lwc1        $f16, 0x48($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80803344;
    }
    goto skip_2;
    // 0x8080332C: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    skip_2:
    // 0x80803330: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80803334: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x80803338: b           L_8080334C
    // 0x8080333C: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
        goto L_8080334C;
    // 0x8080333C: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x80803340: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
L_80803344:
    // 0x80803344: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80803348: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
L_8080334C:
    // 0x8080334C: jal         0x8080460C
    // 0x80803350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_8;
    // 0x80803350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80803354: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803358: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080335C: nop

    // 0x80803360: bc1fl       L_80803380
    if (!c1cs) {
        // 0x80803364: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80803380;
    }
    goto skip_3;
    // 0x80803364: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    skip_3:
    // 0x80803368: jal         0x8080458C
    // 0x8080336C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080458C_chdodgemcontrol(rdram, ctx);
        goto after_9;
    // 0x8080336C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80803370: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803374: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80803378: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8080337C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80803380:
    // 0x80803380: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803384: nop

    // 0x80803388: swc1        $f10, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->f10.u32l;
    // 0x8080338C: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
L_80803390:
    // 0x80803390: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80803394: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803398: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8080339C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808033A0: jal         0x800EEB9C
    // 0x808033A4: nop

    func_800EEB9C(rdram, ctx);
        goto after_10;
    // 0x808033A4: nop

    after_10:
    // 0x808033A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808033AC: jal         0x800EF04C
    // 0x808033B0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x808033B0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_11:
    // 0x808033B4: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x808033B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808033BC: jal         0x800F0064
    // 0x808033C0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800F0064(rdram, ctx);
        goto after_12;
    // 0x808033C0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_12:
    // 0x808033C4: beql        $v0, $zero, L_80803444
    if (ctx->r2 == 0) {
        // 0x808033C8: lbu         $t9, 0xC2($fp)
        ctx->r25 = MEM_BU(ctx->r30, 0XC2);
            goto L_80803444;
    }
    goto skip_4;
    // 0x808033C8: lbu         $t9, 0xC2($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0XC2);
    skip_4:
    // 0x808033CC: jal         0x800DC0C0
    // 0x808033D0: swc1        $f28, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->f28.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_13;
    // 0x808033D0: swc1        $f28, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->f28.u32l;
    after_13:
    // 0x808033D4: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x808033D8: nop

    // 0x808033DC: bc1fl       L_808033F8
    if (!c1cs) {
        // 0x808033E0: lwc1        $f8, 0x48($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
            goto L_808033F8;
    }
    goto skip_5;
    // 0x808033E0: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    skip_5:
    // 0x808033E4: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808033E8: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x808033EC: b           L_80803400
    // 0x808033F0: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
        goto L_80803400;
    // 0x808033F0: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x808033F4: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
L_808033F8:
    // 0x808033F8: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x808033FC: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
L_80803400:
    // 0x80803400: jal         0x8080460C
    // 0x80803404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_14;
    // 0x80803404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80803408: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080340C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80803410: nop

    // 0x80803414: bc1fl       L_80803434
    if (!c1cs) {
        // 0x80803418: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80803434;
    }
    goto skip_6;
    // 0x80803418: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    skip_6:
    // 0x8080341C: jal         0x8080458C
    // 0x80803420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080458C_chdodgemcontrol(rdram, ctx);
        goto after_15;
    // 0x80803420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80803424: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803428: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8080342C: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80803430: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80803434:
    // 0x80803434: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803438: nop

    // 0x8080343C: swc1        $f6, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->f6.u32l;
    // 0x80803440: lbu         $t9, 0xC2($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0XC2);
L_80803444:
    // 0x80803444: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80803448: slt         $at, $s5, $t9
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8080344C: bnel        $at, $zero, L_808032B4
    if (ctx->r1 != 0) {
        // 0x80803450: lw          $t7, 0x6C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X6C);
            goto L_808032B4;
    }
    goto skip_7;
    // 0x80803450: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    skip_7:
L_80803454:
    // 0x80803454: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80803458: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080345C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80803460: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80803464: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80803468: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8080346C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80803470: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80803474: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80803478: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8080347C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80803480: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80803484: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80803488: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8080348C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80803490: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80803494: jr          $ra
    // 0x80803498: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80803498: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80801284_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801284: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080128C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801290: jal         0x80800AEC
    // 0x80801294: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_80800AEC_bssub(rdram, ctx);
        goto after_0;
    // 0x80801294: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80801298: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080129C: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x808012A0: jal         0x800914FC
    // 0x808012A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800914FC(rdram, ctx);
        goto after_1;
    // 0x808012A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808012A8: jal         0x80085158
    // 0x808012AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baspin_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808012AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808012B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808012B4: bne         $v0, $at, L_808012C0
    if (ctx->r2 != ctx->r1) {
        // 0x808012B8: addiu       $t6, $zero, 0x131
        ctx->r14 = ADD32(0, 0X131);
            goto L_808012C0;
    }
    // 0x808012B8: addiu       $t6, $zero, 0x131
    ctx->r14 = ADD32(0, 0X131);
    // 0x808012BC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808012C0:
    // 0x808012C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808012C4: jal         0x8009E5C8
    // 0x808012C8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x808012C8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808012CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808012D4: jr          $ra
    // 0x808012D8: nop

    return;
    // 0x808012D8: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085648: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085648);
    return;
    // 0x8008564C: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void bsbfly_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CE4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801CE8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(96, 0X1DD8) << 16);
    // 0x80801CEC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801CF0: jr          $ra
    // 0x80801CF4: lw          $v0, 0x1DD8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1DD8));
    return;
    // 0x80801CF4: lw          $v0, 0x1DD8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1DD8));
    // 0x80801CF8: nop

    // 0x80801CFC: nop

;}
RECOMP_FUNC void func_8080035C_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080035C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800364: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800368: jal         0x800EB854
    // 0x8080036C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EB854(rdram, ctx);
        goto after_0;
    // 0x8080036C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800370: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800374: bne         $v0, $at, L_808003AC
    if (ctx->r2 != ctx->r1) {
        // 0x80800378: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808003AC;
    }
    // 0x80800378: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800380: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800384: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800388: bnel        $t7, $at, L_808003B8
    if (ctx->r15 != ctx->r1) {
        // 0x8080038C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003B8;
    }
    goto skip_0;
    // 0x8080038C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800390: jal         0x80100094
    // 0x80800394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080039C: jal         0x80087CA0
    // 0x808003A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808003A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808003A4: b           L_808003B8
    // 0x808003A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003B8;
    // 0x808003A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003AC:
    // 0x808003AC: jal         0x80101870
    // 0x808003B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_3;
    // 0x808003B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B8:
    // 0x808003B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003BC: jr          $ra
    // 0x808003C0: nop

    return;
    // 0x808003C0: nop

;}
RECOMP_FUNC void func_808000C0_bsdronegoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: jal         0x8009B7C0
    // 0x808000CC: nop

    func_8009B7C0(rdram, ctx);
        goto after_0;
    // 0x808000CC: nop

    after_0:
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084368: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084368);
    return;
    // 0x8008436C: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void _chsquits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086780: syscall     370
    recomp_syscall_handler(rdram, ctx, 0x80086780);
    return;
    // 0x80086784: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801554_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801554: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80801558: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080155C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801560: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801564: addiu       $s4, $sp, 0x38
    ctx->r20 = ADD32(ctx->r29, 0X38);
    // 0x80801568: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080156C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801570: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801574: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801578: jal         0x8008FE68
    // 0x8080157C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8008FE68(rdram, ctx);
        goto after_0;
    // 0x8080157C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x80801580: jal         0x80090128
    // 0x80801584: nop

    func_80090128(rdram, ctx);
        goto after_1;
    // 0x80801584: nop

    after_1:
    // 0x80801588: beql        $v0, $zero, L_80801624
    if (ctx->r2 == 0) {
        // 0x8080158C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80801624;
    }
    goto skip_0;
    // 0x8080158C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80801590: lbu         $t6, 0x80($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X80);
    // 0x80801594: bnel        $t6, $zero, L_808015F4
    if (ctx->r14 != 0) {
        // 0x80801598: lbu         $t0, 0x77($s1)
        ctx->r8 = MEM_BU(ctx->r17, 0X77);
            goto L_808015F4;
    }
    goto skip_1;
    // 0x80801598: lbu         $t0, 0x77($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X77);
    skip_1:
    // 0x8080159C: lbu         $t7, 0x77($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X77);
    // 0x808015A0: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x808015A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808015A8: blez        $t7, L_808015E0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808015AC: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_808015E0;
    }
    // 0x808015AC: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x808015B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808015B4:
    // 0x808015B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808015B8: jal         0x80800DC8
    // 0x808015BC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_80800DC8_gcmapsects(rdram, ctx);
        goto after_2;
    // 0x808015BC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_2:
    // 0x808015C0: beql        $v0, $s2, L_808015D0
    if (ctx->r2 == ctx->r18) {
        // 0x808015C4: lbu         $t8, 0x77($s1)
        ctx->r24 = MEM_BU(ctx->r17, 0X77);
            goto L_808015D0;
    }
    goto skip_2;
    // 0x808015C4: lbu         $t8, 0x77($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X77);
    skip_2:
    // 0x808015C8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808015CC: lbu         $t8, 0x77($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X77);
L_808015D0:
    // 0x808015D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808015D4: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x808015D8: bnel        $at, $zero, L_808015B4
    if (ctx->r1 != 0) {
        // 0x808015DC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808015B4;
    }
    goto skip_3;
    // 0x808015DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
L_808015E0:
    // 0x808015E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808015E4: sh          $s3, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r19;
    // 0x808015E8: b           L_80801620
    // 0x808015EC: sb          $t9, 0x82($s1)
    MEM_B(0X82, ctx->r17) = ctx->r25;
        goto L_80801620;
    // 0x808015EC: sb          $t9, 0x82($s1)
    MEM_B(0X82, ctx->r17) = ctx->r25;
    // 0x808015F0: lbu         $t0, 0x77($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X77);
L_808015F4:
    // 0x808015F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808015F8: blez        $t0, L_80801620
    if (SIGNED(ctx->r8) <= 0) {
        // 0x808015FC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801620;
    }
    // 0x808015FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801600:
    // 0x80801600: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801604: jal         0x80801320
    // 0x80801608: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_80801320_gcmapsects(rdram, ctx);
        goto after_3;
    // 0x80801608: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_3:
    // 0x8080160C: lbu         $t1, 0x77($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X77);
    // 0x80801610: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801614: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80801618: bnel        $at, $zero, L_80801600
    if (ctx->r1 != 0) {
        // 0x8080161C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801600;
    }
    goto skip_4;
    // 0x8080161C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
L_80801620:
    // 0x80801620: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801624:
    // 0x80801624: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801628: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080162C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801630: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801634: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801638: jr          $ra
    // 0x8080163C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080163C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _bafpctrl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C88: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084C88);
    return;
    // 0x80084C8C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chdoormake_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086898: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x80086898);
    return;
    // 0x8008689C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080041C_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080041C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800420: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800424: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080042C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800430: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800434: jal         0x800EE7F8
    // 0x80800438: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800438: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080043C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800440: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800444: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800448: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1052, 0X9E4) << 16);
    // 0x8080044C: addiu       $a2, $a2, 0x9E4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1052, 0X9E4));
    // 0x80800450: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800454: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800458: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080045C: jal         0x80089D18
    // 0x80800460: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800460: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800464: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1052, 0X9FC) << 16);
    // 0x80800468: addiu       $t6, $t6, 0x9FC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1052, 0X9FC));
    // 0x8080046C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800470: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800474: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800478: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080047C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800480: jal         0x800BBCB8
    // 0x80800484: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80800484: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_2:
    // 0x80800488: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080048C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800490: jal         0x80086670
    // 0x80800494: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800494: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_3:
    // 0x80800498: jal         0x800DA544
    // 0x8080049C: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x8080049C: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    after_4:
    // 0x808004A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808004A8: jr          $ra
    // 0x808004AC: nop

    return;
    // 0x808004AC: nop

;}
RECOMP_FUNC void bstimeout_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001D0: jal         0x8008CABC
    // 0x808001D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001D8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808001DC: jal         0x8008AF24
    // 0x808001E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808001E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x800A0110
    // 0x808001EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800A0110(rdram, ctx);
        goto after_2;
    // 0x808001EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x808001F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808001F4: jal         0x8008B134
    // 0x808001F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_3;
    // 0x808001F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808001FC: jal         0x8008B064
    // 0x80800200: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_start(rdram, ctx);
        goto after_4;
    // 0x80800200: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800204: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80800208: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800214: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800218: jal         0x8009FFD8
    // 0x8080021C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_5;
    // 0x8080021C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x8009B9B0
    // 0x80800228: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x80800228: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x800A4DA4
    // 0x80800234: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A4DA4(rdram, ctx);
        goto after_7;
    // 0x80800234: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_7:
    // 0x80800238: jal         0x8009F308
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F308(rdram, ctx);
        goto after_8;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800240: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80800244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800250: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800254: jal         0x8009C914
    // 0x80800258: nop

    yaw_setIdeal(rdram, ctx);
        goto after_9;
    // 0x80800258: nop

    after_9:
    // 0x8080025C: jal         0x800A4CA8
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_10;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800268: jal         0x80089288
    // 0x8080026C: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    _ncbadie_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x8080026C: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    after_11:
    // 0x80800270: jal         0x800FC6B0
    // 0x80800274: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_12;
    // 0x80800274: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_12:
    // 0x80800278: jal         0x8008E944
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_13;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800280: lui         $a2, 0x4039
    ctx->r6 = S32(0X4039 << 16);
    // 0x80800284: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x80085338
    // 0x80800290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_14;
    // 0x80800290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800294: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800298: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080029C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002A0: jr          $ra
    // 0x808002A4: nop

    return;
    // 0x808002A4: nop

;}
RECOMP_FUNC void func_80800930_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800930: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800934: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800938: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080093C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800940: lhu         $a2, 0x72($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X72);
    // 0x80800944: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800948: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080094C: srl         $t6, $a2, 10
    ctx->r14 = S32(U32(ctx->r6) >> 10);
    // 0x80800950: beq         $t6, $at, L_80800988
    if (ctx->r14 == ctx->r1) {
        // 0x80800954: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800988;
    }
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800958: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080095C: beq         $t6, $at, L_80800978
    if (ctx->r14 == ctx->r1) {
        // 0x80800960: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800978;
    }
    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800964: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800968: beq         $t6, $at, L_808009D0
    if (ctx->r14 == ctx->r1) {
        // 0x8080096C: nop
    
            goto L_808009D0;
    }
    // 0x8080096C: nop

    // 0x80800970: b           L_80800A10
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A10;
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800978:
    // 0x80800978: jal         0x80087CC8
    // 0x8080097C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x8080097C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800980: b           L_80800A10
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A10;
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800988:
    // 0x80800988: jal         0x80087CC8
    // 0x8080098C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080098C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800990: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800994: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800998: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x8080099C: andi        $t9, $t8, 0xFFF7
    ctx->r25 = ctx->r24 & 0XFFF7;
    // 0x808009A0: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x808009A4: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x808009A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808009AC: bnel        $t0, $at, L_80800A10
    if (ctx->r8 != ctx->r1) {
        // 0x808009B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A10;
    }
    goto skip_0;
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808009B4: jal         0x80085750
    // 0x808009B8: nop

    _capod_entrypoint_22(rdram, ctx);
        goto after_2;
    // 0x808009B8: nop

    after_2:
    // 0x808009BC: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x808009C0: jal         0x80101238
    // 0x808009C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80101238(rdram, ctx);
        goto after_3;
    // 0x808009C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808009C8: b           L_80800A10
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A10;
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009D0:
    // 0x808009D0: jal         0x800F54E4
    // 0x808009D4: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808009D4: nop

    after_4:
    // 0x808009D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808009E0: jal         0x800F8300
    // 0x808009E4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800F8300(rdram, ctx);
        goto after_5;
    // 0x808009E4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808009E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808009EC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x808009F0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808009F4: jal         0x80085748
    // 0x808009F8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_21(rdram, ctx);
        goto after_6;
    // 0x808009F8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_6:
    // 0x808009FC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800A00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A04: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80800A08: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80800A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A10:
    // 0x80800A10: jal         0x80102424
    // 0x80800A14: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800A14: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_7:
    // 0x80800A18: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x80800A1C: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80800A20: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80800A24: sltiu       $at, $t3, 0x5
    ctx->r1 = ctx->r11 < 0X5 ? 1 : 0;
    // 0x80800A28: beq         $at, $zero, L_80800CA8
    if (ctx->r1 == 0) {
        // 0x80800A2C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80800CA8;
    }
    // 0x80800A2C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80800A30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1824, 0X1268) << 16);
    // 0x80800A34: addu        $at, $at, $t3
    gpr jr_addend_80800A3C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80800A38: lw          $t3, 0x1268($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1824, 0X1268));
    // 0x80800A3C: jr          $t3
    // 0x80800A40: nop

    switch (jr_addend_80800A3C >> 2) {
        case 0: goto L_80800A44; break;
        case 1: goto L_80800B04; break;
        case 2: goto L_80800C34; break;
        case 3: goto L_80800C24; break;
        case 4: goto L_80800C64; break;
        default: switch_error(__func__, 0x80800A3C, 0x80801268);
    }
    // 0x80800A40: nop

L_80800A44:
    // 0x80800A44: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800A48: addiu       $t4, $zero, 0x1850
    ctx->r12 = ADD32(0, 0X1850);
    // 0x80800A4C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800A50: addiu       $a2, $a2, 0x7DB0
    ctx->r6 = ADD32(ctx->r6, 0X7DB0);
    // 0x80800A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A5C: jal         0x80087CB8
    // 0x80800A60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800A60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A68: jal         0x80100094
    // 0x80800A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800A70: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1824, 0X127C) << 16);
    // 0x80800A74: lwc1        $f6, 0x127C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1824, 0X127C));
    // 0x80800A78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800A80: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800A84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A88: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x80800A8C: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80800A90: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800A94: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800A98: jal         0x80087DD8
    // 0x80800A9C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_10;
    // 0x80800A9C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x80800AA0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800AA4: jal         0x80087CD8
    // 0x80800AA8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x80800AA8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_11:
    // 0x80800AAC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800AB0: jal         0x80087CE0
    // 0x80800AB4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80800AB4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_12:
    // 0x80800AB8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800ABC: jal         0x80087CE8
    // 0x80800AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_13;
    // 0x80800AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC8: jal         0x808000D0
    // 0x80800ACC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_808000D0_chmusicmenu(rdram, ctx);
        goto after_14;
    // 0x80800ACC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_14:
    // 0x80800AD0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800AD4: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80800AD8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800AE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AE4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AEC: jal         0x80087D08
    // 0x80800AF0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _gcnewoption_entrypoint_14(rdram, ctx);
        goto after_15;
    // 0x80800AF0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x80800AF4: jal         0x80087CF0
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800AFC: b           L_80800CAC
    // 0x80800B00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800CAC;
    // 0x80800B00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B04:
    // 0x80800B04: jal         0x808000B4
    // 0x80800B08: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    func_808000B4_chmusicmenu(rdram, ctx);
        goto after_17;
    // 0x80800B08: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    after_17:
    // 0x80800B0C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800B10: addiu       $a2, $a2, 0x7DB0
    ctx->r6 = ADD32(ctx->r6, 0X7DB0);
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800B20: jal         0x80087CB8
    // 0x80800B24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_18;
    // 0x80800B24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_18:
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B2C: jal         0x80100094
    // 0x80800B30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_19;
    // 0x80800B30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800B34: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1824, 0X1280) << 16);
    // 0x80800B38: lwc1        $f16, 0x1280($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1824, 0X1280));
    // 0x80800B3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800B44: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800B48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B4C: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x80800B50: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80800B54: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800B58: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80800B5C: jal         0x80087DD8
    // 0x80800B60: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_20;
    // 0x80800B60: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x80800B64: lw          $t5, 0x30($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X30);
    // 0x80800B68: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1824, 0X14F8) << 16);
    // 0x80800B6C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800B70: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80800B74: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B78: lbu         $v0, 0x14F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(1824, 0X14F8));
    // 0x80800B7C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800B80: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80800B84: beq         $at, $zero, L_80800B94
    if (ctx->r1 == 0) {
        // 0x80800B88: nop
    
            goto L_80800B94;
    }
    // 0x80800B88: nop

    // 0x80800B8C: b           L_80800B94
    // 0x80800B90: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80800B94;
    // 0x80800B90: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80800B94:
    // 0x80800B94: jal         0x80087CD8
    // 0x80800B98: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_21;
    // 0x80800B98: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_21:
    // 0x80800B9C: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x80800BA0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1824, 0X14F8) << 16);
    // 0x80800BA4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800BA8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800BAC: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80800BB0: jal         0x80087CE0
    // 0x80800BB4: lbu         $a1, 0x14F8($a1)
    ctx->r5 = MEM_BU(ctx->r5, (int16_t)RELOC_LO16(1824, 0X14F8));
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_22;
    // 0x80800BB4: lbu         $a1, 0x14F8($a1)
    ctx->r5 = MEM_BU(ctx->r5, (int16_t)RELOC_LO16(1824, 0X14F8));
    after_22:
    // 0x80800BB8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800BBC: jal         0x80087CE8
    // 0x80800BC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_23;
    // 0x80800BC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_23:
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC8: jal         0x808000D0
    // 0x80800BCC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_808000D0_chmusicmenu(rdram, ctx);
        goto after_24;
    // 0x80800BCC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_24:
    // 0x80800BD0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800BD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800BD8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800BDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800BE4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800BE8: jal         0x80087D08
    // 0x80800BEC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _gcnewoption_entrypoint_14(rdram, ctx);
        goto after_25;
    // 0x80800BEC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_25:
    // 0x80800BF0: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80800BF4: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x80800BF8: bne         $t9, $t0, L_80800C14
    if (ctx->r25 != ctx->r8) {
        // 0x80800BFC: nop
    
            goto L_80800C14;
    }
    // 0x80800BFC: nop

    // 0x80800C00: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80800C04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800C08: beq         $v0, $at, L_80800C14
    if (ctx->r2 == ctx->r1) {
        // 0x80800C0C: nop
    
            goto L_80800C14;
    }
    // 0x80800C0C: nop

    // 0x80800C10: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_80800C14:
    // 0x80800C14: jal         0x80087CF0
    // 0x80800C18: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_26;
    // 0x80800C18: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_26:
    // 0x80800C1C: b           L_80800CAC
    // 0x80800C20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800CAC;
    // 0x80800C20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C24:
    // 0x80800C24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800C28: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80800C2C: b           L_80800CA8
    // 0x80800C30: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
        goto L_80800CA8;
    // 0x80800C30: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_80800C34:
    // 0x80800C34: jal         0x800F54E4
    // 0x80800C38: nop

    func_800F54E4(rdram, ctx);
        goto after_27;
    // 0x80800C38: nop

    after_27:
    // 0x80800C3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C40: jal         0x800F82D4
    // 0x80800C44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_28;
    // 0x80800C44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x80800C48: jal         0x80800714
    // 0x80800C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800714_chmusicmenu(rdram, ctx);
        goto after_29;
    // 0x80800C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800C50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800C54: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80800C58: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80800C5C: b           L_80800CA8
    // 0x80800C60: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
        goto L_80800CA8;
    // 0x80800C60: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
L_80800C64:
    // 0x80800C64: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800C68: addiu       $a1, $zero, 0x299
    ctx->r5 = ADD32(0, 0X299);
    // 0x80800C6C: jal         0x800882D8
    // 0x80800C70: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    _gccubesearch_entrypoint_12(rdram, ctx);
        goto after_30;
    // 0x80800C70: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_30:
    // 0x80800C74: jal         0x8008F8B0
    // 0x80800C78: nop

    func_8008F8B0(rdram, ctx);
        goto after_31;
    // 0x80800C78: nop

    after_31:
    // 0x80800C7C: jal         0x8008F8D8
    // 0x80800C80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_32;
    // 0x80800C80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_32:
    // 0x80800C84: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800C88: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800C8C: jal         0x8008F904
    // 0x80800C90: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8008F904(rdram, ctx);
        goto after_33;
    // 0x80800C90: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_33:
    // 0x80800C94: jal         0x8008F938
    // 0x80800C98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F938(rdram, ctx);
        goto after_34;
    // 0x80800C98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_34:
    // 0x80800C9C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800CA0: jal         0x8008F990
    // 0x80800CA4: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    func_8008F990(rdram, ctx);
        goto after_35;
    // 0x80800CA4: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_35:
L_80800CA8:
    // 0x80800CA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CAC:
    // 0x80800CAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800CB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800CB4: jr          $ra
    // 0x80800CB8: nop

    return;
    // 0x80800CB8: nop

;}
RECOMP_FUNC void func_80800740_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800740: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800744: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800748: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080074C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800750: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800754: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800758: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8080075C: bgez        $t8, L_8080078C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800760: addiu       $a1, $s0, 0x54
        ctx->r5 = ADD32(ctx->r16, 0X54);
            goto L_8080078C;
    }
    // 0x80800760: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x80800764: jal         0x80089BF0
    // 0x80800768: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800768: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x8080076C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800770: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800778: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x8080077C: jal         0x80102BF8
    // 0x80800780: lui         $a3, 0x435C
    ctx->r7 = S32(0X435C << 16);
    func_80102BF8(rdram, ctx);
        goto after_1;
    // 0x80800780: lui         $a3, 0x435C
    ctx->r7 = S32(0X435C << 16);
    after_1:
    // 0x80800784: b           L_808008D0
    // 0x80800788: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008D0;
    // 0x80800788: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080078C:
    // 0x8080078C: jal         0x800D8FF8
    // 0x80800790: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800790: nop

    after_2:
    // 0x80800794: jal         0x800F54E4
    // 0x80800798: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800798: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8080079C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808007A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808007A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007A8: jal         0x8010D09C
    // 0x808007AC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_8010D09C(rdram, ctx);
        goto after_4;
    // 0x808007AC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_4:
    // 0x808007B0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808007B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007B8: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x808007BC: beq         $t9, $at, L_808007D4
    if (ctx->r25 == ctx->r1) {
        // 0x808007C0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808007D4;
    }
    // 0x808007C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808007C4: beq         $t9, $at, L_808007D4
    if (ctx->r25 == ctx->r1) {
        // 0x808007C8: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808007D4;
    }
    // 0x808007C8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808007CC: bne         $t9, $at, L_80800838
    if (ctx->r25 != ctx->r1) {
        // 0x808007D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800838;
    }
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007D4:
    // 0x808007D4: jal         0x80089F78
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808007DC: beq         $v0, $zero, L_80800850
    if (ctx->r2 == 0) {
        // 0x808007E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800850;
    }
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E4: jal         0x80102D78
    // 0x808007E8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80102D78(rdram, ctx);
        goto after_6;
    // 0x808007E8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_6:
    // 0x808007EC: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808007F0: jal         0x800136E4
    // 0x808007F4: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x808007F4: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_7:
    // 0x808007F8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800800: jal         0x80100094
    // 0x80800804: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x80800804: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800808: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080080C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800810: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800814: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80800818: addiu       $t0, $zero, 0x4000
    ctx->r8 = ADD32(0, 0X4000);
    // 0x8080081C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800824: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800828: jal         0x80089F90
    // 0x8080082C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x8080082C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x80800830: b           L_80800854
    // 0x80800834: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
        goto L_80800854;
    // 0x80800834: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_80800838:
    // 0x80800838: jal         0x80102D78
    // 0x8080083C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80102D78(rdram, ctx);
        goto after_10;
    // 0x8080083C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_10:
    // 0x80800840: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800844: jal         0x800136E4
    // 0x80800848: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_11;
    // 0x80800848: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    after_11:
    // 0x8080084C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80800850:
    // 0x80800850: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_80800854:
    // 0x80800854: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800858: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080085C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800860: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800864: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800868: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080086C: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800870: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800874: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x80800878: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080087C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800880: jal         0x800F1FF0
    // 0x80800884: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_12;
    // 0x80800884: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80800888: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080088C: jal         0x800F1DCC
    // 0x80800890: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_13;
    // 0x80800890: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    after_13:
    // 0x80800894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800898: jal         0x80101F24
    // 0x8080089C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_80101F24(rdram, ctx);
        goto after_14;
    // 0x8080089C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x808008A0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(896, 0X11FC) << 16);
    // 0x808008A4: addiu       $a1, $a1, 0x11FC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(896, 0X11FC));
    // 0x808008A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808008AC: jal         0x800F3780
    // 0x808008B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_15;
    // 0x808008B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_15:
    // 0x808008B4: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808008B8: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808008BC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808008C0: jal         0x800136E4
    // 0x808008C4: add.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f2.fl;
    func_800136E4(rdram, ctx);
        goto after_16;
    // 0x808008C4: add.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f2.fl;
    after_16:
    // 0x808008C8: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808008CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008D0:
    // 0x808008D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808008D8: jr          $ra
    // 0x808008DC: nop

    return;
    // 0x808008DC: nop

;}
RECOMP_FUNC void func_80800124_chlavaarchgrill3switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800130: jal         0x80800000
    // 0x80800134: addiu       $a1, $zero, 0xA1E
    ctx->r5 = ADD32(0, 0XA1E);
    func_80800000_chlavaarchgrill3switches(rdram, ctx);
        goto after_0;
    // 0x80800134: addiu       $a1, $zero, 0xA1E
    ctx->r5 = ADD32(0, 0XA1E);
    after_0:
    // 0x80800138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080013C: jal         0x80085810
    // 0x80800140: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800140: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_1:
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080014C: jr          $ra
    // 0x80800150: nop

    return;
    // 0x80800150: nop

;}
RECOMP_FUNC void func_800909EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800909EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800909F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800909F4: jal         0x8009097C
    // 0x800909F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009097C(rdram, ctx);
        goto after_0;
    // 0x800909F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800909FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090A04: jr          $ra
    // 0x80090A08: nop

    return;
    // 0x80090A08: nop

;}
RECOMP_FUNC void _babackpack_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844F0: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x800844F0);
    return;
    // 0x800844F4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808000F0_chfactoryliftdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808000F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800100: bne         $a1, $at, L_80800124
    if (ctx->r5 != ctx->r1) {
        // 0x80800104: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800124;
    }
    // 0x80800104: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800108: addiu       $a0, $zero, 0x3B8
    ctx->r4 = ADD32(0, 0X3B8);
    // 0x8080010C: jal         0x80101180
    // 0x80800110: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x80800110: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800114: jal         0x8010A570
    // 0x80800118: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x80800118: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080011C: b           L_8080012C
    // 0x80800120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080012C;
    // 0x80800120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800124:
    // 0x80800124: b           L_8080012C
    // 0x80800128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080012C;
    // 0x80800128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080012C:
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

    // 0x8080013C: nop

;}
RECOMP_FUNC void subaddiedialog_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801284: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801288: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8080128C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801290: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801294: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
    // 0x80801298: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080129C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808012A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808012A4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808012A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808012AC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808012B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808012B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808012B8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x808012BC: jal         0x800C0534
    // 0x808012C0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_800C0534(rdram, ctx);
        goto after_0;
    // 0x808012C0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x808012C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808012C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808012CC: jr          $ra
    // 0x808012D0: nop

    return;
    // 0x808012D0: nop

;}
RECOMP_FUNC void _bashoes_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085060: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085060);
    return;
    // 0x80085064: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_800F55FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F55FC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5604: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F560C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5610: jal         0x80096628
    // 0x800F5614: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80096628(rdram, ctx);
        goto after_0;
    // 0x800F5614: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F561C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5620: jr          $ra
    // 0x800F5624: nop

    return;
    // 0x800F5624: nop

;}
RECOMP_FUNC void func_800A89A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A89A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A89A4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A89A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A89AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A89B0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800A89B4: jr          $ra
    // 0x800A89B8: lw          $v0, 0x7688($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7688);
    return;
    // 0x800A89B8: lw          $v0, 0x7688($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7688);
;}
RECOMP_FUNC void gspropprop_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80800094: sll         $t8, $t6, 30
    ctx->r24 = S32(ctx->r14 << 30);
    // 0x80800098: bgez        $t8, L_808000F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080009C: nop
    
            goto L_808000F0;
    }
    // 0x8080009C: nop

    // 0x808000A0: jal         0x80800050
    // 0x808000A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800050_gspropprop(rdram, ctx);
        goto after_0;
    // 0x808000A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000B4: lbu         $t9, 0xA($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XA);
    // 0x808000B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808000BC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808000C0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x808000C4: bgez        $t9, L_808000D8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808000C8: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_808000D8;
    }
    // 0x808000C8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808000CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808000D0: nop

    // 0x808000D4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_808000D8:
    // 0x808000D8: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808000DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2874, 0X6A0) << 16);
    // 0x808000E0: lwc1        $f4, 0x6A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2874, 0X6A0));
    // 0x808000E4: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808000E8: b           L_80800148
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800148;
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F0:
    // 0x808000F0: jal         0x8080001C
    // 0x808000F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080001C_gspropprop(rdram, ctx);
        goto after_1;
    // 0x808000F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808000F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800100: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800104: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80800108: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080010C: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800110: sll         $t1, $t0, 22
    ctx->r9 = S32(ctx->r8 << 22);
    // 0x80800114: srl         $t2, $t1, 24
    ctx->r10 = S32(U32(ctx->r9) >> 24);
    // 0x80800118: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8080011C: bgez        $t2, L_80800130
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800120: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800130;
    }
    // 0x80800120: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800124: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800128: nop

    // 0x8080012C: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_80800130:
    // 0x80800130: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80800134: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2874, 0X6A4) << 16);
    // 0x80800138: lwc1        $f8, 0x6A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2874, 0X6A4));
    // 0x8080013C: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800140: nop

    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800148:
    // 0x80800148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080014C: jr          $ra
    // 0x80800150: nop

    return;
    // 0x80800150: nop

;}
RECOMP_FUNC void func_80804948_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080494C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804950: beq         $a0, $at, L_8080496C
    if (ctx->r4 == ctx->r1) {
        // 0x80804954: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8080496C;
    }
    // 0x80804954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804958: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080495C: beq         $a0, $at, L_8080497C
    if (ctx->r4 == ctx->r1) {
        // 0x80804960: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080497C;
    }
    // 0x80804960: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80804964: b           L_8080498C
    // 0x80804968: nop

        goto L_8080498C;
    // 0x80804968: nop

L_8080496C:
    // 0x8080496C: jal         0x800886D8
    // 0x80804970: nop

    _glglobalsettings_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80804970: nop

    after_0:
    // 0x80804974: b           L_80804990
    // 0x80804978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80804990;
    // 0x80804978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080497C:
    // 0x8080497C: jal         0x800886F8
    // 0x80804980: nop

    _glglobalsettings_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80804980: nop

    after_1:
    // 0x80804984: b           L_80804990
    // 0x80804988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80804990;
    // 0x80804988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080498C:
    // 0x8080498C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804990:
    // 0x80804990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804994: jr          $ra
    // 0x80804998: nop

    return;
    // 0x80804998: nop

;}
RECOMP_FUNC void func_800BFD6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFD6C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800BFD70: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x800BFD74: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800BFD78: addiu       $s7, $s7, -0x7890
    ctx->r23 = ADD32(ctx->r23, -0X7890);
    // 0x800BFD7C: lw          $t6, 0x10($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X10);
    // 0x800BFD80: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800BFD84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BFD88: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800BFD8C: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x800BFD90: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800BFD94: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800BFD98: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800BFD9C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800BFDA0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800BFDA4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800BFDA8: beq         $t6, $zero, L_800BFEF8
    if (ctx->r14 == 0) {
        // 0x800BFDAC: sw          $a1, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r5;
            goto L_800BFEF8;
    }
    // 0x800BFDAC: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x800BFDB0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800BFDB4: jal         0x800E3CB8
    // 0x800BFDB8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800E3CB8(rdram, ctx);
        goto after_0;
    // 0x800BFDB8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x800BFDBC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800BFDC0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800BFDC4: jal         0x800E3C8C
    // 0x800BFDC8: lwc1        $f14, 0x130($s7)
    ctx->f14.u32l = MEM_W(ctx->r23, 0X130);
    func_800E3C8C(rdram, ctx);
        goto after_1;
    // 0x800BFDC8: lwc1        $f14, 0x130($s7)
    ctx->f14.u32l = MEM_W(ctx->r23, 0X130);
    after_1:
    // 0x800BFDCC: addiu       $s6, $sp, 0x68
    ctx->r22 = ADD32(ctx->r29, 0X68);
    // 0x800BFDD0: jal         0x800E3980
    // 0x800BFDD4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800E3980(rdram, ctx);
        goto after_2;
    // 0x800BFDD4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x800BFDD8: jal         0x800E44FC
    // 0x800BFDDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E44FC(rdram, ctx);
        goto after_3;
    // 0x800BFDDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800BFDE0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BFDE4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800BFDE8: addiu       $s1, $s1, -0x7890
    ctx->r17 = ADD32(ctx->r17, -0X7890);
    // 0x800BFDEC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BFDF0: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800BFDF4: addiu       $s4, $sp, 0x5C
    ctx->r20 = ADD32(ctx->r29, 0X5C);
L_800BFDF8:
    // 0x800BFDF8: lw          $t7, 0x10($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X10);
    // 0x800BFDFC: beql        $t7, $zero, L_800BFEE4
    if (ctx->r15 == 0) {
        // 0x800BFE00: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800BFEE4;
    }
    goto skip_0;
    // 0x800BFE00: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800BFE04: lwc1        $f4, 0x120($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X120);
    // 0x800BFE08: lwc1        $f6, 0x134($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X134);
    // 0x800BFE0C: sll         $t8, $s2, 3
    ctx->r24 = S32(ctx->r18 << 3);
    // 0x800BFE10: sll         $t9, $s2, 3
    ctx->r25 = S32(ctx->r18 << 3);
    // 0x800BFE14: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800BFE18: swc1        $f20, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f20.u32l;
    // 0x800BFE1C: swc1        $f20, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f20.u32l;
    // 0x800BFE20: addu        $s0, $s7, $t9
    ctx->r16 = ADD32(ctx->r23, ctx->r25);
    // 0x800BFE24: addu        $s3, $s7, $t8
    ctx->r19 = ADD32(ctx->r23, ctx->r24);
    // 0x800BFE28: jal         0x800BFD00
    // 0x800BFE2C: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    func_800BFD00(rdram, ctx);
        goto after_4;
    // 0x800BFE2C: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x800BFE30: jal         0x800DF738
    // 0x800BFE34: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800DF738(rdram, ctx);
        goto after_5;
    // 0x800BFE34: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x800BFE38: jal         0x800DF7DC
    // 0x800BFE3C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    func_800DF7DC(rdram, ctx);
        goto after_6;
    // 0x800BFE3C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    after_6:
    // 0x800BFE40: lw          $t0, 0x138($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X138);
    // 0x800BFE44: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BFE48: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x800BFE4C: jal         0x800DF818
    // 0x800BFE50: lw          $a0, 0x20($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X20);
    func_800DF818(rdram, ctx);
        goto after_7;
    // 0x800BFE50: lw          $a0, 0x20($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X20);
    after_7:
    // 0x800BFE54: jal         0x800DF4B0
    // 0x800BFE58: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800DF4B0(rdram, ctx);
        goto after_8;
    // 0x800BFE58: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x800BFE5C: lw          $t3, 0x10($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X10);
    // 0x800BFE60: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800BFE64: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800BFE68: lw          $a2, 0x128($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X128);
    // 0x800BFE6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BFE70: jal         0x800DE448
    // 0x800BFE74: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800DE448(rdram, ctx);
        goto after_9;
    // 0x800BFE74: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_9:
    // 0x800BFE78: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x800BFE7C: beql        $t4, $zero, L_800BFEE4
    if (ctx->r12 == 0) {
        // 0x800BFE80: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800BFEE4;
    }
    goto skip_1;
    // 0x800BFE80: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x800BFE84: jal         0x800EA340
    // 0x800BFE88: nop

    func_800EA340(rdram, ctx);
        goto after_10;
    // 0x800BFE88: nop

    after_10:
    // 0x800BFE8C: beql        $v0, $zero, L_800BFEE4
    if (ctx->r2 == 0) {
        // 0x800BFE90: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800BFEE4;
    }
    goto skip_2;
    // 0x800BFE90: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x800BFE94: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x800BFE98: beql        $s0, $zero, L_800BFEC0
    if (ctx->r16 == 0) {
        // 0x800BFE9C: lw          $t8, 0x138($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X138);
            goto L_800BFEC0;
    }
    goto skip_3;
    // 0x800BFE9C: lw          $t8, 0x138($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X138);
    skip_3:
    // 0x800BFEA0: lw          $t5, 0x138($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X138);
    // 0x800BFEA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BFEA8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800BFEAC: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x800BFEB0: jal         0x80088690
    // 0x800BFEB4: lw          $a1, 0x20($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X20);
    _glid_entrypoint_6(rdram, ctx);
        goto after_11;
    // 0x800BFEB4: lw          $a1, 0x20($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X20);
    after_11:
    // 0x800BFEB8: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x800BFEBC: lw          $t8, 0x138($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X138);
L_800BFEC0:
    // 0x800BFEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BFEC4: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x800BFEC8: beq         $s0, $zero, L_800BFEE0
    if (ctx->r16 == 0) {
        // 0x800BFECC: sw          $t9, 0x138($s1)
        MEM_W(0X138, ctx->r17) = ctx->r25;
            goto L_800BFEE0;
    }
    // 0x800BFECC: sw          $t9, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->r25;
    // 0x800BFED0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800BFED4: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x800BFED8: jal         0x80088688
    // 0x800BFEDC: lw          $a1, 0x20($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X20);
    _glid_entrypoint_5(rdram, ctx);
        goto after_12;
    // 0x800BFEDC: lw          $a1, 0x20($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X20);
    after_12:
L_800BFEE0:
    // 0x800BFEE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800BFEE4:
    // 0x800BFEE4: bne         $s2, $s5, L_800BFDF8
    if (ctx->r18 != ctx->r21) {
        // 0x800BFEE8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800BFDF8;
    }
    // 0x800BFEE8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800BFEEC: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800BFEF0: jal         0x800E3C8C
    // 0x800BFEF4: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    func_800E3C8C(rdram, ctx);
        goto after_13;
    // 0x800BFEF4: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    after_13:
L_800BFEF8:
    // 0x800BFEF8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800BFEFC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800BFF00: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800BFF04: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800BFF08: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800BFF0C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800BFF10: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800BFF14: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800BFF18: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x800BFF1C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x800BFF20: jr          $ra
    // 0x800BFF24: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800BFF24: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80800300_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800300: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800308: jal         0x80800078
    // 0x8080030C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800078_chcredits(rdram, ctx);
        goto after_0;
    // 0x8080030C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800310: beq         $v0, $zero, L_80800328
    if (ctx->r2 == 0) {
        // 0x80800314: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80800328;
    }
    // 0x80800314: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800318: jal         0x808000E8
    // 0x8080031C: nop

    func_808000E8_chcredits(rdram, ctx);
        goto after_1;
    // 0x8080031C: nop

    after_1:
    // 0x80800320: b           L_80800380
    // 0x80800324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800380;
    // 0x80800324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800328:
    // 0x80800328: jal         0x80800000
    // 0x8080032C: lbu         $a0, 0x7610($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7610);
    func_80800000_chcredits(rdram, ctx);
        goto after_2;
    // 0x8080032C: lbu         $a0, 0x7610($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7610);
    after_2:
    // 0x80800330: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80800334: addiu       $v1, $v1, 0x7610
    ctx->r3 = ADD32(ctx->r3, 0X7610);
    // 0x80800338: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8080033C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800340: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800344: jal         0x800EA05C
    // 0x80800348: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x80800348: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    after_3:
    // 0x8080034C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800350: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800354: beq         $v0, $a0, L_8080036C
    if (ctx->r2 == ctx->r4) {
        // 0x80800358: nop
    
            goto L_8080036C;
    }
    // 0x80800358: nop

    // 0x8080035C: jal         0x80088868
    // 0x80800360: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_4;
    // 0x80800360: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_4:
    // 0x80800364: b           L_80800380
    // 0x80800368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800380;
    // 0x80800368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080036C:
    // 0x8080036C: jal         0x80085710
    // 0x80800370: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80800370: nop

    after_5:
    // 0x80800374: jal         0x808002A4
    // 0x80800378: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808002A4_chcredits(rdram, ctx);
        goto after_6;
    // 0x80800378: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x8080037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800380:
    // 0x80800380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800384: jr          $ra
    // 0x80800388: nop

    return;
    // 0x80800388: nop

;}
RECOMP_FUNC void glintrosyncDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080038C: jal         0x800C954C
    // 0x80800390: nop

    func_800C954C(rdram, ctx);
        goto after_0;
    // 0x80800390: nop

    after_0:
    // 0x80800394: beq         $v0, $zero, L_808003B8
    if (ctx->r2 == 0) {
        // 0x80800398: nop
    
            goto L_808003B8;
    }
    // 0x80800398: nop

    // 0x8080039C: jal         0x800D8FF8
    // 0x808003A0: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808003A0: nop

    after_1:
    // 0x808003A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808003A8: lwc1        $f4, 0x75DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X75DC);
    // 0x808003AC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808003B0: b           L_808003D4
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003D4;
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B8:
    // 0x808003B8: jal         0x800D9004
    // 0x808003BC: nop

    func_800D9004(rdram, ctx);
        goto after_2;
    // 0x808003BC: nop

    after_2:
    // 0x808003C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808003C4: lwc1        $f6, 0x75DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X75DC);
    // 0x808003C8: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808003CC: nop

    // 0x808003D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003D4:
    // 0x808003D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003D8: jr          $ra
    // 0x808003DC: nop

    return;
    // 0x808003DC: nop

;}
RECOMP_FUNC void _badialog_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847E0: syscall     121
    recomp_syscall_handler(rdram, ctx, 0x800847E0);
    return;
    // 0x800847E4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _changlerboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865A8: syscall     339
    recomp_syscall_handler(rdram, ctx, 0x800865A8);
    return;
    // 0x800865AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808009D8_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009D8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x808009DC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808009E0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x808009E4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808009E8: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x808009EC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808009F0: jal         0x80101F24
    // 0x808009F4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    func_80101F24(rdram, ctx);
        goto after_0;
    // 0x808009F4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    after_0:
    // 0x808009F8: addiu       $s0, $sp, 0x8C
    ctx->r16 = ADD32(ctx->r29, 0X8C);
    // 0x808009FC: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x80800A00: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80800A04: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800A08: jal         0x8008A0E8
    // 0x80800A0C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800A0C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80800A10: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1284, 0X16A4) << 16);
    // 0x80800A14: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1284, 0X16C4) << 16);
    // 0x80800A18: addiu       $a3, $a3, 0x16C4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1284, 0X16C4));
    // 0x80800A1C: addiu       $a2, $a2, 0x16A4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1284, 0X16A4));
    // 0x80800A20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A24: jal         0x80089D28
    // 0x80800A28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800A28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800A2C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1284, 0X16B4) << 16);
    // 0x80800A30: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1284, 0X16DC) << 16);
    // 0x80800A34: addiu       $a3, $a3, 0x16DC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1284, 0X16DC));
    // 0x80800A38: addiu       $a2, $a2, 0x16B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1284, 0X16B4));
    // 0x80800A3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A40: jal         0x80089D28
    // 0x80800A44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800A44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800A48: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80800A4C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800A50: jal         0x8008A0E0
    // 0x80800A54: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800A54: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    after_4:
    // 0x80800A58: beq         $v0, $zero, L_80800AE8
    if (ctx->r2 == 0) {
        // 0x80800A5C: lwc1        $f4, 0x80($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
            goto L_80800AE8;
    }
    // 0x80800A5C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800A60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X1458) << 16);
    // 0x80800A64: lwc1        $f6, 0x1458($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1284, 0X1458));
    // 0x80800A68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800A6C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800A70: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800A74: nop

    // 0x80800A78: bc1f        L_80800AE8
    if (!c1cs) {
        // 0x80800A7C: nop
    
            goto L_80800AE8;
    }
    // 0x80800A7C: nop

    // 0x80800A80: jal         0x8008A0E0
    // 0x80800A84: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800A84: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_5:
    // 0x80800A88: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X145C) << 16);
    // 0x80800A8C: lwc1        $f8, 0x145C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1284, 0X145C));
    // 0x80800A90: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1284, 0X14B0) << 16);
    // 0x80800A94: addiu       $s1, $s1, 0x14B0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1284, 0X14B0));
    // 0x80800A98: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800AA4: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x80800AA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800AAC: jal         0x800BBCB8
    // 0x80800AB0: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    func_800BBCB8(rdram, ctx);
        goto after_6;
    // 0x80800AB0: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x80800AB4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80800AB8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800ABC: jal         0x8008A0E0
    // 0x80800AC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800AC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80800AC4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X1460) << 16);
    // 0x80800AC8: lwc1        $f10, 0x1460($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1284, 0X1460));
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800AD4: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x80800AD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800ADC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80800AE0: jal         0x800BBCB8
    // 0x80800AE4: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    func_800BBCB8(rdram, ctx);
        goto after_8;
    // 0x80800AE4: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    after_8:
L_80800AE8:
    // 0x80800AE8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X1464) << 16);
    // 0x80800AEC: lwc1        $f16, 0x1464($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1284, 0X1464));
    // 0x80800AF0: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80800AF4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800AF8: nop

    // 0x80800AFC: bc1fl       L_80800C60
    if (!c1cs) {
        // 0x80800B00: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800C60;
    }
    goto skip_0;
    // 0x80800B00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80800B04: lw          $t6, 0x7C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X7C);
    // 0x80800B08: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X1468) << 16);
    // 0x80800B0C: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800B10: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800B14: bgezl       $t8, L_80800C60
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800B18: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800C60;
    }
    goto skip_1;
    // 0x80800B18: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80800B1C: lwc1        $f4, 0x1468($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1284, 0X1468));
    // 0x80800B20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B24: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800B28: nop

    // 0x80800B2C: bc1fl       L_80800C60
    if (!c1cs) {
        // 0x80800B30: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800C60;
    }
    goto skip_2;
    // 0x80800B30: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80800B34: jal         0x800DC128
    // 0x80800B38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_9;
    // 0x80800B38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800B3C: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80800B40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800B44: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // 0x80800B48: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_80800B4C:
    // 0x80800B4C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80800B50: addiu       $a1, $s0, 0x5
    ctx->r5 = ADD32(ctx->r16, 0X5);
    // 0x80800B54: jal         0x8008A0E0
    // 0x80800B58: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800B58: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_10:
    // 0x80800B5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800B60: bne         $s0, $s2, L_80800B4C
    if (ctx->r16 != ctx->r18) {
        // 0x80800B64: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800B4C;
    }
    // 0x80800B64: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80800B68: jal         0x800B53A4
    // 0x80800B6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_11;
    // 0x80800B6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80800B70: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800B74: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800B78: lwc1        $f0, 0x48($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X48);
    // 0x80800B7C: addiu       $t3, $zero, -0x19
    ctx->r11 = ADD32(0, -0X19);
    // 0x80800B80: addiu       $t6, $zero, 0x4B
    ctx->r14 = ADD32(0, 0X4B);
    // 0x80800B84: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80800B88: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B8C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80800B90: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80800B94: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800B98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B9C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800BA0: addiu       $a1, $zero, -0x2D
    ctx->r5 = ADD32(0, -0X2D);
    // 0x80800BA4: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x80800BA8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800BAC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800BB0: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80800BB4: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x80800BB8: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80800BBC: jal         0x800BA994
    // 0x80800BC0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_800BA994(rdram, ctx);
        goto after_12;
    // 0x80800BC0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_12:
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC8: jal         0x800BA5A8
    // 0x80800BCC: addiu       $a1, $zero, 0x1200
    ctx->r5 = ADD32(0, 0X1200);
    func_800BA5A8(rdram, ctx);
        goto after_13;
    // 0x80800BCC: addiu       $a1, $zero, 0x1200
    ctx->r5 = ADD32(0, 0X1200);
    after_13:
    // 0x80800BD0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1284, 0X14D8) << 16);
    // 0x80800BD4: addiu       $t7, $t7, 0x14D8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1284, 0X14D8));
    // 0x80800BD8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE0: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x80800BE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800BE8: jal         0x800BABB8
    // 0x80800BEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_14;
    // 0x80800BEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_14:
    // 0x80800BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BF4: jal         0x800BA4D0
    // 0x80800BF8: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    func_800BA4D0(rdram, ctx);
        goto after_15;
    // 0x80800BF8: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_15:
    // 0x80800BFC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800C00: addiu       $a1, $a1, 0x6488
    ctx->r5 = ADD32(ctx->r5, 0X6488);
    // 0x80800C04: jal         0x800BA544
    // 0x80800C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BA544(rdram, ctx);
        goto after_16;
    // 0x80800C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800C0C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80800C10: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1284, 0X16E8) << 16);
    // 0x80800C14: addiu       $t1, $t1, 0x16E8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1284, 0X16E8));
    // 0x80800C18: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80800C1C: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80800C20: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80800C24: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80800C28: lbu         $t4, 0x1($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1);
    // 0x80800C2C: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800C30: addiu       $v1, $sp, 0x48
    ctx->r3 = ADD32(ctx->r29, 0X48);
    // 0x80800C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800C3C: mflo        $t3
    ctx->r11 = lo;
    // 0x80800C40: addu        $a1, $v1, $t3
    ctx->r5 = ADD32(ctx->r3, ctx->r11);
    // 0x80800C44: nop

    // 0x80800C48: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800C4C: mflo        $t5
    ctx->r13 = lo;
    // 0x80800C50: addu        $a2, $v1, $t5
    ctx->r6 = ADD32(ctx->r3, ctx->r13);
    // 0x80800C54: jal         0x800BA1D0
    // 0x80800C58: nop

    func_800BA1D0(rdram, ctx);
        goto after_17;
    // 0x80800C58: nop

    after_17:
    // 0x80800C5C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800C60:
    // 0x80800C60: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800C64: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800C68: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C6C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800C70: jr          $ra
    // 0x80800C74: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80800C74: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8001D31C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D31C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001D320: addiu       $v0, $v0, -0x8A0
    ctx->r2 = ADD32(ctx->r2, -0X8A0);
    // 0x8001D324: jr          $ra
    // 0x8001D328: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    return;
    // 0x8001D328: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
;}
RECOMP_FUNC void func_808007B0_chmricecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808007B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007B8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808007BC: jal         0x800D90A4
    // 0x808007C0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x808007C0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x808007C4: beq         $v0, $zero, L_80800840
    if (ctx->r2 == 0) {
        // 0x808007C8: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_80800840;
    }
    // 0x808007C8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808007CC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808007D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808007D4: jal         0x800EE7F8
    // 0x808007D8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808007D8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x808007DC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808007E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808007E8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808007EC: jal         0x800EE7F8
    // 0x808007F0: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808007F0: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808007F4: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808007F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007FC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800800: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1224, 0X9C8) << 16);
    // 0x80800804: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80800808: addiu       $t7, $t7, 0x9C8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1224, 0X9C8));
    // 0x8080080C: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80800810: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800814: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800818: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080081C: jal         0x800BBCB8
    // 0x80800820: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800820: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_3:
    // 0x80800824: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1224, 0X8A8) << 16);
    // 0x80800828: lwc1        $f12, 0x8A8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1224, 0X8A8));
    // 0x8080082C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1224, 0X8AC) << 16);
    // 0x80800830: jal         0x800DC178
    // 0x80800834: lwc1        $f14, 0x8AC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1224, 0X8AC));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800834: lwc1        $f14, 0x8AC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1224, 0X8AC));
    after_4:
    // 0x80800838: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8080083C: swc1        $f0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f0.u32l;
L_80800840:
    // 0x80800840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800844: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800848: jr          $ra
    // 0x8080084C: nop

    return;
    // 0x8080084C: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088800: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088800);
    return;
    // 0x80088804: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _subaddiedialog_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A218: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A218);
    return;
    // 0x8008A21C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_800DFB40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFB40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DFB44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFB48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DFB4C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800DFB50: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800DFB54: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800DFB58: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x800DFB5C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800DFB60: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800DFB64: jal         0x800D9600
    // 0x800DFB68: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    func_800D9600(rdram, ctx);
        goto after_0;
    // 0x800DFB68: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    after_0:
    // 0x800DFB6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFB70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DFB74: jr          $ra
    // 0x800DFB78: nop

    return;
    // 0x800DFB78: nop

;}
RECOMP_FUNC void func_8080000C_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80108B04
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void func_80800000_bssilowait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80092880
    // 0x80800010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80092880(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800014: jal         0x80091E6C
    // 0x80800018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80091E6C(rdram, ctx);
        goto after_1;
    // 0x80800018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080001C: jal         0x8009BC6C
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800024: jal         0x8009BC90
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037774: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80037778: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8003777C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037780: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80037784: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80037788: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8003778C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80037790: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80037794: jal         0x8002F54C
    // 0x80037798: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x80037798: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x8003779C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800377A0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800377A4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800377A8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800377AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800377B0: jal         0x8002F5A8
    // 0x800377B4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800377B4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x800377B8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800377BC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800377C0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800377C4: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x800377C8: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x800377CC: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x800377D0: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x800377D4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800377D8: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800377DC: bgtz        $t0, L_8003783C
    if (SIGNED(ctx->r8) > 0) {
        // 0x800377E0: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_8003783C;
    }
    // 0x800377E0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800377E4: bltz        $t0, L_800377F4
    if (SIGNED(ctx->r8) < 0) {
        // 0x800377E8: nop
    
            goto L_800377F4;
    }
    // 0x800377E8: nop

    // 0x800377EC: b           L_80037840
    // 0x800377F0: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_80037840;
    // 0x800377F0: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800377F4:
    // 0x800377F4: bltzl       $t8, L_80037840
    if (SIGNED(ctx->r24) < 0) {
        // 0x800377F8: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_80037840;
    }
    goto skip_0;
    // 0x800377F8: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x800377FC: bgtz        $t8, L_8003780C
    if (SIGNED(ctx->r24) > 0) {
        // 0x80037800: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_8003780C;
    }
    // 0x80037800: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80037804: beql        $t9, $zero, L_80037840
    if (ctx->r25 == 0) {
        // 0x80037808: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_80037840;
    }
    goto skip_1;
    // 0x80037808: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_8003780C:
    // 0x8003780C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80037810: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80037814: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80037818: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x8003781C: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x80037820: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x80037824: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x80037828: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x8003782C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80037830: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80037834: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80037838: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_8003783C:
    // 0x8003783C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_80037840:
    // 0x80037840: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80037844: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80037848: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x8003784C: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80037850: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80037854: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80037858: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x8003785C: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x80037860: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x80037864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037868: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003786C: jr          $ra
    // 0x80037870: nop

    return;
    // 0x80037870: nop

;}
RECOMP_FUNC void _chlagoonbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FB8: syscall     268
    recomp_syscall_handler(rdram, ctx, 0x80085FB8);
    return;
    // 0x80085FBC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080169C_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080169C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808016A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808016A4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808016A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808016AC: beq         $a1, $zero, L_808016C4
    if (ctx->r5 == 0) {
        // 0x808016B0: sw          $a0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r4;
            goto L_808016C4;
    }
    // 0x808016B0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808016B4: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x808016B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808016BC: b           L_808016D4
    // 0x808016C0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
        goto L_808016D4;
    // 0x808016C0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
L_808016C4:
    // 0x808016C4: lui         $at, 0xC268
    ctx->r1 = S32(0XC268 << 16);
    // 0x808016C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808016CC: nop

    // 0x808016D0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
L_808016D4:
    // 0x808016D4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808016D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808016DC: lw          $a1, 0x44($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X44);
    // 0x808016E0: lw          $a2, 0x48($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X48);
    // 0x808016E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016E8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x808016EC: jal         0x800EF4E4
    // 0x808016F0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_0;
    // 0x808016F0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x808016F4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x808016F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016FC: jal         0x800EF04C
    // 0x80801700: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x80801700: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80801704: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80801708: jal         0x800EE7F8
    // 0x8080170C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080170C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80801710: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80801714: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801718: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080171C: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x80801720: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80801724: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80801728: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8080172C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801730: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80801734: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80801738: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080173C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80801740: jal         0x800BEF00
    // 0x80801744: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    func_800BEF00(rdram, ctx);
        goto after_3;
    // 0x80801744: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x80801748: bne         $v0, $zero, L_80801758
    if (ctx->r2 != 0) {
        // 0x8080174C: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80801758;
    }
    // 0x8080174C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80801750: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80801754: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
L_80801758:
    // 0x80801758: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080175C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801760: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801764: jr          $ra
    // 0x80801768: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80801768: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80015F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015F5C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015F60: addiu       $v0, $v0, -0x6540
    ctx->r2 = ADD32(ctx->r2, -0X6540);
    // 0x80015F64: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80015F68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80015F6C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80015F70: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x80015F74: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80015F78: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x80015F7C: jr          $ra
    // 0x80015F80: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    return;
    // 0x80015F80: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void _bsbanbflip_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082688: syscall     5
    recomp_syscall_handler(rdram, ctx, 0x80082688);
    return;
    // 0x8008268C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _idworldmake_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F38: syscall     749
    recomp_syscall_handler(rdram, ctx, 0x80088F38);
    return;
    // 0x80088F3C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chperspexbox_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871A0: syscall     530
    recomp_syscall_handler(rdram, ctx, 0x800871A0);
    return;
    // 0x800871A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800BFAA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFAA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BFAA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BFAAC: jal         0x800BF704
    // 0x800BFAB0: nop

    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x800BFAB0: nop

    after_0:
    // 0x800BFAB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BFAB8: lbu         $v0, 0x77($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X77);
    // 0x800BFABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BFAC0: jr          $ra
    // 0x800BFAC4: nop

    return;
    // 0x800BFAC4: nop

    // 0x800BFAC8: nop

    // 0x800BFACC: nop

;}
RECOMP_FUNC void _bskazmove_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083500: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x80083500);
    return;
    // 0x80083504: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
