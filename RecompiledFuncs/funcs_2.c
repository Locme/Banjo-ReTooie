#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800384_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080038C: jal         0x800EA05C
    // 0x80800390: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800390: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800394: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
    // 0x80800398: bne         $v0, $at, L_808003A8
    if (ctx->r2 != ctx->r1) {
        // 0x8080039C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003A8;
    }
    // 0x8080039C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003A0: b           L_808003C4
    // 0x808003A4: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_808003C4;
    // 0x808003A4: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_808003A8:
    // 0x808003A8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808003AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1688, 0X2648) << 16);
    // 0x808003B0: lw          $t7, 0x6C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X6C);
    // 0x808003B4: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808003B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808003BC: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x808003C0: lw          $v0, 0x2648($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1688, 0X2648));
L_808003C4:
    // 0x808003C4: jr          $ra
    // 0x808003C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808003C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800A5904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A590C: jal         0x800A5854
    // 0x800A5910: nop

    func_800A5854(rdram, ctx);
        goto after_0;
    // 0x800A5910: nop

    after_0:
    // 0x800A5914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5918: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A591C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800A5920: jr          $ra
    // 0x800A5924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800A5924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5928: nop

    // 0x800A592C: nop

;}
RECOMP_FUNC void func_8080649C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080649C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808064A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808064A4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x808064A8: lw          $t7, 0x188($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X188);
    // 0x808064AC: jal         0x800D9004
    // 0x808064B0: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    func_800D9004(rdram, ctx);
        goto after_0;
    // 0x808064B0: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    after_0:
    // 0x808064B4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA550) << 16);
    // 0x808064B8: lwc1        $f2, -0x5AB0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA550));
    // 0x808064BC: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x808064C0: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x808064C4: addiu       $v0, $v0, 0x1CC
    ctx->r2 = ADD32(ctx->r2, 0X1CC);
    // 0x808064C8: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x808064CC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808064D0: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x808064D4: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x808064D8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808064DC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x808064E0: jal         0x808052C8
    // 0x808064E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_808052C8_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808064E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x808064E8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808064EC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x808064F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808064F4: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x808064F8: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x808064FC: jal         0x808052C8
    // 0x80806500: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    func_808052C8_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80806500: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_2:
    // 0x80806504: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80806508: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8080650C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80806510: jal         0x808052A4
    // 0x80806514: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    func_808052A4_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80806514: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    after_3:
    // 0x80806518: jal         0x8009C984
    // 0x8080651C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    yaw_get(rdram, ctx);
        goto after_4;
    // 0x8080651C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_4:
    // 0x80806520: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80806524: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80806528: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080652C: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80806530: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80806534: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80806538: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080653C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80806540: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80806544: jal         0x800EFCD8
    // 0x80806548: nop

    func_800EFCD8(rdram, ctx);
        goto after_5;
    // 0x80806548: nop

    after_5:
    // 0x8080654C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80806550: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80806554: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80806558: jal         0x8009BC08
    // 0x8080655C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    func_8009BC08(rdram, ctx);
        goto after_6;
    // 0x8080655C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80806560: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80806564: jal         0x800EF04C
    // 0x80806568: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80806568: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_7:
    // 0x8080656C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80806570: jal         0x8009B98C
    // 0x80806574: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009B98C(rdram, ctx);
        goto after_8;
    // 0x80806574: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_8:
    // 0x80806578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080657C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80806580: jr          $ra
    // 0x80806584: nop

    return;
    // 0x80806584: nop

;}
RECOMP_FUNC void func_80801248_chminisubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801248: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080124C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801250: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801254: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801258: jal         0x80090270
    // 0x8080125C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    func_80090270(rdram, ctx);
        goto after_0;
    // 0x8080125C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80801260: bnel        $v0, $zero, L_808012B4
    if (ctx->r2 != 0) {
        // 0x80801264: lw          $a1, 0x6C($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X6C);
            goto L_808012B4;
    }
    goto skip_0;
    // 0x80801264: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x80801268: jal         0x800DA298
    // 0x8080126C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080126C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80801270: bnel        $v0, $zero, L_80801288
    if (ctx->r2 != 0) {
        // 0x80801274: lui         $a2, 0x3F19
        ctx->r6 = S32(0X3F19 << 16);
            goto L_80801288;
    }
    goto skip_1;
    // 0x80801274: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    skip_1:
    // 0x80801278: jal         0x800CEAD0
    // 0x8080127C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_2;
    // 0x8080127C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80801280: bne         $v0, $zero, L_808012B0
    if (ctx->r2 != 0) {
        // 0x80801284: lui         $a2, 0x3F19
        ctx->r6 = S32(0X3F19 << 16);
            goto L_808012B0;
    }
    // 0x80801284: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
L_80801288:
    // 0x80801288: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x8080128C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80801290: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801294: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801298: jal         0x800E1610
    // 0x8080129C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_800E1610(rdram, ctx);
        goto after_3;
    // 0x8080129C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_3:
    // 0x808012A0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(792, 0X1578) << 16);
    // 0x808012A4: addiu       $a1, $a1, 0x1578
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(792, 0X1578));
    // 0x808012A8: jal         0x800C4AF0
    // 0x808012AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800C4AF0(rdram, ctx);
        goto after_4;
    // 0x808012AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_808012B0:
    // 0x808012B0: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_808012B4:
    // 0x808012B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808012BC: andi        $t6, $a1, 0x1FF
    ctx->r14 = ctx->r5 & 0X1FF;
    // 0x808012C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808012C4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x808012C8: addiu       $a1, $t7, 0x9A4
    ctx->r5 = ADD32(ctx->r15, 0X9A4);
    // 0x808012CC: jal         0x808011DC
    // 0x808012D0: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    func_808011DC_chminisubgame(rdram, ctx);
        goto after_5;
    // 0x808012D0: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808012D4: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808012D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012DC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808012E0: andi        $t8, $a1, 0x1FF
    ctx->r24 = ctx->r5 & 0X1FF;
    // 0x808012E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808012E8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808012EC: jal         0x808011DC
    // 0x808012F0: addiu       $a1, $t9, 0x9A5
    ctx->r5 = ADD32(ctx->r25, 0X9A5);
    func_808011DC_chminisubgame(rdram, ctx);
        goto after_6;
    // 0x808012F0: addiu       $a1, $t9, 0x9A5
    ctx->r5 = ADD32(ctx->r25, 0X9A5);
    after_6:
    // 0x808012F4: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808012F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80801300: andi        $t0, $a1, 0x1FF
    ctx->r8 = ctx->r5 & 0X1FF;
    // 0x80801304: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80801308: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8080130C: jal         0x808011DC
    // 0x80801310: addiu       $a1, $t1, 0x9A6
    ctx->r5 = ADD32(ctx->r9, 0X9A6);
    func_808011DC_chminisubgame(rdram, ctx);
        goto after_7;
    // 0x80801310: addiu       $a1, $t1, 0x9A6
    ctx->r5 = ADD32(ctx->r9, 0X9A6);
    after_7:
    // 0x80801314: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(792, 0X14F0) << 16);
    // 0x80801318: addiu       $t2, $t2, 0x14F0
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(792, 0X14F0));
    // 0x8080131C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801320: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801324: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801328: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080132C: jal         0x800BABB8
    // 0x80801330: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_8;
    // 0x80801330: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x80801334: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(792, 0X1534) << 16);
    // 0x80801338: addiu       $t3, $t3, 0x1534
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(792, 0X1534));
    // 0x8080133C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80801340: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801344: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080134C: jal         0x800BABB8
    // 0x80801350: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_9;
    // 0x80801350: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_9:
    // 0x80801354: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801358: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080135C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801360: jr          $ra
    // 0x80801364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801368: nop

    // 0x8080136C: nop

;}
RECOMP_FUNC void _basetup_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FC0: syscall     146
    recomp_syscall_handler(rdram, ctx, 0x80084FC0);
    return;
    // 0x80084FC4: xori        $t0, $zero, 0x10
    ctx->r8 = 0 ^ 0X10;
;}
RECOMP_FUNC void func_800D6CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6CF4: jal         0x800D6254
    // 0x800D6CF8: nop

    func_800D6254(rdram, ctx);
        goto after_0;
    // 0x800D6CF8: nop

    after_0:
    // 0x800D6CFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D6D00: beq         $v0, $at, L_800D6D54
    if (ctx->r2 == ctx->r1) {
        // 0x800D6D04: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D6D54;
    }
    // 0x800D6D04: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D6D08: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x800D6D0C: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6D10: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D6D14: addiu       $a1, $a1, -0x4800
    ctx->r5 = ADD32(ctx->r5, -0X4800);
    // 0x800D6D18: mflo        $t6
    ctx->r14 = lo;
    // 0x800D6D1C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800D6D20: lhu         $t8, 0xA($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XA);
    // 0x800D6D24: srl         $t9, $t8, 12
    ctx->r25 = S32(U32(ctx->r24) >> 12);
    // 0x800D6D28: beq         $t9, $zero, L_800D6D38
    if (ctx->r25 == 0) {
        // 0x800D6D2C: nop
    
            goto L_800D6D38;
    }
    // 0x800D6D2C: nop

    // 0x800D6D30: b           L_800D6D58
    // 0x800D6D34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D6D58;
    // 0x800D6D34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D6D38:
    // 0x800D6D38: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6D3C: mflo        $t0
    ctx->r8 = lo;
    // 0x800D6D40: addu        $a0, $a1, $t0
    ctx->r4 = ADD32(ctx->r5, ctx->r8);
    // 0x800D6D44: jal         0x800D6408
    // 0x800D6D48: nop

    func_800D6408(rdram, ctx);
        goto after_1;
    // 0x800D6D48: nop

    after_1:
    // 0x800D6D4C: b           L_800D6D5C
    // 0x800D6D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D6D5C;
    // 0x800D6D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D6D54:
    // 0x800D6D54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800D6D58:
    // 0x800D6D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D6D5C:
    // 0x800D6D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D6D60: jr          $ra
    // 0x800D6D64: nop

    return;
    // 0x800D6D64: nop

;}
RECOMP_FUNC void _chfiregen_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086990: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x80086990);
    return;
    // 0x80086994: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsbeefly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082850: syscall     16
    recomp_syscall_handler(rdram, ctx, 0x80082850);
    return;
    // 0x80082854: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080035C_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x80800380: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
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
RECOMP_FUNC void func_800A2EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2EDC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A2EE0: lw          $t6, 0x124($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X124);
    // 0x800A2EE4: jr          $ra
    // 0x800A2EE8: swc1        $f12, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x800A2EE8: swc1        $f12, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800954E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800954E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800954EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800954F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800954F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800954F8: jal         0x800D3E40
    // 0x800954FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800D3E40(rdram, ctx);
        goto after_0;
    // 0x800954FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80095500: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80095504: beq         $v0, $zero, L_80095514
    if (ctx->r2 == 0) {
        // 0x80095508: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80095514;
    }
    // 0x80095508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009550C: b           L_80095520
    // 0x80095510: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_80095520;
    // 0x80095510: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80095514:
    // 0x80095514: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80095518: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8009551C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80095520:
    // 0x80095520: lw          $t8, 0x7C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X7C);
    // 0x80095524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095528: lw          $v0, 0x14($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X14);
    // 0x8009552C: jr          $ra
    // 0x80095530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80095530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8080084C_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080084C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800850: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800858: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0XF58) << 16);
    // 0x8080085C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800860: addiu       $a2, $a2, 0xF58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0XF58));
    // 0x80800864: jal         0x8008A1F8
    // 0x80800868: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800868: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x8080086C: jal         0x8008A200
    // 0x80800870: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddiedialog_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800870: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800874: beq         $v0, $zero, L_80800894
    if (ctx->r2 == 0) {
        // 0x80800878: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800894;
    }
    // 0x80800878: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080087C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800880: jal         0x80800A64
    // 0x80800884: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800A64_chmineprospector(rdram, ctx);
        goto after_2;
    // 0x80800884: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_2:
    // 0x80800888: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080088C: jal         0x80108B04
    // 0x80800890: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_3;
    // 0x80800890: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80800894:
    // 0x80800894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080089C: jr          $ra
    // 0x808008A0: nop

    return;
    // 0x808008A0: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DF0: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DF0);
    return;
    // 0x80082DF4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80099730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099730: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80099734: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80099738: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009973C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80099740: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80099744: jal         0x8009AD20
    // 0x80099748: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_8009AD20(rdram, ctx);
        goto after_0;
    // 0x80099748: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_0:
    // 0x8009974C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099750: jal         0x800995B8
    // 0x80099754: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800995B8(rdram, ctx);
        goto after_1;
    // 0x80099754: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80099758: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8009975C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099760: beq         $t6, $zero, L_80099778
    if (ctx->r14 == 0) {
        // 0x80099764: nop
    
            goto L_80099778;
    }
    // 0x80099764: nop

    // 0x80099768: jal         0x800996E0
    // 0x8009976C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800996E0(rdram, ctx);
        goto after_2;
    // 0x8009976C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80099770: b           L_80099780
    // 0x80099774: nop

        goto L_80099780;
    // 0x80099774: nop

L_80099778:
    // 0x80099778: jal         0x800A17A8
    // 0x8009977C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_3;
    // 0x8009977C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
L_80099780:
    // 0x80099780: jal         0x800A1718
    // 0x80099784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_4;
    // 0x80099784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80099788: beq         $v0, $zero, L_800997A0
    if (ctx->r2 == 0) {
        // 0x8009978C: nop
    
            goto L_800997A0;
    }
    // 0x8009978C: nop

    // 0x80099790: jal         0x80084710
    // 0x80099794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_26(rdram, ctx);
        goto after_5;
    // 0x80099794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80099798: b           L_800997AC
    // 0x8009979C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800997AC;
    // 0x8009979C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800997A0:
    // 0x800997A0: jal         0x800846E0
    // 0x800997A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_20(rdram, ctx);
        goto after_6;
    // 0x800997A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800997A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800997AC:
    // 0x800997AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800997B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800997B4: jr          $ra
    // 0x800997B8: nop

    return;
    // 0x800997B8: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B90: jal         0x80105230
    // 0x80801B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_0;
    // 0x80801B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801BA0: jr          $ra
    // 0x80801BA4: nop

    return;
    // 0x80801BA4: nop

;}
RECOMP_FUNC void func_808000C4_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D4: jal         0x80100094
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000DC: beq         $v0, $zero, L_80800140
    if (ctx->r2 == 0) {
        // 0x808000E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800140;
    }
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x80100094
    // 0x808000E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808000E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000F0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808000F4: jal         0x800897D8
    // 0x808000F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808000F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808000FC: jal         0x801022E4
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_3;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800104: addiu       $at, $zero, 0xDC
    ctx->r1 = ADD32(0, 0XDC);
    // 0x80800108: bne         $v0, $at, L_80800128
    if (ctx->r2 != ctx->r1) {
        // 0x8080010C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800128;
    }
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: lui         $a1, 0x3EA3
    ctx->r5 = S32(0X3EA3 << 16);
    // 0x80800114: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800118: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080011C: jal         0x80102320
    // 0x80800120: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    func_80102320(rdram, ctx);
        goto after_4;
    // 0x80800120: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_4:
    // 0x80800124: bne         $v0, $zero, L_80800140
    if (ctx->r2 != 0) {
        // 0x80800128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800140;
    }
L_80800128:
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x80100094
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800134: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800138: jal         0x80089818
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_6;
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_80800140:
    // 0x80800140: jal         0x800F54E4
    // 0x80800144: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800144: nop

    after_7:
    // 0x80800148: lui         $at, 0x4382
    ctx->r1 = S32(0X4382 << 16);
    // 0x8080014C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800150: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800154: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800158: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x8080015C: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    // 0x80800160: jal         0x800F4EC8
    // 0x80800164: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_8;
    // 0x80800164: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80800168: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x8080016C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800170: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800174: beq         $t6, $at, L_808001A0
    if (ctx->r14 == ctx->r1) {
        // 0x80800178: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001A0;
    }
    // 0x80800178: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080017C: beq         $t6, $at, L_808001C0
    if (ctx->r14 == ctx->r1) {
        // 0x80800180: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808001C0;
    }
    // 0x80800180: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800184: beq         $t6, $at, L_808001D8
    if (ctx->r14 == ctx->r1) {
        // 0x80800188: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D8;
    }
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800190: beq         $t6, $at, L_80800260
    if (ctx->r14 == ctx->r1) {
        // 0x80800194: nop
    
            goto L_80800260;
    }
    // 0x80800194: nop

    // 0x80800198: b           L_80800274
    // 0x8080019C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800274;
    // 0x8080019C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001A0:
    // 0x808001A0: jal         0x808004DC
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004DC_chburgerstand(rdram, ctx);
        goto after_9;
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001A8: jal         0x808005AC
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005AC_chburgerstand(rdram, ctx);
        goto after_10;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001B0: jal         0x80800754
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800754_chburgerstand(rdram, ctx);
        goto after_11;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001B8: b           L_80800274
    // 0x808001BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800274;
    // 0x808001BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001C0:
    // 0x808001C0: jal         0x808004DC
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004DC_chburgerstand(rdram, ctx);
        goto after_12;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001C8: jal         0x808005AC
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005AC_chburgerstand(rdram, ctx);
        goto after_13;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001D0: b           L_80800274
    // 0x808001D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800274;
    // 0x808001D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001D8:
    // 0x808001D8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001DC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(936, 0XD48) << 16);
    // 0x808001E0: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x808001E4: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808001E8: addiu       $a2, $a2, 0xD48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(936, 0XD48));
    // 0x808001EC: jal         0x80089D20
    // 0x808001F0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x808001F0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_14:
    // 0x808001F4: jal         0x80101DDC
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_15;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808001FC: beql        $v0, $zero, L_80800274
    if (ctx->r2 == 0) {
        // 0x80800200: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800274;
    }
    goto skip_0;
    // 0x80800200: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800204: jal         0x800D1A04
    // 0x80800208: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_800D1A04(rdram, ctx);
        goto after_16;
    // 0x80800208: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_16:
    // 0x8080020C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80800210: subu        $a1, $t7, $v0
    ctx->r5 = SUB32(ctx->r15, ctx->r2);
    // 0x80800214: jal         0x800D175C
    // 0x80800218: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_800D175C(rdram, ctx);
        goto after_17;
    // 0x80800218: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_17:
    // 0x8080021C: jal         0x800FC660
    // 0x80800220: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_18;
    // 0x80800220: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_18:
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: jal         0x80102424
    // 0x8080022C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_19;
    // 0x8080022C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800230: jal         0x800FFA88
    // 0x80800234: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_800FFA88(rdram, ctx);
        goto after_20;
    // 0x80800234: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_20:
    // 0x80800238: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x8080023C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800240: addiu       $t8, $zero, 0x51
    ctx->r24 = ADD32(0, 0X51);
    // 0x80800244: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800248: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8080024C: addiu       $a1, $zero, 0x10FE
    ctx->r5 = ADD32(0, 0X10FE);
    // 0x80800250: jal         0x8008A208
    // 0x80800254: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x80800254: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_21:
    // 0x80800258: b           L_80800274
    // 0x8080025C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800274;
    // 0x8080025C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800260:
    // 0x80800260: jal         0x808004DC
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004DC_chburgerstand(rdram, ctx);
        goto after_22;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800268: jal         0x808005AC
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005AC_chburgerstand(rdram, ctx);
        goto after_23;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800270: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800274:
    // 0x80800274: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800278: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080027C: jr          $ra
    // 0x80800280: nop

    return;
    // 0x80800280: nop

;}
RECOMP_FUNC void _bsbanswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082780: syscall     10
    recomp_syscall_handler(rdram, ctx, 0x80082780);
    return;
    // 0x80082784: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800F101C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F101C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F1020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1024: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800F1028: jal         0x800F13C4
    // 0x800F102C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    func_800F13C4(rdram, ctx);
        goto after_0;
    // 0x800F102C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x800F1030: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F1034: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800F1038: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800F103C: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F1040: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800F1044: jal         0x800138D0
    // 0x800F1048: nop

    func_800138D0(rdram, ctx);
        goto after_1;
    // 0x800F1048: nop

    after_1:
    // 0x800F104C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F1050: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800F1054: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800F1058: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F105C: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800F1060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F1068: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800F106C: jr          $ra
    // 0x800F1070: nop

    return;
    // 0x800F1070: nop

;}
RECOMP_FUNC void func_8008DE24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DE24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DE28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DE2C: jal         0x80096568
    // 0x8008DE30: addiu       $a1, $zero, 0xE00
    ctx->r5 = ADD32(0, 0XE00);
    func_80096568(rdram, ctx);
        goto after_0;
    // 0x8008DE30: addiu       $a1, $zero, 0xE00
    ctx->r5 = ADD32(0, 0XE00);
    after_0:
    // 0x8008DE34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DE38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DE3C: jr          $ra
    // 0x8008DE40: nop

    return;
    // 0x8008DE40: nop

;}
RECOMP_FUNC void bskazegghead_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080027C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800288: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080028C: jal         0x80098140
    // 0x80800290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_0;
    // 0x80800290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800294: jal         0x8009BC6C
    // 0x80800298: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x80800298: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080029C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002A0: jal         0x800A0CF4
    // 0x808002A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x808002A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808002A8: jal         0x800832E8
    // 0x808002AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808002AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808002B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002B8: jr          $ra
    // 0x808002BC: nop

    return;
    // 0x808002BC: nop

;}
RECOMP_FUNC void func_808013E8_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013F0: jal         0x80800448
    // 0x808013F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexsmall_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808013F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808013FC: jal         0x80801294
    // 0x80801400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801294_bstrexsmall(rdram, ctx);
        goto after_1;
    // 0x80801400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080140C: jr          $ra
    // 0x80801410: nop

    return;
    // 0x80801410: nop

;}
RECOMP_FUNC void func_80802680_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802680: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80802684: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80802688: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x8080268C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802690: sw          $s7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r23;
    // 0x80802694: sw          $s6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r22;
    // 0x80802698: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x8080269C: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x808026A0: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x808026A4: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x808026A8: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x808026AC: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x808026B0: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808026B4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808026B8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808026BC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808026C0: jal         0x800D8FF8
    // 0x808026C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808026C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x808026C8: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x808026CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026D0: jal         0x80100094
    // 0x808026D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808026D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808026D8: addiu       $s5, $sp, 0x94
    ctx->r21 = ADD32(ctx->r29, 0X94);
    // 0x808026DC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808026E0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808026E4: jal         0x80103DFC
    // 0x808026E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103DFC(rdram, ctx);
        goto after_2;
    // 0x808026E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808026EC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808026F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808026F4: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x808026F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808026FC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80802700: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80802704: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80802708: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8080270C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80802710: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(1332, 0X3060) << 16);
    // 0x80802714: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80802718: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8080271C: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x80802720: addiu       $s6, $s6, 0x3060
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(1332, 0X3060));
    // 0x80802724: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80802728: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8080272C: addiu       $s7, $zero, 0x6
    ctx->r23 = ADD32(0, 0X6);
L_80802730:
    // 0x80802730: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802734: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80802738: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x8080273C: c.lt.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl < ctx->f12.fl;
    // 0x80802740: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80802744: addu        $s3, $s4, $t6
    ctx->r19 = ADD32(ctx->r20, ctx->r14);
    // 0x80802748: addiu       $s3, $s3, 0x3C
    ctx->r19 = ADD32(ctx->r19, 0X3C);
    // 0x8080274C: bc1fl       L_808027AC
    if (!c1cs) {
        // 0x80802750: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808027AC;
    }
    goto skip_0;
    // 0x80802750: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80802754: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80802758: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8080275C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80802760: jal         0x800F10B4
    // 0x80802764: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80802764: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    after_3:
    // 0x80802768: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080276C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80802770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802774: sub.s       $f16, $f10, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f30.fl;
    // 0x80802778: jal         0x800B53A4
    // 0x8080277C: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    func_800B53A4(rdram, ctx);
        goto after_4;
    // 0x8080277C: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    after_4:
    // 0x80802780: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80802784: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80802788: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080278C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80802790: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80802794: jal         0x800BABB8
    // 0x80802798: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x80802798: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_5:
    // 0x8080279C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808027A0: jal         0x800BA22C
    // 0x808027A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x808027A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808027A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808027AC:
    // 0x808027AC: bne         $s1, $s7, L_80802730
    if (ctx->r17 != ctx->r23) {
        // 0x808027B0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80802730;
    }
    // 0x808027B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808027B4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x808027B8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808027BC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808027C0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808027C4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808027C8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808027CC: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x808027D0: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x808027D4: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x808027D8: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x808027DC: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x808027E0: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x808027E4: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x808027E8: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x808027EC: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
    // 0x808027F0: jr          $ra
    // 0x808027F4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x808027F4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_800DF8D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF8D4: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x800DF8D8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800DF8DC: beq         $t6, $zero, L_800DF8F0
    if (ctx->r14 == 0) {
        // 0x800DF8E0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800DF8F0;
    }
    // 0x800DF8E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800DF8E4: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x800DF8E8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800DF8EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800DF8F0:
    // 0x800DF8F0: jr          $ra
    // 0x800DF8F4: nop

    return;
    // 0x800DF8F4: nop

;}
RECOMP_FUNC void func_800E765C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E765C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800E7660: addiu       $a1, $a1, -0x2A80
    ctx->r5 = ADD32(ctx->r5, -0X2A80);
    // 0x800E7664: lbu         $t6, 0x24($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X24);
    // 0x800E7668: beq         $t6, $zero, L_800E768C
    if (ctx->r14 == 0) {
        // 0x800E766C: nop
    
            goto L_800E768C;
    }
    // 0x800E766C: nop

    // 0x800E7670: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E7674: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800E7678: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800E767C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800E7680: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800E7684: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800E7688: sb          $zero, 0x24($a1)
    MEM_B(0X24, ctx->r5) = 0;
L_800E768C:
    // 0x800E768C: jr          $ra
    // 0x800E7690: nop

    return;
    // 0x800E7690: nop

;}
RECOMP_FUNC void _bashoessuck_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850A8: syscall     149
    recomp_syscall_handler(rdram, ctx, 0x800850A8);
    return;
    // 0x800850AC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800580_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800580: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800588: jal         0x800EA05C
    // 0x8080058C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080058C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800590: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x80800594: beq         $v0, $at, L_808005CC
    if (ctx->r2 == ctx->r1) {
        // 0x80800598: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808005CC;
    }
    // 0x80800598: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080059C: addiu       $at, $zero, 0x106
    ctx->r1 = ADD32(0, 0X106);
    // 0x808005A0: beq         $v0, $at, L_808005F8
    if (ctx->r2 == ctx->r1) {
        // 0x808005A4: lui         $a1, 0x45C4
        ctx->r5 = S32(0X45C4 << 16);
            goto L_808005F8;
    }
    // 0x808005A4: lui         $a1, 0x45C4
    ctx->r5 = S32(0X45C4 << 16);
    // 0x808005A8: addiu       $at, $zero, 0x109
    ctx->r1 = ADD32(0, 0X109);
    // 0x808005AC: beq         $v0, $at, L_80800620
    if (ctx->r2 == ctx->r1) {
        // 0x808005B0: lui         $a1, 0xC392
        ctx->r5 = S32(0XC392 << 16);
            goto L_80800620;
    }
    // 0x808005B0: lui         $a1, 0xC392
    ctx->r5 = S32(0XC392 << 16);
    // 0x808005B4: addiu       $at, $zero, 0x10B
    ctx->r1 = ADD32(0, 0X10B);
    // 0x808005B8: beq         $v0, $at, L_80800644
    if (ctx->r2 == ctx->r1) {
        // 0x808005BC: lui         $a1, 0x4565
        ctx->r5 = S32(0X4565 << 16);
            goto L_80800644;
    }
    // 0x808005BC: lui         $a1, 0x4565
    ctx->r5 = S32(0X4565 << 16);
    // 0x808005C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808005C4: b           L_80800668
    // 0x808005C8: nop

        goto L_80800668;
    // 0x808005C8: nop

L_808005CC:
    // 0x808005CC: lui         $a1, 0x451D
    ctx->r5 = S32(0X451D << 16);
    // 0x808005D0: lui         $a2, 0x443B
    ctx->r6 = S32(0X443B << 16);
    // 0x808005D4: lui         $a3, 0xC51E
    ctx->r7 = S32(0XC51E << 16);
    // 0x808005D8: ori         $a3, $a3, 0x1000
    ctx->r7 = ctx->r7 | 0X1000;
    // 0x808005DC: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x808005E0: jal         0x800EFA4C
    // 0x808005E4: ori         $a1, $a1, 0x9000
    ctx->r5 = ctx->r5 | 0X9000;
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x808005E4: ori         $a1, $a1, 0x9000
    ctx->r5 = ctx->r5 | 0X9000;
    after_1:
    // 0x808005E8: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x808005EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808005F0: b           L_8080066C
    // 0x808005F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080066C;
    // 0x808005F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005F8:
    // 0x808005F8: lui         $a2, 0x44C1
    ctx->r6 = S32(0X44C1 << 16);
    // 0x808005FC: lui         $a3, 0xC476
    ctx->r7 = S32(0XC476 << 16);
    // 0x80800600: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80800604: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x80800608: jal         0x800EFA4C
    // 0x8080060C: ori         $a1, $a1, 0xF800
    ctx->r5 = ctx->r5 | 0XF800;
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x8080060C: ori         $a1, $a1, 0xF800
    ctx->r5 = ctx->r5 | 0XF800;
    after_2:
    // 0x80800610: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800614: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800618: b           L_8080066C
    // 0x8080061C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080066C;
    // 0x8080061C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800620:
    // 0x80800620: lui         $a3, 0x4524
    ctx->r7 = S32(0X4524 << 16);
    // 0x80800624: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x80800628: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8080062C: jal         0x800EFA4C
    // 0x80800630: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80800630: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_3:
    // 0x80800634: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800638: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080063C: b           L_8080066C
    // 0x80800640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080066C;
    // 0x80800640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800644:
    // 0x80800644: lui         $a3, 0xC4F9
    ctx->r7 = S32(0XC4F9 << 16);
    // 0x80800648: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x8080064C: ori         $a1, $a1, 0xE000
    ctx->r5 = ctx->r5 | 0XE000;
    // 0x80800650: jal         0x800EFA4C
    // 0x80800654: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800654: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    after_4:
    // 0x80800658: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080065C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800660: b           L_8080066C
    // 0x80800664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080066C;
    // 0x80800664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800668:
    // 0x80800668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080066C:
    // 0x8080066C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800670: jr          $ra
    // 0x80800674: nop

    return;
    // 0x80800674: nop

;}
RECOMP_FUNC void badeathmatch_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808002B4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808002B8: lw          $t7, 0x158($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X158);
    // 0x808002BC: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x808002C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808002C4: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x808002C8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x808002CC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x808002D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002D4: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
    // 0x808002D8: lh          $t9, 0x2E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2E);
    // 0x808002DC: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    // 0x808002E0: bgezl       $t9, L_808002F4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808002E4: lh          $t0, 0x10($v0)
        ctx->r8 = MEM_H(ctx->r2, 0X10);
            goto L_808002F4;
    }
    goto skip_0;
    // 0x808002E4: lh          $t0, 0x10($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X10);
    skip_0:
    // 0x808002E8: b           L_80800378
    // 0x808002EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800378;
    // 0x808002EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002F0: lh          $t0, 0x10($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X10);
L_808002F4:
    // 0x808002F4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x808002F8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x808002FC: jal         0x800F0D90
    // 0x80800300: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    func_800F0D90(rdram, ctx);
        goto after_0;
    // 0x80800300: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_0:
    // 0x80800304: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800308: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080030C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800310: lw          $t2, 0x158($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X158);
    // 0x80800314: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80800318: sh          $v0, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r2;
    // 0x8080031C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80800320: blezl       $t4, L_80800370
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80800324: lw          $t1, 0x158($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X158);
            goto L_80800370;
    }
    goto skip_1;
    // 0x80800324: lw          $t1, 0x158($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X158);
    skip_1:
    // 0x80800328: lw          $v0, 0x158($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X158);
    // 0x8080032C: lw          $t6, 0x184($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X184);
    // 0x80800330: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x80800334: lbu         $t7, 0x20($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X20);
    // 0x80800338: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8080033C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800340: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80800344: lh          $t0, 0x10($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10);
    // 0x80800348: bnel        $t0, $zero, L_80800358
    if (ctx->r8 != 0) {
        // 0x8080034C: addiu       $a0, $zero, 0x72
        ctx->r4 = ADD32(0, 0X72);
            goto L_80800358;
    }
    goto skip_2;
    // 0x8080034C: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    skip_2:
    // 0x80800350: sb          $a0, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r4;
    // 0x80800354: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
L_80800358:
    // 0x80800358: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8080035C: jal         0x80101238
    // 0x80800360: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80101238(rdram, ctx);
        goto after_1;
    // 0x80800360: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800364: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800368: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8080036C: lw          $t1, 0x158($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X158);
L_80800370:
    // 0x80800370: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x80800374: lh          $v0, 0x10($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X10);
L_80800378:
    // 0x80800378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080037C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_45(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D28: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D28);
    return;
    // 0x80082D2C: addi        $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
;}
RECOMP_FUNC void func_80800000_idbounce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8008FD48
    // 0x8080000C: nop

    func_8008FD48(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800014: beq         $v0, $at, L_80800038
    if (ctx->r2 == ctx->r1) {
        // 0x80800018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800038;
    }
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800020: beq         $v0, $at, L_80800044
    if (ctx->r2 == ctx->r1) {
        // 0x80800024: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80800044;
    }
    // 0x80800024: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800028: bne         $v0, $at, L_80800050
    if (ctx->r2 != ctx->r1) {
        // 0x8080002C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2890, 0XE30) << 16);
            goto L_80800050;
    }
    // 0x8080002C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2890, 0XE30) << 16);
    // 0x80800030: b           L_8080005C
    // 0x80800034: lwc1        $f0, 0xE30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2890, 0XE30));
        goto L_8080005C;
    // 0x80800034: lwc1        $f0, 0xE30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2890, 0XE30));
L_80800038:
    // 0x80800038: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2890, 0XE34) << 16);
    // 0x8080003C: b           L_8080005C
    // 0x80800040: lwc1        $f0, 0xE34($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2890, 0XE34));
        goto L_8080005C;
    // 0x80800040: lwc1        $f0, 0xE34($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2890, 0XE34));
L_80800044:
    // 0x80800044: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2890, 0XE38) << 16);
    // 0x80800048: b           L_8080005C
    // 0x8080004C: lwc1        $f0, 0xE38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2890, 0XE38));
        goto L_8080005C;
    // 0x8080004C: lwc1        $f0, 0xE38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2890, 0XE38));
L_80800050:
    // 0x80800050: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800054: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800058: nop

L_8080005C:
    // 0x8080005C: jr          $ra
    // 0x80800060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chflamer_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860D8: syscall     277
    recomp_syscall_handler(rdram, ctx, 0x800860D8);
    return;
    // 0x800860DC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void subaddiesect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800014: jal         0x80087F28
    // 0x80800018: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    _gcmapsects_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080001C: bne         $v0, $zero, L_808000A0
    if (ctx->r2 != 0) {
        // 0x80800020: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_808000A0;
    }
    // 0x80800020: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800024: andi        $t6, $a2, 0x1
    ctx->r14 = ctx->r6 & 0X1;
    // 0x80800028: beql        $t6, $zero, L_80800054
    if (ctx->r14 == 0) {
        // 0x8080002C: andi        $t0, $a2, 0x2
        ctx->r8 = ctx->r6 & 0X2;
            goto L_80800054;
    }
    goto skip_0;
    // 0x8080002C: andi        $t0, $a2, 0x2
    ctx->r8 = ctx->r6 & 0X2;
    skip_0:
    // 0x80800030: lw          $t7, 0x70($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X70);
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: sll         $t9, $t7, 28
    ctx->r25 = S32(ctx->r15 << 28);
    // 0x8080003C: bgezl       $t9, L_80800054
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800040: andi        $t0, $a2, 0x2
        ctx->r8 = ctx->r6 & 0X2;
            goto L_80800054;
    }
    goto skip_1;
    // 0x80800040: andi        $t0, $a2, 0x2
    ctx->r8 = ctx->r6 & 0X2;
    skip_1:
    // 0x80800044: jal         0x8010381C
    // 0x80800048: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8010381C(rdram, ctx);
        goto after_1;
    // 0x80800048: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x8080004C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800050: andi        $t0, $a2, 0x2
    ctx->r8 = ctx->r6 & 0X2;
L_80800054:
    // 0x80800054: beq         $t0, $zero, L_80800068
    if (ctx->r8 == 0) {
        // 0x80800058: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800068;
    }
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: jal         0x8010A570
    // 0x80800060: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80800060: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x80800064: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_80800068:
    // 0x80800068: andi        $t1, $a2, 0x4
    ctx->r9 = ctx->r6 & 0X4;
    // 0x8080006C: beq         $t1, $zero, L_80800080
    if (ctx->r9 == 0) {
        // 0x80800070: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800080;
    }
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: jal         0x8010A624
    // 0x80800078: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8010A624(rdram, ctx);
        goto after_3;
    // 0x80800078: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x8080007C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_80800080:
    // 0x80800080: andi        $t2, $a2, 0x8
    ctx->r10 = ctx->r6 & 0X8;
    // 0x80800084: beq         $t2, $zero, L_80800098
    if (ctx->r10 == 0) {
        // 0x80800088: nop
    
            goto L_80800098;
    }
    // 0x80800088: nop

    // 0x8080008C: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800090: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x80800094: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_80800098:
    // 0x80800098: b           L_8080010C
    // 0x8080009C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080010C;
    // 0x8080009C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000A0:
    // 0x808000A0: andi        $t5, $a2, 0x2
    ctx->r13 = ctx->r6 & 0X2;
    // 0x808000A4: beq         $t5, $zero, L_808000B8
    if (ctx->r13 == 0) {
        // 0x808000A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000B8;
    }
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x8010A590
    // 0x808000B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8010A590(rdram, ctx);
        goto after_4;
    // 0x808000B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_4:
    // 0x808000B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_808000B8:
    // 0x808000B8: andi        $t6, $a2, 0x4
    ctx->r14 = ctx->r6 & 0X4;
    // 0x808000BC: beq         $t6, $zero, L_808000D0
    if (ctx->r14 == 0) {
        // 0x808000C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x8010A63C
    // 0x808000C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8010A63C(rdram, ctx);
        goto after_5;
    // 0x808000C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_5:
    // 0x808000CC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_808000D0:
    // 0x808000D0: andi        $t7, $a2, 0x8
    ctx->r15 = ctx->r6 & 0X8;
    // 0x808000D4: beq         $t7, $zero, L_80800108
    if (ctx->r15 == 0) {
        // 0x808000D8: andi        $t8, $a2, 0x10
        ctx->r24 = ctx->r6 & 0X10;
            goto L_80800108;
    }
    // 0x808000D8: andi        $t8, $a2, 0x10
    ctx->r24 = ctx->r6 & 0X10;
    // 0x808000DC: beql        $t8, $zero, L_80800100
    if (ctx->r24 == 0) {
        // 0x808000E0: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_80800100;
    }
    goto skip_2;
    // 0x808000E0: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_2:
    // 0x808000E4: lhu         $t9, 0x64($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X64);
    // 0x808000E8: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x808000EC: bnel        $t0, $zero, L_80800100
    if (ctx->r8 != 0) {
        // 0x808000F0: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_80800100;
    }
    goto skip_3;
    // 0x808000F0: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_3:
    // 0x808000F4: jal         0x80089CA0
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000FC: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_80800100:
    // 0x80800100: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80800104: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80800108:
    // 0x80800108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080010C:
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800114: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void func_80800B8C_chlavagargoyle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800B90: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B9C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800BA0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800BA4: jal         0x800B53A4
    // 0x80800BA8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800BA8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80800BAC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800BB0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800BB4: addiu       $a1, $a1, 0x7580
    ctx->r5 = ADD32(ctx->r5, 0X7580);
    // 0x80800BB8: jal         0x800BA544
    // 0x80800BBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BA544(rdram, ctx);
        goto after_1;
    // 0x80800BBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800BC0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800BC4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2324, 0XE50) << 16);
    // 0x80800BC8: addiu       $t6, $t6, 0xE50
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2324, 0XE50));
    // 0x80800BCC: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80800BD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800BD4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BD8: jal         0x800BABB8
    // 0x80800BDC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800BDC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_2:
    // 0x80800BE0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BE4: jal         0x800BA22C
    // 0x80800BE8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800BE8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80800BEC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800BF0: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2324, 0XE98) << 16);
    // 0x80800BF4: addiu       $t8, $t8, 0xE98
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2324, 0XE98));
    // 0x80800BF8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800BFC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800C00: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800C04: jal         0x800BBCB8
    // 0x80800C08: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x80800C08: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80800C0C: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80800C10: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800C14: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800C18: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800C1C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800C20: jal         0x800C4140
    // 0x80800C24: ori         $a0, $a0, 0x5C13
    ctx->r4 = ctx->r4 | 0X5C13;
    func_800C4140(rdram, ctx);
        goto after_5;
    // 0x80800C24: ori         $a0, $a0, 0x5C13
    ctx->r4 = ctx->r4 | 0X5C13;
    after_5:
    // 0x80800C28: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80800C2C: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800C30: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800C34: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800C38: jal         0x800C4140
    // 0x80800C3C: ori         $a0, $a0, 0x5C17
    ctx->r4 = ctx->r4 | 0X5C17;
    func_800C4140(rdram, ctx);
        goto after_6;
    // 0x80800C3C: ori         $a0, $a0, 0x5C17
    ctx->r4 = ctx->r4 | 0X5C17;
    after_6:
    // 0x80800C40: jal         0x80089D40
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800C48: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80800C4C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80800C50: jal         0x800863E8
    // 0x80800C54: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800C54: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_8:
    // 0x80800C58: jal         0x800FFA88
    // 0x80800C5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_9;
    // 0x80800C5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x80800C60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C64: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800C6C: jr          $ra
    // 0x80800C70: nop

    return;
    // 0x80800C70: nop

;}
RECOMP_FUNC void func_80801F18_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801F1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801F20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801F24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801F28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801F2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801F30: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
L_80801F34:
    // 0x80801F34: jal         0x800D1338
    // 0x80801F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D1338(rdram, ctx);
        goto after_0;
    // 0x80801F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801F3C: beq         $v0, $zero, L_80801F4C
    if (ctx->r2 == 0) {
        // 0x80801F40: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801F4C;
    }
    // 0x80801F40: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801F44: b           L_80801F58
    // 0x80801F48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801F58;
    // 0x80801F48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801F4C:
    // 0x80801F4C: bne         $s0, $s1, L_80801F34
    if (ctx->r16 != ctx->r17) {
        // 0x80801F50: nop
    
            goto L_80801F34;
    }
    // 0x80801F50: nop

    // 0x80801F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801F58:
    // 0x80801F58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801F5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801F60: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801F64: jr          $ra
    // 0x80801F68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801F68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C92A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C92A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C92AC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C92B0: addiu       $t6, $t6, -0x54C0
    ctx->r14 = ADD32(ctx->r14, -0X54C0);
    // 0x800C92B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C92B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C92BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C92C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C92C4: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x800C92C8: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x800C92CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C92D0: blez        $t7, L_800C92F8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C92D4: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_800C92F8;
    }
    // 0x800C92D4: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
L_800C92D8:
    // 0x800C92D8: jal         0x800881F0
    // 0x800C92DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    _gctransitionDll_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x800C92DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x800C92E0: lbu         $t8, 0x14($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X14);
    // 0x800C92E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C92E8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800C92EC: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C92F0: bne         $at, $zero, L_800C92D8
    if (ctx->r1 != 0) {
        // 0x800C92F4: nop
    
            goto L_800C92D8;
    }
    // 0x800C92F4: nop

L_800C92F8:
    // 0x800C92F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C92FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C9300: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9304: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C9308: jr          $ra
    // 0x800C930C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C930C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ncpod_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800698: jr          $ra
    // 0x8080069C: lbu         $v0, 0x41($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X41);
    return;
    // 0x8080069C: lbu         $v0, 0x41($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X41);
;}
RECOMP_FUNC void idbounce_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080090C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800914: jal         0x8001B084
    // 0x80800918: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    heap_free(rdram, ctx);
        goto after_0;
    // 0x80800918: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    after_0:
    // 0x8080091C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80800920: addiu       $v0, $v0, 0x5480
    ctx->r2 = ADD32(ctx->r2, 0X5480);
    // 0x80800924: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x80800928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080092C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800930: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800934: jr          $ra
    // 0x80800938: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
    return;
    // 0x80800938: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_800D0894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0894: sltiu       $at, $a0, 0x9
    ctx->r1 = ctx->r4 < 0X9 ? 1 : 0;
    // 0x800D0898: beq         $at, $zero, L_800D0900
    if (ctx->r1 == 0) {
        // 0x800D089C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800D0900;
    }
    // 0x800D089C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800D08A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D08A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D08A8: addu        $at, $at, $t6
    gpr jr_addend_800D08B0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D08AC: lw          $t6, 0x5A50($at)
    ctx->r14 = ADD32(ctx->r1, 0X5A50);
    // 0x800D08B0: jr          $t6
    // 0x800D08B4: nop

    switch (jr_addend_800D08B0 >> 2) {
        case 0: goto L_800D08B8; break;
        case 1: goto L_800D08C0; break;
        case 2: goto L_800D08C8; break;
        case 3: goto L_800D08D0; break;
        case 4: goto L_800D08D8; break;
        case 5: goto L_800D08E0; break;
        case 6: goto L_800D08E8; break;
        case 7: goto L_800D08F0; break;
        case 8: goto L_800D08F8; break;
        default: switch_error(__func__, 0x800D08B0, 0x80125A50);
    }
    // 0x800D08B4: nop

L_800D08B8:
    // 0x800D08B8: jr          $ra
    // 0x800D08BC: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    return;
    // 0x800D08BC: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_800D08C0:
    // 0x800D08C0: jr          $ra
    // 0x800D08C4: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    return;
    // 0x800D08C4: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
L_800D08C8:
    // 0x800D08C8: jr          $ra
    // 0x800D08CC: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x800D08CC: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_800D08D0:
    // 0x800D08D0: jr          $ra
    // 0x800D08D4: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    return;
    // 0x800D08D4: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800D08D8:
    // 0x800D08D8: jr          $ra
    // 0x800D08DC: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x800D08DC: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_800D08E0:
    // 0x800D08E0: jr          $ra
    // 0x800D08E4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x800D08E4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_800D08E8:
    // 0x800D08E8: jr          $ra
    // 0x800D08EC: addiu       $v0, $zero, 0x99
    ctx->r2 = ADD32(0, 0X99);
    return;
    // 0x800D08EC: addiu       $v0, $zero, 0x99
    ctx->r2 = ADD32(0, 0X99);
L_800D08F0:
    // 0x800D08F0: jr          $ra
    // 0x800D08F4: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    return;
    // 0x800D08F4: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_800D08F8:
    // 0x800D08F8: jr          $ra
    // 0x800D08FC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x800D08FC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800D0900:
    // 0x800D0900: jr          $ra
    // 0x800D0904: nop

    return;
    // 0x800D0904: nop

;}
RECOMP_FUNC void func_8010D248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D248: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010D24C: jr          $ra
    // 0x8010D250: lh          $v0, 0x6F5E($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6F5E);
    return;
    // 0x8010D250: lh          $v0, 0x6F5E($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6F5E);
;}
RECOMP_FUNC void func_80101870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101878: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010187C: jal         0x80101970
    // 0x80101880: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80101970(rdram, ctx);
        goto after_0;
    // 0x80101880: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80101884: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80101888: addiu       $a1, $a1, 0x15D0
    ctx->r5 = ADD32(ctx->r5, 0X15D0);
    // 0x8010188C: jal         0x80101808
    // 0x80101890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101808(rdram, ctx);
        goto after_1;
    // 0x80101890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80101894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010189C: jr          $ra
    // 0x801018A0: nop

    return;
    // 0x801018A0: nop

;}
RECOMP_FUNC void func_80800104_chdinofamilymissing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800108: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800110: jal         0x80103EF4
    // 0x80800114: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80103EF4(rdram, ctx);
        goto after_0;
    // 0x80800114: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800118: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8080011C: jal         0x80103EAC
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_1;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800124: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800128: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080012C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80800130: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800134: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800138: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080013C: jal         0x80089F20
    // 0x80800140: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800140: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x80800144: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x80800148: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x8080014C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800150: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x80800154: beq         $at, $zero, L_80800308
    if (ctx->r1 == 0) {
        // 0x80800158: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800308;
    }
    // 0x80800158: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8080015C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2260, 0X640) << 16);
    // 0x80800160: addu        $at, $at, $t9
    gpr jr_addend_80800168 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800164: lw          $t9, 0x640($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2260, 0X640));
    // 0x80800168: jr          $t9
    // 0x8080016C: nop

    switch (jr_addend_80800168 >> 2) {
        case 0: goto L_80800170; break;
        case 1: goto L_808001F8; break;
        case 2: goto L_80800260; break;
        case 3: goto L_80800308; break;
        case 4: goto L_8080029C; break;
        default: switch_error(__func__, 0x80800168, 0x80800640);
    }
    // 0x8080016C: nop

L_80800170:
    // 0x80800170: jal         0x80800418
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800418_chdinofamilymissing(rdram, ctx);
        goto after_3;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800178: jal         0x80105834
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_4;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800180: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x80800184: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800188: jal         0x80105998
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105998(rdram, ctx);
        goto after_5;
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800190: beq         $v0, $zero, L_808001B0
    if (ctx->r2 == 0) {
        // 0x80800194: addiu       $a1, $zero, 0x17CD
        ctx->r5 = ADD32(0, 0X17CD);
            goto L_808001B0;
    }
    // 0x80800194: addiu       $a1, $zero, 0x17CD
    ctx->r5 = ADD32(0, 0X17CD);
    // 0x80800198: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080019C: addiu       $t0, $zero, 0x39
    ctx->r8 = ADD32(0, 0X39);
    // 0x808001A0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808001A4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808001A8: jal         0x8008A208
    // 0x808001AC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808001AC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_6:
L_808001B0:
    // 0x808001B0: jal         0x80105A5C
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_7;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001B8: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x808001BC: addiu       $a0, $zero, 0x118
        ctx->r4 = ADD32(0, 0X118);
            goto L_808001D4;
    }
    // 0x808001BC: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    // 0x808001C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808001C4: jal         0x80088868
    // 0x808001C8: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_8;
    // 0x808001C8: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    after_8:
    // 0x808001CC: jal         0x800FFAB0
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_808001D4:
    // 0x808001D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2260, 0X6A0) << 16);
    // 0x808001D8: lui         $a3, 0x3EF0
    ctx->r7 = S32(0X3EF0 << 16);
    // 0x808001DC: ori         $a3, $a3, 0xA3D7
    ctx->r7 = ctx->r7 | 0XA3D7;
    // 0x808001E0: addiu       $a2, $a2, 0x6A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2260, 0X6A0));
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x80089D20
    // 0x808001EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808001EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x808001F0: b           L_80800308
    // 0x808001F4: nop

        goto L_80800308;
    // 0x808001F4: nop

L_808001F8:
    // 0x808001F8: jal         0x80105A5C
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_11;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800200: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x80800204: nop
    
            goto L_8080022C;
    }
    // 0x80800204: nop

    // 0x80800208: jal         0x800DA524
    // 0x8080020C: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    func_800DA524(rdram, ctx);
        goto after_12;
    // 0x8080020C: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    after_12:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: jal         0x80102424
    // 0x80800218: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x80800218: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x8080021C: lbu         $t1, 0x77($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X77);
    // 0x80800220: andi        $t2, $t1, 0xFFF0
    ctx->r10 = ctx->r9 & 0XFFF0;
    // 0x80800224: b           L_8080023C
    // 0x80800228: sb          $t2, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r10;
        goto L_8080023C;
    // 0x80800228: sb          $t2, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r10;
L_8080022C:
    // 0x8080022C: jal         0x80800418
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800418_chdinofamilymissing(rdram, ctx);
        goto after_14;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800234: jal         0x80105834
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_15;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_8080023C:
    // 0x8080023C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2260, 0X6A0) << 16);
    // 0x80800240: lui         $a3, 0x3EF0
    ctx->r7 = S32(0X3EF0 << 16);
    // 0x80800244: ori         $a3, $a3, 0xA3D7
    ctx->r7 = ctx->r7 | 0XA3D7;
    // 0x80800248: addiu       $a2, $a2, 0x6A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2260, 0X6A0));
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: jal         0x80089D20
    // 0x80800254: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80800254: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x80800258: b           L_80800308
    // 0x8080025C: nop

        goto L_80800308;
    // 0x8080025C: nop

L_80800260:
    // 0x80800260: jal         0x80105A5C
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_17;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800268: beq         $v0, $zero, L_80800308
    if (ctx->r2 == 0) {
        // 0x8080026C: nop
    
            goto L_80800308;
    }
    // 0x8080026C: nop

    // 0x80800270: jal         0x800DA544
    // 0x80800274: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_800DA544(rdram, ctx);
        goto after_18;
    // 0x80800274: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_18:
    // 0x80800278: addiu       $a0, $zero, 0x290
    ctx->r4 = ADD32(0, 0X290);
    // 0x8080027C: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x80800280: jal         0x80101180
    // 0x80800284: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80101180(rdram, ctx);
        goto after_19;
    // 0x80800284: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_19:
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x80102424
    // 0x80800290: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_20;
    // 0x80800290: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_20:
    // 0x80800294: b           L_80800308
    // 0x80800298: nop

        goto L_80800308;
    // 0x80800298: nop

L_8080029C:
    // 0x8080029C: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x808002A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002A4: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808002A8: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x808002AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002B0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808002B4: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x808002B8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808002BC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808002C0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808002C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808002C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808002CC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x808002D0: jal         0x80089F20
    // 0x808002D4: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_21;
    // 0x808002D4: nop

    after_21:
    // 0x808002D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808002DC: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x808002E0: jal         0x8008A1D0
    // 0x808002E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_22;
    // 0x808002E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x808002E8: beq         $v0, $zero, L_80800308
    if (ctx->r2 == 0) {
        // 0x808002EC: addiu       $a1, $zero, 0x17CE
        ctx->r5 = ADD32(0, 0X17CE);
            goto L_80800308;
    }
    // 0x808002EC: addiu       $a1, $zero, 0x17CE
    ctx->r5 = ADD32(0, 0X17CE);
    // 0x808002F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002F4: addiu       $t4, $zero, 0x39
    ctx->r12 = ADD32(0, 0X39);
    // 0x808002F8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808002FC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800300: jal         0x8008A208
    // 0x80800304: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_23;
    // 0x80800304: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_23:
L_80800308:
    // 0x80800308: jal         0x80087738
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdinofamilyfx_entrypoint_0(rdram, ctx);
        goto after_24;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800310: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800314: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800318: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080031C: jr          $ra
    // 0x80800320: nop

    return;
    // 0x80800320: nop

;}
RECOMP_FUNC void _babounce_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845F8: syscall     116
    recomp_syscall_handler(rdram, ctx, 0x800845F8);
    return;
    // 0x800845FC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _chfirefx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086130: syscall     281
    recomp_syscall_handler(rdram, ctx, 0x80086130);
    return;
    // 0x80086134: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800BEB64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEB64: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BEB68: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEB6C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEB70: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEB74: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BEB78: addiu       $t7, $t7, -0x7A50
    ctx->r15 = ADD32(ctx->r15, -0X7A50);
    // 0x800BEB7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEB80: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800BEB84: lbu         $t8, 0x29($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X29);
    // 0x800BEB88: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BEB8C: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x800BEB90: jr          $ra
    // 0x800BEB94: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
    return;
    // 0x800BEB94: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
;}
RECOMP_FUNC void func_80800090_chhotfloorsmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080009C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000A4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000A8: beq         $t6, $at, L_808000C0
    if (ctx->r14 == ctx->r1) {
        // 0x808000AC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000C0;
    }
    // 0x808000AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000B0: beq         $t6, $at, L_808000D0
    if (ctx->r14 == ctx->r1) {
        // 0x808000B4: addiu       $a0, $a2, 0x58
        ctx->r4 = ADD32(ctx->r6, 0X58);
            goto L_808000D0;
    }
    // 0x808000B4: addiu       $a0, $a2, 0x58
    ctx->r4 = ADD32(ctx->r6, 0X58);
    // 0x808000B8: b           L_808000F0
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000F0;
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000C0:
    // 0x808000C0: jal         0x808000FC
    // 0x808000C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808000FC_chhotfloorsmoke(rdram, ctx);
        goto after_0;
    // 0x808000C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x808000C8: b           L_808000F0
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000F0;
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000D0:
    // 0x808000D0: jal         0x800D9078
    // 0x808000D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x808000D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808000D8: beq         $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x808000DC: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_808000EC;
    }
    // 0x808000DC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808000E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808000E4: jal         0x80101FDC
    // 0x808000E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808000E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_808000EC:
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F0:
    // 0x808000F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
RECOMP_FUNC void func_800DF848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF848: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800DF84C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800DF850: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DF854: addiu       $t0, $t0, 0x2DC8
    ctx->r8 = ADD32(ctx->r8, 0X2DC8);
    // 0x800DF858: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800DF85C: addiu       $v1, $v1, -0x35D8
    ctx->r3 = ADD32(ctx->r3, -0X35D8);
    // 0x800DF860: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800DF864: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800DF868: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800DF86C: jr          $ra
    // 0x800DF870: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    return;
    // 0x800DF870: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_80801150_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801150: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801158: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080115C: jal         0x808005DC
    // 0x80801160: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    bstrexsmall_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801160: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80801164: jal         0x80084600
    // 0x80801168: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _babounce_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80801168: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080116C: beq         $v0, $zero, L_80801178
    if (ctx->r2 == 0) {
        // 0x80801170: addiu       $t6, $zero, 0x145
        ctx->r14 = ADD32(0, 0X145);
            goto L_80801178;
    }
    // 0x80801170: addiu       $t6, $zero, 0x145
    ctx->r14 = ADD32(0, 0X145);
    // 0x80801174: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80801178:
    // 0x80801178: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080117C: jal         0x8009E5C8
    // 0x80801180: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80801180: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80801184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801188: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080118C: jr          $ra
    // 0x80801190: nop

    return;
    // 0x80801190: nop

;}
RECOMP_FUNC void func_800D046C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D046C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0470: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D0474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0478: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D047C: jal         0x800D0A80
    // 0x800D0480: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800D0A80(rdram, ctx);
        goto after_0;
    // 0x800D0480: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800D0484: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D0488: jal         0x800DAC78
    // 0x800D048C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DAC78(rdram, ctx);
        goto after_1;
    // 0x800D048C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800D0490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D0498: jr          $ra
    // 0x800D049C: nop

    return;
    // 0x800D049C: nop

;}
RECOMP_FUNC void bssplitup_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C0: jal         0x800A0CF4
    // 0x808005C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_0;
    // 0x808005C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005D0: jr          $ra
    // 0x808005D4: nop

    return;
    // 0x808005D4: nop

;}
RECOMP_FUNC void func_80800580_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800588: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080058C: jal         0x80100094
    // 0x80800590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800594: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800598: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    // 0x8080059C: jal         0x80106790
    // 0x808005A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808005A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808005A4: jal         0x800D8FF8
    // 0x808005A8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x808005A8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x808005AC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808005B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1004, 0X980) << 16);
    // 0x808005B4: lwc1        $f6, 0x2C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x808005B8: lwc1        $f18, 0x34($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X34);
    // 0x808005BC: lwc1        $f4, 0x28($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X28);
    // 0x808005C0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808005C4: lwc1        $f16, 0x30($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X30);
    // 0x808005C8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808005CC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808005D0: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x808005D4: swc1        $f10, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f10.u32l;
    // 0x808005D8: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x808005DC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808005E0: lwc1        $f10, 0x980($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1004, 0X980));
    // 0x808005E4: lwc1        $f8, 0x28($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X28);
    // 0x808005E8: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808005EC: swc1        $f18, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f18.u32l;
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005F8: jr          $ra
    // 0x808005FC: nop

    return;
    // 0x808005FC: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D18: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D18);
    return;
    // 0x80087D1C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
