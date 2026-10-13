#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _mlwave_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FE0: syscall     754
    recomp_syscall_handler(rdram, ctx, 0x80088FE0);
    return;
    // 0x80088FE4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800978_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800978: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x8080097C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA3CC) << 16);
    // 0x80800980: lwc1        $f6, -0x5C34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA3CC));
    // 0x80800984: lwc1        $f4, 0xC8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80800988: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080098C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA3D0) << 16);
    // 0x80800990: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800994: lwc1        $f10, -0x5C30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA3D0));
    // 0x80800998: lwc1        $f8, 0xCC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XCC);
    // 0x8080099C: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808009A0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x808009A4: nop

    // 0x808009A8: bc1fl       L_808009C0
    if (!c1cs) {
        // 0x808009AC: lwc1        $f12, 0x38($a1)
        ctx->f12.u32l = MEM_W(ctx->r5, 0X38);
            goto L_808009C0;
    }
    goto skip_0;
    // 0x808009AC: lwc1        $f12, 0x38($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X38);
    skip_0:
    // 0x808009B0: lwc1        $f12, 0x34($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X34);
    // 0x808009B4: b           L_808009C0
    // 0x808009B8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_808009C0;
    // 0x808009B8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x808009BC: lwc1        $f12, 0x38($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X38);
L_808009C0:
    // 0x808009C0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x808009C4: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x808009C8: bc1fl       L_808009E0
    if (!c1cs) {
        // 0x808009CC: lwc1        $f12, 0x40($a1)
        ctx->f12.u32l = MEM_W(ctx->r5, 0X40);
            goto L_808009E0;
    }
    goto skip_1;
    // 0x808009CC: lwc1        $f12, 0x40($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X40);
    skip_1:
    // 0x808009D0: lwc1        $f12, 0x3C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x808009D4: b           L_808009E0
    // 0x808009D8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_808009E0;
    // 0x808009D8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x808009DC: lwc1        $f12, 0x40($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X40);
L_808009E0:
    // 0x808009E0: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x808009E4: lwc1        $f16, 0x30($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X30);
    // 0x808009E8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808009EC: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x808009F0: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x808009F4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x808009F8: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x808009FC: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800A00: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80800A04: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x80800A08: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80800A0C: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80800A10: jr          $ra
    // 0x80800A14: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    return;
    // 0x80800A14: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
;}
RECOMP_FUNC void chexploder_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808011DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808011E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808011E8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808011EC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808011F0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808011F4: jal         0x80106790
    // 0x808011F8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808011F8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x808011FC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80801200: addiu       $a0, $zero, 0x1FF
    ctx->r4 = ADD32(0, 0X1FF);
    // 0x80801204: jal         0x801084B0
    // 0x80801208: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x80801208: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x8080120C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801214: jal         0x80100094
    // 0x80801218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80801218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080121C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801220: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801224: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80801228: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x8080122C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80801230: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x80801234: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801238: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x8080123C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80801240: jal         0x800EE7F8
    // 0x80801244: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80801244: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_3:
    // 0x80801248: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8080124C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80801250: lwc1        $f10, 0x38($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80801254: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x80801258: lh          $t8, 0x10($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X10);
    // 0x8080125C: bnel        $t8, $zero, L_80801278
    if (ctx->r24 != 0) {
        // 0x80801260: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_80801278;
    }
    goto skip_0;
    // 0x80801260: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80801264: jal         0x800AE020
    // 0x80801268: nop

    func_800AE020(rdram, ctx);
        goto after_4;
    // 0x80801268: nop

    after_4:
    // 0x8080126C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80801270: sh          $v0, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r2;
    // 0x80801274: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_80801278:
    // 0x80801278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080127C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80801280: lhu         $t2, 0x14($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X14);
    // 0x80801284: sh          $t2, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r10;
    // 0x80801288: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8080128C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80801290: lhu         $t5, 0x16($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X16);
    // 0x80801294: sh          $t5, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r13;
    // 0x80801298: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8080129C: sh          $t6, 0x54($s1)
    MEM_H(0X54, ctx->r17) = ctx->r14;
    // 0x808012A0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x808012A4: lbu         $t8, 0x65($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X65);
    // 0x808012A8: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x808012AC: sb          $t9, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r25;
    // 0x808012B0: jal         0x80108944
    // 0x808012B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80108944(rdram, ctx);
        goto after_5;
    // 0x808012B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x808012B8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x808012BC: jal         0x801039E4
    // 0x808012C0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_801039E4(rdram, ctx);
        goto after_6;
    // 0x808012C0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_6:
    // 0x808012C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808012CC: jal         0x80801188
    // 0x808012D0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_80801188_chexploder(rdram, ctx);
        goto after_7;
    // 0x808012D0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x808012D4: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    // 0x808012D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012DC: andi        $t2, $t1, 0xFFFD
    ctx->r10 = ctx->r9 & 0XFFFD;
    // 0x808012E0: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
    // 0x808012E4: lhu         $a2, 0x16($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X16);
    // 0x808012E8: jal         0x80103140
    // 0x808012EC: lhu         $a1, 0x14($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X14);
    func_80103140(rdram, ctx);
        goto after_8;
    // 0x808012EC: lhu         $a1, 0x14($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X14);
    after_8:
    // 0x808012F0: jal         0x80800A18
    // 0x808012F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A18_chexploder(rdram, ctx);
        goto after_9;
    // 0x808012F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808012F8: jal         0x80104248
    // 0x808012FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80104248(rdram, ctx);
        goto after_10;
    // 0x808012FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x80801300: beq         $v0, $zero, L_80801324
    if (ctx->r2 == 0) {
        // 0x80801304: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801324;
    }
    // 0x80801304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080130C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80801310: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x80801314: jal         0x80800AC8
    // 0x80801318: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_80800AC8_chexploder(rdram, ctx);
        goto after_11;
    // 0x80801318: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_11:
    // 0x8080131C: b           L_80801334
    // 0x80801320: nop

        goto L_80801334;
    // 0x80801320: nop

L_80801324:
    // 0x80801324: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80801328: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x8080132C: jal         0x80800D7C
    // 0x80801330: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_80800D7C_chexploder(rdram, ctx);
        goto after_12;
    // 0x80801330: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_12:
L_80801334:
    // 0x80801334: jal         0x80101074
    // 0x80801338: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80101074(rdram, ctx);
        goto after_13;
    // 0x80801338: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_13:
    // 0x8080133C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801340: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // 0x80801344: jal         0x8010108C
    // 0x80801348: lhu         $a2, 0x14($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X14);
    func_8010108C(rdram, ctx);
        goto after_14;
    // 0x80801348: lhu         $a2, 0x14($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X14);
    after_14:
    // 0x8080134C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801350: jal         0x80800F74
    // 0x80801354: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800F74_chexploder(rdram, ctx);
        goto after_15;
    // 0x80801354: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_15:
    // 0x80801358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080135C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80801360: jal         0x808010E0
    // 0x80801364: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    func_808010E0_chexploder(rdram, ctx);
        goto after_16;
    // 0x80801364: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_16:
    // 0x80801368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080136C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801370: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801374: jr          $ra
    // 0x80801378: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801378: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void gsmaker_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080033C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800340: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800344: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800348: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8080034C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800350: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800354: blez        $a2, L_80800374
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800358: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80800374;
    }
    // 0x80800358: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_8080035C:
    // 0x8080035C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800360: jal         0x80800318
    // 0x80800364: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gsmaker_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800364: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80800368: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8080036C: bgtz        $s0, L_8080035C
    if (SIGNED(ctx->r16) > 0) {
        // 0x80800370: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8080035C;
    }
    // 0x80800370: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80800374:
    // 0x80800374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800380: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800384: jr          $ra
    // 0x80800388: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800388: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bsbansnooze_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082750: syscall     9
    recomp_syscall_handler(rdram, ctx, 0x80082750);
    return;
    // 0x80082754: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bsbtrot_entrypoint_38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080234C: jal         0x80082FF0
    // 0x80802350: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80802350: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802354: jal         0x8080061C
    // 0x80802358: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080061C_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802358: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080235C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802364: jr          $ra
    // 0x80802368: nop

    return;
    // 0x80802368: nop

;}
RECOMP_FUNC void scinfobar_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800510: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x80800514: beql        $t6, $zero, L_80800528
    if (ctx->r14 == 0) {
        // 0x80800518: sw          $a1, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->r5;
            goto L_80800528;
    }
    goto skip_0;
    // 0x80800518: sw          $a1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r5;
    skip_0:
    // 0x8080051C: jr          $ra
    // 0x80800520: sh          $a1, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r5;
    return;
    // 0x80800520: sh          $a1, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r5;
    // 0x80800524: sw          $a1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r5;
L_80800528:
    // 0x80800528: jr          $ra
    // 0x8080052C: nop

    return;
    // 0x8080052C: nop

;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800376F0: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x800376F4: mflo        $v0
    ctx->r2 = lo;
    // 0x800376F8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800376FC: bne         $a2, $zero, L_80037708
    if (ctx->r6 != 0) {
        // 0x80037700: nop
    
            goto L_80037708;
    }
    // 0x80037700: nop

    // 0x80037704: break       7
    do_break(2147710724);
L_80037708:
    // 0x80037708: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003770C: bne         $a2, $at, L_80037720
    if (ctx->r6 != ctx->r1) {
        // 0x80037710: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80037720;
    }
    // 0x80037710: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80037714: bne         $a1, $at, L_80037720
    if (ctx->r5 != ctx->r1) {
        // 0x80037718: nop
    
            goto L_80037720;
    }
    // 0x80037718: nop

    // 0x8003771C: break       6
    do_break(2147710748);
L_80037720:
    // 0x80037720: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037724: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x80037728: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x8003772C: mflo        $t6
    ctx->r14 = lo;
    // 0x80037730: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x80037734: bgez        $v0, L_80037758
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80037738: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_80037758;
    }
    // 0x80037738: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x8003773C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x80037740: blez        $v1, L_80037758
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80037744: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_80037758;
    }
    // 0x80037744: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80037748: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003774C: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80037750: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80037754: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_80037758:
    // 0x80037758: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8003775C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80037760: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80037764: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80037768: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8003776C: jr          $ra
    // 0x80037770: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x80037770: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void chswitch_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800ADC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800AE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800AE4: jal         0x800DA298
    // 0x80800AE8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800AE8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800AEC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800AF0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800AF4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800AF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800AFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800B00: sw          $a2, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r6;
    // 0x80800B04: beq         $a2, $at, L_80800B20
    if (ctx->r6 == ctx->r1) {
        // 0x80800B08: sw          $t6, 0x34($a3)
        MEM_W(0X34, ctx->r7) = ctx->r14;
            goto L_80800B20;
    }
    // 0x80800B08: sw          $t6, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r14;
    // 0x80800B0C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800B10: jal         0x800DA524
    // 0x80800B14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x80800B14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800B18: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B1C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_80800B20:
    // 0x80800B20: beq         $v1, $zero, L_80800B30
    if (ctx->r3 == 0) {
        // 0x80800B24: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800B30;
    }
    // 0x80800B24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B28: b           L_80800B30
    // 0x80800B2C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80800B30;
    // 0x80800B2C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80800B30:
    // 0x80800B30: jal         0x80102424
    // 0x80800B34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800B34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x80800B38: jal         0x80102E08
    // 0x80800B3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80102E08(rdram, ctx);
        goto after_3;
    // 0x80800B3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B48: jr          $ra
    // 0x80800B4C: nop

    return;
    // 0x80800B4C: nop

;}
RECOMP_FUNC void chstoneballcontrol_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1608, 0X535C) << 16);
    // 0x808036B8: jr          $ra
    // 0x808036BC: addiu       $v0, $v0, 0x535C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1608, 0X535C));
    return;
    // 0x808036BC: addiu       $v0, $v0, 0x535C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1608, 0X535C));
;}
RECOMP_FUNC void func_80801248_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801248: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080124C: bne         $a2, $at, L_8080128C
    if (ctx->r6 != ctx->r1) {
        // 0x80801250: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8080128C;
    }
    // 0x80801250: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80801254: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80801258: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2658, 0X2124) << 16);
    // 0x8080125C: sltiu       $at, $v0, 0xA
    ctx->r1 = ctx->r2 < 0XA ? 1 : 0;
    // 0x80801260: beq         $at, $zero, L_808012C4
    if (ctx->r1 == 0) {
        // 0x80801264: addu        $t7, $t7, $v0
        ctx->r15 = ADD32(ctx->r15, ctx->r2);
            goto L_808012C4;
    }
    // 0x80801264: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80801268: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8080126C: lb          $t7, 0x2124($t7)
    ctx->r15 = MEM_B(ctx->r15, (int16_t)RELOC_LO16(2658, 0X2124));
    // 0x80801270: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801274: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80801278: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x8080127C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x80801280: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80801284: jr          $ra
    // 0x80801288: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
    return;
    // 0x80801288: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
L_8080128C:
    // 0x8080128C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80801290: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2658, 0X2124) << 16);
    // 0x80801294: blez        $v0, L_808012C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801298: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_808012C0;
    }
    // 0x80801298: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8080129C: sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
    // 0x808012A0: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x808012A4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x808012A8: lb          $t4, 0x2124($t4)
    ctx->r12 = MEM_B(ctx->r12, (int16_t)RELOC_LO16(2658, 0X2124));
    // 0x808012AC: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x808012B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808012B4: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x808012B8: jr          $ra
    // 0x808012BC: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    return;
    // 0x808012BC: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
L_808012C0:
    // 0x808012C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808012C4:
    // 0x808012C4: jr          $ra
    // 0x808012C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808012C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800D5AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5AB4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D5AB8: lbu         $v0, -0x481C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X481C);
    // 0x800D5ABC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D5AC0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D5AC4: blez        $v0, L_800D5B00
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D5AC8: nop
    
            goto L_800D5B00;
    }
    // 0x800D5AC8: nop

    // 0x800D5ACC: lh          $t6, -0x4920($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4920);
    // 0x800D5AD0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5AD4: addiu       $a1, $a1, -0x4920
    ctx->r5 = ADD32(ctx->r5, -0X4920);
    // 0x800D5AD8: beq         $a0, $t6, L_800D5B00
    if (ctx->r4 == ctx->r14) {
        // 0x800D5ADC: nop
    
            goto L_800D5B00;
    }
    // 0x800D5ADC: nop

    // 0x800D5AE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D5AE4:
    // 0x800D5AE4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D5AE8: beq         $at, $zero, L_800D5B00
    if (ctx->r1 == 0) {
        // 0x800D5AEC: sll         $t7, $v1, 1
        ctx->r15 = S32(ctx->r3 << 1);
            goto L_800D5B00;
    }
    // 0x800D5AEC: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800D5AF0: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800D5AF4: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800D5AF8: bnel        $a0, $t9, L_800D5AE4
    if (ctx->r4 != ctx->r25) {
        // 0x800D5AFC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D5AE4;
    }
    goto skip_0;
    // 0x800D5AFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_800D5B00:
    // 0x800D5B00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5B04: sb          $v1, -0x481B($at)
    MEM_B(-0X481B, ctx->r1) = ctx->r3;
    // 0x800D5B08: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x800D5B0C: bne         $v1, $at, L_800D5B1C
    if (ctx->r3 != ctx->r1) {
        // 0x800D5B10: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800D5B1C;
    }
    // 0x800D5B10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D5B14: jr          $ra
    // 0x800D5B18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800D5B18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D5B1C:
    // 0x800D5B1C: jr          $ra
    // 0x800D5B20: nop

    return;
    // 0x800D5B20: nop

;}
RECOMP_FUNC void func_8080057C_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080057C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800584: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800588: jal         0x80801188
    // 0x8080058C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801188_chterryegg(rdram, ctx);
        goto after_0;
    // 0x8080058C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800590: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800594: jal         0x80102FDC
    // 0x80800598: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x80800598: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080059C: lui         $a1, 0x1000
    ctx->r5 = S32(0X1000 << 16);
    // 0x808005A0: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x808005A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005AC: jal         0x801088A8
    // 0x808005B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_801088A8(rdram, ctx);
        goto after_2;
    // 0x808005B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x808005B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005BC: jr          $ra
    // 0x808005C0: nop

    return;
    // 0x808005C0: nop

;}
RECOMP_FUNC void func_800129FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800129FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80012A00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012A04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80012A08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012A0C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80012A10: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80012A14: jal         0x8002E330
    // 0x80012A18: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80012A18: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80012A1C: jal         0x80012D84
    // 0x80012A20: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_80012D84(rdram, ctx);
        goto after_1;
    // 0x80012A20: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x80012A24: jal         0x8002E3B0
    // 0x80012A28: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_2;
    // 0x80012A28: nop

    after_2:
    // 0x80012A2C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80012A30: srl         $v1, $v0, 2
    ctx->r3 = S32(U32(ctx->r2) >> 2);
    // 0x80012A34: beql        $a2, $zero, L_80012A60
    if (ctx->r6 == 0) {
        // 0x80012A38: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80012A60;
    }
    goto skip_0;
    // 0x80012A38: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80012A3C: lh          $a1, 0x4($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X4);
    // 0x80012A40: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80012A44: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80012A48: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80012A4C: jal         0x8002E3C0
    // 0x80012A50: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x80012A50: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_3:
    // 0x80012A54: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80012A58: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80012A5C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80012A60:
    // 0x80012A60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012A64: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x80012A68: bne         $t7, $at, L_80012A78
    if (ctx->r15 != ctx->r1) {
        // 0x80012A6C: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80012A78;
    }
    // 0x80012A6C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80012A70: b           L_80012B60
    // 0x80012A74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012B60;
    // 0x80012A74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80012A78:
    // 0x80012A78: slti        $at, $v1, 0x5C
    ctx->r1 = SIGNED(ctx->r3) < 0X5C ? 1 : 0;
    // 0x80012A7C: beq         $at, $zero, L_80012AAC
    if (ctx->r1 == 0) {
        // 0x80012A80: addiu       $a1, $sp, 0x2C
        ctx->r5 = ADD32(ctx->r29, 0X2C);
            goto L_80012AAC;
    }
    // 0x80012A80: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80012A84: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80012A88: lw          $v0, 0x6938($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6938);
    // 0x80012A8C: addiu       $t8, $zero, 0x398
    ctx->r24 = ADD32(0, 0X398);
    // 0x80012A90: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012A94: bne         $v0, $zero, L_80012AAC
    if (ctx->r2 != 0) {
        // 0x80012A98: nop
    
            goto L_80012AAC;
    }
    // 0x80012A98: nop

    // 0x80012A9C: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x80012AA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80012AA4: b           L_80012AF0
    // 0x80012AA8: sw          $v0, 0x6938($at)
    MEM_W(0X6938, ctx->r1) = ctx->r2;
        goto L_80012AF0;
    // 0x80012AA8: sw          $v0, 0x6938($at)
    MEM_W(0X6938, ctx->r1) = ctx->r2;
L_80012AAC:
    // 0x80012AAC: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80012AB0: slti        $at, $v1, 0x115
    ctx->r1 = SIGNED(ctx->r3) < 0X115 ? 1 : 0;
    // 0x80012AB4: bne         $at, $zero, L_80012AD8
    if (ctx->r1 != 0) {
        // 0x80012AB8: lw          $v0, 0x6938($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X6938);
            goto L_80012AD8;
    }
    // 0x80012AB8: lw          $v0, 0x6938($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6938);
    // 0x80012ABC: bne         $v0, $zero, L_80012AD8
    if (ctx->r2 != 0) {
        // 0x80012AC0: addiu       $t9, $zero, 0x228
        ctx->r25 = ADD32(0, 0X228);
            goto L_80012AD8;
    }
    // 0x80012AC0: addiu       $t9, $zero, 0x228
    ctx->r25 = ADD32(0, 0X228);
    // 0x80012AC4: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x80012AC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80012ACC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012AD0: b           L_80012AF0
    // 0x80012AD4: sw          $v0, 0x6938($at)
    MEM_W(0X6938, ctx->r1) = ctx->r2;
        goto L_80012AF0;
    // 0x80012AD4: sw          $v0, 0x6938($at)
    MEM_W(0X6938, ctx->r1) = ctx->r2;
L_80012AD8:
    // 0x80012AD8: addiu       $t0, $zero, 0x2E0
    ctx->r8 = ADD32(0, 0X2E0);
    // 0x80012ADC: beq         $v0, $zero, L_80012AF0
    if (ctx->r2 == 0) {
        // 0x80012AE0: sh          $t0, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r8;
            goto L_80012AF0;
    }
    // 0x80012AE0: sh          $t0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r8;
    // 0x80012AE4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80012AE8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012AEC: sw          $v0, 0x6938($at)
    MEM_W(0X6938, ctx->r1) = ctx->r2;
L_80012AF0:
    // 0x80012AF0: lw          $t1, -0x5EB0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5EB0);
    // 0x80012AF4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80012AF8: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x80012AFC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80012B00: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80012B04: jal         0x80021574
    // 0x80012B08: lw          $a0, 0x59E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X59E0);
    func_80021574(rdram, ctx);
        goto after_4;
    // 0x80012B08: lw          $a0, 0x59E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X59E0);
    after_4:
    // 0x80012B0C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80012B10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80012B14: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x80012B18: bne         $t3, $zero, L_80012B28
    if (ctx->r11 != 0) {
        // 0x80012B1C: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80012B28;
    }
    // 0x80012B1C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80012B20: b           L_80012B60
    // 0x80012B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012B60;
    // 0x80012B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80012B28:
    // 0x80012B28: lw          $t4, -0x5EB0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5EB0);
    // 0x80012B2C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80012B30: addiu       $a2, $a2, 0x5BF0
    ctx->r6 = ADD32(ctx->r6, 0X5BF0);
    // 0x80012B34: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80012B38: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80012B3C: lw          $a0, 0x59E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X59E0);
    // 0x80012B40: jal         0x8001A148
    // 0x80012B44: addiu       $a3, $s0, 0x8
    ctx->r7 = ADD32(ctx->r16, 0X8);
    func_8001A148(rdram, ctx);
        goto after_5;
    // 0x80012B44: addiu       $a3, $s0, 0x8
    ctx->r7 = ADD32(ctx->r16, 0X8);
    after_5:
    // 0x80012B48: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80012B4C: lw          $t6, -0x5EB0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5EB0);
    // 0x80012B50: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80012B58: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80012B5C: sw          $t7, -0x5EB0($at)
    MEM_W(-0X5EB0, ctx->r1) = ctx->r15;
L_80012B60:
    // 0x80012B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80012B64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012B68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80012B6C: jr          $ra
    // 0x80012B70: nop

    return;
    // 0x80012B70: nop

;}
RECOMP_FUNC void func_808004A8_bstaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B0: jal         0x8009E6EC
    // 0x808004B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808004B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004B8: addiu       $t6, $v0, -0x15
    ctx->r14 = ADD32(ctx->r2, -0X15);
    // 0x808004BC: sltiu       $at, $t6, 0x48
    ctx->r1 = ctx->r14 < 0X48 ? 1 : 0;
    // 0x808004C0: beq         $at, $zero, L_8080050C
    if (ctx->r1 == 0) {
        // 0x808004C4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080050C;
    }
    // 0x808004C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808004C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1DE4) << 16);
    // 0x808004CC: addu        $at, $at, $t6
    gpr jr_addend_808004D4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808004D0: lw          $t6, 0x1DE4($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(392, 0X1DE4));
    // 0x808004D4: jr          $t6
    // 0x808004D8: nop

    switch (jr_addend_808004D4 >> 2) {
        case 0: goto L_808004F4; break;
        case 1: goto L_8080050C; break;
        case 2: goto L_8080050C; break;
        case 3: goto L_8080050C; break;
        case 4: goto L_8080050C; break;
        case 5: goto L_8080050C; break;
        case 6: goto L_8080050C; break;
        case 7: goto L_808004F4; break;
        case 8: goto L_808004F4; break;
        case 9: goto L_808004F4; break;
        case 10: goto L_808004DC; break;
        case 11: goto L_808004DC; break;
        case 12: goto L_808004DC; break;
        case 13: goto L_8080050C; break;
        case 14: goto L_8080050C; break;
        case 15: goto L_808004DC; break;
        case 16: goto L_808004F4; break;
        case 17: goto L_8080050C; break;
        case 18: goto L_8080050C; break;
        case 19: goto L_8080050C; break;
        case 20: goto L_8080050C; break;
        case 21: goto L_8080050C; break;
        case 22: goto L_8080050C; break;
        case 23: goto L_8080050C; break;
        case 24: goto L_808004DC; break;
        case 25: goto L_808004DC; break;
        case 26: goto L_8080050C; break;
        case 27: goto L_8080050C; break;
        case 28: goto L_8080050C; break;
        case 29: goto L_8080050C; break;
        case 30: goto L_8080050C; break;
        case 31: goto L_8080050C; break;
        case 32: goto L_8080050C; break;
        case 33: goto L_8080050C; break;
        case 34: goto L_8080050C; break;
        case 35: goto L_8080050C; break;
        case 36: goto L_8080050C; break;
        case 37: goto L_8080050C; break;
        case 38: goto L_8080050C; break;
        case 39: goto L_8080050C; break;
        case 40: goto L_8080050C; break;
        case 41: goto L_8080050C; break;
        case 42: goto L_8080050C; break;
        case 43: goto L_8080050C; break;
        case 44: goto L_8080050C; break;
        case 45: goto L_8080050C; break;
        case 46: goto L_808004F4; break;
        case 47: goto L_8080050C; break;
        case 48: goto L_808004DC; break;
        case 49: goto L_8080050C; break;
        case 50: goto L_8080050C; break;
        case 51: goto L_8080050C; break;
        case 52: goto L_8080050C; break;
        case 53: goto L_8080050C; break;
        case 54: goto L_8080050C; break;
        case 55: goto L_8080050C; break;
        case 56: goto L_8080050C; break;
        case 57: goto L_808004DC; break;
        case 58: goto L_8080050C; break;
        case 59: goto L_8080050C; break;
        case 60: goto L_808004DC; break;
        case 61: goto L_808004DC; break;
        case 62: goto L_8080050C; break;
        case 63: goto L_8080050C; break;
        case 64: goto L_8080050C; break;
        case 65: goto L_8080050C; break;
        case 66: goto L_8080050C; break;
        case 67: goto L_8080050C; break;
        case 68: goto L_808004DC; break;
        case 69: goto L_808004DC; break;
        case 70: goto L_808004DC; break;
        case 71: goto L_808004DC; break;
        default: switch_error(__func__, 0x808004D4, 0x80801DE4);
    }
    // 0x808004D8: nop

L_808004DC:
    // 0x808004DC: jal         0x80800420
    // 0x808004E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800420_bstaxi(rdram, ctx);
        goto after_1;
    // 0x808004E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808004E4: jal         0x80099B94
    // 0x808004E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_2;
    // 0x808004E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808004EC: b           L_80800518
    // 0x808004F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800518;
    // 0x808004F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004F4:
    // 0x808004F4: jal         0x80800420
    // 0x808004F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800420_bstaxi(rdram, ctx);
        goto after_3;
    // 0x808004F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808004FC: jal         0x80099B94
    // 0x80800500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_4;
    // 0x80800500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800504: b           L_80800518
    // 0x80800508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800518;
    // 0x80800508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080050C:
    // 0x8080050C: jal         0x80099B94
    // 0x80800510: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_5;
    // 0x80800510: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80800514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800518:
    // 0x80800518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080051C: jr          $ra
    // 0x80800520: nop

    return;
    // 0x80800520: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DC4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801DC8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(392, 0X21F8) << 16);
    // 0x80801DCC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801DD0: jr          $ra
    // 0x80801DD4: lw          $v0, 0x21F8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21F8));
    return;
    // 0x80801DD4: lw          $v0, 0x21F8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21F8));
    // 0x80801DD8: nop

    // 0x80801DDC: nop

;}
RECOMP_FUNC void func_80800298_bsclimb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080029C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A0: jal         0x8009BB0C
    // 0x808002A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8009BB0C(rdram, ctx);
        goto after_0;
    // 0x808002A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002A8: jal         0x800F2100
    // 0x808002AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x808002AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x808002B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002B8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808002BC: nop

    // 0x808002C0: bc1f        L_808002CC
    if (!c1cs) {
        // 0x808002C4: nop
    
            goto L_808002CC;
    }
    // 0x808002C4: nop

    // 0x808002C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002CC:
    // 0x808002CC: bnel        $v0, $zero, L_80800308
    if (ctx->r2 != 0) {
        // 0x808002D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800308;
    }
    goto skip_0;
    // 0x808002D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002D4: jal         0x8009C984
    // 0x808002D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    yaw_get(rdram, ctx);
        goto after_2;
    // 0x808002D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808002DC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x808002E0: jal         0x8009C990
    // 0x808002E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    yaw_getIdeal(rdram, ctx);
        goto after_3;
    // 0x808002E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808002E8: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x808002EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002F0: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x808002F4: nop

    // 0x808002F8: bc1tl       L_80800308
    if (c1cs) {
        // 0x808002FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800308;
    }
    goto skip_1;
    // 0x808002FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800308:
    // 0x80800308: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080030C: jr          $ra
    // 0x80800310: nop

    return;
    // 0x80800310: nop

;}
RECOMP_FUNC void ncfixposrot_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002BC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808002C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808002C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002CC: jal         0x800EE7F8
    // 0x808002D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808002D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x808002D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002DC: jr          $ra
    // 0x808002E0: nop

    return;
    // 0x808002E0: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(104, 0X1470) << 16);
    // 0x808005A8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005AC: jr          $ra
    // 0x808005B0: lw          $v0, 0x1470($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X1470));
    return;
    // 0x808005B0: lw          $v0, 0x1470($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X1470));
;}
RECOMP_FUNC void func_80100E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100E54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80100E58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80100E5C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80100E60: addiu       $s2, $s2, 0x5A60
    ctx->r18 = ADD32(ctx->r18, 0X5A60);
    // 0x80100E64: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80100E68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80100E6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80100E70: beq         $a0, $zero, L_80100E84
    if (ctx->r4 == 0) {
        // 0x80100E74: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80100E84;
    }
    // 0x80100E74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80100E78: jal         0x800B32E4
    // 0x80100E7C: nop

    freelist_defrag(rdram, ctx);
        goto after_0;
    // 0x80100E7C: nop

    after_0:
    // 0x80100E80: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
L_80100E84:
    // 0x80100E84: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x80100E88: beql        $a0, $zero, L_80100EF8
    if (ctx->r4 == 0) {
        // 0x80100E8C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80100EF8;
    }
    goto skip_0;
    // 0x80100E8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80100E90: jal         0x800B3034
    // 0x80100E94: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    freelist_capacity(rdram, ctx);
        goto after_1;
    // 0x80100E94: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_1:
    // 0x80100E98: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80100E9C: bne         $at, $zero, L_80100EE8
    if (ctx->r1 != 0) {
        // 0x80100EA0: nop
    
            goto L_80100EE8;
    }
    // 0x80100EA0: nop

    // 0x80100EA4: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
L_80100EA8:
    // 0x80100EA8: jal         0x800B31B8
    // 0x80100EAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    freelist_is_element_alive(rdram, ctx);
        goto after_2;
    // 0x80100EAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80100EB0: beq         $v0, $zero, L_80100ED0
    if (ctx->r2 == 0) {
        // 0x80100EB4: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80100ED0;
    }
    // 0x80100EB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80100EB8: jal         0x800B301C
    // 0x80100EBC: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    freelist_at(rdram, ctx);
        goto after_3;
    // 0x80100EBC: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    after_3:
    // 0x80100EC0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80100EC4: jal         0x8001BAFC
    // 0x80100EC8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    defrag(rdram, ctx);
        goto after_4;
    // 0x80100EC8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_4:
    // 0x80100ECC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_80100ED0:
    // 0x80100ED0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80100ED4: jal         0x800B3034
    // 0x80100ED8: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    freelist_capacity(rdram, ctx);
        goto after_5;
    // 0x80100ED8: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    after_5:
    // 0x80100EDC: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80100EE0: bnel        $at, $zero, L_80100EA8
    if (ctx->r1 != 0) {
        // 0x80100EE4: lw          $a0, 0x4($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X4);
            goto L_80100EA8;
    }
    goto skip_1;
    // 0x80100EE4: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    skip_1:
L_80100EE8:
    // 0x80100EE8: jal         0x800B32E4
    // 0x80100EEC: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    freelist_defrag(rdram, ctx);
        goto after_6;
    // 0x80100EEC: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    after_6:
    // 0x80100EF0: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x80100EF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80100EF8:
    // 0x80100EF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100EFC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80100F00: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80100F04: jr          $ra
    // 0x80100F08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80100F08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80013AAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013AAC: lui         $at, 0x3E34
    ctx->r1 = S32(0X3E34 << 16);
    // 0x80013AB0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80013AB4: b           L_80013ABC
    // 0x80013AB8: nop

    func_80013ABC(rdram, ctx);
    return;
    // 0x80013AB8: nop

;}
RECOMP_FUNC void bsdie_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080049C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004A8: jal         0x8008CABC
    // 0x808004AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808004AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808004B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808004B4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x808004B8: jal         0x80085228
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: jal         0x8009B9B0
    // 0x808004C8: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808004C8: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_2:
    // 0x808004CC: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808004D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D8: beq         $v0, $zero, L_80800500
    if (ctx->r2 == 0) {
        // 0x808004DC: nop
    
            goto L_80800500;
    }
    // 0x808004DC: nop

    // 0x808004E0: beq         $v0, $at, L_80800528
    if (ctx->r2 == ctx->r1) {
        // 0x808004E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800528;
    }
    // 0x808004E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004E8: beq         $v0, $at, L_80800594
    if (ctx->r2 == ctx->r1) {
        // 0x808004EC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800594;
    }
    // 0x808004EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808004F0: beq         $v0, $at, L_808005F8
    if (ctx->r2 == ctx->r1) {
        // 0x808004F4: nop
    
            goto L_808005F8;
    }
    // 0x808004F4: nop

    // 0x808004F8: b           L_808005F8
    // 0x808004FC: nop

        goto L_808005F8;
    // 0x808004FC: nop

L_80800500:
    // 0x80800500: jal         0x8008DF8C
    // 0x80800504: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    func_8008DF8C(rdram, ctx);
        goto after_3;
    // 0x80800504: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    after_3:
    // 0x80800508: beq         $v0, $zero, L_808005F8
    if (ctx->r2 == 0) {
        // 0x8080050C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F8;
    }
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800510: lui         $a1, 0x3E3E
    ctx->r5 = S32(0X3E3E << 16);
    // 0x80800514: jal         0x8008CED4
    // 0x80800518: ori         $a1, $a1, 0xC56D
    ctx->r5 = ctx->r5 | 0XC56D;
    baanim_setEnd(rdram, ctx);
        goto after_4;
    // 0x80800518: ori         $a1, $a1, 0xC56D
    ctx->r5 = ctx->r5 | 0XC56D;
    after_4:
    // 0x8080051C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800520: b           L_808005F8
    // 0x80800524: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_808005F8;
    // 0x80800524: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800528:
    // 0x80800528: jal         0x8008E078
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_5;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800530: beq         $v0, $zero, L_808005F8
    if (ctx->r2 == 0) {
        // 0x80800534: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F8;
    }
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    // 0x8080053C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800540: jal         0x8009DF18
    // 0x80800544: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_6;
    // 0x80800544: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_6:
    // 0x80800548: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080054C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800550: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800554: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800558: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080055C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800560: jal         0x80085490
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800568: jal         0x80800000
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsdie(rdram, ctx);
        goto after_8;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800570: jal         0x8009E058
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E058(rdram, ctx);
        goto after_9;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800578: lui         $a1, 0x3EAA
    ctx->r5 = S32(0X3EAA << 16);
    // 0x8080057C: ori         $a1, $a1, 0xA64C
    ctx->r5 = ctx->r5 | 0XA64C;
    // 0x80800580: jal         0x8008CED4
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_setEnd(rdram, ctx);
        goto after_10;
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800588: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8080058C: b           L_808005F8
    // 0x80800590: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_808005F8;
    // 0x80800590: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800594:
    // 0x80800594: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80800598: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080059C: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808005A0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808005A4: jal         0x800F0E00
    // 0x808005A8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800F0E00(rdram, ctx);
        goto after_11;
    // 0x808005A8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_11:
    // 0x808005AC: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x808005B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005B4: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x808005B8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808005BC: nop

    // 0x808005C0: bc1f        L_808005D0
    if (!c1cs) {
        // 0x808005C4: nop
    
            goto L_808005D0;
    }
    // 0x808005C4: nop

    // 0x808005C8: jal         0x80084A10
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_808005D0:
    // 0x808005D0: jal         0x8008B324
    // 0x808005D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isStopped(rdram, ctx);
        goto after_13;
    // 0x808005D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x808005D8: beq         $v0, $zero, L_808005F8
    if (ctx->r2 == 0) {
        // 0x808005DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F8;
    }
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: jal         0x8008CED4
    // 0x808005E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_14;
    // 0x808005E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_14:
    // 0x808005E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808005EC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x808005F0: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
    // 0x808005F4: swc1        $f10, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f10.u32l;
L_808005F8:
    // 0x808005F8: jal         0x80085238
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_7(rdram, ctx);
        goto after_15;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800600: beq         $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x80800604: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800610;
    }
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800608: addiu       $t9, $zero, 0x54
    ctx->r25 = ADD32(0, 0X54);
    // 0x8080060C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_80800610:
    // 0x80800610: jal         0x8009E5C8
    // 0x80800614: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_16;
    // 0x80800614: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_16:
    // 0x80800618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080061C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800620: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800624: jr          $ra
    // 0x80800628: nop

    return;
    // 0x80800628: nop

;}
RECOMP_FUNC void func_800D55A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D55A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D55A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D55A8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800D55AC: jal         0x800B2D70
    // 0x800D55B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    vector_new(rdram, ctx);
        goto after_0;
    // 0x800D55B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x800D55B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D55B8: sw          $v0, -0x4810($at)
    MEM_W(-0X4810, ctx->r1) = ctx->r2;
    // 0x800D55BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800D55C0: jal         0x800B2D70
    // 0x800D55C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    vector_new(rdram, ctx);
        goto after_1;
    // 0x800D55C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x800D55C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D55CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D55D0: sw          $v0, -0x480C($at)
    MEM_W(-0X480C, ctx->r1) = ctx->r2;
    // 0x800D55D4: jr          $ra
    // 0x800D55D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D55D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EF334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF334: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EF338: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF33C: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF340: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EF344: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800EF348: nop

    // 0x800EF34C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800EF350: nop

    // 0x800EF354: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800EF358: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800EF35C: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800EF360: jr          $ra
    // 0x800EF364: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800EF364: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void chdragonbrothers_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803F40: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1852, 0X574C) << 16);
    // 0x80803F44: jr          $ra
    // 0x80803F48: addiu       $v0, $v0, 0x574C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1852, 0X574C));
    return;
    // 0x80803F48: addiu       $v0, $v0, 0x574C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1852, 0X574C));
;}
RECOMP_FUNC void func_80026BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026BE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026BE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026BEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80026BF0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80026BF4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80026BF8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80026BFC: beq         $t7, $zero, L_80026C8C
    if (ctx->r15 == 0) {
        // 0x80026C00: nop
    
            goto L_80026C8C;
    }
    // 0x80026C00: nop

    // 0x80026C04: jal         0x80021794
    // 0x80026C08: nop

    func_80021794(rdram, ctx);
        goto after_0;
    // 0x80026C08: nop

    after_0:
    // 0x80026C0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80026C10: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80026C14: bne         $t8, $zero, L_80026C24
    if (ctx->r24 != 0) {
        // 0x80026C18: nop
    
            goto L_80026C24;
    }
    // 0x80026C18: nop

    // 0x80026C1C: b           L_80026C94
    // 0x80026C20: nop

        goto L_80026C94;
    // 0x80026C20: nop

L_80026C24:
    // 0x80026C24: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80026C28: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80026C2C: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x80026C30: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80026C34: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80026C38: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x80026C3C: lw          $t3, 0x88($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X88);
    // 0x80026C40: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80026C44: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x80026C48: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80026C4C: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x80026C50: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x80026C54: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x80026C58: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80026C5C: sw          $t8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r24;
    // 0x80026C60: jal         0x80021928
    // 0x80026C64: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80021928(rdram, ctx);
        goto after_1;
    // 0x80026C64: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80026C68: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80026C6C: sw          $v0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r2;
    // 0x80026C70: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80026C74: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x80026C78: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80026C7C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80026C80: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80026C84: jal         0x8002B684
    // 0x80026C88: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    func_8002B684(rdram, ctx);
        goto after_2;
    // 0x80026C88: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    after_2:
L_80026C8C:
    // 0x80026C8C: b           L_80026C94
    // 0x80026C90: nop

        goto L_80026C94;
    // 0x80026C90: nop

L_80026C94:
    // 0x80026C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026C98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026C9C: jr          $ra
    // 0x80026CA0: nop

    return;
    // 0x80026CA0: nop

    // 0x80026CA4: nop

    // 0x80026CA8: nop

    // 0x80026CAC: nop

;}
RECOMP_FUNC void func_808001C4_chjiggypost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001C8: addiu       $at, $zero, 0x1512
    ctx->r1 = ADD32(0, 0X1512);
    // 0x808001CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001D8: beq         $a1, $at, L_80800294
    if (ctx->r5 == ctx->r1) {
        // 0x808001DC: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800294;
    }
    // 0x808001DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808001E0: addiu       $at, $zero, 0x1513
    ctx->r1 = ADD32(0, 0X1513);
    // 0x808001E4: beq         $a1, $at, L_808001F4
    if (ctx->r5 == ctx->r1) {
        // 0x808001E8: addiu       $at, $zero, 0x1514
        ctx->r1 = ADD32(0, 0X1514);
            goto L_808001F4;
    }
    // 0x808001E8: addiu       $at, $zero, 0x1514
    ctx->r1 = ADD32(0, 0X1514);
    // 0x808001EC: bnel        $a1, $at, L_808002A0
    if (ctx->r5 != ctx->r1) {
        // 0x808001F0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808002A0;
    }
    goto skip_0;
    // 0x808001F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
L_808001F4:
    // 0x808001F4: jal         0x800DA298
    // 0x808001F8: addiu       $a0, $zero, 0x35B
    ctx->r4 = ADD32(0, 0X35B);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808001F8: addiu       $a0, $zero, 0x35B
    ctx->r4 = ADD32(0, 0X35B);
    after_0:
    // 0x808001FC: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x80800200: nop
    
            goto L_8080026C;
    }
    // 0x80800200: nop

    // 0x80800204: jal         0x800D035C
    // 0x80800208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D035C(rdram, ctx);
        goto after_1;
    // 0x80800208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8080020C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800210: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800214: lhu         $a0, 0x76($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X76);
    // 0x80800218: srl         $t8, $a0, 7
    ctx->r24 = S32(U32(ctx->r4) >> 7);
    // 0x8080021C: jal         0x8008A6A8
    // 0x80800220: addiu       $a0, $t8, -0x33
    ctx->r4 = ADD32(ctx->r24, -0X33);
    _sujiggy_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800220: addiu       $a0, $t8, -0x33
    ctx->r4 = ADD32(ctx->r24, -0X33);
    after_2:
    // 0x80800224: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800228: addiu       $a1, $zero, 0x1516
    ctx->r5 = ADD32(0, 0X1516);
    // 0x8080022C: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800230: bne         $at, $zero, L_8080025C
    if (ctx->r1 != 0) {
        // 0x80800234: nop
    
            goto L_8080025C;
    }
    // 0x80800234: nop

    // 0x80800238: jal         0x8008FD48
    // 0x8080023C: nop

    func_8008FD48(rdram, ctx);
        goto after_3;
    // 0x8080023C: nop

    after_3:
    // 0x80800240: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800244: bne         $v0, $at, L_80800254
    if (ctx->r2 != ctx->r1) {
        // 0x80800248: nop
    
            goto L_80800254;
    }
    // 0x80800248: nop

    // 0x8080024C: b           L_8080025C
    // 0x80800250: addiu       $a1, $zero, 0x1515
    ctx->r5 = ADD32(0, 0X1515);
        goto L_8080025C;
    // 0x80800250: addiu       $a1, $zero, 0x1515
    ctx->r5 = ADD32(0, 0X1515);
L_80800254:
    // 0x80800254: b           L_8080025C
    // 0x80800258: addiu       $a1, $zero, 0x152E
    ctx->r5 = ADD32(0, 0X152E);
        goto L_8080025C;
    // 0x80800258: addiu       $a1, $zero, 0x152E
    ctx->r5 = ADD32(0, 0X152E);
L_8080025C:
    // 0x8080025C: jal         0x80800014
    // 0x80800260: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800014_chjiggypost(rdram, ctx);
        goto after_4;
    // 0x80800260: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800264: b           L_808002AC
    // 0x80800268: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
        goto L_808002AC;
    // 0x80800268: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_8080026C:
    // 0x8080026C: jal         0x800C0850
    // 0x80800270: nop

    func_800C0850(rdram, ctx);
        goto after_5;
    // 0x80800270: nop

    after_5:
    // 0x80800274: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80800278: jal         0x800C01A8
    // 0x8080027C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_6;
    // 0x8080027C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800280: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800284: jal         0x80101FDC
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8080028C: b           L_808002AC
    // 0x80800290: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
        goto L_808002AC;
    // 0x80800290: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_80800294:
    // 0x80800294: jal         0x800DA544
    // 0x80800298: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x80800298: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_8:
    // 0x8080029C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808002A0:
    // 0x808002A0: jal         0x80101FDC
    // 0x808002A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x808002A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808002A8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_808002AC:
    // 0x808002AC: addiu       $at, $zero, 0x1515
    ctx->r1 = ADD32(0, 0X1515);
    // 0x808002B0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808002B4: bne         $t0, $at, L_808002CC
    if (ctx->r8 != ctx->r1) {
        // 0x808002B8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808002CC;
    }
    // 0x808002B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002BC: bne         $t1, $at, L_808002CC
    if (ctx->r9 != ctx->r1) {
        // 0x808002C0: addiu       $a0, $zero, 0x151
        ctx->r4 = ADD32(0, 0X151);
            goto L_808002CC;
    }
    // 0x808002C0: addiu       $a0, $zero, 0x151
    ctx->r4 = ADD32(0, 0X151);
    // 0x808002C4: jal         0x80087A58
    // 0x808002C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x808002C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
L_808002CC:
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void defrag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BAFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001BB00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001BB04: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8001BB08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001BB0C: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8001BB10: beq         $t6, $zero, L_8001BB28
    if (ctx->r14 == 0) {
        // 0x8001BB14: nop
    
            goto L_8001BB28;
    }
    // 0x8001BB14: nop

    // 0x8001BB18: beq         $t6, $at, L_8001BB38
    if (ctx->r14 == ctx->r1) {
        // 0x8001BB1C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001BB38;
    }
    // 0x8001BB1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001BB20: bne         $t6, $at, L_8001BB48
    if (ctx->r14 != ctx->r1) {
        // 0x8001BB24: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8001BB48;
    }
    // 0x8001BB24: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8001BB28:
    // 0x8001BB28: jal         0x8001B9BC
    // 0x8001BB2C: nop

    defrag_prev(rdram, ctx);
        goto after_0;
    // 0x8001BB2C: nop

    after_0:
    // 0x8001BB30: b           L_8001BB4C
    // 0x8001BB34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001BB4C;
    // 0x8001BB34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001BB38:
    // 0x8001BB38: jal         0x8001B870
    // 0x8001BB3C: nop

    defrag_next(rdram, ctx);
        goto after_1;
    // 0x8001BB3C: nop

    after_1:
    // 0x8001BB40: b           L_8001BB4C
    // 0x8001BB44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001BB4C;
    // 0x8001BB44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001BB48:
    // 0x8001BB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001BB4C:
    // 0x8001BB4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001BB50: jr          $ra
    // 0x8001BB54: nop

    return;
    // 0x8001BB54: nop

;}
RECOMP_FUNC void func_800CB9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB9AC: jr          $ra
    // 0x800CB9B0: nop

    return;
    // 0x800CB9B0: nop

;}
RECOMP_FUNC void func_808000BC_glintrosyncDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C4: jal         0x800343B0
    // 0x808000C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x808000C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000CC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x808000D0: lw          $v1, 0x75D0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X75D0);
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D8: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x808000DC: bne         $at, $zero, L_808000EC
    if (ctx->r1 != 0) {
        // 0x808000E0: subu        $a0, $v0, $v1
        ctx->r4 = SUB32(ctx->r2, ctx->r3);
            goto L_808000EC;
    }
    // 0x808000E0: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // 0x808000E4: b           L_808000EC
    // 0x808000E8: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
        goto L_808000EC;
    // 0x808000E8: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
L_808000EC:
    // 0x808000EC: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x808000F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2738, 0X480) << 16);
    // 0x808000F4: lwc1        $f8, 0x480($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2738, 0X480));
    // 0x808000F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800100: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800104: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800108: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8080010C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80800110: nop

    // 0x80800114: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800118: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8080011C: nop

    // 0x80800120: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80800124: beql        $v0, $zero, L_80800174
    if (ctx->r2 == 0) {
        // 0x80800128: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_80800174;
    }
    goto skip_0;
    // 0x80800128: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x8080012C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800134: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800138: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8080013C: nop

    // 0x80800140: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800144: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80800148: nop

    // 0x8080014C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80800150: bne         $v0, $zero, L_80800168
    if (ctx->r2 != 0) {
        // 0x80800154: nop
    
            goto L_80800168;
    }
    // 0x80800154: nop

    // 0x80800158: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8080015C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800160: b           L_80800180
    // 0x80800164: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80800180;
    // 0x80800164: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80800168:
    // 0x80800168: b           L_80800180
    // 0x8080016C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80800180;
    // 0x8080016C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800170: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_80800174:
    // 0x80800174: nop

    // 0x80800178: bltz        $v0, L_80800168
    if (SIGNED(ctx->r2) < 0) {
        // 0x8080017C: nop
    
            goto L_80800168;
    }
    // 0x8080017C: nop

L_80800180:
    // 0x80800180: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800184: jr          $ra
    // 0x80800188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bstaxi_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083ED8: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083ED8);
    return;
    // 0x80083EDC: addi        $t0, $zero, 0x88
    ctx->r8 = ADD32(0, 0X88);
;}
RECOMP_FUNC void func_8080004C_ncba1p(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800054: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800058: jal         0x80110840
    // 0x8080005C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x8080005C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800060: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800068: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8080006C: lbu         $t8, 0x51($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X51);
    // 0x80800070: bnel        $t8, $zero, L_80800094
    if (ctx->r24 != 0) {
        // 0x80800074: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800094;
    }
    goto skip_0;
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800078: jal         0x800F7B9C
    // 0x8080007C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800F7B9C(rdram, ctx);
        goto after_1;
    // 0x8080007C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800080: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800088: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8080008C: sb          $t9, 0x51($t1)
    MEM_B(0X51, ctx->r9) = ctx->r25;
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800094:
    // 0x80800094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void func_808019EC_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808019F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019F4: jal         0x80800128
    // 0x808019F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800128_bsbfly(rdram, ctx);
        goto after_0;
    // 0x808019F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808019FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801A00: addiu       $a1, $zero, 0x10D
    ctx->r5 = ADD32(0, 0X10D);
    // 0x80801A04: jal         0x80084C48
    // 0x80801A08: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _bafly_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80801A08: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80801A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A14: jr          $ra
    // 0x80801A18: nop

    return;
    // 0x80801A18: nop

;}
RECOMP_FUNC void func_80801604_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801604: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801608: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080160C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801610: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80801614: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801618: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8080161C: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80801620: beq         $t6, $at, L_80801644
    if (ctx->r14 == ctx->r1) {
        // 0x80801624: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801644;
    }
    // 0x80801624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801628: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8080162C: beq         $t6, $at, L_80801644
    if (ctx->r14 == ctx->r1) {
        // 0x80801630: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_80801644;
    }
    // 0x80801630: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80801634: beq         $t6, $at, L_80801674
    if (ctx->r14 == ctx->r1) {
        // 0x80801638: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801674;
    }
    // 0x80801638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080163C: b           L_808016A0
    // 0x80801640: nop

        goto L_808016A0;
    // 0x80801640: nop

L_80801644:
    // 0x80801644: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80801648: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x8080164C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801650: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801654: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80801658: jal         0x80086140
    // 0x8080165C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    _chfirefx_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080165C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_0:
    // 0x80801660: lhu         $t8, 0x76($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X76);
    // 0x80801664: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80801668: addiu       $t0, $t9, 0x2F2
    ctx->r8 = ADD32(ctx->r25, 0X2F2);
    // 0x8080166C: b           L_808016A0
    // 0x80801670: sw          $t0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r8;
        goto L_808016A0;
    // 0x80801670: sw          $t0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r8;
L_80801674:
    // 0x80801674: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80801678: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080167C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80801680: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80801684: jal         0x80086140
    // 0x80801688: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    _chfirefx_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801688: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_1:
    // 0x8080168C: addiu       $t2, $zero, 0x326
    ctx->r10 = ADD32(0, 0X326);
    // 0x80801690: sw          $t2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r10;
    // 0x80801694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801698: jal         0x80102FDC
    // 0x8080169C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x8080169C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
L_808016A0:
    // 0x808016A0: jal         0x800DA298
    // 0x808016A4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808016A4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_3:
    // 0x808016A8: bne         $v0, $zero, L_808016C0
    if (ctx->r2 != 0) {
        // 0x808016AC: nop
    
            goto L_808016C0;
    }
    // 0x808016AC: nop

    // 0x808016B0: jal         0x80088848
    // 0x808016B4: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x808016B4: nop

    after_4:
    // 0x808016B8: beql        $v0, $zero, L_808016D8
    if (ctx->r2 == 0) {
        // 0x808016BC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808016D8;
    }
    goto skip_0;
    // 0x808016BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_808016C0:
    // 0x808016C0: jal         0x8010A570
    // 0x808016C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x808016C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808016C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016CC: jal         0x80101FDC
    // 0x808016D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x808016D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808016D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808016D8:
    // 0x808016D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808016DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808016E0: jr          $ra
    // 0x808016E4: nop

    return;
    // 0x808016E4: nop

;}
RECOMP_FUNC void func_80800854_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800854: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080085C: jal         0x808006F0
    // 0x80800860: nop

    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800860: nop

    after_0:
    // 0x80800864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080086C: jr          $ra
    // 0x80800870: nop

    return;
    // 0x80800870: nop

;}
RECOMP_FUNC void func_80801138_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080113C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801144: addiu       $a0, $zero, 0x361
    ctx->r4 = ADD32(0, 0X361);
    // 0x80801148: jal         0x800DA564
    // 0x8080114C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x8080114C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80801150: bne         $v0, $zero, L_80801160
    if (ctx->r2 != 0) {
        // 0x80801154: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80801160;
    }
    // 0x80801154: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801158: b           L_80801178
    // 0x8080115C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801178;
    // 0x8080115C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801160:
    // 0x80801160: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80801164: addiu       $t6, $v1, 0x31
    ctx->r14 = ADD32(ctx->r3, 0X31);
    // 0x80801168: lhu         $t8, 0x76($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X76);
    // 0x8080116C: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80801170: xor         $v0, $t6, $t9
    ctx->r2 = ctx->r14 ^ ctx->r25;
    // 0x80801174: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80801178:
    // 0x80801178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080117C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801180: jr          $ra
    // 0x80801184: nop

    return;
    // 0x80801184: nop

;}
RECOMP_FUNC void vpflicker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800010: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x80800014: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80800018: jal         0x8001ACCC
    // 0x8080001C: addiu       $a0, $t7, 0x8
    ctx->r4 = ADD32(ctx->r15, 0X8);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $t7, 0x8
    ctx->r4 = ADD32(ctx->r15, 0X8);
    after_0:
    // 0x80800020: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800028: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080002C: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x80800030: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800034: addiu       $a0, $a2, 0x14
    ctx->r4 = ADD32(ctx->r6, 0X14);
    // 0x80800038: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8080003C: addu        $a1, $t0, $a2
    ctx->r5 = ADD32(ctx->r8, ctx->r6);
    // 0x80800040: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x80800044: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80800048: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8080004C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800050: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800054: beq         $at, $zero, L_8080009C
    if (ctx->r1 == 0) {
        // 0x80800058: swc1        $f4, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
            goto L_8080009C;
    }
    // 0x80800058: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8080005C: lhu         $t1, 0x2($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X2);
L_80800060:
    // 0x80800060: beql        $t1, $zero, L_80800090
    if (ctx->r9 == 0) {
        // 0x80800064: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800090;
    }
    goto skip_0;
    // 0x80800064: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x80800068: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8080006C: subu        $t2, $v1, $a0
    ctx->r10 = SUB32(ctx->r3, ctx->r4);
    // 0x80800070: sra         $t3, $t2, 2
    ctx->r11 = S32(SIGNED(ctx->r10) >> 2);
    // 0x80800074: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80800078: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8080007C: sh          $t3, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r11;
    // 0x80800080: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80800084: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80800088: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8080008C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80800090:
    // 0x80800090: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x80800094: bnel        $at, $zero, L_80800060
    if (ctx->r1 != 0) {
        // 0x80800098: lhu         $t1, 0x2($v1)
        ctx->r9 = MEM_HU(ctx->r3, 0X2);
            goto L_80800060;
    }
    goto skip_1;
    // 0x80800098: lhu         $t1, 0x2($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X2);
    skip_1:
L_8080009C:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void bstnt_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808014B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808014BC: jal         0x80091A58
    // 0x808014C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x808014C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x808014C4: bne         $v0, $zero, L_808014D4
    if (ctx->r2 != 0) {
        // 0x808014C8: nop
    
            goto L_808014D4;
    }
    // 0x808014C8: nop

    // 0x808014CC: b           L_808014FC
    // 0x808014D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808014FC;
    // 0x808014D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808014D4:
    // 0x808014D4: jal         0x800A1718
    // 0x808014D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A1718(rdram, ctx);
        goto after_1;
    // 0x808014D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808014DC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x808014E0: bne         $at, $zero, L_808014F0
    if (ctx->r1 != 0) {
        // 0x808014E4: nop
    
            goto L_808014F0;
    }
    // 0x808014E4: nop

    // 0x808014E8: b           L_808014FC
    // 0x808014EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808014FC;
    // 0x808014EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808014F0:
    // 0x808014F0: jal         0x800FC660
    // 0x808014F4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_2;
    // 0x808014F4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_2:
    // 0x808014F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808014FC:
    // 0x808014FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801504: jr          $ra
    // 0x80801508: nop

    return;
    // 0x80801508: nop

;}
RECOMP_FUNC void _bsbabykaz_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082810: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x80082810);
    return;
    // 0x80082814: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_800E8DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8DB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E8DBC: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800E8DC0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800E8DC4: jal         0x800E8CB0
    // 0x800E8DC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800E8CB0(rdram, ctx);
        goto after_0;
    // 0x800E8DC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E8DCC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800E8DD0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800E8DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8DD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8DDC: jr          $ra
    // 0x800E8DE0: nop

    return;
    // 0x800E8DE0: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007DC: jal         0x800DA298
    // 0x808007E0: addiu       $a0, $zero, 0xD4E
    ctx->r4 = ADD32(0, 0XD4E);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808007E0: addiu       $a0, $zero, 0xD4E
    ctx->r4 = ADD32(0, 0XD4E);
    after_0:
    // 0x808007E4: beq         $v0, $zero, L_808007FC
    if (ctx->r2 == 0) {
        // 0x808007E8: addiu       $a0, $zero, 0xD50
        ctx->r4 = ADD32(0, 0XD50);
            goto L_808007FC;
    }
    // 0x808007E8: addiu       $a0, $zero, 0xD50
    ctx->r4 = ADD32(0, 0XD50);
    // 0x808007EC: jal         0x800DA564
    // 0x808007F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x808007F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x808007F4: b           L_80800808
    // 0x808007F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80800808;
    // 0x808007F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808007FC:
    // 0x808007FC: jal         0x808000E8
    // 0x80800800: nop

    sujiggy_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800800: nop

    after_2:
    // 0x80800804: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800808:
    // 0x80800808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080080C: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80800810: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80800814: jr          $ra
    // 0x80800818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80809A7C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809A7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80809A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809A84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80809A88: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80809A8C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80809A90: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80809A94: lwc1        $f12, 0xC0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x80809A98: lw          $a2, 0x234($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X234);
    // 0x80809A9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80809AA0: jal         0x800F122C
    // 0x80809AA4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_800F122C(rdram, ctx);
        goto after_0;
    // 0x80809AA4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x80809AA8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80809AAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80809AB0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80809AB4: lwc1        $f6, 0xC0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x80809AB8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80809ABC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80809AC0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80809AC4: nop

    // 0x80809AC8: bc1tl       L_80809ADC
    if (c1cs) {
        // 0x80809ACC: lwc1        $f0, 0x244($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X244);
            goto L_80809ADC;
    }
    goto skip_0;
    // 0x80809ACC: lwc1        $f0, 0x244($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X244);
    skip_0:
    // 0x80809AD0: b           L_80809ADC
    // 0x80809AD4: lwc1        $f0, 0x23C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X23C);
        goto L_80809ADC;
    // 0x80809AD4: lwc1        $f0, 0x23C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X23C);
    // 0x80809AD8: lwc1        $f0, 0x244($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X244);
L_80809ADC:
    // 0x80809ADC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80809AE0: jal         0x80809AF8
    // 0x80809AE4: lw          $a3, 0x234($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X234);
    func_80809AF8_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80809AE4: lw          $a3, 0x234($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X234);
    after_1:
    // 0x80809AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80809AEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80809AF0: jr          $ra
    // 0x80809AF4: nop

    return;
    // 0x80809AF4: nop

;}
RECOMP_FUNC void func_80800000_baeggcursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800004: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(512, 0X690) << 16);
    // 0x80800008: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080000C: jr          $ra
    // 0x80800010: lw          $v0, 0x690($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(512, 0X690));
    return;
    // 0x80800010: lw          $v0, 0x690($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(512, 0X690));
;}
RECOMP_FUNC void func_80801A54_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A54: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801A58: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80801A5C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801A60: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801A64: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801A68: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801A6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801A70: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80801A74: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801A78: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80801A7C: lui         $s3, 0xFFFE
    ctx->r19 = S32(0XFFFE << 16);
    // 0x80801A80: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80801A84: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80801A88: ori         $s3, $s3, 0x7960
    ctx->r19 = ctx->r19 | 0X7960;
    // 0x80801A8C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80801A90: sw          $s1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r17;
    // 0x80801A94: sw          $s1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r17;
    // 0x80801A98: sw          $s1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r17;
    // 0x80801A9C: sw          $s1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r17;
    // 0x80801AA0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80801AA4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80801AA8:
    // 0x80801AA8: jal         0x80801784
    // 0x80801AAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801784_chquiz(rdram, ctx);
        goto after_0;
    // 0x80801AAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80801AB0: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801AB4: beql        $at, $zero, L_80801AC8
    if (ctx->r1 == 0) {
        // 0x80801AB8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801AC8;
    }
    goto skip_0;
    // 0x80801AB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80801ABC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80801AC0: sw          $s0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r16;
    // 0x80801AC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801AC8:
    // 0x80801AC8: slti        $at, $s0, 0x7
    ctx->r1 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // 0x80801ACC: bnel        $at, $zero, L_80801AA8
    if (ctx->r1 != 0) {
        // 0x80801AD0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80801AA8;
    }
    goto skip_1;
    // 0x80801AD0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_1:
    // 0x80801AD4: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80801AD8: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    // 0x80801ADC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80801AE0:
    // 0x80801AE0: jal         0x80801784
    // 0x80801AE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801784_chquiz(rdram, ctx);
        goto after_1;
    // 0x80801AE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80801AE8: bnel        $v0, $s3, L_80801B48
    if (ctx->r2 != ctx->r19) {
        // 0x80801AEC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801B48;
    }
    goto skip_2;
    // 0x80801AEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x80801AF0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80801AF4: beql        $s0, $t6, L_80801B48
    if (ctx->r16 == ctx->r14) {
        // 0x80801AF8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801B48;
    }
    goto skip_3;
    // 0x80801AF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x80801AFC: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80801B00: beql        $s0, $v0, L_80801B48
    if (ctx->r16 == ctx->r2) {
        // 0x80801B04: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801B48;
    }
    goto skip_4;
    // 0x80801B04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x80801B08: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x80801B0C: beql        $s0, $t7, L_80801B48
    if (ctx->r16 == ctx->r15) {
        // 0x80801B10: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801B48;
    }
    goto skip_5;
    // 0x80801B10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_5:
    // 0x80801B14: beq         $s1, $v0, L_80801B34
    if (ctx->r17 == ctx->r2) {
        // 0x80801B18: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80801B34;
    }
    // 0x80801B18: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80801B1C: addiu       $v0, $s2, 0x4
    ctx->r2 = ADD32(ctx->r18, 0X4);
    // 0x80801B20: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
L_80801B24:
    // 0x80801B24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80801B28: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801B2C: bnel        $s1, $t8, L_80801B24
    if (ctx->r17 != ctx->r24) {
        // 0x80801B30: lw          $t8, 0x4($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X4);
            goto L_80801B24;
    }
    goto skip_6;
    // 0x80801B30: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    skip_6:
L_80801B34:
    // 0x80801B34: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80801B38: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x80801B3C: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x80801B40: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80801B44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801B48:
    // 0x80801B48: bnel        $s0, $s6, L_80801AE0
    if (ctx->r16 != ctx->r22) {
        // 0x80801B4C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80801AE0;
    }
    goto skip_7;
    // 0x80801B4C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_7:
    // 0x80801B50: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801B54: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80801B58: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801B5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801B60: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B64: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801B68: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801B6C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80801B70: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80801B74: jr          $ra
    // 0x80801B78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801B78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808000A0_chdodgemdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000A8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808000AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B4: beq         $a1, $at, L_808001F8
    if (ctx->r5 == ctx->r1) {
        // 0x808000B8: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808001F8;
    }
    // 0x808000B8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808000BC: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808000C0: bne         $a1, $at, L_8080024C
    if (ctx->r5 != ctx->r1) {
        // 0x808000C4: nop
    
            goto L_8080024C;
    }
    // 0x808000C4: nop

    // 0x808000C8: jal         0x800DA298
    // 0x808000CC: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000CC: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_0:
    // 0x808000D0: beql        $v0, $zero, L_80800198
    if (ctx->r2 == 0) {
        // 0x808000D4: lhu         $t2, 0x76($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0X76);
            goto L_80800198;
    }
    goto skip_0;
    // 0x808000D4: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
    skip_0:
    // 0x808000D8: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x808000DC: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x808000E0: jal         0x800DA298
    // 0x808000E4: addiu       $a0, $t6, 0xA8
    ctx->r4 = ADD32(ctx->r14, 0XA8);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808000E4: addiu       $a0, $t6, 0xA8
    ctx->r4 = ADD32(ctx->r14, 0XA8);
    after_1:
    // 0x808000E8: beql        $v0, $zero, L_80800198
    if (ctx->r2 == 0) {
        // 0x808000EC: lhu         $t2, 0x76($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0X76);
            goto L_80800198;
    }
    goto skip_1;
    // 0x808000EC: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
    skip_1:
    // 0x808000F0: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x808000F4: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x808000F8: jal         0x800DA298
    // 0x808000FC: addiu       $a0, $t7, 0xAB
    ctx->r4 = ADD32(ctx->r15, 0XAB);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808000FC: addiu       $a0, $t7, 0xAB
    ctx->r4 = ADD32(ctx->r15, 0XAB);
    after_2:
    // 0x80800100: bne         $v0, $zero, L_80800194
    if (ctx->r2 != 0) {
        // 0x80800104: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800194;
    }
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: jal         0x80101FDC
    // 0x8080010C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x8080010C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800110: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x80800114: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080011C: srl         $t8, $a2, 7
    ctx->r24 = S32(U32(ctx->r6) >> 7);
    // 0x80800120: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80800124: addiu       $a2, $t9, 0x3
    ctx->r6 = ADD32(ctx->r25, 0X3);
    // 0x80800128: jal         0x80085708
    // 0x8080012C: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x8080012C: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    after_4:
    // 0x80800130: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800134: srl         $t0, $a0, 7
    ctx->r8 = S32(U32(ctx->r4) >> 7);
    // 0x80800138: jal         0x800DA544
    // 0x8080013C: addiu       $a0, $t0, 0xAB
    ctx->r4 = ADD32(ctx->r8, 0XAB);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x8080013C: addiu       $a0, $t0, 0xAB
    ctx->r4 = ADD32(ctx->r8, 0XAB);
    after_5:
    // 0x80800140: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x80800144: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800148: srl         $t1, $v0, 7
    ctx->r9 = S32(U32(ctx->r2) >> 7);
    // 0x8080014C: beq         $t1, $zero, L_8080016C
    if (ctx->r9 == 0) {
        // 0x80800150: nop
    
            goto L_8080016C;
    }
    // 0x80800150: nop

    // 0x80800154: beq         $t1, $at, L_8080017C
    if (ctx->r9 == ctx->r1) {
        // 0x80800158: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080017C;
    }
    // 0x80800158: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080015C: beq         $t1, $at, L_8080018C
    if (ctx->r9 == ctx->r1) {
        // 0x80800160: nop
    
            goto L_8080018C;
    }
    // 0x80800160: nop

    // 0x80800164: b           L_80800198
    // 0x80800168: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
        goto L_80800198;
    // 0x80800168: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
L_8080016C:
    // 0x8080016C: jal         0x80088178
    // 0x80800170: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80800170: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_6:
    // 0x80800174: b           L_80800198
    // 0x80800178: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
        goto L_80800198;
    // 0x80800178: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
L_8080017C:
    // 0x8080017C: jal         0x80088178
    // 0x80800180: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80800180: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    after_7:
    // 0x80800184: b           L_80800198
    // 0x80800188: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
        goto L_80800198;
    // 0x80800188: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
L_8080018C:
    // 0x8080018C: jal         0x80088178
    // 0x80800190: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x80800190: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_8:
L_80800194:
    // 0x80800194: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
L_80800198:
    // 0x80800198: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080019C: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x808001A0: bnel        $t3, $at, L_80800258
    if (ctx->r11 != ctx->r1) {
        // 0x808001A4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800258;
    }
    goto skip_2;
    // 0x808001A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808001A8: jal         0x800DA298
    // 0x808001AC: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808001AC: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    after_9:
    // 0x808001B0: beq         $v0, $zero, L_80800254
    if (ctx->r2 == 0) {
        // 0x808001B4: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_80800254;
    }
    // 0x808001B4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x808001B8: jal         0x800D0A9C
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_10;
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808001C0: bne         $v0, $zero, L_80800254
    if (ctx->r2 != 0) {
        // 0x808001C4: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_80800254;
    }
    // 0x808001C4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x808001C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808001D4: jal         0x800D10D4
    // 0x808001D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D10D4(rdram, ctx);
        goto after_11;
    // 0x808001D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x808001DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808001E8: jal         0x80085708
    // 0x808001EC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x808001EC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_12:
    // 0x808001F0: b           L_80800258
    // 0x808001F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800258;
    // 0x808001F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001F8:
    // 0x808001F8: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x808001FC: srl         $t4, $v0, 7
    ctx->r12 = S32(U32(ctx->r2) >> 7);
    // 0x80800200: bnel        $t4, $zero, L_80800258
    if (ctx->r12 != 0) {
        // 0x80800204: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800258;
    }
    goto skip_3;
    // 0x80800204: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80800208: jal         0x800DA544
    // 0x8080020C: addiu       $a0, $t4, 0xAB
    ctx->r4 = ADD32(ctx->r12, 0XAB);
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x8080020C: addiu       $a0, $t4, 0xAB
    ctx->r4 = ADD32(ctx->r12, 0XAB);
    after_13:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: jal         0x80101FDC
    // 0x80800218: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x80800218: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x8080021C: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x80800220: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800228: srl         $t5, $a2, 7
    ctx->r13 = S32(U32(ctx->r6) >> 7);
    // 0x8080022C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80800230: addiu       $a2, $t6, 0x3
    ctx->r6 = ADD32(ctx->r14, 0X3);
    // 0x80800234: jal         0x80085708
    // 0x80800238: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    _capod_entrypoint_13(rdram, ctx);
        goto after_15;
    // 0x80800238: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    after_15:
    // 0x8080023C: jal         0x80088178
    // 0x80800240: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_16;
    // 0x80800240: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_16:
    // 0x80800244: b           L_80800258
    // 0x80800248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800258;
    // 0x80800248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080024C:
    // 0x8080024C: b           L_80800258
    // 0x80800250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800258;
    // 0x80800250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800254:
    // 0x80800254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800258:
    // 0x80800258: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080025C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800264: jr          $ra
    // 0x80800268: nop

    return;
    // 0x80800268: nop

;}
RECOMP_FUNC void func_800BC8F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC8F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BC8FC: addiu       $v0, $v0, -0x7D20
    ctx->r2 = ADD32(ctx->r2, -0X7D20);
    // 0x800BC900: lbu         $t6, 0xD($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XD);
    // 0x800BC904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BC908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BC90C: beql        $t6, $zero, L_800BC93C
    if (ctx->r14 == 0) {
        // 0x800BC910: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BC93C;
    }
    goto skip_0;
    // 0x800BC910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BC914: lbu         $t8, 0xC($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XC);
    // 0x800BC918: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800BC91C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BC920: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800BC924: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800BC928: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800BC92C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800BC930: jal         0x800E42E4
    // 0x800BC934: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E42E4(rdram, ctx);
        goto after_0;
    // 0x800BC934: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800BC938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BC93C:
    // 0x800BC93C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BC940: jr          $ra
    // 0x800BC944: nop

    return;
    // 0x800BC944: nop

;}
RECOMP_FUNC void bstalk_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: jr          $ra
    // 0x80800104: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800104: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bababykaz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084490: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x80084490);
    return;
    // 0x80084494: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800C52F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C52F4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C52F8: addiu       $t7, $t7, -0x5660
    ctx->r15 = ADD32(ctx->r15, -0X5660);
    // 0x800C52FC: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800C5300: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5304: lbu         $v1, 0xC($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC);
    // 0x800C5308: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C530C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C5310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5314: beq         $v1, $at, L_800C5328
    if (ctx->r3 == ctx->r1) {
        // 0x800C5318: sw          $a1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r5;
            goto L_800C5328;
    }
    // 0x800C5318: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800C531C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C5320: bne         $v1, $at, L_800C5330
    if (ctx->r3 != ctx->r1) {
        // 0x800C5324: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800C5330;
    }
    // 0x800C5324: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_800C5328:
    // 0x800C5328: b           L_800C53DC
    // 0x800C532C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C53DC;
    // 0x800C532C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C5330:
    // 0x800C5330: sb          $t8, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r24;
    // 0x800C5334: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C5338: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800C533C: addiu       $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x800C5340: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800C5344: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C5348: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800C534C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C5350: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C5354: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800C5358: jal         0x800A8A44
    // 0x800C535C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_800A8A44(rdram, ctx);
        goto after_0;
    // 0x800C535C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x800C5360: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800C5364: lui         $at, 0x3F10
    ctx->r1 = S32(0X3F10 << 16);
    // 0x800C5368: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C536C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800C5370: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800C5374: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5378: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C537C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800C5380: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C5384: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C5388: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800C538C: nop

    // 0x800C5390: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x800C5394: beq         $t3, $zero, L_800C53A0
    if (ctx->r11 == 0) {
        // 0x800C5398: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800C53A0;
    }
    // 0x800C5398: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800C539C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
L_800C53A0:
    // 0x800C53A0: subu        $t5, $t4, $a0
    ctx->r13 = SUB32(ctx->r12, ctx->r4);
    // 0x800C53A4: bgez        $t5, L_800C53B4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C53A8: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_800C53B4;
    }
    // 0x800C53A8: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800C53AC: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x800C53B0: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_800C53B4:
    // 0x800C53B4: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x800C53B8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800C53BC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800C53C0: bnel        $t7, $zero, L_800C53DC
    if (ctx->r15 != 0) {
        // 0x800C53C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C53DC;
    }
    goto skip_0;
    // 0x800C53C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800C53C8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C53CC: sb          $t8, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r24;
    // 0x800C53D0: jal         0x800C524C
    // 0x800C53D4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800C524C(rdram, ctx);
        goto after_1;
    // 0x800C53D4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800C53D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C53DC:
    // 0x800C53DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C53E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800C53E4: jr          $ra
    // 0x800C53E8: nop

    return;
    // 0x800C53E8: nop

;}
RECOMP_FUNC void _chweather_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859D8: syscall     185
    recomp_syscall_handler(rdram, ctx, 0x800859D8);
    return;
    // 0x800859DC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
