#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80804054_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804054: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80804058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080405C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80804060: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804064: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80804068: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8080406C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80804070: jal         0x80100094
    // 0x80804074: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804074: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80804078: jal         0x800D8FF8
    // 0x8080407C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080407C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80804080: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80804084: lw          $a2, 0xF0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XF0);
    // 0x80804088: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8080408C: jal         0x800EF934
    // 0x80804090: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_800EF934(rdram, ctx);
        goto after_2;
    // 0x80804090: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_2:
    // 0x80804094: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80804098: jal         0x800EF04C
    // 0x8080409C: addiu       $a1, $s0, 0xE4
    ctx->r5 = ADD32(ctx->r16, 0XE4);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x8080409C: addiu       $a1, $s0, 0xE4
    ctx->r5 = ADD32(ctx->r16, 0XE4);
    after_3:
    // 0x808040A0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808040A4: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x808040A8: jal         0x800EF934
    // 0x808040AC: lw          $a2, 0x100($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X100);
    func_800EF934(rdram, ctx);
        goto after_4;
    // 0x808040AC: lw          $a2, 0x100($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X100);
    after_4:
    // 0x808040B0: addiu       $a1, $s0, 0xF4
    ctx->r5 = ADD32(ctx->r16, 0XF4);
    // 0x808040B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808040B8: jal         0x800EF04C
    // 0x808040BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808040BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x808040C0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808040C4: jal         0x800EEAD4
    // 0x808040C8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EEAD4(rdram, ctx);
        goto after_6;
    // 0x808040C8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_6:
    // 0x808040CC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808040D0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808040D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808040D8: jal         0x800EECE0
    // 0x808040DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EECE0(rdram, ctx);
        goto after_7;
    // 0x808040DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_7:
    // 0x808040E0: beq         $v0, $zero, L_80804134
    if (ctx->r2 == 0) {
        // 0x808040E4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80804134;
    }
    // 0x808040E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808040E8: lwc1        $f12, 0x100($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X100);
    // 0x808040EC: jal         0x800F1DCC
    // 0x808040F0: lwc1        $f14, 0xF0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XF0);
    func_800F1DCC(rdram, ctx);
        goto after_8;
    // 0x808040F0: lwc1        $f14, 0xF0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XF0);
    after_8:
    // 0x808040F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808040F8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x808040FC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80804100: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80804104: nop

    // 0x80804108: bc1fl       L_80804124
    if (!c1cs) {
        // 0x8080410C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80804124;
    }
    goto skip_0;
    // 0x8080410C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80804110: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80804114: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80804118: b           L_80804128
    // 0x8080411C: nop

        goto L_80804128;
    // 0x8080411C: nop

    // 0x80804120: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80804124:
    // 0x80804124: nop

L_80804128:
    // 0x80804128: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080412C: b           L_80804140
    // 0x80804130: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
        goto L_80804140;
    // 0x80804130: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
L_80804134:
    // 0x80804134: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80804138: nop

    // 0x8080413C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
L_80804140:
    // 0x80804140: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80804144: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80804148: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8080414C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80804150: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80804154: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80804158: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8080415C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80804160: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x80804164: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80804168: lwc1        $f10, 0xD8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x8080416C: sll         $t0, $a1, 1
    ctx->r8 = S32(ctx->r5 << 1);
    // 0x80804170: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80804174: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80804178: nop

    // 0x8080417C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80804180: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80804184: swc1        $f16, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f16.u32l;
    // 0x80804188: lwc1        $f0, 0xD8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x8080418C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80804190: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80804194: nop

    // 0x80804198: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x8080419C: bne         $at, $zero, L_808041CC
    if (ctx->r1 != 0) {
        // 0x808041A0: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_808041CC;
    }
    // 0x808041A0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x808041A4: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808041A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808041AC: nop

    // 0x808041B0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x808041B4: swc1        $f6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f6.u32l;
    // 0x808041B8: lwc1        $f10, 0xD8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x808041BC: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808041C0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x808041C4: b           L_808041F8
    // 0x808041C8: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
        goto L_808041F8;
    // 0x808041C8: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
L_808041CC:
    // 0x808041CC: bgez        $a0, L_808041F4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x808041D0: lui         $at, 0x4600
        ctx->r1 = S32(0X4600 << 16);
            goto L_808041F4;
    }
    // 0x808041D0: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808041D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808041D8: nop

    // 0x808041DC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808041E0: swc1        $f18, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f18.u32l;
    // 0x808041E4: lwc1        $f4, 0xD8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x808041E8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808041EC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x808041F0: nop

L_808041F4:
    // 0x808041F4: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
L_808041F8:
    // 0x808041F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X477C) << 16);
    // 0x808041FC: lwc1        $f10, 0x477C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X477C));
    // 0x80804200: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X4780) << 16);
    // 0x80804204: lwc1        $f18, 0x4780($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X4780));
    // 0x80804208: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8080420C: lwc1        $f6, 0xD0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XD0);
    // 0x80804210: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80804214: nop

    // 0x80804218: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080421C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80804220: swc1        $f10, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->f10.u32l;
    // 0x80804224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804228: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080422C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80804230: jr          $ra
    // 0x80804234: nop

    return;
    // 0x80804234: nop

;}
RECOMP_FUNC void _bsbreegullbash_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B00: syscall     26
    recomp_syscall_handler(rdram, ctx, 0x80082B00);
    return;
    // 0x80082B04: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800D28_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800D2C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800D30: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800D34: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800D38: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800D3C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800D40: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800D44: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800D48: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800D4C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800D50: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800D54: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800D58: jal         0x80100094
    // 0x80800D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D60: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
    // 0x80800D64: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800D68: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800D6C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800D70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800D74: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80800D78: beq         $t7, $zero, L_80800DF4
    if (ctx->r15 == 0) {
        // 0x80800D7C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800DF4;
    }
    // 0x80800D7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800D80: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800D84: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800D88: addiu       $s4, $s2, 0x18
    ctx->r20 = ADD32(ctx->r18, 0X18);
    // 0x80800D8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80800D90:
    // 0x80800D90: jal         0x800EEAD4
    // 0x80800D94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_1;
    // 0x80800D94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80800D98: beql        $s0, $zero, L_80800DB4
    if (ctx->r16 == 0) {
        // 0x80800D9C: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80800DB4;
    }
    goto skip_0;
    // 0x80800D9C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_0:
    // 0x80800DA0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800DA4: nop

    // 0x80800DA8: bc1f        L_80800DB4
    if (!c1cs) {
        // 0x80800DAC: nop
    
            goto L_80800DB4;
    }
    // 0x80800DAC: nop

    // 0x80800DB0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80800DB4:
    // 0x80800DB4: beql        $s0, $zero, L_80800DD0
    if (ctx->r16 == 0) {
        // 0x80800DB8: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_80800DD0;
    }
    goto skip_1;
    // 0x80800DB8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_1:
    // 0x80800DBC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80800DC0: nop

    // 0x80800DC4: bc1fl       L_80800DD8
    if (!c1cs) {
        // 0x80800DC8: swc1        $f24, 0x58($s1)
        MEM_W(0X58, ctx->r17) = ctx->f24.u32l;
            goto L_80800DD8;
    }
    goto skip_2;
    // 0x80800DC8: swc1        $f24, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f24.u32l;
    skip_2:
    // 0x80800DCC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_80800DD0:
    // 0x80800DD0: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x80800DD4: swc1        $f24, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f24.u32l;
L_80800DD8:
    // 0x80800DD8: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
    // 0x80800DDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800DE0: addiu       $s1, $s1, 0x60
    ctx->r17 = ADD32(ctx->r17, 0X60);
    // 0x80800DE4: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800DE8: sltu        $at, $s0, $t9
    ctx->r1 = ctx->r16 < ctx->r25 ? 1 : 0;
    // 0x80800DEC: bnel        $at, $zero, L_80800D90
    if (ctx->r1 != 0) {
        // 0x80800DF0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800D90;
    }
    goto skip_3;
    // 0x80800DF0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_3:
L_80800DF4:
    // 0x80800DF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800DF8: beq         $s3, $at, L_80800E48
    if (ctx->r19 == ctx->r1) {
        // 0x80800DFC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800E48;
    }
    // 0x80800DFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800E00: jal         0x80100094
    // 0x80800E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800E08: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x80800E0C: subu        $t0, $t0, $s3
    ctx->r8 = SUB32(ctx->r8, ctx->r19);
    // 0x80800E10: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800E14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800E1C: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80800E20: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x80800E24: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
    // 0x80800E28: swc1        $f6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f6.u32l;
    // 0x80800E2C: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x80800E30: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80800E34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800E38: andi        $t1, $a2, 0x1FF
    ctx->r9 = ctx->r6 & 0X1FF;
    // 0x80800E3C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80800E40: jal         0x80800824
    // 0x80800E44: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80800824_chnewfreezy(rdram, ctx);
        goto after_3;
    // 0x80800E44: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_3:
L_80800E48:
    // 0x80800E48: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800E4C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800E50: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800E54: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800E58: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800E5C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80800E60: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800E64: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800E68: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800E6C: jr          $ra
    // 0x80800E70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800E70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void gleeprom_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800094: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800098: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080009C: jal         0x80016934
    // 0x808000A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80016934(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x808000A4: jal         0x80016928
    // 0x808000A8: nop

    func_80016928(rdram, ctx);
        goto after_1;
    // 0x808000A8: nop

    after_1:
    // 0x808000AC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808000B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000B4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808000B8: bgez        $a1, L_808000C8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x808000BC: sra         $t6, $a1, 3
        ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
            goto L_808000C8;
    }
    // 0x808000BC: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x808000C0: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x808000C4: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_808000C8:
    // 0x808000C8: andi        $a1, $t6, 0xFF
    ctx->r5 = ctx->r14 & 0XFF;
    // 0x808000CC: jal         0x8002DE70
    // 0x808000D0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    osEepromLongRead_recomp(rdram, ctx);
        goto after_2;
    // 0x808000D0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808000D4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808000D8: jal         0x80016934
    // 0x808000DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80016934(rdram, ctx);
        goto after_3;
    // 0x808000DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x808000E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

    // 0x808000F4: nop

    // 0x808000F8: nop

    // 0x808000FC: nop

;}
RECOMP_FUNC void _bsledge_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837D8: syscall     74
    recomp_syscall_handler(rdram, ctx, 0x800837D8);
    return;
    // 0x800837DC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bstaxi_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E48: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E48);
    return;
    // 0x80083E4C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _sujiggy_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6C0: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6C0);
    return;
    // 0x8008A6C4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _chstatueboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086528: syscall     334
    recomp_syscall_handler(rdram, ctx, 0x80086528);
    return;
    // 0x8008652C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801B44_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801B48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801B4C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801B50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B54: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801B58: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(932, 0X2E00) << 16);
    // 0x80801B5C: addiu       $t7, $t7, 0x2E00
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(932, 0X2E00));
    // 0x80801B60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80801B64: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80801B68: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801B70: jal         0x800BBCB8
    // 0x80801B74: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80801B74: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x80801B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801B80: jr          $ra
    // 0x80801B84: nop

    return;
    // 0x80801B84: nop

;}
RECOMP_FUNC void func_8080046C_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080046C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800470: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800474: bne         $a1, $at, L_80800494
    if (ctx->r5 != ctx->r1) {
        // 0x80800478: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800494;
    }
    // 0x80800478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080047C: jal         0x80800720
    // 0x80800480: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800720_chbottlesfamily(rdram, ctx);
        goto after_0;
    // 0x80800480: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800484: jal         0x80089F60
    // 0x80800488: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800488: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080048C: b           L_808004A4
    // 0x80800490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004A4;
    // 0x80800490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800494:
    // 0x80800494: jal         0x80800720
    // 0x80800498: nop

    func_80800720_chbottlesfamily(rdram, ctx);
        goto after_2;
    // 0x80800498: nop

    after_2:
    // 0x8080049C: b           L_808004A8
    // 0x808004A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004A8;
    // 0x808004A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004A4:
    // 0x808004A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004A8:
    // 0x808004A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004AC: jr          $ra
    // 0x808004B0: nop

    return;
    // 0x808004B0: nop

;}
RECOMP_FUNC void chcamwaypoint_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(764, 0X130) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(764, 0X130));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(764, 0X130));
;}
RECOMP_FUNC void wait_one_frame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001577C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015780: jal         0x8002FF60
    // 0x80015784: nop

    osViGetCurrentLine_recomp(rdram, ctx);
        goto after_0;
    // 0x80015784: nop

    after_0:
    // 0x80015788: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8001578C: beq         $at, $zero, L_800157A8
    if (ctx->r1 == 0) {
        // 0x80015790: nop
    
            goto L_800157A8;
    }
    // 0x80015790: nop

L_80015794:
    // 0x80015794: jal         0x8002FF60
    // 0x80015798: nop

    osViGetCurrentLine_recomp(rdram, ctx);
        goto after_1;
    // 0x80015798: nop

    after_1:
    // 0x8001579C: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x800157A0: bne         $at, $zero, L_80015794
    if (ctx->r1 != 0) {
        // 0x800157A4: nop
    
            goto L_80015794;
    }
    // 0x800157A4: nop

L_800157A8:
    // 0x800157A8: jal         0x8002FF60
    // 0x800157AC: nop

    osViGetCurrentLine_recomp(rdram, ctx);
        goto after_2;
    // 0x800157AC: nop

    after_2:
    // 0x800157B0: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x800157B4: bnel        $at, $zero, L_800157D4
    if (ctx->r1 != 0) {
        // 0x800157B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800157D4;
    }
    goto skip_0;
    // 0x800157B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800157BC:
    // 0x800157BC: jal         0x8002FF60
    // 0x800157C0: nop

    osViGetCurrentLine_recomp(rdram, ctx);
        goto after_3;
    // 0x800157C0: nop

    after_3:
    // 0x800157C4: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x800157C8: beq         $at, $zero, L_800157BC
    if (ctx->r1 == 0) {
        // 0x800157CC: nop
    
            goto L_800157BC;
    }
    // 0x800157CC: nop

    // 0x800157D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800157D4:
    // 0x800157D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800157D8: jr          $ra
    // 0x800157DC: nop

    return;
    // 0x800157DC: nop

;}
RECOMP_FUNC void func_80800514_chmumbopad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800514: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800518: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080051C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800520: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800528: beq         $a1, $at, L_808005E4
    if (ctx->r5 == ctx->r1) {
        // 0x8080052C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808005E4;
    }
    // 0x8080052C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800530: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800534: beq         $a1, $at, L_808005AC
    if (ctx->r5 == ctx->r1) {
        // 0x80800538: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005AC;
    }
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080053C: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800540: beq         $a1, $at, L_80800558
    if (ctx->r5 == ctx->r1) {
        // 0x80800544: addiu       $at, $zero, 0xBB
        ctx->r1 = ADD32(0, 0XBB);
            goto L_80800558;
    }
    // 0x80800544: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x80800548: beql        $a1, $at, L_808005C0
    if (ctx->r5 == ctx->r1) {
        // 0x8080054C: lw          $t7, 0x6C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X6C);
            goto L_808005C0;
    }
    goto skip_0;
    // 0x8080054C: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x80800550: b           L_80800628
    // 0x80800554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800628;
    // 0x80800554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800558:
    // 0x80800558: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x8080055C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800560: bltzl       $t8, L_8080059C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800564: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080059C;
    }
    goto skip_1;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800568: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x8080056C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80800570: bltzl       $t1, L_8080059C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800574: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080059C;
    }
    goto skip_2;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800578: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: lw          $t3, 0x28($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X28);
    // 0x80800584: sll         $t5, $t3, 18
    ctx->r13 = S32(ctx->r11 << 18);
    // 0x80800588: bltzl       $t5, L_8080059C
    if (SIGNED(ctx->r13) < 0) {
        // 0x8080058C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080059C;
    }
    goto skip_3;
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800590: jal         0x808008CC
    // 0x80800594: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_808008CC_chmumbopad(rdram, ctx);
        goto after_0;
    // 0x80800594: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080059C:
    // 0x8080059C: jal         0x80103110
    // 0x808005A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808005A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808005A4: b           L_80800628
    // 0x808005A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800628;
    // 0x808005A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005AC:
    // 0x808005AC: jal         0x80800674
    // 0x808005B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800674_chmumbopad(rdram, ctx);
        goto after_2;
    // 0x808005B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808005B4: b           L_80800628
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800628;
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005BC: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_808005C0:
    // 0x808005C0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808005C4: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808005C8: bnel        $t6, $t8, L_80800628
    if (ctx->r14 != ctx->r24) {
        // 0x808005CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800628;
    }
    goto skip_4;
    // 0x808005CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x808005D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x808005D4: lbu         $t9, 0x2A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2A);
    // 0x808005D8: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x808005DC: b           L_80800624
    // 0x808005E0: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
        goto L_80800624;
    // 0x808005E0: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
L_808005E4:
    // 0x808005E4: lh          $t1, 0x28($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X28);
    // 0x808005E8: addiu       $at, $zero, 0x11DE
    ctx->r1 = ADD32(0, 0X11DE);
    // 0x808005EC: addiu       $a0, $zero, 0x18BD
    ctx->r4 = ADD32(0, 0X18BD);
    // 0x808005F0: bne         $t1, $at, L_8080061C
    if (ctx->r9 != ctx->r1) {
        // 0x808005F4: nop
    
            goto L_8080061C;
    }
    // 0x808005F4: nop

    // 0x808005F8: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808005FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800600: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800604: andi        $t2, $a1, 0x1FF
    ctx->r10 = ctx->r5 & 0X1FF;
    // 0x80800608: jal         0x800861A0
    // 0x8080060C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080060C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_3:
    // 0x80800610: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800614: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x80800618: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_8080061C:
    // 0x8080061C: b           L_80800628
    // 0x80800620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800628;
    // 0x80800620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800624:
    // 0x80800624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800628:
    // 0x80800628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080062C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800630: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800634: jr          $ra
    // 0x80800638: nop

    return;
    // 0x80800638: nop

;}
RECOMP_FUNC void func_808042A8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808042A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808042AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808042B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808042B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x808042B8: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x808042BC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808042C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808042C4: beq         $v0, $zero, L_808042E8
    if (ctx->r2 == 0) {
        // 0x808042C8: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808042E8;
    }
    // 0x808042C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808042CC: beq         $v0, $at, L_80804348
    if (ctx->r2 == ctx->r1) {
        // 0x808042D0: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80804348;
    }
    // 0x808042D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808042D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808042D8: beql        $v0, $at, L_808043B4
    if (ctx->r2 == ctx->r1) {
        // 0x808042DC: lw          $t8, 0x64($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X64);
            goto L_808043B4;
    }
    goto skip_0;
    // 0x808042DC: lw          $t8, 0x64($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X64);
    skip_0:
    // 0x808042E0: b           L_808043F4
    // 0x808042E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808043F4;
    // 0x808042E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808042E8:
    // 0x808042E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808042EC: jal         0x808036F8
    // 0x808042F0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_808036F8_chgameselect(rdram, ctx);
        goto after_0;
    // 0x808042F0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x808042F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808042F8: beq         $v0, $zero, L_80804334
    if (ctx->r2 == 0) {
        // 0x808042FC: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80804334;
    }
    // 0x808042FC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80804300: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80804304: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80804308: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8080430C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80804310: sw          $t7, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r15;
    // 0x80804314: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    // 0x80804318: jal         0x80801758
    // 0x8080431C: sw          $a1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r5;
    func_80801758_chgameselect(rdram, ctx);
        goto after_1;
    // 0x8080431C: sw          $a1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r5;
    after_1:
    // 0x80804320: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80804324: jal         0x8080218C
    // 0x80804328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080218C_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80804328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080432C: b           L_808043F4
    // 0x80804330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808043F4;
    // 0x80804330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804334:
    // 0x80804334: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80804338: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8080433C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80804340: b           L_808043F0
    // 0x80804344: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
        goto L_808043F0;
    // 0x80804344: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_80804348:
    // 0x80804348: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080434C: jal         0x808036F8
    // 0x80804350: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_808036F8_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80804350: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x80804354: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80804358: beq         $v0, $zero, L_80804374
    if (ctx->r2 == 0) {
        // 0x8080435C: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80804374;
    }
    // 0x8080435C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80804360: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80804364: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80804368: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8080436C: b           L_808043F0
    // 0x80804370: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
        goto L_808043F0;
    // 0x80804370: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
L_80804374:
    // 0x80804374: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80804378: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x8080437C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80804380: sw          $t3, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r11;
    // 0x80804384: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80804388: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    // 0x8080438C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80804390: sw          $t4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r12;
    // 0x80804394: jal         0x80801658
    // 0x80804398: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80801658_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80804398: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_4:
    // 0x8080439C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808043A0: lbu         $t6, 0x65($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X65);
    // 0x808043A4: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x808043A8: b           L_808043F0
    // 0x808043AC: sb          $t7, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r15;
        goto L_808043F0;
    // 0x808043AC: sb          $t7, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r15;
    // 0x808043B0: lw          $t8, 0x64($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X64);
L_808043B4:
    // 0x808043B4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x808043B8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x808043BC: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x808043C0: bltzl       $t0, L_808043F4
    if (SIGNED(ctx->r8) < 0) {
        // 0x808043C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808043F4;
    }
    goto skip_1;
    // 0x808043C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808043C8: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x808043CC: sw          $t2, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r10;
    // 0x808043D0: lw          $a1, 0x1C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X1C);
    // 0x808043D4: lw          $a0, 0x20($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X20);
    // 0x808043D8: jal         0x80803698
    // 0x808043DC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80803698_chgameselect(rdram, ctx);
        goto after_5;
    // 0x808043DC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_5:
    // 0x808043E0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808043E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808043E8: jal         0x80801714
    // 0x808043EC: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    func_80801714_chgameselect(rdram, ctx);
        goto after_6;
    // 0x808043EC: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    after_6:
L_808043F0:
    // 0x808043F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808043F4:
    // 0x808043F4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808043F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808043FC: jr          $ra
    // 0x80804400: nop

    return;
    // 0x80804400: nop

;}
RECOMP_FUNC void _sukickball_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AB0: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AB0);
    return;
    // 0x80089AB4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8010963C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010963C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109644: jal         0x80109538
    // 0x80109648: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80109538(rdram, ctx);
        goto after_0;
    // 0x80109648: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8010964C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109654: jr          $ra
    // 0x80109658: nop

    return;
    // 0x80109658: nop

;}
RECOMP_FUNC void func_800FC4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC4B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC4B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FC4B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC4BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800FC4C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800FC4C4: bne         $a1, $at, L_800FC4E8
    if (ctx->r5 != ctx->r1) {
        // 0x800FC4C8: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_800FC4E8;
    }
    // 0x800FC4C8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800FC4CC: jal         0x800FB5F8
    // 0x800FC4D0: nop

    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FC4D0: nop

    after_0:
    // 0x800FC4D4: bnel        $v0, $zero, L_800FC4E8
    if (ctx->r2 != 0) {
        // 0x800FC4D8: lw          $a1, 0x20($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X20);
            goto L_800FC4E8;
    }
    goto skip_0;
    // 0x800FC4D8: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    skip_0:
    // 0x800FC4DC: b           L_800FC4F8
    // 0x800FC4E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FC4F8;
    // 0x800FC4E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FC4E4: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
L_800FC4E8:
    // 0x800FC4E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800FC4EC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800FC4F0: jal         0x800FC3D8
    // 0x800FC4F4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_800FC3D8(rdram, ctx);
        goto after_1;
    // 0x800FC4F4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
L_800FC4F8:
    // 0x800FC4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC4FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC500: jr          $ra
    // 0x800FC504: nop

    return;
    // 0x800FC504: nop

;}
RECOMP_FUNC void _babuzz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847A0: syscall     120
    recomp_syscall_handler(rdram, ctx, 0x800847A0);
    return;
    // 0x800847A4: xori        $t0, $zero, 0x8
    ctx->r8 = 0 ^ 0X8;
;}
RECOMP_FUNC void func_80800C48_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C54: jal         0x80100094
    // 0x80800C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C60: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x80800C64: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800C68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800C6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800C70: jal         0x80089C20
    // 0x80800C74: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800C74: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800C78: beq         $v0, $zero, L_80800C94
    if (ctx->r2 == 0) {
        // 0x80800C7C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800C94;
    }
    // 0x80800C7C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C80: addiu       $a0, $v1, 0x60
    ctx->r4 = ADD32(ctx->r3, 0X60);
    // 0x80800C84: jal         0x8008A028
    // 0x80800C88: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800C88: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_2:
    // 0x80800C8C: b           L_80800CA0
    // 0x80800C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CA0;
    // 0x80800C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C94:
    // 0x80800C94: jal         0x8008A020
    // 0x80800C98: addiu       $a0, $v1, 0x60
    ctx->r4 = ADD32(ctx->r3, 0X60);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800C98: addiu       $a0, $v1, 0x60
    ctx->r4 = ADD32(ctx->r3, 0X60);
    after_3:
    // 0x80800C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CA0:
    // 0x80800CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CA8: jr          $ra
    // 0x80800CAC: nop

    return;
    // 0x80800CAC: nop

;}
RECOMP_FUNC void func_800FCA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCA90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FCA94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FCA98: jal         0x800FB5F8
    // 0x800FCA9C: nop

    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FCA9C: nop

    after_0:
    // 0x800FCAA0: beq         $v0, $zero, L_800FCAD0
    if (ctx->r2 == 0) {
        // 0x800FCAA4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FCAD0;
    }
    // 0x800FCAA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FCAA8: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x800FCAAC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800FCAB0: sb          $t6, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r14;
    // 0x800FCAB4: beq         $t7, $zero, L_800FCAC8
    if (ctx->r15 == 0) {
        // 0x800FCAB8: nop
    
            goto L_800FCAC8;
    }
    // 0x800FCAB8: nop

    // 0x800FCABC: lbu         $t8, 0x34($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X34);
    // 0x800FCAC0: beql        $t8, $zero, L_800FCAD4
    if (ctx->r24 == 0) {
        // 0x800FCAC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FCAD4;
    }
    goto skip_0;
    // 0x800FCAC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800FCAC8:
    // 0x800FCAC8: jal         0x800FB774
    // 0x800FCACC: nop

    func_800FB774(rdram, ctx);
        goto after_1;
    // 0x800FCACC: nop

    after_1:
L_800FCAD0:
    // 0x800FCAD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FCAD4:
    // 0x800FCAD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FCAD8: jr          $ra
    // 0x800FCADC: nop

    return;
    // 0x800FCADC: nop

;}
RECOMP_FUNC void func_80808948_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808948: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080894C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80808950: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80808954: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80808958: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080895C: jal         0x80100094
    // 0x80808960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80808960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808964: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80808968: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080896C: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_80808970:
    // 0x80808970: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
    // 0x80808974: beql        $a0, $zero, L_8080899C
    if (ctx->r4 == 0) {
        // 0x80808978: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8080899C;
    }
    goto skip_0;
    // 0x80808978: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x8080897C: jal         0x801069A4
    // 0x80808980: nop

    func_801069A4(rdram, ctx);
        goto after_1;
    // 0x80808980: nop

    after_1:
    // 0x80808984: beql        $v0, $zero, L_80808998
    if (ctx->r2 == 0) {
        // 0x80808988: sw          $zero, 0xB0($s0)
        MEM_W(0XB0, ctx->r16) = 0;
            goto L_80808998;
    }
    goto skip_1;
    // 0x80808988: sw          $zero, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = 0;
    skip_1:
    // 0x8080898C: jal         0x800FFA88
    // 0x80808990: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80808990: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
    after_2:
    // 0x80808994: sw          $zero, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = 0;
L_80808998:
    // 0x80808998: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8080899C:
    // 0x8080899C: bne         $s1, $s2, L_80808970
    if (ctx->r17 != ctx->r18) {
        // 0x808089A0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80808970;
    }
    // 0x808089A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808089A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808089A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808089AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808089B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808089B4: jr          $ra
    // 0x808089B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808089B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800F03AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F03AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F03B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800F03B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800F03B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F03BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F03C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800F03C4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800F03C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800F03CC: jal         0x800EFB24
    // 0x800F03D0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800F03D0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800F03D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F03D8: jal         0x800EEAA4
    // 0x800F03DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EEAA4(rdram, ctx);
        goto after_1;
    // 0x800F03DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x800F03E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F03E4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800F03E8: jal         0x800EFA20
    // 0x800F03EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EFA20(rdram, ctx);
        goto after_2;
    // 0x800F03EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x800F03F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800F03F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800F03F8: jal         0x800EFB24
    // 0x800F03FC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x800F03FC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x800F0400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0404: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F0408: jr          $ra
    // 0x800F040C: nop

    return;
    // 0x800F040C: nop

;}
RECOMP_FUNC void baswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080005C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800060: jal         0x80096544
    // 0x80800064: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80096544(rdram, ctx);
        goto after_0;
    // 0x80800064: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800068: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8080006C: beq         $t6, $zero, L_808000B0
    if (ctx->r14 == 0) {
        // 0x80800070: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808000B0;
    }
    // 0x80800070: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800074: jal         0x8009C150
    // 0x80800078: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8009C150(rdram, ctx);
        goto after_1;
    // 0x80800078: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080007C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80800080: jal         0x800964DC
    // 0x80800084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800964DC(rdram, ctx);
        goto after_2;
    // 0x80800084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800088: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8080008C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800090: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800098: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8080009C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808000A0: nop

    // 0x808000A4: bc1fl       L_808000B4
    if (!c1cs) {
        // 0x808000A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000B4;
    }
    goto skip_0;
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000B0:
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000B4:
    // 0x808000B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void glid_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800598: jr          $ra
    // 0x8080059C: sw          $a1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r5;
    return;
    // 0x8080059C: sw          $a1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_808070B0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808070B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808070B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808070B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808070BC: jal         0x80100094
    // 0x808070C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808070C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808070C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808070C8: jal         0x80802C40
    // 0x808070CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80802C40_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x808070CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808070D0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808070D4: lh          $t6, 0x7C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X7C);
    // 0x808070D8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808070DC: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x808070E0: beq         $at, $zero, L_8080726C
    if (ctx->r1 == 0) {
        // 0x808070E4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080726C;
    }
    // 0x808070E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808070E8: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9BF8) << 16);
    // 0x808070EC: addu        $at, $at, $t7
    gpr jr_addend_808070F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808070F0: lw          $t7, -0x6408($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9BF8));
    // 0x808070F4: jr          $t7
    // 0x808070F8: nop

    switch (jr_addend_808070F4 >> 2) {
        case 0: goto L_808070FC; break;
        case 1: goto L_80807118; break;
        case 2: goto L_808071A8; break;
        case 3: goto L_80807218; break;
        case 4: goto L_80807234; break;
        default: switch_error(__func__, 0x808070F4, 0x80809BF8);
    }
    // 0x808070F8: nop

L_808070FC:
    // 0x808070FC: jal         0x800D9078
    // 0x80807100: addiu       $a0, $v0, 0x84
    ctx->r4 = ADD32(ctx->r2, 0X84);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80807100: addiu       $a0, $v0, 0x84
    ctx->r4 = ADD32(ctx->r2, 0X84);
    after_2:
    // 0x80807104: beq         $v0, $zero, L_8080726C
    if (ctx->r2 == 0) {
        // 0x80807108: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_8080726C;
    }
    // 0x80807108: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8080710C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80807110: b           L_8080726C
    // 0x80807114: sh          $t8, 0x7C($t9)
    MEM_H(0X7C, ctx->r25) = ctx->r24;
        goto L_8080726C;
    // 0x80807114: sh          $t8, 0x7C($t9)
    MEM_H(0X7C, ctx->r25) = ctx->r24;
L_80807118:
    // 0x80807118: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080711C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80807120: jal         0x808063C8
    // 0x80807124: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_808063C8_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80807124: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_3:
    // 0x80807128: beql        $v0, $zero, L_80807270
    if (ctx->r2 == 0) {
        // 0x8080712C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80807270;
    }
    goto skip_0;
    // 0x8080712C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80807130: jal         0x80802228
    // 0x80807134: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80807134: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80807138: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080713C: jal         0x8080761C
    // 0x80807140: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080761C_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80807140: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80807144: beq         $v0, $zero, L_80807180
    if (ctx->r2 == 0) {
        // 0x80807148: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80807180;
    }
    // 0x80807148: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080714C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80807150: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80807154: jal         0x808008C0
    // 0x80807158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80807158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8080715C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80807160: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80807164: jal         0x808008C0
    // 0x80807168: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x80807168: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x8080716C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80807170: jal         0x8080041C
    // 0x80807174: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80807174: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_8:
    // 0x80807178: b           L_8080719C
    // 0x8080717C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
        goto L_8080719C;
    // 0x8080717C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80807180:
    // 0x80807180: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80807184: jal         0x808008C0
    // 0x80807188: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80807188: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x8080718C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80807190: jal         0x8080041C
    // 0x80807194: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x80807194: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_10:
    // 0x80807198: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_8080719C:
    // 0x8080719C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x808071A0: b           L_8080726C
    // 0x808071A4: sh          $t0, 0x7C($t1)
    MEM_H(0X7C, ctx->r9) = ctx->r8;
        goto L_8080726C;
    // 0x808071A4: sh          $t0, 0x7C($t1)
    MEM_H(0X7C, ctx->r9) = ctx->r8;
L_808071A8:
    // 0x808071A8: jal         0x80802228
    // 0x808071AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x808071AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_11:
    // 0x808071B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808071B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808071B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808071BC: jal         0x808063C8
    // 0x808071C0: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_808063C8_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x808071C0: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_12:
    // 0x808071C4: lui         $a1, 0x3E0F
    ctx->r5 = S32(0X3E0F << 16);
    // 0x808071C8: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x808071CC: jal         0x80101E14
    // 0x808071D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x808071D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_13:
    // 0x808071D4: beq         $v0, $zero, L_808071E4
    if (ctx->r2 == 0) {
        // 0x808071D8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808071E4;
    }
    // 0x808071D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808071DC: jal         0x80108B04
    // 0x808071E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_14;
    // 0x808071E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
L_808071E4:
    // 0x808071E4: jal         0x8080761C
    // 0x808071E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080761C_chdiggerboss(rdram, ctx);
        goto after_15;
    // 0x808071E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_15:
    // 0x808071EC: beq         $v0, $zero, L_8080726C
    if (ctx->r2 == 0) {
        // 0x808071F0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8080726C;
    }
    // 0x808071F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808071F4: lui         $a1, 0x3E8F
    ctx->r5 = S32(0X3E8F << 16);
    // 0x808071F8: jal         0x80101E14
    // 0x808071FC: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    func_80101E14(rdram, ctx);
        goto after_16;
    // 0x808071FC: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    after_16:
    // 0x80807200: beq         $v0, $zero, L_8080726C
    if (ctx->r2 == 0) {
        // 0x80807204: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080726C;
    }
    // 0x80807204: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80807208: jal         0x80108B04
    // 0x8080720C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80108B04(rdram, ctx);
        goto after_17;
    // 0x8080720C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x80807210: b           L_80807270
    // 0x80807214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80807270;
    // 0x80807214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80807218:
    // 0x80807218: jal         0x800D9078
    // 0x8080721C: addiu       $a0, $v0, 0x84
    ctx->r4 = ADD32(ctx->r2, 0X84);
    func_800D9078(rdram, ctx);
        goto after_18;
    // 0x8080721C: addiu       $a0, $v0, 0x84
    ctx->r4 = ADD32(ctx->r2, 0X84);
    after_18:
    // 0x80807220: beq         $v0, $zero, L_8080726C
    if (ctx->r2 == 0) {
        // 0x80807224: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_8080726C;
    }
    // 0x80807224: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80807228: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8080722C: b           L_8080726C
    // 0x80807230: sh          $t2, 0x7C($t3)
    MEM_H(0X7C, ctx->r11) = ctx->r10;
        goto L_8080726C;
    // 0x80807230: sh          $t2, 0x7C($t3)
    MEM_H(0X7C, ctx->r11) = ctx->r10;
L_80807234:
    // 0x80807234: addiu       $a0, $zero, 0x4F3
    ctx->r4 = ADD32(0, 0X4F3);
    // 0x80807238: jal         0x80089C30
    // 0x8080723C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x8080723C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80807240: bne         $v0, $zero, L_8080726C
    if (ctx->r2 != 0) {
        // 0x80807244: addiu       $a0, $zero, 0x4F4
        ctx->r4 = ADD32(0, 0X4F4);
            goto L_8080726C;
    }
    // 0x80807244: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    // 0x80807248: jal         0x80089C30
    // 0x8080724C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_20;
    // 0x8080724C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80807250: bne         $v0, $zero, L_8080726C
    if (ctx->r2 != 0) {
        // 0x80807254: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_8080726C;
    }
    // 0x80807254: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80807258: sh          $zero, 0x7C($t4)
    MEM_H(0X7C, ctx->r12) = 0;
    // 0x8080725C: jal         0x80802CB4
    // 0x80807260: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80802CB4_chdiggerboss(rdram, ctx);
        goto after_21;
    // 0x80807260: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_21:
    // 0x80807264: b           L_80807270
    // 0x80807268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80807270;
    // 0x80807268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080726C:
    // 0x8080726C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80807270:
    // 0x80807270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807274: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80807278: jr          $ra
    // 0x8080727C: nop

    return;
    // 0x8080727C: nop

;}
RECOMP_FUNC void _ncbaclimb_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089250: syscall     768
    recomp_syscall_handler(rdram, ctx, 0x80089250);
    return;
    // 0x80089254: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void gcdialogDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800008: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080000C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800014: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800018: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080001C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800020: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800024: sw          $zero, 0x100($a0)
    MEM_W(0X100, ctx->r4) = 0;
    // 0x80800028: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8080002C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800030: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800038: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_8080003C:
    // 0x8080003C: sw          $zero, 0x104($v1)
    MEM_W(0X104, ctx->r3) = 0;
    // 0x80800040: sb          $zero, 0x114($v0)
    MEM_B(0X114, ctx->r2) = 0;
    // 0x80800044: sw          $zero, 0x120($v1)
    MEM_W(0X120, ctx->r3) = 0;
    // 0x80800048: sb          $zero, 0x116($v0)
    MEM_B(0X116, ctx->r2) = 0;
    // 0x8080004C: sh          $s4, 0x118($a2)
    MEM_H(0X118, ctx->r6) = ctx->r20;
    // 0x80800050: sw          $zero, 0x10C($v1)
    MEM_W(0X10C, ctx->r3) = 0;
    // 0x80800054: lbu         $t6, 0x11C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X11C);
    // 0x80800058: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8080005C: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80800060: andi        $t8, $t6, 0xFF3F
    ctx->r24 = ctx->r14 & 0XFF3F;
    // 0x80800064: sb          $t8, 0x11C($v0)
    MEM_B(0X11C, ctx->r2) = ctx->r24;
    // 0x80800068: andi        $t9, $t8, 0xCF
    ctx->r25 = ctx->r24 & 0XCF;
    // 0x8080006C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800070: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800074: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80800078: bne         $at, $zero, L_8080003C
    if (ctx->r1 != 0) {
        // 0x8080007C: sb          $t9, 0x11B($v0)
        MEM_B(0X11B, ctx->r2) = ctx->r25;
            goto L_8080003C;
    }
    // 0x8080007C: sb          $t9, 0x11B($v0)
    MEM_B(0X11B, ctx->r2) = ctx->r25;
    // 0x80800080: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800084: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80800088: addiu       $s2, $s3, 0x188
    ctx->r18 = ADD32(ctx->r19, 0X188);
    // 0x8080008C: addiu       $s5, $zero, 0xB0
    ctx->r21 = ADD32(0, 0XB0);
L_80800090:
    // 0x80800090: sh          $s4, 0x184($s0)
    MEM_H(0X184, ctx->r16) = ctx->r20;
    // 0x80800094: sh          $zero, 0x186($s0)
    MEM_H(0X186, ctx->r16) = 0;
    // 0x80800098: sw          $zero, 0x194($s0)
    MEM_W(0X194, ctx->r16) = 0;
    // 0x8080009C: sh          $zero, 0x198($s0)
    MEM_H(0X198, ctx->r16) = 0;
    // 0x808000A0: sw          $zero, 0x19C($s0)
    MEM_W(0X19C, ctx->r16) = 0;
    // 0x808000A4: sw          $zero, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = 0;
    // 0x808000A8: sw          $zero, 0x1A4($s0)
    MEM_W(0X1A4, ctx->r16) = 0;
    // 0x808000AC: sw          $zero, 0x1A8($s0)
    MEM_W(0X1A8, ctx->r16) = 0;
    // 0x808000B0: jal         0x800EFD24
    // 0x808000B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x808000B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x808000B8: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x808000BC: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x808000C0: bne         $s1, $s5, L_80800090
    if (ctx->r17 != ctx->r21) {
        // 0x808000C4: addiu       $s2, $s2, 0x2C
        ctx->r18 = ADD32(ctx->r18, 0X2C);
            goto L_80800090;
    }
    // 0x808000C4: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    // 0x808000C8: lbu         $t0, 0x15E($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X15E);
    // 0x808000CC: lbu         $t5, 0x15F($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X15F);
    // 0x808000D0: sb          $zero, 0x15C($s3)
    MEM_B(0X15C, ctx->r19) = 0;
    // 0x808000D4: andi        $t1, $t0, 0xFFDF
    ctx->r9 = ctx->r8 & 0XFFDF;
    // 0x808000D8: sb          $t1, 0x15E($s3)
    MEM_B(0X15E, ctx->r19) = ctx->r9;
    // 0x808000DC: lw          $t2, 0x15C($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X15C);
    // 0x808000E0: andi        $t1, $t5, 0xFFFC
    ctx->r9 = ctx->r13 & 0XFFFC;
    // 0x808000E4: sb          $t1, 0x15F($s3)
    MEM_B(0X15F, ctx->r19) = ctx->r9;
    // 0x808000E8: lw          $v0, 0x15C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X15C);
    // 0x808000EC: sll         $t3, $t2, 18
    ctx->r11 = S32(ctx->r10 << 18);
    // 0x808000F0: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x808000F4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x808000F8: sh          $t4, 0x15A($s3)
    MEM_H(0X15A, ctx->r19) = ctx->r12;
    // 0x808000FC: andi        $t0, $t9, 0xC
    ctx->r8 = ctx->r25 & 0XC;
    // 0x80800100: andi        $t2, $t1, 0xF3
    ctx->r10 = ctx->r9 & 0XF3;
    // 0x80800104: or          $t6, $t0, $t2
    ctx->r14 = ctx->r8 | ctx->r10;
    // 0x80800108: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x8080010C: andi        $t5, $t4, 0x30
    ctx->r13 = ctx->r12 & 0X30;
    // 0x80800110: lbu         $t4, 0x15E($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X15E);
    // 0x80800114: andi        $t7, $t6, 0xCF
    ctx->r15 = ctx->r14 & 0XCF;
    // 0x80800118: or          $t0, $t5, $t7
    ctx->r8 = ctx->r13 | ctx->r15;
    // 0x8080011C: andi        $t2, $t0, 0x3F
    ctx->r10 = ctx->r8 & 0X3F;
    // 0x80800120: sb          $t6, 0x15F($s3)
    MEM_B(0X15F, ctx->r19) = ctx->r14;
    // 0x80800124: sll         $t1, $v0, 6
    ctx->r9 = S32(ctx->r2 << 6);
    // 0x80800128: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x8080012C: sb          $t0, 0x15F($s3)
    MEM_B(0X15F, ctx->r19) = ctx->r8;
    // 0x80800130: andi        $t9, $t4, 0xFF7F
    ctx->r25 = ctx->r12 & 0XFF7F;
    // 0x80800134: sb          $t3, 0x15F($s3)
    MEM_B(0X15F, ctx->r19) = ctx->r11;
    // 0x80800138: sb          $t9, 0x15E($s3)
    MEM_B(0X15E, ctx->r19) = ctx->r25;
    // 0x8080013C: lhu         $t5, 0x15E($s3)
    ctx->r13 = MEM_HU(ctx->r19, 0X15E);
    // 0x80800140: lbu         $t1, 0x161($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X161);
    // 0x80800144: sb          $s4, 0x160($s3)
    MEM_B(0X160, ctx->r19) = ctx->r20;
    // 0x80800148: srl         $t7, $t5, 15
    ctx->r15 = S32(U32(ctx->r13) >> 15);
    // 0x8080014C: sb          $t7, 0x15D($s3)
    MEM_B(0X15D, ctx->r19) = ctx->r15;
    // 0x80800150: andi        $t7, $t1, 0xFFF0
    ctx->r15 = ctx->r9 & 0XFFF0;
    // 0x80800154: sb          $t7, 0x161($s3)
    MEM_B(0X161, ctx->r19) = ctx->r15;
    // 0x80800158: lhu         $t4, 0x160($s3)
    ctx->r12 = MEM_HU(ctx->r19, 0X160);
    // 0x8080015C: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x80800160: sb          $t0, 0x15E($s3)
    MEM_B(0X15E, ctx->r19) = ctx->r8;
    // 0x80800164: lbu         $t2, 0x15E($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X15E);
    // 0x80800168: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8080016C: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80800170: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80800174: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80800178: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8080017C: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x80800180: sb          $t9, 0x161($s3)
    MEM_B(0X161, ctx->r19) = ctx->r25;
    // 0x80800184: sh          $s4, 0x162($s3)
    MEM_H(0X162, ctx->r19) = ctx->r20;
    // 0x80800188: sh          $s4, 0x164($s3)
    MEM_H(0X164, ctx->r19) = ctx->r20;
    // 0x8080018C: sw          $zero, 0x168($s3)
    MEM_W(0X168, ctx->r19) = 0;
    // 0x80800190: sw          $zero, 0x170($s3)
    MEM_W(0X170, ctx->r19) = 0;
    // 0x80800194: sw          $zero, 0x174($s3)
    MEM_W(0X174, ctx->r19) = 0;
    // 0x80800198: sw          $zero, 0x178($s3)
    MEM_W(0X178, ctx->r19) = 0;
    // 0x8080019C: sb          $t0, 0x166($s3)
    MEM_B(0X166, ctx->r19) = ctx->r8;
    // 0x808001A0: sb          $zero, 0x159($s3)
    MEM_B(0X159, ctx->r19) = 0;
    // 0x808001A4: sb          $s4, 0x158($s3)
    MEM_B(0X158, ctx->r19) = ctx->r20;
    // 0x808001A8: sb          $t3, 0x15E($s3)
    MEM_B(0X15E, ctx->r19) = ctx->r11;
    // 0x808001AC: sb          $t4, 0x180($s3)
    MEM_B(0X180, ctx->r19) = ctx->r12;
    // 0x808001B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808001B4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808001B8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808001BC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808001C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808001C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808001CC: jr          $ra
    // 0x808001D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808001D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001D4: nop

    // 0x808001D8: nop

    // 0x808001DC: nop

;}
RECOMP_FUNC void func_80025DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025DE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80025DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025DEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80025DF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80025DF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80025DF8: jal         0x80025BF0
    // 0x80025DFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80025BF0(rdram, ctx);
        goto after_0;
    // 0x80025DFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x80025E00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80025E04: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80025E08: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x80025E0C: beq         $t7, $zero, L_80025E58
    if (ctx->r15 == 0) {
        // 0x80025E10: nop
    
            goto L_80025E58;
    }
    // 0x80025E10: nop

    // 0x80025E14: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80025E18: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80025E1C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_80025E20:
    // 0x80025E20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80025E24: jal         0x80025BF0
    // 0x80025E28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80025BF0(rdram, ctx);
        goto after_1;
    // 0x80025E28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80025E2C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80025E30: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80025E34: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80025E38: sll         $t1, $t0, 7
    ctx->r9 = S32(ctx->r8 << 7);
    // 0x80025E3C: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x80025E40: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80025E44: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80025E48: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80025E4C: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x80025E50: bne         $t6, $zero, L_80025E20
    if (ctx->r14 != 0) {
        // 0x80025E54: nop
    
            goto L_80025E20;
    }
    // 0x80025E54: nop

L_80025E58:
    // 0x80025E58: b           L_80025E68
    // 0x80025E5C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_80025E68;
    // 0x80025E5C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80025E60: b           L_80025E68
    // 0x80025E64: nop

        goto L_80025E68;
    // 0x80025E64: nop

L_80025E68:
    // 0x80025E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025E6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80025E70: jr          $ra
    // 0x80025E74: nop

    return;
    // 0x80025E74: nop

    // 0x80025E78: nop

    // 0x80025E7C: nop

;}
RECOMP_FUNC void func_808003B4_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003BC: jal         0x80090A2C
    // 0x808003C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090A2C(rdram, ctx);
        goto after_0;
    // 0x808003C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003C4: jal         0x80082830
    // 0x808003C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808003C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808003CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003D4: jr          $ra
    // 0x808003D8: nop

    return;
    // 0x808003D8: nop

;}
RECOMP_FUNC void chskeletonexplode_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E18: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800E1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800E20: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800E24: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800E28: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800E2C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800E30: lhu         $t8, 0x14($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X14);
    // 0x80800E34: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80800E38: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80800E3C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800E40: addiu       $a0, $a0, 0x6DE8
    ctx->r4 = ADD32(ctx->r4, 0X6DE8);
    // 0x80800E44: lhu         $t0, 0x16($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X16);
    // 0x80800E48: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80800E4C: lh          $a2, 0x0($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X0);
    // 0x80800E50: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80800E54: lh          $a3, 0x2($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X2);
    // 0x80800E58: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80800E5C: lh          $t4, 0x4($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X4);
    // 0x80800E60: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x80800E64: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80800E68: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800E6C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80800E70: jal         0x80086D58
    // 0x80800E74: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800E74: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x80800E78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800E7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800E80: jr          $ra
    // 0x80800E84: nop

    return;
    // 0x80800E84: nop

;}
RECOMP_FUNC void func_800E8078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8078: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E807C: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800E8080: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x800E8084: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E8088: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E808C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800E8090: jr          $ra
    // 0x800E8094: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    return;
    // 0x800E8094: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
;}
RECOMP_FUNC void babounce_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005EC: jal         0x80800504
    // 0x808005F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    babounce_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808005F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005F8: beq         $v0, $at, L_80800614
    if (ctx->r2 == ctx->r1) {
        // 0x808005FC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800614;
    }
    // 0x808005FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800600: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800604: beq         $v0, $at, L_8080062C
    if (ctx->r2 == ctx->r1) {
        // 0x80800608: nop
    
            goto L_8080062C;
    }
    // 0x80800608: nop

    // 0x8080060C: b           L_80800668
    // 0x80800610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800668;
    // 0x80800610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800614:
    // 0x80800614: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80800618: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8080061C: jal         0x8008CF1C
    // 0x80800620: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_1;
    // 0x80800620: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    after_1:
    // 0x80800624: b           L_80800668
    // 0x80800628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800668;
    // 0x80800628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080062C:
    // 0x8080062C: jal         0x8008CAEC
    // 0x80800630: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baanim_isStopped(rdram, ctx);
        goto after_2;
    // 0x80800630: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800634: bne         $v0, $zero, L_8080065C
    if (ctx->r2 != 0) {
        // 0x80800638: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080065C;
    }
    // 0x80800638: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080063C: jal         0x8009EF04
    // 0x80800640: nop

    bastick_distance(rdram, ctx);
        goto after_3;
    // 0x80800640: nop

    after_3:
    // 0x80800644: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800648: nop

    // 0x8080064C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800650: nop

    // 0x80800654: bc1tl       L_80800668
    if (c1cs) {
        // 0x80800658: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800668;
    }
    goto skip_0;
    // 0x80800658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8080065C:
    // 0x8080065C: b           L_80800668
    // 0x80800660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800668;
    // 0x80800660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800668:
    // 0x80800668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080066C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800670: jr          $ra
    // 0x80800674: nop

    return;
    // 0x80800674: nop

;}
RECOMP_FUNC void func_80800050_chbanjocurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800054: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800058: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080005C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800064: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800068: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8080006C: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x80800070: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800074: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800078: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080007C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800080: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800084: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800088: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8080008C: jal         0x800BEB28
    // 0x80800090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEB28(rdram, ctx);
        goto after_0;
    // 0x80800090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800094: bne         $v0, $zero, L_808000A8
    if (ctx->r2 != 0) {
        // 0x80800098: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000A8;
    }
    // 0x80800098: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080009C: jal         0x800BEB28
    // 0x808000A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEB28(rdram, ctx);
        goto after_1;
    // 0x808000A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808000A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_808000A8:
    // 0x808000A8: jal         0x800B2840
    // 0x808000AC: nop

    func_800B2840(rdram, ctx);
        goto after_2;
    // 0x808000AC: nop

    after_2:
    // 0x808000B0: or          $s4, $s7, $zero
    ctx->r20 = ctx->r23 | 0;
    // 0x808000B4: addiu       $s6, $v0, 0x18
    ctx->r22 = ADD32(ctx->r2, 0X18);
    // 0x808000B8: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x808000BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808000C0: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x808000C4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x808000C8: or          $s5, $fp, $zero
    ctx->r21 = ctx->r30 | 0;
    // 0x808000CC: lhu         $t6, 0x0($s3)
    ctx->r14 = MEM_HU(ctx->r19, 0X0);
L_808000D0:
    // 0x808000D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808000D4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x808000D8: addu        $s2, $t7, $s6
    ctx->r18 = ADD32(ctx->r15, ctx->r22);
    // 0x808000DC: jal         0x800EE88C
    // 0x808000E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x808000E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x808000E4: lh          $t8, 0x8($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X8);
    // 0x808000E8: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x808000EC: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x808000F0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808000F4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x808000F8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x808000FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800100: swc1        $f6, -0x8($s1)
    MEM_W(-0X8, ctx->r17) = ctx->f6.u32l;
    // 0x80800104: lh          $t9, 0xA($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XA);
    // 0x80800108: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8080010C: nop

    // 0x80800110: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800114: swc1        $f10, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80800118: sw          $s0, -0x4($s5)
    MEM_W(-0X4, ctx->r21) = ctx->r16;
    // 0x8080011C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800120: bnel        $s0, $s7, L_808000D0
    if (ctx->r16 != ctx->r23) {
        // 0x80800124: lhu         $t6, 0x0($s3)
        ctx->r14 = MEM_HU(ctx->r19, 0X0);
            goto L_808000D0;
    }
    goto skip_0;
    // 0x80800124: lhu         $t6, 0x0($s3)
    ctx->r14 = MEM_HU(ctx->r19, 0X0);
    skip_0:
    // 0x80800128: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8080012C: lw          $t1, 0x4($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X4);
    // 0x80800130: lw          $t4, 0x8($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X8);
    // 0x80800134: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80800138: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8080013C: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x80800140: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80800144: lwc1        $f0, 0x0($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80800148: lwc1        $f2, 0x0($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8080014C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80800150: nop

    // 0x80800154: bc1fl       L_8080018C
    if (!c1cs) {
        // 0x80800158: c.le.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
            goto L_8080018C;
    }
    goto skip_1;
    // 0x80800158: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    skip_1:
    // 0x8080015C: jal         0x80800034
    // 0x80800160: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80800034_chbanjocurrent(rdram, ctx);
        goto after_4;
    // 0x80800160: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_4:
    // 0x80800164: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80800168: lw          $t8, 0x4($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X4);
    // 0x8080016C: lw          $t2, 0x8($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X8);
    // 0x80800170: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80800174: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80800178: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x8080017C: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x80800180: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80800184: lwc1        $f2, 0x0($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80800188: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
L_8080018C:
    // 0x8080018C: nop

    // 0x80800190: bc1fl       L_808001A4
    if (!c1cs) {
        // 0x80800194: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808001A4;
    }
    goto skip_2;
    // 0x80800194: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x80800198: jal         0x80800034
    // 0x8080019C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80800034_chbanjocurrent(rdram, ctx);
        goto after_5;
    // 0x8080019C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_5:
    // 0x808001A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808001A4:
    // 0x808001A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808001AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808001B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808001B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808001B8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808001BC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808001C0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x808001C4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x808001C8: jr          $ra
    // 0x808001CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808001CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gcmapsects_lagoonbot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080010C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800110: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800114: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800118: jal         0x800E39A8
    // 0x8080011C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800E39A8(rdram, ctx);
        goto after_0;
    // 0x8080011C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80800120: jal         0x80013728
    // 0x80800124: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x80800124: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800128: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8080012C: jal         0x800136E4
    // 0x80800130: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80800130: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800134: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80800138: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8080013C: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800140: lbu         $v0, 0x7E($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X7E);
    // 0x80800144: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x80800148: beq         $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x8080014C: nop
    
            goto L_808001BC;
    }
    // 0x8080014C: nop

    // 0x80800150: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800154: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80800158: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080015C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800160: nop

    // 0x80800164: bc1f        L_80800180
    if (!c1cs) {
        // 0x80800168: nop
    
            goto L_80800180;
    }
    // 0x80800168: nop

    // 0x8080016C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800170: nop

    // 0x80800174: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800178: nop

    // 0x8080017C: bc1t        L_808001B4
    if (c1cs) {
        // 0x80800180: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2622, 0X220) << 16);
            goto L_808001B4;
    }
L_80800180:
    // 0x80800180: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2622, 0X220) << 16);
    // 0x80800184: lwc1        $f10, 0x220($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2622, 0X220));
    // 0x80800188: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080018C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800190: nop

    // 0x80800194: bc1f        L_808001BC
    if (!c1cs) {
        // 0x80800198: nop
    
            goto L_808001BC;
    }
    // 0x80800198: nop

    // 0x8080019C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808001A0: nop

    // 0x808001A4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808001A8: nop

    // 0x808001AC: bc1f        L_808001BC
    if (!c1cs) {
        // 0x808001B0: nop
    
            goto L_808001BC;
    }
    // 0x808001B0: nop

L_808001B4:
    // 0x808001B4: sb          $zero, 0x7E($v1)
    MEM_B(0X7E, ctx->r3) = 0;
    // 0x808001B8: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
L_808001BC:
    // 0x808001BC: beq         $v0, $zero, L_8080020C
    if (ctx->r2 == 0) {
        // 0x808001C0: lwc1        $f0, 0x30($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
            goto L_8080020C;
    }
    // 0x808001C0: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808001C4: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x808001C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001CC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808001D0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808001D4: nop

    // 0x808001D8: bc1fl       L_80800210
    if (!c1cs) {
        // 0x808001DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800210;
    }
    goto skip_0;
    // 0x808001DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808001E4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2622, 0X2F4) << 16);
    // 0x808001E8: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2622, 0X2F4));
    // 0x808001EC: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x808001F0: lui         $a1, 0x4475
    ctx->r5 = S32(0X4475 << 16);
    // 0x808001F4: bc1fl       L_80800210
    if (!c1cs) {
        // 0x808001F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800210;
    }
    goto skip_1;
    // 0x808001F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808001FC: jal         0x800E3E8C
    // 0x80800200: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    func_800E3E8C(rdram, ctx);
        goto after_3;
    // 0x80800200: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    after_3:
    // 0x80800204: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800208: sb          $v0, 0x7E($t6)
    MEM_B(0X7E, ctx->r14) = ctx->r2;
L_8080020C:
    // 0x8080020C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800210:
    // 0x80800210: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

    // 0x8080021C: nop

;}
RECOMP_FUNC void _badata_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084678: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084678);
    return;
    // 0x8008467C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80801318_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080131C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801320: jal         0x80801158
    // 0x80801324: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80801158_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801324: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801328: jal         0x800845D0
    // 0x8080132C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _babounce_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080132C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801330: jal         0x80800238
    // 0x80801334: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800238_bsbansack(rdram, ctx);
        goto after_2;
    // 0x80801334: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080133C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801340: jr          $ra
    // 0x80801344: nop

    return;
    // 0x80801344: nop

;}
RECOMP_FUNC void func_80800000_chicekey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800008: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800010: bne         $a1, $at, L_80800080
    if (ctx->r5 != ctx->r1) {
        // 0x80800014: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800080;
    }
    // 0x80800014: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800018: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2452, 0XA0) << 16);
    // 0x8080001C: addiu       $t6, $t6, 0xA0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2452, 0XA0));
    // 0x80800020: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800024: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800028: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8080002C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800030: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800034: jal         0x800BBCB8
    // 0x80800038: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_0:
    // 0x8080003C: jal         0x800D1844
    // 0x80800040: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800D1844(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_1:
    // 0x80800044: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800048: addiu       $t8, $zero, 0x6F
    ctx->r24 = ADD32(0, 0X6F);
    // 0x8080004C: addiu       $a1, $zero, 0x1550
    ctx->r5 = ADD32(0, 0X1550);
    // 0x80800050: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800054: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800058: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080005C: jal         0x8008A208
    // 0x80800060: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800060: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800064: jal         0x800FC660
    // 0x80800068: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_3;
    // 0x80800068: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_3:
    // 0x8080006C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800070: jal         0x800FFA88
    // 0x80800074: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_4;
    // 0x80800074: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_4:
    // 0x80800078: b           L_80800084
    // 0x8080007C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800084;
    // 0x8080007C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800080:
    // 0x80800080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800084:
    // 0x80800084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800088: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void func_80800650_chtoxicroomprops(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800650: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800654: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800658: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080065C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80800660: swc1        $f0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
    // 0x80800664: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    // 0x80800668: jr          $ra
    // 0x8080066C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8080066C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void _gczoombox_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B38: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B38);
    return;
    // 0x80087B3C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80801F2C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801F30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801F34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801F38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801F3C: jal         0x80106790
    // 0x80801F40: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801F40: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80801F44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801F48: jal         0x80100094
    // 0x80801F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801F50: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80801F54: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80801F58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4BF0) << 16);
    // 0x80801F5C: lwc1        $f4, 0x4BF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4BF0));
    // 0x80801F60: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80801F64: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80801F68: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x80801F6C: lbu         $t9, 0xB6($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XB6);
    // 0x80801F70: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80801F74: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1752, 0X4ED4) << 16);
    // 0x80801F78: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80801F7C: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80801F80: lhu         $a1, 0x4ED4($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1752, 0X4ED4));
    // 0x80801F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F88: jal         0x801032B0
    // 0x80801F8C: lhu         $a2, 0x16($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X16);
    func_801032B0(rdram, ctx);
        goto after_2;
    // 0x80801F8C: lhu         $a2, 0x16($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X16);
    after_2:
    // 0x80801F90: jal         0x800C8A98
    // 0x80801F94: nop

    func_800C8A98(rdram, ctx);
        goto after_3;
    // 0x80801F94: nop

    after_3:
    // 0x80801F98: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80801F9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801FA0: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801FA4: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80801FA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801FAC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801FB0: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80801FB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801FB8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801FBC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801FC0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80801FC4: jal         0x800C8E54
    // 0x80801FC8: nop

    func_800C8E54(rdram, ctx);
        goto after_4;
    // 0x80801FC8: nop

    after_4:
    // 0x80801FCC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80801FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801FD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801FD8: jal         0x800C8FB0
    // 0x80801FDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C8FB0(rdram, ctx);
        goto after_5;
    // 0x80801FDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80801FE0: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80801FE4: jal         0x800C8CB8
    // 0x80801FE8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_6;
    // 0x80801FE8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80801FEC: jal         0x80089CA0
    // 0x80801FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80801FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801FF4: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80801FF8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80801FFC: andi        $t2, $v0, 0x1FF
    ctx->r10 = ctx->r2 & 0X1FF;
    // 0x80802000: beql        $t2, $zero, L_80802028
    if (ctx->r10 == 0) {
        // 0x80802004: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80802028;
    }
    goto skip_0;
    // 0x80802004: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_0:
    // 0x80802008: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080200C: beq         $t2, $at, L_80802030
    if (ctx->r10 == ctx->r1) {
        // 0x80802010: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802030;
    }
    // 0x80802010: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802014: beql        $t2, $at, L_80802044
    if (ctx->r10 == ctx->r1) {
        // 0x80802018: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80802044;
    }
    goto skip_1;
    // 0x80802018: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_1:
    // 0x8080201C: b           L_80802054
    // 0x80802020: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80802054;
    // 0x80802020: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80802024: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80802028:
    // 0x80802028: b           L_80802050
    // 0x8080202C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_80802050;
    // 0x8080202C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80802030:
    // 0x80802030: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80802034: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802038: b           L_80802050
    // 0x8080203C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80802050;
    // 0x8080203C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80802040: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_80802044:
    // 0x80802044: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802048: nop

    // 0x8080204C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80802050:
    // 0x80802050: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_80802054:
    // 0x80802054: sb          $zero, 0xC4($v0)
    MEM_B(0XC4, ctx->r2) = 0;
    // 0x80802058: sb          $zero, 0xC6($v0)
    MEM_B(0XC6, ctx->r2) = 0;
    // 0x8080205C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802064: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802068: jr          $ra
    // 0x8080206C: nop

    return;
    // 0x8080206C: nop

;}
RECOMP_FUNC void _chpickups_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085880: syscall     177
    recomp_syscall_handler(rdram, ctx, 0x80085880);
    return;
    // 0x80085884: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8001817C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001817C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80018180: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80018184: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018188: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8001818C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80018190: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80018194: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80018198: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x8001819C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800181A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800181A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800181A8: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x800181AC: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x800181B0: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x800181B4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800181B8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800181BC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800181C0: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x800181C4: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x800181C8: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x800181CC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800181D0: addiu       $s5, $s5, -0x5110
    ctx->r21 = ADD32(ctx->r21, -0X5110);
    // 0x800181D4: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x800181D8: addiu       $s4, $zero, 0x3C
    ctx->r20 = ADD32(0, 0X3C);
    // 0x800181DC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800181E0:
    // 0x800181E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800181E4: jal         0x8002E1F0
    // 0x800181E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800181E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800181EC: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800181F0: lw          $t6, -0x4B20($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B20);
    // 0x800181F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800181F8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800181FC: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80018200: bne         $t8, $zero, L_80018218
    if (ctx->r24 != 0) {
        // 0x80018204: sw          $t7, -0x4B20($at)
        MEM_W(-0X4B20, ctx->r1) = ctx->r15;
            goto L_80018218;
    }
    // 0x80018204: sw          $t7, -0x4B20($at)
    MEM_W(-0X4B20, ctx->r1) = ctx->r15;
    // 0x80018208: sra         $a0, $t7, 4
    ctx->r4 = S32(SIGNED(ctx->r15) >> 4);
    // 0x8001820C: andi        $t9, $a0, 0x3
    ctx->r25 = ctx->r4 & 0X3;
    // 0x80018210: jal         0x80018108
    // 0x80018214: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_80018108(rdram, ctx);
        goto after_1;
    // 0x80018214: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
L_80018218:
    // 0x80018218: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8001821C: addiu       $s0, $s0, -0x4D30
    ctx->r16 = ADD32(ctx->r16, -0X4D30);
    // 0x80018220: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80018224:
    // 0x80018224: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80018228: beql        $t0, $zero, L_8001838C
    if (ctx->r8 == 0) {
        // 0x8001822C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001838C;
    }
    goto skip_0;
    // 0x8001822C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80018230: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80018234: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80018238: bnel        $t1, $zero, L_80018284
    if (ctx->r9 != 0) {
        // 0x8001823C: lwc1        $f12, 0x10($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
            goto L_80018284;
    }
    goto skip_1;
    // 0x8001823C: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    skip_1:
    // 0x80018240: lw          $t2, -0x4B20($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4B20);
    // 0x80018244: div         $zero, $t2, $s4
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r20)));
    // 0x80018248: mfhi        $t3
    ctx->r11 = hi;
    // 0x8001824C: bne         $s4, $zero, L_80018258
    if (ctx->r20 != 0) {
        // 0x80018250: nop
    
            goto L_80018258;
    }
    // 0x80018250: nop

    // 0x80018254: break       7
    do_break(2147582548);
L_80018258:
    // 0x80018258: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001825C: bne         $s4, $at, L_80018270
    if (ctx->r20 != ctx->r1) {
        // 0x80018260: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80018270;
    }
    // 0x80018260: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80018264: bne         $t2, $at, L_80018270
    if (ctx->r10 != ctx->r1) {
        // 0x80018268: nop
    
            goto L_80018270;
    }
    // 0x80018268: nop

    // 0x8001826C: break       6
    do_break(2147582572);
L_80018270:
    // 0x80018270: bnel        $t3, $zero, L_80018284
    if (ctx->r11 != 0) {
        // 0x80018274: lwc1        $f12, 0x10($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
            goto L_80018284;
    }
    goto skip_2;
    // 0x80018274: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    skip_2:
    // 0x80018278: jal         0x80018090
    // 0x8001827C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80018090(rdram, ctx);
        goto after_2;
    // 0x8001827C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80018280: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
L_80018284:
    // 0x80018284: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018288: lw          $s2, 0x8($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X8);
    // 0x8001828C: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x80018290: nop

    // 0x80018294: bc1tl       L_80018348
    if (c1cs) {
        // 0x80018298: sw          $zero, 0x8($s0)
        MEM_W(0X8, ctx->r16) = 0;
            goto L_80018348;
    }
    goto skip_3;
    // 0x80018298: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    skip_3:
    // 0x8001829C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800182A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800182A4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x800182A8: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x800182AC: jal         0x800F10B4
    // 0x800182B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x800182B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x800182B4: sub.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x800182B8: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800182BC: add.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x800182C0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800182C4: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800182C8: nop

    // 0x800182CC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800182D0: beq         $at, $zero, L_80018300
    if (ctx->r1 == 0) {
        // 0x800182D4: nop
    
            goto L_80018300;
    }
    // 0x800182D4: nop

    // 0x800182D8: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x800182DC: bne         $v0, $zero, L_800182F8
    if (ctx->r2 != 0) {
        // 0x800182E0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800182F8;
    }
    // 0x800182E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800182E4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800182E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800182EC: bc1f        L_800182F8
    if (!c1cs) {
        // 0x800182F0: nop
    
            goto L_800182F8;
    }
    // 0x800182F0: nop

    // 0x800182F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800182F8:
    // 0x800182F8: b           L_80018348
    // 0x800182FC: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
        goto L_80018348;
    // 0x800182FC: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
L_80018300:
    // 0x80018300: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80018304: lw          $t5, -0x4B20($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4B20);
    // 0x80018308: div         $zero, $t5, $v1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r3)));
    // 0x8001830C: mfhi        $t6
    ctx->r14 = hi;
    // 0x80018310: sltiu       $t8, $t6, 0x1
    ctx->r24 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80018314: bne         $v1, $zero, L_80018320
    if (ctx->r3 != 0) {
        // 0x80018318: nop
    
            goto L_80018320;
    }
    // 0x80018318: nop

    // 0x8001831C: break       7
    do_break(2147582748);
L_80018320:
    // 0x80018320: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80018324: bne         $v1, $at, L_80018338
    if (ctx->r3 != ctx->r1) {
        // 0x80018328: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80018338;
    }
    // 0x80018328: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001832C: bne         $t5, $at, L_80018338
    if (ctx->r13 != ctx->r1) {
        // 0x80018330: nop
    
            goto L_80018338;
    }
    // 0x80018330: nop

    // 0x80018334: break       6
    do_break(2147582772);
L_80018338:
    // 0x80018338: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8001833C: b           L_8001834C
    // 0x80018340: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
        goto L_8001834C;
    // 0x80018340: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80018344: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
L_80018348:
    // 0x80018348: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
L_8001834C:
    // 0x8001834C: beql        $s2, $t7, L_8001838C
    if (ctx->r18 == ctx->r15) {
        // 0x80018350: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001838C;
    }
    goto skip_4;
    // 0x80018350: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x80018354: jal         0x800A9CAC
    // 0x80018358: nop

    func_800A9CAC(rdram, ctx);
        goto after_4;
    // 0x80018358: nop

    after_4:
    // 0x8001835C: bnel        $v0, $zero, L_8001838C
    if (ctx->r2 != 0) {
        // 0x80018360: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001838C;
    }
    goto skip_5;
    // 0x80018360: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x80018364: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80018368: beq         $t9, $zero, L_80018380
    if (ctx->r25 == 0) {
        // 0x8001836C: nop
    
            goto L_80018380;
    }
    // 0x8001836C: nop

    // 0x80018370: jal         0x80017FC0
    // 0x80018374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80017FC0(rdram, ctx);
        goto after_5;
    // 0x80018374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80018378: b           L_8001838C
    // 0x8001837C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8001838C;
    // 0x8001837C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018380:
    // 0x80018380: jal         0x80018028
    // 0x80018384: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80018028(rdram, ctx);
        goto after_6;
    // 0x80018384: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80018388: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001838C:
    // 0x8001838C: bne         $s1, $s3, L_80018224
    if (ctx->r17 != ctx->r19) {
        // 0x80018390: addiu       $s0, $s0, 0x84
        ctx->r16 = ADD32(ctx->r16, 0X84);
            goto L_80018224;
    }
    // 0x80018390: addiu       $s0, $s0, 0x84
    ctx->r16 = ADD32(ctx->r16, 0X84);
    // 0x80018394: b           L_800181E0
    // 0x80018398: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800181E0;
    // 0x80018398: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001839C: nop

    // 0x800183A0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800183A4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800183A8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800183AC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800183B0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800183B4: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x800183B8: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x800183BC: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x800183C0: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x800183C4: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x800183C8: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x800183CC: jr          $ra
    // 0x800183D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800183D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800230_chsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800234: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800238: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080023C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800240: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800244: bne         $t7, $at, L_8080025C
    if (ctx->r15 != ctx->r1) {
        // 0x80800248: nop
    
            goto L_8080025C;
    }
    // 0x80800248: nop

    // 0x8080024C: lbu         $t8, 0x72($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X72);
    // 0x80800250: andi        $t9, $t8, 0xFF03
    ctx->r25 = ctx->r24 & 0XFF03;
    // 0x80800254: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x80800258: sb          $t0, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r8;
L_8080025C:
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void func_8080135C_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080135C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801360: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80801364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801368: bne         $a1, $at, L_80801380
    if (ctx->r5 != ctx->r1) {
        // 0x8080136C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801380;
    }
    // 0x8080136C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801370: jal         0x808012A4
    // 0x80801374: nop

    func_808012A4_chlagoonufoint(rdram, ctx);
        goto after_0;
    // 0x80801374: nop

    after_0:
    // 0x80801378: b           L_80801388
    // 0x8080137C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801388;
    // 0x8080137C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801380:
    // 0x80801380: b           L_80801388
    // 0x80801384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801388;
    // 0x80801384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801388:
    // 0x80801388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080138C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801390: jr          $ra
    // 0x80801394: nop

    return;
    // 0x80801394: nop

;}
RECOMP_FUNC void _bsclimb_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F08: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082F08);
    return;
    // 0x80082F0C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80802E7C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802E7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802E84: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80802E88: lh          $a0, 0xE8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0XE8);
    // 0x80802E8C: jal         0x808027A8
    // 0x80802E90: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_808027A8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80802E90: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802E94: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80802E98: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80802E9C: lh          $t6, 0xE2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XE2);
    // 0x80802EA0: sh          $t7, 0xE0($a1)
    MEM_H(0XE0, ctx->r5) = ctx->r15;
    // 0x80802EA4: sh          $zero, 0xE2($a1)
    MEM_H(0XE2, ctx->r5) = 0;
    // 0x80802EA8: sh          $zero, 0xE6($a1)
    MEM_H(0XE6, ctx->r5) = 0;
    // 0x80802EAC: sh          $t6, 0xE4($a1)
    MEM_H(0XE4, ctx->r5) = ctx->r14;
    // 0x80802EB0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80802EB4: swc1        $f4, 0xD8($a1)
    MEM_W(0XD8, ctx->r5) = ctx->f4.u32l;
    // 0x80802EB8: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80802EBC: swc1        $f6, 0xDC($a1)
    MEM_W(0XDC, ctx->r5) = ctx->f6.u32l;
    // 0x80802EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802EC4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80802EC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802ECC: jr          $ra
    // 0x80802ED0: nop

    return;
    // 0x80802ED0: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C08: jal         0x80100094
    // 0x80800C0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C10: beql        $v0, $zero, L_80800C28
    if (ctx->r2 == 0) {
        // 0x80800C14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800C28;
    }
    goto skip_0;
    // 0x80800C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800C18: lbu         $t6, 0x19($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X19);
    // 0x80800C1C: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80800C20: sb          $t7, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r15;
    // 0x80800C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C28:
    // 0x80800C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C2C: jr          $ra
    // 0x80800C30: nop

    return;
    // 0x80800C30: nop

;}
RECOMP_FUNC void func_800DD2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD2E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DD2EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DD2F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DD2F4: lw          $t6, 0x1C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1C);
    // 0x800DD2F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DD2FC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800DD300: beq         $t6, $zero, L_800DD36C
    if (ctx->r14 == 0) {
        // 0x800DD304: addiu       $a0, $a0, -0x3090
        ctx->r4 = ADD32(ctx->r4, -0X3090);
            goto L_800DD36C;
    }
    // 0x800DD304: addiu       $a0, $a0, -0x3090
    ctx->r4 = ADD32(ctx->r4, -0X3090);
    // 0x800DD308: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800DD30C: jal         0x800DC580
    // 0x800DD310: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800DC580(rdram, ctx);
        goto after_0;
    // 0x800DD310: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800DD314: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DD318: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DD31C: addiu       $a1, $a1, -0x3168
    ctx->r5 = ADD32(ctx->r5, -0X3168);
    // 0x800DD320: jal         0x800EEB40
    // 0x800DD324: addiu       $a0, $a0, -0x3090
    ctx->r4 = ADD32(ctx->r4, -0X3090);
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x800DD324: addiu       $a0, $a0, -0x3090
    ctx->r4 = ADD32(ctx->r4, -0X3090);
    after_1:
    // 0x800DD328: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD32C: lwc1        $f2, 0xC($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800DD330: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800DD334: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800DD338: nop

    // 0x800DD33C: bc1fl       L_800DD370
    if (!c1cs) {
        // 0x800DD340: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DD370;
    }
    goto skip_0;
    // 0x800DD340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800DD344: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800DD348: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800DD34C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x800DD350: nop

    // 0x800DD354: bc1fl       L_800DD370
    if (!c1cs) {
        // 0x800DD358: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DD370;
    }
    goto skip_1;
    // 0x800DD358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800DD35C: lw          $t7, 0x1C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1C);
    // 0x800DD360: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DD364: jal         0x800DE2A4
    // 0x800DD368: addu        $a1, $a2, $t7
    ctx->r5 = ADD32(ctx->r6, ctx->r15);
    func_800DE2A4(rdram, ctx);
        goto after_2;
    // 0x800DD368: addu        $a1, $a2, $t7
    ctx->r5 = ADD32(ctx->r6, ctx->r15);
    after_2:
L_800DD36C:
    // 0x800DD36C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DD370:
    // 0x800DD370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DD374: jr          $ra
    // 0x800DD378: nop

    return;
    // 0x800DD378: nop

;}
RECOMP_FUNC void func_80800F50_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F50: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800F54: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800F58: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80800F5C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800F60: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800F64: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800F68: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800F6C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800F70: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800F74: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800F78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F7C: jal         0x80100094
    // 0x80800F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F84: jal         0x800B8C50
    // 0x80800F88: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    func_800B8C50(rdram, ctx);
        goto after_1;
    // 0x80800F88: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_1:
    // 0x80800F8C: jal         0x800B7F14
    // 0x80800F90: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800B7F14(rdram, ctx);
        goto after_2;
    // 0x80800F90: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x80800F94: jal         0x800B8CB0
    // 0x80800F98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B8CB0(rdram, ctx);
        goto after_3;
    // 0x80800F98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800F9C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800FA0: lbu         $t6, 0x7611($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7611);
    // 0x80800FA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800FA8: addiu       $s1, $zero, 0x55
    ctx->r17 = ADD32(0, 0X55);
    // 0x80800FAC: bne         $t6, $at, L_80800FD4
    if (ctx->r14 != ctx->r1) {
        // 0x80800FB0: addiu       $s5, $zero, 0x78
        ctx->r21 = ADD32(0, 0X78);
            goto L_80800FD4;
    }
    // 0x80800FB0: addiu       $s5, $zero, 0x78
    ctx->r21 = ADD32(0, 0X78);
    // 0x80800FB4: addiu       $s1, $zero, 0xA0
    ctx->r17 = ADD32(0, 0XA0);
    // 0x80800FB8: addiu       $s5, $zero, 0xAF
    ctx->r21 = ADD32(0, 0XAF);
    // 0x80800FBC: jal         0x800E7188
    // 0x80800FC0: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    func_800E7188(rdram, ctx);
        goto after_4;
    // 0x80800FC0: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    after_4:
    // 0x80800FC4: beq         $v0, $zero, L_80800FD4
    if (ctx->r2 == 0) {
        // 0x80800FC8: nop
    
            goto L_80800FD4;
    }
    // 0x80800FC8: nop

    // 0x80800FCC: b           L_80800FD4
    // 0x80800FD0: addiu       $s1, $zero, 0x91
    ctx->r17 = ADD32(0, 0X91);
        goto L_80800FD4;
    // 0x80800FD0: addiu       $s1, $zero, 0x91
    ctx->r17 = ADD32(0, 0X91);
L_80800FD4:
    // 0x80800FD4: jal         0x800E7188
    // 0x80800FD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800E7188(rdram, ctx);
        goto after_5;
    // 0x80800FD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80800FDC: beq         $v0, $zero, L_80801084
    if (ctx->r2 == 0) {
        // 0x80800FE0: addiu       $s0, $s2, 0x80
        ctx->r16 = ADD32(ctx->r18, 0X80);
            goto L_80801084;
    }
    // 0x80800FE0: addiu       $s0, $s2, 0x80
    ctx->r16 = ADD32(ctx->r18, 0X80);
    // 0x80800FE4: jal         0x800E7188
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E7188(rdram, ctx);
        goto after_6;
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800FEC: beq         $v0, $zero, L_8080106C
    if (ctx->r2 == 0) {
        // 0x80800FF0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080106C;
    }
    // 0x80800FF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800FF4: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x80800FF8: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80800FFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801000: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801004: lw          $a3, 0x6C($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X6C);
    // 0x80801008: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080100C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80801010: andi        $t8, $a3, 0x1FF
    ctx->r24 = ctx->r7 & 0X1FF;
    // 0x80801014: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80801018: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8080101C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80801020: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801024: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801028: jal         0x80800E4C
    // 0x8080102C: nop

    func_80800E4C_chcredits(rdram, ctx);
        goto after_7;
    // 0x8080102C: nop

    after_7:
    // 0x80801030: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80801034: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801038: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080103C: lw          $a3, 0x6C($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X6C);
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801044: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80801048: andi        $t0, $a3, 0x1FF
    ctx->r8 = ctx->r7 & 0X1FF;
    // 0x8080104C: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x80801050: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80801054: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80801058: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080105C: jal         0x80800E4C
    // 0x80801060: nop

    func_80800E4C_chcredits(rdram, ctx);
        goto after_8;
    // 0x80801060: nop

    after_8:
    // 0x80801064: b           L_80801088
    // 0x80801068: addiu       $s1, $s2, 0x100
    ctx->r17 = ADD32(ctx->r18, 0X100);
        goto L_80801088;
    // 0x80801068: addiu       $s1, $s2, 0x100
    ctx->r17 = ADD32(ctx->r18, 0X100);
L_8080106C:
    // 0x8080106C: lw          $a3, 0x6C($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X6C);
    // 0x80801070: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801074: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80801078: andi        $t1, $a3, 0x1FF
    ctx->r9 = ctx->r7 & 0X1FF;
    // 0x8080107C: jal         0x80800E4C
    // 0x80801080: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    func_80800E4C_chcredits(rdram, ctx);
        goto after_9;
    // 0x80801080: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    after_9:
L_80801084:
    // 0x80801084: addiu       $s1, $s2, 0x100
    ctx->r17 = ADD32(ctx->r18, 0X100);
L_80801088:
    // 0x80801088: addiu       $s2, $zero, 0xF
    ctx->r18 = ADD32(0, 0XF);
    // 0x8080108C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801090: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_80801094:
    // 0x80801094: jal         0x800E7188
    // 0x80801098: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E7188(rdram, ctx);
        goto after_10;
    // 0x80801098: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8080109C: beql        $v0, $zero, L_808010D0
    if (ctx->r2 == 0) {
        // 0x808010A0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808010D0;
    }
    goto skip_0;
    // 0x808010A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x808010A4: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808010A8: lw          $a3, 0x6C($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X6C);
    // 0x808010AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010B0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x808010B4: andi        $t3, $a3, 0x1FF
    ctx->r11 = ctx->r7 & 0X1FF;
    // 0x808010B8: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x808010BC: mflo        $t2
    ctx->r10 = lo;
    // 0x808010C0: addu        $a1, $t2, $s5
    ctx->r5 = ADD32(ctx->r10, ctx->r21);
    // 0x808010C4: jal         0x80800E4C
    // 0x808010C8: nop

    func_80800E4C_chcredits(rdram, ctx);
        goto after_11;
    // 0x808010C8: nop

    after_11:
    // 0x808010CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808010D0:
    // 0x808010D0: bne         $s0, $s3, L_80801094
    if (ctx->r16 != ctx->r19) {
        // 0x808010D4: addiu       $s1, $s1, 0x80
        ctx->r17 = ADD32(ctx->r17, 0X80);
            goto L_80801094;
    }
    // 0x808010D4: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x808010D8: jal         0x800B811C
    // 0x808010DC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800B811C(rdram, ctx);
        goto after_12;
    // 0x808010DC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_12:
    // 0x808010E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808010E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808010EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808010F0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808010F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808010F8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808010FC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80801100: jr          $ra
    // 0x80801104: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801104: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800520_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800528: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080052C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800530: jal         0x8008CABC
    // 0x80800534: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800534: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800538: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080053C: jal         0x808001A8
    // 0x80800540: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bsvan_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800540: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800544: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800548: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080054C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800550: lui         $a2, 0x43D2
    ctx->r6 = S32(0X43D2 << 16);
    // 0x80800554: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800558: lui         $a3, 0xC496
    ctx->r7 = S32(0XC496 << 16);
    // 0x8080055C: jal         0x80085210
    // 0x80800560: swc1        $f0, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f0.u32l;
    _basudie_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800560: swc1        $f0, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f0.u32l;
    after_2:
    // 0x80800564: jal         0x8008AF24
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_3;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800570: jal         0x8008B1A0
    // 0x80800574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_4;
    // 0x80800574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: jal         0x8008AED4
    // 0x80800580: addiu       $a1, $zero, 0xD7
    ctx->r5 = ADD32(0, 0XD7);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x80800580: addiu       $a1, $zero, 0xD7
    ctx->r5 = ADD32(0, 0XD7);
    after_5:
    // 0x80800584: lui         $a2, 0x3ECB
    ctx->r6 = S32(0X3ECB << 16);
    // 0x80800588: ori         $a2, $a2, 0xF28
    ctx->r6 = ctx->r6 | 0XF28;
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: jal         0x8008B1D4
    // 0x80800594: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x80800594: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800598: lui         $a1, 0x3FD9
    ctx->r5 = S32(0X3FD9 << 16);
    // 0x8080059C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808005A0: jal         0x8008B1BC
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_7;
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: jal         0x8008B134
    // 0x808005B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x808005B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808005B4: jal         0x8008B064
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808005BC: lui         $a1, 0x3FE6
    ctx->r5 = S32(0X3FE6 << 16);
    // 0x808005C0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808005C4: jal         0x8009D820
    // 0x808005C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009D820(rdram, ctx);
        goto after_10;
    // 0x808005C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x808005CC: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x808005D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808005D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808005DC: jr          $ra
    // 0x808005E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808005E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
