#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _baspin_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085158: syscall     152
    recomp_syscall_handler(rdram, ctx, 0x80085158);
    return;
    // 0x8008515C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void sucoaster_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C3C: jal         0x80100094
    // 0x80800C40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C44: beql        $v0, $zero, L_80800C5C
    if (ctx->r2 == 0) {
        // 0x80800C48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800C5C;
    }
    goto skip_0;
    // 0x80800C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800C4C: lbu         $t7, 0x19($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X19);
    // 0x80800C50: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800C54: sb          $t8, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r24;
    // 0x80800C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C5C:
    // 0x80800C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C60: jr          $ra
    // 0x80800C64: nop

    return;
    // 0x80800C64: nop

;}
RECOMP_FUNC void func_80115D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115D08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80115D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80115D10: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80115D14: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80115D18: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80115D1C: jal         0x80013B7C
    // 0x80115D20: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_80013B7C(rdram, ctx);
        goto after_0;
    // 0x80115D20: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80115D24: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80115D28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80115D2C: nop

    // 0x80115D30: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x80115D34: nop

    // 0x80115D38: bc1fl       L_80115D50
    if (!c1cs) {
        // 0x80115D3C: add.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_80115D50;
    }
    goto skip_0;
    // 0x80115D3C: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    skip_0:
    // 0x80115D40: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80115D44: b           L_80115D54
    // 0x80115D48: add.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_80115D54;
    // 0x80115D48: add.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80115D4C: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
L_80115D50:
    // 0x80115D50: sub.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f2.fl;
L_80115D54:
    // 0x80115D54: jal         0x800136E4
    // 0x80115D58: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80115D58: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x80115D5C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80115D60: jal         0x800136E4
    // 0x80115D64: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80115D64: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80115D68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80115D6C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80115D70: jal         0x801158B0
    // 0x80115D74: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_801158B0(rdram, ctx);
        goto after_3;
    // 0x80115D74: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80115D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80115D7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80115D80: jr          $ra
    // 0x80115D84: nop

    return;
    // 0x80115D84: nop

;}
RECOMP_FUNC void func_800961A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800961A0: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800961A4: jr          $ra
    // 0x800961A8: sb          $a1, 0xA2($t6)
    MEM_B(0XA2, ctx->r14) = ctx->r5;
    return;
    // 0x800961A8: sb          $a1, 0xA2($t6)
    MEM_B(0XA2, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void idbounce_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800068: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8080006C: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x80800070: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800074: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80800078: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8080007C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80800080: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80800084: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80800088: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8080008C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80800090: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80800094: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80800098: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8080009C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808000A0: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x808000A4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808000A8: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x808000AC: addu        $s4, $t6, $a2
    ctx->r20 = ADD32(ctx->r14, ctx->r6);
    // 0x808000B0: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x808000B4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808000B8: sltu        $at, $a2, $s4
    ctx->r1 = ctx->r6 < ctx->r20 ? 1 : 0;
    // 0x808000BC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x808000C0: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x808000C4: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x808000C8: lwc1        $f24, 0x20($s0)
    ctx->f24.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808000CC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808000D0: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x808000D4: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808000D8: lwc1        $f30, 0x60($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808000DC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x808000E0: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x808000E4: beq         $at, $zero, L_808002A0
    if (ctx->r1 == 0) {
        // 0x808000E8: lwc1        $f26, 0x1C($s0)
        ctx->f26.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_808002A0;
    }
    // 0x808000E8: lwc1        $f26, 0x1C($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808000EC: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x808000F0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x808000F4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808000F8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808000FC: addiu       $s2, $s2, 0x5480
    ctx->r18 = ADD32(ctx->r18, 0X5480);
L_80800100:
    // 0x80800100: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x80800104: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80800108: beql        $t7, $zero, L_808001A4
    if (ctx->r15 == 0) {
        // 0x8080010C: lh          $t0, 0x2($s3)
        ctx->r8 = MEM_H(ctx->r19, 0X2);
            goto L_808001A4;
    }
    goto skip_0;
    // 0x8080010C: lh          $t0, 0x2($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X2);
    skip_0:
    // 0x80800110: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x80800114: lh          $t9, 0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4);
    // 0x80800118: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8080011C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80800120: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80800124: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800128: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080012C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800130: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800134: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800138: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8080013C: nop

    // 0x80800140: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800144: jal         0x8002DCA0
    // 0x80800148: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80800148: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x8080014C: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800150: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x80800154: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800158: nop

    // 0x8080015C: bc1fl       L_80800170
    if (!c1cs) {
        // 0x80800160: lwc1        $f4, 0x38($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
            goto L_80800170;
    }
    goto skip_1;
    // 0x80800160: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    skip_1:
    // 0x80800164: b           L_808001A0
    // 0x80800168: sub.s       $f20, $f22, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f24.fl;
        goto L_808001A0;
    // 0x80800168: sub.s       $f20, $f22, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x8080016C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
L_80800170:
    // 0x80800170: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800174: nop

    // 0x80800178: bc1fl       L_808001A4
    if (!c1cs) {
        // 0x8080017C: lh          $t0, 0x2($s3)
        ctx->r8 = MEM_H(ctx->r19, 0X2);
            goto L_808001A4;
    }
    goto skip_2;
    // 0x8080017C: lh          $t0, 0x2($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X2);
    skip_2:
    // 0x80800180: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80800184: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80800188: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080018C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800190: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800194: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80800198: mul.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x8080019C: sub.s       $f20, $f22, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f4.fl;
L_808001A0:
    // 0x808001A0: lh          $t0, 0x2($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X2);
L_808001A4:
    // 0x808001A4: lh          $t1, 0x2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X2);
    // 0x808001A8: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x808001AC: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x808001B0: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x808001B4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x808001B8: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808001BC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808001C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808001C4: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x808001C8: nop

    // 0x808001CC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808001D0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x808001D4: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x808001D8: mul.s       $f8, $f20, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x808001DC: add.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808001E0: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x808001E4: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x808001E8: lh          $t3, 0x2($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X2);
    // 0x808001EC: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x808001F0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x808001F4: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x808001F8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808001FC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80800200: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800204: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80800208: nop

    // 0x8080020C: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
    // 0x80800210: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x80800214: beq         $t7, $zero, L_80800280
    if (ctx->r15 == 0) {
        // 0x80800218: nop
    
            goto L_80800280;
    }
    // 0x80800218: nop

    // 0x8080021C: lbu         $v0, 0x2($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X2);
    // 0x80800220: bnel        $v0, $zero, L_80800284
    if (ctx->r2 != 0) {
        // 0x80800224: lw          $t9, 0x28($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X28);
            goto L_80800284;
    }
    goto skip_3;
    // 0x80800224: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    skip_3:
    // 0x80800228: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8080022C: c.lt.s      $f30, $f18
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f30.fl < ctx->f18.fl;
    // 0x80800230: nop

    // 0x80800234: bc1fl       L_80800284
    if (!c1cs) {
        // 0x80800238: lw          $t9, 0x28($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X28);
            goto L_80800284;
    }
    goto skip_4;
    // 0x80800238: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    skip_4:
    // 0x8080023C: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x80800240: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80800244: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80800248: nop

    // 0x8080024C: bne         $v0, $zero, L_80800280
    if (ctx->r2 != 0) {
        // 0x80800250: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80800280;
    }
    // 0x80800250: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800254: c.lt.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl < ctx->f0.fl;
    // 0x80800258: nop

    // 0x8080025C: bc1f        L_80800268
    if (!c1cs) {
        // 0x80800260: nop
    
            goto L_80800268;
    }
    // 0x80800260: nop

    // 0x80800264: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
L_80800268:
    // 0x80800268: jal         0x800F54E4
    // 0x8080026C: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x8080026C: nop

    after_1:
    // 0x80800270: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800274: jal         0x800F83E4
    // 0x80800278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F83E4(rdram, ctx);
        goto after_2;
    // 0x80800278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080027C: sb          $s5, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r21;
L_80800280:
    // 0x80800280: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
L_80800284:
    // 0x80800284: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80800288: sltu        $at, $s1, $s4
    ctx->r1 = ctx->r17 < ctx->r20 ? 1 : 0;
    // 0x8080028C: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80800290: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x80800294: bne         $at, $zero, L_80800100
    if (ctx->r1 != 0) {
        // 0x80800298: sw          $t0, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r8;
            goto L_80800100;
    }
    // 0x80800298: sw          $t0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r8;
    // 0x8080029C: swc1        $f30, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f30.u32l;
L_808002A0:
    // 0x808002A0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x808002A4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808002A8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808002AC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x808002B0: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x808002B4: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x808002B8: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x808002BC: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x808002C0: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x808002C4: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x808002C8: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x808002CC: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x808002D0: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x808002D4: jr          $ra
    // 0x808002D8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x808002D8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_801158CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801158CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801158D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801158D4: jal         0x80112550
    // 0x801158D8: nop

    func_80112550(rdram, ctx);
        goto after_0;
    // 0x801158D8: nop

    after_0:
    // 0x801158DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801158E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801158E4: jr          $ra
    // 0x801158E8: nop

    return;
    // 0x801158E8: nop

;}
RECOMP_FUNC void func_8010297C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010297C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102980: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80102984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102988: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010298C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80102990: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80102994: jal         0x800DC0C0
    // 0x80102998: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80102998: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8010299C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801029A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801029A4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801029A8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801029AC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801029B0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801029B4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801029B8: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x801029BC: mul.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801029C0: add.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x801029C4: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x801029C8: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x801029CC: bc1fl       L_801029E0
    if (!c1cs) {
        // 0x801029D0: neg.s       $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
            goto L_801029E0;
    }
    goto skip_0;
    // 0x801029D0: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
    skip_0:
    // 0x801029D4: b           L_801029E0
    // 0x801029D8: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_801029E0;
    // 0x801029D8: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x801029DC: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
L_801029E0:
    // 0x801029E0: add.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801029E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801029E8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801029EC: jal         0x80102924
    // 0x801029F0: nop

    func_80102924(rdram, ctx);
        goto after_1;
    // 0x801029F0: nop

    after_1:
    // 0x801029F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801029F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801029FC: jr          $ra
    // 0x80102A00: nop

    return;
    // 0x80102A00: nop

;}
RECOMP_FUNC void func_8080000C_changlerbossbubble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800018: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080001C: jal         0x800EC75C
    // 0x80800020: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EC75C(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800024: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800028: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8080002C: jal         0x800EFD4C
    // 0x80800030: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
    func_800EFD4C(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
    after_1:
    // 0x80800034: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800038: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080003C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800040: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800048: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void func_80800424_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080042C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800430: jr          $ra
    // 0x80800434: nop

    return;
    // 0x80800434: nop

;}
RECOMP_FUNC void _bsclimb_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EE0: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082EE0);
    return;
    // 0x80082EE4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _gczoombox_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B70: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B70);
    return;
    // 0x80087B74: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_80802C40_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C48: jal         0x80802248
    // 0x80802C4C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80802C4C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802C50: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80802C54: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80802C58: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80802C5C: jal         0x800EE7F8
    // 0x80802C60: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80802C60: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80802C64: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80802C68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802C6C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80802C70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802C74: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80802C78: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80802C7C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80802C80: jal         0x80087900
    // 0x80802C84: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    _plcamera_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80802C84: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80802C88: jal         0x800F5EF8
    // 0x80802C8C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F5EF8(rdram, ctx);
        goto after_3;
    // 0x80802C8C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80802C90: jal         0x80110014
    // 0x80802C94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_4;
    // 0x80802C94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80802C98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802C9C: jal         0x80116088
    // 0x80802CA0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80116088(rdram, ctx);
        goto after_5;
    // 0x80802CA0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80802CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802CA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802CAC: jr          $ra
    // 0x80802CB0: nop

    return;
    // 0x80802CB0: nop

;}
RECOMP_FUNC void _gcextra_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883F8: syscall     681
    recomp_syscall_handler(rdram, ctx, 0x800883F8);
    return;
    // 0x800883FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _badrone_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084818: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084818);
    return;
    // 0x8008481C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chklungodoors_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1252, 0X508) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x508
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1252, 0X508));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x508
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1252, 0X508));
;}
RECOMP_FUNC void bsthrow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080000C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800010: jal         0x8008CABC
    // 0x80800014: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800018: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080001C: jal         0x8008AF24
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800028: jal         0x8008AED4
    // 0x8080002C: addiu       $a1, $zero, 0x11B
    ctx->r5 = ADD32(0, 0X11B);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x8080002C: addiu       $a1, $zero, 0x11B
    ctx->r5 = ADD32(0, 0X11B);
    after_2:
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: jal         0x8008B1BC
    // 0x80800038: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x80800038: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x8008B134
    // 0x80800044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x80800044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800048: jal         0x8008B064
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_5;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800050: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800054: jal         0x8008CA4C
    // 0x80800058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_6;
    // 0x80800058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080005C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800060: jal         0x8009C908
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_7;
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080006C: jal         0x8009D2D8
    // 0x80800070: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_8;
    // 0x80800070: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800074: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800078: jal         0x8009B800
    // 0x8080007C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baphysics_set_type(rdram, ctx);
        goto after_9;
    // 0x8080007C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800080: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800084: jal         0x8009B9B0
    // 0x80800088: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x80800088: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x8080008C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800090: jal         0x8009BA9C
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_11;
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800098: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: jr          $ra
    // 0x808000AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void sumultiscore_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F68: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800F6C: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x80800F70: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80800F74: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80800F78: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80800F7C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800F80: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80800F84: sll         $t9, $v0, 5
    ctx->r25 = S32(ctx->r2 << 5);
    // 0x80800F88: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800F8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800F90: jr          $ra
    // 0x80800F94: sb          $t6, 0x47($t0)
    MEM_B(0X47, ctx->r8) = ctx->r14;
    return;
    // 0x80800F94: sb          $t6, 0x47($t0)
    MEM_B(0X47, ctx->r8) = ctx->r14;
;}
RECOMP_FUNC void _baeggcursor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AB8: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084AB8);
    return;
    // 0x80084ABC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A02DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A02DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A02E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A02E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A02E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A02EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A02F0: jal         0x800A3274
    // 0x800A02F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x800A02F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x800A02F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A02FC: jal         0x8008E078
    // 0x800A0300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_1;
    // 0x800A0300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A0304: bne         $v0, $zero, L_800A0314
    if (ctx->r2 != 0) {
        // 0x800A0308: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A0314;
    }
    // 0x800A0308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A030C: b           L_800A0418
    // 0x800A0310: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_800A0418;
    // 0x800A0310: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_800A0314:
    // 0x800A0314: jal         0x80095738
    // 0x800A0318: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x800A0318: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_2:
    // 0x800A031C: beql        $v0, $zero, L_800A0334
    if (ctx->r2 == 0) {
        // 0x800A0320: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A0334;
    }
    goto skip_0;
    // 0x800A0320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800A0324: jal         0x800848C8
    // 0x800A0328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_28(rdram, ctx);
        goto after_3;
    // 0x800A0328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800A032C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800A0330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A0334:
    // 0x800A0334: jal         0x80095738
    // 0x800A0338: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    baflag_isTrue(rdram, ctx);
        goto after_4;
    // 0x800A0338: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_4:
    // 0x800A033C: beq         $v0, $zero, L_800A0348
    if (ctx->r2 == 0) {
        // 0x800A0340: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A0348;
    }
    // 0x800A0340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0344: addiu       $s1, $zero, 0x34
    ctx->r17 = ADD32(0, 0X34);
L_800A0348:
    // 0x800A0348: jal         0x80095738
    // 0x800A034C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    baflag_isTrue(rdram, ctx);
        goto after_5;
    // 0x800A034C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_5:
    // 0x800A0350: beq         $v0, $zero, L_800A0374
    if (ctx->r2 == 0) {
        // 0x800A0354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A0374;
    }
    // 0x800A0354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0358: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800A035C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800A0360: addiu       $s1, $zero, 0x25
    ctx->r17 = ADD32(0, 0X25);
    // 0x800A0364: bne         $t6, $at, L_800A0374
    if (ctx->r14 != ctx->r1) {
        // 0x800A0368: nop
    
            goto L_800A0374;
    }
    // 0x800A0368: nop

    // 0x800A036C: b           L_800A0374
    // 0x800A0370: addiu       $s1, $zero, 0x47
    ctx->r17 = ADD32(0, 0X47);
        goto L_800A0374;
    // 0x800A0370: addiu       $s1, $zero, 0x47
    ctx->r17 = ADD32(0, 0X47);
L_800A0374:
    // 0x800A0374: jal         0x80095738
    // 0x800A0378: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    baflag_isTrue(rdram, ctx);
        goto after_6;
    // 0x800A0378: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_6:
    // 0x800A037C: bne         $v0, $zero, L_800A03A4
    if (ctx->r2 != 0) {
        // 0x800A0380: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A03A4;
    }
    // 0x800A0380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0384: jal         0x80095738
    // 0x800A0388: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    baflag_isTrue(rdram, ctx);
        goto after_7;
    // 0x800A0388: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_7:
    // 0x800A038C: bne         $v0, $zero, L_800A03A4
    if (ctx->r2 != 0) {
        // 0x800A0390: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A03A4;
    }
    // 0x800A0390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0394: jal         0x80095738
    // 0x800A0398: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    baflag_isTrue(rdram, ctx);
        goto after_8;
    // 0x800A0398: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_8:
    // 0x800A039C: beql        $v0, $zero, L_800A03D0
    if (ctx->r2 == 0) {
        // 0x800A03A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A03D0;
    }
    goto skip_1;
    // 0x800A03A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_800A03A4:
    // 0x800A03A4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800A03A8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800A03AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A03B0: beql        $t7, $at, L_800A03D0
    if (ctx->r15 == ctx->r1) {
        // 0x800A03B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A03D0;
    }
    goto skip_2;
    // 0x800A03B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x800A03B8: jal         0x8009E674
    // 0x800A03BC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_8009E674(rdram, ctx);
        goto after_9;
    // 0x800A03BC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_9:
    // 0x800A03C0: bnel        $v0, $zero, L_800A03D0
    if (ctx->r2 != 0) {
        // 0x800A03C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A03D0;
    }
    goto skip_3;
    // 0x800A03C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x800A03C8: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // 0x800A03CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A03D0:
    // 0x800A03D0: jal         0x80095738
    // 0x800A03D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baflag_isTrue(rdram, ctx);
        goto after_10;
    // 0x800A03D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x800A03D8: beq         $v0, $zero, L_800A03E4
    if (ctx->r2 == 0) {
        // 0x800A03DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A03E4;
    }
    // 0x800A03DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A03E0: addiu       $s1, $zero, 0x53
    ctx->r17 = ADD32(0, 0X53);
L_800A03E4:
    // 0x800A03E4: jal         0x80095738
    // 0x800A03E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baflag_isTrue(rdram, ctx);
        goto after_11;
    // 0x800A03E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_11:
    // 0x800A03EC: beq         $v0, $zero, L_800A03F8
    if (ctx->r2 == 0) {
        // 0x800A03F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A03F8;
    }
    // 0x800A03F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A03F4: addiu       $s1, $zero, 0x44
    ctx->r17 = ADD32(0, 0X44);
L_800A03F8:
    // 0x800A03F8: jal         0x80095738
    // 0x800A03FC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    baflag_isTrue(rdram, ctx);
        goto after_12;
    // 0x800A03FC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_12:
    // 0x800A0400: beq         $v0, $zero, L_800A040C
    if (ctx->r2 == 0) {
        // 0x800A0404: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A040C;
    }
    // 0x800A0404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0408: addiu       $s1, $zero, 0x53
    ctx->r17 = ADD32(0, 0X53);
L_800A040C:
    // 0x800A040C: jal         0x80095774
    // 0x800A0410: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_clear(rdram, ctx);
        goto after_13;
    // 0x800A0410: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_13:
    // 0x800A0414: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_800A0418:
    // 0x800A0418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A041C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A0420: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A0424: jr          $ra
    // 0x800A0428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A0428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800218C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800218C4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800218C8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800218CC: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x800218D0: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800218D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800218D8: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800218DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800218E0: lwc1        $f18, 0x1980($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1980);
    // 0x800218E4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800218E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800218EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800218F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800218F4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800218F8: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800218FC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80021900: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x80021904: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80021908: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8002190C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80021910: b           L_80021920
    // 0x80021914: nop

        goto L_80021920;
    // 0x80021914: nop

    // 0x80021918: b           L_80021920
    // 0x8002191C: nop

        goto L_80021920;
    // 0x8002191C: nop

L_80021920:
    // 0x80021920: jr          $ra
    // 0x80021924: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80021924: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80800944_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800944: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080094C: jal         0x80800000
    // 0x80800950: nop

    func_80800000_bskazglide(rdram, ctx);
        goto after_0;
    // 0x80800950: nop

    after_0:
    // 0x80800954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080095C: jr          $ra
    // 0x80800960: nop

    return;
    // 0x80800960: nop

;}
RECOMP_FUNC void func_800A3B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3B70: jr          $ra
    // 0x800A3B74: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    return;
    // 0x800A3B74: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80801964_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801964: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801968: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080196C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801970: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801974: jal         0x80100094
    // 0x80801978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080197C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801980: lbu         $t6, 0x75($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X75);
    // 0x80801984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801988: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x8080198C: jal         0x8010A590
    // 0x80801990: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x80801990: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
    after_1:
    // 0x80801994: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801998: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080199C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808019A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808019A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808019A8: jal         0x800DC178
    // 0x808019AC: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x808019AC: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x808019B0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808019B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808019B8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808019BC: jal         0x800DC178
    // 0x808019C0: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808019C0: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x808019C4: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x808019C8: jal         0x80801920
    // 0x808019CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801920_chcollballcontrol(rdram, ctx);
        goto after_4;
    // 0x808019CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808019D0: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x808019D4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808019D8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808019DC: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x808019E0: bgezl       $t0, L_80801A00
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808019E4: lui         $at, 0xC296
        ctx->r1 = S32(0XC296 << 16);
            goto L_80801A00;
    }
    goto skip_0;
    // 0x808019E4: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    skip_0:
    // 0x808019E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808019EC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808019F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808019F4: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x808019F8: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x808019FC: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
L_80801A00:
    // 0x80801A00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801A04: sb          $zero, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = 0;
    // 0x80801A08: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80801A0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801A14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801A18: jr          $ra
    // 0x80801A1C: nop

    return;
    // 0x80801A1C: nop

;}
RECOMP_FUNC void func_80800000_chplatuegrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x80103EF4
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80103EF4(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2460, 0X1C0) << 16);
    // 0x80800018: lwc1        $f4, 0x1C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2460, 0X1C0));
    // 0x8080001C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800020: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800024: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800028: addiu       $t7, $zero, 0x3EA
    ctx->r15 = ADD32(0, 0X3EA);
    // 0x8080002C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800030: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x8080003C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800040: jal         0x80086898
    // 0x80800044: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800044: nop

    after_1:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x800868A8
    // 0x80800050: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800050: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_2:
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: jal         0x800868B0
    // 0x8080005C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x8080005C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_3:
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: jal         0x800868C0
    // 0x80800068: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800068: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800074: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80800078: jal         0x800868C8
    // 0x8080007C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x8080007C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_5:
    // 0x80800080: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800084: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800088: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void glhittableDll_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800400: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800404: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80800408: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8080040C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800410: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2742, 0X530) << 16);
    // 0x80800414: addiu       $t9, $t9, 0x530
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2742, 0X530));
    // 0x80800418: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080041C: andi        $t0, $a0, 0xFFFF
    ctx->r8 = ctx->r4 & 0XFFFF;
    // 0x80800420: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80800424: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80800428: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x8080042C: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x80800430: lhu         $t5, 0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X2);
    // 0x80800434: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x80800438: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x8080043C: jr          $ra
    // 0x80800440: or          $v0, $t4, $t6
    ctx->r2 = ctx->r12 | ctx->r14;
    return;
    // 0x80800440: or          $v0, $t4, $t6
    ctx->r2 = ctx->r12 | ctx->r14;
;}
RECOMP_FUNC void fxkern_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080030C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800314: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800318: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080031C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800320: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800324: jal         0x80800084
    // 0x80800328: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800084_fxkern(rdram, ctx);
        goto after_0;
    // 0x80800328: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x8080032C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800330: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800334: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800338: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080033C: jal         0x80800224
    // 0x80800340: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80800224_fxkern(rdram, ctx);
        goto after_1;
    // 0x80800340: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800348: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080034C: jr          $ra
    // 0x80800350: nop

    return;
    // 0x80800350: nop

;}
RECOMP_FUNC void func_8080153C_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080153C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801544: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801548: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080154C: jal         0x800BF744
    // 0x80801550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_0;
    // 0x80801550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801554: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80801558: jal         0x800BF744
    // 0x8080155C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_1;
    // 0x8080155C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801560: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801568: jal         0x800BF544
    // 0x8080156C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BF544(rdram, ctx);
        goto after_2;
    // 0x8080156C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80801570: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801574: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080157C: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x80801580: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80801584: bnel        $t8, $at, L_80801598
    if (ctx->r24 != ctx->r1) {
        // 0x80801588: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801598;
    }
    goto skip_0;
    // 0x80801588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080158C: jal         0x8008A090
    // 0x80801590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiemulti_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80801590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801598:
    // 0x80801598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080159C: jr          $ra
    // 0x808015A0: nop

    return;
    // 0x808015A0: nop

;}
RECOMP_FUNC void _chflamer_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860D0: syscall     277
    recomp_syscall_handler(rdram, ctx, 0x800860D0);
    return;
    // 0x800860D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800AE630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE630: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AE634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AE638: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AE63C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AE640: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x800AE644: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800AE648: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800AE64C: addiu       $s0, $a1, 0x8
    ctx->r16 = ADD32(ctx->r5, 0X8);
    // 0x800AE650: beq         $t0, $t7, L_800AE660
    if (ctx->r8 == ctx->r15) {
        // 0x800AE654: addiu       $a0, $t8, 0x50
        ctx->r4 = ADD32(ctx->r24, 0X50);
            goto L_800AE660;
    }
    // 0x800AE654: addiu       $a0, $t8, 0x50
    ctx->r4 = ADD32(ctx->r24, 0X50);
    // 0x800AE658: b           L_800AE6A8
    // 0x800AE65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE6A8;
    // 0x800AE65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AE660:
    // 0x800AE660: sll         $t9, $t0, 6
    ctx->r25 = S32(ctx->r8 << 6);
    // 0x800AE664: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800AE668: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x800AE66C: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800AE670: beq         $at, $zero, L_800AE6A4
    if (ctx->r1 == 0) {
        // 0x800AE674: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_800AE6A4;
    }
    // 0x800AE674: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_800AE678:
    // 0x800AE678: lh          $t1, 0xC($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XC);
    // 0x800AE67C: bnel        $a2, $t1, L_800AE698
    if (ctx->r6 != ctx->r9) {
        // 0x800AE680: addiu       $a0, $a0, 0x40
        ctx->r4 = ADD32(ctx->r4, 0X40);
            goto L_800AE698;
    }
    goto skip_0;
    // 0x800AE680: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    skip_0:
    // 0x800AE684: jal         0x800F23D0
    // 0x800AE688: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F23D0(rdram, ctx);
        goto after_0;
    // 0x800AE688: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x800AE68C: b           L_800AE6A8
    // 0x800AE690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800AE6A8;
    // 0x800AE690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AE694: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
L_800AE698:
    // 0x800AE698: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800AE69C: bne         $at, $zero, L_800AE678
    if (ctx->r1 != 0) {
        // 0x800AE6A0: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800AE678;
    }
    // 0x800AE6A0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_800AE6A4:
    // 0x800AE6A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AE6A8:
    // 0x800AE6A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE6AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AE6B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE6B4: jr          $ra
    // 0x800AE6B8: nop

    return;
    // 0x800AE6B8: nop

;}
RECOMP_FUNC void func_80800008_baeggfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080000C: bnel        $a1, $at, L_8080002C
    if (ctx->r5 != ctx->r1) {
        // 0x80800010: lw          $v0, 0x6C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X6C);
            goto L_8080002C;
    }
    goto skip_0;
    // 0x80800010: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    skip_0:
    // 0x80800014: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800018: lbu         $t6, 0x12($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12);
    // 0x8080001C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800020: jr          $ra
    // 0x80800024: sb          $t7, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r15;
    return;
    // 0x80800024: sb          $t7, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r15;
    // 0x80800028: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
L_8080002C:
    // 0x8080002C: lbu         $t8, 0x11($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X11);
    // 0x80800030: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80800034: sb          $t9, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r25;
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_80802A48_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802A4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802A50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802A54: jal         0x8010CD28
    // 0x80802A58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8010CD28(rdram, ctx);
        goto after_0;
    // 0x80802A58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802A5C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80802A60: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802A64: jal         0x800F1DCC
    // 0x80802A68: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80802A68: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_1:
    // 0x80802A6C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80802A70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802A74: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80802A78: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80802A7C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80802A80: nop

    // 0x80802A84: bc1t        L_80802AA4
    if (c1cs) {
        // 0x80802A88: nop
    
            goto L_80802AA4;
    }
    // 0x80802A88: nop

    // 0x80802A8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802A90: nop

    // 0x80802A94: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80802A98: nop

    // 0x80802A9C: bc1fl       L_80802BBC
    if (!c1cs) {
        // 0x80802AA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802BBC;
    }
    goto skip_0;
    // 0x80802AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80802AA4:
    // 0x80802AA4: jal         0x80101F24
    // 0x80802AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_2;
    // 0x80802AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802AB0: jal         0x801022E4
    // 0x80802AB4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_801022E4(rdram, ctx);
        goto after_3;
    // 0x80802AB4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80802AB8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80802ABC: beq         $v0, $at, L_80802AD8
    if (ctx->r2 == ctx->r1) {
        // 0x80802AC0: lwc1        $f2, 0x20($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80802AD8;
    }
    // 0x80802AC0: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80802AC4: addiu       $at, $zero, 0x85
    ctx->r1 = ADD32(0, 0X85);
    // 0x80802AC8: beq         $v0, $at, L_80802B1C
    if (ctx->r2 == ctx->r1) {
        // 0x80802ACC: nop
    
            goto L_80802B1C;
    }
    // 0x80802ACC: nop

    // 0x80802AD0: b           L_80802BBC
    // 0x80802AD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802BBC;
    // 0x80802AD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802AD8:
    // 0x80802AD8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80802ADC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802AE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X382C) << 16);
    // 0x80802AE4: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80802AE8: nop

    // 0x80802AEC: bc1fl       L_80802BBC
    if (!c1cs) {
        // 0x80802AF0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802BBC;
    }
    goto skip_1;
    // 0x80802AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80802AF4: lwc1        $f10, 0x382C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X382C));
    // 0x80802AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802AFC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80802B00: nop

    // 0x80802B04: bc1fl       L_80802BBC
    if (!c1cs) {
        // 0x80802B08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802BBC;
    }
    goto skip_2;
    // 0x80802B08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80802B0C: jal         0x80102B2C
    // 0x80802B10: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    func_80102B2C(rdram, ctx);
        goto after_4;
    // 0x80802B10: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_4:
    // 0x80802B14: b           L_80802BBC
    // 0x80802B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802BBC;
    // 0x80802B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802B1C:
    // 0x80802B1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3830) << 16);
    // 0x80802B20: lwc1        $f16, 0x3830($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3830));
    // 0x80802B24: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3834) << 16);
    // 0x80802B28: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80802B2C: nop

    // 0x80802B30: bc1fl       L_80802B4C
    if (!c1cs) {
        // 0x80802B34: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80802B4C;
    }
    goto skip_3;
    // 0x80802B34: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    skip_3:
    // 0x80802B38: lwc1        $f18, 0x3834($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3834));
    // 0x80802B3C: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80802B40: nop

    // 0x80802B44: bc1t        L_80802B78
    if (c1cs) {
        // 0x80802B48: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80802B78;
    }
    // 0x80802B48: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80802B4C:
    // 0x80802B4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802B50: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3838) << 16);
    // 0x80802B54: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80802B58: nop

    // 0x80802B5C: bc1fl       L_80802BBC
    if (!c1cs) {
        // 0x80802B60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802BBC;
    }
    goto skip_4;
    // 0x80802B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80802B64: lwc1        $f6, 0x3838($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3838));
    // 0x80802B68: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80802B6C: nop

    // 0x80802B70: bc1fl       L_80802BBC
    if (!c1cs) {
        // 0x80802B74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802BBC;
    }
    goto skip_5;
    // 0x80802B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
L_80802B78:
    // 0x80802B78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80802B7C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80802B80: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80802B84: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80802B88: nop

    // 0x80802B8C: bc1fl       L_80802BA8
    if (!c1cs) {
        // 0x80802B90: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80802BA8;
    }
    goto skip_6;
    // 0x80802B90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_6:
    // 0x80802B94: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80802B98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80802B9C: b           L_80802BB0
    // 0x80802BA0: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
        goto L_80802BB0;
    // 0x80802BA0: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802BA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80802BA8:
    // 0x80802BA8: nop

    // 0x80802BAC: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
L_80802BB0:
    // 0x80802BB0: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80802BB4: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x80802BB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802BBC:
    // 0x80802BBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802BC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802BC4: jr          $ra
    // 0x80802BC8: nop

    return;
    // 0x80802BC8: nop

;}
RECOMP_FUNC void func_808008C8_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808008CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008D8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808008DC: lui         $a1, 0x4370
    ctx->r5 = S32(0X4370 << 16);
    // 0x808008E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808008E4: jal         0x8008FB10
    // 0x808008E8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    func_8008FB10(rdram, ctx);
        goto after_0;
    // 0x808008E8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_0:
    // 0x808008EC: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x808008F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008F4: srl         $t6, $a1, 10
    ctx->r14 = S32(U32(ctx->r5) >> 10);
    // 0x808008F8: beq         $t6, $at, L_80800918
    if (ctx->r14 == ctx->r1) {
        // 0x808008FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800918;
    }
    // 0x808008FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800900: beq         $t6, $at, L_80800920
    if (ctx->r14 == ctx->r1) {
        // 0x80800904: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800920;
    }
    // 0x80800904: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800908: beql        $t6, $at, L_80800A00
    if (ctx->r14 == ctx->r1) {
        // 0x8080090C: lw          $t2, 0x6C($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X6C);
            goto L_80800A00;
    }
    goto skip_0;
    // 0x8080090C: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x80800910: b           L_80800CC4
    // 0x80800914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800CC4;
    // 0x80800914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800918:
    // 0x80800918: jal         0x80800744
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800744_chlagoonufoint(rdram, ctx);
        goto after_1;
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80800920:
    // 0x80800920: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80800924: addiu       $at, $zero, 0x1C6
    ctx->r1 = ADD32(0, 0X1C6);
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080092C: sll         $t7, $a1, 11
    ctx->r15 = S32(ctx->r5 << 11);
    // 0x80800930: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800934: beq         $t8, $at, L_80800950
    if (ctx->r24 == ctx->r1) {
        // 0x80800938: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(748, 0X1B1C) << 16);
            goto L_80800950;
    }
    // 0x80800938: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(748, 0X1B1C) << 16);
    // 0x8080093C: addiu       $at, $zero, 0x1C7
    ctx->r1 = ADD32(0, 0X1C7);
    // 0x80800940: beq         $t8, $at, L_80800970
    if (ctx->r24 == ctx->r1) {
        // 0x80800944: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800970;
    }
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800948: b           L_80800994
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800994;
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800950:
    // 0x80800950: jal         0x80101E4C
    // 0x80800954: addiu       $a1, $a1, 0x1B1C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X1B1C));
    func_80101E4C(rdram, ctx);
        goto after_2;
    // 0x80800954: addiu       $a1, $a1, 0x1B1C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X1B1C));
    after_2:
    // 0x80800958: beq         $v0, $zero, L_808009B0
    if (ctx->r2 == 0) {
        // 0x8080095C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009B0;
    }
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800960: jal         0x80800878
    // 0x80800964: addiu       $a1, $zero, 0x5C1
    ctx->r5 = ADD32(0, 0X5C1);
    func_80800878_chlagoonufoint(rdram, ctx);
        goto after_3;
    // 0x80800964: addiu       $a1, $zero, 0x5C1
    ctx->r5 = ADD32(0, 0X5C1);
    after_3:
    // 0x80800968: b           L_808009B0
    // 0x8080096C: nop

        goto L_808009B0;
    // 0x8080096C: nop

L_80800970:
    // 0x80800970: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(748, 0X1B2C) << 16);
    // 0x80800974: jal         0x80101E4C
    // 0x80800978: addiu       $a1, $a1, 0x1B2C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X1B2C));
    func_80101E4C(rdram, ctx);
        goto after_4;
    // 0x80800978: addiu       $a1, $a1, 0x1B2C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X1B2C));
    after_4:
    // 0x8080097C: beq         $v0, $zero, L_808009B0
    if (ctx->r2 == 0) {
        // 0x80800980: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009B0;
    }
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800984: jal         0x80800878
    // 0x80800988: addiu       $a1, $zero, 0x5BF
    ctx->r5 = ADD32(0, 0X5BF);
    func_80800878_chlagoonufoint(rdram, ctx);
        goto after_5;
    // 0x80800988: addiu       $a1, $zero, 0x5BF
    ctx->r5 = ADD32(0, 0X5BF);
    after_5:
    // 0x8080098C: b           L_808009B0
    // 0x80800990: nop

        goto L_808009B0;
    // 0x80800990: nop

L_80800994:
    // 0x80800994: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(748, 0X1B38) << 16);
    // 0x80800998: jal         0x80101E4C
    // 0x8080099C: addiu       $a1, $a1, 0x1B38
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X1B38));
    func_80101E4C(rdram, ctx);
        goto after_6;
    // 0x8080099C: addiu       $a1, $a1, 0x1B38
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X1B38));
    after_6:
    // 0x808009A0: beq         $v0, $zero, L_808009B0
    if (ctx->r2 == 0) {
        // 0x808009A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009B0;
    }
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A8: jal         0x80800878
    // 0x808009AC: addiu       $a1, $zero, 0x5C0
    ctx->r5 = ADD32(0, 0X5C0);
    func_80800878_chlagoonufoint(rdram, ctx);
        goto after_7;
    // 0x808009AC: addiu       $a1, $zero, 0x5C0
    ctx->r5 = ADD32(0, 0X5C0);
    after_7:
L_808009B0:
    // 0x808009B0: jal         0x800DA298
    // 0x808009B4: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x808009B4: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    after_8:
    // 0x808009B8: beq         $v0, $zero, L_80800CC0
    if (ctx->r2 == 0) {
        // 0x808009BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CC0;
    }
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C0: jal         0x80102424
    // 0x808009C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x808009C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x808009C8: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x808009CC: addiu       $at, $zero, 0x1C7
    ctx->r1 = ADD32(0, 0X1C7);
    // 0x808009D0: sll         $t0, $t9, 11
    ctx->r8 = S32(ctx->r25 << 11);
    // 0x808009D4: srl         $t1, $t0, 20
    ctx->r9 = S32(U32(ctx->r8) >> 20);
    // 0x808009D8: bnel        $t1, $at, L_80800CC4
    if (ctx->r9 != ctx->r1) {
        // 0x808009DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CC4;
    }
    goto skip_1;
    // 0x808009DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808009E0: jal         0x800DC0C0
    // 0x808009E4: nop

    func_800DC0C0(rdram, ctx);
        goto after_10;
    // 0x808009E4: nop

    after_10:
    // 0x808009E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808009EC: jal         0x80101EE4
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101EE4(rdram, ctx);
        goto after_11;
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808009F4: b           L_80800CC4
    // 0x808009F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800CC4;
    // 0x808009F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009FC: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
L_80800A00:
    // 0x80800A00: addiu       $at, $zero, 0x1C7
    ctx->r1 = ADD32(0, 0X1C7);
    // 0x80800A04: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x80800A08: srl         $t4, $t3, 20
    ctx->r12 = S32(U32(ctx->r11) >> 20);
    // 0x80800A0C: bne         $t4, $at, L_80800CB8
    if (ctx->r12 != ctx->r1) {
        // 0x80800A10: nop
    
            goto L_80800CB8;
    }
    // 0x80800A10: nop

    // 0x80800A14: jal         0x80101F24
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_12;
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800A1C: lbu         $t5, 0x79($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X79);
    // 0x80800A20: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800A24: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X18EC) << 16);
    // 0x80800A28: andi        $t6, $t5, 0xFF0F
    ctx->r14 = ctx->r13 & 0XFF0F;
    // 0x80800A2C: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800A30: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
    // 0x80800A34: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
    // 0x80800A38: lwc1        $f4, 0x18EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X18EC));
    // 0x80800A3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X18F0) << 16);
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800A48: nop

    // 0x80800A4C: bc1f        L_80800A78
    if (!c1cs) {
        // 0x80800A50: nop
    
            goto L_80800A78;
    }
    // 0x80800A50: nop

    // 0x80800A54: lwc1        $f6, 0x18F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X18F0));
    // 0x80800A58: andi        $t0, $t6, 0xF
    ctx->r8 = ctx->r14 & 0XF;
    // 0x80800A5C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80800A60: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800A64: nop

    // 0x80800A68: bc1f        L_80800A78
    if (!c1cs) {
        // 0x80800A6C: nop
    
            goto L_80800A78;
    }
    // 0x80800A6C: nop

    // 0x80800A70: b           L_80800B6C
    // 0x80800A74: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
        goto L_80800B6C;
    // 0x80800A74: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
L_80800A78:
    // 0x80800A78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X18F4) << 16);
    // 0x80800A7C: lwc1        $f8, 0x18F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X18F4));
    // 0x80800A80: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X18F8) << 16);
    // 0x80800A84: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800A88: nop

    // 0x80800A8C: bc1f        L_80800ABC
    if (!c1cs) {
        // 0x80800A90: nop
    
            goto L_80800ABC;
    }
    // 0x80800A90: nop

    // 0x80800A94: lwc1        $f10, 0x18F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X18F8));
    // 0x80800A98: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800A9C: nop

    // 0x80800AA0: bc1f        L_80800ABC
    if (!c1cs) {
        // 0x80800AA4: nop
    
            goto L_80800ABC;
    }
    // 0x80800AA4: nop

    // 0x80800AA8: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800AAC: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80800AB0: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80800AB4: b           L_80800B6C
    // 0x80800AB8: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
        goto L_80800B6C;
    // 0x80800AB8: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
L_80800ABC:
    // 0x80800ABC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X18FC) << 16);
    // 0x80800AC0: lwc1        $f16, 0x18FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X18FC));
    // 0x80800AC4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X1900) << 16);
    // 0x80800AC8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800ACC: nop

    // 0x80800AD0: bc1f        L_80800AE8
    if (!c1cs) {
        // 0x80800AD4: nop
    
            goto L_80800AE8;
    }
    // 0x80800AD4: nop

    // 0x80800AD8: lwc1        $f18, 0x1900($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X1900));
    // 0x80800ADC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800AE0: nop

    // 0x80800AE4: bc1t        L_80800B44
    if (c1cs) {
        // 0x80800AE8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(748, 0X1904) << 16);
            goto L_80800B44;
    }
L_80800AE8:
    // 0x80800AE8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X1904) << 16);
    // 0x80800AEC: lwc1        $f4, 0x1904($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X1904));
    // 0x80800AF0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X1908) << 16);
    // 0x80800AF4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800AF8: nop

    // 0x80800AFC: bc1f        L_80800B14
    if (!c1cs) {
        // 0x80800B00: nop
    
            goto L_80800B14;
    }
    // 0x80800B00: nop

    // 0x80800B04: lwc1        $f6, 0x1908($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X1908));
    // 0x80800B08: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800B0C: nop

    // 0x80800B10: bc1t        L_80800B44
    if (c1cs) {
        // 0x80800B14: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(748, 0X190C) << 16);
            goto L_80800B44;
    }
L_80800B14:
    // 0x80800B14: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X190C) << 16);
    // 0x80800B18: lwc1        $f8, 0x190C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X190C));
    // 0x80800B1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X1910) << 16);
    // 0x80800B20: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800B24: nop

    // 0x80800B28: bc1f        L_80800B6C
    if (!c1cs) {
        // 0x80800B2C: nop
    
            goto L_80800B6C;
    }
    // 0x80800B2C: nop

    // 0x80800B30: lwc1        $f10, 0x1910($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X1910));
    // 0x80800B34: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800B38: nop

    // 0x80800B3C: bc1f        L_80800B6C
    if (!c1cs) {
        // 0x80800B40: nop
    
            goto L_80800B6C;
    }
    // 0x80800B40: nop

L_80800B44:
    // 0x80800B44: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800B48: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x80800B4C: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x80800B50: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80800B54: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    // 0x80800B58: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x80800B5C: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x80800B60: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x80800B64: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800B68: sb          $t5, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r13;
L_80800B6C:
    // 0x80800B6C: jal         0x80100094
    // 0x80800B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_13;
    // 0x80800B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800B74: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800B78: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800B7C: bnel        $t6, $zero, L_80800BCC
    if (ctx->r14 != 0) {
        // 0x80800B80: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80800BCC;
    }
    goto skip_2;
    // 0x80800B80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80800B84: jal         0x800C8A98
    // 0x80800B88: nop

    func_800C8A98(rdram, ctx);
        goto after_14;
    // 0x80800B88: nop

    after_14:
    // 0x80800B8C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80800B90: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(748, 0X1B44) << 16);
    // 0x80800B94: addiu       $a1, $a1, 0x1B44
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X1B44));
    // 0x80800B98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B9C: jal         0x800C8E84
    // 0x80800BA0: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    func_800C8E84(rdram, ctx);
        goto after_15;
    // 0x80800BA0: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    after_15:
    // 0x80800BA4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80800BA8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(748, 0X1B50) << 16);
    // 0x80800BAC: addiu       $a1, $a1, 0x1B50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X1B50));
    // 0x80800BB0: jal         0x800C8D4C
    // 0x80800BB4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_800C8D4C(rdram, ctx);
        goto after_16;
    // 0x80800BB4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_16:
    // 0x80800BB8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80800BBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800BC0: jal         0x800C8F64
    // 0x80800BC4: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800C8F64(rdram, ctx);
        goto after_17;
    // 0x80800BC4: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_17:
    // 0x80800BC8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800BCC:
    // 0x80800BCC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800BD0: jal         0x8008A0E8
    // 0x80800BD4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x80800BD4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_18:
    // 0x80800BD8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800BDC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800BE0: jal         0x8008A0E8
    // 0x80800BE4: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80800BE4: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_19:
    // 0x80800BE8: lbu         $v1, 0x79($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X79);
    // 0x80800BEC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800BF0: srl         $t0, $v1, 4
    ctx->r8 = S32(U32(ctx->r3) >> 4);
    // 0x80800BF4: beq         $t0, $zero, L_80800C24
    if (ctx->r8 == 0) {
        // 0x80800BF8: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80800C24;
    }
    // 0x80800BF8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80800BFC: lw          $t1, 0x6C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X6C);
    // 0x80800C00: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800C04: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80800C08: andi        $t3, $t1, 0x1FF
    ctx->r11 = ctx->r9 & 0X1FF;
    // 0x80800C0C: beq         $t3, $zero, L_80800C24
    if (ctx->r11 == 0) {
        // 0x80800C10: nop
    
            goto L_80800C24;
    }
    // 0x80800C10: nop

    // 0x80800C14: jal         0x800EFE50
    // 0x80800C18: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    func_800EFE50(rdram, ctx);
        goto after_20;
    // 0x80800C18: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_20:
    // 0x80800C1C: b           L_80800C48
    // 0x80800C20: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
        goto L_80800C48;
    // 0x80800C20: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
L_80800C24:
    // 0x80800C24: beq         $v1, $zero, L_80800C3C
    if (ctx->r3 == 0) {
        // 0x80800C28: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_80800C3C;
    }
    // 0x80800C28: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800C2C: jal         0x800EE7F8
    // 0x80800C30: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_21;
    // 0x80800C30: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_21:
    // 0x80800C34: b           L_80800C48
    // 0x80800C38: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
        goto L_80800C48;
    // 0x80800C38: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
L_80800C3C:
    // 0x80800C3C: jal         0x800EE7F8
    // 0x80800C40: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_22;
    // 0x80800C40: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_22:
    // 0x80800C44: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
L_80800C48:
    // 0x80800C48: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800C4C: jal         0x800C8CB8
    // 0x80800C50: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    func_800C8CB8(rdram, ctx);
        goto after_23;
    // 0x80800C50: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_23:
    // 0x80800C54: lbu         $t4, 0x79($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X79);
    // 0x80800C58: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80800C5C: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x80800C60: bne         $t5, $zero, L_80800C7C
    if (ctx->r13 != 0) {
        // 0x80800C64: nop
    
            goto L_80800C7C;
    }
    // 0x80800C64: nop

    // 0x80800C68: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80800C6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C70: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800C74: beq         $t7, $zero, L_80800C84
    if (ctx->r15 == 0) {
        // 0x80800C78: nop
    
            goto L_80800C84;
    }
    // 0x80800C78: nop

L_80800C7C:
    // 0x80800C7C: b           L_80800C84
    // 0x80800C80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800C84;
    // 0x80800C80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800C84:
    // 0x80800C84: jal         0x800C8FE0
    // 0x80800C88: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_800C8FE0(rdram, ctx);
        goto after_24;
    // 0x80800C88: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_24:
    // 0x80800C8C: lbu         $t9, 0x79($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X79);
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C94: srl         $t0, $t9, 4
    ctx->r8 = S32(U32(ctx->r25) >> 4);
    // 0x80800C98: bne         $t0, $zero, L_80800CB0
    if (ctx->r8 != 0) {
        // 0x80800C9C: nop
    
            goto L_80800CB0;
    }
    // 0x80800C9C: nop

    // 0x80800CA0: lw          $t1, 0x6C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X6C);
    // 0x80800CA4: andi        $t3, $t1, 0x1FF
    ctx->r11 = ctx->r9 & 0X1FF;
    // 0x80800CA8: beq         $t3, $zero, L_80800CB8
    if (ctx->r11 == 0) {
        // 0x80800CAC: nop
    
            goto L_80800CB8;
    }
    // 0x80800CAC: nop

L_80800CB0:
    // 0x80800CB0: jal         0x80800820
    // 0x80800CB4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80800820_chlagoonufoint(rdram, ctx);
        goto after_25;
    // 0x80800CB4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_25:
L_80800CB8:
    // 0x80800CB8: jal         0x80800744
    // 0x80800CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800744_chlagoonufoint(rdram, ctx);
        goto after_26;
    // 0x80800CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
L_80800CC0:
    // 0x80800CC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CC4:
    // 0x80800CC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CC8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800CCC: jr          $ra
    // 0x80800CD0: nop

    return;
    // 0x80800CD0: nop

;}
RECOMP_FUNC void _gclightsDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EB0: syscall     660
    recomp_syscall_handler(rdram, ctx, 0x80087EB0);
    return;
    // 0x80087EB4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087CE0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087CE0);
    return;
    // 0x80087CE4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void bakey_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091B18: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80091B1C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80091B20: jal         0x800BD0DC
    // 0x80091B24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800BD0DC(rdram, ctx);
        goto after_0;
    // 0x80091B24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80091B28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80091B2C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80091B30: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
    // 0x80091B34: lw          $t6, 0x40($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X40);
    // 0x80091B38: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x80091B3C: lw          $t7, 0x40($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X40);
    // 0x80091B40: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80091B44: sb          $zero, 0x9($t7)
    MEM_B(0X9, ctx->r15) = 0;
    // 0x80091B48: lw          $t8, 0x40($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X40);
    // 0x80091B4C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80091B50: lw          $t0, 0x40($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X40);
    // 0x80091B54: sb          $t9, 0x8($t0)
    MEM_B(0X8, ctx->r8) = ctx->r25;
    // 0x80091B58: lw          $t1, 0x40($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X40);
    // 0x80091B5C: sb          $zero, 0xA($t1)
    MEM_B(0XA, ctx->r9) = 0;
    // 0x80091B60: lw          $t2, 0x40($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X40);
    // 0x80091B64: sb          $zero, 0x18($t2)
    MEM_B(0X18, ctx->r10) = 0;
    // 0x80091B68: lw          $t3, 0x40($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X40);
    // 0x80091B6C: sb          $zero, 0xB($t3)
    MEM_B(0XB, ctx->r11) = 0;
    // 0x80091B70: lw          $t4, 0x40($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X40);
    // 0x80091B74: sb          $zero, 0x19($t4)
    MEM_B(0X19, ctx->r12) = 0;
L_80091B78:
    // 0x80091B78: lw          $t5, 0x40($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X40);
    // 0x80091B7C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80091B80: sb          $zero, 0xA($t6)
    MEM_B(0XA, ctx->r14) = 0;
    // 0x80091B84: lw          $t7, 0x40($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X40);
    // 0x80091B88: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80091B8C: sb          $zero, 0x18($t8)
    MEM_B(0X18, ctx->r24) = 0;
    // 0x80091B90: lw          $t9, 0x40($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X40);
    // 0x80091B94: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80091B98: sb          $zero, 0xB($t0)
    MEM_B(0XB, ctx->r8) = 0;
    // 0x80091B9C: lw          $t1, 0x40($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X40);
    // 0x80091BA0: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80091BA4: sb          $zero, 0x19($t2)
    MEM_B(0X19, ctx->r10) = 0;
    // 0x80091BA8: lw          $t3, 0x40($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X40);
    // 0x80091BAC: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80091BB0: sb          $zero, 0xC($t4)
    MEM_B(0XC, ctx->r12) = 0;
    // 0x80091BB4: lw          $t5, 0x40($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X40);
    // 0x80091BB8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80091BBC: sb          $zero, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = 0;
    // 0x80091BC0: lw          $t7, 0x40($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X40);
    // 0x80091BC4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80091BC8: sb          $zero, 0xD($t8)
    MEM_B(0XD, ctx->r24) = 0;
    // 0x80091BCC: lw          $t9, 0x40($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X40);
    // 0x80091BD0: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80091BD4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80091BD8: bne         $v0, $v1, L_80091B78
    if (ctx->r2 != ctx->r3) {
        // 0x80091BDC: sb          $zero, 0x1B($t0)
        MEM_B(0X1B, ctx->r8) = 0;
            goto L_80091B78;
    }
    // 0x80091BDC: sb          $zero, 0x1B($t0)
    MEM_B(0X1B, ctx->r8) = 0;
    // 0x80091BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091BE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091BE8: jr          $ra
    // 0x80091BEC: nop

    return;
    // 0x80091BEC: nop

;}
RECOMP_FUNC void bahold_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B8: jal         0x80800008
    // 0x808001BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800008_bahold(rdram, ctx);
        goto after_0;
    // 0x808001BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C8: jr          $ra
    // 0x808001CC: nop

    return;
    // 0x808001CC: nop

;}
RECOMP_FUNC void func_80800C60_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800C6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800C70: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800C74: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800C78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C7C: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800C80: beq         $t6, $zero, L_80800CA4
    if (ctx->r14 == 0) {
        // 0x80800C84: addiu       $a1, $zero, 0x17
        ctx->r5 = ADD32(0, 0X17);
            goto L_80800CA4;
    }
    // 0x80800C84: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80800C88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C8C: beq         $t6, $at, L_80800CB4
    if (ctx->r14 == ctx->r1) {
        // 0x80800C90: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800CB4;
    }
    // 0x80800C90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C94: beql        $t6, $at, L_80800CE4
    if (ctx->r14 == ctx->r1) {
        // 0x80800C98: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CE4;
    }
    goto skip_0;
    // 0x80800C98: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800C9C: b           L_80800CF0
    // 0x80800CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800CF0;
    // 0x80800CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CA4:
    // 0x80800CA4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800CA8: jal         0x800856B0
    // 0x80800CAC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800CAC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800CB0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80800CB4:
    // 0x80800CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800CB8: jal         0x800856E0
    // 0x80800CBC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800CBC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800CC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800CC4: lhu         $t7, 0x6E($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800CC8: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800CCC: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80800CD0: jal         0x80800B28
    // 0x80800CD4: sh          $t9, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r25;
    func_80800B28_chkingjinjo(rdram, ctx);
        goto after_2;
    // 0x80800CD4: sh          $t9, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r25;
    after_2:
    // 0x80800CD8: jal         0x800880B8
    // 0x80800CDC: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800CDC: nop

    after_3:
    // 0x80800CE0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80800CE4:
    // 0x80800CE4: jal         0x800856D8
    // 0x80800CE8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800CE8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CF0:
    // 0x80800CF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CF4: jr          $ra
    // 0x80800CF8: nop

    return;
    // 0x80800CF8: nop

;}
RECOMP_FUNC void _bsbswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B60: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082B60);
    return;
    // 0x80082B64: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chfactoryentrydoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2016, 0X2B0) << 16);
    // 0x80800144: jr          $ra
    // 0x80800148: addiu       $v0, $v0, 0x2B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2016, 0X2B0));
    return;
    // 0x80800148: addiu       $v0, $v0, 0x2B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2016, 0X2B0));
;}
RECOMP_FUNC void func_8010C5C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C5C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C5C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C5C8: lw          $v1, 0x70($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X70);
    // 0x8010C5CC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8010C5D0: srl         $a3, $v1, 25
    ctx->r7 = S32(U32(ctx->r3) >> 25);
    // 0x8010C5D4: bnel        $a3, $zero, L_8010C5E8
    if (ctx->r7 != 0) {
        // 0x8010C5D8: lwc1        $f2, 0x8($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
            goto L_8010C5E8;
    }
    goto skip_0;
    // 0x8010C5D8: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x8010C5DC: b           L_8010C658
    // 0x8010C5E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010C658;
    // 0x8010C5E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010C5E4: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
L_8010C5E8:
    // 0x8010C5E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C5EC: lwc1        $f0, 0x6F54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6F54);
    // 0x8010C5F0: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8010C5F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010C5F8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8010C5FC: nop

    // 0x8010C600: bc1f        L_8010C60C
    if (!c1cs) {
        // 0x8010C604: nop
    
            goto L_8010C60C;
    }
    // 0x8010C604: nop

    // 0x8010C608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010C60C:
    // 0x8010C60C: beql        $v0, $zero, L_8010C65C
    if (ctx->r2 == 0) {
        // 0x8010C610: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010C65C;
    }
    goto skip_1;
    // 0x8010C610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8010C614: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8010C618: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010C61C: sll         $a2, $v1, 22
    ctx->r6 = S32(ctx->r3 << 22);
    // 0x8010C620: srl         $t6, $a2, 26
    ctx->r14 = S32(U32(ctx->r6) >> 26);
    // 0x8010C624: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8010C628: addiu       $a0, $a0, 0x6F50
    ctx->r4 = ADD32(ctx->r4, 0X6F50);
    // 0x8010C62C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010C630: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    // 0x8010C634: bc1f        L_8010C640
    if (!c1cs) {
        // 0x8010C638: nop
    
            goto L_8010C640;
    }
    // 0x8010C638: nop

    // 0x8010C63C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010C640:
    // 0x8010C640: beql        $v0, $zero, L_8010C65C
    if (ctx->r2 == 0) {
        // 0x8010C644: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010C65C;
    }
    goto skip_2;
    // 0x8010C644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8010C648: jal         0x800CC338
    // 0x8010C64C: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    func_800CC338(rdram, ctx);
        goto after_0;
    // 0x8010C64C: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    after_0:
    // 0x8010C650: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8010C654: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
L_8010C658:
    // 0x8010C658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010C65C:
    // 0x8010C65C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C660: jr          $ra
    // 0x8010C664: nop

    return;
    // 0x8010C664: nop

;}
RECOMP_FUNC void func_80800238_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800238: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080023C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800240: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800244: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800248: jal         0x8009E74C
    // 0x8080024C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x8080024C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_0:
    // 0x80800250: beq         $v0, $zero, L_80800288
    if (ctx->r2 == 0) {
        // 0x80800254: nop
    
            goto L_80800288;
    }
    // 0x80800254: nop

    // 0x80800258: jal         0x80084508
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babackpack_get_state(rdram, ctx);
        goto after_1;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800260: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800264: beq         $v0, $at, L_808002C0
    if (ctx->r2 == ctx->r1) {
        // 0x80800268: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002C0;
    }
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: jal         0x800A0CD0
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CD0(rdram, ctx);
        goto after_2;
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: jal         0x80084538
    // 0x8080027C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _babackpack_set_state(rdram, ctx);
        goto after_3;
    // 0x8080027C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800280: b           L_808002C4
    // 0x80800284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C4;
    // 0x80800284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800288:
    // 0x80800288: jal         0x80084508
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babackpack_get_state(rdram, ctx);
        goto after_4;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800290: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800294: beq         $v0, $at, L_808002A4
    if (ctx->r2 == ctx->r1) {
        // 0x80800298: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A4;
    }
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080029C: jal         0x80084538
    // 0x808002A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_5;
    // 0x808002A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_808002A4:
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: jal         0x800A0CD0
    // 0x808002AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_6;
    // 0x808002AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808002B0: jal         0x8009EF60
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_7;
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002B8: jal         0x800A1040
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1040(rdram, ctx);
        goto after_8;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_808002C0:
    // 0x808002C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002C4:
    // 0x808002C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002CC: jr          $ra
    // 0x808002D0: nop

    return;
    // 0x808002D0: nop

;}
RECOMP_FUNC void func_80800000_bsclimb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80098634
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80098634(rdram, ctx);
        goto after_0;
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800014: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800018: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8080001C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80800020: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(144, 0X8C0) << 16);
    // 0x80800024: addiu       $t7, $t7, 0x8C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(144, 0X8C0));
    // 0x80800028: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080002C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800030: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80800034: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80800038: lw          $a2, -0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, -0X10);
    // 0x8080003C: lw          $a3, -0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, -0XC);
    // 0x80800040: lh          $a1, -0x12($v1)
    ctx->r5 = MEM_H(ctx->r3, -0X12);
    // 0x80800044: jal         0x8009DF94
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009DF94(rdram, ctx);
        goto after_1;
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void func_80025F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025F20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025F28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80025F2C: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80025F30: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80025F34: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80025F38: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80025F3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025F40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80025F44: jal         0x80026500
    // 0x80025F48: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x80025F48: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x80025F4C: b           L_80025F54
    // 0x80025F50: nop

        goto L_80025F54;
    // 0x80025F50: nop

L_80025F54:
    // 0x80025F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025F58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80025F5C: jr          $ra
    // 0x80025F60: nop

    return;
    // 0x80025F60: nop

    // 0x80025F64: nop

    // 0x80025F68: nop

    // 0x80025F6C: nop

;}
RECOMP_FUNC void func_800F92CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F92CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F92D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F92D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F92D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800F92DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800F92E0: jal         0x800F54E4
    // 0x800F92E4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800F92E4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x800F92E8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800F92EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F92F0: jal         0x800F5410
    // 0x800F92F4: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x800F92F4: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    after_1:
    // 0x800F92F8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800F92FC: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800F9300: beq         $v0, $v1, L_800F931C
    if (ctx->r2 == ctx->r3) {
        // 0x800F9304: sw          $v0, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->r2;
            goto L_800F931C;
    }
    // 0x800F9304: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800F9308: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800F930C: beq         $v0, $at, L_800F932C
    if (ctx->r2 == ctx->r1) {
        // 0x800F9310: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_800F932C;
    }
    // 0x800F9310: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800F9314: b           L_800F9334
    // 0x800F9318: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
        goto L_800F9334;
    // 0x800F9318: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_800F931C:
    // 0x800F931C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800F9320: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x800F9324: b           L_800F9330
    // 0x800F9328: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
        goto L_800F9330;
    // 0x800F9328: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_800F932C:
    // 0x800F932C: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
L_800F9330:
    // 0x800F9330: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_800F9334:
    // 0x800F9334: jal         0x800878A0
    // 0x800F9338: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x800F9338: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_2:
    // 0x800F933C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800F9340: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x800F9344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F9348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F934C: jr          $ra
    // 0x800F9350: nop

    return;
    // 0x800F9350: nop

;}
RECOMP_FUNC void func_808001CC_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001D8: jal         0x800F54E4
    // 0x808001DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808001DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808001E4: jal         0x800F6478
    // 0x808001E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6478(rdram, ctx);
        goto after_1;
    // 0x808001E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808001EC: beql        $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x808001F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800350;
    }
    goto skip_0;
    // 0x808001F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001F4: jal         0x800F55FC
    // 0x808001F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F55FC(rdram, ctx);
        goto after_2;
    // 0x808001F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808001FC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800200: bltzl       $t6, L_80800350
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800204: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800350;
    }
    goto skip_1;
    // 0x80800204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800208: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080020C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800210: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80800214: beq         $t7, $at, L_80800234
    if (ctx->r15 == ctx->r1) {
        // 0x80800218: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800234;
    }
    // 0x80800218: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080021C: beq         $t7, $at, L_8080029C
    if (ctx->r15 == ctx->r1) {
        // 0x80800220: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080029C;
    }
    // 0x80800220: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800224: beq         $t7, $at, L_808002C8
    if (ctx->r15 == ctx->r1) {
        // 0x80800228: nop
    
            goto L_808002C8;
    }
    // 0x80800228: nop

    // 0x8080022C: b           L_80800350
    // 0x80800230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800350;
    // 0x80800230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800234:
    // 0x80800234: jal         0x800D90A4
    // 0x80800238: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_3;
    // 0x80800238: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_3:
    // 0x8080023C: beql        $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x80800240: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800350;
    }
    goto skip_2;
    // 0x80800240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800244: jal         0x8008A230
    // 0x80800248: nop

    _subaddiedialog_entrypoint_16(rdram, ctx);
        goto after_4;
    // 0x80800248: nop

    after_4:
    // 0x8080024C: beq         $v0, $zero, L_8080034C
    if (ctx->r2 == 0) {
        // 0x80800250: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080034C;
    }
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800258: addiu       $a1, $zero, 0x12CF
    ctx->r5 = ADD32(0, 0X12CF);
    // 0x8080025C: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800260: bgez        $t0, L_80800270
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800264: nop
    
            goto L_80800270;
    }
    // 0x80800264: nop

    // 0x80800268: b           L_80800270
    // 0x8080026C: addiu       $a1, $zero, 0x12D0
    ctx->r5 = ADD32(0, 0X12D0);
        goto L_80800270;
    // 0x8080026C: addiu       $a1, $zero, 0x12D0
    ctx->r5 = ADD32(0, 0X12D0);
L_80800270:
    // 0x80800270: jal         0x80800980
    // 0x80800274: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800980_chfireicestorm(rdram, ctx);
        goto after_5;
    // 0x80800274: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x80800278: beql        $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x8080027C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800350;
    }
    goto skip_3;
    // 0x8080027C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800280: jal         0x80800940
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800940_chfireicestorm(rdram, ctx);
        goto after_6;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x80800558
    // 0x80800290: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800558_chfireicestorm(rdram, ctx);
        goto after_7;
    // 0x80800290: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800294: b           L_80800350
    // 0x80800298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800350;
    // 0x80800298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080029C:
    // 0x8080029C: jal         0x800D9078
    // 0x808002A0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_8;
    // 0x808002A0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_8:
    // 0x808002A4: beql        $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x808002A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800350;
    }
    goto skip_4;
    // 0x808002A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x808002AC: jal         0x80800940
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800940_chfireicestorm(rdram, ctx);
        goto after_9;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: jal         0x80800558
    // 0x808002BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800558_chfireicestorm(rdram, ctx);
        goto after_10;
    // 0x808002BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x808002C0: b           L_80800350
    // 0x808002C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800350;
    // 0x808002C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002C8:
    // 0x808002C8: jal         0x800DA298
    // 0x808002CC: addiu       $a0, $zero, 0x6CD
    ctx->r4 = ADD32(0, 0X6CD);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x808002CC: addiu       $a0, $zero, 0x6CD
    ctx->r4 = ADD32(0, 0X6CD);
    after_11:
    // 0x808002D0: bnel        $v0, $zero, L_80800350
    if (ctx->r2 != 0) {
        // 0x808002D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800350;
    }
    goto skip_5;
    // 0x808002D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x808002D8: jal         0x800A9C98
    // 0x808002DC: nop

    func_800A9C98(rdram, ctx);
        goto after_12;
    // 0x808002DC: nop

    after_12:
    // 0x808002E0: bnel        $v0, $zero, L_80800350
    if (ctx->r2 != 0) {
        // 0x808002E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800350;
    }
    goto skip_6;
    // 0x808002E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x808002E8: jal         0x800D9078
    // 0x808002EC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_13;
    // 0x808002EC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_13:
    // 0x808002F0: beq         $v0, $zero, L_80800308
    if (ctx->r2 == 0) {
        // 0x808002F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800308;
    }
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F8: jal         0x80800558
    // 0x808002FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800558_chfireicestorm(rdram, ctx);
        goto after_14;
    // 0x808002FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x80800300: b           L_80800350
    // 0x80800304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800350;
    // 0x80800304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800308:
    // 0x80800308: jal         0x800D9078
    // 0x8080030C: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800D9078(rdram, ctx);
        goto after_15;
    // 0x8080030C: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_15:
    // 0x80800310: beql        $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x80800314: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800350;
    }
    goto skip_7;
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80800318: jal         0x808009C8
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009C8_chfireicestorm(rdram, ctx);
        goto after_16;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800320: bne         $v0, $zero, L_8080034C
    if (ctx->r2 != 0) {
        // 0x80800324: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080034C;
    }
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800328: jal         0x80108B04
    // 0x8080032C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_17;
    // 0x8080032C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800330: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800334: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800338: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080033C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800340: jal         0x800DC178
    // 0x80800344: nop

    func_800DC178(rdram, ctx);
        goto after_18;
    // 0x80800344: nop

    after_18:
    // 0x80800348: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8080034C:
    // 0x8080034C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800350:
    // 0x80800350: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800354: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800358: jr          $ra
    // 0x8080035C: nop

    return;
    // 0x8080035C: nop

;}
RECOMP_FUNC void _chstonepillar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CD0: syscall     225
    recomp_syscall_handler(rdram, ctx, 0x80085CD0);
    return;
    // 0x80085CD4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080039C_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080039C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003A8: jal         0x8008CABC
    // 0x808003AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808003AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808003B4: jal         0x8009E710
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003BC: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x808003C0: bnel        $v0, $at, L_808003DC
    if (ctx->r2 != ctx->r1) {
        // 0x808003C4: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808003DC;
    }
    goto skip_0;
    // 0x808003C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x808003C8: jal         0x8008B2B4
    // 0x808003CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_2;
    // 0x808003CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808003D0: b           L_808003E4
    // 0x808003D4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_808003E4;
    // 0x808003D4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808003D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_808003DC:
    // 0x808003DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808003E0: nop

L_808003E4:
    // 0x808003E4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x808003F0: jal         0x8008CC34
    // 0x808003F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopStartingAt(rdram, ctx);
        goto after_3;
    // 0x808003F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x808003F8: jal         0x80800000
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbswim(rdram, ctx);
        goto after_4;
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800400: jal         0x80800030
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_5;
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: jal         0x800852A8
    // 0x80800410: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    _baswim_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800410: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_6:
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: jal         0x8009BC5C
    // 0x8080041C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_7;
    // 0x8080041C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800424: jal         0x800910BC
    // 0x80800428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800910BC(rdram, ctx);
        goto after_8;
    // 0x80800428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8080042C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800430: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800434: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800438: jr          $ra
    // 0x8080043C: nop

    return;
    // 0x8080043C: nop

;}
RECOMP_FUNC void _bsbflip_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082938: syscall     21
    recomp_syscall_handler(rdram, ctx, 0x80082938);
    return;
    // 0x8008293C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008ED88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ED88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008ED8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008ED90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008ED94: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008ED98: jal         0x80106790
    // 0x8008ED9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8008ED9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8008EDA0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008EDA4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008EDA8: jal         0x800F497C
    // 0x8008EDAC: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    func_800F497C(rdram, ctx);
        goto after_1;
    // 0x8008EDAC: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    after_1:
    // 0x8008EDB0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008EDB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008EDB8: jal         0x800F49A8
    // 0x8008EDBC: lw          $a0, 0x184($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X184);
    func_800F49A8(rdram, ctx);
        goto after_2;
    // 0x8008EDBC: lw          $a0, 0x184($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X184);
    after_2:
    // 0x8008EDC0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8008EDC4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008EDC8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8008EDCC: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x8008EDD0: lw          $a0, 0x184($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X184);
    // 0x8008EDD4: jal         0x800F49D4
    // 0x8008EDD8: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_3;
    // 0x8008EDD8: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x8008EDDC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008EDE0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8008EDE4: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x8008EDE8: lw          $a0, 0x184($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X184);
    // 0x8008EDEC: jal         0x800F4A58
    // 0x8008EDF0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800F4A58(rdram, ctx);
        goto after_4;
    // 0x8008EDF0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x8008EDF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008EDF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008EDFC: jr          $ra
    // 0x8008EE00: nop

    return;
    // 0x8008EE00: nop

;}
RECOMP_FUNC void bamum_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800204: jal         0x80800018
    // 0x80800208: nop

    func_80800018_bamum(rdram, ctx);
        goto after_0;
    // 0x80800208: nop

    after_0:
    // 0x8080020C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
